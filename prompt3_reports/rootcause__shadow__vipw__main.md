# Prompt3 根因报告：shadow/vipw/main

## 报告元数据

- report_id: `rootcause__shadow__vipw__main`
- case: `shadow` / `O2-noinline` / `vipw` / `main` / 137 lines

输入文件：

- source: `decbench-large/sources/shadow/vipw.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/shadow/vipw.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/shadow/vipw.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/shadow/vipw.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/shadow/vipw.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__shadow__vipw__main.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__shadow__vipw__main.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.4 | 0.0 | 2.0 |
| claude-code | 0.5 | 0.0 | 0.0 |

## 类型/声明错误

未发现可人工确认的类型/声明层错误。不可由 stripped binary 确定的 `static` 等信息未强行计错。
## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | main 完整签名 | int main(int argc, char **argv) | int main(int argc, char **argv) | 返回类型、参数宽度和指针层级正确。 |
| codex | long_options | static struct option[] | static struct option[] | 存储类别、结构体数组和静态初始化正确。 |
| codex | do_vipw/editshadow | _Bool | bool | 等价布尔类型。 |
| claude-code | main 完整签名 | int main(int argc, char **argv) | int main(int argc, char **argv) | 正确。 |
| claude-code | long_options | static struct option[] | static struct option[] | 正确恢复 static 数组。 |
| claude-code | 函数指针参数 | int (*)(void) | int (*)(void) | vipwedit helper 原型中的函数指针正确。 |

## 汇总

- error_count_by_agent: `{"codex": 0, "claude-code": 0}`
- error_count_by_pattern: `{}`
- error_count_by_root_cause: `{}`
- error_count_by_attribution: `{}`
- correct_count_by_agent: `{"codex": 3, "claude-code": 3}`

关键结论：

- 本 case 未发现可人工确认的类型/声明错误；type_match 非满分主要反映评测实体覆盖/对齐口径，而非明确错误模式。
- 两 agent 都恢复 main 与 static long_options，说明大型函数并不必然导致存储类别或签名失败。
- Claude GED=0 但 byte_match=0，继续说明结构/类型/字节指标彼此独立。
