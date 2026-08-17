# codex trace — O2-noinline__e2fsprogs__e2fsck__sub_1f800_0x1f800

- model: gpt-5.6-sol
- binary given to agent: target.bin (original: e2fsck)
- status: ok
- elapsed: 324s

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
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x1f800.
- Name the reconstructed function `sub_1f800` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x1f800: push r15
  0x1f802: mov r15, rdi
  0x1f805: push r14
  0x1f807: mov r14, rsi
  0x1f80a: push r13
  0x1f80c: push r12
  0x1f80e: mov r12, rdx
  0x1f811: push rbp
  0x1f812: push rbx
  0x1f813: sub rsp, 0x48
  0x1f817: mov rcx, qword ptr [rsi + 0x18]
  0x1f81b: mov rax, qword ptr fs:[0x28]
  0x1f824: mov qword ptr [rsp + 0x38], rax
  0x1f829: mov rax, qword ptr [rdi]
  0x1f82c: mov rax, qword ptr [rax + 0x20]
  0x1f830: mov qword ptr [rdx], 0
  0x1f837: mov qword ptr [rdx + 8], 0
  0x1f83f: xor edx, edx
  0x1f841: mov r8d, dword ptr [rax + 0x4c]
  0x1f845: mov qword ptr [rsp + 0x28], rax
  0x1f84a: test r8d, r8d
  0x1f84d: je 0x1f856
  0x1f84f: movzx edx, word ptr [rax + 0x58]
  0x1f853: add edx, -0x80
  0x1f856: movzx esi, word ptr [rcx + 0x80]
  0x1f85d: mov ebx, edx
  0x1f85f: xor edi, edi
  0x1f861: lea rax, [rcx + rsi + 0x80]
  0x1f869: sub ebx, esi
  0x1f86b: mov qword ptr [rsp + 8], rax
  0x1f870: mov esi, ebx
  0x1f872: add rax, 4
  0x1f876: mov qword ptr [rsp + 0x20], rsi
  0x1f87b: mov qword ptr [rsp + 0x10], rax
  0x1f880: call 0x39d30
  0x1f885: mov rbp, rax
  0x1f888: test rax, rax
  0x1f88b: je 0x1fad0
  0x1f891: xor esi, esi
  0x1f893: mov edx, 4
  0x1f898: mov rdi, rax
  0x1f89b: call 0x39e30
  0x1f8a0: test eax, eax
  0x1f8a2: jne 0x1f9c8
  0x1f8a8: sub ebx, 4
  0x1f8ab: cmp ebx, 0xf
  0x1f8ae: jbe 0x1fb70
  0x1f8b4: lea rax, [rsp + 0x30]
  0x1f8b9: mov r13, qword ptr [rsp + 0x10]
  0x1f8be: mov qword ptr [rsp + 0x18], rax
  0x1f8c3: jmp 0x1f93e
  0x1f8c5: nop dword ptr [rax]
  0x1f8c8: mov edx, dword ptr [r13 + 8]
  0x1f8cc: cmp edx, ebx
  0x1f8ce: ja 0x1fb40
  0x1f8d4: movzx esi, word ptr [r13 + 2]
  0x1f8d9: test edx, edx
  0x1f8db: je 0x1f8f7
  0x1f8dd: add edx, 3
  0x1f8e0: add rsi, 4
  0x1f8e4: mov rdi, rbp
  0x1f8e7: and edx, 0xfffffffc
  0x1f8ea: call 0x39e30
  0x1f8ef: test eax, eax
  0x1f8f1: jne 0x1faf0
  0x1f8f7: movzx esi, word ptr [r13 + 2]
  0x1f8fc: mov rdi, r13
  0x1f8ff: add rsi, qword ptr [rsp + 0x10]
  0x1f904: call 0x510b0
  0x1f909: mov edx, dword ptr [r13 + 0xc]
  0x1f90d: test edx, edx
  0x1f90f: je 0x1f919
  0x1f911: cmp edx, eax
  0x1f913: jne 0x1fb58
  0x1f919: mov esi, dword ptr [r13 + 4]
  0x1f91d: test esi, esi
  0x1f91f: jne 0x1f925
  0x1f921: sub ebx, dword ptr [r13 + 8]
  0x1f925: movzx eax, byte ptr [r13]
  0x1f92a: add eax, 0x13

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_1f800`).

```

## Agent transcript (stdout/stderr)

```
Created and syntax-checked [decompiled.c](/tmp/llmdec_codex_6_u0et34/decompiled.c). It contains exactly one function definition, `sub_1f800`.

Reading additional input from stdin...
OpenAI Codex v0.144.1
--------
workdir: /tmp/llmdec_codex_6_u0et34
model: gpt-5.6-sol
provider: openai
approval: never
sandbox: danger-full-access
reasoning effort: high
reasoning summaries: none
session id: 019f87d6-db1d-7ae3-ba59-a483d3f7ceb7
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
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x1f800.
- Name the reconstructed function `sub_1f800` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x1f800: push r15
  0x1f802: mov r15, rdi
  0x1f805: push r14
  0x1f807: mov r14, rsi
  0x1f80a: push r13
  0x1f80c: push r12
  0x1f80e: mov r12, rdx
  0x1f811: push rbp
  0x1f812: push rbx
  0x1f813: sub rsp, 0x48
  0x1f817: mov rcx, qword ptr [rsi + 0x18]
  0x1f81b: mov rax, qword ptr fs:[0x28]
  0x1f824: mov qword ptr [rsp + 0x38], rax
  0x1f829: mov rax, qword ptr [rdi]
  0x1f82c: mov rax, qword ptr [rax + 0x20]
  0x1f830: mov qword ptr [rdx], 0
  0x1f837: mov qword ptr [rdx + 8], 0
  0x1f83f: xor edx, edx
  0x1f841: mov r8d, dword ptr [rax + 0x4c]
  0x1f845: mov qword ptr [rsp + 0x28], rax
  0x1f84a: test r8d, r8d
  0x1f84d: je 0x1f856
  0x1f84f: movzx edx, word ptr [rax + 0x58]
  0x1f853: add edx, -0x80
  0x1f856: movzx esi, word ptr [rcx + 0x80]
  0x1f85d: mov ebx, edx
  0x1f85f: xor edi, edi
  0x1f861: lea rax, [rcx + rsi + 0x80]
  0x1f869: sub ebx, esi
  0x1f86b: mov qword ptr [rsp + 8], rax
  0x1f870: mov esi, ebx
  0x1f872: add rax, 4
  0x1f876: mov qword ptr [rsp + 0x20], rsi
  0x1f87b: mov qword ptr [rsp + 0x10], rax
  0x1f880: call 0x39d30
  0x1f885: mov rbp, rax
  0x1f888: test rax, rax
  0x1f88b: je 0x1fad0
  0x1f891: xor esi, esi
  0x1f893: mov edx, 4
  0x1f898: mov rdi, rax
  0x1f89b: call 0x39e30
  0x1f8a0: test eax, eax
  0x1f8a2: jne 0x1f9c8
  0x1f8a8: sub ebx, 4
  0x1f8ab: cmp ebx, 0xf
  0x1f8ae: jbe 0x1fb70
  0x1f8b4: lea rax, [rsp + 0x30]
  0x1f8b9: mov r13, qword ptr [rsp + 0x10]
  0x1f8be: mov qword ptr [rsp + 0x18], rax
  0x1f8c3: jmp 0x1f93e
  0x1f8c5: nop dword ptr [rax]
  0x1f8c8: mov edx, dword ptr [r13 + 8]
  0x1f8cc: cmp edx, ebx
  0x1f8ce: ja 0x1fb40
  0x1f8d4: movzx esi, word ptr [r13 + 2]
  0x1f8d9: test edx, edx
  0x1f8db: je 0x1f8f7
  0x1f8dd: add edx, 3
  0x1f8e0: add rsi, 4
  0x1f8e4: mov rdi, rbp
  0x1f8e7: and edx, 0xfffffffc
  0x1f8ea: call 0x39e30
  0x1f8ef: test eax, eax
  0x1f8f1: jne 0x1faf0
  0x1f8f7: movzx esi, word ptr [r13 + 2]
  0x1f8fc: mov rdi, r13
  0x1f8ff: add rsi, qword ptr [rsp + 0x10]
  0x1f904: call 0x510b0
  0x1f909: mov edx, dword ptr [r13 + 0xc]
  0x1f90d: test edx, edx
  0x1f90f: je 0x1f919
  0x1f911: cmp edx, eax
  0x1f913: jne 0x1fb58
  0x1f919: mov esi, dword ptr [r13 + 4]
  0x1f91d: test esi, esi
  0x1f91f: jne 0x1f925
  0x1f921: sub ebx, dword ptr [r13 + 8]
  0x1f925: movzx eax, byte ptr [r13]
  0x1f92a: add eax, 0x13

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_1f800`).

codex
I’ll inspect the full function, its direct callees/symbol context, and relevant constants using only the permitted binary tools, then write and sanity-check the single C definition.
exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x1f800 --stop-address=0x1fc80 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001f800 <check_backup_super_block@@Base+0x18c0>:
   1f800:	41 57                	push   r15
   1f802:	49 89 ff             	mov    r15,rdi
   1f805:	41 56                	push   r14
   1f807:	49 89 f6             	mov    r14,rsi
   1f80a:	41 55                	push   r13
   1f80c:	41 54                	push   r12
   1f80e:	49 89 d4             	mov    r12,rdx
   1f811:	55                   	push   rbp
   1f812:	53                   	push   rbx
   1f813:	48 83 ec 48          	sub    rsp,0x48
   1f817:	48 8b 4e 18          	mov    rcx,QWORD PTR [rsi+0x18]
   1f81b:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f822:	00 00 
   1f824:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
   1f829:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   1f82c:	48 8b 40 20          	mov    rax,QWORD PTR [rax+0x20]
   1f830:	48 c7 02 00 00 00 00 	mov    QWORD PTR [rdx],0x0
   1f837:	48 c7 42 08 00 00 00 	mov    QWORD PTR [rdx+0x8],0x0
   1f83e:	00 
   1f83f:	31 d2                	xor    edx,edx
   1f841:	44 8b 40 4c          	mov    r8d,DWORD PTR [rax+0x4c]
   1f845:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   1f84a:	45 85 c0             	test   r8d,r8d
   1f84d:	74 07                	je     1f856 <check_backup_super_block@@Base+0x1916>
   1f84f:	0f b7 50 58          	movzx  edx,WORD PTR [rax+0x58]
   1f853:	83 c2 80             	add    edx,0xffffff80
   1f856:	0f b7 b1 80 00 00 00 	movzx  esi,WORD PTR [rcx+0x80]
   1f85d:	89 d3                	mov    ebx,edx
   1f85f:	31 ff                	xor    edi,edi
   1f861:	48 8d 84 31 80 00 00 	lea    rax,[rcx+rsi*1+0x80]
   1f868:	00 
   1f869:	29 f3                	sub    ebx,esi
   1f86b:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1f870:	89 de                	mov    esi,ebx
   1f872:	48 83 c0 04          	add    rax,0x4
   1f876:	48 89 74 24 20       	mov    QWORD PTR [rsp+0x20],rsi
   1f87b:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
   1f880:	e8 ab a4 01 00       	call   39d30 <region_create@@Base>
   1f885:	48 89 c5             	mov    rbp,rax
   1f888:	48 85 c0             	test   rax,rax
   1f88b:	0f 84 3f 02 00 00    	je     1fad0 <check_backup_super_block@@Base+0x1b90>
   1f891:	31 f6                	xor    esi,esi
   1f893:	ba 04 00 00 00       	mov    edx,0x4
   1f898:	48 89 c7             	mov    rdi,rax
   1f89b:	e8 90 a5 01 00       	call   39e30 <region_allocate@@Base>
   1f8a0:	85 c0                	test   eax,eax
   1f8a2:	0f 85 20 01 00 00    	jne    1f9c8 <check_backup_super_block@@Base+0x1a88>
   1f8a8:	83 eb 04             	sub    ebx,0x4
   1f8ab:	83 fb 0f             	cmp    ebx,0xf
   1f8ae:	0f 86 bc 02 00 00    	jbe    1fb70 <check_backup_super_block@@Base+0x1c30>
   1f8b4:	48 8d 44 24 30       	lea    rax,[rsp+0x30]
   1f8b9:	4c 8b 6c 24 10       	mov    r13,QWORD PTR [rsp+0x10]
   1f8be:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1f8c3:	eb 79                	jmp    1f93e <check_backup_super_block@@Base+0x19fe>
   1f8c5:	0f 1f 00             	nop    DWORD PTR [rax]
   1f8c8:	41 8b 55 08          	mov    edx,DWORD PTR [r13+0x8]
   1f8cc:	39 da                	cmp    edx,ebx
   1f8ce:	0f 87 6c 02 00 00    	ja     1fb40 <check_backup_super_block@@Base+0x1c00>
   1f8d4:	41 0f b7 75 02       	movzx  esi,WORD PTR [r13+0x2]
   1f8d9:	85 d2                	test   edx,edx
   1f8db:	74 1a                	je     1f8f7 <check_backup_super_block@@Base+0x19b7>
   1f8dd:	83 c2 03             	add    edx,0x3
   1f8e0:	48 83 c6 04          	add    rsi,0x4
   1f8e4:	48 89 ef             	mov    rdi,rbp
   1f8e7:	83 e2 fc             	and    edx,0xfffffffc
   1f8ea:	e8 41 a5 01 00       	call   39e30 <region_allocate@@Base>
   1f8ef:	85 c0                	test   eax,eax
   1f8f1:	0f 85 f9 01 00 00    	jne    1faf0 <check_backup_super_block@@Base+0x1bb0>
   1f8f7:	41 0f b7 75 02       	movzx  esi,WORD PTR [r13+0x2]
   1f8fc:	4c 89 ef             	mov    rdi,r13
   1f8ff:	48 03 74 24 10       	add    rsi,QWORD PTR [rsp+0x10]
   1f904:	e8 a7 17 03 00       	call   510b0 <ext2fs_ext_attr_hash_entry@@Base>
   1f909:	41 8b 55 0c          	mov    edx,DWORD PTR [r13+0xc]
   1f90d:	85 d2                	test   edx,edx
   1f90f:	74 08                	je     1f919 <check_backup_super_block@@Base+0x19d9>
   1f911:	39 c2                	cmp    edx,eax
   1f913:	0f 85 3f 02 00 00    	jne    1fb58 <check_backup_super_block@@Base+0x1c18>
   1f919:	41 8b 75 04          	mov    esi,DWORD PTR [r13+0x4]
   1f91d:	85 f6                	test   esi,esi
   1f91f:	75 04                	jne    1f925 <check_backup_super_block@@Base+0x19e5>
   1f921:	41 2b 5d 08          	sub    ebx,DWORD PTR [r13+0x8]
   1f925:	41 0f b6 45 00       	movzx  eax,BYTE PTR [r13+0x0]
   1f92a:	83 c0 13             	add    eax,0x13
   1f92d:	25 fc 01 00 00       	and    eax,0x1fc
   1f932:	49 01 c5             	add    r13,rax
   1f935:	83 fb 0f             	cmp    ebx,0xf
   1f938:	0f 86 1a 01 00 00    	jbe    1fa58 <check_backup_super_block@@Base+0x1b18>
   1f93e:	41 8b 4d 00          	mov    ecx,DWORD PTR [r13+0x0]
   1f942:	4c 89 ee             	mov    rsi,r13
   1f945:	48 2b 74 24 08       	sub    rsi,QWORD PTR [rsp+0x8]
   1f94a:	85 c9                	test   ecx,ecx
   1f94c:	0f 84 0e 01 00 00    	je     1fa60 <check_backup_super_block@@Base+0x1b20>
   1f952:	41 0f b6 55 00       	movzx  edx,BYTE PTR [r13+0x0]
   1f957:	48 89 ef             	mov    rdi,rbp
   1f95a:	83 c2 13             	add    edx,0x13
   1f95d:	83 e2 fc             	and    edx,0xfffffffc
   1f960:	e8 cb a4 01 00       	call   39e30 <region_allocate@@Base>
   1f965:	85 c0                	test   eax,eax
   1f967:	0f 85 83 01 00 00    	jne    1faf0 <check_backup_super_block@@Base+0x1bb0>
   1f96d:	41 0f b6 45 00       	movzx  eax,BYTE PTR [r13+0x0]
   1f972:	83 eb 10             	sub    ebx,0x10
   1f975:	48 89 c2             	mov    rdx,rax
   1f978:	83 c0 03             	add    eax,0x3
   1f97b:	83 e0 fc             	and    eax,0xfffffffc
   1f97e:	39 d8                	cmp    eax,ebx
   1f980:	0f 87 8a 01 00 00    	ja     1fb10 <check_backup_super_block@@Base+0x1bd0>
   1f986:	41 8b 7d 04          	mov    edi,DWORD PTR [r13+0x4]
   1f98a:	29 c3                	sub    ebx,eax
   1f98c:	85 ff                	test   edi,edi
   1f98e:	0f 84 34 ff ff ff    	je     1f8c8 <check_backup_super_block@@Base+0x1988>
   1f994:	48 8b 4c 24 18       	mov    rcx,QWORD PTR [rsp+0x18]
   1f999:	4c 89 f2             	mov    rdx,r14
   1f99c:	4c 89 ee             	mov    rsi,r13
   1f99f:	4c 89 ff             	mov    rdi,r15
   1f9a2:	e8 59 fc ff ff       	call   1f600 <check_backup_super_block@@Base+0x16c0>
   1f9a7:	85 c0                	test   eax,eax
   1f9a9:	0f 85 46 01 00 00    	jne    1faf5 <check_backup_super_block@@Base+0x1bb5>
   1f9af:	48 8b 44 24 30       	mov    rax,QWORD PTR [rsp+0x30]
   1f9b4:	49 83 44 24 08 01    	add    QWORD PTR [r12+0x8],0x1
   1f9ba:	49 01 04 24          	add    QWORD PTR [r12],rax
   1f9be:	e9 56 ff ff ff       	jmp    1f919 <check_backup_super_block@@Base+0x19d9>
   1f9c3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f9c8:	48 89 ef             	mov    rdi,rbp
   1f9cb:	e8 d0 a3 01 00       	call   39da0 <region_free@@Base>
   1f9d0:	b8 69 00 01 00       	mov    eax,0x10069
   1f9d5:	4c 89 f2             	mov    rdx,r14
   1f9d8:	89 c6                	mov    esi,eax
   1f9da:	4c 89 ff             	mov    rdi,r15
   1f9dd:	e8 0e 78 01 00       	call   371f0 <fix_problem@@Base>
   1f9e2:	85 c0                	test   eax,eax
   1f9e4:	0f 84 93 00 00 00    	je     1fa7d <check_backup_super_block@@Base+0x1b3d>
   1f9ea:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   1f9ef:	b9 80 00 00 00       	mov    ecx,0x80
   1f9f4:	c7 00 00 00 00 00    	mov    DWORD PTR [rax],0x0
   1f9fa:	48 8b 44 24 28       	mov    rax,QWORD PTR [rsp+0x28]
   1f9ff:	8b 50 4c             	mov    edx,DWORD PTR [rax+0x4c]
   1fa02:	85 d2                	test   edx,edx
   1fa04:	0f 85 b6 00 00 00    	jne    1fac0 <check_backup_super_block@@Base+0x1b80>
   1fa0a:	49 8b 56 18          	mov    rdx,QWORD PTR [r14+0x18]
   1fa0e:	41 8b 76 08          	mov    esi,DWORD PTR [r14+0x8]
   1fa12:	4c 8d 05 67 95 05 00 	lea    r8,[rip+0x59567]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1fa19:	4c 89 ff             	mov    rdi,r15
   1fa1c:	e8 5f 55 01 00       	call   34f80 <e2fsck_write_inode_full@@Base>
   1fa21:	49 c7 04 24 00 00 00 	mov    QWORD PTR [r12],0x0
   1fa28:	00 
   1fa29:	49 c7 44 24 08 00 00 	mov    QWORD PTR [r12+0x8],0x0
   1fa30:	00 00 
   1fa32:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
   1fa37:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1fa3e:	00 00 
   1fa40:	0f 85 34 01 00 00    	jne    1fb7a <check_backup_super_block@@Base+0x1c3a>
   1fa46:	48 83 c4 48          	add    rsp,0x48
   1fa4a:	5b                   	pop    rbx
   1fa4b:	5d                   	pop    rbp
   1fa4c:	41 5c                	pop    r12
   1fa4e:	41 5d                	pop    r13
   1fa50:	41 5e                	pop    r14
   1fa52:	41 5f                	pop    r15
   1fa54:	c3                   	ret    
   1fa55:	0f 1f 00             	nop    DWORD PTR [rax]
   1fa58:	4c 89 ee             	mov    rsi,r13
   1fa5b:	48 2b 74 24 08       	sub    rsi,QWORD PTR [rsp+0x8]
   1fa60:	48 89 ef             	mov    rdi,rbp
   1fa63:	ba 04 00 00 00       	mov    edx,0x4
   1fa68:	e8 c3 a3 01 00       	call   39e30 <region_allocate@@Base>
   1fa6d:	48 89 ef             	mov    rdi,rbp
   1fa70:	85 c0                	test   eax,eax
   1fa72:	0f 85 b8 00 00 00    	jne    1fb30 <check_backup_super_block@@Base+0x1bf0>
   1fa78:	e8 23 a3 01 00       	call   39da0 <region_free@@Base>
   1fa7d:	48 8b 44 24 38       	mov    rax,QWORD PTR [rsp+0x38]
   1fa82:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1fa89:	00 00 
   1fa8b:	0f 85 e9 00 00 00    	jne    1fb7a <check_backup_super_block@@Base+0x1c3a>
   1fa91:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   1fa96:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
   1fa9b:	4c 89 f6             	mov    rsi,r14
   1fa9e:	4c 89 ff             	mov    rdi,r15
   1faa1:	48 03 4c 24 20       	add    rcx,QWORD PTR [rsp+0x20]
   1faa6:	48 83 c4 48          	add    rsp,0x48
   1faaa:	5b                   	pop    rbx
   1faab:	5d                   	pop    rbp
   1faac:	41 5c                	pop    r12
   1faae:	41 5d                	pop    r13
   1fab0:	41 5e                	pop    r14
   1fab2:	41 5f                	pop    r15
   1fab4:	e9 17 f2 ff ff       	jmp    1ecd0 <check_backup_super_block@@Base+0xd90>
   1fab9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1fac0:	0f b7 48 58          	movzx  ecx,WORD PTR [rax+0x58]
   1fac4:	e9 41 ff ff ff       	jmp    1fa0a <check_backup_super_block@@Base+0x1aca>
   1fac9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1fad0:	4c 89 f2             	mov    rdx,r14
   1fad3:	be 3f 00 01 00       	mov    esi,0x1003f
   1fad8:	4c 89 ff             	mov    rdi,r15
   1fadb:	e8 10 77 01 00       	call   371f0 <fix_problem@@Base>
   1fae0:	41 83 4f 48 01       	or     DWORD PTR [r15+0x48],0x1
   1fae5:	e9 48 ff ff ff       	jmp    1fa32 <check_backup_super_block@@Base+0x1af2>
   1faea:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1faf0:	b8 69 00 01 00       	mov    eax,0x10069
   1faf5:	48 89 ef             	mov    rdi,rbp
   1faf8:	89 44 24 18          	mov    DWORD PTR [rsp+0x18],eax
   1fafc:	e8 9f a2 01 00       	call   39da0 <region_free@@Base>
   1fb01:	8b 44 24 18          	mov    eax,DWORD PTR [rsp+0x18]
   1fb05:	e9 cb fe ff ff       	jmp    1f9d5 <check_backup_super_block@@Base+0x1a95>
   1fb0a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1fb10:	49 89 56 50          	mov    QWORD PTR [r14+0x50],rdx
   1fb14:	48 89 ef             	mov    rdi,rbp
   1fb17:	e8 84 a2 01 00       	call   39da0 <region_free@@Base>
   1fb1c:	b8 50 00 01 00       	mov    eax,0x10050
   1fb21:	e9 af fe ff ff       	jmp    1f9d5 <check_backup_super_block@@Base+0x1a95>
   1fb26:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1fb2d:	00 00 00 
   1fb30:	e8 6b a2 01 00       	call   39da0 <region_free@@Base>
   1fb35:	b8 69 00 01 00       	mov    eax,0x10069
   1fb3a:	e9 96 fe ff ff       	jmp    1f9d5 <check_backup_super_block@@Base+0x1a95>
   1fb3f:	90                   	nop
   1fb40:	89 d0                	mov    eax,edx
   1fb42:	48 89 ef             	mov    rdi,rbp
   1fb45:	49 89 46 50          	mov    QWORD PTR [r14+0x50],rax
   1fb49:	e8 52 a2 01 00       	call   39da0 <region_free@@Base>
   1fb4e:	b8 53 00 01 00       	mov    eax,0x10053
   1fb53:	e9 7d fe ff ff       	jmp    1f9d5 <check_backup_super_block@@Base+0x1a95>
   1fb58:	89 d0                	mov    eax,edx
   1fb5a:	48 89 ef             	mov    rdi,rbp
   1fb5d:	49 89 46 50          	mov    QWORD PTR [r14+0x50],rax
   1fb61:	e8 3a a2 01 00       	call   39da0 <region_free@@Base>
   1fb66:	b8 54 00 01 00       	mov    eax,0x10054
   1fb6b:	e9 65 fe ff ff       	jmp    1f9d5 <check_backup_super_block@@Base+0x1a95>
   1fb70:	be 04 00 00 00       	mov    esi,0x4
   1fb75:	e9 e6 fe ff ff       	jmp    1fa60 <check_backup_super_block@@Base+0x1b20>
   1fb7a:	e8 81 62 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1fb7f:	90                   	nop
   1fb80:	41 57                	push   r15
   1fb82:	41 56                	push   r14
   1fb84:	41 55                	push   r13
   1fb86:	41 54                	push   r12
   1fb88:	55                   	push   rbp
   1fb89:	53                   	push   rbx
   1fb8a:	48 83 ec 08          	sub    rsp,0x8
   1fb8e:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   1fb91:	4c 8b 6e 18          	mov    r13,QWORD PTR [rsi+0x18]
   1fb95:	4c 8b 70 20          	mov    r14,QWORD PTR [rax+0x20]
   1fb99:	48 c7 02 00 00 00 00 	mov    QWORD PTR [rdx],0x0
   1fba0:	48 c7 42 08 00 00 00 	mov    QWORD PTR [rdx+0x8],0x0
   1fba7:	00 
   1fba8:	41 8b 4e 4c          	mov    ecx,DWORD PTR [r14+0x4c]
   1fbac:	85 c9                	test   ecx,ecx
   1fbae:	0f 84 88 01 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbb4:	49 89 d4             	mov    r12,rdx
   1fbb7:	41 0f b7 56 58       	movzx  edx,WORD PTR [r14+0x58]
   1fbbc:	66 81 fa 80 00       	cmp    dx,0x80
   1fbc1:	0f 84 75 01 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbc7:	41 0f b7 85 80 00 00 	movzx  eax,WORD PTR [r13+0x80]
   1fbce:	00 
   1fbcf:	48 89 fd             	mov    rbp,rdi
   1fbd2:	48 89 f3             	mov    rbx,rsi
   1fbd5:	44 8d 7a 80          	lea    r15d,[rdx-0x80]
   1fbd9:	66 85 c0             	test   ax,ax
   1fbdc:	0f 85 3e 01 00 00    	jne    1fd20 <check_backup_super_block@@Base+0x1de0>
   1fbe2:	49 63 d7             	movsxd rdx,r15d
   1fbe5:	48 83 ea 04          	sub    rdx,0x4
   1fbe9:	48 39 d0             	cmp    rax,rdx
   1fbec:	0f 83 4a 01 00 00    	jae    1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbf2:	41 81 bc 05 80 00 00 	cmp    DWORD PTR [r13+rax*1+0x80],0xea020000
   1fbf9:	00 00 00 02 ea 
   1fbfe:	0f 84 bc 01 00 00    	je     1fdc0 <check_backup_super_block@@Base+0x1e80>
   1fc04:	48 b8 ff ff ff ff 01 	movabs rax,0x1ffffffff
   1fc0b:	00 00 00 
   1fc0e:	48 39 85 48 03 00 00 	cmp    QWORD PTR [rbp+0x348],rax
   1fc15:	0f 8f 21 01 00 00    	jg     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fc1b:	41 8b b5 8c 00 00 00 	mov    esi,DWORD PTR [r13+0x8c]
   1fc22:	41 8b 7d 08          	mov    edi,DWORD PTR [r13+0x8]
   1fc26:	e8 45 e5 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc2b:	85 c0                	test   eax,eax
   1fc2d:	75 18                	jne    1fc47 <check_backup_super_block@@Base+0x1d07>
   1fc2f:	41 8b b5 84 00 00 00 	mov    esi,DWORD PTR [r13+0x84]
   1fc36:	41 8b 7d 0c          	mov    edi,DWORD PTR [r13+0xc]
   1fc3a:	e8 31 e5 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc3f:	85 c0                	test   eax,eax
   1fc41:	0f 84 91 01 00 00    	je     1fdd8 <check_backup_super_block@@Base+0x1e98>
   1fc47:	48 89 da             	mov    rdx,rbx
   1fc4a:	be 82 00 01 00       	mov    esi,0x10082
   1fc4f:	48 89 ef             	mov    rdi,rbp
   1fc52:	e8 99 75 01 00       	call   371f0 <fix_problem@@Base>
   1fc57:	85 c0                	test   eax,eax
   1fc59:	0f 84 dd 00 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fc5f:	41 8b 95 8c 00 00 00 	mov    edx,DWORD PTR [r13+0x8c]
   1fc66:	41 8b 7d 08          	mov    edi,DWORD PTR [r13+0x8]
   1fc6a:	89 d6                	mov    esi,edx
   1fc6c:	e8 ff e4 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc71:	85 c0                	test   eax,eax
   1fc73:	74 0a                	je     1fc7f <check_backup_super_block@@Base+0x1d3f>
   1fc75:	83 e2 fc             	and    edx,0xfffffffc
   1fc78:	41 89 95 8c 00 00 00 	mov    DWORD PTR [r13+0x8c],edx
   1fc7f:	41                   	rex.B

exec
/bin/bash -lc 'file ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
./target.bin: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=3ab124450289058df9755ec817ad3dca6c742179, for GNU/Linux 3.2.0, stripped

exec
/bin/bash -lc 'readelf -Ws ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

Symbol table '.dynsym' contains 1055 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __ctype_toupper_loc@GLIBC_2.3 (2)
     2: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __strcat_chk@GLIBC_2.3.4 (3)
     3: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getenv@GLIBC_2.2.5 (4)
     4: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND utime@GLIBC_2.2.5 (4)
     5: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __snprintf_chk@GLIBC_2.3.4 (3)
     6: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND free@GLIBC_2.2.5 (4)
     7: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND endmntent@GLIBC_2.2.5 (4)
     8: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcasecmp@GLIBC_2.2.5 (4)
     9: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND backtrace_symbols_fd@GLIBC_2.2.5 (4)
    10: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND localtime@GLIBC_2.2.5 (4)
    11: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __vfprintf_chk@GLIBC_2.3.4 (3)
    12: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.34 (5)
    13: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND abort@GLIBC_2.2.5 (4)
    14: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __errno_location@GLIBC_2.2.5 (4)
    15: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND srandom@GLIBC_2.2.5 (4)
    16: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND unlink@GLIBC_2.2.5 (4)
    17: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND uuid_unparse@UUID_1.0 (6)
    18: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncpy@GLIBC_2.2.5 (4)
    19: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncmp@GLIBC_2.2.5 (4)
    20: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTable
    21: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND localtime_r@GLIBC_2.2.5 (4)
    22: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_probe_lookup_value@BLKID_2.15 (7)
    23: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcpy@GLIBC_2.2.5 (4)
    24: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __isoc99_fscanf@GLIBC_2.7 (8)
    25: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND secure_getenv@GLIBC_2.17 (9)
    26: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_new_probe_from_filename@BLKID_2.17 (10)
    27: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND puts@GLIBC_2.2.5 (4)
    28: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND qsort@GLIBC_2.2.5 (4)
    29: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND isatty@GLIBC_2.2.5 (4)
    30: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sigaction@GLIBC_2.2.5 (4)
    31: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtod@GLIBC_2.2.5 (4)
    32: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_probe_enable_superblocks@BLKID_2.17 (10)
    33: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __vprintf_chk@GLIBC_2.3.4 (3)
    34: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fcntl@GLIBC_2.2.5 (4)
    35: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND write@GLIBC_2.2.5 (4)
    36: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_probe_enable_partitions@BLKID_2.17 (10)
    37: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpid@GLIBC_2.2.5 (4)
    38: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND textdomain@GLIBC_2.2.5 (4)
    39: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __open_2@GLIBC_2.7 (8)
    40: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fclose@GLIBC_2.2.5 (4)
    41: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND opendir@GLIBC_2.2.5 (4)
    42: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ctime@GLIBC_2.2.5 (4)
    43: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND bindtextdomain@GLIBC_2.2.5 (4)
    44: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_put_cache@BLKID_1.0 (11)
    45: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND msync@GLIBC_2.2.5 (4)
    46: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dcgettext@GLIBC_2.2.5 (4)
    47: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strlen@GLIBC_2.2.5 (4)
    48: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fallocate64@GLIBC_2.10 (12)
    49: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND backtrace@GLIBC_2.2.5 (4)
    50: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpwuid_r@GLIBC_2.2.5 (4)
    51: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (13)
    52: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getuid@GLIBC_2.2.5 (4)
    53: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND mmap@GLIBC_2.2.5 (4)
    54: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND asctime@GLIBC_2.2.5 (4)
    55: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gettext@GLIBC_2.2.5 (4)
    56: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND stat64@GLIBC_2.33 (14)
    57: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strchr@GLIBC_2.2.5 (4)
    58: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_get_tag_value@BLKID_1.0 (11)
    59: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_mutex_destroy@GLIBC_2.2.5 (4)
    60: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pclose@GLIBC_2.2.5 (4)
    61: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strrchr@GLIBC_2.2.5 (4)
    62: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ftruncate@GLIBC_2.2.5 (4)
    63: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND mallinfo@GLIBC_2.2.5 (4)
    64: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND uname@GLIBC_2.2.5 (4)
    65: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gmtime_r@GLIBC_2.2.5 (4)
    66: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dup@GLIBC_2.2.5 (4)
    67: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND lseek@GLIBC_2.2.5 (4)
    68: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setrlimit64@GLIBC_2.2.5 (4)
    69: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gettimeofday@GLIBC_2.2.5 (4)
    70: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fputs@GLIBC_2.2.5 (4)
    71: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memset@GLIBC_2.2.5 (4)
    72: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND geteuid@GLIBC_2.2.5 (4)
    73: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ioctl@GLIBC_2.2.5 (4)
    74: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strnlen@GLIBC_2.2.5 (4)
    75: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND close@GLIBC_2.2.5 (4)
    76: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pipe@GLIBC_2.2.5 (4)
    77: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND closedir@GLIBC_2.2.5 (4)
    78: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fputc@GLIBC_2.2.5 (4)
    79: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND read@GLIBC_2.2.5 (4)
    80: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcmp@GLIBC_2.2.5 (4)
    81: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_attr_init@GLIBC_2.2.5 (4)
    82: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sbrk@GLIBC_2.2.5 (4)
    83: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fgets@GLIBC_2.2.5 (4)
    84: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _setjmp@GLIBC_2.2.5 (4)
    85: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtoull@GLIBC_2.2.5 (4)
    86: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND calloc@GLIBC_2.2.5 (4)
    87: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND putenv@GLIBC_2.2.5 (4)
    88: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_get_devname@BLKID_1.0 (11)
    89: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcmp@GLIBC_2.2.5 (4)
    90: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_do_fullprobe@BLKID_2.17 (10)
    91: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __memcpy_chk@GLIBC_2.3.4 (3)
    92: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND feof@GLIBC_2.2.5 (4)
    93: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    94: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND umask@GLIBC_2.2.5 (4)
    95: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND stat@GLIBC_2.33 (14)
    96: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtol@GLIBC_2.2.5 (4)
    97: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcpy@GLIBC_2.14 (15)
    98: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND prctl@GLIBC_2.2.5 (4)
    99: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND tzset@GLIBC_2.2.5 (4)
   100: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __xpg_basename@GLIBC_2.2.5 (4)
   101: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND time@GLIBC_2.2.5 (4)
   102: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fileno@GLIBC_2.2.5 (4)
   103: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getgid@GLIBC_2.2.5 (4)
   104: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND select@GLIBC_2.2.5 (4)
   105: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pwrite64@GLIBC_2.2.5 (4)
   106: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND readdir@GLIBC_2.2.5 (4)
   107: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getrlimit64@GLIBC_2.2.5 (4)
   108: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND random@GLIBC_2.2.5 (4)
   109: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_mutex_unlock@GLIBC_2.2.5 (4)
   110: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __open64_2@GLIBC_2.7 (8)
   111: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND malloc@GLIBC_2.2.5 (4)
   112: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncasecmp@GLIBC_2.2.5 (4)
   113: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fflush@GLIBC_2.2.5 (4)
   114: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getmntent@GLIBC_2.2.5 (4)
   115: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setmntent@GLIBC_2.2.5 (4)
   116: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __isoc99_sscanf@GLIBC_2.7 (8)
   117: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND uuid_is_null@UUID_1.0 (6)
   118: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getegid@GLIBC_2.2.5 (4)
   119: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND daemon@GLIBC_2.2.5 (4)
   120: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND mkstemp@GLIBC_2.2.5 (4)
   121: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND uuid_generate@UUID_1.0 (6)
   122: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gnu_dev_major@GLIBC_2.3.3 (16)
   123: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND realloc@GLIBC_2.2.5 (4)
   124: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __strcpy_chk@GLIBC_2.3.4 (3)
   125: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fdopen@GLIBC_2.2.5 (4)
   126: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND munmap@GLIBC_2.2.5 (4)
   127: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setlocale@GLIBC_2.2.5 (4)
   128: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ftruncate64@GLIBC_2.2.5 (4)
   129: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pwrite@GLIBC_2.2.5 (4)
   130: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __printf_chk@GLIBC_2.3.4 (3)
   131: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setvbuf@GLIBC_2.2.5 (4)
   132: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_create@GLIBC_2.34 (5)
   133: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __longjmp_chk@GLIBC_2.11 (17)
   134: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND open64@GLIBC_2.2.5 (4)
   135: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fcntl64@GLIBC_2.28 (18)
   136: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_free_probe@BLKID_2.15 (7)
   137: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memmove@GLIBC_2.2.5 (4)
   138: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fsync@GLIBC_2.2.5 (4)
   139: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pread64@GLIBC_2.2.5 (4)
   140: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND tcgetattr@GLIBC_2.2.5 (4)
   141: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND tcsetattr@GLIBC_2.2.5 (4)
   142: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND open@GLIBC_2.2.5 (4)
   143: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND access@GLIBC_2.2.5 (4)
   144: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND popen@GLIBC_2.2.5 (4)
   145: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fopen@GLIBC_2.2.5 (4)
   146: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dcngettext@GLIBC_2.2.5 (4)
   147: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getrusage@GLIBC_2.2.5 (4)
   148: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND perror@GLIBC_2.2.5 (4)
   149: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sysconf@GLIBC_2.2.5 (4)
   150: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getopt@GLIBC_2.2.5 (4)
   151: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtoul@GLIBC_2.2.5 (4)
   152: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_attr_destroy@GLIBC_2.2.5 (4)
   153: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __cxa_atexit@GLIBC_2.2.5 (4)
   154: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND atoi@GLIBC_2.2.5 (4)
   155: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_devno_to_devname@BLKID_1.0 (11)
   156: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pread@GLIBC_2.2.5 (4)
   157: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcat@GLIBC_2.2.5 (4)
   158: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gethostname@GLIBC_2.2.5 (4)
   159: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND exit@GLIBC_2.2.5 (4)
   160: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND lseek64@GLIBC_2.2.5 (4)
   161: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __fprintf_chk@GLIBC_2.3.4 (3)
   162: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fstat64@GLIBC_2.33 (14)
   163: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND posix_fadvise64@GLIBC_2.2.5 (4)
   164: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND posix_memalign@GLIBC_2.2.5 (4)
   165: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
   166: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_join@GLIBC_2.34 (5)
   167: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strdup@GLIBC_2.2.5 (4)
   168: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strerror@GLIBC_2.2.5 (4)
   169: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND blkid_get_cache@BLKID_1.0 (11)
   170: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND hasmntopt@GLIBC_2.2.5 (4)
   171: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sleep@GLIBC_2.2.5 (4)
   172: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_mutex_init@GLIBC_2.2.5 (4)
   173: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fstat@GLIBC_2.33 (14)
   174: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fork@GLIBC_2.2.5 (4)
   175: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pthread_mutex_lock@GLIBC_2.2.5 (4)
   176: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __ctype_b_loc@GLIBC_2.3 (2)
   177: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __sprintf_chk@GLIBC_2.3.4 (3)
   178: 0000000000049960    21 FUNC    GLOBAL DEFAULT   16 ext2fs_set_inode_bitmap_range
   179: 000000000001b210    78 FUNC    GLOBAL DEFAULT   16 e2fsck_clear_progbar
   180: 000000000005cde0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_test_ib_dirty
   181: 00000000000311d0    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_revoke
   182: 0000000000031330    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_csum2
   183: 00000000000313b0    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_csum3
   184: 000000000005cc20    35 FUNC    GLOBAL DEFAULT   16 ext2fs_get_array
   185: 0000000000045d40   231 FUNC    GLOBAL DEFAULT   16 qtree_scan_dquots
   186: 0000000000047e20    78 FUNC    GLOBAL DEFAULT   16 ext2fs_get_free_blocks
   187: 000000000004f220   101 FUNC    GLOBAL DEFAULT   16 ext2fs_copy_dblist
   188: 000000000005c810     9 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_block_bitmap
   189: 00000000000495d0   228 FUNC    GLOBAL DEFAULT   16 ext2fs_allocate_block_bitmap
   190: 000000000005cf20     9 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_set_file_type
   191: 0000000000072850   241 FUNC    GLOBAL DEFAULT   16 ext2fs_add_exit_fn
   192: 000000000002ca70  1736 FUNC    GLOBAL DEFAULT   16 e2fsck_get_lost_and_found
   193: 0000000000061810   140 FUNC    GLOBAL DEFAULT   16 ext2fs_lookup
   194: 000000000005eab0  1060 FUNC    GLOBAL DEFAULT   16 ext2fs_get_next_inode_full
   195: 000000000004f4e0    55 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_get_last2
   196: 0000000000048760   285 FUNC    GLOBAL DEFAULT   16 ext2fs_block_alloc_stats2
   197: 0000000000034a70   209 FUNC    GLOBAL DEFAULT   16 init_resource_track
   198: 0000000000057ac0   117 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_generic_bitmap
   199: 000000000003fc00    95 FUNC    GLOBAL DEFAULT   16 find_encryption_policy
   200: 00000000000349d0   157 FUNC    GLOBAL DEFAULT   16 preenhalt
   201: 000000000001cdb0  4489 FUNC    GLOBAL DEFAULT   16 check_super_block
   202: 000000000005a3e0   159 FUNC    GLOBAL DEFAULT   16 ext2fs_iblk_sub_blocks
   203: 000000000005f340    12 FUNC    GLOBAL DEFAULT   16 ext2fs_read_inode_full
   204: 000000000005fb60    54 FUNC    GLOBAL DEFAULT   16 io_channel_write_byte
   205: 000000000005e510   134 FUNC    GLOBAL DEFAULT   16 ext2fs_free_inode_cache
   206: 0000000000048ee0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_del
   207: 000000000005d5e0   149 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_size
   208: 00000000000767b0   160 FUNC    GLOBAL DEFAULT   16 e2p_feature_to_string
   209: 0000000000043280    16 FUNC    GLOBAL DEFAULT   16 initialize_prof_error_table
   210: 000000000005a480   122 FUNC    GLOBAL DEFAULT   16 ext2fs_iblk_set
   211: 00000000000592f0   295 FUNC    GLOBAL DEFAULT   16 ext2fs_convert_subcluster_bitmap
   212: 000000000005ace0   364 FUNC    GLOBAL DEFAULT   16 ext2fs_create_icount2
   213: 000000000004f560    14 FUNC    GLOBAL DEFAULT   16 ext2fs_set_dir_block
   214: 00000000000431f0   129 FUNC    GLOBAL DEFAULT   16 initialize_prof_error_table_r
   215: 000000000005c890     6 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_inode_bitmap
   216: 0000000000056200   434 FUNC    GLOBAL DEFAULT   16 ext2fs_file_open2
   217: 0000000000047ac0    76 FUNC    GLOBAL DEFAULT   16 ext2fs_new_block
   218: 000000000004b9b0    74 FUNC    GLOBAL DEFAULT   16 ext2fs_block_iterate2
   219: 000000000004b1d0  2005 FUNC    GLOBAL DEFAULT   16 ext2fs_block_iterate3
   220: 0000000000065980    69 FUNC    GLOBAL DEFAULT   16 ext2fs_read_bb_FILE
   221: 00000000000402f0   392 FUNC    GLOBAL DEFAULT   16 quota_write_inode
   222: 0000000000037160    39 FUNC    GLOBAL DEFAULT   16 set_latch_flags
   223: 0000000000039d30   105 FUNC    GLOBAL DEFAULT   16 region_create
   224: 00000000000312f0    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_csum2
   225: 0000000000034b50   836 FUNC    GLOBAL DEFAULT   16 print_resource_track
   226: 000000000005c800     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_block_bitmap
   227: 0000000000031370    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_csum3
   228: 0000000000042790    19 FUNC    GLOBAL DEFAULT   16 profile_set_syntax_err_cb
   229: 0000000000036620    64 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_set_dotdot
   230: 000000000003fcf0   102 FUNC    GLOBAL DEFAULT   16 destroy_encrypted_file_info
   231: 000000000004cda0   170 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_has_super
   232: 000000000004a160    56 FUNC    GLOBAL DEFAULT   16 ext2fs_block_bitmap_loc
   233: 0000000000036690    47 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_get_dotdot
   234: 000000000005e6d0   752 FUNC    GLOBAL DEFAULT   16 ext2fs_open_inode_scan
   235: 000000000005ce70    18 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_data_blocks
   236: 000000000005c730    25 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_set_bit
   237: 0000000000057d60    89 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bitmap_range
   238: 00000000000324e0    82 FUNC    GLOBAL DEFAULT   16 brelse
   239: 00000000000342a0   155 FUNC    GLOBAL DEFAULT   16 e2fsck_allocate_memory
   240: 0000000000057130   125 FUNC    GLOBAL DEFAULT   16 ext2fs_sync_device
   241: 0000000000051940    18 FUNC    GLOBAL DEFAULT   16 ext2fs_get_ea_inode_ref
   242: 000000000005cdb0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_test_valid
   243: 0000000000048ef0   120 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_iterate_begin
   244: 000000000005c4f0   571 FUNC    GLOBAL DEFAULT   16 ext2fs_calculate_summary_stats
   245: 0000000000038a90   269 FUNC    GLOBAL DEFAULT   16 e2fsck_hide_quota
   246: 0000000000048c60    56 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_copy
   247: 0000000000049ce0    26 FUNC    GLOBAL DEFAULT   16 ext2fs_group_of_blk2
   248: 000000000006cbe0   227 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_firstkey
   249: 0000000000048300    41 FUNC    GLOBAL DEFAULT   16 ext2fs_set_new_range_callback
   250: 000000000004e200   164 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_csum_verify
   251: 00000000000242d0   108 FUNC    GLOBAL DEFAULT   16 e2fsck_use_inode_shortcuts
   252: 00000000000b2000     0 NOTYPE  WEAK   DEFAULT   27 data_start
   253: 00000000000720f0    42 FUNC    GLOBAL DEFAULT   16 ext2fs_get_library_version
   254: 000000000005f8d0   166 FUNC    GLOBAL DEFAULT   16 ext2fs_get_blocks
   255: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@GLIBC_2.2.5 (4)
   256: 00000000000500f0    61 FUNC    GLOBAL DEFAULT   16 ext2fs_get_rec_len
   257: 0000000000024390  8207 FUNC    GLOBAL DEFAULT   16 e2fsck_pass1
   258: 0000000000029cb0  1589 FUNC    GLOBAL DEFAULT   16 e2fsck_pass2
   259: 000000000004d6b0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_close
   260: 0000000000043620   270 FUNC    GLOBAL DEFAULT   16 quota_inode_truncate
   261: 000000000002d780   816 FUNC    GLOBAL DEFAULT   16 e2fsck_pass3
   262: 0000000000061f10    69 FUNC    GLOBAL DEFAULT   16 ext2fs_create_journal_superblock
   263: 000000000002de50  1558 FUNC    GLOBAL DEFAULT   16 e2fsck_pass4
   264: 000000000004c1c0   188 FUNC    GLOBAL DEFAULT   16 ext2fs_map_cluster_block
   265: 00000000000463c0    52 FUNC    GLOBAL DEFAULT   16 dnode_create
   266: 0000000000036940   128 FUNC    GLOBAL DEFAULT   16 e2fsck_free_dx_dir_info
   267: 000000000006bcf0    56 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainlock_unmark
   268: 000000000005ceb0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_div_ceil
   269: 0000000000055ee0   322 FUNC    GLOBAL DEFAULT   16 ext2fs_count_blocks
   270: 000000000002ffd0   410 FUNC    GLOBAL DEFAULT   16 e2fsck_pass5
   271: 0000000000050640   367 FUNC    GLOBAL DEFAULT   16 ext2fs_dir_iterate2
   272: 00000000000315d0    14 FUNC    GLOBAL DEFAULT   16 tid_geq
   273: 0000000000032f80    24 FUNC    GLOBAL DEFAULT   16 mark_buffer_uptodate
   274: 0000000000040170    38 FUNC    GLOBAL DEFAULT   16 quota_set_sb_inum
   275: 00000000000311b0    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_revoke
   276: 0000000000044da0    54 FUNC    GLOBAL DEFAULT   16 qtree_entry_unused
   277: 000000000005f350    17 FUNC    GLOBAL DEFAULT   16 ext2fs_read_inode
   278: 0000000000040ab0   282 FUNC    GLOBAL DEFAULT   16 quota_read_all_dquots
   279: 0000000000046300    87 FUNC    GLOBAL DEFAULT   16 dict_prev
   280: 000000000006e8f0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_flush
   281: 0000000000035700   441 FUNC    GLOBAL DEFAULT   16 dump_mmp_msg
   282: 00000000000b10e0    24 OBJECT  GLOBAL DEFAULT   24 et_ext2_error_table
   283: 000000000005cda0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_valid
   284: 000000000006e630   600 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_reopen
   285: 000000000006d5b0    55 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_exists
   286: 000000000003fc60   130 FUNC    GLOBAL DEFAULT   16 destroy_encryption_policy_map
   287: 0000000000042870    49 FUNC    GLOBAL DEFAULT   16 profile_iterator_free
   288: 000000000005b020   424 FUNC    GLOBAL DEFAULT   16 ext2fs_icount_increment
   289: 00000000000595c0   407 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_set_generic_bmap
   290: 000000000004d820     6 FUNC    GLOBAL DEFAULT   16 ext2fs_crc32c_le
   291: 000000000004e4e0   147 FUNC    GLOBAL DEFAULT   16 ext2fs_dir_block_csum_verify
   292: 0000000000063cc0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_casefold_cmp
   293: 0000000000057280   459 FUNC    GLOBAL DEFAULT   16 ext2fs_free
   294: 000000000005cdd0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_bb_dirty
   295: 0000000000038530   463 FUNC    GLOBAL DEFAULT   16 print_e2fsck_message
   296: 000000000005c960    11 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_inode_bitmap2
   297: 00000000000312d0    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_async_commit
   298: 0000000000053d60  2070 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_get
   299: 0000000000051170     8 FUNC    GLOBAL DEFAULT   16 ext2fs_get_ea_inode_hash
   300: 0000000000039e30   538 FUNC    GLOBAL DEFAULT   16 region_allocate
   301: 000000000005e5a0   301 FUNC    GLOBAL DEFAULT   16 ext2fs_create_inode_cache
   302: 0000000000062820    69 FUNC    GLOBAL DEFAULT   16 ext2fs_add_journal_inode2
   303: 0000000000031250    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_64bit
   304: 00000000000625b0   615 FUNC    GLOBAL DEFAULT   16 ext2fs_add_journal_inode3
   305: 0000000000067400    70 FUNC    GLOBAL DEFAULT   16 ext2fs_read_bitmaps
   306: 00000000000538a0    41 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_flags
   307: 000000000005ce90    32 FUNC    GLOBAL DEFAULT   16 ext2fs_htree_intnode_maxrecs
   308: 0000000000056a80    82 FUNC    GLOBAL DEFAULT   16 ext2fs_file_get_size
   309: 0000000000022d70   518 FUNC    GLOBAL DEFAULT   16 e2fsck_pass1_check_symlink
   310: 00000000000681e0    52 FUNC    GLOBAL DEFAULT   16 ext2fs_is_fast_symlink
   311: 000000000004f970    10 FUNC    GLOBAL DEFAULT   16 ext2fs_write_dir_block
   312: 000000000005fd20    30 FUNC    GLOBAL DEFAULT   16 io_channel_cache_readahead
   313: 00000000000b7408     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_read_blk
   314: 000000000005cf00     9 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_set_name_len
   315: 0000000000049f00    33 FUNC    GLOBAL DEFAULT   16 ext2fs_r_blocks_count_set
   316: 000000000004e930   145 FUNC    GLOBAL DEFAULT   16 ext2fs_block_bitmap_csum_set
   317: 0000000000039da0   138 FUNC    GLOBAL DEFAULT   16 region_free
   318: 000000000005c9b0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_block_bitmap2
   319: 000000000005c770    28 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_set_bit64
   320: 000000000001b6e0   960 FUNC    GLOBAL DEFAULT   16 e2fsck_reset_context
   321: 0000000000045ff0    79 FUNC    GLOBAL DEFAULT   16 dict_init
   322: 0000000000052ee0   198 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_iterate
   323: 0000000000042370   513 FUNC    GLOBAL DEFAULT   16 profile_init
   324: 00000000000364b0   291 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_iter
   325: 000000000006bcb0    56 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainlock_mark
   326: 000000000006d420   190 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_fetch
   327: 000000000006dc30     8 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_map_size
   328: 0000000000049b80    41 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_bit64
   329: 0000000000031470    85 FUNC    GLOBAL DEFAULT   16 journal_tag_bytes
   330: 000000000006e4b0   338 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_validate_freelist
   331: 00000000000230f0   285 FUNC    GLOBAL DEFAULT   16 e2fsck_clear_inode
   332: 000000000004d830     6 FUNC    GLOBAL DEFAULT   16 ext2fs_crc32_be
   333: 00000000000180d0    38 FUNC    GLOBAL DEFAULT   16 _start
   334: 000000000004e9d0   268 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_csum_verify
   335: 00000000000462a0    87 FUNC    GLOBAL DEFAULT   16 dict_next
   336: 0000000000063cb0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_check_encoded_name
   337: 000000000006c130   487 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_transaction_cancel
   338: 0000000000057b40    37 FUNC    GLOBAL DEFAULT   16 ext2fs_fudge_generic_bitmap_end
   339: 0000000000037190    28 FUNC    GLOBAL DEFAULT   16 get_latch_flags
   340: 0000000000076450    78 FUNC    GLOBAL DEFAULT   16 error_table_name
   341: 0000000000042e70   222 FUNC    GLOBAL DEFAULT   16 profile_get_uint
   342: 000000000003ab00    83 FUNC    GLOBAL DEFAULT   16 ea_refcount_intr_next
   343: 00000000000406d0   137 FUNC    GLOBAL DEFAULT   16 quota_data_add
   344: 0000000000059760   233 FUNC    GLOBAL DEFAULT   16 ext2fs_count_used_clusters
   345: 000000000005ced0    25 FUNC    GLOBAL DEFAULT   16 ext2fs_div64_ceil
   346: 000000000004f5b0    87 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_iterate
   347: 00000000000b6600     8 OBJECT  GLOBAL DEFAULT   27 test_io_manager
   348: 00000000000765f0    10 FUNC    GLOBAL DEFAULT   16 com_err_va
   349: 0000000000045fb0     9 FUNC    GLOBAL DEFAULT   16 dict_set_cmp_context
   350: 0000000000048fd0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_iterate
   351: 0000000000052fb0   344 FUNC    GLOBAL DEFAULT   16 ext2fs_xattr_get
   352: 000000000005cd80    11 FUNC    GLOBAL DEFAULT   16 ext2fs_test_changed
   353: 000000000005cba0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_block_bitmap_range2
   354: 0000000000047cc0   340 FUNC    GLOBAL DEFAULT   16 ext2fs_get_free_blocks2
   355: 0000000000055240    11 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_node_split
   356: 0000000000034010   280 FUNC    GLOBAL DEFAULT   16 log_err
   357: 0000000000048f80    69 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_iterate
   358: 0000000000071fd0   141 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_has_valid_blocks2
   359: 00000000000547f0   447 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_delete
   360: 0000000000048cb0   297 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_add
   361: 0000000000072720    85 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_prev
   362: 000000000002d140   410 FUNC    GLOBAL DEFAULT   16 e2fsck_expand_directory
   363: 0000000000052c70   610 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_read
   364: 0000000000064a70    41 FUNC    GLOBAL DEFAULT   16 ext2fs_set_data_io
   365: 000000000005a280    38 FUNC    GLOBAL DEFAULT   16 ext2fs_hashmap_iter_in_order
   366: 0000000000049e80    33 FUNC    GLOBAL DEFAULT   16 ext2fs_blocks_count_set
   367: 0000000000035bf0   107 FUNC    GLOBAL DEFAULT   16 e2fsck_allocate_subcluster_bitmap
   368: 000000000004e1d0    34 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_has_tail
   369: 00000000000567e0   408 FUNC    GLOBAL DEFAULT   16 ext2fs_file_read
   370: 000000000006bb10     8 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_error
   371: 00000000000b65a0    72 OBJECT  GLOBAL DEFAULT   27 quotafile_ops_2
   372: 000000000003efc0   194 FUNC    GLOBAL DEFAULT   16 e2fsck_rebuild_extents_later
   373: 0000000000057b70   208 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_generic_bitmap
   374: 00000000000476c0   129 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_block_uninit
   375: 0000000000072060    14 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_has_valid_blocks
   376: 00000000000b73e0     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_write_byte
   377: 000000000002a2f0  1733 FUNC    GLOBAL DEFAULT   16 e2fsck_process_bad_inode
   378: 000000000003aa40    75 FUNC    GLOBAL DEFAULT   16 ea_refcount_decrement
   379: 000000000004f570    61 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_sort
   380: 000000000003a510    66 FUNC    GLOBAL DEFAULT   16 jbd2_journal_destroy_revoke
   381: 000000000005b4a0    76 FUNC    GLOBAL DEFAULT   16 ext2fs_read_ind_block
   382: 000000000001df40   411 FUNC    GLOBAL DEFAULT   16 check_backup_super_block
   383: 0000000000048c50     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_create
   384: 0000000000076700    26 FUNC    GLOBAL DEFAULT   16 reset_com_err_hook
   385: 0000000000047e70    41 FUNC    GLOBAL DEFAULT   16 ext2fs_set_alloc_block_callback
   386: 0000000000048e60    15 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_test
   387: 0000000000048af0    41 FUNC    GLOBAL DEFAULT   16 ext2fs_set_block_alloc_stats_range_callback
   388: 000000000005ae50    14 FUNC    GLOBAL DEFAULT   16 ext2fs_create_icount
   389: 000000000004cfb0   255 FUNC    GLOBAL DEFAULT   16 ext2fs_super_and_bgd_loc
   390: 000000000005b480    28 FUNC    GLOBAL DEFAULT   16 ext2fs_get_icount_size
   391: 000000000003a610    98 FUNC    GLOBAL DEFAULT   16 jbd2_journal_clear_revoke
   392: 0000000000075dc0    95 FUNC    GLOBAL DEFAULT   16 ext2fs_get_device_phys_sectsize
   393: 000000000004a2d0    57 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_table_loc
   394: 000000000003aaf0    13 FUNC    GLOBAL DEFAULT   16 ea_refcount_intr_begin
   395: 0000000000051dd0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_write_ext_attr2
   396: 0000000000051bc0   109 FUNC    GLOBAL DEFAULT   16 ext2fs_write_ext_attr3
   397: 0000000000049a90    36 FUNC    GLOBAL DEFAULT   16 ext2fs_set_bit
   398: 000000000005c880     6 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_block_bitmap
   399: 00000000000576b0    39 FUNC    GLOBAL DEFAULT   16 ext2fs_allocate_generic_bitmap
   400: 00000000000581c0   139 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_block_bitmap_range
   401: 000000000005dc30   280 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_get
   402: 000000000005c790    30 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_clear_bit64
   403: 0000000000062ce0   194 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_init
   404: 00000000000b6fe0     8 OBJECT  GLOBAL DEFAULT   28 stderr@GLIBC_2.2.5 (4)
   405: 00000000000430e0   267 FUNC    GLOBAL DEFAULT   16 profile_iterator
   406: 0000000000059d00   175 FUNC    GLOBAL DEFAULT   16 ext2fs_get_pathname
   407: 0000000000034950   128 FUNC    GLOBAL DEFAULT   16 e2fsck_write_bitmaps
   408: 000000000006bc20    11 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_unlockall_read
   409: 0000000000057200     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_free
   410: 000000000006d5f0    55 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_delete
   411: 000000000005c9f0    75 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_zero_block_bitmap2
   412: 00000000000b6f90     0 NOTYPE  GLOBAL DEFAULT   27 _edata
   413: 000000000004c2c0  1450 FUNC    GLOBAL DEFAULT   16 ext2fs_bmap2
   414: 0000000000046490     9 FUNC    GLOBAL DEFAULT   16 dnode_get
   415: 00000000000b74a8     8 OBJECT  GLOBAL DEFAULT   28 _et_dynamic_list
   416: 0000000000022f80   357 FUNC    GLOBAL DEFAULT   16 e2fsck_setup_icount
   417: 000000000005cf10     9 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_file_type
   418: 0000000000047500   129 FUNC    GLOBAL DEFAULT   16 initialize_ext2_error_table_r
   419: 0000000000047fd0   812 FUNC    GLOBAL DEFAULT   16 ext2fs_new_range
   420: 0000000000047c70    79 FUNC    GLOBAL DEFAULT   16 ext2fs_alloc_block
   421: 0000000000058100    86 FUNC    GLOBAL DEFAULT   16 ext2fs_test_block_bitmap_range
   422: 000000000004a600    28 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_flags_set
   423: 0000000000057860   185 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_generic_bitmap
   424: 0000000000047c60    12 FUNC    GLOBAL DEFAULT   16 ext2fs_alloc_block2
   425: 00000000000434d0    39 FUNC    GLOBAL DEFAULT   16 quota_type2inum
   426: 0000000000047b10   334 FUNC    GLOBAL DEFAULT   16 ext2fs_alloc_block3
   427: 0000000000043040   148 FUNC    GLOBAL DEFAULT   16 profile_get_boolean
   428: 00000000000726c0    85 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_next
   429: 0000000000053290   951 FUNC    GLOBAL DEFAULT   16 ext2fs_xattr_set
   430: 0000000000059420   407 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_zero_generic_bmap
   431: 000000000005a070    92 FUNC    GLOBAL DEFAULT   16 ext2fs_get_device_size
   432: 0000000000048750    11 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_alloc_stats
   433: 000000000005cc80    27 FUNC    GLOBAL DEFAULT   16 ext2fs_free_mem
   434: 00000000000499c0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_set_block_bitmap_range
   435: 00000000000464a0     9 FUNC    GLOBAL DEFAULT   16 dnode_getkey
   436: 000000000003e590    56 FUNC    GLOBAL DEFAULT   16 e2fsck_guess_readahead
   437: 0000000000034860   230 FUNC    GLOBAL DEFAULT   16 ask
   438: 000000000005cca0    39 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_mem
   439: 000000000005a110    76 FUNC    GLOBAL DEFAULT   16 ext2fs_hashmap_create
   440: 000000000004f370    97 FUNC    GLOBAL DEFAULT   16 ext2fs_set_dir_block2
   441: 0000000000076ee0   168 FUNC    GLOBAL DEFAULT   16 e2p_uuid_to_str
   442: 0000000000048c30    18 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_create
   443: 0000000000065ac0  1192 FUNC    GLOBAL DEFAULT   16 ext2fs_create_resize_inode
   444: 0000000000057dc0    81 FUNC    GLOBAL DEFAULT   16 ext2fs_set_generic_bitmap_range
   445: 0000000000033ef0   273 FUNC    GLOBAL DEFAULT   16 log_out
   446: 0000000000058fa0   274 FUNC    GLOBAL DEFAULT   16 ext2fs_test_block_bitmap_range2
   447: 000000000005ea50    37 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_scan_flags
   448: 00000000000549b0   181 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_get_info
   449: 0000000000036d00    27 FUNC    GLOBAL DEFAULT   16 ehandler_init
   450: 0000000000051de0     8 FUNC    GLOBAL DEFAULT   16 ext2fs_write_ext_attr
   451: 00000000000315c0    14 FUNC    GLOBAL DEFAULT   16 tid_gt
   452: 000000000005fba0    70 FUNC    GLOBAL DEFAULT   16 io_channel_read_blk64
   453: 0000000000053650   270 FUNC    GLOBAL DEFAULT   16 ext2fs_xattr_remove
   454: 000000000004e580   155 FUNC    GLOBAL DEFAULT   16 ext2fs_dir_block_csum_set
   455: 000000000006bd70    53 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainlock_read
   456: 0000000000031350    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_csum2
   457: 000000000005c9d0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_inode_bitmap2
   458: 00000000000673a0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_read_inode_bitmap
   459: 0000000000049020     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_iterate_end
   460: 00000000000313d0    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_csum3
   461: 000000000004a1f0    68 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_bitmap_checksum
   462: 00000000000583c0   676 FUNC    GLOBAL DEFAULT   16 ext2fs_alloc_generic_bmap
   463: 000000000005c8f0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_end
   464: 00000000000410a0   916 FUNC    GLOBAL DEFAULT   16 check_plausibility
   465: 00000000000427b0   185 FUNC    GLOBAL DEFAULT   16 profile_iterator_create
   466: 0000000000058950    75 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_generic_bmap
   467: 0000000000051bb0     8 FUNC    GLOBAL DEFAULT   16 ext2fs_read_ext_attr
   468: 0000000000053110   377 FUNC    GLOBAL DEFAULT   16 ext2fs_xattr_inode_max_size
   469: 000000000004a6b0    37 FUNC    GLOBAL DEFAULT   16 ext2fs_file_acl_block_set
   470: 0000000000049b50    39 FUNC    GLOBAL DEFAULT   16 ext2fs_set_bit64
   471: 0000000000076850    32 FUNC    GLOBAL DEFAULT   16 e2p_feature2string
   472: 000000000005a340   149 FUNC    GLOBAL DEFAULT   16 ext2fs_iblk_add_blocks
   473: 000000000006bbd0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall_nonblock
   474: 00000000000310f0    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_checksum
   475: 000000000003e1d0   173 FUNC    GLOBAL DEFAULT   16 e2fsck_readahead_dblist
   476: 0000000000040480   225 FUNC    GLOBAL DEFAULT   16 quota_release_context
   477: 0000000000049f80    33 FUNC    GLOBAL DEFAULT   16 ext2fs_free_blocks_count_set
   478: 0000000000058670   215 FUNC    GLOBAL DEFAULT   16 ext2fs_free_generic_bmap
   479: 0000000000042580   526 FUNC    GLOBAL DEFAULT   16 profile_set_default
   480: 000000000003c880    38 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_will_be_rehashed
   481: 000000000003aad0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_get_refcount_size
   482: 000000000005cb40    18 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_start2
   483: 000000000006dc50    15 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_enable_seqnum
   484: 0000000000072500   345 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_erase
   485: 00000000000400d0   156 FUNC    GLOBAL DEFAULT   16 quota_file_exists
   486: 0000000000045b80    84 FUNC    GLOBAL DEFAULT   16 qtree_delete_dquot
   487: 0000000000031660    25 FUNC    GLOBAL DEFAULT   16 kmalloc_array
   488: 000000000005dd50   393 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_set
   489: 00000000000369d0    43 FUNC    GLOBAL DEFAULT   16 e2fsck_dx_dir_info_iter
   490: 0000000000049dd0    40 FUNC    GLOBAL DEFAULT   16 ext2fs_blocks_count
   491: 0000000000045f80    45 FUNC    GLOBAL DEFAULT   16 dict_set_allocator
   492: 0000000000049990    21 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_range
   493: 00000000000b6fa8     4 OBJECT  GLOBAL DEFAULT   28 optind@GLIBC_2.2.5 (4)
   494: 0000000000072660    37 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_first
   495: 000000000006d1b0   118 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_increment_seqnum_nonblock
   496: 0000000000058d40   134 FUNC    GLOBAL DEFAULT   16 ext2fs_set_generic_bmap_range
   497: 000000000005a940   183 FUNC    GLOBAL DEFAULT   16 ext2fs_free_icount
   498: 000000000005c860     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_block_bitmap
   499: 000000000004ba00    77 FUNC    GLOBAL DEFAULT   16 ext2fs_block_iterate
   500: 00000000000507b0    74 FUNC    GLOBAL DEFAULT   16 ext2fs_dir_iterate
   501: 000000000003f1a0   227 FUNC    GLOBAL DEFAULT   16 e2fsck_read_extents
   502: 000000000004d4c0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_flush
   503: 00000000000b6fa0     8 OBJECT  GLOBAL DEFAULT   28 stdout@GLIBC_2.2.5 (4)
   504: 000000000002c830   270 FUNC    GLOBAL DEFAULT   16 e2fsck_adjust_inode_count
   505: 0000000000056980   103 FUNC    GLOBAL DEFAULT   16 ext2fs_file_llseek
   506: 000000000004a5e0    31 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_flags_test
   507: 000000000004ebc0   245 FUNC    GLOBAL DEFAULT   16 ext2fs_group_desc_csum
   508: 0000000000049d00    24 FUNC    GLOBAL DEFAULT   16 ext2fs_group_first_block2
   509: 0000000000056410    19 FUNC    GLOBAL DEFAULT   16 ext2fs_file_get_inode_num
   510: 0000000000031430    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_fast_commit
   511: 00000000000563f0    22 FUNC    GLOBAL DEFAULT   16 ext2fs_file_get_inode
   512: 00000000000488c0   552 FUNC    GLOBAL DEFAULT   16 ext2fs_block_alloc_stats_range
   513: 0000000000049f50    40 FUNC    GLOBAL DEFAULT   16 ext2fs_free_blocks_count
   514: 0000000000033b10   797 FUNC    GLOBAL DEFAULT   16 read_bad_blocks_file
   515: 000000000005c8e0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_end
   516: 000000000005d680   778 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_dir_iterate
   517: 0000000000027f90   582 FUNC    GLOBAL DEFAULT   16 e2fsck_pass1_dupblocks
   518: 00000000000359d0   308 FUNC    GLOBAL DEFAULT   16 e2fsck_read_bitmaps
   519: 0000000000035920   175 FUNC    GLOBAL DEFAULT   16 e2fsck_set_bitmap_type
   520: 0000000000042300    97 FUNC    GLOBAL DEFAULT   16 profile_release
   521: 0000000000049980     9 FUNC    GLOBAL DEFAULT   16 ext2fs_set_inode_bitmap_range2
   522: 000000000005c910     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_block_bitmap_range
   523: 00000000000315e0    26 FUNC    GLOBAL DEFAULT   16 do_cache_create
   524: 0000000000046240    41 FUNC    GLOBAL DEFAULT   16 dict_first
   525: 0000000000034f80   105 FUNC    GLOBAL DEFAULT   16 e2fsck_write_inode_full
   526: 00000000000494f0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_free_inode_bitmap
   527: 0000000000053ad0   626 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_open2
   528: 00000000000591b0   240 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_block_bitmap_range2
   529: 000000000004e080   132 FUNC    GLOBAL DEFAULT   16 ext2fs_ext_attr_block_csum_verify
   530: 00000000000312b0    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_async_commit
   531: 0000000000056ae0   295 FUNC    GLOBAL DEFAULT   16 ext2fs_file_set_size2
   532: 0000000000076280   184 FUNC    GLOBAL DEFAULT   16 add_error_table
   533: 00000000000b0f60    24 OBJECT  GLOBAL DEFAULT   24 et_prof_error_table
   534: 0000000000039b80   257 FUNC    GLOBAL DEFAULT   16 jbd2_journal_recover
   535: 0000000000045a00   373 FUNC    GLOBAL DEFAULT   16 qtree_write_dquot
   536: 000000000006e610    16 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_set_logging_function
   537: 0000000000049e40    64 FUNC    GLOBAL DEFAULT   16 ext2fs_group_blocks_count
   538: 000000000005c930     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_block_bitmap2
   539: 00000000000673c0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_read_block_bitmap
   540: 0000000000059850   166 FUNC    GLOBAL DEFAULT   16 ext2fs_get_num_dirs
   541: 000000000003f360   637 FUNC    GLOBAL DEFAULT   16 e2fsck_check_rebuild_extents
   542: 0000000000053840    64 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_close
   543: 000000000004f4b0    18 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_iterate2
   544: 00000000000579e0   112 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bitmap_start
   545: 000000000004f420   134 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_iterate3
   546: 000000000005f370   928 FUNC    GLOBAL DEFAULT   16 ext2fs_write_inode2
   547: 0000000000042cc0   168 FUNC    GLOBAL DEFAULT   16 profile_get_string
   548: 00000000000499f0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_range
   549: 000000000006e890    89 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_reopen_all
   550: 000000000006bba0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall_mark
   551: 000000000004a3f0    58 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_free_inodes_count
   552: 0000000000036ce0    19 FUNC    GLOBAL DEFAULT   16 ehandler_operation
   553: 0000000000022d20    67 FUNC    GLOBAL DEFAULT   16 e2fsck_pass1_check_device_inode
   554: 000000000006bb80    19 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall
   555: 000000000006d630   935 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_store
   556: 0000000000049f30    20 FUNC    GLOBAL DEFAULT   16 ext2fs_r_blocks_count_add
   557: 0000000000051f20   449 FUNC    GLOBAL DEFAULT   16 ext2fs_free_ext_attr
   558: 0000000000046390    19 FUNC    GLOBAL DEFAULT   16 dict_isfull
   559: 000000000006cfa0    88 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_dump_all
   560: 000000000004f960     8 FUNC    GLOBAL DEFAULT   16 ext2fs_write_dir_block2
   561: 000000000004f950     9 FUNC    GLOBAL DEFAULT   16 ext2fs_write_dir_block3
   562: 000000000004f910    64 FUNC    GLOBAL DEFAULT   16 ext2fs_write_dir_block4
   563: 000000000003aa00    55 FUNC    GLOBAL DEFAULT   16 ea_refcount_increment
   564: 000000000005c7b0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_swab16
   565: 00000000000407f0   137 FUNC    GLOBAL DEFAULT   16 quota_data_inodes
   566: 0000000000062cc0    22 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_clear
   567: 00000000000358c0    95 FUNC    GLOBAL DEFAULT   16 e2fsck_mmp_update
   568: 000000000005ce10    17 FUNC    GLOBAL DEFAULT   16 ext2fs_group_of_ino
   569: 0000000000048ca0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_copy
   570: 00000000000b67c0     8 OBJECT  GLOBAL DEFAULT   27 undo_io_manager
   571: 0000000000057fe0   144 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_zero_generic_bitmap
   572: 0000000000031170    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_revoke
   573: 0000000000045be0   339 FUNC    GLOBAL DEFAULT   16 qtree_read_dquot
   574: 000000000003a400   259 FUNC    GLOBAL DEFAULT   16 jbd2_journal_init_revoke
   575: 0000000000032fe0  1006 FUNC    GLOBAL DEFAULT   16 e2fsck_check_ext3_journal
   576: 000000000006dbc0    86 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_get_seqnum
   577: 0000000000071ef0   211 FUNC    GLOBAL DEFAULT   16 ext2fs_unlink
   578: 000000000004a620    30 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_flags_clear
   579: 00000000000343b0  1194 FUNC    GLOBAL DEFAULT   16 ask_yn
   580: 000000000004a280    67 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_bitmap_loc_set
   581: 000000000005cb70    18 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_end2
   582: 0000000000035c60    34 FUNC    GLOBAL DEFAULT   16 get_memory_size
   583: 00000000000511f0   116 FUNC    GLOBAL DEFAULT   16 ext2fs_ext_attr_hash_entry2
   584: 00000000000434b0    30 FUNC    GLOBAL DEFAULT   16 quota_type2name
   585: 000000000005cdc0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_ib_dirty
   586: 000000000004f750   261 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_dir_iterate
   587: 0000000000053d50    14 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_open
   588: 0000000000049270   613 FUNC    GLOBAL DEFAULT   16 ext2fs_update_bb_inode
   589: 00000000000313f0    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_fast_commit
   590: 0000000000043f30   135 FUNC    GLOBAL DEFAULT   16 get_empty_dquot
   591: 0000000000058dd0   134 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bmap_range
   592: 000000000005cb30     9 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_start2
   593: 0000000000072070   117 FUNC    GLOBAL DEFAULT   16 ext2fs_parse_version_string
   594: 0000000000046380    15 FUNC    GLOBAL DEFAULT   16 dict_isempty
   595: 0000000000049bb0    31 FUNC    GLOBAL DEFAULT   16 ext2fs_test_bit64
   596: 0000000000048890    41 FUNC    GLOBAL DEFAULT   16 ext2fs_set_block_alloc_stats_callback
   597: 00000000000494e0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_free_block_bitmap
   598: 000000000005c970    11 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_inode_bitmap2
   599: 0000000000046370     9 FUNC    GLOBAL DEFAULT   16 dict_count
   600: 0000000000031610    11 FUNC    GLOBAL DEFAULT   16 __hash_32
   601: 0000000000033940   285 FUNC    GLOBAL DEFAULT   16 e2fsck_fix_ext3_journal_hint
   602: 0000000000057d00    81 FUNC    GLOBAL DEFAULT   16 ext2fs_set_generic_bitmap_padding
   603: 0000000000036320   228 FUNC    GLOBAL DEFAULT   16 e2fsck_free_dir_info
   604: 000000000005f710    12 FUNC    GLOBAL DEFAULT   16 ext2fs_write_inode_full
   605: 000000000005d990   131 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_ea_remove
   606: 0000000000049870    20 FUNC    GLOBAL DEFAULT   16 ext2fs_fudge_block_bitmap_end2
   607: 000000000004f900    10 FUNC    GLOBAL DEFAULT   16 ext2fs_read_dir_block
   608: 0000000000076040     6 FUNC    GLOBAL DEFAULT   16 et_list_unlock
   609: 00000000000497f0    83 FUNC    GLOBAL DEFAULT   16 ext2fs_fudge_inode_bitmap_end
   610: 000000000004a430    67 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_free_inodes_count_set
   611: 00000000000314d0    44 FUNC    GLOBAL DEFAULT   16 jbd2_journal_has_csum_v2or3
   612: 000000000005cae0    78 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_set_inode_bitmap2
   613: 0000000000031620    19 FUNC    GLOBAL DEFAULT   16 hash_32
   614: 0000000000070020    14 FUNC    GLOBAL DEFAULT   16 set_undo_io_backing_manager
   615: 0000000000049eb0    20 FUNC    GLOBAL DEFAULT   16 ext2fs_blocks_count_add
   616: 0000000000048430   377 FUNC    GLOBAL DEFAULT   16 ext2fs_reserve_super_and_bgd
   617: 0000000000061dc0   324 FUNC    GLOBAL DEFAULT   16 ext2fs_create_journal_superblock2
   618: 00000000000438e0   636 FUNC    GLOBAL DEFAULT   16 quota_file_create
   619: 0000000000061da0    19 FUNC    GLOBAL DEFAULT   16 ext2fs_journal_sb_start
   620: 000000000004a680    44 FUNC    GLOBAL DEFAULT   16 ext2fs_file_acl_block
   621: 000000000006e360    23 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_open
   622: 0000000000049030    86 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_equal
   623: 000000000006c320   892 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_transaction_recover
   624: 000000000003f0b0   226 FUNC    GLOBAL DEFAULT   16 e2fsck_rewrite_extent_tree
   625: 00000000000766d0    33 FUNC    GLOBAL DEFAULT   16 set_com_err_hook
   626: 000000000006d4e0   201 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_parse_record
   627: 0000000000057710   135 FUNC    GLOBAL DEFAULT   16 ext2fs_free_generic_bitmap
   628: 00000000000505c0   126 FUNC    GLOBAL DEFAULT   16 ext2fs_set_rec_len
   629: 00000000000b73f8     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_read_blk64
   630: 0000000000058ab0    90 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bmap_end
   631: 000000000006bc10    16 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall_read_nonblock
   632: 00000000000498d0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_inode_bitmap2
   633: 0000000000054700    14 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_goto
   634: 0000000000054a70   404 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_fix_parents
   635: 0000000000048330   234 FUNC    GLOBAL DEFAULT   16 ext2fs_alloc_range
   636: 000000000004df60    68 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_csum_verify
   637: 000000000005cf30     8 FUNC    GLOBAL DEFAULT   16 ext2fs_inode
   638: 000000000004c870   108 FUNC    GLOBAL DEFAULT   16 ext2fs_bmap
   639: 00000000000b6ba0   136 OBJECT  GLOBAL DEFAULT   27 ext2fs_blkmap64_rbtree
   640: 000000000006bc70    56 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainlock_nonblock
   641: 00000000000499e0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_set_block_bitmap_range2
   642: 00000000000656d0   261 FUNC    GLOBAL DEFAULT   16 ext2fs_read_bb_inode
   643: 000000000006cb30   173 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_traverse
   644: 0000000000046270    42 FUNC    GLOBAL DEFAULT   16 dict_last
   645: 0000000000049510     9 FUNC    GLOBAL DEFAULT   16 ext2fs_set_bitmap_padding
   646: 0000000000049850    24 FUNC    GLOBAL DEFAULT   16 ext2fs_fudge_block_bitmap_end
   647: 0000000000036110   517 FUNC    GLOBAL DEFAULT   16 e2fsck_add_dir_info
   648: 000000000004a1a0    66 FUNC    GLOBAL DEFAULT   16 ext2fs_block_bitmap_loc_set
   649: 00000000000b69f0     8 OBJECT  GLOBAL DEFAULT   27 unix_io_manager
   650: 0000000000053760   223 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_open
   651: 0000000000058e60   254 FUNC    GLOBAL DEFAULT   16 ext2fs_compare_generic_bmap
   652: 000000000004a3a0    67 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_free_blocks_count_set
   653: 00000000000769c0   160 FUNC    GLOBAL DEFAULT   16 e2p_jrnl_feature2string
   654: 0000000000046430    71 FUNC    GLOBAL DEFAULT   16 dict_alloc_insert
   655: 0000000000062870    15 FUNC    GLOBAL DEFAULT   16 ext2fs_add_journal_inode
   656: 000000000003e280   727 FUNC    GLOBAL DEFAULT   16 e2fsck_readahead
   657: 000000000005c940     9 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_block_bitmap2
   658: 0000000000067d90  1102 FUNC    GLOBAL DEFAULT   16 ext2fs_symlink
   659: 00000000000563c0    16 FUNC    GLOBAL DEFAULT   16 ext2fs_file_open
   660: 0000000000043c00   812 FUNC    GLOBAL DEFAULT   16 quota_file_open
   661: 0000000000048e80    83 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_del
   662: 0000000000063f00  2838 FUNC    GLOBAL DEFAULT   16 ext2fs_open2
   663: 000000000005af40   209 FUNC    GLOBAL DEFAULT   16 ext2fs_icount_fetch
   664: 000000000005cbc0    32 FUNC    GLOBAL DEFAULT   16 ext2fs_get_mem
   665: 000000000004ed20    72 FUNC    GLOBAL DEFAULT   16 ext2fs_group_desc_csum_set
   666: 0000000000064a40    45 FUNC    GLOBAL DEFAULT   16 ext2fs_get_data_io
   667: 000000000003a8d0    49 FUNC    GLOBAL DEFAULT   16 ea_refcount_free
   668: 000000000004a6e0   186 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_size_set
   669: 000000000005c7c0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_swab32
   670: 0000000000031680    16 FUNC    GLOBAL DEFAULT   16 jbd2_chksum
   671: 0000000000056770   103 FUNC    GLOBAL DEFAULT   16 ext2fs_file_close
   672: 0000000000043b60   146 FUNC    GLOBAL DEFAULT   16 quota_file_close
   673: 0000000000049af0    28 FUNC    GLOBAL DEFAULT   16 ext2fs_test_bit
   674: 0000000000031d60   281 FUNC    GLOBAL DEFAULT   16 ll_rw_block
   675: 000000000005c980    11 FUNC    GLOBAL DEFAULT   16 ext2fs_test_inode_bitmap2
   676: 0000000000040bd0   369 FUNC    GLOBAL DEFAULT   16 quota_compare_and_update
   677: 000000000005a0d0    54 FUNC    GLOBAL DEFAULT   16 ext2fs_djb2_hash
   678: 0000000000058c90   170 FUNC    GLOBAL DEFAULT   16 ext2fs_test_generic_bmap
   679: 0000000000048df0   100 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_find
   680: 00000000000b6c28     8 OBJECT  GLOBAL DEFAULT   27 com_err_hook
   681: 0000000000076070   513 FUNC    GLOBAL DEFAULT   16 error_message
   682: 000000000006bb70    14 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lock_nonblock
   683: 000000000005ce50    18 FUNC    GLOBAL DEFAULT   16 ext2fs_group_last_block
   684: 000000000006bc00    16 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall_read
   685: 000000000005c920     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_block_bitmap_range
   686: 0000000000047ab0    12 FUNC    GLOBAL DEFAULT   16 ext2fs_new_block2
   687: 00000000000b7410     8 OBJECT  GLOBAL DEFAULT   28 test_io_backing_manager
   688: 00000000000478f0   445 FUNC    GLOBAL DEFAULT   16 ext2fs_new_block3
   689: 0000000000058b10    39 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_generic_bmap
   690: 0000000000049e00    54 FUNC    GLOBAL DEFAULT   16 ext2fs_group_last_block2
   691: 000000000005a210    97 FUNC    GLOBAL DEFAULT   16 ext2fs_hashmap_lookup
   692: 0000000000052910   862 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_write
   693: 0000000000076340   252 FUNC    GLOBAL DEFAULT   16 remove_error_table
   694: 00000000000744a0    59 FUNC    GLOBAL DEFAULT   16 ext2fs_crc16
   695: 0000000000053880    28 FUNC    GLOBAL DEFAULT   16 ext2fs_xattrs_count
   696: 000000000004f3e0    52 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_sort2
   697: 000000000005ae60   213 FUNC    GLOBAL DEFAULT   16 ext2fs_icount_validate
   698: 0000000000051ba0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_read_ext_attr2
   699: 0000000000051b10   131 FUNC    GLOBAL DEFAULT   16 ext2fs_read_ext_attr3
   700: 000000000005cd90     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_valid
   701: 0000000000064aa0   135 FUNC    GLOBAL DEFAULT   16 ext2fs_rewrite_to_io
   702: 000000000005c9a0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_block_bitmap2
   703: 0000000000038ba0   207 FUNC    GLOBAL DEFAULT   16 e2fsck_validate_quota_inodes
   704: 000000000006bd30    56 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainunlock
   705: 0000000000048f70     9 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_iterate_begin
   706: 0000000000066f20  1137 FUNC    GLOBAL DEFAULT   16 ext2fs_rw_bitmaps
   707: 000000000003a9d0    41 FUNC    GLOBAL DEFAULT   16 ea_refcount_fetch
   708: 0000000000057e20   129 FUNC    GLOBAL DEFAULT   16 ext2fs_mem_is_zero
   709: 00000000000498b0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_inode_bitmap
   710: 000000000005c8a0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_inode_bitmap
   711: 000000000001b5c0   281 FUNC    GLOBAL DEFAULT   16 e2fsck_allocate_context
   712: 00000000000563d0    20 FUNC    GLOBAL DEFAULT   16 ext2fs_file_get_fs
   713: 000000000003ccc0   732 FUNC    GLOBAL DEFAULT   16 e2fsck_rehash_directories
   714: 0000000000035380   366 FUNC    GLOBAL DEFAULT   16 fs_proc_check
   715: 0000000000063da0   313 FUNC    GLOBAL DEFAULT   16 ext2fs_descriptor_block_loc2
   716: 0000000000049fb0    20 FUNC    GLOBAL DEFAULT   16 ext2fs_free_blocks_count_add
   717: 000000000005e4c0    77 FUNC    GLOBAL DEFAULT   16 ext2fs_flush_icache
   718: 00000000000499b0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_range2
   719: 000000000003c820    84 FUNC    GLOBAL DEFAULT   16 e2fsck_rehash_dir_later
   720: 0000000000042f50   230 FUNC    GLOBAL DEFAULT   16 profile_get_double
   721: 0000000000034ea0   105 FUNC    GLOBAL DEFAULT   16 e2fsck_read_inode
   722: 000000000004ce50   338 FUNC    GLOBAL DEFAULT   16 ext2fs_super_and_bgd_loc2
   723: 0000000000058be0   170 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_generic_bmap
   724: 0000000000032fa0    56 FUNC    GLOBAL DEFAULT   16 wait_on_buffer
   725: 000000000005da20   522 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_expand
   726: 000000000004e6b0   122 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_block_csum_set
   727: 000000000004e050    46 FUNC    GLOBAL DEFAULT   16 ext2fs_superblock_csum_set
   728: 000000000005c850     6 FUNC    GLOBAL DEFAULT   16 ext2fs_test_inode_bitmap
   729: 00000000000617b0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_llseek
   730: 000000000004e110   121 FUNC    GLOBAL DEFAULT   16 ext2fs_ext_attr_block_csum_set
   731: 00000000000667e0   116 FUNC    GLOBAL DEFAULT   16 ext2fs_write_bitmaps
   732: 00000000000b7400     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_write_blk
   733: 000000000005c900     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_block_bitmap_range
   734: 000000000005cc50    38 FUNC    GLOBAL DEFAULT   16 ext2fs_get_arrayzero
   735: 000000000006e620    12 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_get_logging_private
   736: 0000000000062340   611 FUNC    GLOBAL DEFAULT   16 ext2fs_add_journal_device
   737: 0000000000072780   110 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_replace_node
   738: 000000000005c9c0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_inode_bitmap2
   739: 000000000004f4d0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_count2
   740: 0000000000062a70   193 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_write
   741: 0000000000076e50    17 FUNC    GLOBAL DEFAULT   16 e2p_edit_feature
   742: 00000000000577a0   185 FUNC    GLOBAL DEFAULT   16 ext2fs_test_generic_bitmap
   743: 000000000005cd60     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_super_dirty
   744: 000000000005eee0    14 FUNC    GLOBAL DEFAULT   16 ext2fs_get_next_inode
   745: 0000000000049890     9 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_inode_bitmap
   746: 0000000000032f70    14 FUNC    GLOBAL DEFAULT   16 buffer_uptodate
   747: 000000000004a110    68 FUNC    GLOBAL DEFAULT   16 ext2fs_block_bitmap_checksum
   748: 0000000000058070   144 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_set_generic_bitmap
   749: 0000000000044de0    15 FUNC    GLOBAL DEFAULT   16 qtree_dqstr_in_blk
   750: 000000000004d0e0   989 FUNC    GLOBAL DEFAULT   16 ext2fs_flush2
   751: 0000000000034f10   105 FUNC    GLOBAL DEFAULT   16 e2fsck_read_inode_full
   752: 0000000000072690    37 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_last
   753: 000000000005ab60   383 FUNC    GLOBAL DEFAULT   16 ext2fs_create_icount_tdb
   754: 000000000004a5c0    30 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_flags_zap
   755: 0000000000042d70   252 FUNC    GLOBAL DEFAULT   16 profile_get_integer
   756: 0000000000059e10   597 FUNC    GLOBAL DEFAULT   16 ext2fs_get_device_size2
   757: 0000000000054710   223 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_replace
   758: 000000000005d580    90 FUNC    GLOBAL DEFAULT   16 ext2fs_inline_data_init
   759: 0000000000076870   323 FUNC    GLOBAL DEFAULT   16 e2p_string2feature
   760: 0000000000049d90    58 FUNC    GLOBAL DEFAULT   16 ext2fs_get_stat_i_blocks
   761: 000000000003a390   109 FUNC    GLOBAL DEFAULT   16 jbd2_journal_init_revoke_table_cache
   762: 0000000000077000     4 OBJECT  GLOBAL DEFAULT   18 _IO_stdin_used
   763: 000000000006db90     8 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_name
   764: 000000000004f620    99 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_get_last
   765: 0000000000049b10    59 FUNC    GLOBAL DEFAULT   16 ext2fs_warn_bitmap
   766: 00000000000354f0   386 FUNC    GLOBAL DEFAULT   16 check_for_modules
   767: 0000000000075980   858 FUNC    GLOBAL DEFAULT   16 ext2fs_fallocate
   768: 0000000000058b40   159 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_generic_bmap
   769: 000000000001baa0   240 FUNC    GLOBAL DEFAULT   16 e2fsck_free_context
   770: 000000000004d660    80 FUNC    GLOBAL DEFAULT   16 ext2fs_close_free
   771: 000000000004c280    63 FUNC    GLOBAL DEFAULT   16 ext2fs_file_block_offset_too_big
   772: 0000000000048de0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_add
   773: 000000000005cbb0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_block_bitmap_range2
   774: 00000000000501f0   963 FUNC    GLOBAL DEFAULT   16 ext2fs_process_dir_block
   775: 000000000006d000   421 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_printfreelist
   776: 00000000000496c0   264 FUNC    GLOBAL DEFAULT   16 ext2fs_allocate_subcluster_bitmap
   777: 0000000000058250   139 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_block_bitmap_range
   778: 000000000005b1d0   412 FUNC    GLOBAL DEFAULT   16 ext2fs_icount_decrement
   779: 00000000000335e0   855 FUNC    GLOBAL DEFAULT   16 e2fsck_move_ext3_journal
   780: 0000000000043560   182 FUNC    GLOBAL DEFAULT   16 update_grace_times
   781: 000000000006da40   327 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_append
   782: 000000000005ce00    11 FUNC    GLOBAL DEFAULT   16 ext2fs_group_of_blk
   783: 00000000000631c0   509 FUNC    GLOBAL DEFAULT   16 ext2fs_new_dir_block
   784: 000000000005fa30   292 FUNC    GLOBAL DEFAULT   16 io_channel_set_options
   785: 0000000000049520   161 FUNC    GLOBAL DEFAULT   16 ext2fs_allocate_inode_bitmap
   786: 0000000000031640    29 FUNC    GLOBAL DEFAULT   16 hash_64
   787: 0000000000048e70     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_list_test
   788: 00000000000589a0   172 FUNC    GLOBAL DEFAULT   16 ext2fs_fudge_generic_bmap_end
   789: 0000000000055250   348 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_insert
   790: 000000000005cb90     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_block_bitmap_range2
   791: 0000000000060520    13 FUNC    GLOBAL DEFAULT   16 ext2fs_check_if_mounted
   792: 0000000000046040   165 FUNC    GLOBAL DEFAULT   16 dict_lookup
   793: 0000000000057c40   188 FUNC    GLOBAL DEFAULT   16 ext2fs_compare_generic_bitmap
   794: 00000000000497d0    30 FUNC    GLOBAL DEFAULT   16 ext2fs_get_bitmap_granularity
   795: 000000000005c8d0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_get_inode_bitmap_start
   796: 000000000005c870     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_unmark_block_bitmap
   797: 00000000000498f0    21 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_block_bitmap
   798: 0000000000075d40   115 FUNC    GLOBAL DEFAULT   16 ext2fs_get_dio_alignment
   799: 0000000000057920   185 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_generic_bitmap
   800: 0000000000045fc0    36 FUNC    GLOBAL DEFAULT   16 dict_free_nodes
   801: 0000000000062890   467 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_read
   802: 000000000005f740   393 FUNC    GLOBAL DEFAULT   16 ext2fs_write_new_inode
   803: 000000000004a550    67 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_itable_unused_set
   804: 000000000005cf40     6 FUNC    GLOBAL DEFAULT   16 ext2fs_const_inode
   805: 0000000000047ea0   299 FUNC    GLOBAL DEFAULT   16 ext2fs_find_inode_goal
   806: 000000000005cd70     9 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_changed
   807: 00000000000b68e0     8 OBJECT  GLOBAL DEFAULT   27 unixfd_io_manager
   808: 000000000006dbb0    12 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_log_fn
   809: 000000000004ffb0   267 FUNC    GLOBAL DEFAULT   16 ext2fs_dirhash2
   810: 00000000000401a0   328 FUNC    GLOBAL DEFAULT   16 quota_remove_inode
   811: 0000000000048600   329 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_alloc_stats2
   812: 00000000000371b0    63 FUNC    GLOBAL DEFAULT   16 clear_problem_context
   813: 0000000000047750   412 FUNC    GLOBAL DEFAULT   16 ext2fs_new_inode
   814: 0000000000049d60    39 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_i_blocks
   815: 0000000000035060   639 FUNC    GLOBAL DEFAULT   16 get_backup_sb
   816: 00000000000673e0    16 FUNC    GLOBAL DEFAULT   16 ext2fs_write_inode_bitmap
   817: 0000000000076bb0   660 FUNC    GLOBAL DEFAULT   16 e2p_edit_feature2
   818: 0000000000058f60    53 FUNC    GLOBAL DEFAULT   16 ext2fs_set_generic_bmap_padding
   819: 000000000004a310    67 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_table_loc_set
   820: 0000000000072950   198 FUNC    GLOBAL DEFAULT   16 ext2fs_remove_exit_fn
   821: 000000000005c830     6 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_inode_bitmap
   822: 0000000000070030    37 FUNC    GLOBAL DEFAULT   16 set_undo_io_backup_file
   823: 00000000000333d0   520 FUNC    GLOBAL DEFAULT   16 e2fsck_run_ext3_journal
   824: 000000000004fde0   450 FUNC    GLOBAL DEFAULT   16 ext2fs_dirhash
   825: 000000000006c6a0  1000 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_transaction_commit
   826: 000000000004f1b0   110 FUNC    GLOBAL DEFAULT   16 ext2fs_init_dblist
   827: 0000000000049ac0    38 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_bit
   828: 0000000000046360    12 FUNC    GLOBAL DEFAULT   16 dict_allow_dupes
   829: 000000000005fbf0    70 FUNC    GLOBAL DEFAULT   16 io_channel_write_blk64
   830: 0000000000031130    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_checksum
   831: 0000000000040570   346 FUNC    GLOBAL DEFAULT   16 quota_init_context
   832: 000000000004a360    58 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_free_blocks_count
   833: 000000000004f8f0     8 FUNC    GLOBAL DEFAULT   16 ext2fs_read_dir_block2
   834: 0000000000049fd0   292 FUNC    GLOBAL DEFAULT   16 ext2fs_group_desc
   835: 000000000004f8e0    12 FUNC    GLOBAL DEFAULT   16 ext2fs_read_dir_block3
   836: 000000000004f860   120 FUNC    GLOBAL DEFAULT   16 ext2fs_read_dir_block4
   837: 000000000003a2f0    36 FUNC    GLOBAL DEFAULT   16 jbd2_journal_destroy_revoke_table_cache
   838: 0000000000056d80   927 FUNC    GLOBAL DEFAULT   16 ext2fs_file_write
   839: 000000000004ed70   452 FUNC    GLOBAL DEFAULT   16 ext2fs_set_gdt_csum
   840: 0000000000064a20    32 FUNC    GLOBAL DEFAULT   16 ext2fs_open
   841: 0000000000031450    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_fast_commit
   842: 0000000000076440    13 FUNC    GLOBAL DEFAULT   16 add_to_error_table
   843: 0000000000061660   326 FUNC    GLOBAL DEFAULT   16 ext2fs_link
   844: 000000000005c7d0    39 FUNC    GLOBAL DEFAULT   16 ext2fs_swab64
   845: 000000000004eae0   220 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_csum_set
   846: 000000000006bb20    73 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_errorstr
   847: 000000000006dc60  1787 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_open_ex
   848: 000000000005eef0  1095 FUNC    GLOBAL DEFAULT   16 ext2fs_read_inode2
   849: 0000000000061cb0   231 FUNC    GLOBAL DEFAULT   16 ext2fs_get_journal_params
   850: 000000000004e1a0    46 FUNC    GLOBAL DEFAULT   16 ext2fs_initialize_dirent_tail
   851: 00000000000371f0  2285 FUNC    GLOBAL DEFAULT   16 fix_problem
   852: 0000000000046400    35 FUNC    GLOBAL DEFAULT   16 dnode_init
   853: 0000000000049a10     6 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_range2
   854: 0000000000024340    77 FUNC    GLOBAL DEFAULT   16 e2fsck_intercept_block_allocations
   855: 0000000000049090     6 FUNC    GLOBAL DEFAULT   16 ext2fs_badblocks_equal
   856: 000000000005a2b0   115 FUNC    GLOBAL DEFAULT   16 ext2fs_hashmap_free
   857: 0000000000031c30   114 FUNC    GLOBAL DEFAULT   16 jbd2_journal_bmap
   858: 0000000000065800   383 FUNC    GLOBAL DEFAULT   16 ext2fs_read_bb_FILE2
   859: 0000000000036660    47 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_get_parent
   860: 0000000000055d50   300 FUNC    GLOBAL DEFAULT   16 ext2fs_fix_extents_checksums
   861: 000000000004a240    57 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_bitmap_loc
   862: 000000000005c8c0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_start
   863: 00000000000365e0    64 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_set_parent
   864: 0000000000060370   425 FUNC    GLOBAL DEFAULT   16 ext2fs_check_mount_point
   865: 000000000004f610     8 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_count
   866: 000000000005c750    27 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_clear_bit
   867: 000000000005fcc0    87 FUNC    GLOBAL DEFAULT   16 io_channel_alloc_buf
   868: 00000000000368c0   119 FUNC    GLOBAL DEFAULT   16 e2fsck_get_dx_dir_info
   869: 0000000000061c30   126 FUNC    GLOBAL DEFAULT   16 ext2fs_default_journal_size
   870: 0000000000067d00   107 FUNC    GLOBAL DEFAULT   16 ext2fs_sha512
   871: 0000000000071840     9 FUNC    GLOBAL DEFAULT   16 ext2fs_stat
   872: 000000000003a5d0    52 FUNC    GLOBAL DEFAULT   16 jbd2_journal_test_revoke
   873: 000000000006dc40    11 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_get_flags
   874: 000000000005ca90    75 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_set_block_bitmap2
   875: 000000000003e560    41 FUNC    GLOBAL DEFAULT   16 e2fsck_can_readahead
   876: 000000000004ecc0    86 FUNC    GLOBAL DEFAULT   16 ext2fs_group_desc_csum_verify
   877: 00000000000569f0    84 FUNC    GLOBAL DEFAULT   16 ext2fs_file_lseek
   878: 00000000000510b0   100 FUNC    GLOBAL DEFAULT   16 ext2fs_ext_attr_hash_entry
   879: 000000000003f090    27 FUNC    GLOBAL DEFAULT   16 e2fsck_ino_will_be_rebuilt
   880: 00000000000553b0  2327 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_set_bmap
   881: 000000000004dfe0    42 FUNC    GLOBAL DEFAULT   16 ext2fs_verify_csum_type
   882: 000000000003a320   109 FUNC    GLOBAL DEFAULT   16 jbd2_journal_init_revoke_record_cache
   883: 0000000000031be0    77 FUNC    GLOBAL DEFAULT   16 jbd2_descriptor_block_csum_set
   884: 0000000000049d20    64 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_data_blocks2
   885: 00000000000b2000     0 NOTYPE  GLOBAL DEFAULT   27 __data_start
   886: 0000000000071820    21 FUNC    GLOBAL DEFAULT   16 ext2fs_open_file
   887: 000000000005cb60     9 FUNC    GLOBAL DEFAULT   16 ext2fs_get_block_bitmap_end2
   888: 0000000000035b10   107 FUNC    GLOBAL DEFAULT   16 e2fsck_allocate_inode_bitmap
   889: 000000000006bdf0   831 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_transaction_start
   890: 000000000005fc40    54 FUNC    GLOBAL DEFAULT   16 io_channel_discard
   891: 000000000004e880   174 FUNC    GLOBAL DEFAULT   16 ext2fs_block_bitmap_csum_verify
   892: 000000000003df00   180 FUNC    GLOBAL DEFAULT   16 sigcatcher_setup
   893: 00000000000b73f0     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_write_blk64
   894: 000000000004f290   220 FUNC    GLOBAL DEFAULT   16 ext2fs_add_dir_block2
   895: 0000000000049910     6 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_block_bitmap2
   896: 00000000000592a0    69 FUNC    GLOBAL DEFAULT   16 ext2fs_warn_bitmap32
   897: 000000000004e2b0   381 FUNC    GLOBAL DEFAULT   16 ext2fs_dx_csum
   898: 00000000000590c0   240 FUNC    GLOBAL DEFAULT   16 ext2fs_mark_block_bitmap_range2
   899: 000000000005f980   163 FUNC    GLOBAL DEFAULT   16 ext2fs_check_directory
   900: 000000000004a660    28 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_checksum_set
   901: 000000000006bc30    56 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainlock
   902: 0000000000057480    64 FUNC    GLOBAL DEFAULT   16 ext2fs_warn_bitmap2
   903: 0000000000031230    31 FUNC    GLOBAL DEFAULT   16 jbd2_set_feature_64bit
   904: 00000000000b74b0     8 OBJECT  GLOBAL DEFAULT   28 _et_list
   905: 00000000000571b0    65 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_free
   906: 00000000000673f0    16 FUNC    GLOBAL DEFAULT   16 ext2fs_write_block_bitmap
   907: 000000000004e7e0   145 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_bitmap_csum_set
   908: 0000000000058750   500 FUNC    GLOBAL DEFAULT   16 ext2fs_copy_generic_bmap
   909: 0000000000062db0   499 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_start
   910: 0000000000063ee0    20 FUNC    GLOBAL DEFAULT   16 ext2fs_descriptor_block_loc
   911: 00000000000352e0   150 FUNC    GLOBAL DEFAULT   16 ext2_file_type
   912: 0000000000031d20    57 FUNC    GLOBAL DEFAULT   16 sync_blockdev
   913: 0000000000056a50    40 FUNC    GLOBAL DEFAULT   16 ext2fs_file_get_lsize
   914: 000000000005b370   269 FUNC    GLOBAL DEFAULT   16 ext2fs_icount_store
   915: 000000000005cf50    57 FUNC    GLOBAL DEFAULT   16 ext2fs_get_memalign
   916: 00000000000574c0   482 FUNC    GLOBAL DEFAULT   16 ext2fs_make_generic_bitmap
   917: 000000000005fc80    54 FUNC    GLOBAL DEFAULT   16 io_channel_zeroout
   918: 0000000000057210   109 FUNC    GLOBAL DEFAULT   16 ext2fs_free_dblist
   919: 0000000000031150    29 FUNC    GLOBAL DEFAULT   16 jbd2_clear_feature_checksum
   920: 0000000000049940    20 FUNC    GLOBAL DEFAULT   16 ext2fs_compare_inode_bitmap
   921: 0000000000076600   205 FUNC    GLOBAL DEFAULT   16 com_err
   922: 000000000005ea80    34 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_scan_goto_blockgroup
   923: 0000000000056430   412 FUNC    GLOBAL DEFAULT   16 ext2fs_file_flush
   924: 0000000000076050    19 FUNC    GLOBAL DEFAULT   16 set_com_err_gettext
   925: 0000000000048880    11 FUNC    GLOBAL DEFAULT   16 ext2fs_block_alloc_stats
   926: 0000000000076f90    55 FUNC    GLOBAL DEFAULT   16 e2p_uuid2str
   927: 0000000000058a50    90 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bmap_start
   928: 000000000003f290   194 FUNC    GLOBAL DEFAULT   16 e2fsck_should_rebuild_extents
   929: 00000000000b6b00   136 OBJECT  GLOBAL DEFAULT   27 ext2fs_blkmap64_bitarray
   930: 000000000006e390   284 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_close
   931: 000000000003a2c0    36 FUNC    GLOBAL DEFAULT   16 jbd2_journal_destroy_revoke_record_cache
   932: 0000000000034130   363 FUNC    GLOBAL DEFAULT   16 fatal_error
   933: 000000000004e620   129 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_block_csum_verify
   934: 000000000006bdb0    53 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_chainunlock_read
   935: 000000000004d4d0   388 FUNC    GLOBAL DEFAULT   16 ext2fs_close2
   936: 0000000000053a40   134 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_free
   937: 000000000005a160   166 FUNC    GLOBAL DEFAULT   16 ext2fs_hashmap_add
   938: 0000000000031cb0   105 FUNC    GLOBAL DEFAULT   16 getblk
   939: 000000000006bbf0    14 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_unlockall
   940: 000000000005c950     9 FUNC    GLOBAL DEFAULT   16 ext2fs_test_block_bitmap2
   941: 000000000005cef0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_dirent_name_len
   942: 00000000000311f0    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_64bit
   943: 000000000004e730   174 FUNC    GLOBAL DEFAULT   16 ext2fs_inode_bitmap_csum_verify
   944: 0000000000034ff0   105 FUNC    GLOBAL DEFAULT   16 e2fsck_write_inode
   945: 000000000004a510    58 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_itable_unused
   946: 000000000005c9e0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_inode_bitmap2
   947: 0000000000057120    12 FUNC    GLOBAL DEFAULT   16 ext2fs_file_set_size
   948: 00000000000b7000     8 OBJECT  GLOBAL DEFAULT   28 e2fsck_global_ctx
   949: 000000000005cdf0    11 FUNC    GLOBAL DEFAULT   16 ext2fs_test_bb_dirty
   950: 0000000000036410    21 FUNC    GLOBAL DEFAULT   16 e2fsck_get_num_dirinfo
   951: 00000000000366c0   502 FUNC    GLOBAL DEFAULT   16 e2fsck_add_dx_dir
   952: 000000000002d2e0   533 FUNC    GLOBAL DEFAULT   16 e2fsck_reconnect_file
   953: 000000000004a640    28 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_checksum
   954: 000000000006bbc0    14 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_lockall_unmark
   955: 0000000000040880   555 FUNC    GLOBAL DEFAULT   16 quota_compute_usage
   956: 000000000004dfb0    48 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_csum_set
   957: 000000000003aa90    53 FUNC    GLOBAL DEFAULT   16 ea_refcount_store
   958: 000000000003fab0   330 FUNC    GLOBAL DEFAULT   16 add_encrypted_file
   959: 000000000006dc20     8 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_hash_size
   960: 00000000000b7570     0 NOTYPE  GLOBAL DEFAULT   28 _end
   961: 0000000000076a60   323 FUNC    GLOBAL DEFAULT   16 e2p_jrnl_string2feature
   962: 0000000000049500     9 FUNC    GLOBAL DEFAULT   16 ext2fs_copy_bitmap
   963: 000000000001b290   610 FUNC    GLOBAL DEFAULT   16 e2fsck_simple_progress
   964: 0000000000049ed0    40 FUNC    GLOBAL DEFAULT   16 ext2fs_r_blocks_count
   965: 0000000000039c90   149 FUNC    GLOBAL DEFAULT   16 jbd2_journal_skip_recovery
   966: 000000000004c900   620 FUNC    GLOBAL DEFAULT   16 ext2fs_check_desc
   967: 000000000005b4f0    43 FUNC    GLOBAL DEFAULT   16 ext2fs_write_ind_block
   968: 00000000000b6fc0     8 OBJECT  GLOBAL DEFAULT   28 optarg@GLIBC_2.2.5 (4)
   969: 0000000000035b80   107 FUNC    GLOBAL DEFAULT   16 e2fsck_allocate_block_bitmap
   970: 00000000000463b0    15 FUNC    GLOBAL DEFAULT   16 dict_contains
   971: 00000000000509d0   405 FUNC    GLOBAL DEFAULT   16 ext2fs_expand_dir
   972: 0000000000063c90    24 FUNC    GLOBAL DEFAULT   16 ext2fs_load_nls_table
   973: 0000000000040760   137 FUNC    GLOBAL DEFAULT   16 quota_data_sub
   974: 00000000000460f0   330 FUNC    GLOBAL DEFAULT   16 dict_insert
   975: 000000000006e380    11 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_set_max_dead
   976: 0000000000075ce0    95 FUNC    GLOBAL DEFAULT   16 ext2fs_get_device_sectsize
   977: 00000000000723e0   277 FUNC    GLOBAL DEFAULT   16 ext2fs_rb_insert_color
   978: 000000000005b6a0  3663 FUNC    GLOBAL DEFAULT   16 ext2fs_initialize
   979: 000000000005ce30    18 FUNC    GLOBAL DEFAULT   16 ext2fs_group_first_block
   980: 0000000000061be0    76 FUNC    GLOBAL DEFAULT   16 ext2fs_zero_blocks
   981: 0000000000061a40   411 FUNC    GLOBAL DEFAULT   16 ext2fs_zero_blocks2
   982: 00000000000633c0    47 FUNC    GLOBAL DEFAULT   16 ext2fs_new_dir_inline_data
   983: 00000000000165c0  6920 FUNC    GLOBAL DEFAULT   16 main
   984: 000000000006ccd0   720 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_nextkey
   985: 0000000000036430    76 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_iter_begin
   986: 0000000000051120    78 FUNC    GLOBAL DEFAULT   16 ext2fs_ext_attr_block_rehash
   987: 000000000005cbe0    60 FUNC    GLOBAL DEFAULT   16 ext2fs_get_memzero
   988: 000000000005ccd0   133 FUNC    GLOBAL DEFAULT   16 ext2fs_resize_array
   989: 0000000000051f10     8 FUNC    GLOBAL DEFAULT   16 ext2fs_adjust_ea_refcount
   990: 000000000004f520    42 FUNC    GLOBAL DEFAULT   16 ext2fs_dblist_drop_last
   991: 000000000003a560   104 FUNC    GLOBAL DEFAULT   16 jbd2_journal_set_revoke
   992: 000000000003f5e0     9 FUNC    GLOBAL DEFAULT   16 e2fsck_pass1e
   993: 0000000000065570   238 FUNC    GLOBAL DEFAULT   16 ext2fs_punch
   994: 0000000000063080   249 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_update2
   995: 000000000005ea20    33 FUNC    GLOBAL DEFAULT   16 ext2fs_set_inode_callback
   996: 00000000000539f0    73 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_header_verify
   997: 000000000004a5a0    28 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_flags
   998: 0000000000055e80    81 FUNC    GLOBAL DEFAULT   16 ext2fs_decode_extent
   999: 0000000000076030     7 FUNC    GLOBAL DEFAULT   16 et_list_lock
  1000: 00000000000490a0     8 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_count
  1001: 000000000005c840     6 FUNC    GLOBAL DEFAULT   16 ext2fs_unmark_inode_bitmap
  1002: 0000000000037ae0   124 FUNC    GLOBAL DEFAULT   16 end_problem_latch
  1003: 0000000000035680   122 FUNC    GLOBAL DEFAULT   16 write_all
  1004: 0000000000054580   369 FUNC    GLOBAL DEFAULT   16 ext2fs_extent_goto2
  1005: 0000000000031e80     9 FUNC    GLOBAL DEFAULT   16 mark_buffer_dirty
  1006: 000000000004a480    58 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_used_dirs_count
  1007: 0000000000031600     9 FUNC    GLOBAL DEFAULT   16 do_cache_destroy
  1008: 00000000000576e0    47 FUNC    GLOBAL DEFAULT   16 ext2fs_copy_generic_bitmap
  1009: 0000000000063180    11 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_update
  1010: 0000000000036480    37 FUNC    GLOBAL DEFAULT   16 e2fsck_dir_info_iter_end
  1011: 0000000000049920    20 FUNC    GLOBAL DEFAULT   16 ext2fs_compare_block_bitmap
  1012: 000000000006ca90   157 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_traverse_read
  1013: 0000000000051f00    12 FUNC    GLOBAL DEFAULT   16 ext2fs_adjust_ea_refcount2
  1014: 0000000000051df0   261 FUNC    GLOBAL DEFAULT   16 ext2fs_adjust_ea_refcount3
  1015: 000000000005c990     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_mark_block_bitmap2
  1016: 000000000003a910   187 FUNC    GLOBAL DEFAULT   16 ea_refcount_create
  1017: 000000000004a4c0    67 FUNC    GLOBAL DEFAULT   16 ext2fs_bg_used_dirs_count_set
  1018: 0000000000051930     8 FUNC    GLOBAL DEFAULT   16 ext2fs_set_ea_inode_hash
  1019: 000000000003dc50    53 FUNC    GLOBAL DEFAULT   16 set_up_logging
  1020: 000000000005c8b0     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fast_test_inode_bitmap
  1021: 000000000004f550    14 FUNC    GLOBAL DEFAULT   16 ext2fs_add_dir_block
  1022: 000000000004d0b0    39 FUNC    GLOBAL DEFAULT   16 ext2fs_update_dynamic_rev
  1023: 0000000000062fb0   203 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_stop
  1024: 0000000000051960    18 FUNC    GLOBAL DEFAULT   16 ext2fs_set_ea_inode_ref
  1025: 0000000000055cd0   120 FUNC    GLOBAL DEFAULT   16 ext2fs_max_extent_depth
  1026: 0000000000076eb0    43 FUNC    GLOBAL DEFAULT   16 e2p_is_null_uuid
  1027: 000000000005c820     9 FUNC    GLOBAL DEFAULT   16 ext2fs_test_block_bitmap
  1028: 00000000000b6f90     0 NOTYPE  GLOBAL DEFAULT   28 __bss_start
  1029: 000000000006dba0     8 FUNC    GLOBAL DEFAULT   16 ext2fs_tdb_fd
  1030: 000000000003c8b0  1031 FUNC    GLOBAL DEFAULT   16 e2fsck_rehash_dir
  1031: 00000000000369c0    11 FUNC    GLOBAL DEFAULT   16 e2fsck_get_num_dx_dirinfo
  1032: 0000000000047590    16 FUNC    GLOBAL DEFAULT   16 initialize_ext2_error_table
  1033: 0000000000048fe0    55 FUNC    GLOBAL DEFAULT   16 ext2fs_u32_list_iterate_end
  1034: 0000000000040d50   193 FUNC    GLOBAL DEFAULT   16 parse_quota_opts
  1035: 000000000001bb90   237 FUNC    GLOBAL DEFAULT   16 e2fsck_run
  1036: 00000000000b73e8     8 OBJECT  GLOBAL DEFAULT   28 test_io_cb_set_blksize
  1037: 000000000001c930  1150 FUNC    GLOBAL DEFAULT   16 check_resize_inode
  1038: 00000000000498a0     6 FUNC    GLOBAL DEFAULT   16 ext2fs_clear_block_bitmap
  1039: 0000000000062c10   174 FUNC    GLOBAL DEFAULT   16 ext2fs_mmp_new_seq
  1040: 0000000000049bd0   154 FUNC    GLOBAL DEFAULT   16 ext2fs_bitcount
  1041: 000000000005e9c0    91 FUNC    GLOBAL DEFAULT   16 ext2fs_close_inode_scan
  1042: 000000000004e010    50 FUNC    GLOBAL DEFAULT   16 ext2fs_superblock_csum_verify
  1043: 000000000004def0    99 FUNC    GLOBAL DEFAULT   16 ext2fs_init_csum_seed
  1044: 0000000000046480     9 FUNC    GLOBAL DEFAULT   16 dnode_destroy
  1045: 000000000005f720    17 FUNC    GLOBAL DEFAULT   16 ext2fs_write_inode
  1046: 0000000000043500    86 FUNC    GLOBAL DEFAULT   16 quota_get_qf_name
  1047: 0000000000057a50   112 FUNC    GLOBAL DEFAULT   16 ext2fs_get_generic_bitmap_end
  1048: 0000000000058160    86 FUNC    GLOBAL DEFAULT   16 ext2fs_test_inode_bitmap_range
  1049: 000000000004e190    12 FUNC    GLOBAL DEFAULT   16 ext2fs_get_dx_countlimit
  1050: 0000000000034340    99 FUNC    GLOBAL DEFAULT   16 string_copy
  1051: 0000000000031270    51 FUNC    GLOBAL DEFAULT   16 jbd2_has_feature_async_commit
  1052: 0000000000071850     9 FUNC    GLOBAL DEFAULT   16 ext2fs_fstat
  1053: 000000000005ca40    78 FUNC    GLOBAL DEFAULT   16 ext2fs_find_first_zero_inode_bitmap2
  1054: 00000000000315a0    31 FUNC    GLOBAL DEFAULT   16 jbd2_journal_get_num_fc_blks

exec
/bin/bash -lc 'readelf -r ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

Relocation section '.rela.dyn' at offset 0xde38 contains 1007 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
0000000b0cb0  000000000008 R_X86_64_RELATIVE                    181b0
0000000b0cb8  000000000008 R_X86_64_RELATIVE                    18170
0000000b0cc0  000000000008 R_X86_64_RELATIVE                    87034
0000000b0cc8  000000000008 R_X86_64_RELATIVE                    87035
0000000b0cd0  000000000008 R_X86_64_RELATIVE                    79ac1
0000000b0cd8  000000000008 R_X86_64_RELATIVE                    79ac2
0000000b0d00  000000000008 R_X86_64_RELATIVE                    7ae46
0000000b0d08  000000000008 R_X86_64_RELATIVE                    7ae4d
0000000b0d10  000000000008 R_X86_64_RELATIVE                    7ae9d
0000000b0d18  000000000008 R_X86_64_RELATIVE                    7ae53
0000000b0d20  000000000008 R_X86_64_RELATIVE                    7ae5d
0000000b0d28  000000000008 R_X86_64_RELATIVE                    7ae67
0000000b0d30  000000000008 R_X86_64_RELATIVE                    7ae70
0000000b0d38  000000000008 R_X86_64_RELATIVE                    7ae7c
0000000b0d40  000000000008 R_X86_64_RELATIVE                    7ae84
0000000b0d48  000000000008 R_X86_64_RELATIVE                    7ae8d
0000000b0d50  000000000008 R_X86_64_RELATIVE                    7ae97
0000000b0d58  000000000008 R_X86_64_RELATIVE                    7aea5
0000000b0d60  000000000008 R_X86_64_RELATIVE                    7aead
0000000b0d68  000000000008 R_X86_64_RELATIVE                    7aeb3
0000000b0d70  000000000008 R_X86_64_RELATIVE                    7eb90
0000000b0d78  000000000008 R_X86_64_RELATIVE                    7aebe
0000000b0d80  000000000008 R_X86_64_RELATIVE                    7aecb
0000000b0d88  000000000008 R_X86_64_RELATIVE                    7aed6
0000000b0d90  000000000008 R_X86_64_RELATIVE                    7aedf
0000000b0d98  000000000008 R_X86_64_RELATIVE                    7aef3
0000000b0da0  000000000008 R_X86_64_RELATIVE                    7af01
0000000b0da8  000000000008 R_X86_64_RELATIVE                    7af0f
0000000b0db0  000000000008 R_X86_64_RELATIVE                    782b4
0000000b0dc0  000000000008 R_X86_64_RELATIVE                    7af1c
0000000b0dc8  000000000008 R_X86_64_RELATIVE                    7af28
0000000b0dd0  000000000008 R_X86_64_RELATIVE                    7af2c
0000000b0dd8  000000000008 R_X86_64_RELATIVE                    7af32
0000000b0de0  000000000008 R_X86_64_RELATIVE                    7af3b
0000000b0de8  000000000008 R_X86_64_RELATIVE                    7af44
0000000b0df0  000000000008 R_X86_64_RELATIVE                    7af4b
0000000b0df8  000000000008 R_X86_64_RELATIVE                    7af62
0000000b0e00  000000000008 R_X86_64_RELATIVE                    7af69
0000000b0e08  000000000008 R_X86_64_RELATIVE                    7af71
0000000b0e10  000000000008 R_X86_64_RELATIVE                    7af7a
0000000b0e18  000000000008 R_X86_64_RELATIVE                    7af86
0000000b0e20  000000000008 R_X86_64_RELATIVE                    7af8c
0000000b0e28  000000000008 R_X86_64_RELATIVE                    7af92
0000000b0e30  000000000008 R_X86_64_RELATIVE                    7af9b
0000000b0e38  000000000008 R_X86_64_RELATIVE                    7afb9
0000000b0e40  000000000008 R_X86_64_RELATIVE                    7afc5
0000000b0e48  000000000008 R_X86_64_RELATIVE                    7afd7
0000000b0e50  000000000008 R_X86_64_RELATIVE                    7afde
0000000b0e58  000000000008 R_X86_64_RELATIVE                    7aff0
0000000b0e60  000000000008 R_X86_64_RELATIVE                    7aff9
0000000b0e68  000000000008 R_X86_64_RELATIVE                    7b002
0000000b0e70  000000000008 R_X86_64_RELATIVE                    782b4
0000000b0e80  000000000008 R_X86_64_RELATIVE                    7eca5
0000000b0e88  000000000008 R_X86_64_RELATIVE                    7ecb6
0000000b0e90  000000000008 R_X86_64_RELATIVE                    7eccd
0000000b0e98  000000000008 R_X86_64_RELATIVE                    7eccf
0000000b0ea0  000000000008 R_X86_64_RELATIVE                    7ece6
0000000b0ea8  000000000008 R_X86_64_RELATIVE                    7ecfe
0000000b0eb0  000000000008 R_X86_64_RELATIVE                    7f128
0000000b0eb8  000000000008 R_X86_64_RELATIVE                    7ed16
0000000b0ec0  000000000008 R_X86_64_RELATIVE                    7ed33
0000000b0ec8  000000000008 R_X86_64_RELATIVE                    7ed47
0000000b0ed0  000000000008 R_X86_64_RELATIVE                    7ed5a
0000000b0ee0  000000000008 R_X86_64_RELATIVE                    79224
0000000b0ee8  000000000008 R_X86_64_RELATIVE                    7a44d
0000000b0ef0  000000000008 R_X86_64_RELATIVE                    7fe78
0000000b0ef8  000000000008 R_X86_64_RELATIVE                    7fe7e
0000000b0f00  000000000008 R_X86_64_RELATIVE                    7fe99
0000000b0f08  000000000008 R_X86_64_RELATIVE                    96c62
0000000b0f20  000000000008 R_X86_64_RELATIVE                    86dc6
0000000b0f28  000000000008 R_X86_64_RELATIVE                    79d12
0000000b0f30  000000000008 R_X86_64_RELATIVE                    7fe82
0000000b0f38  000000000008 R_X86_64_RELATIVE                    7ff09
0000000b0f40  000000000008 R_X86_64_RELATIVE                    7923b
0000000b0f48  000000000008 R_X86_64_RELATIVE                    96c6c
0000000b0f60  000000000008 R_X86_64_RELATIVE                    b0f80
0000000b0f80  000000000008 R_X86_64_RELATIVE                    7fe87
0000000b0f88  000000000008 R_X86_64_RELATIVE                    7ff90
0000000b0f90  000000000008 R_X86_64_RELATIVE                    7fe9b
0000000b0f98  000000000008 R_X86_64_RELATIVE                    7feb5
0000000b0fa0  000000000008 R_X86_64_RELATIVE                    7ffb0
0000000b0fa8  000000000008 R_X86_64_RELATIVE                    7fff0
0000000b0fb0  000000000008 R_X86_64_RELATIVE                    80020
0000000b0fb8  000000000008 R_X86_64_RELATIVE                    80048
0000000b0fc0  000000000008 R_X86_64_RELATIVE                    80070
0000000b0fc8  000000000008 R_X86_64_RELATIVE                    800a0
0000000b0fd0  000000000008 R_X86_64_RELATIVE                    800c8
0000000b0fd8  000000000008 R_X86_64_RELATIVE                    800e8
0000000b0fe0  000000000008 R_X86_64_RELATIVE                    80118
0000000b0fe8  000000000008 R_X86_64_RELATIVE                    80140
0000000b0ff0  000000000008 R_X86_64_RELATIVE                    80168
0000000b0ff8  000000000008 R_X86_64_RELATIVE                    80190
0000000b1000  000000000008 R_X86_64_RELATIVE                    801b8
0000000b1008  000000000008 R_X86_64_RELATIVE                    7fed0
0000000b1010  000000000008 R_X86_64_RELATIVE                    7feee
0000000b1018  000000000008 R_X86_64_RELATIVE                    801d8
0000000b1020  000000000008 R_X86_64_RELATIVE                    80200
0000000b1028  000000000008 R_X86_64_RELATIVE                    80238
0000000b1030  000000000008 R_X86_64_RELATIVE                    7ff0b
0000000b1038  000000000008 R_X86_64_RELATIVE                    80258
0000000b1040  000000000008 R_X86_64_RELATIVE                    7ff1c
0000000b1048  000000000008 R_X86_64_RELATIVE                    80280
0000000b1050  000000000008 R_X86_64_RELATIVE                    7ff31
0000000b1058  000000000008 R_X86_64_RELATIVE                    7ff4c
0000000b1060  000000000008 R_X86_64_RELATIVE                    7ff63
0000000b1068  000000000008 R_X86_64_RELATIVE                    7ff79
0000000b1070  000000000008 R_X86_64_RELATIVE                    802a8
0000000b1080  000000000008 R_X86_64_RELATIVE                    782b4
0000000b1088  000000000008 R_X86_64_RELATIVE                    802e8
0000000b1090  000000000008 R_X86_64_RELATIVE                    802e7
0000000b1098  000000000008 R_X86_64_RELATIVE                    782b4
0000000b10a0  000000000008 R_X86_64_RELATIVE                    802e7
0000000b10b0  000000000008 R_X86_64_RELATIVE                    7ec20
0000000b10b8  000000000008 R_X86_64_RELATIVE                    78e99
0000000b10c0  000000000008 R_X86_64_RELATIVE                    7ec25
0000000b10e0  000000000008 R_X86_64_RELATIVE                    b1100
0000000b1100  000000000008 R_X86_64_RELATIVE                    80e4c
0000000b1108  000000000008 R_X86_64_RELATIVE                    81448
0000000b1110  000000000008 R_X86_64_RELATIVE                    81478
0000000b1118  000000000008 R_X86_64_RELATIVE                    814a8
0000000b1120  000000000008 R_X86_64_RELATIVE                    814e0
0000000b1128  000000000008 R_X86_64_RELATIVE                    81510
0000000b1130  000000000008 R_X86_64_RELATIVE                    81540
0000000b1138  000000000008 R_X86_64_RELATIVE                    81578
0000000b1140  000000000008 R_X86_64_RELATIVE                    815a8
0000000b1148  000000000008 R_X86_64_RELATIVE                    815d8
0000000b1150  000000000008 R_X86_64_RELATIVE                    81608
0000000b1158  000000000008 R_X86_64_RELATIVE                    81638
0000000b1160  000000000008 R_X86_64_RELATIVE                    81670
0000000b1168  000000000008 R_X86_64_RELATIVE                    816a8
0000000b1170  000000000008 R_X86_64_RELATIVE                    816d0
0000000b1178  000000000008 R_X86_64_RELATIVE                    81708
0000000b1180  000000000008 R_X86_64_RELATIVE                    81738
0000000b1188  000000000008 R_X86_64_RELATIVE                    81768
0000000b1190  000000000008 R_X86_64_RELATIVE                    817a0
0000000b1198  000000000008 R_X86_64_RELATIVE                    817d0
0000000b11a0  000000000008 R_X86_64_RELATIVE                    80e6a
0000000b11a8  000000000008 R_X86_64_RELATIVE                    817f0
0000000b11b0  000000000008 R_X86_64_RELATIVE                    80e87
0000000b11b8  000000000008 R_X86_64_RELATIVE                    80ea4
0000000b11c0  000000000008 R_X86_64_RELATIVE                    81820
0000000b11c8  000000000008 R_X86_64_RELATIVE                    81858
0000000b11d0  000000000008 R_X86_64_RELATIVE                    81890
0000000b11d8  000000000008 R_X86_64_RELATIVE                    80ec2
0000000b11e0  000000000008 R_X86_64_RELATIVE                    80ede
0000000b11e8  000000000008 R_X86_64_RELATIVE                    80ef9
0000000b11f0  000000000008 R_X86_64_RELATIVE                    80f14
0000000b11f8  000000000008 R_X86_64_RELATIVE                    80f2e
0000000b1200  000000000008 R_X86_64_RELATIVE                    80f49
0000000b1208  000000000008 R_X86_64_RELATIVE                    80f63
0000000b1210  000000000008 R_X86_64_RELATIVE                    818c8
0000000b1218  000000000008 R_X86_64_RELATIVE                    80f79
0000000b1220  000000000008 R_X86_64_RELATIVE                    818f0
0000000b1228  000000000008 R_X86_64_RELATIVE                    81930
0000000b1230  000000000008 R_X86_64_RELATIVE                    81970
0000000b1238  000000000008 R_X86_64_RELATIVE                    80f92
0000000b1240  000000000008 R_X86_64_RELATIVE                    80faa
0000000b1248  000000000008 R_X86_64_RELATIVE                    80fc2
0000000b1250  000000000008 R_X86_64_RELATIVE                    80fd7
0000000b1258  000000000008 R_X86_64_RELATIVE                    81990
0000000b1260  000000000008 R_X86_64_RELATIVE                    819b8
0000000b1268  000000000008 R_X86_64_RELATIVE                    819e8
0000000b1270  000000000008 R_X86_64_RELATIVE                    81a20
0000000b1278  000000000008 R_X86_64_RELATIVE                    81a60
0000000b1280  000000000008 R_X86_64_RELATIVE                    81a98
0000000b1288  000000000008 R_X86_64_RELATIVE                    81ad0
0000000b1290  000000000008 R_X86_64_RELATIVE                    81b10
0000000b1298  000000000008 R_X86_64_RELATIVE                    81b48
0000000b12a0  000000000008 R_X86_64_RELATIVE                    81b80
0000000b12a8  000000000008 R_X86_64_RELATIVE                    80fec
0000000b12b0  000000000008 R_X86_64_RELATIVE                    81bb8
0000000b12b8  000000000008 R_X86_64_RELATIVE                    81be0
0000000b12c0  000000000008 R_X86_64_RELATIVE                    81c08
0000000b12c8  000000000008 R_X86_64_RELATIVE                    81c28
0000000b12d0  000000000008 R_X86_64_RELATIVE                    81c48
0000000b12d8  000000000008 R_X86_64_RELATIVE                    81c70
0000000b12e0  000000000008 R_X86_64_RELATIVE                    81c98
0000000b12e8  000000000008 R_X86_64_RELATIVE                    81cb8
0000000b12f0  000000000008 R_X86_64_RELATIVE                    81cf8
0000000b12f8  000000000008 R_X86_64_RELATIVE                    81d40
0000000b1300  000000000008 R_X86_64_RELATIVE                    81d80
0000000b1308  000000000008 R_X86_64_RELATIVE                    81da8
0000000b1310  000000000008 R_X86_64_RELATIVE                    81dd8
0000000b1318  000000000008 R_X86_64_RELATIVE                    81e10
0000000b1320  000000000008 R_X86_64_RELATIVE                    81e38
0000000b1328  000000000008 R_X86_64_RELATIVE                    81e68
0000000b1330  000000000008 R_X86_64_RELATIVE                    81009
0000000b1338  000000000008 R_X86_64_RELATIVE                    81e98
0000000b1340  000000000008 R_X86_64_RELATIVE                    81ec0
0000000b1348  000000000008 R_X86_64_RELATIVE                    81ef0
0000000b1350  000000000008 R_X86_64_RELATIVE                    81022
0000000b1358  000000000008 R_X86_64_RELATIVE                    81040
0000000b1360  000000000008 R_X86_64_RELATIVE                    8105d
0000000b1368  000000000008 R_X86_64_RELATIVE                    8107b
0000000b1370  000000000008 R_X86_64_RELATIVE                    81f20
0000000b1378  000000000008 R_X86_64_RELATIVE                    8108f
0000000b1380  000000000008 R_X86_64_RELATIVE                    81f40
0000000b1388  000000000008 R_X86_64_RELATIVE                    810ad
0000000b1390  000000000008 R_X86_64_RELATIVE                    810c3
0000000b1398  000000000008 R_X86_64_RELATIVE                    81f68
0000000b13a0  000000000008 R_X86_64_RELATIVE                    810d5
0000000b13a8  000000000008 R_X86_64_RELATIVE                    81f98
0000000b13b0  000000000008 R_X86_64_RELATIVE                    810f2
0000000b13b8  000000000008 R_X86_64_RELATIVE                    81fc0
0000000b13c0  000000000008 R_X86_64_RELATIVE                    8110e
0000000b13c8  000000000008 R_X86_64_RELATIVE                    81120
0000000b13d0  000000000008 R_X86_64_RELATIVE                    81fe0
0000000b13d8  000000000008 R_X86_64_RELATIVE                    82008
0000000b13e0  000000000008 R_X86_64_RELATIVE                    8113b
0000000b13e8  000000000008 R_X86_64_RELATIVE                    82048
0000000b13f0  000000000008 R_X86_64_RELATIVE                    81157
0000000b13f8  000000000008 R_X86_64_RELATIVE                    82078
0000000b1400  000000000008 R_X86_64_RELATIVE                    8116f
0000000b1408  000000000008 R_X86_64_RELATIVE                    8117c
0000000b1410  000000000008 R_X86_64_RELATIVE                    81192
0000000b1418  000000000008 R_X86_64_RELATIVE                    811a0
0000000b1420  000000000008 R_X86_64_RELATIVE                    811b3
0000000b1428  000000000008 R_X86_64_RELATIVE                    811c6
0000000b1430  000000000008 R_X86_64_RELATIVE                    820b0
0000000b1438  000000000008 R_X86_64_RELATIVE                    811d9
0000000b1440  000000000008 R_X86_64_RELATIVE                    811f0
0000000b1448  000000000008 R_X86_64_RELATIVE                    8120b
0000000b1450  000000000008 R_X86_64_RELATIVE                    820d0
0000000b1458  000000000008 R_X86_64_RELATIVE                    820f8
0000000b1460  000000000008 R_X86_64_RELATIVE                    82140
0000000b1468  000000000008 R_X86_64_RELATIVE                    82170
0000000b1470  000000000008 R_X86_64_RELATIVE                    821a0
0000000b1478  000000000008 R_X86_64_RELATIVE                    821d0
0000000b1480  000000000008 R_X86_64_RELATIVE                    82200
0000000b1488  000000000008 R_X86_64_RELATIVE                    82228
0000000b1490  000000000008 R_X86_64_RELATIVE                    82250
0000000b1498  000000000008 R_X86_64_RELATIVE                    82278
0000000b14a0  000000000008 R_X86_64_RELATIVE                    822a0
0000000b14a8  000000000008 R_X86_64_RELATIVE                    822c8
0000000b14b0  000000000008 R_X86_64_RELATIVE                    822f0
0000000b14b8  000000000008 R_X86_64_RELATIVE                    81224
0000000b14c0  000000000008 R_X86_64_RELATIVE                    8123a
0000000b14c8  000000000008 R_X86_64_RELATIVE                    8124f
0000000b14d0  000000000008 R_X86_64_RELATIVE                    8125e
0000000b14d8  000000000008 R_X86_64_RELATIVE                    8127a
0000000b14e0  000000000008 R_X86_64_RELATIVE                    81295
0000000b14e8  000000000008 R_X86_64_RELATIVE                    812a6
0000000b14f0  000000000008 R_X86_64_RELATIVE                    812bb
0000000b14f8  000000000008 R_X86_64_RELATIVE                    812ca
0000000b1500  000000000008 R_X86_64_RELATIVE                    812db
0000000b1508  000000000008 R_X86_64_RELATIVE                    82318
0000000b1510  000000000008 R_X86_64_RELATIVE                    82338
0000000b1518  000000000008 R_X86_64_RELATIVE                    82360
0000000b1520  000000000008 R_X86_64_RELATIVE                    812eb
0000000b1528  000000000008 R_X86_64_RELATIVE                    82388
0000000b1530  000000000008 R_X86_64_RELATIVE                    812fc
0000000b1538  000000000008 R_X86_64_RELATIVE                    823c0
0000000b1540  000000000008 R_X86_64_RELATIVE                    823f8
0000000b1548  000000000008 R_X86_64_RELATIVE                    82438
0000000b1550  000000000008 R_X86_64_RELATIVE                    81315
0000000b1558  000000000008 R_X86_64_RELATIVE                    8132f
0000000b1560  000000000008 R_X86_64_RELATIVE                    8134c
0000000b1568  000000000008 R_X86_64_RELATIVE                    82468
0000000b1570  000000000008 R_X86_64_RELATIVE                    82498
0000000b1578  000000000008 R_X86_64_RELATIVE                    81362
0000000b1580  000000000008 R_X86_64_RELATIVE                    824c0
0000000b1588  000000000008 R_X86_64_RELATIVE                    824e0
0000000b1590  000000000008 R_X86_64_RELATIVE                    82508
0000000b1598  000000000008 R_X86_64_RELATIVE                    82530
0000000b15a0  000000000008 R_X86_64_RELATIVE                    82560
0000000b15a8  000000000008 R_X86_64_RELATIVE                    82598
0000000b15b0  000000000008 R_X86_64_RELATIVE                    825d0
0000000b15b8  000000000008 R_X86_64_RELATIVE                    82608
0000000b15c0  000000000008 R_X86_64_RELATIVE                    82640
0000000b15c8  000000000008 R_X86_64_RELATIVE                    8137f
0000000b15d0  000000000008 R_X86_64_RELATIVE                    82670
0000000b15d8  000000000008 R_X86_64_RELATIVE                    8139a
0000000b15e0  000000000008 R_X86_64_RELATIVE                    82698
0000000b15e8  000000000008 R_X86_64_RELATIVE                    826c8
0000000b15f0  000000000008 R_X86_64_RELATIVE                    82708
0000000b15f8  000000000008 R_X86_64_RELATIVE                    82738
0000000b1600  000000000008 R_X86_64_RELATIVE                    82768
0000000b1608  000000000008 R_X86_64_RELATIVE                    82798
0000000b1610  000000000008 R_X86_64_RELATIVE                    827c8
0000000b1618  000000000008 R_X86_64_RELATIVE                    827f0
0000000b1620  000000000008 R_X86_64_RELATIVE                    82828
0000000b1628  000000000008 R_X86_64_RELATIVE                    82860
0000000b1630  000000000008 R_X86_64_RELATIVE                    82880
0000000b1638  000000000008 R_X86_64_RELATIVE                    813b3
0000000b1640  000000000008 R_X86_64_RELATIVE                    828a8
0000000b1648  000000000008 R_X86_64_RELATIVE                    828e0
0000000b1650  000000000008 R_X86_64_RELATIVE                    82900
0000000b1658  000000000008 R_X86_64_RELATIVE                    813d0
0000000b1660  000000000008 R_X86_64_RELATIVE                    813eb
0000000b1668  000000000008 R_X86_64_RELATIVE                    82930
0000000b1670  000000000008 R_X86_64_RELATIVE                    813fd
0000000b1678  000000000008 R_X86_64_RELATIVE                    82958
0000000b1680  000000000008 R_X86_64_RELATIVE                    82978
0000000b1688  000000000008 R_X86_64_RELATIVE                    81416
0000000b1690  000000000008 R_X86_64_RELATIVE                    829a0
0000000b1698  000000000008 R_X86_64_RELATIVE                    81429
0000000b16a0  000000000008 R_X86_64_RELATIVE                    829d8
0000000b16b8  000000000008 R_X86_64_RELATIVE                    b16c0
0000000b16c0  000000000008 R_X86_64_RELATIVE                    63b00
0000000b16c8  000000000008 R_X86_64_RELATIVE                    63700
0000000b16d0  000000000008 R_X86_64_RELATIVE                    63bc0
0000000b16e0  000000000008 R_X86_64_RELATIVE                    68ec0
0000000b16e8  000000000008 R_X86_64_RELATIVE                    69500
0000000b16f0  000000000008 R_X86_64_RELATIVE                    685e0
0000000b16f8  000000000008 R_X86_64_RELATIVE                    68620
0000000b1700  000000000008 R_X86_64_RELATIVE                    69890
0000000b1708  000000000008 R_X86_64_RELATIVE                    68640
0000000b1720  000000000008 R_X86_64_RELATIVE                    69f10
0000000b1728  000000000008 R_X86_64_RELATIVE                    69e20
0000000b1730  000000000008 R_X86_64_RELATIVE                    68400
0000000b1738  000000000008 R_X86_64_RELATIVE                    69d20
0000000b1740  000000000008 R_X86_64_RELATIVE                    6a270
0000000b1748  000000000008 R_X86_64_RELATIVE                    698b0
0000000b1768  000000000008 R_X86_64_RELATIVE                    81174
0000000b1778  000000000008 R_X86_64_RELATIVE                    81181
0000000b1788  000000000008 R_X86_64_RELATIVE                    81197
0000000b1798  000000000008 R_X86_64_RELATIVE                    811a5
0000000b17a8  000000000008 R_X86_64_RELATIVE                    811b8
0000000b17b8  000000000008 R_X86_64_RELATIVE                    811cb
0000000b17c8  000000000008 R_X86_64_RELATIVE                    9840c
0000000b17d8  000000000008 R_X86_64_RELATIVE                    811de
0000000b17e8  000000000008 R_X86_64_RELATIVE                    811f5
0000000b17f8  000000000008 R_X86_64_RELATIVE                    98426
0000000b1800  000000000008 R_X86_64_RELATIVE                    24390
0000000b1808  000000000008 R_X86_64_RELATIVE                    3f5e0
0000000b1810  000000000008 R_X86_64_RELATIVE                    29cb0
0000000b1818  000000000008 R_X86_64_RELATIVE                    2d780
0000000b1820  000000000008 R_X86_64_RELATIVE                    2de50
0000000b1828  000000000008 R_X86_64_RELATIVE                    2ffd0
0000000b2008  000000000008 R_X86_64_RELATIVE                    b2008
0000000b20b0  000000000008 R_X86_64_RELATIVE                    78b13
0000000b2188  000000000008 R_X86_64_RELATIVE                    7b038
0000000b21b0  000000000008 R_X86_64_RELATIVE                    7b060
0000000b21d8  000000000008 R_X86_64_RELATIVE                    7b088
0000000b2200  000000000008 R_X86_64_RELATIVE                    7b0d8
0000000b2228  000000000008 R_X86_64_RELATIVE                    7b218
0000000b2250  000000000008 R_X86_64_RELATIVE                    7b2b0
0000000b2278  000000000008 R_X86_64_RELATIVE                    7b328
0000000b22a0  000000000008 R_X86_64_RELATIVE                    7b358
0000000b22c8  000000000008 R_X86_64_RELATIVE                    7b388
0000000b22f0  000000000008 R_X86_64_RELATIVE                    7b3b8
0000000b2318  000000000008 R_X86_64_RELATIVE                    7b4d0
0000000b2340  000000000008 R_X86_64_RELATIVE                    7b4f8
0000000b2368  000000000008 R_X86_64_RELATIVE                    7a4bf
0000000b2390  000000000008 R_X86_64_RELATIVE                    7b528
0000000b23b8  000000000008 R_X86_64_RELATIVE                    7a4dd
0000000b23e0  000000000008 R_X86_64_RELATIVE                    7b560
0000000b2408  000000000008 R_X86_64_RELATIVE                    7a4f7
0000000b2430  000000000008 R_X86_64_RELATIVE                    7a50f
0000000b2458  000000000008 R_X86_64_RELATIVE                    7b598
0000000b2480  000000000008 R_X86_64_RELATIVE                    7b5c0
0000000b24a8  000000000008 R_X86_64_RELATIVE                    7a527
0000000b24d0  000000000008 R_X86_64_RELATIVE                    7b670
0000000b24f8  000000000008 R_X86_64_RELATIVE                    7b6a0
0000000b2520  000000000008 R_X86_64_RELATIVE                    7b6d8
0000000b2548  000000000008 R_X86_64_RELATIVE                    7a53a
0000000b2570  000000000008 R_X86_64_RELATIVE                    7b710
0000000b2598  000000000008 R_X86_64_RELATIVE                    7b748
0000000b25c0  000000000008 R_X86_64_RELATIVE                    7b780
0000000b25e8  000000000008 R_X86_64_RELATIVE                    7b7a0
0000000b2610  000000000008 R_X86_64_RELATIVE                    7a543
0000000b2638  000000000008 R_X86_64_RELATIVE                    7a557
0000000b2660  000000000008 R_X86_64_RELATIVE                    7b7d0
0000000b2688  000000000008 R_X86_64_RELATIVE                    7b808
0000000b26b0  000000000008 R_X86_64_RELATIVE                    7b840
0000000b26d8  000000000008 R_X86_64_RELATIVE                    7b870
0000000b2700  000000000008 R_X86_64_RELATIVE                    7a570
0000000b2728  000000000008 R_X86_64_RELATIVE                    7b898
0000000b2750  000000000008 R_X86_64_RELATIVE                    7a586
0000000b2778  000000000008 R_X86_64_RELATIVE                    7b8e8
0000000b27a0  000000000008 R_X86_64_RELATIVE                    7b928
0000000b27c8  000000000008 R_X86_64_RELATIVE                    7b950
0000000b27f0  000000000008 R_X86_64_RELATIVE                    7b9a0
0000000b2818  000000000008 R_X86_64_RELATIVE                    7a594
0000000b2840  000000000008 R_X86_64_RELATIVE                    7b9d8
0000000b2868  000000000008 R_X86_64_RELATIVE                    7ba10
0000000b2890  000000000008 R_X86_64_RELATIVE                    7ba48
0000000b28b8  000000000008 R_X86_64_RELATIVE                    7a5ab
0000000b28e0  000000000008 R_X86_64_RELATIVE                    7ba78
0000000b2908  000000000008 R_X86_64_RELATIVE                    7bab0
0000000b2930  000000000008 R_X86_64_RELATIVE                    7baf0
0000000b2958  000000000008 R_X86_64_RELATIVE                    7bb28
0000000b2980  000000000008 R_X86_64_RELATIVE                    7bb48
0000000b29a8  000000000008 R_X86_64_RELATIVE                    7bb88
0000000b29d0  000000000008 R_X86_64_RELATIVE                    7bbc0
0000000b29f8  000000000008 R_X86_64_RELATIVE                    7bc38
0000000b2a20  000000000008 R_X86_64_RELATIVE                    7bcb0
0000000b2a48  000000000008 R_X86_64_RELATIVE                    7bce8
0000000b2a70  000000000008 R_X86_64_RELATIVE                    7bd10
0000000b2a98  000000000008 R_X86_64_RELATIVE                    7a5c8
0000000b2ac0  000000000008 R_X86_64_RELATIVE                    7a5e2
0000000b2ae8  000000000008 R_X86_64_RELATIVE                    7a5fe
0000000b2b10  000000000008 R_X86_64_RELATIVE                    7a61a
0000000b2b38  000000000008 R_X86_64_RELATIVE                    7a62c
0000000b2b60  000000000008 R_X86_64_RELATIVE                    7bd38
0000000b2b88  000000000008 R_X86_64_RELATIVE                    7bd90
0000000b2bb0  000000000008 R_X86_64_RELATIVE                    7bdb8
0000000b2bd8  000000000008 R_X86_64_RELATIVE                    7bdf0
0000000b2c00  000000000008 R_X86_64_RELATIVE                    7be28
0000000b2c28  000000000008 R_X86_64_RELATIVE                    7be58
0000000b2c50  000000000008 R_X86_64_RELATIVE                    7be98
0000000b2c78  000000000008 R_X86_64_RELATIVE                    7bed8
0000000b2ca0  000000000008 R_X86_64_RELATIVE                    7bf00
0000000b2cc8  000000000008 R_X86_64_RELATIVE                    7a643
0000000b2cf0  000000000008 R_X86_64_RELATIVE                    7bf28
0000000b2d18  000000000008 R_X86_64_RELATIVE                    7bf50
0000000b2d40  000000000008 R_X86_64_RELATIVE                    7bfc0
0000000b2d68  000000000008 R_X86_64_RELATIVE                    7a65a
0000000b2d90  000000000008 R_X86_64_RELATIVE                    7bfe8
0000000b2db8  000000000008 R_X86_64_RELATIVE                    7c020
0000000b2de0  000000000008 R_X86_64_RELATIVE                    7a66c
0000000b2e08  000000000008 R_X86_64_RELATIVE                    7c048
0000000b2e30  000000000008 R_X86_64_RELATIVE                    7a687
0000000b2e58  000000000008 R_X86_64_RELATIVE                    7a69b
0000000b2e80  000000000008 R_X86_64_RELATIVE                    7a6b4
0000000b2ea8  000000000008 R_X86_64_RELATIVE                    7a6cd
0000000b2ed0  000000000008 R_X86_64_RELATIVE                    7a6e9
0000000b2ef8  000000000008 R_X86_64_RELATIVE                    7a706
0000000b2f20  000000000008 R_X86_64_RELATIVE                    7c070
0000000b2f48  000000000008 R_X86_64_RELATIVE                    7a723
0000000b2f70  000000000008 R_X86_64_RELATIVE                    7a741
0000000b2f98  000000000008 R_X86_64_RELATIVE                    7c090
0000000b2fc0  000000000008 R_X86_64_RELATIVE                    7a758
0000000b2fe8  000000000008 R_X86_64_RELATIVE                    7c0c0
0000000b3010  000000000008 R_X86_64_RELATIVE                    7a773
0000000b3038  000000000008 R_X86_64_RELATIVE                    7c0e0
0000000b3060  000000000008 R_X86_64_RELATIVE                    7a78e
0000000b3088  000000000008 R_X86_64_RELATIVE                    7c100
0000000b30b0  000000000008 R_X86_64_RELATIVE                    7c130
0000000b30d8  000000000008 R_X86_64_RELATIVE                    7c1b0
0000000b3100  000000000008 R_X86_64_RELATIVE                    7c1e8
0000000b3128  000000000008 R_X86_64_RELATIVE                    7c258
0000000b3150  000000000008 R_X86_64_RELATIVE                    7c288
0000000b3178  000000000008 R_X86_64_RELATIVE                    7c2c8
0000000b31a0  000000000008 R_X86_64_RELATIVE                    7c2f0
0000000b31c8  000000000008 R_X86_64_RELATIVE                    7c338
0000000b31f0  000000000008 R_X86_64_RELATIVE                    7c380
0000000b3218  000000000008 R_X86_64_RELATIVE                    7c3b0
0000000b3240  000000000008 R_X86_64_RELATIVE                    7c3d0
0000000b3268  000000000008 R_X86_64_RELATIVE                    7c3f8
0000000b3290  000000000008 R_X86_64_RELATIVE                    7c418
0000000b32b8  000000000008 R_X86_64_RELATIVE                    7c448
0000000b32e0  000000000008 R_X86_64_RELATIVE                    7a7ab
0000000b3308  000000000008 R_X86_64_RELATIVE                    7a7be
0000000b3330  000000000008 R_X86_64_RELATIVE                    7c478
0000000b3358  000000000008 R_X86_64_RELATIVE                    7a7d1
0000000b3380  000000000008 R_X86_64_RELATIVE                    7c498
0000000b33a8  000000000008 R_X86_64_RELATIVE                    7c4c0
0000000b33d0  000000000008 R_X86_64_RELATIVE                    7c4f0
0000000b33f8  000000000008 R_X86_64_RELATIVE                    7c530
0000000b3420  000000000008 R_X86_64_RELATIVE                    7a7e5
0000000b3448  000000000008 R_X86_64_RELATIVE                    782b4
0000000b3470  000000000008 R_X86_64_RELATIVE                    7a7fe
0000000b3498  000000000008 R_X86_64_RELATIVE                    7c570
0000000b34c0  000000000008 R_X86_64_RELATIVE                    7c5c8
0000000b34e8  000000000008 R_X86_64_RELATIVE                    7b710
0000000b3510  000000000008 R_X86_64_RELATIVE                    7c600
0000000b3538  000000000008 R_X86_64_RELATIVE                    7a81b
0000000b3560  000000000008 R_X86_64_RELATIVE                    7c630
0000000b3588  000000000008 R_X86_64_RELATIVE                    7c658
0000000b35b0  000000000008 R_X86_64_RELATIVE                    7c698
0000000b35d8  000000000008 R_X86_64_RELATIVE                    7c6b8
0000000b3600  000000000008 R_X86_64_RELATIVE                    7a835
0000000b3628  000000000008 R_X86_64_RELATIVE                    7c6e0
0000000b3650  000000000008 R_X86_64_RELATIVE                    7c700
0000000b3678  000000000008 R_X86_64_RELATIVE                    7c730
0000000b36a0  000000000008 R_X86_64_RELATIVE                    7a851
0000000b36c8  000000000008 R_X86_64_RELATIVE                    7c750
0000000b36f0  000000000008 R_X86_64_RELATIVE                    7c778
0000000b3718  000000000008 R_X86_64_RELATIVE                    7c7a8
0000000b3740  000000000008 R_X86_64_RELATIVE                    7c7d0
0000000b3768  000000000008 R_X86_64_RELATIVE                    7a86b
0000000b3790  000000000008 R_X86_64_RELATIVE                    7c7f8
0000000b37b8  000000000008 R_X86_64_RELATIVE                    7c820
0000000b37e0  000000000008 R_X86_64_RELATIVE                    7c848
0000000b3808  000000000008 R_X86_64_RELATIVE                    7c870
0000000b3830  000000000008 R_X86_64_RELATIVE                    7c8b0
0000000b3858  000000000008 R_X86_64_RELATIVE                    7a87f
0000000b3880  000000000008 R_X86_64_RELATIVE                    7c8e0
0000000b38a8  000000000008 R_X86_64_RELATIVE                    7c910
0000000b38d0  000000000008 R_X86_64_RELATIVE                    7c948
0000000b38f8  000000000008 R_X86_64_RELATIVE                    7c978
0000000b3920  000000000008 R_X86_64_RELATIVE                    7c9c0
0000000b3948  000000000008 R_X86_64_RELATIVE                    7c9e8
0000000b3970  000000000008 R_X86_64_RELATIVE                    7ca18
0000000b3998  000000000008 R_X86_64_RELATIVE                    7ca48
0000000b39c0  000000000008 R_X86_64_RELATIVE                    7ca80
0000000b39e8  000000000008 R_X86_64_RELATIVE                    7cac0
0000000b3a10  000000000008 R_X86_64_RELATIVE                    7caf0
0000000b3a38  000000000008 R_X86_64_RELATIVE                    7cb20
0000000b3a60  000000000008 R_X86_64_RELATIVE                    7cb60
0000000b3a88  000000000008 R_X86_64_RELATIVE                    7cb90
0000000b3ab0  000000000008 R_X86_64_RELATIVE                    7cbd8
0000000b3ad8  000000000008 R_X86_64_RELATIVE                    7cc20
0000000b3b00  000000000008 R_X86_64_RELATIVE                    7cc68
0000000b3b28  000000000008 R_X86_64_RELATIVE                    7cca8
0000000b3b50  000000000008 R_X86_64_RELATIVE                    7cce8
0000000b3b78  000000000008 R_X86_64_RELATIVE                    7cd20
0000000b3ba0  000000000008 R_X86_64_RELATIVE                    7cd48
0000000b3bc8  000000000008 R_X86_64_RELATIVE                    7cd98
0000000b3bf0  000000000008 R_X86_64_RELATIVE                    7cdd0
0000000b3c18  000000000008 R_X86_64_RELATIVE                    7cdf8
0000000b3c40  000000000008 R_X86_64_RELATIVE                    7ce18
0000000b3c68  000000000008 R_X86_64_RELATIVE                    7ce48
0000000b3c90  000000000008 R_X86_64_RELATIVE                    7a89b
0000000b3cb8  000000000008 R_X86_64_RELATIVE                    7ce68
0000000b3ce0  000000000008 R_X86_64_RELATIVE                    7ceb0
0000000b3d08  000000000008 R_X86_64_RELATIVE                    7ced8
0000000b3d30  000000000008 R_X86_64_RELATIVE                    7cf10
0000000b3d58  000000000008 R_X86_64_RELATIVE                    7cf40
0000000b3d80  000000000008 R_X86_64_RELATIVE                    7cfb0
0000000b3da8  000000000008 R_X86_64_RELATIVE                    7cff0
0000000b3dd0  000000000008 R_X86_64_RELATIVE                    7d058
0000000b3df8  000000000008 R_X86_64_RELATIVE                    7d0b0
0000000b3e20  000000000008 R_X86_64_RELATIVE                    7d0f0
0000000b3e48  000000000008 R_X86_64_RELATIVE                    7d138
0000000b3e70  000000000008 R_X86_64_RELATIVE                    7d188
0000000b3e98  000000000008 R_X86_64_RELATIVE                    7d1b0
0000000b3ec0  000000000008 R_X86_64_RELATIVE                    7d1e8
0000000b3ee8  000000000008 R_X86_64_RELATIVE                    7d248
0000000b3f10  000000000008 R_X86_64_RELATIVE                    7d280
0000000b3f38  000000000008 R_X86_64_RELATIVE                    7d2d0
0000000b3f60  000000000008 R_X86_64_RELATIVE                    7d308
0000000b3f88  000000000008 R_X86_64_RELATIVE                    7d340
0000000b3fb0  000000000008 R_X86_64_RELATIVE                    7d380
0000000b3fd8  000000000008 R_X86_64_RELATIVE                    7d3c8
0000000b4000  000000000008 R_X86_64_RELATIVE                    7d400
0000000b4028  000000000008 R_X86_64_RELATIVE                    7d428
0000000b4050  000000000008 R_X86_64_RELATIVE                    7d478
0000000b4078  000000000008 R_X86_64_RELATIVE                    7d4a8
0000000b40a0  000000000008 R_X86_64_RELATIVE                    7d4e8
0000000b40c8  000000000008 R_X86_64_RELATIVE                    7d518
0000000b40f0  000000000008 R_X86_64_RELATIVE                    7d538
0000000b4118  000000000008 R_X86_64_RELATIVE                    7a8b5
0000000b4140  000000000008 R_X86_64_RELATIVE                    7d578
0000000b4168  000000000008 R_X86_64_RELATIVE                    7d5b0
0000000b4190  000000000008 R_X86_64_RELATIVE                    7d5e8
0000000b41b8  000000000008 R_X86_64_RELATIVE                    7d620
0000000b41e0  000000000008 R_X86_64_RELATIVE                    7d660
0000000b4208  000000000008 R_X86_64_RELATIVE                    7d6a8
0000000b4230  000000000008 R_X86_64_RELATIVE                    7d6d8
0000000b4258  000000000008 R_X86_64_RELATIVE                    7d708
0000000b4280  000000000008 R_X86_64_RELATIVE                    7d748
0000000b42a8  000000000008 R_X86_64_RELATIVE                    7d770
0000000b42d0  000000000008 R_X86_64_RELATIVE                    7a8d3
0000000b42f8  000000000008 R_X86_64_RELATIVE                    7a8e6
0000000b4320  000000000008 R_X86_64_RELATIVE                    7a5c6
0000000b4348  000000000008 R_X86_64_RELATIVE                    7d7e0
0000000b4370  000000000008 R_X86_64_RELATIVE                    7a8ea
0000000b4398  000000000008 R_X86_64_RELATIVE                    7d808
0000000b43c0  000000000008 R_X86_64_RELATIVE                    7d840
0000000b43e8  000000000008 R_X86_64_RELATIVE                    7a905
0000000b4410  000000000008 R_X86_64_RELATIVE                    7d878
0000000b4438  000000000008 R_X86_64_RELATIVE                    7a90d
0000000b4460  000000000008 R_X86_64_RELATIVE                    7d8b0
0000000b4488  000000000008 R_X86_64_RELATIVE                    7a92a
0000000b44b0  000000000008 R_X86_64_RELATIVE                    7a946
0000000b44d8  000000000008 R_X86_64_RELATIVE                    7d900
0000000b4500  000000000008 R_X86_64_RELATIVE                    7d928
0000000b4528  000000000008 R_X86_64_RELATIVE                    782b4
0000000b4550  000000000008 R_X86_64_RELATIVE                    782b4
0000000b4578  000000000008 R_X86_64_RELATIVE                    7a956
0000000b45a0  000000000008 R_X86_64_RELATIVE                    7a96f
0000000b45c8  000000000008 R_X86_64_RELATIVE                    7d950
0000000b45f0  000000000008 R_X86_64_RELATIVE                    7a98d
0000000b4618  000000000008 R_X86_64_RELATIVE                    7a9a3
0000000b4640  000000000008 R_X86_64_RELATIVE                    7a5c6
0000000b4668  000000000008 R_X86_64_RELATIVE                    7d978
0000000b4690  000000000008 R_X86_64_RELATIVE                    7d9c0
0000000b46b8  000000000008 R_X86_64_RELATIVE                    7d9f0
0000000b46e0  000000000008 R_X86_64_RELATIVE                    7da28
0000000b4708  000000000008 R_X86_64_RELATIVE                    7da48
0000000b4730  000000000008 R_X86_64_RELATIVE                    7a9a7
0000000b4758  000000000008 R_X86_64_RELATIVE                    7a9bd
0000000b4780  000000000008 R_X86_64_RELATIVE                    7a9d8
0000000b47a8  000000000008 R_X86_64_RELATIVE                    7da70
0000000b47d0  000000000008 R_X86_64_RELATIVE                    7a9e7
0000000b47f8  000000000008 R_X86_64_RELATIVE                    7a9fe
0000000b4820  000000000008 R_X86_64_RELATIVE                    7daa0
0000000b4848  000000000008 R_X86_64_RELATIVE                    7aa10
0000000b4870  000000000008 R_X86_64_RELATIVE                    7aa2a
0000000b4898  000000000008 R_X86_64_RELATIVE                    7dac8
0000000b48c0  000000000008 R_X86_64_RELATIVE                    7db00
0000000b48e8  000000000008 R_X86_64_RELATIVE                    7aa45
0000000b4910  000000000008 R_X86_64_RELATIVE                    7aa5f
0000000b4938  000000000008 R_X86_64_RELATIVE                    7aa7c
0000000b4960  000000000008 R_X86_64_RELATIVE                    7aa9a
0000000b4988  000000000008 R_X86_64_RELATIVE                    7aab2
0000000b49b0  000000000008 R_X86_64_RELATIVE                    7db30
0000000b49d8  000000000008 R_X86_64_RELATIVE                    7db50
0000000b4a00  000000000008 R_X86_64_RELATIVE                    7db78
0000000b4a28  000000000008 R_X86_64_RELATIVE                    7dba8
0000000b4a50  000000000008 R_X86_64_RELATIVE                    7dbd0
0000000b4a78  000000000008 R_X86_64_RELATIVE                    7dc00
0000000b4aa0  000000000008 R_X86_64_RELATIVE                    7dc30
0000000b4ac8  000000000008 R_X86_64_RELATIVE                    7aacb
0000000b4af0  000000000008 R_X86_64_RELATIVE                    7aae7
0000000b4b18  000000000008 R_X86_64_RELATIVE                    7ab00
0000000b4b40  000000000008 R_X86_64_RELATIVE                    7dc58
0000000b4b68  000000000008 R_X86_64_RELATIVE                    7dc88
0000000b4b90  000000000008 R_X86_64_RELATIVE                    7ab1a
0000000b4bb8  000000000008 R_X86_64_RELATIVE                    7dca8
0000000b4be0  000000000008 R_X86_64_RELATIVE                    7dcd0
0000000b4c08  000000000008 R_X86_64_RELATIVE                    7dcf8
0000000b4c30  000000000008 R_X86_64_RELATIVE                    7dd20
0000000b4c58  000000000008 R_X86_64_RELATIVE                    7ab33
0000000b4c80  000000000008 R_X86_64_RELATIVE                    7dd48
0000000b4ca8  000000000008 R_X86_64_RELATIVE                    7ab51
0000000b4cd0  000000000008 R_X86_64_RELATIVE                    7ab6c
0000000b4cf8  000000000008 R_X86_64_RELATIVE                    7dd70
0000000b4d20  000000000008 R_X86_64_RELATIVE                    7dd90
0000000b4d48  000000000008 R_X86_64_RELATIVE                    7ab89
0000000b4d70  000000000008 R_X86_64_RELATIVE                    7ab9f
0000000b4d98  000000000008 R_X86_64_RELATIVE                    7abb2
0000000b4dc0  000000000008 R_X86_64_RELATIVE                    7abce
0000000b4de8  000000000008 R_X86_64_RELATIVE                    7ddc0
0000000b4e10  000000000008 R_X86_64_RELATIVE                    7abe2
0000000b4e38  000000000008 R_X86_64_RELATIVE                    7de00
0000000b4e60  000000000008 R_X86_64_RELATIVE                    7de20
0000000b4e88  000000000008 R_X86_64_RELATIVE                    7de40
0000000b4eb0  000000000008 R_X86_64_RELATIVE                    7abff
0000000b4ed8  000000000008 R_X86_64_RELATIVE                    7de60
0000000b4f00  000000000008 R_X86_64_RELATIVE                    7dea0
0000000b4f28  000000000008 R_X86_64_RELATIVE                    7d840
0000000b4f50  000000000008 R_X86_64_RELATIVE                    7ac10
0000000b4f78  000000000008 R_X86_64_RELATIVE                    7dec8
0000000b4fa0  000000000008 R_X86_64_RELATIVE                    7dee8
0000000b4fc8  000000000008 R_X86_64_RELATIVE                    7df08
0000000b4ff0  000000000008 R_X86_64_RELATIVE                    7df38
0000000b5018  000000000008 R_X86_64_RELATIVE                    7ac2b
0000000b5040  000000000008 R_X86_64_RELATIVE                    7df58
0000000b5068  000000000008 R_X86_64_RELATIVE                    7df88
0000000b5090  000000000008 R_X86_64_RELATIVE                    7ac41
0000000b50b8  000000000008 R_X86_64_RELATIVE                    7ac5e
0000000b50e0  000000000008 R_X86_64_RELATIVE                    7dfc8
0000000b5108  000000000008 R_X86_64_RELATIVE                    7e008
0000000b5130  000000000008 R_X86_64_RELATIVE                    7e048
0000000b5158  000000000008 R_X86_64_RELATIVE                    7e068
0000000b5180  000000000008 R_X86_64_RELATIVE                    7e090
0000000b51a8  000000000008 R_X86_64_RELATIVE                    7e0c0
0000000b51d0  000000000008 R_X86_64_RELATIVE                    7e0f0
0000000b51f8  000000000008 R_X86_64_RELATIVE                    7e128
0000000b5220  000000000008 R_X86_64_RELATIVE                    7e160
0000000b5248  000000000008 R_X86_64_RELATIVE                    7ac7c
0000000b5270  000000000008 R_X86_64_RELATIVE                    7e188
0000000b5298  000000000008 R_X86_64_RELATIVE                    7e1b8
0000000b52c0  000000000008 R_X86_64_RELATIVE                    7e208
0000000b52e8  000000000008 R_X86_64_RELATIVE                    7e238
0000000b5310  000000000008 R_X86_64_RELATIVE                    7e258
0000000b5338  000000000008 R_X86_64_RELATIVE                    7ac98
0000000b5360  000000000008 R_X86_64_RELATIVE                    7acac
0000000b5388  000000000008 R_X86_64_RELATIVE                    7acc0
0000000b53b0  000000000008 R_X86_64_RELATIVE                    7acdb
0000000b53d8  000000000008 R_X86_64_RELATIVE                    7e280
0000000b5400  000000000008 R_X86_64_RELATIVE                    7e2b0
0000000b5428  000000000008 R_X86_64_RELATIVE                    7acec
0000000b5450  000000000008 R_X86_64_RELATIVE                    7ad06
0000000b5478  000000000008 R_X86_64_RELATIVE                    7e2e0
0000000b54a0  000000000008 R_X86_64_RELATIVE                    7e308
0000000b54c8  000000000008 R_X86_64_RELATIVE                    7e340
0000000b54f0  000000000008 R_X86_64_RELATIVE                    7e378
0000000b5518  000000000008 R_X86_64_RELATIVE                    7e3a8
0000000b5540  000000000008 R_X86_64_RELATIVE                    7e3e8
0000000b5568  000000000008 R_X86_64_RELATIVE                    7e418
0000000b5590  000000000008 R_X86_64_RELATIVE                    7e440
0000000b55b8  000000000008 R_X86_64_RELATIVE                    7a7ab
0000000b55e0  000000000008 R_X86_64_RELATIVE                    7e480
0000000b5608  000000000008 R_X86_64_RELATIVE                    7e4a8
0000000b5630  000000000008 R_X86_64_RELATIVE                    7ad22
0000000b5658  000000000008 R_X86_64_RELATIVE                    7ad3d
0000000b5680  000000000008 R_X86_64_RELATIVE                    7dc58
0000000b56a8  000000000008 R_X86_64_RELATIVE                    7ad5b
0000000b56d0  000000000008 R_X86_64_RELATIVE                    7ad75
0000000b56f8  000000000008 R_X86_64_RELATIVE                    7e4c8
0000000b5720  000000000008 R_X86_64_RELATIVE                    7e518
0000000b5748  000000000008 R_X86_64_RELATIVE                    7ad8a
0000000b5770  000000000008 R_X86_64_RELATIVE                    7e570
0000000b5798  000000000008 R_X86_64_RELATIVE                    7e598
0000000b57c0  000000000008 R_X86_64_RELATIVE                    7e5c8
0000000b57e8  000000000008 R_X86_64_RELATIVE                    7ad9c
0000000b5810  000000000008 R_X86_64_RELATIVE                    7adb5
0000000b5838  000000000008 R_X86_64_RELATIVE                    7a5c6
0000000b5860  000000000008 R_X86_64_RELATIVE                    7e5f8
0000000b5888  000000000008 R_X86_64_RELATIVE                    7adb9
0000000b58b0  000000000008 R_X86_64_RELATIVE                    7adc8
0000000b58d8  000000000008 R_X86_64_RELATIVE                    7e620
0000000b5900  000000000008 R_X86_64_RELATIVE                    7e648
0000000b5928  000000000008 R_X86_64_RELATIVE                    7e6f8
0000000b5950  000000000008 R_X86_64_RELATIVE                    7e720
0000000b5978  000000000008 R_X86_64_RELATIVE                    7e758
0000000b59a0  000000000008 R_X86_64_RELATIVE                    7e7a0
0000000b59c8  000000000008 R_X86_64_RELATIVE                    7e7d0
0000000b59f0  000000000008 R_X86_64_RELATIVE                    7e7f8
0000000b5a18  000000000008 R_X86_64_RELATIVE                    7add2
0000000b5a40  000000000008 R_X86_64_RELATIVE                    7ade6
0000000b5a68  000000000008 R_X86_64_RELATIVE                    7adeb
0000000b5a90  000000000008 R_X86_64_RELATIVE                    7a5c6
0000000b5ab8  000000000008 R_X86_64_RELATIVE                    7adf0
0000000b5ae0  000000000008 R_X86_64_RELATIVE                    7ae04
0000000b5b08  000000000008 R_X86_64_RELATIVE                    7ae09
0000000b5b30  000000000008 R_X86_64_RELATIVE                    7a5c6
0000000b5b58  000000000008 R_X86_64_RELATIVE                    7e820
0000000b5b80  000000000008 R_X86_64_RELATIVE                    7e858
0000000b5ba8  000000000008 R_X86_64_RELATIVE                    7e890
0000000b5bd0  000000000008 R_X86_64_RELATIVE                    7e8b8
0000000b5bf8  000000000008 R_X86_64_RELATIVE                    7e8f0
0000000b5c20  000000000008 R_X86_64_RELATIVE                    7e918
0000000b5c48  000000000008 R_X86_64_RELATIVE                    7e978
0000000b5c70  000000000008 R_X86_64_RELATIVE                    7e9a8
0000000b5c98  000000000008 R_X86_64_RELATIVE                    7e9d0
0000000b5cc0  000000000008 R_X86_64_RELATIVE                    7ae0e
0000000b5ce8  000000000008 R_X86_64_RELATIVE                    7ae19
0000000b5d10  000000000008 R_X86_64_RELATIVE                    7ae24
0000000b5d38  000000000008 R_X86_64_RELATIVE                    7ae2f
0000000b5d60  000000000008 R_X86_64_RELATIVE                    7e9f8
0000000b5d88  000000000008 R_X86_64_RELATIVE                    7ea30
0000000b5db0  000000000008 R_X86_64_RELATIVE                    7ea68
0000000b5dd8  000000000008 R_X86_64_RELATIVE                    7ea90
0000000b5e00  000000000008 R_X86_64_RELATIVE                    7ae3a
0000000b5e28  000000000008 R_X86_64_RELATIVE                    7eab8
0000000b5e50  000000000008 R_X86_64_RELATIVE                    7eae0
0000000b5e78  000000000008 R_X86_64_RELATIVE                    7eb08
0000000b5ea0  000000000008 R_X86_64_RELATIVE                    7eb30
0000000b5ec8  000000000008 R_X86_64_RELATIVE                    7eb60
0000000b5f20  000000000008 R_X86_64_RELATIVE                    7ed6e
0000000b5f28  000000000008 R_X86_64_RELATIVE                    7ed82
0000000b5f30  000000000008 R_X86_64_RELATIVE                    7ed94
0000000b5f38  000000000008 R_X86_64_RELATIVE                    7ed9b
0000000b5f40  000000000008 R_X86_64_RELATIVE                    7eda3
0000000b5f48  000000000008 R_X86_64_RELATIVE                    7f148
0000000b5f50  000000000008 R_X86_64_RELATIVE                    7edad
0000000b5f58  000000000008 R_X86_64_RELATIVE                    7edb8
0000000b5f60  000000000008 R_X86_64_RELATIVE                    7edc1
0000000b5f68  000000000008 R_X86_64_RELATIVE                    7edc8
0000000b5f70  000000000008 R_X86_64_RELATIVE                    7eddd
0000000b5f78  000000000008 R_X86_64_RELATIVE                    7ede9
0000000b5f80  000000000008 R_X86_64_RELATIVE                    7edfc
0000000b5f88  000000000008 R_X86_64_RELATIVE                    7ee03
0000000b5f90  000000000008 R_X86_64_RELATIVE                    7ee10
0000000b5f98  000000000008 R_X86_64_RELATIVE                    7ee17
0000000b5fa0  000000000008 R_X86_64_RELATIVE                    7ee20
0000000b5fa8  000000000008 R_X86_64_RELATIVE                    7ee29
0000000b5fb0  000000000008 R_X86_64_RELATIVE                    7ee35
0000000b5fb8  000000000008 R_X86_64_RELATIVE                    7ee40
0000000b5fc0  000000000008 R_X86_64_RELATIVE                    7ee52
0000000b5fc8  000000000008 R_X86_64_RELATIVE                    7ee5b
0000000b5fd0  000000000008 R_X86_64_RELATIVE                    7ee65
0000000b5fd8  000000000008 R_X86_64_RELATIVE                    7ee71
0000000b5fe0  000000000008 R_X86_64_RELATIVE                    7ee78
0000000b5fe8  000000000008 R_X86_64_RELATIVE                    7ee81
0000000b5ff0  000000000008 R_X86_64_RELATIVE                    7ee8c
0000000b5ff8  000000000008 R_X86_64_RELATIVE                    7ee95
0000000b6000  000000000008 R_X86_64_RELATIVE                    7eea1
0000000b6008  000000000008 R_X86_64_RELATIVE                    7eea9
0000000b6010  000000000008 R_X86_64_RELATIVE                    7eeb1
0000000b6018  000000000008 R_X86_64_RELATIVE                    7eebe
0000000b6048  000000000008 R_X86_64_RELATIVE                    7f74a
0000000b6058  000000000008 R_X86_64_RELATIVE                    7f755
0000000b6068  000000000008 R_X86_64_RELATIVE                    7f760
0000000b6078  000000000008 R_X86_64_RELATIVE                    7f76b
0000000b6088  000000000008 R_X86_64_RELATIVE                    7f777
0000000b6098  000000000008 R_X86_64_RELATIVE                    7f783
0000000b60c8  000000000008 R_X86_64_RELATIVE                    7f791
0000000b60d8  000000000008 R_X86_64_RELATIVE                    7f79c
0000000b60e8  000000000008 R_X86_64_RELATIVE                    7f7a7
0000000b6108  000000000008 R_X86_64_RELATIVE                    7f7b2
0000000b6118  000000000008 R_X86_64_RELATIVE                    7f7be
0000000b6148  000000000008 R_X86_64_RELATIVE                    7f7ca
0000000b6158  000000000008 R_X86_64_RELATIVE                    7f7d5
0000000b6168  000000000008 R_X86_64_RELATIVE                    7f7e0
0000000b6178  000000000008 R_X86_64_RELATIVE                    7f7eb
0000000b6188  000000000008 R_X86_64_RELATIVE                    7f7f6
0000000b6198  000000000008 R_X86_64_RELATIVE                    7f801
0000000b61a8  000000000008 R_X86_64_RELATIVE                    7f80c
0000000b61b8  000000000008 R_X86_64_RELATIVE                    7f817
0000000b61e8  000000000008 R_X86_64_RELATIVE                    7f822
0000000b61f8  000000000008 R_X86_64_RELATIVE                    7f82d
0000000b6208  000000000008 R_X86_64_RELATIVE                    7f838
0000000b6218  000000000008 R_X86_64_RELATIVE                    7f843
0000000b6228  000000000008 R_X86_64_RELATIVE                    7f84e
0000000b6238  000000000008 R_X86_64_RELATIVE                    7f859
0000000b6248  000000000008 R_X86_64_RELATIVE                    7f864
0000000b6258  000000000008 R_X86_64_RELATIVE                    7f86f
0000000b6268  000000000008 R_X86_64_RELATIVE                    7f791
0000000b6278  000000000008 R_X86_64_RELATIVE                    7f79c
0000000b6288  000000000008 R_X86_64_RELATIVE                    7f7a7
0000000b62a8  000000000008 R_X86_64_RELATIVE                    7f87a
0000000b62b8  000000000008 R_X86_64_RELATIVE                    7f885
0000000b62c8  000000000008 R_X86_64_RELATIVE                    7f88e
0000000b62d8  000000000008 R_X86_64_RELATIVE                    7f897
0000000b62e8  000000000008 R_X86_64_RELATIVE                    7f8a2
0000000b62f8  000000000008 R_X86_64_RELATIVE                    7f8ab
0000000b6308  000000000008 R_X86_64_RELATIVE                    7f8b4
0000000b6318  000000000008 R_X86_64_RELATIVE                    7f8bd
0000000b6328  000000000008 R_X86_64_RELATIVE                    7f8c5
0000000b6348  000000000008 R_X86_64_RELATIVE                    7f8cf
0000000b6358  000000000008 R_X86_64_RELATIVE                    7f8d6
0000000b6368  000000000008 R_X86_64_RELATIVE                    7f8dd
0000000b6378  000000000008 R_X86_64_RELATIVE                    7f8e5
0000000b6388  000000000008 R_X86_64_RELATIVE                    7f8ec
0000000b6398  000000000008 R_X86_64_RELATIVE                    7f8f4
0000000b63a8  000000000008 R_X86_64_RELATIVE                    7f8fc
0000000b63b8  000000000008 R_X86_64_RELATIVE                    7f903
0000000b63c8  000000000008 R_X86_64_RELATIVE                    7f90a
0000000b63d8  000000000008 R_X86_64_RELATIVE                    7f911
0000000b63e8  000000000008 R_X86_64_RELATIVE                    7f919
0000000b63f8  000000000008 R_X86_64_RELATIVE                    7f921
0000000b6408  000000000008 R_X86_64_RELATIVE                    7f929
0000000b6418  000000000008 R_X86_64_RELATIVE                    7f931
0000000b6428  000000000008 R_X86_64_RELATIVE                    7f939
0000000b6438  000000000008 R_X86_64_RELATIVE                    7f941
0000000b6448  000000000008 R_X86_64_RELATIVE                    7f949
0000000b6458  000000000008 R_X86_64_RELATIVE                    7f953
0000000b6468  000000000008 R_X86_64_RELATIVE                    7f95b
0000000b6478  000000000008 R_X86_64_RELATIVE                    7f963
0000000b6488  000000000008 R_X86_64_RELATIVE                    7f96b
0000000b6498  000000000008 R_X86_64_RELATIVE                    7f973
0000000b64a8  000000000008 R_X86_64_RELATIVE                    7f97b
0000000b64b8  000000000008 R_X86_64_RELATIVE                    7f983
0000000b64c8  000000000008 R_X86_64_RELATIVE                    7f98a
0000000b64d8  000000000008 R_X86_64_RELATIVE                    7f992
0000000b64e8  000000000008 R_X86_64_RELATIVE                    7f99a
0000000b64f8  000000000008 R_X86_64_RELATIVE                    7f9a4
0000000b6508  000000000008 R_X86_64_RELATIVE                    7f9ac
0000000b6518  000000000008 R_X86_64_RELATIVE                    7f891
0000000b6528  000000000008 R_X86_64_RELATIVE                    7f9b5
0000000b6538  000000000008 R_X86_64_RELATIVE                    7f9bd
0000000b6548  000000000008 R_X86_64_RELATIVE                    7f9c4
0000000b6560  000000000008 R_X86_64_RELATIVE                    44370
0000000b6568  000000000008 R_X86_64_RELATIVE                    44620
0000000b6570  000000000008 R_X86_64_RELATIVE                    44330
0000000b6580  000000000008 R_X86_64_RELATIVE                    44420
0000000b6588  000000000008 R_X86_64_RELATIVE                    446e0
0000000b6590  000000000008 R_X86_64_RELATIVE                    443e0
0000000b65a0  000000000008 R_X86_64_RELATIVE                    441c0
0000000b65a8  000000000008 R_X86_64_RELATIVE                    44490
0000000b65b0  000000000008 R_X86_64_RELATIVE                    44050
0000000b65c0  000000000008 R_X86_64_RELATIVE                    44150
0000000b65c8  000000000008 R_X86_64_RELATIVE                    44320
0000000b65d0  000000000008 R_X86_64_RELATIVE                    442d0
0000000b65d8  000000000008 R_X86_64_RELATIVE                    442c0
0000000b65e0  000000000008 R_X86_64_RELATIVE                    44280
0000000b6600  000000000008 R_X86_64_RELATIVE                    b6620
0000000b6628  000000000008 R_X86_64_RELATIVE                    80c43
0000000b6630  000000000008 R_X86_64_RELATIVE                    46bb0
0000000b6638  000000000008 R_X86_64_RELATIVE                    46aa0
0000000b6640  000000000008 R_X86_64_RELATIVE                    46780
0000000b6648  000000000008 R_X86_64_RELATIVE                    471a0
0000000b6650  000000000008 R_X86_64_RELATIVE                    472c0
0000000b6658  000000000008 R_X86_64_RELATIVE                    466e0
0000000b6660  000000000008 R_X86_64_RELATIVE                    469e0
0000000b6668  000000000008 R_X86_64_RELATIVE                    465c0
0000000b6670  000000000008 R_X86_64_RELATIVE                    464b0
0000000b6678  000000000008 R_X86_64_RELATIVE                    47080
0000000b6680  000000000008 R_X86_64_RELATIVE                    473e0
0000000b6688  000000000008 R_X86_64_RELATIVE                    468f0
0000000b6690  000000000008 R_X86_64_RELATIVE                    46840
0000000b6698  000000000008 R_X86_64_RELATIVE                    46510
0000000b6728  000000000008 R_X86_64_RELATIVE                    86b29
0000000b6738  000000000008 R_X86_64_RELATIVE                    86af8
0000000b6748  000000000008 R_X86_64_RELATIVE                    86b11
0000000b6758  000000000008 R_X86_64_RELATIVE                    86b2e
0000000b6768  000000000008 R_X86_64_RELATIVE                    86b3d
0000000b6778  000000000008 R_X86_64_RELATIVE                    86b47
0000000b6788  000000000008 R_X86_64_RELATIVE                    86b50
0000000b6798  000000000008 R_X86_64_RELATIVE                    86b58
0000000b67c0  000000000008 R_X86_64_RELATIVE                    b67e0
0000000b67e8  000000000008 R_X86_64_RELATIVE                    984b7
0000000b67f0  000000000008 R_X86_64_RELATIVE                    6fc10
0000000b67f8  000000000008 R_X86_64_RELATIVE                    6f620
0000000b6800  000000000008 R_X86_64_RELATIVE                    6e960
0000000b6808  000000000008 R_X86_64_RELATIVE                    6eb10
0000000b6810  000000000008 R_X86_64_RELATIVE                    6f320
0000000b6818  000000000008 R_X86_64_RELATIVE                    6e9f0
0000000b6820  000000000008 R_X86_64_RELATIVE                    6f570
0000000b6828  000000000008 R_X86_64_RELATIVE                    6f410
0000000b6830  000000000008 R_X86_64_RELATIVE                    6ea50
0000000b6838  000000000008 R_X86_64_RELATIVE                    6eab0
0000000b6840  000000000008 R_X86_64_RELATIVE                    6f2a0
0000000b6848  000000000008 R_X86_64_RELATIVE                    6f390
0000000b6850  000000000008 R_X86_64_RELATIVE                    6f330
0000000b6858  000000000008 R_X86_64_RELATIVE                    6f220
0000000b68e0  000000000008 R_X86_64_RELATIVE                    b6900
0000000b6908  000000000008 R_X86_64_RELATIVE                    984ef
0000000b6910  000000000008 R_X86_64_RELATIVE                    71dc0
0000000b6918  000000000008 R_X86_64_RELATIVE                    71730
0000000b6920  000000000008 R_X86_64_RELATIVE                    71670
0000000b6928  000000000008 R_X86_64_RELATIVE                    71360
0000000b6930  000000000008 R_X86_64_RELATIVE                    70cb0
0000000b6938  000000000008 R_X86_64_RELATIVE                    71540
0000000b6940  000000000008 R_X86_64_RELATIVE                    71480
0000000b6948  000000000008 R_X86_64_RELATIVE                    71370
0000000b6950  000000000008 R_X86_64_RELATIVE                    70cc0
0000000b6958  000000000008 R_X86_64_RELATIVE                    71100
0000000b6960  000000000008 R_X86_64_RELATIVE                    70aa0
0000000b6968  000000000008 R_X86_64_RELATIVE                    70400
0000000b6970  000000000008 R_X86_64_RELATIVE                    703b0
0000000b6978  000000000008 R_X86_64_RELATIVE                    70280
0000000b69f0  000000000008 R_X86_64_RELATIVE                    b6a00
0000000b6a08  000000000008 R_X86_64_RELATIVE                    98503
0000000b6a10  000000000008 R_X86_64_RELATIVE                    71d40
0000000b6a18  000000000008 R_X86_64_RELATIVE                    71730
0000000b6a20  000000000008 R_X86_64_RELATIVE                    71670
0000000b6a28  000000000008 R_X86_64_RELATIVE                    71360
0000000b6a30  000000000008 R_X86_64_RELATIVE                    70cb0
0000000b6a38  000000000008 R_X86_64_RELATIVE                    71540
0000000b6a40  000000000008 R_X86_64_RELATIVE                    71480
0000000b6a48  000000000008 R_X86_64_RELATIVE                    71370
0000000b6a50  000000000008 R_X86_64_RELATIVE                    70cc0
0000000b6a58  000000000008 R_X86_64_RELATIVE                    71100
0000000b6a60  000000000008 R_X86_64_RELATIVE                    70aa0
0000000b6a68  000000000008 R_X86_64_RELATIVE                    70400
0000000b6a70  000000000008 R_X86_64_RELATIVE                    703b0
0000000b6a78  000000000008 R_X86_64_RELATIVE                    70280
0000000b6b08  000000000008 R_X86_64_RELATIVE                    72ed0
0000000b6b10  000000000008 R_X86_64_RELATIVE                    72ab0
0000000b6b18  000000000008 R_X86_64_RELATIVE                    72f80
0000000b6b20  000000000008 R_X86_64_RELATIVE                    73170
0000000b6b28  000000000008 R_X86_64_RELATIVE                    73280
0000000b6b30  000000000008 R_X86_64_RELATIVE                    73150
0000000b6b38  000000000008 R_X86_64_RELATIVE                    72e50
0000000b6b40  000000000008 R_X86_64_RELATIVE                    72b10
0000000b6b48  000000000008 R_X86_64_RELATIVE                    72b60
0000000b6b50  000000000008 R_X86_64_RELATIVE                    72fe0
0000000b6b58  000000000008 R_X86_64_RELATIVE                    72f20
0000000b6b60  000000000008 R_X86_64_RELATIVE                    72f50
0000000b6b68  000000000008 R_X86_64_RELATIVE                    72ea0
0000000b6b70  000000000008 R_X86_64_RELATIVE                    72e70
0000000b6b78  000000000008 R_X86_64_RELATIVE                    72d00
0000000b6b80  000000000008 R_X86_64_RELATIVE                    72bb0
0000000b6ba8  000000000008 R_X86_64_RELATIVE                    733b0
0000000b6bb0  000000000008 R_X86_64_RELATIVE                    737a0
0000000b6bb8  000000000008 R_X86_64_RELATIVE                    73d40
0000000b6bc0  000000000008 R_X86_64_RELATIVE                    73cb0
0000000b6bc8  000000000008 R_X86_64_RELATIVE                    73be0
0000000b6bd0  000000000008 R_X86_64_RELATIVE                    74070
0000000b6bd8  000000000008 R_X86_64_RELATIVE                    734f0
0000000b6be0  000000000008 R_X86_64_RELATIVE                    73bc0
0000000b6be8  000000000008 R_X86_64_RELATIVE                    74050
0000000b6bf0  000000000008 R_X86_64_RELATIVE                    74090
0000000b6bf8  000000000008 R_X86_64_RELATIVE                    73aa0
0000000b6c00  000000000008 R_X86_64_RELATIVE                    74160
0000000b6c08  000000000008 R_X86_64_RELATIVE                    73770
0000000b6c10  000000000008 R_X86_64_RELATIVE                    73510
0000000b6c18  000000000008 R_X86_64_RELATIVE                    743f0
0000000b6c20  000000000008 R_X86_64_RELATIVE                    74300
0000000b6c28  000000000008 R_X86_64_RELATIVE                    764a0
0000000b6c48  000000000008 R_X86_64_RELATIVE                    9893c
0000000b6c58  000000000008 R_X86_64_RELATIVE                    9894d
0000000b6c68  000000000008 R_X86_64_RELATIVE                    98965
0000000b6c78  000000000008 R_X86_64_RELATIVE                    98973
0000000b6c88  000000000008 R_X86_64_RELATIVE                    98988
0000000b6c98  000000000008 R_X86_64_RELATIVE                    9899c
0000000b6cc8  000000000008 R_X86_64_RELATIVE                    989b0
0000000b6cd8  000000000008 R_X86_64_RELATIVE                    989bd
0000000b6ce8  000000000008 R_X86_64_RELATIVE                    989c9
0000000b6cf8  000000000008 R_X86_64_RELATIVE                    79088
0000000b6d08  000000000008 R_X86_64_RELATIVE                    989d7
0000000b6d18  000000000008 R_X86_64_RELATIVE                    989e1
0000000b6d28  000000000008 R_X86_64_RELATIVE                    989ee
0000000b6d38  000000000008 R_X86_64_RELATIVE                    989f6
0000000b6d48  000000000008 R_X86_64_RELATIVE                    98a06
0000000b6d58  000000000008 R_X86_64_RELATIVE                    98a14
0000000b6d68  000000000008 R_X86_64_RELATIVE                    98a20
0000000b6d78  000000000008 R_X86_64_RELATIVE                    98a2e
0000000b6d88  000000000008 R_X86_64_RELATIVE                    98a3b
0000000b6d98  000000000008 R_X86_64_RELATIVE                    98a46
0000000b6da8  000000000008 R_X86_64_RELATIVE                    98a50
0000000b6db8  000000000008 R_X86_64_RELATIVE                    98a5a
0000000b6dc8  000000000008 R_X86_64_RELATIVE                    98a68
0000000b6dd8  000000000008 R_X86_64_RELATIVE                    98a72
0000000b6de8  000000000008 R_X86_64_RELATIVE                    802e8
0000000b6df8  000000000008 R_X86_64_RELATIVE                    98a7e
0000000b6e08  000000000008 R_X86_64_RELATIVE                    98a87
0000000b6e18  000000000008 R_X86_64_RELATIVE                    98a95
0000000b6e28  000000000008 R_X86_64_RELATIVE                    81085
0000000b6e38  000000000008 R_X86_64_RELATIVE                    7ec25
0000000b6e48  000000000008 R_X86_64_RELATIVE                    98a9d
0000000b6e58  000000000008 R_X86_64_RELATIVE                    98aab
0000000b6e68  000000000008 R_X86_64_RELATIVE                    98ab2
0000000b6e78  000000000008 R_X86_64_RELATIVE                    79593
0000000b6e88  000000000008 R_X86_64_RELATIVE                    98abe
0000000b6e98  000000000008 R_X86_64_RELATIVE                    98acd
0000000b6ea8  000000000008 R_X86_64_RELATIVE                    812d4
0000000b6eb8  000000000008 R_X86_64_RELATIVE                    8128d
0000000b6ec8  000000000008 R_X86_64_RELATIVE                    98ad9
0000000b6ed8  000000000008 R_X86_64_RELATIVE                    9896d
0000000b6ee8  000000000008 R_X86_64_RELATIVE                    98ae1
0000000b6ef8  000000000008 R_X86_64_RELATIVE                    98ae5
0000000b6f08  000000000008 R_X86_64_RELATIVE                    78f9e
0000000b6f18  000000000008 R_X86_64_RELATIVE                    98aed
0000000b6f28  000000000008 R_X86_64_RELATIVE                    98af5
0000000b6f38  000000000008 R_X86_64_RELATIVE                    98b08
0000000b6f48  000000000008 R_X86_64_RELATIVE                    98b12
0000000b6f58  000000000008 R_X86_64_RELATIVE                    98b1e
0000000b6f68  000000000008 R_X86_64_RELATIVE                    98b26
0000000b6f78  000000000008 R_X86_64_RELATIVE                    98b2f
0000000b1fc0  000c00000006 R_X86_64_GLOB_DAT 0000000000000000 __libc_start_main@GLIBC_2.34 + 0
0000000b1fc8  001400000006 R_X86_64_GLOB_DAT 0000000000000000 _ITM_deregisterTM[...] + 0
0000000b1fd0  003700000006 R_X86_64_GLOB_DAT 0000000000000000 gettext@GLIBC_2.2.5 + 0
0000000b1fd8  005d00000006 R_X86_64_GLOB_DAT 0000000000000000 __gmon_start__ + 0
0000000b1fe0  00a500000006 R_X86_64_GLOB_DAT 0000000000000000 _ITM_registerTMCl[...] + 0
0000000b1fe8  00ff00000006 R_X86_64_GLOB_DAT 0000000000000000 __cxa_finalize@GLIBC_2.2.5 + 0
0000000b6fa0  01f700000005 R_X86_64_COPY     00000000000b6fa0 stdout@GLIBC_2.2.5 + 0
0000000b6fa8  01ed00000005 R_X86_64_COPY     00000000000b6fa8 optind@GLIBC_2.2.5 + 0
0000000b6fc0  03c800000005 R_X86_64_COPY     00000000000b6fc0 optarg@GLIBC_2.2.5 + 0
0000000b6fe0  019400000005 R_X86_64_COPY     00000000000b6fe0 stderr@GLIBC_2.2.5 + 0

Relocation section '.rela.plt' at offset 0x13ca0 contains 172 entries:
  Offset          Info           Type           Sym. Value    Sym. Name + Addend
0000000b1a60  000100000007 R_X86_64_JUMP_SLO 0000000000000000 __ctype_toupper_loc@GLIBC_2.3 + 0
0000000b1a68  000200000007 R_X86_64_JUMP_SLO 0000000000000000 __strcat_chk@GLIBC_2.3.4 + 0
0000000b1a70  000300000007 R_X86_64_JUMP_SLO 0000000000000000 getenv@GLIBC_2.2.5 + 0
0000000b1a78  000400000007 R_X86_64_JUMP_SLO 0000000000000000 utime@GLIBC_2.2.5 + 0
0000000b1a80  000500000007 R_X86_64_JUMP_SLO 0000000000000000 __snprintf_chk@GLIBC_2.3.4 + 0
0000000b1a88  000600000007 R_X86_64_JUMP_SLO 0000000000000000 free@GLIBC_2.2.5 + 0
0000000b1a90  000700000007 R_X86_64_JUMP_SLO 0000000000000000 endmntent@GLIBC_2.2.5 + 0
0000000b1a98  000800000007 R_X86_64_JUMP_SLO 0000000000000000 strcasecmp@GLIBC_2.2.5 + 0
0000000b1aa0  000900000007 R_X86_64_JUMP_SLO 0000000000000000 backtrace_symbols_fd@GLIBC_2.2.5 + 0
0000000b1aa8  000a00000007 R_X86_64_JUMP_SLO 0000000000000000 localtime@GLIBC_2.2.5 + 0
0000000b1ab0  000b00000007 R_X86_64_JUMP_SLO 0000000000000000 __vfprintf_chk@GLIBC_2.3.4 + 0
0000000b1ab8  000d00000007 R_X86_64_JUMP_SLO 0000000000000000 abort@GLIBC_2.2.5 + 0
0000000b1ac0  000e00000007 R_X86_64_JUMP_SLO 0000000000000000 __errno_location@GLIBC_2.2.5 + 0
0000000b1ac8  000f00000007 R_X86_64_JUMP_SLO 0000000000000000 srandom@GLIBC_2.2.5 + 0
0000000b1ad0  001000000007 R_X86_64_JUMP_SLO 0000000000000000 unlink@GLIBC_2.2.5 + 0
0000000b1ad8  001100000007 R_X86_64_JUMP_SLO 0000000000000000 uuid_unparse@UUID_1.0 + 0
0000000b1ae0  001200000007 R_X86_64_JUMP_SLO 0000000000000000 strncpy@GLIBC_2.2.5 + 0
0000000b1ae8  001300000007 R_X86_64_JUMP_SLO 0000000000000000 strncmp@GLIBC_2.2.5 + 0
0000000b1af0  001500000007 R_X86_64_JUMP_SLO 0000000000000000 localtime_r@GLIBC_2.2.5 + 0
0000000b1af8  001600000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_probe_looku[...]@BLKID_2.15 + 0
0000000b1b00  001700000007 R_X86_64_JUMP_SLO 0000000000000000 strcpy@GLIBC_2.2.5 + 0
0000000b1b08  001800000007 R_X86_64_JUMP_SLO 0000000000000000 __isoc99_fscanf@GLIBC_2.7 + 0
0000000b1b10  001900000007 R_X86_64_JUMP_SLO 0000000000000000 secure_getenv@GLIBC_2.17 + 0
0000000b1b18  001a00000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_new_probe_f[...]@BLKID_2.17 + 0
0000000b1b20  001b00000007 R_X86_64_JUMP_SLO 0000000000000000 puts@GLIBC_2.2.5 + 0
0000000b1b28  001c00000007 R_X86_64_JUMP_SLO 0000000000000000 qsort@GLIBC_2.2.5 + 0
0000000b1b30  001d00000007 R_X86_64_JUMP_SLO 0000000000000000 isatty@GLIBC_2.2.5 + 0
0000000b1b38  001e00000007 R_X86_64_JUMP_SLO 0000000000000000 sigaction@GLIBC_2.2.5 + 0
0000000b1b40  001f00000007 R_X86_64_JUMP_SLO 0000000000000000 strtod@GLIBC_2.2.5 + 0
0000000b1b48  002000000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_probe_enabl[...]@BLKID_2.17 + 0
0000000b1b50  002100000007 R_X86_64_JUMP_SLO 0000000000000000 __vprintf_chk@GLIBC_2.3.4 + 0
0000000b1b58  002200000007 R_X86_64_JUMP_SLO 0000000000000000 fcntl@GLIBC_2.2.5 + 0
0000000b1b60  002300000007 R_X86_64_JUMP_SLO 0000000000000000 write@GLIBC_2.2.5 + 0
0000000b1b68  002400000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_probe_enabl[...]@BLKID_2.17 + 0
0000000b1b70  002500000007 R_X86_64_JUMP_SLO 0000000000000000 getpid@GLIBC_2.2.5 + 0
0000000b1b78  002600000007 R_X86_64_JUMP_SLO 0000000000000000 textdomain@GLIBC_2.2.5 + 0
0000000b1b80  002700000007 R_X86_64_JUMP_SLO 0000000000000000 __open_2@GLIBC_2.7 + 0
0000000b1b88  002800000007 R_X86_64_JUMP_SLO 0000000000000000 fclose@GLIBC_2.2.5 + 0
0000000b1b90  002900000007 R_X86_64_JUMP_SLO 0000000000000000 opendir@GLIBC_2.2.5 + 0
0000000b1b98  002a00000007 R_X86_64_JUMP_SLO 0000000000000000 ctime@GLIBC_2.2.5 + 0
0000000b1ba0  002b00000007 R_X86_64_JUMP_SLO 0000000000000000 bindtextdomain@GLIBC_2.2.5 + 0
0000000b1ba8  002c00000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_put_cache@BLKID_1.0 + 0
0000000b1bb0  002d00000007 R_X86_64_JUMP_SLO 0000000000000000 msync@GLIBC_2.2.5 + 0
0000000b1bb8  002e00000007 R_X86_64_JUMP_SLO 0000000000000000 dcgettext@GLIBC_2.2.5 + 0
0000000b1bc0  002f00000007 R_X86_64_JUMP_SLO 0000000000000000 strlen@GLIBC_2.2.5 + 0
0000000b1bc8  003000000007 R_X86_64_JUMP_SLO 0000000000000000 fallocate64@GLIBC_2.10 + 0
0000000b1bd0  003100000007 R_X86_64_JUMP_SLO 0000000000000000 backtrace@GLIBC_2.2.5 + 0
0000000b1bd8  003200000007 R_X86_64_JUMP_SLO 0000000000000000 getpwuid_r@GLIBC_2.2.5 + 0
0000000b1be0  003300000007 R_X86_64_JUMP_SLO 0000000000000000 __stack_chk_fail@GLIBC_2.4 + 0
0000000b1be8  003400000007 R_X86_64_JUMP_SLO 0000000000000000 getuid@GLIBC_2.2.5 + 0
0000000b1bf0  003500000007 R_X86_64_JUMP_SLO 0000000000000000 mmap@GLIBC_2.2.5 + 0
0000000b1bf8  003600000007 R_X86_64_JUMP_SLO 0000000000000000 asctime@GLIBC_2.2.5 + 0
0000000b1c00  003800000007 R_X86_64_JUMP_SLO 0000000000000000 stat64@GLIBC_2.33 + 0
0000000b1c08  003900000007 R_X86_64_JUMP_SLO 0000000000000000 strchr@GLIBC_2.2.5 + 0
0000000b1c10  003a00000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_get_tag_value@BLKID_1.0 + 0
0000000b1c18  003b00000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_mutex_destroy@GLIBC_2.2.5 + 0
0000000b1c20  003c00000007 R_X86_64_JUMP_SLO 0000000000000000 pclose@GLIBC_2.2.5 + 0
0000000b1c28  003d00000007 R_X86_64_JUMP_SLO 0000000000000000 strrchr@GLIBC_2.2.5 + 0
0000000b1c30  003e00000007 R_X86_64_JUMP_SLO 0000000000000000 ftruncate@GLIBC_2.2.5 + 0
0000000b1c38  003f00000007 R_X86_64_JUMP_SLO 0000000000000000 mallinfo@GLIBC_2.2.5 + 0
0000000b1c40  004000000007 R_X86_64_JUMP_SLO 0000000000000000 uname@GLIBC_2.2.5 + 0
0000000b1c48  004100000007 R_X86_64_JUMP_SLO 0000000000000000 gmtime_r@GLIBC_2.2.5 + 0
0000000b1c50  004200000007 R_X86_64_JUMP_SLO 0000000000000000 dup@GLIBC_2.2.5 + 0
0000000b1c58  004300000007 R_X86_64_JUMP_SLO 0000000000000000 lseek@GLIBC_2.2.5 + 0
0000000b1c60  004400000007 R_X86_64_JUMP_SLO 0000000000000000 setrlimit64@GLIBC_2.2.5 + 0
0000000b1c68  004500000007 R_X86_64_JUMP_SLO 0000000000000000 gettimeofday@GLIBC_2.2.5 + 0
0000000b1c70  004600000007 R_X86_64_JUMP_SLO 0000000000000000 fputs@GLIBC_2.2.5 + 0
0000000b1c78  004700000007 R_X86_64_JUMP_SLO 0000000000000000 memset@GLIBC_2.2.5 + 0
0000000b1c80  004800000007 R_X86_64_JUMP_SLO 0000000000000000 geteuid@GLIBC_2.2.5 + 0
0000000b1c88  004900000007 R_X86_64_JUMP_SLO 0000000000000000 ioctl@GLIBC_2.2.5 + 0
0000000b1c90  004a00000007 R_X86_64_JUMP_SLO 0000000000000000 strnlen@GLIBC_2.2.5 + 0
0000000b1c98  004b00000007 R_X86_64_JUMP_SLO 0000000000000000 close@GLIBC_2.2.5 + 0
0000000b1ca0  004c00000007 R_X86_64_JUMP_SLO 0000000000000000 pipe@GLIBC_2.2.5 + 0
0000000b1ca8  004d00000007 R_X86_64_JUMP_SLO 0000000000000000 closedir@GLIBC_2.2.5 + 0
0000000b1cb0  004e00000007 R_X86_64_JUMP_SLO 0000000000000000 fputc@GLIBC_2.2.5 + 0
0000000b1cb8  004f00000007 R_X86_64_JUMP_SLO 0000000000000000 read@GLIBC_2.2.5 + 0
0000000b1cc0  005000000007 R_X86_64_JUMP_SLO 0000000000000000 memcmp@GLIBC_2.2.5 + 0
0000000b1cc8  005100000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_attr_init@GLIBC_2.2.5 + 0
0000000b1cd0  005200000007 R_X86_64_JUMP_SLO 0000000000000000 sbrk@GLIBC_2.2.5 + 0
0000000b1cd8  005300000007 R_X86_64_JUMP_SLO 0000000000000000 fgets@GLIBC_2.2.5 + 0
0000000b1ce0  005400000007 R_X86_64_JUMP_SLO 0000000000000000 _setjmp@GLIBC_2.2.5 + 0
0000000b1ce8  005500000007 R_X86_64_JUMP_SLO 0000000000000000 strtoull@GLIBC_2.2.5 + 0
0000000b1cf0  005600000007 R_X86_64_JUMP_SLO 0000000000000000 calloc@GLIBC_2.2.5 + 0
0000000b1cf8  005700000007 R_X86_64_JUMP_SLO 0000000000000000 putenv@GLIBC_2.2.5 + 0
0000000b1d00  005800000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_get_devname@BLKID_1.0 + 0
0000000b1d08  005900000007 R_X86_64_JUMP_SLO 0000000000000000 strcmp@GLIBC_2.2.5 + 0
0000000b1d10  005a00000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_do_fullprobe@BLKID_2.17 + 0
0000000b1d18  005b00000007 R_X86_64_JUMP_SLO 0000000000000000 __memcpy_chk@GLIBC_2.3.4 + 0
0000000b1d20  005c00000007 R_X86_64_JUMP_SLO 0000000000000000 feof@GLIBC_2.2.5 + 0
0000000b1d28  005e00000007 R_X86_64_JUMP_SLO 0000000000000000 umask@GLIBC_2.2.5 + 0
0000000b1d30  005f00000007 R_X86_64_JUMP_SLO 0000000000000000 stat@GLIBC_2.33 + 0
0000000b1d38  006000000007 R_X86_64_JUMP_SLO 0000000000000000 strtol@GLIBC_2.2.5 + 0
0000000b1d40  006100000007 R_X86_64_JUMP_SLO 0000000000000000 memcpy@GLIBC_2.14 + 0
0000000b1d48  006200000007 R_X86_64_JUMP_SLO 0000000000000000 prctl@GLIBC_2.2.5 + 0
0000000b1d50  006300000007 R_X86_64_JUMP_SLO 0000000000000000 tzset@GLIBC_2.2.5 + 0
0000000b1d58  006400000007 R_X86_64_JUMP_SLO 0000000000000000 __xpg_basename@GLIBC_2.2.5 + 0
0000000b1d60  006500000007 R_X86_64_JUMP_SLO 0000000000000000 time@GLIBC_2.2.5 + 0
0000000b1d68  006600000007 R_X86_64_JUMP_SLO 0000000000000000 fileno@GLIBC_2.2.5 + 0
0000000b1d70  006700000007 R_X86_64_JUMP_SLO 0000000000000000 getgid@GLIBC_2.2.5 + 0
0000000b1d78  006800000007 R_X86_64_JUMP_SLO 0000000000000000 select@GLIBC_2.2.5 + 0
0000000b1d80  006900000007 R_X86_64_JUMP_SLO 0000000000000000 pwrite64@GLIBC_2.2.5 + 0
0000000b1d88  006a00000007 R_X86_64_JUMP_SLO 0000000000000000 readdir@GLIBC_2.2.5 + 0
0000000b1d90  006b00000007 R_X86_64_JUMP_SLO 0000000000000000 getrlimit64@GLIBC_2.2.5 + 0
0000000b1d98  006c00000007 R_X86_64_JUMP_SLO 0000000000000000 random@GLIBC_2.2.5 + 0
0000000b1da0  006d00000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_mutex_unlock@GLIBC_2.2.5 + 0
0000000b1da8  006e00000007 R_X86_64_JUMP_SLO 0000000000000000 __open64_2@GLIBC_2.7 + 0
0000000b1db0  006f00000007 R_X86_64_JUMP_SLO 0000000000000000 malloc@GLIBC_2.2.5 + 0
0000000b1db8  007000000007 R_X86_64_JUMP_SLO 0000000000000000 strncasecmp@GLIBC_2.2.5 + 0
0000000b1dc0  007100000007 R_X86_64_JUMP_SLO 0000000000000000 fflush@GLIBC_2.2.5 + 0
0000000b1dc8  007200000007 R_X86_64_JUMP_SLO 0000000000000000 getmntent@GLIBC_2.2.5 + 0
0000000b1dd0  007300000007 R_X86_64_JUMP_SLO 0000000000000000 setmntent@GLIBC_2.2.5 + 0
0000000b1dd8  007400000007 R_X86_64_JUMP_SLO 0000000000000000 __isoc99_sscanf@GLIBC_2.7 + 0
0000000b1de0  007500000007 R_X86_64_JUMP_SLO 0000000000000000 uuid_is_null@UUID_1.0 + 0
0000000b1de8  007600000007 R_X86_64_JUMP_SLO 0000000000000000 getegid@GLIBC_2.2.5 + 0
0000000b1df0  007700000007 R_X86_64_JUMP_SLO 0000000000000000 daemon@GLIBC_2.2.5 + 0
0000000b1df8  007800000007 R_X86_64_JUMP_SLO 0000000000000000 mkstemp@GLIBC_2.2.5 + 0
0000000b1e00  007900000007 R_X86_64_JUMP_SLO 0000000000000000 uuid_generate@UUID_1.0 + 0
0000000b1e08  007a00000007 R_X86_64_JUMP_SLO 0000000000000000 gnu_dev_major@GLIBC_2.3.3 + 0
0000000b1e10  007b00000007 R_X86_64_JUMP_SLO 0000000000000000 realloc@GLIBC_2.2.5 + 0
0000000b1e18  007c00000007 R_X86_64_JUMP_SLO 0000000000000000 __strcpy_chk@GLIBC_2.3.4 + 0
0000000b1e20  007d00000007 R_X86_64_JUMP_SLO 0000000000000000 fdopen@GLIBC_2.2.5 + 0
0000000b1e28  007e00000007 R_X86_64_JUMP_SLO 0000000000000000 munmap@GLIBC_2.2.5 + 0
0000000b1e30  007f00000007 R_X86_64_JUMP_SLO 0000000000000000 setlocale@GLIBC_2.2.5 + 0
0000000b1e38  008000000007 R_X86_64_JUMP_SLO 0000000000000000 ftruncate64@GLIBC_2.2.5 + 0
0000000b1e40  008100000007 R_X86_64_JUMP_SLO 0000000000000000 pwrite@GLIBC_2.2.5 + 0
0000000b1e48  008200000007 R_X86_64_JUMP_SLO 0000000000000000 __printf_chk@GLIBC_2.3.4 + 0
0000000b1e50  008300000007 R_X86_64_JUMP_SLO 0000000000000000 setvbuf@GLIBC_2.2.5 + 0
0000000b1e58  008400000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_create@GLIBC_2.34 + 0
0000000b1e60  008500000007 R_X86_64_JUMP_SLO 0000000000000000 __longjmp_chk@GLIBC_2.11 + 0
0000000b1e68  008600000007 R_X86_64_JUMP_SLO 0000000000000000 open64@GLIBC_2.2.5 + 0
0000000b1e70  008700000007 R_X86_64_JUMP_SLO 0000000000000000 fcntl64@GLIBC_2.28 + 0
0000000b1e78  008800000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_free_probe@BLKID_2.15 + 0
0000000b1e80  008900000007 R_X86_64_JUMP_SLO 0000000000000000 memmove@GLIBC_2.2.5 + 0
0000000b1e88  008a00000007 R_X86_64_JUMP_SLO 0000000000000000 fsync@GLIBC_2.2.5 + 0
0000000b1e90  008b00000007 R_X86_64_JUMP_SLO 0000000000000000 pread64@GLIBC_2.2.5 + 0
0000000b1e98  008c00000007 R_X86_64_JUMP_SLO 0000000000000000 tcgetattr@GLIBC_2.2.5 + 0
0000000b1ea0  008d00000007 R_X86_64_JUMP_SLO 0000000000000000 tcsetattr@GLIBC_2.2.5 + 0
0000000b1ea8  008e00000007 R_X86_64_JUMP_SLO 0000000000000000 open@GLIBC_2.2.5 + 0
0000000b1eb0  008f00000007 R_X86_64_JUMP_SLO 0000000000000000 access@GLIBC_2.2.5 + 0
0000000b1eb8  009000000007 R_X86_64_JUMP_SLO 0000000000000000 popen@GLIBC_2.2.5 + 0
0000000b1ec0  009100000007 R_X86_64_JUMP_SLO 0000000000000000 fopen@GLIBC_2.2.5 + 0
0000000b1ec8  009200000007 R_X86_64_JUMP_SLO 0000000000000000 dcngettext@GLIBC_2.2.5 + 0
0000000b1ed0  009300000007 R_X86_64_JUMP_SLO 0000000000000000 getrusage@GLIBC_2.2.5 + 0
0000000b1ed8  009400000007 R_X86_64_JUMP_SLO 0000000000000000 perror@GLIBC_2.2.5 + 0
0000000b1ee0  009500000007 R_X86_64_JUMP_SLO 0000000000000000 sysconf@GLIBC_2.2.5 + 0
0000000b1ee8  009600000007 R_X86_64_JUMP_SLO 0000000000000000 getopt@GLIBC_2.2.5 + 0
0000000b1ef0  009700000007 R_X86_64_JUMP_SLO 0000000000000000 strtoul@GLIBC_2.2.5 + 0
0000000b1ef8  009800000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_attr_destroy@GLIBC_2.2.5 + 0
0000000b1f00  009900000007 R_X86_64_JUMP_SLO 0000000000000000 __cxa_atexit@GLIBC_2.2.5 + 0
0000000b1f08  009a00000007 R_X86_64_JUMP_SLO 0000000000000000 atoi@GLIBC_2.2.5 + 0
0000000b1f10  009b00000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_devno_to_devname@BLKID_1.0 + 0
0000000b1f18  009c00000007 R_X86_64_JUMP_SLO 0000000000000000 pread@GLIBC_2.2.5 + 0
0000000b1f20  009d00000007 R_X86_64_JUMP_SLO 0000000000000000 strcat@GLIBC_2.2.5 + 0
0000000b1f28  009e00000007 R_X86_64_JUMP_SLO 0000000000000000 gethostname@GLIBC_2.2.5 + 0
0000000b1f30  009f00000007 R_X86_64_JUMP_SLO 0000000000000000 exit@GLIBC_2.2.5 + 0
0000000b1f38  00a000000007 R_X86_64_JUMP_SLO 0000000000000000 lseek64@GLIBC_2.2.5 + 0
0000000b1f40  00a100000007 R_X86_64_JUMP_SLO 0000000000000000 __fprintf_chk@GLIBC_2.3.4 + 0
0000000b1f48  00a200000007 R_X86_64_JUMP_SLO 0000000000000000 fstat64@GLIBC_2.33 + 0
0000000b1f50  00a300000007 R_X86_64_JUMP_SLO 0000000000000000 posix_fadvise64@GLIBC_2.2.5 + 0
0000000b1f58  00a400000007 R_X86_64_JUMP_SLO 0000000000000000 posix_memalign@GLIBC_2.2.5 + 0
0000000b1f60  00a600000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_join@GLIBC_2.34 + 0
0000000b1f68  00a700000007 R_X86_64_JUMP_SLO 0000000000000000 strdup@GLIBC_2.2.5 + 0
0000000b1f70  00a800000007 R_X86_64_JUMP_SLO 0000000000000000 strerror@GLIBC_2.2.5 + 0
0000000b1f78  00a900000007 R_X86_64_JUMP_SLO 0000000000000000 blkid_get_cache@BLKID_1.0 + 0
0000000b1f80  00aa00000007 R_X86_64_JUMP_SLO 0000000000000000 hasmntopt@GLIBC_2.2.5 + 0
0000000b1f88  00ab00000007 R_X86_64_JUMP_SLO 0000000000000000 sleep@GLIBC_2.2.5 + 0
0000000b1f90  00ac00000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_mutex_init@GLIBC_2.2.5 + 0
0000000b1f98  00ad00000007 R_X86_64_JUMP_SLO 0000000000000000 fstat@GLIBC_2.33 + 0
0000000b1fa0  00ae00000007 R_X86_64_JUMP_SLO 0000000000000000 fork@GLIBC_2.2.5 + 0
0000000b1fa8  00af00000007 R_X86_64_JUMP_SLO 0000000000000000 pthread_mutex_lock@GLIBC_2.2.5 + 0
0000000b1fb0  00b000000007 R_X86_64_JUMP_SLO 0000000000000000 __ctype_b_loc@GLIBC_2.3 + 0
0000000b1fb8  00b100000007 R_X86_64_JUMP_SLO 0000000000000000 __sprintf_chk@GLIBC_2.3.4 + 0

codex
The function is an e2fsck extended-attribute validator. Its main loop walks inline xattr entries, tracks external value blocks, validates hashes and bounds with a region allocator, and falls back to a separate checker for the remaining area. I’m resolving the precise struct layouts and error paths from adjacent assembly now.
exec
/bin/bash -lc 'objdump -s --start-address=0x78f60 --stop-address=0x78fc0 ./target.bin' in /tmp/llmdec_codex_6_u0et34
exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x1ec80 --stop-address=0x1f800 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64

Contents of section .rodata:
 78f60 6d617000 62616420 696e6f64 65206d61  map.bad inode ma
 78f70 7000696e 6f64655f 6261645f 6d617000  p.inode_bad_map.
 78f80 70617373 31007379 7374656d 2e646174  pass1.system.dat
 78f90 61006368 65636b5f 6c617267 655f6561  a.check_large_ea
 78fa0 5f696e6f 64650072 65616469 6e672064  _inode.reading d
 78fb0 69726563 746f7279 20626c6f 636b0063  irectory block.c

 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001ec80 <check_backup_super_block@@Base+0xd40>:
   1ec80:	18 b9 01 00 00 00    	sbb    BYTE PTR [rcx+0x1],bh
   1ec86:	31 db                	xor    ebx,ebx
   1ec88:	e9 2e ff ff ff       	jmp    1ebbb <check_backup_super_block@@Base+0xc7b>
   1ec8d:	0f 1f 00             	nop    DWORD PTR [rax]
   1ec90:	41 54                	push   r12
   1ec92:	49 89 fc             	mov    r12,rdi
   1ec95:	55                   	push   rbp
   1ec96:	89 f5                	mov    ebp,esi
   1ec98:	53                   	push   rbx
   1ec99:	31 db                	xor    ebx,ebx
   1ec9b:	49 8b 74 24 20       	mov    rsi,QWORD PTR [r12+0x20]
   1eca0:	89 df                	mov    edi,ebx
   1eca2:	e8 29 48 02 00       	call   434d0 <quota_type2inum@@Base>
   1eca7:	39 e8                	cmp    eax,ebp
   1eca9:	74 15                	je     1ecc0 <check_backup_super_block@@Base+0xd80>
   1ecab:	83 c3 01             	add    ebx,0x1
   1ecae:	83 fb 03             	cmp    ebx,0x3
   1ecb1:	75 e8                	jne    1ec9b <check_backup_super_block@@Base+0xd5b>
   1ecb3:	5b                   	pop    rbx
   1ecb4:	31 c0                	xor    eax,eax
   1ecb6:	5d                   	pop    rbp
   1ecb7:	41 5c                	pop    r12
   1ecb9:	c3                   	ret    
   1ecba:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1ecc0:	5b                   	pop    rbx
   1ecc1:	b8 01 00 00 00       	mov    eax,0x1
   1ecc6:	5d                   	pop    rbp
   1ecc7:	41 5c                	pop    r12
   1ecc9:	c3                   	ret    
   1ecca:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1ecd0:	48 39 ca             	cmp    rdx,rcx
   1ecd3:	0f 83 a0 00 00 00    	jae    1ed79 <check_backup_super_block@@Base+0xe39>
   1ecd9:	41 56                	push   r14
   1ecdb:	4c 8d b7 e8 01 00 00 	lea    r14,[rdi+0x1e8]
   1ece2:	41 55                	push   r13
   1ece4:	49 89 f5             	mov    r13,rsi
   1ece7:	41 54                	push   r12
   1ece9:	49 89 fc             	mov    r12,rdi
   1ecec:	55                   	push   rbp
   1eced:	48 89 cd             	mov    rbp,rcx
   1ecf0:	53                   	push   rbx
   1ecf1:	48 89 d3             	mov    rbx,rdx
   1ecf4:	eb 24                	jmp    1ed1a <check_backup_super_block@@Base+0xdda>
   1ecf6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1ecfd:	00 00 00 
   1ed00:	31 d2                	xor    edx,edx
   1ed02:	e8 f9 bc 01 00       	call   3aa00 <ea_refcount_increment@@Base>
   1ed07:	0f b6 03             	movzx  eax,BYTE PTR [rbx]
   1ed0a:	83 c0 13             	add    eax,0x13
   1ed0d:	25 fc 01 00 00       	and    eax,0x1fc
   1ed12:	48 01 c3             	add    rbx,rax
   1ed15:	48 39 dd             	cmp    rbp,rbx
   1ed18:	76 56                	jbe    1ed70 <check_backup_super_block@@Base+0xe30>
   1ed1a:	8b 03                	mov    eax,DWORD PTR [rbx]
   1ed1c:	85 c0                	test   eax,eax
   1ed1e:	74 50                	je     1ed70 <check_backup_super_block@@Base+0xe30>
   1ed20:	8b 73 04             	mov    esi,DWORD PTR [rbx+0x4]
   1ed23:	85 f6                	test   esi,esi
   1ed25:	74 e0                	je     1ed07 <check_backup_super_block@@Base+0xdc7>
   1ed27:	49 8b bc 24 e8 01 00 	mov    rdi,QWORD PTR [r12+0x1e8]
   1ed2e:	00 
   1ed2f:	48 85 ff             	test   rdi,rdi
   1ed32:	75 cc                	jne    1ed00 <check_backup_super_block@@Base+0xdc0>
   1ed34:	4c 89 f6             	mov    rsi,r14
   1ed37:	e8 d4 bb 01 00       	call   3a910 <ea_refcount_create@@Base>
   1ed3c:	49 89 45 00          	mov    QWORD PTR [r13+0x0],rax
   1ed40:	48 85 c0             	test   rax,rax
   1ed43:	75 0d                	jne    1ed52 <check_backup_super_block@@Base+0xe12>
   1ed45:	8b 73 04             	mov    esi,DWORD PTR [rbx+0x4]
   1ed48:	49 8b bc 24 e8 01 00 	mov    rdi,QWORD PTR [r12+0x1e8]
   1ed4f:	00 
   1ed50:	eb ae                	jmp    1ed00 <check_backup_super_block@@Base+0xdc0>
   1ed52:	49 c7 45 50 04 00 00 	mov    QWORD PTR [r13+0x50],0x4
   1ed59:	00 
   1ed5a:	4c 89 ea             	mov    rdx,r13
   1ed5d:	be 38 00 01 00       	mov    esi,0x10038
   1ed62:	4c 89 e7             	mov    rdi,r12
   1ed65:	e8 86 84 01 00       	call   371f0 <fix_problem@@Base>
   1ed6a:	41 83 4c 24 48 01    	or     DWORD PTR [r12+0x48],0x1
   1ed70:	5b                   	pop    rbx
   1ed71:	5d                   	pop    rbp
   1ed72:	41 5c                	pop    r12
   1ed74:	41 5d                	pop    r13
   1ed76:	41 5e                	pop    r14
   1ed78:	c3                   	ret    
   1ed79:	c3                   	ret    
   1ed7a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1ed80:	55                   	push   rbp
   1ed81:	48 89 f5             	mov    rbp,rsi
   1ed84:	53                   	push   rbx
   1ed85:	48 89 fb             	mov    rbx,rdi
   1ed88:	48 83 ec 78          	sub    rsp,0x78
   1ed8c:	48 8b bf 70 03 00 00 	mov    rdi,QWORD PTR [rdi+0x370]
   1ed93:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1ed9a:	00 00 
   1ed9c:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   1eda1:	31 c0                	xor    eax,eax
   1eda3:	48 85 ff             	test   rdi,rdi
   1eda6:	74 40                	je     1ede8 <check_backup_super_block@@Base+0xea8>
   1eda8:	89 ee                	mov    esi,ebp
   1edaa:	e8 01 9f 02 00       	call   48cb0 <ext2fs_u32_list_add@@Base>
   1edaf:	48 89 04 24          	mov    QWORD PTR [rsp],rax
   1edb3:	48 85 c0             	test   rax,rax
   1edb6:	74 14                	je     1edcc <check_backup_super_block@@Base+0xe8c>
   1edb8:	48 89 e2             	mov    rdx,rsp
   1edbb:	be 8c 00 01 00       	mov    esi,0x1008c
   1edc0:	48 89 df             	mov    rdi,rbx
   1edc3:	e8 28 84 01 00       	call   371f0 <fix_problem@@Base>
   1edc8:	83 4b 48 01          	or     DWORD PTR [rbx+0x48],0x1
   1edcc:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   1edd1:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1edd8:	00 00 
   1edda:	75 2c                	jne    1ee08 <check_backup_super_block@@Base+0xec8>
   1eddc:	48 83 c4 78          	add    rsp,0x78
   1ede0:	5b                   	pop    rbx
   1ede1:	5d                   	pop    rbp
   1ede2:	c3                   	ret    
   1ede3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1ede8:	48 8d bb 70 03 00 00 	lea    rdi,[rbx+0x370]
   1edef:	31 f6                	xor    esi,esi
   1edf1:	e8 3a 9e 02 00       	call   48c30 <ext2fs_u32_list_create@@Base>
   1edf6:	48 89 04 24          	mov    QWORD PTR [rsp],rax
   1edfa:	48 85 c0             	test   rax,rax
   1edfd:	75 b9                	jne    1edb8 <check_backup_super_block@@Base+0xe78>
   1edff:	48 8b bb 70 03 00 00 	mov    rdi,QWORD PTR [rbx+0x370]
   1ee06:	eb a0                	jmp    1eda8 <check_backup_super_block@@Base+0xe68>
   1ee08:	e8 f3 6f ff ff       	call   15e00 <__stack_chk_fail@plt>
   1ee0d:	0f 1f 00             	nop    DWORD PTR [rax]
   1ee10:	41 55                	push   r13
   1ee12:	41 54                	push   r12
   1ee14:	49 89 f4             	mov    r12,rsi
   1ee17:	55                   	push   rbp
   1ee18:	53                   	push   rbx
   1ee19:	48 83 ec 18          	sub    rsp,0x18
   1ee1d:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1ee24:	00 00 
   1ee26:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1ee2b:	31 c0                	xor    eax,eax
   1ee2d:	48 c7 04 24 00 00 00 	mov    QWORD PTR [rsp],0x0
   1ee34:	00 
   1ee35:	f6 42 04 01          	test   BYTE PTR [rdx+0x4],0x1
   1ee39:	75 2d                	jne    1ee68 <check_backup_super_block@@Base+0xf28>
   1ee3b:	49 c7 04 24 00 00 00 	mov    QWORD PTR [r12],0x0
   1ee42:	00 
   1ee43:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   1ee48:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1ee4f:	00 00 
   1ee51:	0f 85 d4 00 00 00    	jne    1ef2b <check_backup_super_block@@Base+0xfeb>
   1ee57:	48 83 c4 18          	add    rsp,0x18
   1ee5b:	5b                   	pop    rbx
   1ee5c:	5d                   	pop    rbp
   1ee5d:	41 5c                	pop    r12
   1ee5f:	41 5d                	pop    r13
   1ee61:	c3                   	ret    
   1ee62:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1ee68:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   1ee6b:	48 89 d3             	mov    rbx,rdx
   1ee6e:	48 89 fd             	mov    rbp,rdi
   1ee71:	31 c9                	xor    ecx,ecx
   1ee73:	8b 33                	mov    esi,DWORD PTR [rbx]
   1ee75:	31 d2                	xor    edx,edx
   1ee77:	48 8b b8 90 00 00 00 	mov    rdi,QWORD PTR [rax+0x90]
   1ee7e:	e8 0d 04 03 00       	call   4f290 <ext2fs_add_dir_block2@@Base>
   1ee83:	49 89 04 24          	mov    QWORD PTR [r12],rax
   1ee87:	48 85 c0             	test   rax,rax
   1ee8a:	75 74                	jne    1ef00 <check_backup_super_block@@Base+0xfc0>
   1ee8c:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1ee90:	8b 33                	mov    esi,DWORD PTR [rbx]
   1ee92:	48 89 e2             	mov    rdx,rsp
   1ee95:	44 8b 6f 10          	mov    r13d,DWORD PTR [rdi+0x10]
   1ee99:	44 89 e8             	mov    eax,r13d
   1ee9c:	41 81 e5 00 00 20 00 	and    r13d,0x200000
   1eea3:	0d 00 00 20 00       	or     eax,0x200000
   1eea8:	89 47 10             	mov    DWORD PTR [rdi+0x10],eax
   1eeab:	e8 30 e7 03 00       	call   5d5e0 <ext2fs_inline_data_size@@Base>
   1eeb0:	48 8b 4d 00          	mov    rcx,QWORD PTR [rbp+0x0]
   1eeb4:	49 89 04 24          	mov    QWORD PTR [r12],rax
   1eeb8:	8b 51 10             	mov    edx,DWORD PTR [rcx+0x10]
   1eebb:	81 e2 ff ff df ff    	and    edx,0xffdfffff
   1eec1:	44 09 ea             	or     edx,r13d
   1eec4:	89 51 10             	mov    DWORD PTR [rcx+0x10],edx
   1eec7:	48 85 c0             	test   rax,rax
   1eeca:	0f 85 6b ff ff ff    	jne    1ee3b <check_backup_super_block@@Base+0xefb>
   1eed0:	48 83 3c 24 3c       	cmp    QWORD PTR [rsp],0x3c
   1eed5:	0f 86 68 ff ff ff    	jbe    1ee43 <check_backup_super_block@@Base+0xf03>
   1eedb:	48 8b b9 90 00 00 00 	mov    rdi,QWORD PTR [rcx+0x90]
   1eee2:	8b 33                	mov    esi,DWORD PTR [rbx]
   1eee4:	b9 01 00 00 00       	mov    ecx,0x1
   1eee9:	31 d2                	xor    edx,edx
   1eeeb:	e8 a0 03 03 00       	call   4f290 <ext2fs_add_dir_block2@@Base>
   1eef0:	49 89 04 24          	mov    QWORD PTR [r12],rax
   1eef4:	48 85 c0             	test   rax,rax
   1eef7:	0f 84 46 ff ff ff    	je     1ee43 <check_backup_super_block@@Base+0xf03>
   1eefd:	0f 1f 00             	nop    DWORD PTR [rax]
   1ef00:	49 c7 44 24 28 00 00 	mov    QWORD PTR [r12+0x28],0x0
   1ef07:	00 00 
   1ef09:	4c 89 e2             	mov    rdx,r12
   1ef0c:	be 2b 00 01 00       	mov    esi,0x1002b
   1ef11:	48 89 ef             	mov    rdi,rbp
   1ef14:	49 c7 44 24 50 00 00 	mov    QWORD PTR [r12+0x50],0x0
   1ef1b:	00 00 
   1ef1d:	e8 ce 82 01 00       	call   371f0 <fix_problem@@Base>
   1ef22:	83 4d 48 01          	or     DWORD PTR [rbp+0x48],0x1
   1ef26:	e9 18 ff ff ff       	jmp    1ee43 <check_backup_super_block@@Base+0xf03>
   1ef2b:	e8 d0 6e ff ff       	call   15e00 <__stack_chk_fail@plt>
   1ef30:	41 57                	push   r15
   1ef32:	41 56                	push   r14
   1ef34:	49 89 ce             	mov    r14,rcx
   1ef37:	b9 a0 00 00 00       	mov    ecx,0xa0
   1ef3c:	41 55                	push   r13
   1ef3e:	41 89 f5             	mov    r13d,esi
   1ef41:	41 54                	push   r12
   1ef43:	49 89 fc             	mov    r12,rdi
   1ef46:	55                   	push   rbp
   1ef47:	48 89 d5             	mov    rbp,rdx
   1ef4a:	48 81 ec b0 00 00 00 	sub    rsp,0xb0
   1ef51:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1ef58:	00 00 
   1ef5a:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
   1ef61:	00 
   1ef62:	31 c0                	xor    eax,eax
   1ef64:	49 89 e7             	mov    r15,rsp
   1ef67:	c7 82 18 02 00 00 00 	mov    DWORD PTR [rdx+0x218],0x0
   1ef6e:	00 00 00 
   1ef71:	4c 89 fa             	mov    rdx,r15
   1ef74:	e8 c7 03 04 00       	call   5f340 <ext2fs_read_inode_full@@Base>
   1ef79:	48 85 c0             	test   rax,rax
   1ef7c:	74 4b                	je     1efc9 <check_backup_super_block@@Base+0x1089>
   1ef7e:	48 3d 92 b7 2b 7f    	cmp    rax,0x7f2bb792
   1ef84:	74 2a                	je     1efb0 <check_backup_super_block@@Base+0x1070>
   1ef86:	48 8b 94 24 a8 00 00 	mov    rdx,QWORD PTR [rsp+0xa8]
   1ef8d:	00 
   1ef8e:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   1ef95:	00 00 
   1ef97:	75 4c                	jne    1efe5 <check_backup_super_block@@Base+0x10a5>
   1ef99:	48 81 c4 b0 00 00 00 	add    rsp,0xb0
   1efa0:	5d                   	pop    rbp
   1efa1:	41 5c                	pop    r12
   1efa3:	41 5d                	pop    r13
   1efa5:	41 5e                	pop    r14
   1efa7:	41 5f                	pop    r15
   1efa9:	c3                   	ret    
   1efaa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1efb0:	48 85 c0             	test   rax,rax
   1efb3:	74 14                	je     1efc9 <check_backup_super_block@@Base+0x1089>
   1efb5:	4c 89 f2             	mov    rdx,r14
   1efb8:	be 68 00 01 00       	mov    esi,0x10068
   1efbd:	48 89 ef             	mov    rdi,rbp
   1efc0:	e8 2b 82 01 00       	call   371f0 <fix_problem@@Base>
   1efc5:	85 c0                	test   eax,eax
   1efc7:	75 07                	jne    1efd0 <check_backup_super_block@@Base+0x1090>
   1efc9:	31 c0                	xor    eax,eax
   1efcb:	eb b9                	jmp    1ef86 <check_backup_super_block@@Base+0x1046>
   1efcd:	0f 1f 00             	nop    DWORD PTR [rax]
   1efd0:	b9 a0 00 00 00       	mov    ecx,0xa0
   1efd5:	4c 89 fa             	mov    rdx,r15
   1efd8:	44 89 ee             	mov    esi,r13d
   1efdb:	4c 89 e7             	mov    rdi,r12
   1efde:	e8 2d 07 04 00       	call   5f710 <ext2fs_write_inode_full@@Base>
   1efe3:	eb a1                	jmp    1ef86 <check_backup_super_block@@Base+0x1046>
   1efe5:	e8 16 6e ff ff       	call   15e00 <__stack_chk_fail@plt>
   1efea:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1eff0:	85 c9                	test   ecx,ecx
   1eff2:	75 04                	jne    1eff8 <check_backup_super_block@@Base+0x10b8>
   1eff4:	c3                   	ret    
   1eff5:	0f 1f 00             	nop    DWORD PTR [rax]
   1eff8:	55                   	push   rbp
   1eff9:	48 89 d1             	mov    rcx,rdx
   1effc:	48 89 d5             	mov    rbp,rdx
   1efff:	48 89 fa             	mov    rdx,rdi
   1f002:	53                   	push   rbx
   1f003:	48 89 fb             	mov    rbx,rdi
   1f006:	48 83 ec 08          	sub    rsp,0x8
   1f00a:	48 8b 3f             	mov    rdi,QWORD PTR [rdi]
   1f00d:	e8 1e ff ff ff       	call   1ef30 <check_backup_super_block@@Base+0xff0>
   1f012:	48 89 45 00          	mov    QWORD PTR [rbp+0x0],rax
   1f016:	48 85 c0             	test   rax,rax
   1f019:	74 04                	je     1f01f <check_backup_super_block@@Base+0x10df>
   1f01b:	83 4b 48 01          	or     DWORD PTR [rbx+0x48],0x1
   1f01f:	48 83 c4 08          	add    rsp,0x8
   1f023:	5b                   	pop    rbx
   1f024:	5d                   	pop    rbp
   1f025:	c3                   	ret    
   1f026:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1f02d:	00 00 00 
   1f030:	55                   	push   rbp
   1f031:	be 02 00 00 00       	mov    esi,0x2
   1f036:	53                   	push   rbx
   1f037:	48 89 fb             	mov    rbx,rdi
   1f03a:	48 83 ec 18          	sub    rsp,0x18
   1f03e:	48 8b 2f             	mov    rbp,QWORD PTR [rdi]
   1f041:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f048:	00 00 
   1f04a:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1f04f:	31 c0                	xor    eax,eax
   1f051:	48 c7 04 24 00 00 00 	mov    QWORD PTR [rsp],0x0
   1f058:	00 
   1f059:	48 c7 87 78 03 00 00 	mov    QWORD PTR [rdi+0x378],0x0
   1f060:	00 00 00 00 
   1f064:	48 8b bf 68 01 00 00 	mov    rdi,QWORD PTR [rdi+0x168]
   1f06b:	e8 10 d9 03 00       	call   5c980 <ext2fs_test_inode_bitmap2@@Base>
   1f070:	85 c0                	test   eax,eax
   1f072:	74 1c                	je     1f090 <check_backup_super_block@@Base+0x1150>
   1f074:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   1f079:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f080:	00 00 
   1f082:	75 42                	jne    1f0c6 <check_backup_super_block@@Base+0x1186>
   1f084:	48 83 c4 18          	add    rsp,0x18
   1f088:	5b                   	pop    rbx
   1f089:	5d                   	pop    rbp
   1f08a:	c3                   	ret    
   1f08b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f090:	48 8b 93 a0 01 00 00 	mov    rdx,QWORD PTR [rbx+0x1a0]
   1f097:	31 f6                	xor    esi,esi
   1f099:	48 89 e1             	mov    rcx,rsp
   1f09c:	48 89 ef             	mov    rdi,rbp
   1f09f:	e8 0c 8a 02 00       	call   47ab0 <ext2fs_new_block2@@Base>
   1f0a4:	48 85 c0             	test   rax,rax
   1f0a7:	75 cb                	jne    1f074 <check_backup_super_block@@Base+0x1134>
   1f0a9:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1f0b0:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
   1f0b4:	e8 77 d8 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1f0b9:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
   1f0bd:	48 89 83 78 03 00 00 	mov    QWORD PTR [rbx+0x378],rax
   1f0c4:	eb ae                	jmp    1f074 <check_backup_super_block@@Base+0x1134>
   1f0c6:	e8 35 6d ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f0cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f0d0:	55                   	push   rbp
   1f0d1:	45 31 c0             	xor    r8d,r8d
   1f0d4:	b9 0a 00 00 00       	mov    ecx,0xa
   1f0d9:	48 8d 15 48 a2 05 00 	lea    rdx,[rip+0x5a248]        # 79328 <_IO_stdin_used@@Base+0x2328>
   1f0e0:	53                   	push   rbx
   1f0e1:	be 02 00 00 00       	mov    esi,0x2
   1f0e6:	48 89 fb             	mov    rbx,rdi
   1f0e9:	48 83 ec 28          	sub    rsp,0x28
   1f0ed:	48 8b 2f             	mov    rbp,QWORD PTR [rdi]
   1f0f0:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f0f7:	00 00 
   1f0f9:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1f0fe:	31 c0                	xor    eax,eax
   1f100:	4c 8d 4c 24 0c       	lea    r9,[rsp+0xc]
   1f105:	48 c7 87 80 03 00 00 	mov    QWORD PTR [rdi+0x380],0x0
   1f10c:	00 00 00 00 
   1f110:	48 c7 44 24 10 00 00 	mov    QWORD PTR [rsp+0x10],0x0
   1f117:	00 00 
   1f119:	48 89 ef             	mov    rdi,rbp
   1f11c:	e8 ef 26 04 00       	call   61810 <ext2fs_lookup@@Base>
   1f121:	48 85 c0             	test   rax,rax
   1f124:	75 1a                	jne    1f140 <check_backup_super_block@@Base+0x1200>
   1f126:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   1f12b:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f132:	00 00 
   1f134:	75 44                	jne    1f17a <check_backup_super_block@@Base+0x123a>
   1f136:	48 83 c4 28          	add    rsp,0x28
   1f13a:	5b                   	pop    rbx
   1f13b:	5d                   	pop    rbp
   1f13c:	c3                   	ret    
   1f13d:	0f 1f 00             	nop    DWORD PTR [rax]
   1f140:	48 8b 93 a0 01 00 00 	mov    rdx,QWORD PTR [rbx+0x1a0]
   1f147:	31 f6                	xor    esi,esi
   1f149:	48 8d 4c 24 10       	lea    rcx,[rsp+0x10]
   1f14e:	48 89 ef             	mov    rdi,rbp
   1f151:	e8 5a 89 02 00       	call   47ab0 <ext2fs_new_block2@@Base>
   1f156:	48 85 c0             	test   rax,rax
   1f159:	75 cb                	jne    1f126 <check_backup_super_block@@Base+0x11e6>
   1f15b:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1f162:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   1f167:	e8 c4 d7 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1f16c:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
   1f171:	48 89 83 80 03 00 00 	mov    QWORD PTR [rbx+0x380],rax
   1f178:	eb ac                	jmp    1f126 <check_backup_super_block@@Base+0x11e6>
   1f17a:	e8 81 6c ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f17f:	90                   	nop
   1f180:	41 57                	push   r15
   1f182:	41 56                	push   r14
   1f184:	41 55                	push   r13
   1f186:	49 89 fd             	mov    r13,rdi
   1f189:	41 54                	push   r12
   1f18b:	49 89 f4             	mov    r12,rsi
   1f18e:	55                   	push   rbp
   1f18f:	48 89 d5             	mov    rbp,rdx
   1f192:	53                   	push   rbx
   1f193:	48 81 ec a8 00 00 00 	sub    rsp,0xa8
   1f19a:	89 4c 24 1c          	mov    DWORD PTR [rsp+0x1c],ecx
   1f19e:	4c 8d 74 24 30       	lea    r14,[rsp+0x30]
   1f1a3:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f1aa:	00 00 
   1f1ac:	48 89 84 24 98 00 00 	mov    QWORD PTR [rsp+0x98],rax
   1f1b3:	00 
   1f1b4:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   1f1b7:	4c 89 f7             	mov    rdi,r14
   1f1ba:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
   1f1bf:	e8 ec 7f 01 00       	call   371b0 <clear_problem_context@@Base>
   1f1c4:	4c 89 e7             	mov    rdi,r12
   1f1c7:	e8 24 b9 01 00       	call   3aaf0 <ea_refcount_intr_begin@@Base>
   1f1cc:	48 8d 44 24 28       	lea    rax,[rsp+0x28]
   1f1d1:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   1f1d6:	eb 5d                	jmp    1f235 <check_backup_super_block@@Base+0x12f5>
   1f1d8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1f1df:	00 
   1f1e0:	8b 4c 24 38          	mov    ecx,DWORD PTR [rsp+0x38]
   1f1e4:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1f1e9:	48 89 ea             	mov    rdx,rbp
   1f1ec:	48 89 c6             	mov    rsi,rax
   1f1ef:	48 89 44 24 58       	mov    QWORD PTR [rsp+0x58],rax
   1f1f4:	e8 17 29 03 00       	call   51b10 <ext2fs_read_ext_attr3@@Base>
   1f1f9:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   1f1fe:	48 85 c0             	test   rax,rax
   1f201:	75 6d                	jne    1f270 <check_backup_super_block@@Base+0x1330>
   1f203:	8b 45 04             	mov    eax,DWORD PTR [rbp+0x4]
   1f206:	8b 5c 24 1c          	mov    ebx,DWORD PTR [rsp+0x1c]
   1f20a:	4c 89 f2             	mov    rdx,r14
   1f20d:	be 3c 00 01 00       	mov    esi,0x1003c
   1f212:	0f af 5c 24 28       	imul   ebx,DWORD PTR [rsp+0x28]
   1f217:	03 5d 04             	add    ebx,DWORD PTR [rbp+0x4]
   1f21a:	4c 89 ef             	mov    rdi,r13
   1f21d:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   1f222:	89 d8                	mov    eax,ebx
   1f224:	48 89 84 24 80 00 00 	mov    QWORD PTR [rsp+0x80],rax
   1f22b:	00 
   1f22c:	e8 bf 7f 01 00       	call   371f0 <fix_problem@@Base>
   1f231:	85 c0                	test   eax,eax
   1f233:	75 53                	jne    1f288 <check_backup_super_block@@Base+0x1348>
   1f235:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
   1f23a:	4c 89 e7             	mov    rdi,r12
   1f23d:	e8 be b8 01 00       	call   3ab00 <ea_refcount_intr_next@@Base>
   1f242:	49 89 c7             	mov    r15,rax
   1f245:	48 85 c0             	test   rax,rax
   1f248:	75 96                	jne    1f1e0 <check_backup_super_block@@Base+0x12a0>
   1f24a:	48 8b 84 24 98 00 00 	mov    rax,QWORD PTR [rsp+0x98]
   1f251:	00 
   1f252:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f259:	00 00 
   1f25b:	75 61                	jne    1f2be <check_backup_super_block@@Base+0x137e>
   1f25d:	48 81 c4 a8 00 00 00 	add    rsp,0xa8
   1f264:	5b                   	pop    rbx
   1f265:	5d                   	pop    rbp
   1f266:	41 5c                	pop    r12
   1f268:	41 5d                	pop    r13
   1f26a:	41 5e                	pop    r14
   1f26c:	41 5f                	pop    r15
   1f26e:	c3                   	ret    
   1f26f:	90                   	nop
   1f270:	4c 89 f2             	mov    rdx,r14
   1f273:	be 3b 00 01 00       	mov    esi,0x1003b
   1f278:	4c 89 ef             	mov    rdi,r13
   1f27b:	e8 70 7f 01 00       	call   371f0 <fix_problem@@Base>
   1f280:	eb c8                	jmp    1f24a <check_backup_super_block@@Base+0x130a>
   1f282:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f288:	89 5d 04             	mov    DWORD PTR [rbp+0x4],ebx
   1f28b:	8b 4c 24 38          	mov    ecx,DWORD PTR [rsp+0x38]
   1f28f:	48 89 ea             	mov    rdx,rbp
   1f292:	4c 89 fe             	mov    rsi,r15
   1f295:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1f29a:	e8 21 29 03 00       	call   51bc0 <ext2fs_write_ext_attr3@@Base>
   1f29f:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   1f2a4:	48 85 c0             	test   rax,rax
   1f2a7:	74 8c                	je     1f235 <check_backup_super_block@@Base+0x12f5>
   1f2a9:	4c 89 f2             	mov    rdx,r14
   1f2ac:	be 3d 00 01 00       	mov    esi,0x1003d
   1f2b1:	4c 89 ef             	mov    rdi,r13
   1f2b4:	e8 37 7f 01 00       	call   371f0 <fix_problem@@Base>
   1f2b9:	e9 77 ff ff ff       	jmp    1f235 <check_backup_super_block@@Base+0x12f5>
   1f2be:	e8 3d 6b ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f2c3:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1f2ca:	00 00 00 00 
   1f2ce:	66 90                	xchg   ax,ax
   1f2d0:	f3 0f 1e fa          	endbr64 
   1f2d4:	53                   	push   rbx
   1f2d5:	48 83 ec 10          	sub    rsp,0x10
   1f2d9:	48 8b 9f e0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xe0]
   1f2e0:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1f2e7:	48 85 ff             	test   rdi,rdi
   1f2ea:	74 5c                	je     1f348 <check_backup_super_block@@Base+0x1408>
   1f2ec:	4c 8b 83 90 03 00 00 	mov    r8,QWORD PTR [rbx+0x390]
   1f2f3:	85 c9                	test   ecx,ecx
   1f2f5:	79 05                	jns    1f2fc <check_backup_super_block@@Base+0x13bc>
   1f2f7:	4d 85 c0             	test   r8,r8
   1f2fa:	75 14                	jne    1f310 <check_backup_super_block@@Base+0x13d0>
   1f2fc:	85 c9                	test   ecx,ecx
   1f2fe:	7e 38                	jle    1f338 <check_backup_super_block@@Base+0x13f8>
   1f300:	48 83 c4 10          	add    rsp,0x10
   1f304:	5b                   	pop    rbx
   1f305:	e9 b6 9d 03 00       	jmp    590c0 <ext2fs_mark_block_bitmap_range2@@Base>
   1f30a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f310:	4c 89 c7             	mov    rdi,r8
   1f313:	89 54 24 0c          	mov    DWORD PTR [rsp+0xc],edx
   1f317:	48 89 34 24          	mov    QWORD PTR [rsp],rsi
   1f31b:	e8 80 9c 03 00       	call   58fa0 <ext2fs_test_block_bitmap_range2@@Base>
   1f320:	48 8b 34 24          	mov    rsi,QWORD PTR [rsp]
   1f324:	8b 54 24 0c          	mov    edx,DWORD PTR [rsp+0xc]
   1f328:	85 c0                	test   eax,eax
   1f32a:	75 1c                	jne    1f348 <check_backup_super_block@@Base+0x1408>
   1f32c:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1f333:	48 85 ff             	test   rdi,rdi
   1f336:	74 10                	je     1f348 <check_backup_super_block@@Base+0x1408>
   1f338:	48 83 c4 10          	add    rsp,0x10
   1f33c:	5b                   	pop    rbx
   1f33d:	e9 6e 9e 03 00       	jmp    591b0 <ext2fs_unmark_block_bitmap_range2@@Base>
   1f342:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f348:	48 83 c4 10          	add    rsp,0x10
   1f34c:	5b                   	pop    rbx
   1f34d:	c3                   	ret    
   1f34e:	66 90                	xchg   ax,ax
   1f350:	f3 0f 1e fa          	endbr64 
   1f354:	55                   	push   rbp
   1f355:	4c 89 cd             	mov    rbp,r9
   1f358:	53                   	push   rbx
   1f359:	4c 89 c3             	mov    rbx,r8
   1f35c:	48 83 ec 28          	sub    rsp,0x28
   1f360:	48 8b 87 e0 00 00 00 	mov    rax,QWORD PTR [rdi+0xe0]
   1f367:	4c 8b 80 a0 01 00 00 	mov    r8,QWORD PTR [rax+0x1a0]
   1f36e:	4d 85 c0             	test   r8,r8
   1f371:	75 09                	jne    1f37c <check_backup_super_block@@Base+0x143c>
   1f373:	4c 8b 47 58          	mov    r8,QWORD PTR [rdi+0x58]
   1f377:	4d 85 c0             	test   r8,r8
   1f37a:	74 1c                	je     1f398 <check_backup_super_block@@Base+0x1458>
   1f37c:	48 83 ec 08          	sub    rsp,0x8
   1f380:	49 89 d9             	mov    r9,rbx
   1f383:	55                   	push   rbp
   1f384:	e8 47 8c 02 00       	call   47fd0 <ext2fs_new_range@@Base>
   1f389:	5a                   	pop    rdx
   1f38a:	59                   	pop    rcx
   1f38b:	48 83 c4 28          	add    rsp,0x28
   1f38f:	5b                   	pop    rbx
   1f390:	5d                   	pop    rbp
   1f391:	c3                   	ret    
   1f392:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f398:	48 89 4c 24 18       	mov    QWORD PTR [rsp+0x18],rcx
   1f39d:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   1f3a2:	89 74 24 0c          	mov    DWORD PTR [rsp+0xc],esi
   1f3a6:	48 89 3c 24          	mov    QWORD PTR [rsp],rdi
   1f3aa:	e8 11 80 04 00       	call   673c0 <ext2fs_read_block_bitmap@@Base>
   1f3af:	48 85 c0             	test   rax,rax
   1f3b2:	75 d7                	jne    1f38b <check_backup_super_block@@Base+0x144b>
   1f3b4:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   1f3b8:	48 8b 4c 24 18       	mov    rcx,QWORD PTR [rsp+0x18]
   1f3bd:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
   1f3c2:	8b 74 24 0c          	mov    esi,DWORD PTR [rsp+0xc]
   1f3c6:	4c 8b 47 58          	mov    r8,QWORD PTR [rdi+0x58]
   1f3ca:	eb b0                	jmp    1f37c <check_backup_super_block@@Base+0x143c>
   1f3cc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1f3d0:	f3 0f 1e fa          	endbr64 
   1f3d4:	55                   	push   rbp
   1f3d5:	48 89 fd             	mov    rbp,rdi
   1f3d8:	53                   	push   rbx
   1f3d9:	48 89 d3             	mov    rbx,rdx
   1f3dc:	48 83 ec 28          	sub    rsp,0x28
   1f3e0:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f3e7:	00 00 
   1f3e9:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1f3ee:	48 8b 87 e0 00 00 00 	mov    rax,QWORD PTR [rdi+0xe0]
   1f3f5:	48 8b 90 a0 01 00 00 	mov    rdx,QWORD PTR [rax+0x1a0]
   1f3fc:	48 85 d2             	test   rdx,rdx
   1f3ff:	74 4f                	je     1f450 <check_backup_super_block@@Base+0x1510>
   1f401:	48 8d 4c 24 10       	lea    rcx,[rsp+0x10]
   1f406:	e8 a5 86 02 00       	call   47ab0 <ext2fs_new_block2@@Base>
   1f40b:	48 85 c0             	test   rax,rax
   1f40e:	75 25                	jne    1f435 <check_backup_super_block@@Base+0x14f5>
   1f410:	48 8b 7d 58          	mov    rdi,QWORD PTR [rbp+0x58]
   1f414:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   1f419:	48 85 ff             	test   rdi,rdi
   1f41c:	74 12                	je     1f430 <check_backup_super_block@@Base+0x14f0>
   1f41e:	e8 0d d5 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1f423:	48 89 ef             	mov    rdi,rbp
   1f426:	e8 a5 d9 03 00       	call   5cdd0 <ext2fs_mark_bb_dirty@@Base>
   1f42b:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   1f430:	48 89 33             	mov    QWORD PTR [rbx],rsi
   1f433:	31 c0                	xor    eax,eax
   1f435:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
   1f43a:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   1f441:	00 00 
   1f443:	75 55                	jne    1f49a <check_backup_super_block@@Base+0x155a>
   1f445:	48 83 c4 28          	add    rsp,0x28
   1f449:	5b                   	pop    rbx
   1f44a:	5d                   	pop    rbp
   1f44b:	c3                   	ret    
   1f44c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1f450:	48 8b 57 58          	mov    rdx,QWORD PTR [rdi+0x58]
   1f454:	48 85 d2             	test   rdx,rdx
   1f457:	74 27                	je     1f480 <check_backup_super_block@@Base+0x1540>
   1f459:	48 8d 4c 24 10       	lea    rcx,[rsp+0x10]
   1f45e:	48 89 ef             	mov    rdi,rbp
   1f461:	e8 4a 86 02 00       	call   47ab0 <ext2fs_new_block2@@Base>
   1f466:	48 85 c0             	test   rax,rax
   1f469:	75 ca                	jne    1f435 <check_backup_super_block@@Base+0x14f5>
   1f46b:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   1f470:	31 c0                	xor    eax,eax
   1f472:	48 89 33             	mov    QWORD PTR [rbx],rsi
   1f475:	eb be                	jmp    1f435 <check_backup_super_block@@Base+0x14f5>
   1f477:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1f47e:	00 00 
   1f480:	48 89 74 24 08       	mov    QWORD PTR [rsp+0x8],rsi
   1f485:	e8 36 7f 04 00       	call   673c0 <ext2fs_read_block_bitmap@@Base>
   1f48a:	48 85 c0             	test   rax,rax
   1f48d:	75 a6                	jne    1f435 <check_backup_super_block@@Base+0x14f5>
   1f48f:	48 8b 55 58          	mov    rdx,QWORD PTR [rbp+0x58]
   1f493:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
   1f498:	eb bf                	jmp    1f459 <check_backup_super_block@@Base+0x1519>
   1f49a:	e8 61 69 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f49f:	90                   	nop
   1f4a0:	41 56                	push   r14
   1f4a2:	41 55                	push   r13
   1f4a4:	49 89 d5             	mov    r13,rdx
   1f4a7:	41 54                	push   r12
   1f4a9:	55                   	push   rbp
   1f4aa:	48 83 ec 28          	sub    rsp,0x28
   1f4ae:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f4b5:	00 00 
   1f4b7:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1f4bc:	31 c0                	xor    eax,eax
   1f4be:	48 8d 6c 24 10       	lea    rbp,[rsp+0x10]
   1f4c3:	48 89 ea             	mov    rdx,rbp
   1f4c6:	e8 95 42 03 00       	call   53760 <ext2fs_xattrs_open@@Base>
   1f4cb:	49 89 c4             	mov    r12,rax
   1f4ce:	48 85 c0             	test   rax,rax
   1f4d1:	74 25                	je     1f4f8 <check_backup_super_block@@Base+0x15b8>
   1f4d3:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   1f4d8:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f4df:	00 00 
   1f4e1:	75 6f                	jne    1f552 <check_backup_super_block@@Base+0x1612>
   1f4e3:	48 83 c4 28          	add    rsp,0x28
   1f4e7:	4c 89 e0             	mov    rax,r12
   1f4ea:	5d                   	pop    rbp
   1f4eb:	41 5c                	pop    r12
   1f4ed:	41 5d                	pop    r13
   1f4ef:	41 5e                	pop    r14
   1f4f1:	c3                   	ret    
   1f4f2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f4f8:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1f4fd:	e8 6e 37 03 00       	call   52c70 <ext2fs_xattrs_read@@Base>
   1f502:	49 89 c4             	mov    r12,rax
   1f505:	48 85 c0             	test   rax,rax
   1f508:	75 24                	jne    1f52e <check_backup_super_block@@Base+0x15ee>
   1f50a:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1f50f:	4c 8d 74 24 08       	lea    r14,[rsp+0x8]
   1f514:	4c 89 e9             	mov    rcx,r13
   1f517:	48 8d 35 68 9a 05 00 	lea    rsi,[rip+0x59a68]        # 78f86 <_IO_stdin_used@@Base+0x1f86>
   1f51e:	4c 89 f2             	mov    rdx,r14
   1f521:	e8 8a 3a 03 00       	call   52fb0 <ext2fs_xattr_get@@Base>
   1f526:	49 89 c4             	mov    r12,rax
   1f529:	48 85 c0             	test   rax,rax
   1f52c:	74 12                	je     1f540 <check_backup_super_block@@Base+0x1600>
   1f52e:	48 89 ef             	mov    rdi,rbp
   1f531:	e8 0a 43 03 00       	call   53840 <ext2fs_xattrs_close@@Base>
   1f536:	eb 9b                	jmp    1f4d3 <check_backup_super_block@@Base+0x1593>
   1f538:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1f53f:	00 
   1f540:	4c 89 f7             	mov    rdi,r14
   1f543:	e8 38 d7 03 00       	call   5cc80 <ext2fs_free_mem@@Base>
   1f548:	48 89 ef             	mov    rdi,rbp
   1f54b:	e8 f0 42 03 00       	call   53840 <ext2fs_xattrs_close@@Base>
   1f550:	eb 81                	jmp    1f4d3 <check_backup_super_block@@Base+0x1593>
   1f552:	e8 a9 68 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f557:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1f55e:	00 00 
   1f560:	b8 08 00 00 00       	mov    eax,0x8
   1f565:	c3                   	ret    
   1f566:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1f56d:	00 00 00 
   1f570:	8b 87 c0 00 00 00    	mov    eax,DWORD PTR [rdi+0xc0]
   1f576:	49 89 f1             	mov    r9,rsi
   1f579:	49 89 d2             	mov    r10,rdx
   1f57c:	48 89 ce             	mov    rsi,rcx
   1f57f:	85 c0                	test   eax,eax
   1f581:	74 3f                	je     1f5c2 <check_backup_super_block@@Base+0x1682>
   1f583:	89 c1                	mov    ecx,eax
   1f585:	ba 01 00 00 00       	mov    edx,0x1
   1f58a:	d3 e2                	shl    edx,cl
   1f58c:	4c 89 c1             	mov    rcx,r8
   1f58f:	83 ea 01             	sub    edx,0x1
   1f592:	48 31 f1             	xor    rcx,rsi
   1f595:	48 63 d2             	movsxd rdx,edx
   1f598:	48 85 d1             	test   rcx,rdx
   1f59b:	75 2b                	jne    1f5c8 <check_backup_super_block@@Base+0x1688>
   1f59d:	4d 85 c9             	test   r9,r9
   1f5a0:	74 1e                	je     1f5c0 <check_backup_super_block@@Base+0x1680>
   1f5a2:	4c 85 c2             	test   rdx,r8
   1f5a5:	74 19                	je     1f5c0 <check_backup_super_block@@Base+0x1680>
   1f5a7:	89 c1                	mov    ecx,eax
   1f5a9:	4c 89 d2             	mov    rdx,r10
   1f5ac:	49 d3 e8             	shr    r8,cl
   1f5af:	48 d3 ea             	shr    rdx,cl
   1f5b2:	49 39 d0             	cmp    r8,rdx
   1f5b5:	74 19                	je     1f5d0 <check_backup_super_block@@Base+0x1690>
   1f5b7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1f5be:	00 00 
   1f5c0:	31 c0                	xor    eax,eax
   1f5c2:	c3                   	ret    
   1f5c3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f5c8:	b8 01 00 00 00       	mov    eax,0x1
   1f5cd:	c3                   	ret    
   1f5ce:	66 90                	xchg   ax,ax
   1f5d0:	48 d3 ee             	shr    rsi,cl
   1f5d3:	49 d3 e9             	shr    r9,cl
   1f5d6:	31 c0                	xor    eax,eax
   1f5d8:	4c 39 ce             	cmp    rsi,r9
   1f5db:	0f 95 c0             	setne  al
   1f5de:	c3                   	ret    
   1f5df:	90                   	nop
   1f5e0:	89 f1                	mov    ecx,esi
   1f5e2:	d3 e7                	shl    edi,cl
   1f5e4:	48 8d 44 17 ff       	lea    rax,[rdi+rdx*1-0x1]
   1f5e9:	31 d2                	xor    edx,edx
   1f5eb:	48 f7 f7             	div    rdi
   1f5ee:	48 d3 e0             	shl    rax,cl
   1f5f1:	c3                   	ret    
   1f5f2:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1f5f9:	00 00 00 00 
   1f5fd:	0f 1f 00             	nop    DWORD PTR [rax]
   1f600:	41 57                	push   r15
   1f602:	41 56                	push   r14
   1f604:	41 55                	push   r13
   1f606:	49 89 cd             	mov    r13,rcx
   1f609:	41 54                	push   r12
   1f60b:	49 89 d4             	mov    r12,rdx
   1f60e:	55                   	push   rbp
   1f60f:	48 89 fd             	mov    rbp,rdi
   1f612:	53                   	push   rbx
   1f613:	48 89 f3             	mov    rbx,rsi
   1f616:	48 81 ec b8 00 00 00 	sub    rsp,0xb8
   1f61d:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
   1f620:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f627:	00 00 
   1f629:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
   1f630:	00 
   1f631:	8b 46 04             	mov    eax,DWORD PTR [rsi+0x4]
   1f634:	48 8b 52 20          	mov    rdx,QWORD PTR [rdx+0x20]
   1f638:	8b 4a 4c             	mov    ecx,DWORD PTR [rdx+0x4c]
   1f63b:	85 c9                	test   ecx,ecx
   1f63d:	74 79                	je     1f6b8 <check_backup_super_block@@Base+0x1778>
   1f63f:	8b 4a 54             	mov    ecx,DWORD PTR [rdx+0x54]
   1f642:	89 c6                	mov    esi,eax
   1f644:	39 c8                	cmp    eax,ecx
   1f646:	72 7b                	jb     1f6c3 <check_backup_super_block@@Base+0x1783>
   1f648:	3b 02                	cmp    eax,DWORD PTR [rdx]
   1f64a:	77 77                	ja     1f6c3 <check_backup_super_block@@Base+0x1783>
   1f64c:	4c 8d 74 24 20       	lea    r14,[rsp+0x20]
   1f651:	48 8d 0d 28 99 05 00 	lea    rcx,[rip+0x59928]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1f658:	48 89 ef             	mov    rdi,rbp
   1f65b:	4c 89 f2             	mov    rdx,r14
   1f65e:	e8 3d 58 01 00       	call   34ea0 <e2fsck_read_inode@@Base>
   1f663:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1f667:	48 8d 4c 24 1c       	lea    rcx,[rsp+0x1c]
   1f66c:	31 d2                	xor    edx,edx
   1f66e:	48 89 de             	mov    rsi,rbx
   1f671:	e8 7a 1b 03 00       	call   511f0 <ext2fs_ext_attr_hash_entry2@@Base>
   1f676:	49 89 c7             	mov    r15,rax
   1f679:	48 85 c0             	test   rax,rax
   1f67c:	0f 85 ae 00 00 00    	jne    1f730 <check_backup_super_block@@Base+0x17f0>
   1f682:	8b 43 0c             	mov    eax,DWORD PTR [rbx+0xc]
   1f685:	3b 44 24 1c          	cmp    eax,DWORD PTR [rsp+0x1c]
   1f689:	74 75                	je     1f700 <check_backup_super_block@@Base+0x17c0>
   1f68b:	41 8b 7c 24 08       	mov    edi,DWORD PTR [r12+0x8]
   1f690:	39 7c 24 30          	cmp    DWORD PTR [rsp+0x30],edi
   1f694:	0f 84 f6 00 00 00    	je     1f790 <check_backup_super_block@@Base+0x1850>
   1f69a:	f6 44 24 42 20       	test   BYTE PTR [rsp+0x42],0x20
   1f69f:	0f 85 db 00 00 00    	jne    1f780 <check_backup_super_block@@Base+0x1840>
   1f6a5:	8b 43 04             	mov    eax,DWORD PTR [rbx+0x4]
   1f6a8:	41 bd 83 00 01 00    	mov    r13d,0x10083
   1f6ae:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f6b3:	eb 19                	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f6b5:	0f 1f 00             	nop    DWORD PTR [rax]
   1f6b8:	b9 0b 00 00 00       	mov    ecx,0xb
   1f6bd:	89 c6                	mov    esi,eax
   1f6bf:	39 c8                	cmp    eax,ecx
   1f6c1:	73 85                	jae    1f648 <check_backup_super_block@@Base+0x1708>
   1f6c3:	49 89 74 24 50       	mov    QWORD PTR [r12+0x50],rsi
   1f6c8:	41 bd 83 00 01 00    	mov    r13d,0x10083
   1f6ce:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
   1f6d5:	00 
   1f6d6:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f6dd:	00 00 
   1f6df:	0f 85 16 01 00 00    	jne    1f7fb <check_backup_super_block@@Base+0x18bb>
   1f6e5:	48 81 c4 b8 00 00 00 	add    rsp,0xb8
   1f6ec:	44 89 e8             	mov    eax,r13d
   1f6ef:	5b                   	pop    rbx
   1f6f0:	5d                   	pop    rbp
   1f6f1:	41 5c                	pop    r12
   1f6f3:	41 5d                	pop    r13
   1f6f5:	41 5e                	pop    r14
   1f6f7:	41 5f                	pop    r15
   1f6f9:	c3                   	ret    
   1f6fa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f700:	48 8b 45 00          	mov    rax,QWORD PTR [rbp+0x0]
   1f704:	8b 53 08             	mov    edx,DWORD PTR [rbx+0x8]
   1f707:	8b b0 c0 00 00 00    	mov    esi,DWORD PTR [rax+0xc0]
   1f70d:	8b 78 28             	mov    edi,DWORD PTR [rax+0x28]
   1f710:	e8 cb fe ff ff       	call   1f5e0 <check_backup_super_block@@Base+0x16a0>
   1f715:	49 89 45 00          	mov    QWORD PTR [r13+0x0],rax
   1f719:	44 8b 6c 24 40       	mov    r13d,DWORD PTR [rsp+0x40]
   1f71e:	41 81 e5 00 00 20 00 	and    r13d,0x200000
   1f725:	0f 84 85 00 00 00    	je     1f7b0 <check_backup_super_block@@Base+0x1870>
   1f72b:	45 31 ed             	xor    r13d,r13d
   1f72e:	eb 9e                	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f730:	8b 4b 04             	mov    ecx,DWORD PTR [rbx+0x4]
   1f733:	ba 05 00 00 00       	mov    edx,0x5
   1f738:	48 8d 35 11 9b 05 00 	lea    rsi,[rip+0x59b11]        # 79250 <_IO_stdin_used@@Base+0x2250>
   1f73f:	31 ff                	xor    edi,edi
   1f741:	89 4c 24 0c          	mov    DWORD PTR [rsp+0xc],ecx
   1f745:	e8 66 66 ff ff       	call   15db0 <dcgettext@plt>
   1f74a:	8b 4c 24 0c          	mov    ecx,DWORD PTR [rsp+0xc]
   1f74e:	4c 89 fe             	mov    rsi,r15
   1f751:	48 8d 3d 3a 98 05 00 	lea    rdi,[rip+0x5983a]        # 78f92 <_IO_stdin_used@@Base+0x1f92>
   1f758:	48 89 c2             	mov    rdx,rax
   1f75b:	31 c0                	xor    eax,eax
   1f75d:	e8 9e 6e 05 00       	call   76600 <com_err@@Base>
   1f762:	31 f6                	xor    esi,esi
   1f764:	48 89 ef             	mov    rdi,rbp
   1f767:	e8 c4 49 01 00       	call   34130 <fatal_error@@Base>
   1f76c:	8b 43 0c             	mov    eax,DWORD PTR [rbx+0xc]
   1f76f:	3b 44 24 1c          	cmp    eax,DWORD PTR [rsp+0x1c]
   1f773:	0f 85 12 ff ff ff    	jne    1f68b <check_backup_super_block@@Base+0x174b>
   1f779:	eb 85                	jmp    1f700 <check_backup_super_block@@Base+0x17c0>
   1f77b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f780:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f785:	41 bd 54 00 01 00    	mov    r13d,0x10054
   1f78b:	e9 3e ff ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f790:	49 8b 54 24 18       	mov    rdx,QWORD PTR [r12+0x18]
   1f795:	8b 7a 64             	mov    edi,DWORD PTR [rdx+0x64]
   1f798:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [rsp+0x84],edi
   1f79f:	0f 85 f5 fe ff ff    	jne    1f69a <check_backup_super_block@@Base+0x175a>
   1f7a5:	31 c0                	xor    eax,eax
   1f7a7:	e9 69 ff ff ff       	jmp    1f715 <check_backup_super_block@@Base+0x17d5>
   1f7ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1f7b0:	8b 43 04             	mov    eax,DWORD PTR [rbx+0x4]
   1f7b3:	4c 89 e2             	mov    rdx,r12
   1f7b6:	be 86 00 01 00       	mov    esi,0x10086
   1f7bb:	48 89 ef             	mov    rdi,rbp
   1f7be:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f7c3:	e8 28 7a 01 00       	call   371f0 <fix_problem@@Base>
   1f7c8:	85 c0                	test   eax,eax
   1f7ca:	74 24                	je     1f7f0 <check_backup_super_block@@Base+0x18b0>
   1f7cc:	8b 73 04             	mov    esi,DWORD PTR [rbx+0x4]
   1f7cf:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1f7d3:	4c 89 f2             	mov    rdx,r14
   1f7d6:	81 4c 24 40 00 00 20 	or     DWORD PTR [rsp+0x40],0x200000
   1f7dd:	00 
   1f7de:	e8 3d ff 03 00       	call   5f720 <ext2fs_write_inode@@Base>
   1f7e3:	e9 e6 fe ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f7e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1f7ef:	00 
   1f7f0:	41 bd 85 00 01 00    	mov    r13d,0x10085
   1f7f6:	e9 d3 fe ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f7fb:	e8 00 66 ff ff       	call   15e00 <__stack_chk_fail@plt>

exec
/bin/bash -lc 'strings -a -t x ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
    350 /lib64/ld-linux-x86-64.so.2
    3c0 lt!y
    461  $0N
    5ca "xA`
    688 HH@@
    6be HP P
    7b7 @P&DL
   102c G**:F**:
   1088 #G|_
   1107 x$qw
   1149 xCS<
   1246 =	JN
   127f :w4 a
   129e (6<rD
   1301 yz9\'5
   1313 R+@ G
   1345 sk?a
   13e5 +PxS
   1487 )<# 
   14ee GhFBo
   1563 "C3vb
   15cf g`H;
   1629 as;Q.
   16f4 iG|0Y
   173d =U`7
   1825 q+ib?,
   1879 _h+.A
   189b X|_s
   18c0 [>^+B
   18d3 Z2w<
   190b 	5-w
   199a 2HrU
   19cf fF,h
   19e5 KGFQ
   1a08 8xyL4
   1a20 ?vng
   1a49 eYRokq
   1ad6 VB+,
   1b32 xep/
   1b3d !.Rs
   1b4c C(4d
   1bd0 (	m]a
   1c42 w+-1fK
   1cb3 |@[5K
   1d35 '2e]
   1d8b $,{/
   80b9 _ITM_deregisterTMCloneTable
   80d5 __gmon_start__
   80e4 _ITM_registerTMCloneTable
   80fe blkid_probe_lookup_value
   8117 blkid_probe_enable_partitions
   8135 blkid_put_cache
   8145 blkid_get_tag_value
   8159 blkid_get_devname
   816b blkid_new_probe_from_filename
   8189 blkid_probe_enable_superblocks
   81a8 blkid_get_cache
   81b8 blkid_do_fullprobe
   81cb blkid_free_probe
   81dc blkid_devno_to_devname
   81f3 uuid_is_null
   8200 uuid_unparse
   820d uuid_generate
   821b setlocale
   8225 qsort
   822b ftruncate64
   8237 hasmntopt
   8241 posix_fadvise64
   8251 __cxa_finalize
   8260 fgets
   8266 __printf_chk
   8273 getpwuid_r
   827e pwrite
   8285 pthread_mutex_lock
   8298 strchr
   829f localtime
   82a9 fileno
   82b0 pthread_mutex_unlock
   82c5 mallinfo
   82ce malloc
   82d5 fcntl
   82db pthread_join
   82e8 getpid
   82ef memmove
   82f7 srandom
   82ff munmap
   8306 pthread_mutex_destroy
   831c posix_memalign
   832b localtime_r
   8337 _setjmp
   833f backtrace_symbols_fd
   8354 __isoc99_fscanf
   8364 __libc_start_main
   8376 secure_getenv
   8384 __fprintf_chk
   8392 strtoul
   839a fputc
   83a0 strcmp
   83a7 fputs
   83ad pthread_attr_destroy
   83c2 __vprintf_chk
   83d0 atoi
   83d5 tcgetattr
   83df fopen
   83e5 getopt
   83ec fclose
   83f3 uname
   83f9 open64
   8400 strcpy
   8407 dcgettext
   8411 backtrace
   841b getrusage
   8425 putenv
   842c strncasecmp
   8438 gmtime_r
   8441 strtod
   8448 strtol
   844f memset
   8456 select
   845d umask
   8463 strcasecmp
   846e pwrite64
   8477 strtoull
   8480 setvbuf
   8488 gnu_dev_major
   8496 optarg
   849d strncmp
   84a5 pread
   84ab getrlimit64
   84b7 __snprintf_chk
   84c6 __ctype_b_loc
   84d4 __open_2
   84dd getuid
   84e4 __ctype_toupper_loc
   84f8 stdout
   84ff __strcat_chk
   850c closedir
   8515 gethostname
   8521 pclose
   8528 fflush
   852f msync
   8535 __strcpy_chk
   8542 pread64
   854a pthread_create
   8559 strncpy
   8561 tzset
   8567 getgid
   856e pipe
   8573 strlen
   857a sbrk
   857f strdup
   8586 sleep
   858c fdopen
   8593 __memcpy_chk
   85a0 getmntent
   85aa fstat64
   85b2 fallocate64
   85be utime
   85c4 memcmp
   85cb daemon
   85d2 asctime
   85da realloc
   85e2 endmntent
   85ec sysconf
   85f4 dcngettext
   85ff tcsetattr
   8609 fsync
   860f geteuid
   8617 abort
   861d __sprintf_chk
   862b fork
   8630 stderr
   8637 ioctl
   863d setrlimit64
   8649 memcpy
   8650 fcntl64
   8658 sigaction
   8662 strnlen
   866a pthread_attr_init
   867c mkstemp
   8684 __longjmp_chk
   8692 strrchr
   869a getegid
   86a2 setmntent
   86ac gettimeofday
   86b9 optind
   86c0 opendir
   86c8 pthread_mutex_init
   86db strerror
   86e4 __xpg_basename
   86f3 perror
   86fa strcat
   8701 lseek64
   8709 bindtextdomain
   8718 __vfprintf_chk
   8727 __errno_location
   8738 popen
   873e __isoc99_sscanf
   874e readdir
   8756 prctl
   875c __stack_chk_fail
   876d ftruncate
   8777 calloc
   877e mmap
   8783 access
   878a __open64_2
   8795 isatty
   879c feof
   87a1 __cxa_atexit
   87ae libblkid.so.1
   87bc libuuid.so.1
   87c9 libc.so.6
   87d3 jbd2_clear_feature_revoke
   87ed ll_rw_block
   87f9 e2fsck_read_inode_full
   8810 ext2fs_file_acl_block_set
   882a ext2fs_bg_flags_test
   883f quota_file_create
   8851 ext2fs_u32_list_iterate_begin
   886f ext2fs_zero_blocks2
   8883 ext2fs_unmark_block_bitmap_range2
   88a5 ext2fs_llseek
   88b3 jbd2_set_feature_csum3
   88ca print_resource_track
   88df dnode_create
   88ec ext2fs_xattrs_read
   88ff ext2fs_extent_insert
   8914 ext2fs_alloc_block3
   8928 ext2fs_hashmap_create
   893e e2fsck_fix_ext3_journal_hint
   895b ext2fs_blkmap64_bitarray
   8974 ext2fs_unmark_valid
   8988 ext2fs_mark_block_bitmap
   89a1 kmalloc_array
   89af ext2fs_tdb_lockall
   89c2 get_empty_dquot
   89d2 ext2fs_read_inode
   89e4 ext2fs_warn_bitmap32
   89f9 ext2fs_write_ind_block
   8a10 e2fsck_clear_progbar
   8a25 e2fsck_allocate_block_bitmap
   8a42 ext2fs_tdb_delete
   8a54 e2fsck_write_inode_full
   8a6c ext2fs_set_data_io
   8a7f e2fsck_add_dx_dir
   8a91 ext2fs_mmp_init
   8aa1 ext2fs_is_fast_symlink
   8ab8 ext2fs_ext_attr_block_csum_set
   8ad7 ext2fs_fast_clear_bit
   8aed ext2fs_set_dir_block
   8b02 ext2fs_free
   8b0e ext2fs_dblist_dir_iterate
   8b28 ext2fs_get_free_blocks
   8b3f test_io_cb_set_blksize
   8b56 ext2fs_bg_free_inodes_count_set
   8b76 ext2fs_copy_dblist
   8b89 ext2fs_block_bitmap_checksum
   8ba6 dict_isempty
   8bb3 ext2fs_file_read
   8bc4 ext2fs_inode_data_blocks2
   8bde ext2fs_verify_csum_type
   8bf6 ext2fs_mark_block_bitmap_range
   8c15 ext2fs_write_dir_block2
   8c2d ext2fs_warn_bitmap
   8c40 ext2fs_crc32_be
   8c50 ext2fs_write_dir_block4
   8c68 remove_error_table
   8c7b ext2fs_free_mem
   8c8b ask_yn
   8c92 initialize_ext2_error_table_r
   8cb0 ext2fs_clear_inode_bitmap
   8cca dnode_get
   8cd4 find_encryption_policy
   8ceb test_io_cb_write_blk
   8d00 ext2fs_tdb_map_size
   8d14 qtree_scan_dquots
   8d26 jbd2_journal_init_revoke
   8d3f ext2fs_descriptor_block_loc
   8d5b e2p_string2feature
   8d6e ext2fs_free_generic_bitmap
   8d89 ext2fs_file_write
   8d9b ext2fs_tdb_chainlock_nonblock
   8db9 ext2fs_read_bitmaps
   8dcd e2fsck_rehash_directories
   8de7 ext2fs_fast_test_block_bitmap_range
   8e0b ext2fs_set_inode_bitmap_range2
   8e2a region_free
   8e36 ext2fs_read_inode_bitmap
   8e4f ext2fs_r_blocks_count_add
   8e69 ext2fs_create_journal_superblock2
   8e8b ea_refcount_fetch
   8e9d ext2fs_flush
   8eaa ext2fs_journal_sb_start
   8ec2 ext2fs_get_memzero
   8ed5 ext2fs_icount_increment
   8eed ext2fs_allocate_subcluster_bitmap
   8f0f ext2fs_rb_insert_color
   8f26 ext2fs_group_desc_csum
   8f3d hash_64
   8f45 e2fsck_use_inode_shortcuts
   8f60 ext2fs_tdb_chainunlock_read
   8f7c sigcatcher_setup
   8f8d profile_iterator
   8f9e ext2fs_file_close
   8fb0 ext2fs_copy_bitmap
   8fc3 ext2fs_add_journal_device
   8fdd get_latch_flags
   8fed ext2fs_block_iterate
   9002 ext2fs_tdb_transaction_commit
   9020 ext2fs_read_ext_attr
   9035 ext2fs_u32_list_free
   904a initialize_prof_error_table_r
   9068 e2fsck_intercept_block_allocations
   908b ext2fs_ext_attr_block_rehash
   90a8 ext2fs_u32_list_iterate
   90c0 ext2fs_check_encoded_name
   90da ext2fs_group_last_block
   90f2 ext2fs_file_get_inode_num
   910c ext2fs_iblk_set
   911c ext2fs_tdb_set_max_dead
   9134 ext2fs_sync_device
   9147 clear_problem_context
   915d ext2fs_new_dir_inline_data
   9178 ext2fs_iblk_sub_blocks
   918f ext2fs_create_icount
   91a4 ext2fs_rb_prev
   91b3 ext2fs_mmp_read
   91c3 ext2fs_init_dblist
   91d6 et_list_lock
   91e3 ext2fs_mark_inode_bitmap2
   91fd ext2fs_ext_attr_hash_entry2
   9219 ext2fs_tdb_validate_freelist
   9236 quotafile_ops_2
   9246 e2p_is_null_uuid
   9257 ext2fs_bg_flags
   9267 _et_dynamic_list
   9278 ext2fs_dblist_iterate
   928e ext2fs_resize_block_bitmap2
   92aa ext2fs_mem_is_zero
   92bd ext2fs_get_memalign
   92d1 ext2fs_free_generic_bmap
   92ea ext2fs_calculate_summary_stats
   9309 ext2fs_dirent_csum_verify
   9323 ext2fs_find_first_set_block_bitmap2
   9347 ext2fs_dirent_set_name_len
   9362 ext2fs_xattrs_open
   9375 check_plausibility
   9388 ext2fs_process_dir_block
   93a1 e2fsck_simple_progress
   93b8 dnode_getkey
   93c5 ext2fs_mmp_update2
   93d8 ext2fs_close_inode_scan
   93f0 fs_proc_check
   93fe ea_refcount_intr_next
   9414 jbd2_clear_feature_64bit
   942d tid_gt
   9434 ext2fs_allocate_generic_bitmap
   9453 ext2fs_file_open
   9464 ext2fs_clear_block_uninit
   947e e2fsck_guess_readahead
   9495 ext2fs_tdb_enable_seqnum
   94ae ext2fs_inline_data_expand
   94c8 ext2fs_unmark_generic_bitmap
   94e5 ext2fs_resize_mem
   94f7 _edata
   94fe ext2fs_dirhash
   950d ext2fs_resize_generic_bmap
   9528 ext2fs_tdb_unlockall
   953d ext2fs_add_exit_fn
   9550 set_latch_flags
   9560 ea_refcount_increment
   9576 quota_set_sb_inum
   9588 profile_get_integer
   959c ext2fs_unmark_inode_bitmap2
   95b8 ext2fs_bg_flags_set
   95cc jbd2_has_feature_64bit
   95e3 ext2fs_write_inode_bitmap
   95fd ext2fs_dirhash2
   960d ext2fs_initialize
   961f profile_init
   962c ext2fs_fast_test_block_bitmap_range2
   9651 jbd2_journal_skip_recovery
   966c ext2fs_free_blocks_count_add
   9689 ext2fs_set_alloc_block_callback
   96a9 ext2fs_set_inode_bitmap_range
   96c7 ext2fs_inode_has_valid_blocks2
   96e6 ext2fs_hashmap_iter_in_order
   9703 ext2fs_bg_flags_clear
   9719 ext2fs_tdb_store
   972a ext2fs_u32_list_create
   9741 ext2fs_remove_exit_fn
   9757 ext2fs_group_last_block2
   9770 e2fsck_get_lost_and_found
   978a end_problem_latch
   979c ext2fs_resize_inode_bitmap
   97b7 ext2fs_r_blocks_count_set
   97d1 e2fsck_allocate_memory
   97e8 ext2fs_get_array
   97f9 profile_iterator_create
   9811 ext2fs_inode_alloc_stats
   982a ext2fs_rb_replace_node
   9841 ext2fs_compare_inode_bitmap
   985d ext2fs_add_journal_inode
   9876 ext2fs_u32_list_equal
   988c io_channel_read_blk64
   98a2 ext2fs_open
   98ae quota_init_context
   98c1 ext2fs_tdb_lockall_mark
   98d9 ext2fs_write_inode2
   98ed ext2fs_write_dir_block
   9904 ext2fs_get_generic_bitmap_end
   9922 e2fsck_readahead_dblist
   993a ext2fs_compare_generic_bmap
   9956 ext2fs_group_desc_csum_set
   9971 e2fsck_global_ctx
   9983 ext2_file_type
   9992 ext2fs_set_inode_callback
   99ac ext2fs_test_block_bitmap_range2
   99cc dict_last
   99d6 ext2fs_group_of_blk2
   99eb ext2fs_tdb_firstkey
   99ff ext2fs_mmp_stop
   9a0f ext2fs_adjust_ea_refcount
   9a29 ext2fs_tdb_reopen_all
   9a3f e2fsck_allocate_context
   9a57 ext2fs_xattr_get
   9a68 ext2fs_test_changed
   9a7c ext2fs_fast_mark_inode_bitmap2
   9a9b io_channel_cache_readahead
   9ab6 ext2fs_free_icount
   9ac9 ext2fs_set_bitmap_padding
   9ae3 e2fsck_dir_info_set_dotdot
   9afe ext2fs_dblist_get_last2
   9b16 ext2fs_bg_free_inodes_count
   9b32 e2fsck_free_dx_dir_info
   9b4a ext2fs_crc32c_le
   9b5b profile_set_default
   9b6f jbd2_journal_get_num_fc_blks
   9b8c check_resize_inode
   9b9f quota_data_inodes
   9bb1 ext2fs_create_resize_inode
   9bcc dict_set_cmp_context
   9be1 ext2fs_inline_data_get
   9bf8 e2fsck_reset_context
   9c0d ext2fs_inode_scan_flags
   9c25 ext2fs_set_bit64
   9c36 ext2fs_write_inode_full
   9c4e e2fsck_dx_dir_info_iter
   9c66 e2fsck_hide_quota
   9c78 ext2fs_count_used_clusters
   9c93 ext2fs_find_first_zero_block_bitmap2
   9cb8 ext2fs_new_range
   9cc9 ext2fs_inode_has_valid_blocks
   9ce7 ext2fs_tdb_fd
   9cf5 ext2fs_mark_bb_dirty
   9d0a jbd2_has_feature_async_commit
   9d28 ext2fs_set_generic_bmap_padding
   9d48 ext2fs_set_generic_bitmap_range
   9d68 ext2fs_crc16
   9d75 e2fsck_adjust_inode_count
   9d8f ext2fs_super_and_bgd_loc2
   9da9 ext2fs_get_generic_bmap_end
   9dc5 profile_release
   9dd5 ext2fs_file_get_lsize
   9deb ext2fs_tdb_nextkey
   9dfe ext2fs_tdb_append
   9e10 e2fsck_pass1_dupblocks
   9e27 ext2fs_blocks_count_set
   9e3f ext2fs_mark_ib_dirty
   9e54 ext2fs_mmp_csum_verify
   9e6b ext2fs_extent_get_info
   9e82 ext2fs_superblock_csum_verify
   9ea0 ext2fs_clear_bit
   9eb1 io_channel_discard
   9ec4 ext2fs_dirent_name_len
   9edb ext2fs_find_first_zero_generic_bitmap
   9f01 ext2fs_tdb_lockall_read_nonblock
   9f22 com_err
   9f2a ext2fs_u32_list_del
   9f3e ext2fs_make_generic_bitmap
   9f59 fix_problem
   9f65 ext2fs_read_bb_FILE2
   9f7a ext2fs_test_generic_bitmap
   9f95 check_backup_super_block
   9fae ext2fs_xattrs_count
   9fc2 dict_prev
   9fcc e2fsck_clear_inode
   9fdf ext2fs_tdb_printfreelist
   9ff8 ext2fs_read_dir_block3
   a00f ext2fs_file_get_fs
   a022 ext2fs_fast_unmark_block_bitmap2
   a043 io_channel_alloc_buf
   a058 ext2fs_adjust_ea_refcount3
   a073 ext2fs_fast_mark_block_bitmap_range2
   a098 jbd2_journal_clear_revoke
   a0b2 quota_type2name
   a0c2 ext2fs_clear_generic_bmap
   a0dc ext2fs_inode_size_set
   a0f2 ext2fs_file_get_size
   a107 ext2fs_fast_unmark_block_bitmap_range
   a12d ext2fs_test_bit64
   a13f ext2fs_mark_generic_bitmap
   a15a ext2fs_mark_super_dirty
   a172 print_e2fsck_message
   a187 e2fsck_allocate_inode_bitmap
   a1a4 ext2fs_tdb_open_ex
   a1b7 ext2fs_get_blocks
   a1c9 ea_refcount_store
   a1db dict_first
   a1e6 ext2fs_check_if_mounted
   a1fe ext2fs_dblist_iterate3
   a215 ext2fs_set_block_alloc_stats_callback
   a23b e2p_jrnl_string2feature
   a253 ext2fs_block_alloc_stats
   a26c ext2fs_tdb_errorstr
   a280 ext2fs_dir_block_csum_set
   a29a ext2fs_get_inode_bitmap_start
   a2b8 ext2fs_tdb_chainlock_read
   a2d2 ext2fs_inline_data_init
   a2ea ext2fs_open_inode_scan
   a301 dict_isfull
   a30d ext2fs_inode_bitmap_csum_verify
   a32d ext2fs_unmark_block_bitmap
   a348 e2p_feature2string
   a35b e2fsck_dir_will_be_rehashed
   a377 ext2fs_new_inode
   a388 ext2fs_group_first_block2
   a3a2 ext2fs_swab16
   a3b0 profile_set_syntax_err_cb
   a3ca ext2fs_read_inode_full
   a3e1 e2fsck_ino_will_be_rebuilt
   a3fc ext2fs_dir_block_csum_verify
   a419 ext2fs_get_ea_inode_ref
   a431 ext2fs_hashmap_free
   a445 e2p_uuid2str
   a452 ext2fs_group_of_blk
   a466 ext2fs_ext_attr_block_csum_verify
   a488 ext2fs_new_block2
   a49a ext2fs_inode_csum_verify
   a4b3 ext2fs_extent_block_csum_set
   a4d0 ext2fs_fast_unmark_inode_bitmap
   a4f0 test_io_manager
   a500 add_encrypted_file
   a513 ext2fs_fast_mark_block_bitmap_range
   a537 ext2fs_tdb_error
   a548 ext2fs_extent_goto
   a55b quota_data_add
   a56a ext2fs_write_bitmaps
   a57f ext2fs_block_iterate3
   a595 error_table_name
   a5a6 ext2fs_get_inode_bitmap_range
   a5c4 ext2fs_tdb_chainlock
   a5d9 ext2fs_write_block_bitmap
   a5f3 ext2fs_get_generic_bmap_range
   a611 ext2fs_rb_erase
   a621 ext2fs_blocks_count
   a635 ext2fs_test_inode_bitmap2
   a64f ext2fs_tdb_lockall_nonblock
   a66b ext2fs_get_rec_len
   a67e ext2fs_get_pathname
   a692 profile_get_double
   a6a5 update_grace_times
   a6b8 ext2fs_read_ext_attr3
   a6ce profile_get_boolean
   a6e2 ext2fs_free_ext_attr
   a6f7 ext2fs_create_journal_superblock
   a718 ext2fs_check_directory
   a72f e2fsck_reconnect_file
   a745 ext2fs_group_of_ino
   a759 jbd2_set_feature_revoke
   a771 ext2fs_get_arrayzero
   a786 ext2fs_inode_data_blocks
   a79f ext2fs_write_new_inode
   a7b6 ext2fs_extent_replace
   a7cc ext2fs_inode_bitmap_csum_set
   a7e9 qtree_entry_unused
   a7fc io_channel_zeroout
   a80f ext2fs_extent_delete
   a824 ext2fs_bg_free_blocks_count
   a840 __data_start
   a84d jbd2_journal_recover
   a862 ext2fs_block_alloc_stats2
   a87c ext2fs_dblist_count2
   a891 ext2fs_get_library_version
   a8ac ext2fs_u32_list_add
   a8c0 ext2fs_allocate_inode_bitmap
   a8dd ext2fs_tdb_chainlock_unmark
   a8f9 e2fsck_rehash_dir
   a90b e2fsck_get_num_dx_dirinfo
   a925 jbd2_journal_destroy_revoke_record_cache
   a94e ext2fs_rb_last
   a95d ext2fs_fudge_block_bitmap_end
   a97b e2fsck_pass4
   a988 ext2fs_mark_inode_bitmap
   a9a1 ext2fs_inode_scan_goto_blockgroup
   a9c3 ext2fs_file_flush
   a9d5 e2fsck_pass2
   a9e2 dict_next
   a9ec ext2fs_close
   a9f9 ext2fs_compare_generic_bitmap
   aa17 ext2fs_dblist_drop_last
   aa2f ext2fs_fast_mark_block_bitmap2
   aa4e ext2fs_group_first_block
   aa67 ext2fs_mark_block_bitmap2
   aa81 jbd2_set_feature_fast_commit
   aa9e ext2fs_write_ext_attr3
   aab5 jbd2_has_feature_csum2
   aacc ext2fs_badblocks_list_test
   aae7 ext2fs_free_dblist
   aafa ext2fs_find_first_set_inode_bitmap2
   ab1e jbd2_journal_bmap
   ab30 ext2fs_tdb_lock_nonblock
   ab49 do_cache_destroy
   ab5a ext2fs_add_journal_inode3
   ab74 region_create
   ab82 ext2fs_tdb_log_fn
   ab94 ext2fs_inode
   aba1 quota_read_all_dquots
   abb7 e2fsck_dir_info_get_parent
   abd2 ext2fs_unmark_block_bitmap_range
   abf3 ext2fs_tdb_reopen
   ac05 ext2fs_bg_checksum
   ac18 ext2fs_inline_data_ea_remove
   ac35 ext2fs_tdb_hash_size
   ac4a ext2fs_group_desc_csum_verify
   ac68 ext2fs_zero_blocks
   ac7b jbd2_clear_feature_csum2
   ac94 ext2fs_extent_get
   aca6 set_undo_io_backing_manager
   acc2 ext2fs_fast_test_block_bitmap
   ace0 ext2fs_badblocks_list_del
   acfa profile_get_string
   ad0d tid_geq
   ad15 ext2fs_map_cluster_block
   ad2e ext2fs_icount_decrement
   ad46 dnode_init
   ad51 ext2fs_fudge_block_bitmap_end2
   ad70 add_to_error_table
   ad83 _IO_stdin_used
   ad92 quota_inode_truncate
   ada7 ext2fs_symlink
   adb6 ext2fs_update_bb_inode
   adcd ext2fs_get_device_sectsize
   ade8 ext2fs_badblocks_list_create
   ae05 ext2fs_tdb_get_seqnum
   ae1b jbd2_set_feature_csum2
   ae32 e2fsck_write_inode
   ae45 ext2fs_alloc_block2
   ae59 e2fsck_can_readahead
   ae6e ext2fs_mmp_update
   ae80 ext2fs_bmap2
   ae8d ext2fs_stat
   ae99 init_resource_track
   aead ext2fs_xattrs_flags
   aec1 ext2fs_inode_bitmap_loc_set
   aedd e2fsck_write_bitmaps
   aef2 initialize_prof_error_table
   af0e ext2fs_badblocks_list_add
   af28 e2fsck_readahead
   af39 ext2fs_dir_iterate
   af4c e2fsck_setup_icount
   af60 ext2fs_div_ceil
   af70 ext2fs_test_block_bitmap
   af89 profile_get_uint
   af9a ext2fs_xattr_inode_max_size
   afb6 quota_remove_inode
   afc9 ext2fs_inode_bitmap_checksum
   afe6 ext2fs_get_ea_inode_hash
   afff ea_refcount_intr_begin
   b016 ext2fs_set_dir_block2
   b02c ext2fs_get_block_bitmap_start2
   b04b ext2fs_fast_set_bit
   b05f ext2fs_tdb_close
   b070 ext2fs_tdb_chainunlock
   b087 write_all
   b091 ext2fs_tdb_traverse_read
   b0aa parse_quota_opts
   b0bb fatal_error
   b0c7 ext2fs_set_gdt_csum
   b0db e2p_uuid_to_str
   b0eb ext2fs_clear_block_bitmap
   b105 ext2fs_rb_next
   b114 ext2fs_new_dir_block
   b129 ext2fs_dx_csum
   b138 jbd2_journal_has_csum_v2or3
   b154 quota_file_exists
   b166 ext2fs_write_dir_block3
   b17e jbd2_has_feature_checksum
   b198 ext2fs_bg_free_blocks_count_set
   b1b8 ext2fs_test_block_bitmap2
   b1d2 ext2fs_flush_icache
   b1e6 ext2fs_dblist_sort
   b1f9 ext2fs_read_bb_FILE
   b20d dict_contains
   b21b quota_type2inum
   b22b destroy_encrypted_file_info
   b247 ext2fs_tdb_transaction_recover
   b266 qtree_write_dquot
   b278 ext2fs_expand_dir
   b28a dict_allow_dupes
   b29b ext2fs_badblocks_list_free
   b2b6 ext2fs_get_num_dirs
   b2ca ext2fs_read_dir_block
   b2e0 ext2fs_get_data_io
   b2f3 ext2fs_init_csum_seed
   b309 ext2fs_tdb_get_flags
   b31e ext2fs_get_inode_bitmap_end2
   b33b ea_refcount_create
   b34e ext2fs_get_refcount_size
   b367 ext2fs_tdb_unlockall_read
   b381 ext2fs_descriptor_block_loc2
   b39e e2fsck_move_ext3_journal
   b3b7 ext2fs_open2
   b3c4 jbd2_journal_set_revoke
   b3dc e2fsck_get_dx_dir_info
   b3f3 quota_write_inode
   b405 e2fsck_read_extents
   b419 ext2fs_fudge_generic_bitmap_end
   b439 e2p_jrnl_feature2string
   b451 ext2fs_block_bitmap_csum_set
   b46e ext2fs_set_generic_bitmap_padding
   b490 ext2fs_fix_extents_checksums
   b4ad ext2fs_load_nls_table
   b4c3 ext2fs_add_dir_block
   b4d8 ext2fs_get_device_phys_sectsize
   b4f8 ext2fs_swab32
   b506 ext2fs_rb_first
   b516 ehandler_operation
   b529 ext2fs_bg_itable_unused_set
   b545 ext2fs_tdb_increment_seqnum_nonblock
   b56a ext2fs_icount_fetch
   b57e sync_blockdev
   b58c ext2fs_extent_goto2
   b5a0 ext2fs_dirent_set_file_type
   b5bc ext2fs_parse_version_string
   b5d8 ext2fs_blocks_count_add
   b5f0 e2fsck_free_dir_info
   b605 check_super_block
   b617 ext2fs_resize_inode_bitmap2
   b633 ext2fs_get_inode_bitmap_start2
   b652 ext2fs_free_inode_bitmap
   b66b e2fsck_read_inode
   b67d ext2fs_file_lseek
   b68f ext2fs_fstat
   b69c ext2fs_mmp_write
   b6ad ext2fs_dirent_file_type
   b6c5 error_message
   b6d3 ext2fs_test_inode_bitmap_range
   b6f2 ext2fs_tdb_parse_record
   b70a ext2fs_alloc_block
   b71d ext2fs_set_generic_bmap_range
   b73b ext2fs_extent_open2
   b74f jbd2_set_feature_async_commit
   b76d ext2fs_set_ea_inode_hash
   b786 ext2fs_fast_unmark_block_bitmap
   b7a6 ext2fs_tdb_name
   b7b6 io_channel_set_options
   b7cd ext2fs_super_and_bgd_loc
   b7e6 quota_release_context
   b7fc ext2fs_find_first_set_generic_bitmap
   b821 ext2fs_tdb_transaction_start
   b83e ext2fs_bg_used_dirs_count_set
   b85c ext2fs_allocate_block_bitmap
   b879 do_cache_create
   b889 ext2fs_inode_bitmap_loc
   b8a1 ext2fs_get_mem
   b8b0 ext2fs_mmp_new_seq
   b8c3 ext2fs_get_block_bitmap_start
   b8e1 ext2fs_inode_table_loc_set
   b8fc ext2fs_inline_data_size
   b914 ext2fs_file_get_inode
   b92a ext2fs_get_generic_bitmap_range
   b94a ext2fs_get_stat_i_blocks
   b963 ext2fs_check_desc
   b975 ext2fs_get_generic_bmap_start
   b993 ext2fs_tdb_dump_all
   b9a7 ext2fs_free_block_bitmap
   b9c0 ext2fs_tdb_open
   b9d0 ext2fs_test_bb_dirty
   b9e5 ext2fs_count_blocks
   b9f9 ext2fs_copy_generic_bitmap
   ba14 e2fsck_expand_directory
   ba2c ext2fs_icount_store
   ba40 jbd2_journal_test_revoke
   ba59 e2fsck_add_dir_info
   ba6d __bss_start
   ba79 ext2fs_write_inode
   ba8c quota_get_qf_name
   ba9e destroy_encryption_policy_map
   babc ext2fs_get_bitmap_granularity
   bada ext2fs_mark_changed
   baee ext2fs_unmark_generic_bmap
   bb09 ext2fs_file_llseek
   bb1c dict_count
   bb27 ext2fs_read_inode2
   bb3a set_undo_io_backup_file
   bb52 ext2fs_fast_clear_bit64
   bb6a log_out
   bb72 ext2fs_get_free_blocks2
   bb8a e2p_feature_to_string
   bba0 ext2fs_iblk_add_blocks
   bbb7 ext2fs_mmp_clear
   bbc8 ext2fs_close_free
   bbda ext2fs_test_valid
   bbec ext2fs_default_journal_size
   bc08 io_channel_write_blk64
   bc1f e2fsck_rewrite_extent_tree
   bc3a ext2fs_tdb_set_logging_function
   bc5a test_io_cb_write_byte
   bc70 ext2fs_extent_block_csum_verify
   bc90 e2p_edit_feature
   bca1 jbd2_has_feature_revoke
   bcb9 ext2fs_test_generic_bmap
   bcd2 qtree_delete_dquot
   bce5 ext2fs_extent_header_verify
   bd01 e2fsck_rebuild_extents_later
   bd1e ext2fs_get_next_inode_full
   bd39 dnode_destroy
   bd47 e2p_edit_feature2
   bd59 ext2fs_dblist_get_last
   bd70 ext2fs_block_bitmap_loc_set
   bd8c dict_init
   bd96 ext2fs_dblist_count
   bdaa ea_refcount_free
   bdbb ext2fs_block_bitmap_csum_verify
   bddb reset_com_err_hook
   bdee ext2fs_fast_test_block_bitmap2
   be0d ext2fs_set_new_range_callback
   be2b ext2fs_create_icount_tdb
   be44 ext2fs_inline_data_dir_iterate
   be63 ext2fs_close2
   be71 check_for_modules
   be83 ext2fs_xattrs_iterate
   be99 set_up_logging
   bea8 quota_file_close
   beb9 ext2fs_bmap
   bec5 ext2fs_set_bit
   bed4 test_io_cb_write_blk64
   beeb ext2fs_get_next_inode
   bf01 ext2fs_decode_extent
   bf16 ext2fs_inode_alloc_stats2
   bf30 ext2fs_ext_attr_hash_entry
   bf4b ext2fs_unmark_block_bitmap2
   bf67 ext2fs_mark_valid
   bf79 jbd2_journal_init_revoke_table_cache
   bf9e ext2fs_u32_list_count
   bfb4 ext2fs_xattr_remove
   bfc8 ext2fs_set_block_bitmap_range
   bfe6 jbd2_chksum
   bff2 jbd2_clear_feature_async_commit
   c012 jbd2_journal_init_revoke_record_cache
   c038 ext2fs_file_block_offset_too_big
   c059 jbd2_journal_destroy_revoke
   c075 io_channel_write_byte
   c08b read_bad_blocks_file
   c0a0 e2fsck_set_bitmap_type
   c0b7 ext2fs_fast_mark_inode_bitmap
   c0d5 ext2fs_lookup
   c0e3 dict_free_nodes
   c0f3 ext2fs_const_inode
   c106 ext2fs_set_ea_inode_ref
   c11e ext2fs_read_ind_block
   c134 qtree_read_dquot
   c145 e2fsck_process_bad_inode
   c15e jbd2_has_feature_fast_commit
   c17b ext2fs_fallocate
   c18c ext2fs_fast_unmark_block_bitmap_range2
   c1b3 ext2fs_tdb_flush
   c1c4 initialize_ext2_error_table
   c1e0 e2fsck_pass1e
   c1ee ext2fs_copy_generic_bmap
   c207 ext2fs_new_block
   c218 ext2fs_bg_itable_unused
   c230 ext2fs_resize_generic_bitmap
   c24d e2fsck_get_num_dirinfo
   c264 ext2fs_extent_free
   c277 ext2fs_sha512
   c285 ext2fs_group_blocks_count
   c29f ext2fs_add_dir_block2
   c2b5 ext2fs_file_set_size2
   c2cb ext2fs_set_block_bitmap_range2
   c2ea ext2fs_unmark_inode_bitmap
   c305 dict_alloc_insert
   c317 journal_tag_bytes
   c329 ext2fs_tdb_fetch
   c33a e2fsck_check_rebuild_extents
   c357 unixfd_io_manager
   c369 ext2fs_blkmap64_rbtree
   c380 unix_io_manager
   c390 ext2fs_badblocks_list_iterate_begin
   c3b4 ext2fs_alloc_generic_bmap
   c3ce ext2fs_warn_bitmap2
   c3e2 ext2fs_superblock_csum_set
   c3fd ext2fs_extent_fix_parents
   c417 ext2fs_bg_has_super
   c42b ext2fs_get_inode_bitmap_range2
   c44a ext2fs_set_rec_len
   c45d ext2fs_block_bitmap_loc
   c475 ext2fs_xattr_set
   c486 ext2fs_swab64
   c494 ext2fs_rw_bitmaps
   c4a6 undo_io_manager
   c4b6 ext2fs_bg_checksum_set
   c4cd ext2fs_read_dir_block2
   c4e4 ext2fs_fast_mark_block_bitmap
   c502 e2fsck_check_ext3_journal
   c51c ext2fs_tdb_lockall_read
   c534 ext2fs_convert_subcluster_bitmap
   c555 ext2fs_extent_set_bmap
   c56c ehandler_init
   c57a jbd2_clear_feature_fast_commit
   c599 e2fsck_dir_info_iter
   c5ae e2fsck_run_ext3_journal
   c5c6 ext2fs_get_dx_countlimit
   c5df ext2fs_get_block_bitmap_range
   c5fd ext2fs_tdb_chainlock_mark
   c617 ext2fs_read_dir_block4
   c62e ext2fs_dblist_sort2
   c642 e2fsck_read_bitmaps
   c656 ea_refcount_decrement
   c66c ext2fs_alloc_range
   c67f ext2fs_resize_block_bitmap
   c69a ext2fs_test_bit
   c6aa ext2fs_find_first_set_generic_bmap
   c6cd quota_compare_and_update
   c6e6 e2fsck_rehash_dir_later
   c6fe ext2fs_test_inode_bitmap
   c717 ext2fs_adjust_ea_refcount2
   c732 jbd2_clear_feature_checksum
   c74e quota_file_open
   c75e ext2fs_max_extent_depth
   c776 ext2fs_clear_bit64
   c789 ext2fs_find_first_zero_generic_bmap
   c7ad jbd2_set_feature_checksum
   c7c7 e2fsck_mmp_update
   c7d9 e2fsck_allocate_subcluster_bitmap
   c7fb ext2fs_block_alloc_stats_range
   c81a dict_lookup
   c826 et_prof_error_table
   c83a ext2fs_hashmap_add
   c84d ext2fs_update_dynamic_rev
   c867 ext2fs_mark_block_bitmap_range2
   c887 ext2fs_get_block_bitmap_end
   c8a3 ext2fs_inode_i_blocks
   c8b9 test_io_backing_manager
   c8d1 ext2fs_test_block_bitmap_range
   c8f0 ext2fs_extent_node_split
   c909 ext2fs_link
   c915 ext2fs_get_journal_params
   c92f region_allocate
   c93f ext2fs_dblist_iterate2
   c956 e2fsck_dir_info_get_dotdot
   c971 ext2fs_dirent_has_tail
   c988 string_copy
   c994 ext2fs_file_acl_block
   c9aa ext2fs_unlink
   c9b8 ext2fs_get_device_size
   c9cf ext2fs_tdb_transaction_cancel
   c9ed ext2fs_u32_list_iterate_end
   ca09 ext2fs_find_inode_goal
   ca20 mark_buffer_dirty
   ca32 ext2fs_mmp_start
   ca43 ext2fs_tdb_lockall_unmark
   ca5d ext2fs_create_icount2
   ca73 e2fsck_validate_quota_inodes
   ca90 get_backup_sb
   ca9e com_err_va
   caa9 e2fsck_dir_info_iter_begin
   cac4 __hash_32
   cace ext2fs_new_block3
   cae0 test_io_cb_read_blk
   caf4 ext2fs_resize_array
   cb08 jbd2_set_feature_64bit
   cb1f e2fsck_dir_info_set_parent
   cb3a preenhalt
   cb44 ext2fs_initialize_dirent_tail
   cb62 profile_iterator_free
   cb78 ext2fs_icount_validate
   cb8f ext2fs_fast_unmark_inode_bitmap2
   cbb0 ext2fs_extent_open
   cbc3 ext2fs_get_block_bitmap_range2
   cbe2 ext2fs_get_inode_bitmap_end
   cbfe ext2fs_read_block_bitmap
   cc17 ext2fs_free_inode_cache
   cc2f add_error_table
   cc3f et_ext2_error_table
   cc53 ext2fs_djb2_hash
   cc64 ext2fs_bitcount
   cc74 e2fsck_pass1_check_symlink
   cc8f ext2fs_read_ext_attr2
   cca5 ext2fs_test_ib_dirty
   ccba e2fsck_pass1_check_device_inode
   ccda dump_mmp_msg
   cce7 ext2fs_clear_generic_bitmap
   cd03 ext2fs_fast_test_inode_bitmap
   cd21 e2fsck_run
   cd2c ext2fs_block_iterate2
   cd42 test_io_cb_read_blk64
   cd58 ext2fs_inode_csum_set
   cd6e ext2fs_tdb_exists
   cd80 ext2fs_create_inode_cache
   cd9a ext2fs_r_blocks_count
   cdb0 ext2fs_get_block_bitmap_end2
   cdcd ext2fs_inline_data_set
   cde4 ext2fs_u32_list_test
   cdf9 get_memory_size
   ce09 qtree_dqstr_in_blk
   ce1c ext2fs_mmp_csum_set
   ce30 ext2fs_htree_intnode_maxrecs
   ce4d e2fsck_pass5
   ce5a ext2fs_free_blocks_count_set
   ce77 mark_buffer_uptodate
   ce8c ext2fs_u32_list_find
   cea1 ext2fs_badblocks_copy
   ceb7 e2fsck_dir_info_iter_end
   ced0 ext2fs_reserve_super_and_bgd
   ceed ext2fs_read_bb_inode
   cf02 ext2fs_badblocks_equal
   cf19 ext2fs_badblocks_list_iterate_end
   cf3b ext2fs_file_set_size
   cf50 e2fsck_free_context
   cf64 _et_list
   cf6d wait_on_buffer
   cf7c ext2fs_xattrs_close
   cf90 ext2fs_get_icount_size
   cfa7 ext2fs_get_dio_alignment
   cfc0 e2fsck_pass3
   cfcd et_list_unlock
   cfdc ext2fs_bg_used_dirs_count
   cff6 e2fsck_pass1
   d003 ext2fs_casefold_cmp
   d017 ext2fs_div64_ceil
   d029 ext2fs_write_ext_attr
   d03f ext2fs_xattrs_write
   d053 ext2fs_punch
   d060 ext2fs_set_block_alloc_stats_range_callback
   d08c ext2fs_mark_generic_bmap
   d0a5 ext2fs_dir_iterate2
   d0b9 ext2fs_get_device_size2
   d0d1 log_err
   d0d9 ext2fs_free_blocks_count
   d0f2 ext2fs_write_ext_attr2
   d109 jbd2_has_feature_csum3
   d120 set_com_err_gettext
   d134 getblk
   d13b ext2fs_tdb_get_logging_private
   d15a quota_compute_usage
   d16e dict_set_allocator
   d181 jbd2_journal_destroy_revoke_table_cache
   d1a9 ext2fs_compare_block_bitmap
   d1c5 ext2fs_fast_test_inode_bitmap2
   d1e4 ext2fs_group_desc
   d1f6 ext2fs_add_journal_inode2
   d210 ext2fs_u32_copy
   d220 jbd2_descriptor_block_csum_set
   d23f ext2fs_fudge_generic_bmap_end
   d25d ext2fs_file_open2
   d26f ext2fs_rewrite_to_io
   d284 ext2fs_inode_table_loc
   d29b ext2fs_fast_set_bit64
   d2b1 ext2fs_find_first_zero_inode_bitmap2
   d2d6 ext2fs_badblocks_list_iterate
   d2f4 ext2fs_bg_flags_zap
   d308 ext2fs_get_generic_bitmap_start
   d328 e2fsck_should_rebuild_extents
   d346 jbd2_clear_feature_csum3
   d35f ext2fs_flush2
   d36d ext2fs_hashmap_lookup
   d383 ext2fs_check_mount_point
   d39c quota_data_sub
   d3ab ext2fs_open_file
   d3bc ext2fs_fudge_inode_bitmap_end
   d3da brelse
   d3e1 dict_insert
   d3ed ext2fs_tdb_traverse
   d401 BLKID_1.0
   d40b BLKID_2.17
   d416 BLKID_2.15
   d421 UUID_1.0
   d42a GLIBC_2.28
   d435 GLIBC_2.11
   d440 GLIBC_2.3.3
   d44c GLIBC_2.14
   d457 GLIBC_2.33
   d462 GLIBC_2.4
   d46c GLIBC_2.10
   d477 GLIBC_2.17
   d482 GLIBC_2.7
   d48c GLIBC_2.34
   d497 GLIBC_2.2.5
   d4a3 GLIBC_2.3.4
   d4af GLIBC_2.3
  165c4 AWAVA
  16680 T$pH
  166ab d$pI
  166b0 t$(H
  166f5 D$pH
  16722 d$pI
  16727 t$8H
  16764 D$pH
  16786 ~@Mc
  167a2 D$pL
  167ca D$pH
  167df d$pI
  167f3 d$pA
  1683f d$pA
  1686d D$`H
  16872 D$PH
  168ba D$`H
  168cd D$pL
  16970 t$`L
  16975 d$XL
  1698b D$pI
  169a6 I#@H
  16a46 D$p1
  16a67 T$ H
  16a6c |$pH
  16a7e |$pH
  16a83 t$XL
  16ab1 |$pL
  16aff D$pH
  16b0d |$pL
  16b3e |$pH
  16b50 |$pL
  16b6d D$pH
  16b9c D$XA
  16be6 D$pH=P
  16c10 D$XH
  16c7a D$pI
  16cd6 D$XH
  16ce4 D$XI
  16d04 D$pI
  16d28 D$pH
  16d38 D$pA
  16d72 |$pH
  16d88 D$pH
  16deb D$XH
  16e1a |$XH
  16e25 ND$0
  16eb0 d$XL
  16f03 |$pA
  16f33 D$pA
  16f62 |$pL
  16f73 D$4 
  16fa0 |$pH
  16ff1 D$8H
  16fff \$8H
  1700e |$pH
  1703f |$8L
  17044 D$pf
  1707b D$pL
  170ea |$XH
  1715a |$pL
  17174 l$@H
  17179 D$ H
  1717e D$ E
  171b2 |$pL
  171d4 |$pH
  171ff |$pH
  1720c D$pM
  1723b D$ I
  17244 D$pM
  17292 |$p1
  172d1 D$pL
  17387 D$pH=
  17405 \$TD
  17450 D$pI
  1747a D$p1
  174a1 |$pH
  174b5 |$p1
  174d9 |$pH
  17504 D$pL
  17512 |$pL
  17544 |$pH
  1758e |$p1
  175e4 D$p1
  17620 |$pH
  17653 D$pL
  17666 |$p1
  1767c D$pL
  176aa |$pH
  176d4 |$pH
  17735 D$pH
  17745 |$p1
  1778f D$pL
  177c0 D$pD
  177f5 |$pH
  1783a D$ I
  17843 D$pM
  17896 t$pL
  178c3 D$p1
  178e5 D$pL
  1790b |$pH
  17958 t$xL
  1795d t$xD
  1797a |$pH
  17998 |$X1
  179d1 |$pH
  179f6 |$pL
  17a34 |$(L
  17a39 D$pI
  17a79 |$pL
  17a95 |$p1
  17ad2 |$pH
  17afb D$pH
  17b31 D$pH
  17b73 D$pH
  17ba4 D$pL
  17bdb l$XL
  17bf7 I#D$H
  17c3d d$pA
  17c42 D$I u
  17c92 d$pI
  17cbc D$I@t
  17cf5 |$pH
  17d0c d$pH
  17d50 |$pH
  17d61 D$4L
  17d70 D$4I
  17d82 L$TH
  17dd9 D$L%
  17e0b |$pH
  17e1c D$4L
  17e40 |$p1
  17e64 D$pH
  17e75 d$pI
  17e7a |$(H
  17e83 L$4H
  17e9b d$pL
  17ed6 D$4H
  17ee0 []A\A]A^A_
  17eed t$xH
  17ef2 t$XL
  17f09 |$pH
  17f43 |$pD
  17f74 D$pH
  17fd9 |$pH
  1800b D$pH
  18067 |$pL
  180e1 PTE1
  1817b u+UH
  18294 w|ATUH
  183a2 ]A\A]
  18480 AWAVAUATI
  18514 []A\A]A^A_
  18830 AWAVI
  1886e AVE1
  18883 []A\A]A^A_
  18919 []A\A]A^A_
  18939 AXAY
  18955 AUATUH
  1896c D$h1
  18a12 D$hdH+
  18a2b ]A\A]A^
  18c49 AVAUATUSH
  18d1a []A\A]A^A_
  18dd6 T$`1
  18e40 AWAVAUATUH
  18e70 EI@t+H
  18e93 []A\A]A^A_
  18eca EI t
  18f3b p@L9
  1905a d$ L
  19074 D$,9
  1909c D$HH
  190a1 T$PH9
  19125 U Y^
  19246 F@H)
  19400 AWAVAUATUH
  1941f D$81
  19443 D$$D
  194ab D$(i
  194f3 L$4H
  1985f L$$A
  1996f D$8dH+
  19984 H[]A\A]A^A_
  19a30 |$4A
  19abd D$0A
  19ac7 L$81
  19b56 D$49
  19cbd AUATI
  19e19 ([]A\A]A^A_
  1a088 []A\A]A^A_
  1a2b0 ATSH
  1a2da X[A\
  1a330 AWAVAUATI
  1a38f []A\A]A^A_
  1a39c D$@H
  1a437 =$k	
  1a443 D$@1
  1a463 T$@H
  1a46e D$@H
  1a499 D$ H
  1a49e D$@L
  1a510 |$@H
  1a551 |$@1
  1a5c2 D$@H
  1a619 T$HH
  1a62c T$HA
  1a634 D$@H
  1a662 D$@H
  1a6d2 L$@H
  1a6fd D$@H
  1a739 D$@H
  1a749 |$@1
  1a7c2 L$@H
  1a7f2 D$@H
  1a83a T$@H
  1a92e D$@H
  1a93e |$@1
  1a94a l$@A
  1a95a ELHc
  1a98a l$@Hc
  1a9ac D$@H
  1a9c6 |$@H
  1a9df l$@H
  1aa42 D$@H
  1aa47 =dv	
  1aa61 D$@E1
  1aa89 l$@t
  1aa90 ML0I
  1aac4 D$@E1
  1aaec l$@t
  1ab78 T$X1
  1ab87 l$P1
  1acb8 D$(H
  1ad03 |$@H
  1ad15 T$X1
  1ad24 l$P1
  1ae34 D$@H
  1ae44 |$@1
  1ae79 D$@H
  1ae89 |$@1
  1aec1 HcD$<L
  1aec8 l$@I
  1af08 HcD$<L
  1af64 D$@H
  1af74 |$@1
  1afa8 D$@L
  1afbb |$@1
  1afeb D$@H
  1affb |$@1
  1b007 l$@A
  1b052 D$@1
  1b085 |$@1
  1b0ad D$@1
  1b0dc Hc01
  1b0e8 |$@1
  1b0fe |$@H
  1b127 |$@H
  1b192 ~l;=
  1b215 GH u
  1b294 AUATUSH
  1b2af D$(1
  1b46f D$(dH+
  1b483 []A\A]
  1b5c4 ATUSH
  1b60f []A\
  1bb94 AVUSH
  1bbd6 --\	
  1bc63 []A^
  1bd20 AUATI
  1bd3e D$h1
  1bd63 T$hdH+
  1bd74 x[]A\A]
  1bda1 \$PL
  1bdc0 AWAVM
  1bde1 4$dH
  1bdee D$h1
  1be13 \$ L
  1be34 l$`H
  1be65 L$@L
  1be6a L$ L
  1be71 T$<L
  1be9e t$LE
  1bec4 HcT$H
  1bee6 D$hdH+
  1beff []A\A]A^A_
  1c0a4 AWAVAUATUSH
  1c0c4 l$(I
  1c0c9 T$8H
  1c0de I9A8
  1c14b C L9
  1c22a []A\A]A^A_
  1c380 AUATUSH
  1c398 D$hH
  1c3b6 T$hdH+
  1c3c7 x[]A\A]
  1c440 ATUSH
  1c464 []A\
  1c4d6 []A\
  1c4e0 AWAVAUATUSH
  1c537 []A\A]A^A_
  1c54a l$ H
  1c562 D$ H
  1c59b CTD9
  1c880 ATUSH
  1c893 D$hH
  1c8e2 D$hdH+
  1c8f3 p[]A\
  1c934 AWAVAUATI
  1c960 l$0H
  1ca2e y E9y
  1caa4 []A\A]A^A_
  1cb82 E E1
  1cc32 E E1
  1cc77 D$(H
  1cd41 E Hc
  1cd68 D9}0w
  1cdb4 AWAVAUATUH
  1cde8 |$ A
  1cdf0 D$,A
  1ce0e t$0A
  1ce2f t$@H
  1ce37 L$(D
  1ce48 t$0H
  1ce67 t$0H
  1ce86 t$ H
  1cf2b []A\A]A^A_
  1d03f L$(D
  1d119 L$(E1
  1d17d D$0A
  1d1df L$(Hc
  1d215 A9G 
  1d25b GXf=
  1d2ee D$ A
  1d349 T$8H9
  1d36a |$ H
  1d39f H;D$
  1d3b0 H;D$
  1d40b H;D$
  1d41c H;D$
  1d477 H;D$
  1d48a T$HH
  1d492 H;D$
  1d50c A;G w
  1d51c A;G(
  1d5c2 A9\$0
  1d62f 9D$,w
  1d63f A;G(v1
  1d794 A;G(
  1d8ff D$hH
  1d975 D$ L
  1d9e6 L$<A
  1da0b D$ t
  1da6a \$41
  1da90 D$41
  1daaf D$4L
  1dabe L$8H
  1daf4 D$ A
  1db1e  u[M
  1db23 D$ H
  1dbba D$ A
  1dc07 D$ A
  1dc3c D$ A
  1dcf5 D$ L
  1dd5d D$ A
  1dda2 |$ 1
  1ddc3 A9\$0w
  1ddee D$ H
  1de50 D$ H
  1df44 ATUSH
  1df9a H#EH
  1dffd |$8S
  1e03a L$\A
  1e043 9H\u[
  1e049 P`3T$`
  1e055 Pd3T$d
  1e081 t$hH
  1e0c0 []A\
  1e3d9 fdUSH
  1e40a []A\A]
  1e41e []A\A]
  1e430 ATSH
  1e445 D$h1
  1e491 D$hdH+
  1e4a2 x[A\
  1e4e0 ATSH
  1e4f5 D$h1
  1e541 D$hdH+
  1e552 x[A\
  1e590 ATUH
  1e5b0 D$h1
  1e5c3 D$hdH+
  1e5d8 p[]A\
  1e6c5 @ 0u
  1e720 ATUSH
  1e735 u	[]A\
  1e785 Gp+Fpt
  1e7d4 []A\
  1e7e0 AWAVAUATI
  1e802 D$x1
  1e982 D$xdH+
  1e99b []A\A]A^A_
  1ea52 |$8B
  1ea65 D9mH
  1eae5 AVAUATUSH
  1ebae D9o0w
  1ec4d ([]A\A]A^A_
  1ed70 []A\A]A^
  1ed9e D$h1
  1edce D$hdH+
  1ee10 AUATI
  1ee5b []A\A]
  1ef30 AWAVI
  1ef7c tKH=
  1efa0 ]A\A]A^A_
  1f180 AWAVAUI
  1f1a0 t$0dH
  1f1ce D$(H
  1f1e1 L$8H
  1f1fb D$0H
  1f264 []A\A]A^A_
  1f28c L$8H
  1f2a1 D$0H
  1f4a0 AVAUI
  1f4a7 ATUH
  1f4ea ]A\A]A^
  1f600 AWAVAUI
  1f64e t$ H
  1f690 9|$0
  1f69b D$B 
  1f6c5 t$PA
  1f6ef []A\A]A^A_
  1f71b l$@A
  1f782 D$PA
  1f80a AUATI
  1f826 D$8H
  1f847 D$(E
  1f878 t$ H
  1f8b6 D$0L
  1f945 H+t$
  1f9b1 D$0I
  1fa34 D$8dH+
  1fa49 H[]A\A]A^A_
  1fa5b H+t$
  1fa7f D$8dH+
  1faa3 L$ H
  1faa9 H[]A\A]A^A_
  1fb80 AWAVAUATUSH
  1fd0a ]A\A]A^A_
  1fd40 []A\A]A^A_
  1fd84 VLfA
  1fe80 AWAVA
  1fe87 AUATI
  1fea7 |$0H
  1feda t$pL
  1ff5e D$0H=H
  1ff8d D$0H
  1ffbf D$`E1
  1ffca HcL$
  1fff6 L$(K
  2000a D$0H
  20024 L$(L
  20036 D$0H
  20042 L9t$
  20056 t$XL
  20085 D$0H
  200a1 L9t$
  200da D$HH
  200fb []A\A]A^A_
  20154 D$0H
  20160 Lct$
  201c0 AWAVI
  201c7 AUATUSH
  2038c ([]A\A]A^A_
  203d0 AWAVI
  203d7 AUATUSH
  2040b @tbf%
  2048e []A\A]A^A_
  20508 D$(H
  20692 l$ A
  2072a t	D9
  20780 ATUH
  20799 D$h1
  207eb D$hdH+
  20800 p[]A\
  20894 AWAVAUATUSH
  208da l$(I
  208df T$8H9
  2094a []A\A]A^A_
  209b6 E9}0
  209c2 |$@D
  20ad5 PXH9
  20ae1 P\H9
  20aed @`H9
  20c74 AWAVAUATI
  20cf9 L$,H
  20d05 D$ L
  20d21 D$0H
  20d2a L$<H
  20e1a u8E1
  20e2a {`E1
  20f27 =TUU
  20f4f ugE1
  20f5b []A\A]A^A_
  21245 AUATA
  21292 []A\A]A^
  212ae ]A\A]A^
  212c0 AWAVI
  212c7 AUATI
  212ec t$`L
  212f1 D$(L
  212f6 L$ L
  2138f T$PD
  2139c l$@I
  213a1 t$0A
  213aa T$PD
  213bc l$(f=
  213c5 D$8H
  213d5 D$8A
  2140c l$HE
  2141e \$@t
  2146b \$`H=w
  21526 D$<D
  21539 L$4D
  2153f T$;I9
  21555 H9D$H
  21562 D$(H
  2157e D$ H9
  215be L9l$HtdH
  215e9 D$HM
  215ee l$(L
  21626 l$HAPL
  21638 L$0H
  2164d AYAZ
  21706 []A\A]A^A_
  21723 L$@I
  21751 D$PD
  21776 l$X_AXD
  217be H#D$@Hc
  217ce D$0L
  217de l$(L
  217fa l$Hf
  2180c \$@D
  21811 L$PM
  218d0 l$HI
  218e1 N(L9
  2190a l$HA9
  2191c T$@A
  21943 D$@M
  21951 L$HI
  21990 \$0I
  219ec HcD$d
  219f6 T$lH
  21a33 D$PH
  21a38 T$@H
  21a9e \$(L
  21ba2 D$HL
  21ba7 \$@D
  21bc4 \$0I
  21bd3 t$@H
  21be3 \$@H
  21bf3 L$PE9
  21c9f D$PL
  21ce1 D$PD
  21cf3 D$@D
  21cf8 T$<I
  21d03 L$;H
  21d11 L$;D
  21d17 T$<I9
  21d47 t$HL
  21d8c T$PA!
  21d98 l$HI
  21d9d F`I9
  21de2 l$HD
  21e0a D$:L
  21e0f l$HE1
  21e73 l$HD
  21e79 T$:D
  21ea0 \$@H
  21eca \$@H
  21ee3 L$4I
  21f3a l$HM
  21fa2 l$H@
  22000 AWAVM
  220d5 []A\A]A^A_
  22107 4$H9
  221ba D$PH
  22320 AWAVAUATI
  2235b D$x1
  223bf D$xdH+
  223db []A\A]A^A_
  22459 T$hL
  22466 D$hH
  224d2 l$(A
  225e6 |$(1
  22619 L$8H
  2262c L$8H
  22631 D$pL
  22636 |$@L
  2263b l$PL
  22640 l$(H
  22645 \$XM
  2265b D$0L
  226e0 D$PL
  2270e L9|$
  22769 D$LM
  22781 |$@L
  2278b l$PH
  22790 \$XD
  227f4 |$(D
  22802 D$HD
  22866 T$ L
  22873 D$hH
  22883 T$8H
  2288b D$ H
  2292a L$0L
  22941 D$pH
  229b0 |$@D
  229b5 D$LH
  229ba |$(D
  22ba0 |$@L
  22ba5 l$PL
  22baf D$LH
  22bbe D$LL
  22bc3 t$0L
  22bd5 |$@L
  22bda l$PH
  22bdf \$XD
  22c09 L+L$
  22c15 l$PL
  22c1a |$@M
  22c22 D$LH
  22c31 D$LL
  22c36 t$0L
  22c41 |$@L
  22c7f T$hH
  22cc0 D$PL
  22d74 AVAUATUSH
  22d82 JldH
  22d8f D$x1
  22dd3 H;D$@A
  22de5 D$xdH+
  22dfe []A\A]A^
  22e74 Sdf.
  22f42 D$(u
  230d4 ([]A\A]A^A_
  2318e D	uH
  231a3 ]A\A]A^
  231c9 D$(A
  231cf D$8A
  23210 AWAVA
  232b6 D$lA
  232e0 D$ %
  232ea D$ D
  23308 []A\A]A^A_
  23329 []A\A]A^A_
  233aa D$ %
  233c2 D$ %
  233d0 AWAVAUATI
  233f9 D$X1
  2343b D$ H
  23453 HcD$0u
  2347e E0H;E(
  23531 D$M@
  23548 D$XdH+
  2355d h[]A\A]A^A_
  236a0 AWAVAUI
  236a9 ATUH
  236df |$0H
  236ec t$ A
  23743 L$ H
  23768 t$pH
  23772 T$4H
  237ca D$ H
  237d2 D$8D
  23818 T$4L
  23823 L$0L
  23857 D$HH
  2387f EM@t$A
  238ea R H9T$8s
  2396b BTD9
  23981 D$ H
  239b9 D$(H
  23a1f D$8A
  23a44 |$(A
  23a65 L$HE
  23aaa D$HH
  23ae7 T$ f%
  23ba6 []A\A]A^A_
  23bd6 L$PA
  23bed |$(H
  23c16 D$HH
  23c32 T$0H
  23d20 D$HA
  23d25 |$(H
  23d42 T$0H
  23e02 =93	
  23e1f D$HA
  23e24 |$(H
  23e3a l$8L
  23e82 D$8H
  23eb5 D$ H
  23f64 BTD9
  24061 D$HL
  240b0 AWAVAUATUSH
  240fc []A\A]A^A_
  24117 l$ I
  24122 Hc5O0	
  24130 =K0	
  241d4 D$(D
  243a2 AVAUATUH
  243df \$ H
  2440b D$ D
  24475 D$lL
  2447a t$hH
  244bc =/,	
  24711 D$pHi
  24754 D$ D
  2477f t$0L
  2479d D$(H
  24801 T$xL
  24813 |$0H
  24834 |$x1
  24845 D$pH
  2484a |$xH
  248a9 D$ A
  248f3 D$<A
  24918 |$$1
  24946 D$dH
  2494b \$HH
  24971 |$TI
  24976 D$ 1
  2499c T$pH
  249a8 |$xI
  249bc D$h9D$d
  24a61 t$df
  24ac4 t$dH
  24b05 t$ D
  24b26 t$d9
  24b3e T$$E
  24bf3 t$d9
  24c00 D$pf
  24c1c t$dH
  24c2d t$ H
  24c96 B! t%
  24cc2 T$@L
  24ce5 t$pD
  24d1a T$8E
  24d86 t$dH
  24ddf D$df
  24f06 []A\A]A^A_
  24fdd |$xH
  2505f D$pE1
  250bc L$XH
  250d6 t$d1
  251ab t$dD
  25221 t$(L
  25267 L$$E
  252d9 t$dH
  2537b T$pA
  253ac L$8E
  253f7 T$pH
  25424 T$pH
  25445 t$dH
  2545c T$pH
  25475 D$pD
  254ad t$dH
  25503 t$ D
  25518 t$d9
  2552f t$dM
  25562 t$dH
  2556f t$ H
  2559f t$dH
  255a4 T$p1
  25661 t$dH
  2568a L$@H
  25719 t$d1
  25724 t$dH
  257e2 t$p1
  257fa T$p1
  2584c D$pE1
  25885 t$dH
  2598e t$dH
  259be T$0H9
  259cc D$ H
  25a4a D$ A
  25a60 D$pf
  25b0e t$d1
  25b99 t$d1
  25bc1 t$dH
  25c3c t$dH
  25ce1 T$pf
  25cea t$dH
  25d02 t$dH
  25d9b t$dH
  25da8 t$ H
  25dc6 t$d1
  25e1a t$dH
  25e3f t$dL
  25e64 t$dH
  25ee3 t$d1
  25f11 t$dL
  2611e L$@L
  26153 t$dH
  26221 D$pL
  26250 T$pf
  26294 T$pL
  262b0 T$pL
  263f5 T$(1
  26401 \$ H
  2640b l$ f
  2641e \$ H
  2643c D$(dH+
  26482 T$(1
  2648e \$ H
  264ae \$ H
  264cc D$(dH+
  264f4 ATUSH
  264fa l$ D
  26504 w*D;E
  26532 []A\
  26638 []A\A]A^A_
  26764 AWAVAUATUH
  26783 []A\A]A^A_
  267f2 H9B(L
  26827 =t		
  26880 AUATI
  268a1 D$x1
  26905 D$xdH+
  2691a []A\A]
  26950 AUATUSH
  26a58 []A\A]
  26a66 []A\A]
  26a70 AUATUSH
  26acb ;]0sp
  26b32 []A\A]
  26b46 []A\A]
  26bf4 AWAVAUATUSH
  26c10 []A\A]A^A_
  26c95 t9L9c
  26d24 AWAVAUI
  26d43 y(dH
  26d50 D$(1
  26d7e GLE1
  26ddd u1E1
  26de4 D$(dH+
  26dfd []A\A]A^A_
  26e3e D$ L
  26e7f t$ H
  26f02 T$ M
  26f2c t$ E
  26f63 |$XH
  26fc2 t$ I
  27070 AWAVAUATI
  2709e t$PL
  270c4 \$LH
  270ec d$XH
  270f1 l$`H
  27134 []A\A]A^A_
  27154 \$HH
  271b9 T$0M
  27208 D$(I
  2722f t$(L
  2724c T$(H
  273a5 t$0H
  273c2 T$0L
  274a0 AWAVI
  274c7 |$`H
  274f6 d$(D
  27508 \$ H
  27539 D$`H
  275b1 L$,D
  27651 []A\A]A^A_
  2767f L$ D
  276e4 $H=Z
  276ed D$`t^H
  2770c L$ E1
  277b0 AWAVAUATI
  277c6 t$0dH
  277df D$8H
  277e4 D$PH
  2789c C(E1
  278af D$(M
  2797b L$(H
  27997 D$`HcA
  27a2a D$HL
  27a54 D$hH
  27b1b []A\A]A^A_
  27b57 L$0H
  27b6b D$PH
  27c0b L$0H
  27c30 AWAVAUATUH
  27c4e |$pL
  27c86 T$ H
  27c93 D$pH
  27cb6 l$0H
  27ccc |$`H
  27d12 D$pH=B
  27d57 D$`L
  27d5c t$XH
  27d63 t$8L
  27de8 T$`H
  27e6a L$0L
  27e80 D$pH
  27eb8 t$(H
  27ec3 L$01
  27eca D$(H
  27edb T$(L
  27f11 t$xL
  27f47 []A\A]A^A_
  27f94 AVAUATUH
  27fc1 d$`L
  27fff D$`H
  28156 []A\A]A^
  2833a AUE1
  283a6 []A\A]A^A_
  283f0 []A\
  2841c ATUH
  28450 ]A\A]
  28574 []A\A]
  2859d []A\A]
  285f9 ]A\A]A^
  28610 AWAVI
  286e8 []A\A]A^A_
  28850 A+4$
  2887b ([]A\A]A^A_
  28920 u	D9
  28a90 []A\A]
  28ac0 t(H9
  28b3a D$(USH
  28bb1 []A\
  28c47 []A\A]A^
  28c70 tnAUH
  28ca7 []A\A]
  28cd6 []A\A]
  28cf0 AWAVAUATI
  28d5e []A\A]A^A_
  28d75 t$ L
  28e71 T$$H
  28f02 D$`L
  29090 AVAUI
  290fd []A\A]A^
  29150 tFD9
  29205 ATUH
  29270 []A\A]
  29390 AWAVAUI
  2944a []A\A]A^A_
  29615 AVAUATI
  29658 xdfD
  296bc A9\$
  2972a x,Hc
  29801 ([]A\A]A^A_
  29981 ([]A\A]A^A_
  29a0a AUATM
  29a4f D$@H
  29b12 L$ L
  29b28 l$ H
  29b44 D$@H
  29b96 []A\A]A^A_
  29bcf D$@H=Z
  29cb9 AVAUATUSH
  29cfe D$0H
  29d82 D$(H
  29f6d 0E9f
  2a002 d$(L
  2a02b []A\A]A^A_
  2a152 d$(L
  2a2f4 AWAVA
  2a2fb AUATA
  2a327 |$ dH
  2a35f t$(D
  2a364 d$0L
  2a504 []A\A]A^A_
  2a699 H9D$
  2a9c9 AVAUATI
  2aa1f D$ H
  2aa6d t HcSpHcKtH
  2aacc D$ D
  2ab75 D$0H
  2ab8e D$\H
  2abbd t$ E
  2abf1 <vA1
  2accb D$@H
  2ad29 D$8D
  2ad6f |$HH
  2adad D$dD
  2adcc |$(E1
  2ae52 D$8N
  2ae80 CXH;D$
  2aebd d$0E
  2aede &D;d$`
  2af00 D$(H
  2af1c BTD9
  2af80 t$PH
  2afbf l$(A
  2aff3 D$xL
  2b013 +D$x
  2b050 t$PL
  2b0fe L$h9A v
  2b10b t$h9F$s
  2b191 t$PE
  2b1a7 L;\$
  2b1b4 t$hE
  2b1bc l$`L
  2b1c1 |$(L
  2b21f CXfA
  2b352 []A\A]A^A_
  2b3ed D$@H
  2b45d t$@H
  2b532 L$hH
  2b6cd D$@H
  2b722 L$dD
  2b737 T$PH
  2b762 |$(H
  2b783 D$xA9
  2b7ca t$0E
  2b89e |$(H
  2b901 T$`H
  2b9dd t$PM
  2ba81 L$PE
  2bab1 T$`H
  2bb6d D$@H
  2bc82 D$(A
  2bd11 |$(1
  2bd30 L$(I
  2bd78 |$HL
  2bd9e |$`L
  2bec0 t]fA
  2bef0 T$8H
  2bef5 t$ E
  2bf0c |$HL
  2bf2c T$PE
  2bf47 L$tL
  2bf4c D$8H
  2bf57 L$@L
  2bf7c T$`A
  2bfad t$8L
  2bfc2 t$8L
  2c01a D$P0
  2c130 AWAVAUA
  2c162 |$ H
  2c22f []A\A]A^A_
  2c2b4 AWAVAUI
  2c2d0 q(dH
  2c428 ([]A\A]A^A_
  2c4c0 AVAUATUSH
  2c54f |$XH
  2c58e D$(f
  2c6cf D$ H
  2c742 []A\A]A^
  2c834 AVAUATUSH
  2c87d []A\A]A^
  2c944 ATE1
  2c960 D$h1
  2c98a D$hdH+
  2c9a3 []A\
  2ca74 AWAVAUATUSH
  2cac5 []A\A]A^A_
  2cad2 l$0H
  2cbc4 t$ I
  2ccbc D$ H
  2ccd7 D$0H
  2cd07 T$(D
  2cd56 D$0H=&
  2cee8 D$0H
  2cf41 L$ 1
  2cf60 t$ I
  2d106 D$0H
  2d144 AWAVAUATA
  2d1bb []A\A]A^A_
  2d21d d$ M
  2d2e4 AWAVAUATA
  2d3e1 []A\A]A^A_
  2d505 AVAUE1
  2d6ef []A\A]A^A_
  2d789 AVAUATUSH
  2d7b5 l$`H
  2d80c D$`H
  2d8fd []A\A]A^A_
  2dad0 AWAVI
  2dae1 ATUH
  2dafd D$x1
  2db41 C" t!H
  2db69 D$xdH+
  2db82 []A\A]A^A_
  2dba4 H9D$
  2dbd7 t$`H
  2dc27 AVAUA
  2dc4d D$x1
  2dd4c T$xdH+
  2dd65 []A\A]A^A_
  2de59 AVAUATUSH
  2de9d D$@H
  2df2a Hct$
  2dfee ATD9
  2e051 d$,D
  2e059 l$.L
  2e096 D$.E
  2e09c t!f=
  2e0bf f9D$,
  2e159 []A\A]A^A_
  2e16a T$0L
  2e189 L$8H
  2e1ac T$0D
  2e1f2 |$0E
  2e218 T$0D
  2e239 D$,f9
  2e250 t$.H
  2e299 D$.L
  2e394 D$8H
  2e3a9 D$.H
  2e3fa t$.H
  2e47a t|wB
  2e490 B0H9B(tx
  2e4e2 B0H9B(t&
  2e553 CM t
  2e577 []A\A]
  2e580 AWAVAUI
  2e589 ATUSH
  2e5e3 D$HH
  2e5e8 D$PH
  2e61f D$8I
  2e710 []A\A]A^A_
  2e904 t$@H
  2e909 t$HD
  2e90e L$,A
  2e9c5 \$xH
  2e9fe  9o$t0A
  2ea46 D$8H
  2ec0a G0E1
  2ec15 D$8D
  2ec35 E9g0w
  2ec44 l$ I
  2ec7f D$xH
  2ed54 |$81
  2edaa D$xH
  2edc8 D$8L
  2ee45 ATUH
  2ee5d U D9B(
  2ef03 ]A\A]
  2ef33 []A\A]
  2ef40 AVAUI
  2ef47 ATUSH
  2ef5d D$x1
  2eff4 D$xdH+
  2f00a []A\A]A^
  2f0f0 AVAUI
  2f0f7 ATUSH
  2f10d D$x1
  2f1a1 }XH9
  2f1c9 D$xdH+
  2f1df []A\A]A^
  2f2f0 AWAVAUATUH
  2f312 D$x1
  2f340 D$xdH+
  2f359 []A\A]A^A_
  2f36a d$$L
  2f4a0 AWAVAUATUH
  2f4c2 D$x1
  2f4f0 D$xdH+
  2f509 []A\A]A^A_
  2f51a d$(L
  2f685 AVAUATUSH
  2f6b4 D$@H
  2f6e9 D$0H
  2f7b0 []A\A]A^A_
  2f92b |$LD
  2f939 L$H@
  2f988 P(A9
  2f99a D$M t
  2fb38 9T$L
  2fb4f D$,D
  2fb5d D$,D
  2fb62 |$LD
  2fb67 |$HD
  2fc1c D$HE
  2fc3a u0E1
  2fc49 D$0D
  2fc84 D$HH
  2fca2 D$0H
  2fcbd D$8D
  2fcf5 D$HH
  2fd13 D$8H
  2fd30 D9m0
  2fd4c D$HH
  2fef3 |$01
  2ff06 |$81
  2ff62 T$ 1
  2ff7e \$ H
  2ffd4 AUATUH
  2fffc l$PL
  30076 ]A\A]
  30284 ATUH
  302b6 $[]A\
  302c5 []A\
  30391 t=Hc
  3046c []A\
  304de :I;9u
  30560 AWAVI
  30567 AUATUSH
  306c6 ([]A\A]A^A_
  30848 tNH9
  3084d tIUH
  308a0 AWAVAUATI
  308bf D$(1
  30943 T$(dH+
  30958 8[]A\A]A^A_
  30993 Hct$
  30a06 t$dH
  30a56 T$ H
  30ad0 AUATI
  30aea D$81
  30b18 T$8dH+
  30b29 @]A\A]
  30b90 AUATI
  30baa D$(1
  30c12 T$(dH+
  30c23 0]A\A]
  30caf t Hc[
  30ce0 AWAVAUATUH
  30d3a []A\A]A^A_
  30d60 T$ L
  30d8c D$ f%
  30da0 @tMf=
  30eb0 ATUSH
  30ec6 D$(1
  30f24 D$(dH+
  30f39 []A\
  310f8 ~&SH
  3110c [#B$
  31149 D	@$[
  31168 !B$[
  31178 ~&SH
  3118c [#B(
  311c9 D	@([
  311e8 !B([
  311f8 ~&SH
  3120c [#B(
  31249 D	@([
  31268 !B([
  31278 ~&SH
  3128c [#B(
  312c9 D	@([
  312e8 !B([
  312f8 ~&SH
  3130c [#B(
  31349 D	@([
  31368 !B([
  31378 ~&SH
  3138c [#B(
  313c9 D	@([
  313e8 !B([
  313f8 ~&SH
  3140c [#B(
  31449 D	@([
  31468 !B([
  3169a v(AUA
  316a1 ATUH
  316b7 L$HH
  316c0 9HcOx
  316f4 D$4A
  31740 T$HdH+
  31755 X[]A\A]A^A_
  31848 )L$0
  31949 AVAUATI
  31999 IcD$xM
  31a5b []A\A]A^A_
  31bb3 []A\A]A^A_
  31bf7 t-HcExH
  31cff X []A\
  31d6c AWHc
  31da4 tbL9
  31df8 []A\A]A^A_
  31e90 ATUSH
  31ea6 D$hH
  31efa D$hdH+
  31f0b p[]A\
  31f20 AVAUATUSH
  31f3a D$xH
  31ffa T$xdH+
  32010 []A\A]A^
  320b2 A#E(
  320cb A#E,
  323ce <$3|$
  32420  []A\
  32450 ATUH
  324a0 []A\
  32545 AVAUATUSH
  3256d d$PH
  325b6 D$@H
  325d8 D$8H
  325e6 T$@L
  326f1 []A\A]A^A_
  3272b D$0H
  3275e t$0f
  32890 T$@HcJx1
  328be L$ H
  328d4 t$0I
  328dc D$ D
  32917 IcpxH
  32932 T$HA
  32976 T$@H
  329d8 D$(H
  329f5 D$(Mcp
  32ab8 T$@Hc4$H9
  32ade D$(H
  32d13 L$0I
  32e30 AVAUATUH
  32e4c D$x1
  32e6d D$xdH+
  32e89 ]A\A]A^
  32fe4 AWAVAUATUH
  3302c l$ L
  33099 []A\A]A^A_
  333dd AUATUH
  33517 []A\A]A^
  335e4 AWAVAUATUH
  33610 l$ L
  3369e []A\A]A^A_
  338c2 |$PD
  3391d D$ L
  33944 AUATUSH
  33998 []A\A]
  339e6 t$pH
  33a94 ATUSD
  33ac9 E D;`
  33b01 []A\
  33b19 AUATI
  33c20 []A\A]A^
  33e10 Hc01
  33ef4 AUATI
  33f08 T$0H
  33f0d L$8L
  33f12 D$@L
  33f1f )D$P
  33f24 )L$`
  33f29 )T$p
  33ff6 [A\A]
  34014 AUATI
  34028 T$0H
  3402d L$8L
  34032 D$@L
  3403f )D$P
  34044 )L$`
  34049 )T$p
  3411d [A\A]
  34134 AUATUSH
  342a4 AUATI
  342fe []A\A]
  34347 tWUH
  343cf ATUSH
  343e3 t$(L
  34449 t$01
  34450 t$ H
  3446a D$`f
  3446f oL$01
  34479 oT$@f
  3447f o\$P
  3448a T$pH
  34496 D$hL
  3449f )L$p
  34519 L$(I
  3467b T$ 1
  346a8 []A\A]A^A_
  346e0 L$(I
  34706 )D$0
  3470b )D$@
  34710 )D$P
  347d2 T$ 1
  348b7 ]A\A]
  348c0 ]A\A]
  348f6 A\A]
  34941 A\A]
  34962 ATUH
  34995 ]A\A]
  349d4 ATSH
  34ac8 oL$ H
  34b54 AWAVAUI
  34b9d |$01
  34bc2 H+C0H=
  34bd4 T$@L
  34be4 LcL$`LcD$\
  34bf3 Lc|$PLct$@H
  34c77 t$XH
  34c8e t$HH
  34ca6 t$8H
  34cab |$0H
  34d53 t$(L
  34d5d T$(H
  34d75 H+C8H+S@H
  34db2 t$8H
  34dfe []A\A]A^A_
  34e1b |$01
  34e37 H+C0
  34ea9 ATUH
  34ec8 []A\A]
  34f19 ATUH
  34f38 []A\A]
  34f89 ATUH
  34fa8 []A\A]
  34ff9 ATUH
  35018 []A\A]
  35064 AVAUATUSH
  350d8 []A\A]A^
  35212 u|fA
  35397 ATUSH
  353aa D$X1
  354cc T$XdH+
  354dd h[]A\A]
  354f4 AWAVAUATI
  35525 t9E1
  3554b []A\A]A^A_
  35684 AUATUSH
  356c5 []A\A]
  356ef ]A\A]
  35715 T$@H
  3571a L$HL
  3571f D$PL
  3572c )D$`
  35731 )L$p
  35770 D$(1
  3589c D$(dH+
  358c4 ATSH
  35924 AVAUATUH
  359c1 []A\A]A^
  359d4 AVAUATUH
  35a9c []A\A]A^
  35b71 []A\
  35be1 []A\
  35c51 []A\
  35c90 AVE1
  35c9e AUATA
  35cd1 D$81
  35d72 D$8dH+
  35d87 @[]A\A]A^
  35fb0 ATSH
  36114 AUATI
  36191 ([]A\A]
  36324 ATSH
  363f5 Hc01
  364b4 AWAVAUATUSH
  3656f []A\A]A^A_
  366ce ATLc
  36719 D9)s
  36728 4vD9,
  3673a D;+tR
  367cf []A\A]A^
  368ce tPA90tK
  368eb 90u*
  369bb []A\
  36a04 AVAUATUSH
  36a6a []A\A]A^
  36a81 |$0H
  36aec D$0E
  36af8 []A\A]A^
  36b44 AWAVAUATUSH
  36bae []A\A]A^A_
  36bc9 |$PM
  36c4f D$PE
  36dc7 ATUH
  371f4 AWAVI
  37200 ATUH
  37216 D$8H
  373e5 D$8dH+
  373fe []A\A]A^A_
  37562 d$/E
  3758e L$ E1
  375b6 D$ H
  376f0 K E1
  37af9 D$h1
  37b39 T$hdH+
  37b60 AVAUI
  37b67 ATUH
  37bf0 []A\A]A^
  37c00 ATUH
  37d10 AVAUATUH
  37d8c ]A\A]A^
  37e0e ]A\A]A^
  37eb0 AUATM
  37f10 []A\A]
  37f34 []A\A]
  37f50 []A\A]
  37f83 ]A\A]
  37fa6 []A\A]
  380b9 []A\A]
  3816e []A\A]
  38185 []A\A]
  38539 AVAUATI
  38590 <%t|A
  385fc ([]A\A]A^A_
  38649 Dt\L
  38700 AWAVAUATI
  38745 @8>u
  3874c 	~1H
  38769 A\A]A^A_
  387d3 ]A\A]A^A_
  3886f ATUH
  3898e []A\A]A^A_
  38a94 AWAVAUATI
  38ab6 D$x1
  38b2b D$xdH+
  38b40 []A\A]A^A_
  38ba4 AWAVAUATI
  38bc5 D$h1
  38c25 D$hdH+
  38c36 x[]A\A]A^A_
  38c70 AUATI
  38c90 t9HcEx
  38ccf []A\A]
  38ce0 ATUH
  38d12 []A\
  38d20 ATUH
  38d6f []A\
  38dd5 []A\A]A^
  38e6a AUATI
  38f34 []A\A]A^A_
  38f46 []A\A]A^A_
  38f60 AVAUATUSH
  39003 []A\A]A^
  39090 AWAVI
  3909b ~4ATI
  390a9 oxdH
  390b6 D$(1
  3914b D$(dH+
  39160 []A\A]A^A_
  39170 AWAVI
  3917c ATUH
  391d2 CHI9
  3925d ([]A\A]A^A_
  392a0 AVAUATUSH
  392ae w8dH
  392f7 4$A+M8A
  39314 M;uHv
  39330 []A\A]A^
  39340 AWAVI
  3939a D$`E
  393ea \$`H
  393ef |$hL
  3941f D$HH9
  39429 \$XH)
  39431 \$`L
  39443 A9F(
  394f7 []A\A]A^A_
  39569 \$`H
  39580 D$HH9
  3958a \$XH)
  39592 \$`L
  3962b V49D$\
  3965c H9\$
  39746 L$\H
  3974b T$`L
  3981e l$0I
  39827 D$(HcD$HD
  39831 l$LH
  39836 D$ L
  3983b t$8I
  39843 D$x+D$
  3984f H+T$(H
  39856 T$ H9
  39867 l$|H
  3986c D$|A
  39889 l$`L
  39897 T$`H
  398b3 D$HH9
  398bd T$XH)
  398c5 T$`D
  398cd |$pL
  3992d D$pH
  39943 T$xI
  39948 |$pL
  39965 D$pIcT$xH
  3999f D$0H
  399d3 t$8H
  399d8 l$0D
  399dd l$LL
  39b12 H9\$
  39b43 l$8H
  39be9 []A\
  39e34 AVAUATUSH
  39e9a tlE1
  39eab rOL9
  39eb9 vAH9
  39ebe s<L9
  39f3d []A\A]A^
  3a090 AVAUATUH
  3a123 ]A\A]A^
  3a29d []A\A]
  3a5a4 []A\A]
  3a5bd []A\A]
  3a614 ATUSL
  3a667 A9,$
  3a66d []A\
  3a6d0 AUATI
  3a6f2 xjHc
  3a720 []A\A]
  3a764 []A\A]
  3a7a9 ATUSH
  3a8a2 []A\
  3ac40 AUATUSH
  3ac9a []A\A]
  3acbb u3A9
  3ad15 ATUH
  3ad9a []A\A]
  3adc8 []A\A]
  3ae10 <zt-<Zt
  3ae50 AWAVI
  3ae5c ATUS
  3ae70 t$ L
  3ae95 D$<H
  3ae9a D$PH
  3aed0 T$8A
  3af13 A9_4
  3afbd D$LL
  3afdb tsE1
  3afe2 l$0D
  3b035 t$LA9o4v
  3b045 A9o4w
  3b04d l$0H
  3b0a4 t$ H
  3b0bd D$LD
  3b0c4 |$HL
  3b0d8 XZA9_4
  3b100 D$,H
  3b10a []A\A]A^A_
  3b1c5 D$(1
  3b1d6 T$(dH+
  3b1eb 8[]A\A]A^A_
  3b25b D$ E
  3b3e8 t>[]A\
  3b41f []A\
  3b4b1 []A\
  3b4c5 AVAUATI
  3b52f []A\A]A^A_
  3b5ff AUATUSH
  3b6a0 4$L9
  3b70b H+4$H
  3b7c7 roM9
  3b811 H+4$H
  3b86b L;d$
  3b89f L;d$
  3b8a9 ([]A\A]A^A_
  3b910 AWAVI
  3b917 AUATUSH
  3b92d T$0dH
  3b93b D$X1
  3b9a2 D$@H
  3b9ac D$XdH+
  3b9c0 D$@H
  3b9c6 h[]A\A]A^A_
  3b9e0 T$PL
  3ba07 D$@H
  3ba26 D$<L
  3ba86 T$HH
  3ba8b t$0L
  3baa1 E(+D$,L
  3baa9 d$PL
  3bacd ;D$8
  3bb84 ;T$<
  3bb9a D$8A
  3bba1 E9~4
  3bbcd T$(L
  3bbe7 T$(L
  3bc03 E(+D$,A
  3bc0d D$ )
  3bc45 D$ 1
  3bcae T$PL
  3bd4e T$PL
  3bdf5 AVAUATM
  3be0c t$pHcT$xH
  3be39 D$(H
  3be6c T$ L
  3be88 T$(dH+
  3be99 8[]A\A]A^A_
  3bf0f ATE1
  3bfff []A\A]A^A_
  3c010 AWAVAUATUH
  3c038 D$x1
  3c069 D$LH
  3c07a t$<A
  3c086 \$P1
  3c0d6 T$xdH+
  3c0ef []A\A]A^A_
  3c150 D$`D
  3c17a \$@L
  3c17f T$HL
  3c184 |$XH
  3c189 D$DL
  3c18e d$hE1
  3c199 l$PH
  3c19e t$pL+e
  3c1ac PASSUH
  3c1b3 L$0H
  3c1de T$DD
  3c1e3 D$@L
  3c1e8 d$hL
  3c1ed l$PH
  3c1f2 L$pH
  3c224 T$D9\$
  3c24c \$@L
  3c251 T$HL
  3c256 |$XH
  3c25b T$PM
  3c263 t$hASL
  3c26d D$DL
  3c272 \$(PSUH
  3c27a |$(L
  3c27f D$lL
  3c297 \$ H
  3c2ca l$LE
  3c2f2 t$pH
  3c324 D$@A9
  3c33d D$@H
  3c342 L$`E1
  3c34d T$PH
  3c352 t$pPL
  3c35b D$DPSAW
  3c377 D$@D
  3c39c D$hD
  3c3a2 l$<H
  3c3a7 \$(D)
  3c3d2 \$(I
  3c454 AWAVAUATUSH
  3c46d D$81
  3c50d D$ H
  3c532 T$(D
  3c544 D$4D
  3c549 d$$1
  3c699 L$ E
  3c6d2 T$8dH+
  3c6e7 H[]A\A]A^A_
  3c7b7 WAVD
  3c7bc D$<L
  3c8c3 AVAUI
  3c939 )D$`
  3c93e )D$p
  3c9a6 \$@H
  3c9ea []A\A]A^A_
  3ca06 \$@H
  3ca2f D$(D
  3ca34 d$pL
  3ca41 D$`H
  3ca53 D$hH
  3caa0 D$8H
  3cb02 |$xM
  3cb92 \$@A
  3cbbd \$@L
  3cc1e EM@trD
  3cc42 D$hD
  3ccc9 AVAUATUSH
  3ccf2 D$ H
  3cdce D$pH
  3cf51 []A\A]A^A_
  3cfa5 ATUH
  3d01c []A\A]
  3d069 <Dt{
  3d0db []A\A]
  3d0f6 t$@A
  3d3c0 AVAUATUSH
  3d400 ~<Lc-
  3d424 <(Ic
  3d45b []A\A]A^
  3d470 AWAVAUI
  3d62b []A\A]A^A_
  3d65f ~(Hc
  3d7ca AUATUH
  3d810 <%t|A
  3d87e []A\A]A^
  3d8d0 AWE1
  3d8d7 AVAUI
  3d90f D$h1
  3d96b D$(H
  3d97f d$ H
  3d993 D$(H
  3d9ba D$(H
  3d9c3 8/tyH
  3d9db l$0E1
  3d9f8 t$@L
  3da05 t$ L
  3da35 |$ L
  3da42 |$0H
  3da7e l$ H
  3daeb T$hdH+
  3db00 x[]A\A]A^A_
  3db21 L$(H
  3dbb2 |$0M
  3dbe6 t$ 1
  3dc16 l$PH
  3e0d4 []A\A]
  3e0e9 []A\A]
  3e0f0 AWAVAUI
  3e0f9 ATUH
  3e1bc []A\A]A^A_
  3e242 T$(dH+
  3e284 AWAVAUATUSH
  3e29d D$H1
  3e2c2 T$HdH+
  3e2d7 X[]A\A]A^A_
  3e2fa T$@A
  3e325 D$(L
  3e32a |$$H
  3e336 t$8L
  3e35c T$$H
  3e361 |$@H
  3e369 Dt$8
  3e3c9 t$(H
  3e3e2 |$@H
  3e423 T$ ;B 
  3e43b |$@H
  3e483 T$ ;B(
  3e49b |$@H
  3e4cc T$ ;B(
  3e4e9 D$(A
  3e516 t$(H
  3e51b |$@A
  3e542 t$@L
  3e600 u>A;A
  3e6e6 AVAUI
  3e6ed ATUH
  3e706 D$H1
  3e774 D$HdH+
  3e78e X[]A\A]A^A_
  3e7a9 L$(L
  3e823 |$(L
  3e8de H+D$
  3e940 AVAUATI
  3e952 v(dH
  3e95f D$81
  3e975 T$8dH+
  3e98a H]A\A]A^
  3e99a t$ H
  3ea37 L;D$ 
  3ea42 A;D$
  3eacc H;t$(
  3eb13 ATUH
  3eb94 tzf.
  3ebba ]A\A]A^
  3ec4b AUATUSH
  3ec7b )D$ 
  3ec80 )D$0
  3ec88 )D$@
  3eccf []A\A]A^A_
  3ed05 D$PH
  3ed43 D$4U
  3eee6 AVAUE1
  3eeed ATUH
  3ef02 D$81
  3ef18 )D$ 
  3ef36 9rTw-H
  3ef6a D$8dH+
  3ef7f ]A\A]A^A_
  3efc4 ATUH
  3efef 9rTw,
  3f0bb ATUH
  3f12e []A\A]
  3f25b []A\A]
  3f306 ~8;L
  3f364 AWAVAUI
  3f3cf []A\A]A^A_
  3f418 t$`H
  3f458 HcD$pH
  3f471 E0I;E(
  3f4b7 \$0L
  3f51e D$$u
  3f531 HcT$4
  3f53b |$8H
  3f585 []A\A]A^A_
  3f730 AWAVI
  3f7a0 []A\A]A^A_
  3f84d []A\A]A^A_
  3f86a ATUH
  3f8ab ]A\A]A^
  3f900 AWAVAUI
  3f909 ATUSH
  3f929 D$X1
  3f930 t$(H
  3f935 L$0L
  3f95d D$XdH+
  3f976 []A\A]A^A_
  3f98a t$0H
  3f98f |$(H
  3f994 l$@H
  3fa1f |$8L
  3fa27 oD$@H
  3fab4 AUATI
  3fb36  ]A\A]
  3fc64 ATUSH
  3fcd8 []A\
  3fe25 ATUSH
  3fe77 []A\A]
  3ff2f []A\A]
  40027 U(I9
  40031 t'RH
  4009e []A\
  400d4 ATUH
  401a4 AVAUA
  401ab ATUH
  4020d ]A\A]A^
  4023c BTD9
  4027c ]A\A]A^
  402f4 AWAVAUATUSH
  4036b ([]A\A]A^A_
  403ae $tnH
  40496 AVAUATI
  404fe []A\A]A^A_
  40574 AWAVAUATUH
  405a3 D$(1
  405b7 D$(dH+
  405d0 []A\A]A^A_
  405e2 D$ f
  405f1 T$ H
  40647 D$ H
  40679 T$ A
  40729 []A\A]
  4074a []A\A]
  407a7 L)h@H
  407b9 []A\A]
  407da []A\A]
  407fe ATLc
  40849 []A\A]
  4086a []A\A]
  40884 AWE1
  40889 AVAUATUSH
  408a0 D$(1
  408b8 T$ L
  40902 |$ D
  409d8 AXAYL
  409e3 D$(dH+
  409fc []A\A]A^A_
  40a72 |$ L
  40ab4 AWAVAUATE1
  40ad0 D$(1
  40b01 D$(dH+
  40b1a []A\A]A^A_
  40bd4 AWAVAUATU
  40c0a t$ H
  40c56 D$XH
  40d00 []A\A]A^A_
  40d2d |$@H
  40d54 AUATI
  40de9 []A\A]
  40e46 D$ 1
  40ea7  []A\
  40fa0 AUATUSH
  41047 []A\A]
  410a4 AVAUI
  41109 D$(%
  41177 []A\A]A^
  41476 <"tF
  4149b t#<"t
  41643 t;UH
  41704 []A\A]
  41730 AWAVAUATUSH
  417ff []A\A]A^A_
  418bb []A\
  418f3 []A\
  419ad []A\A]
  419cb []A\A]
  419e0 AVAUATUH
  41a23 [t*1
  41a3f  []A\A]A^
  41e10 AVAUATE1
  41e66 []A\A]A^
  41f70 AUATI
  41fbb <$~D
  42003 []A\A]
  420b0 AWAVAUATUH
  421b4 t$ L
  421c8 D$8%
  421db D;l$
  4220f t"Mc
  42268 []A\A]A^A_
  42307 tWUH
  42374 AWAVAUATUH
  4239a D$81
  4240c t$0H
  4241f d$0I
  4243c |$(H
  42464 D$(H
  424a1 D$(H
  424f6 |$(H
  42544 D$8dH+
  42559 []A\A]A^A_
  42584 AWAVAUATUSH
  4259d D$81
  4261b T$ 1
  4262d )D$ 
  426f3 D$8dH+
  4270d H[]A\A]A^A_
  42722 D$ L
  427bd AVAUATUSH
  42832 []A\A]A^
  42877 t'SH
  428b0 AWAVAUATUSH
  428c8 t$ H
  428cd T$(H
  42903 ]8E1
  4290e E09G
  4294d D$ H
  4295e D$(H
  4296d 8[]A\A]A^A_
  42a8d T$ H
  42aa2 T$(H
  42aae []A\A]A^A_
  42aea E0HcE4H
  42bd9 8[]A\A]A^A_
  42c10 ATUSL
  42c26 D$81
  42c44 L$ H
  42c62 D$8dH+
  42c77 []A\
  42d74 AVAUATE1
  42e04 wBIc
  42e19 H9l$
  42e3a []A\A]A^
  42e74 AUATE1
  42efe H9l$
  42f1f []A\A]
  42f54 AVAUATE1
  42f6e D$(1
  42fbd t$ H
  42fe9 H9l$ u8L
  42ff5 D$(dH+
  4300a []A\A]A^
  430e4 AUATUH
  4319d []A\A]
  432c4 AUATA
  43334 ]A\A]
  433b4 AUATA
  43424 ]A\A]
  435b1 H;C(|!H
  43624 AVAUA
  4362b ATUH
  436b2 ]A\A]A^
  43730 AVAUA
  43737 ATUH
  437e4 D$ H
  43836 ]A\A]A^
  438ee ATUH
  43977 []A\A]A^
  43b69 V8ATUH
  43bcb []A\
  43bed []A\
  43c04 AWAVAUATA
  43c2f D$(1
  43c7f L$ D
  43cb4 D$ H
  43d52 D$(dH+
  43d6b []A\A]A^A_
  43e80 |$ A
  44065 D$8H
  4411f T$8dH+
  444a8 D$(1
  44538 CPH9
  44567 T$(dH+
  44658 )D$ 
  4465d )D$0
  446ba D$HdH+
  44774 D$8dH+
  44a70 AVAUA
  44af6 []A\A]A^
  44bd4 []A\
  44c14 []A\
  44c20 ATUH
  44cca []A\
  44d30 9wPv
  44d77 t$$1
  44dfa AUATUH
  44f34 ]\Mc
  44f61 []A\A]A^A_
  44fe0 AWAVAUI
  450b5 ([]A\A]A^A_
  452c0 AUATA
  45315 ,$fA
  45386 []A\A]
  454ad  []A\A]A^
  45559 wPAUI
  455aa D$`L
  455e4 \$\I
  45600 []A\A]A^A_
  45702 []A\A]A^
  4574a AUATUH
  4576d D$(1
  45779 D$ H
  457b2 D$ H
  4582f D$(dH+
  45844 8[]A\A]A^A_
  45860 AWAVA
  45867 AUATA
  4588f D$(1
  4589b D$ H
  45944 D$(dH+
  4595d []A\A]A^A_
  45a04 AUATUSH
  45a77 9E\tJ
  45ae6 []A\A]
  45c82 9C\tK
  45d03  []A\
  45d44 AUATI
  45dc5 ClE1
  45dfb []A\A]
  45e47 H9:t
  45eb3 t;ATI
  45ee4 []A\
  45f00 AUE1
  45f05 ATUSH
  45f39 []A\A]
  46044 AUATUSH
  4606e T$ H
  46081 $$L9
  46092 []A\A]
  460b2 ,$H9
  4610c V H9
  461e6 []A\A]
  4633f I90t
  46396 G8H9G0
  46471 ]A\A]
  46514 AUATA
  4659b []A\A]
  465c4 AUATA
  465fb  ujH
  4662a  t'H
  4665b []A\A]
  466c3 ]A\A]
  46784 AUATA
  46829 []A\A]
  46844 AUATA
  468cb []A\A]
  468f4 AUATA
  4693d @t4L
  4697b []A\A]
  469e4 AUATA
  46a7f []A\A]
  46ad5 O0E1
  46b77 u'E1
  46bb4 AVAUATUSH
  46c4b []A\A]A^
  46f85 AVAUI
  47029 A9\$
  4705c []A\A]A^A_
  47084 AWAVAUATUSH
  47118 E L9
  4714d []A\A]A^A_
  471a4 AWAVAUATUSH
  47239 F L9
  4726d []A\A]A^A_
  472c4 AWAVAUATUSH
  47359 F L9
  4738d []A\A]A^A_
  473e4 AWAVAUATUSH
  47478 E L9
  474ad []A\A]A^A_
  475f9 AVAUATUH
  47611 []A\A]A^
  47661 U D)
  47669 9B(w
  476a5 ]A\A]A^
  476c4 9w0vwATUH
  47754 AWAVAUATUSH
  4782e D97s
  47842 wTA9
  47898 ([]A\A]A^A_
  478f4 AWAVAUATA
  479ca []A\A]A^A_
  47a47 } L9
  47b14 AUATI
  47bc1 ([]A\A]
  47ccb AVAUATUSH
  47d80 H9l$
  47dae ([]A\A]A^A_
  47de1 []A\A]A^A_
  47ec2 D$(1
  47f30 T$(dH+
  47f45 8[]A\A]
  47fbc H+D$
  47fd9 AVAUI
  48003 L$0H
  48008 D$8dH
  48016 D$X1
  48070 D$ L
  48075 d$HL
  4807d |$HL
  480ce L9D$
  480e3 L$PL
  480ee D$(L
  480ff D$(H
  48113 t$PH
  4813a t$HH9t$ v|
  4814e H9t$
  4816f T$XdH+
  48184 h[]A\A]A^A_
  4819f H;t$Ht
  48232 L$8L
  48237 D$0L
  48266 D$0H
  4826e D$8H
  48276 l$HH
  4827e t$PH9
  48284 v0f.
  482af H9l$Pw
  482e2 T$0H
  482e7 l$HL
  482ef T$8H
  48334 AWAVAUATA
  483a7 u7L;<$wY
  483f7 []A\A]A^A_
  48434 AVAUATI
  4845d D$(1
  484aa t$ H
  484cc +CHD
  484d4 T$(dH+
  484e9 0[]A\A]A^
  48552 { Mc
  48576 t$ H
  4860e ATUH
  4867d u1D)j
  4868f ]A\A]A^
  48728 A]A^
  48764 AVAUA
  4882a ]A\A]A^
  4884c ]A\A]A^
  48874 A]A^
  488c9 AVAUI
  488d0 ATUH
  4891b HcD$
  489eb ]A\A]A^A_
  48aa4 []A\A]A^A_
  48ad0 A]A^A_
  48b2a AVAUI
  48b31 ATUH
  48b7c []A\A]A^A_
  48bdc $HcP
  48cf6 tCr6H
  48d1f to9(u
  48e0d A91t>Hc
  49043 u3HcW
  490ff HcC ;C
  4916b []A\
  491a8 AUATUS
  491b4 []A\A]A^
  4921e []A\A]A^
  49274 AWAVAUATA
  492ec )D$ 
  4931e []A\A]A^A_
  49330 HcT$
  4933e t$(H
  49376 |$(1
  493b1 d$0M
  49406 d$0M
  4945c D$LHcT$
  495ef AVAUI
  495f6 ATUH
  4964e w0I9
  49653 w+SD
  4966b ZY[]A\A]A^
  49686 ]A\A]A^
  496c4 AVAUATUH
  49787 ]A\A]A^
  497b7 ]A\A]A^
  49a54 %UUUU)
  49a62 3333
  49a68 3333
  49e6c N H)
  49fd4 AVAUATUH
  4a004 9]0r(H
  4a017 &A\A]A^
  4a02c 9]0s
  4a034 ]A\A]A^
  4a046 9E(wmH
  4a0ab ]A\A]A^
  4a6e7 xwATI
  4a71a @u7I
  4a752 ]l[]A\
  4a810 AWAVA
  4a817 AUATUH
  4a834 g(dH
  4a841 D$(1
  4a85e D$ H
  4a863 t$ H
  4a89c D$(dH+
  4a8b5 []A\A]A^A_
  4a8e2 G ;p
  4a939 D$ A
  4a973 T$ A	
  4a995 L9d$
  4aa3f t$ D
  4aa80 L9d$
  4aaa9 T$ A	
  4ab33 t$ E
  4abd0 AWAVAUA
  4abd9 ATUH
  4ac01 D$(1
  4ac22 D$ H
  4ac27 t$ H
  4ac67 D$(dH+
  4ac80 []A\A]A^A_
  4acb2 G ;p
  4ad1d L;t$
  4adb8 L9t$
  4ae7f t$ E
  4aed0 AWAVAUATI
  4aee9 4$dH
  4af81 []A\A]A^A_
  4afb3 G ;p
  4b1d4 AWAVA
  4b1de AUATUSH
  4b234 []A\A]A^A_
  4b349 D$0I
  4b35f D$0M
  4b37c D$0A
  4b550 D$0H
  4b555 t$0M
  4b5c6 L$8L
  4b5ea D$PL
  4b601 D$pH
  4b62f l$dH
  4b634 D$@@
  4b66a t$@M
  4b69f t$(H
  4b6a4 |$8A
  4b756 T$XH
  4b75f D$`H
  4b77d D$@H
  4b791 \$H1
  4b7b4 D$@I
  4b7c4 D$@9l$`
  4b7d3 D$HM
  4b80f T$HL
  4b869 oD$pH
  4b887 )D$P
  4b892 D$@H
  4b89e |$8H
  4b8ca t$(H
  4b8db |$8A
  4b8e9 t$(L
  4b8f9 |$8A
  4b922 T$@1
  4ba50 AWAVAUATUS
  4ba67 |$pdH
  4ba75 D$(1
  4ba95 D$(dH+
  4baae []A\A]A^A_
  4bb4e D$$I
  4bb7f D$$f
  4bba3 D$$A
  4bbdd AUATA
  4bbf1 W(dH
  4bc4e []A\A]A^A_
  4bc8d ]A\A]A^A_
  4bcad AUATA
  4bcc1 W(dH
  4bd1e []A\A]A^A_
  4bd5d ]A\A]A^A_
  4bd80 AWAVAUATUH
  4bda5 D$(1
  4bdef D$ A
  4be00 L9<$t5
  4be29 D$@H
  4be53 D$ H
  4be62 D$(dH+
  4be76 []A\A]A^A_
  4be8d ,$H+l$
  4beb0 AWAVI
  4beb7 AUATE
  4beeb D$ H
  4bf43 t;H=
  4bf6f []A\A]A^A_
  4bf84 T$@L
  4bf96 D$HH;
  4bfac 9T$Pr>H
  4bfb4 D$ H
  4bfb9 T$@H
  4c00a \$8H
  4c032 T$8H
  4c040 \$ E1
  4c052 t$ j
  4c066 D$0H
  4c079 \$ H
  4c087 t$8H
  4c09c D$`D
  4c0a1 |$`H
  4c0a6 D$hH
  4c0ef H#T$8H
  4c0f9 T$8H
  4c18e \$ H
  4c1a0 \$ H
  4c1a5 D$8H
  4c1c4 AVAUATUH
  4c21f  []A\A]A^
  4c2c4 AWAVI
  4c2cb AUATA
  4c331 t$@H
  4c336 T$HH
  4c412 L$(L
  4c439 |$8L
  4c44b |$(H
  4c463 u+HcT$$A	
  4c4b1 []A\A]A^A_
  4c4d2 t$ L9
  4c552 t$`D
  4c5a8 D$@H
  4c5b0 L$0H
  4c5c2 D$0M
  4c5e5 D$(PH
  4c5ef t$(L
  4c60b t$ H
  4c687 D$,PAWSL
  4c690 D$ D
  4c695 L$8H
  4c6a7 D$(H
  4c6ed D$@H
  4c6f5 L$0L
  4c70c D$0M
  4c731 D$(PD
  4c73e t$(D)
  4c760 t$ H
  4c788 D$@H
  4c78d L$0H
  4c79f t$0I
  4c7da D$@H
  4c7e2 L$0H
  4c7f4 D$0M
  4c817 D$(PH
  4c821 t$(L
  4c82e AYAZI
  4c904 AWAVAUA
  4c910 ATUSH
  4c9e9 H9D$
  4ca2d H9D$
  4ca78 H;L$
  4caa4 9kHvgH
  4cae5 []A\A]A^A_
  4cb14 D9{0v
  4cbd8 []A\
  4cc05 AUATI
  4cc43 f9TE
  4cc57 t"Hc
  4cc74 f9|E
  4ccf4 ]A\A]A^
  4cd3a P [L
  4cd40 ]A\A]A^
  4cf49 []A\A]A^A_
  4cfe9 D$(1
  4d02b D$ A
  4d079 T$(dH+
  4d08a 8[]A\A]A^A_
  4d0e4 AWAVAUATUSH
  4d0f3 t$(dH
  4d1db t$P1
  4d201 L$PH
  4d206 l$ E
  4d20e l$HL
  4d213 d$@H
  4d21b \$8I
  4d23b t$@H
  4d26a t$HH
  4d2d8 E9w0
  4d32a T$8H
  4d338 L$ D
  4d36a T$hdH+
  4d37f x[]A\A]A^A_
  4d3d3 t$P1
  4d452 l$ M
  4d4d4 ATUH
  4d583 (]A\
  4d899 E9~(
  4d90d []A\A]A^A_
  4d929 []A\A]A^A_
  4d96f AVAUATUSH
  4d9d9 []A\A]A^A_
  4da53 AVAUA
  4da87 []D)
  4da8c A\A]A^
  4da9c ]A\A]A^
  4daba ATUD
  4dad1 T$ dH
  4db56 []A\A]A^
  4dbbd ([]A\A]
  4dc00 AVAUI
  4dc07 ATUH
  4dc23 T$ dH
  4dcb2 []A\A]A^
  4dcc0 AUATI
  4dd17 []A\A]
  4dd47 AUATA
  4dde2 k|fD
  4de02 []A\A]A^
  4e259 ([]A\A]
  4e2b4 AWAVAUI
  4e2bd ATUH
  4e2d4 L$4H
  4e2d9 T$8H
  4e318 D$8A
  4e325 HcT$4E
  4e34c T$@L
  4e41d []A\A]A^A_
  4e4e4 AUATUH
  4e505 ]A\A]
  4e555 ]A\A]
  4e569 ]A\A]
  4e584 AUATUH
  4e59f A\A]
  4e5ea ]A\A]
  4e5f9 ]A\A]
  4e611 ]A\A]
  4e76f []A\A]A^
  4e7c0 A\A]A^
  4e81e []A\A]
  4e83b K fA
  4e863 T$:H
  4e86a []A\A]
  4e8bf []A\A]A^
  4e910 A\A]A^
  4e96e []A\A]
  4e98b K fA
  4e9b3 T$8H
  4e9ba []A\A]
  4e9df W dH
  4ea16 tHfA
  4eaee W dH
  4eb23 tkfA
  4ec4c []A\A]
  4ec6d []A\A]
  4ecae []A\A]
  4ecc4 ATUH
  4ece1 []A\
  4ed24 ATUH
  4ed74 AWAVAUATUSH
  4edc2 O(D9
  4ee41 f9D$
  4ee4d A9]0
  4ee98 A9G 
  4eec2 O(D9
  4ef02 []A\A]A^A_
  4ef29 []A\A]A^A_
  4efb8 HcT$
  4f050 AWAVAUATA
  4f074 D$(1
  4f08d |$ H
  4f0c2 D$(dH+
  4f0db []A\A]A^A_
  4f0f2 D$ f
  4f141 D$ H
  4f15f D$ H
  4f2a6 AVAUI
  4f336 []A\A]A^
  4f363 []A\A]A^
  4f38c W(E1
  4f42a utAVI
  4f486 ]A\A]A^
  4f728 []A\
  4f754 AVAUATA
  4f770 D$H1
  4f7a4 L$(L
  4f7a9 D$0H
  4f7c2 Dd$8H
  4f7c8 D$HdH+
  4f7dd ]A\A]A^
  4f823 L$(H
  4f82f D$0H
  4f876 ATUH
  4f89e ]A\A]A^
  4f8d1 A\A]A^
  4f92e []A\
  4f9bd $2D1
  4f9f5 []A\
  4fa06 AWAV
  4fa15 ATD1
  4fc94 []A\A]A^A_
  4fd39 ~uS1
  4fde9 AVAUATM
  4fe0a D$HH
  4fe92 T$HdH+
  4fea7 X[]A\A]A^A_
  4fed4 l$ L
  4ff29 l$ L
  4ffb4 AWAVAUATUSH
  5000c @tYH
  50057 []A\A]A^A_
  50093 A\A]A^A_
  50130 AWAVAUI
  501d6 []A\A]A^A_
  501f4 AWAVAUATUSH
  50204 t$(dH
  50212 D$81
  502e6 D;|$
  50316 T$4B
  5036d +t$ D9
  50386 D;<$
  503ac AYAZA
  503ff T$8dH+
  50414 H[]A\A]A^A_
  50496 ;t$ 
  504bc S D;<$
  5051b D$(H
  50552 D$$E
  50571 D$(H
  50644 AWAVAUATA
  50668 D$H1
  50678 D$HdH+
  50691 []A\A]A^A_
  506d7 D$(1
  506f8 \$0H
  5076d D$(H
  50789 \$0H
  50804 AUATI
  50930 ([]A\A]
  509d4 AUATUH
  50a23 l$ D
  50a5e ]A\A]
  50b07 D$$L
  50b2b HcT$
  50cc0 AVAUATUSH
  50d17 []A\A]A^
  50e44 (A9l$
  50e55 []A\
  50e60 ATUS
  50e66 ~XHc
  50eb3 []A\
  50ed0 AWAVI
  50ed7 AUE1
  50f3f D9#~
  50f4b []A\A]A^A_
  50f93 u.HcC
  50ff0 AWAVAUATUSH
  5105b []A\A]A^A_
  51284 ATUHc
  51322 L;|$
  513b3 H+D$
  513f9 ([]A\A]A^A_
  51426 []A\A]A^A_
  51460 AWAVAUATUSH
  51473 t$(dH
  5150f ;T$$
  51585 L$8L
  5159d D$8A9G
  515c7 D$$9D$P
  51613 IcD$
  51618 A;D$
  51731 L$81
  51793 []A\A]A^A_
  517b0 IcD$
  518e3 |$81
  518ef |$8H
  51980 AWAVI
  51990 ATUH
  519e9 []A\A]A^A_
  51a1f T$*H
  51b50 ]A\A]A^
  51b8b ]A\A]A^
  51bec ]A\A]
  51c27 ]A\A]
  51c30 AWAVA
  51c3f ATUH
  51c8a H;D$
  51d41 ]A\A]A^A_
  51ebb []A\A]A^A_
  51f24 AWAVA
  51f2b AUATI
  51fd1 []A\A]A^A_
  520a7 D$ I9
  52148 ]A\A]
  521c5 t#E1
  52220 AWAVI
  52227 AUATI
  5224f D$81
  52283 t$(E1
  522c5 D$8dH+
  522de []A\A]A^A_
  522fa |$(H
  52344 D$(E
  523a6 |$0H
  523ca L$$H
  523da |$$H
  5240f T$0H)
  52430 AWAVI
  52457 T$,dH
  52465 D$81
  5246c t$0H
  52483 |$0L
  525bd D$,H
  525fe LcL$
  52624 uILcK
  52671 T$8dH+
  52686 H[]A\A]A^A_
  5271e b Ic
  52743 |.(L
  527b9 z Hc
  527eb HcC H
  52885 t,(D
  528c8 LcL$
  52914 AWAVAUA
  52920 ATUSH
  5293a D$(1
  52969 D$(dH+
  52982 []A\A]A^A_
  52a05 uIfA
  52a33 |$ L
  52a60 HcC 
  52a73 L$(A
  52aaa D$ H
  52af3 T$ L
  52b78 T$ H
  52c74 AWAVAUATA
  52dd4 ]A\A]A^A_
  52ef1 AWAVI
  52ef8 AUATUSH
  52f6e []A\A]A^A_
  52f97 []A\A]A^A_
  52fb4 AWAVAUATUSH
  53073 []A\A]A^A_
  530ca ]A\A]A^A_
  53119 AUATUH
  5321b []A\A]A^
  53299 AVAUI
  532a0 ATUH
  532bf D$81
  532fa D$8dH+
  53313 []A\A]A^A_
  53327 D$0H
  53378 T$0H
  533e7 W H;T$
  533f7 H+L$
  53406 Hc<$H
  5340c t$(I
  53428 T$(D
  534b1 HcE 
  5350d D$ L
  53563 |$0H
  53596 9] ~
  535a3 D$ H
  535a8 L$(H
  535f6 D$ H
  53635 D$ H
  53661 AVAUI
  53668 ATUSHcG
  536fc IcU H
  53723 []A\A]A^
  53743 ]A\A]A^
  53764 AVAUA
  5376b ATUH
  5377b W dH
  537da []A\A]A^
  53890 u	HcG
  53940 ATUSHc
  5395d []A\
  5399a []A\
  53a09 w*Hc
  53ad4 AVAUATA
  53c83 []A\A]A^
  53c9c G 90r
  53d7b AVAUATI
  53f25 kXD9
  54080 k(D9
  54291 ([]A\A]A^A_
  54489 []A\A]A^A_
  544a9 []A\A]A^A_
  54584 AUATI
  545ce |PA+
  54637 ([]A\A]
  5465d H9l$
  54743 t[Hc
  547f4 ATUSH
  54807 D$(1
  54907 T$(dH+
  5491c 0[]A\
  54931 D$(dH+
  54946 []A\
  549dd F Hc
  54a74 AWAVAUATUSH
  54aee t0Hc
  54af5 T$XdH+
  54b0a h[]A\A]A^A_
  54b22 t$ H
  54b42 t$0D
  54b6e tZHc
  54c18 AVAUATUSH
  54c99 t$pL
  54cb7 +D$t
  54cc1 D$XI
  54ccd D$ Ic
  54d3a t$HL
  54d3f L$8E1
  54d47 D$0f
  54d4c D$(A
  54d7d D$0L
  54d82 L$8	
  54de2 D$0L
  54e0f L$(L
  54e33 L$@L
  54e70 D$(I
  54ee8 t$@L
  54f11 D$(L
  54f6e D$@L
  54f7b \$XH
  54f80 D$PI
  54f8c @ +D$
  55023 []A\A]A^A_
  5514d D$`H
  55152 l$X1
  5517a D$@L
  5518a \$XH
  551bb |$HL
  551d0 D$HL
  55254 AVAUATA
  55377 ]A\A]A^
  553bc AVAUATUSH
  5545c t$@1
  554a1 []A\A]A^A_
  554fe )D$@H
  55535 D$HH
  5558b D$(H
  55590 D$`H
  5563b T$(L
  5565d T$@L)
  556a5 D$hH
  55799 D$tD
  557eb D$hH
  55891 D$@H9
  558c4 L$PL
  55973 D$@H
  559b0 L$PH
  559bf D$Pf
  559c4 oL$@E)
  55a4c D$@H
  55ab4 D$`H
  55ac5 <$9|$8
  55ae3 9D$p
  55b3e D$@H
  55ba2 D$`H
  55bb3 <$9|$8
  55bd1 9D$p
  55c54 <$9|$<
  55d54 AVAUATUH
  55d71 D$81
  55da1 t5H={
  55db4 T$8dH+
  55dc9 H]A\A]A^
  55ee4 AVAUE1
  55eeb ATUSH
  55f01 D$(1
  55f2c D$(dH+
  55f44 []A\A]A^
  55fb5 D$ I
  55fee 2H91t
  56030 AWAVI
  56040 ATUH
  560af []A\A]A^A_
  56100 AUATE1
  56123  t*H
  56141 []A\A]
  5620e AUATU
  56277 []A\A]A^A_
  56434 ATUSH
  56488  []A\
  564af E(E1
  564d9 AXAYH
  56630 AVAUATUSH
  56667 u'E1
  56687 []A\A]A^
  567e4 AWAVAUATUSH
  56867 []A\A]A^A_
  56968 ([]A\A]A^A_
  56af1 AWAVAUI
  56afa ATUSH
  56b9c []A\A]A^A_
  56bf1 A\A]A^A_
  56c16 AVAUI
  56c1d ATUH
  56c6b H;|$
  56cd3 []A\A]A^A_
  56d84 AWAVA
  56d8e AUATUSH
  56e1f D$4H
  56e40 t$(L
  56e4e D$DH
  56e53 T$ A
  56ead \$0A)
  56f5e D$ L
  56f83 t$(L
  57012 D$8H
  57027 []A\A]A^A_
  5708e D$4H
  570ca L$8H
  5714c []A\
  571a5 []Hc
  5724e t	H9
  57486 G Hc
  574c9 AVAUATI
  574ee l$ D
  574fb t$pH
  5750e D$(1
  57526 t$ D
  5759e D$ H
  575af t$ D
  575e6 D$ L
  57609 D$ H
  57616 D$(dH+
  5762b []A\A]A^A_
  5767f D$ H
  57b47 H97u
  57b80 AVAUATUSH
  57b8b H99ueA
  57bcc tj+C
  57bf5 []A\A]A^
  57c50 AVAUATUSH
  57c6a twH99urH
  57ce3 []A\A]A^
  57d04 ATUH
  57d4c []A\
  57d6a tLH97uG
  57dcf H97u<
  57e6d []A\
  57fe4 AUATUH
  58036 []A\A]
  58058 []A\A]
  58069 []A\A]
  58074 AUATUH
  580c6 []A\A]
  580e8 []A\A]
  580f9 []A\A]
  5810b uC9w
  5816b uC9w
  581c4 AUATA
  5821f []A\A]
  58240 []A\A]
  58254 AUATA
  582af []A\A]
  582d0 []A\A]
  583c4 AWAVAUATUH
  58406 D$81
  58435 D$8dH+
  5844e []A\A]A^A_
  58483 D$01
  5849c t$0H
  58526 D$0L
  58537 t$0L
  58553 D$0H
  58582 t$,L
  585ac (;D$,H
  5861e D$0H
  58754 AWAVAUATUH
  5878e vXH-m
  587d7 ]A\A]A^A_
  587ff  ]A\A]A^A_
  588a2 copy of H
  589ed H9W0r
  58ba2 H9w w H9w(r
  58c4a H9w w H9w(r
  58cfa H9w w H9w(r
  58e6d AVAUI
  58e74 ATUSH
  58e89 >H;:
  58eb8 F H;B uPH
  58ec2 ^(H;Z(uFH
  58ee4 I9\$(reH
  58f13 []A\A]A^
  58f26 ]A\A]A^
  58f3a ]A\A]A^
  59027 H9w w;L
  5902f G(I9
  59147 H9_ wCH
  5914f G(H9
  59237 H9_ wCH
  5923f G(H9
  592f4 AWAVAUATE1
  59325 D$81
  5933a T$(H
  5935e |$(H
  59381 G(H9
  59392 l$0H
  59397 |$(L
  593f2 D$8dH+
  59407 []A\A]A^A_
  59424 AUATUSH
  594aa []A\A]
  594d6 H9w wdL9o(r^I9
  59572 4$L9
  5958a 4$L9
  595c4 AUATUSH
  5964a []A\A]
  59676 H9w wdL9o(r^I9
  59712 4$L9
  5972a 4$L9
  59764 AWAVAUI
  59823 []A\A]A^A_
  59866 AVAUATUH
  5989e 9]0v$
  598c2 9]0w
  598dd []A\A]A^A_
  59922 $t;[]A\
  599b0 AWAVAUA
  599b9 ATUL
  599cf D$h1
  59a03 L$ L
  59a58 d$0L
  59a6a t$$A
  59aa4 d$(L
  59b23 t$(H
  59b6b D$hdH+
  59b84 []A\A]A^A_
  59d04 AWAVAUATA
  59d48 []A\A]A^A_
  59e14 AWAVAUATI
  59e21 USHc
  59e89 t$ 1
  59eeb []A\A]A^A_
  59f9c trE1
  59fe4 L9t$
  5a011 D$X%
  5a026 D$pH
  5a157 []A\
  5a1cc B(E1
  5a1e0 ]A\A]A^
  5a1f2 C [D
  5a1f8 ]A\A]A^
  5a24a I9\$
  5a26c []A\
  5a2b4 AUATI
  5a2c5 tJE1
  5a318 []A\A]
  5a394 VtE1
  5a4cc t"fA
  5a585 T$%R
  5a58b T$,R
  5a591 T$3R
  5a597 T$:R
  5a5b0 D$NPD
  5a5b7 L$T1
  5a5f0 AUATA
  5a6ae []A\A]
  5a6ba C(Hc
  5a6e6 []A\A]
  5a71a A90taE1
  5a744 A90t7w
  5a756 uPE1
  5aa00 AVAUA
  5aa07 ATUH
  5aa5c []A\A]A^
  5ab64 AWAVAUI
  5ab6d ATUH
  5ab88 D$H1
  5aba1 D$HdH+
  5abba []A\A]A^A_
  5abf8 L$ L
  5ace9 AVAUM
  5acf0 ATUH
  5ad6a []A\A]A^A_
  5ae77 AVAUATI
  5aefb ]A\A]A^
  5af72 9w r*H
  5b024 ATSH
  5b053 9w rTH
  5b0c3 ([A\
  5b1d4 AVAUATU
  5b1f9 9o rjH
  5b25c []A\A]A^
  5b374 AUATU
  5b383 9w rhH
  5b3e9 ]A\A]
  5b3f6 ]A\L
  5b41d ]A\L
  5b434 A\A]
  5b4ae  t'L9
  5b5b1 v=+{
  5b5cf A+D$8
  5b5e9 []A\A]
  5b6a4 AWAVAUATUSH
  5b6bd D$(1
  5b70d D$(dH+
  5b726 []A\A]A^A_
  5ba27 FXf=
  5bcb1 D$ =
  5bd7b |$XD
  5bde8 D$(D
  5bdfa |$\E
  5be43 L$ I
  5be90 |$\E
  5bed8 O H)
  5c105 L$ fA
  5c12c tZA;
  5c1b0 D$ f
  5c1cb |$ H
  5c1de t$ H
  5c1f8 D$ f
  5c213 |$ H
  5c226 t$ H
  5c501 AUE1
  5c506 ATE1
  5c540 9o tC
  5c57b ~ E1
  5c583 9o u
  5c651 D9h(t8
  5c689 D9h(u
  5c707 []A\A]A^A_
  5ccde ATUSH
  5cd1c ]A\A]A^
  5cd45 ]A\A]A^
  5cf90 ATUSH
  5cfdb []A\
  5d020 ATUSH
  5d07b []A\
  5d10e AUATI
  5d190 []A\A]A^A_
  5d235 AVAUATI
  5d251 zddH
  5d25e D$(1
  5d289 z`E1
  5d2d8 D$(fD
  5d2e7 D$$H
  5d330 |$$E
  5d35d t$$Ic
  5d383 T$(dH+
  5d394 8[]A\A]A^A_
  5d3a2 t$(L
  5d3c9 T$(L
  5d3f0 AWAVI
  5d3fc ATUH
  5d414 |$ L
  5d425 D$(1
  5d439 D$(dH+
  5d452 []A\A]A^A_
  5d462 T$ A
  5d4aa T$ H
  5d593 D$(1
  5d59e D$'H
  5d5c2 T$(dH+
  5d66b []A\
  5d684 AWAVI
  5d68b AUATE1
  5d6c1 l$@L
  5d6e3 D$@f%
  5d6ed @tXI
  5d726 []A\A]A^A_
  5d872 D$lM
  5d8ad l$ H
  5d8b2 l$ L
  5d8cc D$0H
  5d8d6 T$8A
  5d994 ATUH
  5da24 AWAVAUATA
  5da81 []A\A]A^A_
  5da92 l$0H
  5dad6 D$ L
  5db1f oL$X
  5db28 oT$h
  5db32 o\$x
  5db52 T$ H
  5dbd5 D$0H
  5dc07 t$(H
  5dca8 []A\A]A^A_
  5dcba oC(A
  5dcc3 oK8A
  5dccd oSHA
  5dd12 \$ H
  5ddad <wXI
  5ddb2 |$(L
  5ddfb ]A\A]A^A_
  5de67 t$ A
  5de85 \$HI
  5de8e T$XA
  5de97 |$(A
  5deaa d$0L
  5def8 tIHcBpD
  5df18 JpA9
  5df78 RpE9
  5df90 AVE1
  5df99 n ATUSA
  5dfc7 @uaf
  5dfcf toE1
  5dffd ~ ;o
  5e02f ]A\A]A^
  5e091 Gt u
  5e0a0 AWAVI
  5e0a9 AUATUH
  5e0ba Hc_@
  5e169 D9|$
  5e197 HcE@A
  5e1b5 H+E8H
  5e1e0 D9|$
  5e218 U@A)
  5e22b ([]A\A]A^A_
  5e27a W0dH
  5e28d G(H9
  5e2fe H()k(1
  5e5a4 ATE1
  5e5b8 []A\
  5e6b8 []A\
  5e6d4 AVAUATA
  5e757 []A\A]A^
  5e8a8 P0Hcx@1
  5eabc AVAUATUSH
  5ead3 D$(1
  5eae1 T$ uzH
  5eb14 C$Lcs@H
  5eb62 D$(dH+
  5eb7b []A\A]A^A_
  5eba7 KPD;K@
  5ec75 |$ L
  5ec88 HcS@H
  5ec8e SH)SP
  5ed39 S@Ic
  5ed6a )CPHc
  5ed95 |$ L
  5ee36 sHIc
  5ee55 t$ D
  5eefc AVAUATU
  5ef88 C 9(
  5eff6 H[]A\A]A^A_
  5f03f []A\A]A^A_
  5f0a6 D$ A
  5f0cd T$<H
  5f0d9 D$0H
  5f0e7 D$(E
  5f0f4 l$8L
  5f13e K(Ic
  5f1d5 t$ H
  5f1e7 H9D$
  5f1f7 t$ A
  5f213 D$ D
  5f26f l$8L
  5f2c0 \$<L
  5f2f2 t$(H
  5f32b l$8L
  5f386 ATLc
  5f3a4 D$(H
  5f3ff C D90
  5f40f t$ H
  5f479 D90u
  5f48f |$ L
  5f510 H9D$
  5f527 D$ L
  5f567 D+l$
  5f5d1 Lc|$
  5f632 D$(dH+
  5f64b []A\A]A^A_
  5f672 T$ D
  5f6c2 T$ D
  5f7fa oT$ 
  5f801 o\$0f
  5f80f od$@
  5f816 ol$P
  5f821 ot$`
  5f828 o|$p
  5f875 []A\A]A^A_
  5f8b3 ]A\A]A^A_
  5f8d4 ATUSH
  5f910 92r>H
  5f937 L$(H
  5f96c []A\
  5f984 ATUH
  5f9bc 92r@H
  5fa46 AUATI
  5fb10 []A\A]
  5fb31 []A\A]
  5fb46 []A\A]
  5fcc9 u%Hc
  5fcd8 ~*H9
  5fd60 AVAUE1
  5fda4 El$(H
  5fe88 []A\A]A^
  5fec5 L9l$(
  5feea ATUH
  5ff40 []A\A]
  5ff8a L9l$
  5ffb0 AWAVAUATI
  60001 l$0H
  60036 D$XH
  6009a H9D$0u
  600cc HcT$
  60160 []A\A]A^A_
  60197 t$XH
  6019d t	H9
  601aa L$(H
  601af T$ I
  60202 D$ H
  6020e H9D$0
  6021b D$(H9D$8
  6025b H9D$0
  60281 HcT$
  602cb D$0H
  602d0 D$ H
  602d5 D$8H
  60338 []A\A]
  60358 ]A\A]
  60374 AVAUI
  603f8 []A\A]A^
  6062b APE1
  60675 []A\A]
  60690 AWAVM
  606c4 D$h1
  606e0 T$hdH+
  606f5 x[]A\A]A^A_
  6071d D$0H
  60738 D$ H
  6073d l$0L
  60753 D$@L
  60783 D$HH
  6079d D$(H
  607ab D$XH
  607d0 AWHc
  607e6 ATUSH
  6084e []A\A]A^A_
  608b6 AVAUA
  608d6 r dH
  608e3 D$(1
  608f4 T$(dH+
  60909 8[]A\A]A^A_
  6099a t$$D
  60ad0 AWAVAUATI
  60b38 L9t$
  60b42 Ic6H
  60b84 ([]A\A]A^A_
  60bbe T$(L
  60bda ([]A\A]A^A_
  60bf0 AWAVAUATM
  60c0a t$,H
  60c14 L$0dH
  60c22 D$X1
  60c29 D$HH
  60c43 D$XdH+
  60c5c []A\A]A^A_
  60c84 T$8H
  60cb7 \$(L
  60cbc l$@1
  60cc3 D$ D
  60d04 D$@E
  60d13 HcT$
  60d21 T$PL
  60d52 t$ L
  60d90 Hc\$
  60e1d D$HL
  60e3c |$,H
  60e41 T$H1
  60e67 D$HH
  60e6c t$PL
  60e87 T$HH
  60e8c t$0E
  60ea6 T$PH
  60f3c |$P1
  60f8f ATUH
  60fc0 D$81
  60fcf D$(A
  60fd6 xxIc
  61004 0f9p
  61029 T$8dH+
  6103e H[]A\A]A^A_
  61097 AYAZH
  610b9 D$0E1
  610d5 _AXH
  61137 |$(Mc
  61177 L$ A
  61182 D$,A
  61194 \$(D
  611b5 L$ D
  611ba D$,L
  6122b t$0E
  61245 t$0L
  61254 L$(L
  612c5 AVAUATI
  612e5 t$ D
  6131b |$0E1
  6132c D$8H
  61331 D$(H
  61341 D$DM
  61383  D9t$DvUH=&
  61395 L$(L
  6139a D$ L
  6141f []A\A]A^A_
  61434 AWAVAUATUSH
  61444 \$pL
  6145b D$(1
  61570 D$(dH+
  61589 []A\A]A^A_
  615db L$$L
  61664 AWAVAUATUSH
  616ac |$@I
  61728 D$ H
  61740 D$(H
  6177a []A\A]A^A_
  617c4 ATE1
  61804 []A\
  61836 T$(dH+
  618cd ATUSH
  61965 A\A]A^
  6198d E0E!
  619be E0A9
  61a44 AWAVAUATUSH
  61afe []A\A]A^A_
  61bc6 []A\A]A^A_
  61cb4 ATUH
  61d05 []A\
  61d41 []A\
  61d92 []A\
  61dc4 AVAUATA
  61e28 []A\A]A^
  61f60 AWAVAUI
  61f69 ATUH
  61fc2 []A\A]A^A_
  6201d Lc L
  620a5 AVAUI
  62107 []A\A]A^A_
  62154 L$<A
  621c3 D$,f
  621c8 |$:A
  621d5 D$0fD
  62298 oD$HL
  622a1 oL$X
  622a7 oT$h
  622c9 T$xH
  62344 AWAVAUATUH
  62385 D$8A
  623bb []A\A]A^A_
  62498 D9l$
  624b9 D9l$
  624ea T$Hf
  625b4 AWAVI
  625c0 ATUH
  62667 []A\A]A^A_
  627e5 Lc D
  62894 AUATUSH
  62930 S(H9
  629a1 []A\A]
  62a74 AUATI
  62b25 []A\A]
  62c98 =OMM
  62cef _ dH
  62db4 AVAUATUH
  62e78 ]A\A]A^
  62f33 ]A\A]A^
  62f8b A\A]A^
  62fb4 AUATE1
  62ff8 [A\A]
  63084 ATUH
  630d3  []A\
  631cc AVAUATUSH
  631e3 D$(1
  631f3 D$(dH+
  6320c []A\A]A^A_
  63245 |$ A
  63259 |$ 1
  63306 \$ )
  6335c D$ H
  63376 T$ L
  6370e ATUSH
  6378c  []A\A]A^
  637c0 ATUH
  63936 []A\
  63952 S(A)
  63b27 D$H1
  63b97 T$HdH+
  63ba8 X[]A\A]
  63c0c l$@L
  63c6f []A\
  63da4 AWAVA
  63dab AUATI
  63e68 []A\A]A^A_
  63e87 []A\A]A^A_
  63f04 AWAVAUATUSH
  63f30 D$81
  63f40 D$8dH+
  63f59 []A\A]A^A_
  63f77 t$0A
  63fcc D$0H
  63fff t$0H
  64036 D$0L
  6407b T$0L
  640ce T$0I
  640e4 T$0I
  64118 L$0I
  64169 L$0I
  641ab L$0I
  641fb L$0A
  6423f L$0L
  64320 v	D9
  643c9 L$0I
  64416 L$0Ic
  6441e D$ H
  644b4 B$D)
  64501 L$0I
  64536 L$0M
  645df L$0A
  6461c D$0L
  64621 D$(H
  64676 D$(u
  6467d T$(H
  64693 |$`A
  6470f T$0H
  64723 D$ H
  64769 D$ I
  64796 T$0A
  647ab t$ L
  647cc D$0H
  647da T$0L
  647e2 M9b8w
  647ec L$0I
  6480f t$ L
  6482f D$0H
  64847 T$0I
  64855 M9j8w
  648d2 T$0L
  648da A9Z0w
  648f6 T$0L
  64960 T$0L
  6497d L$0I
  649df L$0I
  649fe T$0L
  64ab1  tkH
  64b22 []A\
  64b32 ~$Hc
  64b9e D$(1
  64c49 T$(dH+
  64c5e 8[]A\A]A^A_
  64c7b D$ L
  64d55 AVAUI
  64d5c ATUH
  64d78 t$8dH
  64dcd []A\A]A^A_
  64de2 |$HH
  64df9 |$H1
  64e25 D$DL
  64e32 D$ H
  64e37 D$pH
  64e3c D$0D
  64e63 l$P1
  64e84 L$`H
  64e89 |$HH
  64e8e T$XH
  64ed8 t$(H
  64ee1 t$HH
  64efb |$HL
  64f27 D$`L
  64f2c d$XH
  64f36 L;d$
  64f47 |$HL9
  64f68 l$PD)
  64f75 L$`H
  64f8a |$01
  64fa2 D$xH
  64fa7 |$HL
  64fbe D$(H=|
  64fd4 |$xH
  64fd9 |$HL
  64feb |$H1
  65013 |$HL
  65035 |$HL
  6505e \$<D)
  65070 T$0L)
  6507d D$pI
  650c4 t$XH
  650db L$`H
  6511a HcT$DL
  6514a AUATA
  6515f W Hc
  65173 D$0L
  651b4 d$,I
  651be t$(H
  651d1 L$,L)d$
  651dc )L$(H;l$
  651fc H9D$
  6522c U(E1
  65231 H;l$
  6523b BL$(L
  65254 D$@H
  65259 t$HD
  652b2 H;\$ 
  652bd HcD$4M
  652d1 t$8H
  652db []A\A]A^A_
  652f3 H[]A\A]A^A_
  65310 AWE1
  65315 AVAUATUSH
  6532c D$81
  65378 O(E1
  653cf T$,L
  653e0 \$0H
  653e5 T$(H
  653ea t$ H
  65404 \$ H
  6541b T$,v0D
  6545d |$0L
  65471 D$8dH+
  65486 []A\A]A^A_
  654ae V(A)
  654be T$0D
  654d8 T$0E
  6557c AUATUH
  65600 ]A\A]A^
  65667 xOATUSH
  65676 &D;g
  65809 AVAUM
  65810 ATUH
  65882 t$ H
  6591a []A\A]A^A_
  65ac4 AWAVAUATA
  65b18 []A\A]A^A_
  65b41 D$(L
  65bcf T$hL
  65c1a \$DL
  65c23 \$$1
  65c32 t$0H
  65c81 t$dL
  65c86 l$`L
  65cac A9G0
  65d0a L$XL
  65d81 D$DL
  65d93 t$XL
  65e12 D$hH
  65e17 \$8L
  65e8d |$h1
  65e99 |$0A
  65ed5 D$|A
  65f2e t$XL
  66030 AWAVAUATA
  6613b []A\A]A^A_
  66200 ATUS
  66241 9]0vy
  662ba 9]0w
  662fa []A\
  66388 AVAUATUSH
  663a7 D$H1
  66489 L$@D
  664e8 A9]0
  66520 L$8L
  665ba |$@L
  665d6 |$8L
  665f2 D$HdH+
  6660b []A\A]A^A_
  6669d l$(L
  66706 |$8A
  6673a T$@1
  6679e |$@L
  66865 AVAUA
  6688e L$8D
  66893 r(dH
  668a0 D$X1
  668f8 L$4A
  66906 D$0H
  6693e \$(H
  6695c t	L9
  66969 T$ H
  6696e |$H1
  66985 T$0L
  669f2 t	L9
  669fd HcT$
  66a04 |$P1
  66acf L$PE
  66afc L$PD
  66b1d L$PE
  66b7e D$XdH+
  66b97 []A\A]A^A_
  66c7c T$HH
  66c9e D$4D
  66cae D$(H
  66cb3 T$P1
  66ce5 \$(H
  66d31 L$4H
  66da4 L$HD
  66dc9 L$HM
  66eb7  ]A\A]
  66f30 AVAUATUSH
  66f53 )D$@H
  66f61 )D$P
  66fc5 U0A9
  67017 D$pH
  67063 D$8H
  67088 D$@H
  6708d L$8L
  67098 D$(A
  670a4 d$ I
  670ac t$0E
  670c9 D9l$4
  6710e D9l$0
  6711a D$ I
  67131 D$(I
  67136 D$ E
  67187 []A\A]A^A_
  67255 D$8D
  6725a d$ 1
  67261 t$0H
  67266 l$ L
  6740b GXt!H
  67458 AVAUATUSH
  67469 |$0H
  6746e \$@H
  6757b BxH9
  6758b |$PH
  67590 D$@H
  6759f L$HL
  675a4 \$xL
  675a9 |$(I
  675b8 |$ H
  675d9 T$`H
  675e1 D$pH
  675e9 t$hI
  675fb L$XH
  67608 D7qL
  67679 |$ H
  679b8 L$ L!
  679e8 L9T$(
  679f5 t$hH
  679fa L$0H
  67a02 T$`H
  67a11 \$xL
  67a16 L$XL
  67a1b D$pL
  67a20 t$PL
  67a5c []A\A]A^A_
  67af4 oPATUH
  67b22 pv<H
  67c18 []A\A]
  67c29 AWAVI
  67c55 |$PL
  67c78 D$HH
  67c80 D$HH=
  67c92 |$HH
  67cc4 []A\A]A^A_
  67d94 AWAVAUATA
  67e22 []A\A]A^A_
  67e32 t$8D
  67e66 |$81
  67e77 |$8A
  67ef1 t$ZL
  67f36 D$0A
  67f52 _AXH
  68033 L$0L
  68220 ATSH
  68404 AUATI
  6846b []A\A]
  686aa []A\
  68748 D$(1
  68771 t9E1
  687b1 D$(dH+
  687c6 []A\
  68866 []A\
  68910 AWAVA
  68920 ATUH
  68930 t.D9w(
  68955 []A\A]A^A_
  689e8 []A\A]A^A_
  689fe []A\A]A^A_
  68a5f E0HcM,
  68a91 []A\A]A^A_
  68b4e e(E1
  68b56 []A\
  68b60 D9g(t
  68b84 []A\
  68bd5 ui9G(ud
  68bed G`E1
  68c8c ATUH
  68ca5 ]A\A]A^
  68ce4 ]A\A]A^
  68cf0 ATUH
  68d25 []A\
  68d52 HcO,
  68da5 []A\
  68dec P(HcM,A
  68e43 []A\
  68f89 []A\A]A^A_
  68fbb []A\A]A^A_
  690ba AUATU
  690ff ]A\A]A^
  6918a D$PtQD
  691cb []A\A]A^A_
  69224 []A\A]A^A_
  69240 AWAVI
  6931d []A\A]A^A_
  6933e AUE1
  6938f []A\A]A^A_
  69435 AVAUI
  6943c ATUH
  694b8 ([]A\A]A^A_
  6951b ATUS
  69581 v@E9
  695af []A\A]A^A_
  695e7 @(D9
  695ec r	D9
  698b4 AWAVAUATUSH
  698d6 D$81
  698fc |$ L
  69946 D$8dH+
  6995f []A\A]A^A_
  699e5 ATUH
  69a32 []A\A]
  69aa9 u5SH
  69af8 ufUSH
  69bfc D$(1
  69c1d D$$D
  69c34 D$(P
  69c39 D$,P
  69c3e D$0PD
  69c44 L$41
  69c54 D$4H
  69c92 T$(dH+
  69ca3 0]A\A]
  69d24 AUE1
  69d29 ATUSH
  69d73 D$0D
  69d8d D$0H
  69db8 []A\A]
  69e24 AWAVAUATUSH
  69ea8 []A\A]A^A_
  69f14 AWAVI
  69f72 []A\A]A^A_
  6a02f ATMc
  6a0be oe L
  6a0cb ou@I
  6a0d7 o}PA
  6a0e1 oU`A
  6a0eb o]pA
  6a172 ]A\A]A^
  6a1a6 oX0E
  6a1b4 ohPI
  6a1c2 oxpA
  6a23b ]A\A]A^
  6a274 AVAUI
  6a27b ATUSH
  6a2ce BBBBBBBBL
  6a368 []A\A]A^
  6a3e0 ATUH
  6a40e 8#uf1
  6a436 t@E1
  6a46f  []A\
  6a51b ]A\A]
  6a6e2 []A\A]A^
  6a710 AWAVAUI
  6a73b D$(1
  6a826 D$(dH+
  6a83f ]A\A]A^A_
  6a87e |$$f
  6a8da =BBBB
  6a915 |$$f
  6aa80 AWAVI
  6aa87 AUATUH
  6aab3 D$8H
  6ab31 L$$9
  6abf6 D$8dH+
  6ac0f []A\A]A^A_
  6acf0 AWAVI
  6acf7 AUATUSH
  6ad07 L$ H
  6ad1f D$8H
  6ada2 D$(L
  6ade4 T$(M
  6ae0f l$(A
  6ae42 D$(D
  6aeb3 D$$A
  6af0c D$8dH+
  6af25 []A\A]A^A_
  6b030 AUATUSH
  6b045 D$(1
  6b0e1 T$(dH+
  6b0f6 8[]A\A]
  6b142 D$(dH+
  6b15d []A\A]
  6b190 AUATI
  6b1db D$`9
  6b2a5 A;D$`
  6b30e []A\A]
  6b36a []A\A]
  6b3b0 AWAVAUI
  6b3b9 ATE1
  6b3da D$8H
  6b3e9 D$ H
  6b404 T$,H
  6b428 t$(D
  6b42d D$,H
  6b4ab D$8dH+
  6b4c4 []A\A]A^A_
  6b594 D$(1
  6b63a D$(dH+
  6b64f []A\A]
  6b745 ([]A\A]
  6b767 ATUH
  6b85b []A\A]
  6b91f AUATE1
  6b942 D$(1
  6b962 D$$H
  6b9b5 T$$9
  6b9bf t	D9
  6ba0e D$(dH+
  6ba27 []A\A]A^A_
  6bdf4 ATSH
  6bf11 C`E1
  6c134 ATUSH
  6c290 []A\
  6c2ed `$E1
  6c32e AVAUATUSH
  6c345 D$81
  6c379 T$ L
  6c3d2 L$,E1
  6c3f7 D$,L
  6c440 D$,M
  6c475 D$8dH+
  6c48e []A\A]A^A_
  6c6a4 AUATI
  6c88d []A\A]
  6c8e6 h$E1
  6cb15 ]A\A]
  6cbb7 ]A\A]
  6cbe4 ATUSH
  6cc33  []A\
  6ccd4 AUATUH
  6ccfa 4$dH
  6cd07 D$(1
  6cd52 L$(dH+
  6cd67 8[]A\A]
  6cd71 D$ 1
  6d010 AUATUH
  6d028 D$(1
  6d03b D$(dH+
  6d054 []A\A]A^
  6d2a0 AWAVI
  6d398 ]A\A]A^A_
  6d424 ATUH
  6d446 D$(1
  6d453 4$E1
  6d480 L$(dH+
  6d491 0[]A\
  6d50c D$(1
  6d519 4$E1
  6d542 D$(dH+
  6d557 []A\
  6d572 D$,H
  6d634 AWAVAUATUH
  6d659 D$(1
  6d801 D$(dH+
  6d81a []A\A]A^A_
  6da0c D$(1
  6da1d T$(dH+
  6da44 AWAVAUM
  6da4d ATUH
  6db2a []A\A]A^A_
  6dc64 AWAVM
  6dc6b AUATA
  6de1d t-E1
  6df1e []A\A]A^A_
  6e125 D$@L
  6e15a t.E1
  6e202 E\=m
  6e394 ATUH
  6e411 t!H9
  6e4c6 ATUH
  6e4df D$(1
  6e5b8 D$(dH+
  6e5cd []A\A]
  6e634 ATE1
  6e720 H9D$
  6e731 $uTH
  6e970 u^AT
  6e9a6 |$H1
  6e9ca []A\
  6eb20 AWAVAUATU
  6ebb9 []A\A]A^A_
  6ebe7 E2UNDO02
  6ec09 T$8H
  6ed0c H9C@
  6ed50 ATE1
  6edc2 ChPH
  6eddf []A\
  6ee86 []A\
  6eeb0 AWAVAUATUSH
  6eed0 D$(1
  6ef49 D$ H
  6ef75 \$ M
  6f06b H;,$
  6f0d9 |$ 1
  6f0e5 KPIcw
  6f12a \$ M
  6f142 H;,$
  6f152 D$(dH+
  6f16b []A\A]A^A_
  6f22b u[ATUSH
  6f27d []A\
  6f2ab ukAU
  6f2b4 ATUSH
  6f2cf []A\A]
  6f309 []A\A]
  6f39b u[ATUSH
  6f3ed []A\
  6f414 ATUSH
  6f4d8 []A\
  6f588 ATUSH
  6f5a3 []A\A]
  6f609 []A\A]
  6f656 O0E1
  6f66c []A\
  6f7a5 AVAUI
  6f822 []A\A]A^A_
  6f896 A9E(
  6f8c5 AVAUATUSH
  6f8f7 d$pM
  6f920 []A\A]A^A_
  6f9b0 L$4=
  6fa56 D$(H
  6facb D$(I
  6fad6 H+l$ I
  6fadd N0H9
  6faf8 D$4E1
  6fb58 m@H;l$
  6fb69 L$(H
  6fb6e L$ H
  6fb73 D$ H9D$8
  6fc14 AWAVAUATUSH
  6fd10 []A\A]A^A_
  70118 []A\
  701c7 u'E1
  70231 ]A\A]A^
  7026b ]A\A]A^
  70284 AUATUSH
  702e7 []A\A]
  70328 uRHcC
  70342 H9t$0s
  70436 uHHcG
  7054a AUATUSH
  70580 HcD$$H
  705b1 l$(HcC
  705d4 D$ u_
  7061a HcL$
  70680 HcD$
  706ea H;l$
  70722 D$ 9D$
  70762 d$ Mc
  70772 d$ L
  707e2 T$4H
  707f8 []A\A]A^A_
  7082b D$ H
  70891 x}Hc
  709a9 []A\
  709de ATUH
  70a6f []A\A]A^A_
  70aa4 AWAVAUATUSH
  70abd D$(1
  70b3d |$ H
  70b90 L9,$
  70bb6 \$ L
  70beb D$(dH+
  70c05 8[]A\A]A^A_
  70c75 D$(dH+
  70c97 ]A\A]A^A_
  70d45 AVAUATM
  70d73 HcD$,H
  70da4 l$ A
  70fbe T$<H
  70fd4 []A\A]A^A_
  71104 AWAVAUATUSH
  71121 D$(1
  7117d D$ H
  711ca D$ H
  7125a L;t$
  71280 D$ H
  712b7 T$(dH+
  712cc 8[]A\A]A^A_
  71301 D$(dH+
  71324 ]A\A]A^A_
  71374 AUATUSH
  71404 []A\A]
  71484 AVAUATA
  714e4 ]A\A]A^
  7163c []A\A]
  7165b []A\A]
  71717 []A\
  71765 G0E1
  7179e Lc H
  71860 AWAVAUM
  71949 []A\A]A^A_
  71cdc D$(H9D$ 
  71d47 tgAUI
  71d91 ]A\A]
  71da5 ]A\Hc
  71dc9 ATUH
  71e2e A\A]
  71e49 AVAUATU
  71e7e []A\A]A^A_
  71eae t E1
  71ef4 AUATUSH
  71fa5 T$(dH+
  71fb6 8[]A\A]
  72074 AUATUSH
  720c6 []A\A]
  7228e tmI9
  72461 t5I9j
  7295d AWAVAUATI
  729fb []A\A]A^A_
  72a20 ATUSH
  72a6a []A\
  72a72 {0H+{ H
  72b14 AVAUATUSL
  72b36 I+|$ H
  72b4c []A\A]A^
  72b64 AVAUATUSL
  72b86 I+|$ H
  72b9c []A\A]A^
  72bbe ATUH
  72bc9 H+_ H)
  72c0c ]A\A]A^
  72cee []A\A]A^
  72d0e ATUH
  72d19 H+_ H)
  72d5c ]A\A]A^
  72e3e []A\A]A^
  72e56 WHH+w H
  72e76 O0H+O H
  72eae H+W H
  72ef8 H+S H
  72f84 AUATUH
  72fae S0H+S I
  72fcf []A\A]
  72fe6 H+w H
  73156 WHH+w H
  73174 AWAVI
  7317b AUATI
  73195 G0H9
  7319a s2H9
  731b7 H+} H
  731c4 H9](r
  731cc E0I9
  731d7 H+E M
  731de L+} H
  731f8 u&H9
  7320d []A\A]A^A_
  7326a []A\A]A^A_
  73286 WHH+w H
  732e6 t&H;G
  733c0 ATUH
  733f0 T$ H9
  73420 P H9
  7345f H H9
  73482 T$ H9
  73491 t-H9X
  734f4 H+w H
  73514 AWAVAUATUSH
  7355b @ I9
  735bc C0H+C 
  7363c L+C H
  7367c []A\A]A^A_
  736f0 AUATI
  73763 []A\A]
  73845 []A\
  73860 AWE1
  73865 AVAUATUSH
  7387c D$(1
  73909 |$ L
  73919 \$ L
  739b4 w)H9
  739e9 D$(dH+
  73a02 []A\A]A^A_
  73a26 \$ I
  73aa4 AWAVAUATUSH
  73b2f I+~ H)
  73b61 M+n H)
  73b7b []A\A]A^A_
  73bcb H+w H
  73be4 H+w H
  73c53 v;H9
  73ca4 []A\
  73cb4 AUATI
  73ce9 H+} 
  73cf8 e0L9
  73d05 []A\A]
  73d1a H+} H)
  73d2c []A\A]
  73d44 AWAVAUATUH
  73d93 []A\A]A^A_
  73e70 AWAVI
  73e77 AUATE1
  73f60 vwH)
  73f7a []A\A]A^A_
  7405b H+w H
  74074 H+w H
  740c3 t{H)
  740f3 P H9
  74134 ]A\A
  74169 AVAUATUSH
  741dd C L9
  741fd >L+d$
  74237 L9<$v\M9
  7429f []A\A]A^A_
  74311 USH+O H+W H9
  74383 w;H9
  7438f []A\
  7439e 4$A\
  743b2 $]A\
  74409 wuATH
  7445f H H9
  7452c ]A\A]
  7454f ATUSL
  7455e t$ H
  7456a T$$L
  74663 T$(I
  746a0 T$0L
  74704 T$0L
  74730 T$0L
  747db D$(H
  7482b T$0L
  74839 T$(H
  7484f T$0L
  7489a |$ 1
  749cd t$$L
  749d2 D$@L
  74a5d D$@M
  74aa9 \$XH
  74abd T$@E1
  74ad3 D$HH
  74aeb D$x1
  74af0 H9D$XH
  74af7 T$PL
  74b22 T$HH
  74b41 ~ H)
  74b4b D$XH
  74b50 D$@I
  74b5e H;D$@w
  74b6e D$@L;
  74b81 \$XA
  74bde L$HH
  74be3 T$@L
  74bfc D$@H
  74c01 t$XL
  74c10 D$H)
  74c22 T$pL
  74c51 t$$I
  74c62 T$(L
  74c6c \$XL
  74c87 D$@L
  74c99 T$(H
  74cae D$ L
  74cb9 t$XL
  74cf6 T$pL
  74d21 D$x1
  74d26 H9D$XH
  74d2d T$PL
  74db0 []A\A]A^A_
  74e1e <$H9
  74e5b t$$L
  74e60 D$@L
  74e7b D$0L
  74ec0 H#D$0I)
  74eea D$PL
  74f03 AXAYH
  74f1f L$HH
  74f24 T$@L
  74fc0 T$HH
  74fc5 t$@E1
  75032 T$8L
  75044 T$8L
  75062 D$@H
  750da H#L$@H#T$@H
  7510e D$HH)E
  75172 T$(E1
  7517b T$HL
  75202 D$@H
  75218 t$$L
  7524d \$ L
  75273 t$XH
  75278 D$PL
  752ae T$pL
  752dd D$x1
  752e2 H9D$XH
  752e9 T$PL
  75376 T$8H
  75399 D$PH
  753b4 T$8L
  753c7 T$@H
  753cc L$HH
  754e8 T$`H
  754ed t$PE1
  75526 T$`H
  7552b t$PE1
  755c8 D$(H
  755cd L$8dH
  755db D$x1
  755fa D$8H
  75608 T$HH
  75611 L$PH)
  7562e D$(D
  75653 |$8L
  75660 |$81
  75680 t$(H
  75696 L$(H
  756a4 D$(E1
  756d1 D$XH
  756f2 T$xdH+
  7570b []A\A]A^A_
  7574a D$(H
  7574f D$`H
  75776 l$ I
  75798 D$hH;D$Hw~L
  757b6 l$ H;L$
  757c5 t$(H
  75800 D$8H
  7583c |$8L9
  75858 D$pL
  7585d l$hI
  75865 T$`f
  7586a oD$`H
  75870 t$pI
  7587a )D$@H
  75880 t$PH
  75885 D$(L9
  75893 |$8M
  758c0 t$(M
  758cc RAUPL
  758d2 D$XH
  758df t$8H
  75913 T$`H)
  7591f D$(I
  75942 D$81
  7595f D$(H
  75984 AWAVAUATUSH
  75a2a l$8D
  75a80 D$8E
  75aa5 t$ E1
  75ac3 D$8H
  75ac8 D$ A
  75ada H;\$
  75b01 _AXH
  75b3f []A\A]A^A_
  75b7a D$@D
  75b98 t$ E1
  75bb2 T$@D
  75bbd \$,L
  75bd4 \$,H
  75c5a []A\A]A^A_
  75ca8 D$(D
  75e3f u/E1
  76102 Unknown 
  76117 codedf
  7621f Unknown d
  7622f codedH
  76284 ATSH
  76322 Lc H
  76344 ATUS
  763dd []A\
  763fa []A\
  764ae AUATI
  764cf D$H1
  76543 D$HdH+
  7655f P]A\A]A^A_
  7660d L$8L
  76612 D$@L
  7661f )D$P
  76624 )L$`
  76629 )T$p
  76688 D$ H
  767db t#98u
  76809 v5E1
  7687e ATUH
  76904 /w9H
  7695d []A\A]A^
  76a0a vDE1
  76a6e ATUH
  76af4 /w9H
  76b4d []A\A]A^
  76bb4 AWAVAUATI
  76be4 D$(1
  76ca7 T$ H
  76cac t$$L
  76cbf HcD$$H
  76cc9 T$ H
  76d52 D$(dH+
  76d6b []A\A]A^A_
  76d82 T$ H
  76d87 t$$I
  76d95 uQHct$$
  76d9d D$ H
  76dca T$ H
  76dcf t$$I
  76f29 T$%R
  76f2f T$,R
  76f35 T$3R
  76f3b T$:R
  76f54 D$NPD
  76f5b L$T1
  77008 while determining whether %s is mounted.
  7703a WARNING!!!  The filesystem is mounted.   If you continue you ***WILL***
  77082 cause ***SEVERE*** filesystem damage.
  770b0 Do you really want to continue
  770d0 Overwriting existing filesystem; this can be undone using the command:
  77117     e2undo %s %s
  77130 while trying to setup undo file
  77158 MMP interval is %u seconds and total wait time is %u seconds. Please wait...
  771a8 If you are sure the filesystem is not in use on any node, run:
  771e7 'tune2fs -f -E clear_mmp %s'
  77208 /sys/class/power_supply/AC/online
  77230 /proc/acpi/ac_adapter/%s/state
  77250  contains a file system with errors
  77278  primary superblock features different from backup
  772b0  has been mounted %u times without being checked
  772e8  has filesystem last checked time in the future
  77318  has gone %u days without being checked
  77340 ignoring check interval, broken_system_clock set
  77378 %s: clean, %u/%u files, %llu/%llu blocks
  773a8 %s: %u/%u files (%0d.%d%% non-contiguous), %llu/%llu blocks
  773e9 %12u inodes used (%2.2f%%, out of %u)
  77411 %12u inode used (%2.2f%%, out of %u)
  77438 %12u non-contiguous files (%0d.%d%%)
  77460 %12u non-contiguous file (%0d.%d%%)
  77488 %12u non-contiguous directories (%0d.%d%%)
  774b8 %12u non-contiguous directory (%0d.%d%%)
  774e8              # of inodes with ind/dind/tind blocks: %u/%u/%u
  77528              Extent depth histogram: 
  77550 %12llu blocks used (%2.2f%%, out of %llu)
  77580 %12llu block used (%2.2f%%, out of %llu)
  775b0 Usage: %s [-panyrcdfktvDFV] [-b superblock] [-B blocksize]
  775eb 		[-l|-L bad_blocks_file] [-C fd] [-j external_journal]
  77623 		[-E extended-options] [-z undo_file] device
  77659 Emergency help:
  77669  -p                   Automatic repair (no questions)
  7769f  -n                   Make no changes to the filesystem
  776d7  -y                   Assume "yes" to all questions
  7770b  -c                   Check for bad blocks and add them to the badblock list
  77758  -f                   Force checking even if filesystem is marked clean
  777a8  -v                   Be verbose
  777c9  -b superblock        Use alternative superblock
  777fa  -B blocksize         Force blocksize when looking for superblock
  7783c  -j external_journal  Set location of the external journal
  77877  -l bad_blocks_file   Add to badblocks list
  778a3  -L bad_blocks_file   Set badblocks list
  778cc  -z undo_file         Create an undo file
  778f8 Syntax error in e2fsck config file (%s, line #%d)
  77930 Invalid readahead buffer size.
  77951 Extended options are separated by commas, and may take an argument which
  7799a is set off by an equals ('=') sign.  Valid extended options are:
  779e0 	ea_ver=<ea_version (1 or 2)>
  77a00 ERROR: Couldn't open /dev/null (%s)
  77a28 Error validating file descriptor %d: %s
  77a58 Invalid completion information file descriptor
  77a88 Only one of the options -p/-a, -n or -y may be specified.
  77ac8 panyrcC:B:dE:fvtFVM:b:I:j:P:l:L:N:SsDkz:
  77af8 The -n and -D options are incompatible.
  77b20 The -n and -c options are incompatible.
  77b48 The -n and -l/-L options are incompatible.
  77b78 The -D and -E fixes_only options are incompatible.
  77bb0 The -E bmap2extent and fixes_only options are incompatible.
  77bf0 The -c and the -l/-L options may not be both used at the same time.
  77c39 Invalid non-numeric argument to -%c ("%s")
  77c68 Error: ext2fs library version out of date!
  77c98 while trying to initialize program
  77cc0 <?xml version="1.0" encoding="utf-8"?>
  77ce8 need terminal for interactive repairs
  77d10 %s: %s trying backup blocks...
  77d30 %s: %s while using the backup blocks
  77d58 %s: going back to original superblock
  77d80 The filesystem revision is apparently too high for this version of e2fsck.
  77dcb (Or the filesystem superblock is corrupt)
  77df8 Could this be a zero-length partition?
  77e20 You must have %s access to the filesystem or be root
  77e58 Possibly non-existent or swap device?
  77e80 Filesystem mounted or opened exclusively by another program?
  77ec0 Possibly non-existent device?
  77ee0 Disk write-protected; use the -n option to do a read-only
  77f1a check of the device.
  77f30 %s: Trying to load superblock despite errors...
  77f68 Get a newer version of e2fsck!
  77f88 Cannot proceed with file system check
  77fb0 Warning: skipping journal recovery because doing a read-only filesystem check.
  78000 unable to set superblock flags on %s
  78028 Journal checksum error found in %s
  78050 while recovering journal of %s
  78070 %s has unsupported feature(s):
  78090 %s has unsupported encoding: %0x
  780b8 %s: %s while reading bad blocks inode
  780e0 This doesn't bode well, but we'll try to go on...
  78118 Creating journal (%d blocks): 
  78138 %s: while trying to create journal
  78161 *** journal has been regenerated ***
  78188 Restarting e2fsck from the beginning...
  781b9 %s: ***** FILE SYSTEM WAS MODIFIED *****
  781e8 %s: ***** REBOOT SYSTEM *****
  78209 %s: ********** WARNING: Filesystem still has errors **********
  7824a ext2fs_check_if_mount
  78260 Warning!  %s is mounted.
  7827a Warning!  %s is in use.
  78293 Cannot continue, aborting.
  782b5 check aborted.
  782c5 E2FSPROGS_UNDO_DIR
  782d8 /var/lib/e2fsprogs
  782eb undo_dir
  782f4 defaults
  782fd none
  78302 %s/e2fsck-%s.e2undo
  78316 while trying to delete %s
  78330 while checking MMP block
  78349 while reading MMP block
  78361 /proc/apm
  7836b %79s %79s %79s %x
  7837d /proc/acpi/ac_adapter
  78393 %79s %79s
  7839d off-line
  783a6 broken_system_clock
  783ba options
  783c2 defer_check_on_battery
  783d9  was not cleanly unmounted
  783f4 %s: 
  783f9 , check forced.
  7840a  (check deferred; on battery)
  78428  (check after next mount)
  78442  (check in %ld mounts)
  78459 report_features
  7846a Filesystem features:
  7847f  (none)
  78487 %12u bad blocks
  78498 %12u bad block
  784a8 %12u large files
  784ba %12u large file
  784cc %12u regular files
  784e1 %12u regular file
  784f4 %12u directories
  78506 %12u directory
  78516 %12u character device files
  78533 %12u character device file
  7854f %12u block device files
  78568 %12u block device file
  78580 %12u fifos
  7858c %12u fifo
  78597 %12u links
  785a3 %12u link
  785ae %12u symbolic links
  785c2 %12u symbolic link
  785d5  (%u fast symbolic links)
  785f0  (%u fast symbolic link)
  7860a %12u sockets
  78618 %12u socket
  78625 ------------
  78633 %12u files
  7863f %12u file
  7864a ea_ver
  78651 Invalid EA version.
  78666 fragcheck
  78670 journal_only
  7867d nodiscard
  78687 no_optimize_extents
  7869b no_inode_count_fullmap
  786b2 problem_log
  786be bmap2extent
  786ca fixes_only
  786d5 unshare_blocks
  786e4 check_encoding
  786f3 Unknown extended option: %s
  78710 	fragcheck
  7871c 	journal_only
  7872b 	discard
  78735 	nodiscard
  78741 	optimize_extents
  78754 	no_optimize_extents
  7876a 	inode_count_fullmap
  78780 	no_inode_count_fullmap
  78799 	readahead_kb=<buffer size>
  787b6 	bmap2extent
  787c4 	unshare_blocks
  787d5 	fixes_only
  787e2 	check_encoding
  787f3 readahead_kb
  78800 /dev/null
  7880a E2FSCK_FORCE_INTERACTIVE
  78823 e2fsck
  7882a Unable to resolve '%s'
  78841 E2FSCK_FIXES_ONLY
  78853 E2FSCK_CONFIG
  78861 report_time
  7886d report_verbose
  7887c readahead_mem_pct
  7888e while opening %s for flushing
  788ac while trying to flush %s
  788c5 ext2fs_sync_device
  788d8 PATH
  788dd PATH=/sbin
  788e8 Couldn't malloc() newpath
  78902 %s%s
  7890a %s%s: |%s%s
  78916  %4.1f%%  
  78928 %d %lu %lu %s
  7893f /usr/share/locale
  78951 E2fsck run: 
  7895e <problem_log time="%lu">
  78978 <invocation prog="%s"
  7898e  arg%d="%s"
  7899a 30-Dec-2021
  789a6 e2fsck %s (%s)
  789b6 	Using %s, %s
  789c5 TEST_IO_FLAGS
  789d3 TEST_IO_BLOCK
  789e1 old_bitmaps
  789ed Superblock invalid,
  78a01 Group descriptors look bad...
  78a1f while trying to open %s
  78a37 <filesystem dev="%s"
  78a4c  uuid="%s"
  78a57  label="%.*s"
  78a65 Filesystem UUID: %s
  78a7a while checking journal for %s
  78a98 Journal corrupted in %s
  78ab1  Done.
  78ab9 aborted
  78ac1 %s: e2fsck canceled.
  78ad7 while resetting context
  78aef allow_cancellation
  78b02 Exit status: %d
  78b13 /etc/e2fsck.conf
  78cc8 \|/-
  78cea HBE2FSCK_TIME
  78cf8 </problem_log>
  78d08 while calling ext2fs_block_iterate for inode %u
  78d38 while calling ext2fs_adjust_ea_refcount2 for inode %u
  78d6e release_inode_blocks
  78d83 block iterate buffer
  78d98 release_orphan_inodes
  78dae Truncating
  78db9 Clearing
  78dc2 delete_file
  78dce clear_resize
  78ddb resize dind buffer
  78dee invalid_inode_bitmap
  78e03 invalid_block_bitmap
  78e18 invalid_inode_table
  78e2c inodes_count
  78e39 first_data_block
  78e4a log_block_size
  78e59 log_cluster_size
  78e6a clusters_per_group
  78e7d blocks_per_group
  78e8e inodes_per_group
  78e9f r_blocks_count
  78eae reserved_gdt_blocks
  78ec2 desc_size
  78ecc first_ino
  78ed6 inode_size
  78ee1 clear_test_fs_flag
  78ef4 ext4
  78ef9 accept_time_fudge
  78f0b buggy_init_scripts
  78f1e inode in bad block map
  78f35 inode_bb_map
  78f42 imagic inode map
  78f53 inode_imagic_map
  78f64 bad inode map
  78f72 inode_bad_map
  78f80 pass1
  78f86 system.data
  78f92 check_large_ea_inode
  78fa7 reading directory block
  78fbf check_is_really_dir
  78fd3 multiply claimed block map
  78fee block_dup_map
  78ffc ext2fs_extent_get_info
  79013 ext2fs_extent_fix_parents
  7902d ext2fs_extent_delete
  79042 EXT2_EXTENT_UP
  79051 EXT2_EXTENT_DOWN
  79062 ext attr block map
  79075 block_ea_map
  79082 check_ext_attr
  79091 scratch_files
  7909f numdirs_threshold
  790b1 check_blocks_extents
  790c6 check_blocks
  790d3 getting next inode from scan
  790f0 in-use inode map
  79101 inode_used_map
  79110 directory inode map
  79124 inode_dir_map
  79132 regular file inode map
  79149 inode_reg_map
  79157 in-use block map
  79168 block_found_map
  79178 metadata block map
  7918b block_metadata_map
  7919e inode casefold map
  791b1 inode_casefold_map
  791c4 inode_link_info
  791d4 scratch inode
  791e2 array of inodes to process
  791fd block interate buffer
  79213 opening inode scan
  79226 clear bad inode
  79236 Pass 1
  7923d recreate inode
  79250 while hashing entry with e_value_inum = %u
  79280 %6lu(%c): expecting %6lu got phys %6lu (blkcnt %lld)
  792b8 %6lu(%c): expecting %6lu actual extent phys %6lu log %lu len %lu
  79300 reading indirect blocks of inode %u
  79328 lost+found
  79333 duplicate cluster header
  7934c inode element
  7935a duplicate inode header
  79371 cluster element
  79381 delete_file_block
  79393 clone_file_block
  793a4 clone_file
  793af clone file EA
  793bd Shared inode list
  793cf pass1b
  793d6 multiply claimed inode map
  793f1 inode_dup_map
  793ff Pass 1b
  79407 Pass 1c
  7940f Pass 1d
  79418 internal error: can't find dup_blk for %llu
  79448 returned from clone_file_block
  79468 internal error: couldn't lookup EA block record for %llu
  794a8 internal error: couldn't lookup EA inode record for %u
  794df check_encryption_policy
  794f7 NLS is broken.
  79506 clear_htree
  79512 allocate_dir_block
  79525 ext2fs_new_block
  79536 ext2fs_new_dir_block
  7954b ext2fs_write_dir_block
  79562 ext2fs_inode_size_set
  79578 ext2fs_block_iterate
  7958d check_filetype
  7959c deallocate_inode
  795ad inode_count
  795b9 directory scan buffer
  795cf Pass 2
  795d6 process_bad_inode
  795e8 Can not continue.
  795fa ext2fs_write_inode
  7960d ext2fs_write_dir_block4
  79625 ext2fs_unlink
  79633 ext2fs_link
  7963f expand_directory
  79654 inode loop detection bitmap
  79670 inode_loop_detect
  79682 inode done bitmap
  79694 inode_done_map
  796a3 Peak memory
  796af Pass 3
  796b8 lost+found
  796c3 pass4: check_ea_inode
  796d9 pass4
  796df pass4: disconnect_inode
  796f7 bad_inode buffer
  79708 Pass 4
  7970f actual bitmap buffer
  79724 bitmap block buffer
  79738 free block count array
  7974f free inode count array
  79766 directory count array
  7977c Pass 5
  79788 PROGRAMMING ERROR: Got start %d outside of group %d! Disabling discard
  797d0 check_block_bitmap_checksum: Memory allocation error
  79808 check_inode_bitmap_checksum: Memory allocation error
  79840 Error "%s" encountered in function %s at line %d
  79878 *** journal has been deleted ***
  798a0 %s: no valid journal superblock found
  798c8 %s: incorrect fast commit blocks
  798f0 %s: won't do journal recovery while read-only
  79950 ext4_fc_handle_inode
  79968 make_room
  79980 ext4_fc_read_extents
  799a0 ext4_fc_handle_add_extent
  799c0 ext4_fc_handle_unlink
  799e0 ext4_fc_handle_link_and_create
  79a00 ext4_fc_replay
  79a0f while reading block %llu
  79a29 while writing block %llu
  79a43 reading journal superblock
  79a5f %s: journal too short
  79a76 kdev
  79a7b journal inode
  79a89 UUID
  79a8e %s: recovering journal
  79aa6 while trying to re-open %s
  79ac1 .journal.dat
  79ad0 Bad block %u out of range; ignored.
  79af8 Warning: illegal block %u found in bad block inode.  Cleared.
  79b38 while sanity checking the bad blocks inode
  79b68 while reading the bad blocks inode
  79b90 badblocks -b %d -X %s%s%s %llu
  79bb0 while reading in list of bad blocks from file
  79be0 %s: Updating bad block inode.
  79c00 while updating bad block inode
  79c27 ext2fs_read_bb_inode
  79c3c read_bad_blocks_file
  79c51 while trying popen '%s'
  79c69 ext2fs_read_bb_FILE
  79c7d ext2fs_update_bb_inode
  79c94 e2fsck: %s
  79ca9  ('a' enables 'yes' to all) 
  79cce  (y/n)
  79cd5 %s%s%s? 
  79cde cancelled!
  79cea yes to all
  79cff %s? no
  79d08 %s? yes
  79d16 %s? %s
  79d1f Memory used: %lluk, 
  79d34 time: %5.2f/%5.2f/%5.2f
  79d4d while reading inode %lu in %s
  79d6b ext2fs_read_inode
  79d7d ext2fs_read_inode_full
  79d94 while writing inode %lu in %s
  79db2 /proc/filesystems
  79dc4 /lib/modules/%s/modules.dep
  79de4 MMP check failed: 
  79df7 MMP_block:
  79e03     mmp_magic: 0x%x
  79e18     mmp_check_interval: %d
  79e34     mmp_sequence: %08x
  79e4c     mmp_update_date: %s
  79e64     mmp_update_time: %lld
  79e7f     mmp_node_name: %.*s
  79e98     mmp_device_name: %.*s
  79eb7 fs_bitmaps
  79ec8 e2fsck: io manager magic bad!
  79ee8 Can't allocate %lu bytes for %s
  79f10 writing block and inode bitmaps
  79f30 while rewriting block and inode bitmaps for %s
  79f62 %s: UNEXPECTED INCONSISTENCY; RUN fsck MANUALLY.
  79f93 	(i.e., without -a or -p options)
  79fb8 Memory used: %lluk/%lluk (%lluk/%lluk), 
  79fe8 I/O read: %lluMB, write: %lluMB, rate: %.2fMB/s
  7a020 UNEXPECTED INCONSISTENCY: the filesystem is being modified while fsck is running.
  7a078 e2fsck_read_bitmaps: illegal bitmap block(s) for %s
  7a0b0 reading inode and block bitmaps
  7a0d0 while retrying to read bitmaps for %s
  7a0f9 $tIdirinfo
  7a104 %s/%s-dirinfo-XXXXXX
  7a119 directory map db
  7a12a directory map
  7a138 store failed: %s
  7a14a e2fsck_free_dir_info
  7a15f dir_info iterator
  7a171 iter fetch failed: %s
  7a188 Couldn't reallocate dir_info structure to %u entries
  7a1c0 while freeing dir_info tdb file
  7a1e0 dx_block info array
  7a1f8 Couldn't reallocate dx_dir_info structure to %u entries
  7a238 Error writing block %lu (%s) while %s.  
  7a268 Error writing block %lu (%s).  
  7a288 Error reading block %lu (%s) while %s.  
  7a2b8 Error reading block %lu (%s).  
  7a2d8 Ignore error
  7a2e5 Force rewrite
  7a2f3 <header code="0x%06x"/>
  7a30c  errcode="%lu"
  7a31b  fixed="1"
  7a326  ino="%u"
  7a330  ino2="%u"
  7a33b  dir="%u"
  7a345  blk="%llu"
  7a351  blk2="%llu"
  7a35e  blkcount="%lld"
  7a36f  group="%u"
  7a37b  csum1="%u"
  7a387  csum2="%u"
  7a393  num="%llu"
  7a39f  num2="%llu"
  7a3ac  str="%s"
  7a3b6 Unhandled error code (0x%x)!
  7a3d4 0x%06x
  7a3db description
  7a3e7 preen_ok
  7a3f0 no_ok
  7a3f6 no_default
  7a401 print_message_only
  7a414 preen_nomessage
  7a424 no_collate
  7a42f no_nomsg
  7a438 preen_noheader
  7a447 force_no
  7a450 not_a_fix
  7a45a max_count_problems
  7a46d max_count
  7a477 <suppressed code="0x%06x"/>
  7a494 ...problem 0x%06x suppressed
  7a4b7 IGNORED
  7a4bf @i count in @S is %i, @s %j.
  7a4dd @S has an @n @j (@i %i).
  7a4f7 Can't find external @j
  7a50f External @j has bad @S
  7a527 @j @S is corrupt.
  7a53a Clear @j
  7a543 @I @o @i %i in @S.
  7a557 @I @i %i in @o @i list.
  7a570 Error moving @j: %m
  7a586 Run @j anyway
  7a594 Resize @i not valid.  
  7a5ab Adding dirhash hint to @f.
  7a5c8 Hiding %U @q @i %i (%Q).
  7a5e2 @S has invalid MMP block.  
  7a5fe @S has invalid MMP magic.  
  7a61a ext2fs_open2: %m
  7a62c ext2fs_check_desc: %m
  7a643 Invalid %U @q @i %i.  
  7a65a @r is not a @d.  
  7a66c @D @i %i has zero dtime.  
  7a687 @i %i is a @z @d.  
  7a69b @g %g's @b @B at %b @C.
  7a6b4 @g %g's @i @B at %b @C.
  7a6cd @g %g's @i table at %b @C.
  7a6e9 @g %g's @b @B (%b) is bad.  
  7a706 @g %g's @i @B (%b) is bad.  
  7a723 @i %i, i_@bs is %Ib, @s %N.  
  7a741 @I %B (%b) in @i %i.  
  7a758 @i %i has illegal @b(s).  
  7a773 @I %B (%b) in bad @b @i.  
  7a78e Duplicate or bad @b in use!
  7a7ab @A @i @B (%N): %m
  7a7be @A @b @B (%N): %m
  7a7d1 @A @d @b array: %m
  7a7e5 Error reading @i %i: %m
  7a7fe @i %i has imagic flag set.  
  7a81b @j is not regular file.  
  7a835 @i %i has a bad @a @b %b.  
  7a851 @a @b %b has h_@bs > 1.  
  7a86b @i %i is too big.  
  7a87f @h %i has an @n root node.
  7a89b The bad @b @i looks @n.  
  7a8b5 @i %i has @I @a value @i %N.
  7a8d3 @m @b(s) in @i %i:
  7a8ea @A @i @B (@i_dup_map): %m
  7a905  %b--%c
  7a90d Pass 1D: Reconciling @m @bs
  7a92a 	%Q (@i #%i, mod time %IM)
  7a946 	<@f metadata>
  7a956 Couldn't clone file: %m
  7a96f Pass 1E: Optimizing @x trees
  7a98d Optimizing @x trees: 
  7a9a7 @E has @n @i #: %Di.
  7a9bd @E has @D/unused @i %Di.  
  7a9d8 @E @L to '.'  
  7a9e7 @E @L to @d %P (%Di).
  7a9fe @E @L to the @r.
  7aa10 Missing '.' in @d @i %i.
  7aa2a Missing '..' in @d @i %i.
  7aa45 i_faddr @F %IF, @s zero.
  7aa5f i_file_acl @F %If, @s zero.
  7aa7c i_size_high @F %Id, @s zero.
  7aa9a i_frag @F %N, @s zero.
  7aab2 i_fsize @F %N, @s zero.
  7aacb @i %i (%Q) is an @I @b @v.
  7aae7 @E is duplicate '.' @e.
  7ab00 @E is duplicate '..' @e.
  7ab1a @A icount structure: %m
  7ab33 Error deallocating @i %i: %m
  7ab51 @i %i (%Q) is an @I FIFO.
  7ab6c @i %i (%Q) is an @I socket.
  7ab89 @E has filetype set.
  7ab9f @E has a @z name.
  7abb2 Symlink %Q (@i #%i) is @n.
  7abce @a @b @F @n (%If).
  7abe2 @p @h %d: %B not referenced
  7abff @n @h %d (%q).  
  7ac10 @p @h %d: root node is @n
  7ac2b Duplicate @E found.  
  7ac41 i_blocks_hi @F %N, @s zero.
  7ac5e Unexpected @b in @h %d (%q).
  7ac7c Encrypted @E is too short.
  7ac98 @r not allocated.  
  7acac No room in @l @d.  
  7acc0 Unconnected @d @i %i (%p)
  7acdb /@l not found.  
  7acec Could not expand /@l: %m
  7ad06 Could not reconnect %i: %m
  7ad22 @r is not a @d; aborting.
  7ad3d Cannot proceed without a @r.
  7ad5b /@l is not a @d (ino=%i)
  7ad75 /@l has inline data
  7ad8a /@l is encrypted
  7ad9c Optimizing directories: 
  7adb9 @u @z @i %i.  
  7adc8 @u @i %i
  7add2 @b @B differences: 
  7ade6  -%b
  7adeb  +%b
  7adf0 @i @B differences: 
  7ae04  -%i
  7ae09  +%i
  7ae0e  -(%b--%c)
  7ae19  +(%b--%c)
  7ae24  -(%i--%j)
  7ae2f  +(%i--%j)
  7ae3a Recreate @j
  7ae46 (NONE)
  7ae4d FIXED
  7ae53 RELOCATED
  7ae5d ALLOCATED
  7ae67 EXPANDED
  7ae70 RECONNECTED
  7ae7c CREATED
  7ae84 SALVAGED
  7ae8d TRUNCATED
  7ae97 INODE CLEARED
  7aea5 ABORTED
  7aead SPLIT
  7aeb3 CONTINUING
  7aebe FILE DELETED
  7aecb SUPPRESSED
  7aed6 UNLINKED
  7aedf HTREE INDEX CLEARED
  7aef3 WILL RECREATE
  7af01 WILL OPTIMIZE
  7af0f FLAG CLEARED
  7af1c (no prompt)
  7af2c Clear
  7af32 Relocate
  7af3b Allocate
  7af44 Expand
  7af4b Connect to /lost+found
  7af62 Create
  7af69 Salvage
  7af71 Truncate
  7af7a Clear inode
  7af86 Abort
  7af8c Split
  7af92 Continue
  7af9b Clone multiply-claimed blocks
  7afb9 Delete file
  7afc5 Suppress messages
  7afd7 Unlink
  7afde Clear HTree index
  7aff0 Recreate
  7aff9 Optimize
  7b002 Clear flag
  7b010 <problem code="0x%06x" answer="%d"
  7b038 @b @B for @g %g is not in @g.  (@b %b)
  7b060 @i @B for @g %g is not in @g.  (@b %b)
  7b088 @i table for @g %g is not in @g.  (@b %b)
  7b0b2 WARNING: SEVERE DATA LOSS POSSIBLE.
  7b0d9 The @S could not be read or does not describe a valid ext2/ext3/ext4
  7b11e @f.  If the @v is valid and it really contains an ext2/ext3/ext4
  7b15f @f (and not swap or ufs or something else), then the @S
  7b197 is corrupt, and you might try running e2fsck with an alternate @S:
  7b1da     e2fsck -b 8193 <@v>
  7b1f6     e2fsck -b 32768 <@v>
  7b218 The @f size (according to the @S) is %b @bs
  7b244 The physical size of the @v is %c @bs
  7b26a Either the @S or the partition table is likely to be corrupt!
  7b2b0 @S @b_size = %b, fragsize = %c.
  7b2d0 This version of e2fsck does not support fragment sizes different
  7b311 from the @b size.
  7b328 @S @bs_per_group = %b, should have been %c
  7b358 @S first_data_@b = %b, should have been %c
  7b388 @f did not have a UUID; generating one.
  7b3b8 Note: if several inode or block bitmap blocks or part
  7b3ee of the inode table require relocation, you may wish to try
  7b429 running e2fsck with the '-b %S' option first.  The problem
  7b464 may lie only with the primary block group descriptors, and
  7b49f the backup block group descriptors may be OK.
  7b4d0 Corruption found in @S.  (%s = %N).
  7b4f8 Error determining size of the physical @v: %m
  7b528 The Hurd does not support the filetype feature.
  7b560 External @j has multiple @f users (unsupported).
  7b598 External @j does not support this @f
  7b5c0 @f @j @S is unknown type %N (unsupported).
  7b5eb It is likely that your copy of e2fsck is old and/or doesn't support this @j format.
  7b63f It is also possible the @j @S is corrupt.
  7b670 @S has_@j flag is clear, but a @j is present.
  7b6a0 @S needs_recovery flag is set, but no @j is present.
  7b6d8 @S needs_recovery flag is clear, but @j has data.
  7b710 @f has feature flag(s) set, but is a revision 0 @f.  
  7b748 %s @o @i %i (uid=%Iu, gid=%Ig, mode=%Im, size=%Is)
  7b780 @I %B (%b) found in @o @i %i.
  7b7a0 Already cleared %B (%b) found in @o @i %i.
  7b7d0 @j @S has an unknown read-only feature flag set.
  7b808 @j @S has an unknown incompatible feature flag set.
  7b840 @j version not supported by this e2fsck.
  7b870 Moving @j from /%s to hidden @i.
  7b898 Found @n V2 @j @S fields (from V1 @j).
  7b8bf Clearing fields beyond the V1 @j @S...
  7b8e8 Recovery flag not set in backup @S, so running @j anyway.
  7b928 Backing up @j @i @b information.
  7b950 @f does not have resize_@i enabled, but s_reserved_gdt_@bs
  7b98b is %N; @s zero.  
  7b9a0 Resize_@i not enabled, but the resize @i is non-zero.  
  7b9d8 @S last mount time (%t,
  7b9f0 	now = %T) is in the future.
  7ba10 @S last write time (%t,
  7ba28 	now = %T) is in the future.
  7ba48 @S hint for external superblock @s %X.  
  7ba78 @g descriptor %g checksum is %04x, should be %04y.  
  7bab0 @g descriptor %g marked uninitialized without feature set.
  7baf0 @g descriptor %g has invalid unused inodes count %b.  
  7bb28 Last @g @b @B uninitialized.  
  7bb48 Journal transaction %i was corrupt, replay was aborted.
  7bb88 The test_fs flag is set (and ext4 is available).  
  7bbc0 @S last mount time is in the future.
  7bbe5 	(by less than a day, probably due to the hardware clock being incorrectly set)
  7bc38 @S last write time is in the future.
  7bc5d 	(by less than a day, probably due to the hardware clock being incorrectly set)
  7bcb0 One or more @b @g descriptor checksums are invalid.  
  7bce8 Setting free @is count to %j (was %i)
  7bd10 Setting free @bs count to %c (was %b)
  7bd38 @S metadata_csum supersedes uninit_bg; both feature bits cannot be set simultaneously.
  7bd90 @S MMP @b checksum does not match.  
  7bdb8 @S 64bit @f needs extents to access the whole disk.  
  7bdf0 First_meta_bg is too big.  (%N, max value %g).  
  7be28 External @j @S checksum does not match @S.  
  7be58 @S metadata_csum_seed is not necessary without metadata_csum.
  7be98 Error initializing quota context in support library: %m
  7bed8 Bad required extra isize in @S (%N).  
  7bf00 Bad desired extra isize in @S (%N).  
  7bf28 @S would have too many inodes (%N).
  7bf50 Resize_@i and meta_bg features are enabled. Those features are
  7bf8f not compatible. Resize @i should be disabled.  
  7bfc0 Pass 1: Checking @is, @bs, and sizes
  7bfe8 @r has dtime set (probably due to old mke2fs).  
  7c020 Reserved @i %i (%Q) has @n mode.  
  7c048 @i %i is in use, but has dtime set.  
  7c070 @i %i, i_size is %Is, @s %N.  
  7c090 %B (%b) overlaps @f metadata in @i %i.  
  7c0c0 Too many illegal @bs in @i %i.
  7c0e0 Bad @b @i has illegal @b(s).  
  7c100 Bad @b %b used as bad @b @i indirect @b.  
  7c131 The bad @b @i has probably been corrupted.  You probably
  7c16a should stop now and run e2fsck -c to scan for bad blocks
  7c1a3 in the @f.
  7c1b1 If the @b is really bad, the @f can not be fixed.
  7c1e8 You can remove this @b from the bad @b list and hope
  7c21d that the @b is really OK.  But there are no guarantees.
  7c258 The primary @S (%b) is on the bad @b list.
  7c288 Block %b in the primary @g descriptors is on the bad @b list
  7c2c8 Warning: Group %g's @S (%b) is bad.
  7c2f0 Warning: Group %g's copy of the @g descriptors has a bad @b (%b).
  7c338 Programming error?  @b #%b claimed for no reason in process_bad_@b.
  7c380 @A %N contiguous @b(s) in @b @g %g for %s: %m
  7c3b0 @A @b buffer for relocating %s
  7c3d0 Relocating @g %g's %s from %b to %c...
  7c3f8 Relocating @g %g's %s to %c...
  7c418 Warning: could not read @b %b of %s: %m
  7c448 Warning: could not write @b %b for %s: %m
  7c478 @A icount link information: %m
  7c498 Error while scanning @is (%i): %m
  7c4c0 Error while iterating over @bs in @i %i: %m
  7c4f0 Error storing @i count information (@i=%i, count=%N): %m
  7c530 Error storing @d @b information (@i=%i, @b=%b, num=%N): %m
  7c570 Special (@v/socket/fifo/symlink) file (@i %i) has immutable
  7c5ac or append-only flag set.  
  7c5c8 Special (@v/socket/fifo) @i %i has non-zero size.  
  7c600 @j @i is not in use, but contains data.  
  7c630 @i %i was part of the @o @i list.  
  7c658 @is that were part of a corrupted orphan linked list found.  
  7c698 @A refcount structure (%N): %m
  7c6b8 Error reading @a @b %b for @i %i.  
  7c6e0 Error reading @a @b %b (%m).  
  7c700 @a @b %b has reference count %r, @s %N.  
  7c730 Error writing @a @b %b (%m).  
  7c750 @A @a region allocation structure.  
  7c778 @a @b %b is corrupt (allocation collision).  
  7c7a8 @a @b %b is corrupt (@n name).  
  7c7d0 @a @b %b is corrupt (@n value).  
  7c7f8 %B (%b) causes @d to be too big.  
  7c820 %B (%b) causes file to be too big.  
  7c848 %B (%b) causes symlink to be too big.  
  7c870 @i %i has INDEX_FL flag set on @f without htree support.
  7c8b0 @i %i has INDEX_FL flag set but is not a @d.
  7c8e0 @h %i has an unsupported hash version (%N)
  7c910 @h %i uses an incompatible htree root node flag.
  7c948 @h %i has a tree depth (%N) which is too big
  7c978 Bad @b @i has an indirect @b (%b) that conflicts with
  7c9ae @f metadata.  
  7c9c0 Resize @i (re)creation failed: %m.
  7c9e8 @i %i has a extra size (%IS) which is @n
  7ca18 @a in @i %i has a namelen (%N) which is @n
  7ca48 @a in @i %i has a value offset (%N) which is @n
  7ca80 @a in @i %i has a value @b (%N) which is @n (must be 0)
  7cac0 @a in @i %i has a value size (%N) which is @n
  7caf0 @a in @i %i has a hash (%N) which is @n
  7cb20 @i %i is a %It but it looks like it is really a directory.
  7cb60 Error while reading over @x tree in @i %i: %m
  7cb90 Failed to iterate extents in @i %i
  7cbb3 	(op %s, blk %b, lblk %c): %m
  7cbd8 @i %i has an @n extent
  7cbef 	(logical @b %c, @n physical @b %b, len %N)
  7cc20 @i %i has an @n extent
  7cc37 	(logical @b %c, physical @b %b, @n len %N)
  7cc68 @i %i has EXTENTS_FL flag set on @f without extents support.
  7cca8 @i %i is in extent format, but @S is missing EXTENTS feature
  7cce8 @i %i missing EXTENT_FL, but is in extents format
  7cd20 Fast symlink %i has EXTENT_FL set.  
  7cd48 @i %i has out of order extents
  7cd67 	(@n logical @b %c, physical @b %b, len %N)
  7cd98 @i %i has an invalid extent node (blk %b, lblk %c)
  7cdd0 Error converting subcluster @b @B: %m
  7cdf8 @q @i is not a regular file.  
  7ce18 @q @i is not in use, but contains data.  
  7ce48 @q @i is visible to the user.  
  7ce68 @i %i has zero length extent
  7ce85 	(@n logical @b %c, physical @b %b)
  7ceb0 @i %i seems to contain garbage.  
  7ced8 @i %i passes checks, but checksum does not match @i.  
  7cf10 @i %i @a is corrupt (allocation collision).  
  7cf40 @i %i extent block passes checks, but checksum does not match extent
  7cf85 	(logical @b %c, physical @b %b, len %N)
  7cfb0 @i %i @a @b %b passes checks, but checksum does not match @b.  
  7cff0 Interior @x node level %N of @i %i:
  7d014 Logical start %b does not match logical start %c at next level.  
  7d058 @i %i, end of extent exceeds allowed value
  7d083 	(logical @b %c, physical @b %b, len %N)
  7d0b0 @i %i has inline data, but @S is missing INLINE_DATA feature
  7d0f0 @i %i has INLINE_DATA_FL flag on @f without inline data support.
  7d138 @i %i block %b conflicts with critical metadata, skipping block checks.
  7d188 @d @i %i @b %b should be at @b %c.  
  7d1b0 @d @i %i has @x marked uninitialized at @b %c.  
  7d1e8 @i %i logical @b %b (physical @b %c) violates cluster allocation rules.
  7d230 Will fix in pass 1B.
  7d248 @i %i has INLINE_DATA_FL flag but @a not found.  
  7d280 Special (@v/socket/fifo) file (@i %i) has extents
  7d2b2 or inline-data flag set.  
  7d2d0 @i %i has @x header but inline data flag is set.
  7d308 @i %i seems to have inline data but @x flag is set.
  7d340 @i %i seems to have @b map but inline data and @x flags set.
  7d380 @i %i has inline data and @x flags set but i_block contains junk.
  7d3c8 Bad block list says the bad block list @i is bad.  
  7d400 @A @x region allocation structure.  
  7d428 @i %i has a duplicate @x mapping
  7d449 	(logical @b %c, @n physical @b %b, len %N)
  7d478 @A %N bytes of memory for encrypted @i list
  7d4a8 @i %i @x tree could be more shallow (%b; could be <= %c)
  7d4e8 @i %i on bigalloc @f cannot be @b mapped.  
  7d518 @i %i has corrupt @x header.  
  7d538 Timestamp(s) on @i %i beyond 2310-04-04 are likely pre-1970.
  7d578 @i %i has @n @a. EA @i %N missing EA_INODE flag.
  7d5b0 EA @i %N for parent @i %i missing EA_INODE flag.
  7d5e8 @i %i has @x marked uninitialized at @b %c (len %N).  
  7d620 @i %i has the casefold flag set but is not a directory.  
  7d660 @d %p has the casefold flag, but the
  7d685 casefold feature is not enabled.  
  7d6a8 @i %i has encrypt flag but no encryption @a.
  7d6d8 Encrypted @i %i has corrupt encryption @a.
  7d708 @h %i uses hash version (%N), but should use SipHash (6) 
  7d748 @h %i uses SipHash, but should not.  
  7d771 Running additional passes to resolve @bs claimed by more than one @i...
  7d7b9 Pass 1B: Rescanning for @m @bs
  7d7e0 Error while scanning inodes (%i): %m
  7d808 Error while iterating over @bs in @i %i (%s): %m
  7d840 Error adjusting refcount for @a @b %b (@i %i): %m
  7d878 Pass 1C: Scanning directories for @is with @m @bs
  7d8b0 File %Q (@i #%i, mod time %IM) 
  7d8d0   has %r @m @b(s), shared with %N file(s):
  7d900 (There are %N @is containing @m @bs.)
  7d928 @m @bs already reassigned or cloned.
  7d950 Failed to optimize @x tree %p (%i): %m
  7d978 Internal error: max extent tree depth too large (%b; expected=%c).
  7d9c0 @i %i @x tree (at level %b) could be shorter.  
  7d9f0 @i %i @x tree (at level %b) could be narrower.  
  7da28 Pass 2: Checking @d structure
  7da48 @n @i number for '.' in @d @i %i.
  7da70 @E points to @i (%Di) located in a bad @b.
  7daa0 @E has illegal characters in its name.
  7dac8 First @e '%Dn' (@i=%Di) in @d @i %i (%p) @s '.'
  7db00 Second @e '%Dn' (@i=%Di) in @d @i %i @s '..'
  7db30 @i %i (%Q) has @n mode (%Im).
  7db50 @d @i %i, %B, offset %N: @d corrupted
  7db78 @d @i %i, %B, offset %N: filename too long
  7dba8 @d @i %i has an unallocated %B.  
  7dbd0 '.' @d @e in @d @i %i is not NULL terminated
  7dc00 '..' @d @e in @d @i %i is not NULL terminated
  7dc30 @i %i (%Q) is an @I character @v.
  7dc58 Internal error: couldn't find dir_info for %i.
  7dc88 @E has rec_len of %Dr, @s %N.
  7dca8 Error iterating over @d @bs: %m
  7dcd0 Error reading @d @b %b (@i %i): %m
  7dcf8 Error writing @d @b %b (@i %i): %m
  7dd20 @A new @d @b for @i %i (%s): %m
  7dd48 @d @e for '.' in %p (%i) is big.
  7dd70 Setting filetype for @E to %N.
  7dd90 @E has an incorrect filetype (was %Dt, @s %N).
  7ddc0 @f contains large files, but lacks LARGE_FILE flag in @S.
  7de00 @p @h %d: %B referenced twice
  7de20 @p @h %d: %B has bad min hash
  7de40 @p @h %d: %B has bad max hash
  7de60 @f has large directories, but lacks LARGE_DIR flag in @S.
  7dea0 @p @h %d (%q): bad @b number %b.
  7dec8 @p @h %d: %B has @n limit (%N)
  7dee8 @p @h %d: %B has @n count (%N)
  7df08 @p @h %d: %B has an unordered hash table
  7df38 @p @h %d: %B has @n depth (%N)
  7df58 @E has a non-unique filename.
  7df76 Rename to %s
  7df88 Duplicate @e '%Dn' found.
  7dfa2 	Marking %p (%i) to be rebuilt.
  7dfc8 @E references @i %Di in @g %g where _INODE_UNINIT is set.
  7e008 @E references @i %Di found in @g %g's unused inodes area.
  7e048 i_file_acl_hi @F %N, @s zero.
  7e068 @p @h %d: root node fails checksum.
  7e090 @p @h %d: internal node fails checksum.
  7e0c0 @d @i %i, %B, offset %N: @d has no checksum.
  7e0f0 @d @i %i, %B: @d passes checks but fails checksum.
  7e128 Inline @d @i %i size (%N) must be a multiple of 4.
  7e160 Fixing size of inline @d @i %i failed.
  7e188 Encrypted @E references unencrypted @i %Di.
  7e1b8 Encrypted @E references @i %Di, which has a different encryption policy.
  7e208 @E has illegal UTF-8 characters in its name.
  7e238 Duplicate filename @E found.  
  7e258 Pass 3: Checking @d connectivity
  7e280 '..' in %Q (%i) is %P (%j), @s %q (%d).
  7e2b0 Bad or non-existent /@l.  Cannot reconnect.
  7e2e0 Error while trying to find /@l: %m
  7e308 ext2fs_new_@b: %m while trying to create /@l @d
  7e340 ext2fs_new_@i: %m while trying to create /@l @d
  7e378 ext2fs_new_dir_@b: %m while creating new @d @b
  7e3a8 ext2fs_write_dir_@b: %m while writing the @d @b for /@l
  7e3e8 Error while adjusting @i count on @i %i
  7e418 Couldn't fix parent of @i %i: %m
  7e440 Couldn't fix parent of @i %i: Couldn't find parent @d @e
  7e480 Error creating root @d (%s): %m
  7e4a8 Error creating /@l @d (%s): %m
  7e4c8 Cannot allocate space for /@l.
  7e4e7 Place lost files in root directory instead
  7e518 Insufficient space to recover lost files!
  7e542 Move data off the @f and re-run e2fsck.
  7e570 Pass 3A: Optimizing directories
  7e598 Failed to create dirs_to_hash iterator: %m
  7e5c8 Failed to optimize directory %q (%d): %m
  7e5f8 Pass 4: Checking reference counts
  7e620 @i %i ref count is %Il, @s %N.  
  7e648 WARNING: PROGRAMMING BUG IN E2FSCK!
  7e66c 	OR SOME BONEHEAD (YOU) IS CHECKING A MOUNTED (LIVE) FILESYSTEM.
  7e6ad @i_link_info[%i] is %N, @i.i_links_count is %Il.  They @s the same!
  7e6f8 @a @i %i ref count is %N, @s %n. 
  7e720 @d exceeds max links, but no DIR_NLINK feature in @S.
  7e758 @d @i %i ref count set to overflow but could be exact value %N.  
  7e7a0 Pass 5: Checking @g summary information
  7e7d0 Padding at end of @i @B is not set. 
  7e7f8 Padding at end of @b @B is not set. 
  7e820 Free @is count wrong for @g #%g (%i, counted=%j).
  7e858 Directories count wrong for @g #%g (%i, counted=%j).
  7e890 Free @is count wrong (%i, counted=%j).
  7e8b8 Free @bs count wrong for @g #%g (%b, counted=%c).
  7e8f0 Free @bs count wrong (%b, counted=%c).
  7e918 PROGRAMMING ERROR: @f (#%N) @B endpoints (%b, %c) don't match calculated @B endpoints (%i, %j)
  7e978 Internal error: fudging end of bitmap (%N)
  7e9a8 Error copying in replacement @i @B: %m
  7e9d0 Error copying in replacement @b @B: %m
  7e9f8 @g %g @b(s) in use but @g is marked BLOCK_UNINIT
  7ea30 @g %g @i(s) in use but @g is marked INODE_UNINIT
  7ea68 @g %g @i @B does not match checksum.
  7ea90 @g %g @b @B does not match checksum.
  7eab8 Update quota info for quota type %N
  7eae0 Error setting @b @g checksum info: %m
  7eb08 Error writing file system info: %m
  7eb30 Error flushing writes to storage device: %m
  7eb60 Error writing quota info for quota type %N: %m
  7eb90 MULTIPLY-CLAIMED BLOCKS CLONED
  7ebb6 %.24s
  7ebbc %%D%c
  7ebc2 %*llu
  7ebc8 double indirect block
  7ebde triple indirect block
  7ebf4 translator block
  7ec05 block #
  7ec0d %lld
  7ec1a %*lld
  7ec20 user
  7ec25 project
  7ec2d unknown quota type
  7ec40 0x%0*x
  7ec47 0x%0*llx
  7ec50 %%%c
  7ec59 regular file
  7ec66 character device
  7ec77 block device
  7ec84 named pipe
  7ec8f socket
  7ec96 %%I%c
  7ec9c %.*s
  7eca5 <The NULL inode>
  7ecb6 <The bad blocks inode>
  7eccf <The user quota inode>
  7ece6 <The group quota inode>
  7ecfe <The boot loader inode>
  7ed16 <The group descriptor inode>
  7ed33 <The journal inode>
  7ed47 <Reserved inode 9>
  7ed5a <Reserved inode 10>
  7ed6e aextended attribute
  7ed82 Aerror allocating
  7ed94 bblock
  7ed9b Bbitmap
  7eda3 ccompress
  7edad ddirectory
  7edb8 Ddeleted
  7edc1 eentry
  7edc8 E@e '%Dn' in %p (%i)
  7eddd ffilesystem
  7ede9 Ffor @i %i (%Q) is
  7edfc ggroup
  7ee03 hHTREE @d @i
  7ee10 iinode
  7ee17 Iillegal
  7ee20 jjournal
  7ee29 llost+found
  7ee35 Lis a link
  7ee40 mmultiply-claimed
  7ee52 ninvalid
  7ee5b oorphaned
  7ee65 pproblem in
  7ee71 qquota
  7ee78 rroot @i
  7ee81 sshould be
  7ee8c Ssuper@b
  7ee95 uunattached
  7eea1 vdevice
  7eea9 xextent
  7eeb1 zzero-length
  7f108 unknown file type with mode 0%o
  7f128 <The undelete directory inode>
  7f148 Cconflicts with some other fs @b
  7f169 in move_quota_inode
  7f17d ext2fs_read_bitmaps
  7f191 ext2fs_write_new_inode
  7f1a8 JBD2: corrupted journal superblock
  7f1d0 JBD2: Failed to read block at offset %u
  7f200 JBD2: IO error %d recovering block %lu in log
  7f230 JBD2: IO error %d recovering block %ld in log
  7f260 Assertion failure in %s() at %s line %d: "%s"
  7f290 JBD2: Invalid checksum recovering data block %llu in log
  7f2d0 JBD2: Out of memory during recovery.
  7f2f8 JBD2: recovery pass %d ended at transaction %u, expected %u
  7f338 JBD2: error %d scanning journal
  7f359 JBD2: bad block at offset %u
  7f377 obh != NULL
  7f383 recovery.c
  7f390 do_one_pass
  7f39c list_empty(hash_list)
  7f3b2 revoke.c
  7f3bb !jbd2_revoke_record_cache
  7f3d5 !jbd2_revoke_table_cache
  7f3ee is_power_of_2(hash_size)
  7f408 journal->j_revoke_table[0] == NULL
  7f440 jbd2_journal_destroy_revoke_table
  7f470 jbd2_journal_init_revoke
  7f4a0 jbd2_journal_init_revoke_table_cache
  7f4e0 jbd2_journal_init_revoke_record_cache
  7f506 rehash_dir
  7f511 indexed_dir_slack_percentage
  7f52e Rebuilding directory
  7f543 Pass 3A
  7f54d %d%02d%02d
  7f558 %02d%02d%02d
  7f565 fork
  7f56a daemon
  7f571 log_dir_wait
  7f57e log_dir
  7f586 log_dir_fallback
  7f597 problem_log_filename
  7f700 Signal (%d) %s 
  7f710 (sent from pid %u) 
  7f724 si_code=%s 
  7f730 si code=%d 
  7f73c fault addr=%p
  7f74a CLD_EXITED
  7f755 CLD_KILLED
  7f760 CLD_DUMPED
  7f76b CLD_TRAPPED
  7f777 CLD_STOPPED
  7f783 CLD_CONTINUED
  7f791 BUS_ADRALN
  7f79c BUS_ADRERR
  7f7a7 BUS_OBJERR
  7f7b2 SEGV_MAPERR
  7f7be SEGV_ACCERR
  7f7ca FPE_INTDIV
  7f7d5 FPE_INTOVF
  7f7e0 FPE_FLTDIV
  7f7eb FPE_FLTOVF
  7f7f6 FPE_FLTUND
  7f801 FPE_FLTRES
  7f80c FPE_FLTINV
  7f817 FPE_FLTSUB
  7f822 ILL_ILLOPC
  7f82d ILL_ILLOPN
  7f838 ILL_ILLADR
  7f843 ILL_ILLTRP
  7f84e ILL_PRVOPC
  7f859 ILL_PRVREG
  7f864 ILL_COPROC
  7f86f ILL_BADSTK
  7f87a SI_ASYNCNL
  7f885 SI_TKILL
  7f88e SI_SIGIO
  7f897 SI_ASYNCIO
  7f8a2 SI_MESGQ
  7f8ab SI_TIMER
  7f8b4 SI_QUEUE
  7f8bd SI_USER
  7f8c5 SI_KERNEL
  7f8cf SIGHUP
  7f8d6 SIGINT
  7f8dd SIGQUIT
  7f8e5 SIGILL
  7f8ec SIGTRAP
  7f8f4 SIGABRT
  7f8fc SIGIOT
  7f903 SIGBUS
  7f90a SIGFPE
  7f911 SIGKILL
  7f919 SIGUSR1
  7f921 SIGSEGV
  7f929 SIGUSR2
  7f931 SIGPIPE
  7f939 SIGALRM
  7f941 SIGTERM
  7f949 SIGSTKFLT
  7f953 SIGCHLD
  7f95b SIGCONT
  7f963 SIGSTOP
  7f96b SIGTSTP
  7f973 SIGTTIN
  7f97b SIGTTOU
  7f983 SIGURG
  7f98a SIGXCPU
  7f992 SIGXFSZ
  7f99a SIGVTALRM
  7f9a4 SIGPROF
  7f9ac SIGWINCH
  7f9b5 SIGPOLL
  7f9bd SIGPWR
  7f9c4 SIGSYS
  7fa04 readahead bitmap
  7fa15 rebuild_extents
  7fa25 Rebuilding extents
  7fa38 Pass 1E
  7fa40 extent rebuild inode map
  7fa59 inodes_to_rebuild
  7fa70 Unhandled encryption policy version
  7fa98 Encrypted inodes processed out of order
  7fac0 mkquota.c
  7fad0 [ERROR] %s:%d:%s: Unable to allocate dquot
  7fb00 [QUOTA WARNING] Usage inconsistent for ID %u:actual (%lld, %lld) != expected (%lld, %lld)
  7fb60 [ERROR] %s:%d:%s: Cannot close quotafile: %s
  7fb90 [ERROR] %s:%d:%s: while opening inode scan. ret=%ld
  7fbc8 [ERROR] %s:%d:%s: while getting next inode. ret=%ld
  7fc00 [QUOTA WARNING] Missing quota entry ID %d
  7fc30 Couldn't allocate memory to parse quota options!
  7fc70 quota_compute_usage
  7fc84 get_dq
  7fc90 quota_release_context
  7fca6 	last mounted on %.*s on %s
  7fcc2 	last mounted on %s
  7fcd6 	created on %s
  7fce5 	last modified on %s
  7fcfa PTTYPE
  7fd01 Creating regular file %s
  7fd1b stat
  7fd20 LABEL
  7fd26 %s contains a %s file system
  7fd44 Could not open %s: %s
  7fd60 Found a %s partition table in %s
  7fd88 The file %s does not exist and no size was specified.
  7fdc1 The device apparently does not exist; did you specify it correctly?
  7fe08 %s is not a block special device.
  7fe30 %s contains a %s file system labelled '%s'
  7fe5c (root)
  7fe63 HOME
  7fe68 <default>
  7fe72 %s/%s
  7fe78 false
  7fe82 true
  7fe87 Profile version 0.0
  7fe9b Profile section not found
  7feb5 Profile relation not found
  7fed0 Missing open brace in profile
  7feee Bad magic value in profile_t
  7ff0b No more sections
  7ff1c No profile file open
  7ff31 Couldn't open profile file
  7ff4c Section already exists
  7ff63 Invalid boolean value
  7ff79 Invalid integer value
  7ff90 Bad magic value in profile_node
  7ffb0 Attempt to add a relation to node which is not a section
  7fff0 A profile section header has a non-zero value
  80020 Bad linked list in profile structures
  80048 Bad group level in profile structures
  80070 Bad parent pointer in profile structures
  800a0 Bad magic value in profile iterator
  800c8 Can't set value on section node
  800e8 Invalid argument passed to profile library
  80118 Attempt to modify read-only profile
  80140 Profile section header not at top level
  80168 Syntax error in profile section header
  80190 Syntax error in profile relation
  801b8 Extra closing brace in profile
  801d8 Bad magic value in profile_section_t
  80200 Iteration through all top level section not supported
  80238 Invalid profile_section object
  80258 Bad nameset passed to query routine
  80280 Bad magic value in profile_file_t
  802a8 Bad magic value in profile_file_data_t
  802cf quotaio.c
  802d9 unknown
  802e1 %s.%s
  802e7 aquota
  802f0 [ERROR] %s:%d:%s: ext2fs_file_llseek failed: %ld
  80328 [ERROR] %s:%d:%s: ext2fs_file_read failed: %ld
  80358 [ERROR] %s:%d:%s: ext2fs_file_write failed: %ld
  80390 [ERROR] %s:%d:%s: ex2fs_read_inode failed
  803c0 [ERROR] %s:%d:%s: ext2fs_write_new_inode failed: %ld
  803f8 [ERROR] %s:%d:%s: init_new_quota_inode failed
  80428 [ERROR] %s:%d:%s: ext2fs_file_open failed: %ld
  80458 [ERROR] %s:%d:%s: qh_ops->new_io failed
  80488 [ERROR] %s:%d:%s: ext2fs_file_open failed: %s
  804b8 [ERROR] %s:%d:%s: Unable to allocate quota handle
  804f0 [ERROR] %s:%d:%s: qh_ops->check_file failed
  80520 [ERROR] %s:%d:%s: qh_ops->init_io failed
  80550 [ERROR] %s:%d:%s: Failed to allocate dquot
  80580 get_empty_dquot
  80590 quota_inode_init_new
  805b0 quota_file_create
  805d0 quota_write_nomount
  805f0 quota_read_nomount
  80610 quota_file_open
  80620 quotaio_v2.c
  80630 [ERROR] %s:%d:%s: Your quota file is stored in wrong endianity
  80670 [ERROR] %s:%d:%s: Not Implemented.
  80698 [ERROR] %s:%d:%s: Quota inode %u corrupted: file size %llu; dqi_blocks %u
  806e8 [ERROR] %s:%d:%s: Quota inode %u corrupted: free_blk %u; dqi_blocks %u
  80730 [ERROR] %s:%d:%s: Quota inode %u corrupted: free_entry %u; dqi_blocks %u
  80780 v2_check_file
  80790 v2_init_io
  807a0 v2_report
  807aa quotaio_tree.c
  807c0 [ERROR] %s:%d:%s: Cannot read block %u: %s
  807f0 [ERROR] %s:%d:%s: Cannot write block (%u): %s
  80820 [ERROR] %s:%d:%s: Failed to allocate dqbuf
  80850 [ERROR] %s:%d:%s: Cannot allocate new quota block (out of disk space).
  80898 [ERROR] %s:%d:%s: Illegal reference (%u >= %u) in %s quota file
  808e0 [ERROR] %s:%d:%s: find_free_dqentry(): Data block full unexpectedly.
  80928 [ERROR] %s:%d:%s: Inserting already present quota entry (block %u).
  80970 [ERROR] %s:%d:%s: Cannot write quota (id %u): %s
  809a8 [ERROR] %s:%d:%s: Quota structure has offset to other block (%u) than it should (%u).
  80a00 [ERROR] %s:%d:%s: Quota for id %u referenced but not present.
  80a40 [ERROR] %s:%d:%s: Quota write failed (id %u): %s
  80a78 [ERROR] %s:%d:%s: Cannot read quota structure for id %u: %s
  80ac0 check_reference
  80ad0 find_block_dqentry
  80af0 qtree_read_dquot
  80b08 free_dqentry
  80b18 write_blk
  80b30 find_free_dqentry
  80b48 read_blk
  80b58 get_free_dqblk
  80b68 getdqbuf
  80b78 do_insert_tree
  80b88 dq_insert_tree
  80ba0 qtree_write_dquot
  80bb2 Test_io: set_option(%s, %s) 
  80bcf not implemented
  80be0 Test_io: flush() returned %s
  80bfe TEST_IO_LOGFILE
  80c0e TEST_IO_READ_ABORT
  80c21 TEST_IO_WRITE_ABORT
  80c35 %04x: 
  80c3c %02x%c
  80c43 Test I/O Manager
  80c58 Test_io: zeroout(%llu, %llu) returned %s
  80c88 Test_io: set_blksize(%d) returned %s
  80cb0 Test_io: readahead(%llu, %llu) returned %s
  80ce0 Test_io: discard(%llu, %llu) returned %s
  80d10 Aborting due to I/O to block %lu
  80d38 Test_io: write_byte(%lu, %d) returned %s
  80d68 Contents of block %lu, checksum %08lu: 
  80d98 Test_io: read_blk64(%llu, %d) returned %s
  80dc8 Test_io: read_blk(%lu, %d) returned %s
  80df0 Test_io: write_blk(%lu, %d) returned %s
  80e20 Test_io: write_blk64(%llu, %d) returned %s
  80e4c EXT2FS Library version 1.46.5
  80e6a Filesystem revision too high
  80e87 Can't read group descriptors
  80ea4 Can't write group descriptors
  80ec2 Can't write an inode bitmap
  80ede Can't read an inode bitmap
  80ef9 Can't write a block bitmap
  80f14 Can't read a block bitmap
  80f2e Can't write an inode table
  80f49 Can't read an inode table
  80f63 Can't read next inode
  80f79 EXT2 directory corrupted
  80f92 Inode bitmap not loaded
  80faa Block bitmap not loaded
  80fc2 Illegal inode number
  80fd7 Illegal block number
  80fec Illegal indirect block found
  81009 Memory allocation failed
  81022 Ext2 inode is not a directory
  81040 Too many references in table
  8105d File not found by ext2_lookup
  8107b File open read-only
  8108f Ext2 directory already exists
  810ad User cancel requested
  810c3 Ext2 file too big
  810d5 Journal superblock not found
  810f2 Unsupported journal version
  8110e Journal not found
  81120 Directory hash unsupported
  8113b E2image snapshot not in use
  81157 Resize inode is corrupt
  8116f TDB: Success
  8117c TDB: Corrupt database
  81192 TDB: IO Error
  811a0 TDB: Locking error
  811b3 TDB: Out of memory
  811c6 TDB: Record exists
  811d9 TDB: Invalid parameter
  811f0 TDB: Record does not exist
  8120b TDB: Write not permitted
  81224 Corrupt extent header
  8123a Corrupt extent index
  8124f Corrupt extent
  8125e No free space in extent map
  8127a Inode does not use extents
  81295 No 'next' extent
  812a6 No 'previous' extent
  812bb No 'up' extent
  812ca No 'down' extent
  812db No current node
  812eb Extent not found
  812fc Extent length is invalid
  81315 MMP: invalid magic number
  8132f MMP: device currently active
  8134c MMP: e2fsck being run
  81362 MMP: filesystem still in use
  8137f Unknown checksum algorithm
  8139a Ext2 file already exists
  813b3 No free space in inline data
  813d0 Journal flags inconsistent
  813eb Undo file corrupt
  813fd File system is corrupted
  81416 Inode is corrupted
  81429 Group descriptors not loaded
  81448 Wrong magic number for ext2_filsys structure
  81478 Wrong magic number for badblocks_list structure
  814a8 Wrong magic number for badblocks_iterate structure
  814e0 Wrong magic number for inode_scan structure
  81510 Wrong magic number for io_channel structure
  81540 Wrong magic number for unix io_channel structure
  81578 Wrong magic number for io_manager structure
  815a8 Wrong magic number for block_bitmap structure
  815d8 Wrong magic number for inode_bitmap structure
  81608 Wrong magic number for generic_bitmap structure
  81638 Wrong magic number for test io_channel structure
  81670 Wrong magic number for directory block list structure
  816a8 Wrong magic number for icount structure
  816d0 Wrong magic number for Powerquest io_channel structure
  81708 Wrong magic number for ext2 file structure
  81738 Wrong magic number for Ext2 Image Header
  81768 Wrong magic number for inode io_channel structure
  817a0 Wrong magic number for ext4 extent handle
  817d0 Bad magic number in super-block
  817f0 Attempt to write to filesystem opened read-only
  81820 Corrupt group descriptor: bad block for block bitmap
  81858 Corrupt group descriptor: bad block for inode bitmap
  81890 Corrupt group descriptor: bad block for inode table
  818c8 Filesystem has unexpected block size
  818f0 Attempt to read block from filesystem resulted in short read
  81930 Attempt to write block to filesystem resulted in short write
  81970 No free space in the directory
  81990 Internal error in ext2fs_expand_dir
  819b8 Not enough space to build proposed filesystem
  819e8 Illegal block number passed to ext2fs_mark_block_bitmap
  81a20 Illegal block number passed to ext2fs_unmark_block_bitmap
  81a60 Illegal block number passed to ext2fs_test_block_bitmap
  81a98 Illegal inode number passed to ext2fs_mark_inode_bitmap
  81ad0 Illegal inode number passed to ext2fs_unmark_inode_bitmap
  81b10 Illegal inode number passed to ext2fs_test_inode_bitmap
  81b48 Attempt to fudge end of block bitmap past the real end
  81b80 Attempt to fudge end of inode bitmap past the real end
  81bb8 Illegal doubly indirect block found
  81be0 Illegal triply indirect block found
  81c08 Block bitmaps are not the same
  81c28 Inode bitmaps are not the same
  81c48 Illegal or malformed device name
  81c70 A block group is missing an inode table
  81c98 The ext2 superblock is corrupt
  81cb8 Illegal generic bit number passed to ext2fs_mark_generic_bitmap
  81cf8 Illegal generic bit number passed to ext2fs_unmark_generic_bitmap
  81d40 Illegal generic bit number passed to ext2fs_test_generic_bitmap
  81d80 Too many symbolic links encountered.
  81da8 The callback function will not handle this case
  81dd8 The inode is from a bad block in the inode table
  81e10 Filesystem has unsupported feature(s)
  81e38 Filesystem has unsupported read-only feature(s)
  81e68 IO Channel failed to seek on read or write
  81e98 Invalid argument passed to ext2 library
  81ec0 Could not allocate block in ext2 filesystem
  81ef0 Could not allocate inode in ext2 filesystem
  81f20 Ext2 directory block not found
  81f40 Unimplemented ext2 library function
  81f68 Supplied journal device not a block device
  81f98 Journal must be at least 1024 blocks
  81fc0 Error loading external journal
  81fe0 Illegal extended attribute block number
  82008 Cannot create filesystem with requested number of inodes
  82048 Too many reserved group descriptor blocks
  82078 Tried to set block bmap with missing indirect block
  820b0 TDB: Lock exists on other keys
  820d0 Ext2fs directory block list is empty
  820f8 Attempt to modify a block mapping via a read-only block iterator
  82140 Wrong magic number for ext4 extent saved path
  82170 Wrong magic number for 64-bit generic bitmap
  821a0 Wrong magic number for 64-bit block bitmap
  821d0 Wrong magic number for 64-bit inode bitmap
  82200 Wrong magic number --- RESERVED_13
  82228 Wrong magic number --- RESERVED_14
  82250 Wrong magic number --- RESERVED_15
  82278 Wrong magic number --- RESERVED_16
  822a0 Wrong magic number --- RESERVED_17
  822c8 Wrong magic number --- RESERVED_18
  822f0 Wrong magic number --- RESERVED_19
  82318 Ext2fs operation not supported
  82338 No room to insert extent in node
  82360 Splitting would result in empty node
  82388 Operation not supported for inodes containing extents
  823c0 I/O Channel does not support 64-bit block numbers
  823f8 Can't check if filesystem is mounted due to missing mtab file
  82438 Filesystem too large to use legacy bitmaps
  82468 MMP: block number beyond filesystem range
  82498 MMP: undergoing an unknown operation
  824c0 MMP: open with O_DIRECT failed
  824e0 Block group descriptor size incorrect
  82508 Inode checksum does not match inode
  82530 Inode bitmap checksum does not match bitmap
  82560 Extent block checksum does not match extent block
  82598 Directory block does not have space for checksum
  825d0 Directory block checksum does not match directory block
  82608 Extended attribute block checksum does not match block
  82640 Superblock checksum does not match superblock
  82670 MMP block checksum does not match
  82698 Block bitmap checksum does not match bitmap
  826c8 Cannot iterate data blocks of an inode containing inline data
  82708 Extended attribute has an invalid name length
  82738 Extended attribute has an invalid value length
  82768 Extended attribute has an incorrect hash
  82798 Extended attribute block has a bad header
  827c8 Extended attribute key not found
  827f0 Insufficient space to store extended attribute data
  82828 Filesystem is missing ext_attr or inline_data feature
  82860 Inode doesn't have inline data
  82880 No block for an inode with inline data
  828a8 Wrong magic number for extended attribute structure
  828e0 Inode seems to contain garbage
  82900 Extended attribute has an invalid value offset
  82930 Wrong undo file for this filesystem
  82958 Bad CRC detected in file system
  82978 The journal superblock is corrupt
  829a0 Inode containing extended attribute value is corrupted
  829d8 The internal ext2_filsys data structure appears to be corrupted
  82a18 Illegal inode number: %lu
  82a32 ext2fs_inode_alloc_stats2
  82a4c Illegal block number: %lu
  82a66 ext2fs_block_alloc_stats
  82a80 Illegal block range: %llu (%u) 
  82aa0 ext2fs_block_alloc_stats_range
  82abf #%lu for %s
  82acb #%lu
  82ad0 check_desc map
  82c2c ')uB
  82cc6 *	5|z
  82cf2 lEd/
  82d65 6 PQ
  82d6a pCRF
  82e43 Yg:a
  82e4d JZJ{.
  82ed5 #FLR
  82edb _QS}
  82ef6 (]2Q
  82f25 ig,o
  82f64 u{)l
  83007 qR5FE%
  83043 ]JldN
  8305a 	4x=
  8308b :'No)b
  8314a W~Y`
  83195 #tDq
  831ee 30!]^JV
  83235 49fN
  83273 5T&w&
  832e9 RoOs
  83354 +ulsX
  83404 b,uZ
  834bc .bs"
  834e6 f.N%H
  8356b %$LM
  83603 t![R
  8360a |;,	=
  83687 0F`8
  836b2 zC`G;
  836f1 1"{K
  83707 +g@#I
  83780 mwa!
  83791 FCZ&
  837ad ,c\E
  837ca bwiO'
  837d5 ]bn"
  839e4 `<C$Y
  83a12 `tun%
  83a49 gAY:
  83a56 A@qVc"
  83ace !S{a!J
  83b3d oT'BjEJ
  83c1a Qb{o@Z}
  83db6 |"0`Oj
  83e62 [B	eJz
  83e9e J/vky
  83f24 '[</
  83f3e EF!(
  83f44 8C:O
  8405e G(fM
  840d4 )9?v
  840f7 Ab qu{KA
  84117 !}8w
  84126 43+'
  8413c E{MZ
  84146 2S4?
  8415c ZcK:[
  84267 xsZtLj1D
  84288 lBr,u)B
  842d6 7j%E
  8432e ^$w?
  8434d rsj$
  84381 ~vs&Ru
  84418 hf|A
  8447b 2N4	Z
  844d1 Fz0+jyXs
  844e8 dWh%
  844ed {kM%
  845a1 wnT'[m<
  84638 iodf
  846e4 '}<IN
  846f6 !h#xe
  84758 Mu(uj
  84780 Ca;Od
  847bb :)i/s
  847e6 <S|1x
  847f3 ;x4!r
  84849 <5N5A	
  84891 (&t;U
  848ac v 2Hr%k
  848e6 =}*ly
  848f4 .i \G
  84948 Da4`c
  84990 Ju'Zm
  849ab / }3f$xj
  849e3 .q =g
  849f6  Fu%d
  84a3d Q.P8PL
  84a59 ()[<U
  84a81 <:a2A
  84a97 	6D_
  84b5a {zt^f
  84be2 pw0Gm
  84c52 0cIZ-
  84d0a 68BG+
  84d1c QC]S%
  84d3a v,;Zk
  84f01 HCRXQ
  84f6b )RHi
  84fe0 AFlL
  85054 LbTx>
  8509d bgBq
  850e7 D"~F
  850f8 gZg>
  85164 p6/b
  85219 TH ~M
  8524c +83F
  85264 1pC.C
  85273 [tTb
  852cf `<T{
  8536c 9|ei<w"
  85386 X_6a
  853dc -Q{=v+!
  853fc s fUx
  85414 ~T[c|=
  85424 jyE7h
  8546b .OWD
  8547a Z2H5
  854a2 yPQl
  854db z[zZ
  8578b "stl
  857c3 X8zi
  8587b x'x(
  8593a tbMp
  8596a S5,x
  85995 }5Tu
  859a2 VOgv
  859dc ^s0.w
  859fc kwS#
  85a02 5BRr
  85a34  yVY@
  85b64 Jhf"
  85bb8 2YC:{T$
  85bc5 So(SD
  85bfd )(JG#
  85cd8 uzGb<w 
  85d58 }AC/4L$
  85de4 BSbo
  85e38 :bGwso 
  85e45 hke[
  85e63 MA6c
  85fc5 k%V1
  86018 S5WbH
  860bb LO^r4
  8611c =Ss{
  861b8 !8V-:
  861e0 uN)anf$
  86336 ".A@
  863bf #]o~
  8640a R-6H:<
  864a8 $p,(k'D9
  86510 gu(p("@a
  86566 t[{Z
  865b2 VuuM>d
  865cd F(SI#-
  865f9 jz]Q=
  866a5 Yz~	
  866ee e^jFn
  86715 kok	
  8675e q4_pR!
  867a5 	) E
  867bf +&$(
  867d0 LbFK
  867fa sI8D
  86800 jly|1
  8684a g#+V
  86875 wD6<
  8687a !hg4
  868c5 eP\/
  86915 k:Xp
  86925 y.2c
  8692a Kl8:
  8696e bLL6i
  869fa &zAD
  86a01 l,OH
  86a31 ~8%[
  86af8 system.posix_acl_default
  86b11 system.posix_acl_access
  86b29 gnu.
  86b2e system.richacl
  86b3d security.
  86b47 trusted.
  86b50 system.
  86b58 user.
  86b98 test_bitmap(%lu)
  86ba9 mark_bitmap(%lu)
  86bba get_bitmap_start
  86bcb get_bitmap_end
  86bda clear_generic_bitmap
  86d00 ext2fs_clear_generic_bitmap
  86d20 ext2fs_get_generic_bitmap_end
  86d40 ext2fs_get_generic_bitmap_start
  86d60 ext2fs_unmark_generic_bitmap
  86d80 ext2fs_mark_generic_bitmap
  86da0 ext2fs_test_generic_bitmap
  86dbb gettimeofday
  86dc9 [+] %s bitmap (type %d)
  86de2 #%llu for %s
  86def #%llu
  86df5 E2FSPROGS_BITMAP_STATS
  86e0c called %s with 64-bit bitmap
  86e29 converted cluster bitmap
  86e48 =================================================
  86e80 called %s with 64-bit bitmap for %s
  86ea4 <%u>/<%u>
  86eb0 %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x
  86ee8 %s: list[%d].ino=%u, list[%d].ino=%u
  86f0e icount_inc
  86f19 %s/%s-icount-XXXXXX
  86f2d bad icount
  86f38 %s: count > size
  86f4a E2FSPROGS_FAKE_TIME
  86f70 block bitmap forinode bitmap for/proc/swaps
  86f9c Filename	
  86fa6 EXT2FS_NO_MTAB_OK
  86fb8 /.ismount-test-file
  86fcf /proc/mounts
  86fdc /etc/mtab
  86fe6 EXT2FS_PRETEND_RO_MOUNT
  86ffe EXT2FS_PRETEND_ROOTFS
  87014 EXT2FS_PRETEND_RW_MOUNT
  8702c <swap>
  87033 /.journal
  8a6b8 B]c-]
  96c5c cache=off
  96c66 cache=on
  96c8d D7q/;M
  96d22 +Yo,
  96d8a &\8!
  96df0 * qW
  96e14 LwH'
  96ee7 L*~e
  96efe Dltdb_transaction_lock: failed to get transaction lock
  96f38 tdb_rec_read bad magic 0x%x at offset=%d
  96f68 tdb_rec_free_read non-free magic 0x%x at offset=%d - fixing
  96fa8 tdb_rec_free_read bad magic 0x%x at offset=%d
  96fd8 tdb_lock: invalid list %d for ltype=%d
  97000 tdb_lock: lck->count == 0 for list %d
  97028 tdb_lock failed on list %d ltype=%d (%s)
  97058 tdb_unlock: list %d invalid (%d)
  97080 tdb_unlock: An error occurred unlocking!
  970b0 transaction_read: failed at off=%d len=%d
  970e0 tdb_alloc_read malloc failed len=%d (%s)
  97110 transaction_write: failed at off=%d len=%d
  97140 tdb_brlock failed (fd=%d) at offset %d rw_type=%d lck_type=%d len=%d
  97188 tdb_transaction: fsync failed
  971a8 tdb_transaction: msync failed - %s
  971d0 tdb_mmap failed for size %d (%s)
  971f8 ERROR: failed to read record at %u
  97220  rec: hash=%d offset=0x%08x next=0x%08x rec_len=%d key_len=%d data_len=%d full_hash=0x%x magic=0x%x
  97288 ERROR: failed to read tailer at %u
  972b0 ERROR: tailer does not match record! tailer=%u totalsize=%u
  972f0 tdb_oob len %d beyond internal malloc size %d
  97320 tdb_oob len %d beyond eof at %d
  97348 tdb_write failed at %d len=%d (%s)
  97370 tdb_read failed at %d len=%d ret=%d (%s) map_size=%d
  973a8 expand_file to %d failed (%s)
  973c8 expand_file write of %d failed (%s)
  973f0 tdb_brlock_upgrade failed at offset %d
  97418 remove_from_freelist: not on list at off=%d
  97448 tdb_free: update_tailer failed!
  97470 tdb_free: right read failed at %u
  97498 tdb_free: right free failed at %u
  974c0 tdb_free: left offset read failed at %u
  974f0 tdb_free: left read failed at %u (%u)
  97518 tdb_free: left free failed at %u
  97540 tdb_free: update_tailer failed at %u
  97568 tdb_free record write failed at offset=%d
  97598 tdb_recovery_allocate: failed to read recovery head
  975d0 tdb_recovery_allocate: failed to read recovery record
  97608 tdb_recovery_allocate: failed to free previous recovery area
  97648 tdb_recovery_allocate: failed to create recovery area
  97680 tdb_recovery_allocate: failed to write recovery head
  976b8 tdb_transaction_setup_recovery: transaction data over new region boundary
  97708 tdb_transaction_setup_recovery: failed to write recovery data
  97748 tdb_transaction_setup_recovery: failed to write recovery magic
  97788 tdb_next_lock: loop detected.
  977a8 tdb_next_lock: On error unlock failed!
  977d0 tdb_traverse: key.dptr == NULL and unlock_record failed!
  97810 tdb_traverse: unlock_record failed!
  97838 tdb_transaction_start: cannot start a transaction on a read-only or internal db
  97890 tdb_transaction_start: nesting %d
  978b8 tdb_transaction_start: cannot start a transaction with locks held
  97900 tdb_transaction_start: cannot start a transaction within a traverse
  97948 tdb_transaction_start: failed to get hash locks
  97980 tdb_transaction_start: failed to read hash heads
  979b8 tdb_transaction_start: failed to prime hash table
  979f0 tdb_transaction_cancel: no transaction
  97a18 tdb_transaction_recover: failed to read recovery head
  97a50 tdb_transaction_recover: failed to read recovery record
  97a90 tdb_transaction_recover: attempt to recover read only database
  97ad0 tdb_transaction_recover: failed to allocate recovery data
  97b10 tdb_transaction_recover: failed to read recovery data
  97b48 tdb_transaction_recover: failed to recover %d bytes at offset %d
  97b90 tdb_transaction_recover: failed to sync recovery
  97bc8 tdb_transaction_recover: failed to remove recovery head
  97c08 tdb_transaction_recover: failed to remove recovery magic
  97c48 tdb_transaction_recover: failed to reduce to recovery size
  97c88 tdb_transaction_recover: failed to sync2 recovery
  97cc0 tdb_transaction_recover: recovered %d byte database
  97cf8 tdb_transaction_commit: no transaction
  97d20 tdb_transaction_commit: transaction error pending
  97d58 tdb_transaction_commit: locks pending on commit
  97d90 tdb_transaction_start: failed to upgrade hash locks
  97dc8 tdb_transaction_commit: failed to get global lock
  97e00 tdb_transaction_commit: failed to setup recovery data
  97e38 tdb_transaction_commit: expansion failed
  97e68 tdb_transaction_commit: write failed during commit
  97ea0 tdb_transaction_commit: write failed
  97ec8 tdb_transaction_commit: failed to remove recovery magic
  97f08 tdb_firstkey: error occurred while tdb_unlocking!
  97f40 tdb_nextkey: lock_record failed (%s)!
  97f68 tdb_nextkey: WARNING tdb_unlock failed!
  97f98 bad magic 0x%08x in free list
  97fb8 entry offset=[0x%08x], rec.rec_len = [0x%08x (%d)] (end = 0x%08x)
  98000 total rec_len = [0x%08x (%d)]
  98020 tdb_delete: WARNING tdb_unlock failed!
  98048 tdb_open_ex: can't open tdb %s write-only
  98078 tdb_open_ex: tdb_new_database failed!
  980a0 tdb_open_ex: could not open file %s: %s
  980d0 tdb_open_ex: failed to get global lock on %s: %s
  98108 tdb_open_ex: failed to truncate %s: %s
  98130 tdb_open_ex: spinlocks no longer supported
  98160 tdb_open_ex: %s (%d,%d) is already open in this process
  981a0 tdb_open_ex: failed to take ACTIVE_LOCK on %s: %s
  981d8 tdb_open_ex: failed to close tdb->fd on error!
  98208 tdb_reopen: reopen not allowed with locks held
  98238 tdb_reopen: reopen not allowed inside a transaction
  98270 tdb_reopen: munmap failed (%s)
  98290 tdb_reopen: WARNING closing tdb->fd failed!
  982c0 tdb_reopen: failed to obtain active lock
  982f0 tdb_reopen: fstat failed (%s)
  98310 tdb_reopen: file dev/inode has changed!
  98339 tdb_lockall failed (%s)
  98352 tdb_unlockall failed (%s)
  9836d tdb_unlock: count is 0
  98385 TDB file
  9838f hash=%d
  98398 lock failed in tdb_expand
  983b3 Invalid error code
  983c6 freelist:
  983d1 freelist top=[0x%08x]
  983e8 flval
  983ee tdb_reopen: open failed (%s)
  9840c Lock exists on other keys
  98426 write not permitted
  98450 undo block map
  9845f tdb_data_size
  9846d offset
  98474 UNDO_IO_SIMULATE_UNFINISHED
  98490 while force-closing undo file
  984ae E2UNDO02
  984b7 Undo I/O Manager
  984c8 UNIX_IO_NOZEROOUT
  984da UNIX_IO_FORCE_BOUNCE
  984ef Unix fd I/O Manager
  98503 Unix I/O Manager
  98518 %16llu Bytes used by bitarray
  98537 %16llu extents (%llu bytes)
  98554 %16llu bits minimum size
  98570 %16llu bits maximum size
  98589 %16llu bits average size
  985a8 %16llu bits set in bitmap (out of %llu)
  985d8 %16.4lf memory / bitmap bit memory ratio (bitarray = 1)
  9881e @@COMERR_DEBUG_FILE
  98832 COMERR_DEBUG
  9883f /dev/tty
  98848 add_error_table: %s (0x%p)
  98868 Couldn't set FD_CLOEXEC on debug FILE: %s
  98898 remove_error_table: %s (0x%p)
  988b8 remove_error_table FAILED: %s (0x%p)
  988e0 ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_
  98920 FEATURE_%c%d
  9892d FEATURE_
  98936 clear
  9893c journal_checksum
  9894d journal_incompat_revoke
  98965 journal_64bit
  98973 journal_async_commit
  98988 journal_checksum_v2
  9899c journal_checksum_v3
  989b0 dir_prealloc
  989bd has_journal
  989c9 imagic_inodes
  989d7 dir_index
  989e1 resize_inode
  989ee lazy_bg
  989f6 snapshot_bitmap
  98a06 sparse_super2
  98a14 fast_commit
  98a20 stable_inodes
  98a2e sparse_super
  98a3b large_file
  98a46 huge_file
  98a50 uninit_bg
  98a5a uninit_groups
  98a68 dir_nlink
  98a72 extra_isize
  98a7e bigalloc
  98a87 metadata_csum
  98a95 replica
  98a9d shared_blocks
  98aab verity
  98ab2 compression
  98abe needs_recovery
  98acd journal_dev
  98ad9 meta_bg
  98ae5 flex_bg
  98aed dirdata
  98af5 metadata_csum_seed
  98b08 large_dir
  98b12 inline_data
  98b1e encrypt
  98b26 casefold
  98b2f fname_encoding
  98b3e CIR<none>
  9c1e7 :*3$"
  b5f90 GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
  b5fbe .shstrtab
  b5fc8 .interp
  b5fd0 .note.gnu.property
  b5fe3 .note.gnu.build-id
  b5ff6 .note.ABI-tag
  b6004 .gnu.hash
  b600e .dynsym
  b6016 .dynstr
  b601e .gnu.version
  b602b .gnu.version_r
  b603a .rela.dyn
  b6044 .rela.plt
  b604e .init
  b6054 .plt.got
  b605d .plt.sec
  b6066 .text
  b606c .fini
  b6072 .rodata
  b607a .eh_frame_hdr
  b6088 .eh_frame
  b6092 .tbss
  b6098 .init_array
  b60a4 .fini_array
  b60b0 .data.rel.ro
  b60bd .dynamic
  b60c6 .data
  b60cc .bss
  b60d1 .comment

exec
/bin/bash -lc 'nm -D -n ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
                 w _ITM_deregisterTMCloneTable
                 w _ITM_registerTMCloneTable
                 U __ctype_b_loc@GLIBC_2.3
                 U __ctype_toupper_loc@GLIBC_2.3
                 U __cxa_atexit@GLIBC_2.2.5
                 w __cxa_finalize@GLIBC_2.2.5
                 U __errno_location@GLIBC_2.2.5
                 U __fprintf_chk@GLIBC_2.3.4
                 w __gmon_start__
                 U __isoc99_fscanf@GLIBC_2.7
                 U __isoc99_sscanf@GLIBC_2.7
                 U __libc_start_main@GLIBC_2.34
                 U __longjmp_chk@GLIBC_2.11
                 U __memcpy_chk@GLIBC_2.3.4
                 U __open64_2@GLIBC_2.7
                 U __open_2@GLIBC_2.7
                 U __printf_chk@GLIBC_2.3.4
                 U __snprintf_chk@GLIBC_2.3.4
                 U __sprintf_chk@GLIBC_2.3.4
                 U __stack_chk_fail@GLIBC_2.4
                 U __strcat_chk@GLIBC_2.3.4
                 U __strcpy_chk@GLIBC_2.3.4
                 U __vfprintf_chk@GLIBC_2.3.4
                 U __vprintf_chk@GLIBC_2.3.4
                 U __xpg_basename@GLIBC_2.2.5
                 U _setjmp@GLIBC_2.2.5
                 U abort@GLIBC_2.2.5
                 U access@GLIBC_2.2.5
                 U asctime@GLIBC_2.2.5
                 U atoi@GLIBC_2.2.5
                 U backtrace@GLIBC_2.2.5
                 U backtrace_symbols_fd@GLIBC_2.2.5
                 U bindtextdomain@GLIBC_2.2.5
                 U blkid_devno_to_devname@BLKID_1.0
                 U blkid_do_fullprobe@BLKID_2.17
                 U blkid_free_probe@BLKID_2.15
                 U blkid_get_cache@BLKID_1.0
                 U blkid_get_devname@BLKID_1.0
                 U blkid_get_tag_value@BLKID_1.0
                 U blkid_new_probe_from_filename@BLKID_2.17
                 U blkid_probe_enable_partitions@BLKID_2.17
                 U blkid_probe_enable_superblocks@BLKID_2.17
                 U blkid_probe_lookup_value@BLKID_2.15
                 U blkid_put_cache@BLKID_1.0
                 U calloc@GLIBC_2.2.5
                 U close@GLIBC_2.2.5
                 U closedir@GLIBC_2.2.5
                 U ctime@GLIBC_2.2.5
                 U daemon@GLIBC_2.2.5
                 U dcgettext@GLIBC_2.2.5
                 U dcngettext@GLIBC_2.2.5
                 U dup@GLIBC_2.2.5
                 U endmntent@GLIBC_2.2.5
                 U exit@GLIBC_2.2.5
                 U fallocate64@GLIBC_2.10
                 U fclose@GLIBC_2.2.5
                 U fcntl@GLIBC_2.2.5
                 U fcntl64@GLIBC_2.28
                 U fdopen@GLIBC_2.2.5
                 U feof@GLIBC_2.2.5
                 U fflush@GLIBC_2.2.5
                 U fgets@GLIBC_2.2.5
                 U fileno@GLIBC_2.2.5
                 U fopen@GLIBC_2.2.5
                 U fork@GLIBC_2.2.5
                 U fputc@GLIBC_2.2.5
                 U fputs@GLIBC_2.2.5
                 U free@GLIBC_2.2.5
                 U fstat@GLIBC_2.33
                 U fstat64@GLIBC_2.33
                 U fsync@GLIBC_2.2.5
                 U ftruncate@GLIBC_2.2.5
                 U ftruncate64@GLIBC_2.2.5
                 U getegid@GLIBC_2.2.5
                 U getenv@GLIBC_2.2.5
                 U geteuid@GLIBC_2.2.5
                 U getgid@GLIBC_2.2.5
                 U gethostname@GLIBC_2.2.5
                 U getmntent@GLIBC_2.2.5
                 U getopt@GLIBC_2.2.5
                 U getpid@GLIBC_2.2.5
                 U getpwuid_r@GLIBC_2.2.5
                 U getrlimit64@GLIBC_2.2.5
                 U getrusage@GLIBC_2.2.5
                 U gettext@GLIBC_2.2.5
                 U gettimeofday@GLIBC_2.2.5
                 U getuid@GLIBC_2.2.5
                 U gmtime_r@GLIBC_2.2.5
                 U gnu_dev_major@GLIBC_2.3.3
                 U hasmntopt@GLIBC_2.2.5
                 U ioctl@GLIBC_2.2.5
                 U isatty@GLIBC_2.2.5
                 U localtime@GLIBC_2.2.5
                 U localtime_r@GLIBC_2.2.5
                 U lseek@GLIBC_2.2.5
                 U lseek64@GLIBC_2.2.5
                 U mallinfo@GLIBC_2.2.5
                 U malloc@GLIBC_2.2.5
                 U memcmp@GLIBC_2.2.5
                 U memcpy@GLIBC_2.14
                 U memmove@GLIBC_2.2.5
                 U memset@GLIBC_2.2.5
                 U mkstemp@GLIBC_2.2.5
                 U mmap@GLIBC_2.2.5
                 U msync@GLIBC_2.2.5
                 U munmap@GLIBC_2.2.5
                 U open@GLIBC_2.2.5
                 U open64@GLIBC_2.2.5
                 U opendir@GLIBC_2.2.5
                 U pclose@GLIBC_2.2.5
                 U perror@GLIBC_2.2.5
                 U pipe@GLIBC_2.2.5
                 U popen@GLIBC_2.2.5
                 U posix_fadvise64@GLIBC_2.2.5
                 U posix_memalign@GLIBC_2.2.5
                 U prctl@GLIBC_2.2.5
                 U pread@GLIBC_2.2.5
                 U pread64@GLIBC_2.2.5
                 U pthread_attr_destroy@GLIBC_2.2.5
                 U pthread_attr_init@GLIBC_2.2.5
                 U pthread_create@GLIBC_2.34
                 U pthread_join@GLIBC_2.34
                 U pthread_mutex_destroy@GLIBC_2.2.5
                 U pthread_mutex_init@GLIBC_2.2.5
                 U pthread_mutex_lock@GLIBC_2.2.5
                 U pthread_mutex_unlock@GLIBC_2.2.5
                 U putenv@GLIBC_2.2.5
                 U puts@GLIBC_2.2.5
                 U pwrite@GLIBC_2.2.5
                 U pwrite64@GLIBC_2.2.5
                 U qsort@GLIBC_2.2.5
                 U random@GLIBC_2.2.5
                 U read@GLIBC_2.2.5
                 U readdir@GLIBC_2.2.5
                 U realloc@GLIBC_2.2.5
                 U sbrk@GLIBC_2.2.5
                 U secure_getenv@GLIBC_2.17
                 U select@GLIBC_2.2.5
                 U setlocale@GLIBC_2.2.5
                 U setmntent@GLIBC_2.2.5
                 U setrlimit64@GLIBC_2.2.5
                 U setvbuf@GLIBC_2.2.5
                 U sigaction@GLIBC_2.2.5
                 U sleep@GLIBC_2.2.5
                 U srandom@GLIBC_2.2.5
                 U stat@GLIBC_2.33
                 U stat64@GLIBC_2.33
                 U strcasecmp@GLIBC_2.2.5
                 U strcat@GLIBC_2.2.5
                 U strchr@GLIBC_2.2.5
                 U strcmp@GLIBC_2.2.5
                 U strcpy@GLIBC_2.2.5
                 U strdup@GLIBC_2.2.5
                 U strerror@GLIBC_2.2.5
                 U strlen@GLIBC_2.2.5
                 U strncasecmp@GLIBC_2.2.5
                 U strncmp@GLIBC_2.2.5
                 U strncpy@GLIBC_2.2.5
                 U strnlen@GLIBC_2.2.5
                 U strrchr@GLIBC_2.2.5
                 U strtod@GLIBC_2.2.5
                 U strtol@GLIBC_2.2.5
                 U strtoul@GLIBC_2.2.5
                 U strtoull@GLIBC_2.2.5
                 U sysconf@GLIBC_2.2.5
                 U tcgetattr@GLIBC_2.2.5
                 U tcsetattr@GLIBC_2.2.5
                 U textdomain@GLIBC_2.2.5
                 U time@GLIBC_2.2.5
                 U tzset@GLIBC_2.2.5
                 U umask@GLIBC_2.2.5
                 U uname@GLIBC_2.2.5
                 U unlink@GLIBC_2.2.5
                 U utime@GLIBC_2.2.5
                 U uuid_generate@UUID_1.0
                 U uuid_is_null@UUID_1.0
                 U uuid_unparse@UUID_1.0
                 U write@GLIBC_2.2.5
00000000000165c0 T main
00000000000180d0 T _start
000000000001b210 T e2fsck_clear_progbar
000000000001b290 T e2fsck_simple_progress
000000000001b5c0 T e2fsck_allocate_context
000000000001b6e0 T e2fsck_reset_context
000000000001baa0 T e2fsck_free_context
000000000001bb90 T e2fsck_run
000000000001c930 T check_resize_inode
000000000001cdb0 T check_super_block
000000000001df40 T check_backup_super_block
0000000000022d20 T e2fsck_pass1_check_device_inode
0000000000022d70 T e2fsck_pass1_check_symlink
0000000000022f80 T e2fsck_setup_icount
00000000000230f0 T e2fsck_clear_inode
00000000000242d0 T e2fsck_use_inode_shortcuts
0000000000024340 T e2fsck_intercept_block_allocations
0000000000024390 T e2fsck_pass1
0000000000027f90 T e2fsck_pass1_dupblocks
0000000000029cb0 T e2fsck_pass2
000000000002a2f0 T e2fsck_process_bad_inode
000000000002c830 T e2fsck_adjust_inode_count
000000000002ca70 T e2fsck_get_lost_and_found
000000000002d140 T e2fsck_expand_directory
000000000002d2e0 T e2fsck_reconnect_file
000000000002d780 T e2fsck_pass3
000000000002de50 T e2fsck_pass4
000000000002ffd0 T e2fsck_pass5
00000000000310f0 T jbd2_has_feature_checksum
0000000000031130 T jbd2_set_feature_checksum
0000000000031150 T jbd2_clear_feature_checksum
0000000000031170 T jbd2_has_feature_revoke
00000000000311b0 T jbd2_set_feature_revoke
00000000000311d0 T jbd2_clear_feature_revoke
00000000000311f0 T jbd2_has_feature_64bit
0000000000031230 T jbd2_set_feature_64bit
0000000000031250 T jbd2_clear_feature_64bit
0000000000031270 T jbd2_has_feature_async_commit
00000000000312b0 T jbd2_set_feature_async_commit
00000000000312d0 T jbd2_clear_feature_async_commit
00000000000312f0 T jbd2_has_feature_csum2
0000000000031330 T jbd2_set_feature_csum2
0000000000031350 T jbd2_clear_feature_csum2
0000000000031370 T jbd2_has_feature_csum3
00000000000313b0 T jbd2_set_feature_csum3
00000000000313d0 T jbd2_clear_feature_csum3
00000000000313f0 T jbd2_has_feature_fast_commit
0000000000031430 T jbd2_set_feature_fast_commit
0000000000031450 T jbd2_clear_feature_fast_commit
0000000000031470 T journal_tag_bytes
00000000000314d0 T jbd2_journal_has_csum_v2or3
00000000000315a0 T jbd2_journal_get_num_fc_blks
00000000000315c0 T tid_gt
00000000000315d0 T tid_geq
00000000000315e0 T do_cache_create
0000000000031600 T do_cache_destroy
0000000000031610 T __hash_32
0000000000031620 T hash_32
0000000000031640 T hash_64
0000000000031660 T kmalloc_array
0000000000031680 T jbd2_chksum
0000000000031be0 T jbd2_descriptor_block_csum_set
0000000000031c30 T jbd2_journal_bmap
0000000000031cb0 T getblk
0000000000031d20 T sync_blockdev
0000000000031d60 T ll_rw_block
0000000000031e80 T mark_buffer_dirty
00000000000324e0 T brelse
0000000000032f70 T buffer_uptodate
0000000000032f80 T mark_buffer_uptodate
0000000000032fa0 T wait_on_buffer
0000000000032fe0 T e2fsck_check_ext3_journal
00000000000333d0 T e2fsck_run_ext3_journal
00000000000335e0 T e2fsck_move_ext3_journal
0000000000033940 T e2fsck_fix_ext3_journal_hint
0000000000033b10 T read_bad_blocks_file
0000000000033ef0 T log_out
0000000000034010 T log_err
0000000000034130 T fatal_error
00000000000342a0 T e2fsck_allocate_memory
0000000000034340 T string_copy
00000000000343b0 T ask_yn
0000000000034860 T ask
0000000000034950 T e2fsck_write_bitmaps
00000000000349d0 T preenhalt
0000000000034a70 T init_resource_track
0000000000034b50 T print_resource_track
0000000000034ea0 T e2fsck_read_inode
0000000000034f10 T e2fsck_read_inode_full
0000000000034f80 T e2fsck_write_inode_full
0000000000034ff0 T e2fsck_write_inode
0000000000035060 T get_backup_sb
00000000000352e0 T ext2_file_type
0000000000035380 T fs_proc_check
00000000000354f0 T check_for_modules
0000000000035680 T write_all
0000000000035700 T dump_mmp_msg
00000000000358c0 T e2fsck_mmp_update
0000000000035920 T e2fsck_set_bitmap_type
00000000000359d0 T e2fsck_read_bitmaps
0000000000035b10 T e2fsck_allocate_inode_bitmap
0000000000035b80 T e2fsck_allocate_block_bitmap
0000000000035bf0 T e2fsck_allocate_subcluster_bitmap
0000000000035c60 T get_memory_size
0000000000036110 T e2fsck_add_dir_info
0000000000036320 T e2fsck_free_dir_info
0000000000036410 T e2fsck_get_num_dirinfo
0000000000036430 T e2fsck_dir_info_iter_begin
0000000000036480 T e2fsck_dir_info_iter_end
00000000000364b0 T e2fsck_dir_info_iter
00000000000365e0 T e2fsck_dir_info_set_parent
0000000000036620 T e2fsck_dir_info_set_dotdot
0000000000036660 T e2fsck_dir_info_get_parent
0000000000036690 T e2fsck_dir_info_get_dotdot
00000000000366c0 T e2fsck_add_dx_dir
00000000000368c0 T e2fsck_get_dx_dir_info
0000000000036940 T e2fsck_free_dx_dir_info
00000000000369c0 T e2fsck_get_num_dx_dirinfo
00000000000369d0 T e2fsck_dx_dir_info_iter
0000000000036ce0 T ehandler_operation
0000000000036d00 T ehandler_init
0000000000037160 T set_latch_flags
0000000000037190 T get_latch_flags
00000000000371b0 T clear_problem_context
00000000000371f0 T fix_problem
0000000000037ae0 T end_problem_latch
0000000000038530 T print_e2fsck_message
0000000000038a90 T e2fsck_hide_quota
0000000000038ba0 T e2fsck_validate_quota_inodes
0000000000039b80 T jbd2_journal_recover
0000000000039c90 T jbd2_journal_skip_recovery
0000000000039d30 T region_create
0000000000039da0 T region_free
0000000000039e30 T region_allocate
000000000003a2c0 T jbd2_journal_destroy_revoke_record_cache
000000000003a2f0 T jbd2_journal_destroy_revoke_table_cache
000000000003a320 T jbd2_journal_init_revoke_record_cache
000000000003a390 T jbd2_journal_init_revoke_table_cache
000000000003a400 T jbd2_journal_init_revoke
000000000003a510 T jbd2_journal_destroy_revoke
000000000003a560 T jbd2_journal_set_revoke
000000000003a5d0 T jbd2_journal_test_revoke
000000000003a610 T jbd2_journal_clear_revoke
000000000003a8d0 T ea_refcount_free
000000000003a910 T ea_refcount_create
000000000003a9d0 T ea_refcount_fetch
000000000003aa00 T ea_refcount_increment
000000000003aa40 T ea_refcount_decrement
000000000003aa90 T ea_refcount_store
000000000003aad0 T ext2fs_get_refcount_size
000000000003aaf0 T ea_refcount_intr_begin
000000000003ab00 T ea_refcount_intr_next
000000000003c820 T e2fsck_rehash_dir_later
000000000003c880 T e2fsck_dir_will_be_rehashed
000000000003c8b0 T e2fsck_rehash_dir
000000000003ccc0 T e2fsck_rehash_directories
000000000003dc50 T set_up_logging
000000000003df00 T sigcatcher_setup
000000000003e1d0 T e2fsck_readahead_dblist
000000000003e280 T e2fsck_readahead
000000000003e560 T e2fsck_can_readahead
000000000003e590 T e2fsck_guess_readahead
000000000003efc0 T e2fsck_rebuild_extents_later
000000000003f090 T e2fsck_ino_will_be_rebuilt
000000000003f0b0 T e2fsck_rewrite_extent_tree
000000000003f1a0 T e2fsck_read_extents
000000000003f290 T e2fsck_should_rebuild_extents
000000000003f360 T e2fsck_check_rebuild_extents
000000000003f5e0 T e2fsck_pass1e
000000000003fab0 T add_encrypted_file
000000000003fc00 T find_encryption_policy
000000000003fc60 T destroy_encryption_policy_map
000000000003fcf0 T destroy_encrypted_file_info
00000000000400d0 T quota_file_exists
0000000000040170 T quota_set_sb_inum
00000000000401a0 T quota_remove_inode
00000000000402f0 T quota_write_inode
0000000000040480 T quota_release_context
0000000000040570 T quota_init_context
00000000000406d0 T quota_data_add
0000000000040760 T quota_data_sub
00000000000407f0 T quota_data_inodes
0000000000040880 T quota_compute_usage
0000000000040ab0 T quota_read_all_dquots
0000000000040bd0 T quota_compare_and_update
0000000000040d50 T parse_quota_opts
00000000000410a0 T check_plausibility
0000000000042300 T profile_release
0000000000042370 T profile_init
0000000000042580 T profile_set_default
0000000000042790 T profile_set_syntax_err_cb
00000000000427b0 T profile_iterator_create
0000000000042870 T profile_iterator_free
0000000000042cc0 T profile_get_string
0000000000042d70 T profile_get_integer
0000000000042e70 T profile_get_uint
0000000000042f50 T profile_get_double
0000000000043040 T profile_get_boolean
00000000000430e0 T profile_iterator
00000000000431f0 T initialize_prof_error_table_r
0000000000043280 T initialize_prof_error_table
00000000000434b0 T quota_type2name
00000000000434d0 T quota_type2inum
0000000000043500 T quota_get_qf_name
0000000000043560 T update_grace_times
0000000000043620 T quota_inode_truncate
00000000000438e0 T quota_file_create
0000000000043b60 T quota_file_close
0000000000043c00 T quota_file_open
0000000000043f30 T get_empty_dquot
0000000000044da0 T qtree_entry_unused
0000000000044de0 T qtree_dqstr_in_blk
0000000000045a00 T qtree_write_dquot
0000000000045b80 T qtree_delete_dquot
0000000000045be0 T qtree_read_dquot
0000000000045d40 T qtree_scan_dquots
0000000000045f80 T dict_set_allocator
0000000000045fb0 T dict_set_cmp_context
0000000000045fc0 T dict_free_nodes
0000000000045ff0 T dict_init
0000000000046040 T dict_lookup
00000000000460f0 T dict_insert
0000000000046240 T dict_first
0000000000046270 T dict_last
00000000000462a0 T dict_next
0000000000046300 T dict_prev
0000000000046360 T dict_allow_dupes
0000000000046370 T dict_count
0000000000046380 T dict_isempty
0000000000046390 T dict_isfull
00000000000463b0 T dict_contains
00000000000463c0 T dnode_create
0000000000046400 T dnode_init
0000000000046430 T dict_alloc_insert
0000000000046480 T dnode_destroy
0000000000046490 T dnode_get
00000000000464a0 T dnode_getkey
0000000000047500 T initialize_ext2_error_table_r
0000000000047590 T initialize_ext2_error_table
00000000000476c0 T ext2fs_clear_block_uninit
0000000000047750 T ext2fs_new_inode
00000000000478f0 T ext2fs_new_block3
0000000000047ab0 T ext2fs_new_block2
0000000000047ac0 T ext2fs_new_block
0000000000047b10 T ext2fs_alloc_block3
0000000000047c60 T ext2fs_alloc_block2
0000000000047c70 T ext2fs_alloc_block
0000000000047cc0 T ext2fs_get_free_blocks2
0000000000047e20 T ext2fs_get_free_blocks
0000000000047e70 T ext2fs_set_alloc_block_callback
0000000000047ea0 T ext2fs_find_inode_goal
0000000000047fd0 T ext2fs_new_range
0000000000048300 T ext2fs_set_new_range_callback
0000000000048330 T ext2fs_alloc_range
0000000000048430 T ext2fs_reserve_super_and_bgd
0000000000048600 T ext2fs_inode_alloc_stats2
0000000000048750 T ext2fs_inode_alloc_stats
0000000000048760 T ext2fs_block_alloc_stats2
0000000000048880 T ext2fs_block_alloc_stats
0000000000048890 T ext2fs_set_block_alloc_stats_callback
00000000000488c0 T ext2fs_block_alloc_stats_range
0000000000048af0 T ext2fs_set_block_alloc_stats_range_callback
0000000000048c30 T ext2fs_u32_list_create
0000000000048c50 T ext2fs_badblocks_list_create
0000000000048c60 T ext2fs_u32_copy
0000000000048ca0 T ext2fs_badblocks_copy
0000000000048cb0 T ext2fs_u32_list_add
0000000000048de0 T ext2fs_badblocks_list_add
0000000000048df0 T ext2fs_u32_list_find
0000000000048e60 T ext2fs_u32_list_test
0000000000048e70 T ext2fs_badblocks_list_test
0000000000048e80 T ext2fs_u32_list_del
0000000000048ee0 T ext2fs_badblocks_list_del
0000000000048ef0 T ext2fs_u32_list_iterate_begin
0000000000048f70 T ext2fs_badblocks_list_iterate_begin
0000000000048f80 T ext2fs_u32_list_iterate
0000000000048fd0 T ext2fs_badblocks_list_iterate
0000000000048fe0 T ext2fs_u32_list_iterate_end
0000000000049020 T ext2fs_badblocks_list_iterate_end
0000000000049030 T ext2fs_u32_list_equal
0000000000049090 T ext2fs_badblocks_equal
00000000000490a0 T ext2fs_u32_list_count
0000000000049270 T ext2fs_update_bb_inode
00000000000494e0 T ext2fs_free_block_bitmap
00000000000494f0 T ext2fs_free_inode_bitmap
0000000000049500 T ext2fs_copy_bitmap
0000000000049510 T ext2fs_set_bitmap_padding
0000000000049520 T ext2fs_allocate_inode_bitmap
00000000000495d0 T ext2fs_allocate_block_bitmap
00000000000496c0 T ext2fs_allocate_subcluster_bitmap
00000000000497d0 T ext2fs_get_bitmap_granularity
00000000000497f0 T ext2fs_fudge_inode_bitmap_end
0000000000049850 T ext2fs_fudge_block_bitmap_end
0000000000049870 T ext2fs_fudge_block_bitmap_end2
0000000000049890 T ext2fs_clear_inode_bitmap
00000000000498a0 T ext2fs_clear_block_bitmap
00000000000498b0 T ext2fs_resize_inode_bitmap
00000000000498d0 T ext2fs_resize_inode_bitmap2
00000000000498f0 T ext2fs_resize_block_bitmap
0000000000049910 T ext2fs_resize_block_bitmap2
0000000000049920 T ext2fs_compare_block_bitmap
0000000000049940 T ext2fs_compare_inode_bitmap
0000000000049960 T ext2fs_set_inode_bitmap_range
0000000000049980 T ext2fs_set_inode_bitmap_range2
0000000000049990 T ext2fs_get_inode_bitmap_range
00000000000499b0 T ext2fs_get_inode_bitmap_range2
00000000000499c0 T ext2fs_set_block_bitmap_range
00000000000499e0 T ext2fs_set_block_bitmap_range2
00000000000499f0 T ext2fs_get_block_bitmap_range
0000000000049a10 T ext2fs_get_block_bitmap_range2
0000000000049a90 T ext2fs_set_bit
0000000000049ac0 T ext2fs_clear_bit
0000000000049af0 T ext2fs_test_bit
0000000000049b10 T ext2fs_warn_bitmap
0000000000049b50 T ext2fs_set_bit64
0000000000049b80 T ext2fs_clear_bit64
0000000000049bb0 T ext2fs_test_bit64
0000000000049bd0 T ext2fs_bitcount
0000000000049ce0 T ext2fs_group_of_blk2
0000000000049d00 T ext2fs_group_first_block2
0000000000049d20 T ext2fs_inode_data_blocks2
0000000000049d60 T ext2fs_inode_i_blocks
0000000000049d90 T ext2fs_get_stat_i_blocks
0000000000049dd0 T ext2fs_blocks_count
0000000000049e00 T ext2fs_group_last_block2
0000000000049e40 T ext2fs_group_blocks_count
0000000000049e80 T ext2fs_blocks_count_set
0000000000049eb0 T ext2fs_blocks_count_add
0000000000049ed0 T ext2fs_r_blocks_count
0000000000049f00 T ext2fs_r_blocks_count_set
0000000000049f30 T ext2fs_r_blocks_count_add
0000000000049f50 T ext2fs_free_blocks_count
0000000000049f80 T ext2fs_free_blocks_count_set
0000000000049fb0 T ext2fs_free_blocks_count_add
0000000000049fd0 T ext2fs_group_desc
000000000004a110 T ext2fs_block_bitmap_checksum
000000000004a160 T ext2fs_block_bitmap_loc
000000000004a1a0 T ext2fs_block_bitmap_loc_set
000000000004a1f0 T ext2fs_inode_bitmap_checksum
000000000004a240 T ext2fs_inode_bitmap_loc
000000000004a280 T ext2fs_inode_bitmap_loc_set
000000000004a2d0 T ext2fs_inode_table_loc
000000000004a310 T ext2fs_inode_table_loc_set
000000000004a360 T ext2fs_bg_free_blocks_count
000000000004a3a0 T ext2fs_bg_free_blocks_count_set
000000000004a3f0 T ext2fs_bg_free_inodes_count
000000000004a430 T ext2fs_bg_free_inodes_count_set
000000000004a480 T ext2fs_bg_used_dirs_count
000000000004a4c0 T ext2fs_bg_used_dirs_count_set
000000000004a510 T ext2fs_bg_itable_unused
000000000004a550 T ext2fs_bg_itable_unused_set
000000000004a5a0 T ext2fs_bg_flags
000000000004a5c0 T ext2fs_bg_flags_zap
000000000004a5e0 T ext2fs_bg_flags_test
000000000004a600 T ext2fs_bg_flags_set
000000000004a620 T ext2fs_bg_flags_clear
000000000004a640 T ext2fs_bg_checksum
000000000004a660 T ext2fs_bg_checksum_set
000000000004a680 T ext2fs_file_acl_block
000000000004a6b0 T ext2fs_file_acl_block_set
000000000004a6e0 T ext2fs_inode_size_set
000000000004b1d0 T ext2fs_block_iterate3
000000000004b9b0 T ext2fs_block_iterate2
000000000004ba00 T ext2fs_block_iterate
000000000004c1c0 T ext2fs_map_cluster_block
000000000004c280 T ext2fs_file_block_offset_too_big
000000000004c2c0 T ext2fs_bmap2
000000000004c870 T ext2fs_bmap
000000000004c900 T ext2fs_check_desc
000000000004cda0 T ext2fs_bg_has_super
000000000004ce50 T ext2fs_super_and_bgd_loc2
000000000004cfb0 T ext2fs_super_and_bgd_loc
000000000004d0b0 T ext2fs_update_dynamic_rev
000000000004d0e0 T ext2fs_flush2
000000000004d4c0 T ext2fs_flush
000000000004d4d0 T ext2fs_close2
000000000004d660 T ext2fs_close_free
000000000004d6b0 T ext2fs_close
000000000004d820 T ext2fs_crc32c_le
000000000004d830 T ext2fs_crc32_be
000000000004def0 T ext2fs_init_csum_seed
000000000004df60 T ext2fs_mmp_csum_verify
000000000004dfb0 T ext2fs_mmp_csum_set
000000000004dfe0 T ext2fs_verify_csum_type
000000000004e010 T ext2fs_superblock_csum_verify
000000000004e050 T ext2fs_superblock_csum_set
000000000004e080 T ext2fs_ext_attr_block_csum_verify
000000000004e110 T ext2fs_ext_attr_block_csum_set
000000000004e190 T ext2fs_get_dx_countlimit
000000000004e1a0 T ext2fs_initialize_dirent_tail
000000000004e1d0 T ext2fs_dirent_has_tail
000000000004e200 T ext2fs_dirent_csum_verify
000000000004e2b0 T ext2fs_dx_csum
000000000004e4e0 T ext2fs_dir_block_csum_verify
000000000004e580 T ext2fs_dir_block_csum_set
000000000004e620 T ext2fs_extent_block_csum_verify
000000000004e6b0 T ext2fs_extent_block_csum_set
000000000004e730 T ext2fs_inode_bitmap_csum_verify
000000000004e7e0 T ext2fs_inode_bitmap_csum_set
000000000004e880 T ext2fs_block_bitmap_csum_verify
000000000004e930 T ext2fs_block_bitmap_csum_set
000000000004e9d0 T ext2fs_inode_csum_verify
000000000004eae0 T ext2fs_inode_csum_set
000000000004ebc0 T ext2fs_group_desc_csum
000000000004ecc0 T ext2fs_group_desc_csum_verify
000000000004ed20 T ext2fs_group_desc_csum_set
000000000004ed70 T ext2fs_set_gdt_csum
000000000004f1b0 T ext2fs_init_dblist
000000000004f220 T ext2fs_copy_dblist
000000000004f290 T ext2fs_add_dir_block2
000000000004f370 T ext2fs_set_dir_block2
000000000004f3e0 T ext2fs_dblist_sort2
000000000004f420 T ext2fs_dblist_iterate3
000000000004f4b0 T ext2fs_dblist_iterate2
000000000004f4d0 T ext2fs_dblist_count2
000000000004f4e0 T ext2fs_dblist_get_last2
000000000004f520 T ext2fs_dblist_drop_last
000000000004f550 T ext2fs_add_dir_block
000000000004f560 T ext2fs_set_dir_block
000000000004f570 T ext2fs_dblist_sort
000000000004f5b0 T ext2fs_dblist_iterate
000000000004f610 T ext2fs_dblist_count
000000000004f620 T ext2fs_dblist_get_last
000000000004f750 T ext2fs_dblist_dir_iterate
000000000004f860 T ext2fs_read_dir_block4
000000000004f8e0 T ext2fs_read_dir_block3
000000000004f8f0 T ext2fs_read_dir_block2
000000000004f900 T ext2fs_read_dir_block
000000000004f910 T ext2fs_write_dir_block4
000000000004f950 T ext2fs_write_dir_block3
000000000004f960 T ext2fs_write_dir_block2
000000000004f970 T ext2fs_write_dir_block
000000000004fde0 T ext2fs_dirhash
000000000004ffb0 T ext2fs_dirhash2
00000000000500f0 T ext2fs_get_rec_len
00000000000501f0 T ext2fs_process_dir_block
00000000000505c0 T ext2fs_set_rec_len
0000000000050640 T ext2fs_dir_iterate2
00000000000507b0 T ext2fs_dir_iterate
00000000000509d0 T ext2fs_expand_dir
00000000000510b0 T ext2fs_ext_attr_hash_entry
0000000000051120 T ext2fs_ext_attr_block_rehash
0000000000051170 T ext2fs_get_ea_inode_hash
00000000000511f0 T ext2fs_ext_attr_hash_entry2
0000000000051930 T ext2fs_set_ea_inode_hash
0000000000051940 T ext2fs_get_ea_inode_ref
0000000000051960 T ext2fs_set_ea_inode_ref
0000000000051b10 T ext2fs_read_ext_attr3
0000000000051ba0 T ext2fs_read_ext_attr2
0000000000051bb0 T ext2fs_read_ext_attr
0000000000051bc0 T ext2fs_write_ext_attr3
0000000000051dd0 T ext2fs_write_ext_attr2
0000000000051de0 T ext2fs_write_ext_attr
0000000000051df0 T ext2fs_adjust_ea_refcount3
0000000000051f00 T ext2fs_adjust_ea_refcount2
0000000000051f10 T ext2fs_adjust_ea_refcount
0000000000051f20 T ext2fs_free_ext_attr
0000000000052910 T ext2fs_xattrs_write
0000000000052c70 T ext2fs_xattrs_read
0000000000052ee0 T ext2fs_xattrs_iterate
0000000000052fb0 T ext2fs_xattr_get
0000000000053110 T ext2fs_xattr_inode_max_size
0000000000053290 T ext2fs_xattr_set
0000000000053650 T ext2fs_xattr_remove
0000000000053760 T ext2fs_xattrs_open
0000000000053840 T ext2fs_xattrs_close
0000000000053880 T ext2fs_xattrs_count
00000000000538a0 T ext2fs_xattrs_flags
00000000000539f0 T ext2fs_extent_header_verify
0000000000053a40 T ext2fs_extent_free
0000000000053ad0 T ext2fs_extent_open2
0000000000053d50 T ext2fs_extent_open
0000000000053d60 T ext2fs_extent_get
0000000000054580 T ext2fs_extent_goto2
0000000000054700 T ext2fs_extent_goto
0000000000054710 T ext2fs_extent_replace
00000000000547f0 T ext2fs_extent_delete
00000000000549b0 T ext2fs_extent_get_info
0000000000054a70 T ext2fs_extent_fix_parents
0000000000055240 T ext2fs_extent_node_split
0000000000055250 T ext2fs_extent_insert
00000000000553b0 T ext2fs_extent_set_bmap
0000000000055cd0 T ext2fs_max_extent_depth
0000000000055d50 T ext2fs_fix_extents_checksums
0000000000055e80 T ext2fs_decode_extent
0000000000055ee0 T ext2fs_count_blocks
0000000000056200 T ext2fs_file_open2
00000000000563c0 T ext2fs_file_open
00000000000563d0 T ext2fs_file_get_fs
00000000000563f0 T ext2fs_file_get_inode
0000000000056410 T ext2fs_file_get_inode_num
0000000000056430 T ext2fs_file_flush
0000000000056770 T ext2fs_file_close
00000000000567e0 T ext2fs_file_read
0000000000056980 T ext2fs_file_llseek
00000000000569f0 T ext2fs_file_lseek
0000000000056a50 T ext2fs_file_get_lsize
0000000000056a80 T ext2fs_file_get_size
0000000000056ae0 T ext2fs_file_set_size2
0000000000056d80 T ext2fs_file_write
0000000000057120 T ext2fs_file_set_size
0000000000057130 T ext2fs_sync_device
00000000000571b0 T ext2fs_u32_list_free
0000000000057200 T ext2fs_badblocks_list_free
0000000000057210 T ext2fs_free_dblist
0000000000057280 T ext2fs_free
0000000000057480 T ext2fs_warn_bitmap2
00000000000574c0 T ext2fs_make_generic_bitmap
00000000000576b0 T ext2fs_allocate_generic_bitmap
00000000000576e0 T ext2fs_copy_generic_bitmap
0000000000057710 T ext2fs_free_generic_bitmap
00000000000577a0 T ext2fs_test_generic_bitmap
0000000000057860 T ext2fs_mark_generic_bitmap
0000000000057920 T ext2fs_unmark_generic_bitmap
00000000000579e0 T ext2fs_get_generic_bitmap_start
0000000000057a50 T ext2fs_get_generic_bitmap_end
0000000000057ac0 T ext2fs_clear_generic_bitmap
0000000000057b40 T ext2fs_fudge_generic_bitmap_end
0000000000057b70 T ext2fs_resize_generic_bitmap
0000000000057c40 T ext2fs_compare_generic_bitmap
0000000000057d00 T ext2fs_set_generic_bitmap_padding
0000000000057d60 T ext2fs_get_generic_bitmap_range
0000000000057dc0 T ext2fs_set_generic_bitmap_range
0000000000057e20 T ext2fs_mem_is_zero
0000000000057fe0 T ext2fs_find_first_zero_generic_bitmap
0000000000058070 T ext2fs_find_first_set_generic_bitmap
0000000000058100 T ext2fs_test_block_bitmap_range
0000000000058160 T ext2fs_test_inode_bitmap_range
00000000000581c0 T ext2fs_mark_block_bitmap_range
0000000000058250 T ext2fs_unmark_block_bitmap_range
00000000000583c0 T ext2fs_alloc_generic_bmap
0000000000058670 T ext2fs_free_generic_bmap
0000000000058750 T ext2fs_copy_generic_bmap
0000000000058950 T ext2fs_resize_generic_bmap
00000000000589a0 T ext2fs_fudge_generic_bmap_end
0000000000058a50 T ext2fs_get_generic_bmap_start
0000000000058ab0 T ext2fs_get_generic_bmap_end
0000000000058b10 T ext2fs_clear_generic_bmap
0000000000058b40 T ext2fs_mark_generic_bmap
0000000000058be0 T ext2fs_unmark_generic_bmap
0000000000058c90 T ext2fs_test_generic_bmap
0000000000058d40 T ext2fs_set_generic_bmap_range
0000000000058dd0 T ext2fs_get_generic_bmap_range
0000000000058e60 T ext2fs_compare_generic_bmap
0000000000058f60 T ext2fs_set_generic_bmap_padding
0000000000058fa0 T ext2fs_test_block_bitmap_range2
00000000000590c0 T ext2fs_mark_block_bitmap_range2
00000000000591b0 T ext2fs_unmark_block_bitmap_range2
00000000000592a0 T ext2fs_warn_bitmap32
00000000000592f0 T ext2fs_convert_subcluster_bitmap
0000000000059420 T ext2fs_find_first_zero_generic_bmap
00000000000595c0 T ext2fs_find_first_set_generic_bmap
0000000000059760 T ext2fs_count_used_clusters
0000000000059850 T ext2fs_get_num_dirs
0000000000059d00 T ext2fs_get_pathname
0000000000059e10 T ext2fs_get_device_size2
000000000005a070 T ext2fs_get_device_size
000000000005a0d0 T ext2fs_djb2_hash
000000000005a110 T ext2fs_hashmap_create
000000000005a160 T ext2fs_hashmap_add
000000000005a210 T ext2fs_hashmap_lookup
000000000005a280 T ext2fs_hashmap_iter_in_order
000000000005a2b0 T ext2fs_hashmap_free
000000000005a340 T ext2fs_iblk_add_blocks
000000000005a3e0 T ext2fs_iblk_sub_blocks
000000000005a480 T ext2fs_iblk_set
000000000005a940 T ext2fs_free_icount
000000000005ab60 T ext2fs_create_icount_tdb
000000000005ace0 T ext2fs_create_icount2
000000000005ae50 T ext2fs_create_icount
000000000005ae60 T ext2fs_icount_validate
000000000005af40 T ext2fs_icount_fetch
000000000005b020 T ext2fs_icount_increment
000000000005b1d0 T ext2fs_icount_decrement
000000000005b370 T ext2fs_icount_store
000000000005b480 T ext2fs_get_icount_size
000000000005b4a0 T ext2fs_read_ind_block
000000000005b4f0 T ext2fs_write_ind_block
000000000005b6a0 T ext2fs_initialize
000000000005c4f0 T ext2fs_calculate_summary_stats
000000000005c730 T ext2fs_fast_set_bit
000000000005c750 T ext2fs_fast_clear_bit
000000000005c770 T ext2fs_fast_set_bit64
000000000005c790 T ext2fs_fast_clear_bit64
000000000005c7b0 T ext2fs_swab16
000000000005c7c0 T ext2fs_swab32
000000000005c7d0 T ext2fs_swab64
000000000005c800 T ext2fs_mark_block_bitmap
000000000005c810 T ext2fs_unmark_block_bitmap
000000000005c820 T ext2fs_test_block_bitmap
000000000005c830 T ext2fs_mark_inode_bitmap
000000000005c840 T ext2fs_unmark_inode_bitmap
000000000005c850 T ext2fs_test_inode_bitmap
000000000005c860 T ext2fs_fast_mark_block_bitmap
000000000005c870 T ext2fs_fast_unmark_block_bitmap
000000000005c880 T ext2fs_fast_test_block_bitmap
000000000005c890 T ext2fs_fast_mark_inode_bitmap
000000000005c8a0 T ext2fs_fast_unmark_inode_bitmap
000000000005c8b0 T ext2fs_fast_test_inode_bitmap
000000000005c8c0 T ext2fs_get_block_bitmap_start
000000000005c8d0 T ext2fs_get_inode_bitmap_start
000000000005c8e0 T ext2fs_get_block_bitmap_end
000000000005c8f0 T ext2fs_get_inode_bitmap_end
000000000005c900 T ext2fs_fast_test_block_bitmap_range
000000000005c910 T ext2fs_fast_mark_block_bitmap_range
000000000005c920 T ext2fs_fast_unmark_block_bitmap_range
000000000005c930 T ext2fs_mark_block_bitmap2
000000000005c940 T ext2fs_unmark_block_bitmap2
000000000005c950 T ext2fs_test_block_bitmap2
000000000005c960 T ext2fs_mark_inode_bitmap2
000000000005c970 T ext2fs_unmark_inode_bitmap2
000000000005c980 T ext2fs_test_inode_bitmap2
000000000005c990 T ext2fs_fast_mark_block_bitmap2
000000000005c9a0 T ext2fs_fast_unmark_block_bitmap2
000000000005c9b0 T ext2fs_fast_test_block_bitmap2
000000000005c9c0 T ext2fs_fast_mark_inode_bitmap2
000000000005c9d0 T ext2fs_fast_unmark_inode_bitmap2
000000000005c9e0 T ext2fs_fast_test_inode_bitmap2
000000000005c9f0 T ext2fs_find_first_zero_block_bitmap2
000000000005ca40 T ext2fs_find_first_zero_inode_bitmap2
000000000005ca90 T ext2fs_find_first_set_block_bitmap2
000000000005cae0 T ext2fs_find_first_set_inode_bitmap2
000000000005cb30 T ext2fs_get_block_bitmap_start2
000000000005cb40 T ext2fs_get_inode_bitmap_start2
000000000005cb60 T ext2fs_get_block_bitmap_end2
000000000005cb70 T ext2fs_get_inode_bitmap_end2
000000000005cb90 T ext2fs_fast_test_block_bitmap_range2
000000000005cba0 T ext2fs_fast_mark_block_bitmap_range2
000000000005cbb0 T ext2fs_fast_unmark_block_bitmap_range2
000000000005cbc0 T ext2fs_get_mem
000000000005cbe0 T ext2fs_get_memzero
000000000005cc20 T ext2fs_get_array
000000000005cc50 T ext2fs_get_arrayzero
000000000005cc80 T ext2fs_free_mem
000000000005cca0 T ext2fs_resize_mem
000000000005ccd0 T ext2fs_resize_array
000000000005cd60 T ext2fs_mark_super_dirty
000000000005cd70 T ext2fs_mark_changed
000000000005cd80 T ext2fs_test_changed
000000000005cd90 T ext2fs_mark_valid
000000000005cda0 T ext2fs_unmark_valid
000000000005cdb0 T ext2fs_test_valid
000000000005cdc0 T ext2fs_mark_ib_dirty
000000000005cdd0 T ext2fs_mark_bb_dirty
000000000005cde0 T ext2fs_test_ib_dirty
000000000005cdf0 T ext2fs_test_bb_dirty
000000000005ce00 T ext2fs_group_of_blk
000000000005ce10 T ext2fs_group_of_ino
000000000005ce30 T ext2fs_group_first_block
000000000005ce50 T ext2fs_group_last_block
000000000005ce70 T ext2fs_inode_data_blocks
000000000005ce90 T ext2fs_htree_intnode_maxrecs
000000000005ceb0 T ext2fs_div_ceil
000000000005ced0 T ext2fs_div64_ceil
000000000005cef0 T ext2fs_dirent_name_len
000000000005cf00 T ext2fs_dirent_set_name_len
000000000005cf10 T ext2fs_dirent_file_type
000000000005cf20 T ext2fs_dirent_set_file_type
000000000005cf30 T ext2fs_inode
000000000005cf40 T ext2fs_const_inode
000000000005cf50 T ext2fs_get_memalign
000000000005d580 T ext2fs_inline_data_init
000000000005d5e0 T ext2fs_inline_data_size
000000000005d680 T ext2fs_inline_data_dir_iterate
000000000005d990 T ext2fs_inline_data_ea_remove
000000000005da20 T ext2fs_inline_data_expand
000000000005dc30 T ext2fs_inline_data_get
000000000005dd50 T ext2fs_inline_data_set
000000000005e4c0 T ext2fs_flush_icache
000000000005e510 T ext2fs_free_inode_cache
000000000005e5a0 T ext2fs_create_inode_cache
000000000005e6d0 T ext2fs_open_inode_scan
000000000005e9c0 T ext2fs_close_inode_scan
000000000005ea20 T ext2fs_set_inode_callback
000000000005ea50 T ext2fs_inode_scan_flags
000000000005ea80 T ext2fs_inode_scan_goto_blockgroup
000000000005eab0 T ext2fs_get_next_inode_full
000000000005eee0 T ext2fs_get_next_inode
000000000005eef0 T ext2fs_read_inode2
000000000005f340 T ext2fs_read_inode_full
000000000005f350 T ext2fs_read_inode
000000000005f370 T ext2fs_write_inode2
000000000005f710 T ext2fs_write_inode_full
000000000005f720 T ext2fs_write_inode
000000000005f740 T ext2fs_write_new_inode
000000000005f8d0 T ext2fs_get_blocks
000000000005f980 T ext2fs_check_directory
000000000005fa30 T io_channel_set_options
000000000005fb60 T io_channel_write_byte
000000000005fba0 T io_channel_read_blk64
000000000005fbf0 T io_channel_write_blk64
000000000005fc40 T io_channel_discard
000000000005fc80 T io_channel_zeroout
000000000005fcc0 T io_channel_alloc_buf
000000000005fd20 T io_channel_cache_readahead
0000000000060370 T ext2fs_check_mount_point
0000000000060520 T ext2fs_check_if_mounted
0000000000061660 T ext2fs_link
00000000000617b0 T ext2fs_llseek
0000000000061810 T ext2fs_lookup
0000000000061a40 T ext2fs_zero_blocks2
0000000000061be0 T ext2fs_zero_blocks
0000000000061c30 T ext2fs_default_journal_size
0000000000061cb0 T ext2fs_get_journal_params
0000000000061da0 T ext2fs_journal_sb_start
0000000000061dc0 T ext2fs_create_journal_superblock2
0000000000061f10 T ext2fs_create_journal_superblock
0000000000062340 T ext2fs_add_journal_device
00000000000625b0 T ext2fs_add_journal_inode3
0000000000062820 T ext2fs_add_journal_inode2
0000000000062870 T ext2fs_add_journal_inode
0000000000062890 T ext2fs_mmp_read
0000000000062a70 T ext2fs_mmp_write
0000000000062c10 T ext2fs_mmp_new_seq
0000000000062cc0 T ext2fs_mmp_clear
0000000000062ce0 T ext2fs_mmp_init
0000000000062db0 T ext2fs_mmp_start
0000000000062fb0 T ext2fs_mmp_stop
0000000000063080 T ext2fs_mmp_update2
0000000000063180 T ext2fs_mmp_update
00000000000631c0 T ext2fs_new_dir_block
00000000000633c0 T ext2fs_new_dir_inline_data
0000000000063c90 T ext2fs_load_nls_table
0000000000063cb0 T ext2fs_check_encoded_name
0000000000063cc0 T ext2fs_casefold_cmp
0000000000063da0 T ext2fs_descriptor_block_loc2
0000000000063ee0 T ext2fs_descriptor_block_loc
0000000000063f00 T ext2fs_open2
0000000000064a20 T ext2fs_open
0000000000064a40 T ext2fs_get_data_io
0000000000064a70 T ext2fs_set_data_io
0000000000064aa0 T ext2fs_rewrite_to_io
0000000000065570 T ext2fs_punch
00000000000656d0 T ext2fs_read_bb_inode
0000000000065800 T ext2fs_read_bb_FILE2
0000000000065980 T ext2fs_read_bb_FILE
0000000000065ac0 T ext2fs_create_resize_inode
00000000000667e0 T ext2fs_write_bitmaps
0000000000066f20 T ext2fs_rw_bitmaps
00000000000673a0 T ext2fs_read_inode_bitmap
00000000000673c0 T ext2fs_read_block_bitmap
00000000000673e0 T ext2fs_write_inode_bitmap
00000000000673f0 T ext2fs_write_block_bitmap
0000000000067400 T ext2fs_read_bitmaps
0000000000067d00 T ext2fs_sha512
0000000000067d90 T ext2fs_symlink
00000000000681e0 T ext2fs_is_fast_symlink
000000000006bb10 T ext2fs_tdb_error
000000000006bb20 T ext2fs_tdb_errorstr
000000000006bb70 T ext2fs_tdb_lock_nonblock
000000000006bb80 T ext2fs_tdb_lockall
000000000006bba0 T ext2fs_tdb_lockall_mark
000000000006bbc0 T ext2fs_tdb_lockall_unmark
000000000006bbd0 T ext2fs_tdb_lockall_nonblock
000000000006bbf0 T ext2fs_tdb_unlockall
000000000006bc00 T ext2fs_tdb_lockall_read
000000000006bc10 T ext2fs_tdb_lockall_read_nonblock
000000000006bc20 T ext2fs_tdb_unlockall_read
000000000006bc30 T ext2fs_tdb_chainlock
000000000006bc70 T ext2fs_tdb_chainlock_nonblock
000000000006bcb0 T ext2fs_tdb_chainlock_mark
000000000006bcf0 T ext2fs_tdb_chainlock_unmark
000000000006bd30 T ext2fs_tdb_chainunlock
000000000006bd70 T ext2fs_tdb_chainlock_read
000000000006bdb0 T ext2fs_tdb_chainunlock_read
000000000006bdf0 T ext2fs_tdb_transaction_start
000000000006c130 T ext2fs_tdb_transaction_cancel
000000000006c320 T ext2fs_tdb_transaction_recover
000000000006c6a0 T ext2fs_tdb_transaction_commit
000000000006ca90 T ext2fs_tdb_traverse_read
000000000006cb30 T ext2fs_tdb_traverse
000000000006cbe0 T ext2fs_tdb_firstkey
000000000006ccd0 T ext2fs_tdb_nextkey
000000000006cfa0 T ext2fs_tdb_dump_all
000000000006d000 T ext2fs_tdb_printfreelist
000000000006d1b0 T ext2fs_tdb_increment_seqnum_nonblock
000000000006d420 T ext2fs_tdb_fetch
000000000006d4e0 T ext2fs_tdb_parse_record
000000000006d5b0 T ext2fs_tdb_exists
000000000006d5f0 T ext2fs_tdb_delete
000000000006d630 T ext2fs_tdb_store
000000000006da40 T ext2fs_tdb_append
000000000006db90 T ext2fs_tdb_name
000000000006dba0 T ext2fs_tdb_fd
000000000006dbb0 T ext2fs_tdb_log_fn
000000000006dbc0 T ext2fs_tdb_get_seqnum
000000000006dc20 T ext2fs_tdb_hash_size
000000000006dc30 T ext2fs_tdb_map_size
000000000006dc40 T ext2fs_tdb_get_flags
000000000006dc50 T ext2fs_tdb_enable_seqnum
000000000006dc60 T ext2fs_tdb_open_ex
000000000006e360 T ext2fs_tdb_open
000000000006e380 T ext2fs_tdb_set_max_dead
000000000006e390 T ext2fs_tdb_close
000000000006e4b0 T ext2fs_tdb_validate_freelist
000000000006e610 T ext2fs_tdb_set_logging_function
000000000006e620 T ext2fs_tdb_get_logging_private
000000000006e630 T ext2fs_tdb_reopen
000000000006e890 T ext2fs_tdb_reopen_all
000000000006e8f0 T ext2fs_tdb_flush
0000000000070020 T set_undo_io_backing_manager
0000000000070030 T set_undo_io_backup_file
0000000000071820 T ext2fs_open_file
0000000000071840 T ext2fs_stat
0000000000071850 T ext2fs_fstat
0000000000071ef0 T ext2fs_unlink
0000000000071fd0 T ext2fs_inode_has_valid_blocks2
0000000000072060 T ext2fs_inode_has_valid_blocks
0000000000072070 T ext2fs_parse_version_string
00000000000720f0 T ext2fs_get_library_version
00000000000723e0 T ext2fs_rb_insert_color
0000000000072500 T ext2fs_rb_erase
0000000000072660 T ext2fs_rb_first
0000000000072690 T ext2fs_rb_last
00000000000726c0 T ext2fs_rb_next
0000000000072720 T ext2fs_rb_prev
0000000000072780 T ext2fs_rb_replace_node
0000000000072850 T ext2fs_add_exit_fn
0000000000072950 T ext2fs_remove_exit_fn
00000000000744a0 T ext2fs_crc16
0000000000075980 T ext2fs_fallocate
0000000000075ce0 T ext2fs_get_device_sectsize
0000000000075d40 T ext2fs_get_dio_alignment
0000000000075dc0 T ext2fs_get_device_phys_sectsize
0000000000076030 T et_list_lock
0000000000076040 T et_list_unlock
0000000000076050 T set_com_err_gettext
0000000000076070 T error_message
0000000000076280 T add_error_table
0000000000076340 T remove_error_table
0000000000076440 T add_to_error_table
0000000000076450 T error_table_name
00000000000765f0 T com_err_va
0000000000076600 T com_err
00000000000766d0 T set_com_err_hook
0000000000076700 T reset_com_err_hook
00000000000767b0 T e2p_feature_to_string
0000000000076850 T e2p_feature2string
0000000000076870 T e2p_string2feature
00000000000769c0 T e2p_jrnl_feature2string
0000000000076a60 T e2p_jrnl_string2feature
0000000000076bb0 T e2p_edit_feature2
0000000000076e50 T e2p_edit_feature
0000000000076eb0 T e2p_is_null_uuid
0000000000076ee0 T e2p_uuid_to_str
0000000000076f90 T e2p_uuid2str
0000000000077000 R _IO_stdin_used
00000000000b0f60 D et_prof_error_table
00000000000b10e0 D et_ext2_error_table
00000000000b2000 D __data_start
00000000000b2000 W data_start
00000000000b65a0 D quotafile_ops_2
00000000000b6600 D test_io_manager
00000000000b67c0 D undo_io_manager
00000000000b68e0 D unixfd_io_manager
00000000000b69f0 D unix_io_manager
00000000000b6b00 D ext2fs_blkmap64_bitarray
00000000000b6ba0 D ext2fs_blkmap64_rbtree
00000000000b6c28 D com_err_hook
00000000000b6f90 B __bss_start
00000000000b6f90 D _edata
00000000000b6fa0 B stdout@GLIBC_2.2.5
00000000000b6fa8 B optind@GLIBC_2.2.5
00000000000b6fc0 B optarg@GLIBC_2.2.5
00000000000b6fe0 B stderr@GLIBC_2.2.5
00000000000b7000 B e2fsck_global_ctx
00000000000b73e0 B test_io_cb_write_byte
00000000000b73e8 B test_io_cb_set_blksize
00000000000b73f0 B test_io_cb_write_blk64
00000000000b73f8 B test_io_cb_read_blk64
00000000000b7400 B test_io_cb_write_blk
00000000000b7408 B test_io_cb_read_blk
00000000000b7410 B test_io_backing_manager
00000000000b74a8 B _et_dynamic_list
00000000000b74b0 B _et_list
00000000000b7570 B _end

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x39cc0 --stop-address=0x39e90 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000039cc0 <jbd2_journal_skip_recovery@@Base+0x30>:
   39cc0:	29 04 24             	sub    DWORD PTR [rsp],eax
   39cc3:	e8 78 f6 ff ff       	call   39340 <e2fsck_validate_quota_inodes@@Base+0x7a0>
   39cc8:	41 89 c4             	mov    r12d,eax
   39ccb:	85 c0                	test   eax,eax
   39ccd:	75 31                	jne    39d00 <jbd2_journal_skip_recovery@@Base+0x70>
   39ccf:	8b 44 24 04          	mov    eax,DWORD PTR [rsp+0x4]
   39cd3:	83 c0 01             	add    eax,0x1
   39cd6:	89 83 94 00 00 00    	mov    DWORD PTR [rbx+0x94],eax
   39cdc:	48 c7 43 30 00 00 00 	mov    QWORD PTR [rbx+0x30],0x0
   39ce3:	00 
   39ce4:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   39ce9:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   39cf0:	00 00 
   39cf2:	75 2c                	jne    39d20 <jbd2_journal_skip_recovery@@Base+0x90>
   39cf4:	48 83 c4 28          	add    rsp,0x28
   39cf8:	44 89 e0             	mov    eax,r12d
   39cfb:	5b                   	pop    rbx
   39cfc:	41 5c                	pop    r12
   39cfe:	c3                   	ret    
   39cff:	90                   	nop
   39d00:	89 c2                	mov    edx,eax
   39d02:	48 8d 35 2f 56 04 00 	lea    rsi,[rip+0x4562f]        # 7f338 <_IO_stdin_used@@Base+0x8338>
   39d09:	bf 01 00 00 00       	mov    edi,0x1
   39d0e:	31 c0                	xor    eax,eax
   39d10:	e8 bb c5 fd ff       	call   162d0 <__printf_chk@plt>
   39d15:	8b 83 94 00 00 00    	mov    eax,DWORD PTR [rbx+0x94]
   39d1b:	83 c0 01             	add    eax,0x1
   39d1e:	eb b6                	jmp    39cd6 <jbd2_journal_skip_recovery@@Base+0x46>
   39d20:	e8 db c0 fd ff       	call   15e00 <__stack_chk_fail@plt>
   39d25:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   39d2c:	00 00 00 
   39d2f:	90                   	nop

0000000000039d30 <region_create@@Base>:
   39d30:	f3 0f 1e fa          	endbr64 
   39d34:	55                   	push   rbp
   39d35:	48 89 fd             	mov    rbp,rdi
   39d38:	bf 20 00 00 00       	mov    edi,0x20
   39d3d:	53                   	push   rbx
   39d3e:	48 89 f3             	mov    rbx,rsi
   39d41:	48 83 ec 18          	sub    rsp,0x18
   39d45:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   39d4c:	00 00 
   39d4e:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   39d53:	31 c0                	xor    eax,eax
   39d55:	48 89 e6             	mov    rsi,rsp
   39d58:	e8 83 2e 02 00       	call   5cbe0 <ext2fs_get_memzero@@Base>
   39d5d:	48 85 c0             	test   rax,rax
   39d60:	75 2e                	jne    39d90 <region_create@@Base+0x60>
   39d62:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
   39d66:	48 89 28             	mov    QWORD PTR [rax],rbp
   39d69:	48 89 58 08          	mov    QWORD PTR [rax+0x8],rbx
   39d6d:	48 c7 40 18 00 00 00 	mov    QWORD PTR [rax+0x18],0x0
   39d74:	00 
   39d75:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
   39d7a:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   39d81:	00 00 
   39d83:	75 0f                	jne    39d94 <region_create@@Base+0x64>
   39d85:	48 83 c4 18          	add    rsp,0x18
   39d89:	5b                   	pop    rbx
   39d8a:	5d                   	pop    rbp
   39d8b:	c3                   	ret    
   39d8c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   39d90:	31 c0                	xor    eax,eax
   39d92:	eb e1                	jmp    39d75 <region_create@@Base+0x45>
   39d94:	e8 67 c0 fd ff       	call   15e00 <__stack_chk_fail@plt>
   39d99:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000039da0 <region_free@@Base>:
   39da0:	f3 0f 1e fa          	endbr64 
   39da4:	55                   	push   rbp
   39da5:	53                   	push   rbx
   39da6:	48 83 ec 28          	sub    rsp,0x28
   39daa:	48 8b 5f 10          	mov    rbx,QWORD PTR [rdi+0x10]
   39dae:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
   39db3:	64 48 8b 14 25 28 00 	mov    rdx,QWORD PTR fs:0x28
   39dba:	00 00 
   39dbc:	48 89 54 24 18       	mov    QWORD PTR [rsp+0x18],rdx
   39dc1:	31 d2                	xor    edx,edx
   39dc3:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
   39dc8:	48 85 db             	test   rbx,rbx
   39dcb:	74 53                	je     39e20 <region_free@@Base+0x80>
   39dcd:	48 8d 6c 24 10       	lea    rbp,[rsp+0x10]
   39dd2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   39dd8:	48 8b 5b 10          	mov    rbx,QWORD PTR [rbx+0x10]
   39ddc:	48 89 ef             	mov    rdi,rbp
   39ddf:	e8 9c 2e 02 00       	call   5cc80 <ext2fs_free_mem@@Base>
   39de4:	48 89 5c 24 10       	mov    QWORD PTR [rsp+0x10],rbx
   39de9:	48 85 db             	test   rbx,rbx
   39dec:	75 ea                	jne    39dd8 <region_free@@Base+0x38>
   39dee:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   39df3:	66 0f ef c0          	pxor   xmm0,xmm0
   39df7:	48 8d 7c 24 08       	lea    rdi,[rsp+0x8]
   39dfc:	0f 11 00             	movups XMMWORD PTR [rax],xmm0
   39dff:	0f 11 40 10          	movups XMMWORD PTR [rax+0x10],xmm0
   39e03:	e8 78 2e 02 00       	call   5cc80 <ext2fs_free_mem@@Base>
   39e08:	48 8b 44 24 18       	mov    rax,QWORD PTR [rsp+0x18]
   39e0d:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   39e14:	00 00 
   39e16:	75 0d                	jne    39e25 <region_free@@Base+0x85>
   39e18:	48 83 c4 28          	add    rsp,0x28
   39e1c:	5b                   	pop    rbx
   39e1d:	5d                   	pop    rbp
   39e1e:	c3                   	ret    
   39e1f:	90                   	nop
   39e20:	48 89 f8             	mov    rax,rdi
   39e23:	eb ce                	jmp    39df3 <region_free@@Base+0x53>
   39e25:	e8 d6 bf fd ff       	call   15e00 <__stack_chk_fail@plt>
   39e2a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]

0000000000039e30 <region_allocate@@Base>:
   39e30:	f3 0f 1e fa          	endbr64 
   39e34:	41 56                	push   r14
   39e36:	41 55                	push   r13
   39e38:	41 54                	push   r12
   39e3a:	55                   	push   rbp
   39e3b:	53                   	push   rbx
   39e3c:	48 83 ec 10          	sub    rsp,0x10
   39e40:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   39e47:	00 00 
   39e49:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   39e4e:	31 c0                	xor    eax,eax
   39e50:	48 39 37             	cmp    QWORD PTR [rdi],rsi
   39e53:	0f 87 c7 00 00 00    	ja     39f20 <region_allocate@@Base+0xf0>
   39e59:	4c 63 e2             	movsxd r12,edx
   39e5c:	49 89 fd             	mov    r13,rdi
   39e5f:	48 89 f3             	mov    rbx,rsi
   39e62:	49 01 f4             	add    r12,rsi
   39e65:	4c 39 67 08          	cmp    QWORD PTR [rdi+0x8],r12
   39e69:	0f 82 b1 00 00 00    	jb     39f20 <region_allocate@@Base+0xf0>
   39e6f:	85 d2                	test   edx,edx
   39e71:	0f 84 85 00 00 00    	je     39efc <region_allocate@@Base+0xcc>
   39e77:	48 8b 6f 18          	mov    rbp,QWORD PTR [rdi+0x18]
   39e7b:	48 85 ed             	test   rbp,rbp
   39e7e:	74 13                	je     39e93 <region_allocate@@Base+0x63>
   39e80:	48 39 75 08          	cmp    QWORD PTR [rbp+0x8],rsi
   39e84:	0f 84 de 00 00 00    	je     39f68 <region_allocate@@Base+0x138>
   39e8a:	73 07                	jae    39e93 <region_allocate@@Base+0x63>
   39e8c:	48                   	rex.W
   39e8d:	83                   	.byte 0x83
   39e8e:	7d 10                	jge    39ea0 <region_allocate@@Base+0x70>

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x1f550 --stop-address=0x1f800 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001f550 <check_backup_super_block@@Base+0x1610>:
   1f550:	eb 81                	jmp    1f4d3 <check_backup_super_block@@Base+0x1593>
   1f552:	e8 a9 68 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1f557:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1f55e:	00 00 
   1f560:	b8 08 00 00 00       	mov    eax,0x8
   1f565:	c3                   	ret    
   1f566:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1f56d:	00 00 00 
   1f570:	8b 87 c0 00 00 00    	mov    eax,DWORD PTR [rdi+0xc0]
   1f576:	49 89 f1             	mov    r9,rsi
   1f579:	49 89 d2             	mov    r10,rdx
   1f57c:	48 89 ce             	mov    rsi,rcx
   1f57f:	85 c0                	test   eax,eax
   1f581:	74 3f                	je     1f5c2 <check_backup_super_block@@Base+0x1682>
   1f583:	89 c1                	mov    ecx,eax
   1f585:	ba 01 00 00 00       	mov    edx,0x1
   1f58a:	d3 e2                	shl    edx,cl
   1f58c:	4c 89 c1             	mov    rcx,r8
   1f58f:	83 ea 01             	sub    edx,0x1
   1f592:	48 31 f1             	xor    rcx,rsi
   1f595:	48 63 d2             	movsxd rdx,edx
   1f598:	48 85 d1             	test   rcx,rdx
   1f59b:	75 2b                	jne    1f5c8 <check_backup_super_block@@Base+0x1688>
   1f59d:	4d 85 c9             	test   r9,r9
   1f5a0:	74 1e                	je     1f5c0 <check_backup_super_block@@Base+0x1680>
   1f5a2:	4c 85 c2             	test   rdx,r8
   1f5a5:	74 19                	je     1f5c0 <check_backup_super_block@@Base+0x1680>
   1f5a7:	89 c1                	mov    ecx,eax
   1f5a9:	4c 89 d2             	mov    rdx,r10
   1f5ac:	49 d3 e8             	shr    r8,cl
   1f5af:	48 d3 ea             	shr    rdx,cl
   1f5b2:	49 39 d0             	cmp    r8,rdx
   1f5b5:	74 19                	je     1f5d0 <check_backup_super_block@@Base+0x1690>
   1f5b7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1f5be:	00 00 
   1f5c0:	31 c0                	xor    eax,eax
   1f5c2:	c3                   	ret    
   1f5c3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f5c8:	b8 01 00 00 00       	mov    eax,0x1
   1f5cd:	c3                   	ret    
   1f5ce:	66 90                	xchg   ax,ax
   1f5d0:	48 d3 ee             	shr    rsi,cl
   1f5d3:	49 d3 e9             	shr    r9,cl
   1f5d6:	31 c0                	xor    eax,eax
   1f5d8:	4c 39 ce             	cmp    rsi,r9
   1f5db:	0f 95 c0             	setne  al
   1f5de:	c3                   	ret    
   1f5df:	90                   	nop
   1f5e0:	89 f1                	mov    ecx,esi
   1f5e2:	d3 e7                	shl    edi,cl
   1f5e4:	48 8d 44 17 ff       	lea    rax,[rdi+rdx*1-0x1]
   1f5e9:	31 d2                	xor    edx,edx
   1f5eb:	48 f7 f7             	div    rdi
   1f5ee:	48 d3 e0             	shl    rax,cl
   1f5f1:	c3                   	ret    
   1f5f2:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1f5f9:	00 00 00 00 
   1f5fd:	0f 1f 00             	nop    DWORD PTR [rax]
   1f600:	41 57                	push   r15
   1f602:	41 56                	push   r14
   1f604:	41 55                	push   r13
   1f606:	49 89 cd             	mov    r13,rcx
   1f609:	41 54                	push   r12
   1f60b:	49 89 d4             	mov    r12,rdx
   1f60e:	55                   	push   rbp
   1f60f:	48 89 fd             	mov    rbp,rdi
   1f612:	53                   	push   rbx
   1f613:	48 89 f3             	mov    rbx,rsi
   1f616:	48 81 ec b8 00 00 00 	sub    rsp,0xb8
   1f61d:	48 8b 17             	mov    rdx,QWORD PTR [rdi]
   1f620:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1f627:	00 00 
   1f629:	48 89 84 24 a8 00 00 	mov    QWORD PTR [rsp+0xa8],rax
   1f630:	00 
   1f631:	8b 46 04             	mov    eax,DWORD PTR [rsi+0x4]
   1f634:	48 8b 52 20          	mov    rdx,QWORD PTR [rdx+0x20]
   1f638:	8b 4a 4c             	mov    ecx,DWORD PTR [rdx+0x4c]
   1f63b:	85 c9                	test   ecx,ecx
   1f63d:	74 79                	je     1f6b8 <check_backup_super_block@@Base+0x1778>
   1f63f:	8b 4a 54             	mov    ecx,DWORD PTR [rdx+0x54]
   1f642:	89 c6                	mov    esi,eax
   1f644:	39 c8                	cmp    eax,ecx
   1f646:	72 7b                	jb     1f6c3 <check_backup_super_block@@Base+0x1783>
   1f648:	3b 02                	cmp    eax,DWORD PTR [rdx]
   1f64a:	77 77                	ja     1f6c3 <check_backup_super_block@@Base+0x1783>
   1f64c:	4c 8d 74 24 20       	lea    r14,[rsp+0x20]
   1f651:	48 8d 0d 28 99 05 00 	lea    rcx,[rip+0x59928]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1f658:	48 89 ef             	mov    rdi,rbp
   1f65b:	4c 89 f2             	mov    rdx,r14
   1f65e:	e8 3d 58 01 00       	call   34ea0 <e2fsck_read_inode@@Base>
   1f663:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1f667:	48 8d 4c 24 1c       	lea    rcx,[rsp+0x1c]
   1f66c:	31 d2                	xor    edx,edx
   1f66e:	48 89 de             	mov    rsi,rbx
   1f671:	e8 7a 1b 03 00       	call   511f0 <ext2fs_ext_attr_hash_entry2@@Base>
   1f676:	49 89 c7             	mov    r15,rax
   1f679:	48 85 c0             	test   rax,rax
   1f67c:	0f 85 ae 00 00 00    	jne    1f730 <check_backup_super_block@@Base+0x17f0>
   1f682:	8b 43 0c             	mov    eax,DWORD PTR [rbx+0xc]
   1f685:	3b 44 24 1c          	cmp    eax,DWORD PTR [rsp+0x1c]
   1f689:	74 75                	je     1f700 <check_backup_super_block@@Base+0x17c0>
   1f68b:	41 8b 7c 24 08       	mov    edi,DWORD PTR [r12+0x8]
   1f690:	39 7c 24 30          	cmp    DWORD PTR [rsp+0x30],edi
   1f694:	0f 84 f6 00 00 00    	je     1f790 <check_backup_super_block@@Base+0x1850>
   1f69a:	f6 44 24 42 20       	test   BYTE PTR [rsp+0x42],0x20
   1f69f:	0f 85 db 00 00 00    	jne    1f780 <check_backup_super_block@@Base+0x1840>
   1f6a5:	8b 43 04             	mov    eax,DWORD PTR [rbx+0x4]
   1f6a8:	41 bd 83 00 01 00    	mov    r13d,0x10083
   1f6ae:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f6b3:	eb 19                	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f6b5:	0f 1f 00             	nop    DWORD PTR [rax]
   1f6b8:	b9 0b 00 00 00       	mov    ecx,0xb
   1f6bd:	89 c6                	mov    esi,eax
   1f6bf:	39 c8                	cmp    eax,ecx
   1f6c1:	73 85                	jae    1f648 <check_backup_super_block@@Base+0x1708>
   1f6c3:	49 89 74 24 50       	mov    QWORD PTR [r12+0x50],rsi
   1f6c8:	41 bd 83 00 01 00    	mov    r13d,0x10083
   1f6ce:	48 8b 84 24 a8 00 00 	mov    rax,QWORD PTR [rsp+0xa8]
   1f6d5:	00 
   1f6d6:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1f6dd:	00 00 
   1f6df:	0f 85 16 01 00 00    	jne    1f7fb <check_backup_super_block@@Base+0x18bb>
   1f6e5:	48 81 c4 b8 00 00 00 	add    rsp,0xb8
   1f6ec:	44 89 e8             	mov    eax,r13d
   1f6ef:	5b                   	pop    rbx
   1f6f0:	5d                   	pop    rbp
   1f6f1:	41 5c                	pop    r12
   1f6f3:	41 5d                	pop    r13
   1f6f5:	41 5e                	pop    r14
   1f6f7:	41 5f                	pop    r15
   1f6f9:	c3                   	ret    
   1f6fa:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1f700:	48 8b 45 00          	mov    rax,QWORD PTR [rbp+0x0]
   1f704:	8b 53 08             	mov    edx,DWORD PTR [rbx+0x8]
   1f707:	8b b0 c0 00 00 00    	mov    esi,DWORD PTR [rax+0xc0]
   1f70d:	8b 78 28             	mov    edi,DWORD PTR [rax+0x28]
   1f710:	e8 cb fe ff ff       	call   1f5e0 <check_backup_super_block@@Base+0x16a0>
   1f715:	49 89 45 00          	mov    QWORD PTR [r13+0x0],rax
   1f719:	44 8b 6c 24 40       	mov    r13d,DWORD PTR [rsp+0x40]
   1f71e:	41 81 e5 00 00 20 00 	and    r13d,0x200000
   1f725:	0f 84 85 00 00 00    	je     1f7b0 <check_backup_super_block@@Base+0x1870>
   1f72b:	45 31 ed             	xor    r13d,r13d
   1f72e:	eb 9e                	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f730:	8b 4b 04             	mov    ecx,DWORD PTR [rbx+0x4]
   1f733:	ba 05 00 00 00       	mov    edx,0x5
   1f738:	48 8d 35 11 9b 05 00 	lea    rsi,[rip+0x59b11]        # 79250 <_IO_stdin_used@@Base+0x2250>
   1f73f:	31 ff                	xor    edi,edi
   1f741:	89 4c 24 0c          	mov    DWORD PTR [rsp+0xc],ecx
   1f745:	e8 66 66 ff ff       	call   15db0 <dcgettext@plt>
   1f74a:	8b 4c 24 0c          	mov    ecx,DWORD PTR [rsp+0xc]
   1f74e:	4c 89 fe             	mov    rsi,r15
   1f751:	48 8d 3d 3a 98 05 00 	lea    rdi,[rip+0x5983a]        # 78f92 <_IO_stdin_used@@Base+0x1f92>
   1f758:	48 89 c2             	mov    rdx,rax
   1f75b:	31 c0                	xor    eax,eax
   1f75d:	e8 9e 6e 05 00       	call   76600 <com_err@@Base>
   1f762:	31 f6                	xor    esi,esi
   1f764:	48 89 ef             	mov    rdi,rbp
   1f767:	e8 c4 49 01 00       	call   34130 <fatal_error@@Base>
   1f76c:	8b 43 0c             	mov    eax,DWORD PTR [rbx+0xc]
   1f76f:	3b 44 24 1c          	cmp    eax,DWORD PTR [rsp+0x1c]
   1f773:	0f 85 12 ff ff ff    	jne    1f68b <check_backup_super_block@@Base+0x174b>
   1f779:	eb 85                	jmp    1f700 <check_backup_super_block@@Base+0x17c0>
   1f77b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1f780:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f785:	41 bd 54 00 01 00    	mov    r13d,0x10054
   1f78b:	e9 3e ff ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f790:	49 8b 54 24 18       	mov    rdx,QWORD PTR [r12+0x18]
   1f795:	8b 7a 64             	mov    edi,DWORD PTR [rdx+0x64]
   1f798:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [rsp+0x84],edi
   1f79f:	0f 85 f5 fe ff ff    	jne    1f69a <check_backup_super_block@@Base+0x175a>
   1f7a5:	31 c0                	xor    eax,eax
   1f7a7:	e9 69 ff ff ff       	jmp    1f715 <check_backup_super_block@@Base+0x17d5>
   1f7ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1f7b0:	8b 43 04             	mov    eax,DWORD PTR [rbx+0x4]
   1f7b3:	4c 89 e2             	mov    rdx,r12
   1f7b6:	be 86 00 01 00       	mov    esi,0x10086
   1f7bb:	48 89 ef             	mov    rdi,rbp
   1f7be:	49 89 44 24 50       	mov    QWORD PTR [r12+0x50],rax
   1f7c3:	e8 28 7a 01 00       	call   371f0 <fix_problem@@Base>
   1f7c8:	85 c0                	test   eax,eax
   1f7ca:	74 24                	je     1f7f0 <check_backup_super_block@@Base+0x18b0>
   1f7cc:	8b 73 04             	mov    esi,DWORD PTR [rbx+0x4]
   1f7cf:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1f7d3:	4c 89 f2             	mov    rdx,r14
   1f7d6:	81 4c 24 40 00 00 20 	or     DWORD PTR [rsp+0x40],0x200000
   1f7dd:	00 
   1f7de:	e8 3d ff 03 00       	call   5f720 <ext2fs_write_inode@@Base>
   1f7e3:	e9 e6 fe ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f7e8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1f7ef:	00 
   1f7f0:	41 bd 85 00 01 00    	mov    r13d,0x10085
   1f7f6:	e9 d3 fe ff ff       	jmp    1f6ce <check_backup_super_block@@Base+0x178e>
   1f7fb:	e8 00 66 ff ff       	call   15e00 <__stack_chk_fail@plt>

exec
/bin/bash -lc "strings -a -t x ./target.bin | awk '"'$1 >= "78d00" && $1 <= "79400"'"'" in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
  78d08 while calling ext2fs_block_iterate for inode %u
  78d38 while calling ext2fs_adjust_ea_refcount2 for inode %u
  78d6e release_inode_blocks
  78d83 block iterate buffer
  78d98 release_orphan_inodes
  78dae Truncating
  78db9 Clearing
  78dc2 delete_file
  78dce clear_resize
  78ddb resize dind buffer
  78dee invalid_inode_bitmap
  78e03 invalid_block_bitmap
  78e18 invalid_inode_table
  78e2c inodes_count
  78e39 first_data_block
  78e4a log_block_size
  78e59 log_cluster_size
  78e6a clusters_per_group
  78e7d blocks_per_group
  78e8e inodes_per_group
  78e9f r_blocks_count
  78eae reserved_gdt_blocks
  78ec2 desc_size
  78ecc first_ino
  78ed6 inode_size
  78ee1 clear_test_fs_flag
  78ef4 ext4
  78ef9 accept_time_fudge
  78f0b buggy_init_scripts
  78f1e inode in bad block map
  78f35 inode_bb_map
  78f42 imagic inode map
  78f53 inode_imagic_map
  78f64 bad inode map
  78f72 inode_bad_map
  78f80 pass1
  78f86 system.data
  78f92 check_large_ea_inode
  78fa7 reading directory block
  78fbf check_is_really_dir
  78fd3 multiply claimed block map
  78fee block_dup_map
  78ffc ext2fs_extent_get_info
  79013 ext2fs_extent_fix_parents
  7902d ext2fs_extent_delete
  79042 EXT2_EXTENT_UP
  79051 EXT2_EXTENT_DOWN
  79062 ext attr block map
  79075 block_ea_map
  79082 check_ext_attr
  79091 scratch_files
  7909f numdirs_threshold
  790b1 check_blocks_extents
  790c6 check_blocks
  790d3 getting next inode from scan
  790f0 in-use inode map
  79101 inode_used_map
  79110 directory inode map
  79124 inode_dir_map
  79132 regular file inode map
  79149 inode_reg_map
  79157 in-use block map
  79168 block_found_map
  79178 metadata block map
  7918b block_metadata_map
  7919e inode casefold map
  791b1 inode_casefold_map
  791c4 inode_link_info
  791d4 scratch inode
  791e2 array of inodes to process
  791fd block interate buffer
  79213 opening inode scan
  79226 clear bad inode
  79236 Pass 1
  7923d recreate inode
  79250 while hashing entry with e_value_inum = %u
  79280 %6lu(%c): expecting %6lu got phys %6lu (blkcnt %lld)
  792b8 %6lu(%c): expecting %6lu actual extent phys %6lu log %lu len %lu
  79300 reading indirect blocks of inode %u
  79328 lost+found
  79333 duplicate cluster header
  7934c inode element
  7935a duplicate inode header
  79371 cluster element
  79381 delete_file_block
  79393 clone_file_block
  793a4 clone_file
  793af clone file EA
  793bd Shared inode list
  793cf pass1b
  793d6 multiply claimed inode map
  793f1 inode_dup_map
  793ff Pass 1b

exec
/bin/bash -lc "nm -D -n ./target.bin | awk '"'$1 >= "000000000001e000" && $1 <= "0000000000021000"'"'" in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
exec
/bin/bash -lc 'readelf -n ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

Displaying notes found in: .note.gnu.property
  Owner                Data size 	Description
  GNU                  0x00000020	NT_GNU_PROPERTY_TYPE_0
      Properties: x86 feature: IBT, SHSTK
	x86 ISA needed: x86-64-baseline

Displaying notes found in: .note.gnu.build-id
  Owner                Data size 	Description
  GNU                  0x00000014	NT_GNU_BUILD_ID (unique build ID bitstring)
    Build ID: 3ab124450289058df9755ec817ad3dca6c742179

Displaying notes found in: .note.ABI-tag
  Owner                Data size 	Description
  GNU                  0x00000010	NT_GNU_ABI_TAG (ABI version tag)
    OS: Linux, ABI: 3.2.0

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x1e000 --stop-address=0x1ec90 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001e000 <check_backup_super_block@@Base+0xc0>:
   1e000:	53                   	push   rbx
   1e001:	ef                   	out    dx,eax
   1e002:	0f 85 c0 00 00 00    	jne    1e0c8 <check_backup_super_block@@Base+0x188>
   1e008:	8b 44 24 4c          	mov    eax,DWORD PTR [rsp+0x4c]
   1e00c:	83 f8 01             	cmp    eax,0x1
   1e00f:	0f 87 b3 00 00 00    	ja     1e0c8 <check_backup_super_block@@Base+0x188>
   1e015:	8b 4c 24 18          	mov    ecx,DWORD PTR [rsp+0x18]
   1e019:	8d 51 0a             	lea    edx,[rcx+0xa]
   1e01c:	83 fa 10             	cmp    edx,0x10
   1e01f:	0f 87 a3 00 00 00    	ja     1e0c8 <check_backup_super_block@@Base+0x188>
   1e025:	85 c0                	test   eax,eax
   1e027:	74 0c                	je     1e035 <check_backup_super_block@@Base+0xf5>
   1e029:	66 83 7c 24 58 7f    	cmp    WORD PTR [rsp+0x58],0x7f
   1e02f:	0f 86 93 00 00 00    	jbe    1e0c8 <check_backup_super_block@@Base+0x188>
   1e035:	48 8b 43 20          	mov    rax,QWORD PTR [rbx+0x20]
   1e039:	8b 4c 24 5c          	mov    ecx,DWORD PTR [rsp+0x5c]
   1e03d:	41 bc 01 00 00 00    	mov    r12d,0x1
   1e043:	39 48 5c             	cmp    DWORD PTR [rax+0x5c],ecx
   1e046:	75 5b                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e048:	8b 50 60             	mov    edx,DWORD PTR [rax+0x60]
   1e04b:	33 54 24 60          	xor    edx,DWORD PTR [rsp+0x60]
   1e04f:	83 e2 bb             	and    edx,0xffffffbb
   1e052:	75 4f                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e054:	8b 50 64             	mov    edx,DWORD PTR [rax+0x64]
   1e057:	33 54 24 64          	xor    edx,DWORD PTR [rsp+0x64]
   1e05b:	83 e2 dd             	and    edx,0xffffffdd
   1e05e:	75 43                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e060:	8b 4c 24 04          	mov    ecx,DWORD PTR [rsp+0x4]
   1e064:	39 48 04             	cmp    DWORD PTR [rax+0x4],ecx
   1e067:	75 3a                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e069:	8b 94 24 50 01 00 00 	mov    edx,DWORD PTR [rsp+0x150]
   1e070:	39 90 50 01 00 00    	cmp    DWORD PTR [rax+0x150],edx
   1e076:	75 2b                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e078:	8b 14 24             	mov    edx,DWORD PTR [rsp]
   1e07b:	39 10                	cmp    DWORD PTR [rax],edx
   1e07d:	75 24                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e07f:	48 8d 74 24 68       	lea    rsi,[rsp+0x68]
   1e084:	48 8d 78 68          	lea    rdi,[rax+0x68]
   1e088:	ba 10 00 00 00       	mov    edx,0x10
   1e08d:	e8 2e 7f ff ff       	call   15fc0 <memcmp@plt>
   1e092:	85 c0                	test   eax,eax
   1e094:	75 0d                	jne    1e0a3 <check_backup_super_block@@Base+0x163>
   1e096:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1e09d:	00 00 00 
   1e0a0:	45 31 e4             	xor    r12d,r12d
   1e0a3:	48 8b 84 24 08 04 00 	mov    rax,QWORD PTR [rsp+0x408]
   1e0aa:	00 
   1e0ab:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1e0b2:	00 00 
   1e0b4:	75 20                	jne    1e0d6 <check_backup_super_block@@Base+0x196>
   1e0b6:	48 81 c4 10 04 00 00 	add    rsp,0x410
   1e0bd:	44 89 e0             	mov    eax,r12d
   1e0c0:	5b                   	pop    rbx
   1e0c1:	5d                   	pop    rbp
   1e0c2:	41 5c                	pop    r12
   1e0c4:	c3                   	ret    
   1e0c5:	0f 1f 00             	nop    DWORD PTR [rax]
   1e0c8:	83 c5 01             	add    ebp,0x1
   1e0cb:	39 6b 30             	cmp    DWORD PTR [rbx+0x30],ebp
   1e0ce:	0f 87 ec fe ff ff    	ja     1dfc0 <check_backup_super_block@@Base+0x80>
   1e0d4:	eb ca                	jmp    1e0a0 <check_backup_super_block@@Base+0x160>
   1e0d6:	e8 25 7d ff ff       	call   15e00 <__stack_chk_fail@plt>
   1e0db:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1e0e0:	83 4f 60 40          	or     DWORD PTR [rdi+0x60],0x40
   1e0e4:	c3                   	ret    
   1e0e5:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e0ec:	00 00 00 00 
   1e0f0:	81 4f 60 00 40 00 00 	or     DWORD PTR [rdi+0x60],0x4000
   1e0f7:	c3                   	ret    
   1e0f8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1e0ff:	00 
   1e100:	81 4f 60 00 80 00 00 	or     DWORD PTR [rdi+0x60],0x8000
   1e107:	c3                   	ret    
   1e108:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1e10f:	00 
   1e110:	8b 47 20             	mov    eax,DWORD PTR [rdi+0x20]
   1e113:	25 00 08 00 40       	and    eax,0x40000800
   1e118:	3d 00 08 00 40       	cmp    eax,0x40000800
   1e11d:	0f 94 c0             	sete   al
   1e120:	0f b6 c0             	movzx  eax,al
   1e123:	c3                   	ret    
   1e124:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e12b:	00 00 00 00 
   1e12f:	90                   	nop
   1e130:	31 c0                	xor    eax,eax
   1e132:	48 81 ff ff ff ff 7f 	cmp    rdi,0x7fffffff
   1e139:	0f 97 c0             	seta   al
   1e13c:	c3                   	ret    
   1e13d:	0f 1f 00             	nop    DWORD PTR [rax]
   1e140:	48 8d 87 44 02 00 00 	lea    rax,[rdi+0x244]
   1e147:	83 fe 01             	cmp    esi,0x1
   1e14a:	74 1b                	je     1e167 <check_backup_super_block@@Base+0x227>
   1e14c:	48 8d 87 6c 02 00 00 	lea    rax,[rdi+0x26c]
   1e153:	83 fe 02             	cmp    esi,0x2
   1e156:	74 0f                	je     1e167 <check_backup_super_block@@Base+0x227>
   1e158:	48 81 c7 40 02 00 00 	add    rdi,0x240
   1e15f:	31 c0                	xor    eax,eax
   1e161:	85 f6                	test   esi,esi
   1e163:	48 0f 44 c7          	cmove  rax,rdi
   1e167:	c3                   	ret    
   1e168:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1e16f:	00 
   1e170:	31 c0                	xor    eax,eax
   1e172:	85 ff                	test   edi,edi
   1e174:	78 0a                	js     1e180 <check_backup_super_block@@Base+0x240>
   1e176:	c3                   	ret    
   1e177:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e17e:	00 00 
   1e180:	83 e6 03             	and    esi,0x3
   1e183:	31 c0                	xor    eax,eax
   1e185:	83 fe 03             	cmp    esi,0x3
   1e188:	0f 94 c0             	sete   al
   1e18b:	c3                   	ret    
   1e18c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1e190:	49 89 f8             	mov    r8,rdi
   1e193:	89 f1                	mov    ecx,esi
   1e195:	31 d2                	xor    edx,edx
   1e197:	89 d6                	mov    esi,edx
   1e199:	4c 89 c7             	mov    rdi,r8
   1e19c:	e8 9f ff ff ff       	call   1e140 <check_backup_super_block@@Base+0x200>
   1e1a1:	39 08                	cmp    DWORD PTR [rax],ecx
   1e1a3:	74 0b                	je     1e1b0 <check_backup_super_block@@Base+0x270>
   1e1a5:	83 c2 01             	add    edx,0x1
   1e1a8:	83 fa 03             	cmp    edx,0x3
   1e1ab:	75 ea                	jne    1e197 <check_backup_super_block@@Base+0x257>
   1e1ad:	31 c0                	xor    eax,eax
   1e1af:	c3                   	ret    
   1e1b0:	b8 01 00 00 00       	mov    eax,0x1
   1e1b5:	c3                   	ret    
   1e1b6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1e1bd:	00 00 00 
   1e1c0:	f3 0f 1e fa          	endbr64 
   1e1c4:	48 8b 87 e0 00 00 00 	mov    rax,QWORD PTR [rdi+0xe0]
   1e1cb:	41 b8 41 b7 2b 7f    	mov    r8d,0x7f2bb741
   1e1d1:	39 b0 18 02 00 00    	cmp    DWORD PTR [rax+0x218],esi
   1e1d7:	75 2b                	jne    1e204 <check_backup_super_block@@Base+0x2c4>
   1e1d9:	48 8b b0 20 02 00 00 	mov    rsi,QWORD PTR [rax+0x220]
   1e1e0:	48 85 f6             	test   rsi,rsi
   1e1e3:	74 1f                	je     1e204 <check_backup_super_block@@Base+0x2c4>
   1e1e5:	31 c0                	xor    eax,eax
   1e1e7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e1ee:	00 00 
   1e1f0:	8b 4c 06 28          	mov    ecx,DWORD PTR [rsi+rax*1+0x28]
   1e1f4:	89 0c 02             	mov    DWORD PTR [rdx+rax*1],ecx
   1e1f7:	48 83 c0 04          	add    rax,0x4
   1e1fb:	48 83 f8 3c          	cmp    rax,0x3c
   1e1ff:	75 ef                	jne    1e1f0 <check_backup_super_block@@Base+0x2b0>
   1e201:	45 31 c0             	xor    r8d,r8d
   1e204:	4c 89 c0             	mov    rax,r8
   1e207:	c3                   	ret    
   1e208:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1e20f:	00 
   1e210:	f3 0f 1e fa          	endbr64 
   1e214:	48 8b 87 e0 00 00 00 	mov    rax,QWORD PTR [rdi+0xe0]
   1e21b:	41 b8 41 b7 2b 7f    	mov    r8d,0x7f2bb741
   1e221:	39 b0 18 02 00 00    	cmp    DWORD PTR [rax+0x218],esi
   1e227:	75 55                	jne    1e27e <check_backup_super_block@@Base+0x33e>
   1e229:	48 8b 80 20 02 00 00 	mov    rax,QWORD PTR [rax+0x220]
   1e230:	48 85 c0             	test   rax,rax
   1e233:	74 49                	je     1e27e <check_backup_super_block@@Base+0x33e>
   1e235:	f3 0f 6f 00          	movdqu xmm0,XMMWORD PTR [rax]
   1e239:	45 31 c0             	xor    r8d,r8d
   1e23c:	0f 11 02             	movups XMMWORD PTR [rdx],xmm0
   1e23f:	f3 0f 6f 48 10       	movdqu xmm1,XMMWORD PTR [rax+0x10]
   1e244:	0f 11 4a 10          	movups XMMWORD PTR [rdx+0x10],xmm1
   1e248:	f3 0f 6f 50 20       	movdqu xmm2,XMMWORD PTR [rax+0x20]
   1e24d:	0f 11 52 20          	movups XMMWORD PTR [rdx+0x20],xmm2
   1e251:	f3 0f 6f 58 30       	movdqu xmm3,XMMWORD PTR [rax+0x30]
   1e256:	0f 11 5a 30          	movups XMMWORD PTR [rdx+0x30],xmm3
   1e25a:	f3 0f 6f 60 40       	movdqu xmm4,XMMWORD PTR [rax+0x40]
   1e25f:	0f 11 62 40          	movups XMMWORD PTR [rdx+0x40],xmm4
   1e263:	f3 0f 6f 68 50       	movdqu xmm5,XMMWORD PTR [rax+0x50]
   1e268:	0f 11 6a 50          	movups XMMWORD PTR [rdx+0x50],xmm5
   1e26c:	f3 0f 6f 70 60       	movdqu xmm6,XMMWORD PTR [rax+0x60]
   1e271:	0f 11 72 60          	movups XMMWORD PTR [rdx+0x60],xmm6
   1e275:	f3 0f 6f 78 70       	movdqu xmm7,XMMWORD PTR [rax+0x70]
   1e27a:	0f 11 7a 70          	movups XMMWORD PTR [rdx+0x70],xmm7
   1e27e:	4c 89 c0             	mov    rax,r8
   1e281:	c3                   	ret    
   1e282:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e289:	00 00 00 00 
   1e28d:	0f 1f 00             	nop    DWORD PTR [rax]
   1e290:	f3 0f 1e fa          	endbr64 
   1e294:	48 8b 87 e0 00 00 00 	mov    rax,QWORD PTR [rdi+0xe0]
   1e29b:	39 b0 18 02 00 00    	cmp    DWORD PTR [rax+0x218],esi
   1e2a1:	74 0d                	je     1e2b0 <check_backup_super_block@@Base+0x370>
   1e2a3:	b8 41 b7 2b 7f       	mov    eax,0x7f2bb741
   1e2a8:	c3                   	ret    
   1e2a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1e2b0:	48 8b 80 20 02 00 00 	mov    rax,QWORD PTR [rax+0x220]
   1e2b7:	48 85 c0             	test   rax,rax
   1e2ba:	74 e7                	je     1e2a3 <check_backup_super_block@@Base+0x363>
   1e2bc:	48 39 d0             	cmp    rax,rdx
   1e2bf:	74 e2                	je     1e2a3 <check_backup_super_block@@Base+0x363>
   1e2c1:	f3 0f 6f 02          	movdqu xmm0,XMMWORD PTR [rdx]
   1e2c5:	0f 11 00             	movups XMMWORD PTR [rax],xmm0
   1e2c8:	f3 0f 6f 4a 10       	movdqu xmm1,XMMWORD PTR [rdx+0x10]
   1e2cd:	0f 11 48 10          	movups XMMWORD PTR [rax+0x10],xmm1
   1e2d1:	f3 0f 6f 52 20       	movdqu xmm2,XMMWORD PTR [rdx+0x20]
   1e2d6:	0f 11 50 20          	movups XMMWORD PTR [rax+0x20],xmm2
   1e2da:	f3 0f 6f 5a 30       	movdqu xmm3,XMMWORD PTR [rdx+0x30]
   1e2df:	0f 11 58 30          	movups XMMWORD PTR [rax+0x30],xmm3
   1e2e3:	f3 0f 6f 62 40       	movdqu xmm4,XMMWORD PTR [rdx+0x40]
   1e2e8:	0f 11 60 40          	movups XMMWORD PTR [rax+0x40],xmm4
   1e2ec:	f3 0f 6f 6a 50       	movdqu xmm5,XMMWORD PTR [rdx+0x50]
   1e2f1:	0f 11 68 50          	movups XMMWORD PTR [rax+0x50],xmm5
   1e2f5:	f3 0f 6f 72 60       	movdqu xmm6,XMMWORD PTR [rdx+0x60]
   1e2fa:	0f 11 70 60          	movups XMMWORD PTR [rax+0x60],xmm6
   1e2fe:	f3 0f 6f 7a 70       	movdqu xmm7,XMMWORD PTR [rdx+0x70]
   1e303:	0f 11 78 70          	movups XMMWORD PTR [rax+0x70],xmm7
   1e307:	b8 41 b7 2b 7f       	mov    eax,0x7f2bb741
   1e30c:	c3                   	ret    
   1e30d:	0f 1f 00             	nop    DWORD PTR [rax]
   1e310:	f3 0f 1e fa          	endbr64 
   1e314:	48 8b 97 e0 00 00 00 	mov    rdx,QWORD PTR [rdi+0xe0]
   1e31b:	b8 41 b7 2b 7f       	mov    eax,0x7f2bb741
   1e320:	39 b2 18 02 00 00    	cmp    DWORD PTR [rdx+0x218],esi
   1e326:	75 25                	jne    1e34d <check_backup_super_block@@Base+0x40d>
   1e328:	48 8b 92 20 02 00 00 	mov    rdx,QWORD PTR [rdx+0x220]
   1e32f:	48 85 d2             	test   rdx,rdx
   1e332:	74 19                	je     1e34d <check_backup_super_block@@Base+0x40d>
   1e334:	0f b7 02             	movzx  eax,WORD PTR [rdx]
   1e337:	ba 4a b7 2b 7f       	mov    edx,0x7f2bb74a
   1e33c:	66 25 00 f0          	and    ax,0xf000
   1e340:	66 3d 00 40          	cmp    ax,0x4000
   1e344:	b8 00 00 00 00       	mov    eax,0x0
   1e349:	48 0f 45 c2          	cmovne rax,rdx
   1e34d:	c3                   	ret    
   1e34e:	66 90                	xchg   ax,ax
   1e350:	f3 0f 1e fa          	endbr64 
   1e354:	53                   	push   rbx
   1e355:	48 83 ec 10          	sub    rsp,0x10
   1e359:	48 8b 9f e0 00 00 00 	mov    rbx,QWORD PTR [rdi+0xe0]
   1e360:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1e367:	48 85 ff             	test   rdi,rdi
   1e36a:	74 54                	je     1e3c0 <check_backup_super_block@@Base+0x480>
   1e36c:	4c 8b 83 90 03 00 00 	mov    r8,QWORD PTR [rbx+0x390]
   1e373:	85 d2                	test   edx,edx
   1e375:	79 05                	jns    1e37c <check_backup_super_block@@Base+0x43c>
   1e377:	4d 85 c0             	test   r8,r8
   1e37a:	75 14                	jne    1e390 <check_backup_super_block@@Base+0x450>
   1e37c:	85 d2                	test   edx,edx
   1e37e:	7e 32                	jle    1e3b2 <check_backup_super_block@@Base+0x472>
   1e380:	48 83 c4 10          	add    rsp,0x10
   1e384:	5b                   	pop    rbx
   1e385:	e9 a6 e5 03 00       	jmp    5c930 <ext2fs_mark_block_bitmap2@@Base>
   1e38a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1e390:	4c 89 c7             	mov    rdi,r8
   1e393:	48 89 74 24 08       	mov    QWORD PTR [rsp+0x8],rsi
   1e398:	e8 b3 e5 03 00       	call   5c950 <ext2fs_test_block_bitmap2@@Base>
   1e39d:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
   1e3a2:	85 c0                	test   eax,eax
   1e3a4:	75 1a                	jne    1e3c0 <check_backup_super_block@@Base+0x480>
   1e3a6:	48 8b bb a0 01 00 00 	mov    rdi,QWORD PTR [rbx+0x1a0]
   1e3ad:	48 85 ff             	test   rdi,rdi
   1e3b0:	74 0e                	je     1e3c0 <check_backup_super_block@@Base+0x480>
   1e3b2:	48 83 c4 10          	add    rsp,0x10
   1e3b6:	5b                   	pop    rbx
   1e3b7:	e9 84 e5 03 00       	jmp    5c940 <ext2fs_unmark_block_bitmap2@@Base>
   1e3bc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1e3c0:	48 83 c4 10          	add    rsp,0x10
   1e3c4:	5b                   	pop    rbx
   1e3c5:	c3                   	ret    
   1e3c6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1e3cd:	00 00 00 
   1e3d0:	41 55                	push   r13
   1e3d2:	49 89 fd             	mov    r13,rdi
   1e3d5:	41 54                	push   r12
   1e3d7:	4c 8d 66 64          	lea    r12,[rsi+0x64]
   1e3db:	55                   	push   rbp
   1e3dc:	53                   	push   rbx
   1e3dd:	48 8d 5e 28          	lea    rbx,[rsi+0x28]
   1e3e1:	48 83 ec 08          	sub    rsp,0x8
   1e3e5:	0f 1f 00             	nop    DWORD PTR [rax]
   1e3e8:	49 8b 7d 20          	mov    rdi,QWORD PTR [r13+0x20]
   1e3ec:	8b 2b                	mov    ebp,DWORD PTR [rbx]
   1e3ee:	e8 dd b9 02 00       	call   49dd0 <ext2fs_blocks_count@@Base>
   1e3f3:	48 39 c5             	cmp    rbp,rax
   1e3f6:	73 20                	jae    1e418 <check_backup_super_block@@Base+0x4d8>
   1e3f8:	48 83 c3 04          	add    rbx,0x4
   1e3fc:	4c 39 e3             	cmp    rbx,r12
   1e3ff:	75 e7                	jne    1e3e8 <check_backup_super_block@@Base+0x4a8>
   1e401:	48 83 c4 08          	add    rsp,0x8
   1e405:	b8 01 00 00 00       	mov    eax,0x1
   1e40a:	5b                   	pop    rbx
   1e40b:	5d                   	pop    rbp
   1e40c:	41 5c                	pop    r12
   1e40e:	41 5d                	pop    r13
   1e410:	c3                   	ret    
   1e411:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1e418:	48 83 c4 08          	add    rsp,0x8
   1e41c:	31 c0                	xor    eax,eax
   1e41e:	5b                   	pop    rbx
   1e41f:	5d                   	pop    rbp
   1e420:	41 5c                	pop    r12
   1e422:	41 5d                	pop    r13
   1e424:	c3                   	ret    
   1e425:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e42c:	00 00 00 00 
   1e430:	41 54                	push   r12
   1e432:	53                   	push   rbx
   1e433:	48 89 fb             	mov    rbx,rdi
   1e436:	48 83 ec 78          	sub    rsp,0x78
   1e43a:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1e441:	00 00 
   1e443:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   1e448:	31 c0                	xor    eax,eax
   1e44a:	49 89 e4             	mov    r12,rsp
   1e44d:	4c 89 e7             	mov    rdi,r12
   1e450:	e8 5b 8d 01 00       	call   371b0 <clear_problem_context@@Base>
   1e455:	ba 05 00 00 00       	mov    edx,0x5
   1e45a:	48 8d 35 bd aa 05 00 	lea    rsi,[rip+0x5aabd]        # 78f1e <_IO_stdin_used@@Base+0x1f1e>
   1e461:	31 ff                	xor    edi,edi
   1e463:	e8 48 79 ff ff       	call   15db0 <dcgettext@plt>
   1e468:	48 8b 3b             	mov    rdi,QWORD PTR [rbx]
   1e46b:	ba 02 00 00 00       	mov    edx,0x2
   1e470:	4c 8d 83 80 01 00 00 	lea    r8,[rbx+0x180]
   1e477:	48 89 c6             	mov    rsi,rax
   1e47a:	48 8d 0d b4 aa 05 00 	lea    rcx,[rip+0x5aab4]        # 78f35 <_IO_stdin_used@@Base+0x1f35>
   1e481:	e8 8a 76 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   1e486:	48 89 04 24          	mov    QWORD PTR [rsp],rax
   1e48a:	48 85 c0             	test   rax,rax
   1e48d:	75 21                	jne    1e4b0 <check_backup_super_block@@Base+0x570>
   1e48f:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   1e494:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1e49b:	00 00 
   1e49d:	75 30                	jne    1e4cf <check_backup_super_block@@Base+0x58f>
   1e49f:	48 83 c4 78          	add    rsp,0x78
   1e4a3:	5b                   	pop    rbx
   1e4a4:	41 5c                	pop    r12
   1e4a6:	c3                   	ret    
   1e4a7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e4ae:	00 00 
   1e4b0:	4c 89 e2             	mov    rdx,r12
   1e4b3:	be 24 00 01 00       	mov    esi,0x10024
   1e4b8:	48 89 df             	mov    rdi,rbx
   1e4bb:	48 c7 44 24 50 04 00 	mov    QWORD PTR [rsp+0x50],0x4
   1e4c2:	00 00 
   1e4c4:	e8 27 8d 01 00       	call   371f0 <fix_problem@@Base>
   1e4c9:	83 4b 48 01          	or     DWORD PTR [rbx+0x48],0x1
   1e4cd:	eb c0                	jmp    1e48f <check_backup_super_block@@Base+0x54f>
   1e4cf:	e8 2c 79 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1e4d4:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e4db:	00 00 00 00 
   1e4df:	90                   	nop
   1e4e0:	41 54                	push   r12
   1e4e2:	53                   	push   rbx
   1e4e3:	48 89 fb             	mov    rbx,rdi
   1e4e6:	48 83 ec 78          	sub    rsp,0x78
   1e4ea:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1e4f1:	00 00 
   1e4f3:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   1e4f8:	31 c0                	xor    eax,eax
   1e4fa:	49 89 e4             	mov    r12,rsp
   1e4fd:	4c 89 e7             	mov    rdi,r12
   1e500:	e8 ab 8c 01 00       	call   371b0 <clear_problem_context@@Base>
   1e505:	ba 05 00 00 00       	mov    edx,0x5
   1e50a:	48 8d 35 31 aa 05 00 	lea    rsi,[rip+0x5aa31]        # 78f42 <_IO_stdin_used@@Base+0x1f42>
   1e511:	31 ff                	xor    edi,edi
   1e513:	e8 98 78 ff ff       	call   15db0 <dcgettext@plt>
   1e518:	48 8b 3b             	mov    rdi,QWORD PTR [rbx]
   1e51b:	ba 02 00 00 00       	mov    edx,0x2
   1e520:	4c 8d 83 88 01 00 00 	lea    r8,[rbx+0x188]
   1e527:	48 89 c6             	mov    rsi,rax
   1e52a:	48 8d 0d 22 aa 05 00 	lea    rcx,[rip+0x5aa22]        # 78f53 <_IO_stdin_used@@Base+0x1f53>
   1e531:	e8 da 75 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   1e536:	48 89 04 24          	mov    QWORD PTR [rsp],rax
   1e53a:	48 85 c0             	test   rax,rax
   1e53d:	75 21                	jne    1e560 <check_backup_super_block@@Base+0x620>
   1e53f:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   1e544:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1e54b:	00 00 
   1e54d:	75 30                	jne    1e57f <check_backup_super_block@@Base+0x63f>
   1e54f:	48 83 c4 78          	add    rsp,0x78
   1e553:	5b                   	pop    rbx
   1e554:	41 5c                	pop    r12
   1e556:	c3                   	ret    
   1e557:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e55e:	00 00 
   1e560:	4c 89 e2             	mov    rdx,r12
   1e563:	be 24 00 01 00       	mov    esi,0x10024
   1e568:	48 89 df             	mov    rdi,rbx
   1e56b:	48 c7 44 24 50 05 00 	mov    QWORD PTR [rsp+0x50],0x5
   1e572:	00 00 
   1e574:	e8 77 8c 01 00       	call   371f0 <fix_problem@@Base>
   1e579:	83 4b 48 01          	or     DWORD PTR [rbx+0x48],0x1
   1e57d:	eb c0                	jmp    1e53f <check_backup_super_block@@Base+0x5ff>
   1e57f:	e8 7c 78 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1e584:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1e58b:	00 00 00 00 
   1e58f:	90                   	nop
   1e590:	41 54                	push   r12
   1e592:	55                   	push   rbp
   1e593:	48 89 fd             	mov    rbp,rdi
   1e596:	53                   	push   rbx
   1e597:	48 89 f3             	mov    rbx,rsi
   1e59a:	48 83 ec 70          	sub    rsp,0x70
   1e59e:	48 8b bf 70 01 00 00 	mov    rdi,QWORD PTR [rdi+0x170]
   1e5a5:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1e5ac:	00 00 
   1e5ae:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   1e5b3:	31 c0                	xor    eax,eax
   1e5b5:	48 85 ff             	test   rdi,rdi
   1e5b8:	74 26                	je     1e5e0 <check_backup_super_block@@Base+0x6a0>
   1e5ba:	89 de                	mov    esi,ebx
   1e5bc:	e8 9f e3 03 00       	call   5c960 <ext2fs_mark_inode_bitmap2@@Base>
   1e5c1:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   1e5c6:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1e5cd:	00 00 
   1e5cf:	0f 85 7d 00 00 00    	jne    1e652 <check_backup_super_block@@Base+0x712>
   1e5d5:	48 83 c4 70          	add    rsp,0x70
   1e5d9:	5b                   	pop    rbx
   1e5da:	5d                   	pop    rbp
   1e5db:	41 5c                	pop    r12
   1e5dd:	c3                   	ret    
   1e5de:	66 90                	xchg   ax,ax
   1e5e0:	49 89 e4             	mov    r12,rsp
   1e5e3:	4c 89 e7             	mov    rdi,r12
   1e5e6:	e8 c5 8b 01 00       	call   371b0 <clear_problem_context@@Base>
   1e5eb:	ba 05 00 00 00       	mov    edx,0x5
   1e5f0:	48 8d 35 6d a9 05 00 	lea    rsi,[rip+0x5a96d]        # 78f64 <_IO_stdin_used@@Base+0x1f64>
   1e5f7:	31 ff                	xor    edi,edi
   1e5f9:	e8 b2 77 ff ff       	call   15db0 <dcgettext@plt>
   1e5fe:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   1e602:	ba 02 00 00 00       	mov    edx,0x2
   1e607:	4c 8d 85 70 01 00 00 	lea    r8,[rbp+0x170]
   1e60e:	48 89 c6             	mov    rsi,rax
   1e611:	48 8d 0d 5a a9 05 00 	lea    rcx,[rip+0x5a95a]        # 78f72 <_IO_stdin_used@@Base+0x1f72>
   1e618:	e8 f3 74 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   1e61d:	48 89 04 24          	mov    QWORD PTR [rsp],rax
   1e621:	48 85 c0             	test   rax,rax
   1e624:	75 0a                	jne    1e630 <check_backup_super_block@@Base+0x6f0>
   1e626:	48 8b bd 70 01 00 00 	mov    rdi,QWORD PTR [rbp+0x170]
   1e62d:	eb 8b                	jmp    1e5ba <check_backup_super_block@@Base+0x67a>
   1e62f:	90                   	nop
   1e630:	4c 89 e2             	mov    rdx,r12
   1e633:	be 24 00 01 00       	mov    esi,0x10024
   1e638:	48 89 ef             	mov    rdi,rbp
   1e63b:	48 c7 44 24 50 03 00 	mov    QWORD PTR [rsp+0x50],0x3
   1e642:	00 00 
   1e644:	e8 a7 8b 01 00       	call   371f0 <fix_problem@@Base>
   1e649:	83 4d 48 01          	or     DWORD PTR [rbp+0x48],0x1
   1e64d:	e9 6f ff ff ff       	jmp    1e5c1 <check_backup_super_block@@Base+0x681>
   1e652:	e8 a9 77 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1e657:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e65e:	00 00 
   1e660:	48 8b 46 18          	mov    rax,QWORD PTR [rsi+0x18]
   1e664:	f7 40 20 00 00 08 10 	test   DWORD PTR [rax+0x20],0x10080000
   1e66b:	75 03                	jne    1e670 <check_backup_super_block@@Base+0x730>
   1e66d:	c3                   	ret    
   1e66e:	66 90                	xchg   ax,ax
   1e670:	55                   	push   rbp
   1e671:	48 89 f2             	mov    rdx,rsi
   1e674:	48 89 fd             	mov    rbp,rdi
   1e677:	53                   	push   rbx
   1e678:	48 89 f3             	mov    rbx,rsi
   1e67b:	be 76 00 01 00       	mov    esi,0x10076
   1e680:	48 83 ec 08          	sub    rsp,0x8
   1e684:	e8 67 8b 01 00       	call   371f0 <fix_problem@@Base>
   1e689:	85 c0                	test   eax,eax
   1e68b:	74 23                	je     1e6b0 <check_backup_super_block@@Base+0x770>
   1e68d:	48 8b 53 18          	mov    rdx,QWORD PTR [rbx+0x18]
   1e691:	8b 73 08             	mov    esi,DWORD PTR [rbx+0x8]
   1e694:	48 89 ef             	mov    rdi,rbp
   1e697:	48 8d 0d e2 a8 05 00 	lea    rcx,[rip+0x5a8e2]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1e69e:	81 62 20 ff ff f7 ef 	and    DWORD PTR [rdx+0x20],0xeff7ffff
   1e6a5:	48 83 c4 08          	add    rsp,0x8
   1e6a9:	5b                   	pop    rbx
   1e6aa:	5d                   	pop    rbp
   1e6ab:	e9 40 69 01 00       	jmp    34ff0 <e2fsck_write_inode@@Base>
   1e6b0:	48 83 c4 08          	add    rsp,0x8
   1e6b4:	5b                   	pop    rbx
   1e6b5:	5d                   	pop    rbp
   1e6b6:	c3                   	ret    
   1e6b7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e6be:	00 00 
   1e6c0:	48 8b 46 18          	mov    rax,QWORD PTR [rsi+0x18]
   1e6c4:	f6 40 20 30          	test   BYTE PTR [rax+0x20],0x30
   1e6c8:	75 06                	jne    1e6d0 <check_backup_super_block@@Base+0x790>
   1e6ca:	c3                   	ret    
   1e6cb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1e6d0:	55                   	push   rbp
   1e6d1:	48 89 f2             	mov    rdx,rsi
   1e6d4:	48 89 fd             	mov    rbp,rdi
   1e6d7:	53                   	push   rbx
   1e6d8:	48 89 f3             	mov    rbx,rsi
   1e6db:	be 30 00 01 00       	mov    esi,0x10030
   1e6e0:	48 83 ec 08          	sub    rsp,0x8
   1e6e4:	e8 07 8b 01 00       	call   371f0 <fix_problem@@Base>
   1e6e9:	85 c0                	test   eax,eax
   1e6eb:	74 23                	je     1e710 <check_backup_super_block@@Base+0x7d0>
   1e6ed:	48 8b 53 18          	mov    rdx,QWORD PTR [rbx+0x18]
   1e6f1:	8b 73 08             	mov    esi,DWORD PTR [rbx+0x8]
   1e6f4:	48 89 ef             	mov    rdi,rbp
   1e6f7:	48 8d 0d 82 a8 05 00 	lea    rcx,[rip+0x5a882]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1e6fe:	83 62 20 cf          	and    DWORD PTR [rdx+0x20],0xffffffcf
   1e702:	48 83 c4 08          	add    rsp,0x8
   1e706:	5b                   	pop    rbx
   1e707:	5d                   	pop    rbp
   1e708:	e9 e3 68 01 00       	jmp    34ff0 <e2fsck_write_inode@@Base>
   1e70d:	0f 1f 00             	nop    DWORD PTR [rax]
   1e710:	48 83 c4 08          	add    rsp,0x8
   1e714:	5b                   	pop    rbx
   1e715:	5d                   	pop    rbp
   1e716:	c3                   	ret    
   1e717:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1e71e:	00 00 
   1e720:	41 54                	push   r12
   1e722:	55                   	push   rbp
   1e723:	53                   	push   rbx
   1e724:	48 8b 6e 18          	mov    rbp,QWORD PTR [rsi+0x18]
   1e728:	8b 45 6c             	mov    eax,DWORD PTR [rbp+0x6c]
   1e72b:	8b 55 04             	mov    edx,DWORD PTR [rbp+0x4]
   1e72e:	48 c1 e0 20          	shl    rax,0x20
   1e732:	48 09 d0             	or     rax,rdx
   1e735:	75 09                	jne    1e740 <check_backup_super_block@@Base+0x800>
   1e737:	5b                   	pop    rbx
   1e738:	5d                   	pop    rbp
   1e739:	41 5c                	pop    r12
   1e73b:	c3                   	ret    
   1e73c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1e740:	48 89 f3             	mov    rbx,rsi
   1e743:	48 89 f2             	mov    rdx,rsi
   1e746:	be 32 00 01 00       	mov    esi,0x10032
   1e74b:	49 89 fc             	mov    r12,rdi
   1e74e:	e8 9d 8a 01 00       	call   371f0 <fix_problem@@Base>
   1e753:	85 c0                	test   eax,eax
   1e755:	74 e0                	je     1e737 <check_backup_super_block@@Base+0x7f7>
   1e757:	49 8b 3c 24          	mov    rdi,QWORD PTR [r12]
   1e75b:	48 89 ee             	mov    rsi,rbp
   1e75e:	31 d2                	xor    edx,edx
   1e760:	e8 7b bf 02 00       	call   4a6e0 <ext2fs_inode_size_set@@Base>
   1e765:	48 8b 53 18          	mov    rdx,QWORD PTR [rbx+0x18]
   1e769:	8b 73 08             	mov    esi,DWORD PTR [rbx+0x8]
   1e76c:	4c 89 e7             	mov    rdi,r12
   1e76f:	5b                   	pop    rbx
   1e770:	48 8d 0d 09 a8 05 00 	lea    rcx,[rip+0x5a809]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1e777:	5d                   	pop    rbp
   1e778:	41 5c                	pop    r12
   1e77a:	e9 71 68 01 00       	jmp    34ff0 <e2fsck_write_inode@@Base>
   1e77f:	90                   	nop
   1e780:	f3 0f 1e fa          	endbr64 
   1e784:	8b 47 70             	mov    eax,DWORD PTR [rdi+0x70]
   1e787:	2b 46 70             	sub    eax,DWORD PTR [rsi+0x70]
   1e78a:	74 04                	je     1e790 <check_backup_super_block@@Base+0x850>
   1e78c:	c3                   	ret    
   1e78d:	0f 1f 00             	nop    DWORD PTR [rax]
   1e790:	41 54                	push   r12
   1e792:	49 89 fc             	mov    r12,rdi
   1e795:	48 8d 7f 18          	lea    rdi,[rdi+0x18]
   1e799:	55                   	push   rbp
   1e79a:	48 89 f5             	mov    rbp,rsi
   1e79d:	53                   	push   rbx
   1e79e:	e8 9d e7 03 00       	call   5cf40 <ext2fs_const_inode@@Base>
   1e7a3:	31 ff                	xor    edi,edi
   1e7a5:	48 89 c6             	mov    rsi,rax
   1e7a8:	e8 d3 be 02 00       	call   4a680 <ext2fs_file_acl_block@@Base>
   1e7ad:	48 8d 7d 18          	lea    rdi,[rbp+0x18]
   1e7b1:	48 89 c3             	mov    rbx,rax
   1e7b4:	e8 87 e7 03 00       	call   5cf40 <ext2fs_const_inode@@Base>
   1e7b9:	31 ff                	xor    edi,edi
   1e7bb:	48 89 c6             	mov    rsi,rax
   1e7be:	e8 bd be 02 00       	call   4a680 <ext2fs_file_acl_block@@Base>
   1e7c3:	49 89 c0             	mov    r8,rax
   1e7c6:	89 d8                	mov    eax,ebx
   1e7c8:	44 29 c0             	sub    eax,r8d
   1e7cb:	75 07                	jne    1e7d4 <check_backup_super_block@@Base+0x894>
   1e7cd:	41 8b 04 24          	mov    eax,DWORD PTR [r12]
   1e7d1:	2b 45 00             	sub    eax,DWORD PTR [rbp+0x0]
   1e7d4:	5b                   	pop    rbx
   1e7d5:	5d                   	pop    rbp
   1e7d6:	41 5c                	pop    r12
   1e7d8:	c3                   	ret    
   1e7d9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1e7e0:	41 57                	push   r15
   1e7e2:	41 56                	push   r14
   1e7e4:	41 55                	push   r13
   1e7e6:	41 54                	push   r12
   1e7e8:	49 89 fc             	mov    r12,rdi
   1e7eb:	55                   	push   rbp
   1e7ec:	53                   	push   rbx
   1e7ed:	48 81 ec 88 00 00 00 	sub    rsp,0x88
   1e7f4:	48 8b 2f             	mov    rbp,QWORD PTR [rdi]
   1e7f7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1e7fe:	00 00 
   1e800:	48 89 44 24 78       	mov    QWORD PTR [rsp+0x78],rax
   1e805:	31 c0                	xor    eax,eax
   1e807:	48 8d 7c 24 10       	lea    rdi,[rsp+0x10]
   1e80c:	48 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],rdi
   1e811:	e8 9a 89 01 00       	call   371b0 <clear_problem_context@@Base>
   1e816:	8b 4d 30             	mov    ecx,DWORD PTR [rbp+0x30]
   1e819:	85 c9                	test   ecx,ecx
   1e81b:	0f 84 5f 01 00 00    	je     1e980 <check_backup_super_block@@Base+0xa40>
   1e821:	31 db                	xor    ebx,ebx
   1e823:	eb 22                	jmp    1e847 <check_backup_super_block@@Base+0x907>
   1e825:	0f 1f 00             	nop    DWORD PTR [rax]
   1e828:	89 de                	mov    esi,ebx
   1e82a:	48 89 ef             	mov    rdi,rbp
   1e82d:	e8 0e ba 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1e832:	48 85 c0             	test   rax,rax
   1e835:	0f 85 d5 00 00 00    	jne    1e910 <check_backup_super_block@@Base+0x9d0>
   1e83b:	83 c3 01             	add    ebx,0x1
   1e83e:	39 5d 30             	cmp    DWORD PTR [rbp+0x30],ebx
   1e841:	0f 86 39 01 00 00    	jbe    1e980 <check_backup_super_block@@Base+0xa40>
   1e847:	49 8b 94 24 a0 01 00 	mov    rdx,QWORD PTR [r12+0x1a0]
   1e84e:	00 
   1e84f:	89 de                	mov    esi,ebx
   1e851:	48 89 ef             	mov    rdi,rbp
   1e854:	89 5c 24 50          	mov    DWORD PTR [rsp+0x50],ebx
   1e858:	e8 d3 9b 02 00       	call   48430 <ext2fs_reserve_super_and_bgd@@Base>
   1e85d:	49 8b 94 24 90 03 00 	mov    rdx,QWORD PTR [r12+0x390]
   1e864:	00 
   1e865:	89 de                	mov    esi,ebx
   1e867:	48 89 ef             	mov    rdi,rbp
   1e86a:	e8 c1 9b 02 00       	call   48430 <ext2fs_reserve_super_and_bgd@@Base>
   1e86f:	89 de                	mov    esi,ebx
   1e871:	48 89 ef             	mov    rdi,rbp
   1e874:	e8 57 ba 02 00       	call   4a2d0 <ext2fs_inode_table_loc@@Base>
   1e879:	48 85 c0             	test   rax,rax
   1e87c:	0f 85 9e 01 00 00    	jne    1ea20 <check_backup_super_block@@Base+0xae0>
   1e882:	89 de                	mov    esi,ebx
   1e884:	48 89 ef             	mov    rdi,rbp
   1e887:	e8 d4 b8 02 00       	call   4a160 <ext2fs_block_bitmap_loc@@Base>
   1e88c:	48 85 c0             	test   rax,rax
   1e88f:	74 97                	je     1e828 <check_backup_super_block@@Base+0x8e8>
   1e891:	89 de                	mov    esi,ebx
   1e893:	48 89 ef             	mov    rdi,rbp
   1e896:	e8 c5 b8 02 00       	call   4a160 <ext2fs_block_bitmap_loc@@Base>
   1e89b:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1e8a2:	00 
   1e8a3:	48 89 c6             	mov    rsi,rax
   1e8a6:	e8 a5 e0 03 00       	call   5c950 <ext2fs_test_block_bitmap2@@Base>
   1e8ab:	89 de                	mov    esi,ebx
   1e8ad:	48 89 ef             	mov    rdi,rbp
   1e8b0:	85 c0                	test   eax,eax
   1e8b2:	0f 84 f8 00 00 00    	je     1e9b0 <check_backup_super_block@@Base+0xa70>
   1e8b8:	e8 a3 b8 02 00       	call   4a160 <ext2fs_block_bitmap_loc@@Base>
   1e8bd:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
   1e8c2:	be 07 00 01 00       	mov    esi,0x10007
   1e8c7:	4c 89 e7             	mov    rdi,r12
   1e8ca:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
   1e8cf:	e8 1c 89 01 00       	call   371f0 <fix_problem@@Base>
   1e8d4:	85 c0                	test   eax,eax
   1e8d6:	0f 84 4c ff ff ff    	je     1e828 <check_backup_super_block@@Base+0x8e8>
   1e8dc:	49 8b 94 24 f8 01 00 	mov    rdx,QWORD PTR [r12+0x1f8]
   1e8e3:	00 
   1e8e4:	89 d8                	mov    eax,ebx
   1e8e6:	89 de                	mov    esi,ebx
   1e8e8:	48 89 ef             	mov    rdi,rbp
   1e8eb:	83 04 82 01          	add    DWORD PTR [rdx+rax*4],0x1
   1e8ef:	41 83 84 24 08 02 00 	add    DWORD PTR [r12+0x208],0x1
   1e8f6:	00 01 
   1e8f8:	e8 43 b9 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1e8fd:	48 85 c0             	test   rax,rax
   1e900:	0f 84 35 ff ff ff    	je     1e83b <check_backup_super_block@@Base+0x8fb>
   1e906:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1e90d:	00 00 00 
   1e910:	89 de                	mov    esi,ebx
   1e912:	48 89 ef             	mov    rdi,rbp
   1e915:	e8 26 b9 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1e91a:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1e921:	00 
   1e922:	48 89 c6             	mov    rsi,rax
   1e925:	e8 26 e0 03 00       	call   5c950 <ext2fs_test_block_bitmap2@@Base>
   1e92a:	89 de                	mov    esi,ebx
   1e92c:	48 89 ef             	mov    rdi,rbp
   1e92f:	85 c0                	test   eax,eax
   1e931:	0f 84 b1 00 00 00    	je     1e9e8 <check_backup_super_block@@Base+0xaa8>
   1e937:	e8 04 b9 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1e93c:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
   1e941:	be 08 00 01 00       	mov    esi,0x10008
   1e946:	4c 89 e7             	mov    rdi,r12
   1e949:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
   1e94e:	e8 9d 88 01 00       	call   371f0 <fix_problem@@Base>
   1e953:	85 c0                	test   eax,eax
   1e955:	0f 84 e0 fe ff ff    	je     1e83b <check_backup_super_block@@Base+0x8fb>
   1e95b:	49 8b 94 24 f0 01 00 	mov    rdx,QWORD PTR [r12+0x1f0]
   1e962:	00 
   1e963:	89 d8                	mov    eax,ebx
   1e965:	83 c3 01             	add    ebx,0x1
   1e968:	83 04 82 01          	add    DWORD PTR [rdx+rax*4],0x1
   1e96c:	41 83 84 24 08 02 00 	add    DWORD PTR [r12+0x208],0x1
   1e973:	00 01 
   1e975:	39 5d 30             	cmp    DWORD PTR [rbp+0x30],ebx
   1e978:	0f 87 c9 fe ff ff    	ja     1e847 <check_backup_super_block@@Base+0x907>
   1e97e:	66 90                	xchg   ax,ax
   1e980:	48 8b 44 24 78       	mov    rax,QWORD PTR [rsp+0x78]
   1e985:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1e98c:	00 00 
   1e98e:	0f 85 43 01 00 00    	jne    1ead7 <check_backup_super_block@@Base+0xb97>
   1e994:	48 81 c4 88 00 00 00 	add    rsp,0x88
   1e99b:	5b                   	pop    rbx
   1e99c:	5d                   	pop    rbp
   1e99d:	41 5c                	pop    r12
   1e99f:	41 5d                	pop    r13
   1e9a1:	41 5e                	pop    r14
   1e9a3:	41 5f                	pop    r15
   1e9a5:	c3                   	ret    
   1e9a6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1e9ad:	00 00 00 
   1e9b0:	e8 ab b7 02 00       	call   4a160 <ext2fs_block_bitmap_loc@@Base>
   1e9b5:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1e9bc:	00 
   1e9bd:	48 89 c6             	mov    rsi,rax
   1e9c0:	e8 6b df 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1e9c5:	89 de                	mov    esi,ebx
   1e9c7:	48 89 ef             	mov    rdi,rbp
   1e9ca:	e8 91 b7 02 00       	call   4a160 <ext2fs_block_bitmap_loc@@Base>
   1e9cf:	49 8b bc 24 90 03 00 	mov    rdi,QWORD PTR [r12+0x390]
   1e9d6:	00 
   1e9d7:	48 89 c6             	mov    rsi,rax
   1e9da:	e8 51 df 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1e9df:	e9 44 fe ff ff       	jmp    1e828 <check_backup_super_block@@Base+0x8e8>
   1e9e4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1e9e8:	e8 53 b8 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1e9ed:	49 8b bc 24 90 03 00 	mov    rdi,QWORD PTR [r12+0x390]
   1e9f4:	00 
   1e9f5:	48 89 c6             	mov    rsi,rax
   1e9f8:	e8 33 df 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1e9fd:	89 de                	mov    esi,ebx
   1e9ff:	48 89 ef             	mov    rdi,rbp
   1ea02:	e8 39 b8 02 00       	call   4a240 <ext2fs_inode_bitmap_loc@@Base>
   1ea07:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1ea0e:	00 
   1ea0f:	48 89 c6             	mov    rsi,rax
   1ea12:	e8 19 df 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1ea17:	e9 1f fe ff ff       	jmp    1e83b <check_backup_super_block@@Base+0x8fb>
   1ea1c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1ea20:	89 de                	mov    esi,ebx
   1ea22:	48 89 ef             	mov    rdi,rbp
   1ea25:	e8 a6 b8 02 00       	call   4a2d0 <ext2fs_inode_table_loc@@Base>
   1ea2a:	8b 55 48             	mov    edx,DWORD PTR [rbp+0x48]
   1ea2d:	49 89 c7             	mov    r15,rax
   1ea30:	85 d2                	test   edx,edx
   1ea32:	0f 84 4a fe ff ff    	je     1e882 <check_backup_super_block@@Base+0x942>
   1ea38:	41 89 de             	mov    r14d,ebx
   1ea3b:	45 31 ed             	xor    r13d,r13d
   1ea3e:	49 c1 e6 02          	shl    r14,0x2
   1ea42:	eb 2b                	jmp    1ea6f <check_backup_super_block@@Base+0xb2f>
   1ea44:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1ea48:	49 8b 84 24 00 02 00 	mov    rax,QWORD PTR [r12+0x200]
   1ea4f:	00 
   1ea50:	4c 89 7c 24 38       	mov    QWORD PTR [rsp+0x38],r15
   1ea55:	42 8b 04 30          	mov    eax,DWORD PTR [rax+r14*1]
   1ea59:	85 c0                	test   eax,eax
   1ea5b:	74 4b                	je     1eaa8 <check_backup_super_block@@Base+0xb68>
   1ea5d:	41 83 c5 01          	add    r13d,0x1
   1ea61:	49 83 c7 01          	add    r15,0x1
   1ea65:	44 39 6d 48          	cmp    DWORD PTR [rbp+0x48],r13d
   1ea69:	0f 86 13 fe ff ff    	jbe    1e882 <check_backup_super_block@@Base+0x942>
   1ea6f:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1ea76:	00 
   1ea77:	4c 89 fe             	mov    rsi,r15
   1ea7a:	e8 d1 de 03 00       	call   5c950 <ext2fs_test_block_bitmap2@@Base>
   1ea7f:	85 c0                	test   eax,eax
   1ea81:	75 c5                	jne    1ea48 <check_backup_super_block@@Base+0xb08>
   1ea83:	49 8b bc 24 a0 01 00 	mov    rdi,QWORD PTR [r12+0x1a0]
   1ea8a:	00 
   1ea8b:	4c 89 fe             	mov    rsi,r15
   1ea8e:	e8 9d de 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1ea93:	49 8b bc 24 90 03 00 	mov    rdi,QWORD PTR [r12+0x390]
   1ea9a:	00 
   1ea9b:	4c 89 fe             	mov    rsi,r15
   1ea9e:	e8 8d de 03 00       	call   5c930 <ext2fs_mark_block_bitmap2@@Base>
   1eaa3:	eb b8                	jmp    1ea5d <check_backup_super_block@@Base+0xb1d>
   1eaa5:	0f 1f 00             	nop    DWORD PTR [rax]
   1eaa8:	48 8b 54 24 08       	mov    rdx,QWORD PTR [rsp+0x8]
   1eaad:	be 09 00 01 00       	mov    esi,0x10009
   1eab2:	4c 89 e7             	mov    rdi,r12
   1eab5:	e8 36 87 01 00       	call   371f0 <fix_problem@@Base>
   1eaba:	85 c0                	test   eax,eax
   1eabc:	74 9f                	je     1ea5d <check_backup_super_block@@Base+0xb1d>
   1eabe:	49 8b 84 24 00 02 00 	mov    rax,QWORD PTR [r12+0x200]
   1eac5:	00 
   1eac6:	4c 01 f0             	add    rax,r14
   1eac9:	83 00 01             	add    DWORD PTR [rax],0x1
   1eacc:	41 83 84 24 08 02 00 	add    DWORD PTR [r12+0x208],0x1
   1ead3:	00 01 
   1ead5:	eb 86                	jmp    1ea5d <check_backup_super_block@@Base+0xb1d>
   1ead7:	e8 24 73 ff ff       	call   15e00 <__stack_chk_fail@plt>
   1eadc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1eae0:	41 57                	push   r15
   1eae2:	49 89 ff             	mov    r15,rdi
   1eae5:	41 56                	push   r14
   1eae7:	41 55                	push   r13
   1eae9:	41 54                	push   r12
   1eaeb:	55                   	push   rbp
   1eaec:	53                   	push   rbx
   1eaed:	48 83 ec 28          	sub    rsp,0x28
   1eaf1:	8b 06                	mov    eax,DWORD PTR [rsi]
   1eaf3:	48 83 bf 98 03 00 00 	cmp    QWORD PTR [rdi+0x398],0x0
   1eafa:	00 
   1eafb:	48 89 74 24 08       	mov    QWORD PTR [rsp+0x8],rsi
   1eb00:	48 8b 37             	mov    rsi,QWORD PTR [rdi]
   1eb03:	48 89 54 24 10       	mov    QWORD PTR [rsp+0x10],rdx
   1eb08:	89 44 24 18          	mov    DWORD PTR [rsp+0x18],eax
   1eb0c:	48 8b 56 20          	mov    rdx,QWORD PTR [rsi+0x20]
   1eb10:	0f 84 1d 01 00 00    	je     1ec33 <check_backup_super_block@@Base+0xcf3>
   1eb16:	8b 4a 18             	mov    ecx,DWORD PTR [rdx+0x18]
   1eb19:	44 8b 42 4c          	mov    r8d,DWORD PTR [rdx+0x4c]
   1eb1d:	b8 00 04 00 00       	mov    eax,0x400
   1eb22:	48 89 f7             	mov    rdi,rsi
   1eb25:	d3 e0                	shl    eax,cl
   1eb27:	b9 80 00 00 00       	mov    ecx,0x80
   1eb2c:	45 85 c0             	test   r8d,r8d
   1eb2f:	0f 85 2b 01 00 00    	jne    1ec60 <check_backup_super_block@@Base+0xd20>
   1eb35:	99                   	cdq    
   1eb36:	f7 f9                	idiv   ecx
   1eb38:	8b 4c 24 18          	mov    ecx,DWORD PTR [rsp+0x18]
   1eb3c:	89 c5                	mov    ebp,eax
   1eb3e:	b8 01 00 00 00       	mov    eax,0x1
   1eb43:	29 c8                	sub    eax,ecx
   1eb45:	89 44 24 1c          	mov    DWORD PTR [rsp+0x1c],eax
   1eb49:	3b 4e 30             	cmp    ecx,DWORD PTR [rsi+0x30]
   1eb4c:	0f 83 2a 01 00 00    	jae    1ec7c <check_backup_super_block@@Base+0xd3c>
   1eb52:	41 89 cd             	mov    r13d,ecx
   1eb55:	45 31 e4             	xor    r12d,r12d
   1eb58:	44 8d 75 ff          	lea    r14d,[rbp-0x1]
   1eb5c:	31 db                	xor    ebx,ebx
   1eb5e:	66 90                	xchg   ax,ax
   1eb60:	ba 01 00 00 00       	mov    edx,0x1
   1eb65:	44 89 ee             	mov    esi,r13d
   1eb68:	e8 73 ba 02 00       	call   4a5e0 <ext2fs_bg_flags_test@@Base>
   1eb6d:	49 8b 3f             	mov    rdi,QWORD PTR [r15]
   1eb70:	85 c0                	test   eax,eax
   1eb72:	75 36                	jne    1ebaa <check_backup_super_block@@Base+0xc6a>
   1eb74:	48 8b 47 20          	mov    rax,QWORD PTR [rdi+0x20]
   1eb78:	44 89 ee             	mov    esi,r13d
   1eb7b:	8b 58 28             	mov    ebx,DWORD PTR [rax+0x28]
   1eb7e:	e8 8d b9 02 00       	call   4a510 <ext2fs_bg_itable_unused@@Base>
   1eb83:	31 d2                	xor    edx,edx
   1eb85:	49 8b 3f             	mov    rdi,QWORD PTR [r15]
   1eb88:	29 c3                	sub    ebx,eax
   1eb8a:	41 8d 04 1e          	lea    eax,[r14+rbx*1]
   1eb8e:	f7 f5                	div    ebp
   1eb90:	8b 57 28             	mov    edx,DWORD PTR [rdi+0x28]
   1eb93:	49 01 c4             	add    r12,rax
   1eb96:	49 8b 87 98 03 00 00 	mov    rax,QWORD PTR [r15+0x398]
   1eb9d:	49 0f af d4          	imul   rdx,r12
   1eba1:	48 c1 e0 0a          	shl    rax,0xa
   1eba5:	48 39 c2             	cmp    rdx,rax
   1eba8:	77 0a                	ja     1ebb4 <check_backup_super_block@@Base+0xc74>
   1ebaa:	41 83 c5 01          	add    r13d,0x1
   1ebae:	44 39 6f 30          	cmp    DWORD PTR [rdi+0x30],r13d
   1ebb2:	77 ac                	ja     1eb60 <check_backup_super_block@@Base+0xc20>
   1ebb4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [rsp+0x1c]
   1ebb8:	44 01 e9             	add    ecx,r13d
   1ebbb:	8b 54 24 18          	mov    edx,DWORD PTR [rsp+0x18]
   1ebbf:	be 10 00 00 00       	mov    esi,0x10
   1ebc4:	e8 b7 f6 01 00       	call   3e280 <e2fsck_readahead@@Base>
   1ebc9:	48 83 f8 0b          	cmp    rax,0xb
   1ebcd:	0f 84 9d 00 00 00    	je     1ec70 <check_backup_super_block@@Base+0xd30>
   1ebd3:	48 85 c0             	test   rax,rax
   1ebd6:	75 58                	jne    1ec30 <check_backup_super_block@@Base+0xcf0>
   1ebd8:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   1ebdd:	41 8d 45 01          	lea    eax,[r13+0x1]
   1ebe1:	ba 08 00 00 00       	mov    edx,0x8
   1ebe6:	89 01                	mov    DWORD PTR [rcx],eax
   1ebe8:	41 8b 87 5c 02 00 00 	mov    eax,DWORD PTR [r15+0x25c]
   1ebef:	b9 80 00 00 00       	mov    ecx,0x80
   1ebf4:	85 c0                	test   eax,eax
   1ebf6:	0f 44 c2             	cmove  eax,edx
   1ebf9:	49 8b 17             	mov    rdx,QWORD PTR [r15]
   1ebfc:	0f af 42 28          	imul   eax,DWORD PTR [rdx+0x28]
   1ec00:	48 8b 52 20          	mov    rdx,QWORD PTR [rdx+0x20]
   1ec04:	8b 72 4c             	mov    esi,DWORD PTR [rdx+0x4c]
   1ec07:	85 f6                	test   esi,esi
   1ec09:	74 04                	je     1ec0f <check_backup_super_block@@Base+0xccf>
   1ec0b:	0f b7 4a 58          	movzx  ecx,WORD PTR [rdx+0x58]
   1ec0f:	44 8b 42 28          	mov    r8d,DWORD PTR [rdx+0x28]
   1ec13:	31 d2                	xor    edx,edx
   1ec15:	8d 7b ff             	lea    edi,[rbx-0x1]
   1ec18:	f7 f1                	div    ecx
   1ec1a:	31 d2                	xor    edx,edx
   1ec1c:	45 0f af c5          	imul   r8d,r13d
   1ec20:	42 8d 34 03          	lea    esi,[rbx+r8*1]
   1ec24:	89 c1                	mov    ecx,eax
   1ec26:	89 f8                	mov    eax,edi
   1ec28:	f7 f1                	div    ecx
   1ec2a:	89 f0                	mov    eax,esi
   1ec2c:	29 d0                	sub    eax,edx
   1ec2e:	eb 13                	jmp    1ec43 <check_backup_super_block@@Base+0xd03>
   1ec30:	49 8b 37             	mov    rsi,QWORD PTR [r15]
   1ec33:	8b 46 30             	mov    eax,DWORD PTR [rsi+0x30]
   1ec36:	48 8b 4c 24 08       	mov    rcx,QWORD PTR [rsp+0x8]
   1ec3b:	89 01                	mov    DWORD PTR [rcx],eax
   1ec3d:	48 8b 46 20          	mov    rax,QWORD PTR [rsi+0x20]
   1ec41:	8b 00                	mov    eax,DWORD PTR [rax]
   1ec43:	48 8b 4c 24 10       	mov    rcx,QWORD PTR [rsp+0x10]
   1ec48:	89 01                	mov    DWORD PTR [rcx],eax
   1ec4a:	48 83 c4 28          	add    rsp,0x28
   1ec4e:	5b                   	pop    rbx
   1ec4f:	5d                   	pop    rbp
   1ec50:	41 5c                	pop    r12
   1ec52:	41 5d                	pop    r13
   1ec54:	41 5e                	pop    r14
   1ec56:	41 5f                	pop    r15
   1ec58:	c3                   	ret    
   1ec59:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1ec60:	0f b7 4a 58          	movzx  ecx,WORD PTR [rdx+0x58]
   1ec64:	e9 cc fe ff ff       	jmp    1eb35 <check_backup_super_block@@Base+0xbf5>
   1ec69:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1ec70:	49 d1 af 98 03 00 00 	shr    QWORD PTR [r15+0x398],1
   1ec77:	e9 5c ff ff ff       	jmp    1ebd8 <check_backup_super_block@@Base+0xc98>
   1ec7c:	44 8b 6c 24 18       	mov    r13d,DWORD PTR [rsp+0x18]
   1ec81:	b9 01 00 00 00       	mov    ecx,0x1
   1ec86:	31 db                	xor    ebx,ebx
   1ec88:	e9 2e ff ff ff       	jmp    1ebbb <check_backup_super_block@@Base+0xc7b>
   1ec8d:	0f 1f 00             	nop    DWORD PTR [rax]

exec
/bin/bash -lc "objdump -d -M intel ./target.bin | rg 'call\\s+1fb80|lea["'^#]+#'"\\s*1fb80|1fb80 <'" in /tmp/llmdec_codex_6_u0et34
exec
/bin/bash -lc "objdump -d -M intel ./target.bin | rg 'call\\s+1f800|lea["'^#]+#'"\\s*1f800|1f800 <'" in /tmp/llmdec_codex_6_u0et34
 succeeded in 118ms:
   1fdc9:	e8 32 fa ff ff       	call   1f800 <check_backup_super_block@@Base+0x18c0>

 succeeded in 151ms:
   24ccb:	e8 b0 ae ff ff       	call   1fb80 <check_backup_super_block@@Base+0x1c40>

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x1fb80 --stop-address=0x1fe20 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001fb80 <check_backup_super_block@@Base+0x1c40>:
   1fb80:	41 57                	push   r15
   1fb82:	41 56                	push   r14
   1fb84:	41 55                	push   r13
   1fb86:	41 54                	push   r12
   1fb88:	55                   	push   rbp
   1fb89:	53                   	push   rbx
   1fb8a:	48 83 ec 08          	sub    rsp,0x8
   1fb8e:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   1fb91:	4c 8b 6e 18          	mov    r13,QWORD PTR [rsi+0x18]
   1fb95:	4c 8b 70 20          	mov    r14,QWORD PTR [rax+0x20]
   1fb99:	48 c7 02 00 00 00 00 	mov    QWORD PTR [rdx],0x0
   1fba0:	48 c7 42 08 00 00 00 	mov    QWORD PTR [rdx+0x8],0x0
   1fba7:	00 
   1fba8:	41 8b 4e 4c          	mov    ecx,DWORD PTR [r14+0x4c]
   1fbac:	85 c9                	test   ecx,ecx
   1fbae:	0f 84 88 01 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbb4:	49 89 d4             	mov    r12,rdx
   1fbb7:	41 0f b7 56 58       	movzx  edx,WORD PTR [r14+0x58]
   1fbbc:	66 81 fa 80 00       	cmp    dx,0x80
   1fbc1:	0f 84 75 01 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbc7:	41 0f b7 85 80 00 00 	movzx  eax,WORD PTR [r13+0x80]
   1fbce:	00 
   1fbcf:	48 89 fd             	mov    rbp,rdi
   1fbd2:	48 89 f3             	mov    rbx,rsi
   1fbd5:	44 8d 7a 80          	lea    r15d,[rdx-0x80]
   1fbd9:	66 85 c0             	test   ax,ax
   1fbdc:	0f 85 3e 01 00 00    	jne    1fd20 <check_backup_super_block@@Base+0x1de0>
   1fbe2:	49 63 d7             	movsxd rdx,r15d
   1fbe5:	48 83 ea 04          	sub    rdx,0x4
   1fbe9:	48 39 d0             	cmp    rax,rdx
   1fbec:	0f 83 4a 01 00 00    	jae    1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fbf2:	41 81 bc 05 80 00 00 	cmp    DWORD PTR [r13+rax*1+0x80],0xea020000
   1fbf9:	00 00 00 02 ea 
   1fbfe:	0f 84 bc 01 00 00    	je     1fdc0 <check_backup_super_block@@Base+0x1e80>
   1fc04:	48 b8 ff ff ff ff 01 	movabs rax,0x1ffffffff
   1fc0b:	00 00 00 
   1fc0e:	48 39 85 48 03 00 00 	cmp    QWORD PTR [rbp+0x348],rax
   1fc15:	0f 8f 21 01 00 00    	jg     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fc1b:	41 8b b5 8c 00 00 00 	mov    esi,DWORD PTR [r13+0x8c]
   1fc22:	41 8b 7d 08          	mov    edi,DWORD PTR [r13+0x8]
   1fc26:	e8 45 e5 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc2b:	85 c0                	test   eax,eax
   1fc2d:	75 18                	jne    1fc47 <check_backup_super_block@@Base+0x1d07>
   1fc2f:	41 8b b5 84 00 00 00 	mov    esi,DWORD PTR [r13+0x84]
   1fc36:	41 8b 7d 0c          	mov    edi,DWORD PTR [r13+0xc]
   1fc3a:	e8 31 e5 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc3f:	85 c0                	test   eax,eax
   1fc41:	0f 84 91 01 00 00    	je     1fdd8 <check_backup_super_block@@Base+0x1e98>
   1fc47:	48 89 da             	mov    rdx,rbx
   1fc4a:	be 82 00 01 00       	mov    esi,0x10082
   1fc4f:	48 89 ef             	mov    rdi,rbp
   1fc52:	e8 99 75 01 00       	call   371f0 <fix_problem@@Base>
   1fc57:	85 c0                	test   eax,eax
   1fc59:	0f 84 dd 00 00 00    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fc5f:	41 8b 95 8c 00 00 00 	mov    edx,DWORD PTR [r13+0x8c]
   1fc66:	41 8b 7d 08          	mov    edi,DWORD PTR [r13+0x8]
   1fc6a:	89 d6                	mov    esi,edx
   1fc6c:	e8 ff e4 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc71:	85 c0                	test   eax,eax
   1fc73:	74 0a                	je     1fc7f <check_backup_super_block@@Base+0x1d3f>
   1fc75:	83 e2 fc             	and    edx,0xfffffffc
   1fc78:	41 89 95 8c 00 00 00 	mov    DWORD PTR [r13+0x8c],edx
   1fc7f:	41 8b 95 84 00 00 00 	mov    edx,DWORD PTR [r13+0x84]
   1fc86:	41 8b 7d 0c          	mov    edi,DWORD PTR [r13+0xc]
   1fc8a:	89 d6                	mov    esi,edx
   1fc8c:	e8 df e4 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fc91:	85 c0                	test   eax,eax
   1fc93:	74 0a                	je     1fc9f <check_backup_super_block@@Base+0x1d5f>
   1fc95:	83 e2 fc             	and    edx,0xfffffffc
   1fc98:	41 89 95 84 00 00 00 	mov    DWORD PTR [r13+0x84],edx
   1fc9f:	41 8b 95 94 00 00 00 	mov    edx,DWORD PTR [r13+0x94]
   1fca6:	41 8b bd 90 00 00 00 	mov    edi,DWORD PTR [r13+0x90]
   1fcad:	89 d6                	mov    esi,edx
   1fcaf:	e8 bc e4 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fcb4:	85 c0                	test   eax,eax
   1fcb6:	74 0a                	je     1fcc2 <check_backup_super_block@@Base+0x1d82>
   1fcb8:	83 e2 fc             	and    edx,0xfffffffc
   1fcbb:	41 89 95 94 00 00 00 	mov    DWORD PTR [r13+0x94],edx
   1fcc2:	41 8b 95 88 00 00 00 	mov    edx,DWORD PTR [r13+0x88]
   1fcc9:	41 8b 7d 10          	mov    edi,DWORD PTR [r13+0x10]
   1fccd:	89 d6                	mov    esi,edx
   1fccf:	e8 9c e4 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fcd4:	85 c0                	test   eax,eax
   1fcd6:	74 0a                	je     1fce2 <check_backup_super_block@@Base+0x1da2>
   1fcd8:	83 e2 fc             	and    edx,0xfffffffc
   1fcdb:	41 89 95 88 00 00 00 	mov    DWORD PTR [r13+0x88],edx
   1fce2:	41 8b 46 4c          	mov    eax,DWORD PTR [r14+0x4c]
   1fce6:	b9 80 00 00 00       	mov    ecx,0x80
   1fceb:	85 c0                	test   eax,eax
   1fced:	74 05                	je     1fcf4 <check_backup_super_block@@Base+0x1db4>
   1fcef:	41 0f b7 4e 58       	movzx  ecx,WORD PTR [r14+0x58]
   1fcf4:	48 8b 53 18          	mov    rdx,QWORD PTR [rbx+0x18]
   1fcf8:	8b 73 08             	mov    esi,DWORD PTR [rbx+0x8]
   1fcfb:	48 83 c4 08          	add    rsp,0x8
   1fcff:	48 89 ef             	mov    rdi,rbp
   1fd02:	5b                   	pop    rbx
   1fd03:	4c 8d 05 76 92 05 00 	lea    r8,[rip+0x59276]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1fd0a:	5d                   	pop    rbp
   1fd0b:	41 5c                	pop    r12
   1fd0d:	41 5d                	pop    r13
   1fd0f:	41 5e                	pop    r14
   1fd11:	41 5f                	pop    r15
   1fd13:	e9 68 52 01 00       	jmp    34f80 <e2fsck_write_inode_full@@Base>
   1fd18:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1fd1f:	00 
   1fd20:	0f b7 d0             	movzx  edx,ax
   1fd23:	44 39 fa             	cmp    edx,r15d
   1fd26:	7e 28                	jle    1fd50 <check_backup_super_block@@Base+0x1e10>
   1fd28:	48 89 da             	mov    rdx,rbx
   1fd2b:	be 4f 00 01 00       	mov    esi,0x1004f
   1fd30:	48 89 ef             	mov    rdi,rbp
   1fd33:	e8 b8 74 01 00       	call   371f0 <fix_problem@@Base>
   1fd38:	85 c0                	test   eax,eax
   1fd3a:	75 24                	jne    1fd60 <check_backup_super_block@@Base+0x1e20>
   1fd3c:	48 83 c4 08          	add    rsp,0x8
   1fd40:	5b                   	pop    rbx
   1fd41:	5d                   	pop    rbp
   1fd42:	41 5c                	pop    r12
   1fd44:	41 5d                	pop    r13
   1fd46:	41 5e                	pop    r14
   1fd48:	41 5f                	pop    r15
   1fd4a:	c3                   	ret    
   1fd4b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1fd50:	66 83 f8 03          	cmp    ax,0x3
   1fd54:	76 d2                	jbe    1fd28 <check_backup_super_block@@Base+0x1de8>
   1fd56:	a8 03                	test   al,0x3
   1fd58:	0f 84 84 fe ff ff    	je     1fbe2 <check_backup_super_block@@Base+0x1ca2>
   1fd5e:	eb c8                	jmp    1fd28 <check_backup_super_block@@Base+0x1de8>
   1fd60:	41 0f b7 85 80 00 00 	movzx  eax,WORD PTR [r13+0x80]
   1fd67:	00 
   1fd68:	66 83 f8 03          	cmp    ax,0x3
   1fd6c:	76 0c                	jbe    1fd7a <check_backup_super_block@@Base+0x1e3a>
   1fd6e:	0f b7 d0             	movzx  edx,ax
   1fd71:	44 39 fa             	cmp    edx,r15d
   1fd74:	0f 8e 96 00 00 00    	jle    1fe10 <check_backup_super_block@@Base+0x1ed0>
   1fd7a:	41 0f b7 86 5e 01 00 	movzx  eax,WORD PTR [r14+0x15e]
   1fd81:	00 
   1fd82:	41 8b 56 4c          	mov    edx,DWORD PTR [r14+0x4c]
   1fd86:	66 41 89 85 80 00 00 	mov    WORD PTR [r13+0x80],ax
   1fd8d:	00 
   1fd8e:	b9 80 00 00 00       	mov    ecx,0x80
   1fd93:	85 d2                	test   edx,edx
   1fd95:	74 05                	je     1fd9c <check_backup_super_block@@Base+0x1e5c>
   1fd97:	41 0f b7 4e 58       	movzx  ecx,WORD PTR [r14+0x58]
   1fd9c:	48 8b 53 18          	mov    rdx,QWORD PTR [rbx+0x18]
   1fda0:	8b 73 08             	mov    esi,DWORD PTR [rbx+0x8]
   1fda3:	4c 8d 05 d6 91 05 00 	lea    r8,[rip+0x591d6]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   1fdaa:	48 89 ef             	mov    rdi,rbp
   1fdad:	e8 ce 51 01 00       	call   34f80 <e2fsck_write_inode_full@@Base>
   1fdb2:	41 0f b7 85 80 00 00 	movzx  eax,WORD PTR [r13+0x80]
   1fdb9:	00 
   1fdba:	e9 23 fe ff ff       	jmp    1fbe2 <check_backup_super_block@@Base+0x1ca2>
   1fdbf:	90                   	nop
   1fdc0:	4c 89 e2             	mov    rdx,r12
   1fdc3:	48 89 de             	mov    rsi,rbx
   1fdc6:	48 89 ef             	mov    rdi,rbp
   1fdc9:	e8 32 fa ff ff       	call   1f800 <check_backup_super_block@@Base+0x18c0>
   1fdce:	e9 31 fe ff ff       	jmp    1fc04 <check_backup_super_block@@Base+0x1cc4>
   1fdd3:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   1fdd8:	41 8b b5 94 00 00 00 	mov    esi,DWORD PTR [r13+0x94]
   1fddf:	41 8b bd 90 00 00 00 	mov    edi,DWORD PTR [r13+0x90]
   1fde6:	e8 85 e3 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fdeb:	85 c0                	test   eax,eax
   1fded:	0f 85 54 fe ff ff    	jne    1fc47 <check_backup_super_block@@Base+0x1d07>
   1fdf3:	41 8b b5 88 00 00 00 	mov    esi,DWORD PTR [r13+0x88]
   1fdfa:	41 8b 7d 10          	mov    edi,DWORD PTR [r13+0x10]
   1fdfe:	e8 6d e3 ff ff       	call   1e170 <check_backup_super_block@@Base+0x230>
   1fe03:	85 c0                	test   eax,eax
   1fe05:	0f 84 31 ff ff ff    	je     1fd3c <check_backup_super_block@@Base+0x1dfc>
   1fe0b:	e9 37 fe ff ff       	jmp    1fc47 <check_backup_super_block@@Base+0x1d07>
   1fe10:	83 c0 03             	add    eax,0x3
   1fe13:	83 e0 fc             	and    eax,0xfffffffc
   1fe16:	e9 67 ff ff ff       	jmp    1fd82 <check_backup_super_block@@Base+0x1e42>
   1fe1b:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x34e70 --stop-address=0x35000 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000034e70 <print_resource_track@@Base+0x320>:
   34e70:	40 e9 ed fd ff ff    	rex jmp 34c63 <print_resource_track@@Base+0x113>
   34e76:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   34e7d:	00 00 00 
   34e80:	45 31 c0             	xor    r8d,r8d
   34e83:	45 31 c9             	xor    r9d,r9d
   34e86:	66 0f ef d2          	pxor   xmm2,xmm2
   34e8a:	e9 15 ff ff ff       	jmp    34da4 <print_resource_track@@Base+0x254>
   34e8f:	e8 6c 0f fe ff       	call   15e00 <__stack_chk_fail@plt>
   34e94:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   34e9b:	00 00 00 00 
   34e9f:	90                   	nop

0000000000034ea0 <e2fsck_read_inode@@Base>:
   34ea0:	f3 0f 1e fa          	endbr64 
   34ea4:	41 55                	push   r13
   34ea6:	49 89 f5             	mov    r13,rsi
   34ea9:	41 54                	push   r12
   34eab:	55                   	push   rbp
   34eac:	48 89 fd             	mov    rbp,rdi
   34eaf:	53                   	push   rbx
   34eb0:	48 89 cb             	mov    rbx,rcx
   34eb3:	48 83 ec 08          	sub    rsp,0x8
   34eb7:	48 8b 3f             	mov    rdi,QWORD PTR [rdi]
   34eba:	e8 91 a4 02 00       	call   5f350 <ext2fs_read_inode@@Base>
   34ebf:	48 85 c0             	test   rax,rax
   34ec2:	75 0b                	jne    34ecf <e2fsck_read_inode@@Base+0x2f>
   34ec4:	48 83 c4 08          	add    rsp,0x8
   34ec8:	5b                   	pop    rbx
   34ec9:	5d                   	pop    rbp
   34eca:	41 5c                	pop    r12
   34ecc:	41 5d                	pop    r13
   34ece:	c3                   	ret    
   34ecf:	ba 05 00 00 00       	mov    edx,0x5
   34ed4:	48 8d 35 72 4e 04 00 	lea    rsi,[rip+0x44e72]        # 79d4d <_IO_stdin_used@@Base+0x2d4d>
   34edb:	31 ff                	xor    edi,edi
   34edd:	49 89 c4             	mov    r12,rax
   34ee0:	e8 cb 0e fe ff       	call   15db0 <dcgettext@plt>
   34ee5:	4c 89 e6             	mov    rsi,r12
   34ee8:	49 89 d8             	mov    r8,rbx
   34eeb:	4c 89 e9             	mov    rcx,r13
   34eee:	48 89 c2             	mov    rdx,rax
   34ef1:	48 8d 3d 73 4e 04 00 	lea    rdi,[rip+0x44e73]        # 79d6b <_IO_stdin_used@@Base+0x2d6b>
   34ef8:	31 c0                	xor    eax,eax
   34efa:	e8 01 17 04 00       	call   76600 <com_err@@Base>
   34eff:	31 f6                	xor    esi,esi
   34f01:	48 89 ef             	mov    rdi,rbp
   34f04:	e8 27 f2 ff ff       	call   34130 <fatal_error@@Base>
   34f09:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000034f10 <e2fsck_read_inode_full@@Base>:
   34f10:	f3 0f 1e fa          	endbr64 
   34f14:	41 55                	push   r13
   34f16:	49 89 f5             	mov    r13,rsi
   34f19:	41 54                	push   r12
   34f1b:	55                   	push   rbp
   34f1c:	48 89 fd             	mov    rbp,rdi
   34f1f:	53                   	push   rbx
   34f20:	4c 89 c3             	mov    rbx,r8
   34f23:	48 83 ec 08          	sub    rsp,0x8
   34f27:	48 8b 3f             	mov    rdi,QWORD PTR [rdi]
   34f2a:	e8 11 a4 02 00       	call   5f340 <ext2fs_read_inode_full@@Base>
   34f2f:	48 85 c0             	test   rax,rax
   34f32:	75 0b                	jne    34f3f <e2fsck_read_inode_full@@Base+0x2f>
   34f34:	48 83 c4 08          	add    rsp,0x8
   34f38:	5b                   	pop    rbx
   34f39:	5d                   	pop    rbp
   34f3a:	41 5c                	pop    r12
   34f3c:	41 5d                	pop    r13
   34f3e:	c3                   	ret    
   34f3f:	ba 05 00 00 00       	mov    edx,0x5
   34f44:	48 8d 35 02 4e 04 00 	lea    rsi,[rip+0x44e02]        # 79d4d <_IO_stdin_used@@Base+0x2d4d>
   34f4b:	31 ff                	xor    edi,edi
   34f4d:	49 89 c4             	mov    r12,rax
   34f50:	e8 5b 0e fe ff       	call   15db0 <dcgettext@plt>
   34f55:	4c 89 e6             	mov    rsi,r12
   34f58:	49 89 d8             	mov    r8,rbx
   34f5b:	4c 89 e9             	mov    rcx,r13
   34f5e:	48 89 c2             	mov    rdx,rax
   34f61:	48 8d 3d 15 4e 04 00 	lea    rdi,[rip+0x44e15]        # 79d7d <_IO_stdin_used@@Base+0x2d7d>
   34f68:	31 c0                	xor    eax,eax
   34f6a:	e8 91 16 04 00       	call   76600 <com_err@@Base>
   34f6f:	31 f6                	xor    esi,esi
   34f71:	48 89 ef             	mov    rdi,rbp
   34f74:	e8 b7 f1 ff ff       	call   34130 <fatal_error@@Base>
   34f79:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000034f80 <e2fsck_write_inode_full@@Base>:
   34f80:	f3 0f 1e fa          	endbr64 
   34f84:	41 55                	push   r13
   34f86:	49 89 f5             	mov    r13,rsi
   34f89:	41 54                	push   r12
   34f8b:	55                   	push   rbp
   34f8c:	48 89 fd             	mov    rbp,rdi
   34f8f:	53                   	push   rbx
   34f90:	4c 89 c3             	mov    rbx,r8
   34f93:	48 83 ec 08          	sub    rsp,0x8
   34f97:	48 8b 3f             	mov    rdi,QWORD PTR [rdi]
   34f9a:	e8 71 a7 02 00       	call   5f710 <ext2fs_write_inode_full@@Base>
   34f9f:	48 85 c0             	test   rax,rax
   34fa2:	75 0b                	jne    34faf <e2fsck_write_inode_full@@Base+0x2f>
   34fa4:	48 83 c4 08          	add    rsp,0x8
   34fa8:	5b                   	pop    rbx
   34fa9:	5d                   	pop    rbp
   34faa:	41 5c                	pop    r12
   34fac:	41 5d                	pop    r13
   34fae:	c3                   	ret    
   34faf:	ba 05 00 00 00       	mov    edx,0x5
   34fb4:	48 8d 35 d9 4d 04 00 	lea    rsi,[rip+0x44dd9]        # 79d94 <_IO_stdin_used@@Base+0x2d94>
   34fbb:	31 ff                	xor    edi,edi
   34fbd:	49 89 c4             	mov    r12,rax
   34fc0:	e8 eb 0d fe ff       	call   15db0 <dcgettext@plt>
   34fc5:	4c 89 e6             	mov    rsi,r12
   34fc8:	49 89 d8             	mov    r8,rbx
   34fcb:	4c 89 e9             	mov    rcx,r13
   34fce:	48 89 c2             	mov    rdx,rax
   34fd1:	48 8d 3d 22 46 04 00 	lea    rdi,[rip+0x44622]        # 795fa <_IO_stdin_used@@Base+0x25fa>
   34fd8:	31 c0                	xor    eax,eax
   34fda:	e8 21 16 04 00       	call   76600 <com_err@@Base>
   34fdf:	31 f6                	xor    esi,esi
   34fe1:	48 89 ef             	mov    rdi,rbp
   34fe4:	e8 47 f1 ff ff       	call   34130 <fatal_error@@Base>
   34fe9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000034ff0 <e2fsck_write_inode@@Base>:
   34ff0:	f3 0f 1e fa          	endbr64 
   34ff4:	41 55                	push   r13
   34ff6:	49 89 f5             	mov    r13,rsi
   34ff9:	41 54                	push   r12
   34ffb:	55                   	push   rbp
   34ffc:	48 89 fd             	mov    rbp,rdi
   34fff:	53                   	push   rbx

exec
/bin/bash -lc 'size ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
   text	   data	    bss	    dec	    hex	filename
 714317	  25296	   1513	 741126	  b4f06	./target.bin

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x37180 --stop-address=0x37240 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000037180 <set_latch_flags@@Base+0x20>:
   37180:	c3                   	ret    
   37181:	b8 ff ff ff ff       	mov    eax,0xffffffff
   37186:	c3                   	ret    
   37187:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   3718e:	00 00 

0000000000037190 <get_latch_flags@@Base>:
   37190:	f3 0f 1e fa          	endbr64 
   37194:	e8 d7 fb ff ff       	call   36d70 <ehandler_init@@Base+0x70>
   37199:	48 85 c0             	test   rax,rax
   3719c:	74 08                	je     371a6 <get_latch_flags@@Base+0x16>
   3719e:	8b 40 0c             	mov    eax,DWORD PTR [rax+0xc]
   371a1:	89 06                	mov    DWORD PTR [rsi],eax
   371a3:	31 c0                	xor    eax,eax
   371a5:	c3                   	ret    
   371a6:	b8 ff ff ff ff       	mov    eax,0xffffffff
   371ab:	c3                   	ret    
   371ac:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000000371b0 <clear_problem_context@@Base>:
   371b0:	f3 0f 1e fa          	endbr64 
   371b4:	48 c7 07 00 00 00 00 	mov    QWORD PTR [rdi],0x0
   371bb:	48 89 fa             	mov    rdx,rdi
   371be:	48 8d 7f 08          	lea    rdi,[rdi+0x8]
   371c2:	31 c0                	xor    eax,eax
   371c4:	48 c7 47 58 00 00 00 	mov    QWORD PTR [rdi+0x58],0x0
   371cb:	00 
   371cc:	48 89 d1             	mov    rcx,rdx
   371cf:	48 83 e7 f8          	and    rdi,0xfffffffffffffff8
   371d3:	48 29 f9             	sub    rcx,rdi
   371d6:	83 c1 68             	add    ecx,0x68
   371d9:	c1 e9 03             	shr    ecx,0x3
   371dc:	f3 48 ab             	rep stos QWORD PTR es:[rdi],rax
   371df:	48 c7 42 38 ff ff ff 	mov    QWORD PTR [rdx+0x38],0xffffffffffffffff
   371e6:	ff 
   371e7:	c7 42 40 ff ff ff ff 	mov    DWORD PTR [rdx+0x40],0xffffffff
   371ee:	c3                   	ret    
   371ef:	90                   	nop

00000000000371f0 <fix_problem@@Base>:
   371f0:	f3 0f 1e fa          	endbr64 
   371f4:	41 57                	push   r15
   371f6:	41 56                	push   r14
   371f8:	49 89 d6             	mov    r14,rdx
   371fb:	41 55                	push   r13
   371fd:	41 89 f5             	mov    r13d,esi
   37200:	41 54                	push   r12
   37202:	55                   	push   rbp
   37203:	48 89 fd             	mov    rbp,rdi
   37206:	53                   	push   rbx
   37207:	48 83 ec 48          	sub    rsp,0x48
   3720b:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   37212:	00 00 
   37214:	48 89 44 24 38       	mov    QWORD PTR [rsp+0x38],rax
   37219:	48 8b 07             	mov    rax,QWORD PTR [rdi]
   3721c:	89 f7                	mov    edi,esi
   3721e:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
   37223:	e8 f8 fa ff ff       	call   36d20 <ehandler_init@@Base+0x20>
   37228:	48 85 c0             	test   rax,rax
   3722b:	0f 84 5f 07 00 00    	je     37990 <fix_problem@@Base+0x7a0>
   37231:	8b 70 14             	mov    esi,DWORD PTR [rax+0x14]
   37234:	48 89 c3             	mov    rbx,rax
   37237:	f7 c6 00 00 08 00    	test   esi,0x80000
   3723d:	0f                   	.byte 0xf
   3723e:	84                   	.byte 0x84
   3723f:	1d                   	.byte 0x1d

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x51080 --stop-address=0x51140 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000051080 <ext2fs_expand_dir@@Base+0x6b0>:
   51080:	89 f8                	mov    eax,edi
   51082:	c1 e8 0a             	shr    eax,0xa
   51085:	83 e0 01             	and    eax,0x1
   51088:	c3                   	ret    
   51089:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   51090:	89 f8                	mov    eax,edi
   51092:	c1 e8 06             	shr    eax,0x6
   51095:	83 e0 01             	and    eax,0x1
   51098:	c3                   	ret    
   51099:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   510a0:	89 f8                	mov    eax,edi
   510a2:	c1 e8 03             	shr    eax,0x3
   510a5:	83 e0 01             	and    eax,0x1
   510a8:	c3                   	ret    
   510a9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000510b0 <ext2fs_ext_attr_hash_entry@@Base>:
   510b0:	f3 0f 1e fa          	endbr64 
   510b4:	0f b6 07             	movzx  eax,BYTE PTR [rdi]
   510b7:	48 8d 57 10          	lea    rdx,[rdi+0x10]
   510bb:	84 c0                	test   al,al
   510bd:	74 51                	je     51110 <ext2fs_ext_attr_hash_entry@@Base+0x60>
   510bf:	4c 8d 44 07 10       	lea    r8,[rdi+rax*1+0x10]
   510c4:	31 c0                	xor    eax,eax
   510c6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   510cd:	00 00 00 
   510d0:	0f be 0a             	movsx  ecx,BYTE PTR [rdx]
   510d3:	c1 c0 05             	rol    eax,0x5
   510d6:	48 83 c2 01          	add    rdx,0x1
   510da:	31 c8                	xor    eax,ecx
   510dc:	4c 39 c2             	cmp    rdx,r8
   510df:	75 ef                	jne    510d0 <ext2fs_ext_attr_hash_entry@@Base+0x20>
   510e1:	8b 57 04             	mov    edx,DWORD PTR [rdi+0x4]
   510e4:	85 d2                	test   edx,edx
   510e6:	75 27                	jne    5110f <ext2fs_ext_attr_hash_entry@@Base+0x5f>
   510e8:	8b 57 08             	mov    edx,DWORD PTR [rdi+0x8]
   510eb:	85 d2                	test   edx,edx
   510ed:	74 20                	je     5110f <ext2fs_ext_attr_hash_entry@@Base+0x5f>
   510ef:	83 c2 03             	add    edx,0x3
   510f2:	c1 ea 02             	shr    edx,0x2
   510f5:	74 18                	je     5110f <ext2fs_ext_attr_hash_entry@@Base+0x5f>
   510f7:	89 d2                	mov    edx,edx
   510f9:	48 8d 14 96          	lea    rdx,[rsi+rdx*4]
   510fd:	0f 1f 00             	nop    DWORD PTR [rax]
   51100:	48 83 c6 04          	add    rsi,0x4
   51104:	c1 c0 10             	rol    eax,0x10
   51107:	33 46 fc             	xor    eax,DWORD PTR [rsi-0x4]
   5110a:	48 39 f2             	cmp    rdx,rsi
   5110d:	75 f1                	jne    51100 <ext2fs_ext_attr_hash_entry@@Base+0x50>
   5110f:	c3                   	ret    
   51110:	31 c0                	xor    eax,eax
   51112:	eb cd                	jmp    510e1 <ext2fs_ext_attr_hash_entry@@Base+0x31>
   51114:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   5111b:	00 00 00 00 
   5111f:	90                   	nop

0000000000051120 <ext2fs_ext_attr_block_rehash@@Base>:
   51120:	f3 0f 1e fa          	endbr64 
   51124:	48 8d 47 20          	lea    rax,[rdi+0x20]
   51128:	31 c9                	xor    ecx,ecx
   5112a:	48 39 f0             	cmp    rax,rsi
   5112d:	72 29                	jb     51158 <ext2fs_ext_attr_block_rehash@@Base+0x38>
   5112f:	eb 2d                	jmp    5115e <ext2fs_ext_attr_block_rehash@@Base+0x3e>
   51131:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   51138:	8b 50 0c             	mov    edx,DWORD PTR [rax+0xc]
   5113b:	85 d2                	test   edx,edx
   5113d:	74 29                	je     51168 <ext2fs_ext_attr_block_rehash@@Base+0x48>
   5113f:	c1                   	.byte 0xc1

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x24b80 --stop-address=0x24d50 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000024b80 <e2fsck_pass1@@Base+0x7f0>:
   24b80:	e8 6b 26 01 00       	call   371f0 <fix_problem@@Base>
   24b85:	85 c0                	test   eax,eax
   24b87:	0f 85 5e 12 00 00    	jne    25deb <e2fsck_pass1@@Base+0x1a5b>
   24b8d:	4c 89 ea             	mov    rdx,r13
   24b90:	be 5a 00 01 00       	mov    esi,0x1005a
   24b95:	48 89 ef             	mov    rdi,rbp
   24b98:	e8 53 26 01 00       	call   371f0 <fix_problem@@Base>
   24b9d:	85 c0                	test   eax,eax
   24b9f:	0f 85 63 0f 00 00    	jne    25b08 <e2fsck_pass1@@Base+0x1778>
   24ba5:	c7 44 24 24 00 00 00 	mov    DWORD PTR [rsp+0x24],0x0
   24bac:	00 
   24bad:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24bb1:	83 fe 01             	cmp    esi,0x1
   24bb4:	0f 84 9e 04 00 00    	je     25058 <e2fsck_pass1@@Base+0xcc8>
   24bba:	83 fe 02             	cmp    esi,0x2
   24bbd:	0f 84 37 0a 00 00    	je     255fa <e2fsck_pass1@@Base+0x126a>
   24bc3:	83 fe 08             	cmp    esi,0x8
   24bc6:	0f 84 de 0a 00 00    	je     256aa <e2fsck_pass1@@Base+0x131a>
   24bcc:	4c 89 e7             	mov    rdi,r12
   24bcf:	e8 bc a0 ff ff       	call   1ec90 <check_backup_super_block@@Base+0xd50>
   24bd4:	85 c0                	test   eax,eax
   24bd6:	0f 85 5c 0e 00 00    	jne    25a38 <e2fsck_pass1@@Base+0x16a8>
   24bdc:	49 8b 54 24 20       	mov    rdx,QWORD PTR [r12+0x20]
   24be1:	b8 0b 00 00 00       	mov    eax,0xb
   24be6:	44 8b 4a 4c          	mov    r9d,DWORD PTR [rdx+0x4c]
   24bea:	45 85 c9             	test   r9d,r9d
   24bed:	74 03                	je     24bf2 <e2fsck_pass1@@Base+0x862>
   24bef:	8b 42 54             	mov    eax,DWORD PTR [rdx+0x54]
   24bf2:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24bf6:	39 c6                	cmp    esi,eax
   24bf8:	0f 82 5f 10 00 00    	jb     25c5d <e2fsck_pass1@@Base+0x18cd>
   24bfe:	48 8b 44 24 70       	mov    rax,QWORD PTR [rsp+0x70]
   24c03:	66 83 78 1a 00       	cmp    WORD PTR [rax+0x1a],0x0
   24c08:	0f 84 9c 05 00 00    	je     251aa <e2fsck_pass1@@Base+0xe1a>
   24c0e:	44 8b 40 14          	mov    r8d,DWORD PTR [rax+0x14]
   24c12:	45 85 c0             	test   r8d,r8d
   24c15:	0f 85 55 0d 00 00    	jne    25970 <e2fsck_pass1@@Base+0x15e0>
   24c1b:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24c1f:	48 8b bd 68 01 00 00 	mov    rdi,QWORD PTR [rbp+0x168]
   24c26:	e8 35 7d 03 00       	call   5c960 <ext2fs_mark_inode_bitmap2@@Base>
   24c2b:	49 8b 74 24 20       	mov    rsi,QWORD PTR [r12+0x20]
   24c30:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   24c35:	83 7e 48 01          	cmp    DWORD PTR [rsi+0x48],0x1
   24c39:	0f 84 e4 0c 00 00    	je     25923 <e2fsck_pass1@@Base+0x1593>
   24c3f:	8b 42 70             	mov    eax,DWORD PTR [rdx+0x70]
   24c42:	85 c0                	test   eax,eax
   24c44:	0f 85 17 09 00 00    	jne    25561 <e2fsck_pass1@@Base+0x11d1>
   24c4a:	8b 7e 60             	mov    edi,DWORD PTR [rsi+0x60]
   24c4d:	e8 ee b1 ff ff       	call   1fe40 <check_backup_super_block@@Base+0x1f00>
   24c52:	85 c0                	test   eax,eax
   24c54:	75 14                	jne    24c6a <e2fsck_pass1@@Base+0x8da>
   24c56:	0f b7 02             	movzx  eax,WORD PTR [rdx]
   24c59:	66 25 00 f0          	and    ax,0xf000
   24c5d:	66 3d 00 40          	cmp    ax,0x4000
   24c61:	0f 84 f0 08 00 00    	je     25557 <e2fsck_pass1@@Base+0x11c7>
   24c67:	8b 7e 60             	mov    edi,DWORD PTR [rsi+0x60]
   24c6a:	e8 41 b7 ff ff       	call   203b0 <check_backup_super_block@@Base+0x2470>
   24c6f:	85 c0                	test   eax,eax
   24c71:	75 0b                	jne    24c7e <e2fsck_pass1@@Base+0x8ee>
   24c73:	66 83 7a 76 00       	cmp    WORD PTR [rdx+0x76],0x0
   24c78:	0f 85 1c 11 00 00    	jne    25d9a <e2fsck_pass1@@Base+0x1a0a>
   24c7e:	8b 7e 64             	mov    edi,DWORD PTR [rsi+0x64]
   24c81:	e8 5a d3 ff ff       	call   21fe0 <check_backup_super_block@@Base+0x40a0>
   24c86:	85 c0                	test   eax,eax
   24c88:	75 0b                	jne    24c95 <e2fsck_pass1@@Base+0x905>
   24c8a:	66 83 7a 74 00       	cmp    WORD PTR [rdx+0x74],0x0
   24c8f:	0f 85 ce 11 00 00    	jne    25e63 <e2fsck_pass1@@Base+0x1ad3>
   24c95:	f6 42 21 20          	test   BYTE PTR [rdx+0x21],0x20
   24c99:	74 25                	je     24cc0 <e2fsck_pass1@@Base+0x930>
   24c9b:	8b 44 24 50          	mov    eax,DWORD PTR [rsp+0x50]
   24c9f:	85 c0                	test   eax,eax
   24ca1:	0f 84 77 0f 00 00    	je     25c1e <e2fsck_pass1@@Base+0x188e>
   24ca7:	48 8b bd 88 01 00 00 	mov    rdi,QWORD PTR [rbp+0x188]
   24cae:	48 85 ff             	test   rdi,rdi
   24cb1:	0f 84 45 12 00 00    	je     25efc <e2fsck_pass1@@Base+0x1b6c>
   24cb7:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24cbb:	e8 a0 7c 03 00       	call   5c960 <ext2fs_mark_inode_bitmap2@@Base>
   24cc0:	48 8b 54 24 40       	mov    rdx,QWORD PTR [rsp+0x40]
   24cc5:	4c 89 ee             	mov    rsi,r13
   24cc8:	48 89 ef             	mov    rdi,rbp
   24ccb:	e8 b0 ae ff ff       	call   1fb80 <check_backup_super_block@@Base+0x1c40>
   24cd0:	48 8b 94 24 80 00 00 	mov    rdx,QWORD PTR [rsp+0x80]
   24cd7:	00 
   24cd8:	4c 89 ee             	mov    rsi,r13
   24cdb:	48 89 ef             	mov    rdi,rbp
   24cde:	e8 ed b6 ff ff       	call   203d0 <check_backup_super_block@@Base+0x2490>
   24ce3:	48 8b 74 24 70       	mov    rsi,QWORD PTR [rsp+0x70]
   24ce8:	44 8b 5c 24 24       	mov    r11d,DWORD PTR [rsp+0x24]
   24ced:	8b 46 20             	mov    eax,DWORD PTR [rsi+0x20]
   24cf0:	45 85 db             	test   r11d,r11d
   24cf3:	74 1a                	je     24d0f <e2fsck_pass1@@Base+0x97f>
   24cf5:	a9 00 00 08 00       	test   eax,0x80000
   24cfa:	74 13                	je     24d0f <e2fsck_pass1@@Base+0x97f>
   24cfc:	0f b7 16             	movzx  edx,WORD PTR [rsi]
   24cff:	66 81 e2 00 f0       	and    dx,0xf000
   24d04:	66 81 fa 00 a0       	cmp    dx,0xa000
   24d09:	0f 84 bf 13 00 00    	je     260ce <e2fsck_pass1@@Base+0x1d3e>
   24d0f:	f6 c4 08             	test   ah,0x8
   24d12:	0f 85 cf 0c 00 00    	jne    259e7 <e2fsck_pass1@@Base+0x1657>
   24d18:	44 8b 54 24 38       	mov    r10d,DWORD PTR [rsp+0x38]
   24d1d:	45 85 d2             	test   r10d,r10d
   24d20:	74 0a                	je     24d2c <e2fsck_pass1@@Base+0x99c>
   24d22:	f6 46 23 40          	test   BYTE PTR [rsi+0x23],0x40
   24d26:	0f 85 ed 10 00 00    	jne    25e19 <e2fsck_pass1@@Base+0x1a89>
   24d2c:	0f b7 06             	movzx  eax,WORD PTR [rsi]
   24d2f:	66 25 00 f0          	and    ax,0xf000
   24d33:	66 3d 00 40          	cmp    ax,0x4000
   24d37:	0f 84 4b 0e 00 00    	je     25b88 <e2fsck_pass1@@Base+0x17f8>
   24d3d:	66 3d 00 80          	cmp    ax,0x8000
   24d41:	0f 84 ba 0f 00 00    	je     25d01 <e2fsck_pass1@@Base+0x1971>
   24d47:	66 3d 00 20          	cmp    ax,0x2000
   24d4b:	0f                   	.byte 0xf
   24d4c:	84 f2                	test   dl,dh
   24d4e:	0d                   	.byte 0xd
	...

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x24390 --stop-address=0x24680 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000024390 <e2fsck_pass1@@Base>:
   24390:	f3 0f 1e fa          	endbr64 
   24394:	41 57                	push   r15
   24396:	ba 05 00 00 00       	mov    edx,0x5
   2439b:	48 8d 35 31 4d 05 00 	lea    rsi,[rip+0x54d31]        # 790d3 <_IO_stdin_used@@Base+0x20d3>
   243a2:	41 56                	push   r14
   243a4:	41 55                	push   r13
   243a6:	41 54                	push   r12
   243a8:	55                   	push   rbp
   243a9:	48 89 fd             	mov    rbp,rdi
   243ac:	53                   	push   rbx
   243ad:	48 81 ec 18 02 00 00 	sub    rsp,0x218
   243b4:	4c 8b 27             	mov    r12,QWORD PTR [rdi]
   243b7:	31 ff                	xor    edi,edi
   243b9:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   243c0:	00 00 
   243c2:	48 89 84 24 08 02 00 	mov    QWORD PTR [rsp+0x208],rax
   243c9:	00 
   243ca:	31 c0                	xor    eax,eax
   243cc:	c7 44 24 64 00 00 00 	mov    DWORD PTR [rsp+0x64],0x0
   243d3:	00 
   243d4:	48 c7 44 24 70 00 00 	mov    QWORD PTR [rsp+0x70],0x0
   243db:	00 00 
   243dd:	49 8b 5c 24 20       	mov    rbx,QWORD PTR [r12+0x20]
   243e2:	48 c7 44 24 78 00 00 	mov    QWORD PTR [rsp+0x78],0x0
   243e9:	00 00 
   243eb:	48 c7 84 24 80 00 00 	mov    QWORD PTR [rsp+0x80],0x0
   243f2:	00 00 00 00 00 
   243f7:	e8 b4 19 ff ff       	call   15db0 <dcgettext@plt>
   243fc:	c7 44 24 08 80 00 00 	mov    DWORD PTR [rsp+0x8],0x80
   24403:	00 
   24404:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   24409:	49 8b 44 24 20       	mov    rax,QWORD PTR [r12+0x20]
   2440e:	44 8b 48 4c          	mov    r9d,DWORD PTR [rax+0x4c]
   24412:	45 85 c9             	test   r9d,r9d
   24415:	74 08                	je     2441f <e2fsck_pass1@@Base+0x8f>
   24417:	0f b7 40 58          	movzx  eax,WORD PTR [rax+0x58]
   2441b:	89 44 24 08          	mov    DWORD PTR [rsp+0x8],eax
   2441f:	48 8b 45 00          	mov    rax,QWORD PTR [rbp+0x0]
   24423:	4c 8d bc 24 b0 00 00 	lea    r15,[rsp+0xb0]
   2442a:	00 
   2442b:	4c 8d ac 24 00 01 00 	lea    r13,[rsp+0x100]
   24432:	00 
   24433:	c7 44 24 68 00 00 00 	mov    DWORD PTR [rsp+0x68],0x0
   2443a:	00 
   2443b:	4c 89 ff             	mov    rdi,r15
   2443e:	c7 44 24 6c 00 00 00 	mov    DWORD PTR [rsp+0x6c],0x0
   24445:	00 
   24446:	48 8b 70 08          	mov    rsi,QWORD PTR [rax+0x8]
   2444a:	e8 21 06 01 00       	call   34a70 <init_resource_track@@Base>
   2444f:	4c 89 ef             	mov    rdi,r13
   24452:	e8 59 2d 01 00       	call   371b0 <clear_problem_context@@Base>
   24457:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
   2445b:	e8 00 a1 01 00       	call   3e560 <e2fsck_can_readahead@@Base>
   24460:	85 c0                	test   eax,eax
   24462:	0f 85 38 0a 00 00    	jne    24ea0 <e2fsck_pass1@@Base+0xb10>
   24468:	48 c7 85 98 03 00 00 	mov    QWORD PTR [rbp+0x398],0x0
   2446f:	00 00 00 00 
   24473:	48 8d 44 24 6c       	lea    rax,[rsp+0x6c]
   24478:	4c 8d 74 24 68       	lea    r14,[rsp+0x68]
   2447d:	48 89 ef             	mov    rdi,rbp
   24480:	4c 89 f2             	mov    rdx,r14
   24483:	48 89 c6             	mov    rsi,rax
   24486:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   2448b:	e8 50 a6 ff ff       	call   1eae0 <check_backup_super_block@@Base+0xba0>
   24490:	f6 45 4c 02          	test   BYTE PTR [rbp+0x4c],0x2
   24494:	0f 84 96 0a 00 00    	je     24f30 <e2fsck_pass1@@Base+0xba0>
   2449a:	49 8b 44 24 20       	mov    rax,QWORD PTR [r12+0x20]
   2449f:	8b 78 5c             	mov    edi,DWORD PTR [rax+0x5c]
   244a2:	e8 49 db ff ff       	call   21ff0 <check_backup_super_block@@Base+0x40b0>
   244a7:	85 c0                	test   eax,eax
   244a9:	74 0a                	je     244b5 <e2fsck_pass1@@Base+0x125>
   244ab:	f6 45 4c 08          	test   BYTE PTR [rbp+0x4c],0x8
   244af:	0f 84 93 0a 00 00    	je     24f48 <e2fsck_pass1@@Base+0xbb8>
   244b5:	ba 0a 00 00 00       	mov    edx,0xa
   244ba:	48 8d 3d 2f 2c 09 00 	lea    rdi,[rip+0x92c2f]        # b70f0 <e2fsck_global_ctx@@Base+0xf0>
   244c1:	be 01 00 00 00       	mov    esi,0x1
   244c6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   244cd:	00 00 00 
   244d0:	8d 4a fe             	lea    ecx,[rdx-0x2]
   244d3:	49 89 f0             	mov    r8,rsi
   244d6:	49 d3 e0             	shl    r8,cl
   244d9:	4c 89 c0             	mov    rax,r8
   244dc:	48 d3 e0             	shl    rax,cl
   244df:	4d 8d 44 00 0c       	lea    r8,[r8+rax*1+0xc]
   244e4:	48 d3 e0             	shl    rax,cl
   244e7:	89 d1                	mov    ecx,edx
   244e9:	4c 01 c0             	add    rax,r8
   244ec:	48 d3 e0             	shl    rax,cl
   244ef:	48 89 04 d7          	mov    QWORD PTR [rdi+rdx*8],rax
   244f3:	48 83 c2 01          	add    rdx,0x1
   244f7:	48 83 fa 11          	cmp    rdx,0x11
   244fb:	75 d3                	jne    244d0 <e2fsck_pass1@@Base+0x140>
   244fd:	8b 43 5c             	mov    eax,DWORD PTR [rbx+0x5c]
   24500:	ba 05 00 00 00       	mov    edx,0x5
   24505:	48 8d 35 e4 4b 05 00 	lea    rsi,[rip+0x54be4]        # 790f0 <_IO_stdin_used@@Base+0x20f0>
   2450c:	31 ff                	xor    edi,edi
   2450e:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   24512:	8b 43 60             	mov    eax,DWORD PTR [rbx+0x60]
   24515:	89 44 24 10          	mov    DWORD PTR [rsp+0x10],eax
   24519:	e8 92 18 ff ff       	call   15db0 <dcgettext@plt>
   2451e:	4c 8d 85 68 01 00 00 	lea    r8,[rbp+0x168]
   24525:	ba 02 00 00 00       	mov    edx,0x2
   2452a:	4c 89 e7             	mov    rdi,r12
   2452d:	48 89 c6             	mov    rsi,rax
   24530:	48 8d 0d ca 4b 05 00 	lea    rcx,[rip+0x54bca]        # 79101 <_IO_stdin_used@@Base+0x2101>
   24537:	e8 d4 15 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   2453c:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   24543:	00 
   24544:	48 85 c0             	test   rax,rax
   24547:	0f 85 cb 09 00 00    	jne    24f18 <e2fsck_pass1@@Base+0xb88>
   2454d:	ba 05 00 00 00       	mov    edx,0x5
   24552:	48 8d 35 b7 4b 05 00 	lea    rsi,[rip+0x54bb7]        # 79110 <_IO_stdin_used@@Base+0x2110>
   24559:	31 ff                	xor    edi,edi
   2455b:	e8 50 18 ff ff       	call   15db0 <dcgettext@plt>
   24560:	4c 8d 85 78 01 00 00 	lea    r8,[rbp+0x178]
   24567:	ba 03 00 00 00       	mov    edx,0x3
   2456c:	4c 89 e7             	mov    rdi,r12
   2456f:	48 89 c6             	mov    rsi,rax
   24572:	48 8d 0d ab 4b 05 00 	lea    rcx,[rip+0x54bab]        # 79124 <_IO_stdin_used@@Base+0x2124>
   24579:	e8 92 15 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   2457e:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   24585:	00 
   24586:	48 85 c0             	test   rax,rax
   24589:	0f 85 39 09 00 00    	jne    24ec8 <e2fsck_pass1@@Base+0xb38>
   2458f:	ba 05 00 00 00       	mov    edx,0x5
   24594:	48 8d 35 97 4b 05 00 	lea    rsi,[rip+0x54b97]        # 79132 <_IO_stdin_used@@Base+0x2132>
   2459b:	31 ff                	xor    edi,edi
   2459d:	e8 0e 18 ff ff       	call   15db0 <dcgettext@plt>
   245a2:	4c 8d 85 90 01 00 00 	lea    r8,[rbp+0x190]
   245a9:	ba 02 00 00 00       	mov    edx,0x2
   245ae:	4c 89 e7             	mov    rdi,r12
   245b1:	48 89 c6             	mov    rsi,rax
   245b4:	48 8d 0d 8e 4b 05 00 	lea    rcx,[rip+0x54b8e]        # 79149 <_IO_stdin_used@@Base+0x2149>
   245bb:	e8 50 15 01 00       	call   35b10 <e2fsck_allocate_inode_bitmap@@Base>
   245c0:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   245c7:	00 
   245c8:	48 85 c0             	test   rax,rax
   245cb:	0f 85 cf 09 00 00    	jne    24fa0 <e2fsck_pass1@@Base+0xc10>
   245d1:	48 8d 85 a0 01 00 00 	lea    rax,[rbp+0x1a0]
   245d8:	ba 05 00 00 00       	mov    edx,0x5
   245dd:	48 8d 35 73 4b 05 00 	lea    rsi,[rip+0x54b73]        # 79157 <_IO_stdin_used@@Base+0x2157>
   245e4:	31 ff                	xor    edi,edi
   245e6:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   245eb:	e8 c0 17 ff ff       	call   15db0 <dcgettext@plt>
   245f0:	4c 8d 85 a0 01 00 00 	lea    r8,[rbp+0x1a0]
   245f7:	ba 02 00 00 00       	mov    edx,0x2
   245fc:	4c 89 e7             	mov    rdi,r12
   245ff:	48 89 c6             	mov    rsi,rax
   24602:	48 8d 0d 5f 4b 05 00 	lea    rcx,[rip+0x54b5f]        # 79168 <_IO_stdin_used@@Base+0x2168>
   24609:	e8 e2 15 01 00       	call   35bf0 <e2fsck_allocate_subcluster_bitmap@@Base>
   2460e:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   24615:	00 
   24616:	48 85 c0             	test   rax,rax
   24619:	0f 85 59 09 00 00    	jne    24f78 <e2fsck_pass1@@Base+0xbe8>
   2461f:	ba 05 00 00 00       	mov    edx,0x5
   24624:	48 8d 35 4d 4b 05 00 	lea    rsi,[rip+0x54b4d]        # 79178 <_IO_stdin_used@@Base+0x2178>
   2462b:	31 ff                	xor    edi,edi
   2462d:	e8 7e 17 ff ff       	call   15db0 <dcgettext@plt>
   24632:	4c 8d 85 90 03 00 00 	lea    r8,[rbp+0x390]
   24639:	ba 02 00 00 00       	mov    edx,0x2
   2463e:	4c 89 e7             	mov    rdi,r12
   24641:	48 89 c6             	mov    rsi,rax
   24644:	48 8d 0d 40 4b 05 00 	lea    rcx,[rip+0x54b40]        # 7918b <_IO_stdin_used@@Base+0x218b>
   2464b:	e8 30 15 01 00       	call   35b80 <e2fsck_allocate_block_bitmap@@Base>
   24650:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   24657:	00 
   24658:	48 85 c0             	test   rax,rax
   2465b:	0f 85 17 09 00 00    	jne    24f78 <e2fsck_pass1@@Base+0xbe8>
   24661:	8b 7c 24 10          	mov    edi,DWORD PTR [rsp+0x10]
   24665:	e8 b6 b7 ff ff       	call   1fe20 <check_backup_super_block@@Base+0x1ee0>
   2466a:	89 44 24 38          	mov    DWORD PTR [rsp+0x38],eax
   2466e:	85 c0                	test   eax,eax
   24670:	74 42                	je     246b4 <e2fsck_pass1@@Base+0x324>
   24672:	ba 05 00 00 00       	mov    edx,0x5
   24677:	48 8d 35 20 4b 05 00 	lea    rsi,[rip+0x54b20]        # 7919e <_IO_stdin_used@@Base+0x219e>
   2467e:	31 ff                	xor    edi,edi

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x24800 --stop-address=0x24b80 ./target.bin' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000024800 <e2fsck_pass1@@Base+0x470>:
   24800:	8d 54 24 78          	lea    edx,[rsp+0x78]
   24804:	4c 89 e7             	mov    rdi,r12
   24807:	48 89 44 24 30       	mov    QWORD PTR [rsp+0x30],rax
   2480c:	e8 bf 9e 03 00       	call   5e6d0 <ext2fs_open_inode_scan@@Base>
   24811:	48 8b 7c 24 30       	mov    rdi,QWORD PTR [rsp+0x30]
   24816:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   2481d:	00 
   2481e:	e8 bd 24 01 00       	call   36ce0 <ehandler_operation@@Base>
   24823:	48 83 bc 24 00 01 00 	cmp    QWORD PTR [rsp+0x100],0x0
   2482a:	00 00 
   2482c:	0f 85 fc 0a 00 00    	jne    2532e <e2fsck_pass1@@Base+0xf9e>
   24832:	48 8b 7c 24 78       	mov    rdi,QWORD PTR [rsp+0x78]
   24837:	31 d2                	xor    edx,edx
   24839:	be 28 00 00 00       	mov    esi,0x28
   2483e:	e8 0d a2 03 00       	call   5ea50 <ext2fs_inode_scan_flags@@Base>
   24843:	48 8b 44 24 70       	mov    rax,QWORD PTR [rsp+0x70]
   24848:	48 8b 7c 24 78       	mov    rdi,QWORD PTR [rsp+0x78]
   2484d:	48 8d 94 24 90 00 00 	lea    rdx,[rsp+0x90]
   24854:	00 
   24855:	48 8d 35 14 fa ff ff 	lea    rsi,[rip+0xfffffffffffffa14]        # 24270 <e2fsck_clear_inode@@Base+0x1180>
   2485c:	48 89 ac 24 90 00 00 	mov    QWORD PTR [rsp+0x90],rbp
   24863:	00 
   24864:	48 89 85 20 02 00 00 	mov    QWORD PTR [rbp+0x220],rax
   2486b:	48 8b 84 24 80 00 00 	mov    rax,QWORD PTR [rsp+0x80]
   24872:	00 
   24873:	48 89 84 24 98 00 00 	mov    QWORD PTR [rsp+0x98],rax
   2487a:	00 
   2487b:	e8 a0 a1 03 00       	call   5ea20 <ext2fs_set_inode_callback@@Base>
   24880:	48 8b 85 60 01 00 00 	mov    rax,QWORD PTR [rbp+0x160]
   24887:	48 85 c0             	test   rax,rax
   2488a:	74 1b                	je     248a7 <e2fsck_pass1@@Base+0x517>
   2488c:	48 8b 55 00          	mov    rdx,QWORD PTR [rbp+0x0]
   24890:	be 01 00 00 00       	mov    esi,0x1
   24895:	48 89 ef             	mov    rdi,rbp
   24898:	8b 4a 30             	mov    ecx,DWORD PTR [rdx+0x30]
   2489b:	31 d2                	xor    edx,edx
   2489d:	ff d0                	call   rax
   2489f:	85 c0                	test   eax,eax
   248a1:	0f 85 1e 07 00 00    	jne    24fc5 <e2fsck_pass1@@Base+0xc35>
   248a7:	4d 8b 44 24 20       	mov    r8,QWORD PTR [r12+0x20]
   248ac:	41 8b 40 30          	mov    eax,DWORD PTR [r8+0x30]
   248b0:	85 c0                	test   eax,eax
   248b2:	74 0d                	je     248c1 <e2fsck_pass1@@Base+0x531>
   248b4:	c7 44 24 3c 00 00 00 	mov    DWORD PTR [rsp+0x3c],0x0
   248bb:	00 
   248bc:	41 3b 00             	cmp    eax,DWORD PTR [r8]
   248bf:	72 35                	jb     248f6 <e2fsck_pass1@@Base+0x566>
   248c1:	41 8b 40 2c          	mov    eax,DWORD PTR [r8+0x2c]
   248c5:	85 c0                	test   eax,eax
   248c7:	74 0d                	je     248d6 <e2fsck_pass1@@Base+0x546>
   248c9:	c7 44 24 3c 00 00 00 	mov    DWORD PTR [rsp+0x3c],0x0
   248d0:	00 
   248d1:	41 3b 00             	cmp    eax,DWORD PTR [r8]
   248d4:	72 20                	jb     248f6 <e2fsck_pass1@@Base+0x566>
   248d6:	41 8b 80 08 01 00 00 	mov    eax,DWORD PTR [r8+0x108]
   248dd:	c7 44 24 3c 01 00 00 	mov    DWORD PTR [rsp+0x3c],0x1
   248e4:	00 
   248e5:	85 c0                	test   eax,eax
   248e7:	74 0d                	je     248f6 <e2fsck_pass1@@Base+0x566>
   248e9:	41 3b 00             	cmp    eax,DWORD PTR [r8]
   248ec:	0f 93 c0             	setae  al
   248ef:	0f b6 c0             	movzx  eax,al
   248f2:	89 44 24 3c          	mov    DWORD PTR [rsp+0x3c],eax
   248f6:	41 8b 78 60          	mov    edi,DWORD PTR [r8+0x60]
   248fa:	e8 a1 ba ff ff       	call   203a0 <check_backup_super_block@@Base+0x2460>
   248ff:	85 c0                	test   eax,eax
   24901:	74 14                	je     24917 <e2fsck_pass1@@Base+0x587>
   24903:	49 8b 90 68 01 00 00 	mov    rdx,QWORD PTR [r8+0x168]
   2490a:	41 8b 40 14          	mov    eax,DWORD PTR [r8+0x14]
   2490e:	48 39 c2             	cmp    rdx,rax
   24911:	0f 87 98 10 00 00    	ja     259af <e2fsck_pass1@@Base+0x161f>
   24917:	8b 7c 24 24          	mov    edi,DWORD PTR [rsp+0x24]
   2491b:	31 f6                	xor    esi,esi
   2491d:	e8 ee e3 ff ff       	call   22d10 <check_backup_super_block@@Base+0x4dd0>
   24922:	8b 7c 24 10          	mov    edi,DWORD PTR [rsp+0x10]
   24926:	89 44 24 50          	mov    DWORD PTR [rsp+0x50],eax
   2492a:	e8 91 ba ff ff       	call   203c0 <check_backup_super_block@@Base+0x2480>
   2492f:	89 44 24 24          	mov    DWORD PTR [rsp+0x24],eax
   24933:	e8 f8 b4 ff ff       	call   1fe30 <check_backup_super_block@@Base+0x1ef0>
   24938:	48 89 ef             	mov    rdi,rbp
   2493b:	89 44 24 30          	mov    DWORD PTR [rsp+0x30],eax
   2493f:	e8 2c 81 00 00       	call   2ca70 <e2fsck_get_lost_and_found@@Base>
   24944:	48 8d 44 24 64       	lea    rax,[rsp+0x64]
   24949:	48 89 5c 24 48       	mov    QWORD PTR [rsp+0x48],rbx
   2494e:	48 89 44 24 10       	mov    QWORD PTR [rsp+0x10],rax
   24953:	48 8d 84 24 a0 00 00 	lea    rax,[rsp+0xa0]
   2495a:	00 
   2495b:	48 89 44 24 40       	mov    QWORD PTR [rsp+0x40],rax
   24960:	8b 44 24 08          	mov    eax,DWORD PTR [rsp+0x8]
   24964:	4c 89 7c 24 08       	mov    QWORD PTR [rsp+0x8],r15
   24969:	89 c7                	mov    edi,eax
   2496b:	89 c3                	mov    ebx,eax
   2496d:	83 e7 04             	and    edi,0x4
   24970:	89 7c 24 54          	mov    DWORD PTR [rsp+0x54],edi
   24974:	49 8b 44 24 20       	mov    rax,QWORD PTR [r12+0x20]
   24979:	31 d2                	xor    edx,edx
   2497b:	8b 48 28             	mov    ecx,DWORD PTR [rax+0x28]
   2497e:	8b 44 24 64          	mov    eax,DWORD PTR [rsp+0x64]
   24982:	c1 e1 02             	shl    ecx,0x2
   24985:	f7 f1                	div    ecx
   24987:	83 fa 01             	cmp    edx,0x1
   2498a:	0f 84 fa 09 00 00    	je     2538a <e2fsck_pass1@@Base+0xffa>
   24990:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   24995:	e8 46 23 01 00       	call   36ce0 <ehandler_operation@@Base>
   2499a:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   2499f:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   249a4:	89 d9                	mov    ecx,ebx
   249a6:	48 8b 7c 24 78       	mov    rdi,QWORD PTR [rsp+0x78]
   249ab:	49 89 c7             	mov    r15,rax
   249ae:	e8 fd a0 03 00       	call   5eab0 <ext2fs_get_next_inode_full@@Base>
   249b3:	48 89 84 24 00 01 00 	mov    QWORD PTR [rsp+0x100],rax
   249ba:	00 
   249bb:	8b 44 24 68          	mov    eax,DWORD PTR [rsp+0x68]
   249bf:	39 44 24 64          	cmp    DWORD PTR [rsp+0x64],eax
   249c3:	0f 87 56 08 00 00    	ja     2521f <e2fsck_pass1@@Base+0xe8f>
   249c9:	4c 89 ff             	mov    rdi,r15
   249cc:	e8 0f 23 01 00       	call   36ce0 <ehandler_operation@@Base>
   249d1:	f6 45 48 03          	test   BYTE PTR [rbp+0x48],0x3
   249d5:	0f 85 b7 04 00 00    	jne    24e92 <e2fsck_pass1@@Base+0xb02>
   249db:	48 8b 84 24 00 01 00 	mov    rax,QWORD PTR [rsp+0x100]
   249e2:	00 
   249e3:	48 3d 42 b7 2b 7f    	cmp    rax,0x7f2bb742
   249e9:	0f 84 e5 07 00 00    	je     251d4 <e2fsck_pass1@@Base+0xe44>
   249ef:	48 85 c0             	test   rax,rax
   249f2:	41 0f 95 c7          	setne  r15b
   249f6:	48 3d 92 b7 2b 7f    	cmp    rax,0x7f2bb792
   249fc:	0f 95 c2             	setne  dl
   249ff:	44 84 fa             	test   dl,r15b
   24a02:	74 0c                	je     24a10 <e2fsck_pass1@@Base+0x680>
   24a04:	48 3d a9 b7 2b 7f    	cmp    rax,0x7f2bb7a9
   24a0a:	0f 85 19 09 00 00    	jne    25329 <e2fsck_pass1@@Base+0xf99>
   24a10:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24a14:	85 f6                	test   esi,esi
   24a16:	0f 84 40 15 00 00    	je     25f5c <e2fsck_pass1@@Base+0x1bcc>
   24a1c:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   24a21:	89 b4 24 08 01 00 00 	mov    DWORD PTR [rsp+0x108],esi
   24a28:	89 b5 18 02 00 00    	mov    DWORD PTR [rbp+0x218],esi
   24a2e:	48 89 94 24 18 01 00 	mov    QWORD PTR [rsp+0x118],rdx
   24a35:	00 
   24a36:	48 89 d1             	mov    rcx,rdx
   24a39:	48 3d a9 b7 2b 7f    	cmp    rax,0x7f2bb7a9
   24a3f:	0f 84 02 09 00 00    	je     25347 <e2fsck_pass1@@Base+0xfb7>
   24a45:	8b 42 14             	mov    eax,DWORD PTR [rdx+0x14]
   24a48:	45 0f b6 ff          	movzx  r15d,r15b
   24a4c:	85 c0                	test   eax,eax
   24a4e:	74 0c                	je     24a5c <e2fsck_pass1@@Base+0x6cc>
   24a50:	8b 74 24 3c          	mov    esi,DWORD PTR [rsp+0x3c]
   24a54:	85 f6                	test   esi,esi
   24a56:	0f 85 a6 09 00 00    	jne    25402 <e2fsck_pass1@@Base+0x1072>
   24a5c:	0f b7 42 1a          	movzx  eax,WORD PTR [rdx+0x1a]
   24a60:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24a64:	66 85 c0             	test   ax,ax
   24a67:	0f 85 68 09 00 00    	jne    253d5 <e2fsck_pass1@@Base+0x1045>
   24a6d:	49 8b 7c 24 20       	mov    rdi,QWORD PTR [r12+0x20]
   24a72:	b8 0b 00 00 00       	mov    eax,0xb
   24a77:	44 8b 5f 4c          	mov    r11d,DWORD PTR [rdi+0x4c]
   24a7b:	45 85 db             	test   r11d,r11d
   24a7e:	74 03                	je     24a83 <e2fsck_pass1@@Base+0x6f3>
   24a80:	8b 47 54             	mov    eax,DWORD PTR [rdi+0x54]
   24a83:	39 f0                	cmp    eax,esi
   24a85:	0f 86 dc 09 00 00    	jbe    25467 <e2fsck_pass1@@Base+0x10d7>
   24a8b:	8b 42 20             	mov    eax,DWORD PTR [rdx+0x20]
   24a8e:	a9 00 00 00 40       	test   eax,0x40000000
   24a93:	74 53                	je     24ae8 <e2fsck_pass1@@Base+0x758>
   24a95:	0f b7 02             	movzx  eax,WORD PTR [rdx]
   24a98:	66 25 00 f0          	and    ax,0xf000
   24a9c:	66 3d 00 40          	cmp    ax,0x4000
   24aa0:	0f 84 04 09 00 00    	je     253aa <e2fsck_pass1@@Base+0x101a>
   24aa6:	4c 89 ea             	mov    rdx,r13
   24aa9:	be 88 00 01 00       	mov    esi,0x10088
   24aae:	48 89 ef             	mov    rdi,rbp
   24ab1:	e8 3a 27 01 00       	call   371f0 <fix_problem@@Base>
   24ab6:	85 c0                	test   eax,eax
   24ab8:	0f 84 ec 08 00 00    	je     253aa <e2fsck_pass1@@Base+0x101a>
   24abe:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   24ac3:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24ac7:	48 8d 0d b2 44 05 00 	lea    rcx,[rip+0x544b2]        # 78f80 <_IO_stdin_used@@Base+0x1f80>
   24ace:	48 89 ef             	mov    rdi,rbp
   24ad1:	81 62 20 ff ff ff bf 	and    DWORD PTR [rdx+0x20],0xbfffffff
   24ad8:	e8 13 05 01 00       	call   34ff0 <e2fsck_write_inode@@Base>
   24add:	48 8b 54 24 70       	mov    rdx,QWORD PTR [rsp+0x70]
   24ae2:	8b 42 20             	mov    eax,DWORD PTR [rdx+0x20]
   24ae5:	48 89 d1             	mov    rcx,rdx
   24ae8:	89 c6                	mov    esi,eax
   24aea:	81 e6 00 00 08 10    	and    esi,0x10080000
   24af0:	81 fe 00 00 08 10    	cmp    esi,0x10080000
   24af6:	0f 84 32 0a 00 00    	je     2552e <e2fsck_pass1@@Base+0x119e>
   24afc:	a9 00 00 00 10       	test   eax,0x10000000
   24b01:	74 2e                	je     24b31 <e2fsck_pass1@@Base+0x7a1>
   24b03:	49 8b 74 24 20       	mov    rsi,QWORD PTR [r12+0x20]
   24b08:	44 8b 44 24 30       	mov    r8d,DWORD PTR [rsp+0x30]
   24b0d:	8b 7e 4c             	mov    edi,DWORD PTR [rsi+0x4c]
   24b10:	45 85 c0             	test   r8d,r8d
   24b13:	0f 85 ed 09 00 00    	jne    25506 <e2fsck_pass1@@Base+0x1176>
   24b19:	ba 0b 00 00 00       	mov    edx,0xb
   24b1e:	85 ff                	test   edi,edi
   24b20:	74 03                	je     24b25 <e2fsck_pass1@@Base+0x795>
   24b22:	8b 56 54             	mov    edx,DWORD PTR [rsi+0x54]
   24b25:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24b29:	39 d6                	cmp    esi,edx
   24b2b:	0f 83 69 0f 00 00    	jae    25a9a <e2fsck_pass1@@Base+0x170a>
   24b31:	a9 00 00 08 00       	test   eax,0x80000
   24b36:	0f 84 29 07 00 00    	je     25265 <e2fsck_pass1@@Base+0xed5>
   24b3c:	44 8b 54 24 24       	mov    r10d,DWORD PTR [rsp+0x24]
   24b41:	45 85 d2             	test   r10d,r10d
   24b44:	0f 85 81 06 00 00    	jne    251cb <e2fsck_pass1@@Base+0xe3b>
   24b4a:	66 83 79 1a 00       	cmp    WORD PTR [rcx+0x1a],0x0
   24b4f:	75 11                	jne    24b62 <e2fsck_pass1@@Base+0x7d2>
   24b51:	8b 74 24 64          	mov    esi,DWORD PTR [rsp+0x64]
   24b55:	8d 46 ff             	lea    eax,[rsi-0x1]
   24b58:	83 f8 01             	cmp    eax,0x1
   24b5b:	76 05                	jbe    24b62 <e2fsck_pass1@@Base+0x7d2>
   24b5d:	83 fe 08             	cmp    esi,0x8
   24b60:	75 58                	jne    24bba <e2fsck_pass1@@Base+0x82a>
   24b62:	48 8d 79 28          	lea    rdi,[rcx+0x28]
   24b66:	be 3c 00 00 00       	mov    esi,0x3c
   24b6b:	e8 80 ee 02 00       	call   539f0 <ext2fs_extent_header_verify@@Base>
   24b70:	48 85 c0             	test   rax,rax
   24b73:	75 18                	jne    24b8d <e2fsck_pass1@@Base+0x7fd>
   24b75:	4c 89 ea             	mov    rdx,r13
   24b78:	be 5b 00 01 00       	mov    esi,0x1005b
   24b7d:	48 89 ef             	mov    rdi,rbp

codex
The signature is `void`: it receives the checker context, a problem context containing the inode, and a two-counter EA quota result. I’ve recovered the exact inline-xattr layout and am now encoding the shared repair/cleanup paths while preserving the observed partial-accounting behavior when a repair is declined.
apply patch
patch: completed
/tmp/llmdec_codex_6_u0et34/decompiled.c
diff --git a/llmdec_codex_6_u0et34/decompiled.c b/llmdec_codex_6_u0et34/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..b64d91e62cc7bec138d8868a96956fc4739e89ef
--- /dev/null
+++ b/llmdec_codex_6_u0et34/decompiled.c
@@ -0,0 +1,198 @@
+#include <stdint.h>
+
+struct ext2_super_block_view {
+    uint8_t pad_00[0x4c];
+    uint32_t s_rev_level;
+    uint8_t pad_50[8];
+    uint16_t s_inode_size;
+};
+
+struct ext2_filsys_view {
+    uint8_t pad_00[0x20];
+    struct ext2_super_block_view *super;
+};
+
+struct e2fsck_struct_view {
+    struct ext2_filsys_view *fs;
+    uint8_t pad_08[0x40];
+    uint32_t flags;
+};
+
+typedef struct e2fsck_struct_view *e2fsck_t;
+
+struct ext2_inode_large_view {
+    uint8_t pad_00[0x80];
+    uint16_t i_extra_isize;
+};
+
+struct problem_context {
+    uint64_t errcode;
+    uint32_t ino;
+    uint32_t ino2;
+    uint32_t dir;
+    uint32_t pad_14;
+    struct ext2_inode_large_view *inode;
+    void *dirent;
+    uint64_t blk;
+    uint64_t blk2;
+    int64_t blkcount;
+    uint32_t group;
+    uint32_t csum1;
+    uint32_t csum2;
+    uint32_t pad_4c;
+    uint64_t num;
+    const char *str;
+    uint32_t flags;
+};
+
+struct ea_quota {
+    uint64_t blocks;
+    uint64_t inodes;
+};
+
+struct ext2_ext_attr_ibody_header {
+    uint32_t h_magic;
+};
+
+struct ext2_ext_attr_entry {
+    uint8_t e_name_len;
+    uint8_t e_name_index;
+    uint16_t e_value_offs;
+    uint32_t e_value_inum;
+    uint32_t e_value_size;
+    uint32_t e_hash;
+    char e_name[];
+};
+
+void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,
+                struct ea_quota *quota)
+{
+    extern void *region_create(uint64_t, uint64_t);
+    extern int region_allocate(void *, uint64_t, int);
+    extern void region_free(void *);
+    extern uint32_t ext2fs_ext_attr_hash_entry(
+        struct ext2_ext_attr_entry *, void *);
+    extern uint32_t check_large_ea_inode(
+        e2fsck_t, struct ext2_ext_attr_entry *,
+        struct problem_context *, uint64_t *);
+    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
+    extern void e2fsck_write_inode_full(
+        e2fsck_t, uint32_t, void *, int, const char *);
+    extern void record_ea_inode_refs(
+        e2fsck_t, struct problem_context *,
+        struct ext2_ext_attr_entry *, void *);
+
+    struct ext2_super_block_view *super = ctx->fs->super;
+    struct ext2_inode_large_view *inode = pctx->inode;
+    struct ext2_ext_attr_ibody_header *header;
+    struct ext2_ext_attr_entry *first_entry;
+    struct ext2_ext_attr_entry *entry;
+    uint32_t inode_space;
+    uint32_t storage_size;
+    uint32_t free_space;
+    uint32_t problem = 0;
+    uint32_t entry_size;
+    uint32_t name_size;
+    uint32_t hash;
+    uint64_t quota_blocks;
+    void *region;
+
+    quota->blocks = 0;
+    quota->inodes = 0;
+
+    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
+    storage_size = inode_space - inode->i_extra_isize;
+    header = (struct ext2_ext_attr_ibody_header *)
+        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
+    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
+    entry = first_entry;
+
+    region = region_create(0, storage_size);
+    if (region == 0) {
+        fix_problem(ctx, 0x1003f, pctx);
+        ctx->flags |= 1;
+        return;
+    }
+
+    if (region_allocate(region, 0, 4) != 0) {
+        problem = 0x10069;
+    } else {
+        free_space = storage_size - 4;
+
+        while (free_space > 15 && *(uint32_t *)entry != 0) {
+            entry_size = (entry->e_name_len + 19U) & ~3U;
+            if (region_allocate(region,
+                                (uint8_t *)entry - (uint8_t *)header,
+                                (int)entry_size) != 0) {
+                problem = 0x10069;
+                break;
+            }
+
+            free_space -= 16;
+            name_size = (entry->e_name_len + 3U) & ~3U;
+            if (name_size > free_space) {
+                pctx->num = entry->e_name_len;
+                problem = 0x10050;
+                break;
+            }
+            free_space -= name_size;
+
+            if (entry->e_value_inum != 0) {
+                problem = check_large_ea_inode(ctx, entry, pctx,
+                                                &quota_blocks);
+                if (problem != 0)
+                    break;
+                quota->inodes++;
+                quota->blocks += quota_blocks;
+            } else {
+                if (entry->e_value_size > free_space) {
+                    pctx->num = entry->e_value_size;
+                    problem = 0x10053;
+                    break;
+                }
+
+                if (entry->e_value_size != 0 &&
+                    region_allocate(region, entry->e_value_offs + 4U,
+                                    (int)((entry->e_value_size + 3U) &
+                                          ~3U)) != 0) {
+                    problem = 0x10069;
+                    break;
+                }
+
+                hash = ext2fs_ext_attr_hash_entry(
+                    entry, (uint8_t *)first_entry + entry->e_value_offs);
+                if (entry->e_hash != 0 && entry->e_hash != hash) {
+                    pctx->num = entry->e_hash;
+                    problem = 0x10054;
+                    break;
+                }
+                free_space -= entry->e_value_size;
+            }
+
+            entry = (struct ext2_ext_attr_entry *)
+                ((uint8_t *)entry + entry_size);
+        }
+
+        if (problem == 0 &&
+            region_allocate(region,
+                            (uint8_t *)entry - (uint8_t *)header,
+                            4) != 0)
+            problem = 0x10069;
+    }
+
+    region_free(region);
+
+    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
+        header->h_magic = 0;
+        e2fsck_write_inode_full(ctx, pctx->ino, inode,
+                                super->s_rev_level ?
+                                    super->s_inode_size : 0x80,
+                                "pass1");
+        quota->blocks = 0;
+        quota->inodes = 0;
+        return;
+    }
+
+    record_ea_inode_refs(ctx, pctx, first_entry,
+                         (uint8_t *)header + storage_size);
+}

diff --git a/llmdec_codex_6_u0et34/decompiled.c b/llmdec_codex_6_u0et34/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..b64d91e62cc7bec138d8868a96956fc4739e89ef
--- /dev/null
+++ b/llmdec_codex_6_u0et34/decompiled.c
@@ -0,0 +1,198 @@
+#include <stdint.h>
+
+struct ext2_super_block_view {
+    uint8_t pad_00[0x4c];
+    uint32_t s_rev_level;
+    uint8_t pad_50[8];
+    uint16_t s_inode_size;
+};
+
+struct ext2_filsys_view {
+    uint8_t pad_00[0x20];
+    struct ext2_super_block_view *super;
+};
+
+struct e2fsck_struct_view {
+    struct ext2_filsys_view *fs;
+    uint8_t pad_08[0x40];
+    uint32_t flags;
+};
+
+typedef struct e2fsck_struct_view *e2fsck_t;
+
+struct ext2_inode_large_view {
+    uint8_t pad_00[0x80];
+    uint16_t i_extra_isize;
+};
+
+struct problem_context {
+    uint64_t errcode;
+    uint32_t ino;
+    uint32_t ino2;
+    uint32_t dir;
+    uint32_t pad_14;
+    struct ext2_inode_large_view *inode;
+    void *dirent;
+    uint64_t blk;
+    uint64_t blk2;
+    int64_t blkcount;
+    uint32_t group;
+    uint32_t csum1;
+    uint32_t csum2;
+    uint32_t pad_4c;
+    uint64_t num;
+    const char *str;
+    uint32_t flags;
+};
+
+struct ea_quota {
+    uint64_t blocks;
+    uint64_t inodes;
+};
+
+struct ext2_ext_attr_ibody_header {
+    uint32_t h_magic;
+};
+
+struct ext2_ext_attr_entry {
+    uint8_t e_name_len;
+    uint8_t e_name_index;
+    uint16_t e_value_offs;
+    uint32_t e_value_inum;
+    uint32_t e_value_size;
+    uint32_t e_hash;
+    char e_name[];
+};
+
+void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,
+                struct ea_quota *quota)
+{
+    extern void *region_create(uint64_t, uint64_t);
+    extern int region_allocate(void *, uint64_t, int);
+    extern void region_free(void *);
+    extern uint32_t ext2fs_ext_attr_hash_entry(
+        struct ext2_ext_attr_entry *, void *);
+    extern uint32_t check_large_ea_inode(
+        e2fsck_t, struct ext2_ext_attr_entry *,
+        struct problem_context *, uint64_t *);
+    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
+    extern void e2fsck_write_inode_full(
+        e2fsck_t, uint32_t, void *, int, const char *);
+    extern void record_ea_inode_refs(
+        e2fsck_t, struct problem_context *,
+        struct ext2_ext_attr_entry *, void *);
+
+    struct ext2_super_block_view *super = ctx->fs->super;
+    struct ext2_inode_large_view *inode = pctx->inode;
+    struct ext2_ext_attr_ibody_header *header;
+    struct ext2_ext_attr_entry *first_entry;
+    struct ext2_ext_attr_entry *entry;
+    uint32_t inode_space;
+    uint32_t storage_size;
+    uint32_t free_space;
+    uint32_t problem = 0;
+    uint32_t entry_size;
+    uint32_t name_size;
+    uint32_t hash;
+    uint64_t quota_blocks;
+    void *region;
+
+    quota->blocks = 0;
+    quota->inodes = 0;
+
+    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
+    storage_size = inode_space - inode->i_extra_isize;
+    header = (struct ext2_ext_attr_ibody_header *)
+        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
+    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
+    entry = first_entry;
+
+    region = region_create(0, storage_size);
+    if (region == 0) {
+        fix_problem(ctx, 0x1003f, pctx);
+        ctx->flags |= 1;
+        return;
+    }
+
+    if (region_allocate(region, 0, 4) != 0) {
+        problem = 0x10069;
+    } else {
+        free_space = storage_size - 4;
+
+        while (free_space > 15 && *(uint32_t *)entry != 0) {
+            entry_size = (entry->e_name_len + 19U) & ~3U;
+            if (region_allocate(region,
+                                (uint8_t *)entry - (uint8_t *)header,
+                                (int)entry_size) != 0) {
+                problem = 0x10069;
+                break;
+            }
+
+            free_space -= 16;
+            name_size = (entry->e_name_len + 3U) & ~3U;
+            if (name_size > free_space) {
+                pctx->num = entry->e_name_len;
+                problem = 0x10050;
+                break;
+            }
+            free_space -= name_size;
+
+            if (entry->e_value_inum != 0) {
+                problem = check_large_ea_inode(ctx, entry, pctx,
+                                                &quota_blocks);
+                if (problem != 0)
+                    break;
+                quota->inodes++;
+                quota->blocks += quota_blocks;
+            } else {
+                if (entry->e_value_size > free_space) {
+                    pctx->num = entry->e_value_size;
+                    problem = 0x10053;
+                    break;
+                }
+
+                if (entry->e_value_size != 0 &&
+                    region_allocate(region, entry->e_value_offs + 4U,
+                                    (int)((entry->e_value_size + 3U) &
+                                          ~3U)) != 0) {
+                    problem = 0x10069;
+                    break;
+                }
+
+                hash = ext2fs_ext_attr_hash_entry(
+                    entry, (uint8_t *)first_entry + entry->e_value_offs);
+                if (entry->e_hash != 0 && entry->e_hash != hash) {
+                    pctx->num = entry->e_hash;
+                    problem = 0x10054;
+                    break;
+                }
+                free_space -= entry->e_value_size;
+            }
+
+            entry = (struct ext2_ext_attr_entry *)
+                ((uint8_t *)entry + entry_size);
+        }
+
+        if (problem == 0 &&
+            region_allocate(region,
+                            (uint8_t *)entry - (uint8_t *)header,
+                            4) != 0)
+            problem = 0x10069;
+    }
+
+    region_free(region);
+
+    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
+        header->h_magic = 0;
+        e2fsck_write_inode_full(ctx, pctx->ino, inode,
+                                super->s_rev_level ?
+                                    super->s_inode_size : 0x80,
+                                "pass1");
+        quota->blocks = 0;
+        quota->inodes = 0;
+        return;
+    }
+
+    record_ea_inode_refs(ctx, pctx, first_entry,
+                         (uint8_t *)header + storage_size);
+}

exec
/bin/bash -lc 'gcc -std=c11 -Wall -Wextra -Werror -fsyntax-only decompiled.c' in /tmp/llmdec_codex_6_u0et34
exec
/bin/bash -lc 'wc -l decompiled.c' in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
198 decompiled.c

 succeeded in 0ms:
exec
/bin/bash -lc "rg -n '"'^([A-Za-z_][A-Za-z0-9_]*[[:space:]]+)*[A-Za-z_][A-Za-z0-9_]*'"\\(["'^;]*$'"' decompiled.c" in /tmp/llmdec_codex_6_u0et34
 succeeded in 0ms:
67:void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,

diff --git a/llmdec_codex_6_u0et34/decompiled.c b/llmdec_codex_6_u0et34/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..b64d91e62cc7bec138d8868a96956fc4739e89ef
--- /dev/null
+++ b/llmdec_codex_6_u0et34/decompiled.c
@@ -0,0 +1,198 @@
+#include <stdint.h>
+
+struct ext2_super_block_view {
+    uint8_t pad_00[0x4c];
+    uint32_t s_rev_level;
+    uint8_t pad_50[8];
+    uint16_t s_inode_size;
+};
+
+struct ext2_filsys_view {
+    uint8_t pad_00[0x20];
+    struct ext2_super_block_view *super;
+};
+
+struct e2fsck_struct_view {
+    struct ext2_filsys_view *fs;
+    uint8_t pad_08[0x40];
+    uint32_t flags;
+};
+
+typedef struct e2fsck_struct_view *e2fsck_t;
+
+struct ext2_inode_large_view {
+    uint8_t pad_00[0x80];
+    uint16_t i_extra_isize;
+};
+
+struct problem_context {
+    uint64_t errcode;
+    uint32_t ino;
+    uint32_t ino2;
+    uint32_t dir;
+    uint32_t pad_14;
+    struct ext2_inode_large_view *inode;
+    void *dirent;
+    uint64_t blk;
+    uint64_t blk2;
+    int64_t blkcount;
+    uint32_t group;
+    uint32_t csum1;
+    uint32_t csum2;
+    uint32_t pad_4c;
+    uint64_t num;
+    const char *str;
+    uint32_t flags;
+};
+
+struct ea_quota {
+    uint64_t blocks;
+    uint64_t inodes;
+};
+
+struct ext2_ext_attr_ibody_header {
+    uint32_t h_magic;
+};
+
+struct ext2_ext_attr_entry {
+    uint8_t e_name_len;
+    uint8_t e_name_index;
+    uint16_t e_value_offs;
+    uint32_t e_value_inum;
+    uint32_t e_value_size;
+    uint32_t e_hash;
+    char e_name[];
+};
+
+void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,
+                struct ea_quota *quota)
+{
+    extern void *region_create(uint64_t, uint64_t);
+    extern int region_allocate(void *, uint64_t, int);
+    extern void region_free(void *);
+    extern uint32_t ext2fs_ext_attr_hash_entry(
+        struct ext2_ext_attr_entry *, void *);
+    extern uint32_t check_large_ea_inode(
+        e2fsck_t, struct ext2_ext_attr_entry *,
+        struct problem_context *, uint64_t *);
+    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
+    extern void e2fsck_write_inode_full(
+        e2fsck_t, uint32_t, void *, int, const char *);
+    extern void record_ea_inode_refs(
+        e2fsck_t, struct problem_context *,
+        struct ext2_ext_attr_entry *, void *);
+
+    struct ext2_super_block_view *super = ctx->fs->super;
+    struct ext2_inode_large_view *inode = pctx->inode;
+    struct ext2_ext_attr_ibody_header *header;
+    struct ext2_ext_attr_entry *first_entry;
+    struct ext2_ext_attr_entry *entry;
+    uint32_t inode_space;
+    uint32_t storage_size;
+    uint32_t free_space;
+    uint32_t problem = 0;
+    uint32_t entry_size;
+    uint32_t name_size;
+    uint32_t hash;
+    uint64_t quota_blocks;
+    void *region;
+
+    quota->blocks = 0;
+    quota->inodes = 0;
+
+    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
+    storage_size = inode_space - inode->i_extra_isize;
+    header = (struct ext2_ext_attr_ibody_header *)
+        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
+    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
+    entry = first_entry;
+
+    region = region_create(0, storage_size);
+    if (region == 0) {
+        fix_problem(ctx, 0x1003f, pctx);
+        ctx->flags |= 1;
+        return;
+    }
+
+    if (region_allocate(region, 0, 4) != 0) {
+        problem = 0x10069;
+    } else {
+        free_space = storage_size - 4;
+
+        while (free_space > 15 && *(uint32_t *)entry != 0) {
+            entry_size = (entry->e_name_len + 19U) & ~3U;
+            if (region_allocate(region,
+                                (uint8_t *)entry - (uint8_t *)header,
+                                (int)entry_size) != 0) {
+                problem = 0x10069;
+                break;
+            }
+
+            free_space -= 16;
+            name_size = (entry->e_name_len + 3U) & ~3U;
+            if (name_size > free_space) {
+                pctx->num = entry->e_name_len;
+                problem = 0x10050;
+                break;
+            }
+            free_space -= name_size;
+
+            if (entry->e_value_inum != 0) {
+                problem = check_large_ea_inode(ctx, entry, pctx,
+                                                &quota_blocks);
+                if (problem != 0)
+                    break;
+                quota->inodes++;
+                quota->blocks += quota_blocks;
+            } else {
+                if (entry->e_value_size > free_space) {
+                    pctx->num = entry->e_value_size;
+                    problem = 0x10053;
+                    break;
+                }
+
+                if (entry->e_value_size != 0 &&
+                    region_allocate(region, entry->e_value_offs + 4U,
+                                    (int)((entry->e_value_size + 3U) &
+                                          ~3U)) != 0) {
+                    problem = 0x10069;
+                    break;
+                }
+
+                hash = ext2fs_ext_attr_hash_entry(
+                    entry, (uint8_t *)first_entry + entry->e_value_offs);
+                if (entry->e_hash != 0 && entry->e_hash != hash) {
+                    pctx->num = entry->e_hash;
+                    problem = 0x10054;
+                    break;
+                }
+                free_space -= entry->e_value_size;
+            }
+
+            entry = (struct ext2_ext_attr_entry *)
+                ((uint8_t *)entry + entry_size);
+        }
+
+        if (problem == 0 &&
+            region_allocate(region,
+                            (uint8_t *)entry - (uint8_t *)header,
+                            4) != 0)
+            problem = 0x10069;
+    }
+
+    region_free(region);
+
+    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
+        header->h_magic = 0;
+        e2fsck_write_inode_full(ctx, pctx->ino, inode,
+                                super->s_rev_level ?
+                                    super->s_inode_size : 0x80,
+                                "pass1");
+        quota->blocks = 0;
+        quota->inodes = 0;
+        return;
+    }
+
+    record_ea_inode_refs(ctx, pctx, first_entry,
+                         (uint8_t *)header + storage_size);
+}

codex
Created and syntax-checked [decompiled.c](/tmp/llmdec_codex_6_u0et34/decompiled.c). It contains exactly one function definition, `sub_1f800`.
diff --git a/llmdec_codex_6_u0et34/decompiled.c b/llmdec_codex_6_u0et34/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..b64d91e62cc7bec138d8868a96956fc4739e89ef
--- /dev/null
+++ b/llmdec_codex_6_u0et34/decompiled.c
@@ -0,0 +1,198 @@
+#include <stdint.h>
+
+struct ext2_super_block_view {
+    uint8_t pad_00[0x4c];
+    uint32_t s_rev_level;
+    uint8_t pad_50[8];
+    uint16_t s_inode_size;
+};
+
+struct ext2_filsys_view {
+    uint8_t pad_00[0x20];
+    struct ext2_super_block_view *super;
+};
+
+struct e2fsck_struct_view {
+    struct ext2_filsys_view *fs;
+    uint8_t pad_08[0x40];
+    uint32_t flags;
+};
+
+typedef struct e2fsck_struct_view *e2fsck_t;
+
+struct ext2_inode_large_view {
+    uint8_t pad_00[0x80];
+    uint16_t i_extra_isize;
+};
+
+struct problem_context {
+    uint64_t errcode;
+    uint32_t ino;
+    uint32_t ino2;
+    uint32_t dir;
+    uint32_t pad_14;
+    struct ext2_inode_large_view *inode;
+    void *dirent;
+    uint64_t blk;
+    uint64_t blk2;
+    int64_t blkcount;
+    uint32_t group;
+    uint32_t csum1;
+    uint32_t csum2;
+    uint32_t pad_4c;
+    uint64_t num;
+    const char *str;
+    uint32_t flags;
+};
+
+struct ea_quota {
+    uint64_t blocks;
+    uint64_t inodes;
+};
+
+struct ext2_ext_attr_ibody_header {
+    uint32_t h_magic;
+};
+
+struct ext2_ext_attr_entry {
+    uint8_t e_name_len;
+    uint8_t e_name_index;
+    uint16_t e_value_offs;
+    uint32_t e_value_inum;
+    uint32_t e_value_size;
+    uint32_t e_hash;
+    char e_name[];
+};
+
+void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,
+                struct ea_quota *quota)
+{
+    extern void *region_create(uint64_t, uint64_t);
+    extern int region_allocate(void *, uint64_t, int);
+    extern void region_free(void *);
+    extern uint32_t ext2fs_ext_attr_hash_entry(
+        struct ext2_ext_attr_entry *, void *);
+    extern uint32_t check_large_ea_inode(
+        e2fsck_t, struct ext2_ext_attr_entry *,
+        struct problem_context *, uint64_t *);
+    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
+    extern void e2fsck_write_inode_full(
+        e2fsck_t, uint32_t, void *, int, const char *);
+    extern void record_ea_inode_refs(
+        e2fsck_t, struct problem_context *,
+        struct ext2_ext_attr_entry *, void *);
+
+    struct ext2_super_block_view *super = ctx->fs->super;
+    struct ext2_inode_large_view *inode = pctx->inode;
+    struct ext2_ext_attr_ibody_header *header;
+    struct ext2_ext_attr_entry *first_entry;
+    struct ext2_ext_attr_entry *entry;
+    uint32_t inode_space;
+    uint32_t storage_size;
+    uint32_t free_space;
+    uint32_t problem = 0;
+    uint32_t entry_size;
+    uint32_t name_size;
+    uint32_t hash;
+    uint64_t quota_blocks;
+    void *region;
+
+    quota->blocks = 0;
+    quota->inodes = 0;
+
+    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
+    storage_size = inode_space - inode->i_extra_isize;
+    header = (struct ext2_ext_attr_ibody_header *)
+        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
+    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
+    entry = first_entry;
+
+    region = region_create(0, storage_size);
+    if (region == 0) {
+        fix_problem(ctx, 0x1003f, pctx);
+        ctx->flags |= 1;
+        return;
+    }
+
+    if (region_allocate(region, 0, 4) != 0) {
+        problem = 0x10069;
+    } else {
+        free_space = storage_size - 4;
+
+        while (free_space > 15 && *(uint32_t *)entry != 0) {
+            entry_size = (entry->e_name_len + 19U) & ~3U;
+            if (region_allocate(region,
+                                (uint8_t *)entry - (uint8_t *)header,
+                                (int)entry_size) != 0) {
+                problem = 0x10069;
+                break;
+            }
+
+            free_space -= 16;
+            name_size = (entry->e_name_len + 3U) & ~3U;
+            if (name_size > free_space) {
+                pctx->num = entry->e_name_len;
+                problem = 0x10050;
+                break;
+            }
+            free_space -= name_size;
+
+            if (entry->e_value_inum != 0) {
+                problem = check_large_ea_inode(ctx, entry, pctx,
+                                                &quota_blocks);
+                if (problem != 0)
+                    break;
+                quota->inodes++;
+                quota->blocks += quota_blocks;
+            } else {
+                if (entry->e_value_size > free_space) {
+                    pctx->num = entry->e_value_size;
+                    problem = 0x10053;
+                    break;
+                }
+
+                if (entry->e_value_size != 0 &&
+                    region_allocate(region, entry->e_value_offs + 4U,
+                                    (int)((entry->e_value_size + 3U) &
+                                          ~3U)) != 0) {
+                    problem = 0x10069;
+                    break;
+                }
+
+                hash = ext2fs_ext_attr_hash_entry(
+                    entry, (uint8_t *)first_entry + entry->e_value_offs);
+                if (entry->e_hash != 0 && entry->e_hash != hash) {
+                    pctx->num = entry->e_hash;
+                    problem = 0x10054;
+                    break;
+                }
+                free_space -= entry->e_value_size;
+            }
+
+            entry = (struct ext2_ext_attr_entry *)
+                ((uint8_t *)entry + entry_size);
+        }
+
+        if (problem == 0 &&
+            region_allocate(region,
+                            (uint8_t *)entry - (uint8_t *)header,
+                            4) != 0)
+            problem = 0x10069;
+    }
+
+    region_free(region);
+
+    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
+        header->h_magic = 0;
+        e2fsck_write_inode_full(ctx, pctx->ino, inode,
+                                super->s_rev_level ?
+                                    super->s_inode_size : 0x80,
+                                "pass1");
+        quota->blocks = 0;
+        quota->inodes = 0;
+        return;
+    }
+
+    record_ea_inode_refs(ctx, pctx, first_entry,
+                         (uint8_t *)header + storage_size);
+}

tokens used
123,601
```

## Reconstructed C

```c
#include <stdint.h>

struct ext2_super_block_view {
    uint8_t pad_00[0x4c];
    uint32_t s_rev_level;
    uint8_t pad_50[8];
    uint16_t s_inode_size;
};

struct ext2_filsys_view {
    uint8_t pad_00[0x20];
    struct ext2_super_block_view *super;
};

struct e2fsck_struct_view {
    struct ext2_filsys_view *fs;
    uint8_t pad_08[0x40];
    uint32_t flags;
};

typedef struct e2fsck_struct_view *e2fsck_t;

struct ext2_inode_large_view {
    uint8_t pad_00[0x80];
    uint16_t i_extra_isize;
};

struct problem_context {
    uint64_t errcode;
    uint32_t ino;
    uint32_t ino2;
    uint32_t dir;
    uint32_t pad_14;
    struct ext2_inode_large_view *inode;
    void *dirent;
    uint64_t blk;
    uint64_t blk2;
    int64_t blkcount;
    uint32_t group;
    uint32_t csum1;
    uint32_t csum2;
    uint32_t pad_4c;
    uint64_t num;
    const char *str;
    uint32_t flags;
};

struct ea_quota {
    uint64_t blocks;
    uint64_t inodes;
};

struct ext2_ext_attr_ibody_header {
    uint32_t h_magic;
};

struct ext2_ext_attr_entry {
    uint8_t e_name_len;
    uint8_t e_name_index;
    uint16_t e_value_offs;
    uint32_t e_value_inum;
    uint32_t e_value_size;
    uint32_t e_hash;
    char e_name[];
};

void sub_1f800(e2fsck_t ctx, struct problem_context *pctx,
                struct ea_quota *quota)
{
    extern void *region_create(uint64_t, uint64_t);
    extern int region_allocate(void *, uint64_t, int);
    extern void region_free(void *);
    extern uint32_t ext2fs_ext_attr_hash_entry(
        struct ext2_ext_attr_entry *, void *);
    extern uint32_t check_large_ea_inode(
        e2fsck_t, struct ext2_ext_attr_entry *,
        struct problem_context *, uint64_t *);
    extern int fix_problem(e2fsck_t, uint32_t, struct problem_context *);
    extern void e2fsck_write_inode_full(
        e2fsck_t, uint32_t, void *, int, const char *);
    extern void record_ea_inode_refs(
        e2fsck_t, struct problem_context *,
        struct ext2_ext_attr_entry *, void *);

    struct ext2_super_block_view *super = ctx->fs->super;
    struct ext2_inode_large_view *inode = pctx->inode;
    struct ext2_ext_attr_ibody_header *header;
    struct ext2_ext_attr_entry *first_entry;
    struct ext2_ext_attr_entry *entry;
    uint32_t inode_space;
    uint32_t storage_size;
    uint32_t free_space;
    uint32_t problem = 0;
    uint32_t entry_size;
    uint32_t name_size;
    uint32_t hash;
    uint64_t quota_blocks;
    void *region;

    quota->blocks = 0;
    quota->inodes = 0;

    inode_space = super->s_rev_level ? super->s_inode_size - 0x80 : 0;
    storage_size = inode_space - inode->i_extra_isize;
    header = (struct ext2_ext_attr_ibody_header *)
        ((uint8_t *)inode + 0x80 + inode->i_extra_isize);
    first_entry = (struct ext2_ext_attr_entry *)(header + 1);
    entry = first_entry;

    region = region_create(0, storage_size);
    if (region == 0) {
        fix_problem(ctx, 0x1003f, pctx);
        ctx->flags |= 1;
        return;
    }

    if (region_allocate(region, 0, 4) != 0) {
        problem = 0x10069;
    } else {
        free_space = storage_size - 4;

        while (free_space > 15 && *(uint32_t *)entry != 0) {
            entry_size = (entry->e_name_len + 19U) & ~3U;
            if (region_allocate(region,
                                (uint8_t *)entry - (uint8_t *)header,
                                (int)entry_size) != 0) {
                problem = 0x10069;
                break;
            }

            free_space -= 16;
            name_size = (entry->e_name_len + 3U) & ~3U;
            if (name_size > free_space) {
                pctx->num = entry->e_name_len;
                problem = 0x10050;
                break;
            }
            free_space -= name_size;

            if (entry->e_value_inum != 0) {
                problem = check_large_ea_inode(ctx, entry, pctx,
                                                &quota_blocks);
                if (problem != 0)
                    break;
                quota->inodes++;
                quota->blocks += quota_blocks;
            } else {
                if (entry->e_value_size > free_space) {
                    pctx->num = entry->e_value_size;
                    problem = 0x10053;
                    break;
                }

                if (entry->e_value_size != 0 &&
                    region_allocate(region, entry->e_value_offs + 4U,
                                    (int)((entry->e_value_size + 3U) &
                                          ~3U)) != 0) {
                    problem = 0x10069;
                    break;
                }

                hash = ext2fs_ext_attr_hash_entry(
                    entry, (uint8_t *)first_entry + entry->e_value_offs);
                if (entry->e_hash != 0 && entry->e_hash != hash) {
                    pctx->num = entry->e_hash;
                    problem = 0x10054;
                    break;
                }
                free_space -= entry->e_value_size;
            }

            entry = (struct ext2_ext_attr_entry *)
                ((uint8_t *)entry + entry_size);
        }

        if (problem == 0 &&
            region_allocate(region,
                            (uint8_t *)entry - (uint8_t *)header,
                            4) != 0)
            problem = 0x10069;
    }

    region_free(region);

    if (problem != 0 && fix_problem(ctx, problem, pctx)) {
        header->h_magic = 0;
        e2fsck_write_inode_full(ctx, pctx->ino, inode,
                                super->s_rev_level ?
                                    super->s_inode_size : 0x80,
                                "pass1");
        quota->blocks = 0;
        quota->inodes = 0;
        return;
    }

    record_ea_inode_refs(ctx, pctx, first_entry,
                         (uint8_t *)header + storage_size);
}

```
