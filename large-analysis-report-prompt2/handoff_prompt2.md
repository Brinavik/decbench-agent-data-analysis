# Prompt2 阶段交接

## 本阶段工作与结论

本阶段将 Phase 1 的 `per_function_detail.csv` 模式命中结果，与
`configs/sample-set/function_results.json` 中的函数 size、codex/claude-code
指标，以及 `decbench-large/large_download_inventory.csv` 中的 52 个 large-function
坐标合并。最终选择 7 个函数，分属 7 个 project。

选择结果覆盖全部 9 类错误模式：SC-01、ST-01、PTR-01、INT-01、FN-01、
LAYOUT-01、QUAL-01、ARRAY-01、OTHER。分数覆盖低分、中低分、中高分和高分段，
并包含两个未命中任何已知模式的反例：`shadow/vipw/main` 与
`cronie/crontab/get_range`。

选定案例：

| project/binary/function | 主要用途 |
|---|---|
| openssh-portable/ssh-sk-helper/cert_parse | 低分、多模式；覆盖 SC/ST/FN/LAYOUT |
| zlib/minigzip64/inflate_fast | 低分；覆盖 PTR/LAYOUT/QUAL，且两 agent 结果一致 |
| sysvinit/shutdown/wall | 低分；ARRAY 代表及同 type_match 下的跨 agent 对照 |
| gnutls/gnutls-cli/send_ocsp_request | 中低分；覆盖 SC/INT/FN/QUAL，错误谱跨 agent 分化 |
| e2fsprogs/e2fsck/check_ea_in_inode | 中低分；唯一残余 OTHER 边界案例 |
| shadow/vipw/main | 中高分、无已知模式的反例 |
| cronie/crontab/get_range | 高分端、无已知模式且 GED 较高的反例 |

该组合用 7 个 case 覆盖全部模式，避免了集中选择同一项目，也保留了对
type_match 与 byte_match/GED 不一致现象的分析空间。

## 产出文件

文件均位于 `/home/user/decbench-dataset/decbench_agent_data/`：

- `case_list_for_tracing.json`：7 个 case 的坐标、size、两种 LLM 的
  type_match/byte_match/GED、分 agent 与 union 模式、入选理由。
- `download_cases_for_tracing.py`：下载脚本；提供
  `download_case_trace(project, opt, binary, function, agent, local_dir)`，也可按
  case list 批量下载两种 agent 的 trace 及 IDA/Ghidra 源码。
- `handoff_prompt2.md`：本交接文件。

## 下一阶段约定与注意事项

- 全部选定 case 的 opt 均为 `O2-noinline`，且 codex/claude-code 输出均存在。
- 深度追踪时应按 `hit_patterns` 的 agent 归属分析，不能只使用 union；同一函数
  在两个 agent 上可能命中完全不同的模式。
- 两个反例“无已知模式”表示 Phase 1 的 wrong entity 未归入九类，并不等同于
  type_match=1。下一阶段应核对指标计算实体、undeterminable 项和人工裁决口径。
- `check_ea_in_inode` 的 OTHER 是分类边界案例：输出标量被恢复成结构体，以及源码
  helper 返回值被拆成独立临时变量。不要在缺乏 trace 证据时强行并入 PTR/LAYOUT。
- `inflate_fast` 的 GED=0 但 type_match 很低，是区分控制流恢复与类型恢复的关键案例。
- `crontab/get_range` 的 type_match 较高但 GED 为 50/43，是相反方向的指标分离案例。
- 下载脚本默认读取同目录的 `case_list_for_tracing.json`，默认下载到
  `decbench_deep_cases/`；本阶段按要求只生成脚本，未执行下载。
- 脚本对每个目标文件独立捕获 HTTP、路径/本地 I/O 和 Hugging Face 版本差异导致的
  异常；批量下载时 IDA/Ghidra 文件会在第二个 agent 调用中命中本地缓存。
