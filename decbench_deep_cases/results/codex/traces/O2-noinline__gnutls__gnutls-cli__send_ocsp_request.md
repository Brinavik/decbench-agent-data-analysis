# codex trace — O2-noinline__gnutls__gnutls-cli__sub_13d10_0x13d10

- model: gpt-5.6-sol
- binary given to agent: target.bin (original: gnutls-cli)
- status: ok
- elapsed: 267s

## Prompt

```
You are an expert reverse engineer performing MANUAL decompilation by hand.

GOAL
Given a compiled binary, reconstruct the original C source code for ONE target
function. Make the C as correct and as close to the original human-written
source as you can: recover the real control flow, argument and return types,
local variables and their roles, struct/array accesses, and calls to other
functions and to libc.

HARD TOOL POLICY (this is the whole point of the exercise — follow it exactly)
- You are BANNED from using any decompiler or anything that emits C / pseudo-C.
  This includes Ghidra, IDA / Hex-Rays, Binary Ninja, angr, RetDec, Reko,
  r2dec / r2ghidra / radare2's `pdc`/`pdg`, dewolf, and any online or local
  "AI decompiler". Do NOT install, download, or invoke any of them.
- You MAY use only simple, non-decompiling binary inspection tools:
  `objdump`, `readelf`, `nm`, `strings`, `xxd` / `od`, `file`, `size`, `c++filt`.
  Read the raw assembly yourself and reason about it; hand-write the C.

METHOD
- Disassemble the target function (e.g. `objdump -d <binary>`), locate it by its
  virtual address, and read the assembly instruction by instruction.
- Recover the calling convention (argument registers/stack, return register) to
  infer the function signature and argument types.
- Rebuild structured control flow: express loops and branches as idiomatic C
  (`for` / `while` / `if` / `else` / `switch`), NOT as a literal transliteration
  of jumps. Only use `goto` when the control flow genuinely cannot be expressed
  structurally.
- Give variables meaningful C types inferred from how they are used (widths,
  pointer dereferences, sign, struct field offsets). Use real libc prototypes
  for resolved library calls; give plausible types to unknown externs.
- Prefer the code a competent human would have written over an assembly-shaped
  transliteration, while staying faithful to the observed behavior.

OUTPUT CONTRACT
- Write ONLY the reconstructed C for the single target function (plus any
  local typedef/struct/enum declarations it needs) to the output file named
  below.
- The file must contain EXACTLY ONE top-level definition of the target function.
- No markdown fences, no commentary, no analysis prose inside the file — just
  compilable C.

TARGET
- Binary (in your working directory): ./target.bin
- Architecture: x86-64
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x13d10.
- Name the reconstructed function `sub_13d10` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x13d10: endbr64
  0x13d14: push r15
  0x13d16: push r14
  0x13d18: push r13
  0x13d1a: mov r13, rdx
  0x13d1d: push r12
  0x13d1f: push rbp
  0x13d20: mov rbp, rsi
  0x13d23: push rbx
  0x13d24: mov rbx, rdi
  0x13d27: sub rsp, 0x588
  0x13d2e: mov qword ptr [rsp + 0x18], rcx
  0x13d33: mov qword ptr [rsp + 8], r8
  0x13d38: mov rax, qword ptr fs:[0x28]
  0x13d41: mov qword ptr [rsp + 0x578], rax
  0x13d49: lea rax, [rip + 0x2eb7]
  0x13d50: mov qword ptr [rsp + 0x28], rax
  0x13d55: call 0xdc70
  0x13d5a: test rbx, rbx
  0x13d5d: je 0x13fe0
  0x13d63: mov r14, rbx
  0x13d66: lea r12, [rsp + 0x40]
  0x13d6b: lea rdx, [rsp + 0x28]
  0x13d70: lea rsi, [rsp + 0x24]
  0x13d75: mov rdi, r14
  0x13d78: call 0x13ae0
  0x13d7d: mov r9d, dword ptr [rsp + 0x24]
  0x13d82: mov r15, rax
  0x13d85: test r9d, r9d
  0x13d88: jne 0x13f78
  0x13d8e: mov eax, 0x3038
  0x13d93: mov byte ptr [rsp + 0x162], 0
  0x13d9b: lea r11, [rsp + 0x160]
  0x13da3: mov word ptr [rsp + 0x160], ax
  0x13dab: mov rcx, r15
  0x13dae: mov esi, 1
  0x13db3: xor eax, eax
  0x13db5: mov qword ptr [rsp + 0x10], r11
  0x13dba: mov rdi, qword ptr [rip + 0xe51f]
  0x13dc1: lea rdx, [rip + 0x4f10]
  0x13dc8: call 0x8550
  0x13dcd: mov rcx, qword ptr [rsp + 8]
  0x13dd2: mov rdx, r12
  0x13dd5: mov rsi, r13
  0x13dd8: pxor xmm0, xmm0
  0x13ddc: mov rdi, rbp
  0x13ddf: lea r13, [rsp + 0x170]
  0x13de7: movaps xmmword ptr [rsp + 0x30], xmm0
  0x13dec: call 0x13c00
  0x13df1: mov eax, dword ptr [rsp + 0x48]
  0x13df5: mov ecx, 0x400
  0x13dfa: mov rdi, r13
  0x13dfd: lea r8, [rip + 0x4efc]
  0x13e04: mov edx, 1
  0x13e09: mov esi, 0x400
  0x13e0e: push rax
  0x13e0f: xor eax, eax
  0x13e11: push r15
  0x13e13: mov r9, qword ptr [rsp + 0x38]
  0x13e18: call 0x9340
  0x13e1d: mov rdi, r13
  0x13e20: lea rbp, [rsp + 0x60]
  0x13e25: call 0x8a40
  0x13e2a: push 0
  0x13e2c: lea r9, [rip + 0x2f92]
  0x13e33: xor ecx, ecx
  0x13e35: push 0
  0x13e37: mov r12, rax
  0x13e3a: mov r8d, 0x28
  0x13e40: mov rsi, r15
  0x13e43: push 0
  0x13e45: mov rdi, rbp
  0x13e48: push 0
  0x13e4a: mov rdx, qword ptr [rsp + 0x40]
  0x13e4f: call 0x11250
  0x13e54: add rsp, 0x30
  0x13e58: mov edx, r12d
  0x13e5b: mov rsi, r13
  0x13e5e: mov rdi, rbp
  0x13e61: lea r12, [rip + 0x80898]

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_13d10`).

```

## Agent transcript (stdout/stderr)

```
Created [decompiled.c](/tmp/llmdec_codex_366ssvk9/decompiled.c).

Reading additional input from stdin...
OpenAI Codex v0.144.1
--------
workdir: /tmp/llmdec_codex_366ssvk9
model: gpt-5.6-sol
provider: openai
approval: never
sandbox: danger-full-access
reasoning effort: high
reasoning summaries: none
session id: 019f87ed-19da-7021-869c-714107af35a5
--------
user
You are an expert reverse engineer performing MANUAL decompilation by hand.

GOAL
Given a compiled binary, reconstruct the original C source code for ONE target
function. Make the C as correct and as close to the original human-written
source as you can: recover the real control flow, argument and return types,
local variables and their roles, struct/array accesses, and calls to other
functions and to libc.

HARD TOOL POLICY (this is the whole point of the exercise — follow it exactly)
- You are BANNED from using any decompiler or anything that emits C / pseudo-C.
  This includes Ghidra, IDA / Hex-Rays, Binary Ninja, angr, RetDec, Reko,
  r2dec / r2ghidra / radare2's `pdc`/`pdg`, dewolf, and any online or local
  "AI decompiler". Do NOT install, download, or invoke any of them.
- You MAY use only simple, non-decompiling binary inspection tools:
  `objdump`, `readelf`, `nm`, `strings`, `xxd` / `od`, `file`, `size`, `c++filt`.
  Read the raw assembly yourself and reason about it; hand-write the C.

METHOD
- Disassemble the target function (e.g. `objdump -d <binary>`), locate it by its
  virtual address, and read the assembly instruction by instruction.
- Recover the calling convention (argument registers/stack, return register) to
  infer the function signature and argument types.
- Rebuild structured control flow: express loops and branches as idiomatic C
  (`for` / `while` / `if` / `else` / `switch`), NOT as a literal transliteration
  of jumps. Only use `goto` when the control flow genuinely cannot be expressed
  structurally.
- Give variables meaningful C types inferred from how they are used (widths,
  pointer dereferences, sign, struct field offsets). Use real libc prototypes
  for resolved library calls; give plausible types to unknown externs.
- Prefer the code a competent human would have written over an assembly-shaped
  transliteration, while staying faithful to the observed behavior.

OUTPUT CONTRACT
- Write ONLY the reconstructed C for the single target function (plus any
  local typedef/struct/enum declarations it needs) to the output file named
  below.
- The file must contain EXACTLY ONE top-level definition of the target function.
- No markdown fences, no commentary, no analysis prose inside the file — just
  compilable C.

TARGET
- Binary (in your working directory): ./target.bin
- Architecture: x86-64
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x13d10.
- Name the reconstructed function `sub_13d10` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x13d10: endbr64
  0x13d14: push r15
  0x13d16: push r14
  0x13d18: push r13
  0x13d1a: mov r13, rdx
  0x13d1d: push r12
  0x13d1f: push rbp
  0x13d20: mov rbp, rsi
  0x13d23: push rbx
  0x13d24: mov rbx, rdi
  0x13d27: sub rsp, 0x588
  0x13d2e: mov qword ptr [rsp + 0x18], rcx
  0x13d33: mov qword ptr [rsp + 8], r8
  0x13d38: mov rax, qword ptr fs:[0x28]
  0x13d41: mov qword ptr [rsp + 0x578], rax
  0x13d49: lea rax, [rip + 0x2eb7]
  0x13d50: mov qword ptr [rsp + 0x28], rax
  0x13d55: call 0xdc70
  0x13d5a: test rbx, rbx
  0x13d5d: je 0x13fe0
  0x13d63: mov r14, rbx
  0x13d66: lea r12, [rsp + 0x40]
  0x13d6b: lea rdx, [rsp + 0x28]
  0x13d70: lea rsi, [rsp + 0x24]
  0x13d75: mov rdi, r14
  0x13d78: call 0x13ae0
  0x13d7d: mov r9d, dword ptr [rsp + 0x24]
  0x13d82: mov r15, rax
  0x13d85: test r9d, r9d
  0x13d88: jne 0x13f78
  0x13d8e: mov eax, 0x3038
  0x13d93: mov byte ptr [rsp + 0x162], 0
  0x13d9b: lea r11, [rsp + 0x160]
  0x13da3: mov word ptr [rsp + 0x160], ax
  0x13dab: mov rcx, r15
  0x13dae: mov esi, 1
  0x13db3: xor eax, eax
  0x13db5: mov qword ptr [rsp + 0x10], r11
  0x13dba: mov rdi, qword ptr [rip + 0xe51f]
  0x13dc1: lea rdx, [rip + 0x4f10]
  0x13dc8: call 0x8550
  0x13dcd: mov rcx, qword ptr [rsp + 8]
  0x13dd2: mov rdx, r12
  0x13dd5: mov rsi, r13
  0x13dd8: pxor xmm0, xmm0
  0x13ddc: mov rdi, rbp
  0x13ddf: lea r13, [rsp + 0x170]
  0x13de7: movaps xmmword ptr [rsp + 0x30], xmm0
  0x13dec: call 0x13c00
  0x13df1: mov eax, dword ptr [rsp + 0x48]
  0x13df5: mov ecx, 0x400
  0x13dfa: mov rdi, r13
  0x13dfd: lea r8, [rip + 0x4efc]
  0x13e04: mov edx, 1
  0x13e09: mov esi, 0x400
  0x13e0e: push rax
  0x13e0f: xor eax, eax
  0x13e11: push r15
  0x13e13: mov r9, qword ptr [rsp + 0x38]
  0x13e18: call 0x9340
  0x13e1d: mov rdi, r13
  0x13e20: lea rbp, [rsp + 0x60]
  0x13e25: call 0x8a40
  0x13e2a: push 0
  0x13e2c: lea r9, [rip + 0x2f92]
  0x13e33: xor ecx, ecx
  0x13e35: push 0
  0x13e37: mov r12, rax
  0x13e3a: mov r8d, 0x28
  0x13e40: mov rsi, r15
  0x13e43: push 0
  0x13e45: mov rdi, rbp
  0x13e48: push 0
  0x13e4a: mov rdx, qword ptr [rsp + 0x40]
  0x13e4f: call 0x11250
  0x13e54: add rsp, 0x30
  0x13e58: mov edx, r12d
  0x13e5b: mov rsi, r13
  0x13e5e: mov rdi, rbp
  0x13e61: lea r12, [rip + 0x80898]

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_13d10`).

codex
I’ll inspect the binary using only the permitted low-level tools, map the target and its direct callees from assembly, then hand-write and syntax-check the single-function C output.
  → Inspect binary metadata, target disassembly, constants, and relocations
  • Infer helper semantics and reconstruct structured control flow
  • Write decompiled.c and verify the output contract
exec
/bin/bash -lc 'file ./target.bin && readelf -hW ./target.bin && readelf -SW ./target.bin && objdump -d -M intel --start-address=0x13d10 --stop-address=0x14100 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:
./target.bin: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=e2e8e12f76e73f8a423fccc447700c5d5b8fbab1, for GNU/Linux 3.2.0, stripped
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Position-Independent Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x9d80
  Start of program headers:          64 (bytes into file)
  Start of section headers:          136168 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         30
  Section header string table index: 29
There are 30 section headers, starting at offset 0x213e8:

Section Headers:
  [Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            0000000000000000 000000 000000 00      0   0  0
  [ 1] .interp           PROGBITS        0000000000000318 000318 00001c 00   A  0   0  1
  [ 2] .note.gnu.property NOTE            0000000000000338 000338 000030 00   A  0   0  8
  [ 3] .note.gnu.build-id NOTE            0000000000000368 000368 000024 00   A  0   0  4
  [ 4] .note.ABI-tag     NOTE            000000000000038c 00038c 000020 00   A  0   0  4
  [ 5] .gnu.hash         GNU_HASH        00000000000003b0 0003b0 000040 00   A  6   0  8
  [ 6] .dynsym           DYNSYM          00000000000003f0 0003f0 001dd0 18   A  7   1  8
  [ 7] .dynstr           STRTAB          00000000000021c0 0021c0 001ab5 00   A  0   0  1
  [ 8] .gnu.version      VERSYM          0000000000003c76 003c76 00027c 02   A  6   0  2
  [ 9] .gnu.version_r    VERNEED         0000000000003ef8 003ef8 000190 00   A  7   3  8
  [10] .rela.dyn         RELA            0000000000004088 004088 000a38 18   A  6   0  8
  [11] .rela.plt         RELA            0000000000004ac0 004ac0 001c80 18  AI  6  25  8
  [12] .init             PROGBITS        0000000000007000 007000 00001b 00  AX  0   0  4
  [13] .plt              PROGBITS        0000000000007020 007020 001310 10  AX  0   0 16
  [14] .plt.got          PROGBITS        0000000000008330 008330 000010 10  AX  0   0 16
  [15] .plt.sec          PROGBITS        0000000000008340 008340 001300 10  AX  0   0 16
  [16] .text             PROGBITS        0000000000009640 009640 00c5cc 00  AX  0   0 16
  [17] .fini             PROGBITS        0000000000015c0c 015c0c 00000d 00  AX  0   0  4
  [18] .rodata           PROGBITS        0000000000016000 016000 0053f4 00   A  0   0 32
  [19] .eh_frame_hdr     PROGBITS        000000000001b3f4 01b3f4 000414 00   A  0   0  4
  [20] .eh_frame         PROGBITS        000000000001b808 01b808 0019c4 00   A  0   0  8
  [21] .init_array       INIT_ARRAY      000000000001e950 01d950 000008 08  WA  0   0  8
  [22] .fini_array       FINI_ARRAY      000000000001e958 01d958 000008 08  WA  0   0  8
  [23] .data.rel.ro      PROGBITS        000000000001e960 01d960 000aa0 00  WA  0   0 32
  [24] .dynamic          DYNAMIC         000000000001f400 01e400 000210 10  WA  7   0  8
  [25] .got              PROGBITS        000000000001f610 01e610 0009e0 08  WA  0   0  8
  [26] .data             PROGBITS        0000000000020000 01f000 0022a0 00  WA  0   0 32
  [27] .bss              NOBITS          00000000000222a0 0212a0 073648 00  WA  0   0 32
  [28] .comment          PROGBITS        0000000000000000 0212a0 00002d 01  MS  0   0  1
  [29] .shstrtab         STRTAB          0000000000000000 0212cd 000117 00      0   0  1
Key to Flags:
  W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
  L (link order), O (extra OS processing required), G (group), T (TLS),
  C (compressed), x (unknown), o (OS specific), E (exclude),
  D (mbind), l (large), p (processor specific)

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000013d10 <.text+0xa6d0>:
   13d10:	f3 0f 1e fa          	endbr64 
   13d14:	41 57                	push   r15
   13d16:	41 56                	push   r14
   13d18:	41 55                	push   r13
   13d1a:	49 89 d5             	mov    r13,rdx
   13d1d:	41 54                	push   r12
   13d1f:	55                   	push   rbp
   13d20:	48 89 f5             	mov    rbp,rsi
   13d23:	53                   	push   rbx
   13d24:	48 89 fb             	mov    rbx,rdi
   13d27:	48 81 ec 88 05 00 00 	sub    rsp,0x588
   13d2e:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
   13d33:	4c 89 44 24 08       	mov    QWORD PTR [rsp+0x8],r8
   13d38:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   13d3f:	00 00 
   13d41:	48 89 84 24 78 05 00 	mov    QWORD PTR [rsp+0x578],rax
   13d48:	00 
   13d49:	48 8d 05 b7 2e 00 00 	lea    rax,[rip+0x2eb7]        # 16c07 <gnutls_reauth@plt+0xd5d7>
   13d50:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   13d55:	e8 16 9f ff ff       	call   dc70 <gnutls_reauth@plt+0x4640>
   13d5a:	48 85 db             	test   rbx,rbx
   13d5d:	0f 84 7d 02 00 00    	je     13fe0 <gnutls_reauth@plt+0xa9b0>
   13d63:	49 89 de             	mov    r14,rbx
   13d66:	4c 8d 64 24 40       	lea    r12,[rsp+0x40]
   13d6b:	48 8d 54 24 28       	lea    rdx,[rsp+0x28]
   13d70:	48 8d 74 24 24       	lea    rsi,[rsp+0x24]
   13d75:	4c 89 f7             	mov    rdi,r14
   13d78:	e8 63 fd ff ff       	call   13ae0 <gnutls_reauth@plt+0xa4b0>
   13d7d:	44 8b 4c 24 24       	mov    r9d,DWORD PTR [rsp+0x24]
   13d82:	49 89 c7             	mov    r15,rax
   13d85:	45 85 c9             	test   r9d,r9d
   13d88:	0f 85 ea 01 00 00    	jne    13f78 <gnutls_reauth@plt+0xa948>
   13d8e:	b8 38 30 00 00       	mov    eax,0x3038
   13d93:	c6 84 24 62 01 00 00 	mov    BYTE PTR [rsp+0x162],0x0
   13d9a:	00 
   13d9b:	4c 8d 9c 24 60 01 00 	lea    r11,[rsp+0x160]
   13da2:	00 
   13da3:	66 89 84 24 60 01 00 	mov    WORD PTR [rsp+0x160],ax
   13daa:	00 
   13dab:	4c 89 f9             	mov    rcx,r15
   13dae:	be 01 00 00 00       	mov    esi,0x1
   13db3:	31 c0                	xor    eax,eax
   13db5:	4c 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],r11
   13dba:	48 8b 3d 1f e5 00 00 	mov    rdi,QWORD PTR [rip+0xe51f]        # 222e0 <stderr@GLIBC_2.2.5>
   13dc1:	48 8d 15 10 4f 00 00 	lea    rdx,[rip+0x4f10]        # 18cd8 <gnutls_reauth@plt+0xf6a8>
   13dc8:	e8 83 47 ff ff       	call   8550 <__fprintf_chk@plt>
   13dcd:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   13dd2:	4c 89 e2             	mov    rdx,r12
   13dd5:	4c 89 ee             	mov    rsi,r13
   13dd8:	66 0f ef c0          	pxor   xmm0,xmm0
   13ddc:	48 89 ef             	mov    rdi,rbp
   13ddf:	4c 8d ac 24 70 01 00 	lea    r13,[rsp+0x170]
   13de6:	00 
   13de7:	0f 29 44 24 30       	movaps XMMWORD PTR [rsp+0x30],xmm0
   13dec:	e8 0f fe ff ff       	call   13c00 <gnutls_reauth@plt+0xa5d0>
   13df1:	8b 44 24 48          	mov    eax,DWORD PTR [rsp+0x48]
   13df5:	b9 00 04 00 00       	mov    ecx,0x400
   13dfa:	4c 89 ef             	mov    rdi,r13
   13dfd:	4c 8d 05 fc 4e 00 00 	lea    r8,[rip+0x4efc]        # 18d00 <gnutls_reauth@plt+0xf6d0>
   13e04:	ba 01 00 00 00       	mov    edx,0x1
   13e09:	be 00 04 00 00       	mov    esi,0x400
   13e0e:	50                   	push   rax
   13e0f:	31 c0                	xor    eax,eax
   13e11:	41 57                	push   r15
   13e13:	4c 8b 4c 24 38       	mov    r9,QWORD PTR [rsp+0x38]
   13e18:	e8 23 55 ff ff       	call   9340 <__snprintf_chk@plt>
   13e1d:	4c 89 ef             	mov    rdi,r13
   13e20:	48 8d 6c 24 60       	lea    rbp,[rsp+0x60]
   13e25:	e8 16 4c ff ff       	call   8a40 <strlen@plt>
   13e2a:	6a 00                	push   0x0
   13e2c:	4c 8d 0d 92 2f 00 00 	lea    r9,[rip+0x2f92]        # 16dc5 <gnutls_reauth@plt+0xd795>
   13e33:	31 c9                	xor    ecx,ecx
   13e35:	6a 00                	push   0x0
   13e37:	49 89 c4             	mov    r12,rax
   13e3a:	41 b8 28 00 00 00    	mov    r8d,0x28
   13e40:	4c 89 fe             	mov    rsi,r15
   13e43:	6a 00                	push   0x0
   13e45:	48 89 ef             	mov    rdi,rbp
   13e48:	6a 00                	push   0x0
   13e4a:	48 8b 54 24 40       	mov    rdx,QWORD PTR [rsp+0x40]
   13e4f:	e8 fc d3 ff ff       	call   11250 <gnutls_reauth@plt+0x7c20>
   13e54:	48 83 c4 30          	add    rsp,0x30
   13e58:	44 89 e2             	mov    edx,r12d
   13e5b:	4c 89 ee             	mov    rsi,r13
   13e5e:	48 89 ef             	mov    rdi,rbp
   13e61:	4c 8d 25 98 08 08 00 	lea    r12,[rip+0x80898]        # 94700 <stdout@GLIBC_2.2.5+0x72418>
   13e68:	4c 8d 6c 24 30       	lea    r13,[rsp+0x30]
   13e6d:	e8 1e d1 ff ff       	call   10f90 <gnutls_reauth@plt+0x7960>
   13e72:	8b 54 24 48          	mov    edx,DWORD PTR [rsp+0x48]
   13e76:	48 8b 74 24 40       	mov    rsi,QWORD PTR [rsp+0x40]
   13e7b:	48 89 ef             	mov    rdi,rbp
   13e7e:	e8 0d d1 ff ff       	call   10f90 <gnutls_reauth@plt+0x7960>
   13e83:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   13e88:	ff 15 1a e4 00 00    	call   QWORD PTR [rip+0xe41a]        # 222a8 <gnutls_free@GNUTLS_3_4>
   13e8e:	48 c7 44 24 40 00 00 	mov    QWORD PTR [rsp+0x40],0x0
   13e95:	00 00 
   13e97:	ba 01 10 00 00       	mov    edx,0x1001
   13e9c:	4c 89 e6             	mov    rsi,r12
   13e9f:	48 89 ef             	mov    rdi,rbp
   13ea2:	e8 e9 ce ff ff       	call   10d90 <gnutls_reauth@plt+0x7760>
   13ea7:	41 89 c7             	mov    r15d,eax
   13eaa:	85 c0                	test   eax,eax
   13eac:	0f 8f fe 00 00 00    	jg     13fb0 <gnutls_reauth@plt+0xa980>
   13eb2:	4c 8b 64 24 30       	mov    r12,QWORD PTR [rsp+0x30]
   13eb7:	85 c0                	test   eax,eax
   13eb9:	0f 85 01 01 00 00    	jne    13fc0 <gnutls_reauth@plt+0xa990>
   13ebf:	44 8b 6c 24 38       	mov    r13d,DWORD PTR [rsp+0x38]
   13ec4:	45 85 ed             	test   r13d,r13d
   13ec7:	0f 84 f3 00 00 00    	je     13fc0 <gnutls_reauth@plt+0xa990>
   13ecd:	31 f6                	xor    esi,esi
   13ecf:	48 89 ef             	mov    rdi,rbp
   13ed2:	e8 69 d1 ff ff       	call   11040 <gnutls_reauth@plt+0x7a10>
   13ed7:	44 89 ee             	mov    esi,r13d
   13eda:	b9 04 00 00 00       	mov    ecx,0x4
   13edf:	4c 89 e7             	mov    rdi,r12
   13ee2:	48 8d 15 c0 2f 00 00 	lea    rdx,[rip+0x2fc0]        # 16ea9 <gnutls_reauth@plt+0xd879>
   13ee9:	e8 a2 52 ff ff       	call   9190 <memmem@plt>
   13eee:	48 85 c0             	test   rax,rax
   13ef1:	0f 84 c0 01 00 00    	je     140b7 <gnutls_reauth@plt+0xaa87>
   13ef7:	48 8d 68 04          	lea    rbp,[rax+0x4]
   13efb:	48 89 e8             	mov    rax,rbp
   13efe:	4c 29 e0             	sub    rax,r12
   13f01:	41 29 c5             	sub    r13d,eax
   13f04:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   13f09:	44 89 ef             	mov    edi,r13d
   13f0c:	44 89 68 08          	mov    DWORD PTR [rax+0x8],r13d
   13f10:	e8 8b 48 ff ff       	call   87a0 <malloc@plt>
   13f15:	48 89 c7             	mov    rdi,rax
   13f18:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   13f1d:	48 89 38             	mov    QWORD PTR [rax],rdi
   13f20:	48 85 ff             	test   rdi,rdi
   13f23:	0f 84 97 00 00 00    	je     13fc0 <gnutls_reauth@plt+0xa990>
   13f29:	8b 50 08             	mov    edx,DWORD PTR [rax+0x8]
   13f2c:	48 89 ee             	mov    rsi,rbp
   13f2f:	e8 0c 56 ff ff       	call   9540 <memcpy@plt>
   13f34:	4c 89 e7             	mov    rdi,r12
   13f37:	e8 c4 4a ff ff       	call   8a00 <free@plt>
   13f3c:	49 39 de             	cmp    r14,rbx
   13f3f:	74 08                	je     13f49 <gnutls_reauth@plt+0xa919>
   13f41:	4c 89 f7             	mov    rdi,r14
   13f44:	e8 b7 4a ff ff       	call   8a00 <free@plt>
   13f49:	48 8b 84 24 78 05 00 	mov    rax,QWORD PTR [rsp+0x578]
   13f50:	00 
   13f51:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   13f58:	00 00 
   13f5a:	0f 85 7a 01 00 00    	jne    140da <gnutls_reauth@plt+0xaaaa>
   13f60:	48 81 c4 88 05 00 00 	add    rsp,0x588
   13f67:	44 89 f8             	mov    eax,r15d
   13f6a:	5b                   	pop    rbx
   13f6b:	5d                   	pop    rbp
   13f6c:	41 5c                	pop    r12
   13f6e:	41 5d                	pop    r13
   13f70:	41 5e                	pop    r14
   13f72:	41 5f                	pop    r15
   13f74:	c3                   	ret    
   13f75:	0f 1f 00             	nop    DWORD PTR [rax]
   13f78:	4c 8d 9c 24 60 01 00 	lea    r11,[rsp+0x160]
   13f7f:	00 
   13f80:	4c 8d 05 1a 2f 00 00 	lea    r8,[rip+0x2f1a]        # 16ea1 <gnutls_reauth@plt+0xd871>
   13f87:	b9 10 00 00 00       	mov    ecx,0x10
   13f8c:	31 c0                	xor    eax,eax
   13f8e:	4c 89 df             	mov    rdi,r11
   13f91:	ba 01 00 00 00       	mov    edx,0x1
   13f96:	be 10 00 00 00       	mov    esi,0x10
   13f9b:	4c 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],r11
   13fa0:	e8 9b 53 ff ff       	call   9340 <__snprintf_chk@plt>
   13fa5:	4c 8b 5c 24 10       	mov    r11,QWORD PTR [rsp+0x10]
   13faa:	e9 fc fd ff ff       	jmp    13dab <gnutls_reauth@plt+0xa77b>
   13faf:	90                   	nop
   13fb0:	48 63 f8             	movsxd rdi,eax
   13fb3:	4c 89 ee             	mov    rsi,r13
   13fb6:	e8 d5 fb ff ff       	call   13b90 <gnutls_reauth@plt+0xa560>
   13fbb:	e9 d7 fe ff ff       	jmp    13e97 <gnutls_reauth@plt+0xa867>
   13fc0:	48 8d 3d dd 2e 00 00 	lea    rdi,[rip+0x2edd]        # 16ea4 <gnutls_reauth@plt+0xd874>
   13fc7:	41 bf ff ff ff ff    	mov    r15d,0xffffffff
   13fcd:	e8 0e 54 ff ff       	call   93e0 <perror@plt>
   13fd2:	e9 5d ff ff ff       	jmp    13f34 <gnutls_reauth@plt+0xa904>
   13fd7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   13fde:	00 00 
   13fe0:	45 31 f6             	xor    r14d,r14d
   13fe3:	4c 8d 64 24 40       	lea    r12,[rsp+0x40]
   13fe8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   13fef:	00 
   13ff0:	44 89 f6             	mov    esi,r14d
   13ff3:	45 31 c0             	xor    r8d,r8d
   13ff6:	4c 89 e1             	mov    rcx,r12
   13ff9:	ba 16 27 00 00       	mov    edx,0x2716
   13ffe:	48 89 ef             	mov    rdi,rbp
   14001:	41 83 c6 01          	add    r14d,0x1
   14005:	e8 b6 4b ff ff       	call   8bc0 <gnutls_x509_crt_get_authority_info_access@plt>
   1400a:	83 f8 97             	cmp    eax,0xffffff97
   1400d:	74 e1                	je     13ff0 <gnutls_reauth@plt+0xa9c0>
   1400f:	85 c0                	test   eax,eax
   14011:	78 4d                	js     14060 <gnutls_reauth@plt+0xaa30>
   14013:	8b 44 24 48          	mov    eax,DWORD PTR [rsp+0x48]
   14017:	8d 78 01             	lea    edi,[rax+0x1]
   1401a:	e8 81 47 ff ff       	call   87a0 <malloc@plt>
   1401f:	49 89 c6             	mov    r14,rax
   14022:	48 85 c0             	test   rax,rax
   14025:	0f 84 b4 00 00 00    	je     140df <gnutls_reauth@plt+0xaaaf>
   1402b:	4c 8b 7c 24 40       	mov    r15,QWORD PTR [rsp+0x40]
   14030:	8b 54 24 48          	mov    edx,DWORD PTR [rsp+0x48]
   14034:	48 89 c7             	mov    rdi,rax
   14037:	4c 89 fe             	mov    rsi,r15
   1403a:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   1403f:	e8 fc 54 ff ff       	call   9540 <memcpy@plt>
   14044:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
   14049:	4c 89 ff             	mov    rdi,r15
   1404c:	41 c6 04 16 00       	mov    BYTE PTR [r14+rdx*1],0x0
   14051:	ff 15 51 e2 00 00    	call   QWORD PTR [rip+0xe251]        # 222a8 <gnutls_free@GNUTLS_3_4>
   14057:	e9 0f fd ff ff       	jmp    13d6b <gnutls_reauth@plt+0xa73b>
   1405c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   14060:	45 31 f6             	xor    r14d,r14d
   14063:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   14068:	44 89 f6             	mov    esi,r14d
   1406b:	45 31 c0             	xor    r8d,r8d
   1406e:	4c 89 e1             	mov    rcx,r12
   14071:	ba 16 27 00 00       	mov    edx,0x2716
   14076:	4c 89 ef             	mov    rdi,r13
   14079:	41 83 c6 01          	add    r14d,0x1
   1407d:	e8 3e 4b ff ff       	call   8bc0 <gnutls_x509_crt_get_authority_info_access@plt>
   14082:	83 f8 97             	cmp    eax,0xffffff97
   14085:	74 e1                	je     14068 <gnutls_reauth@plt+0xaa38>
   14087:	41 89 c7             	mov    r15d,eax
   1408a:	85 c0                	test   eax,eax
   1408c:	79 85                	jns    14013 <gnutls_reauth@plt+0xa9e3>
   1408e:	89 c7                	mov    edi,eax
   14090:	e8 5b 4f ff ff       	call   8ff0 <gnutls_strerror@plt>
   14095:	48 8b 3d 44 e2 00 00 	mov    rdi,QWORD PTR [rip+0xe244]        # 222e0 <stderr@GLIBC_2.2.5>
   1409c:	be 01 00 00 00       	mov    esi,0x1
   140a1:	48 8d 15 f8 4b 00 00 	lea    rdx,[rip+0x4bf8]        # 18ca0 <gnutls_reauth@plt+0xf670>
   140a8:	48 89 c1             	mov    rcx,rax
   140ab:	31 c0                	xor    eax,eax
   140ad:	e8 9e 44 ff ff       	call   8550 <__fprintf_chk@plt>
   140b2:	e9 92 fe ff ff       	jmp    13f49 <gnutls_reauth@plt+0xa919>
   140b7:	48 8b 3d 22 e2 00 00 	mov    rdi,QWORD PTR [rip+0xe222]        # 222e0 <stderr@GLIBC_2.2.5>
   140be:	48 8d 15 8b 28 00 00 	lea    rdx,[rip+0x288b]        # 16950 <gnutls_reauth@plt+0xd320>
   140c5:	be 01 00 00 00       	mov    esi,0x1
   140ca:	41 bf ff ff ff ff    	mov    r15d,0xffffffff
   140d0:	e8 7b 44 ff ff       	call   8550 <__fprintf_chk@plt>
   140d5:	e9 5a fe ff ff       	jmp    13f34 <gnutls_reauth@plt+0xa904>
   140da:	e8 41 4f ff ff       	call   9020 <__stack_chk_fail@plt>
   140df:	41 83 cf ff          	or     r15d,0xffffffff
   140e3:	e9 61 fe ff ff       	jmp    13f49 <gnutls_reauth@plt+0xa919>
   140e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   140ef:	00 
   140f0:	f3 0f 1e fa          	endbr64 
   140f4:	53                   	push   rbx
   140f5:	89 fb                	mov    ebx,edi
   140f7:	85 ff                	test   edi,edi
   140f9:	0f 84 51 01 00 00    	je     14250 <gnutls_reauth@plt+0xac20>
   140ff:	31                   	.byte 0x31

codex
The target is a certificate-status retrieval routine. Its main path builds an HTTP request, sends it through internal transport helpers, extracts the response body after the header terminator, and returns it through a pointer/length pair. I’m now resolving exact strings, error behavior, and helper signatures.
exec
/bin/bash -lc 'readelf -Ws ./target.bin
objdump -s --start-address=0x168f0 --stop-address=0x18d80 ./target.bin
objdump -d -M intel --start-address=0x13a80 --stop-address=0x13d10 ./target.bin
objdump -d -M intel --start-address=0x10d50 --stop-address=0x11320 ./target.bin
objdump -d -M intel --start-address=0xdc20 --stop-address=0xdd20 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:

Symbol table '.dynsym' contains 318 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_compression_get_id@GNUTLS_3_4 (2)
     2: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_credentials_set@GNUTLS_3_4 (2)
     3: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_heartbeat_pong@GNUTLS_3_4 (2)
     4: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_url_is_supported@GNUTLS_3_4 (2)
     5: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_privkey_import_x509_raw@GNUTLS_3_4 (2)
     6: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_encrypt2@GNUTLS_3_4 (2)
     7: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fileno@GLIBC_2.2.5 (3)
     8: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_prf_rfc5705@GNUTLS_3_4 (2)
     9: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dup2@GLIBC_2.2.5 (3)
    10: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_pull_timeout_function@GNUTLS_3_4 (2)
    11: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_client_get_request_status@GNUTLS_3_4 (2)
    12: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_get_id@GNUTLS_3_4 (2)
    13: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memset@GLIBC_2.2.5 (3)
    14: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_mac_list@GNUTLS_3_4 (2)
    15: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_errno@GNUTLS_3_4 (2)
    16: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_mac_get@GNUTLS_3_4 (2)
    17: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND snprintf@GLIBC_2.2.5 (3)
    18: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_protocol_list@GNUTLS_3_4 (2)
    19: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_list_import2@GNUTLS_3_4 (2)
    20: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND shutdown@GLIBC_2.2.5 (3)
    21: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND inet_pton@GLIBC_2.2.5 (3)
    22: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND close@GLIBC_2.2.5 (3)
    23: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_mac_list@GNUTLS_3_4 (2)
    24: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_params_deinit@GNUTLS_3_4 (2)
    25: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_protocol_get_name@GNUTLS_3_4 (2)
    26: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND abort@GLIBC_2.2.5 (3)
    27: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_recv@GNUTLS_3_4 (2)
    28: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pcert_import_rawpk_raw@GNUTLS_3_6_6 (4)
    29: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_fips140_mode_enabled@GNUTLS_3_4 (2)
    30: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_idna_map@GNUTLS_3_4 (2)
    31: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_import@GNUTLS_3_4 (2)
    32: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND clock_gettime@GLIBC_2.17 (5)
    33: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_get_prime_bits@GNUTLS_3_4 (2)
    34: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __fprintf_chk@GLIBC_2.3.4 (6)
    35: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_sign_list@GNUTLS_3_4 (2)
    36: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_error_is_fatal@GNUTLS_3_4 (2)
    37: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_rehandshake@GNUTLS_3_4 (2)
    38: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    39: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_trust_list_add_system_trust@GNUTLS_3_4 (2)
    40: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_handshake@GNUTLS_3_4 (2)
    41: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_get_issuer@GNUTLS_3_4 (2)
    42: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_alpn_set_protocols@GNUTLS_3_4 (2)
    43: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND select@GLIBC_2.2.5 (3)
    44: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND execvp@GLIBC_2.2.5 (3)
    45: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND exit@GLIBC_2.2.5 (3)
    46: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_compression_get_name@GNUTLS_3_4 (2)
    47: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_heartbeat_ping@GNUTLS_3_4 (2)
    48: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_digest_list@GNUTLS_3_4 (2)
    49: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __assert_fail@GLIBC_2.2.5 (3)
    50: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fstat@GLIBC_2.33 (7)
    51: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __printf_chk@GLIBC_2.3.4 (6)
    52: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_key_update@GNUTLS_3_6_3 (8)
    53: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getaddrinfo@GLIBC_2.2.5 (3)
    54: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_server_get_username@GNUTLS_3_4 (2)
    55: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcasecmp@GLIBC_2.2.5 (3)
    56: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_string_list@GNUTLS_3_4 (2)
    57: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_sign_get_name@GNUTLS_3_4 (2)
    58: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setvbuf@GLIBC_2.2.5 (3)
    59: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pk_list@GNUTLS_3_4 (2)
    60: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_kx_get@GNUTLS_3_4 (2)
    61: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_set_client_credentials_function@GNUTLS_3_4 (2)
    62: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_alert_get@GNUTLS_3_4 (2)
    63: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_send_early_data@GNUTLS_3_6_5 (9)
    64: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hmac_deinit@GNUTLS_3_4 (2)
    65: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND reallocarray@GLIBC_2.26 (10)
    66: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ecc_curve_get@GNUTLS_3_4 (2)
    67: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_get_tag_size@GNUTLS_3_4 (2)
    68: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_trust_list_add_trust_file@GNUTLS_3_4 (2)
    69: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND read@GLIBC_2.2.5 (3)
    70: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_privkey_init@GNUTLS_3_4 (2)
    71: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncmp@GLIBC_2.2.5 (3)
    72: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND malloc@GLIBC_2.2.5 (3)
    73: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fopen@GLIBC_2.2.5 (3)
    74: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND recv@GLIBC_2.2.5 (3)
    75: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_server_set_request@GNUTLS_3_4 (2)
    76: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_req_set_nonce@GNUTLS_3_4 (2)
    77: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_set_prime_bits@GNUTLS_3_4 (2)
    78: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_trust_list@GNUTLS_3_4 (2)
    79: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_get_data2@GNUTLS_3_4 (2)
    80: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_init@GNUTLS_3_4 (2)
    81: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_allocate_client_credentials@GNUTLS_3_4 (2)
    82: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_type_get@GNUTLS_3_4 (2)
    83: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_global_init@GNUTLS_3_4 (2)
    84: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __memcpy_chk@GLIBC_2.3.4 (6)
    85: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_get_peers_public_bits@GNUTLS_3_4 (2)
    86: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_alert_get_name@GNUTLS_3_4 (2)
    87: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hex_decode@GNUTLS_3_4 (2)
    88: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setsockopt@GLIBC_2.2.5 (3)
    89: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_get_desc@GNUTLS_3_4 (2)
    90: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sysconf@GLIBC_2.2.5 (3)
    91: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_send_range@GNUTLS_3_4 (2)
    92: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_safe_renegotiation_status@GNUTLS_3_4 (2)
    93: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_suite_info@GNUTLS_3_4 (2)
    94: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fgets@GLIBC_2.2.5 (3)
    95: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_global_deinit@GNUTLS_3_4 (2)
    96: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_mac_get_name@GNUTLS_3_4 (2)
    97: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_memset@GNUTLS_3_4 (2)
    98: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTable
    99: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_global_set_log_function@GNUTLS_3_4 (2)
   100: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_trust_list_set_getissuer_function@GNUTLS_3_7_0 (11)
   101: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_privkey_set_pin_function@GNUTLS_3_4 (2)
   102: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_channel_binding@GNUTLS_3_4 (2)
   103: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strnlen@GLIBC_2.2.5 (3)
   104: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_anon_allocate_server_credentials@GNUTLS_3_4 (2)
   105: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srp_allocate_client_credentials@GNUTLS_3_4 (2)
   106: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pk_algorithm_get_name@GNUTLS_3_4 (2)
   107: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fputc@GLIBC_2.2.5 (3)
   108: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_retrieve_function2@GNUTLS_3_4 (2)
   109: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND freeaddrinfo@GLIBC_2.2.5 (3)
   110: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_compress_certificate_set_methods@GNUTLS_3_7_4 (12)
   111: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND free@GLIBC_2.2.5 (3)
   112: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pem_base64_encode2@GNUTLS_3_4 (2)
   113: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND secure_getenv@GLIBC_2.17 (5)
   114: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_get_system_config_file@GNUTLS_3_6_9 (13)
   115: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strlen@GLIBC_2.2.5 (3)
   116: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_init@GNUTLS_3_4 (2)
   117: 0000000000000000     0 OBJECT  GLOBAL DEFAULT  UND optind@GLIBC_2.2.5 (3)
   118: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
   119: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ferror@GLIBC_2.2.5 (3)
   120: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_export2@GNUTLS_3_4 (2)
   121: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_protocol_list@GNUTLS_3_4 (2)
   122: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_store_pubkey@GNUTLS_3_4 (2)
   123: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_verify_direct@GNUTLS_3_4 (2)
   124: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_fastopen@GNUTLS_3_4 (2)
   125: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_get_secret_bits@GNUTLS_3_4 (2)
   126: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_deinit@GNUTLS_3_4 (2)
   127: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __vfprintf_chk@GLIBC_2.3.4 (6)
   128: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srp_free_client_credentials@GNUTLS_3_4 (2)
   129: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_ext_master_secret_status@GNUTLS_3_4 (2)
   130: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srp_server_get_username@GNUTLS_3_4 (2)
   131: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_heartbeat_enable@GNUTLS_3_4 (2)
   132: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_push_function@GNUTLS_3_4 (2)
   133: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpass@GLIBC_2.2.5 (3)
   134: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_recv_packet@GNUTLS_3_4 (2)
   135: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srtp_set_profile_direct@GNUTLS_3_4 (2)
   136: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_type_get_name@GNUTLS_3_4 (2)
   137: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_is_resumed@GNUTLS_3_4 (2)
   138: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_verify_peers@GNUTLS_3_4 (2)
   139: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_set_timeout@GNUTLS_3_4 (2)
   140: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_allocate_credentials@GNUTLS_3_4 (2)
   141: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_get_authority_info_access@GNUTLS_3_4 (2)
   142: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_sign_algorithm_get_client@GNUTLS_3_4 (2)
   143: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_check_pending@GNUTLS_3_4 (2)
   144: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_list_import@GNUTLS_3_4 (2)
   145: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_etm_status@GNUTLS_3_4 (2)
   146: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_deinit@GNUTLS_3_4 (2)
   147: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pipe@GLIBC_2.2.5 (3)
   148: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_sign_algorithm_get@GNUTLS_3_4 (2)
   149: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ftello@GLIBC_2.2.5 (3)
   150: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_req_export@GNUTLS_3_4 (2)
   151: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_handshake_set_timeout@GNUTLS_3_4 (2)
   152: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_get_peers@GNUTLS_3_4 (2)
   153: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_group_list@GNUTLS_3_6_0 (14)
   154: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strerror@GLIBC_2.2.5 (3)
   155: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strstr@GLIBC_2.2.5 (3)
   156: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_params_init@GNUTLS_3_4 (2)
   157: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_free_client_credentials@GNUTLS_3_4 (2)
   158: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sigaction@GLIBC_2.2.5 (3)
   159: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __explicit_bzero_chk@GLIBC_2.25 (15)
   160: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_load_file@GNUTLS_3_4 (2)
   161: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dtls_set_mtu@GNUTLS_3_4 (2)
   162: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_anon_allocate_client_credentials@GNUTLS_3_4 (2)
   163: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fputs@GLIBC_2.2.5 (3)
   164: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtol@GLIBC_2.2.5 (3)
   165: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_rdn_get@GNUTLS_3_4 (2)
   166: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND atoi@GLIBC_2.2.5 (3)
   167: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND connect@GLIBC_2.2.5 (3)
   168: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_status_request_get2@GNUTLS_3_6_3 (8)
   169: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_protocol_get_version@GNUTLS_3_4 (2)
   170: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_can_use_length_hiding@GNUTLS_3_4 (2)
   171: 0000000000000000     0 OBJECT  GLOBAL DEFAULT  UND optarg@GLIBC_2.2.5 (3)
   172: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_set_direct@GNUTLS_3_4 (2)
   173: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_x509_crl_file@GNUTLS_3_4 (2)
   174: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_init@GNUTLS_3_4 (2)
   175: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_system_recv_timeout@GNUTLS_3_4 (2)
   176: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hmac@GNUTLS_3_4 (2)
   177: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_print@GNUTLS_3_4 (2)
   178: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_get_name@GNUTLS_3_4 (2)
   179: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __strcpy_chk@GLIBC_2.3.4 (6)
   180: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_get_group@GNUTLS_3_4 (2)
   181: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ecc_curve_get_size@GNUTLS_3_4 (2)
   182: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_compression_list@GNUTLS_3_4 (2)
   183: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_verify_flags@GNUTLS_3_4 (2)
   184: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_bye@GNUTLS_3_4 (2)
   185: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_get_nonce@GNUTLS_3_4 (2)
   186: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND signal@GLIBC_2.2.5 (3)
   187: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strspn@GLIBC_2.2.5 (3)
   188: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setbuf@GLIBC_2.2.5 (3)
   189: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_type_list@GNUTLS_3_4 (2)
   190: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_verify_stored_pubkey@GNUTLS_3_4 (2)
   191: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strchr@GLIBC_2.2.5 (3)
   192: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getopt_long@GLIBC_2.2.5 (3)
   193: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND socket@GLIBC_2.2.5 (3)
   194: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fread@GLIBC_2.2.5 (3)
   195: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_pull_function@GNUTLS_3_4 (2)
   196: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getenv@GLIBC_2.2.5 (3)
   197: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_group_get_name@GNUTLS_3_6_0 (14)
   198: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND alarm@GLIBC_2.2.5 (3)
   199: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_packet_deinit@GNUTLS_3_4 (2)
   200: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ecc_curve_get_name@GNUTLS_3_4 (2)
   201: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_list@GNUTLS_3_4 (2)
   202: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_verification_status_print@GNUTLS_3_4 (2)
   203: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_req_init@GNUTLS_3_4 (2)
   204: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __errno_location@GLIBC_2.2.5 (3)
   205: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hmac_fast@GNUTLS_3_4 (2)
   206: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strdup@GLIBC_2.2.5 (3)
   207: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_server_name_get@GNUTLS_3_4 (2)
   208: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_send@GNUTLS_3_4 (2)
   209: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_strerror@GNUTLS_3_4 (2)
   210: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_client_get_hint@GNUTLS_3_4 (2)
   211: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_deinit@GNUTLS_3_4 (2)
   212: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (16)
   213: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_req_deinit@GNUTLS_3_4 (2)
   214: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getnameinfo@GLIBC_2.2.5 (3)
   215: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_sign_list@GNUTLS_3_4 (2)
   216: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_params_import_raw@GNUTLS_3_4 (2)
   217: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_free_credentials@GNUTLS_3_4 (2)
   218: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_cipher_list@GNUTLS_3_4 (2)
   219: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_global_set_log_level@GNUTLS_3_4 (2)
   220: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_kx_list@GNUTLS_3_4 (2)
   221: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_digest_get_name@GNUTLS_3_4 (2)
   222: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_get_cipher_suite_index@GNUTLS_3_4 (2)
   223: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcmp@GLIBC_2.2.5 (3)
   224: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pubkey_get_pk_algorithm@GNUTLS_3_4 (2)
   225: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_get_ours@GNUTLS_3_4 (2)
   226: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_alpn_get_selected_protocol@GNUTLS_3_4 (2)
   227: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_x509_key_mem@GNUTLS_3_4 (2)
   228: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND send@GLIBC_2.2.5 (3)
   229: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getline@GLIBC_2.2.5 (3)
   230: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_priority_set@GNUTLS_3_4 (2)
   231: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_print@GNUTLS_3_4 (2)
   232: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_deinit@GNUTLS_3_4 (2)
   233: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcpy@GLIBC_2.2.5 (3)
   234: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_verify_function@GNUTLS_3_4 (2)
   235: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memmem@GLIBC_2.2.5 (3)
   236: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pem_base64_encode@GNUTLS_3_4 (2)
   237: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getservbyport@GLIBC_2.2.5 (3)
   238: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcmp@GLIBC_2.2.5 (3)
   239: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_kx_get_name@GNUTLS_3_4 (2)
   240: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fclose@GLIBC_2.2.5 (3)
   241: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hex_encode@GNUTLS_3_4 (2)
   242: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_aead_cipher_init@GNUTLS_3_4 (2)
   243: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_check_version@GNUTLS_3_4 (2)
   244: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_init@GNUTLS_3_4 (2)
   245: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_group_list@GNUTLS_3_6_0 (14)
   246: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_server_name_set@GNUTLS_3_4 (2)
   247: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hmac_get_key_size@GNUTLS_3_6_12 (17)
   248: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND localtime_r@GLIBC_2.2.5 (3)
   249: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND endservent@GLIBC_2.2.5 (3)
   250: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_int2@GNUTLS_3_4 (2)
   251: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hex_encode2@GNUTLS_3_4 (2)
   252: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_set_default_priority@GNUTLS_3_4 (2)
   253: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srp_set_client_credentials_function@GNUTLS_3_4 (2)
   254: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_pin_function@GNUTLS_3_4 (2)
   255: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_import@GNUTLS_3_4 (2)
   256: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_get_flags@GNUTLS_3_4 (2)
   257: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __sprintf_chk@GLIBC_2.3.4 (6)
   258: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_anon_free_server_credentials@GNUTLS_3_4 (2)
   259: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_session_set_data@GNUTLS_3_4 (2)
   260: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_anon_free_client_credentials@GNUTLS_3_4 (2)
   261: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND clearerr@GLIBC_2.2.5 (3)
   262: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __snprintf_chk@GLIBC_2.3.4 (6)
   263: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fork@GLIBC_2.2.5 (3)
   264: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sigemptyset@GLIBC_2.2.5 (3)
   265: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_privkey_import_url@GNUTLS_3_4 (2)
   266: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_rnd@GNUTLS_3_4 (2)
   267: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_hmac_init@GNUTLS_3_4 (2)
   268: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fwrite@GLIBC_2.2.5 (3)
   269: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_req_add_cert@GNUTLS_3_4 (2)
   270: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND realloc@GLIBC_2.2.5 (3)
   271: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srtp_get_profile_name@GNUTLS_3_4 (2)
   272: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND perror@GLIBC_2.2.5 (3)
   273: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_perror@GNUTLS_3_4 (2)
   274: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gai_strerror@GLIBC_2.2.5 (3)
   275: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_psk_set_client_credentials@GNUTLS_3_4 (2)
   276: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND error@GLIBC_2.2.5 (3)
   277: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_get_iv_size@GNUTLS_3_4 (2)
   278: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __memmove_chk@GLIBC_2.3.4 (6)
   279: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_set_flags@GNUTLS_3_4 (2)
   280: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_get_key_size@GNUTLS_3_4 (2)
   281: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_record_set_max_size@GNUTLS_3_4 (2)
   282: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.34 (18)
   283: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_transport_set_ptr@GNUTLS_3_4 (2)
   284: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_get_single@GNUTLS_3_4 (2)
   285: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_certificate_type_get2@GNUTLS_3_6_4 (19)
   286: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pcert_import_x509@GNUTLS_3_4 (2)
   287: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_crt_deinit@GNUTLS_3_4 (2)
   288: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_get@GNUTLS_3_4 (2)
   289: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_pubkey_export2@GNUTLS_3_4 (2)
   290: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strftime@GLIBC_2.2.5 (3)
   291: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_aead_cipher_deinit@GNUTLS_3_4 (2)
   292: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sqrt@GLIBC_2.2.5 (20)
   293: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_srtp_get_selected_profile@GNUTLS_3_4 (2)
   294: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_status_request_is_checked@GNUTLS_3_4 (2)
   295: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcpy@GLIBC_2.14 (21)
   296: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_alert_send_appropriate@GNUTLS_3_4 (2)
   297: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_ocsp_resp_check_crt@GNUTLS_3_4 (2)
   298: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_cipher_init@GNUTLS_3_4 (2)
   299: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_kx_list@GNUTLS_3_4 (2)
   300: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_x509_trust_list_init@GNUTLS_3_4 (2)
   301: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_auth_get_type@GNUTLS_3_4 (2)
   302: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __fdelt_chk@GLIBC_2.15 (22)
   303: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_get_library_config@GNUTLS_3_7_3 (23)
   304: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND time@GLIBC_2.2.5 (3)
   305: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_aead_cipher_encrypt@GNUTLS_3_4 (2)
   306: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fflush@GLIBC_2.2.5 (3)
   307: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_dh_params_export_pkcs3@GNUTLS_3_4 (2)
   308: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_group_get@GNUTLS_3_6_0 (14)
   309: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getservbyname@GLIBC_2.2.5 (3)
   310: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnutls_reauth@GNUTLS_3_6_3 (8)
   311: 00000000000222b0     8 OBJECT  GLOBAL DEFAULT   27 gnutls_strdup@GNUTLS_3_4 (2)
   312: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@GLIBC_2.2.5 (3)
   313: 00000000000222e8     8 OBJECT  GLOBAL DEFAULT   27 stdout@GLIBC_2.2.5 (3)
   314: 00000000000222a8     8 OBJECT  GLOBAL DEFAULT   27 gnutls_free@GNUTLS_3_4 (2)
   315: 00000000000222c0     8 OBJECT  GLOBAL DEFAULT   27 stdin@GLIBC_2.2.5 (3)
   316: 00000000000222e0     8 OBJECT  GLOBAL DEFAULT   27 stderr@GLIBC_2.2.5 (3)
   317: 00000000000222a0     8 OBJECT  GLOBAL DEFAULT   27 gnutls_malloc@GNUTLS_3_4 (2)

./target.bin:     file format elf64-x86-64

Contents of section .rodata:
 168f0 6e672074 6f206361 49737375 65722073  ng to caIssuer s
 16900 65727665 723a2025 732e2e2e 0a000000  erver: %s.......
 16910 47455420 2f257320 48545450 2f312e30  GET /%s HTTP/1.0
 16920 0d0a486f 73743a20 25730d0a 41636365  ..Host: %s..Acce
 16930 70743a20 2a2f2a0d 0a436f6e 6e656374  pt: */*..Connect
 16940 696f6e3a 20636c6f 73650d0a 0d0a0000  ion: close......
 16950 43616e6e 6f742069 6e746572 70726574  Cannot interpret
 16960 20485454 50207265 73706f6e 73650a00   HTTP response..
 16970 4572726f 7220696e 20736574 74696e67  Error in setting
 16980 20707269 6f726974 6965733a 2025730a   priorities: %s.
 16990 00000000 00000000 4e756d62 6572206f  ........Number o
 169a0 6620414c 504e2070 726f746f 636f6c73  f ALPN protocols
 169b0 20746f6f 206c6172 67652028 2564290a   too large (%d).
 169c0 00000000 00000000 43616e6e 6f742073  ........Cannot s
 169d0 65742074 6865206d 6178696d 756d2072  et the maximum r
 169e0 65636f72 64207369 7a652074 6f202564  ecord size to %d
 169f0 2e0a0000 00000000 506f7373 69626c65  ........Possible
 16a00 2076616c 7565733a 20353132 2c203130   values: 512, 10
 16a10 32342c20 32303438 2c203430 39362e0a  24, 2048, 4096..
 16a20 00000000 00000000 2a2a2a20 52656365  ........*** Rece
 16a30 69766564 20726568 616e6473 68616b65  ived rehandshake
 16a40 20726571 75657374 0a000000 00000000   request........
 16a50 2a2a2a20 52656861 6e647368 616b6520  *** Rehandshake 
 16a60 77617320 70657266 6f726d65 642e0a00  was performed...
 16a70 2d205065 65722068 61732063 6c6f7365  - Peer has close
 16a80 64207468 6520476e 75544c53 20636f6e  d the GnuTLS con
 16a90 6e656374 696f6e0a 00000000 00000000  nection.........
 16aa0 2a2a2a20 53657276 65722068 61732074  *** Server has t
 16ab0 65726d69 6e617465 64207468 6520636f  erminated the co
 16ac0 6e6e6563 74696f6e 2061626e 6f726d61  nnection abnorma
 16ad0 6c6c792e 0a002020 205b2564 5d3a2000  lly...   [%d]: .
 16ae0 7700636f 756c6420 6e6f7420 6f70656e  w.could not open
 16af0 2025730a 00434552 54494649 43415445   %s..CERTIFICATE
 16b00 00657272 6f725b25 645d3a20 25730a00  .error[%d]: %s..
 16b10 77726974 696e6720 746f2025 73206661  writing to %s fa
 16b20 696c6564 0a004f43 53502052 4553504f  iled..OCSP RESPO
 16b30 4e534500 4e6f2063 65727469 66696361  NSE.No certifica
 16b40 74657320 666f756e 64210a00 4d656d6f  tes found!..Memo
 16b50 72792065 72726f72 3a202573 0a004465  ry error: %s..De
 16b60 636f6469 6e672065 72726f72 3a202573  coding error: %s
 16b70 0a004361 6e6e6f74 2066696e 64206973  ..Cannot find is
 16b80 73756572 3a202573 0a00676e 75746c73  suer: %s..gnutls
 16b90 5f726e64 3a202573 0043616e 6e6f7420  _rnd: %s.Cannot 
 16ba0 636f6e74 61637420 4f435350 20736572  contact OCSP ser
 16bb0 7665720a 00756470 00746370 00312e33  ver..udp.tcp.1.3
 16bc0 2e362e31 2e352e35 2e372e33 2e31002a  .6.1.5.5.7.3.1.*
 16bd0 2a2a204f 4353503a 206e6f74 68696e67  ** OCSP: nothing
 16be0 20746f20 63686563 6b2e0a00 436f756c   to check...Coul
 16bf0 64206e6f 74207374 6f726520 6b65793a  d not store key:
 16c00 2025730a 000a0900 0a0a5370 65636961   %s.......Specia
 16c10 6c207374 72696e67 733a0a00 25252573  l strings:..%%%s
 16c20 20002d20 50534b20 636c6965 6e742063   .- PSK client c
 16c30 616c6c62 61636b2e 20005053 4b206869  allback. .PSK hi
 16c40 6e742027 2573270a 004e6f20 50534b20  nt '%s'..No PSK 
 16c50 68696e74 0a00456e 74657220 50534b20  hint..Enter PSK 
 16c60 6964656e 74697479 3a200045 6e746572  identity: .Enter
 16c70 206b6579 3a20004e 6f206b65 79206769   key: .No key gi
 16c80 76656e2c 2061626f 7274696e 672e2e2e  ven, aborting...
 16c90 0a004572 726f7220 64657269 76696e67  ..Error deriving
 16ca0 20706173 73776f72 643a2025 730a0045   password: %s..E
 16cb0 72726f72 20696e20 68657820 656e636f  rror in hex enco
 16cc0 64696e67 3a202573 0a005053 4b207573  ding: %s..PSK us
 16cd0 65726e61 6d653a20 25730a00 50534b20  ername: %s..PSK 
 16ce0 68696e74 3a202573 0a005053 4b206b65  hint: %s..PSK ke
 16cf0 793a2025 730a002a 2a2a2045 72726f72  y: %s..*** Error
 16d00 206c6f61 64696e67 2075726c 3a202573   loading url: %s
 16d10 0a002a2a 2a204572 726f7220 6c6f6164  ..*** Error load
 16d20 696e6720 6b657920 66696c65 2e0a002a  ing key file...*
 16d30 2a2a2045 72726f72 20696d70 6f727469  ** Error importi
 16d40 6e67206b 65793a20 25730a00 2a2a2a20  ng key: %s..*** 
 16d50 4572726f 72206c6f 6164696e 67206365  Error loading ce
 16d60 72742066 696c652e 0a005072 6f636573  rt file...Proces
 16d70 73656420 25642043 524c2873 292e0a00  sed %d CRL(s)...
 16d80 53525020 61757468 656e7469 63617469  SRP authenticati
 16d90 6f6e2065 72726f72 0a005053 4b206175  on error..PSK au
 16da0 7468656e 74696361 74696f6e 20657272  thentication err
 16db0 6f720a00 2d204469 73636f6e 6e656374  or..- Disconnect
 16dc0 696e670a 00436f6e 6e656374 696e6720  ing..Connecting 
 16dd0 746f006f 6373705f 72657370 5f696e69  to.ocsp_resp_ini
 16de0 743a2025 730a0069 6d706f72 74696e67  t: %s..importing
 16df0 20726573 706f6e73 653a2025 730a0063   response: %s..c
 16e00 6c692e63 006c6f63 616c5f62 75666665  li.c.local_buffe
 16e10 725f7074 7220213d 204e554c 4c002a2a  r_ptr != NULL.**
 16e20 2a205265 6b657920 68617320 6661696c  * Rekey has fail
 16e30 65643a20 25730a00 2d205265 6b657920  ed: %s..- Rekey 
 16e40 77617320 636f6d70 6c657465 640a0068  was completed..h
 16e50 7474703a 2f2f006c 69627261 72792069  ttp://.library i
 16e60 7320696e 20464950 53313430 2d32206d  s in FIPS140-2 m
 16e70 6f64650a 00737973 74656d2d 636f6e66  ode..system-conf
 16e80 69673a20 25730a00 5e004e6f 20686f73  ig: %s..^.No hos
 16e90 746e616d 65207370 65636966 6965640a  tname specified.
 16ea0 00257500 72656376 000d0a0d 0a004d65  .%u.recv......Me
 16eb0 6d6f7279 20657272 6f720a00 53796e74  mory error..Synt
 16ec0 61782065 72726f72 2061743a 2025730a  ax error at: %s.
 16ed0 00457272 6f722069 6e207072 696f7269  .Error in priori
 16ee0 74696573 3a202573 0a004572 726f7220  ties: %s..Error 
 16ef0 696e2070 726f6669 6c65733a 2025730a  in profiles: %s.
 16f00 0044544c 53207072 6f66696c 65207365  .DTLS profile se
 16f10 7420746f 2025730a 002a2a2a 20526548  t to %s..*** ReH
 16f20 616e6473 68616b65 20686173 20666169  andshake has fai
 16f30 6c65640a 002d2052 6548616e 64736861  led..- ReHandsha
 16f40 6b652077 61732063 6f6d706c 65746564  ke was completed
 16f50 0a002a2a 2a205265 68616e64 7368616b  ..*** Rehandshak
 16f60 65204661 696c6564 3a202573 0a002a2a  e Failed: %s..**
 16f70 2a205265 2d617574 68207761 73207065  * Re-auth was pe
 16f80 72666f72 6d65642e 0a002a2a 2a205265  rformed...*** Re
 16f90 2d617574 68206661 696c6564 3a202573  -auth failed: %s
 16fa0 0a004e6f 6e206661 74616c00 46617461  ..Non fatal.Fata
 16fb0 6c002a2a 2a202573 20657272 6f723a20  l.*** %s error: 
 16fc0 25730a00 2a2a2a20 52656365 69766564  %s..*** Received
 16fd0 20616c65 7274205b 25645d3a 2025730a   alert [%d]: %s.
 16fe0 00772b00 556e6162 6c652074 6f206f70  .w+.Unable to op
 16ff0 656e2027 25732721 0a00676c 6f62616c  en '%s'!..global
 17000 5f696e69 743a2025 730a004e 6f20686f  _init: %s..No ho
 17010 73746e61 6d652067 6976656e 0a007762  stname given..wb
 17020 002d2048 616e6473 68616b65 20776173  .- Handshake was
 17030 20636f6d 706c6574 65640a00 0a2d2053   completed...- S
 17040 696d706c 6520436c 69656e74 204d6f64  imple Client Mod
 17050 653a0a0a 002a2a2a 20537461 7274696e  e:...*** Startin
 17060 6720544c 53206861 6e647368 616b650a  g TLS handshake.
 17070 002a2a2a 2048616e 64736861 6b652068  .*** Handshake h
 17080 61732066 61696c65 640a002d 20526563  as failed..- Rec
 17090 65697665 645b2564 5d3a2000 2d205365  eived[%d]: .- Se
 170a0 6e743a20 25642062 79746573 0a000000  nt: %d bytes....
 170b0 00000000 00000000 00000000 00000000  ................
 170c0 70617273 655f666f 725f696e 6c696e65  parse_for_inline
 170d0 5f636f6d 6d616e64 735f696e 5f627566  _commands_in_buf
 170e0 66657200 28656d70 74792900 28746f6f  fer.(empty).(too
 170f0 206c6172 67652900 25303258 25730025   large).%02X%s.%
 17100 30327800 28657272 6f722900 2a2a5245  02x.(error).**RE
 17110 48414e44 5348414b 452a2a00 2a2a5245  HANDSHAKE**.**RE
 17120 41555448 2a2a002a 2a2a2053 656e6469  AUTH**.*** Sendi
 17130 6e672072 652d6175 74682072 65717565  ng re-auth reque
 17140 73740a00 72656175 74683a20 25730a00  st..reauth: %s..
 17150 2a2a4845 41525442 4541542a 2a004e6f  **HEARTBEAT**.No
 17160 20686561 72746265 61742069 6e207468   heartbeat in th
 17170 69732073 65737369 6f6e0a00 70696e67  is session..ping
 17180 3a202573 0a002d20 53746174 75733a20  : %s..- Status: 
 17190 25730a00 202d2055 73696e67 20707269  %s.. - Using pri
 171a0 6d653a20 25642062 6974730a 00202d20  me: %d bits.. - 
 171b0 53656372 6574206b 65793a20 25642062  Secret key: %d b
 171c0 6974730a 00676e75 746c735f 64685f67  its..gnutls_dh_g
 171d0 65745f67 726f7570 2025640a 00676e75  et_group %d..gnu
 171e0 746c735f 64685f70 6172616d 735f696e  tls_dh_params_in
 171f0 69742025 640a0067 6e75746c 735f6d61  it %d..gnutls_ma
 17200 6c6c6f63 2025640a 00202d20 504b4353  lloc %d.. - PKCS
 17210 23332066 6f726d61 743a0a0a 252e2a73  #3 format:..%.*s
 17220 0a00202d 20557369 6e672063 75727665  .. - Using curve
 17230 3a202573 0a00202d 20437572 76652073  : %s.. - Curve s
 17240 697a653a 20256420 62697473 0a002d20  ize: %d bits..- 
 17250 4368616e 6e656c20 62696e64 696e6773  Channel bindings
 17260 0a00202d 20272573 273a206e 6f742061  .. - '%s': not a
 17270 7661696c 61626c65 0a00202d 20272573  vailable.. - '%s
 17280 273a2065 72726f72 3a202573 0a00202d  ': error: %s.. -
 17290 20272573 273a2000 2d204365 72746966   '%s': .- Certif
 172a0 69636174 65207479 70653a20 582e3530  icate type: X.50
 172b0 390a002d 20436572 74696669 63617465  9..- Certificate
 172c0 5b25645d 20696e66 6f3a0a20 2d200045  [%d] info:. - .E
 172d0 6e636f64 696e6720 6572726f 723a2025  ncoding error: %
 172e0 730a000a 25730a00 43697068 65722073  s...%s..Cipher s
 172f0 75697465 7320666f 72202573 0a00252d  uites for %s..%-
 17300 35307309 30782530 32782c20 30782530  50s.0x%02x, 0x%0
 17310 32780925 730a0050 726f746f 636f6c73  2x.%s..Protocols
 17320 3a20006e 6f6e650a 00564552 532d2573  : .none..VERS-%s
 17330 002c2000 43697068 6572733a 20004d41  ., .Ciphers: .MA
 17340 43733a20 004b6579 20457863 68616e67  Cs: .Key Exchang
 17350 6520416c 676f7269 74686d73 3a200047  e Algorithms: .G
 17360 726f7570 733a2000 47524f55 502d2573  roups: .GROUP-%s
 17370 00504b2d 7369676e 61747572 65733a20  .PK-signatures: 
 17380 00534947 4e2d2573 00436970 68657220  .SIGN-%s.Cipher 
 17390 73756974 65733a0a 00436572 74696669  suites:..Certifi
 173a0 63617465 20747970 65733a20 00435459  cate types: .CTY
 173b0 50452d25 73004469 67657374 733a2000  PE-%s.Digests: .
 173c0 4b657920 65786368 616e6765 20616c67  Key exchange alg
 173d0 6f726974 686d733a 2000436f 6d707265  orithms: .Compre
 173e0 7373696f 6e3a2000 434f4d50 2d257300  ssion: .COMP-%s.
 173f0 5075626c 6963204b 65792053 79737465  Public Key Syste
 17400 6d733a20 00457272 6f722069 6e20676e  ms: .Error in gn
 17410 75746c73 5f6d616c 6c6f633a 2025730a  utls_malloc: %s.
 17420 002d204b 6579206d 61746572 69616c3a  .- Key material:
 17430 2025730a 00474e55 544c535f 534f5f50   %s..GNUTLS_SO_P
 17440 494e0073 65637572 69747920 6f666669  IN.security offi
 17450 63657200 474e5554 4c535f50 494e0075  cer.GNUTLS_PIN.u
 17460 73657200 546f6f20 6c6f6e67 2050494e  ser.Too long PIN
 17470 20676976 656e0a00 546f6b65 6e202725   given..Token '%
 17480 73272077 69746820 55524c20 27257327  s' with URL '%s'
 17490 20007265 71756972 65732025 73205049   .requires %s PI
 174a0 4e0a0045 6e746572 2050494e 3a200045  N..Enter PIN: .E
 174b0 6e746572 20706173 73776f72 643a2000  nter password: .
 174c0 4e6f2050 494e2067 6976656e 2e0a002d  No PIN given...-
 174d0 20476f74 20256420 52617720 7075626c   Got %d Raw publ
 174e0 69632d6b 65792873 292e0a00 2d205261  ic-key(s)...- Ra
 174f0 7720706b 20696e66 6f3a0a00 202d2050  w pk info:.. - P
 17500 4b20616c 676f3a20 25730a00 556e6b6e  K algo: %s..Unkn
 17510 6f776e00 5b69676e 6f726564 5d002d20  own.[ignored].- 
 17520 44657363 72697074 696f6e3a 2025730a  Description: %s.
 17530 002d2053 65737369 6f6e2049 443a2025  .- Session ID: %
 17540 730a0041 6e6f6e79 6d6f7573 20004570  s..Anonymous .Ep
 17550 68656d65 72616c20 002d2054 4c532f49  hemeral .- TLS/I
 17560 41206175 7468656e 74696361 74696f6e  A authentication
 17570 0a002d20 47697665 6e207365 72766572  ..- Given server
 17580 206e616d 655b2564 5d3a2025 730a002d   name[%d]: %s..-
 17590 20566572 73696f6e 3a202573 0a002d20   Version: %s..- 
 175a0 4b657920 45786368 616e6765 3a202573  Key Exchange: %s
 175b0 0a002d20 53657276 65722053 69676e61  ..- Server Signa
 175c0 74757265 3a202573 0a002d20 436c6965  ture: %s..- Clie
 175d0 6e742053 69676e61 74757265 3a202573  nt Signature: %s
 175e0 0a002d20 43697068 65723a20 25730a00  ..- Cipher: %s..
 175f0 2d204d41 433a2025 730a002d 204f7074  - MAC: %s..- Opt
 17600 696f6e73 3a002065 7874656e 64656420  ions:. extended 
 17610 6d617374 65722073 65637265 742c0020  master secret,. 
 17620 73616665 2072656e 65676f74 69617469  safe renegotiati
 17630 6f6e2c00 2045744d 2c00204f 43535020  on,. EtM,. OCSP 
 17640 73746174 75732072 65717565 73742573  status request%s
 17650 2c002d20 53525450 2070726f 66696c65  ,.- SRTP profile
 17660 3a202573 0a002d20 4170706c 69636174  : %s..- Applicat
 17670 696f6e20 70726f74 6f636f6c 3a20252e  ion protocol: %.
 17680 2a730a00 25630074 6c732d75 6e697175  *s..%c.tls-uniqu
 17690 6500746c 732d7365 72766572 2d656e64  e.tls-server-end
 176a0 2d706f69 6e740074 6c732d65 78706f72  -point.tls-expor
 176b0 74657200 00000000 436f756c 64206e6f  ter.....Could no
 176c0 74207365 74206365 72746966 69636174  t set certificat
 176d0 6520636f 6d707265 7373696f 6e206d65  e compression me
 176e0 74686f64 733a2025 730a0000 00000000  thods: %s.......
 176f0 556e6b6e 6f776e20 636f6d70 72657373  Unknown compress
 17700 696f6e20 6d657468 6f643a20 25730a00  ion method: %s..
 17710 2a2a2a20 50726f63 65737369 6e672025  *** Processing %
 17720 75206279 74657320 636f6d6d 616e643a  u bytes command:
 17730 2025730a 00000000 2a2a2a20 53656e64   %s.....*** Send
 17740 696e6720 72656861 6e647368 616b6520  ing rehandshake 
 17750 72657175 6573740a 00000000 00000000  request.........
 17760 2d205065 65722064 6964206e 6f742073  - Peer did not s
 17770 656e6420 616e7920 63657274 69666963  end any certific
 17780 6174652e 0a000000 2d20436f 756c6420  ate.....- Could 
 17790 6e6f7420 76657269 66792063 65727469  not verify certi
 177a0 66696361 74652028 6572723a 20257329  ficate (err: %s)
 177b0 0a000000 00000000 2d20436f 756c6420  ........- Could 
 177c0 6e6f7420 7072696e 74207665 72696669  not print verifi
 177d0 63617469 6f6e2066 6c616773 20286572  cation flags (er
 177e0 723a2025 73290a00 2d202573 44696666  r: %s)..- %sDiff
 177f0 69652d48 656c6c6d 616e2070 6172616d  ie-Hellman param
 17800 65746572 730a0000 202d2050 65657227  eters... - Peer'
 17810 73207075 626c6963 206b6579 3a202564  s public key: %d
 17820 20626974 730a0000 676e7574 6c735f64   bits...gnutls_d
 17830 685f7061 72616d73 5f696d70 6f72745f  h_params_import_
 17840 72617720 25640a00 676e7574 6c735f64  raw %d..gnutls_d
 17850 685f7061 72616d73 5f657870 6f72745f  h_params_export_
 17860 706b6373 33202564 0a000000 00000000  pkcs3 %d........
 17870 676e7574 6c735f64 685f7061 72616d73  gnutls_dh_params
 17880 5f657870 6f72745f 706b6373 332d3220  _export_pkcs3-2 
 17890 25640a00 00000000 2d202573 45432044  %d......- %sEC D
 178a0 69666669 652d4865 6c6c6d61 6e207061  iffie-Hellman pa
 178b0 72616d65 74657273 0a000000 00000000  rameters........
 178c0 2d20476f 74206120 63657274 69666963  - Got a certific
 178d0 61746520 6c697374 206f6620 25642063  ate list of %d c
 178e0 65727469 66696361 7465732e 0a000000  ertificates.....
 178f0 094b6579 20657863 68616e67 653a2025  .Key exchange: %
 17900 730a0943 69706865 723a2025 730a094d  s..Cipher: %s..M
 17910 41433a20 25730a0a 00000000 00000000  AC: %s..........
 17920 4572726f 7220696e 20676e75 746c735f  Error in gnutls_
 17930 7072665f 72666335 3730353a 2025730a  prf_rfc5705: %s.
 17940 00000000 00000000 2a2a2a20 57726f6e  ........*** Wron
 17950 67205049 4e206861 73206265 656e2070  g PIN has been p
 17960 726f7669 64656421 0a000000 00000000  rovided!........
 17970 2a2a2a20 54686973 20697320 74686520  *** This is the 
 17980 66696e61 6c207472 79206265 666f7265  final try before
 17990 206c6f63 6b696e67 210a0000 00000000   locking!.......
 179a0 2a2a2a20 4f6e6c79 20666577 20747269  *** Only few tri
 179b0 6573206c 65667420 6265666f 7265206c  es left before l
 179c0 6f636b69 6e67210a 00000000 00000000  ocking!.........
 179d0 52652d75 73696e67 20636163 68656420  Re-using cached 
 179e0 50494e20 666f7220 746f6b65 6e202725  PIN for token '%
 179f0 73270a00 00000000 43616e6e 6f742063  s'......Cannot c
 17a00 6f6e7469 6e756520 77697468 20612077  ontinue with a w
 17a10 726f6e67 20706173 73776f72 6420696e  rong password in
 17a20 20746865 20656e76 69726f6e 6d656e74   the environment
 17a30 2e0a0000 00000000 6e6f7465 3a207768  ........note: wh
 17a40 656e206f 70657261 74696e67 20696e20  en operating in 
 17a50 62617463 68206d6f 64652c20 73657420  batch mode, set 
 17a60 74686520 474e5554 4c535f50 494e206f  the GNUTLS_PIN o
 17a70 7220474e 55544c53 5f534f5f 50494e20  r GNUTLS_SO_PIN 
 17a80 656e7669 726f6e6d 656e7420 76617269  environment vari
 17a90 61626c65 730a0000 2d204365 72746966  ables...- Certif
 17aa0 69636174 65207479 70653a20 52617720  icate type: Raw 
 17ab0 5075626c 6963204b 65790a00 00000000  Public Key......
 17ac0 2d205365 72766572 20686173 20726571  - Server has req
 17ad0 75657374 65642061 20636572 74696669  uested a certifi
 17ae0 63617465 2e0a0000 2d205352 50206175  cate....- SRP au
 17af0 7468656e 74696361 74696f6e 2e20436f  thentication. Co
 17b00 6e6e6563 74656420 61732027 2573270a  nnected as '%s'.
 17b10 00000000 00000000 2d205053 4b206175  ........- PSK au
 17b20 7468656e 74696361 74696f6e 2e205053  thentication. PS
 17b30 4b206869 6e742027 2573270a 00000000  K hint '%s'.....
 17b40 2d205053 4b206175 7468656e 74696361  - PSK authentica
 17b50 74696f6e 2e20436f 6e6e6563 74656420  tion. Connected 
 17b60 61732027 2573270a 00000000 00000000  as '%s'.........
 17b70 2d204e6f 20636572 74696669 63617465  - No certificate
 17b80 20776173 2073656e 7420746f 20706565   was sent to pee
 17b90 720a0000 00000000 7581ffff 4884ffff  r.......u...H...
 17ba0 d084ffff 0085ffff 4885ffff 6081ffff  ........H...`...
 17bb0 28756e6b 6e6f776e 29000000 00000000  (unknown).......
 17bc0 73746172 74746c73 3a207761 6974696e  starttls: waitin
 17bd0 6720666f 723a2022 252e2a73 220a0000  g for: "%.*s"...
 17be0 6572726f 72207265 63656976 696e6720  error receiving 
 17bf0 27257327 3a205469 6d656f75 740a0000  '%s': Timeout...
 17c00 3c737472 65616d3a 73747265 616d2078  <stream:stream x
 17c10 6d6c6e73 3a737472 65616d3d 27687474  mlns:stream='htt
 17c20 703a2f2f 65746865 72782e6a 61626265  p://etherx.jabbe
 17c30 722e6f72 672f7374 7265616d 73272078  r.org/streams' x
 17c40 6d6c6e73 3d276a61 62626572 3a636c69  mlns='jabber:cli
 17c50 656e7427 20746f3d 27257327 20766572  ent' to='%s' ver
 17c60 73696f6e 3d27312e 30273e0a 00000000  sion='1.0'>.....
 17c70 3c737461 7274746c 7320786d 6c6e733d  <starttls xmlns=
 17c80 2775726e 3a696574 663a7061 72616d73  'urn:ietf:params
 17c90 3a786d6c 3a6e733a 786d7070 2d746c73  :xml:ns:xmpp-tls
 17ca0 272f3e00 00000000 301d0201 01771880  '/>.....0....w..
 17cb0 16312e33 2e362e31 2e342e31 2e313436  .1.3.6.1.4.1.146
 17cc0 362e3230 30333700 4e65676f 74696174  6.20037.Negotiat
 17cd0 696e6720 506f7374 67726553 514c2053  ing PostgreSQL S
 17ce0 54415254 544c530a 00000000 00000000  TARTTLS.........
 17cf0 2a2a2a20 4f6e6c79 2073656e 74202564  *** Only sent %d
 17d00 20627974 65732069 6e737465 6164206f   bytes instead o
 17d10 66202564 2e0a0000 43616e6e 6f742063  f %d....Cannot c
 17d20 6f6e7665 72742025 7320746f 2049444e  onvert %s to IDN
 17d30 413a2025 730a0000 436f756c 64206e6f  A: %s...Could no
 17d40 74206669 6e642061 20737570 706f7274  t find a support
 17d50 65642073 6f636b65 740a0000 00000000  ed socket.......
 17d60 436f756c 64206e6f 7420636f 6e6e6563  Could not connec
 17d70 7420746f 2025733a 25733a20 25730a00  t to %s:%s: %s..
 17d80 5761726e 696e673a 20676574 73657276  Warning: getserv
 17d90 6279706f 72742825 73292066 61696c65  byport(%s) faile
 17da0 642e2055 73696e67 20706f72 74206e75  d. Using port nu
 17db0 6d626572 20617320 73657276 6963652e  mber as service.
 17dc0 0a000000 00000000 5761726e 696e673a  ........Warning:
 17dd0 20676574 73657276 62796e61 6d652829   getservbyname()
 17de0 20666169 6c656420 666f7220 2725732f   failed for '%s/
 17df0 2573272e 0a006572 726f7220 72656365  %s'...error rece
 17e00 6976696e 67202725 73273a20 25730a00  iving '%s': %s..
 17e10 73746172 74746c73 3a207265 63656976  starttls: receiv
 17e20 65643a20 25730a00 73746172 74746c73  ed: %s..starttls
 17e30 3a207365 6e64696e 673a2025 730a0065  : sending: %s..e
 17e40 72726f72 2073656e 64696e67 20222573  rror sending "%s
 17e50 220a0068 74747073 00736d74 70007375  "..https.smtp.su
 17e60 626d6973 73696f6e 004e6567 6f746961  bmission.Negotia
 17e70 74696e67 20534d54 50205354 41525454  ting SMTP STARTT
 17e80 4c530a00 32323020 0045484c 4f202573  LS..220 .EHLO %s
 17e90 0d0a0032 35302000 696d6170 00696d61  ...250 .imap.ima
 17ea0 7032004e 65676f74 69617469 6e672049  p2.Negotiating I
 17eb0 4d415020 53544152 54544c53 0a006120  MAP STARTTLS..a 
 17ec0 43415041 42494c49 54590d0a 0061204f  CAPABILITY...a O
 17ed0 4b006120 53544152 54544c53 0d0a0078  K.a STARTTLS...x
 17ee0 6d707000 4e65676f 74696174 696e6720  mpp.Negotiating 
 17ef0 584d5050 20535441 5254544c 530a003c  XMPP STARTTLS..<
 17f00 3f003c70 726f6365 6564006c 64617000  ?.<proceed.ldap.
 17f10 4e65676f 74696174 696e6720 4c444150  Negotiating LDAP
 17f20 20535441 5254544c 530a0066 74700066   STARTTLS..ftp.f
 17f30 74707300 4e65676f 74696174 696e6720  tps.Negotiating 
 17f40 46545020 53544152 54544c53 0a004645  FTP STARTTLS..FE
 17f50 41540d0a 00323131 20004155 54482054  AT...211 .AUTH T
 17f60 4c530d0a 00323334 006c6d74 70004e65  LS...234.lmtp.Ne
 17f70 676f7469 6174696e 67204c4d 54502053  gotiating LMTP S
 17f80 54415254 544c530a 004c484c 4f202573  TARTTLS..LHLO %s
 17f90 0d0a0070 6f703300 4e65676f 74696174  ...pop3.Negotiat
 17fa0 696e6720 504f5033 20535441 5254544c  ing POP3 STARTTL
 17fb0 530a002b 4f4b0053 544c530d 0a006e6e  S..+OK.STLS...nn
 17fc0 7470004e 65676f74 69617469 6e67204e  tp.Negotiating N
 17fd0 4e545020 53544152 54544c53 0a003230  NTP STARTTLS..20
 17fe0 30200033 38322000 73696576 65004e65  0 .382 .sieve.Ne
 17ff0 676f7469 6174696e 67205369 65766520  gotiating Sieve 
 18000 53544152 54544c53 0a004f4b 2000706f  STARTTLS..OK .po
 18010 73746772 65730070 6f737467 72657371  stgres.postgresq
 18020 6c00756e 6b6e6f77 6e207072 6f746f63  l.unknown protoc
 18030 6f6c2027 2573270a 00786d70 702d7365  ol '%s'..xmpp-se
 18040 72766572 00343433 002a2a2a 20676e75  rver.443.*** gnu
 18050 746c735f 62796528 29206572 726f723a  tls_bye() error:
 18060 2025730a 00526573 6f6c7669 6e672027   %s..Resolving '
 18070 25733a25 73272e2e 2e0a0043 616e6e6f  %s:%s'.....Canno
 18080 74207265 736f6c76 65202573 3a25733a  t resolve %s:%s:
 18090 2025730a 00676574 6e616d65 696e666f   %s..getnameinfo
 180a0 28293a20 25730a00 73657473 6f636b6f  (): %s..setsocko
 180b0 70742849 505f4446 29206661 696c6564  pt(IP_DF) failed
 180c0 00257320 2725733a 25732720 2854464f  .%s '%s:%s' (TFO
 180d0 292e2e2e 0a002573 20272573 3a257327  ).....%s '%s:%s'
 180e0 2e2e2e0a 00657272 6f722069 6e697469  .....error initi
 180f0 616c697a 696e6720 73657373 696f6e0a  alizing session.
 18100 00657272 6f722073 656e6469 6e672065  .error sending e
 18110 61726c79 20646174 610a002a 2a2a2068  arly data..*** h
 18120 616e6473 68616b65 20686173 20666169  andshake has fai
 18130 6c65643a 2025730a 00000000 0804d216  led: %s.........
 18140 2f006265 6e63686d 61726b2d 63697068  /.benchmark-ciph
 18150 65722e63 00696e70 7574213d 4e554c4c  er.c.input!=NULL
 18160 00253136 73200025 32347320 006f7574  .%16s .%24s .out
 18170 70757421 3d4e554c 4c002531 39732d25  put!=NULL.%19s-%
 18180 73200000 00000000 676e7574 6c735f72  s ......gnutls_r
 18190 6e642847 4e55544c 535f524e 445f4e4f  nd(GNUTLS_RND_NO
 181a0 4e43452c 20696e70 75742c20 36342a31  NCE, input, 64*1
 181b0 3032342a 31303234 29203e3d 20300000  024*1024) >= 0..
 181c0 676e7574 6c735f72 6e642847 4e55544c  gnutls_rnd(GNUTL
 181d0 535f524e 445f4e4f 4e43452c 2026632c  S_RND_NONCE, &c,
 181e0 20312920 3e3d2030 00000000 00000000   1) >= 0........
 181f0 676e7574 6c735f72 6e642847 4e55544c  gnutls_rnd(GNUTL
 18200 535f524e 445f4e4f 4e43452c 206f7574  S_RND_NONCE, out
 18210 7075742c 20737465 702b3634 29203e3d  put, step+64) >=
 18220 20300000 00000000 676e7574 6c735f61   0......gnutls_a
 18230 6561645f 63697068 65725f65 6e637279  ead_cipher_encry
 18240 70742861 6374782c 2069762e 64617461  pt(actx, iv.data
 18250 2c206976 2e73697a 652c204e 554c4c2c  , iv.size, NULL,
 18260 20302c20 7461675f 73697a65 2c20692c   0, tag_size, i,
 18270 20737465 702c206f 75747075 742c2026   step, output, &
 18280 6f75745f 73697a65 29203e3d 20300000  out_size) >= 0..
 18290 43686563 6b696e67 20414541 44206369  Checking AEAD ci
 182a0 70686572 732c2070 61796c6f 61642073  phers, payload s
 182b0 697a653a 2025750a 00000000 00000000  ize: %u.........
 182c0 0a436865 636b696e 67206369 70686572  .Checking cipher
 182d0 2d4d4143 20636f6d 62696e61 74696f6e  -MAC combination
 182e0 732c2070 61796c6f 61642073 697a653a  s, payload size:
 182f0 2025750a 00000000 0a436865 636b696e   %u......Checkin
 18300 67204d41 4320616c 676f7269 74686d73  g MAC algorithms
 18310 2c207061 796c6f61 64207369 7a653a20  , payload size: 
 18320 25750a00 00000000 0a436865 636b696e  %u.......Checkin
 18330 67206369 70686572 732c2070 61796c6f  g ciphers, paylo
 18340 61642073 697a653a 2025750a 00000000  ad size: %u.....
 18350 63697068 65725f62 656e6368 00000000  cipher_bench....
 18360 6d61635f 62656e63 68000000 00000000  mac_bench.......
 18370 63697068 65725f6d 61635f62 656e6368  cipher_mac_bench
 18380 00000000 00000000 20205072 6f636573  ........  Proces
 18390 73656420 252e3266 20257320 696e2025  sed %.2f %s in %
 183a0 2e326620 73656373 3a200025 2e326620  .2f secs: .%.2f 
 183b0 25732f73 65630a00 00000000 00408f40  %s/sec.......@.@
 183c0 00000000 80842e41 00000000 65cdcd41  .......A....e..A
 183d0 25737c3c 25643e7c 20257300 4572726f  %s|<%d>| %s.Erro
 183e0 7220696e 2025730a 00636c69 656e7400  r in %s..client.
 183f0 636c6965 6e745b25 645d3a20 25730a00  client[%d]: %s..
 18400 73657276 65725b25 645d3a20 25730a00  server[%d]: %s..
 18410 48616e64 7368616b 65206661 696c6564  Handshake failed
 18420 0a002533 3073202d 20257320 20004661  ..%30s - %s  .Fa
 18430 696c6564 2073656e 64696e67 20746f20  iled sending to 
 18440 73657276 65720a00 c2b57300 6d730045  server....s.ms.E
 18450 72726f72 20696e20 25643a20 25730a00  rror in %d: %s..
 18460 25730a20 2d200074 72616e73 61637469  %s. - .transacti
 18470 6f6e7300 00000000 4661696c 65642072  ons.....Failed r
 18480 65636569 76696e67 2066726f 6d20636c  eceiving from cl
 18490 69656e74 3a202573 0a000000 00000000  ient: %s........
 184a0 4572726f 7220696e 20736574 74696e67  Error in setting
 184b0 20707269 6f726974 793a2025 730a0000   priority: %s...
 184c0 202d2061 76672e20 68616e64 7368616b   - avg. handshak
 184d0 65207469 6d653a20 252e3266 2025730a  e time: %.2f %s.
 184e0 202d2073 74616e64 61726420 64657669   - standard devi
 184f0 6174696f 6e3a2025 2e326620 25730a0a  ation: %.2f %s..
 18500 00000000 00000000 54657374 696e6720  ........Testing 
 18510 7468726f 75676870 75742069 6e206369  throughput in ci
 18520 70686572 2f4d4143 20636f6d 62696e61  pher/MAC combina
 18530 74696f6e 73202870 61796c6f 61643a20  tions (payload: 
 18540 25642062 79746573 290a0000 00000000  %d bytes).......
 18550 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18560 323a2b41 45532d31 32382d47 434d3a2b  2:+AES-128-GCM:+
 18570 41454144 3a2b5349 474e2d41 4c4c3a2b  AEAD:+SIGN-ALL:+
 18580 434f4d50 2d4e554c 4c3a2b52 53410000  COMP-NULL:+RSA..
 18590 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 185a0 333a2b41 45532d31 32382d47 434d3a2b  3:+AES-128-GCM:+
 185b0 41454144 3a2b5349 474e2d41 4c4c3a2b  AEAD:+SIGN-ALL:+
 185c0 434f4d50 2d4e554c 4c3a2b47 524f5550  COMP-NULL:+GROUP
 185d0 2d414c4c 00000000 4e4f4e45 3a2b5645  -ALL....NONE:+VE
 185e0 52532d54 4c53312e 323a2b41 45532d31  RS-TLS1.2:+AES-1
 185f0 32382d43 434d3a2b 41454144 3a2b5349  28-CCM:+AEAD:+SI
 18600 474e2d41 4c4c3a2b 434f4d50 2d4e554c  GN-ALL:+COMP-NUL
 18610 4c3a2b52 53410000 4e4f4e45 3a2b5645  L:+RSA..NONE:+VE
 18620 52532d54 4c53312e 333a2b41 45532d31  RS-TLS1.3:+AES-1
 18630 32382d43 434d3a2b 41454144 3a2b5349  28-CCM:+AEAD:+SI
 18640 474e2d41 4c4c3a2b 434f4d50 2d4e554c  GN-ALL:+COMP-NUL
 18650 4c3a2b47 524f5550 2d414c4c 00000000  L:+GROUP-ALL....
 18660 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18670 323a2b43 48414348 4132302d 504f4c59  2:+CHACHA20-POLY
 18680 31333035 3a2b4145 41443a2b 5349474e  1305:+AEAD:+SIGN
 18690 2d414c4c 3a2b434f 4d502d4e 554c4c3a  -ALL:+COMP-NULL:
 186a0 2b454344 48452d52 53413a2b 43555256  +ECDHE-RSA:+CURV
 186b0 452d414c 4c000000 4e4f4e45 3a2b5645  E-ALL...NONE:+VE
 186c0 52532d54 4c53312e 333a2b43 48414348  RS-TLS1.3:+CHACH
 186d0 4132302d 504f4c59 31333035 3a2b4145  A20-POLY1305:+AE
 186e0 41443a2b 5349474e 2d414c4c 3a2b434f  AD:+SIGN-ALL:+CO
 186f0 4d502d4e 554c4c3a 2b454344 48452d52  MP-NULL:+ECDHE-R
 18700 53413a2b 43555256 452d414c 4c000000  SA:+CURVE-ALL...
 18710 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18720 303a2b41 45532d31 32382d43 42433a2b  0:+AES-128-CBC:+
 18730 53484131 3a2b5349 474e2d41 4c4c3a2b  SHA1:+SIGN-ALL:+
 18740 434f4d50 2d4e554c 4c3a2b52 53410000  COMP-NULL:+RSA..
 18750 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18760 303a2b43 414d454c 4c49412d 3132382d  0:+CAMELLIA-128-
 18770 4342433a 2b534841 313a2b53 49474e2d  CBC:+SHA1:+SIGN-
 18780 414c4c3a 2b434f4d 502d4e55 4c4c3a2b  ALL:+COMP-NULL:+
 18790 52534100 00000000 4e4f4e45 3a2b5645  RSA.....NONE:+VE
 187a0 52532d54 4c53312e 323a2b47 4f535432  RS-TLS1.2:+GOST2
 187b0 38313437 2d544332 365a2d43 4e543a2b  8147-TC26Z-CNT:+
 187c0 474f5354 32383134 372d5443 32365a2d  GOST28147-TC26Z-
 187d0 494d4954 3a2b5349 474e2d41 4c4c3a2b  IMIT:+SIGN-ALL:+
 187e0 5349474e 2d474f53 54523334 31303132  SIGN-GOSTR341012
 187f0 2d323536 3a2b434f 4d502d4e 554c4c3a  -256:+COMP-NULL:
 18800 2b564b4f 2d474f53 542d3132 3a2b4752  +VKO-GOST-12:+GR
 18810 4f55502d 474f5354 2d414c4c 00000000  OUP-GOST-ALL....
 18820 0a546573 74696e67 20746872 6f756768  .Testing through
 18830 70757420 696e2063 69706865 722f4d41  put in cipher/MA
 18840 4320636f 6d62696e 6174696f 6e732028  C combinations (
 18850 7061796c 6f61643a 20256420 62797465  payload: %d byte
 18860 73290a00 00000000 54657374 696e6720  s)......Testing 
 18870 6b657920 65786368 616e6765 73202852  key exchanges (R
 18880 53412f44 48206269 74733a20 25642c20  SA/DH bits: %d, 
 18890 45432062 6974733a 20256429 0a0a0000  EC bits: %d)....
 188a0 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 188b0 333a2b41 45532d31 32382d47 434d3a2b  3:+AES-128-GCM:+
 188c0 41454144 3a2b5349 474e2d41 4c4c3a2b  AEAD:+SIGN-ALL:+
 188d0 434f4d50 2d4e554c 4c3a2b44 48452d52  COMP-NULL:+DHE-R
 188e0 53413a2b 47524f55 502d4646 44484533  SA:+GROUP-FFDHE3
 188f0 30373200 00000000 4e4f4e45 3a2b5645  072.....NONE:+VE
 18900 52532d54 4c53312e 333a2b41 45532d31  RS-TLS1.3:+AES-1
 18910 32382d47 434d3a2b 41454144 3a2b5349  28-GCM:+AEAD:+SI
 18920 474e2d52 53412d50 53532d53 48413235  GN-RSA-PSS-SHA25
 18930 363a2b43 4f4d502d 4e554c4c 3a2b4543  6:+COMP-NULL:+EC
 18940 4448452d 5253413a 2b435552 56452d53  DHE-RSA:+CURVE-S
 18950 45435032 35365231 00000000 00000000  ECP256R1........
 18960 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18970 333a2b41 45532d31 32382d47 434d3a2b  3:+AES-128-GCM:+
 18980 41454144 3a2b5349 474e2d41 4c4c3a2b  AEAD:+SIGN-ALL:+
 18990 434f4d50 2d4e554c 4c3a2b45 43444845  COMP-NULL:+ECDHE
 189a0 2d525341 3a2b4355 5256452d 53454350  -RSA:+CURVE-SECP
 189b0 32353652 31000000 4e4f4e45 3a2b5645  256R1...NONE:+VE
 189c0 52532d54 4c53312e 333a2b41 45532d31  RS-TLS1.3:+AES-1
 189d0 32382d47 434d3a2b 41454144 3a2b5349  28-GCM:+AEAD:+SI
 189e0 474e2d41 4c4c3a2b 434f4d50 2d4e554c  GN-ALL:+COMP-NUL
 189f0 4c3a2b45 43444845 2d525341 3a2b4355  L:+ECDHE-RSA:+CU
 18a00 5256452d 58323535 31390000 00000000  RVE-X25519......
 18a10 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18a20 333a2b41 45532d31 32382d47 434d3a2b  3:+AES-128-GCM:+
 18a30 41454144 3a2b5349 474e2d41 4c4c3a2b  AEAD:+SIGN-ALL:+
 18a40 434f4d50 2d4e554c 4c3a2b45 43444845  COMP-NULL:+ECDHE
 18a50 2d454344 53413a2b 43555256 452d5345  -ECDSA:+CURVE-SE
 18a60 43503235 36523100 4e4f4e45 3a2b5645  CP256R1.NONE:+VE
 18a70 52532d54 4c53312e 333a2b41 45532d31  RS-TLS1.3:+AES-1
 18a80 32382d47 434d3a2b 41454144 3a2b5349  28-GCM:+AEAD:+SI
 18a90 474e2d41 4c4c3a2b 434f4d50 2d4e554c  GN-ALL:+COMP-NUL
 18aa0 4c3a2b45 43444845 2d454344 53413a2b  L:+ECDHE-ECDSA:+
 18ab0 43555256 452d5832 35353139 00000000  CURVE-X25519....
 18ac0 4e4f4e45 3a2b5645 52532d54 4c53312e  NONE:+VERS-TLS1.
 18ad0 333a2b41 45532d31 32382d47 434d3a2b  3:+AES-128-GCM:+
 18ae0 41454144 3a2b5349 474e2d45 44445341  AEAD:+SIGN-EDDSA
 18af0 2d454432 35353139 3a2b434f 4d502d4e  -ED25519:+COMP-N
 18b00 554c4c3a 2b454344 48452d45 43445341  ULL:+ECDHE-ECDSA
 18b10 3a2b4355 5256452d 58323535 3139006f  :+CURVE-X25519.o
 18b20 6373705f 7265715f 696e6974 3a202573  csp_req_init: %s
 18b30 006f6373 705f7265 715f6164 645f6365  .ocsp_req_add_ce
 18b40 72743a20 2573006f 6373705f 7265715f  rt: %s.ocsp_req_
 18b50 7365745f 6e6f6e63 653a2025 73006f63  set_nonce: %s.oc
 18b60 73705f72 65715f65 78706f72 743a2025  sp_req_export: %
 18b70 73004661 696c7572 65005375 63636573  s.Failure.Succes
 18b80 73005369 676e6572 20636572 74206e6f  s.Signer cert no
 18b90 7420666f 756e6400 5369676e 65722063  t found.Signer c
 18ba0 65727420 6b657975 73616765 20657272  ert keyusage err
 18bb0 6f720053 69676e65 72206365 72742069  or.Signer cert i
 18bc0 73206e6f 74207472 75737465 6400496e  s not trusted.In
 18bd0 73656375 72652061 6c676f72 6974686d  secure algorithm
 18be0 00536967 6e617475 72652066 61696c75  .Signature failu
 18bf0 72650053 69676e65 72206365 7274206e  re.Signer cert n
 18c00 6f742079 65742061 63746976 61746564  ot yet activated
 18c10 00536967 6e657220 63657274 20657870  .Signer cert exp
 18c20 69726564 006f6373 705f7265 73705f69  ired.ocsp_resp_i
 18c30 6e69743a 20257300 696d706f 7274696e  nit: %s.importin
 18c40 67207265 73706f6e 73653a20 2573004f  g response: %s.O
 18c50 43535020 76657269 66696361 74696f6e  CSP verification
 18c60 3a202573 0a002a2a 2a205665 72696679  : %s..*** Verify
 18c70 696e6720 4f435350 20526573 706f6e73  ing OCSP Respons
 18c80 653a2000 72656164 696e6720 72657370  e: .reading resp
 18c90 6f6e7365 3a202573 0a000000 00000000  onse: %s........
 18ca0 2a2a2a20 43616e6e 6f742066 696e6420  *** Cannot find 
 18cb0 4f435350 20736572 76657220 55524920  OCSP server URI 
 18cc0 696e2063 65727469 66696361 74653a20  in certificate: 
 18cd0 25730a00 00000000 436f6e6e 65637469  %s......Connecti
 18ce0 6e672074 6f204f43 53502073 65727665  ng to OCSP serve
 18cf0 723a2025 732e2e2e 0a000000 00000000  r: %s...........
 18d00 504f5354 202f2573 20485454 502f312e  POST /%s HTTP/1.
 18d10 300d0a48 6f73743a 2025730d 0a416363  0..Host: %s..Acc
 18d20 6570743a 202a2f2a 0d0a436f 6e74656e  ept: */*..Conten
 18d30 742d5479 70653a20 6170706c 69636174  t-Type: applicat
 18d40 696f6e2f 6f637370 2d726571 75657374  ion/ocsp-request
 18d50 0d0a436f 6e74656e 742d4c65 6e677468  ..Content-Length
 18d60 3a202575 0d0a436f 6e6e6563 74696f6e  : %u..Connection
 18d70 3a20636c 6f73650d 0a0d0a00 00000000  : close.........

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000013a80 <.text+0xa440>:
   13a80:	ff                   	(bad)  
   13a81:	be 04 00 00 00       	mov    esi,0x4
   13a86:	48 8d 3d 83 4f 00 00 	lea    rdi,[rip+0x4f83]        # 18a10 <gnutls_reauth@plt+0xf3e0>
   13a8d:	e8 ce f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13a92:	be 04 00 00 00       	mov    esi,0x4
   13a97:	48 8d 3d ca 4f 00 00 	lea    rdi,[rip+0x4fca]        # 18a68 <gnutls_reauth@plt+0xf438>
   13a9e:	e8 bd f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13aa3:	be 07 00 00 00       	mov    esi,0x7
   13aa8:	48 8d 3d 11 50 00 00 	lea    rdi,[rip+0x5011]        # 18ac0 <gnutls_reauth@plt+0xf490>
   13aaf:	e8 ac f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ab4:	be 01 00 00 00       	mov    esi,0x1
   13ab9:	48 8d 3d 90 4a 00 00 	lea    rdi,[rip+0x4a90]        # 18550 <gnutls_reauth@plt+0xef20>
   13ac0:	e8 9b f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ac5:	be 09 00 00 00       	mov    esi,0x9
   13aca:	48 8d 3d c7 4c 00 00 	lea    rdi,[rip+0x4cc7]        # 18798 <gnutls_reauth@plt+0xf168>
   13ad1:	e8 8a f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ad6:	e9 29 ff ff ff       	jmp    13a04 <gnutls_reauth@plt+0xa3d4>
   13adb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   13ae0:	41 55                	push   r13
   13ae2:	48 8d 05 1e 31 00 00 	lea    rax,[rip+0x311e]        # 16c07 <gnutls_reauth@plt+0xd5d7>
   13ae9:	41 54                	push   r12
   13aeb:	49 89 d4             	mov    r12,rdx
   13aee:	55                   	push   rbp
   13aef:	48 89 f5             	mov    rbp,rsi
   13af2:	53                   	push   rbx
   13af3:	48 89 fb             	mov    rbx,rdi
   13af6:	48 83 ec 08          	sub    rsp,0x8
   13afa:	c7 06 00 00 00 00    	mov    DWORD PTR [rsi],0x0
   13b00:	48 8d 35 48 33 00 00 	lea    rsi,[rip+0x3348]        # 16e4f <gnutls_reauth@plt+0xd81f>
   13b07:	48 89 02             	mov    QWORD PTR [rdx],rax
   13b0a:	e8 91 51 ff ff       	call   8ca0 <strstr@plt>
   13b0f:	48 85 c0             	test   rax,rax
   13b12:	74 66                	je     13b7a <gnutls_reauth@plt+0xa54a>
   13b14:	4c 8d 2d e5 09 08 00 	lea    r13,[rip+0x809e5]        # 94500 <stdout@GLIBC_2.2.5+0x72218>
   13b1b:	48 8d 48 07          	lea    rcx,[rax+0x7]
   13b1f:	31 c0                	xor    eax,eax
   13b21:	be 00 02 00 00       	mov    esi,0x200
   13b26:	4c 89 ef             	mov    rdi,r13
   13b29:	48 8d 15 66 30 00 00 	lea    rdx,[rip+0x3066]        # 16b96 <gnutls_reauth@plt+0xd566>
   13b30:	e8 0b 49 ff ff       	call   8440 <snprintf@plt>
   13b35:	be 2f 00 00 00       	mov    esi,0x2f
   13b3a:	4c 89 ef             	mov    rdi,r13
   13b3d:	e8 8e 53 ff ff       	call   8ed0 <strchr@plt>
   13b42:	48 85 c0             	test   rax,rax
   13b45:	74 0b                	je     13b52 <gnutls_reauth@plt+0xa522>
   13b47:	c6 00 00             	mov    BYTE PTR [rax],0x0
   13b4a:	48 83 c0 01          	add    rax,0x1
   13b4e:	49 89 04 24          	mov    QWORD PTR [r12],rax
   13b52:	be 3a 00 00 00       	mov    esi,0x3a
   13b57:	4c 89 ef             	mov    rdi,r13
   13b5a:	48 8d 1d 9f 09 08 00 	lea    rbx,[rip+0x8099f]        # 94500 <stdout@GLIBC_2.2.5+0x72218>
   13b61:	e8 6a 53 ff ff       	call   8ed0 <strchr@plt>
   13b66:	48 85 c0             	test   rax,rax
   13b69:	74 0f                	je     13b7a <gnutls_reauth@plt+0xa54a>
   13b6b:	c6 00 00             	mov    BYTE PTR [rax],0x0
   13b6e:	48 8d 78 01          	lea    rdi,[rax+0x1]
   13b72:	e8 d9 51 ff ff       	call   8d50 <atoi@plt>
   13b77:	89 45 00             	mov    DWORD PTR [rbp+0x0],eax
   13b7a:	48 83 c4 08          	add    rsp,0x8
   13b7e:	48 89 d8             	mov    rax,rbx
   13b81:	5b                   	pop    rbx
   13b82:	5d                   	pop    rbp
   13b83:	41 5c                	pop    r12
   13b85:	41 5d                	pop    r13
   13b87:	c3                   	ret    
   13b88:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   13b8f:	00 
   13b90:	55                   	push   rbp
   13b91:	48 89 fd             	mov    rbp,rdi
   13b94:	53                   	push   rbx
   13b95:	48 89 f3             	mov    rbx,rsi
   13b98:	48 83 ec 08          	sub    rsp,0x8
   13b9c:	8b 76 08             	mov    esi,DWORD PTR [rsi+0x8]
   13b9f:	48 01 fe             	add    rsi,rdi
   13ba2:	48 8b 3b             	mov    rdi,QWORD PTR [rbx]
   13ba5:	e8 16 58 ff ff       	call   93c0 <realloc@plt>
   13baa:	48 89 03             	mov    QWORD PTR [rbx],rax
   13bad:	48 85 c0             	test   rax,rax
   13bb0:	74 20                	je     13bd2 <gnutls_reauth@plt+0xa5a2>
   13bb2:	8b 53 08             	mov    edx,DWORD PTR [rbx+0x8]
   13bb5:	48 8d 35 44 0b 08 00 	lea    rsi,[rip+0x80b44]        # 94700 <stdout@GLIBC_2.2.5+0x72418>
   13bbc:	48 8d 3c 10          	lea    rdi,[rax+rdx*1]
   13bc0:	48 89 ea             	mov    rdx,rbp
   13bc3:	e8 78 59 ff ff       	call   9540 <memcpy@plt>
   13bc8:	01 6b 08             	add    DWORD PTR [rbx+0x8],ebp
   13bcb:	48 83 c4 08          	add    rsp,0x8
   13bcf:	5b                   	pop    rbx
   13bd0:	5d                   	pop    rbp
   13bd1:	c3                   	ret    
   13bd2:	48 8b 3d 07 e7 00 00 	mov    rdi,QWORD PTR [rip+0xe707]        # 222e0 <stderr@GLIBC_2.2.5>
   13bd9:	48 8d 15 a8 2c 00 00 	lea    rdx,[rip+0x2ca8]        # 16888 <gnutls_reauth@plt+0xd258>
   13be0:	be 01 00 00 00       	mov    esi,0x1
   13be5:	e8 66 49 ff ff       	call   8550 <__fprintf_chk@plt>
   13bea:	bf 01 00 00 00       	mov    edi,0x1
   13bef:	e8 fc 49 ff ff       	call   85f0 <exit@plt>
   13bf4:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   13bfb:	00 00 00 00 
   13bff:	90                   	nop
   13c00:	f3 0f 1e fa          	endbr64 
   13c04:	41 56                	push   r14
   13c06:	49 89 fe             	mov    r14,rdi
   13c09:	41 55                	push   r13
   13c0b:	49 89 f5             	mov    r13,rsi
   13c0e:	41 54                	push   r12
   13c10:	49 89 cc             	mov    r12,rcx
   13c13:	55                   	push   rbp
   13c14:	48 89 d5             	mov    rbp,rdx
   13c17:	48 83 ec 18          	sub    rsp,0x18
   13c1b:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   13c22:	00 00 
   13c24:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   13c29:	31 c0                	xor    eax,eax
   13c2b:	48 89 e7             	mov    rdi,rsp
   13c2e:	e8 5d 53 ff ff       	call   8f90 <gnutls_ocsp_req_init@plt>
   13c33:	85 c0                	test   eax,eax
   13c35:	78 6c                	js     13ca3 <gnutls_reauth@plt+0xa673>
   13c37:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c3b:	4c 89 f1             	mov    rcx,r14
   13c3e:	4c 89 ea             	mov    rdx,r13
   13c41:	be 03 00 00 00       	mov    esi,0x3
   13c46:	e8 65 57 ff ff       	call   93b0 <gnutls_ocsp_req_add_cert@plt>
   13c4b:	85 c0                	test   eax,eax
   13c4d:	0f 88 96 00 00 00    	js     13ce9 <gnutls_reauth@plt+0xa6b9>
   13c53:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c57:	4d 85 e4             	test   r12,r12
   13c5a:	74 16                	je     13c72 <gnutls_reauth@plt+0xa642>
   13c5c:	31 f6                	xor    esi,esi
   13c5e:	4c 89 e2             	mov    rdx,r12
   13c61:	e8 7a 4b ff ff       	call   87e0 <gnutls_ocsp_req_set_nonce@plt>
   13c66:	85 c0                	test   eax,eax
   13c68:	0f 88 8e 00 00 00    	js     13cfc <gnutls_reauth@plt+0xa6cc>
   13c6e:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c72:	48 89 ee             	mov    rsi,rbp
   13c75:	e8 d6 4f ff ff       	call   8c50 <gnutls_ocsp_req_export@plt>
   13c7a:	85 c0                	test   eax,eax
   13c7c:	75 58                	jne    13cd6 <gnutls_reauth@plt+0xa6a6>
   13c7e:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c82:	e8 a9 53 ff ff       	call   9030 <gnutls_ocsp_req_deinit@plt>
   13c87:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   13c8c:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   13c93:	00 00 
   13c95:	75 3a                	jne    13cd1 <gnutls_reauth@plt+0xa6a1>
   13c97:	48 83 c4 18          	add    rsp,0x18
   13c9b:	5d                   	pop    rbp
   13c9c:	41 5c                	pop    r12
   13c9e:	41 5d                	pop    r13
   13ca0:	41 5e                	pop    r14
   13ca2:	c3                   	ret    
   13ca3:	89 c7                	mov    edi,eax
   13ca5:	e8 46 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13caa:	48 8d 15 6e 4e 00 00 	lea    rdx,[rip+0x4e6e]        # 18b1f <gnutls_reauth@plt+0xf4ef>
   13cb1:	48 89 c1             	mov    rcx,rax
   13cb4:	48 8b 3d 25 e6 00 00 	mov    rdi,QWORD PTR [rip+0xe625]        # 222e0 <stderr@GLIBC_2.2.5>
   13cbb:	be 01 00 00 00       	mov    esi,0x1
   13cc0:	31 c0                	xor    eax,eax
   13cc2:	e8 89 48 ff ff       	call   8550 <__fprintf_chk@plt>
   13cc7:	bf 01 00 00 00       	mov    edi,0x1
   13ccc:	e8 1f 49 ff ff       	call   85f0 <exit@plt>
   13cd1:	e8 4a 53 ff ff       	call   9020 <__stack_chk_fail@plt>
   13cd6:	89 c7                	mov    edi,eax
   13cd8:	e8 13 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13cdd:	48 8d 15 7a 4e 00 00 	lea    rdx,[rip+0x4e7a]        # 18b5e <gnutls_reauth@plt+0xf52e>
   13ce4:	48 89 c1             	mov    rcx,rax
   13ce7:	eb cb                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13ce9:	89 c7                	mov    edi,eax
   13ceb:	e8 00 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13cf0:	48 8d 15 3a 4e 00 00 	lea    rdx,[rip+0x4e3a]        # 18b31 <gnutls_reauth@plt+0xf501>
   13cf7:	48 89 c1             	mov    rcx,rax
   13cfa:	eb b8                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13cfc:	89 c7                	mov    edi,eax
   13cfe:	e8 ed 52 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13d03:	48 8d 15 3d 4e 00 00 	lea    rdx,[rip+0x4e3d]        # 18b47 <gnutls_reauth@plt+0xf517>
   13d0a:	48 89 c1             	mov    rcx,rax
   13d0d:	eb a5                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13d0f:	90                   	nop

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000010d50 <.text+0x7710>:
   10d50:	84 c6                	test   dh,al
   10d52:	fc                   	cld    
   10d53:	ff                   	(bad)  
   10d54:	ff                   	(bad)  
   10d55:	e9 b0 fe ff ff       	jmp    10c0a <gnutls_reauth@plt+0x75da>
   10d5a:	48 8b 3d 87 15 01 00 	mov    rdi,QWORD PTR [rip+0x11587]        # 222e8 <stdout@GLIBC_2.2.5>
   10d61:	48 8d 35 86 72 00 00 	lea    rsi,[rip+0x7286]        # 17fee <gnutls_reauth@plt+0xe9be>
   10d68:	e8 23 cf ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   10d6d:	e9 d2 fe ff ff       	jmp    10c44 <gnutls_reauth@plt+0x7614>
   10d72:	48 8b 3d 6f 15 01 00 	mov    rdi,QWORD PTR [rip+0x1156f]        # 222e8 <stdout@GLIBC_2.2.5>
   10d79:	48 8d 35 48 6f 00 00 	lea    rsi,[rip+0x6f48]        # 17cc8 <gnutls_reauth@plt+0xe698>
   10d80:	31 c0                	xor    eax,eax
   10d82:	e8 09 cf ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   10d87:	eb 9f                	jmp    10d28 <gnutls_reauth@plt+0x76f8>
   10d89:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   10d90:	f3 0f 1e fa          	endbr64 
   10d94:	41 54                	push   r12
   10d96:	49 89 f4             	mov    r12,rsi
   10d99:	55                   	push   rbp
   10d9a:	48 63 ea             	movsxd rbp,edx
   10d9d:	53                   	push   rbx
   10d9e:	8b 47 10             	mov    eax,DWORD PTR [rdi+0x10]
   10da1:	48 89 fb             	mov    rbx,rdi
   10da4:	85 c0                	test   eax,eax
   10da6:	74 3a                	je     10de2 <gnutls_reauth@plt+0x77b2>
   10da8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   10daf:	00 
   10db0:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10db4:	48 89 ea             	mov    rdx,rbp
   10db7:	4c 89 e6             	mov    rsi,r12
   10dba:	e8 21 77 ff ff       	call   84e0 <gnutls_record_recv@plt>
   10dbf:	89 c2                	mov    edx,eax
   10dc1:	3d db fe ff ff       	cmp    eax,0xfffffedb
   10dc6:	74 38                	je     10e00 <gnutls_reauth@plt+0x77d0>
   10dc8:	83 f8 cc             	cmp    eax,0xffffffcc
   10dcb:	74 e3                	je     10db0 <gnutls_reauth@plt+0x7780>
   10dcd:	5b                   	pop    rbx
   10dce:	48 63 c2             	movsxd rax,edx
   10dd1:	5d                   	pop    rbp
   10dd2:	41 5c                	pop    r12
   10dd4:	c3                   	ret    
   10dd5:	0f 1f 00             	nop    DWORD PTR [rax]
   10dd8:	e8 c3 81 ff ff       	call   8fa0 <__errno_location@plt>
   10ddd:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10de0:	75 2e                	jne    10e10 <gnutls_reauth@plt+0x77e0>
   10de2:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10de4:	48 89 ea             	mov    rdx,rbp
   10de7:	31 c9                	xor    ecx,ecx
   10de9:	4c 89 e6             	mov    rsi,r12
   10dec:	e8 cf 79 ff ff       	call   87c0 <recv@plt>
   10df1:	89 c2                	mov    edx,eax
   10df3:	83 f8 ff             	cmp    eax,0xffffffff
   10df6:	74 e0                	je     10dd8 <gnutls_reauth@plt+0x77a8>
   10df8:	eb d3                	jmp    10dcd <gnutls_reauth@plt+0x779d>
   10dfa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10e00:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e04:	31 f6                	xor    esi,esi
   10e06:	e8 55 75 ff ff       	call   8360 <gnutls_heartbeat_pong@plt>
   10e0b:	eb a3                	jmp    10db0 <gnutls_reauth@plt+0x7780>
   10e0d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e10:	5b                   	pop    rbx
   10e11:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   10e18:	5d                   	pop    rbp
   10e19:	41 5c                	pop    r12
   10e1b:	c3                   	ret    
   10e1c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10e20:	f3 0f 1e fa          	endbr64 
   10e24:	55                   	push   rbp
   10e25:	48 89 f5             	mov    rbp,rsi
   10e28:	53                   	push   rbx
   10e29:	48 89 fb             	mov    rbx,rdi
   10e2c:	48 83 ec 18          	sub    rsp,0x18
   10e30:	8b 77 10             	mov    esi,DWORD PTR [rdi+0x10]
   10e33:	85 f6                	test   esi,esi
   10e35:	75 29                	jne    10e60 <gnutls_reauth@plt+0x7830>
   10e37:	48 89 ee             	mov    rsi,rbp
   10e3a:	48 89 df             	mov    rdi,rbx
   10e3d:	e8 4e ff ff ff       	call   10d90 <gnutls_reauth@plt+0x7760>
   10e42:	48 89 c5             	mov    rbp,rax
   10e45:	8b 43 10             	mov    eax,DWORD PTR [rbx+0x10]
   10e48:	85 c0                	test   eax,eax
   10e4a:	75 2c                	jne    10e78 <gnutls_reauth@plt+0x7848>
   10e4c:	48 83 c4 18          	add    rsp,0x18
   10e50:	48 63 c5             	movsxd rax,ebp
   10e53:	5b                   	pop    rbx
   10e54:	5d                   	pop    rbp
   10e55:	c3                   	ret    
   10e56:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   10e5d:	00 00 00 
   10e60:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
   10e64:	89 ce                	mov    esi,ecx
   10e66:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   10e6a:	e8 31 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e6f:	8b 54 24 0c          	mov    edx,DWORD PTR [rsp+0xc]
   10e73:	eb c2                	jmp    10e37 <gnutls_reauth@plt+0x7807>
   10e75:	0f 1f 00             	nop    DWORD PTR [rax]
   10e78:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e7c:	31 f6                	xor    esi,esi
   10e7e:	e8 1d 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e83:	48 83 c4 18          	add    rsp,0x18
   10e87:	48 63 c5             	movsxd rax,ebp
   10e8a:	5b                   	pop    rbx
   10e8b:	5d                   	pop    rbp
   10e8c:	c3                   	ret    
   10e8d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e90:	f3 0f 1e fa          	endbr64 
   10e94:	41 56                	push   r14
   10e96:	49 89 ce             	mov    r14,rcx
   10e99:	41 55                	push   r13
   10e9b:	41 54                	push   r12
   10e9d:	4c 63 e2             	movsxd r12,edx
   10ea0:	55                   	push   rbp
   10ea1:	4d 89 e5             	mov    r13,r12
   10ea4:	48 89 f5             	mov    rbp,rsi
   10ea7:	53                   	push   rbx
   10ea8:	8b 57 10             	mov    edx,DWORD PTR [rdi+0x10]
   10eab:	48 89 fb             	mov    rbx,rdi
   10eae:	85 d2                	test   edx,edx
   10eb0:	74 58                	je     10f0a <gnutls_reauth@plt+0x78da>
   10eb2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10eb8:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10ebc:	4d 85 f6             	test   r14,r14
   10ebf:	74 67                	je     10f28 <gnutls_reauth@plt+0x78f8>
   10ec1:	4c 89 f1             	mov    rcx,r14
   10ec4:	4c 89 e2             	mov    rdx,r12
   10ec7:	48 89 ee             	mov    rsi,rbp
   10eca:	e8 01 7a ff ff       	call   88d0 <gnutls_record_send_range@plt>
   10ecf:	89 c1                	mov    ecx,eax
   10ed1:	83 f9 e4             	cmp    ecx,0xffffffe4
   10ed4:	74 e2                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10ed6:	83 f9 cc             	cmp    ecx,0xffffffcc
   10ed9:	74 dd                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10edb:	4c 63 e1             	movsxd r12,ecx
   10ede:	85 c9                	test   ecx,ecx
   10ee0:	7e 0c                	jle    10eee <gnutls_reauth@plt+0x78be>
   10ee2:	44 39 e9             	cmp    ecx,r13d
   10ee5:	74 07                	je     10eee <gnutls_reauth@plt+0x78be>
   10ee7:	8b 43 48             	mov    eax,DWORD PTR [rbx+0x48]
   10eea:	85 c0                	test   eax,eax
   10eec:	75 6a                	jne    10f58 <gnutls_reauth@plt+0x7928>
   10eee:	5b                   	pop    rbx
   10eef:	4c 89 e0             	mov    rax,r12
   10ef2:	5d                   	pop    rbp
   10ef3:	41 5c                	pop    r12
   10ef5:	41 5d                	pop    r13
   10ef7:	41 5e                	pop    r14
   10ef9:	c3                   	ret    
   10efa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f00:	e8 9b 80 ff ff       	call   8fa0 <__errno_location@plt>
   10f05:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10f08:	75 36                	jne    10f40 <gnutls_reauth@plt+0x7910>
   10f0a:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10f0c:	31 c9                	xor    ecx,ecx
   10f0e:	4c 89 e2             	mov    rdx,r12
   10f11:	48 89 ee             	mov    rsi,rbp
   10f14:	e8 07 82 ff ff       	call   9120 <send@plt>
   10f19:	89 c1                	mov    ecx,eax
   10f1b:	83 f8 ff             	cmp    eax,0xffffffff
   10f1e:	74 e0                	je     10f00 <gnutls_reauth@plt+0x78d0>
   10f20:	eb b9                	jmp    10edb <gnutls_reauth@plt+0x78ab>
   10f22:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f28:	4c 89 e2             	mov    rdx,r12
   10f2b:	48 89 ee             	mov    rsi,rbp
   10f2e:	e8 ad 80 ff ff       	call   8fe0 <gnutls_record_send@plt>
   10f33:	89 c1                	mov    ecx,eax
   10f35:	eb 9a                	jmp    10ed1 <gnutls_reauth@plt+0x78a1>
   10f37:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   10f3e:	00 00 
   10f40:	49 c7 c4 ff ff ff ff 	mov    r12,0xffffffffffffffff
   10f47:	5b                   	pop    rbx
   10f48:	5d                   	pop    rbp
   10f49:	4c 89 e0             	mov    rax,r12
   10f4c:	41 5c                	pop    r12
   10f4e:	41 5d                	pop    r13
   10f50:	41 5e                	pop    r14
   10f52:	c3                   	ret    
   10f53:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   10f58:	48 8b 3d 81 13 01 00 	mov    rdi,QWORD PTR [rip+0x11381]        # 222e0 <stderr@GLIBC_2.2.5>
   10f5f:	45 89 e8             	mov    r8d,r13d
   10f62:	be 01 00 00 00       	mov    esi,0x1
   10f67:	31 c0                	xor    eax,eax
   10f69:	48 8d 15 80 6d 00 00 	lea    rdx,[rip+0x6d80]        # 17cf0 <gnutls_reauth@plt+0xe6c0>
   10f70:	e8 db 75 ff ff       	call   8550 <__fprintf_chk@plt>
   10f75:	5b                   	pop    rbx
   10f76:	4c 89 e0             	mov    rax,r12
   10f79:	5d                   	pop    rbp
   10f7a:	41 5c                	pop    r12
   10f7c:	41 5d                	pop    r13
   10f7e:	41 5e                	pop    r14
   10f80:	c3                   	ret    
   10f81:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   10f88:	00 00 00 00 
   10f8c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10f90:	f3 0f 1e fa          	endbr64 
   10f94:	31 c9                	xor    ecx,ecx
   10f96:	e9 f5 fe ff ff       	jmp    10e90 <gnutls_reauth@plt+0x7860>
   10f9b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   10fa0:	f3 0f 1e fa          	endbr64 
   10fa4:	55                   	push   rbp
   10fa5:	48 8d 35 33 6f 00 00 	lea    rsi,[rip+0x6f33]        # 17edf <gnutls_reauth@plt+0xe8af>
   10fac:	48 89 fd             	mov    rbp,rdi
   10faf:	e8 dc 76 ff ff       	call   8690 <strcasecmp@plt>
   10fb4:	85 c0                	test   eax,eax
   10fb6:	48 8d 05 7c 70 00 00 	lea    rax,[rip+0x707c]        # 18039 <gnutls_reauth@plt+0xea09>
   10fbd:	48 0f 44 e8          	cmove  rbp,rax
   10fc1:	31 f6                	xor    esi,esi
   10fc3:	48 89 ef             	mov    rdi,rbp
   10fc6:	e8 55 86 ff ff       	call   9620 <getservbyname@plt>
   10fcb:	48 85 c0             	test   rax,rax
   10fce:	74 10                	je     10fe0 <gnutls_reauth@plt+0x79b0>
   10fd0:	0f b7 78 10          	movzx  edi,WORD PTR [rax+0x10]
   10fd4:	e8 97 f3 ff ff       	call   10370 <gnutls_reauth@plt+0x6d40>
   10fd9:	5d                   	pop    rbp
   10fda:	0f b7 c0             	movzx  eax,ax
   10fdd:	c3                   	ret    
   10fde:	66 90                	xchg   ax,ax
   10fe0:	e8 8b 82 ff ff       	call   9270 <endservent@plt>
   10fe5:	b8 bb 01 00 00       	mov    eax,0x1bb
   10fea:	5d                   	pop    rbp
   10feb:	c3                   	ret    
   10fec:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10ff0:	f3 0f 1e fa          	endbr64 
   10ff4:	55                   	push   rbp
   10ff5:	48 8d 35 e3 6e 00 00 	lea    rsi,[rip+0x6ee3]        # 17edf <gnutls_reauth@plt+0xe8af>
   10ffc:	48 89 fd             	mov    rbp,rdi
   10fff:	e8 8c 76 ff ff       	call   8690 <strcasecmp@plt>
   11004:	85 c0                	test   eax,eax
   11006:	48 8d 05 2c 70 00 00 	lea    rax,[rip+0x702c]        # 18039 <gnutls_reauth@plt+0xea09>
   1100d:	48 0f 44 e8          	cmove  rbp,rax
   11011:	31 f6                	xor    esi,esi
   11013:	48 89 ef             	mov    rdi,rbp
   11016:	e8 05 86 ff ff       	call   9620 <getservbyname@plt>
   1101b:	48 85 c0             	test   rax,rax
   1101e:	74 08                	je     11028 <gnutls_reauth@plt+0x79f8>
   11020:	48 8b 00             	mov    rax,QWORD PTR [rax]
   11023:	5d                   	pop    rbp
   11024:	c3                   	ret    
   11025:	0f 1f 00             	nop    DWORD PTR [rax]
   11028:	e8 43 82 ff ff       	call   9270 <endservent@plt>
   1102d:	48 8d 05 11 70 00 00 	lea    rax,[rip+0x7011]        # 18045 <gnutls_reauth@plt+0xea15>
   11034:	5d                   	pop    rbp
   11035:	c3                   	ret    
   11036:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1103d:	00 00 00 
   11040:	f3 0f 1e fa          	endbr64 
   11044:	53                   	push   rbx
   11045:	48 89 fb             	mov    rbx,rdi
   11048:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
   1104c:	8b 4b 10             	mov    ecx,DWORD PTR [rbx+0x10]
   1104f:	85 c9                	test   ecx,ecx
   11051:	74 48                	je     1109b <gnutls_reauth@plt+0x7a6b>
   11053:	85 f6                	test   esi,esi
   11055:	74 44                	je     1109b <gnutls_reauth@plt+0x7a6b>
   11057:	48 85 ff             	test   rdi,rdi
   1105a:	74 51                	je     110ad <gnutls_reauth@plt+0x7a7d>
   1105c:	be 01 00 00 00       	mov    esi,0x1
   11061:	e8 fa 7d ff ff       	call   8e60 <gnutls_bye@plt>
   11066:	83 f8 cc             	cmp    eax,0xffffffcc
   11069:	75 18                	jne    11083 <gnutls_reauth@plt+0x7a53>
   1106b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   11070:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   11074:	be 01 00 00 00       	mov    esi,0x1
   11079:	e8 e2 7d ff ff       	call   8e60 <gnutls_bye@plt>
   1107e:	83 f8 cc             	cmp    eax,0xffffffcc
   11081:	74 ed                	je     11070 <gnutls_reauth@plt+0x7a40>
   11083:	83 f8 e4             	cmp    eax,0xffffffe4
   11086:	74 e8                	je     11070 <gnutls_reauth@plt+0x7a40>
   11088:	8b 53 48             	mov    edx,DWORD PTR [rbx+0x48]
   1108b:	85 d2                	test   edx,edx
   1108d:	74 08                	je     11097 <gnutls_reauth@plt+0x7a67>
   1108f:	85 c0                	test   eax,eax
   11091:	0f 88 b9 00 00 00    	js     11150 <gnutls_reauth@plt+0x7b20>
   11097:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   1109b:	48 85 ff             	test   rdi,rdi
   1109e:	74 0d                	je     110ad <gnutls_reauth@plt+0x7a7d>
   110a0:	e8 6b 7b ff ff       	call   8c10 <gnutls_deinit@plt>
   110a5:	48 c7 43 08 00 00 00 	mov    QWORD PTR [rbx+0x8],0x0
   110ac:	00 
   110ad:	48 8b 7b 40          	mov    rdi,QWORD PTR [rbx+0x40]
   110b1:	e8 2a 79 ff ff       	call   89e0 <freeaddrinfo@plt>
   110b6:	48 c7 43 38 00 00 00 	mov    QWORD PTR [rbx+0x38],0x0
   110bd:	00 
   110be:	48 8b 7b 28          	mov    rdi,QWORD PTR [rbx+0x28]
   110c2:	48 c7 43 40 00 00 00 	mov    QWORD PTR [rbx+0x40],0x0
   110c9:	00 
   110ca:	c7 83 d0 00 00 00 00 	mov    DWORD PTR [rbx+0xd0],0x0
   110d1:	00 00 00 
   110d4:	e8 27 79 ff ff       	call   8a00 <free@plt>
   110d9:	48 8b 7b 18          	mov    rdi,QWORD PTR [rbx+0x18]
   110dd:	e8 1e 79 ff ff       	call   8a00 <free@plt>
   110e2:	48 8b 7b 30          	mov    rdi,QWORD PTR [rbx+0x30]
   110e6:	e8 15 79 ff ff       	call   8a00 <free@plt>
   110eb:	8b 3b                	mov    edi,DWORD PTR [rbx]
   110ed:	be 02 00 00 00       	mov    esi,0x2
   110f2:	e8 79 73 ff ff       	call   8470 <shutdown@plt>
   110f7:	8b 3b                	mov    edi,DWORD PTR [rbx]
   110f9:	e8 92 73 ff ff       	call   8490 <close@plt>
   110fe:	48 8b bb e8 00 00 00 	mov    rdi,QWORD PTR [rbx+0xe8]
   11105:	ff 15 9d 11 01 00    	call   QWORD PTR [rip+0x1119d]        # 222a8 <gnutls_free@GNUTLS_3_4>
   1110b:	48 8b bb d8 00 00 00 	mov    rdi,QWORD PTR [rbx+0xd8]
   11112:	48 c7 83 e8 00 00 00 	mov    QWORD PTR [rbx+0xe8],0x0
   11119:	00 00 00 00 
   1111d:	48 85 ff             	test   rdi,rdi
   11120:	74 05                	je     11127 <gnutls_reauth@plt+0x7af7>
   11122:	e8 b9 80 ff ff       	call   91e0 <fclose@plt>
   11127:	48 8b bb e0 00 00 00 	mov    rdi,QWORD PTR [rbx+0xe0]
   1112e:	48 85 ff             	test   rdi,rdi
   11131:	74 05                	je     11138 <gnutls_reauth@plt+0x7b08>
   11133:	e8 a8 80 ff ff       	call   91e0 <fclose@plt>
   11138:	c7 03 ff ff ff ff    	mov    DWORD PTR [rbx],0xffffffff
   1113e:	c7 43 10 00 00 00 00 	mov    DWORD PTR [rbx+0x10],0x0
   11145:	5b                   	pop    rbx
   11146:	c3                   	ret    
   11147:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1114e:	00 00 
   11150:	89 c7                	mov    edi,eax
   11152:	e8 99 7e ff ff       	call   8ff0 <gnutls_strerror@plt>
   11157:	48 8b 3d 82 11 01 00 	mov    rdi,QWORD PTR [rip+0x11182]        # 222e0 <stderr@GLIBC_2.2.5>
   1115e:	be 01 00 00 00       	mov    esi,0x1
   11163:	48 8d 15 df 6e 00 00 	lea    rdx,[rip+0x6edf]        # 18049 <gnutls_reauth@plt+0xea19>
   1116a:	48 89 c1             	mov    rcx,rax
   1116d:	31 c0                	xor    eax,eax
   1116f:	e8 dc 73 ff ff       	call   8550 <__fprintf_chk@plt>
   11174:	e9 1e ff ff ff       	jmp    11097 <gnutls_reauth@plt+0x7a67>
   11179:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   11180:	f3 0f 1e fa          	endbr64 
   11184:	41 55                	push   r13
   11186:	49 89 f5             	mov    r13,rsi
   11189:	be 3a 00 00 00       	mov    esi,0x3a
   1118e:	41 54                	push   r12
   11190:	41 89 d4             	mov    r12d,edx
   11193:	55                   	push   rbp
   11194:	48 89 fd             	mov    rbp,rdi
   11197:	53                   	push   rbx
   11198:	48 83 ec 58          	sub    rsp,0x58
   1119c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   111a3:	00 00 
   111a5:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
   111aa:	31 c0                	xor    eax,eax
   111ac:	e8 1f 7d ff ff       	call   8ed0 <strchr@plt>
   111b1:	48 85 c0             	test   rax,rax
   111b4:	74 5a                	je     11210 <gnutls_reauth@plt+0x7be0>
   111b6:	48 89 e2             	mov    rdx,rsp
   111b9:	48 89 ee             	mov    rsi,rbp
   111bc:	bf 0a 00 00 00       	mov    edi,0xa
   111c1:	48 89 c3             	mov    rbx,rax
   111c4:	e8 b7 72 ff ff       	call   8480 <inet_pton@plt>
   111c9:	83 f8 01             	cmp    eax,0x1
   111cc:	74 1d                	je     111eb <gnutls_reauth@plt+0x7bbb>
   111ce:	c6 03 00             	mov    BYTE PTR [rbx],0x0
   111d1:	4d 85 ed             	test   r13,r13
   111d4:	74 0a                	je     111e0 <gnutls_reauth@plt+0x7bb0>
   111d6:	45 85 e4             	test   r12d,r12d
   111d9:	75 55                	jne    11230 <gnutls_reauth@plt+0x7c00>
   111db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   111e0:	48 39 eb             	cmp    rbx,rbp
   111e3:	76 06                	jbe    111eb <gnutls_reauth@plt+0x7bbb>
   111e5:	80 7b ff 2e          	cmp    BYTE PTR [rbx-0x1],0x2e
   111e9:	74 35                	je     11220 <gnutls_reauth@plt+0x7bf0>
   111eb:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
   111f0:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   111f7:	00 00 
   111f9:	75 4f                	jne    1124a <gnutls_reauth@plt+0x7c1a>
   111fb:	48 83 c4 58          	add    rsp,0x58
   111ff:	5b                   	pop    rbx
   11200:	5d                   	pop    rbp
   11201:	41 5c                	pop    r12
   11203:	41 5d                	pop    r13
   11205:	c3                   	ret    
   11206:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1120d:	00 00 00 
   11210:	48 89 ef             	mov    rdi,rbp
   11213:	e8 28 78 ff ff       	call   8a40 <strlen@plt>
   11218:	48 8d 5c 05 00       	lea    rbx,[rbp+rax*1+0x0]
   1121d:	eb c1                	jmp    111e0 <gnutls_reauth@plt+0x7bb0>
   1121f:	90                   	nop
   11220:	c6 43 ff 00          	mov    BYTE PTR [rbx-0x1],0x0
   11224:	eb c5                	jmp    111eb <gnutls_reauth@plt+0x7bbb>
   11226:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1122d:	00 00 00 
   11230:	48 8d 4b 01          	lea    rcx,[rbx+0x1]
   11234:	44 89 e6             	mov    esi,r12d
   11237:	48 8d 15 58 59 00 00 	lea    rdx,[rip+0x5958]        # 16b96 <gnutls_reauth@plt+0xd566>
   1123e:	31 c0                	xor    eax,eax
   11240:	4c 89 ef             	mov    rdi,r13
   11243:	e8 f8 71 ff ff       	call   8440 <snprintf@plt>
   11248:	eb 96                	jmp    111e0 <gnutls_reauth@plt+0x7bb0>
   1124a:	e8 d1 7d ff ff       	call   9020 <__stack_chk_fail@plt>
   1124f:	90                   	nop
   11250:	f3 0f 1e fa          	endbr64 
   11254:	41 57                	push   r15
   11256:	41 56                	push   r14
   11258:	41 55                	push   r13
   1125a:	41 54                	push   r12
   1125c:	55                   	push   rbp
   1125d:	53                   	push   rbx
   1125e:	48 81 ec 00 10 00 00 	sub    rsp,0x1000
   11265:	48 83 0c 24 00       	or     QWORD PTR [rsp],0x0
   1126a:	48 81 ec b8 00 00 00 	sub    rsp,0xb8
   11271:	66 0f ef c0          	pxor   xmm0,xmm0
   11275:	48 8b 84 24 00 11 00 	mov    rax,QWORD PTR [rsp+0x1100]
   1127c:	00 
   1127d:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   11282:	48 89 fb             	mov    rbx,rdi
   11285:	48 89 d5             	mov    rbp,rdx
   11288:	48 83 c7 08          	add    rdi,0x8
   1128c:	48 8b 84 24 08 11 00 	mov    rax,QWORD PTR [rsp+0x1108]
   11293:	00 
   11294:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
   11299:	45 89 c5             	mov    r13d,r8d
   1129c:	48 89 4c 24 38       	mov    QWORD PTR [rsp+0x38],rcx
   112a1:	48 89 d9             	mov    rcx,rbx
   112a4:	41 83 e5 01          	and    r13d,0x1
   112a8:	48 8b b4 24 f0 10 00 	mov    rsi,QWORD PTR [rsp+0x10f0]
   112af:	00 
   112b0:	44 89 44 24 0c       	mov    DWORD PTR [rsp+0xc],r8d
   112b5:	48 8b 94 24 f8 10 00 	mov    rdx,QWORD PTR [rsp+0x10f8]
   112bc:	00 
   112bd:	4c 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],r9
   112c2:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   112c7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   112ce:	00 00 
   112d0:	48 89 84 24 a8 10 00 	mov    QWORD PTR [rsp+0x10a8],rax
   112d7:	00 
   112d8:	31 c0                	xor    eax,eax
   112da:	44 89 c0             	mov    eax,r8d
   112dd:	0f 29 84 24 90 00 00 	movaps XMMWORD PTR [rsp+0x90],xmm0
   112e4:	00 
   112e5:	83 e0 02             	and    eax,0x2
   112e8:	89 44 24 20          	mov    DWORD PTR [rsp+0x20],eax
   112ec:	31 c0                	xor    eax,eax
   112ee:	48 c7 47 f8 00 00 00 	mov    QWORD PTR [rdi-0x8],0x0
   112f5:	00 
   112f6:	48 c7 87 f8 00 00 00 	mov    QWORD PTR [rdi+0xf8],0x0
   112fd:	00 00 00 00 
   11301:	48 83 e7 f8          	and    rdi,0xfffffffffffffff8
   11305:	48 29 f9             	sub    rcx,rdi
   11308:	81 c1 08 01 00 00    	add    ecx,0x108
   1130e:	c1 e9 03             	shr    ecx,0x3
   11311:	41 83 e0 10          	and    r8d,0x10
   11315:	f3 48 ab             	rep stos QWORD PTR es:[rdi],rax
   11318:	74 07                	je     11321 <gnutls_reauth@plt+0x7cf1>
   1131a:	c7                   	.byte 0xc7
   1131b:	43                   	rex.XB
   1131c:	48 01 00             	add    QWORD PTR [rax],rax
	...

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000000dc20 <.text+0x45e0>:
    dc20:	f3 0f 1e fa          	endbr64 
    dc24:	41 54                	push   r12
    dc26:	49 89 fc             	mov    r12,rdi
    dc29:	48 89 d7             	mov    rdi,rdx
    dc2c:	55                   	push   rbp
    dc2d:	53                   	push   rbx
    dc2e:	48 89 f3             	mov    rbx,rsi
    dc31:	e8 ea b2 ff ff       	call   8f20 <getenv@plt>
    dc36:	48 85 c0             	test   rax,rax
    dc39:	74 10                	je     dc4b <gnutls_reauth@plt+0x461b>
    dc3b:	48 89 c7             	mov    rdi,rax
    dc3e:	48 89 c5             	mov    rbp,rax
    dc41:	e8 fa ad ff ff       	call   8a40 <strlen@plt>
    dc46:	48 39 d8             	cmp    rax,rbx
    dc49:	72 0d                	jb     dc58 <gnutls_reauth@plt+0x4628>
    dc4b:	5b                   	pop    rbx
    dc4c:	5d                   	pop    rbp
    dc4d:	41 c6 04 24 00       	mov    BYTE PTR [r12],0x0
    dc52:	41 5c                	pop    r12
    dc54:	c3                   	ret    
    dc55:	0f 1f 00             	nop    DWORD PTR [rax]
    dc58:	5b                   	pop    rbx
    dc59:	48 89 ee             	mov    rsi,rbp
    dc5c:	4c 89 e7             	mov    rdi,r12
    dc5f:	5d                   	pop    rbp
    dc60:	41 5c                	pop    r12
    dc62:	e9 09 b5 ff ff       	jmp    9170 <strcpy@plt>
    dc67:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    dc6e:	00 00 
    dc70:	f3 0f 1e fa          	endbr64 
    dc74:	be 01 00 00 00       	mov    esi,0x1
    dc79:	bf 0d 00 00 00       	mov    edi,0xd
    dc7e:	e9 fd b1 ff ff       	jmp    8e80 <signal@plt>
    dc83:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    dc8a:	00 00 00 00 
    dc8e:	66 90                	xchg   ax,ax
    dc90:	f3 0f 1e fa          	endbr64 
    dc94:	48 81 ec d8 00 00 00 	sub    rsp,0xd8
    dc9b:	49 89 fb             	mov    r11,rdi
    dc9e:	49 89 f2             	mov    r10,rsi
    dca1:	48 89 54 24 30       	mov    QWORD PTR [rsp+0x30],rdx
    dca6:	48 89 4c 24 38       	mov    QWORD PTR [rsp+0x38],rcx
    dcab:	4c 89 44 24 40       	mov    QWORD PTR [rsp+0x40],r8
    dcb0:	4c 89 4c 24 48       	mov    QWORD PTR [rsp+0x48],r9
    dcb5:	84 c0                	test   al,al
    dcb7:	74 37                	je     dcf0 <gnutls_reauth@plt+0x46c0>
    dcb9:	0f 29 44 24 50       	movaps XMMWORD PTR [rsp+0x50],xmm0
    dcbe:	0f 29 4c 24 60       	movaps XMMWORD PTR [rsp+0x60],xmm1
    dcc3:	0f 29 54 24 70       	movaps XMMWORD PTR [rsp+0x70],xmm2
    dcc8:	0f 29 9c 24 80 00 00 	movaps XMMWORD PTR [rsp+0x80],xmm3
    dccf:	00 
    dcd0:	0f 29 a4 24 90 00 00 	movaps XMMWORD PTR [rsp+0x90],xmm4
    dcd7:	00 
    dcd8:	0f 29 ac 24 a0 00 00 	movaps XMMWORD PTR [rsp+0xa0],xmm5
    dcdf:	00 
    dce0:	0f 29 b4 24 b0 00 00 	movaps XMMWORD PTR [rsp+0xb0],xmm6
    dce7:	00 
    dce8:	0f 29 bc 24 c0 00 00 	movaps XMMWORD PTR [rsp+0xc0],xmm7
    dcef:	00 
    dcf0:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
    dcf7:	00 00 
    dcf9:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
    dcfe:	31 c0                	xor    eax,eax
    dd00:	48 8b 3d 79 67 01 00 	mov    rdi,QWORD PTR [rip+0x16779]        # 24480 <stdout@GLIBC_2.2.5+0x2198>
    dd07:	4c 89 d2             	mov    rdx,r10
    dd0a:	48 89 e1             	mov    rcx,rsp
    dd0d:	48 8d 84 24 e0 00 00 	lea    rax,[rsp+0xe0]
    dd14:	00 
    dd15:	be 01 00 00 00       	mov    esi,0x1
    dd1a:	c7                   	.byte 0xc7
    dd1b:	04 24                	add    al,0x24
    dd1d:	10 00                	adc    BYTE PTR [rax],al
	...

exec
/bin/bash -lc 'xxd -g 1 -s 0x168f0 -l 0x620 ./target.bin
xxd -g 1 -s 0x16b70 -l 0x2b0 ./target.bin
xxd -g 1 -s 0x18c80 -l 0x120 ./target.bin
objdump -d -M intel --start-address=0x13a80 --stop-address=0x13d10 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:
000168f0: 6e 67 20 74 6f 20 63 61 49 73 73 75 65 72 20 73  ng to caIssuer s
00016900: 65 72 76 65 72 3a 20 25 73 2e 2e 2e 0a 00 00 00  erver: %s.......
00016910: 47 45 54 20 2f 25 73 20 48 54 54 50 2f 31 2e 30  GET /%s HTTP/1.0
00016920: 0d 0a 48 6f 73 74 3a 20 25 73 0d 0a 41 63 63 65  ..Host: %s..Acce
00016930: 70 74 3a 20 2a 2f 2a 0d 0a 43 6f 6e 6e 65 63 74  pt: */*..Connect
00016940: 69 6f 6e 3a 20 63 6c 6f 73 65 0d 0a 0d 0a 00 00  ion: close......
00016950: 43 61 6e 6e 6f 74 20 69 6e 74 65 72 70 72 65 74  Cannot interpret
00016960: 20 48 54 54 50 20 72 65 73 70 6f 6e 73 65 0a 00   HTTP response..
00016970: 45 72 72 6f 72 20 69 6e 20 73 65 74 74 69 6e 67  Error in setting
00016980: 20 70 72 69 6f 72 69 74 69 65 73 3a 20 25 73 0a   priorities: %s.
00016990: 00 00 00 00 00 00 00 00 4e 75 6d 62 65 72 20 6f  ........Number o
000169a0: 66 20 41 4c 50 4e 20 70 72 6f 74 6f 63 6f 6c 73  f ALPN protocols
000169b0: 20 74 6f 6f 20 6c 61 72 67 65 20 28 25 64 29 0a   too large (%d).
000169c0: 00 00 00 00 00 00 00 00 43 61 6e 6e 6f 74 20 73  ........Cannot s
000169d0: 65 74 20 74 68 65 20 6d 61 78 69 6d 75 6d 20 72  et the maximum r
000169e0: 65 63 6f 72 64 20 73 69 7a 65 20 74 6f 20 25 64  ecord size to %d
000169f0: 2e 0a 00 00 00 00 00 00 50 6f 73 73 69 62 6c 65  ........Possible
00016a00: 20 76 61 6c 75 65 73 3a 20 35 31 32 2c 20 31 30   values: 512, 10
00016a10: 32 34 2c 20 32 30 34 38 2c 20 34 30 39 36 2e 0a  24, 2048, 4096..
00016a20: 00 00 00 00 00 00 00 00 2a 2a 2a 20 52 65 63 65  ........*** Rece
00016a30: 69 76 65 64 20 72 65 68 61 6e 64 73 68 61 6b 65  ived rehandshake
00016a40: 20 72 65 71 75 65 73 74 0a 00 00 00 00 00 00 00   request........
00016a50: 2a 2a 2a 20 52 65 68 61 6e 64 73 68 61 6b 65 20  *** Rehandshake 
00016a60: 77 61 73 20 70 65 72 66 6f 72 6d 65 64 2e 0a 00  was performed...
00016a70: 2d 20 50 65 65 72 20 68 61 73 20 63 6c 6f 73 65  - Peer has close
00016a80: 64 20 74 68 65 20 47 6e 75 54 4c 53 20 63 6f 6e  d the GnuTLS con
00016a90: 6e 65 63 74 69 6f 6e 0a 00 00 00 00 00 00 00 00  nection.........
00016aa0: 2a 2a 2a 20 53 65 72 76 65 72 20 68 61 73 20 74  *** Server has t
00016ab0: 65 72 6d 69 6e 61 74 65 64 20 74 68 65 20 63 6f  erminated the co
00016ac0: 6e 6e 65 63 74 69 6f 6e 20 61 62 6e 6f 72 6d 61  nnection abnorma
00016ad0: 6c 6c 79 2e 0a 00 20 20 20 5b 25 64 5d 3a 20 00  lly...   [%d]: .
00016ae0: 77 00 63 6f 75 6c 64 20 6e 6f 74 20 6f 70 65 6e  w.could not open
00016af0: 20 25 73 0a 00 43 45 52 54 49 46 49 43 41 54 45   %s..CERTIFICATE
00016b00: 00 65 72 72 6f 72 5b 25 64 5d 3a 20 25 73 0a 00  .error[%d]: %s..
00016b10: 77 72 69 74 69 6e 67 20 74 6f 20 25 73 20 66 61  writing to %s fa
00016b20: 69 6c 65 64 0a 00 4f 43 53 50 20 52 45 53 50 4f  iled..OCSP RESPO
00016b30: 4e 53 45 00 4e 6f 20 63 65 72 74 69 66 69 63 61  NSE.No certifica
00016b40: 74 65 73 20 66 6f 75 6e 64 21 0a 00 4d 65 6d 6f  tes found!..Memo
00016b50: 72 79 20 65 72 72 6f 72 3a 20 25 73 0a 00 44 65  ry error: %s..De
00016b60: 63 6f 64 69 6e 67 20 65 72 72 6f 72 3a 20 25 73  coding error: %s
00016b70: 0a 00 43 61 6e 6e 6f 74 20 66 69 6e 64 20 69 73  ..Cannot find is
00016b80: 73 75 65 72 3a 20 25 73 0a 00 67 6e 75 74 6c 73  suer: %s..gnutls
00016b90: 5f 72 6e 64 3a 20 25 73 00 43 61 6e 6e 6f 74 20  _rnd: %s.Cannot 
00016ba0: 63 6f 6e 74 61 63 74 20 4f 43 53 50 20 73 65 72  contact OCSP ser
00016bb0: 76 65 72 0a 00 75 64 70 00 74 63 70 00 31 2e 33  ver..udp.tcp.1.3
00016bc0: 2e 36 2e 31 2e 35 2e 35 2e 37 2e 33 2e 31 00 2a  .6.1.5.5.7.3.1.*
00016bd0: 2a 2a 20 4f 43 53 50 3a 20 6e 6f 74 68 69 6e 67  ** OCSP: nothing
00016be0: 20 74 6f 20 63 68 65 63 6b 2e 0a 00 43 6f 75 6c   to check...Coul
00016bf0: 64 20 6e 6f 74 20 73 74 6f 72 65 20 6b 65 79 3a  d not store key:
00016c00: 20 25 73 0a 00 0a 09 00 0a 0a 53 70 65 63 69 61   %s.......Specia
00016c10: 6c 20 73 74 72 69 6e 67 73 3a 0a 00 25 25 25 73  l strings:..%%%s
00016c20: 20 00 2d 20 50 53 4b 20 63 6c 69 65 6e 74 20 63   .- PSK client c
00016c30: 61 6c 6c 62 61 63 6b 2e 20 00 50 53 4b 20 68 69  allback. .PSK hi
00016c40: 6e 74 20 27 25 73 27 0a 00 4e 6f 20 50 53 4b 20  nt '%s'..No PSK 
00016c50: 68 69 6e 74 0a 00 45 6e 74 65 72 20 50 53 4b 20  hint..Enter PSK 
00016c60: 69 64 65 6e 74 69 74 79 3a 20 00 45 6e 74 65 72  identity: .Enter
00016c70: 20 6b 65 79 3a 20 00 4e 6f 20 6b 65 79 20 67 69   key: .No key gi
00016c80: 76 65 6e 2c 20 61 62 6f 72 74 69 6e 67 2e 2e 2e  ven, aborting...
00016c90: 0a 00 45 72 72 6f 72 20 64 65 72 69 76 69 6e 67  ..Error deriving
00016ca0: 20 70 61 73 73 77 6f 72 64 3a 20 25 73 0a 00 45   password: %s..E
00016cb0: 72 72 6f 72 20 69 6e 20 68 65 78 20 65 6e 63 6f  rror in hex enco
00016cc0: 64 69 6e 67 3a 20 25 73 0a 00 50 53 4b 20 75 73  ding: %s..PSK us
00016cd0: 65 72 6e 61 6d 65 3a 20 25 73 0a 00 50 53 4b 20  ername: %s..PSK 
00016ce0: 68 69 6e 74 3a 20 25 73 0a 00 50 53 4b 20 6b 65  hint: %s..PSK ke
00016cf0: 79 3a 20 25 73 0a 00 2a 2a 2a 20 45 72 72 6f 72  y: %s..*** Error
00016d00: 20 6c 6f 61 64 69 6e 67 20 75 72 6c 3a 20 25 73   loading url: %s
00016d10: 0a 00 2a 2a 2a 20 45 72 72 6f 72 20 6c 6f 61 64  ..*** Error load
00016d20: 69 6e 67 20 6b 65 79 20 66 69 6c 65 2e 0a 00 2a  ing key file...*
00016d30: 2a 2a 20 45 72 72 6f 72 20 69 6d 70 6f 72 74 69  ** Error importi
00016d40: 6e 67 20 6b 65 79 3a 20 25 73 0a 00 2a 2a 2a 20  ng key: %s..*** 
00016d50: 45 72 72 6f 72 20 6c 6f 61 64 69 6e 67 20 63 65  Error loading ce
00016d60: 72 74 20 66 69 6c 65 2e 0a 00 50 72 6f 63 65 73  rt file...Proces
00016d70: 73 65 64 20 25 64 20 43 52 4c 28 73 29 2e 0a 00  sed %d CRL(s)...
00016d80: 53 52 50 20 61 75 74 68 65 6e 74 69 63 61 74 69  SRP authenticati
00016d90: 6f 6e 20 65 72 72 6f 72 0a 00 50 53 4b 20 61 75  on error..PSK au
00016da0: 74 68 65 6e 74 69 63 61 74 69 6f 6e 20 65 72 72  thentication err
00016db0: 6f 72 0a 00 2d 20 44 69 73 63 6f 6e 6e 65 63 74  or..- Disconnect
00016dc0: 69 6e 67 0a 00 43 6f 6e 6e 65 63 74 69 6e 67 20  ing..Connecting 
00016dd0: 74 6f 00 6f 63 73 70 5f 72 65 73 70 5f 69 6e 69  to.ocsp_resp_ini
00016de0: 74 3a 20 25 73 0a 00 69 6d 70 6f 72 74 69 6e 67  t: %s..importing
00016df0: 20 72 65 73 70 6f 6e 73 65 3a 20 25 73 0a 00 63   response: %s..c
00016e00: 6c 69 2e 63 00 6c 6f 63 61 6c 5f 62 75 66 66 65  li.c.local_buffe
00016e10: 72 5f 70 74 72 20 21 3d 20 4e 55 4c 4c 00 2a 2a  r_ptr != NULL.**
00016e20: 2a 20 52 65 6b 65 79 20 68 61 73 20 66 61 69 6c  * Rekey has fail
00016e30: 65 64 3a 20 25 73 0a 00 2d 20 52 65 6b 65 79 20  ed: %s..- Rekey 
00016e40: 77 61 73 20 63 6f 6d 70 6c 65 74 65 64 0a 00 68  was completed..h
00016e50: 74 74 70 3a 2f 2f 00 6c 69 62 72 61 72 79 20 69  ttp://.library i
00016e60: 73 20 69 6e 20 46 49 50 53 31 34 30 2d 32 20 6d  s in FIPS140-2 m
00016e70: 6f 64 65 0a 00 73 79 73 74 65 6d 2d 63 6f 6e 66  ode..system-conf
00016e80: 69 67 3a 20 25 73 0a 00 5e 00 4e 6f 20 68 6f 73  ig: %s..^.No hos
00016e90: 74 6e 61 6d 65 20 73 70 65 63 69 66 69 65 64 0a  tname specified.
00016ea0: 00 25 75 00 72 65 63 76 00 0d 0a 0d 0a 00 4d 65  .%u.recv......Me
00016eb0: 6d 6f 72 79 20 65 72 72 6f 72 0a 00 53 79 6e 74  mory error..Synt
00016ec0: 61 78 20 65 72 72 6f 72 20 61 74 3a 20 25 73 0a  ax error at: %s.
00016ed0: 00 45 72 72 6f 72 20 69 6e 20 70 72 69 6f 72 69  .Error in priori
00016ee0: 74 69 65 73 3a 20 25 73 0a 00 45 72 72 6f 72 20  ties: %s..Error 
00016ef0: 69 6e 20 70 72 6f 66 69 6c 65 73 3a 20 25 73 0a  in profiles: %s.
00016f00: 00 44 54 4c 53 20 70 72 6f 66 69 6c 65 20 73 65  .DTLS profile se
00016b70: 0a 00 43 61 6e 6e 6f 74 20 66 69 6e 64 20 69 73  ..Cannot find is
00016b80: 73 75 65 72 3a 20 25 73 0a 00 67 6e 75 74 6c 73  suer: %s..gnutls
00016b90: 5f 72 6e 64 3a 20 25 73 00 43 61 6e 6e 6f 74 20  _rnd: %s.Cannot 
00016ba0: 63 6f 6e 74 61 63 74 20 4f 43 53 50 20 73 65 72  contact OCSP ser
00016bb0: 76 65 72 0a 00 75 64 70 00 74 63 70 00 31 2e 33  ver..udp.tcp.1.3
00016bc0: 2e 36 2e 31 2e 35 2e 35 2e 37 2e 33 2e 31 00 2a  .6.1.5.5.7.3.1.*
00016bd0: 2a 2a 20 4f 43 53 50 3a 20 6e 6f 74 68 69 6e 67  ** OCSP: nothing
00016be0: 20 74 6f 20 63 68 65 63 6b 2e 0a 00 43 6f 75 6c   to check...Coul
00016bf0: 64 20 6e 6f 74 20 73 74 6f 72 65 20 6b 65 79 3a  d not store key:
00016c00: 20 25 73 0a 00 0a 09 00 0a 0a 53 70 65 63 69 61   %s.......Specia
00016c10: 6c 20 73 74 72 69 6e 67 73 3a 0a 00 25 25 25 73  l strings:..%%%s
00016c20: 20 00 2d 20 50 53 4b 20 63 6c 69 65 6e 74 20 63   .- PSK client c
00016c30: 61 6c 6c 62 61 63 6b 2e 20 00 50 53 4b 20 68 69  allback. .PSK hi
00016c40: 6e 74 20 27 25 73 27 0a 00 4e 6f 20 50 53 4b 20  nt '%s'..No PSK 
00016c50: 68 69 6e 74 0a 00 45 6e 74 65 72 20 50 53 4b 20  hint..Enter PSK 
00016c60: 69 64 65 6e 74 69 74 79 3a 20 00 45 6e 74 65 72  identity: .Enter
00016c70: 20 6b 65 79 3a 20 00 4e 6f 20 6b 65 79 20 67 69   key: .No key gi
00016c80: 76 65 6e 2c 20 61 62 6f 72 74 69 6e 67 2e 2e 2e  ven, aborting...
00016c90: 0a 00 45 72 72 6f 72 20 64 65 72 69 76 69 6e 67  ..Error deriving
00016ca0: 20 70 61 73 73 77 6f 72 64 3a 20 25 73 0a 00 45   password: %s..E
00016cb0: 72 72 6f 72 20 69 6e 20 68 65 78 20 65 6e 63 6f  rror in hex enco
00016cc0: 64 69 6e 67 3a 20 25 73 0a 00 50 53 4b 20 75 73  ding: %s..PSK us
00016cd0: 65 72 6e 61 6d 65 3a 20 25 73 0a 00 50 53 4b 20  ername: %s..PSK 
00016ce0: 68 69 6e 74 3a 20 25 73 0a 00 50 53 4b 20 6b 65  hint: %s..PSK ke
00016cf0: 79 3a 20 25 73 0a 00 2a 2a 2a 20 45 72 72 6f 72  y: %s..*** Error
00016d00: 20 6c 6f 61 64 69 6e 67 20 75 72 6c 3a 20 25 73   loading url: %s
00016d10: 0a 00 2a 2a 2a 20 45 72 72 6f 72 20 6c 6f 61 64  ..*** Error load
00016d20: 69 6e 67 20 6b 65 79 20 66 69 6c 65 2e 0a 00 2a  ing key file...*
00016d30: 2a 2a 20 45 72 72 6f 72 20 69 6d 70 6f 72 74 69  ** Error importi
00016d40: 6e 67 20 6b 65 79 3a 20 25 73 0a 00 2a 2a 2a 20  ng key: %s..*** 
00016d50: 45 72 72 6f 72 20 6c 6f 61 64 69 6e 67 20 63 65  Error loading ce
00016d60: 72 74 20 66 69 6c 65 2e 0a 00 50 72 6f 63 65 73  rt file...Proces
00016d70: 73 65 64 20 25 64 20 43 52 4c 28 73 29 2e 0a 00  sed %d CRL(s)...
00016d80: 53 52 50 20 61 75 74 68 65 6e 74 69 63 61 74 69  SRP authenticati
00016d90: 6f 6e 20 65 72 72 6f 72 0a 00 50 53 4b 20 61 75  on error..PSK au
00016da0: 74 68 65 6e 74 69 63 61 74 69 6f 6e 20 65 72 72  thentication err
00016db0: 6f 72 0a 00 2d 20 44 69 73 63 6f 6e 6e 65 63 74  or..- Disconnect
00016dc0: 69 6e 67 0a 00 43 6f 6e 6e 65 63 74 69 6e 67 20  ing..Connecting 
00016dd0: 74 6f 00 6f 63 73 70 5f 72 65 73 70 5f 69 6e 69  to.ocsp_resp_ini
00016de0: 74 3a 20 25 73 0a 00 69 6d 70 6f 72 74 69 6e 67  t: %s..importing
00016df0: 20 72 65 73 70 6f 6e 73 65 3a 20 25 73 0a 00 63   response: %s..c
00016e00: 6c 69 2e 63 00 6c 6f 63 61 6c 5f 62 75 66 66 65  li.c.local_buffe
00016e10: 72 5f 70 74 72 20 21 3d 20 4e 55 4c 4c 00 2a 2a  r_ptr != NULL.**
00018c80: 65 3a 20 00 72 65 61 64 69 6e 67 20 72 65 73 70  e: .reading resp
00018c90: 6f 6e 73 65 3a 20 25 73 0a 00 00 00 00 00 00 00  onse: %s........
00018ca0: 2a 2a 2a 20 43 61 6e 6e 6f 74 20 66 69 6e 64 20  *** Cannot find 
00018cb0: 4f 43 53 50 20 73 65 72 76 65 72 20 55 52 49 20  OCSP server URI 
00018cc0: 69 6e 20 63 65 72 74 69 66 69 63 61 74 65 3a 20  in certificate: 
00018cd0: 25 73 0a 00 00 00 00 00 43 6f 6e 6e 65 63 74 69  %s......Connecti
00018ce0: 6e 67 20 74 6f 20 4f 43 53 50 20 73 65 72 76 65  ng to OCSP serve
00018cf0: 72 3a 20 25 73 2e 2e 2e 0a 00 00 00 00 00 00 00  r: %s...........
00018d00: 50 4f 53 54 20 2f 25 73 20 48 54 54 50 2f 31 2e  POST /%s HTTP/1.
00018d10: 30 0d 0a 48 6f 73 74 3a 20 25 73 0d 0a 41 63 63  0..Host: %s..Acc
00018d20: 65 70 74 3a 20 2a 2f 2a 0d 0a 43 6f 6e 74 65 6e  ept: */*..Conten
00018d30: 74 2d 54 79 70 65 3a 20 61 70 70 6c 69 63 61 74  t-Type: applicat
00018d40: 69 6f 6e 2f 6f 63 73 70 2d 72 65 71 75 65 73 74  ion/ocsp-request
00018d50: 0d 0a 43 6f 6e 74 65 6e 74 2d 4c 65 6e 67 74 68  ..Content-Length
00018d60: 3a 20 25 75 0d 0a 43 6f 6e 6e 65 63 74 69 6f 6e  : %u..Connection
00018d70: 3a 20 63 6c 6f 73 65 0d 0a 0d 0a 00 00 00 00 00  : close.........
00018d80: 2a 2a 2a 20 47 6f 74 20 4f 43 53 50 20 72 65 73  *** Got OCSP res
00018d90: 70 6f 6e 73 65 20 77 69 74 68 20 6e 6f 20 64 61  ponse with no da

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000013a80 <.text+0xa440>:
   13a80:	ff                   	(bad)  
   13a81:	be 04 00 00 00       	mov    esi,0x4
   13a86:	48 8d 3d 83 4f 00 00 	lea    rdi,[rip+0x4f83]        # 18a10 <gnutls_reauth@plt+0xf3e0>
   13a8d:	e8 ce f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13a92:	be 04 00 00 00       	mov    esi,0x4
   13a97:	48 8d 3d ca 4f 00 00 	lea    rdi,[rip+0x4fca]        # 18a68 <gnutls_reauth@plt+0xf438>
   13a9e:	e8 bd f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13aa3:	be 07 00 00 00       	mov    esi,0x7
   13aa8:	48 8d 3d 11 50 00 00 	lea    rdi,[rip+0x5011]        # 18ac0 <gnutls_reauth@plt+0xf490>
   13aaf:	e8 ac f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ab4:	be 01 00 00 00       	mov    esi,0x1
   13ab9:	48 8d 3d 90 4a 00 00 	lea    rdi,[rip+0x4a90]        # 18550 <gnutls_reauth@plt+0xef20>
   13ac0:	e8 9b f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ac5:	be 09 00 00 00       	mov    esi,0x9
   13aca:	48 8d 3d c7 4c 00 00 	lea    rdi,[rip+0x4cc7]        # 18798 <gnutls_reauth@plt+0xf168>
   13ad1:	e8 8a f6 ff ff       	call   13160 <gnutls_reauth@plt+0x9b30>
   13ad6:	e9 29 ff ff ff       	jmp    13a04 <gnutls_reauth@plt+0xa3d4>
   13adb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   13ae0:	41 55                	push   r13
   13ae2:	48 8d 05 1e 31 00 00 	lea    rax,[rip+0x311e]        # 16c07 <gnutls_reauth@plt+0xd5d7>
   13ae9:	41 54                	push   r12
   13aeb:	49 89 d4             	mov    r12,rdx
   13aee:	55                   	push   rbp
   13aef:	48 89 f5             	mov    rbp,rsi
   13af2:	53                   	push   rbx
   13af3:	48 89 fb             	mov    rbx,rdi
   13af6:	48 83 ec 08          	sub    rsp,0x8
   13afa:	c7 06 00 00 00 00    	mov    DWORD PTR [rsi],0x0
   13b00:	48 8d 35 48 33 00 00 	lea    rsi,[rip+0x3348]        # 16e4f <gnutls_reauth@plt+0xd81f>
   13b07:	48 89 02             	mov    QWORD PTR [rdx],rax
   13b0a:	e8 91 51 ff ff       	call   8ca0 <strstr@plt>
   13b0f:	48 85 c0             	test   rax,rax
   13b12:	74 66                	je     13b7a <gnutls_reauth@plt+0xa54a>
   13b14:	4c 8d 2d e5 09 08 00 	lea    r13,[rip+0x809e5]        # 94500 <stdout@GLIBC_2.2.5+0x72218>
   13b1b:	48 8d 48 07          	lea    rcx,[rax+0x7]
   13b1f:	31 c0                	xor    eax,eax
   13b21:	be 00 02 00 00       	mov    esi,0x200
   13b26:	4c 89 ef             	mov    rdi,r13
   13b29:	48 8d 15 66 30 00 00 	lea    rdx,[rip+0x3066]        # 16b96 <gnutls_reauth@plt+0xd566>
   13b30:	e8 0b 49 ff ff       	call   8440 <snprintf@plt>
   13b35:	be 2f 00 00 00       	mov    esi,0x2f
   13b3a:	4c 89 ef             	mov    rdi,r13
   13b3d:	e8 8e 53 ff ff       	call   8ed0 <strchr@plt>
   13b42:	48 85 c0             	test   rax,rax
   13b45:	74 0b                	je     13b52 <gnutls_reauth@plt+0xa522>
   13b47:	c6 00 00             	mov    BYTE PTR [rax],0x0
   13b4a:	48 83 c0 01          	add    rax,0x1
   13b4e:	49 89 04 24          	mov    QWORD PTR [r12],rax
   13b52:	be 3a 00 00 00       	mov    esi,0x3a
   13b57:	4c 89 ef             	mov    rdi,r13
   13b5a:	48 8d 1d 9f 09 08 00 	lea    rbx,[rip+0x8099f]        # 94500 <stdout@GLIBC_2.2.5+0x72218>
   13b61:	e8 6a 53 ff ff       	call   8ed0 <strchr@plt>
   13b66:	48 85 c0             	test   rax,rax
   13b69:	74 0f                	je     13b7a <gnutls_reauth@plt+0xa54a>
   13b6b:	c6 00 00             	mov    BYTE PTR [rax],0x0
   13b6e:	48 8d 78 01          	lea    rdi,[rax+0x1]
   13b72:	e8 d9 51 ff ff       	call   8d50 <atoi@plt>
   13b77:	89 45 00             	mov    DWORD PTR [rbp+0x0],eax
   13b7a:	48 83 c4 08          	add    rsp,0x8
   13b7e:	48 89 d8             	mov    rax,rbx
   13b81:	5b                   	pop    rbx
   13b82:	5d                   	pop    rbp
   13b83:	41 5c                	pop    r12
   13b85:	41 5d                	pop    r13
   13b87:	c3                   	ret    
   13b88:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   13b8f:	00 
   13b90:	55                   	push   rbp
   13b91:	48 89 fd             	mov    rbp,rdi
   13b94:	53                   	push   rbx
   13b95:	48 89 f3             	mov    rbx,rsi
   13b98:	48 83 ec 08          	sub    rsp,0x8
   13b9c:	8b 76 08             	mov    esi,DWORD PTR [rsi+0x8]
   13b9f:	48 01 fe             	add    rsi,rdi
   13ba2:	48 8b 3b             	mov    rdi,QWORD PTR [rbx]
   13ba5:	e8 16 58 ff ff       	call   93c0 <realloc@plt>
   13baa:	48 89 03             	mov    QWORD PTR [rbx],rax
   13bad:	48 85 c0             	test   rax,rax
   13bb0:	74 20                	je     13bd2 <gnutls_reauth@plt+0xa5a2>
   13bb2:	8b 53 08             	mov    edx,DWORD PTR [rbx+0x8]
   13bb5:	48 8d 35 44 0b 08 00 	lea    rsi,[rip+0x80b44]        # 94700 <stdout@GLIBC_2.2.5+0x72418>
   13bbc:	48 8d 3c 10          	lea    rdi,[rax+rdx*1]
   13bc0:	48 89 ea             	mov    rdx,rbp
   13bc3:	e8 78 59 ff ff       	call   9540 <memcpy@plt>
   13bc8:	01 6b 08             	add    DWORD PTR [rbx+0x8],ebp
   13bcb:	48 83 c4 08          	add    rsp,0x8
   13bcf:	5b                   	pop    rbx
   13bd0:	5d                   	pop    rbp
   13bd1:	c3                   	ret    
   13bd2:	48 8b 3d 07 e7 00 00 	mov    rdi,QWORD PTR [rip+0xe707]        # 222e0 <stderr@GLIBC_2.2.5>
   13bd9:	48 8d 15 a8 2c 00 00 	lea    rdx,[rip+0x2ca8]        # 16888 <gnutls_reauth@plt+0xd258>
   13be0:	be 01 00 00 00       	mov    esi,0x1
   13be5:	e8 66 49 ff ff       	call   8550 <__fprintf_chk@plt>
   13bea:	bf 01 00 00 00       	mov    edi,0x1
   13bef:	e8 fc 49 ff ff       	call   85f0 <exit@plt>
   13bf4:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   13bfb:	00 00 00 00 
   13bff:	90                   	nop
   13c00:	f3 0f 1e fa          	endbr64 
   13c04:	41 56                	push   r14
   13c06:	49 89 fe             	mov    r14,rdi
   13c09:	41 55                	push   r13
   13c0b:	49 89 f5             	mov    r13,rsi
   13c0e:	41 54                	push   r12
   13c10:	49 89 cc             	mov    r12,rcx
   13c13:	55                   	push   rbp
   13c14:	48 89 d5             	mov    rbp,rdx
   13c17:	48 83 ec 18          	sub    rsp,0x18
   13c1b:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   13c22:	00 00 
   13c24:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   13c29:	31 c0                	xor    eax,eax
   13c2b:	48 89 e7             	mov    rdi,rsp
   13c2e:	e8 5d 53 ff ff       	call   8f90 <gnutls_ocsp_req_init@plt>
   13c33:	85 c0                	test   eax,eax
   13c35:	78 6c                	js     13ca3 <gnutls_reauth@plt+0xa673>
   13c37:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c3b:	4c 89 f1             	mov    rcx,r14
   13c3e:	4c 89 ea             	mov    rdx,r13
   13c41:	be 03 00 00 00       	mov    esi,0x3
   13c46:	e8 65 57 ff ff       	call   93b0 <gnutls_ocsp_req_add_cert@plt>
   13c4b:	85 c0                	test   eax,eax
   13c4d:	0f 88 96 00 00 00    	js     13ce9 <gnutls_reauth@plt+0xa6b9>
   13c53:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c57:	4d 85 e4             	test   r12,r12
   13c5a:	74 16                	je     13c72 <gnutls_reauth@plt+0xa642>
   13c5c:	31 f6                	xor    esi,esi
   13c5e:	4c 89 e2             	mov    rdx,r12
   13c61:	e8 7a 4b ff ff       	call   87e0 <gnutls_ocsp_req_set_nonce@plt>
   13c66:	85 c0                	test   eax,eax
   13c68:	0f 88 8e 00 00 00    	js     13cfc <gnutls_reauth@plt+0xa6cc>
   13c6e:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c72:	48 89 ee             	mov    rsi,rbp
   13c75:	e8 d6 4f ff ff       	call   8c50 <gnutls_ocsp_req_export@plt>
   13c7a:	85 c0                	test   eax,eax
   13c7c:	75 58                	jne    13cd6 <gnutls_reauth@plt+0xa6a6>
   13c7e:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   13c82:	e8 a9 53 ff ff       	call   9030 <gnutls_ocsp_req_deinit@plt>
   13c87:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   13c8c:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   13c93:	00 00 
   13c95:	75 3a                	jne    13cd1 <gnutls_reauth@plt+0xa6a1>
   13c97:	48 83 c4 18          	add    rsp,0x18
   13c9b:	5d                   	pop    rbp
   13c9c:	41 5c                	pop    r12
   13c9e:	41 5d                	pop    r13
   13ca0:	41 5e                	pop    r14
   13ca2:	c3                   	ret    
   13ca3:	89 c7                	mov    edi,eax
   13ca5:	e8 46 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13caa:	48 8d 15 6e 4e 00 00 	lea    rdx,[rip+0x4e6e]        # 18b1f <gnutls_reauth@plt+0xf4ef>
   13cb1:	48 89 c1             	mov    rcx,rax
   13cb4:	48 8b 3d 25 e6 00 00 	mov    rdi,QWORD PTR [rip+0xe625]        # 222e0 <stderr@GLIBC_2.2.5>
   13cbb:	be 01 00 00 00       	mov    esi,0x1
   13cc0:	31 c0                	xor    eax,eax
   13cc2:	e8 89 48 ff ff       	call   8550 <__fprintf_chk@plt>
   13cc7:	bf 01 00 00 00       	mov    edi,0x1
   13ccc:	e8 1f 49 ff ff       	call   85f0 <exit@plt>
   13cd1:	e8 4a 53 ff ff       	call   9020 <__stack_chk_fail@plt>
   13cd6:	89 c7                	mov    edi,eax
   13cd8:	e8 13 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13cdd:	48 8d 15 7a 4e 00 00 	lea    rdx,[rip+0x4e7a]        # 18b5e <gnutls_reauth@plt+0xf52e>
   13ce4:	48 89 c1             	mov    rcx,rax
   13ce7:	eb cb                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13ce9:	89 c7                	mov    edi,eax
   13ceb:	e8 00 53 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13cf0:	48 8d 15 3a 4e 00 00 	lea    rdx,[rip+0x4e3a]        # 18b31 <gnutls_reauth@plt+0xf501>
   13cf7:	48 89 c1             	mov    rcx,rax
   13cfa:	eb b8                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13cfc:	89 c7                	mov    edi,eax
   13cfe:	e8 ed 52 ff ff       	call   8ff0 <gnutls_strerror@plt>
   13d03:	48 8d 15 3d 4e 00 00 	lea    rdx,[rip+0x4e3d]        # 18b47 <gnutls_reauth@plt+0xf517>
   13d0a:	48 89 c1             	mov    rcx,rax
   13d0d:	eb a5                	jmp    13cb4 <gnutls_reauth@plt+0xa684>
   13d0f:	90                   	nop

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x140f0 --stop-address=0x14680 ./target.bin
objdump -d -M intel --start-address=0x10d80 --stop-address=0x10fa0 ./target.bin
objdump -d -M intel --start-address=0x11250 --stop-address=0x11740 ./target.bin
xxd -g 1 -s 0x16b80 -l 0x30 ./target.bin
xxd -g 1 -s 0x16870 -l 0x40 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

00000000000140f0 <.text+0xaab0>:
   140f0:	f3 0f 1e fa          	endbr64 
   140f4:	53                   	push   rbx
   140f5:	89 fb                	mov    ebx,edi
   140f7:	85 ff                	test   edi,edi
   140f9:	0f 84 51 01 00 00    	je     14250 <gnutls_reauth@plt+0xac20>
   140ff:	31 c0                	xor    eax,eax
   14101:	48 8d 35 6a 4a 00 00 	lea    rsi,[rip+0x4a6a]        # 18b72 <gnutls_reauth@plt+0xf542>
   14108:	bf 01 00 00 00       	mov    edi,0x1
   1410d:	e8 3e 45 ff ff       	call   8650 <__printf_chk@plt>
   14112:	f6 c3 01             	test   bl,0x1
   14115:	74 26                	je     1413d <gnutls_reauth@plt+0xab0d>
   14117:	48 8d 35 13 32 00 00 	lea    rsi,[rip+0x3213]        # 17331 <gnutls_reauth@plt+0xdd01>
   1411e:	bf 01 00 00 00       	mov    edi,0x1
   14123:	31 c0                	xor    eax,eax
   14125:	e8 26 45 ff ff       	call   8650 <__printf_chk@plt>
   1412a:	48 8d 35 51 4a 00 00 	lea    rsi,[rip+0x4a51]        # 18b82 <gnutls_reauth@plt+0xf552>
   14131:	bf 01 00 00 00       	mov    edi,0x1
   14136:	31 c0                	xor    eax,eax
   14138:	e8 13 45 ff ff       	call   8650 <__printf_chk@plt>
   1413d:	f6 c3 02             	test   bl,0x2
   14140:	74 26                	je     14168 <gnutls_reauth@plt+0xab38>
   14142:	48 8d 35 e8 31 00 00 	lea    rsi,[rip+0x31e8]        # 17331 <gnutls_reauth@plt+0xdd01>
   14149:	bf 01 00 00 00       	mov    edi,0x1
   1414e:	31 c0                	xor    eax,eax
   14150:	e8 fb 44 ff ff       	call   8650 <__printf_chk@plt>
   14155:	48 8d 35 3c 4a 00 00 	lea    rsi,[rip+0x4a3c]        # 18b98 <gnutls_reauth@plt+0xf568>
   1415c:	bf 01 00 00 00       	mov    edi,0x1
   14161:	31 c0                	xor    eax,eax
   14163:	e8 e8 44 ff ff       	call   8650 <__printf_chk@plt>
   14168:	f6 c3 04             	test   bl,0x4
   1416b:	74 26                	je     14193 <gnutls_reauth@plt+0xab63>
   1416d:	48 8d 35 bd 31 00 00 	lea    rsi,[rip+0x31bd]        # 17331 <gnutls_reauth@plt+0xdd01>
   14174:	bf 01 00 00 00       	mov    edi,0x1
   14179:	31 c0                	xor    eax,eax
   1417b:	e8 d0 44 ff ff       	call   8650 <__printf_chk@plt>
   14180:	48 8d 35 2c 4a 00 00 	lea    rsi,[rip+0x4a2c]        # 18bb3 <gnutls_reauth@plt+0xf583>
   14187:	bf 01 00 00 00       	mov    edi,0x1
   1418c:	31 c0                	xor    eax,eax
   1418e:	e8 bd 44 ff ff       	call   8650 <__printf_chk@plt>
   14193:	f6 c3 08             	test   bl,0x8
   14196:	0f 84 c7 00 00 00    	je     14263 <gnutls_reauth@plt+0xac33>
   1419c:	48 8d 35 8e 31 00 00 	lea    rsi,[rip+0x318e]        # 17331 <gnutls_reauth@plt+0xdd01>
   141a3:	bf 01 00 00 00       	mov    edi,0x1
   141a8:	31 c0                	xor    eax,eax
   141aa:	e8 a1 44 ff ff       	call   8650 <__printf_chk@plt>
   141af:	31 c0                	xor    eax,eax
   141b1:	bf 01 00 00 00       	mov    edi,0x1
   141b6:	48 8d 35 11 4a 00 00 	lea    rsi,[rip+0x4a11]        # 18bce <gnutls_reauth@plt+0xf59e>
   141bd:	e8 8e 44 ff ff       	call   8650 <__printf_chk@plt>
   141c2:	f6 c3 10             	test   bl,0x10
   141c5:	0f 84 a1 00 00 00    	je     1426c <gnutls_reauth@plt+0xac3c>
   141cb:	48 8d 35 5f 31 00 00 	lea    rsi,[rip+0x315f]        # 17331 <gnutls_reauth@plt+0xdd01>
   141d2:	bf 01 00 00 00       	mov    edi,0x1
   141d7:	31 c0                	xor    eax,eax
   141d9:	e8 72 44 ff ff       	call   8650 <__printf_chk@plt>
   141de:	31 c0                	xor    eax,eax
   141e0:	bf 01 00 00 00       	mov    edi,0x1
   141e5:	48 8d 35 f5 49 00 00 	lea    rsi,[rip+0x49f5]        # 18be1 <gnutls_reauth@plt+0xf5b1>
   141ec:	e8 5f 44 ff ff       	call   8650 <__printf_chk@plt>
   141f1:	f6 c3 20             	test   bl,0x20
   141f4:	74 7b                	je     14271 <gnutls_reauth@plt+0xac41>
   141f6:	48 8d 35 34 31 00 00 	lea    rsi,[rip+0x3134]        # 17331 <gnutls_reauth@plt+0xdd01>
   141fd:	bf 01 00 00 00       	mov    edi,0x1
   14202:	31 c0                	xor    eax,eax
   14204:	e8 47 44 ff ff       	call   8650 <__printf_chk@plt>
   14209:	31 c0                	xor    eax,eax
   1420b:	bf 01 00 00 00       	mov    edi,0x1
   14210:	48 8d 35 dc 49 00 00 	lea    rsi,[rip+0x49dc]        # 18bf3 <gnutls_reauth@plt+0xf5c3>
   14217:	e8 34 44 ff ff       	call   8650 <__printf_chk@plt>
   1421c:	83 e3 40             	and    ebx,0x40
   1421f:	74 55                	je     14276 <gnutls_reauth@plt+0xac46>
   14221:	48 8d 35 09 31 00 00 	lea    rsi,[rip+0x3109]        # 17331 <gnutls_reauth@plt+0xdd01>
   14228:	bf 01 00 00 00       	mov    edi,0x1
   1422d:	31 c0                	xor    eax,eax
   1422f:	e8 1c 44 ff ff       	call   8650 <__printf_chk@plt>
   14234:	48 8d 35 d6 49 00 00 	lea    rsi,[rip+0x49d6]        # 18c11 <gnutls_reauth@plt+0xf5e1>
   1423b:	31 c0                	xor    eax,eax
   1423d:	5b                   	pop    rbx
   1423e:	bf 01 00 00 00       	mov    edi,0x1
   14243:	e9 08 44 ff ff       	jmp    8650 <__printf_chk@plt>
   14248:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1424f:	00 
   14250:	48 8d 35 23 49 00 00 	lea    rsi,[rip+0x4923]        # 18b7a <gnutls_reauth@plt+0xf54a>
   14257:	bf 01 00 00 00       	mov    edi,0x1
   1425c:	31 c0                	xor    eax,eax
   1425e:	e8 ed 43 ff ff       	call   8650 <__printf_chk@plt>
   14263:	f6 c3 10             	test   bl,0x10
   14266:	0f 85 5f ff ff ff    	jne    141cb <gnutls_reauth@plt+0xab9b>
   1426c:	f6 c3 20             	test   bl,0x20
   1426f:	75 85                	jne    141f6 <gnutls_reauth@plt+0xabc6>
   14271:	83 e3 40             	and    ebx,0x40
   14274:	75 ab                	jne    14221 <gnutls_reauth@plt+0xabf1>
   14276:	5b                   	pop    rbx
   14277:	c3                   	ret    
   14278:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1427f:	00 
   14280:	f3 0f 1e fa          	endbr64 
   14284:	41 57                	push   r15
   14286:	49 89 d7             	mov    r15,rdx
   14289:	41 56                	push   r14
   1428b:	49 89 fe             	mov    r14,rdi
   1428e:	31 ff                	xor    edi,edi
   14290:	41 55                	push   r13
   14292:	45 89 c5             	mov    r13d,r8d
   14295:	41 54                	push   r12
   14297:	49 89 cc             	mov    r12,rcx
   1429a:	55                   	push   rbp
   1429b:	48 89 f5             	mov    rbp,rsi
   1429e:	53                   	push   rbx
   1429f:	48 81 ec d8 00 00 00 	sub    rsp,0xd8
   142a6:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   142ad:	00 00 
   142af:	48 89 84 24 c8 00 00 	mov    QWORD PTR [rsp+0xc8],rax
   142b6:	00 
   142b7:	31 c0                	xor    eax,eax
   142b9:	e8 12 53 ff ff       	call   95d0 <time@plt>
   142be:	48 8d 7c 24 10       	lea    rdi,[rsp+0x10]
   142c3:	48 89 c3             	mov    rbx,rax
   142c6:	e8 55 4f ff ff       	call   9220 <gnutls_ocsp_resp_init@plt>
   142cb:	85 c0                	test   eax,eax
   142cd:	0f 88 10 03 00 00    	js     145e3 <gnutls_reauth@plt+0xafb3>
   142d3:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   142d8:	4c 89 fe             	mov    rsi,r15
   142db:	e8 f0 4f ff ff       	call   92d0 <gnutls_ocsp_resp_import@plt>
   142e0:	85 c0                	test   eax,eax
   142e2:	0f 88 cd 02 00 00    	js     145b5 <gnutls_reauth@plt+0xaf85>
   142e8:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   142ed:	31 f6                	xor    esi,esi
   142ef:	4c 89 f2             	mov    rdx,r14
   142f2:	e8 69 52 ff ff       	call   9560 <gnutls_ocsp_resp_check_crt@plt>
   142f7:	85 c0                	test   eax,eax
   142f9:	0f 88 91 01 00 00    	js     14490 <gnutls_reauth@plt+0xae60>
   142ff:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   14304:	31 c9                	xor    ecx,ecx
   14306:	48 8d 54 24 08       	lea    rdx,[rsp+0x8]
   1430b:	48 89 ee             	mov    rsi,rbp
   1430e:	e8 8d 47 ff ff       	call   8aa0 <gnutls_ocsp_resp_verify_direct@plt>
   14313:	85 c0                	test   eax,eax
   14315:	0f 88 db 02 00 00    	js     145f6 <gnutls_reauth@plt+0xafc6>
   1431b:	8b 54 24 08          	mov    edx,DWORD PTR [rsp+0x8]
   1431f:	85 d2                	test   edx,edx
   14321:	0f 85 e9 00 00 00    	jne    14410 <gnutls_reauth@plt+0xade0>
   14327:	48 83 ec 08          	sub    rsp,0x8
   1432b:	45 31 c9             	xor    r9d,r9d
   1432e:	45 31 c0             	xor    r8d,r8d
   14331:	31 c9                	xor    ecx,ecx
   14333:	6a 00                	push   0x0
   14335:	31 d2                	xor    edx,edx
   14337:	31 f6                	xor    esi,esi
   14339:	4c 8d 7c 24 28       	lea    r15,[rsp+0x28]
   1433e:	41 57                	push   r15
   14340:	4c 8d 74 24 40       	lea    r14,[rsp+0x40]
   14345:	41 56                	push   r14
   14347:	48 8d 6c 24 40       	lea    rbp,[rsp+0x40]
   1434c:	55                   	push   rbp
   1434d:	48 8d 44 24 34       	lea    rax,[rsp+0x34]
   14352:	50                   	push   rax
   14353:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   14358:	e8 33 51 ff ff       	call   9490 <gnutls_ocsp_resp_get_single@plt>
   1435d:	48 83 c4 30          	add    rsp,0x30
   14361:	85 c0                	test   eax,eax
   14363:	0f 88 a0 02 00 00    	js     14609 <gnutls_reauth@plt+0xafd9>
   14369:	83 7c 24 0c 01       	cmp    DWORD PTR [rsp+0xc],0x1
   1436e:	0f 84 e4 01 00 00    	je     14558 <gnutls_reauth@plt+0xaf28>
   14374:	48 8b 44 24 28       	mov    rax,QWORD PTR [rsp+0x28]
   14379:	48 83 f8 ff          	cmp    rax,0xffffffffffffffff
   1437d:	0f 84 2d 01 00 00    	je     144b0 <gnutls_reauth@plt+0xae80>
   14383:	48 39 d8             	cmp    rax,rbx
   14386:	0f 8c 84 01 00 00    	jl     14510 <gnutls_reauth@plt+0xaee0>
   1438c:	4d 85 e4             	test   r12,r12
   1438f:	74 53                	je     143e4 <gnutls_reauth@plt+0xadb4>
   14391:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   14396:	31 f6                	xor    esi,esi
   14398:	48 8d 54 24 30       	lea    rdx,[rsp+0x30]
   1439d:	e8 ce 4a ff ff       	call   8e70 <gnutls_ocsp_resp_get_nonce@plt>
   143a2:	83 f8 c8             	cmp    eax,0xffffffc8
   143a5:	0f 84 dd 01 00 00    	je     14588 <gnutls_reauth@plt+0xaf58>
   143ab:	85 c0                	test   eax,eax
   143ad:	0f 88 8d 02 00 00    	js     14640 <gnutls_reauth@plt+0xb010>
   143b3:	41 8b 54 24 08       	mov    edx,DWORD PTR [r12+0x8]
   143b8:	39 54 24 38          	cmp    DWORD PTR [rsp+0x38],edx
   143bc:	0f 85 5a 02 00 00    	jne    1461c <gnutls_reauth@plt+0xafec>
   143c2:	4c 8b 6c 24 30       	mov    r13,QWORD PTR [rsp+0x30]
   143c7:	49 8b 3c 24          	mov    rdi,QWORD PTR [r12]
   143cb:	4c 89 ee             	mov    rsi,r13
   143ce:	e8 ed 4d ff ff       	call   91c0 <memcmp@plt>
   143d3:	85 c0                	test   eax,eax
   143d5:	0f 85 41 02 00 00    	jne    1461c <gnutls_reauth@plt+0xafec>
   143db:	4c 89 ef             	mov    rdi,r13
   143de:	ff 15 c4 de 00 00    	call   QWORD PTR [rip+0xdec4]        # 222a8 <gnutls_free@GNUTLS_3_4>
   143e4:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
   143e9:	48 89 ef             	mov    rdi,rbp
   143ec:	41 bc 01 00 00 00    	mov    r12d,0x1
   143f2:	e8 e9 be ff ff       	call   102e0 <gnutls_reauth@plt+0x6cb0>
   143f7:	48 8d 35 3a 4b 00 00 	lea    rsi,[rip+0x4b3a]        # 18f38 <gnutls_reauth@plt+0xf908>
   143fe:	bf 01 00 00 00       	mov    edi,0x1
   14403:	48 89 c2             	mov    rdx,rax
   14406:	31 c0                	xor    eax,eax
   14408:	e8 43 42 ff ff       	call   8650 <__printf_chk@plt>
   1440d:	eb 42                	jmp    14451 <gnutls_reauth@plt+0xae21>
   1440f:	90                   	nop
   14410:	48 8d 35 4f 48 00 00 	lea    rsi,[rip+0x484f]        # 18c66 <gnutls_reauth@plt+0xf636>
   14417:	bf 01 00 00 00       	mov    edi,0x1
   1441c:	31 c0                	xor    eax,eax
   1441e:	e8 2d 42 ff ff       	call   8650 <__printf_chk@plt>
   14423:	8b 7c 24 08          	mov    edi,DWORD PTR [rsp+0x8]
   14427:	e8 c4 fc ff ff       	call   140f0 <gnutls_reauth@plt+0xaac0>
   1442c:	48 8d 35 4a 29 00 00 	lea    rsi,[rip+0x294a]        # 16d7d <gnutls_reauth@plt+0xd74d>
   14433:	bf 01 00 00 00       	mov    edi,0x1
   14438:	31 c0                	xor    eax,eax
   1443a:	e8 11 42 ff ff       	call   8650 <__printf_chk@plt>
   1443f:	8b 44 24 08          	mov    eax,DWORD PTR [rsp+0x8]
   14443:	85 c0                	test   eax,eax
   14445:	0f 84 dc fe ff ff    	je     14327 <gnutls_reauth@plt+0xacf7>
   1444b:	41 bc ff ff ff ff    	mov    r12d,0xffffffff
   14451:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   14456:	e8 b5 4b ff ff       	call   9010 <gnutls_ocsp_resp_deinit@plt>
   1445b:	48 8b 84 24 c8 00 00 	mov    rax,QWORD PTR [rsp+0xc8]
   14462:	00 
   14463:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1446a:	00 00 
   1446c:	0f 85 3e 01 00 00    	jne    145b0 <gnutls_reauth@plt+0xaf80>
   14472:	48 81 c4 d8 00 00 00 	add    rsp,0xd8
   14479:	44 89 e0             	mov    eax,r12d
   1447c:	5b                   	pop    rbx
   1447d:	5d                   	pop    rbp
   1447e:	41 5c                	pop    r12
   14480:	41 5d                	pop    r13
   14482:	41 5e                	pop    r14
   14484:	41 5f                	pop    r15
   14486:	c3                   	ret    
   14487:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1448e:	00 00 
   14490:	83 f8 c8             	cmp    eax,0xffffffc8
   14493:	74 5b                	je     144f0 <gnutls_reauth@plt+0xaec0>
   14495:	48 8d 35 14 49 00 00 	lea    rsi,[rip+0x4914]        # 18db0 <gnutls_reauth@plt+0xf780>
   1449c:	bf 01 00 00 00       	mov    edi,0x1
   144a1:	31 c0                	xor    eax,eax
   144a3:	41 bc ff ff ff ff    	mov    r12d,0xffffffff
   144a9:	e8 a2 41 ff ff       	call   8650 <__printf_chk@plt>
   144ae:	eb a1                	jmp    14451 <gnutls_reauth@plt+0xae21>
   144b0:	48 2b 5c 24 20       	sub    rbx,QWORD PTR [rsp+0x20]
   144b5:	48 81 fb 80 f4 03 00 	cmp    rbx,0x3f480
   144bc:	0f 8e ca fe ff ff    	jle    1438c <gnutls_reauth@plt+0xad5c>
   144c2:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
   144c7:	48 89 ef             	mov    rdi,rbp
   144ca:	41 bc ff ff ff ff    	mov    r12d,0xffffffff
   144d0:	e8 0b be ff ff       	call   102e0 <gnutls_reauth@plt+0x6cb0>
   144d5:	48 8d 35 3c 49 00 00 	lea    rsi,[rip+0x493c]        # 18e18 <gnutls_reauth@plt+0xf7e8>
   144dc:	bf 01 00 00 00       	mov    edi,0x1
   144e1:	48 89 c2             	mov    rdx,rax
   144e4:	31 c0                	xor    eax,eax
   144e6:	e8 65 41 ff ff       	call   8650 <__printf_chk@plt>
   144eb:	e9 61 ff ff ff       	jmp    14451 <gnutls_reauth@plt+0xae21>
   144f0:	48 8d 35 89 48 00 00 	lea    rsi,[rip+0x4889]        # 18d80 <gnutls_reauth@plt+0xf750>
   144f7:	bf 01 00 00 00       	mov    edi,0x1
   144fc:	31 c0                	xor    eax,eax
   144fe:	41 bc ff ff ff ff    	mov    r12d,0xffffffff
   14504:	e8 47 41 ff ff       	call   8650 <__printf_chk@plt>
   14509:	e9 43 ff ff ff       	jmp    14451 <gnutls_reauth@plt+0xae21>
   1450e:	66 90                	xchg   ax,ax
   14510:	48 8d b4 24 80 00 00 	lea    rsi,[rsp+0x80]
   14517:	00 
   14518:	4c 89 f7             	mov    rdi,r14
   1451b:	e8 c0 bd ff ff       	call   102e0 <gnutls_reauth@plt+0x6cb0>
   14520:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
   14525:	48 89 ef             	mov    rdi,rbp
   14528:	49 89 c4             	mov    r12,rax
   1452b:	e8 b0 bd ff ff       	call   102e0 <gnutls_reauth@plt+0x6cb0>
   14530:	4c 89 e1             	mov    rcx,r12
   14533:	bf 01 00 00 00       	mov    edi,0x1
   14538:	48 8d 35 19 49 00 00 	lea    rsi,[rip+0x4919]        # 18e58 <gnutls_reauth@plt+0xf828>
   1453f:	48 89 c2             	mov    rdx,rax
   14542:	31 c0                	xor    eax,eax
   14544:	41 bc ff ff ff ff    	mov    r12d,0xffffffff
   1454a:	e8 01 41 ff ff       	call   8650 <__printf_chk@plt>
   1454f:	e9 fd fe ff ff       	jmp    14451 <gnutls_reauth@plt+0xae21>
   14554:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   14558:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
   1455d:	4c 89 ff             	mov    rdi,r15
   14560:	45 31 e4             	xor    r12d,r12d
   14563:	e8 78 bd ff ff       	call   102e0 <gnutls_reauth@plt+0x6cb0>
   14568:	48 8d 35 81 48 00 00 	lea    rsi,[rip+0x4881]        # 18df0 <gnutls_reauth@plt+0xf7c0>
   1456f:	bf 01 00 00 00       	mov    edi,0x1
   14574:	48 89 c2             	mov    rdx,rax
   14577:	31 c0                	xor    eax,eax
   14579:	e8 d2 40 ff ff       	call   8650 <__printf_chk@plt>
   1457e:	e9 ce fe ff ff       	jmp    14451 <gnutls_reauth@plt+0xae21>
   14583:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   14588:	45 85 ed             	test   r13d,r13d
   1458b:	0f 84 53 fe ff ff    	je     143e4 <gnutls_reauth@plt+0xadb4>
   14591:	48 8b 3d 48 dd 00 00 	mov    rdi,QWORD PTR [rip+0xdd48]        # 222e0 <stderr@GLIBC_2.2.5>
   14598:	48 8d 15 09 49 00 00 	lea    rdx,[rip+0x4909]        # 18ea8 <gnutls_reauth@plt+0xf878>
   1459f:	be 01 00 00 00       	mov    esi,0x1
   145a4:	31 c0                	xor    eax,eax
   145a6:	e8 a5 3f ff ff       	call   8550 <__fprintf_chk@plt>
   145ab:	e9 34 fe ff ff       	jmp    143e4 <gnutls_reauth@plt+0xadb4>
   145b0:	e8 6b 4a ff ff       	call   9020 <__stack_chk_fail@plt>
   145b5:	89 c7                	mov    edi,eax
   145b7:	e8 34 4a ff ff       	call   8ff0 <gnutls_strerror@plt>
   145bc:	48 8d 15 75 46 00 00 	lea    rdx,[rip+0x4675]        # 18c38 <gnutls_reauth@plt+0xf608>
   145c3:	48 89 c1             	mov    rcx,rax
   145c6:	48 8b 3d 13 dd 00 00 	mov    rdi,QWORD PTR [rip+0xdd13]        # 222e0 <stderr@GLIBC_2.2.5>
   145cd:	be 01 00 00 00       	mov    esi,0x1
   145d2:	31 c0                	xor    eax,eax
   145d4:	e8 77 3f ff ff       	call   8550 <__fprintf_chk@plt>
   145d9:	bf 01 00 00 00       	mov    edi,0x1
   145de:	e8 0d 40 ff ff       	call   85f0 <exit@plt>
   145e3:	89 c7                	mov    edi,eax
   145e5:	e8 06 4a ff ff       	call   8ff0 <gnutls_strerror@plt>
   145ea:	48 8d 15 34 46 00 00 	lea    rdx,[rip+0x4634]        # 18c25 <gnutls_reauth@plt+0xf5f5>
   145f1:	48 89 c1             	mov    rcx,rax
   145f4:	eb d0                	jmp    145c6 <gnutls_reauth@plt+0xaf96>
   145f6:	89 c7                	mov    edi,eax
   145f8:	e8 f3 49 ff ff       	call   8ff0 <gnutls_strerror@plt>
   145fd:	48 8d 15 4b 46 00 00 	lea    rdx,[rip+0x464b]        # 18c4f <gnutls_reauth@plt+0xf61f>
   14604:	48 89 c1             	mov    rcx,rax
   14607:	eb bd                	jmp    145c6 <gnutls_reauth@plt+0xaf96>
   14609:	89 c7                	mov    edi,eax
   1460b:	e8 e0 49 ff ff       	call   8ff0 <gnutls_strerror@plt>
   14610:	48 8d 15 6d 46 00 00 	lea    rdx,[rip+0x466d]        # 18c84 <gnutls_reauth@plt+0xf654>
   14617:	48 89 c1             	mov    rcx,rax
   1461a:	eb aa                	jmp    145c6 <gnutls_reauth@plt+0xaf96>
   1461c:	48 8b 3d bd dc 00 00 	mov    rdi,QWORD PTR [rip+0xdcbd]        # 222e0 <stderr@GLIBC_2.2.5>
   14623:	48 8d 15 e6 48 00 00 	lea    rdx,[rip+0x48e6]        # 18f10 <gnutls_reauth@plt+0xf8e0>
   1462a:	be 01 00 00 00       	mov    esi,0x1
   1462f:	31 c0                	xor    eax,eax
   14631:	e8 1a 3f ff ff       	call   8550 <__fprintf_chk@plt>
   14636:	bf 01 00 00 00       	mov    edi,0x1
   1463b:	e8 b0 3f ff ff       	call   85f0 <exit@plt>
   14640:	89 c7                	mov    edi,eax
   14642:	e8 a9 49 ff ff       	call   8ff0 <gnutls_strerror@plt>
   14647:	48 8d 15 9a 48 00 00 	lea    rdx,[rip+0x489a]        # 18ee8 <gnutls_reauth@plt+0xf8b8>
   1464e:	48 89 c1             	mov    rcx,rax
   14651:	e9 70 ff ff ff       	jmp    145c6 <gnutls_reauth@plt+0xaf96>
   14656:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1465d:	00 00 00 
   14660:	41 55                	push   r13
   14662:	41 54                	push   r12
   14664:	49 89 fc             	mov    r12,rdi
   14667:	53                   	push   rbx
   14668:	48 83 ec 10          	sub    rsp,0x10
   1466c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   14673:	00 00 
   14675:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1467a:	31 c0                	xor    eax,eax
   1467c:	48                   	rex.W
   1467d:	c7                   	.byte 0xc7
   1467e:	04 24                	add    al,0x24

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000010d80 <.text+0x7740>:
   10d80:	31 c0                	xor    eax,eax
   10d82:	e8 09 cf ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   10d87:	eb 9f                	jmp    10d28 <gnutls_reauth@plt+0x76f8>
   10d89:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   10d90:	f3 0f 1e fa          	endbr64 
   10d94:	41 54                	push   r12
   10d96:	49 89 f4             	mov    r12,rsi
   10d99:	55                   	push   rbp
   10d9a:	48 63 ea             	movsxd rbp,edx
   10d9d:	53                   	push   rbx
   10d9e:	8b 47 10             	mov    eax,DWORD PTR [rdi+0x10]
   10da1:	48 89 fb             	mov    rbx,rdi
   10da4:	85 c0                	test   eax,eax
   10da6:	74 3a                	je     10de2 <gnutls_reauth@plt+0x77b2>
   10da8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   10daf:	00 
   10db0:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10db4:	48 89 ea             	mov    rdx,rbp
   10db7:	4c 89 e6             	mov    rsi,r12
   10dba:	e8 21 77 ff ff       	call   84e0 <gnutls_record_recv@plt>
   10dbf:	89 c2                	mov    edx,eax
   10dc1:	3d db fe ff ff       	cmp    eax,0xfffffedb
   10dc6:	74 38                	je     10e00 <gnutls_reauth@plt+0x77d0>
   10dc8:	83 f8 cc             	cmp    eax,0xffffffcc
   10dcb:	74 e3                	je     10db0 <gnutls_reauth@plt+0x7780>
   10dcd:	5b                   	pop    rbx
   10dce:	48 63 c2             	movsxd rax,edx
   10dd1:	5d                   	pop    rbp
   10dd2:	41 5c                	pop    r12
   10dd4:	c3                   	ret    
   10dd5:	0f 1f 00             	nop    DWORD PTR [rax]
   10dd8:	e8 c3 81 ff ff       	call   8fa0 <__errno_location@plt>
   10ddd:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10de0:	75 2e                	jne    10e10 <gnutls_reauth@plt+0x77e0>
   10de2:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10de4:	48 89 ea             	mov    rdx,rbp
   10de7:	31 c9                	xor    ecx,ecx
   10de9:	4c 89 e6             	mov    rsi,r12
   10dec:	e8 cf 79 ff ff       	call   87c0 <recv@plt>
   10df1:	89 c2                	mov    edx,eax
   10df3:	83 f8 ff             	cmp    eax,0xffffffff
   10df6:	74 e0                	je     10dd8 <gnutls_reauth@plt+0x77a8>
   10df8:	eb d3                	jmp    10dcd <gnutls_reauth@plt+0x779d>
   10dfa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10e00:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e04:	31 f6                	xor    esi,esi
   10e06:	e8 55 75 ff ff       	call   8360 <gnutls_heartbeat_pong@plt>
   10e0b:	eb a3                	jmp    10db0 <gnutls_reauth@plt+0x7780>
   10e0d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e10:	5b                   	pop    rbx
   10e11:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   10e18:	5d                   	pop    rbp
   10e19:	41 5c                	pop    r12
   10e1b:	c3                   	ret    
   10e1c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10e20:	f3 0f 1e fa          	endbr64 
   10e24:	55                   	push   rbp
   10e25:	48 89 f5             	mov    rbp,rsi
   10e28:	53                   	push   rbx
   10e29:	48 89 fb             	mov    rbx,rdi
   10e2c:	48 83 ec 18          	sub    rsp,0x18
   10e30:	8b 77 10             	mov    esi,DWORD PTR [rdi+0x10]
   10e33:	85 f6                	test   esi,esi
   10e35:	75 29                	jne    10e60 <gnutls_reauth@plt+0x7830>
   10e37:	48 89 ee             	mov    rsi,rbp
   10e3a:	48 89 df             	mov    rdi,rbx
   10e3d:	e8 4e ff ff ff       	call   10d90 <gnutls_reauth@plt+0x7760>
   10e42:	48 89 c5             	mov    rbp,rax
   10e45:	8b 43 10             	mov    eax,DWORD PTR [rbx+0x10]
   10e48:	85 c0                	test   eax,eax
   10e4a:	75 2c                	jne    10e78 <gnutls_reauth@plt+0x7848>
   10e4c:	48 83 c4 18          	add    rsp,0x18
   10e50:	48 63 c5             	movsxd rax,ebp
   10e53:	5b                   	pop    rbx
   10e54:	5d                   	pop    rbp
   10e55:	c3                   	ret    
   10e56:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   10e5d:	00 00 00 
   10e60:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
   10e64:	89 ce                	mov    esi,ecx
   10e66:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   10e6a:	e8 31 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e6f:	8b 54 24 0c          	mov    edx,DWORD PTR [rsp+0xc]
   10e73:	eb c2                	jmp    10e37 <gnutls_reauth@plt+0x7807>
   10e75:	0f 1f 00             	nop    DWORD PTR [rax]
   10e78:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e7c:	31 f6                	xor    esi,esi
   10e7e:	e8 1d 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e83:	48 83 c4 18          	add    rsp,0x18
   10e87:	48 63 c5             	movsxd rax,ebp
   10e8a:	5b                   	pop    rbx
   10e8b:	5d                   	pop    rbp
   10e8c:	c3                   	ret    
   10e8d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e90:	f3 0f 1e fa          	endbr64 
   10e94:	41 56                	push   r14
   10e96:	49 89 ce             	mov    r14,rcx
   10e99:	41 55                	push   r13
   10e9b:	41 54                	push   r12
   10e9d:	4c 63 e2             	movsxd r12,edx
   10ea0:	55                   	push   rbp
   10ea1:	4d 89 e5             	mov    r13,r12
   10ea4:	48 89 f5             	mov    rbp,rsi
   10ea7:	53                   	push   rbx
   10ea8:	8b 57 10             	mov    edx,DWORD PTR [rdi+0x10]
   10eab:	48 89 fb             	mov    rbx,rdi
   10eae:	85 d2                	test   edx,edx
   10eb0:	74 58                	je     10f0a <gnutls_reauth@plt+0x78da>
   10eb2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10eb8:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10ebc:	4d 85 f6             	test   r14,r14
   10ebf:	74 67                	je     10f28 <gnutls_reauth@plt+0x78f8>
   10ec1:	4c 89 f1             	mov    rcx,r14
   10ec4:	4c 89 e2             	mov    rdx,r12
   10ec7:	48 89 ee             	mov    rsi,rbp
   10eca:	e8 01 7a ff ff       	call   88d0 <gnutls_record_send_range@plt>
   10ecf:	89 c1                	mov    ecx,eax
   10ed1:	83 f9 e4             	cmp    ecx,0xffffffe4
   10ed4:	74 e2                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10ed6:	83 f9 cc             	cmp    ecx,0xffffffcc
   10ed9:	74 dd                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10edb:	4c 63 e1             	movsxd r12,ecx
   10ede:	85 c9                	test   ecx,ecx
   10ee0:	7e 0c                	jle    10eee <gnutls_reauth@plt+0x78be>
   10ee2:	44 39 e9             	cmp    ecx,r13d
   10ee5:	74 07                	je     10eee <gnutls_reauth@plt+0x78be>
   10ee7:	8b 43 48             	mov    eax,DWORD PTR [rbx+0x48]
   10eea:	85 c0                	test   eax,eax
   10eec:	75 6a                	jne    10f58 <gnutls_reauth@plt+0x7928>
   10eee:	5b                   	pop    rbx
   10eef:	4c 89 e0             	mov    rax,r12
   10ef2:	5d                   	pop    rbp
   10ef3:	41 5c                	pop    r12
   10ef5:	41 5d                	pop    r13
   10ef7:	41 5e                	pop    r14
   10ef9:	c3                   	ret    
   10efa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f00:	e8 9b 80 ff ff       	call   8fa0 <__errno_location@plt>
   10f05:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10f08:	75 36                	jne    10f40 <gnutls_reauth@plt+0x7910>
   10f0a:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10f0c:	31 c9                	xor    ecx,ecx
   10f0e:	4c 89 e2             	mov    rdx,r12
   10f11:	48 89 ee             	mov    rsi,rbp
   10f14:	e8 07 82 ff ff       	call   9120 <send@plt>
   10f19:	89 c1                	mov    ecx,eax
   10f1b:	83 f8 ff             	cmp    eax,0xffffffff
   10f1e:	74 e0                	je     10f00 <gnutls_reauth@plt+0x78d0>
   10f20:	eb b9                	jmp    10edb <gnutls_reauth@plt+0x78ab>
   10f22:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f28:	4c 89 e2             	mov    rdx,r12
   10f2b:	48 89 ee             	mov    rsi,rbp
   10f2e:	e8 ad 80 ff ff       	call   8fe0 <gnutls_record_send@plt>
   10f33:	89 c1                	mov    ecx,eax
   10f35:	eb 9a                	jmp    10ed1 <gnutls_reauth@plt+0x78a1>
   10f37:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   10f3e:	00 00 
   10f40:	49 c7 c4 ff ff ff ff 	mov    r12,0xffffffffffffffff
   10f47:	5b                   	pop    rbx
   10f48:	5d                   	pop    rbp
   10f49:	4c 89 e0             	mov    rax,r12
   10f4c:	41 5c                	pop    r12
   10f4e:	41 5d                	pop    r13
   10f50:	41 5e                	pop    r14
   10f52:	c3                   	ret    
   10f53:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   10f58:	48 8b 3d 81 13 01 00 	mov    rdi,QWORD PTR [rip+0x11381]        # 222e0 <stderr@GLIBC_2.2.5>
   10f5f:	45 89 e8             	mov    r8d,r13d
   10f62:	be 01 00 00 00       	mov    esi,0x1
   10f67:	31 c0                	xor    eax,eax
   10f69:	48 8d 15 80 6d 00 00 	lea    rdx,[rip+0x6d80]        # 17cf0 <gnutls_reauth@plt+0xe6c0>
   10f70:	e8 db 75 ff ff       	call   8550 <__fprintf_chk@plt>
   10f75:	5b                   	pop    rbx
   10f76:	4c 89 e0             	mov    rax,r12
   10f79:	5d                   	pop    rbp
   10f7a:	41 5c                	pop    r12
   10f7c:	41 5d                	pop    r13
   10f7e:	41 5e                	pop    r14
   10f80:	c3                   	ret    
   10f81:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   10f88:	00 00 00 00 
   10f8c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10f90:	f3 0f 1e fa          	endbr64 
   10f94:	31 c9                	xor    ecx,ecx
   10f96:	e9 f5 fe ff ff       	jmp    10e90 <gnutls_reauth@plt+0x7860>
   10f9b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000011250 <.text+0x7c10>:
   11250:	f3 0f 1e fa          	endbr64 
   11254:	41 57                	push   r15
   11256:	41 56                	push   r14
   11258:	41 55                	push   r13
   1125a:	41 54                	push   r12
   1125c:	55                   	push   rbp
   1125d:	53                   	push   rbx
   1125e:	48 81 ec 00 10 00 00 	sub    rsp,0x1000
   11265:	48 83 0c 24 00       	or     QWORD PTR [rsp],0x0
   1126a:	48 81 ec b8 00 00 00 	sub    rsp,0xb8
   11271:	66 0f ef c0          	pxor   xmm0,xmm0
   11275:	48 8b 84 24 00 11 00 	mov    rax,QWORD PTR [rsp+0x1100]
   1127c:	00 
   1127d:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   11282:	48 89 fb             	mov    rbx,rdi
   11285:	48 89 d5             	mov    rbp,rdx
   11288:	48 83 c7 08          	add    rdi,0x8
   1128c:	48 8b 84 24 08 11 00 	mov    rax,QWORD PTR [rsp+0x1108]
   11293:	00 
   11294:	48 89 74 24 10       	mov    QWORD PTR [rsp+0x10],rsi
   11299:	45 89 c5             	mov    r13d,r8d
   1129c:	48 89 4c 24 38       	mov    QWORD PTR [rsp+0x38],rcx
   112a1:	48 89 d9             	mov    rcx,rbx
   112a4:	41 83 e5 01          	and    r13d,0x1
   112a8:	48 8b b4 24 f0 10 00 	mov    rsi,QWORD PTR [rsp+0x10f0]
   112af:	00 
   112b0:	44 89 44 24 0c       	mov    DWORD PTR [rsp+0xc],r8d
   112b5:	48 8b 94 24 f8 10 00 	mov    rdx,QWORD PTR [rsp+0x10f8]
   112bc:	00 
   112bd:	4c 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],r9
   112c2:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   112c7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   112ce:	00 00 
   112d0:	48 89 84 24 a8 10 00 	mov    QWORD PTR [rsp+0x10a8],rax
   112d7:	00 
   112d8:	31 c0                	xor    eax,eax
   112da:	44 89 c0             	mov    eax,r8d
   112dd:	0f 29 84 24 90 00 00 	movaps XMMWORD PTR [rsp+0x90],xmm0
   112e4:	00 
   112e5:	83 e0 02             	and    eax,0x2
   112e8:	89 44 24 20          	mov    DWORD PTR [rsp+0x20],eax
   112ec:	31 c0                	xor    eax,eax
   112ee:	48 c7 47 f8 00 00 00 	mov    QWORD PTR [rdi-0x8],0x0
   112f5:	00 
   112f6:	48 c7 87 f8 00 00 00 	mov    QWORD PTR [rdi+0xf8],0x0
   112fd:	00 00 00 00 
   11301:	48 83 e7 f8          	and    rdi,0xfffffffffffffff8
   11305:	48 29 f9             	sub    rcx,rdi
   11308:	81 c1 08 01 00 00    	add    ecx,0x108
   1130e:	c1 e9 03             	shr    ecx,0x3
   11311:	41 83 e0 10          	and    r8d,0x10
   11315:	f3 48 ab             	rep stos QWORD PTR es:[rdi],rax
   11318:	74 07                	je     11321 <gnutls_reauth@plt+0x7cf1>
   1131a:	c7 43 48 01 00 00 00 	mov    DWORD PTR [rbx+0x48],0x1
   11321:	48 85 f6             	test   rsi,rsi
   11324:	74 13                	je     11339 <gnutls_reauth@plt+0x7d09>
   11326:	48 8b 06             	mov    rax,QWORD PTR [rsi]
   11329:	48 89 83 e8 00 00 00 	mov    QWORD PTR [rbx+0xe8],rax
   11330:	8b 46 08             	mov    eax,DWORD PTR [rsi+0x8]
   11333:	89 83 f0 00 00 00    	mov    DWORD PTR [rbx+0xf0],eax
   11339:	48 85 d2             	test   rdx,rdx
   1133c:	74 13                	je     11351 <gnutls_reauth@plt+0x7d21>
   1133e:	48 8b 02             	mov    rax,QWORD PTR [rdx]
   11341:	48 89 83 f8 00 00 00 	mov    QWORD PTR [rbx+0xf8],rax
   11348:	8b 42 08             	mov    eax,DWORD PTR [rdx+0x8]
   1134b:	89 83 00 01 00 00    	mov    DWORD PTR [rbx+0x100],eax
   11351:	4c 8b 74 24 10       	mov    r14,QWORD PTR [rsp+0x10]
   11356:	4c 89 f7             	mov    rdi,r14
   11359:	e8 e2 76 ff ff       	call   8a40 <strlen@plt>
   1135e:	31 c9                	xor    ecx,ecx
   11360:	48 8d 54 24 50       	lea    rdx,[rsp+0x50]
   11365:	4c 89 f7             	mov    rdi,r14
   11368:	89 c6                	mov    esi,eax
   1136a:	e8 a1 71 ff ff       	call   8510 <gnutls_idna_map@plt>
   1136f:	85 c0                	test   eax,eax
   11371:	0f 88 1b 05 00 00    	js     11892 <gnutls_reauth@plt+0x8262>
   11377:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1137c:	e8 3f 7c ff ff       	call   8fc0 <strdup@plt>
   11381:	48 83 7c 24 18 00    	cmp    QWORD PTR [rsp+0x18],0x0
   11387:	4c 8b 74 24 50       	mov    r14,QWORD PTR [rsp+0x50]
   1138c:	48 89 43 18          	mov    QWORD PTR [rbx+0x18],rax
   11390:	74 1b                	je     113ad <gnutls_reauth@plt+0x7d7d>
   11392:	48 8b 3d 4f 0f 01 00 	mov    rdi,QWORD PTR [rip+0x10f4f]        # 222e8 <stdout@GLIBC_2.2.5>
   11399:	48 89 e9             	mov    rcx,rbp
   1139c:	4c 89 f2             	mov    rdx,r14
   1139f:	31 c0                	xor    eax,eax
   113a1:	48 8d 35 bd 6c 00 00 	lea    rsi,[rip+0x6cbd]        # 18065 <gnutls_reauth@plt+0xea35>
   113a8:	e8 e3 c8 ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   113ad:	66 0f ef c0          	pxor   xmm0,xmm0
   113b1:	48 8d 54 24 60       	lea    rdx,[rsp+0x60]
   113b6:	41 83 c5 01          	add    r13d,0x1
   113ba:	48 89 ee             	mov    rsi,rbp
   113bd:	48 8d 4c 24 48       	lea    rcx,[rsp+0x48]
   113c2:	4c 89 f7             	mov    rdi,r14
   113c5:	0f 29 44 24 60       	movaps XMMWORD PTR [rsp+0x60],xmm0
   113ca:	0f 29 44 24 70       	movaps XMMWORD PTR [rsp+0x70],xmm0
   113cf:	44 89 6c 24 68       	mov    DWORD PTR [rsp+0x68],r13d
   113d4:	0f 29 84 24 80 00 00 	movaps XMMWORD PTR [rsp+0x80],xmm0
   113db:	00 
   113dc:	e8 8f 72 ff ff       	call   8670 <getaddrinfo@plt>
   113e1:	41 89 c7             	mov    r15d,eax
   113e4:	85 c0                	test   eax,eax
   113e6:	0f 85 0d 05 00 00    	jne    118f9 <gnutls_reauth@plt+0x82c9>
   113ec:	4c 8b 64 24 48       	mov    r12,QWORD PTR [rsp+0x48]
   113f1:	4d 85 e4             	test   r12,r12
   113f4:	0f 84 26 04 00 00    	je     11820 <gnutls_reauth@plt+0x81f0>
   113fa:	41 8b 54 24 0c       	mov    edx,DWORD PTR [r12+0xc]
   113ff:	41 8b 74 24 08       	mov    esi,DWORD PTR [r12+0x8]
   11404:	41 8b 7c 24 04       	mov    edi,DWORD PTR [r12+0x4]
   11409:	e8 e2 7a ff ff       	call   8ef0 <socket@plt>
   1140e:	89 c5                	mov    ebp,eax
   11410:	83 f8 ff             	cmp    eax,0xffffffff
   11413:	0f 84 62 02 00 00    	je     1167b <gnutls_reauth@plt+0x804b>
   11419:	41 8b 74 24 10       	mov    esi,DWORD PTR [r12+0x10]
   1141e:	49 8b 7c 24 18       	mov    rdi,QWORD PTR [r12+0x18]
   11423:	b9 00 10 00 00       	mov    ecx,0x1000
   11428:	4c 8d ac 24 90 00 00 	lea    r13,[rsp+0x90]
   1142f:	00 
   11430:	4c 8d b4 24 a0 00 00 	lea    r14,[rsp+0xa0]
   11437:	00 
   11438:	48 83 ec 08          	sub    rsp,0x8
   1143c:	41 b9 10 00 00 00    	mov    r9d,0x10
   11442:	4d 89 e8             	mov    r8,r13
   11445:	6a 03                	push   0x3
   11447:	4c 89 f2             	mov    rdx,r14
   1144a:	e8 f1 7b ff ff       	call   9040 <getnameinfo@plt>
   1144f:	5e                   	pop    rsi
   11450:	5f                   	pop    rdi
   11451:	41 89 c7             	mov    r15d,eax
   11454:	85 c0                	test   eax,eax
   11456:	0f 85 f4 01 00 00    	jne    11650 <gnutls_reauth@plt+0x8020>
   1145c:	83 7c 24 68 02       	cmp    DWORD PTR [rsp+0x68],0x2
   11461:	0f 84 69 03 00 00    	je     117d0 <gnutls_reauth@plt+0x81a0>
   11467:	8b 4c 24 20          	mov    ecx,DWORD PTR [rsp+0x20]
   1146b:	85 c9                	test   ecx,ecx
   1146d:	74 0c                	je     1147b <gnutls_reauth@plt+0x7e4b>
   1146f:	41 83 7c 24 08 01    	cmp    DWORD PTR [r12+0x8],0x1
   11475:	0f 84 55 02 00 00    	je     116d0 <gnutls_reauth@plt+0x80a0>
   1147b:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   11480:	48 85 c0             	test   rax,rax
   11483:	74 1e                	je     114a3 <gnutls_reauth@plt+0x7e73>
   11485:	48 8b 3d 5c 0e 01 00 	mov    rdi,QWORD PTR [rip+0x10e5c]        # 222e8 <stdout@GLIBC_2.2.5>
   1148c:	48 89 c2             	mov    rdx,rax
   1148f:	4d 89 e8             	mov    r8,r13
   11492:	4c 89 f1             	mov    rcx,r14
   11495:	48 8d 35 3a 6c 00 00 	lea    rsi,[rip+0x6c3a]        # 180d6 <gnutls_reauth@plt+0xeaa6>
   1149c:	31 c0                	xor    eax,eax
   1149e:	e8 ed c7 ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   114a3:	41 8b 54 24 10       	mov    edx,DWORD PTR [r12+0x10]
   114a8:	49 8b 74 24 18       	mov    rsi,QWORD PTR [r12+0x18]
   114ad:	89 ef                	mov    edi,ebp
   114af:	e8 ac 78 ff ff       	call   8d60 <connect@plt>
   114b4:	41 89 c7             	mov    r15d,eax
   114b7:	85 c0                	test   eax,eax
   114b9:	0f 88 f2 02 00 00    	js     117b1 <gnutls_reauth@plt+0x8181>
   114bf:	89 2b                	mov    DWORD PTR [rbx],ebp
   114c1:	f6 44 24 0c 04       	test   BYTE PTR [rsp+0xc],0x4
   114c6:	0f 85 ac 02 00 00    	jne    11778 <gnutls_reauth@plt+0x8148>
   114cc:	f6 44 24 0c 20       	test   BYTE PTR [rsp+0xc],0x20
   114d1:	0f 84 59 02 00 00    	je     11730 <gnutls_reauth@plt+0x8100>
   114d7:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   114db:	48 85 ff             	test   rdi,rdi
   114de:	0f 84 9a 00 00 00    	je     1157e <gnutls_reauth@plt+0x7f4e>
   114e4:	48 8b b3 f8 00 00 00 	mov    rsi,QWORD PTR [rbx+0xf8]
   114eb:	48 85 f6             	test   rsi,rsi
   114ee:	74 13                	je     11503 <gnutls_reauth@plt+0x7ed3>
   114f0:	8b 93 00 01 00 00    	mov    edx,DWORD PTR [rbx+0x100]
   114f6:	e8 15 72 ff ff       	call   8710 <gnutls_record_send_early_data@plt>
   114fb:	85 c0                	test   eax,eax
   114fd:	0f 88 07 03 00 00    	js     1180a <gnutls_reauth@plt+0x81da>
   11503:	48 8b b3 e8 00 00 00 	mov    rsi,QWORD PTR [rbx+0xe8]
   1150a:	48 85 f6             	test   rsi,rsi
   1150d:	74 0f                	je     1151e <gnutls_reauth@plt+0x7eee>
   1150f:	8b 93 f0 00 00 00    	mov    edx,DWORD PTR [rbx+0xf0]
   11515:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   11519:	e8 f2 7d ff ff       	call   9310 <gnutls_session_set_data@plt>
   1151e:	48 8b 44 24 30       	mov    rax,QWORD PTR [rsp+0x30]
   11523:	48 8b 54 24 28       	mov    rdx,QWORD PTR [rsp+0x28]
   11528:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   1152c:	48 89 c1             	mov    rcx,rax
   1152f:	48 09 d1             	or     rcx,rdx
   11532:	0f 84 88 01 00 00    	je     116c0 <gnutls_reauth@plt+0x8090>
   11538:	48 89 93 d8 00 00 00 	mov    QWORD PTR [rbx+0xd8],rdx
   1153f:	48 8d 35 9a ee ff ff 	lea    rsi,[rip+0xffffffffffffee9a]        # 103e0 <gnutls_reauth@plt+0x6db0>
   11546:	48 89 83 e0 00 00 00 	mov    QWORD PTR [rbx+0xe0],rax
   1154d:	e8 de 75 ff ff       	call   8b30 <gnutls_transport_set_push_function@plt>
   11552:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   11556:	48 8d 35 33 ee ff ff 	lea    rsi,[rip+0xffffffffffffee33]        # 10390 <gnutls_reauth@plt+0x6d60>
   1155d:	e8 ae 79 ff ff       	call   8f10 <gnutls_transport_set_pull_function@plt>
   11562:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   11566:	48 8d 35 13 ee ff ff 	lea    rsi,[rip+0xffffffffffffee13]        # 10380 <gnutls_reauth@plt+0x6d50>
   1156d:	e8 5e 6e ff ff       	call   83d0 <gnutls_transport_set_pull_timeout_function@plt>
   11572:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   11576:	48 89 de             	mov    rsi,rbx
   11579:	e8 02 7f ff ff       	call   9480 <gnutls_transport_set_ptr@plt>
   1157e:	8b 44 24 0c          	mov    eax,DWORD PTR [rsp+0xc]
   11582:	83 e0 28             	and    eax,0x28
   11585:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   11589:	75 1c                	jne    115a7 <gnutls_reauth@plt+0x7f77>
   1158b:	48 89 df             	mov    rdi,rbx
   1158e:	e8 6d bc ff ff       	call   d200 <gnutls_reauth@plt+0x3bd0>
   11593:	41 89 c7             	mov    r15d,eax
   11596:	83 f8 cb             	cmp    eax,0xffffffcb
   11599:	0f 84 01 02 00 00    	je     117a0 <gnutls_reauth@plt+0x8170>
   1159f:	85 c0                	test   eax,eax
   115a1:	0f 88 1e 03 00 00    	js     118c5 <gnutls_reauth@plt+0x8295>
   115a7:	45 85 ff             	test   r15d,r15d
   115aa:	0f 85 a9 02 00 00    	jne    11859 <gnutls_reauth@plt+0x8229>
   115b0:	8b 54 24 24          	mov    edx,DWORD PTR [rsp+0x24]
   115b4:	31 c0                	xor    eax,eax
   115b6:	89 2b                	mov    DWORD PTR [rbx],ebp
   115b8:	4c 89 f7             	mov    rdi,r14
   115bb:	85 d2                	test   edx,edx
   115bd:	0f 94 c0             	sete   al
   115c0:	89 43 10             	mov    DWORD PTR [rbx+0x10],eax
   115c3:	e8 f8 79 ff ff       	call   8fc0 <strdup@plt>
   115c8:	4c 89 ef             	mov    rdi,r13
   115cb:	48 89 43 28          	mov    QWORD PTR [rbx+0x28],rax
   115cf:	e8 ec 79 ff ff       	call   8fc0 <strdup@plt>
   115d4:	48 8b bb e8 00 00 00 	mov    rdi,QWORD PTR [rbx+0xe8]
   115db:	4c 89 63 38          	mov    QWORD PTR [rbx+0x38],r12
   115df:	48 89 43 30          	mov    QWORD PTR [rbx+0x30],rax
   115e3:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
   115e8:	48 89 43 40          	mov    QWORD PTR [rbx+0x40],rax
   115ec:	ff 15 b6 0c 01 00    	call   QWORD PTR [rip+0x10cb6]        # 222a8 <gnutls_free@GNUTLS_3_4>
   115f2:	48 8b bb f8 00 00 00 	mov    rdi,QWORD PTR [rbx+0xf8]
   115f9:	48 c7 83 e8 00 00 00 	mov    QWORD PTR [rbx+0xe8],0x0
   11600:	00 00 00 00 
   11604:	ff 15 9e 0c 01 00    	call   QWORD PTR [rip+0x10c9e]        # 222a8 <gnutls_free@GNUTLS_3_4>
   1160a:	48 8b 7c 24 50       	mov    rdi,QWORD PTR [rsp+0x50]
   1160f:	48 c7 83 f8 00 00 00 	mov    QWORD PTR [rbx+0xf8],0x0
   11616:	00 00 00 00 
   1161a:	ff 15 88 0c 01 00    	call   QWORD PTR [rip+0x10c88]        # 222a8 <gnutls_free@GNUTLS_3_4>
   11620:	48 8b 84 24 a8 10 00 	mov    rax,QWORD PTR [rsp+0x10a8]
   11627:	00 
   11628:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1162f:	00 00 
   11631:	0f 85 0d 02 00 00    	jne    11844 <gnutls_reauth@plt+0x8214>
   11637:	48 81 c4 b8 10 00 00 	add    rsp,0x10b8
   1163e:	5b                   	pop    rbx
   1163f:	5d                   	pop    rbp
   11640:	41 5c                	pop    r12
   11642:	41 5d                	pop    r13
   11644:	41 5e                	pop    r14
   11646:	41 5f                	pop    r15
   11648:	c3                   	ret    
   11649:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   11650:	89 c7                	mov    edi,eax
   11652:	e8 a9 7d ff ff       	call   9400 <gai_strerror@plt>
   11657:	48 8b 3d 82 0c 01 00 	mov    rdi,QWORD PTR [rip+0x10c82]        # 222e0 <stderr@GLIBC_2.2.5>
   1165e:	be 01 00 00 00       	mov    esi,0x1
   11663:	48 8d 15 2b 6a 00 00 	lea    rdx,[rip+0x6a2b]        # 18095 <gnutls_reauth@plt+0xea65>
   1166a:	48 89 c1             	mov    rcx,rax
   1166d:	31 c0                	xor    eax,eax
   1166f:	e8 dc 6e ff ff       	call   8550 <__fprintf_chk@plt>
   11674:	89 ef                	mov    edi,ebp
   11676:	e8 15 6e ff ff       	call   8490 <close@plt>
   1167b:	4d 8b 64 24 28       	mov    r12,QWORD PTR [r12+0x28]
   11680:	4d 85 e4             	test   r12,r12
   11683:	0f 85 71 fd ff ff    	jne    113fa <gnutls_reauth@plt+0x7dca>
   11689:	45 85 ff             	test   r15d,r15d
   1168c:	0f 85 b7 01 00 00    	jne    11849 <gnutls_reauth@plt+0x8219>
   11692:	83 fd ff             	cmp    ebp,0xffffffff
   11695:	0f 84 85 01 00 00    	je     11820 <gnutls_reauth@plt+0x81f0>
   1169b:	8b 44 24 0c          	mov    eax,DWORD PTR [rsp+0xc]
   1169f:	4c 8d ac 24 90 00 00 	lea    r13,[rsp+0x90]
   116a6:	00 
   116a7:	4c 8d b4 24 a0 00 00 	lea    r14,[rsp+0xa0]
   116ae:	00 
   116af:	83 e0 28             	and    eax,0x28
   116b2:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   116b6:	e9 f5 fe ff ff       	jmp    115b0 <gnutls_reauth@plt+0x7f80>
   116bb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   116c0:	8b 33                	mov    esi,DWORD PTR [rbx]
   116c2:	89 f2                	mov    edx,esi
   116c4:	e8 b7 7b ff ff       	call   9280 <gnutls_transport_set_int2@plt>
   116c9:	e9 b0 fe ff ff       	jmp    1157e <gnutls_reauth@plt+0x7f4e>
   116ce:	66 90                	xchg   ax,ax
   116d0:	41 8b 44 24 04       	mov    eax,DWORD PTR [r12+0x4]
   116d5:	83 e0 f7             	and    eax,0xfffffff7
   116d8:	83 f8 02             	cmp    eax,0x2
   116db:	0f 85 9a fd ff ff    	jne    1147b <gnutls_reauth@plt+0x7e4b>
   116e1:	41 8b 54 24 10       	mov    edx,DWORD PTR [r12+0x10]
   116e6:	49 8b 74 24 18       	mov    rsi,QWORD PTR [r12+0x18]
   116eb:	48 8d 7b 50          	lea    rdi,[rbx+0x50]
   116ef:	e8 4c 7e ff ff       	call   9540 <memcpy@plt>
   116f4:	41 8b 44 24 10       	mov    eax,DWORD PTR [r12+0x10]
   116f9:	89 83 d0 00 00 00    	mov    DWORD PTR [rbx+0xd0],eax
   116ff:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   11704:	48 85 c0             	test   rax,rax
   11707:	0f 84 b2 fd ff ff    	je     114bf <gnutls_reauth@plt+0x7e8f>
   1170d:	48 8b 3d d4 0b 01 00 	mov    rdi,QWORD PTR [rip+0x10bd4]        # 222e8 <stdout@GLIBC_2.2.5>
   11714:	48 89 c2             	mov    rdx,rax
   11717:	4d 89 e8             	mov    r8,r13
   1171a:	4c 89 f1             	mov    rcx,r14
   1171d:	48 8d 35 9d 69 00 00 	lea    rsi,[rip+0x699d]        # 180c1 <gnutls_reauth@plt+0xea91>
   11724:	31 c0                	xor    eax,eax
   11726:	e8 65 c5 ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   1172b:	e9 8f fd ff ff       	jmp    114bf <gnutls_reauth@plt+0x7e8f>
   11730:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   11735:	e8 f6 b5 ff ff       	call   cd30 <gnutls_reauth@plt+0x3700>
   1173a:	48 89 43 08          	mov    QWORD PTR [rbx+0x8],rax
   1173e:	48                   	rex.W
   1173f:	89                   	.byte 0x89
00016b80: 73 75 65 72 3a 20 25 73 0a 00 67 6e 75 74 6c 73  suer: %s..gnutls
00016b90: 5f 72 6e 64 3a 20 25 73 00 43 61 6e 6e 6f 74 20  _rnd: %s.Cannot 
00016ba0: 63 6f 6e 74 61 63 74 20 4f 43 53 50 20 73 65 72  contact OCSP ser
00016870: 74 65 72 20 28 6f 63 74 65 74 73 20 30 20 2d 20  ter (octets 0 - 
00016880: 31 32 37 29 0a 00 00 00 4e 6f 74 20 65 6e 6f 75  127)....Not enou
00016890: 67 68 20 6d 65 6d 6f 72 79 20 66 6f 72 20 74 68  gh memory for th
000168a0: 65 20 72 65 71 75 65 73 74 0a 00 00 00 00 00 00  e request.......

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x10d80 --stop-address=0x10fa0 ./target.bin
objdump -d -M intel --start-address=0x14660 --stop-address=0x14980 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000010d80 <.text+0x7740>:
   10d80:	31 c0                	xor    eax,eax
   10d82:	e8 09 cf ff ff       	call   dc90 <gnutls_reauth@plt+0x4660>
   10d87:	eb 9f                	jmp    10d28 <gnutls_reauth@plt+0x76f8>
   10d89:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   10d90:	f3 0f 1e fa          	endbr64 
   10d94:	41 54                	push   r12
   10d96:	49 89 f4             	mov    r12,rsi
   10d99:	55                   	push   rbp
   10d9a:	48 63 ea             	movsxd rbp,edx
   10d9d:	53                   	push   rbx
   10d9e:	8b 47 10             	mov    eax,DWORD PTR [rdi+0x10]
   10da1:	48 89 fb             	mov    rbx,rdi
   10da4:	85 c0                	test   eax,eax
   10da6:	74 3a                	je     10de2 <gnutls_reauth@plt+0x77b2>
   10da8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   10daf:	00 
   10db0:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10db4:	48 89 ea             	mov    rdx,rbp
   10db7:	4c 89 e6             	mov    rsi,r12
   10dba:	e8 21 77 ff ff       	call   84e0 <gnutls_record_recv@plt>
   10dbf:	89 c2                	mov    edx,eax
   10dc1:	3d db fe ff ff       	cmp    eax,0xfffffedb
   10dc6:	74 38                	je     10e00 <gnutls_reauth@plt+0x77d0>
   10dc8:	83 f8 cc             	cmp    eax,0xffffffcc
   10dcb:	74 e3                	je     10db0 <gnutls_reauth@plt+0x7780>
   10dcd:	5b                   	pop    rbx
   10dce:	48 63 c2             	movsxd rax,edx
   10dd1:	5d                   	pop    rbp
   10dd2:	41 5c                	pop    r12
   10dd4:	c3                   	ret    
   10dd5:	0f 1f 00             	nop    DWORD PTR [rax]
   10dd8:	e8 c3 81 ff ff       	call   8fa0 <__errno_location@plt>
   10ddd:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10de0:	75 2e                	jne    10e10 <gnutls_reauth@plt+0x77e0>
   10de2:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10de4:	48 89 ea             	mov    rdx,rbp
   10de7:	31 c9                	xor    ecx,ecx
   10de9:	4c 89 e6             	mov    rsi,r12
   10dec:	e8 cf 79 ff ff       	call   87c0 <recv@plt>
   10df1:	89 c2                	mov    edx,eax
   10df3:	83 f8 ff             	cmp    eax,0xffffffff
   10df6:	74 e0                	je     10dd8 <gnutls_reauth@plt+0x77a8>
   10df8:	eb d3                	jmp    10dcd <gnutls_reauth@plt+0x779d>
   10dfa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10e00:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e04:	31 f6                	xor    esi,esi
   10e06:	e8 55 75 ff ff       	call   8360 <gnutls_heartbeat_pong@plt>
   10e0b:	eb a3                	jmp    10db0 <gnutls_reauth@plt+0x7780>
   10e0d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e10:	5b                   	pop    rbx
   10e11:	48 c7 c0 ff ff ff ff 	mov    rax,0xffffffffffffffff
   10e18:	5d                   	pop    rbp
   10e19:	41 5c                	pop    r12
   10e1b:	c3                   	ret    
   10e1c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10e20:	f3 0f 1e fa          	endbr64 
   10e24:	55                   	push   rbp
   10e25:	48 89 f5             	mov    rbp,rsi
   10e28:	53                   	push   rbx
   10e29:	48 89 fb             	mov    rbx,rdi
   10e2c:	48 83 ec 18          	sub    rsp,0x18
   10e30:	8b 77 10             	mov    esi,DWORD PTR [rdi+0x10]
   10e33:	85 f6                	test   esi,esi
   10e35:	75 29                	jne    10e60 <gnutls_reauth@plt+0x7830>
   10e37:	48 89 ee             	mov    rsi,rbp
   10e3a:	48 89 df             	mov    rdi,rbx
   10e3d:	e8 4e ff ff ff       	call   10d90 <gnutls_reauth@plt+0x7760>
   10e42:	48 89 c5             	mov    rbp,rax
   10e45:	8b 43 10             	mov    eax,DWORD PTR [rbx+0x10]
   10e48:	85 c0                	test   eax,eax
   10e4a:	75 2c                	jne    10e78 <gnutls_reauth@plt+0x7848>
   10e4c:	48 83 c4 18          	add    rsp,0x18
   10e50:	48 63 c5             	movsxd rax,ebp
   10e53:	5b                   	pop    rbx
   10e54:	5d                   	pop    rbp
   10e55:	c3                   	ret    
   10e56:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   10e5d:	00 00 00 
   10e60:	48 8b 7f 08          	mov    rdi,QWORD PTR [rdi+0x8]
   10e64:	89 ce                	mov    esi,ecx
   10e66:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   10e6a:	e8 31 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e6f:	8b 54 24 0c          	mov    edx,DWORD PTR [rsp+0xc]
   10e73:	eb c2                	jmp    10e37 <gnutls_reauth@plt+0x7807>
   10e75:	0f 1f 00             	nop    DWORD PTR [rax]
   10e78:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10e7c:	31 f6                	xor    esi,esi
   10e7e:	e8 1d 7d ff ff       	call   8ba0 <gnutls_record_set_timeout@plt>
   10e83:	48 83 c4 18          	add    rsp,0x18
   10e87:	48 63 c5             	movsxd rax,ebp
   10e8a:	5b                   	pop    rbx
   10e8b:	5d                   	pop    rbp
   10e8c:	c3                   	ret    
   10e8d:	0f 1f 00             	nop    DWORD PTR [rax]
   10e90:	f3 0f 1e fa          	endbr64 
   10e94:	41 56                	push   r14
   10e96:	49 89 ce             	mov    r14,rcx
   10e99:	41 55                	push   r13
   10e9b:	41 54                	push   r12
   10e9d:	4c 63 e2             	movsxd r12,edx
   10ea0:	55                   	push   rbp
   10ea1:	4d 89 e5             	mov    r13,r12
   10ea4:	48 89 f5             	mov    rbp,rsi
   10ea7:	53                   	push   rbx
   10ea8:	8b 57 10             	mov    edx,DWORD PTR [rdi+0x10]
   10eab:	48 89 fb             	mov    rbx,rdi
   10eae:	85 d2                	test   edx,edx
   10eb0:	74 58                	je     10f0a <gnutls_reauth@plt+0x78da>
   10eb2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10eb8:	48 8b 7b 08          	mov    rdi,QWORD PTR [rbx+0x8]
   10ebc:	4d 85 f6             	test   r14,r14
   10ebf:	74 67                	je     10f28 <gnutls_reauth@plt+0x78f8>
   10ec1:	4c 89 f1             	mov    rcx,r14
   10ec4:	4c 89 e2             	mov    rdx,r12
   10ec7:	48 89 ee             	mov    rsi,rbp
   10eca:	e8 01 7a ff ff       	call   88d0 <gnutls_record_send_range@plt>
   10ecf:	89 c1                	mov    ecx,eax
   10ed1:	83 f9 e4             	cmp    ecx,0xffffffe4
   10ed4:	74 e2                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10ed6:	83 f9 cc             	cmp    ecx,0xffffffcc
   10ed9:	74 dd                	je     10eb8 <gnutls_reauth@plt+0x7888>
   10edb:	4c 63 e1             	movsxd r12,ecx
   10ede:	85 c9                	test   ecx,ecx
   10ee0:	7e 0c                	jle    10eee <gnutls_reauth@plt+0x78be>
   10ee2:	44 39 e9             	cmp    ecx,r13d
   10ee5:	74 07                	je     10eee <gnutls_reauth@plt+0x78be>
   10ee7:	8b 43 48             	mov    eax,DWORD PTR [rbx+0x48]
   10eea:	85 c0                	test   eax,eax
   10eec:	75 6a                	jne    10f58 <gnutls_reauth@plt+0x7928>
   10eee:	5b                   	pop    rbx
   10eef:	4c 89 e0             	mov    rax,r12
   10ef2:	5d                   	pop    rbp
   10ef3:	41 5c                	pop    r12
   10ef5:	41 5d                	pop    r13
   10ef7:	41 5e                	pop    r14
   10ef9:	c3                   	ret    
   10efa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f00:	e8 9b 80 ff ff       	call   8fa0 <__errno_location@plt>
   10f05:	83 38 04             	cmp    DWORD PTR [rax],0x4
   10f08:	75 36                	jne    10f40 <gnutls_reauth@plt+0x7910>
   10f0a:	8b 3b                	mov    edi,DWORD PTR [rbx]
   10f0c:	31 c9                	xor    ecx,ecx
   10f0e:	4c 89 e2             	mov    rdx,r12
   10f11:	48 89 ee             	mov    rsi,rbp
   10f14:	e8 07 82 ff ff       	call   9120 <send@plt>
   10f19:	89 c1                	mov    ecx,eax
   10f1b:	83 f8 ff             	cmp    eax,0xffffffff
   10f1e:	74 e0                	je     10f00 <gnutls_reauth@plt+0x78d0>
   10f20:	eb b9                	jmp    10edb <gnutls_reauth@plt+0x78ab>
   10f22:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   10f28:	4c 89 e2             	mov    rdx,r12
   10f2b:	48 89 ee             	mov    rsi,rbp
   10f2e:	e8 ad 80 ff ff       	call   8fe0 <gnutls_record_send@plt>
   10f33:	89 c1                	mov    ecx,eax
   10f35:	eb 9a                	jmp    10ed1 <gnutls_reauth@plt+0x78a1>
   10f37:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   10f3e:	00 00 
   10f40:	49 c7 c4 ff ff ff ff 	mov    r12,0xffffffffffffffff
   10f47:	5b                   	pop    rbx
   10f48:	5d                   	pop    rbp
   10f49:	4c 89 e0             	mov    rax,r12
   10f4c:	41 5c                	pop    r12
   10f4e:	41 5d                	pop    r13
   10f50:	41 5e                	pop    r14
   10f52:	c3                   	ret    
   10f53:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   10f58:	48 8b 3d 81 13 01 00 	mov    rdi,QWORD PTR [rip+0x11381]        # 222e0 <stderr@GLIBC_2.2.5>
   10f5f:	45 89 e8             	mov    r8d,r13d
   10f62:	be 01 00 00 00       	mov    esi,0x1
   10f67:	31 c0                	xor    eax,eax
   10f69:	48 8d 15 80 6d 00 00 	lea    rdx,[rip+0x6d80]        # 17cf0 <gnutls_reauth@plt+0xe6c0>
   10f70:	e8 db 75 ff ff       	call   8550 <__fprintf_chk@plt>
   10f75:	5b                   	pop    rbx
   10f76:	4c 89 e0             	mov    rax,r12
   10f79:	5d                   	pop    rbp
   10f7a:	41 5c                	pop    r12
   10f7c:	41 5d                	pop    r13
   10f7e:	41 5e                	pop    r14
   10f80:	c3                   	ret    
   10f81:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   10f88:	00 00 00 00 
   10f8c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   10f90:	f3 0f 1e fa          	endbr64 
   10f94:	31 c9                	xor    ecx,ecx
   10f96:	e9 f5 fe ff ff       	jmp    10e90 <gnutls_reauth@plt+0x7860>
   10f9b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000014660 <.text+0xb020>:
   14660:	41 55                	push   r13
   14662:	41 54                	push   r12
   14664:	49 89 fc             	mov    r12,rdi
   14667:	53                   	push   rbx
   14668:	48 83 ec 10          	sub    rsp,0x10
   1466c:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   14673:	00 00 
   14675:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1467a:	31 c0                	xor    eax,eax
   1467c:	48 c7 04 24 00 00 00 	mov    QWORD PTR [rsp],0x0
   14683:	00 
   14684:	e8 17 49 ff ff       	call   8fa0 <__errno_location@plt>
   14689:	ba 02 00 00 00       	mov    edx,0x2
   1468e:	48 8d 35 d9 48 00 00 	lea    rsi,[rip+0x48d9]        # 18f6e <gnutls_reauth@plt+0xf93e>
   14695:	4c 89 e7             	mov    rdi,r12
   14698:	c7 00 00 00 00 00    	mov    DWORD PTR [rax],0x0
   1469e:	48 89 c3             	mov    rbx,rax
   146a1:	e8 ea 40 ff ff       	call   8790 <strncmp@plt>
   146a6:	85 c0                	test   eax,eax
   146a8:	0f 84 a2 00 00 00    	je     14750 <gnutls_reauth@plt+0xb120>
   146ae:	ba 01 00 00 00       	mov    edx,0x1
   146b3:	48 8d 35 b7 48 00 00 	lea    rsi,[rip+0x48b7]        # 18f71 <gnutls_reauth@plt+0xf941>
   146ba:	4c 89 e7             	mov    rdi,r12
   146bd:	e8 ce 40 ff ff       	call   8790 <strncmp@plt>
   146c2:	85 c0                	test   eax,eax
   146c4:	75 2a                	jne    146f0 <gnutls_reauth@plt+0xb0c0>
   146c6:	4c 89 e7             	mov    rdi,r12
   146c9:	48 8d 35 a3 48 00 00 	lea    rsi,[rip+0x48a3]        # 18f73 <gnutls_reauth@plt+0xf943>
   146d0:	e8 bb 47 ff ff       	call   8e90 <strspn@plt>
   146d5:	49 89 c5             	mov    r13,rax
   146d8:	48 8b 05 f1 b8 00 00 	mov    rax,QWORD PTR [rip+0xb8f1]        # 1ffd0 <gnutls_reauth@plt+0x169a0>
   146df:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   146e2:	e8 59 43 ff ff       	call   8a40 <strlen@plt>
   146e7:	49 39 c5             	cmp    r13,rax
   146ea:	0f 84 80 00 00 00    	je     14770 <gnutls_reauth@plt+0xb140>
   146f0:	48 89 e6             	mov    rsi,rsp
   146f3:	ba 0a 00 00 00       	mov    edx,0xa
   146f8:	4c 89 e7             	mov    rdi,r12
   146fb:	e8 30 46 ff ff       	call   8d30 <strtol@plt>
   14700:	49 89 c5             	mov    r13,rax
   14703:	8b 33                	mov    esi,DWORD PTR [rbx]
   14705:	85 f6                	test   esi,esi
   14707:	75 2f                	jne    14738 <gnutls_reauth@plt+0xb108>
   14709:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
   1470d:	48 85 c0             	test   rax,rax
   14710:	74 05                	je     14717 <gnutls_reauth@plt+0xb0e7>
   14712:	80 38 00             	cmp    BYTE PTR [rax],0x0
   14715:	75 21                	jne    14738 <gnutls_reauth@plt+0xb108>
   14717:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   1471c:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   14723:	00 00 
   14725:	75 63                	jne    1478a <gnutls_reauth@plt+0xb15a>
   14727:	48 83 c4 10          	add    rsp,0x10
   1472b:	4c 89 e8             	mov    rax,r13
   1472e:	5b                   	pop    rbx
   1472f:	41 5c                	pop    r12
   14731:	41 5d                	pop    r13
   14733:	c3                   	ret    
   14734:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   14738:	4c 89 e1             	mov    rcx,r12
   1473b:	48 8d 15 ce 4b 00 00 	lea    rdx,[rip+0x4bce]        # 19310 <gnutls_reauth@plt+0xfce0>
   14742:	bf 01 00 00 00       	mov    edi,0x1
   14747:	31 c0                	xor    eax,eax
   14749:	e8 d2 4c ff ff       	call   9420 <error@plt>
   1474e:	eb c7                	jmp    14717 <gnutls_reauth@plt+0xb0e7>
   14750:	48 89 e6             	mov    rsi,rsp
   14753:	49 8d 7c 24 02       	lea    rdi,[r12+0x2]
   14758:	ba 10 00 00 00       	mov    edx,0x10
   1475d:	e8 ce 45 ff ff       	call   8d30 <strtol@plt>
   14762:	49 89 c5             	mov    r13,rax
   14765:	eb 9c                	jmp    14703 <gnutls_reauth@plt+0xb0d3>
   14767:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1476e:	00 00 
   14770:	48 89 e6             	mov    rsi,rsp
   14773:	49 8d 7c 24 01       	lea    rdi,[r12+0x1]
   14778:	ba 08 00 00 00       	mov    edx,0x8
   1477d:	e8 ae 45 ff ff       	call   8d30 <strtol@plt>
   14782:	49 89 c5             	mov    r13,rax
   14785:	e9 79 ff ff ff       	jmp    14703 <gnutls_reauth@plt+0xb0d3>
   1478a:	e8 91 48 ff ff       	call   9020 <__stack_chk_fail@plt>
   1478f:	90                   	nop
   14790:	48 8d 47 01          	lea    rax,[rdi+0x1]
   14794:	c3                   	ret    
   14795:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1479c:	00 00 00 00 
   147a0:	41 55                	push   r13
   147a2:	49 89 f5             	mov    r13,rsi
   147a5:	41 54                	push   r12
   147a7:	55                   	push   rbp
   147a8:	53                   	push   rbx
   147a9:	48 89 fb             	mov    rbx,rdi
   147ac:	48 83 ec 08          	sub    rsp,0x8
   147b0:	8b 7f 08             	mov    edi,DWORD PTR [rdi+0x8]
   147b3:	e8 d8 ff ff ff       	call   14790 <gnutls_reauth@plt+0xb160>
   147b8:	48 89 c5             	mov    rbp,rax
   147bb:	48 83 f8 ff          	cmp    rax,0xffffffffffffffff
   147bf:	74 3f                	je     14800 <gnutls_reauth@plt+0xb1d0>
   147c1:	48 8b 3b             	mov    rdi,QWORD PTR [rbx]
   147c4:	ba 08 00 00 00       	mov    edx,0x8
   147c9:	48 89 ee             	mov    rsi,rbp
   147cc:	e8 5f 3f ff ff       	call   8730 <reallocarray@plt>
   147d1:	49 89 c4             	mov    r12,rax
   147d4:	48 85 c0             	test   rax,rax
   147d7:	74 47                	je     14820 <gnutls_reauth@plt+0xb1f0>
   147d9:	48 8b 05 f0 b7 00 00 	mov    rax,QWORD PTR [rip+0xb7f0]        # 1ffd0 <gnutls_reauth@plt+0x169a0>
   147e0:	4c 89 23             	mov    QWORD PTR [rbx],r12
   147e3:	48 8b 10             	mov    rdx,QWORD PTR [rax]
   147e6:	8b 43 08             	mov    eax,DWORD PTR [rbx+0x8]
   147e9:	49 89 14 c4          	mov    QWORD PTR [r12+rax*8],rdx
   147ed:	89 6b 08             	mov    DWORD PTR [rbx+0x8],ebp
   147f0:	48 83 c4 08          	add    rsp,0x8
   147f4:	5b                   	pop    rbx
   147f5:	5d                   	pop    rbp
   147f6:	41 5c                	pop    r12
   147f8:	41 5d                	pop    r13
   147fa:	c3                   	ret    
   147fb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   14800:	48 89 f1             	mov    rcx,rsi
   14803:	48 8d 15 73 47 00 00 	lea    rdx,[rip+0x4773]        # 18f7d <gnutls_reauth@plt+0xf94d>
   1480a:	31 f6                	xor    esi,esi
   1480c:	bf 01 00 00 00       	mov    edi,0x1
   14811:	31 c0                	xor    eax,eax
   14813:	e8 08 4c ff ff       	call   9420 <error@plt>
   14818:	eb a7                	jmp    147c1 <gnutls_reauth@plt+0xb191>
   1481a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   14820:	4c 89 e9             	mov    rcx,r13
   14823:	48 8d 15 0e 4b 00 00 	lea    rdx,[rip+0x4b0e]        # 19338 <gnutls_reauth@plt+0xfd08>
   1482a:	31 f6                	xor    esi,esi
   1482c:	31 c0                	xor    eax,eax
   1482e:	bf 01 00 00 00       	mov    edi,0x1
   14833:	e8 e8 4b ff ff       	call   9420 <error@plt>
   14838:	eb 9f                	jmp    147d9 <gnutls_reauth@plt+0xb1a9>
   1483a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   14840:	f3 0f 1e fa          	endbr64 
   14844:	55                   	push   rbp
   14845:	48 81 ec 00 10 00 00 	sub    rsp,0x1000
   1484c:	48 83 0c 24 00       	or     QWORD PTR [rsp],0x0
   14851:	48 81 ec 70 07 00 00 	sub    rsp,0x770
   14858:	b9 ec 02 00 00       	mov    ecx,0x2ec
   1485d:	48 8d 15 32 23 00 00 	lea    rdx,[rip+0x2332]        # 16b96 <gnutls_reauth@plt+0xd566>
   14864:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1486b:	00 00 
   1486d:	48 89 84 24 68 17 00 	mov    QWORD PTR [rsp+0x1768],rax
   14874:	00 
   14875:	31 c0                	xor    eax,eax
   14877:	49 89 f8             	mov    r8,rdi
   1487a:	89 f5                	mov    ebp,esi
   1487c:	48 89 e7             	mov    rdi,rsp
   1487f:	48 8d 35 da 4a 00 00 	lea    rsi,[rip+0x4ada]        # 19360 <gnutls_reauth@plt+0xfd30>
   14886:	f3 48 a5             	rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi]
   14889:	48 89 e1             	mov    rcx,rsp
   1488c:	0f b7 06             	movzx  eax,WORD PTR [rsi]
   1488f:	be 01 00 00 00       	mov    esi,0x1
   14894:	66 89 07             	mov    WORD PTR [rdi],ax
   14897:	0f b6 05 24 62 00 00 	movzx  eax,BYTE PTR [rip+0x6224]        # 1aac2 <gnutls_reauth@plt+0x11492>
   1489e:	88 47 02             	mov    BYTE PTR [rdi+0x2],al
   148a1:	4c 89 c7             	mov    rdi,r8
   148a4:	31 c0                	xor    eax,eax
   148a6:	e8 a5 3c ff ff       	call   8550 <__fprintf_chk@plt>
   148ab:	89 ef                	mov    edi,ebp
   148ad:	e8 3e 3d ff ff       	call   85f0 <exit@plt>
   148b2:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   148b9:	00 00 00 00 
   148bd:	0f 1f 00             	nop    DWORD PTR [rax]
   148c0:	f3 0f 1e fa          	endbr64 
   148c4:	41 57                	push   r15
   148c6:	41 56                	push   r14
   148c8:	4c 8d 35 51 a1 00 00 	lea    r14,[rip+0xa151]        # 1ea20 <gnutls_reauth@plt+0x153f0>
   148cf:	41 55                	push   r13
   148d1:	4c 8d 2d d7 46 00 00 	lea    r13,[rip+0x46d7]        # 18faf <gnutls_reauth@plt+0xf97f>
   148d8:	41 54                	push   r12
   148da:	41 89 fc             	mov    r12d,edi
   148dd:	55                   	push   rbp
   148de:	48 89 f5             	mov    rbp,rsi
   148e1:	53                   	push   rbx
   148e2:	48 8d 1d eb 67 00 00 	lea    rbx,[rip+0x67eb]        # 1b0d4 <gnutls_reauth@plt+0x11aa4>
   148e9:	48 81 ec d8 03 00 00 	sub    rsp,0x3d8
   148f0:	4c 8d 3d 29 0e 08 00 	lea    r15,[rip+0x80e29]        # 95720 <stdout@GLIBC_2.2.5+0x73438>
   148f7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   148fe:	00 00 
   14900:	48 89 84 24 c8 03 00 	mov    QWORD PTR [rsp+0x3c8],rax
   14907:	00 
   14908:	31 c0                	xor    eax,eax
   1490a:	41 c6 87 86 01 00 00 	mov    BYTE PTR [r15+0x186],0x1
   14911:	01 
   14912:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   14918:	45 31 c0             	xor    r8d,r8d
   1491b:	4c 89 f1             	mov    rcx,r14
   1491e:	4c 89 ea             	mov    rdx,r13
   14921:	48 89 ee             	mov    rsi,rbp
   14924:	44 89 e7             	mov    edi,r12d
   14927:	e8 b4 45 ff ff       	call   8ee0 <getopt_long@plt>
   1492c:	83 f8 ff             	cmp    eax,0xffffffff
   1492f:	0f 84 13 08 00 00    	je     15148 <gnutls_reauth@plt+0xbb18>
   14935:	3d c1 00 00 00       	cmp    eax,0xc1
   1493a:	77 14                	ja     14950 <gnutls_reauth@plt+0xb320>
   1493c:	89 c0                	mov    eax,eax
   1493e:	48 63 04 83          	movsxd rax,DWORD PTR [rbx+rax*4]
   14942:	48 01 d8             	add    rax,rbx
   14945:	3e ff e0             	notrack jmp rax
   14948:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1494f:	00 
   14950:	48 8b 05 81 b6 00 00 	mov    rax,QWORD PTR [rip+0xb681]        # 1ffd8 <gnutls_reauth@plt+0x169a8>
   14957:	be 01 00 00 00       	mov    esi,0x1
   1495c:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   1495f:	e8 dc fe ff ff       	call   14840 <gnutls_reauth@plt+0xb210>
   14964:	eb b2                	jmp    14918 <gnutls_reauth@plt+0xb2e8>
   14966:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1496d:	00 00 00 
   14970:	48 8b 05 59 b6 00 00 	mov    rax,QWORD PTR [rip+0xb659]        # 1ffd0 <gnutls_reauth@plt+0x169a0>
   14977:	41 c6 47 0e 01       	mov    BYTE PTR [r15+0xe],0x1
   1497c:	41                   	rex.B
   1497d:	c6                   	.byte 0xc6
   1497e:	87                   	.byte 0x87
   1497f:	8e                   	.byte 0x8e

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x15140 --stop-address=0x15c00 ./target.bin' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000015140 <.text+0xbb00>:
   15140:	f7 ff                	idiv   edi
   15142:	ff 0f                	dec    DWORD PTR [rdi]
   15144:	1f                   	(bad)  
   15145:	44 00 00             	add    BYTE PTR [rax],r8b
   15148:	41 80 3f 00          	cmp    BYTE PTR [r15],0x0
   1514c:	74 1d                	je     1516b <gnutls_reauth@plt+0xbb3b>
   1514e:	45 8b 87 48 01 00 00 	mov    r8d,DWORD PTR [r15+0x148]
   15155:	45 85 c0             	test   r8d,r8d
   15158:	0f 88 3e 03 00 00    	js     1549c <gnutls_reauth@plt+0xbe6c>
   1515e:	41 81 f8 0f 27 00 00 	cmp    r8d,0x270f
   15165:	0f 8f ef 01 00 00    	jg     1535a <gnutls_reauth@plt+0xbd2a>
   1516b:	41 80 7f 0e 00       	cmp    BYTE PTR [r15+0xe],0x0
   15170:	74 0b                	je     1517d <gnutls_reauth@plt+0xbb4d>
   15172:	41 80 7f 0d 00       	cmp    BYTE PTR [r15+0xd],0x0
   15177:	0f 85 fe 01 00 00    	jne    1537b <gnutls_reauth@plt+0xbd4b>
   1517d:	41 80 7f 10 00       	cmp    BYTE PTR [r15+0x10],0x0
   15182:	74 1d                	je     151a1 <gnutls_reauth@plt+0xbb71>
   15184:	45 8b 87 4c 01 00 00 	mov    r8d,DWORD PTR [r15+0x14c]
   1518b:	45 85 c0             	test   r8d,r8d
   1518e:	0f 88 47 03 00 00    	js     154db <gnutls_reauth@plt+0xbeab>
   15194:	41 81 f8 68 42 00 00 	cmp    r8d,0x4268
   1519b:	0f 8f 02 02 00 00    	jg     153a3 <gnutls_reauth@plt+0xbd73>
   151a1:	41 80 7f 16 00       	cmp    BYTE PTR [r15+0x16],0x0
   151a6:	41 0f b6 47 17       	movzx  eax,BYTE PTR [r15+0x17]
   151ab:	74 08                	je     151b5 <gnutls_reauth@plt+0xbb85>
   151ad:	84 c0                	test   al,al
   151af:	0f 85 0f 02 00 00    	jne    153c4 <gnutls_reauth@plt+0xbd94>
   151b5:	41 80 7f 1f 00       	cmp    BYTE PTR [r15+0x1f],0x0
   151ba:	74 0b                	je     151c7 <gnutls_reauth@plt+0xbb97>
   151bc:	41 80 7f 1e 00       	cmp    BYTE PTR [r15+0x1e],0x0
   151c1:	0f 84 5d 02 00 00    	je     15424 <gnutls_reauth@plt+0xbdf4>
   151c7:	41 80 7f 21 00       	cmp    BYTE PTR [r15+0x21],0x0
   151cc:	74 0b                	je     151d9 <gnutls_reauth@plt+0xbba9>
   151ce:	41 80 7f 20 00       	cmp    BYTE PTR [r15+0x20],0x0
   151d3:	0f 84 73 02 00 00    	je     1544c <gnutls_reauth@plt+0xbe1c>
   151d9:	41 80 7f 2d 00       	cmp    BYTE PTR [r15+0x2d],0x0
   151de:	74 0b                	je     151eb <gnutls_reauth@plt+0xbbbb>
   151e0:	41 80 7f 26 00       	cmp    BYTE PTR [r15+0x26],0x0
   151e5:	0f 85 89 02 00 00    	jne    15474 <gnutls_reauth@plt+0xbe44>
   151eb:	41 80 7f 34 00       	cmp    BYTE PTR [r15+0x34],0x0
   151f0:	74 1d                	je     1520f <gnutls_reauth@plt+0xbbdf>
   151f2:	45 8b 87 54 01 00 00 	mov    r8d,DWORD PTR [r15+0x154]
   151f9:	45 85 c0             	test   r8d,r8d
   151fc:	0f 88 19 03 00 00    	js     1551b <gnutls_reauth@plt+0xbeeb>
   15202:	41 81 f8 00 10 00 00 	cmp    r8d,0x1000
   15209:	0f 8f 2a 01 00 00    	jg     15339 <gnutls_reauth@plt+0xbd09>
   1520f:	41 80 7f 44 00       	cmp    BYTE PTR [r15+0x44],0x0
   15214:	0f 85 09 01 00 00    	jne    15323 <gnutls_reauth@plt+0xbcf3>
   1521a:	41 80 7f 45 00       	cmp    BYTE PTR [r15+0x45],0x0
   1521f:	0f 85 a3 00 00 00    	jne    152c8 <gnutls_reauth@plt+0xbc98>
   15225:	41 80 7f 43 00       	cmp    BYTE PTR [r15+0x43],0x0
   1522a:	74 6a                	je     15296 <gnutls_reauth@plt+0xbc66>
   1522c:	49 8b af 40 01 00 00 	mov    rbp,QWORD PTR [r15+0x140]
   15233:	48 85 ed             	test   rbp,rbp
   15236:	0f 84 bb 03 00 00    	je     155f7 <gnutls_reauth@plt+0xbfc7>
   1523c:	48 8d 35 42 24 00 00 	lea    rsi,[rip+0x2442]        # 17685 <gnutls_reauth@plt+0xe055>
   15243:	48 89 ef             	mov    rdi,rbp
   15246:	e8 85 3e ff ff       	call   90d0 <strcmp@plt>
   1524b:	85 c0                	test   eax,eax
   1524d:	0f 84 a4 03 00 00    	je     155f7 <gnutls_reauth@plt+0xbfc7>
   15253:	48 8d 35 4d 1c 00 00 	lea    rsi,[rip+0x1c4d]        # 16ea7 <gnutls_reauth@plt+0xd877>
   1525a:	48 89 ef             	mov    rdi,rbp
   1525d:	e8 6e 3e ff ff       	call   90d0 <strcmp@plt>
   15262:	85 c0                	test   eax,eax
   15264:	0f 84 df 03 00 00    	je     15649 <gnutls_reauth@plt+0xc019>
   1526a:	48 8d 35 40 3f 00 00 	lea    rsi,[rip+0x3f40]        # 191b1 <gnutls_reauth@plt+0xfb81>
   15271:	48 89 ef             	mov    rdi,rbp
   15274:	e8 57 3e ff ff       	call   90d0 <strcmp@plt>
   15279:	85 c0                	test   eax,eax
   1527b:	0f 84 de 03 00 00    	je     1565f <gnutls_reauth@plt+0xc02f>
   15281:	48 8d 15 e0 58 00 00 	lea    rdx,[rip+0x58e0]        # 1ab68 <gnutls_reauth@plt+0x11538>
   15288:	31 f6                	xor    esi,esi
   1528a:	bf 01 00 00 00       	mov    edi,0x1
   1528f:	31 c0                	xor    eax,eax
   15291:	e8 8a 41 ff ff       	call   9420 <error@plt>
   15296:	48 8b 05 1b ad 00 00 	mov    rax,QWORD PTR [rip+0xad1b]        # 1ffb8 <gnutls_reauth@plt+0x16988>
   1529d:	8b 00                	mov    eax,DWORD PTR [rax]
   1529f:	48 8b 94 24 c8 03 00 	mov    rdx,QWORD PTR [rsp+0x3c8]
   152a6:	00 
   152a7:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   152ae:	00 00 
   152b0:	0f 85 8e 03 00 00    	jne    15644 <gnutls_reauth@plt+0xc014>
   152b6:	48 81 c4 d8 03 00 00 	add    rsp,0x3d8
   152bd:	5b                   	pop    rbx
   152be:	5d                   	pop    rbp
   152bf:	41 5c                	pop    r12
   152c1:	41 5d                	pop    r13
   152c3:	41 5e                	pop    r14
   152c5:	41 5f                	pop    r15
   152c7:	c3                   	ret    
   152c8:	48 8d 7c 24 08       	lea    rdi,[rsp+0x8]
   152cd:	e8 4e 39 ff ff       	call   8c20 <pipe@plt>
   152d2:	85 c0                	test   eax,eax
   152d4:	0f 88 fe 02 00 00    	js     155d8 <gnutls_reauth@plt+0xbfa8>
   152da:	e8 71 40 ff ff       	call   9350 <fork@plt>
   152df:	85 c0                	test   eax,eax
   152e1:	0f 88 74 02 00 00    	js     1555b <gnutls_reauth@plt+0xbf2b>
   152e7:	0f 85 88 02 00 00    	jne    15575 <gnutls_reauth@plt+0xbf45>
   152ed:	8b 7c 24 08          	mov    edi,DWORD PTR [rsp+0x8]
   152f1:	e8 9a 31 ff ff       	call   8490 <close@plt>
   152f6:	8b 7c 24 0c          	mov    edi,DWORD PTR [rsp+0xc]
   152fa:	be 01 00 00 00       	mov    esi,0x1
   152ff:	e8 bc 30 ff ff       	call   83c0 <dup2@plt>
   15304:	8b 7c 24 0c          	mov    edi,DWORD PTR [rsp+0xc]
   15308:	e8 83 31 ff ff       	call   8490 <close@plt>
   1530d:	48 8b 05 d4 ac 00 00 	mov    rax,QWORD PTR [rip+0xacd4]        # 1ffe8 <gnutls_reauth@plt+0x169b8>
   15314:	31 f6                	xor    esi,esi
   15316:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   15319:	e8 22 f5 ff ff       	call   14840 <gnutls_reauth@plt+0xb210>
   1531e:	e9 02 ff ff ff       	jmp    15225 <gnutls_reauth@plt+0xbbf5>
   15323:	48 8b 05 be ac 00 00 	mov    rax,QWORD PTR [rip+0xacbe]        # 1ffe8 <gnutls_reauth@plt+0x169b8>
   1532a:	31 f6                	xor    esi,esi
   1532c:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   1532f:	e8 0c f5 ff ff       	call   14840 <gnutls_reauth@plt+0xb210>
   15334:	e9 e1 fe ff ff       	jmp    1521a <gnutls_reauth@plt+0xbbea>
   15339:	48 8d 0d 05 3d 00 00 	lea    rcx,[rip+0x3d05]        # 19045 <gnutls_reauth@plt+0xfa15>
   15340:	31 f6                	xor    esi,esi
   15342:	bf 01 00 00 00       	mov    edi,0x1
   15347:	31 c0                	xor    eax,eax
   15349:	48 8d 15 a0 57 00 00 	lea    rdx,[rip+0x57a0]        # 1aaf0 <gnutls_reauth@plt+0x114c0>
   15350:	e8 cb 40 ff ff       	call   9420 <error@plt>
   15355:	e9 b5 fe ff ff       	jmp    1520f <gnutls_reauth@plt+0xbbdf>
   1535a:	48 8d 0d 5e 3c 00 00 	lea    rcx,[rip+0x3c5e]        # 18fbf <gnutls_reauth@plt+0xf98f>
   15361:	31 f6                	xor    esi,esi
   15363:	bf 01 00 00 00       	mov    edi,0x1
   15368:	31 c0                	xor    eax,eax
   1536a:	48 8d 15 7f 57 00 00 	lea    rdx,[rip+0x577f]        # 1aaf0 <gnutls_reauth@plt+0x114c0>
   15371:	e8 aa 40 ff ff       	call   9420 <error@plt>
   15376:	e9 f0 fd ff ff       	jmp    1516b <gnutls_reauth@plt+0xbb3b>
   1537b:	4c 8d 05 43 3c 00 00 	lea    r8,[rip+0x3c43]        # 18fc5 <gnutls_reauth@plt+0xf995>
   15382:	31 f6                	xor    esi,esi
   15384:	bf 01 00 00 00       	mov    edi,0x1
   15389:	31 c0                	xor    eax,eax
   1538b:	48 8d 0d 3c 3c 00 00 	lea    rcx,[rip+0x3c3c]        # 18fce <gnutls_reauth@plt+0xf99e>
   15392:	48 8d 15 7f 57 00 00 	lea    rdx,[rip+0x577f]        # 1ab18 <gnutls_reauth@plt+0x114e8>
   15399:	e8 82 40 ff ff       	call   9420 <error@plt>
   1539e:	e9 da fd ff ff       	jmp    1517d <gnutls_reauth@plt+0xbb4d>
   153a3:	48 8d 0d 33 3c 00 00 	lea    rcx,[rip+0x3c33]        # 18fdd <gnutls_reauth@plt+0xf9ad>
   153aa:	31 f6                	xor    esi,esi
   153ac:	bf 01 00 00 00       	mov    edi,0x1
   153b1:	31 c0                	xor    eax,eax
   153b3:	48 8d 15 36 57 00 00 	lea    rdx,[rip+0x5736]        # 1aaf0 <gnutls_reauth@plt+0x114c0>
   153ba:	e8 61 40 ff ff       	call   9420 <error@plt>
   153bf:	e9 dd fd ff ff       	jmp    151a1 <gnutls_reauth@plt+0xbb71>
   153c4:	4c 8d 25 4d 57 00 00 	lea    r12,[rip+0x574d]        # 1ab18 <gnutls_reauth@plt+0x114e8>
   153cb:	31 f6                	xor    esi,esi
   153cd:	31 c0                	xor    eax,eax
   153cf:	bf 01 00 00 00       	mov    edi,0x1
   153d4:	4c 8d 05 06 3c 00 00 	lea    r8,[rip+0x3c06]        # 18fe1 <gnutls_reauth@plt+0xf9b1>
   153db:	48 8d 0d 0f 3c 00 00 	lea    rcx,[rip+0x3c0f]        # 18ff1 <gnutls_reauth@plt+0xf9c1>
   153e2:	4c 89 e2             	mov    rdx,r12
   153e5:	e8 36 40 ff ff       	call   9420 <error@plt>
   153ea:	41 80 7f 17 00       	cmp    BYTE PTR [r15+0x17],0x0
   153ef:	0f 84 c0 fd ff ff    	je     151b5 <gnutls_reauth@plt+0xbb85>
   153f5:	41 80 7f 16 00       	cmp    BYTE PTR [r15+0x16],0x0
   153fa:	0f 84 b5 fd ff ff    	je     151b5 <gnutls_reauth@plt+0xbb85>
   15400:	4c 8d 05 f4 3b 00 00 	lea    r8,[rip+0x3bf4]        # 18ffb <gnutls_reauth@plt+0xf9cb>
   15407:	4c 89 e2             	mov    rdx,r12
   1540a:	31 f6                	xor    esi,esi
   1540c:	31 c0                	xor    eax,eax
   1540e:	48 8d 0d f0 3b 00 00 	lea    rcx,[rip+0x3bf0]        # 19005 <gnutls_reauth@plt+0xf9d5>
   15415:	bf 01 00 00 00       	mov    edi,0x1
   1541a:	e8 01 40 ff ff       	call   9420 <error@plt>
   1541f:	e9 91 fd ff ff       	jmp    151b5 <gnutls_reauth@plt+0xbb85>
   15424:	4c 8d 05 ea 3b 00 00 	lea    r8,[rip+0x3bea]        # 19015 <gnutls_reauth@plt+0xf9e5>
   1542b:	31 f6                	xor    esi,esi
   1542d:	bf 01 00 00 00       	mov    edi,0x1
   15432:	31 c0                	xor    eax,eax
   15434:	48 8d 0d e6 3b 00 00 	lea    rcx,[rip+0x3be6]        # 19021 <gnutls_reauth@plt+0xf9f1>
   1543b:	48 8d 15 fe 56 00 00 	lea    rdx,[rip+0x56fe]        # 1ab40 <gnutls_reauth@plt+0x11510>
   15442:	e8 d9 3f ff ff       	call   9420 <error@plt>
   15447:	e9 7b fd ff ff       	jmp    151c7 <gnutls_reauth@plt+0xbb97>
   1544c:	4c 8d 05 db 3b 00 00 	lea    r8,[rip+0x3bdb]        # 1902e <gnutls_reauth@plt+0xf9fe>
   15453:	31 f6                	xor    esi,esi
   15455:	bf 01 00 00 00       	mov    edi,0x1
   1545a:	31 c0                	xor    eax,eax
   1545c:	48 8d 0d d8 3b 00 00 	lea    rcx,[rip+0x3bd8]        # 1903b <gnutls_reauth@plt+0xfa0b>
   15463:	48 8d 15 d6 56 00 00 	lea    rdx,[rip+0x56d6]        # 1ab40 <gnutls_reauth@plt+0x11510>
   1546a:	e8 b1 3f ff ff       	call   9420 <error@plt>
   1546f:	e9 65 fd ff ff       	jmp    151d9 <gnutls_reauth@plt+0xbba9>
   15474:	4c 8d 05 44 3e 00 00 	lea    r8,[rip+0x3e44]        # 192bf <gnutls_reauth@plt+0xfc8f>
   1547b:	31 f6                	xor    esi,esi
   1547d:	bf 01 00 00 00       	mov    edi,0x1
   15482:	31 c0                	xor    eax,eax
   15484:	48 8d 0d 71 3d 00 00 	lea    rcx,[rip+0x3d71]        # 191fc <gnutls_reauth@plt+0xfbcc>
   1548b:	48 8d 15 86 56 00 00 	lea    rdx,[rip+0x5686]        # 1ab18 <gnutls_reauth@plt+0x114e8>
   15492:	e8 89 3f ff ff       	call   9420 <error@plt>
   15497:	e9 4f fd ff ff       	jmp    151eb <gnutls_reauth@plt+0xbbbb>
   1549c:	31 f6                	xor    esi,esi
   1549e:	31 c0                	xor    eax,eax
   154a0:	48 8d 0d 18 3b 00 00 	lea    rcx,[rip+0x3b18]        # 18fbf <gnutls_reauth@plt+0xf98f>
   154a7:	bf 01 00 00 00       	mov    edi,0x1
   154ac:	48 8d 15 15 56 00 00 	lea    rdx,[rip+0x5615]        # 1aac8 <gnutls_reauth@plt+0x11498>
   154b3:	e8 68 3f ff ff       	call   9420 <error@plt>
   154b8:	41 80 3f 00          	cmp    BYTE PTR [r15],0x0
   154bc:	0f 84 a9 fc ff ff    	je     1516b <gnutls_reauth@plt+0xbb3b>
   154c2:	45 8b 87 48 01 00 00 	mov    r8d,DWORD PTR [r15+0x148]
   154c9:	41 81 f8 0f 27 00 00 	cmp    r8d,0x270f
   154d0:	0f 8e 95 fc ff ff    	jle    1516b <gnutls_reauth@plt+0xbb3b>
   154d6:	e9 7f fe ff ff       	jmp    1535a <gnutls_reauth@plt+0xbd2a>
   154db:	31 f6                	xor    esi,esi
   154dd:	31 c0                	xor    eax,eax
   154df:	48 8d 0d f7 3a 00 00 	lea    rcx,[rip+0x3af7]        # 18fdd <gnutls_reauth@plt+0xf9ad>
   154e6:	bf 01 00 00 00       	mov    edi,0x1
   154eb:	48 8d 15 d6 55 00 00 	lea    rdx,[rip+0x55d6]        # 1aac8 <gnutls_reauth@plt+0x11498>
   154f2:	e8 29 3f ff ff       	call   9420 <error@plt>
   154f7:	41 80 7f 10 00       	cmp    BYTE PTR [r15+0x10],0x0
   154fc:	0f 84 9f fc ff ff    	je     151a1 <gnutls_reauth@plt+0xbb71>
   15502:	45 8b 87 4c 01 00 00 	mov    r8d,DWORD PTR [r15+0x14c]
   15509:	41 81 f8 68 42 00 00 	cmp    r8d,0x4268
   15510:	0f 8e 8b fc ff ff    	jle    151a1 <gnutls_reauth@plt+0xbb71>
   15516:	e9 88 fe ff ff       	jmp    153a3 <gnutls_reauth@plt+0xbd73>
   1551b:	31 f6                	xor    esi,esi
   1551d:	31 c0                	xor    eax,eax
   1551f:	48 8d 0d 1f 3b 00 00 	lea    rcx,[rip+0x3b1f]        # 19045 <gnutls_reauth@plt+0xfa15>
   15526:	bf 01 00 00 00       	mov    edi,0x1
   1552b:	48 8d 15 96 55 00 00 	lea    rdx,[rip+0x5596]        # 1aac8 <gnutls_reauth@plt+0x11498>
   15532:	e8 e9 3e ff ff       	call   9420 <error@plt>
   15537:	41 80 7f 34 00       	cmp    BYTE PTR [r15+0x34],0x0
   1553c:	0f 84 cd fc ff ff    	je     1520f <gnutls_reauth@plt+0xbbdf>
   15542:	45 8b 87 54 01 00 00 	mov    r8d,DWORD PTR [r15+0x154]
   15549:	41 81 f8 00 10 00 00 	cmp    r8d,0x1000
   15550:	0f 8e b9 fc ff ff    	jle    1520f <gnutls_reauth@plt+0xbbdf>
   15556:	e9 de fd ff ff       	jmp    15339 <gnutls_reauth@plt+0xbd09>
   1555b:	e8 40 3a ff ff       	call   8fa0 <__errno_location@plt>
   15560:	48 8d 15 ee 3a 00 00 	lea    rdx,[rip+0x3aee]        # 19055 <gnutls_reauth@plt+0xfa25>
   15567:	bf 01 00 00 00       	mov    edi,0x1
   1556c:	8b 30                	mov    esi,DWORD PTR [rax]
   1556e:	31 c0                	xor    eax,eax
   15570:	e8 ab 3e ff ff       	call   9420 <error@plt>
   15575:	8b 7c 24 0c          	mov    edi,DWORD PTR [rsp+0xc]
   15579:	e8 12 2f ff ff       	call   8490 <close@plt>
   1557e:	8b 7c 24 08          	mov    edi,DWORD PTR [rsp+0x8]
   15582:	31 f6                	xor    esi,esi
   15584:	e8 37 2e ff ff       	call   83c0 <dup2@plt>
   15589:	8b 7c 24 08          	mov    edi,DWORD PTR [rsp+0x8]
   1558d:	e8 fe 2e ff ff       	call   8490 <close@plt>
   15592:	48 8d 3d c1 3a 00 00 	lea    rdi,[rip+0x3ac1]        # 1905a <gnutls_reauth@plt+0xfa2a>
   15599:	e8 82 34 ff ff       	call   8a20 <secure_getenv@plt>
   1559e:	48 89 c7             	mov    rdi,rax
   155a1:	48 85 c0             	test   rax,rax
   155a4:	74 05                	je     155ab <gnutls_reauth@plt+0xbf7b>
   155a6:	80 38 00             	cmp    BYTE PTR [rax],0x0
   155a9:	75 07                	jne    155b2 <gnutls_reauth@plt+0xbf82>
   155ab:	48 8d 3d e5 39 00 00 	lea    rdi,[rip+0x39e5]        # 18f97 <gnutls_reauth@plt+0xf967>
   155b2:	48 8d 74 24 10       	lea    rsi,[rsp+0x10]
   155b7:	48 89 7c 24 10       	mov    QWORD PTR [rsp+0x10],rdi
   155bc:	48 c7 44 24 18 00 00 	mov    QWORD PTR [rsp+0x18],0x0
   155c3:	00 00 
   155c5:	e8 16 30 ff ff       	call   85e0 <execvp@plt>
   155ca:	bf 01 00 00 00       	mov    edi,0x1
   155cf:	e8 1c 30 ff ff       	call   85f0 <exit@plt>
   155d4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   155d8:	e8 c3 39 ff ff       	call   8fa0 <__errno_location@plt>
   155dd:	48 8d 15 6c 3a 00 00 	lea    rdx,[rip+0x3a6c]        # 19050 <gnutls_reauth@plt+0xfa20>
   155e4:	bf 01 00 00 00       	mov    edi,0x1
   155e9:	8b 30                	mov    esi,DWORD PTR [rax]
   155eb:	31 c0                	xor    eax,eax
   155ed:	e8 2e 3e ff ff       	call   9420 <error@plt>
   155f2:	e9 e3 fc ff ff       	jmp    152da <gnutls_reauth@plt+0xbcaa>
   155f7:	48 8d 7c 24 20       	lea    rdi,[rsp+0x20]
   155fc:	48 8d 35 ed 55 00 00 	lea    rsi,[rip+0x55ed]        # 1abf0 <gnutls_reauth@plt+0x115c0>
   15603:	b9 28 00 00 00       	mov    ecx,0x28
   15608:	f3 48 a5             	rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi]
   1560b:	0f b7 06             	movzx  eax,WORD PTR [rsi]
   1560e:	66 89 07             	mov    WORD PTR [rdi],ax
   15611:	0f b6 05 1a 57 00 00 	movzx  eax,BYTE PTR [rip+0x571a]        # 1ad32 <gnutls_reauth@plt+0x11702>
   15618:	88 47 02             	mov    BYTE PTR [rdi+0x2],al
   1561b:	48 8b 05 c6 a9 00 00 	mov    rax,QWORD PTR [rip+0xa9c6]        # 1ffe8 <gnutls_reauth@plt+0x169b8>
   15622:	48 8d 4c 24 20       	lea    rcx,[rsp+0x20]
   15627:	be 01 00 00 00       	mov    esi,0x1
   1562c:	48 8d 15 63 15 00 00 	lea    rdx,[rip+0x1563]        # 16b96 <gnutls_reauth@plt+0xd566>
   15633:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   15636:	31 c0                	xor    eax,eax
   15638:	e8 13 2f ff ff       	call   8550 <__fprintf_chk@plt>
   1563d:	31 ff                	xor    edi,edi
   1563f:	e8 ac 2f ff ff       	call   85f0 <exit@plt>
   15644:	e8 d7 39 ff ff       	call   9020 <__stack_chk_fail@plt>
   15649:	66 0f 6f 05 8f 5d 00 	movdqa xmm0,XMMWORD PTR [rip+0x5d8f]        # 1b3e0 <gnutls_reauth@plt+0x11db0>
   15650:	00 
   15651:	66 c7 44 24 30 0a 00 	mov    WORD PTR [rsp+0x30],0xa
   15658:	0f 29 44 24 20       	movaps XMMWORD PTR [rsp+0x20],xmm0
   1565d:	eb bc                	jmp    1561b <gnutls_reauth@plt+0xbfeb>
   1565f:	48 8d 7c 24 20       	lea    rdi,[rsp+0x20]
   15664:	48 8d 35 cd 56 00 00 	lea    rsi,[rip+0x56cd]        # 1ad38 <gnutls_reauth@plt+0x11708>
   1566b:	b9 73 00 00 00       	mov    ecx,0x73
   15670:	f3 48 a5             	rep movs QWORD PTR es:[rdi],QWORD PTR ds:[rsi]
   15673:	0f b7 06             	movzx  eax,WORD PTR [rsi]
   15676:	66 89 07             	mov    WORD PTR [rdi],ax
   15679:	0f b6 05 52 5a 00 00 	movzx  eax,BYTE PTR [rip+0x5a52]        # 1b0d2 <gnutls_reauth@plt+0x11aa2>
   15680:	88 47 02             	mov    BYTE PTR [rdi+0x2],al
   15683:	eb 96                	jmp    1561b <gnutls_reauth@plt+0xbfeb>
   15685:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1568c:	00 00 00 
   1568f:	90                   	nop
   15690:	f3 0f 1e fa          	endbr64 
   15694:	83 ff 5a             	cmp    edi,0x5a
   15697:	7f 17                	jg     156b0 <gnutls_reauth@plt+0xc080>
   15699:	b8 01 00 00 00       	mov    eax,0x1
   1569e:	83 ff 40             	cmp    edi,0x40
   156a1:	7f 16                	jg     156b9 <gnutls_reauth@plt+0xc089>
   156a3:	83 ef 30             	sub    edi,0x30
   156a6:	83 ff 09             	cmp    edi,0x9
   156a9:	0f 96 c0             	setbe  al
   156ac:	c3                   	ret    
   156ad:	0f 1f 00             	nop    DWORD PTR [rax]
   156b0:	83 ef 61             	sub    edi,0x61
   156b3:	83 ff 19             	cmp    edi,0x19
   156b6:	0f 96 c0             	setbe  al
   156b9:	c3                   	ret    
   156ba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   156c0:	f3 0f 1e fa          	endbr64 
   156c4:	83 ff 5a             	cmp    edi,0x5a
   156c7:	7f 07                	jg     156d0 <gnutls_reauth@plt+0xc0a0>
   156c9:	83 ff 40             	cmp    edi,0x40
   156cc:	0f 9f c0             	setg   al
   156cf:	c3                   	ret    
   156d0:	83 ef 61             	sub    edi,0x61
   156d3:	83 ff 19             	cmp    edi,0x19
   156d6:	0f 96 c0             	setbe  al
   156d9:	c3                   	ret    
   156da:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   156e0:	f3 0f 1e fa          	endbr64 
   156e4:	83 ff 7f             	cmp    edi,0x7f
   156e7:	0f 96 c0             	setbe  al
   156ea:	c3                   	ret    
   156eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   156f0:	f3 0f 1e fa          	endbr64 
   156f4:	83 ff 20             	cmp    edi,0x20
   156f7:	0f 94 c0             	sete   al
   156fa:	83 ff 09             	cmp    edi,0x9
   156fd:	0f 94 c2             	sete   dl
   15700:	09 d0                	or     eax,edx
   15702:	c3                   	ret    
   15703:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1570a:	00 00 00 00 
   1570e:	66 90                	xchg   ax,ax
   15710:	f3 0f 1e fa          	endbr64 
   15714:	83 ff 1f             	cmp    edi,0x1f
   15717:	7f 0f                	jg     15728 <gnutls_reauth@plt+0xc0f8>
   15719:	f7 d7                	not    edi
   1571b:	c1 ef 1f             	shr    edi,0x1f
   1571e:	89 f8                	mov    eax,edi
   15720:	c3                   	ret    
   15721:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   15728:	83 ff 7f             	cmp    edi,0x7f
   1572b:	0f 94 c0             	sete   al
   1572e:	c3                   	ret    
   1572f:	90                   	nop
   15730:	f3 0f 1e fa          	endbr64 
   15734:	83 ef 30             	sub    edi,0x30
   15737:	83 ff 09             	cmp    edi,0x9
   1573a:	0f 96 c0             	setbe  al
   1573d:	c3                   	ret    
   1573e:	66 90                	xchg   ax,ax
   15740:	f3 0f 1e fa          	endbr64 
   15744:	83 ef 21             	sub    edi,0x21
   15747:	83 ff 5d             	cmp    edi,0x5d
   1574a:	0f 96 c0             	setbe  al
   1574d:	c3                   	ret    
   1574e:	66 90                	xchg   ax,ax
   15750:	f3 0f 1e fa          	endbr64 
   15754:	83 ef 61             	sub    edi,0x61
   15757:	83 ff 19             	cmp    edi,0x19
   1575a:	0f 96 c0             	setbe  al
   1575d:	c3                   	ret    
   1575e:	66 90                	xchg   ax,ax
   15760:	f3 0f 1e fa          	endbr64 
   15764:	83 ef 20             	sub    edi,0x20
   15767:	83 ff 5e             	cmp    edi,0x5e
   1576a:	0f 96 c0             	setbe  al
   1576d:	c3                   	ret    
   1576e:	66 90                	xchg   ax,ax
   15770:	f3 0f 1e fa          	endbr64 
   15774:	83 ff 60             	cmp    edi,0x60
   15777:	7f 17                	jg     15790 <gnutls_reauth@plt+0xc160>
   15779:	83 ff 5a             	cmp    edi,0x5a
   1577c:	7f 32                	jg     157b0 <gnutls_reauth@plt+0xc180>
   1577e:	83 ff 2f             	cmp    edi,0x2f
   15781:	7f 1d                	jg     157a0 <gnutls_reauth@plt+0xc170>
   15783:	83 ff 20             	cmp    edi,0x20
   15786:	0f 9f c0             	setg   al
   15789:	c3                   	ret    
   1578a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   15790:	83 ef 7b             	sub    edi,0x7b
   15793:	83 ff 03             	cmp    edi,0x3
   15796:	0f 96 c0             	setbe  al
   15799:	c3                   	ret    
   1579a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   157a0:	83 ef 3a             	sub    edi,0x3a
   157a3:	83 ff 06             	cmp    edi,0x6
   157a6:	0f 96 c0             	setbe  al
   157a9:	c3                   	ret    
   157aa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   157b0:	b8 01 00 00 00       	mov    eax,0x1
   157b5:	c3                   	ret    
   157b6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   157bd:	00 00 00 
   157c0:	f3 0f 1e fa          	endbr64 
   157c4:	83 ff 0d             	cmp    edi,0xd
   157c7:	7f 07                	jg     157d0 <gnutls_reauth@plt+0xc1a0>
   157c9:	83 ff 08             	cmp    edi,0x8
   157cc:	0f 9f c0             	setg   al
   157cf:	c3                   	ret    
   157d0:	83 ff 20             	cmp    edi,0x20
   157d3:	0f 94 c0             	sete   al
   157d6:	c3                   	ret    
   157d7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   157de:	00 00 
   157e0:	f3 0f 1e fa          	endbr64 
   157e4:	83 ef 41             	sub    edi,0x41
   157e7:	83 ff 19             	cmp    edi,0x19
   157ea:	0f 96 c0             	setbe  al
   157ed:	c3                   	ret    
   157ee:	66 90                	xchg   ax,ax
   157f0:	f3 0f 1e fa          	endbr64 
   157f4:	8d 4f d0             	lea    ecx,[rdi-0x30]
   157f7:	83 f9 36             	cmp    ecx,0x36
   157fa:	77 14                	ja     15810 <gnutls_reauth@plt+0xc1e0>
   157fc:	48 b8 ff 03 7e 00 00 	movabs rax,0x7e0000007e03ff
   15803:	00 7e 00 
   15806:	48 d3 e8             	shr    rax,cl
   15809:	83 e0 01             	and    eax,0x1
   1580c:	c3                   	ret    
   1580d:	0f 1f 00             	nop    DWORD PTR [rax]
   15810:	31 c0                	xor    eax,eax
   15812:	c3                   	ret    
   15813:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1581a:	00 00 00 00 
   1581e:	66 90                	xchg   ax,ax
   15820:	f3 0f 1e fa          	endbr64 
   15824:	8d 4f bf             	lea    ecx,[rdi-0x41]
   15827:	89 f8                	mov    eax,edi
   15829:	8d 57 20             	lea    edx,[rdi+0x20]
   1582c:	83 f9 1a             	cmp    ecx,0x1a
   1582f:	0f 42 c2             	cmovb  eax,edx
   15832:	c3                   	ret    
   15833:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1583a:	00 00 00 00 
   1583e:	66 90                	xchg   ax,ax
   15840:	f3 0f 1e fa          	endbr64 
   15844:	8d 4f 9f             	lea    ecx,[rdi-0x61]
   15847:	89 f8                	mov    eax,edi
   15849:	8d 57 e0             	lea    edx,[rdi-0x20]
   1584c:	83 f9 1a             	cmp    ecx,0x1a
   1584f:	0f 42 c2             	cmovb  eax,edx
   15852:	c3                   	ret    
   15853:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1585a:	00 00 00 
   1585d:	0f 1f 00             	nop    DWORD PTR [rax]
   15860:	f3 0f 1e fa          	endbr64 
   15864:	41 57                	push   r15
   15866:	41 56                	push   r14
   15868:	41 55                	push   r13
   1586a:	41 54                	push   r12
   1586c:	55                   	push   rbp
   1586d:	53                   	push   rbx
   1586e:	48 81 ec c8 00 00 00 	sub    rsp,0xc8
   15875:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
   1587a:	89 74 24 14          	mov    DWORD PTR [rsp+0x14],esi
   1587e:	48 89 54 24 18       	mov    QWORD PTR [rsp+0x18],rdx
   15883:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1588a:	00 00 
   1588c:	48 89 84 24 b8 00 00 	mov    QWORD PTR [rsp+0xb8],rax
   15893:	00 
   15894:	31 c0                	xor    eax,eax
   15896:	e8 05 2b ff ff       	call   83a0 <fileno@plt>
   1589b:	48 8d 74 24 20       	lea    rsi,[rsp+0x20]
   158a0:	89 c7                	mov    edi,eax
   158a2:	e8 99 2d ff ff       	call   8640 <fstat@plt>
   158a7:	85 c0                	test   eax,eax
   158a9:	78 14                	js     158bf <gnutls_reauth@plt+0xc28f>
   158ab:	8b 44 24 38          	mov    eax,DWORD PTR [rsp+0x38]
   158af:	25 00 f0 00 00       	and    eax,0xf000
   158b4:	3d 00 80 00 00       	cmp    eax,0x8000
   158b9:	0f 84 01 02 00 00    	je     15ac0 <gnutls_reauth@plt+0xc490>
   158bf:	41 bd 00 20 00 00    	mov    r13d,0x2000
   158c5:	4c 89 ef             	mov    rdi,r13
   158c8:	e8 d3 2e ff ff       	call   87a0 <malloc@plt>
   158cd:	48 89 c5             	mov    rbp,rax
   158d0:	48 85 c0             	test   rax,rax
   158d3:	0f 84 ed 00 00 00    	je     159c6 <gnutls_reauth@plt+0xc396>
   158d9:	49 be ff ff ff ff ff 	movabs r14,0x7fffffffffffffff
   158e0:	ff ff 7f 
   158e3:	31 db                	xor    ebx,ebx
   158e5:	eb 4b                	jmp    15932 <gnutls_reauth@plt+0xc302>
   158e7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   158ee:	00 00 
   158f0:	48 89 c7             	mov    rdi,rax
   158f3:	e8 a8 2e ff ff       	call   87a0 <malloc@plt>
   158f8:	49 89 c7             	mov    r15,rax
   158fb:	48 85 c0             	test   rax,rax
   158fe:	0f 84 76 01 00 00    	je     15a7a <gnutls_reauth@plt+0xc44a>
   15904:	48 89 ee             	mov    rsi,rbp
   15907:	4c 89 ea             	mov    rdx,r13
   1590a:	48 89 c7             	mov    rdi,rax
   1590d:	e8 2e 3c ff ff       	call   9540 <memcpy@plt>
   15912:	48 89 ef             	mov    rdi,rbp
   15915:	48 c7 c2 ff ff ff ff 	mov    rdx,0xffffffffffffffff
   1591c:	4c 89 ee             	mov    rsi,r13
   1591f:	e8 bc 33 ff ff       	call   8ce0 <__explicit_bzero_chk@plt>
   15924:	48 89 ef             	mov    rdi,rbp
   15927:	4c 89 fd             	mov    rbp,r15
   1592a:	e8 d1 30 ff ff       	call   8a00 <free@plt>
   1592f:	4d 89 e5             	mov    r13,r12
   15932:	4d 89 ef             	mov    r15,r13
   15935:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   1593a:	48 8d 7c 1d 00       	lea    rdi,[rbp+rbx*1+0x0]
   1593f:	be 01 00 00 00       	mov    esi,0x1
   15944:	49 29 df             	sub    r15,rbx
   15947:	4c 89 fa             	mov    rdx,r15
   1594a:	e8 b1 35 ff ff       	call   8f00 <fread@plt>
   1594f:	48 01 c3             	add    rbx,rax
   15952:	49 39 c7             	cmp    r15,rax
   15955:	0f 85 9d 00 00 00    	jne    159f8 <gnutls_reauth@plt+0xc3c8>
   1595b:	4d 39 f5             	cmp    r13,r14
   1595e:	74 40                	je     159a0 <gnutls_reauth@plt+0xc370>
   15960:	4c 89 e8             	mov    rax,r13
   15963:	4c 89 f2             	mov    rdx,r14
   15966:	48 d1 e8             	shr    rax,1
   15969:	48 29 c2             	sub    rdx,rax
   1596c:	4c 01 e8             	add    rax,r13
   1596f:	4c 39 ea             	cmp    rdx,r13
   15972:	49 0f 46 c6          	cmovbe rax,r14
   15976:	49 89 c4             	mov    r12,rax
   15979:	f6 44 24 14 02       	test   BYTE PTR [rsp+0x14],0x2
   1597e:	0f 85 6c ff ff ff    	jne    158f0 <gnutls_reauth@plt+0xc2c0>
   15984:	48 89 c6             	mov    rsi,rax
   15987:	48 89 ef             	mov    rdi,rbp
   1598a:	e8 31 3a ff ff       	call   93c0 <realloc@plt>
   1598f:	48 85 c0             	test   rax,rax
   15992:	0f 84 18 01 00 00    	je     15ab0 <gnutls_reauth@plt+0xc480>
   15998:	48 89 c5             	mov    rbp,rax
   1599b:	eb 92                	jmp    1592f <gnutls_reauth@plt+0xc2ff>
   1599d:	0f 1f 00             	nop    DWORD PTR [rax]
   159a0:	e8 fb 35 ff ff       	call   8fa0 <__errno_location@plt>
   159a5:	41 bf 0c 00 00 00    	mov    r15d,0xc
   159ab:	49 89 c6             	mov    r14,rax
   159ae:	f6 44 24 14 02       	test   BYTE PTR [rsp+0x14],0x2
   159b3:	0f 85 d7 00 00 00    	jne    15a90 <gnutls_reauth@plt+0xc460>
   159b9:	48 89 ef             	mov    rdi,rbp
   159bc:	31 ed                	xor    ebp,ebp
   159be:	e8 3d 30 ff ff       	call   8a00 <free@plt>
   159c3:	45 89 3e             	mov    DWORD PTR [r14],r15d
   159c6:	48 8b 84 24 b8 00 00 	mov    rax,QWORD PTR [rsp+0xb8]
   159cd:	00 
   159ce:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   159d5:	00 00 
   159d7:	0f 85 60 01 00 00    	jne    15b3d <gnutls_reauth@plt+0xc50d>
   159dd:	48 81 c4 c8 00 00 00 	add    rsp,0xc8
   159e4:	48 89 e8             	mov    rax,rbp
   159e7:	5b                   	pop    rbx
   159e8:	5d                   	pop    rbp
   159e9:	41 5c                	pop    r12
   159eb:	41 5d                	pop    r13
   159ed:	41 5e                	pop    r14
   159ef:	41 5f                	pop    r15
   159f1:	c3                   	ret    
   159f2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   159f8:	e8 a3 35 ff ff       	call   8fa0 <__errno_location@plt>
   159fd:	48 8b 7c 24 08       	mov    rdi,QWORD PTR [rsp+0x8]
   15a02:	44 8b 38             	mov    r15d,DWORD PTR [rax]
   15a05:	49 89 c6             	mov    r14,rax
   15a08:	e8 53 30 ff ff       	call   8a60 <ferror@plt>
   15a0d:	85 c0                	test   eax,eax
   15a0f:	75 9d                	jne    159ae <gnutls_reauth@plt+0xc37e>
   15a11:	49 8d 45 ff          	lea    rax,[r13-0x1]
   15a15:	48 39 d8             	cmp    rax,rbx
   15a18:	76 4e                	jbe    15a68 <gnutls_reauth@plt+0xc438>
   15a1a:	48 8d 73 01          	lea    rsi,[rbx+0x1]
   15a1e:	f6 44 24 14 02       	test   BYTE PTR [rsp+0x14],0x2
   15a23:	0f 84 e7 00 00 00    	je     15b10 <gnutls_reauth@plt+0xc4e0>
   15a29:	48 89 f7             	mov    rdi,rsi
   15a2c:	e8 6f 2d ff ff       	call   87a0 <malloc@plt>
   15a31:	49 89 c4             	mov    r12,rax
   15a34:	48 85 c0             	test   rax,rax
   15a37:	0f 84 e7 00 00 00    	je     15b24 <gnutls_reauth@plt+0xc4f4>
   15a3d:	48 89 ee             	mov    rsi,rbp
   15a40:	48 89 da             	mov    rdx,rbx
   15a43:	48 89 c7             	mov    rdi,rax
   15a46:	e8 f5 3a ff ff       	call   9540 <memcpy@plt>
   15a4b:	48 89 ef             	mov    rdi,rbp
   15a4e:	48 c7 c2 ff ff ff ff 	mov    rdx,0xffffffffffffffff
   15a55:	4c 89 ee             	mov    rsi,r13
   15a58:	e8 83 32 ff ff       	call   8ce0 <__explicit_bzero_chk@plt>
   15a5d:	48 89 ef             	mov    rdi,rbp
   15a60:	4c 89 e5             	mov    rbp,r12
   15a63:	e8 98 2f ff ff       	call   8a00 <free@plt>
   15a68:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   15a6d:	c6 44 1d 00 00       	mov    BYTE PTR [rbp+rbx*1+0x0],0x0
   15a72:	48 89 18             	mov    QWORD PTR [rax],rbx
   15a75:	e9 4c ff ff ff       	jmp    159c6 <gnutls_reauth@plt+0xc396>
   15a7a:	e8 21 35 ff ff       	call   8fa0 <__errno_location@plt>
   15a7f:	4d 89 e5             	mov    r13,r12
   15a82:	44 8b 38             	mov    r15d,DWORD PTR [rax]
   15a85:	49 89 c6             	mov    r14,rax
   15a88:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   15a8f:	00 
   15a90:	48 c7 c2 ff ff ff ff 	mov    rdx,0xffffffffffffffff
   15a97:	4c 89 ee             	mov    rsi,r13
   15a9a:	48 89 ef             	mov    rdi,rbp
   15a9d:	e8 3e 32 ff ff       	call   8ce0 <__explicit_bzero_chk@plt>
   15aa2:	e9 12 ff ff ff       	jmp    159b9 <gnutls_reauth@plt+0xc389>
   15aa7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   15aae:	00 00 
   15ab0:	e8 eb 34 ff ff       	call   8fa0 <__errno_location@plt>
   15ab5:	44 8b 38             	mov    r15d,DWORD PTR [rax]
   15ab8:	49 89 c6             	mov    r14,rax
   15abb:	e9 f9 fe ff ff       	jmp    159b9 <gnutls_reauth@plt+0xc389>
   15ac0:	48 8b 7c 24 08       	mov    rdi,QWORD PTR [rsp+0x8]
   15ac5:	e8 76 31 ff ff       	call   8c40 <ftello@plt>
   15aca:	48 85 c0             	test   rax,rax
   15acd:	0f 88 ec fd ff ff    	js     158bf <gnutls_reauth@plt+0xc28f>
   15ad3:	48 8b 54 24 50       	mov    rdx,QWORD PTR [rsp+0x50]
   15ad8:	48 39 c2             	cmp    rdx,rax
   15adb:	0f 8e de fd ff ff    	jle    158bf <gnutls_reauth@plt+0xc28f>
   15ae1:	48 29 c2             	sub    rdx,rax
   15ae4:	48 b8 ff ff ff ff ff 	movabs rax,0x7fffffffffffffff
   15aeb:	ff ff 7f 
   15aee:	4c 8d 6a 01          	lea    r13,[rdx+0x1]
   15af2:	48 39 c2             	cmp    rdx,rax
   15af5:	0f 85 ca fd ff ff    	jne    158c5 <gnutls_reauth@plt+0xc295>
   15afb:	e8 a0 34 ff ff       	call   8fa0 <__errno_location@plt>
   15b00:	31 ed                	xor    ebp,ebp
   15b02:	c7 00 0c 00 00 00    	mov    DWORD PTR [rax],0xc
   15b08:	e9 b9 fe ff ff       	jmp    159c6 <gnutls_reauth@plt+0xc396>
   15b0d:	0f 1f 00             	nop    DWORD PTR [rax]
   15b10:	48 89 ef             	mov    rdi,rbp
   15b13:	e8 a8 38 ff ff       	call   93c0 <realloc@plt>
   15b18:	48 85 c0             	test   rax,rax
   15b1b:	48 0f 45 e8          	cmovne rbp,rax
   15b1f:	e9 44 ff ff ff       	jmp    15a68 <gnutls_reauth@plt+0xc438>
   15b24:	4c 89 ee             	mov    rsi,r13
   15b27:	48 8d 7c 1d 00       	lea    rdi,[rbp+rbx*1+0x0]
   15b2c:	48 83 ca ff          	or     rdx,0xffffffffffffffff
   15b30:	48 29 de             	sub    rsi,rbx
   15b33:	e8 a8 31 ff ff       	call   8ce0 <__explicit_bzero_chk@plt>
   15b38:	e9 2b ff ff ff       	jmp    15a68 <gnutls_reauth@plt+0xc438>
   15b3d:	e8 de 34 ff ff       	call   9020 <__stack_chk_fail@plt>
   15b42:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   15b49:	00 00 00 00 
   15b4d:	0f 1f 00             	nop    DWORD PTR [rax]
   15b50:	f3 0f 1e fa          	endbr64 
   15b54:	41 56                	push   r14
   15b56:	48 8d 05 f2 36 00 00 	lea    rax,[rip+0x36f2]        # 1924f <gnutls_reauth@plt+0xfc1f>
   15b5d:	41 55                	push   r13
   15b5f:	41 54                	push   r12
   15b61:	55                   	push   rbp
   15b62:	89 f5                	mov    ebp,esi
   15b64:	83 e6 01             	and    esi,0x1
   15b67:	48 8d 35 82 58 00 00 	lea    rsi,[rip+0x5882]        # 1b3f0 <gnutls_reauth@plt+0x11dc0>
   15b6e:	53                   	push   rbx
   15b6f:	48 0f 44 f0          	cmove  rsi,rax
   15b73:	48 89 d3             	mov    rbx,rdx
   15b76:	e8 35 2c ff ff       	call   87b0 <fopen@plt>
   15b7b:	48 85 c0             	test   rax,rax
   15b7e:	74 62                	je     15be2 <gnutls_reauth@plt+0xc5b2>
   15b80:	41 89 ee             	mov    r14d,ebp
   15b83:	49 89 c4             	mov    r12,rax
   15b86:	41 83 e6 02          	and    r14d,0x2
   15b8a:	75 2c                	jne    15bb8 <gnutls_reauth@plt+0xc588>
   15b8c:	4c 89 e7             	mov    rdi,r12
   15b8f:	48 89 da             	mov    rdx,rbx
   15b92:	89 ee                	mov    esi,ebp
   15b94:	e8 c7 fc ff ff       	call   15860 <gnutls_reauth@plt+0xc230>
   15b99:	4c 89 e7             	mov    rdi,r12
   15b9c:	49 89 c5             	mov    r13,rax
   15b9f:	e8 3c 36 ff ff       	call   91e0 <fclose@plt>
   15ba4:	85 c0                	test   eax,eax
   15ba6:	75 28                	jne    15bd0 <gnutls_reauth@plt+0xc5a0>
   15ba8:	5b                   	pop    rbx
   15ba9:	4c 89 e8             	mov    rax,r13
   15bac:	5d                   	pop    rbp
   15bad:	41 5c                	pop    r12
   15baf:	41 5d                	pop    r13
   15bb1:	41 5e                	pop    r14
   15bb3:	c3                   	ret    
   15bb4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   15bb8:	31 c9                	xor    ecx,ecx
   15bba:	ba 02 00 00 00       	mov    edx,0x2
   15bbf:	31 f6                	xor    esi,esi
   15bc1:	48 89 c7             	mov    rdi,rax
   15bc4:	e8 f7 2a ff ff       	call   86c0 <setvbuf@plt>
   15bc9:	eb c1                	jmp    15b8c <gnutls_reauth@plt+0xc55c>
   15bcb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   15bd0:	4d 85 ed             	test   r13,r13
   15bd3:	74 0d                	je     15be2 <gnutls_reauth@plt+0xc5b2>
   15bd5:	45 85 f6             	test   r14d,r14d
   15bd8:	75 1e                	jne    15bf8 <gnutls_reauth@plt+0xc5c8>
   15bda:	4c 89 ef             	mov    rdi,r13
   15bdd:	e8 1e 2e ff ff       	call   8a00 <free@plt>
   15be2:	45 31 ed             	xor    r13d,r13d
   15be5:	5b                   	pop    rbx
   15be6:	5d                   	pop    rbp
   15be7:	4c 89 e8             	mov    rax,r13
   15bea:	41 5c                	pop    r12
   15bec:	41 5d                	pop    r13
   15bee:	41 5e                	pop    r14
   15bf0:	c3                   	ret    
   15bf1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   15bf8:	48 8b 33             	mov    rsi,QWORD PTR [rbx]
   15bfb:	48                   	rex.W
   15bfc:	c7                   	.byte 0xc7
   15bfd:	c2 ff ff             	ret    0xffff

codex
The signature is now recoverable as an optional OCSP URL, certificate, issuer, output datum, and optional nonce. I also confirmed the fallback URI search: it scans the certificate’s AIA entries, then the issuer’s, skipping non-OCSP entries; the successful return is `0`, while receive/body errors normalize to `-1`.
Target control flow and data types are resolved from the assembly and direct helper inspection.
  ✓ Inspect binary metadata, target disassembly, constants, and relocations
  ✓ Infer helper semantics and reconstruct structured control flow
  → Write decompiled.c and verify the output contract
apply patch
patch: completed
/tmp/llmdec_codex_366ssvk9/decompiled.c
diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..d66ef1ae97b4ae964c6904864e96f210cd14eb7a
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..d66ef1ae97b4ae964c6904864e96f210cd14eb7a
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

codex
The C is written. I’m doing a final contract and fidelity pass now, including checking the one observed GnuTLS sentinel value and ensuring no extra top-level function definitions slipped into the file.
exec
/bin/bash -lc 'file /usr/include/gnutls/gnutls.h ./decompiled.c
xxd -g 1 -s 0 -l 256 ./decompiled.c
xxd -g 1 -s 0 -l 64 /usr/include/gnutls/gnutls.h' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:
/usr/include/gnutls/gnutls.h: C source, ASCII text, with very long lines (386)
./decompiled.c:               C source, ASCII text
00000000: 23 69 6e 63 6c 75 64 65 20 3c 73 69 67 6e 61 6c  #include <signal
00000010: 2e 68 3e 0a 23 69 6e 63 6c 75 64 65 20 3c 73 74  .h>.#include <st
00000020: 64 64 65 66 2e 68 3e 0a 23 69 6e 63 6c 75 64 65  ddef.h>.#include
00000030: 20 3c 73 74 64 69 6f 2e 68 3e 0a 23 69 6e 63 6c   <stdio.h>.#incl
00000040: 75 64 65 20 3c 73 74 64 6c 69 62 2e 68 3e 0a 23  ude <stdlib.h>.#
00000050: 69 6e 63 6c 75 64 65 20 3c 73 74 72 69 6e 67 2e  include <string.
00000060: 68 3e 0a 23 69 6e 63 6c 75 64 65 20 3c 73 79 73  h>.#include <sys
00000070: 2f 74 79 70 65 73 2e 68 3e 0a 0a 74 79 70 65 64  /types.h>..typed
00000080: 65 66 20 76 6f 69 64 20 2a 67 6e 75 74 6c 73 5f  ef void *gnutls_
00000090: 78 35 30 39 5f 63 72 74 5f 74 3b 0a 0a 74 79 70  x509_crt_t;..typ
000000a0: 65 64 65 66 20 73 74 72 75 63 74 20 7b 0a 20 20  edef struct {.  
000000b0: 20 20 75 6e 73 69 67 6e 65 64 20 63 68 61 72 20    unsigned char 
000000c0: 2a 64 61 74 61 3b 0a 20 20 20 20 75 6e 73 69 67  *data;.    unsig
000000d0: 6e 65 64 20 69 6e 74 20 73 69 7a 65 3b 0a 7d 20  ned int size;.} 
000000e0: 67 6e 75 74 6c 73 5f 64 61 74 75 6d 5f 74 3b 0a  gnutls_datum_t;.
000000f0: 0a 74 79 70 65 64 65 66 20 73 74 72 75 63 74 20  .typedef struct 
00000000: 2f 2a 20 2d 2a 2d 20 63 20 2d 2a 2d 0a 20 2a 20  /* -*- c -*-. * 
00000010: 43 6f 70 79 72 69 67 68 74 20 28 43 29 20 32 30  Copyright (C) 20
00000020: 30 30 2d 32 30 31 36 20 46 72 65 65 20 53 6f 66  00-2016 Free Sof
00000030: 74 77 61 72 65 20 46 6f 75 6e 64 61 74 69 6f 6e  tware Foundation

diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..d66ef1ae97b4ae964c6904864e96f210cd14eb7a
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

exec
/bin/bash -lc 'strings -a -t d /usr/include/gnutls/gnutls.h' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:
      0 /* -*- c -*-
     13  * Copyright (C) 2000-2016 Free Software Foundation, Inc.
     71  * Copyright (C) 2015-2017 Red Hat, Inc.
    115  * Author: Nikos Mavrogiannopoulos
    153  * This file is part of GnuTLS.
    188  * The GnuTLS is free software; you can redistribute it and/or
    251  * modify it under the terms of the GNU Lesser General Public License
    321  * as published by the Free Software Foundation; either version 2.1 of
    392  * the License, or (at your option) any later version.
    450  * This library is distributed in the hope that it will be useful, but
    521  * WITHOUT ANY WARRANTY; without even the implied warranty of
    583  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    652  * Lesser General Public License for more details.
    706  * You should have received a copy of the GNU Lesser General Public License
    782  * along with this program.  If not, see <https://www.gnu.org/licenses/>
    863 /* This file contains the types and prototypes for all the
    922  * high level functionality of the gnutls main library.
    981  * If the optional C++ binding was built, it is available in
   1042  * gnutls/gnutlsxx.h.
   1067  * The openssl compatibility layer (which is under the GNU GPL
   1130  * license) is in gnutls/openssl.h.
   1169  * The low level cipher functionality is in gnutls/crypto.h.
   1235 #ifndef GNUTLS_GNUTLS_H
   1259 #define GNUTLS_GNUTLS_H
   1284 /* Get ssize_t. */
   1303 #include <sys/types.h>
   1327 /* Get size_t. */
   1345 #include <stddef.h>
   1366 /* Get time_t. */
   1384 #include <time.h>
   1403 /* *INDENT-OFF* */
   1422 #ifdef __cplusplus
   1441 extern "C" {
   1454 #endif
   1461 /* *INDENT-ON* */
   1480 #define GNUTLS_VERSION "3.7.3"
   1512 #define GNUTLS_VERSION_MAJOR 3
   1543 #define GNUTLS_VERSION_MINOR 7
   1574 #define GNUTLS_VERSION_PATCH 3
   1606 #define GNUTLS_VERSION_NUMBER 0x030703
   1646 #define GNUTLS_CIPHER_RIJNDAEL_128_CBC GNUTLS_CIPHER_AES_128_CBC
   1711 #define GNUTLS_CIPHER_RIJNDAEL_256_CBC GNUTLS_CIPHER_AES_256_CBC
   1776 #define GNUTLS_CIPHER_RIJNDAEL_CBC GNUTLS_CIPHER_AES_128_CBC
   1837 #define GNUTLS_CIPHER_ARCFOUR GNUTLS_CIPHER_ARCFOUR_128
   1894 #if !defined(GNUTLS_INTERNAL_BUILD) && defined(_WIN32)
   1949 # define _SYM_EXPORT __declspec(dllimport)
   1992 #else
   1998 # define _SYM_EXPORT
   2019 #endif
   2027 #ifdef __GNUC__
   2043 # define __GNUTLS_CONST__  __attribute__((const))
   2093 # define __GNUTLS_PURE__  __attribute__((pure))
   2141 #else
   2147 # define __GNUTLS_CONST__
   2173 # define __GNUTLS_PURE__
   2198 #endif
   2207 /* Use the following definition globally in your program to disable
   2275  * implicit initialization of gnutls. */
   2316 #define GNUTLS_SKIP_GLOBAL_INIT int _gnutls_global_init_skip(void); \
   2386     int _gnutls_global_init_skip(void) {return 1;}
   2442  * gnutls_cipher_algorithm_t:
   2472  * @GNUTLS_CIPHER_UNKNOWN: Value to identify an unknown/unsupported algorithm.
   2551  * @GNUTLS_CIPHER_NULL: The NULL (identity) encryption algorithm.
   2617  * @GNUTLS_CIPHER_ARCFOUR_128: ARCFOUR stream cipher with 128-bit keys.
   2689  * @GNUTLS_CIPHER_3DES_CBC: 3DES in CBC mode.
   2735  * @GNUTLS_CIPHER_AES_128_CBC: AES in CBC mode with 128-bit keys.
   2801  * @GNUTLS_CIPHER_AES_192_CBC: AES in CBC mode with 192-bit keys.
   2867  * @GNUTLS_CIPHER_AES_256_CBC: AES in CBC mode with 256-bit keys.
   2933  * @GNUTLS_CIPHER_AES_128_CFB8: AES in CFB8 mode with 128-bit keys.
   3001  * @GNUTLS_CIPHER_AES_192_CFB8: AES in CFB8 mode with 192-bit keys.
   3069  * @GNUTLS_CIPHER_AES_256_CFB8: AES in CFB8 mode with 256-bit keys.
   3137  * @GNUTLS_CIPHER_ARCFOUR_40: ARCFOUR stream cipher with 40-bit keys.
   3207  * @GNUTLS_CIPHER_CAMELLIA_128_CBC: Camellia in CBC mode with 128-bit keys.
   3283  * @GNUTLS_CIPHER_CAMELLIA_192_CBC: Camellia in CBC mode with 192-bit keys.
   3359  * @GNUTLS_CIPHER_CAMELLIA_256_CBC: Camellia in CBC mode with 256-bit keys.
   3435  * @GNUTLS_CIPHER_RC2_40_CBC: RC2 in CBC mode with 40-bit keys.
   3499  * @GNUTLS_CIPHER_DES_CBC: DES in CBC mode (56-bit keys).
   3557  * @GNUTLS_CIPHER_AES_128_GCM: AES in GCM mode with 128-bit keys (AEAD).
   3630  * @GNUTLS_CIPHER_AES_256_GCM: AES in GCM mode with 256-bit keys (AEAD).
   3703  * @GNUTLS_CIPHER_AES_128_CCM: AES in CCM mode with 128-bit keys (AEAD).
   3776  * @GNUTLS_CIPHER_AES_256_CCM: AES in CCM mode with 256-bit keys (AEAD).
   3849  * @GNUTLS_CIPHER_AES_128_CCM_8: AES in CCM mode with 64-bit tag and 128-bit keys (AEAD).
   3939  * @GNUTLS_CIPHER_AES_256_CCM_8: AES in CCM mode with 64-bit tag and 256-bit keys (AEAD).
   4029  * @GNUTLS_CIPHER_CAMELLIA_128_GCM: CAMELLIA in GCM mode with 128-bit keys (AEAD).
   4112  * @GNUTLS_CIPHER_CAMELLIA_256_GCM: CAMELLIA in GCM mode with 256-bit keys (AEAD).
   4195  * @GNUTLS_CIPHER_SALSA20_256: Salsa20 with 256-bit keys.
   4253  * @GNUTLS_CIPHER_ESTREAM_SALSA20_256: Estream's Salsa20 variant with 256-bit keys.
   4337  * @GNUTLS_CIPHER_CHACHA20_32: Chacha20 cipher with 96-bit nonces and 32-bit block counters.
   4430  * @GNUTLS_CIPHER_CHACHA20_64: Chacha20 cipher with 64-bit nonces and 64-bit block counters.
   4523  * @GNUTLS_CIPHER_CHACHA20_POLY1305: The Chacha20 cipher with the Poly1305 authenticator (AEAD).
   4620  * @GNUTLS_CIPHER_GOST28147_TC26Z_CFB: GOST 28147-89 (Magma) cipher in CFB mode with TC26 Z S-box.
   4719  * @GNUTLS_CIPHER_GOST28147_CPA_CFB: GOST 28147-89 (Magma) cipher in CFB mode with CryptoPro A S-box.
   4821  * @GNUTLS_CIPHER_GOST28147_CPB_CFB: GOST 28147-89 (Magma) cipher in CFB mode with CryptoPro B S-box.
   4923  * @GNUTLS_CIPHER_GOST28147_CPC_CFB: GOST 28147-89 (Magma) cipher in CFB mode with CryptoPro C S-box.
   5025  * @GNUTLS_CIPHER_GOST28147_CPD_CFB: GOST 28147-89 (Magma) cipher in CFB mode with CryptoPro D S-box.
   5127  * @GNUTLS_CIPHER_AES_128_XTS: AES in XTS mode with 128-bit key + 128bit tweak key.
   5211  * @GNUTLS_CIPHER_AES_256_XTS: AES in XTS mode with 256-bit key + 256bit tweak key.
   5295  *                             Note that the XTS ciphers are message oriented.
   5374  *                             The whole message needs to be provided with a single call, because
   5472  *                             cipher-stealing requires to know where the message actually terminates
   5574  *                             in order to be able to compute where the stealing occurs.
   5663  * @GNUTLS_CIPHER_GOST28147_TC26Z_CNT: GOST 28147-89 (Magma) cipher in CNT mode with TC26 Z S-box.
   5762  * @GNUTLS_CIPHER_MAGMA_CTR_ACPKM: GOST R 34.12-2015 (Magma) cipher in CTR-ACPKM mode.
   5849  * @GNUTLS_CIPHER_KUZNYECHIK_CTR_ACPKM: GOST R 34.12-2015 (Kuznyechik) cipher in CTR-ACPKM mode.
   5946  * @GNUTLS_CIPHER_IDEA_PGP_CFB: IDEA in CFB mode (placeholder - unsupported).
   6024  * @GNUTLS_CIPHER_3DES_PGP_CFB: 3DES in CFB mode (placeholder - unsupported).
   6102  * @GNUTLS_CIPHER_CAST5_PGP_CFB: CAST5 in CFB mode (placeholder - unsupported).
   6182  * @GNUTLS_CIPHER_BLOWFISH_PGP_CFB: Blowfish in CFB mode (placeholder - unsupported).
   6268  * @GNUTLS_CIPHER_SAFER_SK128_PGP_CFB: Safer-SK in CFB mode with 128-bit keys (placeholder - unsupported).
   6375  * @GNUTLS_CIPHER_AES128_PGP_CFB: AES in CFB mode with 128-bit keys (placeholder - unsupported).
   6472  * @GNUTLS_CIPHER_AES192_PGP_CFB: AES in CFB mode with 192-bit keys (placeholder - unsupported).
   6569  * @GNUTLS_CIPHER_AES256_PGP_CFB: AES in CFB mode with 256-bit keys (placeholder - unsupported).
   6666  * @GNUTLS_CIPHER_TWOFISH_PGP_CFB: Twofish in CFB mode (placeholder - unsupported).
   6750  * @GNUTLS_CIPHER_AES_128_SIV: AES in SIV mode with 128-bit key.
   6815  * @GNUTLS_CIPHER_AES_256_SIV: AES in SIV mode with 256-bit key.
   6880  *                             Note that the SIV ciphers can only be used with
   6959  *                             the AEAD interface, and the IV plays a role as
   7037  *                             the authentication tag while it is prepended to
   7116  *                             the cipher text.
   7164  * @GNUTLS_CIPHER_AES_192_GCM: AES in GCM mode with 192-bit keys (AEAD).
   7240  * Enumeration of different symmetric encryption algorithms.
   7305 typedef enum gnutls_cipher_algorithm {
   7344 	GNUTLS_CIPHER_UNKNOWN = 0,
   7372 	GNUTLS_CIPHER_NULL = 1,
   7397 	GNUTLS_CIPHER_ARCFOUR_128 = 2,
   7429 	GNUTLS_CIPHER_3DES_CBC = 3,
   7458 	GNUTLS_CIPHER_AES_128_CBC = 4,
   7490 	GNUTLS_CIPHER_AES_256_CBC = 5,
   7522 	GNUTLS_CIPHER_ARCFOUR_40 = 6,
   7553 	GNUTLS_CIPHER_CAMELLIA_128_CBC = 7,
   7590 	GNUTLS_CIPHER_CAMELLIA_256_CBC = 8,
   7627 	GNUTLS_CIPHER_AES_192_CBC = 9,
   7659 	GNUTLS_CIPHER_AES_128_GCM = 10,
   7692 	GNUTLS_CIPHER_AES_256_GCM = 11,
   7725 	GNUTLS_CIPHER_CAMELLIA_192_CBC = 12,
   7763 	GNUTLS_CIPHER_SALSA20_256 = 13,
   7796 	GNUTLS_CIPHER_ESTREAM_SALSA20_256 = 14,
   7837 	GNUTLS_CIPHER_CAMELLIA_128_GCM = 15,
   7875 	GNUTLS_CIPHER_CAMELLIA_256_GCM = 16,
   7913 	GNUTLS_CIPHER_RC2_40_CBC = 17,
   7945 	GNUTLS_CIPHER_DES_CBC = 18,
   7974 	GNUTLS_CIPHER_AES_128_CCM = 19,
   8007 	GNUTLS_CIPHER_AES_256_CCM = 20,
   8040 	GNUTLS_CIPHER_AES_128_CCM_8 = 21,
   8075 	GNUTLS_CIPHER_AES_256_CCM_8 = 22,
   8110 	GNUTLS_CIPHER_CHACHA20_POLY1305 = 23,
   8149 	GNUTLS_CIPHER_GOST28147_TC26Z_CFB = 24,
   8190 	GNUTLS_CIPHER_GOST28147_CPA_CFB = 25,
   8229 	GNUTLS_CIPHER_GOST28147_CPB_CFB = 26,
   8268 	GNUTLS_CIPHER_GOST28147_CPC_CFB = 27,
   8307 	GNUTLS_CIPHER_GOST28147_CPD_CFB = 28,
   8346 	GNUTLS_CIPHER_AES_128_CFB8 = 29,
   8380 	GNUTLS_CIPHER_AES_192_CFB8 = 30,
   8414 	GNUTLS_CIPHER_AES_256_CFB8 = 31,
   8448 	GNUTLS_CIPHER_AES_128_XTS = 32,
   8481 	GNUTLS_CIPHER_AES_256_XTS = 33,
   8514 	GNUTLS_CIPHER_GOST28147_TC26Z_CNT = 34,
   8555 	GNUTLS_CIPHER_CHACHA20_64 = 35,
   8588 	GNUTLS_CIPHER_CHACHA20_32 = 36,
   8621 	GNUTLS_CIPHER_AES_128_SIV = 37,
   8654 	GNUTLS_CIPHER_AES_256_SIV = 38,
   8687 	GNUTLS_CIPHER_AES_192_GCM = 39,
   8720 	GNUTLS_CIPHER_MAGMA_CTR_ACPKM = 40,
   8757 	GNUTLS_CIPHER_KUZNYECHIK_CTR_ACPKM = 41,
   8800 	/* used only for PGP internals. Ignored in TLS/SSL
   8852 	 */
   8857 	GNUTLS_CIPHER_IDEA_PGP_CFB = 200,
   8892 	GNUTLS_CIPHER_3DES_PGP_CFB = 201,
   8927 	GNUTLS_CIPHER_CAST5_PGP_CFB = 202,
   8963 	GNUTLS_CIPHER_BLOWFISH_PGP_CFB = 203,
   9002 	GNUTLS_CIPHER_SAFER_SK128_PGP_CFB = 204,
   9044 	GNUTLS_CIPHER_AES128_PGP_CFB = 205,
   9081 	GNUTLS_CIPHER_AES192_PGP_CFB = 206,
   9118 	GNUTLS_CIPHER_AES256_PGP_CFB = 207,
   9155 	GNUTLS_CIPHER_TWOFISH_PGP_CFB = 208
   9192 } gnutls_cipher_algorithm_t;
   9226  * gnutls_kx_algorithm_t:
   9252  * @GNUTLS_KX_UNKNOWN: Unknown key-exchange algorithm.
   9307  * @GNUTLS_KX_RSA: RSA key-exchange algorithm.
   9354  * @GNUTLS_KX_DHE_DSS: DHE-DSS key-exchange algorithm.
   9409  * @GNUTLS_KX_DHE_RSA: DHE-RSA key-exchange algorithm.
   9464  * @GNUTLS_KX_ECDHE_RSA: ECDHE-RSA key-exchange algorithm.
   9523  * @GNUTLS_KX_ECDHE_ECDSA: ECDHE-ECDSA key-exchange algorithm.
   9586  * @GNUTLS_KX_ANON_DH: Anon-DH key-exchange algorithm.
   9641  * @GNUTLS_KX_ANON_ECDH: Anon-ECDH key-exchange algorithm.
   9700  * @GNUTLS_KX_SRP: SRP key-exchange algorithm.
   9747  * @GNUTLS_KX_RSA_EXPORT: RSA-EXPORT key-exchange algorithm (defunc).
   9817  * @GNUTLS_KX_SRP_RSA: SRP-RSA key-exchange algorithm.
   9872  * @GNUTLS_KX_SRP_DSS: SRP-DSS key-exchange algorithm.
   9927  * @GNUTLS_KX_PSK: PSK key-exchange algorithm.
   9974  * @GNUTLS_KX_DHE_PSK: DHE-PSK key-exchange algorithm.
  10029  * @GNUTLS_KX_ECDHE_PSK: ECDHE-PSK key-exchange algorithm.
  10088  * @GNUTLS_KX_RSA_PSK: RSA-PSK key-exchange algorithm.
  10143  * @GNUTLS_KX_VKO_GOST_12: VKO GOST R 34.10-2012 key-exchange algorithm.
  10219  * Enumeration of different key exchange algorithms.
  10276 typedef enum {
  10291 	GNUTLS_KX_UNKNOWN = 0,
  10315 	GNUTLS_KX_RSA = 1,
  10335 	GNUTLS_KX_DHE_DSS = 2,
  10359 	GNUTLS_KX_DHE_RSA = 3,
  10383 	GNUTLS_KX_ANON_DH = 4,
  10407 	GNUTLS_KX_SRP = 5,
  10427 	GNUTLS_KX_RSA_EXPORT = 6,
  10454 	GNUTLS_KX_SRP_RSA = 7,
  10478 	GNUTLS_KX_SRP_DSS = 8,
  10502 	GNUTLS_KX_PSK = 9,
  10522 	GNUTLS_KX_DHE_PSK = 10,
  10547 	GNUTLS_KX_ANON_ECDH = 11,
  10574 	GNUTLS_KX_ECDHE_RSA = 12,
  10601 	GNUTLS_KX_ECDHE_ECDSA = 13,
  10630 	GNUTLS_KX_ECDHE_PSK = 14,
  10657 	GNUTLS_KX_RSA_PSK = 15,
  10682 	GNUTLS_KX_VKO_GOST_12 = 16
  10710 } gnutls_kx_algorithm_t;
  10740  * gnutls_params_type_t:
  10765  * @GNUTLS_PARAMS_RSA_EXPORT: Session RSA-EXPORT parameters (defunc).
  10835  * @GNUTLS_PARAMS_DH: Session Diffie-Hellman parameters.
  10892  * @GNUTLS_PARAMS_ECDH: Session Elliptic-Curve Diffie-Hellman parameters.
  10969  * Enumeration of different TLS session parameter types.
  11030 typedef enum {
  11045 	GNUTLS_PARAMS_RSA_EXPORT = 1,
  11076 	GNUTLS_PARAMS_DH = 2,
  11099 	GNUTLS_PARAMS_ECDH = 3
  11123 } gnutls_params_type_t;
  11152  * gnutls_credentials_type_t:
  11182  * @GNUTLS_CRD_CERTIFICATE: Certificate credential.
  11234  * @GNUTLS_CRD_ANON: Anonymous credential.
  11277  * @GNUTLS_CRD_SRP: SRP credential.
  11313  * @GNUTLS_CRD_PSK: PSK credential.
  11349  * @GNUTLS_CRD_IA: IA credential.
  11386  * Enumeration of different credential types.
  11436 typedef enum {
  11451 	GNUTLS_CRD_CERTIFICATE = 1,
  11480 	GNUTLS_CRD_ANON,
  11498 	GNUTLS_CRD_SRP,
  11515 	GNUTLS_CRD_PSK,
  11532 	GNUTLS_CRD_IA
  11547 } gnutls_credentials_type_t;
  11577 #define GNUTLS_MAC_SHA GNUTLS_MAC_SHA1
  11616 #define GNUTLS_DIG_SHA GNUTLS_DIG_SHA1
  11660  * gnutls_mac_algorithm_t:
  11687  * @GNUTLS_MAC_UNKNOWN: Unknown MAC algorithm.
  11734  * @GNUTLS_MAC_NULL: NULL MAC algorithm (empty output).
  11790  * @GNUTLS_MAC_MD5: HMAC-MD5 algorithm.
  11830  * @GNUTLS_MAC_SHA1: HMAC-SHA-1 algorithm.
  11873  * @GNUTLS_MAC_RMD160: HMAC-RMD160 algorithm.
  11919  * @GNUTLS_MAC_MD2: HMAC-MD2 algorithm.
  11959  * @GNUTLS_MAC_SHA256: HMAC-SHA-256 algorithm.
  12006  * @GNUTLS_MAC_SHA384: HMAC-SHA-384 algorithm.
  12053  * @GNUTLS_MAC_SHA512: HMAC-SHA-512 algorithm.
  12100  * @GNUTLS_MAC_SHA224: HMAC-SHA-224 algorithm.
  12147  * @GNUTLS_MAC_MD5_SHA1: Combined MD5+SHA1 MAC placeholder.
  12207  * @GNUTLS_MAC_GOSTR_94: HMAC GOST R 34.11-94 algorithm.
  12264  * @GNUTLS_MAC_STREEBOG_256: HMAC GOST R 34.11-2001 (Streebog) algorithm, 256 bit.
  12347  * @GNUTLS_MAC_STREEBOG_512: HMAC GOST R 34.11-2001 (Streebog) algorithm, 512 bit.
  12430  * @GNUTLS_MAC_AEAD: MAC implicit through AEAD cipher.
  12485  * @GNUTLS_MAC_UMAC_96: The UMAC-96 MAC algorithm (requires nonce).
  12553  * @GNUTLS_MAC_UMAC_128: The UMAC-128 MAC algorithm (requires nonce).
  12623  * @GNUTLS_MAC_AES_CMAC_128: The AES-CMAC-128 MAC algorithm.
  12684  * @GNUTLS_MAC_AES_CMAC_256: The AES-CMAC-256 MAC algorithm.
  12745  * @GNUTLS_MAC_AES_GMAC_128: The AES-GMAC-128 MAC algorithm (requires nonce).
  12823  * @GNUTLS_MAC_AES_GMAC_192: The AES-GMAC-192 MAC algorithm (requires nonce).
  12901  * @GNUTLS_MAC_AES_GMAC_256: The AES-GMAC-256 MAC algorithm (requires nonce).
  12979  * @GNUTLS_MAC_SHA3_224: Reserved; unimplemented.
  13029  * @GNUTLS_MAC_SHA3_256: Reserved; unimplemented.
  13079  * @GNUTLS_MAC_SHA3_384: Reserved; unimplemented.
  13129  * @GNUTLS_MAC_SHA3_512: Reserved; unimplemented.
  13179  * @GNUTLS_MAC_GOST28147_TC26Z_IMIT: The GOST 28147-89 working in IMIT mode with TC26 Z S-box.
  13274  * @GNUTLS_MAC_SHAKE_128: Reserved; unimplemented.
  13325  * @GNUTLS_MAC_SHAKE_256: Reserved; unimplemented.
  13376  * @GNUTLS_MAC_MAGMA_OMAC: GOST R 34.12-2015 (Magma) in OMAC (CMAC) mode.
  13450  * @GNUTLS_MAC_KUZNYECHIK_OMAC: GOST R 34.12-2015 (Kuznyechik) in OMAC (CMAC) mode.
  13537  * Enumeration of different Message Authentication Code (MAC)
  13599  * algorithms.
  13618 typedef enum {
  13633 	GNUTLS_MAC_UNKNOWN = 0,
  13658 	GNUTLS_MAC_NULL = 1,
  13680 	GNUTLS_MAC_MD5 = 2,
  13701 	GNUTLS_MAC_SHA1 = 3,
  13723 	GNUTLS_MAC_RMD160 = 4,
  13747 	GNUTLS_MAC_MD2 = 5,
  13768 	GNUTLS_MAC_SHA256 = 6,
  13792 	GNUTLS_MAC_SHA384 = 7,
  13816 	GNUTLS_MAC_SHA512 = 8,
  13840 	GNUTLS_MAC_SHA224 = 9,
  13864 	GNUTLS_MAC_SHA3_224 = 10, /* reserved: no implementation */
  13925 	GNUTLS_MAC_SHA3_256 = 11, /* reserved: no implementation */
  13986 	GNUTLS_MAC_SHA3_384 = 12, /* reserved: no implementation */
  14047 	GNUTLS_MAC_SHA3_512 = 13, /* reserved: no implementation */
  14108 	GNUTLS_MAC_MD5_SHA1 = 14, /* reserved: no implementation */
  14169 	GNUTLS_MAC_GOSTR_94 = 15,
  14196 	GNUTLS_MAC_STREEBOG_256 = 16,
  14227 	GNUTLS_MAC_STREEBOG_512 = 17,
  14258 	/* If you add anything here, make sure you align with
  14313 	   gnutls_digest_algorithm_t. */
  14347 	GNUTLS_MAC_AEAD = 200,	/* indicates that MAC is on the cipher */
  14413 	GNUTLS_MAC_UMAC_96 = 201,
  14440 	GNUTLS_MAC_UMAC_128 = 202,
  14468 	GNUTLS_MAC_AES_CMAC_128 = 203,
  14500 	GNUTLS_MAC_AES_CMAC_256 = 204,
  14532 	GNUTLS_MAC_AES_GMAC_128 = 205,
  14564 	GNUTLS_MAC_AES_GMAC_192 = 206,
  14596 	GNUTLS_MAC_AES_GMAC_256 = 207,
  14628 	GNUTLS_MAC_GOST28147_TC26Z_IMIT = 208,
  14668 	GNUTLS_MAC_SHAKE_128 = 209,
  14697 	GNUTLS_MAC_SHAKE_256 = 210,
  14726 	GNUTLS_MAC_MAGMA_OMAC = 211,
  14756 	GNUTLS_MAC_KUZNYECHIK_OMAC = 212
  14790 } gnutls_mac_algorithm_t;
  14821  * gnutls_digest_algorithm_t:
  14851  * @GNUTLS_DIG_UNKNOWN: Unknown hash algorithm.
  14899  * @GNUTLS_DIG_NULL: NULL hash algorithm (empty output).
  14956  * @GNUTLS_DIG_MD5: MD5 algorithm.
  14991  * @GNUTLS_DIG_SHA1: SHA-1 algorithm.
  15029  * @GNUTLS_DIG_RMD160: RMD160 algorithm.
  15070  * @GNUTLS_DIG_MD2: MD2 algorithm.
  15105  * @GNUTLS_DIG_SHA256: SHA-256 algorithm.
  15147  * @GNUTLS_DIG_SHA384: SHA-384 algorithm.
  15189  * @GNUTLS_DIG_SHA512: SHA-512 algorithm.
  15231  * @GNUTLS_DIG_SHA224: SHA-224 algorithm.
  15273  * @GNUTLS_DIG_SHA3_224: SHA3-224 algorithm.
  15318  * @GNUTLS_DIG_SHA3_256: SHA3-256 algorithm.
  15363  * @GNUTLS_DIG_SHA3_384: SHA3-384 algorithm.
  15408  * @GNUTLS_DIG_SHA3_512: SHA3-512 algorithm.
  15453  * @GNUTLS_DIG_MD5_SHA1: Combined MD5+SHA1 algorithm.
  15507  * @GNUTLS_DIG_GOSTR_94: GOST R 34.11-94 algorithm.
  15559  * @GNUTLS_DIG_STREEBOG_256: GOST R 34.11-2001 (Streebog) algorithm, 256 bit.
  15637  * @GNUTLS_DIG_STREEBOG_512: GOST R 34.11-2001 (Streebog) algorithm, 512 bit.
  15715  * @GNUTLS_DIG_SHAKE_128: Reserved; unimplemented.
  15766  * @GNUTLS_DIG_SHAKE_256: Reserved; unimplemented.
  15820  * Enumeration of different digest (hash) algorithms.
  15878 typedef enum {
  15893 	GNUTLS_DIG_UNKNOWN = GNUTLS_MAC_UNKNOWN,
  15935 	GNUTLS_DIG_NULL = GNUTLS_MAC_NULL,
  15971 	GNUTLS_DIG_MD5 = GNUTLS_MAC_MD5,
  16005 	GNUTLS_DIG_SHA1 = GNUTLS_MAC_SHA1,
  16041 	GNUTLS_DIG_RMD160 = GNUTLS_MAC_RMD160,
  16081 	GNUTLS_DIG_MD2 = GNUTLS_MAC_MD2,
  16115 	GNUTLS_DIG_SHA256 = GNUTLS_MAC_SHA256,
  16155 	GNUTLS_DIG_SHA384 = GNUTLS_MAC_SHA384,
  16195 	GNUTLS_DIG_SHA512 = GNUTLS_MAC_SHA512,
  16235 	GNUTLS_DIG_SHA224 = GNUTLS_MAC_SHA224,
  16275 	GNUTLS_DIG_SHA3_224 = GNUTLS_MAC_SHA3_224,
  16319 	GNUTLS_DIG_SHA3_256 = GNUTLS_MAC_SHA3_256,
  16363 	GNUTLS_DIG_SHA3_384 = GNUTLS_MAC_SHA3_384,
  16407 	GNUTLS_DIG_SHA3_512 = GNUTLS_MAC_SHA3_512,
  16451 	GNUTLS_DIG_MD5_SHA1 = GNUTLS_MAC_MD5_SHA1,
  16495 	GNUTLS_DIG_GOSTR_94 = GNUTLS_MAC_GOSTR_94,
  16539 	GNUTLS_DIG_STREEBOG_256 = GNUTLS_MAC_STREEBOG_256,
  16591 	GNUTLS_DIG_STREEBOG_512 = GNUTLS_MAC_STREEBOG_512,
  16643 	GNUTLS_DIG_SHAKE_128 = GNUTLS_MAC_SHAKE_128,
  16689 	GNUTLS_DIG_SHAKE_256 = GNUTLS_MAC_SHAKE_256
  16734 	    /* If you add anything here, make sure you align with
  16793 	       gnutls_mac_algorithm_t. */
  16828 } gnutls_digest_algorithm_t;
  16858   /* exported for other gnutls headers. This is the maximum number of
  16928    * algorithms (ciphers, kx or macs).
  16967    */
  16973 #define GNUTLS_MAX_ALGORITHM_NUM 64
  17009 #define GNUTLS_MAX_SESSION_ID_SIZE 32
  17053  * gnutls_compression_method_t:
  17085  * @GNUTLS_COMP_UNKNOWN: Unknown compression method.
  17138  * @GNUTLS_COMP_NULL: The NULL compression method (no compression).
  17206  * @GNUTLS_COMP_DEFLATE: The DEFLATE compression method from zlib.
  17273  * @GNUTLS_COMP_ZLIB: Same as %GNUTLS_COMP_DEFLATE.
  17328  * Enumeration of different TLS compression methods.
  17385 typedef enum {
  17400 	GNUTLS_COMP_UNKNOWN = 0,
  17426 	GNUTLS_COMP_NULL = 1,
  17449 	GNUTLS_COMP_DEFLATE = 2,
  17475 	GNUTLS_COMP_ZLIB = GNUTLS_COMP_DEFLATE
  17515 } gnutls_compression_method_t;
  17552  * gnutls_init_flags_t:
  17579  * @GNUTLS_SERVER: Connection end is a server.
  17626  * @GNUTLS_CLIENT: Connection end is a client.
  17673  * @GNUTLS_DATAGRAM: Connection is datagram oriented (DTLS). Since 3.0.0.
  17747  * @GNUTLS_NONBLOCK: Connection should not block. Since 3.0.0.
  17810  * @GNUTLS_NO_SIGNAL: In systems where SIGPIPE is delivered on send, it will be disabled. That flag has effect in systems which support the MSG_NOSIGNAL sockets flag (since 3.4.2).
  17991  * @GNUTLS_NO_EXTENSIONS: Do not enable any TLS extensions by default (since 3.1.2). As TLS 1.2 and later require extensions this option is considered obsolete and should not be used.
  18175  * @GNUTLS_NO_REPLAY_PROTECTION: Disable any replay protection in DTLS. This must only be used if  replay protection is achieved using other means. Since 3.2.2.
  18336  * @GNUTLS_ALLOW_ID_CHANGE: Allow the peer to replace its certificate, or change its ID during a rehandshake. This change is often used in attacks and thus prohibited by default. Since 3.5.0.
  18528  * @GNUTLS_ENABLE_FALSE_START: Enable the TLS false start on client side if the negotiated ciphersuites allow it. This will enable sending data prior to the handshake being complete, and may introduce a risk of crypto failure when combined with certain key exchanged; for that GnuTLS may not enable that option in ciphersuites that are known to be not safe for false start. Since 3.5.0.
  18915  * @GNUTLS_ENABLE_EARLY_START: Under TLS1.3 allow the server to return earlier than the full handshake
  19018  *   finish; similarly to false start the handshake will be completed once data are received by the
  19118  *   client, while the server is able to transmit sooner. This is not enabled by default as it could
  19219  *   break certain existing server assumptions and use-cases. Since 3.6.4.
  19294  * @GNUTLS_ENABLE_EARLY_DATA: Under TLS1.3 allow the server to receive early data sent as part of the initial ClientHello (0-RTT).
  19425  *   This can also be used to explicitly indicate that the client will send early data.
  19513  *   This is not enabled by default as early data has weaker security properties than other data. Since 3.6.5.
  19624  * @GNUTLS_FORCE_CLIENT_CERT: When in client side and only a single cert is specified, send that certificate irrespective of the issuers expected by the server. Since 3.5.0.
  19798  * @GNUTLS_NO_TICKETS: Flag to indicate that the session should not use resumption with session tickets.
  19903  * @GNUTLS_KEY_SHARE_TOP3: Generate key shares for the top-3 different groups which are enabled.
  20000  *   That is, as each group is associated with a key type (EC, finite field, x25519), generate
  20095  *   three keys using %GNUTLS_PK_DH, %GNUTLS_PK_EC, %GNUTLS_PK_ECDH_X25519 if all of them are enabled.
  20198  * @GNUTLS_KEY_SHARE_TOP2: Generate key shares for the top-2 different groups which are enabled.
  20295  *   For example (ECDH + x25519). This is the default.
  20350  * @GNUTLS_KEY_SHARE_TOP: Generate key share for the first group which is enabled.
  20433  *   For example x25519. This option is the most performant for client (less CPU spent
  20520  *   generating keys), but if the server doesn't support the advertized option it may
  20606  *   result to more roundtrips needed to discover the server's choice.
  20677  * @GNUTLS_NO_AUTO_REKEY: Disable auto-rekeying under TLS1.3. If this option is not specified
  20771  *   gnutls will force a rekey after 2^24 records have been sent.
  20837  * @GNUTLS_POST_HANDSHAKE_AUTH: Enable post handshake authentication for server and client. When set and
  20942  *   a server requests authentication after handshake %GNUTLS_E_REAUTH_REQUEST will be returned
  21038  *   by gnutls_record_recv(). A client should then call gnutls_reauth() to re-authenticate.
  21130  * @GNUTLS_SAFE_PADDING_CHECK: Flag to indicate that the TLS 1.3 padding check will be done in a
  21227  *   safe way which doesn't leak the pad size based on GnuTLS processing time. This is of use to
  21324  *   applications which hide the length of transferred data via the TLS1.3 padding mechanism and
  21421  *   are already taking steps to hide the data processing time. This comes at a performance
  21513  *   penalty.
  21527  * @GNUTLS_AUTO_REAUTH: Enable transparent re-authentication in client side when the server
  21619  *    requests to. That is, reauthentication is handled within gnutls_record_recv(), and
  21708  *    the %GNUTLS_E_REHANDSHAKE or %GNUTLS_E_REAUTH_REQUEST are not returned. This must be
  21799  *    enabled with %GNUTLS_POST_HANDSHAKE_AUTH for TLS1.3. Enabling this flag requires to restore
  21897  *    interrupted calls to gnutls_record_recv() based on the output of gnutls_record_get_direction(),
  21999  *    since gnutls_record_recv() could be interrupted when sending when this flag is enabled.
  22093  *    Note this flag may not be used if you are using the same session for sending and receiving
  22190  *    in different threads.
  22218  * @GNUTLS_ENABLE_RAWPK: Allows raw public-keys to be negotiated during the handshake. Since 3.6.6.
  22318  * @GNUTLS_NO_AUTO_SEND_TICKET: Under TLS1.3 disable auto-sending of
  22387  *    session tickets during the handshake.
  22431  * @GNUTLS_NO_END_OF_EARLY_DATA: Under TLS1.3 suppress sending EndOfEarlyData message. Since 3.7.2.
  22534  * Enumeration of different flags for gnutls_init() function. All the flags
  22610  * can be combined except @GNUTLS_SERVER and @GNUTLS_CLIENT which are mutually
  22689  * exclusive.
  22706  * The key share options relate to the TLS 1.3 key share extension
  22773  * which is a speculative key generation expecting that the server
  22840  * would support the generated key.
  22880 typedef enum {
  22895 	GNUTLS_SERVER = 1,
  22915 	GNUTLS_CLIENT = (1<<1),
  22940 	GNUTLS_DATAGRAM = (1<<2),
  22967 	GNUTLS_NONBLOCK = (1<<3),
  22994 	GNUTLS_NO_EXTENSIONS = (1<<4),
  23026 	GNUTLS_NO_REPLAY_PROTECTION = (1<<5),
  23065 	GNUTLS_NO_SIGNAL = (1<<6),
  23093 	GNUTLS_ALLOW_ID_CHANGE = (1<<7),
  23127 	GNUTLS_ENABLE_FALSE_START = (1<<8),
  23164 	GNUTLS_FORCE_CLIENT_CERT = (1<<9),
  23200 	GNUTLS_NO_TICKETS = (1<<10),
  23230 	GNUTLS_KEY_SHARE_TOP = (1<<11),
  23263 	GNUTLS_KEY_SHARE_TOP2 = (1<<12),
  23297 	GNUTLS_KEY_SHARE_TOP3 = (1<<13),
  23331 	GNUTLS_POST_HANDSHAKE_AUTH = (1<<14),
  23370 	GNUTLS_NO_AUTO_REKEY = (1<<15),
  23403 	GNUTLS_SAFE_PADDING_CHECK = (1<<16),
  23441 	GNUTLS_ENABLE_EARLY_START = (1<<17),
  23479 	GNUTLS_ENABLE_RAWPK = (1<<18),
  23511 	GNUTLS_AUTO_REAUTH = (1<<19),
  23542 	GNUTLS_ENABLE_EARLY_DATA = (1<<20),
  23579 	GNUTLS_NO_AUTO_SEND_TICKET = (1<<21),
  23618 	GNUTLS_NO_END_OF_EARLY_DATA = (1<<22)
  23657 } gnutls_init_flags_t;
  23681 /* compatibility defines (previous versions of gnutls
  23735  * used defines instead of enumerated values). */
  23785 #define GNUTLS_SERVER (1)
  23811 #define GNUTLS_CLIENT (1<<1)
  23840 #define GNUTLS_DATAGRAM (1<<2)
  23871 #define GNUTLS_NONBLOCK (1<<3)
  23902 #define GNUTLS_NO_EXTENSIONS (1<<4)
  23938 #define GNUTLS_NO_REPLAY_PROTECTION (1<<5)
  23981 #define GNUTLS_NO_SIGNAL (1<<6)
  24013 #define GNUTLS_ALLOW_ID_CHANGE (1<<7)
  24051 #define GNUTLS_ENABLE_FALSE_START (1<<8)
  24092 #define GNUTLS_FORCE_CLIENT_CERT (1<<9)
  24132 #define GNUTLS_NO_TICKETS (1<<10)
  24166 #define GNUTLS_ENABLE_CERT_TYPE_NEG 0
  24204 	// Here for compatibility reasons
  24244  * gnutls_alert_level_t:
  24269  * @GNUTLS_AL_WARNING: Alert of warning severity.
  24319  * @GNUTLS_AL_FATAL: Alert of fatal severity.
  24368  * Enumeration of different TLS alert severities.
  24422 typedef enum {
  24437 	GNUTLS_AL_WARNING = 1,
  24461 	GNUTLS_AL_FATAL
  24478 } gnutls_alert_level_t;
  24507  * gnutls_alert_description_t:
  24538  * @GNUTLS_A_CLOSE_NOTIFY: Close notify.
  24579  * @GNUTLS_A_UNEXPECTED_MESSAGE: Unexpected message.
  24632  * @GNUTLS_A_BAD_RECORD_MAC: Bad record MAC.
  24677  * @GNUTLS_A_DECRYPTION_FAILED: Decryption failed.
  24728  * @GNUTLS_A_RECORD_OVERFLOW: Record overflow.
  24775  * @GNUTLS_A_DECOMPRESSION_FAILURE: Decompression failed.
  24833  * @GNUTLS_A_HANDSHAKE_FAILURE: Handshake failed.
  24883  * @GNUTLS_A_SSL3_NO_CERTIFICATE: No certificate.
  24933  * @GNUTLS_A_BAD_CERTIFICATE: Certificate is bad.
  24983  * @GNUTLS_A_UNSUPPORTED_CERTIFICATE: Certificate is not supported.
  25051  * @GNUTLS_A_CERTIFICATE_REVOKED: Certificate was revoked.
  25110  * @GNUTLS_A_CERTIFICATE_EXPIRED: Certificate is expired.
  25168  * @GNUTLS_A_CERTIFICATE_UNKNOWN: Unknown certificate.
  25223  * @GNUTLS_A_ILLEGAL_PARAMETER: Illegal parameter.
  25274  * @GNUTLS_A_UNKNOWN_CA: CA is unknown.
  25314  * @GNUTLS_A_ACCESS_DENIED: Access was denied.
  25361  * @GNUTLS_A_DECODE_ERROR: Decode error.
  25402  * @GNUTLS_A_DECRYPT_ERROR: Decrypt error.
  25445  * @GNUTLS_A_EXPORT_RESTRICTION: Export restriction.
  25498  * @GNUTLS_A_PROTOCOL_VERSION: Error in protocol version.
  25556  * @GNUTLS_A_INSUFFICIENT_SECURITY: Insufficient security.
  25615  * @GNUTLS_A_INTERNAL_ERROR: Internal error.
  25660  * @GNUTLS_A_INAPPROPRIATE_FALLBACK: Inappropriate fallback,
  25721  * @GNUTLS_A_USER_CANCELED: User canceled.
  25764  * @GNUTLS_A_NO_RENEGOTIATION: No renegotiation is allowed.
  25824  * @GNUTLS_A_MISSING_EXTENSION: An extension was expected but was not seen
  25899  * @GNUTLS_A_UNSUPPORTED_EXTENSION: An unsupported extension was
  25964  *   sent.
  25975  * @GNUTLS_A_CERTIFICATE_UNOBTAINABLE: Could not retrieve the
  26037  *   specified certificate.
  26065  * @GNUTLS_A_UNRECOGNIZED_NAME: The server name sent was not
  26126  *   recognized.
  26143  * @GNUTLS_A_UNKNOWN_PSK_IDENTITY: The SRP/PSK username is missing
  26210  *   or not known.
  26229  * @GNUTLS_A_CERTIFICATE_REQUIRED: Certificate is required.
  26289  * @GNUTLS_A_NO_APPLICATION_PROTOCOL: The ALPN protocol requested is
  26358  *   not supported by the peer.
  26393  * Enumeration of different TLS alerts.
  26437 typedef enum {
  26452 	GNUTLS_A_CLOSE_NOTIFY,
  26476 	GNUTLS_A_UNEXPECTED_MESSAGE = 10,
  26511 	GNUTLS_A_BAD_RECORD_MAC = 20,
  26542 	GNUTLS_A_DECRYPTION_FAILED,
  26571 	GNUTLS_A_RECORD_OVERFLOW,
  26598 	GNUTLS_A_DECOMPRESSION_FAILURE = 30,
  26636 	GNUTLS_A_HANDSHAKE_FAILURE = 40,
  26670 	GNUTLS_A_SSL3_NO_CERTIFICATE = 41,
  26706 	GNUTLS_A_BAD_CERTIFICATE = 42,
  26738 	GNUTLS_A_UNSUPPORTED_CERTIFICATE,
  26773 	GNUTLS_A_CERTIFICATE_REVOKED,
  26804 	GNUTLS_A_CERTIFICATE_EXPIRED,
  26835 	GNUTLS_A_CERTIFICATE_UNKNOWN,
  26866 	GNUTLS_A_ILLEGAL_PARAMETER,
  26895 	GNUTLS_A_UNKNOWN_CA,
  26917 	GNUTLS_A_ACCESS_DENIED,
  26942 	GNUTLS_A_DECODE_ERROR = 50,
  26971 	GNUTLS_A_DECRYPT_ERROR,
  26996 	GNUTLS_A_EXPORT_RESTRICTION = 60,
  27031 	GNUTLS_A_PROTOCOL_VERSION = 70,
  27064 	GNUTLS_A_INSUFFICIENT_SECURITY,
  27097 	GNUTLS_A_INTERNAL_ERROR = 80,
  27128 	GNUTLS_A_INAPPROPRIATE_FALLBACK = 86,
  27167 	GNUTLS_A_USER_CANCELED = 90,
  27197 	GNUTLS_A_NO_RENEGOTIATION = 100,
  27231 	GNUTLS_A_MISSING_EXTENSION = 109,
  27266 	GNUTLS_A_UNSUPPORTED_EXTENSION = 110,
  27305 	GNUTLS_A_CERTIFICATE_UNOBTAINABLE = 111,
  27347 	GNUTLS_A_UNRECOGNIZED_NAME = 112,
  27382 	GNUTLS_A_UNKNOWN_PSK_IDENTITY = 115,
  27420 	GNUTLS_A_CERTIFICATE_REQUIRED = 116,
  27458 	GNUTLS_A_NO_APPLICATION_PROTOCOL = 120,
  27499 	GNUTLS_A_MAX = GNUTLS_A_NO_APPLICATION_PROTOCOL
  27548 } gnutls_alert_description_t;
  27583  * gnutls_handshake_description_t:
  27618  * @GNUTLS_HANDSHAKE_HELLO_REQUEST: Hello request.
  27669  * @GNUTLS_HANDSHAKE_HELLO_VERIFY_REQUEST: DTLS Hello verify request.
  27739  * @GNUTLS_HANDSHAKE_CLIENT_HELLO: Client hello.
  27788  * @GNUTLS_HANDSHAKE_SERVER_HELLO: Server hello.
  27837  * @GNUTLS_HANDSHAKE_END_OF_EARLY_DATA: End of early data.
  27896  * @GNUTLS_HANDSHAKE_HELLO_RETRY_REQUEST: Hello retry request.
  27959  * @GNUTLS_HANDSHAKE_NEW_SESSION_TICKET: New session ticket.
  28020  * @GNUTLS_HANDSHAKE_CERTIFICATE_PKT: Certificate packet.
  28078  * @GNUTLS_HANDSHAKE_SERVER_KEY_EXCHANGE: Server key exchange.
  28141  * @GNUTLS_HANDSHAKE_CERTIFICATE_REQUEST: Certificate request.
  28204  * @GNUTLS_HANDSHAKE_SERVER_HELLO_DONE: Server hello done.
  28263  * @GNUTLS_HANDSHAKE_CERTIFICATE_VERIFY: Certificate verify.
  28324  * @GNUTLS_HANDSHAKE_CLIENT_KEY_EXCHANGE: Client key exchange.
  28387  * @GNUTLS_HANDSHAKE_FINISHED: Finished.
  28428  * @GNUTLS_HANDSHAKE_CERTIFICATE_STATUS: Certificate status (OCSP).
  28496  * @GNUTLS_HANDSHAKE_KEY_UPDATE: TLS1.3 key update message.
  28556  * @GNUTLS_HANDSHAKE_SUPPLEMENTAL: Supplemental.
  28605  * @GNUTLS_HANDSHAKE_CHANGE_CIPHER_SPEC: Change Cipher Spec.
  28666  * @GNUTLS_HANDSHAKE_CLIENT_HELLO_V2: SSLv2 Client Hello.
  28724  * @GNUTLS_HANDSHAKE_ENCRYPTED_EXTENSIONS: Encrypted extensions message.
  28800  * Enumeration of different TLS handshake packets.
  28855 typedef enum {
  28870 	GNUTLS_HANDSHAKE_HELLO_REQUEST = 0,
  28907 	GNUTLS_HANDSHAKE_CLIENT_HELLO = 1,
  28943 	GNUTLS_HANDSHAKE_SERVER_HELLO = 2,
  28979 	GNUTLS_HANDSHAKE_HELLO_VERIFY_REQUEST = 3,
  29023 	GNUTLS_HANDSHAKE_NEW_SESSION_TICKET = 4,
  29065 	GNUTLS_HANDSHAKE_END_OF_EARLY_DATA = 5,
  29106 	GNUTLS_HANDSHAKE_ENCRYPTED_EXTENSIONS = 8,
  29150 	GNUTLS_HANDSHAKE_CERTIFICATE_PKT = 11,
  29190 	GNUTLS_HANDSHAKE_SERVER_KEY_EXCHANGE = 12,
  29234 	GNUTLS_HANDSHAKE_CERTIFICATE_REQUEST = 13,
  29278 	GNUTLS_HANDSHAKE_SERVER_HELLO_DONE = 14,
  29320 	GNUTLS_HANDSHAKE_CERTIFICATE_VERIFY = 15,
  29363 	GNUTLS_HANDSHAKE_CLIENT_KEY_EXCHANGE = 16,
  29407 	GNUTLS_HANDSHAKE_FINISHED = 20,
  29440 	GNUTLS_HANDSHAKE_CERTIFICATE_STATUS = 22,
  29483 	GNUTLS_HANDSHAKE_SUPPLEMENTAL = 23,
  29520 	GNUTLS_HANDSHAKE_KEY_UPDATE = 24,
  29555 	GNUTLS_HANDSHAKE_CHANGE_CIPHER_SPEC = 254,
  29599 	GNUTLS_HANDSHAKE_CLIENT_HELLO_V2 = 1024,
  29641 	GNUTLS_HANDSHAKE_HELLO_RETRY_REQUEST = 1025,
  29687 } gnutls_handshake_description_t;
  29722 #define GNUTLS_HANDSHAKE_ANY ((unsigned int)-1)
  29771 const char
  29782     *gnutls_handshake_description_get_name(gnutls_handshake_description_t
  29856 					   type);
  29876  * gnutls_certificate_status_t:
  29908  * @GNUTLS_CERT_INVALID: The certificate is not signed by one of the
  29977  *   known authorities or the signature is invalid (deprecated by the flags 
  30054  *   %GNUTLS_CERT_SIGNATURE_FAILURE and %GNUTLS_CERT_SIGNER_NOT_FOUND).
  30126  * @GNUTLS_CERT_SIGNATURE_FAILURE: The signature verification failed.
  30196  * @GNUTLS_CERT_REVOKED: Certificate is revoked by its authority.  In X.509 this will be
  30285  *   set only if CRLs are checked.
  30320  * @GNUTLS_CERT_SIGNER_NOT_FOUND: The certificate's issuer is not known. 
  30394  *   This is the case if the issuer is not included in the trusted certificate list.
  30479  * @GNUTLS_CERT_SIGNER_NOT_CA: The certificate's signer was not a CA. This
  30554  *   may happen if this was a version 1 certificate, which is common with
  30628  *   some CAs, or a version 3 certificate without the basic constrains extension.
  30710  * @GNUTLS_CERT_SIGNER_CONSTRAINTS_FAILURE: The certificate's signer constraints were
  30796  *   violated.
  30811  * @GNUTLS_CERT_INSECURE_ALGORITHM:  The certificate was signed using an insecure
  30893  *   algorithm such as MD2 or MD5. These algorithms have been broken and
  30966  *   should not be trusted.
  30994  * @GNUTLS_CERT_NOT_ACTIVATED: The certificate is not yet activated.
  31063  * @GNUTLS_CERT_EXPIRED: The certificate has expired.
  31117  * @GNUTLS_CERT_REVOCATION_DATA_SUPERSEDED: The revocation data are old and have been superseded.
  31215  * @GNUTLS_CERT_REVOCATION_DATA_ISSUED_IN_FUTURE: The revocation data have a future issue date.
  31311  * @GNUTLS_CERT_UNEXPECTED_OWNER: The owner is not the expected one.
  31380  * @GNUTLS_CERT_MISMATCH: The certificate presented isn't the expected one (TOFU)
  31462  * @GNUTLS_CERT_PURPOSE_MISMATCH: The certificate or an intermediate does not match the intended purpose (extended key usage).
  31589  * @GNUTLS_CERT_MISSING_OCSP_STATUS: The certificate requires the server to send the certifiate status, but no status was received.
  31721  * @GNUTLS_CERT_INVALID_OCSP_STATUS: The received OCSP status response is invalid.
  31804  * @GNUTLS_CERT_UNKNOWN_CRIT_EXTENSIONS: The certificate has extensions marked as critical which are not supported.
  31923  * Enumeration of certificate status codes.  Note that the status
  31989  * bits may have different meanings in OpenPGP keys and X.509
  32051  * certificate verification.
  32084 typedef enum {
  32099 	GNUTLS_CERT_INVALID = 1 << 1,
  32130 	GNUTLS_CERT_REVOKED = 1 << 5,
  32161 	GNUTLS_CERT_SIGNER_NOT_FOUND = 1 << 6,
  32201 	GNUTLS_CERT_SIGNER_NOT_CA = 1 << 7,
  32238 	GNUTLS_CERT_INSECURE_ALGORITHM = 1 << 8,
  32280 	GNUTLS_CERT_NOT_ACTIVATED = 1 << 9,
  32317 	GNUTLS_CERT_EXPIRED = 1 << 10,
  32349 	GNUTLS_CERT_SIGNATURE_FAILURE = 1 << 11,
  32391 	GNUTLS_CERT_REVOCATION_DATA_SUPERSEDED = 1 << 12,
  32442 	GNUTLS_CERT_UNEXPECTED_OWNER = 1 << 14,
  32483 	GNUTLS_CERT_REVOCATION_DATA_ISSUED_IN_FUTURE = 1 << 15,
  32540 	GNUTLS_CERT_SIGNER_CONSTRAINTS_FAILURE = 1 << 16,
  32591 	GNUTLS_CERT_MISMATCH = 1 << 17,
  32624 	GNUTLS_CERT_PURPOSE_MISMATCH = 1 << 18,
  32665 	GNUTLS_CERT_MISSING_OCSP_STATUS = 1 << 19,
  32709 	GNUTLS_CERT_INVALID_OCSP_STATUS = 1 << 20,
  32753 	GNUTLS_CERT_UNKNOWN_CRIT_EXTENSIONS = 1 << 21
  32800 } gnutls_certificate_status_t;
  32836  * gnutls_certificate_request_t:
  32869  * @GNUTLS_CERT_IGNORE: Ignore certificate.
  32913  * @GNUTLS_CERT_REQUEST: Request certificate.
  32959  * @GNUTLS_CERT_REQUIRE: Require certificate.
  33008  * Enumeration of certificate request types.
  33057 typedef enum {
  33072 	GNUTLS_CERT_IGNORE = 0,
  33097 	GNUTLS_CERT_REQUEST = 1,
  33123 	GNUTLS_CERT_REQUIRE = 2
  33148 } gnutls_certificate_request_t;
  33185  * gnutls_openpgp_crt_status_t:
  33217  * @GNUTLS_OPENPGP_CERT: Send entire certificate.
  33267  * @GNUTLS_OPENPGP_CERT_FINGERPRINT: Send only certificate fingerprint.
  33342  * Enumeration of ways to send OpenPGP certificate.
  33398 typedef enum {
  33413 	GNUTLS_OPENPGP_CERT = 0,
  33439 	GNUTLS_OPENPGP_CERT_FINGERPRINT = 1
  33476 } gnutls_openpgp_crt_status_t;
  33512  * gnutls_close_request_t:
  33539  * @GNUTLS_SHUT_RDWR: Disallow further receives/sends.
  33594  * @GNUTLS_SHUT_WR: Disallow further sends.
  33641  * Enumeration of how TLS session should be terminated.  See gnutls_bye().
  33720 typedef enum {
  33735 	GNUTLS_SHUT_RDWR = 0,
  33758 	GNUTLS_SHUT_WR = 1
  33778 } gnutls_close_request_t;
  33809  * gnutls_protocol_t:
  33831  * @GNUTLS_SSL3: SSL version 3.0.
  33865  * @GNUTLS_TLS1_0: TLS version 1.0.
  33901  * @GNUTLS_TLS1: Same as %GNUTLS_TLS1_0.
  33942  * @GNUTLS_TLS1_1: TLS version 1.1.
  33978  * @GNUTLS_TLS1_2: TLS version 1.2.
  34014  * @GNUTLS_TLS1_3: TLS version 1.3.
  34050  * @GNUTLS_DTLS1_0: DTLS version 1.0.
  34088  * @GNUTLS_DTLS1_2: DTLS version 1.2.
  34126  * @GNUTLS_DTLS0_9: DTLS version 0.9 (Cisco AnyConnect / OpenSSL 0.9.8e).
  34200  * @GNUTLS_TLS_VERSION_MAX: Maps to the highest supported TLS version.
  34271  * @GNUTLS_DTLS_VERSION_MAX: Maps to the highest supported DTLS version.
  34344  * @GNUTLS_VERSION_UNKNOWN: Unknown SSL/TLS version.
  34400  * Enumeration of different SSL/TLS protocol versions.
  34459 typedef enum {
  34474 	GNUTLS_SSL3 = 1,
  34492 	GNUTLS_TLS1_0 = 2,
  34512 	GNUTLS_TLS1 = GNUTLS_TLS1_0,
  34542 	GNUTLS_TLS1_1 = 3,
  34562 	GNUTLS_TLS1_2 = 4,
  34582 	GNUTLS_TLS1_3 = 5,
  34603 	GNUTLS_DTLS0_9 = 200,
  34626 	GNUTLS_DTLS1_0 = 201,	/* 201 */
  34659 	GNUTLS_DTLS1_2 = 202,
  34682 	GNUTLS_DTLS_VERSION_MIN = GNUTLS_DTLS0_9,
  34725 	GNUTLS_DTLS_VERSION_MAX = GNUTLS_DTLS1_2,
  34768 	GNUTLS_TLS_VERSION_MAX = GNUTLS_TLS1_3,
  34809 	GNUTLS_VERSION_UNKNOWN = 0xff	/* change it to 0xffff */
  34866 } gnutls_protocol_t;
  34888 #define GNUTLS_CRT_RAW GNUTLS_CRT_RAWPK
  34933  * gnutls_certificate_type_t:
  34963  * @GNUTLS_CRT_UNKNOWN: Unknown certificate type.
  35013  * @GNUTLS_CRT_X509: X.509 Certificate.
  35053  * @GNUTLS_CRT_OPENPGP: OpenPGP certificate.
  35098  * @GNUTLS_CRT_RAWPK: Raw public-key (SubjectPublicKeyInfo)
  35161  * Enumeration of different certificate types.
  35212 typedef enum {
  35227 	GNUTLS_CRT_UNKNOWN = 0,
  35252 	GNUTLS_CRT_X509 = 1,
  35274 	GNUTLS_CRT_OPENPGP = 2,
  35299 	GNUTLS_CRT_RAWPK = 3,
  35322 	GNUTLS_CRT_MAX = GNUTLS_CRT_RAWPK
  35357 } gnutls_certificate_type_t;
  35391  * gnutls_x509_crt_fmt_t:
  35417  * @GNUTLS_X509_FMT_DER: X.509 certificate in DER format (binary).
  35484  * @GNUTLS_X509_FMT_PEM: X.509 certificate in PEM format (text).
  35552  * Enumeration of different certificate encoding formats.
  35614 typedef enum {
  35629 	GNUTLS_X509_FMT_DER = 0,
  35655 	GNUTLS_X509_FMT_PEM = 1
  35680 } gnutls_x509_crt_fmt_t;
  35710  * gnutls_certificate_print_formats_t:
  35749  * @GNUTLS_CRT_PRINT_FULL: Full information about certificate.
  35812  * @GNUTLS_CRT_PRINT_FULL_NUMBERS: Full information about certificate and include easy to parse public key parameters.
  35931  * @GNUTLS_CRT_PRINT_COMPACT: Information about certificate name in one line, plus identification of the public key.
  36048  * @GNUTLS_CRT_PRINT_ONELINE: Information about certificate in one line.
  36121  * @GNUTLS_CRT_PRINT_UNSIGNED_FULL: All info for an unsigned certificate.
  36198  * Enumeration of different certificate printing variants.
  36261 typedef enum gnutls_certificate_print_formats {
  36309 	GNUTLS_CRT_PRINT_FULL = 0,
  36337 	GNUTLS_CRT_PRINT_ONELINE = 1,
  36368 	GNUTLS_CRT_PRINT_UNSIGNED_FULL = 2,
  36405 	GNUTLS_CRT_PRINT_COMPACT = 3,
  36436 	GNUTLS_CRT_PRINT_FULL_NUMBERS = 4
  36471 } gnutls_certificate_print_formats_t;
  36510 #define GNUTLS_PK_ECC GNUTLS_PK_ECDSA
  36548 #define GNUTLS_PK_EC GNUTLS_PK_ECDSA
  36586 #define GNUTLS_PK_ECDHX GNUTLS_PK_ECDH_X25519
  36636  * gnutls_pk_algorithm_t:
  36662  * @GNUTLS_PK_UNKNOWN: Unknown public-key algorithm.
  36715  * @GNUTLS_PK_RSA: RSA public-key algorithm.
  36760  * @GNUTLS_PK_RSA_PSS: RSA public-key algorithm, with PSS padding.
  36827  * @GNUTLS_PK_DSA: DSA public-key algorithm.
  36872  * @GNUTLS_PK_DH: Diffie-Hellman algorithm. Used to generate parameters.
  36945  * @GNUTLS_PK_ECDSA: Elliptic curve algorithm. These parameters are compatible with the ECDSA and ECDH algorithm.
  37059  * @GNUTLS_PK_ECDH_X25519: Elliptic curve algorithm, restricted to ECDH as per rfc7748.
  37147  * @GNUTLS_PK_EDDSA_ED25519: Edwards curve Digital signature algorithm. Used with SHA512 on signatures.
  37251  * @GNUTLS_PK_GOST_01: GOST R 34.10-2001 algorithm per rfc5832.
  37315  * @GNUTLS_PK_GOST_12_256: GOST R 34.10-2012 algorithm, 256-bit key per rfc7091.
  37396  * @GNUTLS_PK_GOST_12_512: GOST R 34.10-2012 algorithm, 512-bit key per rfc7091.
  37477  * @GNUTLS_PK_ECDH_X448: Elliptic curve algorithm, restricted to ECDH as per rfc7748.
  37563  * @GNUTLS_PK_EDDSA_ED448: Edwards curve Digital signature algorithm. Used with SHAKE256 on signatures.
  37670  * Enumeration of different public-key algorithms.
  37725 typedef enum {
  37740 	GNUTLS_PK_UNKNOWN = 0,
  37764 	GNUTLS_PK_RSA = 1,
  37784 	GNUTLS_PK_DSA = 2,
  37804 	GNUTLS_PK_DH = 3,
  37823 	GNUTLS_PK_ECDSA = 4,
  37845 	GNUTLS_PK_ECDH_X25519 = 5,
  37873 	GNUTLS_PK_RSA_PSS = 6,
  37897 	GNUTLS_PK_EDDSA_ED25519 = 7,
  37927 	GNUTLS_PK_GOST_01 = 8,
  37951 	GNUTLS_PK_GOST_12_256 = 9,
  37979 	GNUTLS_PK_GOST_12_512 = 10,
  38008 	GNUTLS_PK_ECDH_X448 = 11,
  38035 	GNUTLS_PK_EDDSA_ED448 = 12,
  38064 	GNUTLS_PK_MAX = GNUTLS_PK_EDDSA_ED448
  38103 } gnutls_pk_algorithm_t;
  38130 const char *gnutls_pk_algorithm_get_name(gnutls_pk_algorithm_t algorithm);
  38210  * gnutls_sign_algorithm_t:
  38238  * @GNUTLS_SIGN_UNKNOWN: Unknown signature algorithm.
  38292  * @GNUTLS_SIGN_RSA_RAW: Digital signature algorithm RSA with DigestInfo formatted data
  38380  * @GNUTLS_SIGN_RSA_SHA1: Digital signature algorithm RSA with SHA-1
  38449  * @GNUTLS_SIGN_RSA_SHA: Same as %GNUTLS_SIGN_RSA_SHA1.
  38505  * @GNUTLS_SIGN_DSA_SHA1: Digital signature algorithm DSA with SHA-1
  38574  * @GNUTLS_SIGN_DSA_SHA224: Digital signature algorithm DSA with SHA-224
  38647  * @GNUTLS_SIGN_DSA_SHA256: Digital signature algorithm DSA with SHA-256
  38720  * @GNUTLS_SIGN_DSA_SHA384: Digital signature algorithm DSA with SHA-384
  38793  * @GNUTLS_SIGN_DSA_SHA512: Digital signature algorithm DSA with SHA-512
  38866  * @GNUTLS_SIGN_DSA_SHA: Same as %GNUTLS_SIGN_DSA_SHA1.
  38922  * @GNUTLS_SIGN_RSA_MD5: Digital signature algorithm RSA with MD5.
  38989  * @GNUTLS_SIGN_RSA_MD2: Digital signature algorithm RSA with MD2.
  39056  * @GNUTLS_SIGN_RSA_RMD160: Digital signature algorithm RSA with RMD-160.
  39130  * @GNUTLS_SIGN_RSA_SHA256: Digital signature algorithm RSA with SHA-256.
  39204  * @GNUTLS_SIGN_RSA_SHA384: Digital signature algorithm RSA with SHA-384.
  39278  * @GNUTLS_SIGN_RSA_SHA512: Digital signature algorithm RSA with SHA-512.
  39352  * @GNUTLS_SIGN_RSA_SHA224: Digital signature algorithm RSA with SHA-224.
  39426  * @GNUTLS_SIGN_ECDSA_SHA1: ECDSA with SHA1.
  39471  * @GNUTLS_SIGN_ECDSA_SHA224: Digital signature algorithm ECDSA with SHA-224.
  39549  * @GNUTLS_SIGN_ECDSA_SHA256: Digital signature algorithm ECDSA with SHA-256.
  39627  * @GNUTLS_SIGN_ECDSA_SHA384: Digital signature algorithm ECDSA with SHA-384.
  39705  * @GNUTLS_SIGN_ECDSA_SHA512: Digital signature algorithm ECDSA with SHA-512.
  39783  * @GNUTLS_SIGN_ECDSA_SECP256R1_SHA256: Digital signature algorithm ECDSA-SECP256R1 with SHA-256 (used in TLS 1.3 but not PKIX).
  39912  * @GNUTLS_SIGN_ECDSA_SECP384R1_SHA384: Digital signature algorithm ECDSA-SECP384R1 with SHA-384 (used in TLS 1.3 but not PKIX).
  40041  * @GNUTLS_SIGN_ECDSA_SECP521R1_SHA512: Digital signature algorithm ECDSA-SECP521R1 with SHA-512 (used in TLS 1.3 but not PKIX).
  40170  * @GNUTLS_SIGN_ECDSA_SHA3_224: Digital signature algorithm ECDSA with SHA3-224.
  40251  * @GNUTLS_SIGN_ECDSA_SHA3_256: Digital signature algorithm ECDSA with SHA3-256.
  40332  * @GNUTLS_SIGN_ECDSA_SHA3_384: Digital signature algorithm ECDSA with SHA3-384.
  40413  * @GNUTLS_SIGN_ECDSA_SHA3_512: Digital signature algorithm ECDSA with SHA3-512.
  40494  * @GNUTLS_SIGN_DSA_SHA3_224: Digital signature algorithm DSA with SHA3-224.
  40571  * @GNUTLS_SIGN_DSA_SHA3_256: Digital signature algorithm DSA with SHA3-256.
  40648  * @GNUTLS_SIGN_DSA_SHA3_384: Digital signature algorithm DSA with SHA3-384.
  40725  * @GNUTLS_SIGN_DSA_SHA3_512: Digital signature algorithm DSA with SHA3-512.
  40802  * @GNUTLS_SIGN_RSA_SHA3_224: Digital signature algorithm RSA with SHA3-224.
  40879  * @GNUTLS_SIGN_RSA_SHA3_256: Digital signature algorithm RSA with SHA3-256.
  40956  * @GNUTLS_SIGN_RSA_SHA3_384: Digital signature algorithm RSA with SHA3-384.
  41033  * @GNUTLS_SIGN_RSA_SHA3_512: Digital signature algorithm RSA with SHA3-512.
  41110  * @GNUTLS_SIGN_RSA_PSS_RSAE_SHA256: Digital signature algorithm RSA with SHA-256,
  41193  *      with PSS padding (RSA PKCS#1 1.5 certificate). This signature is identical
  41276  *      to #GNUTLS_SIGN_RSA_PSS_SHA256, but they are distinct as the TLS1.3 protocol
  41361  *      treats them differently.
  41394  * @GNUTLS_SIGN_RSA_PSS_RSAE_SHA384: Digital signature algorithm RSA with SHA-384,
  41477  *      with PSS padding (RSA PKCS#1 1.5 certificate). This signature is identical
  41560  *      to #GNUTLS_SIGN_RSA_PSS_SHA384, but they are distinct as the TLS1.3 protocol
  41645  *      treats them differently.
  41678  * @GNUTLS_SIGN_RSA_PSS_RSAE_SHA512: Digital signature algorithm RSA with SHA-512,
  41761  *      with PSS padding (RSA PKCS#1 1.5 certificate). This signature is identical
  41844  *      to #GNUTLS_SIGN_RSA_PSS_SHA512, but they are distinct as the TLS1.3 protocol
  41929  *      treats them differently.
  41962  * @GNUTLS_SIGN_RSA_PSS_SHA256: Digital signature algorithm RSA with SHA-256, with PSS padding (RSA-PSS certificate).
  42080  * @GNUTLS_SIGN_RSA_PSS_SHA384: Digital signature algorithm RSA with SHA-384, with PSS padding (RSA-PSS certificate).
  42198  * @GNUTLS_SIGN_RSA_PSS_SHA512: Digital signature algorithm RSA with SHA-512, with PSS padding (RSA-PSS certificate).
  42316  * @GNUTLS_SIGN_EDDSA_ED25519: Digital signature algorithm EdDSA with Ed25519 curve.
  42401  * @GNUTLS_SIGN_GOST_94: Digital signature algorithm GOST R 34.10-2001 with GOST R 34.11-94
  42493  * @GNUTLS_SIGN_GOST_256: Digital signature algorithm GOST R 34.10-2012 with GOST R 34.11-2012 256 bit
  42596  * @GNUTLS_SIGN_GOST_512: Digital signature algorithm GOST R 34.10-2012 with GOST R 34.11-2012 512 bit
  42699  * @GNUTLS_SIGN_EDDSA_ED448: Digital signature algorithm EdDSA with Ed448 curve.
  42783  * Enumeration of different digital signature algorithms.
  42845 typedef enum {
  42860 	GNUTLS_SIGN_UNKNOWN = 0,
  42886 	GNUTLS_SIGN_RSA_SHA1 = 1,
  42913 	GNUTLS_SIGN_RSA_SHA = GNUTLS_SIGN_RSA_SHA1,
  42958 	GNUTLS_SIGN_DSA_SHA1 = 2,
  42985 	GNUTLS_SIGN_DSA_SHA = GNUTLS_SIGN_DSA_SHA1,
  43030 	GNUTLS_SIGN_RSA_MD5 = 3,
  43056 	GNUTLS_SIGN_RSA_MD2 = 4,
  43082 	GNUTLS_SIGN_RSA_RMD160 = 5,
  43111 	GNUTLS_SIGN_RSA_SHA256 = 6,
  43140 	GNUTLS_SIGN_RSA_SHA384 = 7,
  43169 	GNUTLS_SIGN_RSA_SHA512 = 8,
  43198 	GNUTLS_SIGN_RSA_SHA224 = 9,
  43227 	GNUTLS_SIGN_DSA_SHA224 = 10,
  43257 	GNUTLS_SIGN_DSA_SHA256 = 11,
  43287 	GNUTLS_SIGN_ECDSA_SHA1 = 12,
  43317 	GNUTLS_SIGN_ECDSA_SHA224 = 13,
  43349 	GNUTLS_SIGN_ECDSA_SHA256 = 14,
  43381 	GNUTLS_SIGN_ECDSA_SHA384 = 15,
  43413 	GNUTLS_SIGN_ECDSA_SHA512 = 16,
  43445 	GNUTLS_SIGN_DSA_SHA384 = 17,
  43475 	GNUTLS_SIGN_DSA_SHA512 = 18,
  43505 	GNUTLS_SIGN_ECDSA_SHA3_224 = 20,
  43539 	GNUTLS_SIGN_ECDSA_SHA3_256 = 21,
  43573 	GNUTLS_SIGN_ECDSA_SHA3_384 = 22,
  43607 	GNUTLS_SIGN_ECDSA_SHA3_512 = 23,
  43642 	GNUTLS_SIGN_DSA_SHA3_224 = 24,
  43674 	GNUTLS_SIGN_DSA_SHA3_256 = 25,
  43706 	GNUTLS_SIGN_DSA_SHA3_384 = 26,
  43738 	GNUTLS_SIGN_DSA_SHA3_512 = 27,
  43770 	GNUTLS_SIGN_RSA_SHA3_224 = 28,
  43802 	GNUTLS_SIGN_RSA_SHA3_256 = 29,
  43834 	GNUTLS_SIGN_RSA_SHA3_384 = 30,
  43866 	GNUTLS_SIGN_RSA_SHA3_512 = 31,
  43899 	GNUTLS_SIGN_RSA_PSS_SHA256 = 32,
  43933 	GNUTLS_SIGN_RSA_PSS_SHA384 = 33,
  43967 	GNUTLS_SIGN_RSA_PSS_SHA512 = 34,
  44001 	GNUTLS_SIGN_EDDSA_ED25519 = 35,
  44034 	GNUTLS_SIGN_RSA_RAW = 36,
  44062 	GNUTLS_SIGN_ECDSA_SECP256R1_SHA256 = 37,
  44104 	GNUTLS_SIGN_ECDSA_SECP384R1_SHA384 = 38,
  44146 	GNUTLS_SIGN_ECDSA_SECP521R1_SHA512 = 39,
  44189 	GNUTLS_SIGN_RSA_PSS_RSAE_SHA256 = 40,
  44228 	GNUTLS_SIGN_RSA_PSS_RSAE_SHA384 = 41,
  44267 	GNUTLS_SIGN_RSA_PSS_RSAE_SHA512 = 42,
  44307 	GNUTLS_SIGN_GOST_94 = 43,
  44334 	GNUTLS_SIGN_GOST_256 = 44,
  44362 	GNUTLS_SIGN_GOST_512 = 45,
  44390 	GNUTLS_SIGN_EDDSA_ED448 = 46,
  44421 	GNUTLS_SIGN_MAX = GNUTLS_SIGN_EDDSA_ED448
  44464 } gnutls_sign_algorithm_t;
  44496  * gnutls_ecc_curve_t:
  44519  * @GNUTLS_ECC_CURVE_INVALID: Cannot be known
  44565  * @GNUTLS_ECC_CURVE_SECP192R1: the SECP192R1 curve
  44617  * @GNUTLS_ECC_CURVE_SECP224R1: the SECP224R1 curve
  44669  * @GNUTLS_ECC_CURVE_SECP256R1: the SECP256R1 curve
  44721  * @GNUTLS_ECC_CURVE_SECP384R1: the SECP384R1 curve
  44773  * @GNUTLS_ECC_CURVE_SECP521R1: the SECP521R1 curve
  44825  * @GNUTLS_ECC_CURVE_X25519: the X25519 curve (ECDH only)
  44883  * @GNUTLS_ECC_CURVE_ED25519: the Ed25519 curve
  44931  * @GNUTLS_ECC_CURVE_GOST256CPA: GOST R 34.10 CryptoPro 256 A curve
  44999  * @GNUTLS_ECC_CURVE_GOST256CPB: GOST R 34.10 CryptoPro 256 B curve
  45067  * @GNUTLS_ECC_CURVE_GOST256CPC: GOST R 34.10 CryptoPro 256 C curve
  45135  * @GNUTLS_ECC_CURVE_GOST256CPXA: GOST R 34.10 CryptoPro 256 XchA curve
  45207  * @GNUTLS_ECC_CURVE_GOST256CPXB: GOST R 34.10 CryptoPro 256 XchB curve
  45279  * @GNUTLS_ECC_CURVE_GOST512A: GOST R 34.10 TC26 512 A curve
  45340  * @GNUTLS_ECC_CURVE_GOST512B: GOST R 34.10 TC26 512 B curve
  45401  * @GNUTLS_ECC_CURVE_GOST512C: GOST R 34.10 TC26 512 C curve
  45462  * @GNUTLS_ECC_CURVE_GOST256A: GOST R 34.10 TC26 256 A curve
  45523  * @GNUTLS_ECC_CURVE_GOST256B: GOST R 34.10 TC26 256 B curve
  45584  * @GNUTLS_ECC_CURVE_GOST256C: GOST R 34.10 TC26 256 C curve
  45645  * @GNUTLS_ECC_CURVE_GOST256D: GOST R 34.10 TC26 256 D curve
  45706  * @GNUTLS_ECC_CURVE_X448: the X448 curve (ECDH only)
  45760  * @GNUTLS_ECC_CURVE_ED448: the Ed448 curve
  45807  * Enumeration of ECC curves.
  45841 typedef enum {
  45856 	GNUTLS_ECC_CURVE_INVALID = 0,
  45887 	GNUTLS_ECC_CURVE_SECP224R1,
  45916 	GNUTLS_ECC_CURVE_SECP256R1,
  45945 	GNUTLS_ECC_CURVE_SECP384R1,
  45974 	GNUTLS_ECC_CURVE_SECP521R1,
  46003 	GNUTLS_ECC_CURVE_SECP192R1,
  46032 	GNUTLS_ECC_CURVE_X25519,
  46058 	GNUTLS_ECC_CURVE_ED25519,
  46085 	GNUTLS_ECC_CURVE_GOST256CPA,
  46115 	GNUTLS_ECC_CURVE_GOST256CPB,
  46145 	GNUTLS_ECC_CURVE_GOST256CPC,
  46175 	GNUTLS_ECC_CURVE_GOST256CPXA,
  46206 	GNUTLS_ECC_CURVE_GOST256CPXB,
  46237 	GNUTLS_ECC_CURVE_GOST512A,
  46265 	GNUTLS_ECC_CURVE_GOST512B,
  46293 	GNUTLS_ECC_CURVE_GOST512C,
  46321 	GNUTLS_ECC_CURVE_GOST256A,
  46349 	GNUTLS_ECC_CURVE_GOST256B,
  46377 	GNUTLS_ECC_CURVE_GOST256C,
  46405 	GNUTLS_ECC_CURVE_GOST256D,
  46433 	GNUTLS_ECC_CURVE_X448,
  46457 	GNUTLS_ECC_CURVE_ED448,
  46482 	GNUTLS_ECC_CURVE_MAX = GNUTLS_ECC_CURVE_ED448
  46529 } gnutls_ecc_curve_t;
  46556  * gnutls_group_t:
  46575  * @GNUTLS_GROUP_INVALID: Indicates unknown/invalid group
  46633  * @GNUTLS_GROUP_SECP192R1: the SECP192R1 curve group (legacy, only for TLS 1.2 compatibility)
  46728  * @GNUTLS_GROUP_SECP224R1: the SECP224R1 curve group (legacy, only for TLS 1.2 compatibility)
  46823  * @GNUTLS_GROUP_SECP256R1: the SECP256R1 curve group
  46877  * @GNUTLS_GROUP_SECP384R1: the SECP384R1 curve group
  46931  * @GNUTLS_GROUP_SECP521R1: the SECP521R1 curve group
  46985  * @GNUTLS_GROUP_X25519: the X25519 curve group
  47033  * @GNUTLS_GROUP_GC256A: the GOST R 34.10 TC26 256 A curve group
  47098  * @GNUTLS_GROUP_GC256B: the GOST R 34.10 TC26 256 B curve group
  47163  * @GNUTLS_GROUP_GC256C: the GOST R 34.10 TC26 256 C curve group
  47228  * @GNUTLS_GROUP_GC256D: the GOST R 34.10 TC26 256 D curve group
  47293  * @GNUTLS_GROUP_GC512A: the GOST R 34.10 TC26 512 A curve group
  47358  * @GNUTLS_GROUP_GC512B: the GOST R 34.10 TC26 512 B curve group
  47423  * @GNUTLS_GROUP_GC512C: the GOST R 34.10 TC26 512 C curve group
  47488  * @GNUTLS_GROUP_FFDHE2048: the FFDHE2048 group
  47536  * @GNUTLS_GROUP_FFDHE3072: the FFDHE3072 group
  47584  * @GNUTLS_GROUP_FFDHE4096: the FFDHE4096 group
  47632  * @GNUTLS_GROUP_FFDHE6144: the FFDHE6144 group
  47680  * @GNUTLS_GROUP_FFDHE8192: the FFDHE8192 group
  47728  * @GNUTLS_GROUP_X448: the X448 curve group
  47775  * Enumeration of supported groups. It is intended to be backwards
  47842  * compatible with the enumerations in %gnutls_ecc_curve_t for the groups
  47916  * which are valid elliptic curves.
  47956 typedef enum {
  47971 	GNUTLS_GROUP_INVALID = 0,
  47998 	GNUTLS_GROUP_SECP192R1 = GNUTLS_ECC_CURVE_SECP192R1,
  48052 	GNUTLS_GROUP_SECP224R1 = GNUTLS_ECC_CURVE_SECP224R1,
  48106 	GNUTLS_GROUP_SECP256R1 = GNUTLS_ECC_CURVE_SECP256R1,
  48160 	GNUTLS_GROUP_SECP384R1 = GNUTLS_ECC_CURVE_SECP384R1,
  48214 	GNUTLS_GROUP_SECP521R1 = GNUTLS_ECC_CURVE_SECP521R1,
  48268 	GNUTLS_GROUP_X25519 = GNUTLS_ECC_CURVE_X25519,
  48316 	GNUTLS_GROUP_X448 = GNUTLS_ECC_CURVE_X448,
  48361 	GNUTLS_GROUP_GC256A = GNUTLS_ECC_CURVE_GOST256A,
  48411 	GNUTLS_GROUP_GC256B = GNUTLS_ECC_CURVE_GOST256B,
  48461 	GNUTLS_GROUP_GC256C = GNUTLS_ECC_CURVE_GOST256C,
  48511 	GNUTLS_GROUP_GC256D = GNUTLS_ECC_CURVE_GOST256D,
  48561 	GNUTLS_GROUP_GC512A = GNUTLS_ECC_CURVE_GOST512A,
  48611 	GNUTLS_GROUP_GC512B = GNUTLS_ECC_CURVE_GOST512B,
  48661 	GNUTLS_GROUP_GC512C = GNUTLS_ECC_CURVE_GOST512C,
  48712 	GNUTLS_GROUP_FFDHE2048 = 256,
  48743 	GNUTLS_GROUP_FFDHE3072,
  48768 	GNUTLS_GROUP_FFDHE4096,
  48793 	GNUTLS_GROUP_FFDHE8192,
  48818 	GNUTLS_GROUP_FFDHE6144,
  48843 	GNUTLS_GROUP_MAX = GNUTLS_GROUP_FFDHE6144,
  48887 } gnutls_group_t;
  48906 /* macros to allow specifying a specific curve in gnutls_privkey_generate()
  48982  * and gnutls_x509_privkey_generate() */
  49023 #define GNUTLS_CURVE_TO_BITS(curve) (unsigned int)(((unsigned int)1<<31)|((unsigned int)(curve)))
  49121 #define GNUTLS_BITS_TO_CURVE(bits) (((unsigned int)(bits)) & 0x7FFFFFFF)
  49194 #define GNUTLS_BITS_ARE_CURVE(bits) (((unsigned int)(bits)) & 0x80000000)
  49273  * gnutls_sec_param_t:
  49296  * @GNUTLS_SEC_PARAM_UNKNOWN: Cannot be known
  49342  * @GNUTLS_SEC_PARAM_INSECURE: Less than 42 bits of security
  49403  * @GNUTLS_SEC_PARAM_EXPORT: 42 bits of security
  49452  * @GNUTLS_SEC_PARAM_VERY_WEAK: 64 bits of security
  49504  * @GNUTLS_SEC_PARAM_WEAK: 72 bits of security
  49551  * @GNUTLS_SEC_PARAM_LOW: 80 bits of security
  49597  * @GNUTLS_SEC_PARAM_LEGACY: 96 bits of security
  49646  * @GNUTLS_SEC_PARAM_MEDIUM: 112 bits of security (used to be %GNUTLS_SEC_PARAM_NORMAL)
  49734  * @GNUTLS_SEC_PARAM_HIGH: 128 bits of security
  49782  * @GNUTLS_SEC_PARAM_ULTRA: 192 bits of security
  49831  * @GNUTLS_SEC_PARAM_FUTURE: 256 bits of security
  49884  * Enumeration of security parameters for passive attacks.
  49947 typedef enum {
  49962 	GNUTLS_SEC_PARAM_UNKNOWN = 0,
  49993 	GNUTLS_SEC_PARAM_INSECURE = 5,
  50025 	GNUTLS_SEC_PARAM_EXPORT = 10,
  50056 	GNUTLS_SEC_PARAM_VERY_WEAK = 15,
  50090 	GNUTLS_SEC_PARAM_WEAK = 20,
  50119 	GNUTLS_SEC_PARAM_LOW = 25,
  50147 	GNUTLS_SEC_PARAM_LEGACY = 30,
  50178 	GNUTLS_SEC_PARAM_MEDIUM = 35,
  50209 	GNUTLS_SEC_PARAM_HIGH = 40,
  50238 	GNUTLS_SEC_PARAM_ULTRA = 45,
  50268 	GNUTLS_SEC_PARAM_FUTURE = 50,
  50299 	GNUTLS_SEC_PARAM_MAX = GNUTLS_SEC_PARAM_FUTURE
  50347 } gnutls_sec_param_t;
  50370 /* old name */
  50385 #define GNUTLS_SEC_PARAM_NORMAL GNUTLS_SEC_PARAM_MEDIUM
  50446  * gnutls_channel_binding_t:
  50475  * @GNUTLS_CB_TLS_UNIQUE: "tls-unique" (RFC 5929) channel binding
  50541  * @GNUTLS_CB_TLS_SERVER_END_POINT: "tls-server-end-point" (RFC 5929) channel binding
  50627  * @GNUTLS_CB_TLS_EXPORTER: "tls-exporter" (draft-ietf-kitten-tls-channel-bindings-for-tls13-03)
  50727  * Enumeration of supported channel binding types.
  50782 typedef enum {
  50797 	GNUTLS_CB_TLS_UNIQUE,
  50820 	GNUTLS_CB_TLS_SERVER_END_POINT,
  50853 	GNUTLS_CB_TLS_EXPORTER
  50877 } gnutls_channel_binding_t;
  50910  * gnutls_gost_paramset_t:
  50937  * @GNUTLS_GOST_PARAMSET_UNKNOWN: Unknown/default parameter set
  51001  * @GNUTLS_GOST_PARAMSET_TC26_Z: Specified by TC26, see rfc7836
  51065  * @GNUTLS_GOST_PARAMSET_CP_A: CryptoPro-A, see rfc4357
  51121  * @GNUTLS_GOST_PARAMSET_CP_B: CryptoPro-B, see rfc4357
  51177  * @GNUTLS_GOST_PARAMSET_CP_C: CryptoPro-C, see rfc4357
  51233  * @GNUTLS_GOST_PARAMSET_CP_D: CryptoPro-D, see rfc4357
  51292  * Enumeration of different GOST 28147 parameter sets.
  51351 typedef enum {
  51366 	GNUTLS_GOST_PARAMSET_UNKNOWN = 0,
  51401 	GNUTLS_GOST_PARAMSET_TC26_Z,
  51431 	GNUTLS_GOST_PARAMSET_CP_A,
  51459 	GNUTLS_GOST_PARAMSET_CP_B,
  51487 	GNUTLS_GOST_PARAMSET_CP_C,
  51515 	GNUTLS_GOST_PARAMSET_CP_D
  51542 } gnutls_gost_paramset_t;
  51573  * gnutls_ctype_target_t:
  51599  * @GNUTLS_CTYPE_CLIENT: for requesting client certificate type values.
  51671  * @GNUTLS_CTYPE_SERVER: for requesting server certificate type values.
  51743  * @GNUTLS_CTYPE_OURS: for requesting our certificate type values.
  51810  * @GNUTLS_CTYPE_PEERS: for requesting the peers' certificate type values.
  51888  * Enumeration of certificate type targets with respect to asymmetric
  51958  * certificate types as specified in RFC7250 and P2P connection set up
  52029  * as specified in draft-vanrein-tls-symmetry-02.
  52083 typedef enum {
  52098 	GNUTLS_CTYPE_CLIENT,
  52120 	GNUTLS_CTYPE_SERVER,
  52142 	GNUTLS_CTYPE_OURS,
  52162 	GNUTLS_CTYPE_PEERS
  52182 } gnutls_ctype_target_t;
  52208 /* If you want to change this, then also change the define in
  52270  * gnutls_int.h, and recompile.
  52306 typedef void *gnutls_transport_ptr_t;
  52345 struct gnutls_session_int;
  52372 typedef struct gnutls_session_int *gnutls_session_t;
  52426 struct gnutls_dh_params_int;
  52455 typedef struct gnutls_dh_params_int *gnutls_dh_params_t;
  52513   /* XXX ugly. */
  52531 struct gnutls_x509_privkey_int;
  52563 typedef struct gnutls_x509_privkey_int *gnutls_rsa_params_t;
  52625 struct gnutls_priority_st;
  52652 typedef struct gnutls_priority_st *gnutls_priority_t;
  52707 typedef struct {
  52724 	unsigned char *data;
  52746 	unsigned int size;
  52766 } gnutls_datum_t;
  52785 typedef struct gnutls_library_config_st {
  52827 	const char *name;
  52846 	const char *value;
  52866 } gnutls_library_config_st;
  52896 typedef struct gnutls_params_st {
  52930 	gnutls_params_type_t type;
  52958 	union params {
  52974 		gnutls_dh_params_t dh;
  52999 		gnutls_rsa_params_t rsa_export;
  53033 	} params;
  53044 	int deinit;
  53057 } gnutls_params_st;
  53078 typedef int gnutls_params_function(gnutls_session_t, gnutls_params_type_t,
  53153 				   gnutls_params_st *);
  53182 /* internal functions */
  53208 int gnutls_init(gnutls_session_t * session, unsigned int flags);
  53273 void gnutls_deinit(gnutls_session_t session);
  53319 #define _gnutls_deinit(x) gnutls_deinit(x)
  53363 int gnutls_bye(gnutls_session_t session, gnutls_close_request_t how);
  53434 int gnutls_handshake(gnutls_session_t session);
  53483 int gnutls_reauth(gnutls_session_t session, unsigned int flags);
  53549 #define GNUTLS_DEFAULT_HANDSHAKE_TIMEOUT ((unsigned int)-1)
  53609 #define GNUTLS_INDEFINITE_TIMEOUT ((unsigned int)-2)
  53662 void gnutls_handshake_set_timeout(gnutls_session_t session,
  53722 				  unsigned int ms);
  53746 int gnutls_rehandshake(gnutls_session_t session);
  53797 #define GNUTLS_KU_PEER 1
  53822 int gnutls_session_key_update(gnutls_session_t session, unsigned flags);
  53896 gnutls_alert_description_t gnutls_alert_get(gnutls_session_t session);
  53967 int gnutls_alert_send(gnutls_session_t session,
  54015 		      gnutls_alert_level_t level,
  54051 		      gnutls_alert_description_t desc);
  54093 int gnutls_alert_send_appropriate(gnutls_session_t session, int err);
  54163 const char *gnutls_alert_get_name(gnutls_alert_description_t alert);
  54232 const char *gnutls_alert_get_strname(gnutls_alert_description_t alert);
  54305 gnutls_sec_param_t gnutls_pk_bits_to_sec_param(gnutls_pk_algorithm_t algo,
  54380 					       unsigned int bits);
  54412 const char *gnutls_sec_param_get_name(gnutls_sec_param_t param);
  54477 unsigned int gnutls_sec_param_to_pk_bits(gnutls_pk_algorithm_t algo,
  54546 					 gnutls_sec_param_t param);
  54579 unsigned int
  54592 	gnutls_sec_param_to_symmetric_bits(gnutls_sec_param_t param) __GNUTLS_CONST__;
  54673 /* Elliptic curves */
  54695 const char *
  54708 	gnutls_ecc_curve_get_name(gnutls_ecc_curve_t curve) __GNUTLS_CONST__;
  54779 const char *
  54792 	gnutls_ecc_curve_get_oid(gnutls_ecc_curve_t curve) __GNUTLS_CONST__;
  54863 const char *
  54876 	gnutls_group_get_name(gnutls_group_t group) __GNUTLS_CONST__;
  54944 	gnutls_ecc_curve_get_size(gnutls_ecc_curve_t curve) __GNUTLS_CONST__;
  55015 gnutls_ecc_curve_t gnutls_ecc_curve_get(gnutls_session_t session);
  55083 gnutls_group_t gnutls_group_get(gnutls_session_t session);
  55143 /* get information on the current session */
  55188 gnutls_cipher_algorithm_t gnutls_cipher_get(gnutls_session_t session);
  55259 gnutls_cipher_algorithm_t gnutls_early_cipher_get(gnutls_session_t session);
  55336 gnutls_kx_algorithm_t gnutls_kx_get(gnutls_session_t session);
  55399 gnutls_mac_algorithm_t gnutls_mac_get(gnutls_session_t session);
  55464 gnutls_digest_algorithm_t gnutls_prf_hash_get(const gnutls_session_t session);
  55543 gnutls_digest_algorithm_t
  55569 gnutls_early_prf_hash_get(const gnutls_session_t session);
  55628 gnutls_certificate_type_t
  55654 gnutls_certificate_type_get(gnutls_session_t session);
  55709 gnutls_certificate_type_t
  55735 gnutls_certificate_type_get2(gnutls_session_t session,
  55790 			     gnutls_ctype_target_t target);
  55830 int gnutls_sign_algorithm_get(gnutls_session_t session);
  55887 int gnutls_sign_algorithm_get_client(gnutls_session_t session);
  55952 int gnutls_sign_algorithm_get_requested(gnutls_session_t session,
  56018 					size_t indx,
  56036 					gnutls_sign_algorithm_t * algo);
  56075 /* the name of the specified algorithms */
  56118 const char *
  56131 	gnutls_cipher_get_name(gnutls_cipher_algorithm_t algorithm) __GNUTLS_CONST__;
  56210 const char *
  56223 	gnutls_mac_get_name(gnutls_mac_algorithm_t algorithm) __GNUTLS_CONST__;
  56297 const char *
  56310 	gnutls_digest_get_name(gnutls_digest_algorithm_t algorithm) __GNUTLS_CONST__;
  56389 const char *
  56402 	gnutls_digest_get_oid(gnutls_digest_algorithm_t algorithm) __GNUTLS_CONST__;
  56481 const char *
  56494 	gnutls_kx_get_name(gnutls_kx_algorithm_t algorithm) __GNUTLS_CONST__;
  56565 const char *
  56578 	gnutls_certificate_type_get_name(gnutls_certificate_type_t
  56638 					     type) __GNUTLS_CONST__;
  56672 const char *
  56685 	gnutls_pk_get_name(gnutls_pk_algorithm_t algorithm) __GNUTLS_CONST__;
  56756 const char *
  56769 	gnutls_pk_get_oid(gnutls_pk_algorithm_t algorithm) __GNUTLS_CONST__;
  56840 const char *
  56853 	gnutls_sign_get_name(gnutls_sign_algorithm_t algorithm) __GNUTLS_CONST__;
  56929 const char *gnutls_sign_get_oid(gnutls_sign_algorithm_t sign) __GNUTLS_CONST__;
  57010 const char *
  57023 	gnutls_gost_paramset_get_name(gnutls_gost_paramset_t param) __GNUTLS_CONST__;
  57102 const char *
  57115 	gnutls_gost_paramset_get_oid(gnutls_gost_paramset_t param) __GNUTLS_CONST__;
  57194 size_t
  57201 	gnutls_cipher_get_key_size(gnutls_cipher_algorithm_t algorithm) __GNUTLS_CONST__;
  57284 size_t
  57291 	gnutls_mac_get_key_size(gnutls_mac_algorithm_t algorithm) __GNUTLS_CONST__;
  57369 unsigned gnutls_sign_is_secure(gnutls_sign_algorithm_t algorithm) __GNUTLS_CONST__;
  57454 /* It is possible that a signature algorithm is ok to use for short-lived
  57528  * data (e.g., to sign a TLS session), but not for data that are long-lived
  57604  * like certificates. This flag is about checking the security of the algorithm
  57684  * for long-lived data. */
  57711 #define GNUTLS_SIGN_FLAG_SECURE_FOR_CERTS 1
  57755 unsigned gnutls_sign_is_secure2(gnutls_sign_algorithm_t algorithm, unsigned int flags) __GNUTLS_CONST__;
  57861 gnutls_digest_algorithm_t
  57887 	gnutls_sign_get_hash_algorithm(gnutls_sign_algorithm_t sign) __GNUTLS_CONST__;
  57967 gnutls_pk_algorithm_t
  57989 	gnutls_sign_get_pk_algorithm(gnutls_sign_algorithm_t sign) __GNUTLS_CONST__;
  58067 gnutls_sign_algorithm_t
  58091 	gnutls_pk_to_sign(gnutls_pk_algorithm_t pk,
  58136 		  gnutls_digest_algorithm_t hash) __GNUTLS_CONST__;
  58191 unsigned
  58200 gnutls_sign_supports_pk_algorithm(gnutls_sign_algorithm_t sign, gnutls_pk_algorithm_t pk) __GNUTLS_CONST__;
  58309 #define gnutls_sign_algorithm_get_name gnutls_sign_get_name
  58370 gnutls_mac_algorithm_t gnutls_mac_get_id(const char *name) __GNUTLS_CONST__;
  58447 gnutls_digest_algorithm_t gnutls_digest_get_id(const char *name) __GNUTLS_CONST__;
  58531 gnutls_cipher_algorithm_t
  58557 	gnutls_cipher_get_id(const char *name) __GNUTLS_CONST__;
  58616 gnutls_kx_algorithm_t
  58638 	gnutls_kx_get_id(const char *name) __GNUTLS_CONST__;
  58692 gnutls_protocol_t
  58710 	gnutls_protocol_get_id(const char *name) __GNUTLS_CONST__;
  58770 gnutls_certificate_type_t
  58796 	gnutls_certificate_type_get_id(const char *name) __GNUTLS_CONST__;
  58864 gnutls_pk_algorithm_t
  58886 	gnutls_pk_get_id(const char *name) __GNUTLS_CONST__;
  58940 gnutls_sign_algorithm_t
  58964 	gnutls_sign_get_id(const char *name) __GNUTLS_CONST__;
  59020 gnutls_ecc_curve_t gnutls_ecc_curve_get_id(const char *name)  __GNUTLS_CONST__;
  59100 gnutls_pk_algorithm_t gnutls_ecc_curve_get_pk(gnutls_ecc_curve_t curve) __GNUTLS_CONST__;
  59190 gnutls_group_t gnutls_group_get_id(const char *name);
  59245 gnutls_digest_algorithm_t
  59271 	gnutls_oid_to_digest(const char *oid)  __GNUTLS_CONST__;
  59329 gnutls_mac_algorithm_t
  59352 	gnutls_oid_to_mac(const char *oid)  __GNUTLS_CONST__;
  59407 gnutls_pk_algorithm_t
  59429 	gnutls_oid_to_pk(const char *oid) __GNUTLS_CONST__;
  59482 gnutls_sign_algorithm_t
  59506 	gnutls_oid_to_sign(const char *oid) __GNUTLS_CONST__;
  59561 gnutls_ecc_curve_t
  59580 	gnutls_oid_to_ecc_curve(const char *oid) __GNUTLS_CONST__;
  59640 gnutls_gost_paramset_t
  59663 	gnutls_oid_to_gost_paramset(const char *oid) __GNUTLS_CONST__;
  59728   /* list supported algorithms */
  59762 const gnutls_ecc_curve_t *
  59789 	gnutls_ecc_curve_list(void)  __GNUTLS_PURE__;
  59836 const gnutls_group_t *
  59859 	gnutls_group_list(void)  __GNUTLS_PURE__;
  59902 const gnutls_cipher_algorithm_t *
  59936 	gnutls_cipher_list(void) __GNUTLS_PURE__;
  59979 const gnutls_mac_algorithm_t *
  60010 	gnutls_mac_list(void) __GNUTLS_PURE__;
  60050 const gnutls_digest_algorithm_t *
  60084 	gnutls_digest_list(void) __GNUTLS_PURE__;
  60127 const gnutls_protocol_t *
  60153 	gnutls_protocol_list(void) __GNUTLS_PURE__;
  60198 const gnutls_certificate_type_t *
  60232 	gnutls_certificate_type_list(void) __GNUTLS_PURE__;
  60285 const gnutls_kx_algorithm_t *
  60315 	gnutls_kx_list(void) __GNUTLS_PURE__;
  60354 const gnutls_pk_algorithm_t *
  60384 	gnutls_pk_list(void) __GNUTLS_PURE__;
  60423 const gnutls_sign_algorithm_t *
  60455 	gnutls_sign_list(void) __GNUTLS_PURE__;
  60496 const char *
  60509 	gnutls_cipher_suite_info(size_t idx,
  60547 			         unsigned char *cs_id,
  60581 				 gnutls_kx_algorithm_t * kx,
  60614 				 gnutls_cipher_algorithm_t * cipher,
  60655 				 gnutls_mac_algorithm_t * mac,
  60690 				 gnutls_protocol_t * min_version);
  60730   /* functions for run-time enablement of algorithms */
  60786 int gnutls_ecc_curve_set_enabled(gnutls_ecc_curve_t curve,
  60845 				 unsigned int enabled);
  60873 int gnutls_sign_set_secure(gnutls_sign_algorithm_t sign, unsigned int secure);
  60952 int gnutls_sign_set_secure_for_certs(gnutls_sign_algorithm_t sign,
  61019 				     unsigned int secure);
  61050 int gnutls_digest_set_secure(gnutls_digest_algorithm_t dig,
  61110 			     unsigned int secure);
  61140 int gnutls_protocol_set_enabled(gnutls_protocol_t version,
  61199 				unsigned int enabled);
  61227   /* error functions */
  61251 int gnutls_error_is_fatal(int error) __GNUTLS_CONST__;
  61306 int gnutls_error_to_alert(int err, int *level);
  61355 void gnutls_perror(int error);
  61386 const char * gnutls_strerror(int error) __GNUTLS_CONST__;
  61444 const char * gnutls_strerror_name(int error) __GNUTLS_CONST__;
  61508 /* Semi-internal functions.
  61540 void gnutls_handshake_set_private_extensions(gnutls_session_t session,
  61611 					     int allow);
  61633 int gnutls_handshake_set_random(gnutls_session_t session,
  61691 				const gnutls_datum_t * random);
  61728 gnutls_handshake_description_t
  61759 gnutls_handshake_get_last_out(gnutls_session_t session);
  61816 gnutls_handshake_description_t
  61847 gnutls_handshake_get_last_in(gnutls_session_t session);
  61904 /* Record layer functions.
  61935 #define GNUTLS_HEARTBEAT_WAIT 1
  61967 int gnutls_heartbeat_ping(gnutls_session_t session, size_t data_size,
  62037 			  unsigned int max_tries, unsigned int flags);
  62087 int gnutls_heartbeat_pong(gnutls_session_t session, unsigned int flags);
  62161 void gnutls_record_set_timeout(gnutls_session_t session, unsigned int ms);
  62236 void gnutls_record_disable_padding(gnutls_session_t session);
  62299 void gnutls_record_cork(gnutls_session_t session);
  62350 #define GNUTLS_RECORD_WAIT 1
  62379 int gnutls_record_uncork(gnutls_session_t session, unsigned int flags);
  62451 size_t gnutls_record_discard_queued(gnutls_session_t session);
  62519 gnutls_record_get_state(gnutls_session_t session,
  62569 			unsigned read,
  62587 			gnutls_datum_t *mac_key,
  62615 			gnutls_datum_t *IV,
  62638 			gnutls_datum_t *cipher_key,
  62669 			unsigned char seq_number[8]);
  62707 gnutls_record_set_state(gnutls_session_t session,
  62757 			unsigned read,
  62775 			const unsigned char seq_number[8]);
  62815 typedef struct {
  62832 	size_t low;
  62845 	size_t high;
  62859 } gnutls_range_st;
  62879 int gnutls_range_split(gnutls_session_t session,
  62928 		       const gnutls_range_st * orig,
  62967 		       gnutls_range_st * small_range,
  63007 		       gnutls_range_st * rem_range);
  63047 ssize_t gnutls_record_send(gnutls_session_t session, const void *data,
  63118 			   size_t data_size);
  63143 ssize_t gnutls_record_send2(gnutls_session_t session, const void *data,
  63215 			    size_t data_size, size_t pad, unsigned flags);
  63269 ssize_t gnutls_record_send_range(gnutls_session_t session,
  63328 				 const void *data, size_t data_size,
  63369 				 const gnutls_range_st * range);
  63406 ssize_t gnutls_record_recv(gnutls_session_t session, void *data,
  63471 			   size_t data_size);
  63497 typedef struct mbuffer_st *gnutls_packet_t;
  63542 ssize_t
  63550 gnutls_record_recv_packet(gnutls_session_t session,
  63602 			  gnutls_packet_t *packet);
  63634 void gnutls_packet_get(gnutls_packet_t packet, gnutls_datum_t *data, unsigned char *sequence);
  63729 void gnutls_packet_deinit(gnutls_packet_t packet);
  63781 #define gnutls_read gnutls_record_recv
  63820 #define gnutls_write gnutls_record_send
  63860 ssize_t gnutls_record_recv_seq(gnutls_session_t session, void *data,
  63929 			       size_t data_size, unsigned char *seq);
  63979 size_t gnutls_record_overhead_size(gnutls_session_t session);
  64042 size_t
  64049 	gnutls_est_record_overhead_size(gnutls_protocol_t version,
  64109 				        gnutls_cipher_algorithm_t cipher,
  64155 				        gnutls_mac_algorithm_t mac,
  64195 				        gnutls_compression_method_t comp,
  64241 				        unsigned int flags) __GNUTLS_CONST__;
  64292 void gnutls_session_enable_compatibility_mode(gnutls_session_t session);
  64365 #define gnutls_record_set_max_empty_records(session, x)
  64422 unsigned gnutls_record_can_use_length_hiding(gnutls_session_t session);
  64495 int gnutls_record_get_direction(gnutls_session_t session);
  64555 size_t gnutls_record_get_max_size(gnutls_session_t session);
  64616 ssize_t gnutls_record_set_max_size(gnutls_session_t session, size_t size);
  64691 ssize_t gnutls_record_set_max_recv_size(gnutls_session_t session, size_t size);
  64772 size_t gnutls_record_check_pending(gnutls_session_t session);
  64834 size_t gnutls_record_check_corked(gnutls_session_t session);
  64896 size_t gnutls_record_get_max_early_data_size(gnutls_session_t session);
  64968 int gnutls_record_set_max_early_data_size(gnutls_session_t session, size_t size);
  65050 ssize_t gnutls_record_send_early_data(gnutls_session_t session,
  65114 				      const void *data,
  65142 				      size_t length);
  65168 ssize_t gnutls_record_recv_early_data(gnutls_session_t session,
  65232 				      void *data,
  65254 				      size_t data_size);
  65284 void gnutls_session_force_valid(gnutls_session_t session);
  65344 int gnutls_prf(gnutls_session_t session,
  65385 	       size_t label_size, const char *label,
  65431 	       int server_random_first,
  65464 	       size_t extra_size, const char *extra,
  65510 	       size_t outsize, char *out);
  65546 int gnutls_prf_rfc5705(gnutls_session_t session,
  65595 	       size_t label_size, const char *label,
  65641 	       size_t context_size, const char *context,
  65691 	       size_t outsize, char *out);
  65727 int gnutls_prf_early(gnutls_session_t session,
  65774 		     size_t label_size, const char *label,
  65819 		     size_t context_size, const char *context,
  65868 		     size_t outsize, char *out);
  65904 int gnutls_prf_raw(gnutls_session_t session,
  65949 		   size_t label_size, const char *label,
  65992 		   size_t seed_size, const char *seed,
  66033 		   size_t outsize, char *out);
  66071  * gnutls_server_name_type_t:
  66101  * @GNUTLS_NAME_DNS: Domain Name System name type.
  66155  * Enumeration of different server name types.
  66206 typedef enum {
  66221 	GNUTLS_NAME_DNS = 1
  66242 } gnutls_server_name_type_t;
  66272 int gnutls_server_name_set(gnutls_session_t session,
  66325 			   gnutls_server_name_type_t type,
  66363 			   const void *name, size_t name_length);
  66409 int gnutls_server_name_get(gnutls_session_t session,
  66462 			   void *data, size_t * data_length,
  66502 			   unsigned int *type, unsigned int indx);
  66549 unsigned int gnutls_heartbeat_get_timeout(gnutls_session_t session);
  66618 void gnutls_heartbeat_set_timeouts(gnutls_session_t session,
  66679 				   unsigned int retrans_timeout,
  66716 				   unsigned int total_timeout);
  66753 #define GNUTLS_HB_PEER_ALLOWED_TO_SEND (1)
  66796 #define GNUTLS_HB_PEER_NOT_ALLOWED_TO_SEND (1<<1)
  66847   /* Heartbeat */
  66865 void gnutls_heartbeat_enable(gnutls_session_t session, unsigned int type);
  66941 #define GNUTLS_HB_LOCAL_ALLOWED_TO_SEND (1<<2)
  66988 unsigned gnutls_heartbeat_allowed(gnutls_session_t session, unsigned int type);
  67069   /* Safe renegotiation */
  67096 unsigned gnutls_safe_renegotiation_status(gnutls_session_t session);
  67165 unsigned gnutls_session_ext_master_secret_status(gnutls_session_t session);
  67241 unsigned gnutls_session_etm_status(gnutls_session_t session);
  67308  * gnutls_session_flags_t:
  67335  * @GNUTLS_SFLAGS_SAFE_RENEGOTIATION: Safe renegotiation (RFC5746) was used
  67411  * @GNUTLS_SFLAGS_EXT_MASTER_SECRET: The extended master secret (RFC7627) extension was used
  67504  * @GNUTLS_SFLAGS_ETM: The encrypt then MAC (RFC7366) extension was used
  67577  * @GNUTLS_SFLAGS_RFC7919: The RFC7919 Diffie-Hellman parameters were negotiated
  67658  * @GNUTLS_SFLAGS_HB_LOCAL_SEND: The heartbeat negotiation allows the local side to send heartbeat messages
  67766  * @GNUTLS_SFLAGS_HB_PEER_SEND: The heartbeat negotiation allows the peer to send heartbeat messages
  67867  * @GNUTLS_SFLAGS_FALSE_START: False start was used in this client session.
  67943  * @GNUTLS_SFLAGS_SESSION_TICKET: A session ticket has been received by the server.
  68027  * @GNUTLS_SFLAGS_POST_HANDSHAKE_AUTH: Indicates client capability for post-handshake auth; set only on server side.
  68144  * @GNUTLS_SFLAGS_EARLY_START: The TLS1.3 server session returned early.
  68217  * @GNUTLS_SFLAGS_EARLY_DATA: The TLS1.3 early data has been received by the server.
  68302  * @GNUTLS_SFLAGS_CLI_REQUESTED_OCSP: Set when the client has requested OCSP staple during handshake.
  68404  * @GNUTLS_SFLAGS_SERV_REQUESTED_OCSP: Set when the server has requested OCSP staple during handshake.
  68510  * Enumeration of different session parameters.
  68562 typedef enum {
  68577 	GNUTLS_SFLAGS_SAFE_RENEGOTIATION = 1,
  68616 	GNUTLS_SFLAGS_EXT_MASTER_SECRET = 1<<1,
  68657 	GNUTLS_SFLAGS_ETM = 1<<2,
  68684 	GNUTLS_SFLAGS_HB_LOCAL_SEND = 1<<3,
  68721 	GNUTLS_SFLAGS_HB_PEER_SEND = 1<<4,
  68757 	GNUTLS_SFLAGS_FALSE_START = 1<<5,
  68792 	GNUTLS_SFLAGS_RFC7919 = 1<<6,
  68823 	GNUTLS_SFLAGS_SESSION_TICKET = 1<<7,
  68861 	GNUTLS_SFLAGS_POST_HANDSHAKE_AUTH = 1<<8,
  68904 	GNUTLS_SFLAGS_EARLY_START = 1<<9,
  68939 	GNUTLS_SFLAGS_EARLY_DATA = 1<<10,
  68974 	GNUTLS_SFLAGS_CLI_REQUESTED_OCSP = 1<<11,
  69017 	GNUTLS_SFLAGS_SERV_REQUESTED_OCSP = 1<<12
  69060 } gnutls_session_flags_t;
  69087 unsigned gnutls_session_get_flags(gnutls_session_t session);
  69153  * gnutls_supplemental_data_format_type_t:
  69196  * @GNUTLS_SUPPLEMENTAL_UNKNOWN: Unknown data format
  69252  * Enumeration of different supplemental data types (RFC 4680).
  69320 typedef enum {
  69335 	GNUTLS_SUPPLEMENTAL_UNKNOWN = 0,
  69369 } gnutls_supplemental_data_format_type_t;
  69412 const char
  69423 *gnutls_supplemental_get_name(gnutls_supplemental_data_format_type_t type);
  69500   /* SessionTicket, RFC 5077. */
  69533 int gnutls_session_ticket_key_generate(gnutls_datum_t * key);
  69595 int gnutls_session_ticket_enable_client(gnutls_session_t session);
  69662 int gnutls_session_ticket_enable_server(gnutls_session_t session,
  69728 					const gnutls_datum_t * key);
  69763 int gnutls_session_ticket_send(gnutls_session_t session, unsigned nr, unsigned flags);
  69851   /* SRTP, RFC 5764 */
  69879  * gnutls_srtp_profile_t:
  69905  * @GNUTLS_SRTP_AES128_CM_HMAC_SHA1_80: 128 bit AES with a 80 bit HMAC-SHA1
  69981  * @GNUTLS_SRTP_AES128_CM_HMAC_SHA1_32: 128 bit AES with a 32 bit HMAC-SHA1
  70057  * @GNUTLS_SRTP_NULL_HMAC_SHA1_80: NULL cipher with a 80 bit HMAC-SHA1
  70128  * @GNUTLS_SRTP_NULL_HMAC_SHA1_32: NULL cipher with a 32 bit HMAC-SHA1
  70202  * Enumeration of different SRTP protection profiles.
  70260 typedef enum {
  70275 	GNUTLS_SRTP_AES128_CM_HMAC_SHA1_80 = 0x0001,
  70321 	GNUTLS_SRTP_AES128_CM_HMAC_SHA1_32 = 0x0002,
  70367 	GNUTLS_SRTP_NULL_HMAC_SHA1_80 = 0x0005,
  70408 	GNUTLS_SRTP_NULL_HMAC_SHA1_32 = 0x0006
  70448 } gnutls_srtp_profile_t;
  70474 int gnutls_srtp_set_profile(gnutls_session_t session,
  70528 			    gnutls_srtp_profile_t profile);
  70567 int gnutls_srtp_set_profile_direct(gnutls_session_t session,
  70628 				   const char *profiles,
  70657 				   const char **err_pos);
  70687 int gnutls_srtp_get_selected_profile(gnutls_session_t session,
  70750 				     gnutls_srtp_profile_t * profile);
  70794 const char *gnutls_srtp_get_profile_name(gnutls_srtp_profile_t profile);
  70867 int gnutls_srtp_get_profile_id(const char *name,
  70916 			       gnutls_srtp_profile_t * profile);
  70960 int gnutls_srtp_get_keys(gnutls_session_t session,
  71011 			 void *key_material,
  71035 			 unsigned int key_material_size,
  71071 			 gnutls_datum_t * client_key,
  71104 			 gnutls_datum_t * client_salt,
  71138 			 gnutls_datum_t * server_key,
  71171 			 gnutls_datum_t * server_salt);
  71207 int gnutls_srtp_set_mki(gnutls_session_t session,
  71257 			const gnutls_datum_t * mki);
  71289 int gnutls_srtp_get_mki(gnutls_session_t session, gnutls_datum_t * mki);
  71363 /* ALPN TLS extension */
  71393  * gnutls_alpn_flags_t:
  71417  * @GNUTLS_ALPN_MANDATORY: Require ALPN negotiation. The connection will be
  71493  *   aborted if no matching ALPN protocol is found.
  71545  * @GNUTLS_ALPN_SERVER_PRECEDENCE: The choices set by the server
  71610  *   will take precedence over the client's.
  71658  * Enumeration of different ALPN flags. These are used by gnutls_alpn_set_protocols().
  71749 typedef enum {
  71764 	GNUTLS_ALPN_MANDATORY = 1,
  71792 	GNUTLS_ALPN_SERVER_PRECEDENCE = (1<<1)
  71832 } gnutls_alpn_flags_t;
  71856 #define GNUTLS_ALPN_MAND GNUTLS_ALPN_MANDATORY
  71903 int gnutls_alpn_get_selected_protocol(gnutls_session_t session,
  71967 				      gnutls_datum_t * protocol);
  72005 int gnutls_alpn_set_protocols(gnutls_session_t session,
  72061 			      const gnutls_datum_t * protocols,
  72104 			      unsigned protocols_size, unsigned flags);
  72156 int gnutls_key_generate(gnutls_datum_t * key, unsigned int key_size);
  72228 #define GNUTLS_PRIORITY_INIT_DEF_APPEND 1
  72270 int gnutls_priority_init(gnutls_priority_t * priority_cache,
  72331 			 const char *priorities, const char **err_pos);
  72382 int gnutls_priority_init2(gnutls_priority_t * priority_cache,
  72444 			  const char *priorities, const char **err_pos,
  72495 			  unsigned flags);
  72517 void gnutls_priority_deinit(gnutls_priority_t priority_cache);
  72580 int gnutls_priority_get_cipher_suite_index(gnutls_priority_t pcache,
  72649 					   unsigned int idx,
  72675 					   unsigned int *sidx);
  72705 #define GNUTLS_PRIORITY_LIST_INIT_KEYWORDS 1
  72750 #define GNUTLS_PRIORITY_LIST_SPECIAL 2
  72789 const char *
  72802 gnutls_priority_string_list(unsigned iter, unsigned int flags);
  72867 int gnutls_priority_set(gnutls_session_t session,
  72917 			gnutls_priority_t priority);
  72950 int gnutls_priority_set_direct(gnutls_session_t session,
  73007 			       const char *priorities,
  73041 			       const char **err_pos);
  73075 int gnutls_priority_certificate_type_list(gnutls_priority_t pcache,
  73143 					  const unsigned int **list);
  73178 int gnutls_priority_certificate_type_list2(gnutls_priority_t pcache,
  73247 					  const unsigned int **list,
  73281 					  gnutls_ctype_target_t target);
  73319 int gnutls_priority_sign_list(gnutls_priority_t pcache,
  73375 			      const unsigned int **list);
  73412 int gnutls_priority_protocol_list(gnutls_priority_t pcache,
  73472 				  const unsigned int **list);
  73506 int gnutls_priority_ecc_curve_list(gnutls_priority_t pcache,
  73567 				   const unsigned int **list);
  73606 gnutls_priority_group_list(gnutls_priority_t pcache,
  73659 			   const unsigned int **list);
  73694 int gnutls_priority_kx_list(gnutls_priority_t pcache,
  73748 			    const unsigned int **list);
  73783 int gnutls_priority_cipher_list(gnutls_priority_t pcache,
  73841 				const unsigned int **list);
  73873 int gnutls_priority_mac_list(gnutls_priority_t pcache,
  73928 			     const unsigned int **list);
  73965 const char *gnutls_get_system_config_file(void);
  74015 int gnutls_set_default_priority(gnutls_session_t session);
  74074 int gnutls_set_default_priority_append(gnutls_session_t session,
  74139 				       const char *add_prio,
  74172 				       const char **err_pos,
  74205 				       unsigned flags);
  74234 /* Returns the name of a cipher suite */
  74275 const char *
  74288 	gnutls_cipher_suite_get_name(gnutls_kx_algorithm_t kx_algorithm,
  74354 				     gnutls_cipher_algorithm_t cipher_algorithm,
  74407 				     gnutls_mac_algorithm_t mac_algorithm) __GNUTLS_CONST__;
  74473 /* get the currently used protocol version */
  74519 gnutls_protocol_t gnutls_protocol_get_version(gnutls_session_t session);
  74593 const char *
  74606 	gnutls_protocol_get_name(gnutls_protocol_t version) __GNUTLS_CONST__;
  74679 /* get/set session
  74702 int gnutls_session_set_data(gnutls_session_t session,
  74756 			    const void *session_data,
  74789 			    size_t session_data_size);
  74823 int gnutls_session_get_data(gnutls_session_t session, void *session_data,
  74897 			    size_t * session_data_size);
  74933 int gnutls_session_get_data2(gnutls_session_t session,
  74988 			     gnutls_datum_t * data);
  75020 void gnutls_session_get_random(gnutls_session_t session,
  75077 			       gnutls_datum_t * client,
  75112 			       gnutls_datum_t * server);
  75149 void gnutls_session_get_master_secret(gnutls_session_t session,
  75213 			              gnutls_datum_t * secret);
  75257 char *gnutls_session_get_desc(gnutls_session_t session);
  75315 typedef int gnutls_certificate_verify_function(gnutls_session_t);
  75381 void gnutls_session_set_verify_function(gnutls_session_t session, gnutls_certificate_verify_function * func);
  75496  * gnutls_vdata_types_t:
  75521  * @GNUTLS_DT_UNKNOWN: Unknown data type.
  75563  * @GNUTLS_DT_DNS_HOSTNAME: The data contain a null-terminated DNS hostname; the hostname will be 
  75662  *   matched using the RFC6125 rules. If the data contain a textual IP (v4 or v6) address it will
  75760  *   be marched against the IPAddress Alternative name, unless the verification flag %GNUTLS_VERIFY_DO_NOT_ALLOW_IP_MATCHES
  75884  *   is specified.
  75903  * @GNUTLS_DT_IP_ADDRESS: The data contain a raw IP address (4 or 16 bytes). If will be matched
  75999  *   against the IPAddress Alternative name; option available since 3.6.0.
  76074  * @GNUTLS_DT_RFC822NAME: The data contain a null-terminated email address; the email will be
  76168  *   matched against the RFC822Name Alternative name of the certificate, or the EMAIL DN component if the
  76274  *   former isn't available. Prior to matching the email address will be converted to ACE
  76364  *   (ASCII-compatible-encoding).
  76398  * @GNUTLS_DT_KEY_PURPOSE_OID: The data contain a null-terminated key purpose OID. It will be matched
  76500  *   against the certificate's Extended Key Usage extension.
  76564  * Enumeration of different typed-data options. They are used as input to certificate
  76650  * verification functions to provide information about the name and purpose of the
  76733  * certificate. Only a single option of a type can be provided to the relevant functions
  76822  * (i.e., options %GNUTLS_DT_DNS_HOSTNAME, %GNUTLS_DT_IP_ADDRESS and
  76891  * %GNUTLS_DT_RFC822NAME cannot be combined).
  76941 typedef enum {
  76956 	GNUTLS_DT_UNKNOWN = 0,
  76980 	GNUTLS_DT_DNS_HOSTNAME = 1,
  77009 	GNUTLS_DT_KEY_PURPOSE_OID = 2,
  77041 	GNUTLS_DT_RFC822NAME = 3,
  77068 	GNUTLS_DT_IP_ADDRESS = 4
  77094 } gnutls_vdata_types_t;
  77119 typedef struct {
  77136 	gnutls_vdata_types_t type;
  77164 	unsigned char *data;
  77186 	unsigned int size;
  77206 } gnutls_typed_vdata_st;
  77232 void gnutls_session_set_verify_cert(gnutls_session_t session,
  77294 			       const char *hostname, unsigned flags);
  77344 void
  77349 gnutls_session_set_verify_cert2(gnutls_session_t session,
  77407 				gnutls_typed_vdata_st * data,
  77441 				unsigned elements, unsigned flags);
  77482 unsigned int gnutls_session_get_verify_cert_status(gnutls_session_t);
  77553 int gnutls_session_set_premaster(gnutls_session_t session,
  77612 				 unsigned int entity,
  77638 				 gnutls_protocol_t version,
  77670 				 gnutls_kx_algorithm_t kx,
  77701 				 gnutls_cipher_algorithm_t cipher,
  77740 				 gnutls_mac_algorithm_t mac,
  77773 				 gnutls_compression_method_t comp,
  77812 				 const gnutls_datum_t * master,
  77848 				 const gnutls_datum_t * session_id);
  77890 /* returns the session ID */
  77919 #define GNUTLS_MAX_SESSION_ID 32
  77952 int gnutls_session_get_id(gnutls_session_t session, void *session_id,
  78022 			  size_t * session_id_size);
  78054 int gnutls_session_get_id2(gnutls_session_t session,
  78107 			   gnutls_datum_t * session_id);
  78144 int gnutls_session_set_id(gnutls_session_t session,
  78196 			  const gnutls_datum_t * sid);
  78231 int gnutls_session_channel_binding(gnutls_session_t session,
  78292 				   gnutls_channel_binding_t cbtype,
  78332 				   gnutls_datum_t * cb);
  78362 /* checks if this session is a resumed one
  78409 int gnutls_session_is_resumed(gnutls_session_t session);
  78466 int gnutls_session_resumption_requested(gnutls_session_t session);
  78534 typedef int (*gnutls_db_store_func) (void *, gnutls_datum_t key,
  78599 				     gnutls_datum_t data);
  78630 typedef int (*gnutls_db_remove_func) (void *, gnutls_datum_t key);
  78697 typedef gnutls_datum_t(*gnutls_db_retr_func) (void *, gnutls_datum_t key);
  78773 void gnutls_db_set_cache_expiration(gnutls_session_t session, int seconds);
  78849 unsigned gnutls_db_get_default_cache_expiration(void);
  78905 void gnutls_db_remove_session(gnutls_session_t session);
  78962 void gnutls_db_set_retrieve_function(gnutls_session_t session,
  79025 				     gnutls_db_retr_func retr_func);
  79066 void gnutls_db_set_remove_function(gnutls_session_t session,
  79127 				   gnutls_db_remove_func rem_func);
  79167 void gnutls_db_set_store_function(gnutls_session_t session,
  79227 				  gnutls_db_store_func store_func);
  79267 void gnutls_db_set_ptr(gnutls_session_t session, void *ptr);
  79328 void *gnutls_db_get_ptr(gnutls_session_t session);
  79379 int gnutls_db_check_entry(gnutls_session_t session,
  79431 			  gnutls_datum_t session_entry);
  79467 time_t gnutls_db_check_entry_time(gnutls_datum_t * entry);
  79526 time_t gnutls_db_check_entry_expire_time(gnutls_datum_t * entry);
  79593   /**
  79599    * gnutls_handshake_hook_func:
  79632    * @session: the current session
  79667    * @htype: the type of the handshake message (%gnutls_handshake_description_t)
  79748    * @when: non zero if this is a post-process/generation call and zero otherwise
  79830    * @incoming: non zero if this is an incoming message and zero if this is an outgoing message
  79926    * @msg: the (const) data of the handshake message without the handshake headers.
  80010    *
  80015    * Function prototype for handshake hooks. It is set using
  80076    * gnutls_handshake_set_hook_function().
  80119    *
  80124    * Returns: Non zero on error.
  80157    */
  80163 #define GNUTLS_HOOK_POST (1)
  80192 #define GNUTLS_HOOK_PRE (0)
  80220 #define GNUTLS_HOOK_BOTH (-1)
  80251 typedef int (*gnutls_handshake_hook_func) (gnutls_session_t,
  80312 					   unsigned int htype,
  80340 					   unsigned when,
  80363 					   unsigned int incoming,
  80394 					   const gnutls_datum_t *msg);
  80430 void gnutls_handshake_set_hook_function(gnutls_session_t session,
  80496 					unsigned int htype, int when,
  80531 					gnutls_handshake_hook_func func);
  80571 #define gnutls_handshake_post_client_hello_func gnutls_handshake_simple_hook_func
  80653 typedef int (*gnutls_handshake_simple_hook_func) (gnutls_session_t);
  80722 void
  80727 gnutls_handshake_set_post_client_hello_function(gnutls_session_t session,
  80801 						gnutls_handshake_simple_hook_func func);
  80849 void gnutls_handshake_set_max_packet_length(gnutls_session_t session,
  80919 					    size_t max);
  80942 /* returns libgnutls version (call it with a NULL argument)
  81006 const char * gnutls_check_version(const char *req_version) __GNUTLS_CONST__;
  81084 /* A macro which will allow optimizing out calls to gnutls_check_version()
  81159  * when the version being compiled with is sufficient.
  81214  * Used as:
  81226  *   if (gnutls_check_version_numerc(3,3,16)) {
  81278 #define gnutls_check_version_numeric(a,b,c) \
  81324 	((GNUTLS_VERSION_MAJOR >= (a)) &&  \
  81362 	 ((GNUTLS_VERSION_NUMBER >= ( ((a) << 16) + ((b) << 8) + (c) )) || \
  81432 	 gnutls_check_version(#a "." #b "." #c)))
  81476 /* Functions for setting/clearing credentials
  81526 void gnutls_credentials_clear(gnutls_session_t session);
  81584 /* cred is a structure defined by the kx algorithm
  81639 int gnutls_credentials_set(gnutls_session_t session,
  81692 			   gnutls_credentials_type_t type, void *cred);
  81743 int gnutls_credentials_get(gnutls_session_t session,
  81796 			   gnutls_credentials_type_t type, void **cred);
  81848 #define gnutls_cred_set	gnutls_credentials_set
  81896 /* x.509 types */
  81915 struct gnutls_pubkey_st;
  81940 typedef struct gnutls_pubkey_st *gnutls_pubkey_t;
  81991 struct gnutls_privkey_st;
  82017 typedef struct gnutls_privkey_st *gnutls_privkey_t;
  82070 struct gnutls_x509_privkey_int;
  82102 typedef struct gnutls_x509_privkey_int *gnutls_x509_privkey_t;
  82166 struct gnutls_x509_crl_int;
  82194 typedef struct gnutls_x509_crl_int *gnutls_x509_crl_t;
  82250 struct gnutls_x509_crt_int;
  82278 typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;
  82334 struct gnutls_x509_crq_int;
  82362 typedef struct gnutls_x509_crq_int *gnutls_x509_crq_t;
  82418 struct gnutls_openpgp_keyring_int;
  82453 typedef struct gnutls_openpgp_keyring_int *gnutls_openpgp_keyring_t;
  82524 /* Credential structures - used in gnutls_credentials_set(); */
  82589 struct gnutls_certificate_credentials_st;
  82631 typedef struct gnutls_certificate_credentials_st
  82680 *gnutls_certificate_credentials_t;
  82715 typedef gnutls_certificate_credentials_t
  82756     gnutls_certificate_server_credentials;
  82799 typedef gnutls_certificate_credentials_t
  82840     gnutls_certificate_client_credentials;
  82884 typedef struct gnutls_anon_server_credentials_st
  82933 *gnutls_anon_server_credentials_t;
  82968 typedef struct gnutls_anon_client_credentials_st
  83017 *gnutls_anon_client_credentials_t;
  83053 void gnutls_anon_free_server_credentials(gnutls_anon_server_credentials_t
  83127 					 sc);
  83142 gnutls_anon_allocate_server_credentials(gnutls_anon_server_credentials_t
  83215 					* sc);
  83228 void gnutls_anon_set_server_dh_params(gnutls_anon_server_credentials_t res,
  83304 				      gnutls_dh_params_t dh_params);
  83350 gnutls_anon_set_server_known_dh_params(gnutls_anon_server_credentials_t res,
  83427 					gnutls_sec_param_t sec_param);
  83464 void
  83469 gnutls_anon_set_server_params_function(gnutls_anon_server_credentials_t
  83541 				       res, gnutls_params_function * func);
  83590 void
  83595 gnutls_anon_free_client_credentials(gnutls_anon_client_credentials_t sc);
  83673 gnutls_anon_allocate_client_credentials(gnutls_anon_client_credentials_t
  83746 					* sc);
  83759 /* CERTFILE is an x509 certificate in PEM form.
  83807  * KEYFILE is a pkcs-1 private key in PEM form (for RSA keys).
  83874 void
  83879 gnutls_certificate_free_credentials(gnutls_certificate_credentials_t sc);
  83957 gnutls_certificate_allocate_credentials(gnutls_certificate_credentials_t
  84030 					* res);
  84048 gnutls_certificate_get_issuer(gnutls_certificate_credentials_t sc,
  84115 			      gnutls_x509_crt_t cert,
  84148 			      gnutls_x509_crt_t * issuer,
  84185 			      unsigned int flags);
  84216 int gnutls_certificate_get_crt_raw(gnutls_certificate_credentials_t sc,
  84288 				   unsigned idx1, unsigned idx2,
  84325 				   gnutls_datum_t * cert);
  84357 void gnutls_certificate_free_keys(gnutls_certificate_credentials_t sc);
  84429 void gnutls_certificate_free_cas(gnutls_certificate_credentials_t sc);
  84500 void gnutls_certificate_free_ca_names(gnutls_certificate_credentials_t sc);
  84576 void gnutls_certificate_free_crls(gnutls_certificate_credentials_t sc);
  84649 void gnutls_certificate_set_dh_params(gnutls_certificate_credentials_t res,
  84725 				      gnutls_dh_params_t dh_params);
  84767 int gnutls_certificate_set_known_dh_params(gnutls_certificate_credentials_t res,
  84848 					   gnutls_sec_param_t sec_param);
  84887 void gnutls_certificate_set_verify_flags(gnutls_certificate_credentials_t
  84961 					 res, unsigned int flags);
  84993 unsigned int
  85006 gnutls_certificate_get_verify_flags(gnutls_certificate_credentials_t res);
  85086  * gnutls_certificate_flags:
  85115  * @GNUTLS_CERTIFICATE_SKIP_KEY_CERT_MATCH: Skip the key and certificate matching check.
  85204  * @GNUTLS_CERTIFICATE_API_V2: If set the gnutls_certificate_set_*key* functions will return an index of the added key pair instead of zero.
  85345  * @GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK: If set, the gnutls_certificate_set_ocsp_status_request_file
  85454  *    function, will not check whether the response set matches any of the certificates.
  85543  * @GNUTLS_CERTIFICATE_VERIFY_CRLS: This will enable CRL verification when added in the certificate structure.
  85654  *    When used, it requires CAs to be added before CRLs.
  85715  * Enumeration of different certificate credentials flags.
  85778 typedef enum gnutls_certificate_flags {
  85818 	GNUTLS_CERTIFICATE_SKIP_KEY_CERT_MATCH = 1,
  85863 	GNUTLS_CERTIFICATE_API_V2 = (1<<1),
  85900 	GNUTLS_CERTIFICATE_SKIP_OCSP_RESPONSE_CHECK = (1<<2),
  85955 	GNUTLS_CERTIFICATE_VERIFY_CRLS = (1<<3)
  85996 } gnutls_certificate_flags;
  86025 void gnutls_certificate_set_flags(gnutls_certificate_credentials_t,
  86093 				  unsigned flags);
  86117 void gnutls_certificate_set_verify_limits(gnutls_certificate_credentials_t
  86192 					  res, unsigned int max_bits,
  86227 					  unsigned int max_depth);
  86264 gnutls_certificate_set_x509_system_trust(gnutls_certificate_credentials_t
  86338 					 cred);
  86356 gnutls_certificate_set_x509_trust_file(gnutls_certificate_credentials_t
  86428 				       cred, const char *cafile,
  86465 				       gnutls_x509_crt_fmt_t type);
  86509 gnutls_certificate_set_x509_trust_dir(gnutls_certificate_credentials_t cred,
  86586 				      const char *ca_dir,
  86616 				      gnutls_x509_crt_fmt_t type);
  86656 int gnutls_certificate_set_x509_trust_mem(gnutls_certificate_credentials_t
  86731 					  res, const gnutls_datum_t * ca,
  86770 					  gnutls_x509_crt_fmt_t type);
  86811 gnutls_certificate_set_x509_crl_file(gnutls_certificate_credentials_t
  86881 				     res, const char *crlfile,
  86916 				     gnutls_x509_crt_fmt_t type);
  86954 int gnutls_certificate_set_x509_crl_mem(gnutls_certificate_credentials_t
  87027 					res, const gnutls_datum_t * CRL,
  87065 					gnutls_x509_crt_fmt_t type);
  87104 gnutls_certificate_set_x509_key_file(gnutls_certificate_credentials_t
  87174 				     res, const char *certfile,
  87210 				     const char *keyfile,
  87240 				     gnutls_x509_crt_fmt_t type);
  87283 gnutls_certificate_set_x509_key_file2(gnutls_certificate_credentials_t
  87354 				      res, const char *certfile,
  87391 				      const char *keyfile,
  87422 				      gnutls_x509_crt_fmt_t type,
  87460 				      const char *pass,
  87488 				      unsigned int flags);
  87520 int gnutls_certificate_set_x509_key_mem(gnutls_certificate_credentials_t
  87593 					res, const gnutls_datum_t * cert,
  87632 					const gnutls_datum_t * key,
  87665 					gnutls_x509_crt_fmt_t type);
  87700 int gnutls_certificate_set_x509_key_mem2(gnutls_certificate_credentials_t
  87774 					 res, const gnutls_datum_t * cert,
  87814 					 const gnutls_datum_t * key,
  87848 					 gnutls_x509_crt_fmt_t type,
  87882 					 const char *pass,
  87906 					 unsigned int flags);
  87934 void gnutls_certificate_send_x509_rdn_sequence(gnutls_session_t session,
  88007 					       int status);
  88037 gnutls_certificate_set_x509_simple_pkcs12_file
  88084 (gnutls_certificate_credentials_t res, const char *pkcs12file,
  88147  gnutls_x509_crt_fmt_t type, const char *password);
  88203 gnutls_certificate_set_x509_simple_pkcs12_mem
  88249 (gnutls_certificate_credentials_t res, const gnutls_datum_t * p12blob,
  88320  gnutls_x509_crt_fmt_t type, const char *password);
  88373 /* New functions to allow setting already parsed X.509 stuff.
  88440 int gnutls_certificate_set_x509_key(gnutls_certificate_credentials_t res,
  88514 				    gnutls_x509_crt_t * cert_list,
  88553 				    int cert_list_size,
  88581 				    gnutls_x509_privkey_t key);
  88617 int gnutls_certificate_set_x509_trust(gnutls_certificate_credentials_t res,
  88693 				      gnutls_x509_crt_t * ca_list,
  88732 				      int ca_list_size);
  88761 int gnutls_certificate_set_x509_crl(gnutls_certificate_credentials_t res,
  88835 				    gnutls_x509_crl_t * crl_list,
  88873 				    int crl_list_size);
  88902 int gnutls_certificate_get_x509_key(gnutls_certificate_credentials_t res,
  88976                                     unsigned index,
  89028                                     gnutls_x509_privkey_t *key);
  89093 int gnutls_certificate_get_x509_crt(gnutls_certificate_credentials_t res,
  89167                                     unsigned index,
  89219                                     gnutls_x509_crt_t **crt_list,
  89285                                     unsigned *crt_list_size);
  89348   /* OCSP status request extension, RFC 6066 */
  89396 typedef int (*gnutls_status_request_ocsp_func)
  89443  (gnutls_session_t session, void *ptr, gnutls_datum_t *ocsp_response);
  89515 void
  89520 gnutls_certificate_set_ocsp_status_request_function
  89572 (gnutls_certificate_credentials_t res,
  89611 gnutls_status_request_ocsp_func ocsp_func, void *ptr);
  89671 gnutls_certificate_set_ocsp_status_request_function2
  89724 (gnutls_certificate_credentials_t res, unsigned idx,
  89777 gnutls_status_request_ocsp_func ocsp_func, void *ptr);
  89837 gnutls_certificate_set_ocsp_status_request_file
  89885 (gnutls_certificate_credentials_t res, const char *response_file,
  89951  unsigned idx);
  89972 gnutls_certificate_set_ocsp_status_request_file2
  90021 (gnutls_certificate_credentials_t res, const char *response_file,
  90087  unsigned idx, gnutls_x509_crt_fmt_t fmt);
  90135 gnutls_certificate_set_ocsp_status_request_mem
  90182 (gnutls_certificate_credentials_t res, const gnutls_datum_t *resp,
  90249  unsigned idx, gnutls_x509_crt_fmt_t fmt);
  90293 typedef struct gnutls_ocsp_data_st {
  90330 	unsigned int version; /* must be zero */
  90372 	gnutls_datum_t response;
  90398 	time_t exptime;
  90415 	unsigned char padding[32];
  90443 } gnutls_ocsp_data_st;
  90467 time_t
  90474 gnutls_certificate_get_ocsp_expiration(gnutls_certificate_credentials_t sc,
  90550 				       unsigned idx,
  90575 				       int oidx,
  90596 				       unsigned flags);
  90625 int gnutls_ocsp_status_request_enable_client(gnutls_session_t session,
  90696 					     gnutls_datum_t * responder_id,
  90737 					     size_t responder_id_size,
  90773 					     gnutls_datum_t *
  90800 					     request_extensions);
  90832 int gnutls_ocsp_status_request_get(gnutls_session_t session,
  90893 				   gnutls_datum_t * response);
  90929 #define GNUTLS_OCSP_SR_IS_AVAIL 1
  90963 unsigned gnutls_ocsp_status_request_is_checked(gnutls_session_t session,
  91036 					       unsigned int flags);
  91074 gnutls_ocsp_status_request_get2(gnutls_session_t session,
  91132 			        unsigned idx,
  91157 			        gnutls_datum_t * response);
  91197 /* RAW public key functions (RFC7250) */
  91238 int gnutls_certificate_set_rawpk_key_mem(gnutls_certificate_credentials_t cred,
  91318 				    const gnutls_datum_t* spki,
  91354 				    const gnutls_datum_t* pkey,
  91390 				    gnutls_x509_crt_fmt_t format,
  91428 				    const char* pass,
  91454 				    unsigned int key_usage,
  91486 				    const char **names,
  91514 				    unsigned int names_length,
  91549 				    unsigned int flags);
  91579 int gnutls_certificate_set_rawpk_key_file(gnutls_certificate_credentials_t cred,
  91660 				      const char* rawpkfile,
  91693 				      const char* privkeyfile,
  91728 				      gnutls_x509_crt_fmt_t format,
  91768 				      const char *pass,
  91796 				      unsigned int key_usage,
  91830 				      const char **names,
  91860 				      unsigned int names_length,
  91897 				      unsigned int privkey_flags,
  91935 				      unsigned int pkcs11_flags);
  91975 /* global state functions
  92005 int gnutls_global_init(void);
  92035 void gnutls_global_deinit(void);
  92069 const gnutls_library_config_st *gnutls_get_library_config(void);
  92135   /**
  92141    * gnutls_time_func:
  92164    * @t: where to store time.
  92194    *
  92199    * Function prototype for time()-like function.  Set with
  92259    * gnutls_global_set_time_function().
  92299    *
  92304    * Returns: Number of seconds since the epoch, or (time_t)-1 on errors.
  92378    */
  92384 typedef time_t(*gnutls_time_func) (time_t * t);
  92433 typedef int (*mutex_init_func) (void **mutex);
  92480 typedef int (*mutex_lock_func) (void **mutex);
  92527 typedef int (*mutex_unlock_func) (void **mutex);
  92576 typedef int (*mutex_deinit_func) (void **mutex);
  92626 void gnutls_global_set_mutex(mutex_init_func init,
  92677 			     mutex_deinit_func deinit,
  92711 			     mutex_lock_func lock,
  92741 			     mutex_unlock_func unlock);
  92777 typedef void *(*gnutls_alloc_function) (size_t);
  92826 typedef void *(*gnutls_calloc_function) (size_t, size_t);
  92884 typedef int (*gnutls_is_secure_function) (const void *);
  92941 typedef void (*gnutls_free_function) (void *);
  92988 typedef void *(*gnutls_realloc_function) (void *, size_t);
  93048 void gnutls_global_set_time_function(gnutls_time_func time_func);
  93115 /* For use in callbacks */
  93142 extern _SYM_EXPORT gnutls_alloc_function gnutls_malloc;
  93198 extern _SYM_EXPORT gnutls_realloc_function gnutls_realloc;
  93257 extern _SYM_EXPORT gnutls_calloc_function gnutls_calloc;
  93314 extern _SYM_EXPORT gnutls_free_function gnutls_free;
  93368 #ifdef GNUTLS_INTERNAL_BUILD
  93397 #define gnutls_free(a) gnutls_free((void *) (a)), a=NULL
  93454 #endif
  93462 extern _SYM_EXPORT char *(*gnutls_strdup) (const char *);
  93521 /* a variant of memset that doesn't get optimized out */
  93578 void gnutls_memset(void *data, int c, size_t size);
  93631 /* constant time memcmp */
  93658 int gnutls_memcmp(const void *s1, const void *s2, size_t n);
  93720 typedef void (*gnutls_log_func) (int, const char *);
  93773 typedef void (*gnutls_audit_log_func) (gnutls_session_t, const char *);
  93845 void gnutls_global_set_log_function(gnutls_log_func log_func);
  93908 void gnutls_global_set_audit_log_function(gnutls_audit_log_func log_func);
  93983 void gnutls_global_set_log_level(int level);
  94029   /**
  94035    * gnutls_keylog_func:
  94060    * @session: the current session
  94095    * @label: the keylog label
  94125    * @secret: the (const) data of the derived secret.
  94179    *
  94184    * Function prototype for keylog hooks. It is set using
  94242    * gnutls_session_set_keylog_function().
  94285    *
  94290    * Returns: Non zero on error.
  94323    * Since: 3.6.13
  94342    */
  94348 typedef int (*gnutls_keylog_func) (gnutls_session_t session,
  94409 				   const char *label,
  94435 				   const gnutls_datum_t *secret);
  94473 gnutls_keylog_func gnutls_session_get_keylog_function(const gnutls_session_t session);
  94560 void gnutls_session_set_keylog_function(gnutls_session_t session,
  94626 					gnutls_keylog_func func);
  94658 /* Diffie-Hellman parameter handling.
  94700 int gnutls_dh_params_init(gnutls_dh_params_t * dh_params);
  94759 void gnutls_dh_params_deinit(gnutls_dh_params_t dh_params);
  94819 int gnutls_dh_params_import_raw(gnutls_dh_params_t dh_params,
  94881 				const gnutls_datum_t * prime,
  94915 				const gnutls_datum_t * generator);
  94954 int gnutls_dh_params_import_dsa(gnutls_dh_params_t dh_params, gnutls_x509_privkey_t key);
  95044 int gnutls_dh_params_import_raw2(gnutls_dh_params_t dh_params,
  95107 				 const gnutls_datum_t * prime,
  95142 				 const gnutls_datum_t * generator,
  95181 				 unsigned key_bits);
  95206 int gnutls_dh_params_import_raw3(gnutls_dh_params_t dh_params,
  95269 				 const gnutls_datum_t * prime,
  95304 				 const gnutls_datum_t * q,
  95335 				 const gnutls_datum_t * generator);
  95375 int gnutls_dh_params_import_pkcs3(gnutls_dh_params_t params,
  95436 				  const gnutls_datum_t * pkcs3_params,
  95479 				  gnutls_x509_crt_fmt_t format);
  95516 int gnutls_dh_params_generate2(gnutls_dh_params_t params,
  95574 			       unsigned int bits);
  95604 int gnutls_dh_params_export_pkcs3(gnutls_dh_params_t params,
  95665 				  gnutls_x509_crt_fmt_t format,
  95701 				  unsigned char *params_data,
  95735 				  size_t * params_data_size);
  95769 int gnutls_dh_params_export2_pkcs3(gnutls_dh_params_t params,
  95831 				   gnutls_x509_crt_fmt_t format,
  95868 				   gnutls_datum_t * out);
  95898 int gnutls_dh_params_export_raw(gnutls_dh_params_t params,
  95957 				gnutls_datum_t * prime,
  95985 				gnutls_datum_t * generator,
  96017 				unsigned int *bits);
  96042 int gnutls_dh_params_cpy(gnutls_dh_params_t dst, gnutls_dh_params_t src);
  96119 /* Session stuff
  96140 #include <sys/uio.h>
  96161 typedef struct iovec giovec_t;
  96193 typedef ssize_t(*gnutls_pull_func) (gnutls_transport_ptr_t, void *,
  96261 				    size_t);
  96278 typedef ssize_t(*gnutls_push_func) (gnutls_transport_ptr_t, const void *,
  96352 				    size_t);
  96370 int gnutls_system_recv_timeout(gnutls_transport_ptr_t ptr, unsigned int ms);
  96447 typedef int (*gnutls_pull_timeout_func) (gnutls_transport_ptr_t,
  96512 					 unsigned int ms);
  96537 typedef ssize_t(*gnutls_vec_push_func) (gnutls_transport_ptr_t,
  96601 					const giovec_t * iov, int iovcnt);
  96642 typedef int (*gnutls_errno_func) (gnutls_transport_ptr_t);
  96702 #if 0
  96708  /* This will be defined as macro. */
  96746   void gnutls_transport_set_int (gnutls_session_t session, int r);
  96813 #endif
  96821 void gnutls_transport_set_int2(gnutls_session_t session, int r, int s);
  96893 #define gnutls_transport_set_int(s, i) gnutls_transport_set_int2(s, i, i)
  96968 void gnutls_transport_get_int2(gnutls_session_t session, int *r, int *s);
  97042 int gnutls_transport_get_int(gnutls_session_t session);
  97099 void gnutls_transport_set_ptr(gnutls_session_t session,
  97155 			      gnutls_transport_ptr_t ptr);
  97193 void gnutls_transport_set_ptr2(gnutls_session_t session,
  97250 			       gnutls_transport_ptr_t recv_ptr,
  97293 			       gnutls_transport_ptr_t send_ptr);
  97338 gnutls_transport_ptr_t gnutls_transport_get_ptr(gnutls_session_t session);
  97413 void gnutls_transport_get_ptr2(gnutls_session_t session,
  97470 			       gnutls_transport_ptr_t * recv_ptr,
  97515 			       gnutls_transport_ptr_t * send_ptr);
  97562 void gnutls_transport_set_vec_push_function(gnutls_session_t session,
  97632 					    gnutls_vec_push_func vec_func);
  97673 void gnutls_transport_set_push_function(gnutls_session_t session,
  97739 					gnutls_push_func push_func);
  97773 void gnutls_transport_set_pull_function(gnutls_session_t session,
  97839 					gnutls_pull_func pull_func);
  97874 void gnutls_transport_set_pull_timeout_function(gnutls_session_t session,
  97948 						gnutls_pull_timeout_func
  97979 						func);
  97993 void gnutls_transport_set_errno_function(gnutls_session_t session,
  98060 					 gnutls_errno_func errno_func);
  98098 void gnutls_transport_set_errno(gnutls_session_t session, int err);
  98167 /* session specific
  98191 void gnutls_session_set_ptr(gnutls_session_t session, void *ptr);
  98257 void *gnutls_session_get_ptr(gnutls_session_t session);
  98314 void gnutls_openpgp_send_cert(gnutls_session_t session,
  98370 			      gnutls_openpgp_crt_status_t status);
  98417 /* This function returns the hash of the given data.
  98474 int gnutls_fingerprint(gnutls_digest_algorithm_t algo,
  98529 		       const gnutls_datum_t * data, void *result,
  98581 		       size_t * result_size);
  98614   /**
  98620    * gnutls_random_art_t:
  98646    * @GNUTLS_RANDOM_ART_OPENSSH: OpenSSH-style random art.
  98705    *
  98710    * Enumeration of different random art types.
  98758    */
  98764 typedef enum gnutls_random_art {
  98797 	GNUTLS_RANDOM_ART_OPENSSH = 1
  98828 } gnutls_random_art_t;
  98852 int gnutls_random_art(gnutls_random_art_t type,
  98900 		      const char *key_type, unsigned int key_size,
  98953 		      void *fpr, size_t fpr_size, gnutls_datum_t * art);
  99013 /* IDNA */
  99024 #define GNUTLS_IDNA_FORCE_2008 (1<<1)
  99062 int gnutls_idna_map(const char * input, unsigned ilen, gnutls_datum_t *out, unsigned flags);
  99155 int gnutls_idna_reverse_map(const char *input, unsigned ilen, gnutls_datum_t *out, unsigned flags);
  99256 /* SRP
  99268 typedef struct gnutls_srp_server_credentials_st
  99316 *gnutls_srp_server_credentials_t;
  99350 typedef struct gnutls_srp_client_credentials_st
  99398 *gnutls_srp_client_credentials_t;
  99433 void
  99438 gnutls_srp_free_client_credentials(gnutls_srp_client_credentials_t sc);
  99514 gnutls_srp_allocate_client_credentials(gnutls_srp_client_credentials_t *
  99587 				       sc);
  99603 int gnutls_srp_set_client_credentials(gnutls_srp_client_credentials_t res,
  99678 				      const char *username,
  99710 				      const char *password);
  99744 void
  99749 gnutls_srp_free_server_credentials(gnutls_srp_server_credentials_t sc);
  99825 gnutls_srp_allocate_server_credentials(gnutls_srp_server_credentials_t *
  99898 				       sc);
  99914 int gnutls_srp_set_server_credentials_file(gnutls_srp_server_credentials_t
  99989 					   res, const char *password_file,
 100029 					   const char *password_conf_file);
 100071 const char *gnutls_srp_server_get_username(gnutls_session_t session);
 100142 void gnutls_srp_set_prime_bits(gnutls_session_t session,
 100199                                unsigned int bits);
 100251 int gnutls_srp_verifier(const char *username,
 100297 			const char *password,
 100322 			const gnutls_datum_t * salt,
 100354 			const gnutls_datum_t * generator,
 100391 			const gnutls_datum_t * prime,
 100424 			gnutls_datum_t * res);
 100451 /* The static parameters defined in draft-ietf-tls-srp-05
 100509  * Those should be used as input to gnutls_srp_verifier().
 100572 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_8192_group_prime;
 100641 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_8192_group_generator;
 100715 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_4096_group_prime;
 100784 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_4096_group_generator;
 100858 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_3072_group_prime;
 100927 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_3072_group_generator;
 101001 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_2048_group_prime;
 101070 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_2048_group_generator;
 101144 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_1536_group_prime;
 101213 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_1536_group_generator;
 101287 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_1024_group_prime;
 101356 extern _SYM_EXPORT const gnutls_datum_t gnutls_srp_1024_group_generator;
 101430 /* The static parameters defined in rfc7919
 101479 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_8192_group_prime;
 101550 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_8192_group_q;
 101617 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_8192_group_generator;
 101692 extern _SYM_EXPORT const unsigned int gnutls_ffdhe_8192_key_bits;
 101759 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_6144_group_prime;
 101830 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_6144_group_q;
 101897 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_6144_group_generator;
 101972 extern _SYM_EXPORT const unsigned int gnutls_ffdhe_6144_key_bits;
 102039 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_4096_group_prime;
 102110 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_4096_group_q;
 102177 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_4096_group_generator;
 102252 extern _SYM_EXPORT const unsigned int gnutls_ffdhe_4096_key_bits;
 102319 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_3072_group_prime;
 102390 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_3072_group_q;
 102457 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_3072_group_generator;
 102532 extern _SYM_EXPORT const unsigned int gnutls_ffdhe_3072_key_bits;
 102599 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_2048_group_prime;
 102670 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_2048_group_q;
 102737 extern _SYM_EXPORT const gnutls_datum_t gnutls_ffdhe_2048_group_generator;
 102812 extern _SYM_EXPORT const unsigned int gnutls_ffdhe_2048_key_bits;
 102879 typedef int gnutls_srp_server_credentials_function(gnutls_session_t,
 102948 						   const char *username,
 102979 						   gnutls_datum_t * salt,
 103011 						   gnutls_datum_t *
 103037 						   verifier,
 103056 						   gnutls_datum_t *
 103082 						   generator,
 103102 						   gnutls_datum_t * prime);
 103136 void
 103141 gnutls_srp_set_server_credentials_function(gnutls_srp_server_credentials_t
 103216 					   cred,
 103230 					   gnutls_srp_server_credentials_function
 103277 					   * func);
 103295 typedef int gnutls_srp_client_credentials_function(gnutls_session_t,
 103364 						   char **, char **);
 103392 void
 103397 gnutls_srp_set_client_credentials_function(gnutls_srp_client_credentials_t
 103472 					   cred,
 103486 					   gnutls_srp_client_credentials_function
 103533 					   * func);
 103551 int gnutls_srp_base64_encode(const gnutls_datum_t * data, char *result,
 103623 			     size_t * result_size);
 103654 int gnutls_srp_base64_encode2(const gnutls_datum_t * data,
 103713 				   gnutls_datum_t * result);
 103747 int gnutls_srp_base64_decode(const gnutls_datum_t * b64_data, char *result,
 103823 			     size_t * result_size);
 103854 int gnutls_srp_base64_decode2(const gnutls_datum_t * b64_data,
 103917 				   gnutls_datum_t * result);
 103951 #define gnutls_srp_base64_encode_alloc gnutls_srp_base64_encode2
 104016 #define gnutls_srp_base64_decode_alloc gnutls_srp_base64_decode2
 104082 void
 104087 gnutls_srp_set_server_fake_salt_seed(gnutls_srp_server_credentials_t
 104156 				     sc,
 104169 				     const gnutls_datum_t * seed,
 104207 				     unsigned int salt_length);
 104244 /* PSK stuff */
 104260 typedef struct gnutls_psk_server_credentials_st
 104308 *gnutls_psk_server_credentials_t;
 104342 typedef struct gnutls_psk_client_credentials_st
 104390 *gnutls_psk_client_credentials_t;
 104429  * gnutls_psk_key_flags:
 104454  * @GNUTLS_PSK_KEY_RAW: PSK-key in raw format.
 104501  * @GNUTLS_PSK_KEY_HEX: PSK-key in hex format.
 104551  * Enumeration of different PSK key flags.
 104598 typedef enum gnutls_psk_key_flags {
 104634 	GNUTLS_PSK_KEY_RAW = 0,
 104659 	GNUTLS_PSK_KEY_HEX
 104679 } gnutls_psk_key_flags;
 104704 void
 104709 gnutls_psk_free_client_credentials(gnutls_psk_client_credentials_t sc);
 104785 gnutls_psk_allocate_client_credentials(gnutls_psk_client_credentials_t *
 104858 				       sc);
 104874 int gnutls_psk_set_client_credentials(gnutls_psk_client_credentials_t res,
 104949 				      const char *username,
 104981 				      const gnutls_datum_t * key,
 105019 				      gnutls_psk_key_flags flags);
 105058 int gnutls_psk_set_client_credentials2(gnutls_psk_client_credentials_t res,
 105134 				       const gnutls_datum_t *username,
 105177 				       const gnutls_datum_t *key,
 105215 				       gnutls_psk_key_flags flags);
 105256 void
 105261 gnutls_psk_free_server_credentials(gnutls_psk_server_credentials_t sc);
 105337 gnutls_psk_allocate_server_credentials(gnutls_psk_server_credentials_t *
 105410 				       sc);
 105426 int gnutls_psk_set_server_credentials_file(gnutls_psk_server_credentials_t
 105501 					   res, const char *password_file);
 105547 gnutls_psk_set_server_credentials_hint(gnutls_psk_server_credentials_t
 105618 				       res, const char *hint);
 105654 const char *gnutls_psk_server_get_username(gnutls_session_t session);
 105724 int gnutls_psk_server_get_username2(gnutls_session_t session,
 105786 				    gnutls_datum_t *out);
 105816 const char *gnutls_psk_client_get_hint(gnutls_session_t session);
 105883 typedef int gnutls_psk_server_credentials_function(gnutls_session_t,
 105952 						   const char *username,
 105983 						   gnutls_datum_t * key);
 106015 typedef int gnutls_psk_server_credentials_function2(gnutls_session_t,
 106085 						    const gnutls_datum_t *username,
 106127 						    gnutls_datum_t *key);
 106159 void
 106164 gnutls_psk_set_server_credentials_function(gnutls_psk_server_credentials_t
 106239 					   cred,
 106253 					   gnutls_psk_server_credentials_function
 106300 					   * func);
 106317 void
 106322 gnutls_psk_set_server_credentials_function2(gnutls_psk_server_credentials_t cred,
 106404 					    gnutls_psk_server_credentials_function2 *func);
 106462 typedef int gnutls_psk_client_credentials_function(gnutls_session_t,
 106531 						   char **username,
 106557 						   gnutls_datum_t * key);
 106589 typedef int gnutls_psk_client_credentials_function2(gnutls_session_t,
 106659 						    gnutls_datum_t *username,
 106695 						    gnutls_datum_t *key);
 106727 void
 106732 gnutls_psk_set_client_credentials_function(gnutls_psk_client_credentials_t
 106807 					   cred,
 106821 					   gnutls_psk_client_credentials_function
 106868 					   * func);
 106885 void
 106890 gnutls_psk_set_client_credentials_function2(gnutls_psk_client_credentials_t cred,
 106972 					    gnutls_psk_client_credentials_function2 *func);
 107030 int gnutls_hex_encode(const gnutls_datum_t * data, char *result,
 107095 		      size_t * result_size);
 107126 int gnutls_hex_decode(const gnutls_datum_t * hex_data, void *result,
 107195 		      size_t * result_size);
 107227 int gnutls_hex_encode2(const gnutls_datum_t * data, gnutls_datum_t *result);
 107304 int gnutls_hex_decode2(const gnutls_datum_t * data, gnutls_datum_t *result);
 107382 void
 107387 gnutls_psk_set_server_dh_params(gnutls_psk_server_credentials_t res,
 107456 				gnutls_dh_params_t dh_params);
 107496 gnutls_psk_set_server_known_dh_params(gnutls_psk_server_credentials_t res,
 107571 				      gnutls_sec_param_t sec_param);
 107613 void
 107618 gnutls_psk_set_server_params_function(gnutls_psk_server_credentials_t
 107688 				      res, gnutls_params_function * func);
 107740  * gnutls_x509_subject_alt_name_t:
 107775  * @GNUTLS_SAN_DNSNAME: DNS-name SAN.
 107813  * @GNUTLS_SAN_RFC822NAME: E-mail address SAN.
 107860  * @GNUTLS_SAN_URI: URI SAN.
 107889  * @GNUTLS_SAN_IPADDRESS: IP address SAN.
 107931  * @GNUTLS_SAN_OTHERNAME: OtherName SAN.
 107972  * @GNUTLS_SAN_DN: DN SAN.
 107999  * @GNUTLS_SAN_REGISTERED_ID: RegisteredID.
 108043  * @GNUTLS_SAN_OTHERNAME_XMPP: Virtual SAN, used by certain functions for convenience.
 108130  * @GNUTLS_SAN_OTHERNAME_KRB5PRINCIPAL: Virtual SAN, used by certain functions for convenience.
 108226  * @GNUTLS_SAN_OTHERNAME_MSUSERPRINCIPAL: Virtual SAN, used by certain functions for convenience.
 108324  * @GNUTLS_SAN_OTHERNAME_SRV: Virtual SAN, used by certain functions for convenience.
 108413  * Enumeration of different subject alternative names types.
 108478 typedef enum gnutls_x509_subject_alt_name_t {
 108524 	GNUTLS_SAN_DNSNAME = 1,
 108549 	GNUTLS_SAN_RFC822NAME = 2,
 108577 	GNUTLS_SAN_URI = 3,
 108598 	GNUTLS_SAN_IPADDRESS = 4,
 108625 	GNUTLS_SAN_OTHERNAME = 5,
 108652 	GNUTLS_SAN_DN = 6,
 108672 	GNUTLS_SAN_REGISTERED_ID = 7,
 108703 	GNUTLS_SAN_MAX = GNUTLS_SAN_REGISTERED_ID,
 108747 	/* The following are "virtual" subject alternative name types, in
 108814 	   that they are represented by an otherName value and an OID.
 108878 	   Used by gnutls_x509_crt_get_subject_alt_othername_oid.  */
 108941 	GNUTLS_SAN_OTHERNAME_XMPP = 1000,
 108976 	GNUTLS_SAN_OTHERNAME_KRB5PRINCIPAL,
 109013 	GNUTLS_SAN_OTHERNAME_MSUSERPRINCIPAL,
 109052 	GNUTLS_SAN_OTHERNAME_SRV
 109078 } gnutls_x509_subject_alt_name_t;
 109113 struct gnutls_openpgp_crt_int;
 109144 typedef struct gnutls_openpgp_crt_int *gnutls_openpgp_crt_t;
 109206 struct gnutls_openpgp_privkey_int;
 109241 typedef struct gnutls_openpgp_privkey_int *gnutls_openpgp_privkey_t;
 109311 struct gnutls_pkcs11_privkey_st;
 109344 typedef struct gnutls_pkcs11_privkey_st *gnutls_pkcs11_privkey_t;
 109415  * gnutls_privkey_type_t:
 109441  * @GNUTLS_PRIVKEY_X509: X.509 private key, #gnutls_x509_privkey_t.
 109509  * @GNUTLS_PRIVKEY_OPENPGP: OpenPGP private key, #gnutls_openpgp_privkey_t.
 109585  * @GNUTLS_PRIVKEY_PKCS11: PKCS11 private key, #gnutls_pkcs11_privkey_t.
 109658  * @GNUTLS_PRIVKEY_EXT: External private key, operating using callbacks.
 109734  * Enumeration of different private key types.
 109785 typedef enum {
 109800 	GNUTLS_PRIVKEY_X509,
 109822 	GNUTLS_PRIVKEY_OPENPGP,
 109847 	GNUTLS_PRIVKEY_PKCS11,
 109871 	GNUTLS_PRIVKEY_EXT
 109891 } gnutls_privkey_type_t;
 109917 typedef struct gnutls_retr2_st {
 109950 	gnutls_certificate_type_t cert_type;
 109988 	gnutls_privkey_type_t key_type;
 110022 	union {
 110031 		gnutls_x509_crt_t *x509;
 110058 		gnutls_openpgp_crt_t pgp;
 110086 	} cert;
 110095 	unsigned int ncerts;	/* one for pgp keys */
 110141 	union {
 110150 		gnutls_x509_privkey_t x509;
 110180 		gnutls_openpgp_privkey_t pgp;
 110212 		gnutls_pkcs11_privkey_t pkcs11;
 110246 	} key;
 110255 	unsigned int deinit_all;	/* if non zero all keys will be deinited */
 110325 } gnutls_retr2_st;
 110346   /* Functions that allow auth_info_t structures handling
 110404    */
 110411 gnutls_credentials_type_t gnutls_auth_get_type(gnutls_session_t session);
 110485 gnutls_credentials_type_t
 110511 gnutls_auth_server_get_type(gnutls_session_t session);
 110566 gnutls_credentials_type_t
 110592 gnutls_auth_client_get_type(gnutls_session_t session);
 110648   /* DH */
 110660 void gnutls_dh_set_prime_bits(gnutls_session_t session, unsigned int bits);
 110736 int gnutls_dh_get_secret_bits(gnutls_session_t session);
 110793 int gnutls_dh_get_peers_public_bits(gnutls_session_t session);
 110856 int gnutls_dh_get_prime_bits(gnutls_session_t session);
 110913 int gnutls_dh_get_group(gnutls_session_t session, gnutls_datum_t * raw_gen,
 110989 			gnutls_datum_t * raw_prime);
 111021 int gnutls_dh_get_pubkey(gnutls_session_t session,
 111072 			 gnutls_datum_t * raw_key);
 111104   /* X509PKI */
 111122   /* These are set on the credentials structure.
 111171    */
 111178   /* use gnutls_certificate_set_retrieve_function2() in abstract.h
 111245    * instead. It's much more efficient.
 111285    */
 111292 typedef int gnutls_certificate_retrieve_function(gnutls_session_t,
 111359 						 const
 111372 						 gnutls_datum_t *
 111396 						 req_ca_rdn,
 111415 						 int nreqs,
 111433 						 const
 111446 						 gnutls_pk_algorithm_t
 111475 						 * pk_algos,
 111494 						 int
 111505 						 pk_algos_length,
 111529 						 gnutls_retr2_st *);
 111558 void
 111563 gnutls_certificate_set_retrieve_function(gnutls_certificate_credentials_t
 111637 					 cred,
 111649 					 gnutls_certificate_retrieve_function
 111692 					 * func);
 111708 void
 111713 gnutls_certificate_set_verify_function(gnutls_certificate_credentials_t
 111785 				       cred,
 111802 				       gnutls_certificate_verify_function
 111848 				       * func);
 111869 void
 111874 gnutls_certificate_server_set_request(gnutls_session_t session,
 111938 				      gnutls_certificate_request_t req);
 111984   /* get data from the session
 112015    */
 112021 const gnutls_datum_t *gnutls_certificate_get_peers(gnutls_session_t
 112089 						   session, unsigned int
 112120 						   *list_size);
 112142 const gnutls_datum_t *gnutls_certificate_get_ours(gnutls_session_t
 112209 						  session);
 112228 int gnutls_certificate_get_peers_subkey_id(gnutls_session_t session,
 112297 					   gnutls_datum_t * id);
 112328 time_t gnutls_certificate_activation_time_peers(gnutls_session_t session);
 112403 time_t gnutls_certificate_expiration_time_peers(gnutls_session_t session);
 112479 unsigned gnutls_certificate_client_get_request_status(gnutls_session_t session);
 112560 int gnutls_certificate_verify_peers2(gnutls_session_t session,
 112623 				     unsigned int *status);
 112655 int gnutls_certificate_verify_peers3(gnutls_session_t session,
 112718 				     const char *hostname,
 112749 				     unsigned int *status);
 112786 gnutls_certificate_verify_peers(gnutls_session_t session,
 112844 				gnutls_typed_vdata_st * data,
 112878 				unsigned int elements,
 112905 				unsigned int *status);
 112933 int gnutls_certificate_verification_status_print(unsigned int status,
 113003 						 gnutls_certificate_type_t
 113036 						 type,
 113049 						 gnutls_datum_t * out,
 113078 						 unsigned int flags);
 113107 int gnutls_pem_base64_encode(const char *msg, const gnutls_datum_t * data,
 113182 			     char *result, size_t * result_size);
 113227 int gnutls_pem_base64_decode(const char *header,
 113276 			     const gnutls_datum_t * b64_data,
 113317 			     unsigned char *result, size_t * result_size);
 113372 int gnutls_pem_base64_encode2(const char *msg,
 113419 				   const gnutls_datum_t * data,
 113455 				   gnutls_datum_t * result);
 113488 int gnutls_pem_base64_decode2(const char *header,
 113538 				   const gnutls_datum_t * b64_data,
 113578 				   gnutls_datum_t * result);
 113612 int gnutls_base64_encode2(const gnutls_datum_t * data,
 113667 			  gnutls_datum_t * result);
 113698 int gnutls_base64_decode2(const gnutls_datum_t * b64_data,
 113757 			  gnutls_datum_t * result);
 113789 #define gnutls_pem_base64_encode_alloc gnutls_pem_base64_encode2
 113854 #define gnutls_pem_base64_decode_alloc gnutls_pem_base64_decode2
 113920   /* key_usage will be an OR of the following values:
 113974    */
 113981   /* when the key is to be used for signing: */
 114029 #define GNUTLS_KEY_DIGITAL_SIGNATURE	128
 114070 #define GNUTLS_KEY_NON_REPUDIATION	64
 114108   /* when the key is to be used for encryption: */
 114159 #define GNUTLS_KEY_KEY_ENCIPHERMENT	32
 114198 #define GNUTLS_KEY_DATA_ENCIPHERMENT	16
 114238 #define GNUTLS_KEY_KEY_AGREEMENT	8
 114273 #define GNUTLS_KEY_KEY_CERT_SIGN	4
 114308 #define GNUTLS_KEY_CRL_SIGN		2
 114339 #define GNUTLS_KEY_ENCIPHER_ONLY	1
 114374 #define GNUTLS_KEY_DECIPHER_ONLY	32768
 114414 void
 114419 gnutls_certificate_set_params_function(gnutls_certificate_credentials_t
 114491 				       res, gnutls_params_function * func);
 114539 void gnutls_anon_set_params_function(gnutls_anon_server_credentials_t res,
 114614 				     gnutls_params_function * func);
 114655 void gnutls_psk_set_params_function(gnutls_psk_server_credentials_t res,
 114728 				    gnutls_params_function * func);
 114769 int gnutls_hex2bin(const char *hex_data, size_t hex_size,
 114827 		   void *bin_data, size_t * bin_size);
 114869   /* Trust on first use (or ssh like) functions */
 114921   /* stores the provided information to a database
 114972    */
 114978 typedef int (*gnutls_tdb_store_func) (const char *db_name,
 115037 				      const char *host,
 115065 				      const char *service,
 115096 				      time_t expiration,
 115125 				      const gnutls_datum_t * pubkey);
 115168 typedef int (*gnutls_tdb_store_commitment_func) (const char *db_name,
 115238 						 const char *host,
 115263 						 const char *service,
 115291 						 time_t expiration,
 115317 						 gnutls_digest_algorithm_t
 115350 						 hash_algo,
 115368 						 const gnutls_datum_t *
 115398 						 hash);
 115413   /* searches for the provided host/service pair that match the
 115477    * provided public key in the database. */
 115522 typedef int (*gnutls_tdb_verify_func) (const char *db_name,
 115582 				       const char *host,
 115611 				       const char *service,
 115643 				       const gnutls_datum_t * pubkey);
 115688 struct gnutls_tdb_int;
 115711 typedef struct gnutls_tdb_int *gnutls_tdb_t;
 115757 int gnutls_tdb_init(gnutls_tdb_t * tdb);
 115798 void gnutls_tdb_set_store_func(gnutls_tdb_t tdb,
 115847 			       gnutls_tdb_store_func store);
 115887 void gnutls_tdb_set_store_commitment_func(gnutls_tdb_t tdb,
 115947 					  gnutls_tdb_store_commitment_func
 115987 					  cstore);
 116003 void gnutls_tdb_set_verify_func(gnutls_tdb_t tdb,
 116053 				gnutls_tdb_verify_func verify);
 116089 void gnutls_tdb_deinit(gnutls_tdb_t tdb);
 116132 int gnutls_verify_stored_pubkey(const char *db_name,
 116185 				gnutls_tdb_t tdb,
 116207 				const char *host,
 116229 				const char *service,
 116254 				gnutls_certificate_type_t cert_type,
 116295 				const gnutls_datum_t * cert,
 116328 				unsigned int flags);
 116354 #define GNUTLS_SCOMMIT_FLAG_ALLOW_BROKEN 1
 116397 int gnutls_store_commitment(const char *db_name,
 116446 			    gnutls_tdb_t tdb,
 116471 			    const char *host,
 116496 			    const char *service,
 116524 			    gnutls_digest_algorithm_t hash_algo,
 116568 			    const gnutls_datum_t * hash,
 116604 			    time_t expiration, unsigned int flags);
 116652 int gnutls_store_pubkey(const char *db_name,
 116697 			gnutls_tdb_t tdb,
 116718 			const char *host,
 116739 			const char *service,
 116763 			gnutls_certificate_type_t cert_type,
 116803 			const gnutls_datum_t * cert,
 116835 			time_t expiration, unsigned int flags);
 116879   /* Other helper functions */
 116910 int gnutls_load_file(const char *filename, gnutls_datum_t * data);
 116978 unsigned gnutls_url_is_supported(const char *url);
 117030   /* PIN callback */
 117056  * gnutls_pin_flag_t:
 117078  * @GNUTLS_PIN_USER: The PIN for the user.
 117121  * @GNUTLS_PIN_SO: The PIN for the security officer (admin).
 117182  * @GNUTLS_PIN_CONTEXT_SPECIFIC: The PIN is for a specific action and key like signing.
 117270  * @GNUTLS_PIN_FINAL_TRY: This is the final try before blocking.
 117335  * @GNUTLS_PIN_COUNT_LOW: Few tries remain before token blocks.
 117399  * @GNUTLS_PIN_WRONG: Last given PIN was not correct.
 117456  * Enumeration of different flags that are input to the PIN function.
 117530 typedef enum {
 117545 	GNUTLS_PIN_USER = (1 << 0),
 117574 	GNUTLS_PIN_SO = (1 << 1),
 117601 	GNUTLS_PIN_FINAL_TRY = (1 << 2),
 117635 	GNUTLS_PIN_COUNT_LOW = (1 << 3),
 117669 	GNUTLS_PIN_CONTEXT_SPECIFIC = (1 << 4),
 117710 	GNUTLS_PIN_WRONG = (1 << 5)
 117739 } gnutls_pin_flag_t;
 117761 #define GNUTLS_PKCS11_PIN_USER GNUTLS_PIN_USER
 117808 #define GNUTLS_PKCS11_PIN_SO GNUTLS_PIN_SO
 117851 #define GNUTLS_PKCS11_PIN_FINAL_TRY GNUTLS_PIN_FINAL_TRY
 117908 #define GNUTLS_PKCS11_PIN_COUNT_LOW  GNUTLS_PIN_COUNT_LOW
 117966 #define GNUTLS_PKCS11_PIN_CONTEXT_SPECIFIC GNUTLS_PIN_CONTEXT_SPECIFIC
 118037 #define GNUTLS_PKCS11_PIN_WRONG GNUTLS_PIN_WRONG
 118091  * gnutls_pin_callback_t:
 118117  * @userdata: user-controlled data from gnutls_pkcs11_set_pin_function().
 118191  * @attempt: pin-attempt counter, initially 0.
 118238  * @token_url: URL of token.
 118267  * @token_label: label of token.
 118300  * @flags: a #gnutls_pin_flag_t flag.
 118338  * @pin: buffer to hold PIN, of size @pin_max.
 118385  * @pin_max: size of @pin buffer.
 118422  * Callback function type for PKCS#11 or TPM PIN entry.  It is set by
 118492  * functions like gnutls_pkcs11_set_pin_function().
 118547  * The callback should provides the PIN code to unlock the token with
 118617  * label @token_label, specified by the URL @token_url.
 118676  * The PIN code, as a NUL-terminated ASCII string, should be copied
 118744  * into the @pin buffer (of maximum size @pin_max), and return 0 to
 118812  * indicate success.  Alternatively, the callback may return a
 118875  * negative gnutls error code to indicate failure and cancel PIN entry
 118946  * (in which case, the contents of the @pin parameter are ignored).
 119017  * When a PIN is required, the callback will be invoked repeatedly
 119084  * (and indefinitely) until either the returned PIN code is correct,
 119153  * the callback returns failure, or the token refuses login (e.g. when
 119224  * the token is locked due to too many incorrect PINs!).  For the
 119290  * first such invocation, the @attempt counter will have value zero;
 119359  * it will increase by one for each subsequent attempt.
 119418  * Returns: %GNUTLS_E_SUCCESS (0) on success or a negative error code on error.
 119501  * Since: 2.12.0
 119518  **/
 119523 typedef int (*gnutls_pin_callback_t) (void *userdata, int attempt,
 119590 				      const char *token_url,
 119623 				      const char *token_label,
 119658 				      unsigned int flags,
 119688 				      char *pin, size_t pin_max);
 119727 void gnutls_certificate_set_pin_function(gnutls_certificate_credentials_t,
 119802 					 gnutls_pin_callback_t fn,
 119834 					 void *userdata);
 119858 /* Public string related functions */
 119896 typedef struct gnutls_buffer_st *gnutls_buffer_t;
 119947 int gnutls_buffer_append_data(gnutls_buffer_t, const void *data, size_t data_size);
 120032 #define GNUTLS_UTF8_IGNORE_ERRS 1
 120066 int gnutls_utf8_password_normalize(const unsigned char *password, unsigned password_len,
 120155 				   gnutls_datum_t *out, unsigned flags);
 120201 /* Public extensions related functions */
 120244 typedef void *gnutls_ext_priv_data_t;
 120283 void gnutls_ext_set_data(gnutls_session_t session, unsigned type,
 120349 			 gnutls_ext_priv_data_t);
 120378 int gnutls_ext_get_data(gnutls_session_t session, unsigned type,
 120443 			gnutls_ext_priv_data_t *);
 120474 unsigned gnutls_ext_get_current_msg(gnutls_session_t session);
 120538 typedef int (*gnutls_ext_recv_func) (gnutls_session_t session,
 120601 				     const unsigned char *data,
 120637 				     size_t len);
 120660 typedef int (*gnutls_ext_send_func) (gnutls_session_t session,
 120723 				     gnutls_buffer_t extdata);
 120759 typedef void (*gnutls_ext_deinit_data_func) (gnutls_ext_priv_data_t data);
 120835 typedef int (*gnutls_ext_pack_func) (gnutls_ext_priv_data_t data,
 120901 				     gnutls_buffer_t packed_data);
 120941 typedef int (*gnutls_ext_unpack_func) (gnutls_buffer_t packed_data,
 121009 				       gnutls_ext_priv_data_t *data);
 121052 #define GNUTLS_EXT_RAW_FLAG_TLS_CLIENT_HELLO 1
 121099 #define GNUTLS_EXT_RAW_FLAG_DTLS_CLIENT_HELLO (1<<1)
 121152 typedef int (*gnutls_ext_raw_process_func)(void *ctx, unsigned tls_id, const unsigned char *data, unsigned data_size);
 121271 int gnutls_ext_raw_parse(void *ctx, gnutls_ext_raw_process_func cb,
 121339 			 const gnutls_datum_t *data, unsigned int flags);
 121397  * gnutls_ext_parse_type_t:
 121425  * @GNUTLS_EXT_NONE: Never to be parsed
 121465  * @GNUTLS_EXT_ANY: Any extension type (should not be used as it is used only internally).
 121556  * @GNUTLS_EXT_VERSION_NEG: Extensions to be parsed first for TLS version negotiation.
 121643  * @GNUTLS_EXT_MANDATORY: Parsed after @GNUTLS_EXT_VERSION_NEG and even when resuming.
 121730  * @GNUTLS_EXT_APPLICATION: Parsed after @GNUTLS_EXT_MANDATORY
 121793  * @GNUTLS_EXT_TLS: TLS-internal extensions, parsed after @GNUTLS_EXT_APPLICATION.
 121879  * Enumeration of different TLS extension parsing phases.  The @gnutls_ext_parse_type_t
 121967  * indicates the time/phase an extension is parsed during Client or Server hello parsing.
 122064 typedef enum {
 122079   GNUTLS_EXT_ANY = 0,
 122101   GNUTLS_EXT_APPLICATION = 1,
 122131   GNUTLS_EXT_TLS = 2,
 122153   GNUTLS_EXT_MANDATORY = 3,
 122181   GNUTLS_EXT_NONE = 4,
 122204   GNUTLS_EXT_VERSION_NEG = 5
 122233 } gnutls_ext_parse_type_t;
 122265  * gnutls_ext_flags_t:
 122288  * @GNUTLS_EXT_FLAG_OVERRIDE_INTERNAL: If specified the extension registered will override the internal; this does not work with extensions existing prior to 3.6.0.
 122453  * @GNUTLS_EXT_FLAG_CLIENT_HELLO: This extension can be present in a client hello
 122535  * @GNUTLS_EXT_FLAG_TLS12_SERVER_HELLO: This extension can be present in a TLS1.2 or earlier server hello
 122641  * @GNUTLS_EXT_FLAG_TLS13_SERVER_HELLO: This extension can be present in a TLS1.3 server hello
 122736  * @GNUTLS_EXT_FLAG_EE: This extension can be present in encrypted extensions message
 122822  * @GNUTLS_EXT_FLAG_HRR: This extension can be present in hello retry request message
 122908  * @GNUTLS_EXT_FLAG_IGNORE_CLIENT_REQUEST: When flag is present, this extension will be send even if the client didn't advertise it. An extension of this type is the Cookie TLS1.3 extension.
 123099  * @GNUTLS_EXT_FLAG_DTLS: This extension can be present under DTLS; otherwise ignored.
 123186  * @GNUTLS_EXT_FLAG_TLS: This extension can be present under TLS; otherwise ignored.
 123274  * Enumeration of different TLS extension registration flags.
 123340 typedef enum {
 123355   GNUTLS_EXT_FLAG_OVERRIDE_INTERNAL = 1,
 123396   GNUTLS_EXT_FLAG_CLIENT_HELLO = (1<<1),
 123437   GNUTLS_EXT_FLAG_TLS12_SERVER_HELLO = (1<<2),
 123484   GNUTLS_EXT_FLAG_TLS13_SERVER_HELLO = (1<<3),
 123531   GNUTLS_EXT_FLAG_EE = (1<<4), /* ENCRYPTED */
 123578   GNUTLS_EXT_FLAG_HRR = (1<<5),
 123610   GNUTLS_EXT_FLAG_IGNORE_CLIENT_REQUEST = (1<<6),
 123660   GNUTLS_EXT_FLAG_TLS = (1<<7),
 123692   GNUTLS_EXT_FLAG_DTLS = (1<<8)
 123724 } gnutls_ext_flags_t;
 123747 /* Register a custom tls extension
 123786 int gnutls_ext_register(const char *name, int type, gnutls_ext_parse_type_t parse_point,
 123875 				gnutls_ext_recv_func recv_func, gnutls_ext_send_func send_func, 
 123944 				gnutls_ext_deinit_data_func deinit_func, gnutls_ext_pack_func pack_func,
 124021 				gnutls_ext_unpack_func unpack_func);
 124063 int gnutls_session_ext_register(gnutls_session_t, const char *name, int type, gnutls_ext_parse_type_t parse_point,
 124178 				gnutls_ext_recv_func recv_func, gnutls_ext_send_func send_func, 
 124247 				gnutls_ext_deinit_data_func deinit_func, gnutls_ext_pack_func pack_func,
 124324 				gnutls_ext_unpack_func unpack_func, unsigned flags);
 124382 const char *gnutls_ext_get_name(unsigned int ext);
 124433 const char *gnutls_ext_get_name2(gnutls_session_t session, unsigned int tls_id,
 124513 				 gnutls_ext_parse_type_t parse_point);
 124557 /* Public supplemental data related functions */
 124607 typedef int (*gnutls_supp_recv_func) (gnutls_session_t session,
 124671 			       const unsigned char * data, size_t data_size);
 124728 typedef int (*gnutls_supp_send_func) (gnutls_session_t session,
 124792 			       gnutls_buffer_t buf);
 124825 int gnutls_supplemental_register(const char *name,
 124876 				gnutls_supplemental_data_format_type_t type,
 124925 				gnutls_supp_recv_func supp_recv_func,
 124967 				gnutls_supp_send_func supp_send_func);
 125011 int gnutls_session_supplemental_register(gnutls_session_t session, const char *name,
 125096 				gnutls_supplemental_data_format_type_t type,
 125145 				gnutls_supp_recv_func supp_recv_func,
 125187 				gnutls_supp_send_func supp_send_func,
 125229 				unsigned int flags);
 125255 void gnutls_supplemental_recv(gnutls_session_t session, unsigned do_recv_supplemental);
 125344 void gnutls_supplemental_send(gnutls_session_t session, unsigned do_send_supplemental);
 125433 /* Anti-replay related functions */
 125470 typedef struct gnutls_anti_replay_st *gnutls_anti_replay_t;
 125531 int gnutls_anti_replay_init(gnutls_anti_replay_t *anti_replay);
 125595 void gnutls_anti_replay_deinit(gnutls_anti_replay_t anti_replay);
 125661 void gnutls_anti_replay_set_window(gnutls_anti_replay_t anti_replay,
 125730 				   unsigned int window);
 125759 void gnutls_anti_replay_enable(gnutls_session_t session,
 125816 			       gnutls_anti_replay_t anti_replay);
 125862 typedef int (*gnutls_db_add_func) (void *, time_t exp_time, const gnutls_datum_t *key,
 125949 				   const gnutls_datum_t *data);
 125986 void gnutls_anti_replay_set_add_function(gnutls_anti_replay_t,
 126049 					 gnutls_db_add_func add_func);
 126086 void gnutls_anti_replay_set_ptr(gnutls_anti_replay_t, void *ptr);
 126158  * gnutls_record_encryption_level_t:
 126195  * @GNUTLS_ENCRYPTION_LEVEL_INITIAL: initial level that doesn't involve any
 126271  *    encryption
 126288  * @GNUTLS_ENCRYPTION_LEVEL_EARLY: early traffic secret is installed
 126357  * @GNUTLS_ENCRYPTION_LEVEL_HANDSHAKE: handshake traffic secret is installed
 126434  * @GNUTLS_ENCRYPTION_LEVEL_APPLICATION: application traffic secret is installed
 126518  * Enumeration of different levels of record encryption currently in place.
 126594  * This is used by gnutls_handshake_set_read_function() and
 126654  * gnutls_handshake_write().
 126686  * Since: 3.7.0
 126706 typedef enum {
 126721 	GNUTLS_ENCRYPTION_LEVEL_INITIAL,
 126755 	GNUTLS_ENCRYPTION_LEVEL_EARLY,
 126787 	GNUTLS_ENCRYPTION_LEVEL_HANDSHAKE,
 126823 	GNUTLS_ENCRYPTION_LEVEL_APPLICATION
 126860 } gnutls_record_encryption_level_t;
 126897   /**
 126903    * gnutls_handshake_read_func:
 126936    * @session: the current session
 126971    * @htype: the type of the handshake message (#gnutls_handshake_description_t)
 127052    * @level: #gnutls_record_encryption_level_t
 127099    * @data: the (const) data that was being sent
 127148    * @data_size: the size of data
 127182    *
 127187    * Function prototype for handshake intercepting hooks. It is set using
 127261    * gnutls_handshake_set_read_function().
 127304    *
 127309    * Returns: Non zero on error.
 127342    * Since: 3.7.0
 127360    */
 127366 typedef int (*gnutls_handshake_read_func) (gnutls_session_t session,
 127435 					   gnutls_record_encryption_level_t level,
 127483 					   gnutls_handshake_description_t htype,
 127529 					   const void *data, size_t data_size);
 127575 void
 127580 gnutls_handshake_set_read_function(gnutls_session_t session,
 127641 				   gnutls_handshake_read_func func);
 127687 gnutls_handshake_write(gnutls_session_t session,
 127736 		       gnutls_record_encryption_level_t level,
 127785 		       const void *data, size_t data_size);
 127832   /**
 127838    * gnutls_handshake_secret_func:
 127873    * @session: the current session
 127908    * @level: the encryption level
 127942    * @secret_read: the secret used for reading, can be %NULL if not set
 128014    * @secret_write: the secret used for writing, can be %NULL if not set
 128087    * @secret_size: the size of the secrets
 128130    *
 128135    * Function prototype for secret hooks. It is set using
 128193    * gnutls_handshake_set_secret_function().
 128238    *
 128243    * Returns: Non zero on error.
 128276    * Since: 3.7.0
 128294    */
 128300 typedef int (*gnutls_handshake_secret_func) (gnutls_session_t session,
 128371 					     gnutls_record_encryption_level_t level,
 128421 					     const void *secret_read,
 128456 					     const void *secret_write,
 128492 					     size_t secret_size);
 128524 void
 128529 gnutls_handshake_set_secret_function(gnutls_session_t session,
 128592 				     gnutls_handshake_secret_func func);
 128638   /**
 128644    * gnutls_alert_read_func:
 128673    * @session: the current session
 128708    * @level: #gnutls_record_encryption_level_t
 128755    * @alert_level: the level of the alert
 128797    * @alert_desc: the alert description
 128837    *
 128842    * Function prototype for alert intercepting hooks. It is set using
 128912    * gnutls_alert_set_read_function().
 128951    *
 128956    * Returns: Non zero on error.
 128989    * Since: 3.7.0
 129007    */
 129013 typedef int (*gnutls_alert_read_func) (gnutls_session_t session,
 129078 				       gnutls_record_encryption_level_t level,
 129129 				       gnutls_alert_level_t alert_level,
 129174 				       gnutls_alert_description_t alert_desc);
 129226 void
 129231 gnutls_alert_set_read_function(gnutls_session_t session,
 129288 			       gnutls_alert_read_func func);
 129329 /* FIPS140-2 related functions */
 129363 unsigned gnutls_fips140_mode_enabled(void);
 129412  * gnutls_fips_mode_t:
 129435  * @GNUTLS_FIPS140_DISABLED: The FIPS140-2 mode is disabled.
 129496  * @GNUTLS_FIPS140_STRICT: The default mode; all forbidden operations will cause an
 129580  *                         operation failure via error code.
 129641  * @GNUTLS_FIPS140_LAX: The library still uses the FIPS140-2 relevant algorithms but all
 129730  *                      forbidden by FIPS140-2 operations are allowed; this is useful when the
 129825  *                      application is aware of the followed security policy, and needs
 129913  *                      to utilize disallowed operations for other reasons (e.g., compatibility).
 130011  * @GNUTLS_FIPS140_LOG: Similarly to %GNUTLS_FIPS140_LAX, it allows forbidden operations; any use of them results
 130125  *                      to a message to the audit callback functions.
 130195  * @GNUTLS_FIPS140_SELFTESTS: A transient state during library initialization. That state
 130285  *			cannot be set or seen by applications.
 130332  * Enumeration of different operational modes under FIPS140-2.
 130399 typedef enum gnutls_fips_mode_t {
 130433   GNUTLS_FIPS140_DISABLED = 0,
 130464   GNUTLS_FIPS140_STRICT = 1,
 130493   GNUTLS_FIPS140_SELFTESTS = 2,
 130525   GNUTLS_FIPS140_LAX = 3,
 130551   GNUTLS_FIPS140_LOG = 4
 130576 } gnutls_fips_mode_t;
 130599 #define GNUTLS_FIPS140_SET_MODE_THREAD 1
 130641 void gnutls_fips140_set_mode(gnutls_fips_mode_t mode, unsigned flags);
 130713 #define GNUTLS_FIPS140_SET_LAX_MODE() do { \
 130758 	if (gnutls_fips140_mode_enabled()) \
 130796 		gnutls_fips140_set_mode(GNUTLS_FIPS140_LAX, GNUTLS_FIPS140_SET_MODE_THREAD); \
 130877 	} while(0)
 130890 #define GNUTLS_FIPS140_SET_STRICT_MODE() do { \
 130938 	if (gnutls_fips140_mode_enabled()) \
 130976 		gnutls_fips140_set_mode(GNUTLS_FIPS140_STRICT, GNUTLS_FIPS140_SET_MODE_THREAD); \
 131060 	} while(0)
 131073 typedef struct gnutls_fips140_context_st *gnutls_fips140_context_t;
 131142 int gnutls_fips140_context_init(gnutls_fips140_context_t *context);
 131210 void gnutls_fips140_context_deinit(gnutls_fips140_context_t context);
 131285  * gnutls_fips140_operation_state_t:
 131322  * @GNUTLS_FIPS140_OP_INITIAL: no previous operation has done
 131384  * @GNUTLS_FIPS140_OP_APPROVED: the previous operation was FIPS approved
 131457  * @GNUTLS_FIPS140_OP_NOT_APPROVED: the previous operation was not FIPS approved
 131538  * @GNUTLS_FIPS140_OP_ERROR: the previous operation caused an error regardless of FIPS
 131628  * The FIPS operation state set by the preceding operation.
 131691  * There are state transition rules among the enum values:
 131750  * - When the context is attached to a thread, it will be set to reset
 131821  *   to the %GNUTLS_FIPS140_OP_INITIAL state
 131866  * - From the %GNUTLS_FIPS140_OP_INITIAL state, the context can
 131930  *   transition to either %GNUTLS_FIPS140_OP_APPROVED,
 131985  *   %GNUTLS_FIPS140_OP_NOT_APPROVED, or %GNUTLS_FIPS140_OP_ERROR
 132051  * - From the %GNUTLS_FIPS140_OP_APPROVED state, the context can
 132116  *   transition to %GNUTLS_FIPS140_OP_NOT_APPROVED
 132167  * - All other transitions are prohibited.
 132213  * Since: 3.7.3
 132233 typedef enum {
 132248         GNUTLS_FIPS140_OP_INITIAL,
 132283         GNUTLS_FIPS140_OP_APPROVED,
 132319         GNUTLS_FIPS140_OP_NOT_APPROVED,
 132359         GNUTLS_FIPS140_OP_ERROR
 132391 } gnutls_fips140_operation_state_t;
 132428 gnutls_fips140_operation_state_t
 132461 gnutls_fips140_get_operation_state(gnutls_fips140_context_t context);
 132532 int gnutls_fips140_push_context(gnutls_fips140_context_t context);
 132599 int gnutls_fips140_pop_context(void);
 132638   /* Gnutls error codes. The mapping to a TLS alert is also shown in
 132707    * comments.
 132722    */
 132729 #define GNUTLS_E_SUCCESS 0
 132756 #define	GNUTLS_E_UNKNOWN_COMPRESSION_ALGORITHM -3
 132806 #define	GNUTLS_E_UNKNOWN_CIPHER_TYPE -6
 132846 #define	GNUTLS_E_LARGE_PACKET -7
 132879 #define GNUTLS_E_UNSUPPORTED_VERSION_PACKET -8	/* GNUTLS_A_PROTOCOL_VERSION */
 132958 #define GNUTLS_E_TLS_PACKET_DECODING_ERROR GNUTLS_E_UNEXPECTED_PACKET_LENGTH
 133035 #define GNUTLS_E_UNEXPECTED_PACKET_LENGTH -9	/* GNUTLS_A_DECODE_ERROR */
 133108 #define GNUTLS_E_INVALID_SESSION -10
 133145 #define GNUTLS_E_FATAL_ALERT_RECEIVED -12
 133187 #define GNUTLS_E_UNEXPECTED_PACKET -15	/* GNUTLS_A_UNEXPECTED_MESSAGE */
 133260 #define GNUTLS_E_WARNING_ALERT_RECEIVED -16
 133304 #define GNUTLS_E_ERROR_IN_FINISHED_PACKET -18
 133350 #define GNUTLS_E_UNEXPECTED_HANDSHAKE_PACKET -19
 133399 #define	GNUTLS_E_UNKNOWN_CIPHER_SUITE -21	/* GNUTLS_A_HANDSHAKE_FAILURE */
 133474 #define	GNUTLS_E_UNWANTED_ALGORITHM -22
 133514 #define	GNUTLS_E_MPI_SCAN_FAILED -23
 133551 #define GNUTLS_E_DECRYPTION_FAILED -24	/* GNUTLS_A_DECRYPTION_FAILED, GNUTLS_A_BAD_RECORD_MAC */
 133648 #define GNUTLS_E_MEMORY_ERROR -25
 133682 #define GNUTLS_E_DECOMPRESSION_FAILED -26	/* GNUTLS_A_DECOMPRESSION_FAILURE */
 133761 #define GNUTLS_E_COMPRESSION_FAILED -27
 133801 #define GNUTLS_E_AGAIN -28
 133828 #define GNUTLS_E_EXPIRED -29
 133857 #define GNUTLS_E_DB_ERROR -30
 133887 #define GNUTLS_E_SRP_PWD_ERROR GNUTLS_E_KEYFILE_ERROR
 133941 #define GNUTLS_E_KEYFILE_ERROR -31
 133976 #define GNUTLS_E_INSUFFICIENT_CREDENTIALS -32
 134022 #define GNUTLS_E_INSUFICIENT_CREDENTIALS GNUTLS_E_INSUFFICIENT_CREDENTIALS	/* for backwards compatibility only */
 134136 #define GNUTLS_E_INSUFFICIENT_CRED GNUTLS_E_INSUFFICIENT_CREDENTIALS
 134205 #define GNUTLS_E_INSUFICIENT_CRED GNUTLS_E_INSUFFICIENT_CREDENTIALS	/* for backwards compatibility only */
 134313 #define GNUTLS_E_HASH_FAILED -33
 134346 #define GNUTLS_E_BASE64_DECODING_ERROR -34
 134390 #define	GNUTLS_E_MPI_PRINT_FAILED -35
 134428 #define GNUTLS_E_REHANDSHAKE -37	/* GNUTLS_A_NO_RENEGOTIATION */
 134493 #define GNUTLS_E_GOT_APPLICATION_DATA -38
 134535 #define GNUTLS_E_RECORD_LIMIT_REACHED -39
 134577 #define GNUTLS_E_ENCRYPTION_FAILED -40
 134617 #define GNUTLS_E_PK_ENCRYPTION_FAILED -44
 134659 #define GNUTLS_E_PK_DECRYPTION_FAILED -45
 134701 #define GNUTLS_E_PK_SIGN_FAILED -46
 134737 #define GNUTLS_E_X509_UNSUPPORTED_CRITICAL_EXTENSION -47
 134794 #define GNUTLS_E_KEY_USAGE_VIOLATION -48
 134835 #define GNUTLS_E_NO_CERTIFICATE_FOUND -49	/* GNUTLS_A_BAD_CERTIFICATE */
 134908 #define GNUTLS_E_INVALID_REQUEST -50
 134945 #define GNUTLS_E_SHORT_MEMORY_BUFFER -51
 134986 #define GNUTLS_E_INTERRUPTED -52
 135019 #define GNUTLS_E_PUSH_ERROR -53
 135051 #define GNUTLS_E_PULL_ERROR -54
 135083 #define GNUTLS_E_RECEIVED_ILLEGAL_PARAMETER -55	/* GNUTLS_A_ILLEGAL_PARAMETER */
 135164 #define GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE -56
 135214 #define GNUTLS_E_PKCS1_WRONG_PAD -57
 135251 #define GNUTLS_E_RECEIVED_ILLEGAL_EXTENSION -58
 135299 #define GNUTLS_E_INTERNAL_ERROR -59
 135335 #define GNUTLS_E_DH_PRIME_UNACCEPTABLE -63
 135378 #define GNUTLS_E_FILE_ERROR -64
 135410 #define GNUTLS_E_TOO_MANY_EMPTY_PACKETS -78
 135454 #define GNUTLS_E_UNKNOWN_PK_ALGORITHM -80
 135496 #define GNUTLS_E_TOO_MANY_HANDSHAKE_PACKETS -81
 135544 #define GNUTLS_E_RECEIVED_DISALLOWED_NAME -82 /* GNUTLS_A_ILLEGAL_PARAMETER */
 135623 #define GNUTLS_E_CERTIFICATE_REQUIRED -112 /* GNUTLS_A_CERTIFICATE_REQUIRED */
 135703   /* returned if you need to generate temporary RSA
 135755    * parameters. These are needed for export cipher suites.
 135815    */
 135821 #define GNUTLS_E_NO_TEMPORARY_RSA_PARAMS -84
 135867 #define GNUTLS_E_NO_COMPRESSION_ALGORITHMS -86
 135914 #define GNUTLS_E_NO_CIPHER_SUITES -87
 135953 #define GNUTLS_E_OPENPGP_GETKEY_FAILED -88
 135996 #define GNUTLS_E_PK_SIG_VERIFY_FAILED -89
 136039 #define GNUTLS_E_ILLEGAL_SRP_USERNAME -90
 136081 #define GNUTLS_E_SRP_PWD_PARSING_ERROR GNUTLS_E_KEYFILE_PARSING_ERROR
 136151 #define GNUTLS_E_KEYFILE_PARSING_ERROR -91
 136194 #define GNUTLS_E_NO_TEMPORARY_DH_PARAMS -93
 136239   /* For certificate and key stuff
 136274    */
 136280 #define GNUTLS_E_ASN1_ELEMENT_NOT_FOUND -67
 136324 #define GNUTLS_E_ASN1_IDENTIFIER_NOT_FOUND -68
 136371 #define GNUTLS_E_ASN1_DER_ERROR -69
 136407 #define GNUTLS_E_ASN1_VALUE_NOT_FOUND -70
 136449 #define GNUTLS_E_ASN1_GENERIC_ERROR -71
 136489 #define GNUTLS_E_ASN1_VALUE_NOT_VALID -72
 136531 #define GNUTLS_E_ASN1_TAG_ERROR -73
 136567 #define GNUTLS_E_ASN1_TAG_IMPLICIT -74
 136606 #define GNUTLS_E_ASN1_TYPE_ANY_ERROR -75
 136647 #define GNUTLS_E_ASN1_SYNTAX_ERROR -76
 136686 #define GNUTLS_E_ASN1_DER_OVERFLOW -77
 136725 #define GNUTLS_E_OPENPGP_UID_REVOKED -79
 136766 #define GNUTLS_E_CERTIFICATE_ERROR -43
 136805 #define GNUTLS_E_X509_CERTIFICATE_ERROR GNUTLS_E_CERTIFICATE_ERROR
 136872 #define GNUTLS_E_CERTIFICATE_KEY_MISMATCH -60
 136918 #define GNUTLS_E_UNSUPPORTED_CERTIFICATE_TYPE -61	/* GNUTLS_A_UNSUPPORTED_CERTIFICATE */
 137007 #define GNUTLS_E_X509_UNKNOWN_SAN -62
 137045 #define GNUTLS_E_OPENPGP_FINGERPRINT_UNSUPPORTED -94
 137098 #define GNUTLS_E_X509_UNSUPPORTED_ATTRIBUTE -95
 137146 #define GNUTLS_E_UNKNOWN_HASH_ALGORITHM -96
 137190 #define GNUTLS_E_UNKNOWN_PKCS_CONTENT_TYPE -97
 137237 #define GNUTLS_E_UNKNOWN_PKCS_BAG_TYPE -98
 137280 #define GNUTLS_E_INVALID_PASSWORD -99
 137318 #define GNUTLS_E_MAC_VERIFY_FAILED -100	/* for PKCS #12 MAC */
 137381 #define GNUTLS_E_CONSTRAINT_ERROR -101
 137421 #define GNUTLS_E_WARNING_IA_IPHF_RECEIVED -102
 137468 #define GNUTLS_E_WARNING_IA_FPHF_RECEIVED -103
 137516 #define GNUTLS_E_IA_VERIFY_FAILED -104
 137555 #define GNUTLS_E_UNKNOWN_ALGORITHM -105
 137595 #define GNUTLS_E_UNSUPPORTED_SIGNATURE_ALGORITHM -106
 137649 #define GNUTLS_E_SAFE_RENEGOTIATION_FAILED -107
 137697 #define GNUTLS_E_UNSAFE_RENEGOTIATION_DENIED -108
 137747 #define GNUTLS_E_UNKNOWN_SRP_USERNAME -109
 137790 #define GNUTLS_E_PREMATURE_TERMINATION -110
 137835 #define GNUTLS_E_MALFORMED_CIDR -111
 137873 #define GNUTLS_E_BASE64_ENCODING_ERROR -201
 137917 #define GNUTLS_E_INCOMPATIBLE_GCRYPT_LIBRARY -202	/* obsolete */
 137982 #define GNUTLS_E_INCOMPATIBLE_CRYPTO_LIBRARY -202
 138032 #define GNUTLS_E_INCOMPATIBLE_LIBTASN1_LIBRARY -203
 138085 #define GNUTLS_E_OPENPGP_KEYRING_ERROR -204
 138129 #define GNUTLS_E_X509_UNSUPPORTED_OID -205
 138173 #define GNUTLS_E_RANDOM_FAILED -206
 138209 #define GNUTLS_E_BASE64_UNEXPECTED_HEADER_ERROR -207
 138263 #define GNUTLS_E_OPENPGP_SUBKEY_ERROR -208
 138307 #define GNUTLS_E_CRYPTO_ALREADY_REGISTERED GNUTLS_E_ALREADY_REGISTERED
 138378 #define GNUTLS_E_ALREADY_REGISTERED -209
 138420 #define GNUTLS_E_HANDSHAKE_TOO_LARGE -210
 138463 #define GNUTLS_E_CRYPTODEV_IOCTL_ERROR -211
 138507 #define GNUTLS_E_CRYPTODEV_DEVICE_ERROR -212
 138553 #define GNUTLS_E_CHANNEL_BINDING_NOT_AVAILABLE -213
 138605 #define GNUTLS_E_BAD_COOKIE -214
 138638 #define GNUTLS_E_OPENPGP_PREFERRED_KEY_ERROR -215
 138688 #define GNUTLS_E_INCOMPAT_DSA_KEY_WITH_TLS_PROTOCOL -216
 138745 #define GNUTLS_E_INSUFFICIENT_SECURITY -217
 138790 #define GNUTLS_E_HEARTBEAT_PONG_RECEIVED -292
 138836 #define GNUTLS_E_HEARTBEAT_PING_RECEIVED -293
 138883 #define GNUTLS_E_UNRECOGNIZED_NAME -294
 138924 /* PKCS11 related */
 138945 #define GNUTLS_E_PKCS11_ERROR -300
 138980 #define GNUTLS_E_PKCS11_LOAD_ERROR -301
 139020 #define GNUTLS_E_PARSING_ERROR -302
 139056 #define GNUTLS_E_PKCS11_PIN_ERROR -303
 139096 #define GNUTLS_E_PKCS11_SLOT_ERROR -305
 139136 #define GNUTLS_E_LOCKING_ERROR -306
 139172 #define GNUTLS_E_PKCS11_ATTRIBUTE_ERROR -307
 139217 #define GNUTLS_E_PKCS11_DEVICE_ERROR -308
 139259 #define GNUTLS_E_PKCS11_DATA_ERROR -309
 139299 #define GNUTLS_E_PKCS11_UNSUPPORTED_FEATURE_ERROR -310
 139354 #define GNUTLS_E_PKCS11_KEY_ERROR -311
 139393 #define GNUTLS_E_PKCS11_PIN_EXPIRED -312
 139434 #define GNUTLS_E_PKCS11_PIN_LOCKED -313
 139474 #define GNUTLS_E_PKCS11_SESSION_ERROR -314
 139517 #define GNUTLS_E_PKCS11_SIGNATURE_ERROR -315
 139562 #define GNUTLS_E_PKCS11_TOKEN_ERROR -316
 139603 #define GNUTLS_E_PKCS11_USER_ERROR -317
 139644 #define GNUTLS_E_CRYPTO_INIT_FAILED -318
 139685 #define GNUTLS_E_TIMEDOUT -319
 139716 #define GNUTLS_E_USER_ERROR -320
 139749 #define GNUTLS_E_ECC_NO_SUPPORTED_CURVES -321
 139795 #define GNUTLS_E_ECC_UNSUPPORTED_CURVE -322
 139839 #define GNUTLS_E_PKCS11_REQUESTED_OBJECT_NOT_AVAILBLE -323
 139898 #define GNUTLS_E_CERTIFICATE_LIST_UNSORTED -324
 139946 #define GNUTLS_E_ILLEGAL_PARAMETER -325 /* GNUTLS_A_ILLEGAL_PARAMETER */
 140019 #define GNUTLS_E_NO_PRIORITIES_WERE_SET -326
 140064 #define GNUTLS_E_X509_UNSUPPORTED_EXTENSION -327
 140113 #define GNUTLS_E_SESSION_EOF -328
 140148 #define GNUTLS_E_TPM_ERROR -329
 140180 #define GNUTLS_E_TPM_KEY_PASSWORD_ERROR -330
 140225 #define GNUTLS_E_TPM_SRK_PASSWORD_ERROR -331
 140270 #define GNUTLS_E_TPM_SESSION_ERROR -332
 140310 #define GNUTLS_E_TPM_KEY_NOT_FOUND -333
 140350 #define GNUTLS_E_TPM_UNINITIALIZED -334
 140390 #define GNUTLS_E_TPM_NO_LIB -335
 140424 #define GNUTLS_E_NO_CERTIFICATE_STATUS -340
 140468 #define GNUTLS_E_OCSP_RESPONSE_ERROR -341
 140510 #define GNUTLS_E_RANDOM_DEVICE_ERROR -342
 140552 #define GNUTLS_E_AUTH_ERROR -343
 140585 #define GNUTLS_E_NO_APPLICATION_PROTOCOL -344
 140631 #define GNUTLS_E_SOCKETS_INIT_ERROR -345
 140672 #define GNUTLS_E_KEY_IMPORT_FAILED -346
 140712 #define GNUTLS_E_INAPPROPRIATE_FALLBACK -347 /*GNUTLS_A_INAPPROPRIATE_FALLBACK*/
 140793 #define GNUTLS_E_CERTIFICATE_VERIFICATION_ERROR -348
 140846 #define GNUTLS_E_PRIVKEY_VERIFICATION_ERROR -349
 140895 #define GNUTLS_E_UNEXPECTED_EXTENSIONS_LENGTH -350 /*GNUTLS_A_DECODE_ERROR*/
 140972 #define GNUTLS_E_ASN1_EMBEDDED_NULL_IN_STRING -351
 141024 #define GNUTLS_E_SELF_TEST_ERROR -400
 141062 #define GNUTLS_E_NO_SELF_TEST -401
 141097 #define GNUTLS_E_LIB_IN_ERROR_STATE -402
 141138 #define GNUTLS_E_PK_GENERATION_ERROR -403
 141180 #define GNUTLS_E_IDNA_ERROR -404
 141214 #define GNUTLS_E_NEED_FALLBACK -405
 141250 #define GNUTLS_E_SESSION_USER_ID_CHANGED -406
 141296 #define GNUTLS_E_HANDSHAKE_DURING_FALSE_START -407
 141347 #define GNUTLS_E_UNAVAILABLE_DURING_HANDSHAKE -408
 141398 #define GNUTLS_E_PK_INVALID_PUBKEY -409
 141438 #define GNUTLS_E_PK_INVALID_PRIVKEY -410
 141479 #define GNUTLS_E_NOT_YET_ACTIVATED -411
 141519 #define GNUTLS_E_INVALID_UTF8_STRING -412
 141561 #define GNUTLS_E_NO_EMBEDDED_DATA -413
 141600 #define GNUTLS_E_INVALID_UTF8_EMAIL -414
 141641 #define GNUTLS_E_INVALID_PASSWORD_STRING -415
 141687 #define GNUTLS_E_CERTIFICATE_TIME_ERROR -416
 141732 #define GNUTLS_E_RECORD_OVERFLOW -417	/* GNUTLS_A_RECORD_OVERFLOW */
 141801 #define GNUTLS_E_ASN1_TIME_ERROR -418
 141839 #define GNUTLS_E_INCOMPATIBLE_SIG_WITH_KEY -419
 141887 #define GNUTLS_E_PK_INVALID_PUBKEY_PARAMS -420
 141934 #define GNUTLS_E_PK_NO_VALIDATION_PARAMS -421
 141980 #define GNUTLS_E_OCSP_MISMATCH_WITH_CERTS -422
 142028 #define GNUTLS_E_NO_COMMON_KEY_SHARE -423
 142070 #define GNUTLS_E_REAUTH_REQUEST -424
 142107 #define GNUTLS_E_TOO_MANY_MATCHES -425
 142146 #define GNUTLS_E_CRL_VERIFICATION_ERROR -426
 142191 #define GNUTLS_E_MISSING_EXTENSION -427
 142231 #define GNUTLS_E_DB_ENTRY_EXISTS -428
 142269 #define GNUTLS_E_EARLY_DATA_REJECTED -429
 142311 #define GNUTLS_E_X509_DUPLICATE_EXTENSION -430
 142359 #define GNUTLS_E_UNIMPLEMENTED_FEATURE -1250
 142405 /* Internal errors of the library; will never be returned
 142463  * to a calling application */
 142494 #define GNUTLS_E_INT_RET_0 -1251
 142527 #define GNUTLS_E_INT_CHECK_AGAIN -1252
 142567 #define GNUTLS_E_APPLICATION_ERROR_MAX -65000
 142613 #define GNUTLS_E_APPLICATION_ERROR_MIN -65500
 142660 /* *INDENT-OFF* */
 142679 #ifdef __cplusplus
 142700 #endif
 142707 /* *INDENT-ON* */
 142726 #include <gnutls/compat.h>
 142754 #endif /* GNUTLS_GNUTLS_H */

diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..d66ef1ae97b4ae964c6904864e96f210cd14eb7a
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_REQUESTED_DATA_NOT_AVAILABLE);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

apply patch
patch: completed
/tmp/llmdec_codex_366ssvk9/decompiled.c
diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..3648c9b1eb0c95e3eac00d71f69652e6ad406e1f
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..3648c9b1eb0c95e3eac00d71f69652e6ad406e1f
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

exec
/bin/bash -lc 'strings -a -n 1 ./decompiled.c
file ./decompiled.c' in /tmp/llmdec_codex_366ssvk9
 succeeded in 0ms:
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
typedef void *gnutls_x509_crt_t;
typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;
typedef struct {
    unsigned char opaque[0x108];
} socket_st;
enum {
    GNUTLS_IA_OCSP_URI = 0x2716,
    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
    SOCKET_FLAG_RAW = 0x28,
    SOCKET_BUFFER_SIZE = 0x1001
};
extern int gnutls_x509_crt_get_authority_info_access(
    gnutls_x509_crt_t crt, unsigned int seq, int what,
    gnutls_datum_t *data, unsigned int *critical);
extern const char *gnutls_strerror(int error);
extern void gnutls_free(void *data);
extern void *memmem(const void *haystack, size_t haystack_len,
                    const void *needle, size_t needle_len);
extern char *sub_13ae0(const char *url, unsigned int *port,
                       const char **path);
extern void sub_13b90(size_t size, gnutls_datum_t *data);
extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
                      gnutls_datum_t *request,
                      const gnutls_datum_t *nonce);
extern int sub_11250(socket_st *socket, const char *host,
                     const char *service, void *credentials,
                     unsigned int flags, const char *description, ...);
extern ssize_t sub_10f90(socket_st *socket, const void *data,
                         unsigned int size);
extern ssize_t sub_10d90(socket_st *socket, void *data,
                         unsigned int size);
extern void sub_11040(socket_st *socket, int graceful);
extern unsigned char sub_94700[];
int sub_13d10(const char *url, gnutls_x509_crt_t crt,
              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
              const gnutls_datum_t *nonce)
{
    gnutls_datum_t uri;
    gnutls_datum_t request;
    gnutls_datum_t http_response = { NULL, 0 };
    socket_st socket;
    const char *original_url = url;
    const char *path;
    char *host;
    char *allocated_url = NULL;
    char port_string[16];
    char request_header[1024];
    unsigned int port;
    unsigned int seq;
    size_t header_size;
    unsigned char *body;
    ssize_t ret;
    signal(SIGPIPE, SIG_IGN);
    if (url == NULL) {
        seq = 0;
        do {
            ret = gnutls_x509_crt_get_authority_info_access(
                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
        if (ret < 0) {
            seq = 0;
            do {
                ret = gnutls_x509_crt_get_authority_info_access(
                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
            if (ret < 0) {
                fprintf(stderr,
                        "*** Cannot find OCSP server URI in certificate: %s\n",
                        gnutls_strerror((int)ret));
                return (int)ret;
            }
        }
        allocated_url = malloc((size_t)uri.size + 1);
        if (allocated_url == NULL)
            return -1;
        memcpy(allocated_url, uri.data, uri.size);
        allocated_url[uri.size] = '\0';
        gnutls_free(uri.data);
        url = allocated_url;
    }
    host = sub_13ae0(url, &port, &path);
    if (port == 0)
        strcpy(port_string, "80");
    else
        snprintf(port_string, sizeof(port_string), "%u", port);
    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
    sub_13c00(crt, issuer, &request, nonce);
    snprintf(request_header, sizeof(request_header),
             "POST /%s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Accept: */*\r\n"
             "Content-Type: application/ocsp-request\r\n"
             "Content-Length: %u\r\n"
             "Connection: close\r\n\r\n",
             path, host, request.size);
    header_size = strlen(request_header);
    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
              "Connecting to", NULL, NULL, NULL, NULL);
    sub_10f90(&socket, request_header, (unsigned int)header_size);
    sub_10f90(&socket, request.data, request.size);
    gnutls_free(request.data);
    request.data = NULL;
    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
        sub_13b90((size_t)ret, &http_response);
    if (ret != 0 || http_response.size == 0) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }
    sub_11040(&socket, 0);
    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
    if (body == NULL) {
        fprintf(stderr, "Cannot interpret HTTP response\n");
        ret = -1;
        goto cleanup;
    }
    body += 4;
    response->size = http_response.size -
                     (unsigned int)(body - http_response.data);
    response->data = malloc(response->size);
    if (response->data == NULL) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }
    memcpy(response->data, body, response->size);
cleanup:
    free(http_response.data);
    if (url != original_url)
        free(allocated_url);
    return (int)ret;
}
./decompiled.c: C source, ASCII text

diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..3648c9b1eb0c95e3eac00d71f69652e6ad406e1f
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef void *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

apply patch
patch: completed
/tmp/llmdec_codex_366ssvk9/decompiled.c
diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..47c67a0638239855d289c879aec1b65b5e2fc483
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

The reconstructed source has been written and checked for the required single-function output shape.
  ✓ Inspect binary metadata, target disassembly, constants, and relocations
  ✓ Infer helper semantics and reconstruct structured control flow
  ✓ Write decompiled.c and verify the output contract
diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..47c67a0638239855d289c879aec1b65b5e2fc483
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

codex
Created [decompiled.c](/tmp/llmdec_codex_366ssvk9/decompiled.c).
diff --git a/llmdec_codex_366ssvk9/decompiled.c b/llmdec_codex_366ssvk9/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..47c67a0638239855d289c879aec1b65b5e2fc483
--- /dev/null
+++ b/llmdec_codex_366ssvk9/decompiled.c
@@ -0,0 +1,165 @@
+#include <signal.h>
+#include <stddef.h>
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/types.h>
+
+typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;
+
+typedef struct {
+    unsigned char *data;
+    unsigned int size;
+} gnutls_datum_t;
+
+typedef struct {
+    unsigned char opaque[0x108];
+} socket_st;
+
+enum {
+    GNUTLS_IA_OCSP_URI = 0x2716,
+    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
+    SOCKET_FLAG_RAW = 0x28,
+    SOCKET_BUFFER_SIZE = 0x1001
+};
+
+extern int gnutls_x509_crt_get_authority_info_access(
+    gnutls_x509_crt_t crt, unsigned int seq, int what,
+    gnutls_datum_t *data, unsigned int *critical);
+extern const char *gnutls_strerror(int error);
+extern void gnutls_free(void *data);
+extern void *memmem(const void *haystack, size_t haystack_len,
+                    const void *needle, size_t needle_len);
+
+extern char *sub_13ae0(const char *url, unsigned int *port,
+                       const char **path);
+extern void sub_13b90(size_t size, gnutls_datum_t *data);
+extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
+                      gnutls_datum_t *request,
+                      const gnutls_datum_t *nonce);
+extern int sub_11250(socket_st *socket, const char *host,
+                     const char *service, void *credentials,
+                     unsigned int flags, const char *description, ...);
+extern ssize_t sub_10f90(socket_st *socket, const void *data,
+                         unsigned int size);
+extern ssize_t sub_10d90(socket_st *socket, void *data,
+                         unsigned int size);
+extern void sub_11040(socket_st *socket, int graceful);
+extern unsigned char sub_94700[];
+
+int sub_13d10(const char *url, gnutls_x509_crt_t crt,
+              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
+              const gnutls_datum_t *nonce)
+{
+    gnutls_datum_t uri;
+    gnutls_datum_t request;
+    gnutls_datum_t http_response = { NULL, 0 };
+    socket_st socket;
+    const char *original_url = url;
+    const char *path;
+    char *host;
+    char *allocated_url = NULL;
+    char port_string[16];
+    char request_header[1024];
+    unsigned int port;
+    unsigned int seq;
+    size_t header_size;
+    unsigned char *body;
+    ssize_t ret;
+
+    signal(SIGPIPE, SIG_IGN);
+
+    if (url == NULL) {
+        seq = 0;
+        do {
+            ret = gnutls_x509_crt_get_authority_info_access(
+                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+        if (ret < 0) {
+            seq = 0;
+            do {
+                ret = gnutls_x509_crt_get_authority_info_access(
+                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
+            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);
+
+            if (ret < 0) {
+                fprintf(stderr,
+                        "*** Cannot find OCSP server URI in certificate: %s\n",
+                        gnutls_strerror((int)ret));
+                return (int)ret;
+            }
+        }
+
+        allocated_url = malloc((size_t)uri.size + 1);
+        if (allocated_url == NULL)
+            return -1;
+
+        memcpy(allocated_url, uri.data, uri.size);
+        allocated_url[uri.size] = '\0';
+        gnutls_free(uri.data);
+        url = allocated_url;
+    }
+
+    host = sub_13ae0(url, &port, &path);
+    if (port == 0)
+        strcpy(port_string, "80");
+    else
+        snprintf(port_string, sizeof(port_string), "%u", port);
+
+    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);
+
+    sub_13c00(crt, issuer, &request, nonce);
+    snprintf(request_header, sizeof(request_header),
+             "POST /%s HTTP/1.0\r\n"
+             "Host: %s\r\n"
+             "Accept: */*\r\n"
+             "Content-Type: application/ocsp-request\r\n"
+             "Content-Length: %u\r\n"
+             "Connection: close\r\n\r\n",
+             path, host, request.size);
+    header_size = strlen(request_header);
+
+    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
+              "Connecting to", NULL, NULL, NULL, NULL);
+    sub_10f90(&socket, request_header, (unsigned int)header_size);
+    sub_10f90(&socket, request.data, request.size);
+    gnutls_free(request.data);
+    request.data = NULL;
+
+    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
+        sub_13b90((size_t)ret, &http_response);
+
+    if (ret != 0 || http_response.size == 0) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    sub_11040(&socket, 0);
+
+    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
+    if (body == NULL) {
+        fprintf(stderr, "Cannot interpret HTTP response\n");
+        ret = -1;
+        goto cleanup;
+    }
+
+    body += 4;
+    response->size = http_response.size -
+                     (unsigned int)(body - http_response.data);
+    response->data = malloc(response->size);
+    if (response->data == NULL) {
+        perror("recv");
+        ret = -1;
+        goto cleanup;
+    }
+
+    memcpy(response->data, body, response->size);
+
+cleanup:
+    free(http_response.data);
+    if (url != original_url)
+        free(allocated_url);
+    return (int)ret;
+}

tokens used
144,470
```

## Reconstructed C

```c
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct gnutls_x509_crt_int *gnutls_x509_crt_t;

typedef struct {
    unsigned char *data;
    unsigned int size;
} gnutls_datum_t;

typedef struct {
    unsigned char opaque[0x108];
} socket_st;

enum {
    GNUTLS_IA_OCSP_URI = 0x2716,
    GNUTLS_E_UNKNOWN_ALGORITHM = -105,
    SOCKET_FLAG_RAW = 0x28,
    SOCKET_BUFFER_SIZE = 0x1001
};

extern int gnutls_x509_crt_get_authority_info_access(
    gnutls_x509_crt_t crt, unsigned int seq, int what,
    gnutls_datum_t *data, unsigned int *critical);
extern const char *gnutls_strerror(int error);
extern void gnutls_free(void *data);
extern void *memmem(const void *haystack, size_t haystack_len,
                    const void *needle, size_t needle_len);

extern char *sub_13ae0(const char *url, unsigned int *port,
                       const char **path);
extern void sub_13b90(size_t size, gnutls_datum_t *data);
extern void sub_13c00(gnutls_x509_crt_t crt, gnutls_x509_crt_t issuer,
                      gnutls_datum_t *request,
                      const gnutls_datum_t *nonce);
extern int sub_11250(socket_st *socket, const char *host,
                     const char *service, void *credentials,
                     unsigned int flags, const char *description, ...);
extern ssize_t sub_10f90(socket_st *socket, const void *data,
                         unsigned int size);
extern ssize_t sub_10d90(socket_st *socket, void *data,
                         unsigned int size);
extern void sub_11040(socket_st *socket, int graceful);
extern unsigned char sub_94700[];

int sub_13d10(const char *url, gnutls_x509_crt_t crt,
              gnutls_x509_crt_t issuer, gnutls_datum_t *response,
              const gnutls_datum_t *nonce)
{
    gnutls_datum_t uri;
    gnutls_datum_t request;
    gnutls_datum_t http_response = { NULL, 0 };
    socket_st socket;
    const char *original_url = url;
    const char *path;
    char *host;
    char *allocated_url = NULL;
    char port_string[16];
    char request_header[1024];
    unsigned int port;
    unsigned int seq;
    size_t header_size;
    unsigned char *body;
    ssize_t ret;

    signal(SIGPIPE, SIG_IGN);

    if (url == NULL) {
        seq = 0;
        do {
            ret = gnutls_x509_crt_get_authority_info_access(
                crt, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
        } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);

        if (ret < 0) {
            seq = 0;
            do {
                ret = gnutls_x509_crt_get_authority_info_access(
                    issuer, seq++, GNUTLS_IA_OCSP_URI, &uri, NULL);
            } while (ret == GNUTLS_E_UNKNOWN_ALGORITHM);

            if (ret < 0) {
                fprintf(stderr,
                        "*** Cannot find OCSP server URI in certificate: %s\n",
                        gnutls_strerror((int)ret));
                return (int)ret;
            }
        }

        allocated_url = malloc((size_t)uri.size + 1);
        if (allocated_url == NULL)
            return -1;

        memcpy(allocated_url, uri.data, uri.size);
        allocated_url[uri.size] = '\0';
        gnutls_free(uri.data);
        url = allocated_url;
    }

    host = sub_13ae0(url, &port, &path);
    if (port == 0)
        strcpy(port_string, "80");
    else
        snprintf(port_string, sizeof(port_string), "%u", port);

    fprintf(stderr, "Connecting to OCSP server: %s...\n", host);

    sub_13c00(crt, issuer, &request, nonce);
    snprintf(request_header, sizeof(request_header),
             "POST /%s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Accept: */*\r\n"
             "Content-Type: application/ocsp-request\r\n"
             "Content-Length: %u\r\n"
             "Connection: close\r\n\r\n",
             path, host, request.size);
    header_size = strlen(request_header);

    sub_11250(&socket, host, port_string, NULL, SOCKET_FLAG_RAW,
              "Connecting to", NULL, NULL, NULL, NULL);
    sub_10f90(&socket, request_header, (unsigned int)header_size);
    sub_10f90(&socket, request.data, request.size);
    gnutls_free(request.data);
    request.data = NULL;

    while ((ret = sub_10d90(&socket, sub_94700, SOCKET_BUFFER_SIZE)) > 0)
        sub_13b90((size_t)ret, &http_response);

    if (ret != 0 || http_response.size == 0) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }

    sub_11040(&socket, 0);

    body = memmem(http_response.data, http_response.size, "\r\n\r\n", 4);
    if (body == NULL) {
        fprintf(stderr, "Cannot interpret HTTP response\n");
        ret = -1;
        goto cleanup;
    }

    body += 4;
    response->size = http_response.size -
                     (unsigned int)(body - http_response.data);
    response->data = malloc(response->size);
    if (response->data == NULL) {
        perror("recv");
        ret = -1;
        goto cleanup;
    }

    memcpy(response->data, body, response->size);

cleanup:
    free(http_response.data);
    if (url != original_url)
        free(allocated_url);
    return (int)ret;
}

```
