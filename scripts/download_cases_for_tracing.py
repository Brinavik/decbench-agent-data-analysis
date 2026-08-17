#!/usr/bin/env python3
"""Download traces and traditional decompiler output for selected cases."""

from __future__ import annotations

import argparse
import json
import logging
from pathlib import Path
from typing import Any

from huggingface_hub import hf_hub_download

try:
    from requests.exceptions import HTTPError
except ImportError:  # Newer huggingface_hub stacks may use httpx without requests.
    class HTTPError(Exception):
        """Compatibility placeholder when requests is not installed."""


REPO_ID = "noelo-lab/decbench-dataset"
REPO_TYPE = "dataset"
DEFAULT_LOCAL_DIR = "decbench_deep_cases"
SUPPORTED_AGENTS = ("codex", "claude-code")


def _validate_component(name: str, value: str) -> str:
    """Reject empty or path-like coordinates before constructing repo paths."""
    if not value or value in {".", ".."} or "/" in value or "\\" in value:
        raise ValueError(f"Invalid {name}: {value!r}")
    return value


def download_case_trace(
    project: str,
    opt: str,
    binary: str,
    function: str,
    agent: str,
    local_dir: str | Path = DEFAULT_LOCAL_DIR,
) -> dict[str, str | None]:
    """Download one agent's two trace files plus IDA and Ghidra C output.

    Each target is attempted independently. The returned mapping uses repository
    filenames as keys and local paths as values; failed downloads map to None.
    """
    project = _validate_component("project", project)
    opt = _validate_component("opt", opt)
    binary = _validate_component("binary", binary)
    function = _validate_component("function", function)
    agent = _validate_component("agent", agent)

    trace_stem = f"{opt}__{project}__{binary}__{function}"
    filenames = (
        f"results/{agent}/traces/{trace_stem}.md",
        f"results/{agent}/traces/{trace_stem}.session.jsonl",
        f"results/ida/{opt}/{project}/{binary}.c",
        f"results/ghidra/{opt}/{project}/{binary}.c",
    )

    destination = Path(local_dir).expanduser().resolve()
    destination.mkdir(parents=True, exist_ok=True)
    downloaded: dict[str, str | None] = {}

    for filename in filenames:
        try:
            local_path = hf_hub_download(
                repo_id=REPO_ID,
                repo_type=REPO_TYPE,
                filename=filename,
                local_dir=str(destination),
            )
        except HTTPError as exc:
            status = getattr(getattr(exc, "response", None), "status_code", None)
            detail = f"HTTP {status}" if status is not None else "HTTP error"
            logging.error("Failed to download %s (%s): %s", filename, detail, exc)
            downloaded[filename] = None
        except (OSError, ValueError) as exc:
            logging.error("Failed to store or resolve %s: %s", filename, exc)
            downloaded[filename] = None
        except Exception as exc:  # Hugging Face error classes vary by version.
            logging.error("Unexpected download failure for %s: %s", filename, exc)
            downloaded[filename] = None
        else:
            downloaded[filename] = local_path
            logging.info("Downloaded %s -> %s", filename, local_path)

    return downloaded


def _load_cases(case_list: Path) -> list[dict[str, Any]]:
    with case_list.open(encoding="utf-8") as handle:
        payload = json.load(handle)
    cases = payload.get("cases")
    if not isinstance(cases, list):
        raise ValueError(f"{case_list} must contain a top-level 'cases' list")
    return cases


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Download LLM traces and IDA/Ghidra output for selected cases."
    )
    parser.add_argument(
        "--case-list",
        type=Path,
        default=Path(__file__).with_name("case_list_for_tracing.json"),
        help="JSON case list (default: case_list_for_tracing.json next to this script)",
    )
    parser.add_argument(
        "--local-dir",
        type=Path,
        default=Path(DEFAULT_LOCAL_DIR),
        help=f"Download root (default: {DEFAULT_LOCAL_DIR})",
    )
    parser.add_argument(
        "--agent",
        choices=("both",) + SUPPORTED_AGENTS,
        default="both",
        help="Trace-producing agent(s) to download (default: both)",
    )
    args = parser.parse_args()

    logging.basicConfig(level=logging.INFO, format="%(levelname)s: %(message)s")

    try:
        cases = _load_cases(args.case_list)
    except (OSError, ValueError, json.JSONDecodeError) as exc:
        logging.error("Cannot load case list %s: %s", args.case_list, exc)
        return 2

    agents = SUPPORTED_AGENTS if args.agent == "both" else (args.agent,)
    failed = 0
    for case in cases:
        try:
            coordinates = {
                key: case[key]
                for key in ("project", "opt", "binary", "function")
            }
        except (KeyError, TypeError) as exc:
            logging.error("Skipping malformed case %r: %s", case, exc)
            failed += 1
            continue

        for agent in agents:
            results = download_case_trace(
                **coordinates,
                agent=agent,
                local_dir=args.local_dir,
            )
            failed += sum(path is None for path in results.values())

    if failed:
        logging.warning("Completed with %d failed file download(s)", failed)
        return 1
    logging.info("All requested files are available under %s", args.local_dir)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
