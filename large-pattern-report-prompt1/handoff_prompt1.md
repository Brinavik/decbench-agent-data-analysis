# Prompt1 阶段交接

## 本阶段工作与核心结论

本阶段基于上一轮已生成的 `needs_review.json`、`pattern_summary.md` 和 `per_function_detail.csv` 做轻量重聚合，没有重新读取 103 个原始裁决 JSON。将已复核的 OTHER 拆分为 QUAL-01、ARRAY-01，并保留无法归入现有模式的残余 OTHER。

目前的错误模式包含：
  SC-01     存储类别错误：static/局部 被重构为 extern/全局，或链接属性不一致。
  ST-01     结构体/头文件冲突：引用了与源码同名但定义不同的结构体/头文件，字段对不上。
  PTR-01    指针层级/数组：指针层级不同（T* vs T vs T**），或数组与指针互换。
  INT-01    整数/typedef：整数宽度/符号不同（int vs long、signed vs unsigned），或 typedef 丢失。
  FN-01     函数签名：参数个数/类型或返回类型不匹配。
  LAYOUT-01 结构体布局：字段数量/顺序/偏移/类型序列不一致。
  QUAL-01   const 限定差异
  ARRAY-01  数组长度/维度错误
  OTHER     无法归入以上任何一种。
归类优先级：先判 SC-01 / FN-01（最明确）；再判 ST-01 vs LAYOUT-01
（"引用了错误的结构体定义"→ST-01，"结构体字段本身排布不对"→LAYOUT-01）；
再判 PTR-01 / INT-01。

最终 wrong-entity 命中率排序（任务命中率 / 103）：LAYOUT-01 21.4%、INT-01 19.4%、FN-01 18.4%、SC-01 11.7%、QUAL-01 10.7%、ST-01 9.7%、ARRAY-01 5.8%、PTR-01 3.9%、OTHER 1.0%。按函数命中率（分母 52），LAYOUT-01 36.5%、INT-01 32.7%、FN-01 32.7% 达到“普遍”（≥30%）；SC-01、QUAL-01、ST-01 属于值得关注，ARRAY-01/PTR-01/OTHER 为低频但应保留代表案例。

QUAL-01 共 31 个 wrong entity（15.6% of all 199），ARRAY-01 共 6 个（3.0%），残余 OTHER 2 个（1.0%）。模式计数守恒：199。

残余 OTHER：`check_ea_in_inode` / `claude-code` 的 `blk64_t` 输出标量被恢复为 `struct ea_quota`，以及源码 helper 返回值被拆成独立 `int ret`；二者属于实体语义映射/临时变量拆分，无法合理归入现有模式。

## 产出文件

以下文件均位于 `/home/user/decbench-dataset/decbench_agent_data/large-pattern-report-prompt1/`：

- `pattern_summary.md`
- `per_function_detail.csv`
- `quality_monitor.md`
- `needs_review.json`
- `handoff_prompt1.md`

同时保留辅助机器可读质量数据 `quality_monitor.json`。

## Prompt2 约定与注意事项

- 最终模式清单：SC-01、ST-01、PTR-01、INT-01、FN-01、LAYOUT-01、QUAL-01、ARRAY-01、OTHER。
- schema 异常：93 个文件的 entity 缺少 `reasoning` 字段，属于良性格式问题，不影响 match/verdict/类型统计；若后续需要使用 reasoning，必须先补齐。
- 缺失任务：`claude-code / shadow / login / main`；有效样本为 103 个任务。
- 任务级 wrong 命中率：codex 69.2%，claude-code 58.8%。
- Prompt2 分层抽样应优先覆盖 LAYOUT-01、INT-01、FN-01 的高命中代表案例；同时各抽取 SC-01、QUAL-01、ST-01 的典型案例，检查存储类别、限定符和结构体定义冲突。ARRAY-01、PTR-01 和残余 OTHER 建议各保留少量边界案例，避免遗漏数组维度/指针表示及实体拆分问题。
- 任务命中率分母固定为 103，函数命中率分母固定为 52；缺失的 claude-code 任务不应改变函数分母。
- `needs_review.json` 中 39 条记录均已完成语义复核并带有 `assigned_pattern`；其中 QUAL-01 31 条、ARRAY-01 6 条、OTHER 2 条。
