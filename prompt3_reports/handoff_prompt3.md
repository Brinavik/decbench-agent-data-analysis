# Prompt3 阶段交接

## 本阶段做了什么

对 Prompt2 选出的 7 个 `O2-noinline` large-function case 完成了逐案根因追踪：

- 对齐源码、Codex 输出、Claude-code 输出中的函数签名、存储类别、限定符、指针层级、整数宽度、数组和结构体布局。
- 逐条回查 Codex/Claude trace；每条错误均保存 trace 原文摘录，并标明错误进入最终声明的推理阶段。
- 对照 Ghidra 与 IDA 输出，严格按 Prompt3 规则给出 attribution。
- 明确记录正确恢复项和无确认错误的反例 case。
- 对所有 JSON 做了字段、枚举、输入文件存在性、计数一致性和 trace 摘录真实性检查。

## 核心结论

7 个 case 共记录 23 条确认错误：Codex 12 条，Claude-code 11 条。

- root cause：`a_llm_reasoning_defect` 11，`b_info_missing` 8，`c_large_function_complexity` 4。
- attribution：`function_inherent_difficulty` 16，`llm_common_difficulty` 4，`claude_code_specific` 2，`codex_specific` 1。
- 最常见模式是 `QUAL-01`（10条）。二进制 ABI 不编码 `const`，但在已明确识别上游源码函数时仍擅自增加/删除 `const`，则进一步体现语言先验或最终代码合成不一致。
- `inflate_fast` 的 GED=0 但两 agent 都出现 `in/last` const 化和 `here` 指针按值化，说明控制流等价与类型实体等价明显分离。
- `send_ocsp_request` 中 Codex 把项目包装函数返回值套成 POSIX `ssize_t`；Claude、Ghidra、IDA均保留 `int`，这是明确的 `codex_specific`。
- `check_ea_in_inode` 中 Claude 把 `void` 恢复为 `int`，并把 helper 的单一 `blk64_t` 输出联想成 `struct ea_quota`；两项均为 `claude_code_specific`。
- `shadow/vipw/main` 与 `cronie/crontab/get_range` 未发现可确认的类型/声明错误，是本阶段反例。非满 type_match 不应直接解释为人工可确认的类型错误。
- 传统反编译器在复杂结构体、source-level linkage/qualifier 上通常也无法恢复，因此按用户给定规则，大量错误被归为 `function_inherent_difficulty`；这不表示 LLM 没有推理缺陷，而是 attribution 与 root_cause 是两个不同维度。

## 产出文件

结果目录：`/home/user/decbench-dataset/decbench_agent_data/prompt3_reports/`

每个 case 各有一份严格 schema JSON 和同内容 Markdown：

- `rootcause__openssh-portable__ssh-sk-helper__cert_parse.json/.md`
- `rootcause__zlib__minigzip64__inflate_fast.json/.md`
- `rootcause__sysvinit__shutdown__wall.json/.md`
- `rootcause__gnutls__gnutls-cli__send_ocsp_request.json/.md`
- `rootcause__e2fsprogs__e2fsck__check_ea_in_inode.json/.md`
- `rootcause__shadow__vipw__main.json/.md`
- `rootcause__cronie__crontab__get_range.json/.md`

辅助生成文件：

- `/home/user/decbench-dataset/decbench_agent_data/build_prompt3_reports.py`
- `/home/user/decbench-dataset/decbench_agent_data/handoff_prompt3.md`（本文件）

## 下一阶段关键约定与注意事项

- `root_cause.category` 描述“为什么 LLM 会这样恢复”；`attribution` 描述“同一错误是否也出现在另一 LLM 或 Ghidra/IDA”。两者不可混用。
- attribution 严格按 Prompt3 规则：只要 Ghidra 或 IDA 也未正确恢复同一实体，即记 `function_inherent_difficulty`。
- `static`、`const` 等 source-level 信息在 stripped binary 中常不可判定。只有 trace 自相矛盾或已明确识别源码函数仍改写声明时，才优先判为 `a_llm_reasoning_defect`。
- 结构体的“最小偏移视图”可以行为正确，但只要字段数量/顺序/类型序列与源码不一致，仍按 `LAYOUT-01` 计入 type_match 根因。
- 临时变量拆分（如 `problem` 被拆成 `ret` 再赋值）保留为 `OTHER`，不要强行并入 INT/PTR。
- 两个零错误报告仍包含 correct_recoveries 和关键结论，用于解释 type_match/GED/byte_match 的口径分离。
