# Prompt3 根因报告：zlib/minigzip64/inflate_fast

## 报告元数据

- report_id: `rootcause__zlib__minigzip64__inflate_fast`
- case: `zlib` / `O2-noinline` / `minigzip64` / `inflate_fast` / 395 lines

输入文件：

- source: `decbench-large/sources/zlib/inffast.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/zlib/minigzip64.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/zlib/minigzip64.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/zlib/minigzip64.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/zlib/minigzip64.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__zlib__minigzip64__inflate_fast.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__zlib__minigzip64__inflate_fast.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.09090909090909091 | 0.12278308321964529 | 0.0 |
| claude-code | 0.09090909090909091 | 0.12278308321964529 | 0.0 |

## 类型/声明错误

### E-CX-001 — codex / QUAL-01

- 实体：局部输入游标 in
- 源码（行 390）：`unsigned char *in`
- 反编译（行 106）：`const unsigned char *in`
- 错误：增加 const。
- trace 原文：> const unsigned char *in;
> const unsigned char *last;
- 引入步骤：识别 zlib 输入流为只读后，把语义只读性提升为源码限定符。
- 根因：`a_llm_reasoning_defect` — trace/输出已识别 exact inffast，但仍未遵循该版本源码的 Bytef * 声明。
- 归因：`llm_common_difficulty`

### E-CX-002 — codex / QUAL-01

- 实体：局部输入边界 last
- 源码（行 391）：`unsigned char *last`
- 反编译（行 107）：`const unsigned char *last`
- 错误：增加 const。
- trace 原文：> const unsigned char *in;
> const unsigned char *last;
- 引入步骤：与 in 一并在局部声明合成时加入 const。
- 根因：`a_llm_reasoning_defect` — 源函数身份明确且可从已知 zlib 模式恢复；两 LLM 同受现代 API/只读语义先验影响。
- 归因：`llm_common_difficulty`

### E-CX-003 — codex / PTR-01

- 实体：局部码表项 here
- 源码（行 407）：`code const *here`
- 反编译（行 121）：`code here`
- 错误：把指向表项的指针改为按值结构体对象。
- trace 原文：> code here;
- 引入步骤：为便于表达 here=lcode[index] 的按值逻辑，在控制流重构时消除了一级指针。
- 根因：`c_large_function_complexity` — 大型热循环中同一变量跨 dolen/dodist 二级表查找复用，按值化保持行为却破坏源码声明。
- 归因：`function_inherent_difficulty`

### E-CX-004 — codex / QUAL-01

- 实体：struct z_stream_s 的 next_in/msg 字段
- 源码（行 43,49）：`next_in: unsigned char *; msg: char *`
- 反编译（行 47,53）：`next_in: const unsigned char *; msg: const char *`
- 错误：两个结构体字段被增加 const。
- trace 原文：> const unsigned char *next_in;
- 引入步骤：套用更强的输入/消息只读语义构造完整 z_stream 视图；同一结构体内 msg 也被声明为 const char *。
- 根因：`a_llm_reasoning_defect` — 已识别 zlib 类型却采用了语义上合理但与该源码版本不一致的限定符。
- 归因：`function_inherent_difficulty`

### E-CL-001 — claude-code / QUAL-01

- 实体：局部输入游标 in
- 源码（行 390）：`unsigned char *in`
- 反编译（行 59）：`const unsigned char *in`
- 错误：增加 const。
- trace 原文：> const unsigned char *in;    /* local strm->next_in */
- 引入步骤：从只读消费模式推断 const。
- 根因：`a_llm_reasoning_defect` — trace 明确识别 exact inffast，仍受语义先验影响。
- 归因：`llm_common_difficulty`

### E-CL-002 — claude-code / QUAL-01

- 实体：局部输入边界 last
- 源码（行 391）：`unsigned char *last`
- 反编译（行 60）：`const unsigned char *last`
- 错误：增加 const。
- trace 原文：> const unsigned char *last;  /* have enough input while in < last */
- 引入步骤：与 in 同步派生 const。
- 根因：`a_llm_reasoning_defect` — 已知源码函数身份下仍改变声明。
- 归因：`llm_common_difficulty`

### E-CL-003 — claude-code / PTR-01

- 实体：局部码表项 here
- 源码（行 407）：`code const *here`
- 反编译（行 74）：`code here`
- 错误：把一级指针改为按值对象。
- trace 原文：> code here;                  /* retrieved table entry */
- 引入步骤：把反汇编中的4字节表项加载重写成 C 结构体值复制。
- 根因：`c_large_function_complexity` — 长循环和两级查表使按值表达更自然，但与源码实体层级不一致。
- 归因：`function_inherent_difficulty`

### E-CL-004 — claude-code / LAYOUT-01

- 实体：struct inflate_state
- 源码（行 334-382）：`完整35字段，mode 前有 strm，wsize 前有 last/wrap/.../wbits`
- 反编译（行 24-38）：`从 mode 直接接 wsize/whave/wnext/window 的最小字段视图`
- 错误：省略大量前置和尾部字段，字段偏移在普通 C 布局下不成立。
- trace 原文：> **State fields**: `[strm+0x38]` → `state`; loaded `wsize/whave/wnext/window/hold/bits`, `lencode`/`distcode` tables, and `lenbits`/`distbits` used to build `lmask`/`dmask` via `(1<<bits)-1`.
- 引入步骤：只收集目标函数访问字段，未把汇编偏移编码为显式 padding，也未恢复完整已识别类型。
- 根因：`c_large_function_complexity` — 395行函数只覆盖状态结构的一部分；字段多且偏移跨度大。
- 归因：`function_inherent_difficulty`

## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | 函数签名 | void (z_streamp, unsigned) | void (z_streamp, unsigned) | 返回和参数 ABI 正确。 |
| codex | struct inflate_state | 35字段源码序列 | 35字段等宽序列 | Codex 完整恢复关键布局。 |
| codex | hold/bits | unsigned long / unsigned | unsigned long / unsigned | 位缓冲宽度正确。 |
| codex | struct code | u8,u8,u16 | u8,u8,u16 | 字段宽度/顺序正确。 |
| claude-code | 函数签名 | void (z_streamp, unsigned) | void (z_streamp, unsigned) | trace 依据寄存器和边界公式正确恢复。 |
| claude-code | z_stream 前缀 | next_in/avail_in/... | 相同字段与类型 | 未给 z_stream 输入字段增加 const。 |
| claude-code | lcode/dcode | code const * | code const * | 表基址指针正确。 |
| claude-code | 窗口游标 from | unsigned char * | unsigned char * | 一级指针正确。 |

## 汇总

- error_count_by_agent: `{"codex": 4, "claude-code": 4}`
- error_count_by_pattern: `{"QUAL-01": 5, "PTR-01": 2, "LAYOUT-01": 1}`
- error_count_by_root_cause: `{"a_llm_reasoning_defect": 5, "c_large_function_complexity": 3}`
- error_count_by_attribution: `{"llm_common_difficulty": 4, "function_inherent_difficulty": 4}`
- correct_count_by_agent: `{"codex": 4, "claude-code": 4}`

关键结论：

- GED=0 但 type_match 极低，证明控制流/行为等价不保证声明实体等价。
- 两 agent 都把 in/last const 化并把 here 按值化，是大型循环重写中的共同类型失真。
- Claude 的最小 inflate_state 没有显式 padding，不能作为偏移正确的 C 布局。
