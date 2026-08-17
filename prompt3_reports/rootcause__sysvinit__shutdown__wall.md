# Prompt3 根因报告：sysvinit/shutdown/wall

## 报告元数据

- report_id: `rootcause__sysvinit__shutdown__wall`
- case: `sysvinit` / `O2-noinline` / `shutdown` / `wall` / 165 lines

输入文件：

- source: `decbench-large/sources/sysvinit/dowall.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/sysvinit/shutdown.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/sysvinit/shutdown.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/sysvinit/shutdown.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/sysvinit/shutdown.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__sysvinit__shutdown__wall.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__sysvinit__shutdown__wall.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.10526315789473684 | 0.925764192139738 | 5.0 |
| claude-code | 0.10526315789473684 | 0.5985401459854015 | 10.0 |

## 类型/声明错误

### E-CX-001 — codex / QUAL-01

- 实体：函数第1参数 text
- 源码（行 133）：`const char *text`
- 反编译（行 15）：`char *message`
- 错误：丢失 const。
- trace 原文：> void sub_4540(char *message, int remote)
- 引入步骤：最终原型依据寄存器/传递行为生成，未保留不可由 ABI 观察的 const。
- 根因：`b_info_missing` — 函数内只读使用不能证明源码是否声明 const。
- 归因：`function_inherent_difficulty`

### E-CL-001 — claude-code / QUAL-01

- 实体：函数第1参数 text
- 源码（行 133）：`const char *text`
- 反编译（行 22）：`char *msg`
- 错误：丢失 const。
- trace 原文：> **Signature:** `void sub_4540(char *msg, int remote)` — this is a `wall`-style message broadcaster.
- 引入步骤：签名推断只使用 rdi→msg、esi→remote 的 ABI 证据；未恢复 const。
- 根因：`b_info_missing` — const 不进入调用约定。
- 归因：`function_inherent_difficulty`

### E-CL-002 — claude-code / ARRAY-01

- 实体：局部终端路径缓冲 term
- 源码（行 139-143）：`char term[32 + strlen("/dev/") + 1]（38）`
- 反编译（行 24）：`char line[dev_len + 0x30]（53）`
- 错误：数组长度多加15字节。
- trace 原文：> size_t dev_len = strlen("/dev/");
> char line[dev_len + 0x30];      /* "/dev/" + terminal name */
- 引入步骤：把动态栈对齐/分配量 0x30 当成源码字符容量，而不是对 38 字节 VLA 的16字节对齐。
- 根因：`a_llm_reasoning_defect` — 汇编栈分配包含对齐；将对齐后的空间误写进数组界限。
- 归因：`function_inherent_difficulty`

## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | 函数返回类型 | void | void | 正确。 |
| codex | term 数组长度 | 38 | sizeof(ut->ut_line)+strlen("/dev/")+1 | 等价恢复。 |
| codex | line/hostname | char[256] / char[65] | char[256] / char[65] | 固定数组正确。 |
| codex | struct sigaction/utmp | 源码系统结构体 | 相同系统结构体 | 没有自造冲突布局。 |
| claude-code | 函数返回类型和第2参数 | void, int | void, int | 正确。 |
| claude-code | header/host | char[256] / char[65] | char[256] / char[65] | 固定缓冲恢复正确。 |
| claude-code | time/local pointers | time_t; char * | time_t; char * | 时间及字符串游标类型正确。 |

## 汇总

- error_count_by_agent: `{"codex": 1, "claude-code": 2}`
- error_count_by_pattern: `{"QUAL-01": 2, "ARRAY-01": 1}`
- error_count_by_root_cause: `{"b_info_missing": 2, "a_llm_reasoning_defect": 1}`
- error_count_by_attribution: `{"function_inherent_difficulty": 3}`
- correct_count_by_agent: `{"codex": 4, "claude-code": 3}`

关键结论：

- 两 LLM 同时丢失参数 const，而 Ghidra/IDA 也未恢复，属于二进制固有信息缺失。
- Claude 将栈对齐量混入 VLA 逻辑长度，是反汇编到源码数组声明映射的典型缺陷。
- Codex 对 VLA 用 ut_line 字段宽度表达，数组恢复优于 Claude。
