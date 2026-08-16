# Prompt1 阶段交接

## 本阶段完成内容

- 从 `function_results.json` 提取全部 52 个 datasets 含 `large` 的函数，并关联 codex、claude-code 的 type_match、byte_match、ged、源码和反编译代码。
- 对每个函数的两个 agent 输出运行 7 类错误模式检测，生成函数 × agent × 模式明细。
- 严格区分 `yes`、`no`、`candidate`、`unevaluable`；只有 `yes` 计入 hit_count。
- 使用固定分母 52 计算命中率；可判定覆盖率至少达到 75% 才进行普遍性分类。
- zlib 函数提取器支持 K&R 参数声明、`local`、`ZEXTERN`、`ZEXPORT` 和 `OF((...))` 双层括号，并通过真实语料回归测试。

## 结论

达到“普遍”或“值得关注”的模式：

- claude-code / FN-01: 6/52 (11.54%), 命中样本平均 type_match=0.108500，分类=值得关注

以下条目因可判定覆盖率未达到 75%，不得仅凭原始命中率作普遍性结论：

- codex / PTR-01: 12/52 可判定（23.08%），确认命中率=0.00%
- codex / INT-01: 10/52 可判定（19.23%），确认命中率=3.85%
- codex / LAYOUT-01: 12/52 可判定（23.08%），确认命中率=15.38%
- claude-code / PTR-01: 15/52 可判定（28.85%），确认命中率=0.00%
- claude-code / INT-01: 11/52 可判定（21.15%），确认命中率=3.85%
- claude-code / LAYOUT-01: 15/52 可判定（28.85%），确认命中率=19.23%

全量预期 agent 输出为 104 份，实际源码与反编译代码同时可用 103 份。唯一已知缺失为 `shadow/O2-noinline/login/main/claude-code`。

## 产出文件

- 阶段结果：`prompt1_results.json`
- 完整函数导出：`large_functions.jsonl`、`large_functions.csv`
- 逐函数明细：`function_pattern_detail.json`、`function_pattern_detail.csv`、`function_pattern_detail.md`
- 模式汇总：`pattern_summary.json`、`pattern_summary.csv`、`pattern_summary.md`
- 人工复核候选：`manual_candidates.json`、`manual_candidates.csv`、`manual_candidates.md`
- 无法自动判定：`unevaluable.json`、`unevaluable.csv`、`unevaluable.md`
- 覆盖率：`coverage.json`、`coverage.csv`、`coverage.md`
- 扫描脚本：`../decbench_agent_data/analyze_large_error_patterns.py`
- 解析回归测试：`../decbench_agent_data/test_download_large_scan_inputs.py`

以上报表均位于 `/home/user/decbench-dataset/large-pattern-report-prompt1`。

## 下一阶段关键约定与注意事项

- `candidate_count` 是疑似证据数量，不是确认命中数；candidate 不进入 hit_rate，也不进入命中样本平均 type_match。
- `evaluable_count` 表示检测器获得了足够输入并产出 yes/no/candidate；`decisive_count` 仅统计 yes/no。
- 普遍性分类先检查可判定覆盖率：低于 75% 一律标记数据不足，再高的原始 hit_rate 也不升级为“值得关注/普遍”。
- 命中率分母固定为 52，不会因 claude-code 缺失一份输出改成 51；覆盖率阈值允许这种少量缺失。
- 下一阶段人工深剖应优先检查 `noteworthy_patterns`，同时参考 candidate 较多的 SC-01、ARR-01；不要把 candidate 当作已证实缺陷。
- PTR-01、INT-01、LAYOUT-01 的自动对齐覆盖率偏低，相关结论必须结合 `manual_candidates` 与 `unevaluable` 清单。
