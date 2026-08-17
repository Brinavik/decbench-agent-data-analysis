# Prompt3 根因报告：e2fsprogs/e2fsck/check_ea_in_inode

## 报告元数据

- report_id: `rootcause__e2fsprogs__e2fsck__check_ea_in_inode`
- case: `e2fsprogs` / `O2-noinline` / `e2fsck` / `check_ea_in_inode` / 159 lines

输入文件：

- source: `decbench-large/sources/e2fsprogs/pass1.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/e2fsprogs/e2fsck.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/e2fsprogs/e2fsck.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/e2fsprogs/e2fsck.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/e2fsprogs/e2fsck.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__e2fsprogs__e2fsck__check_ea_in_inode.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__e2fsprogs__e2fsck__check_ea_in_inode.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.35714285714285715 | 0.2708333333333333 | 4.0 |
| claude-code | 0.21428571428571427 | 0.0 | 17.0 |

## 类型/声明错误

### E-CL-001 — claude-code / FN-01

- 实体：函数返回类型
- 源码（行 4252-4253）：`static void check_ea_in_inode(...) `
- 反编译（行 115-116）：`static int check_ea_in_inode(...)`
- 错误：把 void 恢复为 int，并在各路径 return 0。
- trace 原文：> **Signature** — `(e2fsck_t ctx, struct problem_context *pctx, struct ea_quota *ea_ibody_quota)`
- 引入步骤：总结只列出参数且正确解释 rdx 输出结构，但最终代码无证据地选择 int；错误在最终签名合成阶段引入。
- 根因：`a_llm_reasoning_defect` — 所有调用点忽略返回值，Ghidra/IDA/Codex均恢复 void。
- 归因：`claude_code_specific`

### E-CL-002 — claude-code / OTHER

- 实体：分支局部 quota_blocks
- 源码（行 4342）：`blk64_t quota_blocks`
- 反编译（行 178）：`struct ea_quota ea_ibody_val_quota`
- 错误：把 helper 的单一块计数输出标量替换为双字段 quota 结构体。
- trace 原文：> Entries with `e_value_inum != 0` go through the helper at `0x1f600` (`check_ea_inode`) and accumulate quota
- 引入步骤：看到 caller 最终同时维护 blocks/inodes 后，按领域语义联想到 ea_quota，并错误重构 helper 原型。
- 根因：`a_llm_reasoning_defect` — 汇编只把一个8字节栈槽地址传给 helper，inodes 明确由 caller 自增。
- 归因：`claude_code_specific`

### E-CL-003 — claude-code / OTHER

- 实体：helper 返回值/源码 problem 赋值
- 源码（行 4344-4346）：`源码直接 problem = check_large_ea_inode(...)`
- 反编译（行 179-185）：`int ret; ret = check_ea_inode(...); problem = ret`
- 错误：把源码 problem 的赋值拆成额外 int ret 实体。
- trace 原文：> int ret;
> ret = check_ea_inode(ctx, entry, pctx, &ea_ibody_val_quota);
> if (ret) { problem = ret;
- 引入步骤：长分支结构重写时引入语义临时变量；行为近似但实体映射不一致。
- 根因：`c_large_function_complexity` — 优化后二者常共用寄存器，源码是否有独立临时量通常不可判定。
- 归因：`function_inherent_difficulty`

## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | 函数签名 | void (e2fsck_t, problem_context *, ea_quota *) | 相同 | 返回类型与三参数正确。 |
| codex | quota_blocks | blk64_t/uint64_t | uint64_t | 输出标量及宽度正确。 |
| codex | ext2_ext_attr_entry | u8,u8,u16,u32,u32,u32 | 相同 | 字段布局正确。 |
| codex | storage_size/remain/hash | unsigned int/unsigned int/__u32 | uint32_t/uint32_t/uint32_t | 等宽无符号恢复。 |
| claude-code | 三个参数 | e2fsck_t, problem_context *, ea_quota * | 相同 | 参数均正确。 |
| claude-code | entry/start/header/end | 结构体指针与 char *游标 | 相同 | 主要游标类型正确。 |
| claude-code | ext2_ext_attr_entry | 源码字段序列 | 相同字段序列 | 布局正确。 |

## 汇总

- error_count_by_agent: `{"claude-code": 3, "codex": 0}`
- error_count_by_pattern: `{"FN-01": 1, "OTHER": 2}`
- error_count_by_root_cause: `{"a_llm_reasoning_defect": 2, "c_large_function_complexity": 1}`
- error_count_by_attribution: `{"claude_code_specific": 2, "function_inherent_difficulty": 1}`
- correct_count_by_agent: `{"codex": 4, "claude-code": 3}`

关键结论：

- Codex 在该 case 没有确认的声明错误，是重要反例。
- Claude 正确解释 rdx 为 ea_quota，却把被调 helper 的单标量输出也类比成 ea_quota，属于领域联想过度。
- Claude 的 int 返回类型与所有其他工具相反，是明确的 Claude-code 特性。
