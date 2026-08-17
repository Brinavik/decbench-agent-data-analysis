# Prompt3 根因报告：gnutls/gnutls-cli/send_ocsp_request

## 报告元数据

- report_id: `rootcause__gnutls__gnutls-cli__send_ocsp_request`
- case: `gnutls` / `O2-noinline` / `gnutls-cli` / `send_ocsp_request` / 146 lines

输入文件：

- source: `decbench-large/sources/gnutls/ocsptool-common.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/gnutls/gnutls-cli.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/gnutls/gnutls-cli.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/gnutls/gnutls-cli.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/gnutls/gnutls-cli.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__gnutls__gnutls-cli__send_ocsp_request.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__gnutls__gnutls-cli__send_ocsp_request.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.17142857142857143 | 0.3738601823708207 | 5.0 |
| claude-code | 0.34285714285714286 | 0.4056603773584906 | 10.0 |

## 类型/声明错误

### E-CX-001 — codex / QUAL-01

- 实体：函数第5参数 nonce
- 源码（行 6907）：`gnutls_datum_t *nonce`
- 反编译（行 53）：`const gnutls_datum_t *nonce`
- 错误：增加 const。
- trace 原文：> extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
>                       gnutls_datum_t *request,
>                       const gnutls_datum_t *nonce);
- 引入步骤：根据 generate_request 只读消费推断 const，并传播到目标函数原型。
- 根因：`b_info_missing` — 所指对象是否 const 不进入 ABI；本函数不写 nonce。
- 归因：`function_inherent_difficulty`

### E-CX-002 — codex / INT-01

- 实体：局部 headers_size
- 源码（行 6919）：`unsigned int headers_size`
- 反编译（行 67）：`size_t header_size`
- 错误：把32位 unsigned int 恢复为64位 size_t。
- trace 原文：> header_size = strlen(request_header);
- 引入步骤：由 strlen 返回类型推断 size_t，随后用显式强转适配32位发送长度；错误在类型传播阶段引入。
- 根因：`a_llm_reasoning_defect` — 汇编向发送 helper 传 edx，且强转本身暴露了目标宽度。
- 归因：`function_inherent_difficulty`

### E-CX-003 — codex / INT-01

- 实体：局部 ret
- 源码（行 6910）：`int ret`
- 反编译（行 69）：`ssize_t ret`
- 错误：把32位 int 恢复为64位 ssize_t。
- trace 原文：> ssize_t ret;
- 引入步骤：套用 POSIX recv 返回 ssize_t 的库原型先验到项目包装函数 socket_recv。
- 根因：`a_llm_reasoning_defect` — 该 helper 是自定义包装且汇编/错误码消费均使用32位；Claude、Ghidra、IDA恢复为 int。
- 归因：`codex_specific`

### E-CX-004 — codex / SC-01

- 实体：文件静态接收缓冲 buffer
- 源码（行 6796）：`static char buffer[4097]`
- 反编译（行 49）：`extern unsigned char sub_94700[]`
- 错误：把文件内 static 定长数组声明为无界 extern，且 char 改 unsigned char。
- trace 原文：> extern unsigned char sub_94700[];
- 引入步骤：识别到跨 helper 共享全局地址，但未从 .bss 尺寸/符号可见性恢复 static 与4097界限。
- 根因：`b_info_missing` — stripped 后源级名称/链接属性不可见；数组边界需结合全局布局推断。
- 归因：`function_inherent_difficulty`

## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | 前4个参数 | const char *, 两个证书句柄, gnutls_datum_t * | 相同 | 参数角色和指针层级正确。 |
| codex | gnutls_datum_t | u8 *data; unsigned int size | 相同 | 布局正确。 |
| codex | HTTP累积对象 | gnutls_datum_t | gnutls_datum_t | 正确。 |
| claude-code | 完整函数签名 | int (..., gnutls_datum_t *nonce) | int (..., gnutls_datum_t *nonce) | 含 nonce 非 const，全部正确。 |
| claude-code | ret | int | int | 没有套用 ssize_t 先验。 |
| claude-code | 静态 buffer | static char[4097] | static char[4097] | 存储类别、元素类型与界限正确。 |
| claude-code | ud/req | gnutls_datum_t | gnutls_datum_t | 结构体局部正确。 |

## 汇总

- error_count_by_agent: `{"codex": 4, "claude-code": 0}`
- error_count_by_pattern: `{"QUAL-01": 1, "INT-01": 2, "SC-01": 1}`
- error_count_by_root_cause: `{"b_info_missing": 2, "a_llm_reasoning_defect": 2}`
- error_count_by_attribution: `{"function_inherent_difficulty": 3, "codex_specific": 1}`
- correct_count_by_agent: `{"codex": 3, "claude-code": 4}`

关键结论：

- Codex 的 ret=ssize_t 是独有错误：Claude 与两传统反编译器都保留32位 int。
- Codex 对 headers_size 进行了从 strlen 返回值的过度类型传播。
- Claude 通过分析 append 对同一全局地址的读取，正确恢复 static buffer[4097]，是强反例。
