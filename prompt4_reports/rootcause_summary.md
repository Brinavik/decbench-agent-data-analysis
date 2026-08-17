# 大型函数类型恢复根因汇总

## 范围与口径

广度扫描覆盖 52 个 large-function、103 个有效 `(agent, function)` 任务（缺少 `claude-code/shadow/login/main`）。1565 个实体中，1180 个正确、199 个 wrong、186 个 undeterminable；66/103 个任务及 46/52 个函数至少有一个 wrong entity。下表的任务命中率分母固定为 103，函数命中率分母固定为 52，wrong-entity 占比的分母为 199。

深度阶段是为覆盖模式和评分区间而选取的 7 个函数、23 条确认错误的目的性样本，不是随机样本。因此它用于解释根因、模型归属和反例，不能把其频数外推为总体比例。`root_cause` 说明为何发生，`attribution` 说明另一 LLM/Ghidra/IDA 是否也在同一实体失败，两者不能混用。

深度样本中 Codex/Claude-code 分别有 12/11 条确认错误；根因为 LLM 推理缺陷 11 条、信息缺失 8 条、大型函数复杂性 4 条；归属为函数本身困难 16 条、LLM 共性 4 条、Claude-code 特性 2 条、Codex 特性 1 条。

## 按模式的规律

| 模式 | wrong entity（占 199） | 广度命中率（任务/函数） | 根因分类 | 深度与广度证据 | 反例 | 置信度 |
|---|---:|---:|---|---|---|---|
| LAYOUT-01 | 57（28.6%） | 21.4% / 36.5% | 信息缺失；大型函数复杂性 | `cert_parse` 两模型将 sshkey 缩为最小视图；`inflate_fast` 中 Claude 省略 inflate_state 字段；另见 `diversion_add`、`process_options` | Codex 完整恢复 inflate_state；两模型正确恢复 sshkey_cert | 高 |
| INT-01 | 39（19.6%） | 19.4% / 32.7% | LLM 推理缺陷；信息缺失 | `send_ocsp_request` 中 Codex 将 uint/int 改为 size_t/ssize_t；另见 `cmp`、`getpasswd` | Claude、Ghidra、IDA 在 ret 上保留 int；`get_range` 局部 int 正确 | 中高 |
| FN-01 | 25（12.6%） | 18.4% / 32.7% | LLM 推理缺陷；信息缺失 | `check_ea_in_inode` 中 Claude 将 void 改为 int；另见 `usage`、`_usbd_standard_request_device` | `inflate_fast`、`vipw/main`、`get_range` 的 ABI 可见签名正确 | 中高 |
| SC-01 | 19（9.5%） | 11.7% / 21.2% | 信息缺失 | `cert_parse` 的 Codex 丢失 static；`send_ocsp_request` 将 static buffer 改 extern | Claude 在 cert_parse 保留 static；vipw/main 两模型恢复 static 数组 | 信息缺失机制高；模型差异中 |
| QUAL-01 | 31（15.6%） | 10.7% / 19.2% | 信息缺失；LLM 推理缺陷 | `wall` 两模型丢 const；`inflate_fast` 两模型在识别源码后仍增 const；`cert_parse` Claude trace/输出矛盾 | `get_range` 正确 const char *[]；Claude 正确保留部分 z_stream 字段 | 高 |
| ST-01 | 16（8.0%） | 9.7% / 15.4% | LLM 推理缺陷；信息缺失 | 广度代表 `diversion_add`、`process_options`、`revoked_certs_generate` | cert_parse 深挖后更应归 LAYOUT；wall 使用正确系统结构体 | 初步 |
| ARRAY-01 | 6（3.0%） | 5.8% / 7.7% | LLM 推理缺陷；大型函数复杂性 | `wall` 中 Claude 把栈对齐量写入 VLA 长度；另见 `compare_files`、`socket_open2` | 同一 case Codex 正确恢复长度 | 中 |
| PTR-01 | 4（2.0%） | 3.9% / 5.8% | 大型函数复杂性 | `inflate_fast` 两模型均将 `code const *here` 按值化；另见 `copy_reg`、`yyparse` | 同 case 其他指针、get_range 双指针均正确 | 中 |
| OTHER | 2（1.0%） | 1.0% / 1.9% | LLM 推理缺陷；大型函数复杂性 | `check_ea_in_inode` 中 Claude 将标量输出改为 ea_quota，并拆出 ret | 同 case Codex 正确恢复标量，无确认错误 | 初步 |

LAYOUT-01、INT-01、FN-01 是唯一覆盖至少 30% 函数的模式。QUAL-01 在深度样本中最多（10/23），但这反映样本选择和逐实体计数，不能取代上述广度排序。

## 跨模式结论

- **函数本身困难，证据充分。** stripped binary 通常无法唯一确定 `static`、`const`、未访问结构体字段及优化前临时变量。23 条深度错误中 16 条按严格规则为 `function_inherent_difficulty`。这不等于模型没有缺陷，而是说明源码级精确匹配存在信息论上限。
- **LLM 共性，证据中高。** `inflate_fast` 中两模型均将 `in/last` const 化、将 `here` 从指针按值化，且 GED=0、type_match=0.0909，证明语义/控制流等价可与类型实体匹配分离。
- **Codex 特性，初步。** `send_ocsp_request` 中 Codex 用 POSIX/API 先验把项目 `int` 返回值改成 `ssize_t`，其他三种工具均为 `int`。目前只有一条，不可泛化。
- **Claude Code 特性，初步。** `check_ea_in_inode` 中 Claude 无依据把 `void` 改 `int`，并把单标量输出类比为 `ea_quota`。两条来自同一函数，尚不能描述为稳定模型特性。
- **大型函数特有，证据中等。** 长循环、稀疏结构体访问、栈对齐和跨分支临时量会放大实体追踪困难；但没有小函数匹配对照，不能把所有高频错误归因于规模本身。
- **指标解释，存在性证据充分。** `inflate_fast` 的 GED=0/type_match 很低、`get_range` 的 GED 很高而类型较好、`vipw/main` 非满 type_match 却无人工确认错误，说明 type_match、GED、byte_match 不可互相替代。

## 改进优先级

1. 先解决复杂结构体布局与精确项目类型定义检索。LAYOUT-01 的任务和函数命中率均最高，并会级联影响多个实体。
2. 再约束函数原型和整数宽度。INT-01、FN-01 各覆盖 32.7% 函数，应以调用点、寄存器位宽、扩展指令和比较语义联合约束，禁止仅凭 API 名称重写为 size_t/ssize_t；最终生成前检查 trace 与声明一致性。
3. 对无法由二进制辨识的信息做校准输出。把 ABI 可见类型与 `static`/`const`/typedef/未访问字段分层，输出 unknown 或候选而不是伪确定源码声明。
4. 在大型函数中保持实体 provenance。跟踪 SSA/栈槽到变量的身份，区分对齐分配与逻辑数组长度，检测指针按值化和临时变量拆分。
5. 扩样验证模型差异和函数规模效应。每个模型特性增加跨项目 case，并构造同项目、同优化级别的小函数对照。

结论：现有证据充分支持“布局优先、原型/整数其次、不可辨识信息需校准”的改进顺序；对 Codex/Claude 的特性和 large-function 的独立因果效应，只能给出初步或中等强度结论。
