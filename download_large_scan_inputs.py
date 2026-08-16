#!/usr/bin/env python3
"""Download the minimum local corpus needed to scan all DecBench large cases.

Downloads:
  * Codex and Claude-Code result C files for every large case.
  * Small source_cfg JSON files, used as source-location hints.
  * Source C files, stopping once each target function has a local definition.

The original Hugging Face repository layout is retained under --local-dir.
An inventory JSON/CSV records every selected case and verified local path.
"""

from __future__ import annotations

import argparse
import csv
import json
import re
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable

from huggingface_hub import hf_hub_download


REPO_ID = "noelo-lab/decbench-dataset"
REPO_TYPE = "dataset"
AGENTS = ("codex", "claude-code")


@dataclass(frozen=True)
class Case:
    project: str
    opt_level: str
    binary: str
    function: str

    @property
    def key(self) -> tuple[str, str, str]:
        return self.project, self.opt_level, self.binary


def read_json(path: Path) -> dict[str, Any]:
    return json.loads(path.read_text(encoding="utf-8"))


def large_cases(scores: dict[str, Any]) -> list[Case]:
    result: list[Case] = []
    for group in scores.get("groups", []):
        for function in group.get("functions", []):
            if "large" in function.get("datasets", []):
                result.append(Case(
                    group["project"], group["opt_level"],
                    group["binary"], function["function"],
                ))
    return result


def binary_index(manifest: dict[str, Any]) -> dict[tuple[str, str, str], dict[str, Any]]:
    binaries = manifest.get("binaries", [])
    entries = binaries.values() if isinstance(binaries, dict) else binaries
    return {(e["project"], e["opt"], e["binary"]): e for e in entries}


def download_one(filename: str, local_dir: Path) -> Path:
    path = hf_hub_download(
        repo_id=REPO_ID,
        repo_type=REPO_TYPE,
        filename=filename,
        local_dir=str(local_dir),
    )
    return Path(path)


def local_file_ready(local_dir: Path, filename: str) -> bool:
    path = local_dir / filename
    return path.is_file() and path.stat().st_size > 0


def download_many(files: Iterable[str], local_dir: Path, workers: int) -> dict[str, str]:
    # Safe resume: files already present and non-empty are not downloaded or
    # overwritten.  Hugging Face's own cache also resumes interrupted blobs.
    unique = sorted(name for name in set(files) if not local_file_ready(local_dir, name))
    failures: dict[str, str] = {}
    if not unique:
        return failures
    with ThreadPoolExecutor(max_workers=workers) as pool:
        futures = {pool.submit(download_one, name, local_dir): name for name in unique}
        for future in as_completed(futures):
            name = futures[future]
            try:
                future.result()
            except Exception as exc:  # inventory needs the exact remote failure
                failures[name] = f"{type(exc).__name__}: {exc}"
    return failures


def all_strings(value: Any) -> Iterable[str]:
    if isinstance(value, str):
        yield value
    elif isinstance(value, dict):
        for key, item in value.items():
            yield from all_strings(key)
            yield from all_strings(item)
    elif isinstance(value, list):
        for item in value:
            yield from all_strings(item)


def _matching_paren(text: str, opening: int) -> int | None:
    """Return the matching ')' while ignoring comments and quoted strings."""
    depth = 0
    quote: str | None = None
    escape = False
    line_comment = False
    block_comment = False
    pos = opening
    while pos < len(text):
        c = text[pos]
        nxt = text[pos + 1] if pos + 1 < len(text) else ""
        if line_comment:
            if c == "\n":
                line_comment = False
        elif block_comment:
            if c == "*" and nxt == "/":
                block_comment = False
                pos += 1
        elif quote:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == quote:
                quote = None
        elif c == "/" and nxt == "/":
            line_comment = True
            pos += 1
        elif c == "/" and nxt == "*":
            block_comment = True
            pos += 1
        elif c in {'"', "'"}:
            quote = c
        elif c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if depth == 0:
                return pos
        pos += 1
    return None


def _kr_parameter_names(argument_text: str) -> set[str]:
    """Return old-style identifier-list parameters, or an empty set for ANSI C."""
    value = argument_text.strip()
    if not value:
        return set()
    parts = [part.strip() for part in value.split(",")]
    if parts and all(re.fullmatch(r"[A-Za-z_]\w*", part) for part in parts):
        return set(parts)
    return set()


def _definition_body_open(text: str, closing: int, kr_names: set[str]) -> int | None:
    """Return the function-body ``{`` while accepting K&R declarations.

    ANSI definitions reach a top-level '{' without a preceding ';'.  K&R
    definitions contain one or more parameter declarations ending in ';'
    before that brace.  A prototype/call reaches ';' without declaring the
    identifier-list parameters and is rejected immediately.
    """
    pos = closing + 1
    limit = min(len(text), pos + 65536)
    segment_start = pos
    declared: set[str] = set()
    paren_depth = 0
    bracket_depth = 0
    quote: str | None = None
    escape = False
    line_comment = False
    block_comment = False

    while pos < limit:
        c = text[pos]
        nxt = text[pos + 1] if pos + 1 < len(text) else ""
        if line_comment:
            if c == "\n":
                line_comment = False
        elif block_comment:
            if c == "*" and nxt == "/":
                block_comment = False
                pos += 1
        elif quote:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == quote:
                quote = None
        elif c == "/" and nxt == "/":
            line_comment = True
            pos += 1
        elif c == "/" and nxt == "*":
            block_comment = True
            pos += 1
        elif c in {'"', "'"}:
            quote = c
        elif c == "(":
            paren_depth += 1
        elif c == ")" and paren_depth:
            paren_depth -= 1
        elif c == "[":
            bracket_depth += 1
        elif c == "]" and bracket_depth:
            bracket_depth -= 1
        elif paren_depth == 0 and bracket_depth == 0:
            if c == "{":
                if not kr_names or kr_names <= declared or not declared:
                    return pos
                return None
            if c == "}":
                return None
            if c == ";":
                if not kr_names:
                    return None
                declaration = text[segment_start:pos]
                names_here = {
                    name for name in kr_names
                    if re.search(rf"\b{re.escape(name)}\b", declaration)
                }
                if not names_here:
                    return None
                declared.update(names_here)
                segment_start = pos + 1
        pos += 1
    return None


def _matching_brace(text: str, opening: int) -> int | None:
    """Return the matching function-body brace, ignoring strings/comments."""
    depth = 0
    quote: str | None = None
    escape = False
    line_comment = False
    block_comment = False
    pos = opening
    while pos < len(text):
        c = text[pos]
        nxt = text[pos + 1] if pos + 1 < len(text) else ""
        if line_comment:
            if c == "\n":
                line_comment = False
        elif block_comment:
            if c == "*" and nxt == "/":
                block_comment = False
                pos += 1
        elif quote:
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == quote:
                quote = None
        elif c == "/" and nxt == "/":
            line_comment = True
            pos += 1
        elif c == "/" and nxt == "*":
            block_comment = True
            pos += 1
        elif c in {'"', "'"}:
            quote = c
        elif c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                return pos
        pos += 1
    return None


def _mask_comments_and_strings(text: str) -> str:
    """Replace non-code text with spaces while preserving character offsets."""
    chars = list(text)
    quote: str | None = None
    escape = False
    line_comment = False
    block_comment = False
    pos = 0
    while pos < len(chars):
        c = chars[pos]
        nxt = chars[pos + 1] if pos + 1 < len(chars) else ""
        if line_comment:
            if c == "\n":
                line_comment = False
            else:
                chars[pos] = " "
        elif block_comment:
            chars[pos] = " "
            if c == "*" and nxt == "/":
                chars[pos + 1] = " "
                block_comment = False
                pos += 1
        elif quote:
            chars[pos] = " "
            if escape:
                escape = False
            elif c == "\\":
                escape = True
            elif c == quote:
                quote = None
        elif c == "/" and nxt == "/":
            chars[pos] = chars[pos + 1] = " "
            line_comment = True
            pos += 1
        elif c == "/" and nxt == "*":
            chars[pos] = chars[pos + 1] = " "
            block_comment = True
            pos += 1
        elif c in {'"', "'"}:
            chars[pos] = " "
            quote = c
        pos += 1
    return "".join(chars)


def extract_function_definition(text: str, function: str) -> str | None:
    """Extract an ANSI, K&R, or ``OF((...))`` function definition."""
    pattern = re.compile(rf"\b{re.escape(function)}\b\s*(?:OF\s*)?\(")
    searchable = _mask_comments_and_strings(text)
    for match in pattern.finditer(searchable):
        match_line_start = text.rfind("\n", 0, match.start()) + 1
        if text[match_line_start:match.start()].lstrip().startswith("#"):
            continue
        opening = text.find("(", match.start(), match.end())
        closing = _matching_paren(text, opening)
        if closing is None:
            continue
        kr_names = _kr_parameter_names(text[opening + 1 : closing])
        body_open = _definition_body_open(text, closing, kr_names)
        if body_open is None:
            continue
        body_close = _matching_brace(text, body_open)
        if body_close is None:
            continue
        start = match_line_start
        # C commonly places storage class / return type on preceding lines.
        # Include declaration-looking lines, but never cross a prior statement,
        # preprocessor directive, comment, initializer, or function body.
        cursor = start
        for _ in range(8):
            previous_end = max(cursor - 1, 0)
            previous_start = text.rfind("\n", 0, previous_end) + 1
            if previous_start == cursor:
                break
            line = text[previous_start:previous_end].strip()
            if not line:
                cursor = previous_start
                continue
            if (line.startswith(("#", "//", "/*", "*")) or
                    line.endswith((";", "{", "}")) or "=" in line):
                break
            start = previous_start
            cursor = previous_start
        return text[start : body_close + 1].strip() + "\n"
    return None


def looks_like_definition(text: str, function: str) -> bool:
    """Recognize ANSI, zlib K&R, and zlib ``OF((...))`` definitions.

    Modifiers before the function name (``local``, ``ZEXTERN``, ``ZEXPORT``)
    require no special treatment.  ``OF`` is allowed between the name and its
    outer parenthesis, whose nested pair is handled by ``_matching_paren``.
    """
    return extract_function_definition(text, function) is not None


def source_hint_score(path: str, case: Case, cfg_strings: set[str]) -> tuple[int, str]:
    name = Path(path).name.lower()
    stem = name[:-2] if name.endswith(".c") else name
    binary = case.binary.lower()
    function = case.function.lower()
    score = 0
    if name == f"{binary}.c":
        score += 1000
    if stem.startswith(binary + "."):
        score += 900
    if binary in name:
        score += 500
    if function in name:
        score += 300
    # zlib's minigzipsh target is built from minigzip.c, while the binary name
    # itself has no same-named source file in the manifest.
    if case.project == "zlib" and binary == "minigzipsh" and name == "minigzip.c":
        score += 850
    if path in cfg_strings or name in cfg_strings:
        score += 1200
    if any(path.endswith(s) or s.endswith(path) for s in cfg_strings if s.endswith(".c")):
        score += 1100
    # Prefer unhashed aggregate source before generated/hash variants.
    if re.search(r"\.[0-9a-f]{8}\.c$", name):
        score -= 20
    return -score, path


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--scores", type=Path, default=Path("configs/sample-set/function_results.json"))
    parser.add_argument("--manifest", type=Path, default=Path("configs/sample-set/manifest.json"))
    parser.add_argument("--local-dir", type=Path, default=Path("decbench-large"))
    parser.add_argument(
        "--workers", type=int, default=1,
        help="Concurrent downloads (default: 1 for unstable networks; try 4 or 8 for parallel mode)",
    )
    args = parser.parse_args()
    if args.workers < 1:
        parser.error("--workers must be at least 1")

    scores, manifest = read_json(args.scores), read_json(args.manifest)
    cases = large_cases(scores)
    if len(cases) != 52:
        raise RuntimeError(f"Expected 52 large functions, found {len(cases)}")
    index = binary_index(manifest)

    missing_entries = [case for case in cases if case.key not in index]
    if missing_entries:
        raise RuntimeError(f"Manifest entries missing: {missing_entries}")

    # Phase 1: all agent C outputs and tiny source-CFG metadata.
    initial_files: set[str] = set()
    for case in cases:
        entry = index[case.key]
        for agent in AGENTS:
            result = entry.get("results", {}).get(agent)
            if not result:
                raise RuntimeError(f"Missing {agent} result path for {case}")
            initial_files.add(result)
        if entry.get("source_cfg_path"):
            initial_files.add(entry["source_cfg_path"])

    already_present = sum(local_file_ready(args.local_dir, name) for name in initial_files)
    print(json.dumps({
        "phase": "initial-download",
        "files_total": len(initial_files),
        "files_reused": already_present,
        "files_to_download": len(initial_files) - already_present,
        "workers": args.workers,
    }, ensure_ascii=False), flush=True)
    failures = download_many(initial_files, args.local_dir, args.workers)

    # Phase 2: locate one or more source definitions for every function.
    project_sources = {
        project: data.get("sources", [])
        for project, data in manifest.get("projects", {}).items()
    }
    source_paths: dict[Case, list[str]] = {case: [] for case in cases}

    for case in cases:
        entry = index[case.key]
        cfg_strings: set[str] = set()
        cfg_rel = entry.get("source_cfg_path")
        cfg_path = args.local_dir / cfg_rel if cfg_rel else None
        if cfg_path and cfg_path.is_file():
            try:
                cfg_strings = set(all_strings(read_json(cfg_path)))
            except (json.JSONDecodeError, OSError):
                pass

        candidates = sorted(
            project_sources.get(case.project, []),
            key=lambda path: source_hint_score(path, case, cfg_strings),
        )

        # Stop at the first verified definition.  Download a same-basename hash
        # variant too when already adjacent, since it may preserve expanded APIs.
        for rel in candidates:
            local = args.local_dir / rel
            if not local.is_file():
                try:
                    download_one(rel, args.local_dir)
                except Exception as exc:
                    failures[rel] = f"{type(exc).__name__}: {exc}"
                    continue
            try:
                text = local.read_text(encoding="utf-8", errors="replace")
            except OSError as exc:
                failures[rel] = f"{type(exc).__name__}: {exc}"
                continue
            if looks_like_definition(text, case.function):
                source_paths[case].append(rel)
                break

    inventory: list[dict[str, Any]] = []
    for case in cases:
        entry = index[case.key]
        result_paths = {agent: entry["results"][agent] for agent in AGENTS}
        row: dict[str, Any] = {
            "project": case.project,
            "opt_level": case.opt_level,
            "binary": case.binary,
            "function": case.function,
            "source_paths": source_paths[case],
            "source_verified": bool(source_paths[case]),
        }
        for agent, rel in result_paths.items():
            local = args.local_dir / rel
            row[f"{agent}_path"] = rel
            row[f"{agent}_downloaded"] = local.is_file() and local.stat().st_size > 0
            row[f"{agent}_contains_function"] = (
                looks_like_definition(local.read_text(encoding="utf-8", errors="replace"), case.function)
                if local.is_file() else False
            )
        inventory.append(row)

    args.local_dir.mkdir(parents=True, exist_ok=True)
    inventory_json = args.local_dir / "large_download_inventory.json"
    inventory_json.write_text(json.dumps(inventory, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    inventory_csv = args.local_dir / "large_download_inventory.csv"
    columns = [
        "project", "opt_level", "binary", "function", "source_paths", "source_verified",
        "codex_path", "codex_downloaded", "codex_contains_function",
        "claude-code_path", "claude-code_downloaded", "claude-code_contains_function",
    ]
    with inventory_csv.open("w", encoding="utf-8", newline="") as fh:
        writer = csv.DictWriter(fh, fieldnames=columns)
        writer.writeheader()
        for row in inventory:
            writer.writerow({**row, "source_paths": ";".join(row["source_paths"])})

    summary = {
        "large_functions": len(cases),
        "unique_initial_files": len(initial_files),
        "verified_source_functions": sum(row["source_verified"] for row in inventory),
        "codex_results_downloaded": sum(row["codex_downloaded"] for row in inventory),
        "codex_results_containing_function": sum(row["codex_contains_function"] for row in inventory),
        "claude_code_results_downloaded": sum(row["claude-code_downloaded"] for row in inventory),
        "claude_code_results_containing_function": sum(row["claude-code_contains_function"] for row in inventory),
        "download_failures": failures,
        "inventory_json": str(inventory_json),
        "inventory_csv": str(inventory_csv),
    }
    summary_path = args.local_dir / "large_download_summary.json"
    summary_path.write_text(json.dumps(summary, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(summary, ensure_ascii=False, indent=2))

    complete = (
        summary["verified_source_functions"] == len(cases)
        and summary["codex_results_downloaded"] == len(cases)
        and summary["claude_code_results_downloaded"] == len(cases)
        and summary["codex_results_containing_function"] == len(cases)
        and summary["claude_code_results_containing_function"] == len(cases)
    )
    if not complete:
        raise SystemExit(2)


if __name__ == "__main__":
    main()
