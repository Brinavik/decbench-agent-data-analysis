#!/usr/bin/env python3
"""Run semantic adjudication tasks with resumable codex exec workers."""

from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
from pathlib import Path
import subprocess
import threading
import time
from typing import Any


ROOT = Path(__file__).resolve().parent


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--tasks", type=Path, default=ROOT / "tasks.json")
    p.add_argument("--template", type=Path, default=ROOT / "prompt_template.txt")
    p.add_argument("--dataset-root", type=Path, default=ROOT / "decbench-large")
    p.add_argument("--output-dir", type=Path, default=ROOT / "adjudication_results")
    p.add_argument("--concurrency", "-j", type=int, default=1)
    p.add_argument("--timeout", type=float, default=1800.0, help="seconds per attempt")
    p.add_argument("--retries", type=int, default=2, help="retries after the first attempt")
    p.add_argument("--codex", default="codex", help="codex executable")
    return p.parse_args()


def load_tasks(path: Path) -> list[dict[str, Any]]:
    with path.open(encoding="utf-8") as f:
        tasks = json.load(f)
    if not isinstance(tasks, list):
        raise ValueError(f"{path} must contain a JSON array")
    return tasks


def render(template: str, task: dict[str, Any], output_path: Path, dataset_root: Path) -> str:
    values = dict(task)
    values["source_path"] = str((dataset_root / task["source_path"]).resolve())
    values["decompiled_path"] = str((dataset_root / task["decompiled_path"]).resolve())
    values["output_path"] = str(output_path.resolve())
    rendered = template
    for key in ("source_path", "decompiled_path", "decompiler", "function", "hypothesis", "output_path"):
        rendered = rendered.replace("{" + key + "}", str(values[key]))
    return rendered


def run_one(task: dict[str, Any], template: str, args: argparse.Namespace, log_lock: threading.Lock) -> tuple[str, bool, str]:
    args.output_dir.mkdir(parents=True, exist_ok=True)
    output = args.output_dir / f"{task['task_id']}.json"
    if output.exists():
        return task["task_id"], True, "skipped (output exists)"

    source = args.dataset_root / task["source_path"]
    decompiled = args.dataset_root / task["decompiled_path"]
    if not source.is_file() or not decompiled.is_file():
        msg = f"missing input: source={source} decompiled={decompiled}"
        with log_lock:
            (args.output_dir / "failures.log").open("a", encoding="utf-8").write(task["task_id"] + "\t" + msg + "\n")
        return task["task_id"], False, msg

    prompt = render(template, task, output, args.dataset_root)
    attempts = args.retries + 1
    last_error = ""
    for attempt in range(1, attempts + 1):
        try:
            proc = subprocess.run(
                [args.codex, "exec", "--full-auto", "--skip-git-repo-check", "-C", str(ROOT), "-"],
                input=prompt,
                text=True,
                capture_output=True,
                timeout=args.timeout,
                check=False,
            )
            if proc.returncode == 0 and output.is_file():
                with output.open(encoding="utf-8") as f:
                    json.load(f)
                return task["task_id"], True, f"completed attempt {attempt}"
            last_error = f"exit={proc.returncode}, output_exists={output.exists()}"
            if proc.stderr:
                last_error += f", stderr={proc.stderr[-500:].strip()}"
        except subprocess.TimeoutExpired:
            last_error = f"timeout after {args.timeout}s"
        except OSError as exc:
            last_error = f"exec error: {exc}"
        if output.exists():
            output.unlink()

    with log_lock:
        with (args.output_dir / "failures.log").open("a", encoding="utf-8") as f:
            f.write(task["task_id"] + "\t" + last_error + "\n")
    return task["task_id"], False, last_error


def main() -> int:
    args = parse_args()
    if args.concurrency < 1 or args.retries < 0 or args.timeout <= 0:
        raise SystemExit("concurrency >= 1, retries >= 0, timeout > 0 required")
    template = args.template.read_text(encoding="utf-8")
    tasks = load_tasks(args.tasks)
    args.output_dir.mkdir(parents=True, exist_ok=True)
    lock = threading.Lock()
    started = time.monotonic()
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.concurrency) as pool:
        futures = [pool.submit(run_one, t, template, args, lock) for t in tasks]
        for future in concurrent.futures.as_completed(futures):
            task_id, ok, message = future.result()
            print(f"{'OK' if ok else 'FAIL'}\t{task_id}\t{message}", flush=True)
    print(f"finished {len(tasks)} tasks in {time.monotonic() - started:.1f}s")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
