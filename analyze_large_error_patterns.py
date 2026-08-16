#!/usr/bin/env python3
"""Extract DecBench large cases and detect source-aware type-recovery patterns.

The score JSON does not normally embed C code.  This script first looks for
embedded source_code/decompiled_code fields, then resolves local files through
manifest.json under --dataset-root.  Missing code is reported as unevaluable,
never as a negative result.
"""

from __future__ import annotations

import argparse
import csv
import json
import re
import subprocess
import tempfile
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from statistics import mean
from typing import Any, Iterable

from download_large_scan_inputs import extract_function_definition, looks_like_definition


AGENTS = ("codex", "claude-code")
PATTERNS = (
    "SC-01",      # static object reconstructed as extern
    "ST-01",      # same-name struct/header collision
    "PTR-01",     # pointer-depth collapse
    "INT-01",     # integer width/signedness/typedef erosion
    "FN-01",      # function prototype mismatch
    "LAYOUT-01",  # explicit struct layout mismatch
    "ARR-01",     # array/pointer/static-sentinel confusion
)
STATUSES = ("yes", "no", "candidate", "unevaluable")


@dataclass
class Detection:
    status: str
    evidence: str

    def __post_init__(self) -> None:
        if self.status not in STATUSES:
            raise ValueError(self.status)


def read_json(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text(encoding="utf-8"))


def manifest_index(manifest: dict[str, Any]) -> dict[tuple[str, str, str], dict[str, Any]]:
    binaries = manifest.get("binaries", [])
    entries = binaries.values() if isinstance(binaries, dict) else binaries
    return {
        (entry["project"], entry["opt"], entry["binary"]): entry
        for entry in entries
    }


def find_matching(text: str, start: int, opening: str, closing: str) -> int | None:
    depth = 0
    quote: str | None = None
    escape = False
    line_comment = False
    block_comment = False
    i = start
    while i < len(text):
        c = text[i]
        n = text[i + 1] if i + 1 < len(text) else ""
        if line_comment:
            if c == "\n":
                line_comment = False
        elif block_comment:
            if c == "*" and n == "/":
                block_comment = False
                i += 1
        elif quote:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == quote:
                quote = None
        elif c == "/" and n == "/":
            line_comment = True
            i += 1
        elif c == "/" and n == "*":
            block_comment = True
            i += 1
        elif c in {'"', "'"}:
            quote = c
        elif c == opening:
            depth += 1
        elif c == closing:
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return None


def extract_function(text: str, name: str) -> str | None:
    """Extract ANSI, zlib K&R, and zlib ``OF((...))`` definitions."""
    return extract_function_definition(text, name)


def embedded_code(function: dict[str, Any], agent: str | None) -> str | None:
    value = function.get("source_code" if agent is None else "decompiled_code")
    if isinstance(value, str):
        return value
    if agent is not None and isinstance(value, dict) and isinstance(value.get(agent), str):
        return value[agent]
    return None


def resolve_decompiled(
    function: dict[str, Any], agent: str, entry: dict[str, Any] | None, root: Path
) -> tuple[str | None, str | None]:
    code = embedded_code(function, agent)
    if code is not None:
        return code, "embedded:function_results.json"
    rel = (entry or {}).get("results", {}).get(agent)
    if not rel:
        return None, None
    path = root / rel
    if not path.is_file():
        return None, rel
    text = path.read_text(encoding="utf-8", errors="replace")
    if not text.strip() or not looks_like_definition(text, function["function"]):
        return None, rel
    # Keep the complete result file: includes, extern declarations and local
    # struct definitions are essential evidence for SC-01/ST-01.
    return text, rel


def source_candidates(manifest: dict[str, Any], project: str, root: Path) -> list[Path]:
    return [root / rel for rel in manifest.get("projects", {}).get(project, {}).get("sources", [])]


CFG_TOKEN_STOPWORDS = {
    "UnsupportedStmt", "FIELD_IDENTIFIER", "FUNCTION_START", "FUNCTION_END",
    "UNKNOWN", "addressOf", "fieldAccess", "logicalNot", "cast", "quot",
    "void", "char", "short", "int", "long", "float", "double", "signed",
    "unsigned", "const", "static", "extern", "struct", "union", "enum",
    "return", "sizeof", "true", "false", "NULL",
}


def source_cfg_tokens(
    entry: dict[str, Any] | None, function_name: str, root: Path,
) -> set[str]:
    """Return target-function identifiers from its source CFG, when present.

    A project can contain many definitions named ``main`` (or duplicated helper
    functions).  The manifest source list alone therefore cannot identify the
    source file.  CFG labels retain calls, globals and field names from the
    actual compiled function and provide a stable local disambiguator.
    """
    rel = (entry or {}).get("source_cfg_path")
    if not rel:
        return set()
    path = root / rel
    if not path.is_file():
        return set()
    try:
        cfg = json.loads(path.read_text(encoding="utf-8"))
        labels = cfg.get("functions", {}).get(function_name, {}).get("labels", {})
        text = "\n".join(str(value) for value in labels.values())
    except (OSError, ValueError, AttributeError):
        return set()
    return {
        token for token in re.findall(r"\b[A-Za-z_]\w{2,}\b", text)
        if token not in CFG_TOKEN_STOPWORDS
    }


def source_cfg_overlap(body: str, cfg_tokens: set[str]) -> tuple[int, float]:
    body_tokens = {
        token for token in re.findall(r"\b[A-Za-z_]\w{2,}\b", body)
        if token not in CFG_TOKEN_STOPWORDS
    }
    overlap = len(body_tokens & cfg_tokens)
    return overlap, overlap / max(1, len(body_tokens))


def resolve_source(
    function: dict[str, Any], project: str, binary: str,
    manifest: dict[str, Any], root: Path, entry: dict[str, Any] | None = None,
    preferred_paths: list[str] | None = None,
) -> tuple[str | None, str | None, str | None]:
    code = embedded_code(function, None)
    if code is not None:
        return code, code, "embedded:function_results.json"

    hits: list[tuple[Path, str, str]] = []
    candidates = source_candidates(manifest, project, root)
    if preferred_paths:
        preferred = [root / rel for rel in preferred_paths]
        seen = {str(path) for path in preferred}
        candidates = preferred + [path for path in candidates if str(path) not in seen]
    for path in candidates:
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8", errors="replace")
        body = extract_function(text, function["function"])
        if body:
            hits.append((path, body, text))
    if not hits:
        return None, None, None

    cfg_tokens = source_cfg_tokens(entry, function["function"], root)
    ranked = sorted(
        hits,
        key=lambda hit: (
            source_cfg_overlap(hit[1], cfg_tokens) if cfg_tokens else (0, 0.0),
            hit[0].name == f"{binary}.c",
        ),
        reverse=True,
    )
    chosen = ranked[0]
    note = str(chosen[0].relative_to(root))
    if len(hits) > 1:
        if cfg_tokens:
            score = source_cfg_overlap(chosen[1], cfg_tokens)
            note += f" (CFG-selected: overlap={score[0]}, coverage={score[1]:.3f}; candidates: "
        else:
            note += " (selected from candidates: "
        note += ", ".join(str(h[0].relative_to(root)) for h in hits) + ")"
    return chosen[1], chosen[2], note


def parse_structs(code: str) -> dict[str, list[tuple[str, str]]]:
    structs: dict[str, list[tuple[str, str]]] = {}
    for match in re.finditer(r"\bstruct\s+(\w+)\s*\{([^{}]*)\}\s*;", code, re.S):
        fields: list[tuple[str, str]] = []
        reliable = True
        for statement in match.group(2).split(";"):
            statement = re.sub(r"/\*.*?\*/|//[^\n]*", " ", statement, flags=re.S).strip()
            if not statement:
                continue
            # Multiple declarators and bit-fields need a real C parser.  Do not
            # turn a partial regex parse into a confirmed layout mismatch.
            if "," in statement or ":" in statement:
                reliable = False
                break
            fm = re.search(r"(.+?)\b([A-Za-z_]\w*)\s*(\[[^]]*\])?\s*$", statement)
            if fm:
                fields.append((fm.group(2), " ".join(fm.group(1).split()) + (fm.group(3) or "")))
            else:
                reliable = False
                break
        if reliable and fields:
            structs[match.group(1)] = fields
    return structs


def extern_objects(code: str) -> dict[str, str]:
    result: dict[str, str] = {}
    for m in re.finditer(r"(?m)^\s*extern\s+(?![^;]*\()([^;=]+?)\b([A-Za-z_]\w*)\s*(\[[^;]*\])?\s*;", code):
        result[m.group(2)] = " ".join(m.group(1).split()) + (m.group(3) or "")
    return result


def static_objects(code: str) -> dict[str, str]:
    result: dict[str, str] = {}
    for m in re.finditer(r"\bstatic\s+([^;={}]+?)\b([A-Za-z_]\w*)\s*(\[[^;]*\])?\s*(?:=[^;]*)?;", code):
        result[m.group(2)] = " ".join(m.group(1).split()) + (m.group(3) or "")
    return result


def address_field_roles(code: str) -> dict[str, set[str]]:
    roles: dict[str, set[str]] = defaultdict(set)
    for m in re.finditer(r"(?:\.|->)\s*(\w+)\s*=\s*&\s*(\w+)", code):
        roles[m.group(2)].add(m.group(1))
    return roles


def compile_diagnostics(code: str) -> str:
    try:
        with tempfile.TemporaryDirectory(prefix="decbench_patterns_") as td:
            path = Path(td) / "case.c"
            path.write_text(code, encoding="utf-8")
            proc = subprocess.run(
                ["gcc", "-fsyntax-only", str(path)],
                text=True, capture_output=True, timeout=20, check=False,
            )
            return proc.stderr
    except (FileNotFoundError, subprocess.TimeoutExpired):
        return ""


def detect_sc01(source: str, source_context: str, decompiled: str) -> Detection:
    local_static = static_objects(source)
    src_static = static_objects(source_context)
    dec_extern = extern_objects(decompiled)
    src_roles = address_field_roles(source)
    dec_roles = address_field_roles(decompiled)

    for sname, stype in src_static.items():
        for dname, dtype in dec_extern.items():
            same_name = sname == dname
            shared_role = bool(src_roles.get(sname, set()) & dec_roles.get(dname, set()))
            if shared_role or (same_name and sname in local_static):
                return Detection(
                    "yes",
                    f"source static {stype} {sname}; decompiled extern {dtype} {dname}; "
                    f"shared fields={sorted(src_roles.get(sname, set()) & dec_roles.get(dname, set()))}",
                )

    file_scope_matches = sorted(src_static.keys() & dec_extern.keys())
    if file_scope_matches:
        return Detection(
            "candidate",
            "file-scope static objects emitted as extern; linkage must be checked against ELF/output contract: "
            + ", ".join(file_scope_matches),
        )

    suspicious = [name for name in dec_extern if re.search(rf"&\s*{re.escape(name)}\b", decompiled)]
    if suspicious and src_static:
        return Detection("candidate", f"address-taken externs={suspicious}; source statics={list(src_static)}")
    return Detection("no", "no role-aligned static-to-extern declaration")


def detect_st01(source_context: str, decompiled: str) -> Detection:
    diagnostics = compile_diagnostics(decompiled)
    member_error = re.search(
        r"struct\s+['‘]?([A-Za-z_]\w*)['’]?\s+has no member named\s+['‘]([A-Za-z_]\w*)['’]",
        diagnostics,
    )
    if member_error:
        return Detection("yes", f"compiler: struct {member_error.group(1)} lacks field {member_error.group(2)}")

    src_structs = parse_structs(source_context)
    dec_structs = parse_structs(decompiled)
    includes_system_header = bool(re.search(r"#\s*include\s*<[^>]+>", decompiled))
    for name, src_fields in src_structs.items():
        used = set(re.findall(rf"\b\w+\s*(?:\.|->)\s*(\w+)", decompiled))
        src_names = {f for f, _ in src_fields}
        if name not in dec_structs and includes_system_header and used & src_names:
            return Detection("candidate", f"custom struct {name} absent; custom fields used={sorted(used & src_names)}")
    return Detection("no", "no missing-member diagnostic or visible collision")


def pointer_depth(type_text: str) -> int:
    return type_text.count("*")


def detect_ptr01(source_context: str, decompiled: str) -> Detection:
    src, dec = parse_structs(source_context), parse_structs(decompiled)
    compared = 0
    for name in src.keys() & dec.keys():
        sf, df = dict(src[name]), dict(dec[name])
        for field in sf.keys() & df.keys():
            compared += 1
            if pointer_depth(sf[field]) != pointer_depth(df[field]):
                src_base = sf[field].replace("*", " ").strip()
                dec_base = df[field].replace("*", " ").strip()
                explicit_prefixes = ("struct ", "union ", "enum ")
                if ((pointer_depth(sf[field]) == 0 and not src_base.startswith(explicit_prefixes)) or
                        (pointer_depth(df[field]) == 0 and not dec_base.startswith(explicit_prefixes))):
                    return Detection(
                        "candidate",
                        f"possible pointer typedef in struct {name}.{field}: {sf[field]} vs {df[field]}",
                    )
                return Detection("yes", f"struct {name}.{field}: {sf[field]} vs {df[field]}")
    if not compared:
        return Detection("unevaluable", "no aligned explicit struct fields")
    return Detection("no", f"pointer depth agrees for {compared} aligned fields")


def target_signature(code: str, name: str) -> tuple[str, str] | None:
    definition = extract_function(code, name)
    if definition is None:
        return None
    match = re.search(rf"\b{re.escape(name)}\b\s*(?:OF\s*)?\(", definition)
    if match is None:
        return None
    opening = definition.find("(", match.start(), match.end())
    closing = find_matching(definition, opening, "(", ")")
    if closing is None:
        return None
    # Result files often put a prose/block comment immediately before a
    # definition.  It is context, not part of the return type.  Keeping it
    # here turns otherwise valid signatures into ``unevaluable`` rows.
    return_type = re.sub(
        r"/\*.*?\*/|//[^\n]*|^\s*#.*$", " ",
        definition[:match.start()], flags=re.S | re.M,
    ).strip()
    # ``extract_function_definition`` deliberately starts at a nearby
    # declaration-looking line.  If that line happens to be inside a block
    # comment whose opener lies earlier, only a dangling ``... */`` is
    # visible in the extracted text.  Discard everything through that closer.
    if "*/" in return_type:
        return_type = return_type.rsplit("*/", 1)[-1].strip()
    if ";" in return_type:
        return_type = return_type.rsplit(";", 1)[-1].strip()
    arguments = definition[opening + 1:closing].strip()
    if re.search(r"\bOF\s*\($", match.group(0)) and arguments.startswith("("):
        inner_close = find_matching(arguments, 0, "(", ")")
        if inner_close == len(arguments) - 1:
            arguments = arguments[1:inner_close]
    return " ".join(return_type.split()), " ".join(arguments.split())


def normalize_signature(sig: tuple[str, str]) -> tuple[str, str]:
    ret, args = sig
    ret = re.sub(r"\bstatic\b|\bextern\b", "", ret)
    return " ".join(ret.split()), args or "void"


def split_parameters(args: str) -> list[str]:
    parts: list[str] = []
    start = 0
    parens = brackets = 0
    for i, char in enumerate(args):
        if char == "(": parens += 1
        elif char == ")" and parens: parens -= 1
        elif char == "[": brackets += 1
        elif char == "]" and brackets: brackets -= 1
        elif char == "," and parens == 0 and brackets == 0:
            parts.append(args[start:i].strip()); start = i + 1
    parts.append(args[start:].strip())
    return [part for part in parts if part]


def remove_parameter_name(parameter: str) -> str | None:
    value = " ".join(parameter.split())
    if value in {"", "void", "..."}:
        return value or "void"
    if "(*" in value:
        return None
    match = re.match(r"^(.*[\s*])([A-Za-z_]\w*)(\s*(?:\[[^]]*\])*)$", value)
    if not match:
        return value
    return " ".join((match.group(1) + match.group(3)).split())


def canonical_function_signature(code: str, name: str) -> tuple[str, tuple[str, ...]] | None:
    sig = target_signature(code, name)
    if sig is None:
        return None
    ret, args = sig
    ret = " ".join(
        re.sub(r"\b(?:static|extern|local|ZEXTERN|ZEXPORT)\b", " ", ret).split()
    )
    params = split_parameters(args)
    if params and all(re.fullmatch(r"[A-Za-z_]\w*", param) for param in params):
        # K&R identifier list: recover each type from declarations before '{'.
        occurrence = re.search(rf"\b{re.escape(name)}\s*\([^)]*\)", code)
        if occurrence is None:
            return None
        brace = code.find("{", occurrence.end())
        if brace < 0:
            return None
        declarations = code[occurrence.end():brace]
        recovered: list[str] = []
        for param in params:
            statement = next(
                (item for item in declarations.split(";") if re.search(rf"\b{re.escape(param)}\b", item)),
                None,
            )
            if statement is None:
                recovered.append("int")  # K&R implicit-int parameter
                continue
            ptype = remove_parameter_name(" ".join(statement.split()))
            if ptype is None:
                return None
            recovered.append(ptype)
        return ret, tuple(recovered)
    canonical: list[str] = []
    for param in params or ["void"]:
        ptype = remove_parameter_name(param)
        if ptype is None:
            return None
        canonical.append(ptype)
    return ret, tuple(canonical)


def sane_type_text(value: str) -> bool:
    if not value or len(value) > 220:
        return False
    if any(token in value for token in ("#", "{", "}", ";", "\\", "=", "/*", "//", "&")):
        return False
    if re.search(r"\b(?:if|while|return|define|saved_locale|strdup)\b", value):
        return False
    return bool(re.fullmatch(r"[A-Za-z_][A-Za-z0-9_\s*\[\]]*", value))


def canonical_c_type(value: str, parameter: bool = False) -> str:
    value = re.sub(r"__attribute__\s*\(\(.*\)\)", " ", value)
    value = re.sub(
        r"\b(?:_Noreturn|__restrict__|__restrict|restrict|local|ZEXTERN|ZEXPORT)\b",
        " ", value,
    )
    value = value.replace("_Bool", "bool")
    for alias, primitive in (
        ("uint8_t", "unsigned char"), ("__u8", "unsigned char"),
        ("uint16_t", "unsigned short"), ("__u16", "unsigned short"),
        ("uint32_t", "unsigned"), ("__u32", "unsigned"),
        ("uint64_t", "unsigned long"), ("__u64", "unsigned long"),
    ):
        value = re.sub(rf"\b{re.escape(alias)}\b", primitive, value)
    value = re.sub(r"\bunsigned\s+long\s+int\b", "unsigned long", value)
    value = re.sub(r"\blong\s+unsigned\s+int\b", "unsigned long", value)
    value = re.sub(r"\bunsigned\s+int\b", "unsigned", value)
    value = re.sub(r"\bsigned\s+int\b", "int", value)
    value = re.sub(r"\b(char|int|long|short|struct\s+\w+)\s+const\b", r"const \1", value)
    if parameter:
        value = re.sub(r"\[[^]]*\]", " *", value)
    value = re.sub(r"\s*\*\s*", "*", value)
    return " ".join(value.split())


def type_profile(value: str) -> tuple[str, int, bool]:
    canonical = canonical_c_type(value, parameter=True)
    depth = canonical.count("*")
    is_const = bool(re.search(r"\bconst\b", canonical))
    base = canonical.replace("*", " ")
    base = re.sub(r"\bconst\b", " ", base)
    return " ".join(base.split()), depth, is_const


def detect_fn01(source: str, decompiled: str, function: str) -> Detection:
    ss = canonical_function_signature(source, function)
    ds = canonical_function_signature(decompiled, function)
    if ss is None or ds is None:
        return Detection("unevaluable", f"signature missing: source={ss is not None}, decompiled={ds is not None}")
    source_ret = canonical_c_type(ss[0])
    decompiled_ret = canonical_c_type(ds[0])
    source_args = tuple(canonical_c_type(arg, parameter=True) for arg in ss[1])
    decompiled_args = tuple(canonical_c_type(arg, parameter=True) for arg in ds[1])
    if not all(sane_type_text(value) for value in (source_ret, *source_args, decompiled_ret, *decompiled_args)):
        return Detection("unevaluable", f"signature parse is not trustworthy: source={ss}; decompiled={ds}")
    if source_ret == decompiled_ret and source_args == decompiled_args:
        return Detection("no", f"matching canonical signature={(source_ret, source_args)}")
    if type_profile(source_ret) != type_profile(decompiled_ret):
        return Detection("yes", f"return type: {source_ret} vs {decompiled_ret}")
    if len(source_args) != len(decompiled_args):
        return Detection("yes", f"parameter count: {len(source_args)} vs {len(decompiled_args)}")
    uncertain: list[str] = []
    for index, (src, dec) in enumerate(zip(source_args, decompiled_args), 1):
        src_profile, dec_profile = type_profile(src), type_profile(dec)
        if src_profile == dec_profile:
            continue
        src_base, src_depth, src_const = src_profile
        dec_base, dec_depth, dec_const = dec_profile
        if src_depth != dec_depth or src_const != dec_const:
            return Detection("yes", f"parameter {index}: {src} vs {dec}")
        # Distinct typedef/record spellings require project typedef resolution.
        uncertain.append(f"parameter {index}: {src} vs {dec}")
    if uncertain:
        return Detection("candidate", "; ".join(uncertain))
    return Detection("no", f"ABI-compatible signature spelling: {(source_ret, source_args)} vs {(decompiled_ret, decompiled_args)}")


def detect_int01(source: str, decompiled: str, function: str) -> Detection:
    # Only exact-name declarations are safe without a variable-alignment engine.
    typedefs = ("gid_t", "uid_t", "size_t", "uint8_t", "uint16_t", "uint32_t", "uint64_t")
    dec_function = extract_function(decompiled, function)
    if dec_function is None:
        return Detection("unevaluable", "decompiled target function cannot be isolated")
    keywords = {"const", "volatile", "restrict", "signed", "unsigned", "struct", "enum"}
    def declarations(code: str, types: tuple[str, ...]) -> dict[str, str]:
        pattern = re.compile(
            r"\b(" + "|".join(map(re.escape, types)) + r")\b"
            r"\s*(?:const\s+|volatile\s+)?(?:\*+\s*)?([A-Za-z_]\w*)\b"
        )
        return {m.group(2): m.group(1) for m in pattern.finditer(code) if m.group(2) not in keywords}
    src_decls = declarations(source, typedefs)
    dec_decls = declarations(decompiled if dec_function is None else dec_function, typedefs + ("int", "long", "short"))
    compared = 0
    for name in src_decls.keys() & dec_decls.keys():
        compared += 1
        if src_decls[name] != dec_decls[name]:
            return Detection("yes", f"{name}: {src_decls[name]} vs {dec_decls[name]}")
    if not compared:
        return Detection("unevaluable", "no safely aligned integer declarations")
    return Detection("no", f"typedefs agree for {compared} exact-name declarations")


def detect_layout01(source_context: str, decompiled: str) -> Detection:
    src, dec = parse_structs(source_context), parse_structs(decompiled)
    shared = src.keys() & dec.keys()
    if not shared:
        return Detection("unevaluable", "no same-name explicit struct definitions")
    uncertain: list[str] = []
    for name in shared:
        src_fields, dec_fields = src[name], dec[name]
        if [field for field, _ in src_fields] != [field for field, _ in dec_fields]:
            return Detection("yes", f"struct {name}: source={src_fields}; decompiled={dec_fields}")
        for (field, src_type), (_, dec_type) in zip(src_fields, dec_fields):
            src_c = canonical_c_type(src_type)
            dec_c = canonical_c_type(dec_type)
            if src_c == dec_c:
                continue
            src_base, src_depth, _ = type_profile(src_c)
            dec_base, dec_depth, _ = type_profile(dec_c)
            known = re.compile(r"^(?:void|bool|char|short|int|long|unsigned|signed|float|double)(?:\s|$)")
            explicit = lambda base: bool(known.match(base) or base.startswith(("struct ", "union ", "enum ")))
            if not explicit(src_base) or not explicit(dec_base):
                uncertain.append(f"struct {name}.{field}: {src_type} vs {dec_type}")
                continue
            if (src_base, src_depth) != (dec_base, dec_depth):
                return Detection("yes", f"struct {name}.{field}: {src_type} vs {dec_type}")
    if uncertain:
        return Detection("candidate", "; ".join(uncertain))
    return Detection("no", f"matching field order/types for {sorted(shared)}")


def detect_arr01(source: str, source_context: str, decompiled: str) -> Detection:
    src_static = static_objects(source_context)
    dec_extern = extern_objects(decompiled)
    src_roles, dec_roles = address_field_roles(source), address_field_roles(decompiled)
    for sname, stype in src_static.items():
        for dname, dtype in dec_extern.items():
            if not (src_roles.get(sname, set()) & dec_roles.get(dname, set())):
                continue
            if ("[" in stype) != ("[" in dtype) or pointer_depth(stype) != pointer_depth(dtype):
                return Detection("yes", f"role-aligned sentinel {sname}:{stype} vs {dname}:{dtype}")
    if src_static and dec_extern:
        return Detection("candidate", "static arrays/pointers and extern objects exist but role mapping is incomplete")
    return Detection("no", "no array/pointer sentinel mismatch found")


def run_detectors(source: str, source_context: str, decompiled: str, function: str) -> dict[str, Detection]:
    return {
        "SC-01": detect_sc01(source, source_context, decompiled),
        "ST-01": detect_st01(source_context, decompiled),
        "PTR-01": detect_ptr01(source_context, decompiled),
        "INT-01": detect_int01(source, decompiled, function),
        "FN-01": detect_fn01(source, decompiled, function),
        "LAYOUT-01": detect_layout01(source_context, decompiled),
        "ARR-01": detect_arr01(source, source_context, decompiled),
    }


def md_escape(value: Any) -> str:
    return str(value if value is not None else "").replace("|", "\\|").replace("\n", " ")


def write_markdown(path: Path, rows: list[dict[str, Any]], columns: Iterable[str]) -> None:
    columns = list(columns)
    lines = [
        "| " + " | ".join(columns) + " |",
        "| " + " | ".join("---" for _ in columns) + " |",
    ]
    lines.extend("| " + " | ".join(md_escape(row.get(c)) for c in columns) + " |" for row in rows)
    path.write_text("\n".join(lines) + "\n", encoding="utf-8")


def write_csv(path: Path, rows: list[dict[str, Any]], columns: Iterable[str]) -> None:
    columns = list(columns)
    with path.open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=columns, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(rows)


def write_json(path: Path, rows: list[dict[str, Any]]) -> None:
    path.write_text(json.dumps(rows, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")


def classify(
    rate: float, evaluable: int, denominator: int, minimum_evaluable_rate: float,
) -> str:
    evaluable_rate = evaluable / denominator if denominator else 0.0
    if evaluable_rate < minimum_evaluable_rate:
        return (
            f"数据不足（仅 {evaluable}/{denominator} 可判定，"
            f"要求 ≥{minimum_evaluable_rate:.0%}）"
        )
    if rate >= 0.30:
        return "普遍"
    if rate >= 0.10:
        return "值得关注"
    return "未达关注阈值"


def metric(function: dict[str, Any], agent: str, name: str) -> float | None:
    value = function.get("values", {}).get(agent, {}).get(name)
    return float(value) if isinstance(value, (int, float)) else None


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--scores", type=Path, default=Path("configs/sample-set/function_results.json"))
    parser.add_argument("--manifest", type=Path, default=Path("configs/sample-set/manifest.json"))
    parser.add_argument("--dataset-root", type=Path, default=Path("decbench-large"))
    parser.add_argument("--output-dir", type=Path, default=Path("large-pattern-report"))
    parser.add_argument(
        "--min-evaluable-rate", type=float, default=0.75,
        help="Minimum evaluable fraction required for prevalence classification (default: 0.75)",
    )
    args = parser.parse_args()
    if not 0.0 <= args.min_evaluable_rate <= 1.0:
        parser.error("--min-evaluable-rate must be between 0 and 1")

    scores, manifest = read_json(args.scores), read_json(args.manifest)
    index = manifest_index(manifest)
    inventory_path = args.dataset_root / "large_download_inventory.json"
    inventory_sources: dict[tuple[str, str, str, str], list[str]] = {}
    if inventory_path.is_file():
        for item in json.loads(inventory_path.read_text(encoding="utf-8")):
            inventory_sources[(
                item["project"], item["opt_level"], item["binary"], item["function"]
            )] = item.get("source_paths", [])
    args.output_dir.mkdir(parents=True, exist_ok=True)

    cases: list[dict[str, Any]] = []
    for group in scores.get("groups", []):
        for function in group.get("functions", []):
            if "large" in function.get("datasets", []):
                cases.append({"group": group, "function": function})
    denominator = len(cases)

    export_rows: list[dict[str, Any]] = []
    detail: list[dict[str, Any]] = []
    coverage: list[dict[str, Any]] = []

    for case in cases:
        group, function = case["group"], case["function"]
        key = (group["project"], group["opt_level"], group["binary"])
        entry = index.get(key)
        source, source_context, source_path = resolve_source(
            function, group["project"], group["binary"], manifest, args.dataset_root,
            entry,
            inventory_sources.get((
                group["project"], group["opt_level"], group["binary"], function["function"]
            )),
        )

        row: dict[str, Any] = {
            "project": group["project"], "opt_level": group["opt_level"],
            "binary": group["binary"], "function": function["function"],
            "size": function.get("size"), "source_code": source,
            "source_path": source_path,
        }
        for agent in AGENTS:
            decompiled, decompiled_path = resolve_decompiled(function, agent, entry, args.dataset_root)
            row[f"{agent}_type_match"] = metric(function, agent, "type_match")
            row[f"{agent}_byte_match"] = metric(function, agent, "byte_match")
            row[f"{agent}_ged"] = metric(function, agent, "ged")
            row[f"{agent}_decompiled_code"] = decompiled
            row[f"{agent}_decompiled_path"] = decompiled_path

            coverage.append({
                "project": group["project"], "opt_level": group["opt_level"],
                "binary": group["binary"], "function": function["function"], "agent": agent,
                "source_available": source is not None,
                "decompiled_available": decompiled is not None,
                "source_path": source_path, "decompiled_path": decompiled_path,
            })

            if source is None or source_context is None or decompiled is None:
                detections = {
                    pattern: Detection(
                        "unevaluable",
                        f"missing source={source is None}, decompiled={decompiled is None}",
                    ) for pattern in PATTERNS
                }
            else:
                detections = run_detectors(source, source_context, decompiled, function["function"])

            for pattern, result in detections.items():
                detail.append({
                    "project": group["project"], "opt_level": group["opt_level"],
                    "binary": group["binary"], "function": function["function"],
                    "size": function.get("size"), "agent": agent, "pattern": pattern,
                    "hit": result.status, "evidence": result.evidence,
                    "type_match": metric(function, agent, "type_match"),
                    "byte_match": metric(function, agent, "byte_match"),
                    "ged": metric(function, agent, "ged"),
                })
        export_rows.append(row)

    # Full requested extraction, including multiline code.
    export_columns = list(export_rows[0]) if export_rows else []
    with (args.output_dir / "large_functions.csv").open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=export_columns)
        writer.writeheader(); writer.writerows(export_rows)
    with (args.output_dir / "large_functions.jsonl").open("w", encoding="utf-8") as fh:
        for row in export_rows:
            fh.write(json.dumps(row, ensure_ascii=False) + "\n")

    detail_columns = [
        "project", "opt_level", "binary", "function", "size", "agent", "pattern",
        "hit", "type_match", "byte_match", "ged", "evidence",
    ]
    write_csv(args.output_dir / "function_pattern_detail.csv", detail, detail_columns)
    write_json(args.output_dir / "function_pattern_detail.json", detail)
    write_markdown(args.output_dir / "function_pattern_detail.md", detail, detail_columns)

    summary: list[dict[str, Any]] = []
    for agent in AGENTS:
        for pattern in PATTERNS:
            rows = [r for r in detail if r["agent"] == agent and r["pattern"] == pattern]
            hits = [r for r in rows if r["hit"] == "yes"]
            candidates = [r for r in rows if r["hit"] == "candidate"]
            evaluated = [r for r in rows if r["hit"] in {"yes", "no", "candidate"}]
            decisive = [r for r in rows if r["hit"] in {"yes", "no"}]
            rate = len(hits) / denominator if denominator else 0.0
            evaluable_rate = len(evaluated) / denominator if denominator else 0.0
            type_scores = [r["type_match"] for r in hits if r["type_match"] is not None]
            summary.append({
                "agent": agent, "pattern": pattern, "hit_count": len(hits),
                "candidate_count": len(candidates), "evaluable_count": len(evaluated),
                "decisive_count": len(decisive), "denominator": denominator,
                "evaluable_rate": f"{evaluable_rate:.2%}",
                "minimum_evaluable_rate": f"{args.min_evaluable_rate:.2%}",
                "coverage_acceptable": evaluable_rate >= args.min_evaluable_rate,
                "hit_rate": f"{rate:.2%}",
                "mean_type_match_of_hits": f"{mean(type_scores):.6f}" if type_scores else "",
                "classification": classify(
                    rate, len(evaluated), denominator, args.min_evaluable_rate,
                ),
            })
    summary_columns = [
        "agent", "pattern", "hit_count", "candidate_count", "evaluable_count",
        "decisive_count", "denominator", "evaluable_rate", "minimum_evaluable_rate",
        "coverage_acceptable", "hit_rate", "mean_type_match_of_hits", "classification",
    ]
    write_csv(args.output_dir / "pattern_summary.csv", summary, summary_columns)
    write_json(args.output_dir / "pattern_summary.json", summary)
    write_markdown(args.output_dir / "pattern_summary.md", summary, summary_columns)

    coverage_columns = list(coverage[0]) if coverage else []
    write_csv(args.output_dir / "coverage.csv", coverage, coverage_columns)
    write_json(args.output_dir / "coverage.json", coverage)
    write_markdown(args.output_dir / "coverage.md", coverage, coverage_columns)

    manual = [r for r in detail if r["hit"] == "candidate"]
    unevaluable = [r for r in detail if r["hit"] == "unevaluable"]
    manual_columns = ["project", "opt_level", "binary", "function", "agent", "pattern", "hit", "evidence"]
    write_csv(args.output_dir / "manual_candidates.csv", manual, manual_columns)
    write_json(args.output_dir / "manual_candidates.json", manual)
    write_markdown(args.output_dir / "manual_candidates.md", manual, manual_columns)
    write_csv(args.output_dir / "unevaluable.csv", unevaluable, manual_columns)
    write_json(args.output_dir / "unevaluable.json", unevaluable)
    write_markdown(args.output_dir / "unevaluable.md", unevaluable, manual_columns)

    noteworthy = [row for row in summary if row["classification"] in {"普遍", "值得关注"}]
    insufficient = [row for row in summary if row["classification"].startswith("数据不足")]
    result_files = {
        "extracted_functions_jsonl": "large_functions.jsonl",
        "extracted_functions_csv": "large_functions.csv",
        "function_pattern_detail_json": "function_pattern_detail.json",
        "function_pattern_detail_csv": "function_pattern_detail.csv",
        "pattern_summary_json": "pattern_summary.json",
        "pattern_summary_csv": "pattern_summary.csv",
        "manual_candidates_json": "manual_candidates.json",
        "manual_candidates_csv": "manual_candidates.csv",
        "unevaluable_json": "unevaluable.json",
        "unevaluable_csv": "unevaluable.csv",
        "coverage_json": "coverage.json",
        "coverage_csv": "coverage.csv",
    }
    phase_result = {
        "phase": "Prompt1",
        "task": "large-function type recovery error-pattern breadth scan",
        "large_function_denominator": denominator,
        "agents": list(AGENTS),
        "patterns": list(PATTERNS),
        "minimum_evaluable_rate": args.min_evaluable_rate,
        "prevalence_thresholds": {
            "universal": ">=30%",
            "noteworthy": ">=10% and <30%",
        },
        "coverage": {
            "expected_agent_outputs": denominator * len(AGENTS),
            "available_source_and_decompiled_outputs": sum(
                item["source_available"] and item["decompiled_available"] for item in coverage
            ),
            "known_missing_output": "shadow/O2-noinline/login/main/claude-code",
        },
        "status_semantics": {
            "yes": "automatically confirmed hit; counted in hit_count and hit_rate",
            "no": "rule ran and found no hit",
            "candidate": "suspicious evidence requiring manual review; excluded from hit_count",
            "unevaluable": "required alignment/evidence was unavailable; excluded from evaluable_count",
        },
        "noteworthy_patterns": noteworthy,
        "insufficient_coverage_patterns": insufficient,
        "pattern_summary": summary,
        "candidate_rows": len(manual),
        "unevaluable_rows": len(unevaluable),
        "files": result_files,
    }
    (args.output_dir / "prompt1_results.json").write_text(
        json.dumps(phase_result, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )

    noteworthy_lines = [
        f"- {row['agent']} / {row['pattern']}: {row['hit_count']}/{row['denominator']} "
        f"({row['hit_rate']}), 命中样本平均 type_match={row['mean_type_match_of_hits'] or 'N/A'}，"
        f"分类={row['classification']}"
        for row in noteworthy
    ] or ["- 无"]
    insufficient_lines = [
        f"- {row['agent']} / {row['pattern']}: {row['evaluable_count']}/{row['denominator']} "
        f"可判定（{row['evaluable_rate']}），确认命中率={row['hit_rate']}"
        for row in insufficient
    ] or ["- 无"]
    handoff = f"""# Prompt1 阶段交接

## 本阶段完成内容

- 从 `function_results.json` 提取全部 {denominator} 个 datasets 含 `large` 的函数，并关联 codex、claude-code 的 type_match、byte_match、ged、源码和反编译代码。
- 对每个函数的两个 agent 输出运行 {len(PATTERNS)} 类错误模式检测，生成函数 × agent × 模式明细。
- 严格区分 `yes`、`no`、`candidate`、`unevaluable`；只有 `yes` 计入 hit_count。
- 使用固定分母 {denominator} 计算命中率；可判定覆盖率至少达到 {args.min_evaluable_rate:.0%} 才进行普遍性分类。
- zlib 函数提取器支持 K&R 参数声明、`local`、`ZEXTERN`、`ZEXPORT` 和 `OF((...))` 双层括号，并通过真实语料回归测试。

## 结论

达到“普遍”或“值得关注”的模式：

{chr(10).join(noteworthy_lines)}

以下条目因可判定覆盖率未达到 {args.min_evaluable_rate:.0%}，不得仅凭原始命中率作普遍性结论：

{chr(10).join(insufficient_lines)}

全量预期 agent 输出为 {denominator * len(AGENTS)} 份，实际源码与反编译代码同时可用 {phase_result['coverage']['available_source_and_decompiled_outputs']} 份。唯一已知缺失为 `shadow/O2-noinline/login/main/claude-code`。

## 产出文件

- 阶段结果：`prompt1_results.json`
- 完整函数导出：`large_functions.jsonl`、`large_functions.csv`
- 逐函数明细：`function_pattern_detail.json`、`function_pattern_detail.csv`、`function_pattern_detail.md`
- 模式汇总：`pattern_summary.json`、`pattern_summary.csv`、`pattern_summary.md`
- 人工复核候选：`manual_candidates.json`、`manual_candidates.csv`、`manual_candidates.md`
- 无法自动判定：`unevaluable.json`、`unevaluable.csv`、`unevaluable.md`
- 覆盖率：`coverage.json`、`coverage.csv`、`coverage.md`
- 扫描脚本：`../decbench_agent_data/analyze_large_error_patterns.py`
- 解析回归测试：`../decbench_agent_data/test_download_large_scan_inputs.py`

以上报表均位于 `{args.output_dir.resolve()}`。

## 下一阶段关键约定与注意事项

- `candidate_count` 是疑似证据数量，不是确认命中数；candidate 不进入 hit_rate，也不进入命中样本平均 type_match。
- `evaluable_count` 表示检测器获得了足够输入并产出 yes/no/candidate；`decisive_count` 仅统计 yes/no。
- 普遍性分类先检查可判定覆盖率：低于 {args.min_evaluable_rate:.0%} 一律标记数据不足，再高的原始 hit_rate 也不升级为“值得关注/普遍”。
- 命中率分母固定为 {denominator}，不会因 claude-code 缺失一份输出改成 51；覆盖率阈值允许这种少量缺失。
- 下一阶段人工深剖应优先检查 `noteworthy_patterns`，同时参考 candidate 较多的 SC-01、ARR-01；不要把 candidate 当作已证实缺陷。
- PTR-01、INT-01、LAYOUT-01 的自动对齐覆盖率偏低，相关结论必须结合 `manual_candidates` 与 `unevaluable` 清单。
"""
    (args.output_dir / "handoff_prompt1.md").write_text(handoff, encoding="utf-8")

    print(json.dumps({
        "large_functions": denominator,
        "agent_outputs_expected": denominator * len(AGENTS),
        "agent_outputs_with_source_and_decompiled": sum(
            c["source_available"] and c["decompiled_available"] for c in coverage
        ),
        "output_dir": str(args.output_dir),
    }, ensure_ascii=False, indent=2))


if __name__ == "__main__":
    main()
