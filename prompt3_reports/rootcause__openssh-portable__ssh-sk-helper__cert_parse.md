# Prompt3 根因报告：openssh-portable/ssh-sk-helper/cert_parse

## 报告元数据

- report_id: `rootcause__openssh-portable__ssh-sk-helper__cert_parse`
- case: `openssh-portable` / `O2-noinline` / `ssh-sk-helper` / `cert_parse` / 138 lines

输入文件：

- source: `decbench-large/sources/openssh-portable/sshkey.c`
- codex_decompiled: `decbench-large/results/codex/O2-noinline/openssh-portable/ssh-sk-helper.c`
- claude_code_decompiled: `decbench-large/results/claude-code/O2-noinline/openssh-portable/ssh-sk-helper.c`
- ghidra_decompiled: `decbench_deep_cases/results/ghidra/O2-noinline/openssh-portable/ssh-sk-helper.c`
- ida_decompiled: `decbench_deep_cases/results/ida/O2-noinline/openssh-portable/ssh-sk-helper.c`
- codex_trace_md: `decbench_deep_cases/results/codex/traces/O2-noinline__openssh-portable__ssh-sk-helper__cert_parse.md`
- claude_code_trace_md: `decbench_deep_cases/results/claude-code/traces/O2-noinline__openssh-portable__ssh-sk-helper__cert_parse.md`

DecBench 分数：

| agent | type_match | byte_match | ged |
|---|---:|---:|---:|
| codex | 0.07142857142857142 | 0.922360248447205 | 12.0 |
| claude-code | 0.14285714285714285 | 0.0 | 5.0 |

## 类型/声明错误

### E-CX-001 — codex / SC-01

- 实体：函数 cert_parse 的内部链接属性
- 源码（行 3862-3863）：`static int cert_parse(struct sshbuf *b, struct sshkey *key, struct sshbuf *certbuf)`
- 反编译（行 57-58）：`int cert_parse(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)`
- 错误：丢失 static，使源码的内部链接函数成为外部链接声明。
- trace 原文：> int
> sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
- 引入步骤：最终写文件阶段直接生成非 static 定义；trace 没有单独论证链接属性。
- 根因：`b_info_missing` — 目标为 stripped binary；局部符号的 internal linkage 通常不由函数机器码编码。
- 归因：`function_inherent_difficulty`

### E-CX-002 — codex / QUAL-01

- 实体：函数第3参数 certbuf
- 源码（行 3863）：`struct sshbuf *certbuf`
- 反编译（行 58）：`const struct sshbuf *certbuf`
- 错误：给所指对象增加了源码不存在的 const。
- trace 原文：> sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
- 引入步骤：在最终原型合成时按只读用法推断 const；机器码只显示该参数被传给读取/复制 helper。
- 根因：`b_info_missing` — 指针所指对象是否由 C 类型标为 const 不进入 ABI；该函数内也未直接写 certbuf。
- 归因：`function_inherent_difficulty`

### E-CX-003 — codex / LAYOUT-01

- 实体：struct sshkey
- 源码（行 987-1018）：`22 个具名字段；cert 在偏移 0x80，且其后还有4字段`
- 反编译（行 24-28）：`struct sshkey { int type; unsigned char opaque[124]; struct sshkey_cert *cert; }`
- 错误：只保留本函数访问到的 type/cert，用 opaque 数组吞并中间字段并遗漏 cert 后字段。
- trace 原文：> The function extends to `0x1539c`; I’ve identified a shared cleanup path and several nested iterator loops. I’m now resolving the nearby internal-call semantics and the context layout from their raw assembly and dynamic symbols so the final C uses coherent types rather than opaque register-shaped variables.
- 引入步骤：上下文布局恢复阶段只确认 type@0 与 cert@0x80；最终仍采用 opaque[124] 的最小视图。
- 根因：`b_info_missing` — 当前函数只观察 type 与 cert 偏移，无法推出未访问字段的名称、类型及尾部字段。
- 归因：`function_inherent_difficulty`

### E-CL-001 — claude-code / QUAL-01

- 实体：函数第3参数 certbuf
- 源码（行 3863）：`struct sshbuf *certbuf`
- 反编译（行 66）：`const struct sshbuf *certbuf`
- 错误：给所指对象增加了源码不存在的 const。
- trace 原文：> **Signature** `(struct sshbuf *b, struct sshkey *key, struct sshbuf *certbuf)` — `rdi`/`rsi`/`rdx`; `key->cert` lives at offset `0x80`.
- 引入步骤：总结阶段已写出正确非 const 签名，但落盘原型又改成 const，错误在最终代码合成阶段引入。
- 根因：`a_llm_reasoning_defect` — trace 自身的正确签名与最终声明矛盾，不是缺少线索导致的必然选择。
- 归因：`function_inherent_difficulty`

### E-CL-002 — claude-code / LAYOUT-01

- 实体：struct sshkey
- 源码（行 987-1018）：`22 个具名字段；cert 在偏移 0x80，且其后还有4字段`
- 反编译（行 37-41）：`struct sshkey { int type; char pad[0x80-sizeof(int)]; struct sshkey_cert *cert; }`
- 错误：用 pad 代替全部中间字段，并遗漏 cert 后字段。
- trace 原文：> `key->cert` lives at offset `0x80`.
- 引入步骤：从偏移证据恢复了最小布局，但把“可观察偏移视图”误当作完整源码结构体。
- 根因：`b_info_missing` — 单函数只访问 type/cert，不能恢复未访问字段；最小视图在行为上足够但 type_match 不匹配。
- 归因：`function_inherent_difficulty`

## 正确恢复/反例

| agent | entity | source_type | decompiled_type | note |
|---|---|---|---|---|
| codex | 第1参数 b | struct sshbuf * | struct sshbuf * | ABI 槽位和 helper 数据流一致。 |
| codex | 第2参数 key | struct sshkey * | struct sshkey * | 正确恢复一级指针。 |
| codex | 局部 signed_len/siglen/key_id_len | size_t | size_t | 长度类型及用途正确。 |
| codex | struct sshkey_cert | 12字段源码布局 | 12字段等宽布局 | 字段顺序、宽度和 LP64 偏移全部正确。 |
| claude-code | 函数存储类别 | static | static | Claude 保留了 internal linkage。 |
| claude-code | 第1/2参数 | struct sshbuf * / struct sshkey * | struct sshbuf * / struct sshkey * | ABI 与语义均正确。 |
| claude-code | struct sshkey_cert | 12字段源码布局 | 12字段源码布局 | 字段级恢复正确。 |
| claude-code | sig | u_char * | u_char * | typedef 与指针层级正确。 |

## 汇总

- error_count_by_agent: `{"codex": 3, "claude-code": 2}`
- error_count_by_pattern: `{"SC-01": 1, "QUAL-01": 2, "LAYOUT-01": 2}`
- error_count_by_root_cause: `{"b_info_missing": 4, "a_llm_reasoning_defect": 1}`
- error_count_by_attribution: `{"function_inherent_difficulty": 5}`
- correct_count_by_agent: `{"codex": 4, "claude-code": 4}`

关键结论：

- 两 agent 都精确恢复 sshkey_cert，却只能为 sshkey 构造偏移视图，说明被访问字段覆盖率决定结构体完整度。
- Claude 的 trace 先给出正确非 const 签名、最终代码却加入 const，是明确的最终合成不一致。
- Ghidra/IDA 对参数及 sshkey 布局更不精确，因此按规则这些错误归为函数本身难点。
