# Prompt4 阶段交接

## 本阶段做了什么

汇总了 Prompt1 的 103 个有效任务/52 个 large-function 广度扫描、Prompt2 的 7-case 分层抽样信息，以及 Prompt3 的 23 条逐 trace 确认错误、正确恢复项、反例和 Ghidra/IDA attribution。统一区分了：

- 广度模式命中率：任务分母 103，函数分母 52，wrong-entity 分母 199。
- 深度根因频数：仅描述 7 个目的性抽样 case，不外推总体比例。
- `root_cause`：为何错误产生；`attribution`：是否为另一模型/传统工具共有。

## 核心结论

1. `LAYOUT-01` 是广度最优先问题：任务命中率 21.4%，函数命中率 36.5%；复杂结构体常被输出为只覆盖当前访问字段的最小视图。
2. `INT-01` 和 `FN-01` 各覆盖 32.7% 函数，应作为第二优先级处理。
3. `QUAL-01`/`SC-01` 同时包含二进制不可辨识的信息缺失和 LLM 在已有证据下擅自改写；不能一概归咎模型。
4. 深度 23 条错误中，11 条是 `a_llm_reasoning_defect`、8 条 `b_info_missing`、4 条 `c_large_function_complexity`；attribution 为 16 条函数本身困难、4 条 LLM 共性、2 条 Claude-code 特异、1 条 Codex 特异。
5. Codex 特异（`int -> ssize_t`）和 Claude-code 特异（`void -> int`、标量输出类比结构体）目前都是初步猜想；各自样本不足。
6. `vipw/main` 与 `get_range` 是无确认错误反例；`inflate_fast` 的 GED=0/type_match 很低、`get_range` 的 GED 高而类型较好，说明 type_match/GED/byte_match 不可互相替代。

## 产出文件

- `prompt4_reports/rootcause_summary.json`：机器可读的范围、模式逐条统计、证据 case、反例、置信度、跨模式结论和优先级建议。
- `prompt4_reports/rootcause_summary.md`：与 JSON 同内容的人类可读汇总。
- `prompt4_reports/large_function_type_recovery_findings.md`：可直接纳入研究报告的《大型函数类型恢复规律总结》。
- `prompt4_reports/handoff_prompt4.md`：本交接文件。

## 下一阶段约定与注意事项

- 不要把深度 7-case/23-error 频数写成总体发生率；总体排序应使用 Prompt1 广度统计。
- `ST-01` 和 `OTHER` 证据较弱，保留分类但标为初步；`Codex 特性`、`Claude Code 特性`、`large-function 独立因果效应`同样不能过度推广。
- `function_inherent_difficulty` 与 `a_llm_reasoning_defect` 是不同轴：前者是跨工具 attribution，后者是错误生成机制。
- Prompt1 的 93 个 JSON 缺少 `reasoning` 字段是格式问题，不影响本阶段使用的 match/verdict/type 统计。
- 缺失任务仍为 `claude-code / shadow / login / main`；所有百分比分母按现有交接约定保持不变。
- 若继续扩样，优先增加复杂结构体布局、整数/函数签名 case，并设置同项目小函数对照，以检验规模独立效应。
