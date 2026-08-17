#!/usr/bin/env python3
import json
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent
OUT = ROOT / "prompt3_reports"
OUT.mkdir(exist_ok=True)

CASES = [
{
"slug":"openssh-portable__ssh-sk-helper__cert_parse","project":"openssh-portable","binary":"ssh-sk-helper","function":"cert_parse","size":138,
"source":"decbench-large/sources/openssh-portable/sshkey.c","metrics":{"codex":{"type_match":0.07142857142857142,"byte_match":0.922360248447205,"ged":12.0},"claude-code":{"type_match":0.14285714285714285,"byte_match":0.0,"ged":5.0}},
"errors":[
 ["E-CX-001","codex","SC-01","函数 cert_parse 的内部链接属性","static int cert_parse(struct sshbuf *b, struct sshkey *key, struct sshbuf *certbuf)","3862-3863","int cert_parse(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)","57-58","丢失 static，使源码的内部链接函数成为外部链接声明。","int\nsub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)","最终写文件阶段直接生成非 static 定义；trace 没有单独论证链接属性。","b_info_missing","目标为 stripped binary；局部符号的 internal linkage 通常不由函数机器码编码。","function_inherent_difficulty"],
 ["E-CX-002","codex","QUAL-01","函数第3参数 certbuf","struct sshbuf *certbuf","3863","const struct sshbuf *certbuf","58","给所指对象增加了源码不存在的 const。","sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)","在最终原型合成时按只读用法推断 const；机器码只显示该参数被传给读取/复制 helper。","b_info_missing","指针所指对象是否由 C 类型标为 const 不进入 ABI；该函数内也未直接写 certbuf。","function_inherent_difficulty"],
 ["E-CX-003","codex","LAYOUT-01","struct sshkey","22 个具名字段；cert 在偏移 0x80，且其后还有4字段","987-1018","struct sshkey { int type; unsigned char opaque[124]; struct sshkey_cert *cert; }","24-28","只保留本函数访问到的 type/cert，用 opaque 数组吞并中间字段并遗漏 cert 后字段。","The function extends to `0x1539c`; I’ve identified a shared cleanup path and several nested iterator loops. I’m now resolving the nearby internal-call semantics and the context layout from their raw assembly and dynamic symbols so the final C uses coherent types rather than opaque register-shaped variables.","上下文布局恢复阶段只确认 type@0 与 cert@0x80；最终仍采用 opaque[124] 的最小视图。","b_info_missing","当前函数只观察 type 与 cert 偏移，无法推出未访问字段的名称、类型及尾部字段。","function_inherent_difficulty"],
 ["E-CL-001","claude-code","QUAL-01","函数第3参数 certbuf","struct sshbuf *certbuf","3863","const struct sshbuf *certbuf","66","给所指对象增加了源码不存在的 const。","**Signature** `(struct sshbuf *b, struct sshkey *key, struct sshbuf *certbuf)` — `rdi`/`rsi`/`rdx`; `key->cert` lives at offset `0x80`.","总结阶段已写出正确非 const 签名，但落盘原型又改成 const，错误在最终代码合成阶段引入。","a_llm_reasoning_defect","trace 自身的正确签名与最终声明矛盾，不是缺少线索导致的必然选择。","function_inherent_difficulty"],
 ["E-CL-002","claude-code","LAYOUT-01","struct sshkey","22 个具名字段；cert 在偏移 0x80，且其后还有4字段","987-1018","struct sshkey { int type; char pad[0x80-sizeof(int)]; struct sshkey_cert *cert; }","37-41","用 pad 代替全部中间字段，并遗漏 cert 后字段。","`key->cert` lives at offset `0x80`.","从偏移证据恢复了最小布局，但把“可观察偏移视图”误当作完整源码结构体。","b_info_missing","单函数只访问 type/cert，不能恢复未访问字段；最小视图在行为上足够但 type_match 不匹配。","function_inherent_difficulty"]],
"correct":[
 ["codex","第1参数 b","struct sshbuf *","struct sshbuf *","ABI 槽位和 helper 数据流一致。"],["codex","第2参数 key","struct sshkey *","struct sshkey *","正确恢复一级指针。"],["codex","局部 signed_len/siglen/key_id_len","size_t","size_t","长度类型及用途正确。"],["codex","struct sshkey_cert","12字段源码布局","12字段等宽布局","字段顺序、宽度和 LP64 偏移全部正确。"],
 ["claude-code","函数存储类别","static","static","Claude 保留了 internal linkage。"],["claude-code","第1/2参数","struct sshbuf * / struct sshkey *","struct sshbuf * / struct sshkey *","ABI 与语义均正确。"],["claude-code","struct sshkey_cert","12字段源码布局","12字段源码布局","字段级恢复正确。"],["claude-code","sig","u_char *","u_char *","typedef 与指针层级正确。"]],
"findings":["两 agent 都精确恢复 sshkey_cert，却只能为 sshkey 构造偏移视图，说明被访问字段覆盖率决定结构体完整度。","Claude 的 trace 先给出正确非 const 签名、最终代码却加入 const，是明确的最终合成不一致。","Ghidra/IDA 对参数及 sshkey 布局更不精确，因此按规则这些错误归为函数本身难点。"]
},
{
"slug":"zlib__minigzip64__inflate_fast","project":"zlib","binary":"minigzip64","function":"inflate_fast","size":395,
"source":"decbench-large/sources/zlib/inffast.c","metrics":{"codex":{"type_match":0.09090909090909091,"byte_match":0.12278308321964529,"ged":0.0},"claude-code":{"type_match":0.09090909090909091,"byte_match":0.12278308321964529,"ged":0.0}},
"errors":[
 ["E-CX-001","codex","QUAL-01","局部输入游标 in","unsigned char *in","390","const unsigned char *in","106","增加 const。","const unsigned char *in;\nconst unsigned char *last;","识别 zlib 输入流为只读后，把语义只读性提升为源码限定符。","a_llm_reasoning_defect","trace/输出已识别 exact inffast，但仍未遵循该版本源码的 Bytef * 声明。","llm_common_difficulty"],
 ["E-CX-002","codex","QUAL-01","局部输入边界 last","unsigned char *last","391","const unsigned char *last","107","增加 const。","const unsigned char *in;\nconst unsigned char *last;","与 in 一并在局部声明合成时加入 const。","a_llm_reasoning_defect","源函数身份明确且可从已知 zlib 模式恢复；两 LLM 同受现代 API/只读语义先验影响。","llm_common_difficulty"],
 ["E-CX-003","codex","PTR-01","局部码表项 here","code const *here","407","code here","121","把指向表项的指针改为按值结构体对象。","code here;","为便于表达 here=lcode[index] 的按值逻辑，在控制流重构时消除了一级指针。","c_large_function_complexity","大型热循环中同一变量跨 dolen/dodist 二级表查找复用，按值化保持行为却破坏源码声明。","function_inherent_difficulty"],
 ["E-CX-004","codex","QUAL-01","struct z_stream_s 的 next_in/msg 字段","next_in: unsigned char *; msg: char *","43,49","next_in: const unsigned char *; msg: const char *","47,53","两个结构体字段被增加 const。","const unsigned char *next_in;","套用更强的输入/消息只读语义构造完整 z_stream 视图；同一结构体内 msg 也被声明为 const char *。","a_llm_reasoning_defect","已识别 zlib 类型却采用了语义上合理但与该源码版本不一致的限定符。","function_inherent_difficulty"],
 ["E-CL-001","claude-code","QUAL-01","局部输入游标 in","unsigned char *in","390","const unsigned char *in","59","增加 const。","const unsigned char *in;    /* local strm->next_in */","从只读消费模式推断 const。","a_llm_reasoning_defect","trace 明确识别 exact inffast，仍受语义先验影响。","llm_common_difficulty"],
 ["E-CL-002","claude-code","QUAL-01","局部输入边界 last","unsigned char *last","391","const unsigned char *last","60","增加 const。","const unsigned char *last;  /* have enough input while in < last */","与 in 同步派生 const。","a_llm_reasoning_defect","已知源码函数身份下仍改变声明。","llm_common_difficulty"],
 ["E-CL-003","claude-code","PTR-01","局部码表项 here","code const *here","407","code here","74","把一级指针改为按值对象。","code here;                  /* retrieved table entry */","把反汇编中的4字节表项加载重写成 C 结构体值复制。","c_large_function_complexity","长循环和两级查表使按值表达更自然，但与源码实体层级不一致。","function_inherent_difficulty"],
 ["E-CL-004","claude-code","LAYOUT-01","struct inflate_state","完整35字段，mode 前有 strm，wsize 前有 last/wrap/.../wbits","334-382","从 mode 直接接 wsize/whave/wnext/window 的最小字段视图","24-38","省略大量前置和尾部字段，字段偏移在普通 C 布局下不成立。","**State fields**: `[strm+0x38]` → `state`; loaded `wsize/whave/wnext/window/hold/bits`, `lencode`/`distcode` tables, and `lenbits`/`distbits` used to build `lmask`/`dmask` via `(1<<bits)-1`.","只收集目标函数访问字段，未把汇编偏移编码为显式 padding，也未恢复完整已识别类型。","c_large_function_complexity","395行函数只覆盖状态结构的一部分；字段多且偏移跨度大。","function_inherent_difficulty"]],
"correct":[
 ["codex","函数签名","void (z_streamp, unsigned)","void (z_streamp, unsigned)","返回和参数 ABI 正确。"],["codex","struct inflate_state","35字段源码序列","35字段等宽序列","Codex 完整恢复关键布局。"],["codex","hold/bits","unsigned long / unsigned","unsigned long / unsigned","位缓冲宽度正确。"],["codex","struct code","u8,u8,u16","u8,u8,u16","字段宽度/顺序正确。"],
 ["claude-code","函数签名","void (z_streamp, unsigned)","void (z_streamp, unsigned)","trace 依据寄存器和边界公式正确恢复。"],["claude-code","z_stream 前缀","next_in/avail_in/...","相同字段与类型","未给 z_stream 输入字段增加 const。"],["claude-code","lcode/dcode","code const *","code const *","表基址指针正确。"],["claude-code","窗口游标 from","unsigned char *","unsigned char *","一级指针正确。"]],
"findings":["GED=0 但 type_match 极低，证明控制流/行为等价不保证声明实体等价。","两 agent 都把 in/last const 化并把 here 按值化，是大型循环重写中的共同类型失真。","Claude 的最小 inflate_state 没有显式 padding，不能作为偏移正确的 C 布局。"]
},
{
"slug":"sysvinit__shutdown__wall","project":"sysvinit","binary":"shutdown","function":"wall","size":165,
"source":"decbench-large/sources/sysvinit/dowall.c","metrics":{"codex":{"type_match":0.10526315789473684,"byte_match":0.925764192139738,"ged":5.0},"claude-code":{"type_match":0.10526315789473684,"byte_match":0.5985401459854015,"ged":10.0}},
"errors":[
 ["E-CX-001","codex","QUAL-01","函数第1参数 text","const char *text","133","char *message","15","丢失 const。","void sub_4540(char *message, int remote)","最终原型依据寄存器/传递行为生成，未保留不可由 ABI 观察的 const。","b_info_missing","函数内只读使用不能证明源码是否声明 const。","function_inherent_difficulty"],
 ["E-CL-001","claude-code","QUAL-01","函数第1参数 text","const char *text","133","char *msg","22","丢失 const。","**Signature:** `void sub_4540(char *msg, int remote)` — this is a `wall`-style message broadcaster.","签名推断只使用 rdi→msg、esi→remote 的 ABI 证据；未恢复 const。","b_info_missing","const 不进入调用约定。","function_inherent_difficulty"],
 ["E-CL-002","claude-code","ARRAY-01","局部终端路径缓冲 term","char term[32 + strlen(\"/dev/\") + 1]（38）","139-143","char line[dev_len + 0x30]（53）","24","数组长度多加15字节。","size_t dev_len = strlen(\"/dev/\");\nchar line[dev_len + 0x30];      /* \"/dev/\" + terminal name */","把动态栈对齐/分配量 0x30 当成源码字符容量，而不是对 38 字节 VLA 的16字节对齐。","a_llm_reasoning_defect","汇编栈分配包含对齐；将对齐后的空间误写进数组界限。","function_inherent_difficulty"]],
"correct":[
 ["codex","函数返回类型","void","void","正确。"],["codex","term 数组长度","38","sizeof(ut->ut_line)+strlen(\"/dev/\")+1","等价恢复。"],["codex","line/hostname","char[256] / char[65]","char[256] / char[65]","固定数组正确。"],["codex","struct sigaction/utmp","源码系统结构体","相同系统结构体","没有自造冲突布局。"],
 ["claude-code","函数返回类型和第2参数","void, int","void, int","正确。"],["claude-code","header/host","char[256] / char[65]","char[256] / char[65]","固定缓冲恢复正确。"],["claude-code","time/local pointers","time_t; char *","time_t; char *","时间及字符串游标类型正确。"]],
"findings":["两 LLM 同时丢失参数 const，而 Ghidra/IDA 也未恢复，属于二进制固有信息缺失。","Claude 将栈对齐量混入 VLA 逻辑长度，是反汇编到源码数组声明映射的典型缺陷。","Codex 对 VLA 用 ut_line 字段宽度表达，数组恢复优于 Claude。"]
},
{
"slug":"gnutls__gnutls-cli__send_ocsp_request","project":"gnutls","binary":"gnutls-cli","function":"send_ocsp_request","size":146,
"source":"decbench-large/sources/gnutls/ocsptool-common.c","metrics":{"codex":{"type_match":0.17142857142857143,"byte_match":0.3738601823708207,"ged":5.0},"claude-code":{"type_match":0.34285714285714286,"byte_match":0.4056603773584906,"ged":10.0}},
"errors":[
 ["E-CX-001","codex","QUAL-01","函数第5参数 nonce","gnutls_datum_t *nonce","6907","const gnutls_datum_t *nonce","53","增加 const。","extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,\n                      gnutls_datum_t *request,\n                      const gnutls_datum_t *nonce);","根据 generate_request 只读消费推断 const，并传播到目标函数原型。","b_info_missing","所指对象是否 const 不进入 ABI；本函数不写 nonce。","function_inherent_difficulty"],
 ["E-CX-002","codex","INT-01","局部 headers_size","unsigned int headers_size","6919","size_t header_size","67","把32位 unsigned int 恢复为64位 size_t。","header_size = strlen(request_header);","由 strlen 返回类型推断 size_t，随后用显式强转适配32位发送长度；错误在类型传播阶段引入。","a_llm_reasoning_defect","汇编向发送 helper 传 edx，且强转本身暴露了目标宽度。","function_inherent_difficulty"],
 ["E-CX-003","codex","INT-01","局部 ret","int ret","6910","ssize_t ret","69","把32位 int 恢复为64位 ssize_t。","ssize_t ret;","套用 POSIX recv 返回 ssize_t 的库原型先验到项目包装函数 socket_recv。","a_llm_reasoning_defect","该 helper 是自定义包装且汇编/错误码消费均使用32位；Claude、Ghidra、IDA恢复为 int。","codex_specific"],
 ["E-CX-004","codex","SC-01","文件静态接收缓冲 buffer","static char buffer[4097]","6796","extern unsigned char sub_94700[]","49","把文件内 static 定长数组声明为无界 extern，且 char 改 unsigned char。","extern unsigned char sub_94700[];","识别到跨 helper 共享全局地址，但未从 .bss 尺寸/符号可见性恢复 static 与4097界限。","b_info_missing","stripped 后源级名称/链接属性不可见；数组边界需结合全局布局推断。","function_inherent_difficulty"]],
"correct":[
 ["codex","前4个参数","const char *, 两个证书句柄, gnutls_datum_t *","相同","参数角色和指针层级正确。"],["codex","gnutls_datum_t","u8 *data; unsigned int size","相同","布局正确。"],["codex","HTTP累积对象","gnutls_datum_t","gnutls_datum_t","正确。"],
 ["claude-code","完整函数签名","int (..., gnutls_datum_t *nonce)","int (..., gnutls_datum_t *nonce)","含 nonce 非 const，全部正确。"],["claude-code","ret","int","int","没有套用 ssize_t 先验。"],["claude-code","静态 buffer","static char[4097]","static char[4097]","存储类别、元素类型与界限正确。"],["claude-code","ud/req","gnutls_datum_t","gnutls_datum_t","结构体局部正确。"]],
"findings":["Codex 的 ret=ssize_t 是独有错误：Claude 与两传统反编译器都保留32位 int。","Codex 对 headers_size 进行了从 strlen 返回值的过度类型传播。","Claude 通过分析 append 对同一全局地址的读取，正确恢复 static buffer[4097]，是强反例。"]
},
{
"slug":"e2fsprogs__e2fsck__check_ea_in_inode","project":"e2fsprogs","binary":"e2fsck","function":"check_ea_in_inode","size":159,
"source":"decbench-large/sources/e2fsprogs/pass1.c","metrics":{"codex":{"type_match":0.35714285714285715,"byte_match":0.2708333333333333,"ged":4.0},"claude-code":{"type_match":0.21428571428571427,"byte_match":0.0,"ged":17.0}},
"errors":[
 ["E-CL-001","claude-code","FN-01","函数返回类型","static void check_ea_in_inode(...) ","4252-4253","static int check_ea_in_inode(...)","115-116","把 void 恢复为 int，并在各路径 return 0。","**Signature** — `(e2fsck_t ctx, struct problem_context *pctx, struct ea_quota *ea_ibody_quota)`","总结只列出参数且正确解释 rdx 输出结构，但最终代码无证据地选择 int；错误在最终签名合成阶段引入。","a_llm_reasoning_defect","所有调用点忽略返回值，Ghidra/IDA/Codex均恢复 void。","claude_code_specific"],
 ["E-CL-002","claude-code","OTHER","分支局部 quota_blocks","blk64_t quota_blocks","4342","struct ea_quota ea_ibody_val_quota","178","把 helper 的单一块计数输出标量替换为双字段 quota 结构体。","Entries with `e_value_inum != 0` go through the helper at `0x1f600` (`check_ea_inode`) and accumulate quota","看到 caller 最终同时维护 blocks/inodes 后，按领域语义联想到 ea_quota，并错误重构 helper 原型。","a_llm_reasoning_defect","汇编只把一个8字节栈槽地址传给 helper，inodes 明确由 caller 自增。","claude_code_specific"],
 ["E-CL-003","claude-code","OTHER","helper 返回值/源码 problem 赋值","源码直接 problem = check_large_ea_inode(...)","4344-4346","int ret; ret = check_ea_inode(...); problem = ret","179-185","把源码 problem 的赋值拆成额外 int ret 实体。","int ret;\nret = check_ea_inode(ctx, entry, pctx, &ea_ibody_val_quota);\nif (ret) { problem = ret;","长分支结构重写时引入语义临时变量；行为近似但实体映射不一致。","c_large_function_complexity","优化后二者常共用寄存器，源码是否有独立临时量通常不可判定。","function_inherent_difficulty"]],
"correct":[
 ["codex","函数签名","void (e2fsck_t, problem_context *, ea_quota *)","相同","返回类型与三参数正确。"],["codex","quota_blocks","blk64_t/uint64_t","uint64_t","输出标量及宽度正确。"],["codex","ext2_ext_attr_entry","u8,u8,u16,u32,u32,u32","相同","字段布局正确。"],["codex","storage_size/remain/hash","unsigned int/unsigned int/__u32","uint32_t/uint32_t/uint32_t","等宽无符号恢复。"],
 ["claude-code","三个参数","e2fsck_t, problem_context *, ea_quota *","相同","参数均正确。"],["claude-code","entry/start/header/end","结构体指针与 char *游标","相同","主要游标类型正确。"],["claude-code","ext2_ext_attr_entry","源码字段序列","相同字段序列","布局正确。"]],
"findings":["Codex 在该 case 没有确认的声明错误，是重要反例。","Claude 正确解释 rdx 为 ea_quota，却把被调 helper 的单标量输出也类比成 ea_quota，属于领域联想过度。","Claude 的 int 返回类型与所有其他工具相反，是明确的 Claude-code 特性。"]
},
{
"slug":"shadow__vipw__main","project":"shadow","binary":"vipw","function":"main","size":137,
"source":"decbench-large/sources/shadow/vipw.c","metrics":{"codex":{"type_match":0.4,"byte_match":0.0,"ged":2.0},"claude-code":{"type_match":0.5,"byte_match":0.0,"ged":0.0}},
"errors":[],
"correct":[
 ["codex","main 完整签名","int main(int argc, char **argv)","int main(int argc, char **argv)","返回类型、参数宽度和指针层级正确。"],["codex","long_options","static struct option[]","static struct option[]","存储类别、结构体数组和静态初始化正确。"],["codex","do_vipw/editshadow","_Bool","bool","等价布尔类型。"],
 ["claude-code","main 完整签名","int main(int argc, char **argv)","int main(int argc, char **argv)","正确。"],["claude-code","long_options","static struct option[]","static struct option[]","正确恢复 static 数组。"],["claude-code","函数指针参数","int (*)(void)","int (*)(void)","vipwedit helper 原型中的函数指针正确。"]],
"findings":["本 case 未发现可人工确认的类型/声明错误；type_match 非满分主要反映评测实体覆盖/对齐口径，而非明确错误模式。","两 agent 都恢复 main 与 static long_options，说明大型函数并不必然导致存储类别或签名失败。","Claude GED=0 但 byte_match=0，继续说明结构/类型/字节指标彼此独立。"]
},
{
"slug":"cronie__crontab__get_range","project":"cronie","binary":"crontab","function":"get_range","size":137,
"source":"decbench-large/sources/cronie/entry.c","metrics":{"codex":{"type_match":0.8181818181818182,"byte_match":0.2920962199312715,"ged":50.0},"claude-code":{"type_match":0.5454545454545454,"byte_match":0.2616822429906542,"ged":43.0}},
"errors":[],
"correct":[
 ["codex","完整函数签名","static int get_range(bitstr_t *, int, int, const char *[], FILE *)","int get_range(bitstr_t *, int, int, const char *[], FILE *)","返回/参数类型全部正确；仅 static 无法从 binary 确证，未计为确认错误。"],["codex","局部 ch/i/num1/num2/num3","int","int","字符/EOF与范围运算宽度正确。"],["codex","bitstr_t","unsigned char typedef","unsigned char typedef","typedef 与一级指针正确。"],
 ["claude-code","完整函数签名","static int get_range(bitstr_t *, int, int, const char *[], FILE *)","int get_range(bitstr_t *, int, int, const char *[], FILE *)","ABI 可见部分全部正确；static 不可判定。"],["claude-code","names","const char *[]","const char *[]","双指针与 const 正确。"],["claude-code","局部 ch/i/num1/num2/num3","int","int","全部正确。"],["claude-code","FILE 参数","FILE *","FILE *","库类型正确。"]],
"findings":["本 case 无确认类型错误，是高 type_match 反例。","两 agent 都准确恢复五参数签名和整数局部，但 GED 仍很高，表明控制流重构差异不等价于类型失败。","源码 static 在 stripped binary 中不可判定，因此按约束没有把缺失 static 强行计错。"]
}
]

PATTERNS={"SC-01","ST-01","PTR-01","INT-01","FN-01","LAYOUT-01","QUAL-01","ARRAY-01","OTHER"}
ROOTS={"a_llm_reasoning_defect","b_info_missing","c_large_function_complexity"}
ATTRS={"codex_specific","claude_code_specific","llm_common_difficulty","function_inherent_difficulty"}

def paths(c):
    base=f"O2-noinline/{c['project']}/{c['binary']}.c"
    trace=f"O2-noinline__{c['project']}__{c['binary']}__{c['function']}.md"
    return {
      "source":c["source"],
      "codex_decompiled":f"decbench-large/results/codex/{base}",
      "claude_code_decompiled":f"decbench-large/results/claude-code/{base}",
      "ghidra_decompiled":f"decbench_deep_cases/results/ghidra/{base}",
      "ida_decompiled":f"decbench_deep_cases/results/ida/{base}",
      "codex_trace_md":f"decbench_deep_cases/results/codex/traces/{trace}",
      "claude_code_trace_md":f"decbench_deep_cases/results/claude-code/traces/{trace}"}

def make(c):
    errs=[]
    for x in c["errors"]:
      eid,agent,pat,role,sdecl,sline,ddecl,dline,desc,excerpt,step,root,detail,attr=x
      assert pat in PATTERNS and root in ROOTS and attr in ATTRS
      errs.append({"error_id":eid,"agent":agent,"pattern":pat,
        "entity":{"source_role":role,"source_declaration":sdecl,"source_line":sline,"decompiled_declaration":ddecl,"decompiled_line":dline},
        "description":desc,"trace_evidence":{"excerpt":excerpt,"reasoning_step":step},
        "root_cause":{"category":root,"detail":detail},"attribution":attr})
    corr=[{"agent":a,"entity":e,"source_type":s,"decompiled_type":d,"note":n} for a,e,s,d,n in c["correct"]]
    report={"report_meta":{"report_id":f"rootcause__{c['slug']}","case":{"project":c['project'],"opt_level":"O2-noinline","binary":c['binary'],"function":c['function'],"size_lines":c['size']},"input_files":paths(c),"decbench_scores":c['metrics']},"errors":errs,"correct_recoveries":corr,
      "summary":{"error_count_by_agent":dict(Counter(e["agent"] for e in errs)),"error_count_by_pattern":dict(Counter(e["pattern"] for e in errs)),"error_count_by_root_cause":dict(Counter(e["root_cause"]["category"] for e in errs)),"error_count_by_attribution":dict(Counter(e["attribution"] for e in errs)),"correct_count_by_agent":dict(Counter(e["agent"] for e in corr)),"key_findings":c["findings"]}}
    for a in ("codex","claude-code"):
      report["summary"]["error_count_by_agent"].setdefault(a,0); report["summary"]["correct_count_by_agent"].setdefault(a,0)
    return report

def markdown(r):
    m=r["report_meta"]; c=m["case"]; s=r["summary"]
    out=[f"# Prompt3 根因报告：{c['project']}/{c['binary']}/{c['function']}","",
      "## 报告元数据","",f"- report_id: `{m['report_id']}`",f"- case: `{c['project']}` / `{c['opt_level']}` / `{c['binary']}` / `{c['function']}` / {c['size_lines']} lines","","输入文件：",""]
    for k,v in m["input_files"].items(): out.append(f"- {k}: `{v}`")
    out += ["","DecBench 分数：","","| agent | type_match | byte_match | ged |","|---|---:|---:|---:|"]
    for a,v in m["decbench_scores"].items(): out.append(f"| {a} | {v['type_match']} | {v['byte_match']} | {v['ged']} |")
    out += ["","## 类型/声明错误",""]
    if not r["errors"]: out.append("未发现可人工确认的类型/声明层错误。不可由 stripped binary 确定的 `static` 等信息未强行计错。")
    for e in r["errors"]:
      q=e["entity"]; rc=e["root_cause"]
      out += [f"### {e['error_id']} — {e['agent']} / {e['pattern']}","",
        f"- 实体：{q['source_role']}",f"- 源码（行 {q['source_line']}）：`{q['source_declaration']}`",f"- 反编译（行 {q['decompiled_line']}）：`{q['decompiled_declaration']}`",f"- 错误：{e['description']}",f"- trace 原文：> {e['trace_evidence']['excerpt'].replace(chr(10), chr(10)+'> ')}",f"- 引入步骤：{e['trace_evidence']['reasoning_step']}",f"- 根因：`{rc['category']}` — {rc['detail']}",f"- 归因：`{e['attribution']}`","" ]
    out += ["## 正确恢复/反例","","| agent | entity | source_type | decompiled_type | note |","|---|---|---|---|---|"]
    esc=lambda x:str(x).replace("|","\\|").replace("\n"," ")
    for x in r["correct_recoveries"]: out.append("| "+" | ".join(esc(x[k]) for k in ["agent","entity","source_type","decompiled_type","note"])+" |")
    out += ["","## 汇总","",f"- error_count_by_agent: `{json.dumps(s['error_count_by_agent'],ensure_ascii=False)}`",f"- error_count_by_pattern: `{json.dumps(s['error_count_by_pattern'],ensure_ascii=False)}`",f"- error_count_by_root_cause: `{json.dumps(s['error_count_by_root_cause'],ensure_ascii=False)}`",f"- error_count_by_attribution: `{json.dumps(s['error_count_by_attribution'],ensure_ascii=False)}`",f"- correct_count_by_agent: `{json.dumps(s['correct_count_by_agent'],ensure_ascii=False)}`","","关键结论：",""]
    out += [f"- {x}" for x in s["key_findings"]]
    return "\n".join(out)+"\n"

for c in CASES:
    r=make(c)
    (OUT/f"rootcause__{c['slug']}.json").write_text(json.dumps(r,ensure_ascii=False,indent=2)+"\n")
    (OUT/f"rootcause__{c['slug']}.md").write_text(markdown(r))
