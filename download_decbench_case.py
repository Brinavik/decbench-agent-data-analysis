from pathlib import Path

from huggingface_hub import hf_hub_download


REPO_ID = "noelo-lab/decbench-dataset"
REPO_TYPE = "dataset"
LOCAL_DIR = Path("./decbench-case")

# shadow/O2-noinline/groupmod, function grp_update
FILES = [
    "sources/shadow/groupmod.c",
    "sources/shadow/groupmod.a80e20ce.c",
    "results/codex/O2-noinline/shadow/groupmod.c",
    "results/claude-code/O2-noinline/shadow/groupmod.c",
    "results/ida/O2-noinline/shadow/groupmod.c",
    "results/ghidra/O2-noinline/shadow/groupmod.c",
    "results/codex/traces/O2-noinline__shadow__groupmod__grp_update.md",
    "results/codex/traces/O2-noinline__shadow__groupmod__grp_update.session.jsonl",
    "results/claude-code/traces/O2-noinline__shadow__groupmod__grp_update.md",
    "results/claude-code/traces/O2-noinline__shadow__groupmod__grp_update.session.jsonl",
]


def main() -> None:
    LOCAL_DIR.mkdir(parents=True, exist_ok=True)
    for filename in FILES:
        path = hf_hub_download(
            repo_id=REPO_ID,
            repo_type=REPO_TYPE,
            filename=filename,
            local_dir=str(LOCAL_DIR),
        )
        print(path)


if __name__ == "__main__":
    main()
