# codex trace — O2-noinline__openssh-portable__ssh-sk-helper__sub_14ea0_0x14ea0

- model: gpt-5.6-sol
- binary given to agent: target.bin (original: ssh-sk-helper)
- status: ok
- elapsed: 304s

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
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x14ea0.
- Name the reconstructed function `sub_14ea0` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x14ea0: push r15
  0x14ea2: push r14
  0x14ea4: mov r14, rdi
  0x14ea7: push r13
  0x14ea9: push r12
  0x14eab: push rbp
  0x14eac: push rbx
  0x14ead: mov rbx, rsi
  0x14eb0: mov rsi, rdx
  0x14eb3: sub rsp, 0x58
  0x14eb7: mov rax, qword ptr fs:[0x28]
  0x14ec0: mov qword ptr [rsp + 0x48], rax
  0x14ec5: xor eax, eax
  0x14ec7: mov rax, qword ptr [rbx + 0x80]
  0x14ece: mov qword ptr [rsp + 8], 0
  0x14ed7: mov qword ptr [rsp + 0x10], 0
  0x14ee0: mov qword ptr [rsp + 0x18], 0
  0x14ee9: mov qword ptr [rsp + 0x20], 0
  0x14ef2: mov qword ptr [rsp + 0x28], 0
  0x14efb: mov qword ptr [rsp + 0x30], 0
  0x14f04: mov qword ptr [rsp + 0x38], 0
  0x14f0d: mov rdi, qword ptr [rax]
  0x14f10: call 0x1aad0
  0x14f15: mov r12d, eax
  0x14f18: test eax, eax
  0x14f1a: je 0x14fc8
  0x14f20: mov rax, qword ptr [rsp + 0x48]
  0x14f25: sub rax, qword ptr fs:[0x28]
  0x14f2e: jne 0x1525b
  0x14f34: add rsp, 0x58
  0x14f38: mov eax, r12d
  0x14f3b: pop rbx

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_14ea0`).

```

## Agent transcript (stdout/stderr)

```
Created [decompiled.c](/tmp/llmdec_codex_s6m_4ok7/decompiled.c) with the reconstructed `sub_14ea0` function.

Reading additional input from stdin...
OpenAI Codex v0.144.1
--------
workdir: /tmp/llmdec_codex_s6m_4ok7
model: gpt-5.6-sol
provider: openai
approval: never
sandbox: danger-full-access
reasoning effort: high
reasoning summaries: none
session id: 019f87fd-849d-7e83-908c-bfeea9b5eb91
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
- The binary is STRIPPED, so the target function has no symbol name. Identify it by its entry virtual address: 0x14ea0.
- Name the reconstructed function `sub_14ea0` in your C output.

DISASSEMBLY HINT (linear from the entry; run objdump yourself for the authoritative full listing):
  0x14ea0: push r15
  0x14ea2: push r14
  0x14ea4: mov r14, rdi
  0x14ea7: push r13
  0x14ea9: push r12
  0x14eab: push rbp
  0x14eac: push rbx
  0x14ead: mov rbx, rsi
  0x14eb0: mov rsi, rdx
  0x14eb3: sub rsp, 0x58
  0x14eb7: mov rax, qword ptr fs:[0x28]
  0x14ec0: mov qword ptr [rsp + 0x48], rax
  0x14ec5: xor eax, eax
  0x14ec7: mov rax, qword ptr [rbx + 0x80]
  0x14ece: mov qword ptr [rsp + 8], 0
  0x14ed7: mov qword ptr [rsp + 0x10], 0
  0x14ee0: mov qword ptr [rsp + 0x18], 0
  0x14ee9: mov qword ptr [rsp + 0x20], 0
  0x14ef2: mov qword ptr [rsp + 0x28], 0
  0x14efb: mov qword ptr [rsp + 0x30], 0
  0x14f04: mov qword ptr [rsp + 0x38], 0
  0x14f0d: mov rdi, qword ptr [rax]
  0x14f10: call 0x1aad0
  0x14f15: mov r12d, eax
  0x14f18: test eax, eax
  0x14f1a: je 0x14fc8
  0x14f20: mov rax, qword ptr [rsp + 0x48]
  0x14f25: sub rax, qword ptr fs:[0x28]
  0x14f2e: jne 0x1525b
  0x14f34: add rsp, 0x58
  0x14f38: mov eax, r12d
  0x14f3b: pop rbx

Write the reconstructed C to the file `decompiled.c` in your working directory. When finished, make sure `decompiled.c` exists and contains only the C code (one definition of `sub_14ea0`).

codex
I’ll inspect the binary with only the permitted low-level tools, map the complete function and its callees/data references, then write and sanity-check `decompiled.c`.
exec
/bin/bash -lc 'file ./target.bin && objdump -d -M intel --start-address=0x14ea0 --stop-address=0x15280 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
./target.bin: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=746658591375970c8a5921c0a17ff65d6271c5ed, for GNU/Linux 3.2.0, stripped

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000014ea0 <closefrom@@Base-0x22920>:
   14ea0:	41 57                	push   r15
   14ea2:	41 56                	push   r14
   14ea4:	49 89 fe             	mov    r14,rdi
   14ea7:	41 55                	push   r13
   14ea9:	41 54                	push   r12
   14eab:	55                   	push   rbp
   14eac:	53                   	push   rbx
   14ead:	48 89 f3             	mov    rbx,rsi
   14eb0:	48 89 d6             	mov    rsi,rdx
   14eb3:	48 83 ec 58          	sub    rsp,0x58
   14eb7:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   14ebe:	00 00 
   14ec0:	48 89 44 24 48       	mov    QWORD PTR [rsp+0x48],rax
   14ec5:	31 c0                	xor    eax,eax
   14ec7:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   14ece:	48 c7 44 24 08 00 00 	mov    QWORD PTR [rsp+0x8],0x0
   14ed5:	00 00 
   14ed7:	48 c7 44 24 10 00 00 	mov    QWORD PTR [rsp+0x10],0x0
   14ede:	00 00 
   14ee0:	48 c7 44 24 18 00 00 	mov    QWORD PTR [rsp+0x18],0x0
   14ee7:	00 00 
   14ee9:	48 c7 44 24 20 00 00 	mov    QWORD PTR [rsp+0x20],0x0
   14ef0:	00 00 
   14ef2:	48 c7 44 24 28 00 00 	mov    QWORD PTR [rsp+0x28],0x0
   14ef9:	00 00 
   14efb:	48 c7 44 24 30 00 00 	mov    QWORD PTR [rsp+0x30],0x0
   14f02:	00 00 
   14f04:	48 c7 44 24 38 00 00 	mov    QWORD PTR [rsp+0x38],0x0
   14f0b:	00 00 
   14f0d:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   14f10:	e8 bb 5b 00 00       	call   1aad0 <getservbyname@plt+0x13cc0>
   14f15:	41 89 c4             	mov    r12d,eax
   14f18:	85 c0                	test   eax,eax
   14f1a:	0f 84 a8 00 00 00    	je     14fc8 <getservbyname@plt+0xe1b8>
   14f20:	48 8b 44 24 48       	mov    rax,QWORD PTR [rsp+0x48]
   14f25:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   14f2c:	00 00 
   14f2e:	0f 85 27 03 00 00    	jne    1525b <getservbyname@plt+0xe44b>
   14f34:	48 83 c4 58          	add    rsp,0x58
   14f38:	44 89 e0             	mov    eax,r12d
   14f3b:	5b                   	pop    rbx
   14f3c:	5d                   	pop    rbp
   14f3d:	41 5c                	pop    r12
   14f3f:	41 5d                	pop    r13
   14f41:	41 5e                	pop    r14
   14f43:	41 5f                	pop    r15
   14f45:	d9 ee                	fldz   
   14f47:	d9 ee                	fldz   
   14f49:	d9 ee                	fldz   
   14f4b:	d9 ee                	fldz   
   14f4d:	d9 ee                	fldz   
   14f4f:	d9 ee                	fldz   
   14f51:	d9 ee                	fldz   
   14f53:	d9 ee                	fldz   
   14f55:	dd d8                	fstp   st(0)
   14f57:	dd d8                	fstp   st(0)
   14f59:	dd d8                	fstp   st(0)
   14f5b:	dd d8                	fstp   st(0)
   14f5d:	dd d8                	fstp   st(0)
   14f5f:	dd d8                	fstp   st(0)
   14f61:	dd d8                	fstp   st(0)
   14f63:	dd d8                	fstp   st(0)
   14f65:	31 d2                	xor    edx,edx
   14f67:	31 c9                	xor    ecx,ecx
   14f69:	31 f6                	xor    esi,esi
   14f6b:	31 ff                	xor    edi,edi
   14f6d:	66 0f ef c0          	pxor   xmm0,xmm0
   14f71:	66 0f ef c9          	pxor   xmm1,xmm1
   14f75:	66 0f ef d2          	pxor   xmm2,xmm2
   14f79:	66 0f ef db          	pxor   xmm3,xmm3
   14f7d:	66 0f ef e4          	pxor   xmm4,xmm4
   14f81:	66 0f ef ed          	pxor   xmm5,xmm5
   14f85:	66 0f ef f6          	pxor   xmm6,xmm6
   14f89:	66 0f ef ff          	pxor   xmm7,xmm7
   14f8d:	45 31 c0             	xor    r8d,r8d
   14f90:	45 31 c9             	xor    r9d,r9d
   14f93:	45 31 d2             	xor    r10d,r10d
   14f96:	45 31 db             	xor    r11d,r11d
   14f99:	66 45 0f ef c0       	pxor   xmm8,xmm8
   14f9e:	66 45 0f ef c9       	pxor   xmm9,xmm9
   14fa3:	66 45 0f ef d2       	pxor   xmm10,xmm10
   14fa8:	66 45 0f ef db       	pxor   xmm11,xmm11
   14fad:	66 45 0f ef e4       	pxor   xmm12,xmm12
   14fb2:	66 45 0f ef ed       	pxor   xmm13,xmm13
   14fb7:	66 45 0f ef f6       	pxor   xmm14,xmm14
   14fbc:	66 45 0f ef ff       	pxor   xmm15,xmm15
   14fc1:	c3                   	ret    
   14fc2:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   14fc8:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   14fcf:	4c 89 f7             	mov    rdi,r14
   14fd2:	48 8d 70 10          	lea    rsi,[rax+0x10]
   14fd6:	e8 35 4c 00 00       	call   19c10 <getservbyname@plt+0x12e00>
   14fdb:	85 c0                	test   eax,eax
   14fdd:	75 17                	jne    14ff6 <getservbyname@plt+0xe1e6>
   14fdf:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   14fe6:	4c 89 f7             	mov    rdi,r14
   14fe9:	48 8d 70 08          	lea    rsi,[rax+0x8]
   14fed:	e8 de 4c 00 00       	call   19cd0 <getservbyname@plt+0x12ec0>
   14ff2:	85 c0                	test   eax,eax
   14ff4:	74 42                	je     15038 <getservbyname@plt+0xe228>
   14ff6:	41 bc fc ff ff ff    	mov    r12d,0xfffffffc
   14ffc:	48 8b 7c 24 20       	mov    rdi,QWORD PTR [rsp+0x20]
   15001:	e8 da 6c ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   15006:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1500b:	e8 d0 6c ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   15010:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   15015:	e8 c6 6c ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   1501a:	48 8b 7c 24 08       	mov    rdi,QWORD PTR [rsp+0x8]
   1501f:	e8 bc 6c ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   15024:	48 8b 7c 24 28       	mov    rdi,QWORD PTR [rsp+0x28]
   15029:	e8 82 14 ff ff       	call   64b0 <free@plt>
   1502e:	e9 ed fe ff ff       	jmp    14f20 <getservbyname@plt+0xe110>
   15033:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   15038:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   1503f:	48 8d 54 24 38       	lea    rdx,[rsp+0x38]
   15044:	4c 89 f7             	mov    rdi,r14
   15047:	48 8d 70 18          	lea    rsi,[rax+0x18]
   1504b:	e8 a0 56 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   15050:	85 c0                	test   eax,eax
   15052:	75 a2                	jne    14ff6 <getservbyname@plt+0xe1e6>
   15054:	48 8d 74 24 08       	lea    rsi,[rsp+0x8]
   15059:	4c 89 f7             	mov    rdi,r14
   1505c:	e8 3f 68 00 00       	call   1b8a0 <getservbyname@plt+0x14a90>
   15061:	85 c0                	test   eax,eax
   15063:	75 91                	jne    14ff6 <getservbyname@plt+0xe1e6>
   15065:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   1506c:	4c 89 f7             	mov    rdi,r14
   1506f:	48 8d 70 30          	lea    rsi,[rax+0x30]
   15073:	e8 98 4b 00 00       	call   19c10 <getservbyname@plt+0x12e00>
   15078:	85 c0                	test   eax,eax
   1507a:	0f 85 76 ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   15080:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15087:	4c 89 f7             	mov    rdi,r14
   1508a:	48 8d 70 38          	lea    rsi,[rax+0x38]
   1508e:	e8 7d 4b 00 00       	call   19c10 <getservbyname@plt+0x12e00>
   15093:	85 c0                	test   eax,eax
   15095:	0f 85 5b ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   1509b:	48 8d 74 24 10       	lea    rsi,[rsp+0x10]
   150a0:	4c 89 f7             	mov    rdi,r14
   150a3:	e8 f8 67 00 00       	call   1b8a0 <getservbyname@plt+0x14a90>
   150a8:	85 c0                	test   eax,eax
   150aa:	0f 85 46 ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   150b0:	48 8d 74 24 18       	lea    rsi,[rsp+0x18]
   150b5:	4c 89 f7             	mov    rdi,r14
   150b8:	e8 e3 67 00 00       	call   1b8a0 <getservbyname@plt+0x14a90>
   150bd:	85 c0                	test   eax,eax
   150bf:	0f 85 31 ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   150c5:	31 d2                	xor    edx,edx
   150c7:	31 f6                	xor    esi,esi
   150c9:	4c 89 f7             	mov    rdi,r14
   150cc:	e8 8f 53 00 00       	call   1a460 <getservbyname@plt+0x13650>
   150d1:	85 c0                	test   eax,eax
   150d3:	0f 85 1d ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   150d9:	48 8d 74 24 20       	lea    rsi,[rsp+0x20]
   150de:	4c 89 f7             	mov    rdi,r14
   150e1:	e8 ba 67 00 00       	call   1b8a0 <getservbyname@plt+0x14a90>
   150e6:	85 c0                	test   eax,eax
   150e8:	0f 85 08 ff ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   150ee:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   150f5:	48 8b 38             	mov    rdi,QWORD PTR [rax]
   150f8:	e8 d3 72 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   150fd:	4c 89 f7             	mov    rdi,r14
   15100:	49 89 c5             	mov    r13,rax
   15103:	e8 c8 72 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   15108:	48 8d 54 24 30       	lea    rdx,[rsp+0x30]
   1510d:	48 8d 74 24 28       	lea    rsi,[rsp+0x28]
   15112:	4c 89 f7             	mov    rdi,r14
   15115:	48 89 c5             	mov    rbp,rax
   15118:	e8 73 54 00 00       	call   1a590 <getservbyname@plt+0x13780>
   1511d:	85 c0                	test   eax,eax
   1511f:	0f 85 d1 fe ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   15125:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   1512c:	41 bc ee ff ff ff    	mov    r12d,0xffffffee
   15132:	8b 40 08             	mov    eax,DWORD PTR [rax+0x8]
   15135:	83 e8 01             	sub    eax,0x1
   15138:	83 f8 01             	cmp    eax,0x1
   1513b:	0f 87 bb fe ff ff    	ja     14ffc <getservbyname@plt+0xe1ec>
   15141:	4c 8d 64 24 40       	lea    r12,[rsp+0x40]
   15146:	eb 7d                	jmp    151c5 <getservbyname@plt+0xe3b5>
   15148:	48 c7 44 24 40 00 00 	mov    QWORD PTR [rsp+0x40],0x0
   1514f:	00 00 
   15151:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15158:	81 78 20 ff 00 00 00 	cmp    DWORD PTR [rax+0x20],0xff
   1515f:	0f 87 91 fe ff ff    	ja     14ff6 <getservbyname@plt+0xe1e6>
   15165:	48 8b 7c 24 08       	mov    rdi,QWORD PTR [rsp+0x8]
   1516a:	31 d2                	xor    edx,edx
   1516c:	4c 89 e6             	mov    rsi,r12
   1516f:	e8 7c 55 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   15174:	85 c0                	test   eax,eax
   15176:	0f 85 7a fe ff ff    	jne    14ff6 <getservbyname@plt+0xe1e6>
   1517c:	4c 8b bb 80 00 00 00 	mov    r15,QWORD PTR [rbx+0x80]
   15183:	b9 08 00 00 00       	mov    ecx,0x8
   15188:	4d 8b 77 28          	mov    r14,QWORD PTR [r15+0x28]
   1518c:	41 8b 77 20          	mov    esi,DWORD PTR [r15+0x20]
   15190:	4c 89 f7             	mov    rdi,r14
   15193:	8d 56 01             	lea    edx,[rsi+0x1]
   15196:	e8 b5 68 02 00       	call   3ba50 <closefrom@@Base+0x4290>
   1519b:	49 89 47 28          	mov    QWORD PTR [r15+0x28],rax
   1519f:	48 8b 93 80 00 00 00 	mov    rdx,QWORD PTR [rbx+0x80]
   151a6:	48 8b 4a 28          	mov    rcx,QWORD PTR [rdx+0x28]
   151aa:	48 85 c9             	test   rcx,rcx
   151ad:	0f 84 ad 00 00 00    	je     15260 <getservbyname@plt+0xe450>
   151b3:	8b 42 20             	mov    eax,DWORD PTR [rdx+0x20]
   151b6:	8d 70 01             	lea    esi,[rax+0x1]
   151b9:	89 72 20             	mov    DWORD PTR [rdx+0x20],esi
   151bc:	48 8b 54 24 40       	mov    rdx,QWORD PTR [rsp+0x40]
   151c1:	48 89 14 c1          	mov    QWORD PTR [rcx+rax*8],rdx
   151c5:	48 8b 7c 24 08       	mov    rdi,QWORD PTR [rsp+0x8]
   151ca:	e8 01 72 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   151cf:	48 85 c0             	test   rax,rax
   151d2:	0f 85 70 ff ff ff    	jne    15148 <getservbyname@plt+0xe338>
   151d8:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   151df:	48 8b 74 24 10       	mov    rsi,QWORD PTR [rsp+0x10]
   151e4:	48 8b 78 40          	mov    rdi,QWORD PTR [rax+0x40]
   151e8:	e8 e3 58 00 00       	call   1aad0 <getservbyname@plt+0x13cc0>
   151ed:	41 89 c4             	mov    r12d,eax
   151f0:	85 c0                	test   eax,eax
   151f2:	0f 85 04 fe ff ff    	jne    14ffc <getservbyname@plt+0xe1ec>
   151f8:	48 8b 74 24 18       	mov    rsi,QWORD PTR [rsp+0x18]
   151fd:	48 85 f6             	test   rsi,rsi
   15200:	74 48                	je     1524a <getservbyname@plt+0xe43a>
   15202:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15209:	48 8b 78 48          	mov    rdi,QWORD PTR [rax+0x48]
   1520d:	e8 be 58 00 00       	call   1aad0 <getservbyname@plt+0x13cc0>
   15212:	41 89 c4             	mov    r12d,eax
   15215:	85 c0                	test   eax,eax
   15217:	74 31                	je     1524a <getservbyname@plt+0xe43a>
   15219:	e9 de fd ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>
   1521e:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   15223:	31 d2                	xor    edx,edx
   15225:	31 f6                	xor    esi,esi
   15227:	e8 34 52 00 00       	call   1a460 <getservbyname@plt+0x13650>
   1522c:	85 c0                	test   eax,eax
   1522e:	0f 85 2d 01 00 00    	jne    15361 <getservbyname@plt+0xe551>
   15234:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   15239:	31 d2                	xor    edx,edx
   1523b:	31 f6                	xor    esi,esi
   1523d:	e8 1e 52 00 00       	call   1a460 <getservbyname@plt+0x13650>
   15242:	85 c0                	test   eax,eax
   15244:	0f 85 17 01 00 00    	jne    15361 <getservbyname@plt+0xe551>
   1524a:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1524f:	e8 7c 71 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   15254:	48 85 c0             	test   rax,rax
   15257:	75 c5                	jne    1521e <getservbyname@plt+0xe40e>
   15259:	eb 5b                	jmp    152b6 <getservbyname@plt+0xe4a6>
   1525b:	e8 80 17 ff ff       	call   69e0 <__stack_chk_fail@plt>
   15260:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   15265:	41 bc fe ff ff ff    	mov    r12d,0xfffffffe
   1526b:	e8 40 12 ff ff       	call   64b0 <free@plt>
   15270:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15277:	4c 89 70 28          	mov    QWORD PTR [rax+0x28],r14
   1527b:	e9 7c fd ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x15240 --stop-address=0x15430 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000015240 <closefrom@@Base-0x22580>:
   15240:	00 00                	add    BYTE PTR [rax],al
   15242:	85 c0                	test   eax,eax
   15244:	0f 85 17 01 00 00    	jne    15361 <getservbyname@plt+0xe551>
   1524a:	48 8b 7c 24 10       	mov    rdi,QWORD PTR [rsp+0x10]
   1524f:	e8 7c 71 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   15254:	48 85 c0             	test   rax,rax
   15257:	75 c5                	jne    1521e <getservbyname@plt+0xe40e>
   15259:	eb 5b                	jmp    152b6 <getservbyname@plt+0xe4a6>
   1525b:	e8 80 17 ff ff       	call   69e0 <__stack_chk_fail@plt>
   15260:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   15265:	41 bc fe ff ff ff    	mov    r12d,0xfffffffe
   1526b:	e8 40 12 ff ff       	call   64b0 <free@plt>
   15270:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15277:	4c 89 70 28          	mov    QWORD PTR [rax+0x28],r14
   1527b:	e9 7c fd ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>
   15280:	e8 4b 71 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   15285:	48 85 c0             	test   rax,rax
   15288:	74 36                	je     152c0 <getservbyname@plt+0xe4b0>
   1528a:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   1528f:	31 d2                	xor    edx,edx
   15291:	31 f6                	xor    esi,esi
   15293:	e8 c8 51 00 00       	call   1a460 <getservbyname@plt+0x13650>
   15298:	85 c0                	test   eax,eax
   1529a:	0f 85 dc 00 00 00    	jne    1537c <getservbyname@plt+0xe56c>
   152a0:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   152a5:	31 d2                	xor    edx,edx
   152a7:	31 f6                	xor    esi,esi
   152a9:	e8 b2 51 00 00       	call   1a460 <getservbyname@plt+0x13650>
   152ae:	85 c0                	test   eax,eax
   152b0:	0f 85 c6 00 00 00    	jne    1537c <getservbyname@plt+0xe56c>
   152b6:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   152bb:	48 85 ff             	test   rdi,rdi
   152be:	75 c0                	jne    15280 <getservbyname@plt+0xe470>
   152c0:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   152c7:	48 8b 7c 24 20       	mov    rdi,QWORD PTR [rsp+0x20]
   152cc:	31 d2                	xor    edx,edx
   152ce:	48 8d 70 50          	lea    rsi,[rax+0x50]
   152d2:	e8 a9 f4 ff ff       	call   14780 <getservbyname@plt+0xd970>
   152d7:	85 c0                	test   eax,eax
   152d9:	0f 85 b2 00 00 00    	jne    15391 <getservbyname@plt+0xe581>
   152df:	4c 8b b3 80 00 00 00 	mov    r14,QWORD PTR [rbx+0x80]
   152e6:	41 bc ed ff ff ff    	mov    r12d,0xffffffed
   152ec:	49 8b 46 50          	mov    rax,QWORD PTR [r14+0x50]
   152f0:	8b 38                	mov    edi,DWORD PTR [rax]
   152f2:	e8 09 80 ff ff       	call   d300 <getservbyname@plt+0x64f0>
   152f7:	85 c0                	test   eax,eax
   152f9:	0f 84 fd fc ff ff    	je     14ffc <getservbyname@plt+0xe1ec>
   152ff:	49 8b 3e             	mov    rdi,QWORD PTR [r14]
   15302:	e8 19 72 ff ff       	call   c520 <getservbyname@plt+0x5710>
   15307:	4d 89 e8             	mov    r8,r13
   1530a:	45 31 c9             	xor    r9d,r9d
   1530d:	48 89 c1             	mov    rcx,rax
   15310:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15317:	49 29 e8             	sub    r8,rbp
   1531a:	48 8b 78 50          	mov    rdi,QWORD PTR [rax+0x50]
   1531e:	6a 00                	push   0x0
   15320:	6a 00                	push   0x0
   15322:	48 8b 54 24 40       	mov    rdx,QWORD PTR [rsp+0x40]
   15327:	48 8b 74 24 38       	mov    rsi,QWORD PTR [rsp+0x38]
   1532c:	e8 1f de ff ff       	call   13150 <getservbyname@plt+0xc340>
   15331:	41 89 c4             	mov    r12d,eax
   15334:	58                   	pop    rax
   15335:	5a                   	pop    rdx
   15336:	45 85 e4             	test   r12d,r12d
   15339:	0f 85 bd fc ff ff    	jne    14ffc <getservbyname@plt+0xe1ec>
   1533f:	48 8b 93 80 00 00 00 	mov    rdx,QWORD PTR [rbx+0x80]
   15346:	48 8b 74 24 30       	mov    rsi,QWORD PTR [rsp+0x30]
   1534b:	48 8b 7c 24 28       	mov    rdi,QWORD PTR [rsp+0x28]
   15350:	48 83 c2 58          	add    rdx,0x58
   15354:	e8 c7 d8 ff ff       	call   12c20 <getservbyname@plt+0xbe10>
   15359:	41 89 c4             	mov    r12d,eax
   1535c:	e9 9b fc ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>
   15361:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15368:	41 bc fc ff ff ff    	mov    r12d,0xfffffffc
   1536e:	48 8b 78 40          	mov    rdi,QWORD PTR [rax+0x40]
   15372:	e8 e9 6a ff ff       	call   be60 <getservbyname@plt+0x5050>
   15377:	e9 80 fc ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>
   1537c:	48 8b 83 80 00 00 00 	mov    rax,QWORD PTR [rbx+0x80]
   15383:	48 8b 78 48          	mov    rdi,QWORD PTR [rax+0x48]
   15387:	e8 d4 6a ff ff       	call   be60 <getservbyname@plt+0x5050>
   1538c:	e9 65 fc ff ff       	jmp    14ff6 <getservbyname@plt+0xe1e6>
   15391:	41 bc ed ff ff ff    	mov    r12d,0xffffffed
   15397:	e9 60 fc ff ff       	jmp    14ffc <getservbyname@plt+0xe1ec>
   1539c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   153a0:	f3 0f 1e fa          	endbr64 
   153a4:	ba 01 00 00 00       	mov    edx,0x1
   153a9:	e9 d2 f3 ff ff       	jmp    14780 <getservbyname@plt+0xd970>
   153ae:	66 90                	xchg   ax,ax
   153b0:	f3 0f 1e fa          	endbr64 
   153b4:	41 57                	push   r15
   153b6:	41 56                	push   r14
   153b8:	41 55                	push   r13
   153ba:	41 54                	push   r12
   153bc:	55                   	push   rbp
   153bd:	53                   	push   rbx
   153be:	48 83 ec 38          	sub    rsp,0x38
   153c2:	48 89 34 24          	mov    QWORD PTR [rsp],rsi
   153c6:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   153cd:	00 00 
   153cf:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   153d4:	31 c0                	xor    eax,eax
   153d6:	c7 44 24 1c ff ff ff 	mov    DWORD PTR [rsp+0x1c],0xffffffff
   153dd:	ff 
   153de:	48 85 ff             	test   rdi,rdi
   153e1:	0f 84 b1 01 00 00    	je     15598 <getservbyname@plt+0xe788>
   153e7:	8b 0f                	mov    ecx,DWORD PTR [rdi]
   153e9:	48 89 fb             	mov    rbx,rdi
   153ec:	83 f9 07             	cmp    ecx,0x7
   153ef:	0f 8e 9b 01 00 00    	jle    15590 <getservbyname@plt+0xe780>
   153f5:	8d 41 f6             	lea    eax,[rcx-0xa]
   153f8:	83 f8 04             	cmp    eax,0x4
   153fb:	0f 87 97 01 00 00    	ja     15598 <getservbyname@plt+0xe788>
   15401:	48 8b 04 24          	mov    rax,QWORD PTR [rsp]
   15405:	4c 8d 25 48 9d 02 00 	lea    r12,[rip+0x29d48]        # 3f154 <closefrom@@Base+0x7994>
   1540c:	89 4c 24 08          	mov    DWORD PTR [rsp+0x8],ecx
   15410:	4c 89 e6             	mov    rsi,r12
   15413:	4c 8b 38             	mov    r15,QWORD PTR [rax]
   15416:	4c 89 ff             	mov    rdi,r15
   15419:	e8 72 17 ff ff       	call   6b90 <strcspn@plt>
   1541e:	4c 89 ff             	mov    rdi,r15
   15421:	49 89 c6             	mov    r14,rax
   15424:	e8 b7 10 ff ff       	call   64e0 <strlen@plt>
   15429:	8b 4c 24 08          	mov    ecx,DWORD PTR [rsp+0x8]
   1542d:	4c 39 f0             	cmp    rax,r14

codex
The function extends to `0x1539c`; I’ve identified a shared cleanup path and several nested iterator loops. I’m now resolving the nearby internal-call semantics and the context layout from their raw assembly and dynamic symbols so the final C uses coherent types rather than opaque register-shaped variables.
exec
/bin/bash -lc 'readelf -d ./target.bin; readelf -Ws ./target.bin; readelf -rW ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:

Dynamic section at offset 0x66620 contains 28 entries:
  Tag        Type                         Name/Value
 0x0000000000000001 (NEEDED)             Shared library: [libcrypto.so.3]
 0x0000000000000001 (NEEDED)             Shared library: [libc.so.6]
 0x000000000000000c (INIT)               0x5000
 0x000000000000000d (FINI)               0x3daf4
 0x0000000000000019 (INIT_ARRAY)         0x66cb0
 0x000000000000001b (INIT_ARRAYSZ)       8 (bytes)
 0x000000000000001a (FINI_ARRAY)         0x66cb8
 0x000000000000001c (FINI_ARRAYSZ)       8 (bytes)
 0x000000006ffffef5 (GNU_HASH)           0x3b0
 0x0000000000000005 (STRTAB)             0x1c98
 0x0000000000000006 (SYMTAB)             0x3f0
 0x000000000000000a (STRSZ)              3411 (bytes)
 0x000000000000000b (SYMENT)             24 (bytes)
 0x0000000000000015 (DEBUG)              0x0
 0x0000000000000003 (PLTGOT)             0x67820
 0x0000000000000002 (PLTRELSZ)           5712 (bytes)
 0x0000000000000014 (PLTREL)             RELA
 0x0000000000000017 (JMPREL)             0x3988
 0x0000000000000007 (RELA)               0x2ce0
 0x0000000000000008 (RELASZ)             3240 (bytes)
 0x0000000000000009 (RELAENT)            24 (bytes)
 0x000000000000001e (FLAGS)              BIND_NOW
 0x000000006ffffffb (FLAGS_1)            Flags: NOW PIE
 0x000000006ffffffe (VERNEED)            0x2c00
 0x000000006fffffff (VERNEEDNUM)         2
 0x000000006ffffff0 (VERSYM)             0x29ec
 0x000000006ffffff9 (RELACOUNT)          111
 0x0000000000000000 (NULL)               0x0

Symbol table '.dynsym' contains 263 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND 
     1: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_do_verify@OPENSSL_3.0.0 (2)
     2: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND initgroups@GLIBC_2.2.5 (3)
     3: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_iv_noconst@OPENSSL_3.0.0 (2)
     4: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_get0_group@OPENSSL_3.0.0 (2)
     5: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dirname@GLIBC_2.2.5 (3)
     6: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dup2@GLIBC_2.2.5 (3)
     7: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_set_key_length@OPENSSL_3.0.0 (2)
     8: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BIO_write@OPENSSL_3.0.0 (2)
     9: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_div@OPENSSL_3.0.0 (2)
    10: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND execv@GLIBC_2.2.5 (3)
    11: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_get1_EC_KEY@OPENSSL_3.0.0 (2)
    12: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dlerror@GLIBC_2.34 (4)
    13: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_generate_parameters_ex@OPENSSL_3.0.0 (2)
    14: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_do_sign@OPENSSL_3.0.0 (2)
    15: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND mktime@GLIBC_2.2.5 (3)
    16: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memset@GLIBC_2.2.5 (3)
    17: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_set_asn1_flag@OPENSSL_3.0.0 (2)
    18: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND snprintf@GLIBC_2.2.5 (3)
    19: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_get1_DSA@OPENSSL_3.0.0 (2)
    20: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND close@GLIBC_2.2.5 (3)
    21: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_free@OPENSSL_3.0.0 (2)
    22: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_set_private_key@OPENSSL_3.0.0 (2)
    23: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ioctl@GLIBC_2.2.5 (3)
    24: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND abort@GLIBC_2.2.5 (3)
    25: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_des_ede3_cbc@OPENSSL_3.0.0 (2)
    26: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memchr@GLIBC_2.2.5 (3)
    27: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND clock_gettime@GLIBC_2.17 (5)
    28: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __fprintf_chk@GLIBC_2.3.4 (6)
    29: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND __gmon_start__
    30: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_set_asn1_flag@OPENSSL_3.0.0 (2)
    31: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_192_cbc@OPENSSL_3.0.0 (2)
    32: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_free@OPENSSL_3.0.0 (2)
    33: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_bin2bn@OPENSSL_3.0.0 (2)
    34: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_SIG_set0@OPENSSL_3.0.0 (2)
    35: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND openlog@GLIBC_2.2.5 (3)
    36: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND exit@GLIBC_2.2.5 (3)
    37: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fstat@GLIBC_2.33 (7)
    38: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BIO_new@OPENSSL_3.0.0 (2)
    39: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getaddrinfo@GLIBC_2.2.5 (3)
    40: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcasecmp@GLIBC_2.2.5 (3)
    41: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_blinding_on@OPENSSL_3.0.0 (2)
    42: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gettimeofday@GLIBC_2.2.5 (3)
    43: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_public_decrypt@OPENSSL_3.0.0 (2)
    44: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_sha512@OPENSSL_3.0.0 (2)
    45: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_get_affine_coordinates_GFp@OPENSSL_3.0.0 (2)
    46: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_SIG_free@OPENSSL_3.0.0 (2)
    47: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_chacha20@OPENSSL_3.0.0 (2)
    48: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strpbrk@GLIBC_2.2.5 (3)
    49: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strsignal@GLIBC_2.2.5 (3)
    50: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_bn2bin@OPENSSL_3.0.0 (2)
    51: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND reallocarray@GLIBC_2.26 (8)
    52: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncmp@GLIBC_2.2.5 (3)
    53: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND malloc@GLIBC_2.2.5 (3)
    54: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_SIG_free@OPENSSL_3.0.0 (2)
    55: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sigfillset@GLIBC_2.2.5 (3)
    56: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dup@GLIBC_2.2.5 (3)
    57: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_SIG_new@OPENSSL_3.0.0 (2)
    58: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND unlink@GLIBC_2.2.5 (3)
    59: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setresuid@GLIBC_2.2.5 (3)
    60: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_set_group@OPENSSL_3.0.0 (2)
    61: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_new@OPENSSL_3.0.0 (2)
    62: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND _exit@GLIBC_2.2.5 (3)
    63: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_set1_RSA@OPENSSL_3.0.0 (2)
    64: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_set_flags@OPENSSL_3.0.0 (2)
    65: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_128_cbc@OPENSSL_3.0.0 (2)
    66: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_print_fp@OPENSSL_3.0.0 (2)
    67: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __memcpy_chk@GLIBC_2.3.4 (6)
    68: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_get0_pqg@OPENSSL_3.0.0 (2)
    69: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_mul@OPENSSL_3.0.0 (2)
    70: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setsockopt@GLIBC_2.2.5 (3)
    71: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_new@OPENSSL_3.0.0 (2)
    72: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getsid@GLIBC_2.2.5 (3)
    73: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_value_one@OPENSSL_3.0.0 (2)
    74: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sysconf@GLIBC_2.2.5 (3)
    75: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND PEM_write_bio_ECPrivateKey@OPENSSL_3.0.0 (2)
    76: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_free@OPENSSL_3.0.0 (2)
    77: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_192_ctr@OPENSSL_3.0.0 (2)
    78: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpid@GLIBC_2.2.5 (3)
    79: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_sha256@OPENSSL_3.0.0 (2)
    80: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __vsnprintf_chk@GLIBC_2.3.4 (6)
    81: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_set0_key@OPENSSL_3.0.0 (2)
    82: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpwuid@GLIBC_2.2.5 (3)
    83: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_deregisterTMCloneTable
    84: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_new@OPENSSL_3.0.0 (2)
    85: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND geteuid@GLIBC_2.2.5 (3)
    86: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_dup@OPENSSL_3.0.0 (2)
    87: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_CTX_new@OPENSSL_3.0.0 (2)
    88: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_MD_CTX_new@OPENSSL_3.0.0 (2)
    89: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND closelog@GLIBC_2.2.5 (3)
    90: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_free@OPENSSL_3.0.0 (2)
    91: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_SIG_new@OPENSSL_3.0.0 (2)
    92: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_set0_pqg@OPENSSL_3.0.0 (2)
    93: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND freeaddrinfo@GLIBC_2.2.5 (3)
    94: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND free@GLIBC_2.2.5 (3)
    95: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_sign@OPENSSL_3.0.0 (2)
    96: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND PEM_write_bio_PrivateKey@OPENSSL_3.0.0 (2)
    97: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strlen@GLIBC_2.2.5 (3)
    98: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_free@OPENSSL_3.0.0 (2)
    99: 0000000000000000     0 NOTYPE  WEAK   DEFAULT  UND _ITM_registerTMCloneTable
   100: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_cmp@OPENSSL_3.0.0 (2)
   101: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_oct2point@OPENSSL_3.0.0 (2)
   102: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __asprintf_chk@GLIBC_2.8 (9)
   103: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND close_range@GLIBC_2.34 (4)
   104: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND opendir@GLIBC_2.2.5 (3)
   105: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_Cipher@OPENSSL_3.0.0 (2)
   106: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_MD_CTX_get0_md@OPENSSL_3.0.0 (2)
   107: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_generate_key@OPENSSL_3.0.0 (2)
   108: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getentropy@GLIBC_2.25 (10)
   109: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_get_iv_length@OPENSSL_3.0.0 (2)
   110: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_do_verify@OPENSSL_3.0.0 (2)
   111: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_set0_crt_params@OPENSSL_3.0.0 (2)
   112: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND listen@GLIBC_2.2.5 (3)
   113: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __ctype_b_loc@GLIBC_2.3 (11)
   114: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_sha1@OPENSSL_3.0.0 (2)
   115: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_get_curve_name@OPENSSL_3.0.0 (2)
   116: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND readdir@GLIBC_2.2.5 (3)
   117: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_get_key_length@OPENSSL_3.0.0 (2)
   118: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_iv@OPENSSL_3.0.0 (2)
   119: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fdopen@GLIBC_2.2.5 (3)
   120: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strrchr@GLIBC_2.2.5 (3)
   121: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpagesize@GLIBC_2.2.5 (3)
   122: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_set0_factors@OPENSSL_3.0.0 (2)
   123: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND pipe@GLIBC_2.2.5 (3)
   124: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_cmp@OPENSSL_3.0.0 (2)
   125: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_256_ctr@OPENSSL_3.0.0 (2)
   126: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_generate_key@OPENSSL_3.0.0 (2)
   127: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND timegm@GLIBC_2.2.5 (3)
   128: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_SIG_get0@OPENSSL_3.0.0 (2)
   129: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_METHOD_get_field_type@OPENSSL_3.0.0 (2)
   130: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND poll@GLIBC_2.2.5 (3)
   131: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_num_bits@OPENSSL_3.0.0 (2)
   132: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_set_word@OPENSSL_3.0.0 (2)
   133: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_clear_free@OPENSSL_3.0.0 (2)
   134: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND PEM_write_bio_DSAPrivateKey@OPENSSL_3.0.0 (2)
   135: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_cmp@OPENSSL_3.0.0 (2)
   136: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND kill@GLIBC_2.2.5 (3)
   137: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strerror@GLIBC_2.2.5 (3)
   138: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_get_order@OPENSSL_3.0.0 (2)
   139: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BIO_s_mem@OPENSSL_3.0.0 (2)
   140: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND PEM_write_bio_RSAPrivateKey@OPENSSL_3.0.0 (2)
   141: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND sigaction@GLIBC_2.2.5 (3)
   142: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __explicit_bzero_chk@GLIBC_2.25 (10)
   143: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getsockopt@GLIBC_2.2.5 (3)
   144: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_DigestUpdate@OPENSSL_3.0.0 (2)
   145: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dlopen@GLIBC_2.34 (4)
   146: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fputs@GLIBC_2.2.5 (3)
   147: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtol@GLIBC_2.2.5 (3)
   148: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getsockname@GLIBC_2.2.5 (3)
   149: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dirfd@GLIBC_2.2.5 (3)
   150: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_md5@OPENSSL_3.0.0 (2)
   151: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND connect@GLIBC_2.2.5 (3)
   152: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_256_gcm@OPENSSL_3.0.0 (2)
   153: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ERR_peek_last_error@OPENSSL_3.0.0 (2)
   154: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_sub@OPENSSL_3.0.0 (2)
   155: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND execve@GLIBC_2.2.5 (3)
   156: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_method_of@OPENSSL_3.0.0 (2)
   157: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND setresgid@GLIBC_2.2.5 (3)
   158: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND raise@GLIBC_2.2.5 (3)
   159: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_generate_key_ex@OPENSSL_3.0.0 (2)
   160: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_MD_CTX_copy_ex@OPENSSL_3.0.0 (2)
   161: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strspn@GLIBC_2.2.5 (3)
   162: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strptime@GLIBC_2.2.5 (3)
   163: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __syslog_chk@GLIBC_2.4 (12)
   164: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ECDSA_do_sign@OPENSSL_3.0.0 (2)
   165: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memmove@GLIBC_2.2.5 (3)
   166: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strchr@GLIBC_2.2.5 (3)
   167: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND waitpid@GLIBC_2.2.5 (3)
   168: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND socket@GLIBC_2.2.5 (3)
   169: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getenv@GLIBC_2.2.5 (3)
   170: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_MD_CTX_free@OPENSSL_3.0.0 (2)
   171: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_get_updated_iv@OPENSSL_3.0.0 (2)
   172: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_get0_private_key@OPENSSL_3.0.0 (2)
   173: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __errno_location@GLIBC_2.2.5 (3)
   174: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strdup@GLIBC_2.2.5 (3)
   175: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_SIG_set0@OPENSSL_3.0.0 (2)
   176: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_ctrl@OPENSSL_3.0.0 (2)
   177: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ERR_peek_error@OPENSSL_3.0.0 (2)
   178: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_free@OPENSSL_3.0.0 (2)
   179: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strncasecmp@GLIBC_2.2.5 (3)
   180: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BN_CTX_free@OPENSSL_3.0.0 (2)
   181: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND PEM_read_bio_PrivateKey@OPENSSL_3.0.0 (2)
   182: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __stack_chk_fail@GLIBC_2.4 (12)
   183: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_free@OPENSSL_3.0.0 (2)
   184: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getnameinfo@GLIBC_2.2.5 (3)
   185: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_new@OPENSSL_3.0.0 (2)
   186: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_MD_get_block_size@OPENSSL_3.0.0 (2)
   187: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcmp@GLIBC_2.2.5 (3)
   188: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_SIG_get0@OPENSSL_3.0.0 (2)
   189: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND nanosleep@GLIBC_2.2.5 (3)
   190: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_set1_EC_KEY@OPENSSL_3.0.0 (2)
   191: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getuid@GLIBC_2.2.5 (3)
   192: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_256_cbc@OPENSSL_3.0.0 (2)
   193: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memmem@GLIBC_2.2.5 (3)
   194: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_DigestInit_ex@OPENSSL_3.0.0 (2)
   195: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __ctype_tolower_loc@GLIBC_2.3 (11)
   196: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcmp@GLIBC_2.2.5 (3)
   197: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND calloc@GLIBC_2.2.5 (3)
   198: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND munmap@GLIBC_2.2.5 (3)
   199: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND feof@GLIBC_2.2.5 (3)
   200: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_point2oct@OPENSSL_3.0.0 (2)
   201: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CIPHER_CTX_new@OPENSSL_3.0.0 (2)
   202: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_set_public_key@OPENSSL_3.0.0 (2)
   203: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_get0_crt_params@OPENSSL_3.0.0 (2)
   204: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BIO_free@OPENSSL_3.0.0 (2)
   205: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_set0_key@OPENSSL_3.0.0 (2)
   206: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_new@OPENSSL_3.0.0 (2)
   207: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND localtime_r@GLIBC_2.2.5 (3)
   208: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND BIO_ctrl@OPENSSL_3.0.0 (2)
   209: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND closedir@GLIBC_2.2.5 (3)
   210: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strcspn@GLIBC_2.2.5 (3)
   211: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __realpath_chk@GLIBC_2.4 (12)
   212: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __snprintf_chk@GLIBC_2.3.4 (6)
   213: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strsep@GLIBC_2.2.5 (3)
   214: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fork@GLIBC_2.2.5 (3)
   215: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_get0_public_key@OPENSSL_3.0.0 (2)
   216: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_get0_factors@OPENSSL_3.0.0 (2)
   217: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getppid@GLIBC_2.2.5 (3)
   218: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtoll@GLIBC_2.2.5 (3)
   219: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dlsym@GLIBC_2.34 (4)
   220: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND DSA_get0_key@OPENSSL_3.0.0 (2)
   221: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND bind@GLIBC_2.2.5 (3)
   222: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fwrite@GLIBC_2.2.5 (3)
   223: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_free@OPENSSL_3.0.0 (2)
   224: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND realloc@GLIBC_2.2.5 (3)
   225: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_sha384@OPENSSL_3.0.0 (2)
   226: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND gai_strerror@GLIBC_2.2.5 (3)
   227: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_size@OPENSSL_3.0.0 (2)
   228: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_get1_RSA@OPENSSL_3.0.0 (2)
   229: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __libc_start_main@GLIBC_2.34 (4)
   230: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_Digest@OPENSSL_3.0.0 (2)
   231: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strftime@GLIBC_2.2.5 (3)
   232: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_128_gcm@OPENSSL_3.0.0 (2)
   233: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND stat@GLIBC_2.33 (7)
   234: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strtoul@GLIBC_2.2.5 (3)
   235: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND readv@GLIBC_2.2.5 (3)
   236: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_CipherInit@OPENSSL_3.0.0 (2)
   237: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND memcpy@GLIBC_2.14 (13)
   238: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND fcntl@GLIBC_2.2.5 (3)
   239: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND RSA_get0_key@OPENSSL_3.0.0 (2)
   240: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_aes_128_ctr@OPENSSL_3.0.0 (2)
   241: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_GROUP_new_by_curve_name@OPENSSL_3.0.0 (2)
   242: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND open@GLIBC_2.2.5 (3)
   243: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND __vasprintf_chk@GLIBC_2.8 (9)
   244: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND mmap@GLIBC_2.2.5 (3)
   245: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getpwnam@GLIBC_2.2.5 (3)
   246: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_DigestFinal_ex@OPENSSL_3.0.0 (2)
   247: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND ERR_get_error@OPENSSL_3.0.0 (2)
   248: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_get_base_id@OPENSSL_3.0.0 (2)
   249: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND strndup@GLIBC_2.2.5 (3)
   250: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_KEY_new_by_curve_name@OPENSSL_3.0.0 (2)
   251: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND time@GLIBC_2.2.5 (3)
   252: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EVP_PKEY_set1_DSA@OPENSSL_3.0.0 (2)
   253: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND EC_POINT_is_at_infinity@OPENSSL_3.0.0 (2)
   254: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND dlclose@GLIBC_2.34 (4)
   255: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND getservbyname@GLIBC_2.2.5 (3)
   256: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND read@GLIBC_2.2.5 (3)
   257: 0000000000000000     0 FUNC    WEAK   DEFAULT  UND __cxa_finalize@GLIBC_2.2.5 (3)
   258: 0000000000068040     8 OBJECT  WEAK   DEFAULT   27 program_invocation_short_name@GLIBC_2.2.5 (3)
   259: 0000000000068040     8 OBJECT  GLOBAL DEFAULT   27 __progname@GLIBC_2.2.5 (3)
   260: 0000000000068060     8 OBJECT  GLOBAL DEFAULT   27 stderr@GLIBC_2.2.5 (3)
   261: 00000000000377c0   442 FUNC    GLOBAL DEFAULT   16 closefrom
   262: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND write@GLIBC_2.2.5 (3)

Relocation section '.rela.dyn' at offset 0x2ce0 contains 135 entries:
    Offset             Info             Type               Symbol's Value  Symbol's Name + Addend
0000000000066cb0  0000000000000008 R_X86_64_RELATIVE                         73b0
0000000000066cb8  0000000000000008 R_X86_64_RELATIVE                         7370
0000000000066cc0  0000000000000008 R_X86_64_RELATIVE                         3f07e
0000000000066cc8  0000000000000008 R_X86_64_RELATIVE                         3f1a2
0000000000066ce8  0000000000000008 R_X86_64_RELATIVE                         3f4c8
0000000000066cf0  0000000000000008 R_X86_64_RELATIVE                         3f1aa
0000000000066d10  0000000000000008 R_X86_64_RELATIVE                         3f1b7
0000000000066d18  0000000000000008 R_X86_64_RELATIVE                         3f1d2
0000000000066d38  0000000000000008 R_X86_64_RELATIVE                         3f4f0
0000000000066d40  0000000000000008 R_X86_64_RELATIVE                         3f1dd
0000000000066d60  0000000000000008 R_X86_64_RELATIVE                         3f08a
0000000000066d68  0000000000000008 R_X86_64_RELATIVE                         3f1ed
0000000000066d88  0000000000000008 R_X86_64_RELATIVE                         3f092
0000000000066d90  0000000000000008 R_X86_64_RELATIVE                         3f1ed
0000000000066db0  0000000000000008 R_X86_64_RELATIVE                         3f09f
0000000000066db8  0000000000000008 R_X86_64_RELATIVE                         3f1ed
0000000000066dd8  0000000000000008 R_X86_64_RELATIVE                         3f1f1
0000000000066de0  0000000000000008 R_X86_64_RELATIVE                         3f20f
0000000000066e00  0000000000000008 R_X86_64_RELATIVE                         3f1f9
0000000000066e08  0000000000000008 R_X86_64_RELATIVE                         3f20d
0000000000066e28  0000000000000008 R_X86_64_RELATIVE                         3f213
0000000000066e30  0000000000000008 R_X86_64_RELATIVE                         3f20d
0000000000066e50  0000000000000008 R_X86_64_RELATIVE                         3f227
0000000000066e58  0000000000000008 R_X86_64_RELATIVE                         3f20d
0000000000066e78  0000000000000008 R_X86_64_RELATIVE                         3f518
0000000000066e80  0000000000000008 R_X86_64_RELATIVE                         3f23b
0000000000066ea0  0000000000000008 R_X86_64_RELATIVE                         3f540
0000000000066ea8  0000000000000008 R_X86_64_RELATIVE                         3f23b
0000000000066ec8  0000000000000008 R_X86_64_RELATIVE                         3f0ac
0000000000066ed0  0000000000000008 R_X86_64_RELATIVE                         3f244
0000000000066ef0  0000000000000008 R_X86_64_RELATIVE                         3f2d8
0000000000066ef8  0000000000000008 R_X86_64_RELATIVE                         3f244
0000000000066f00  0000000000000008 R_X86_64_RELATIVE                         3f092
0000000000066f18  0000000000000008 R_X86_64_RELATIVE                         3f300
0000000000066f20  0000000000000008 R_X86_64_RELATIVE                         3f244
0000000000066f28  0000000000000008 R_X86_64_RELATIVE                         3f09f
0000000000066f40  0000000000000008 R_X86_64_RELATIVE                         3f24d
0000000000066f48  0000000000000008 R_X86_64_RELATIVE                         3f26c
0000000000066f68  0000000000000008 R_X86_64_RELATIVE                         3f570
0000000000066f70  0000000000000008 R_X86_64_RELATIVE                         3f26a
0000000000066f90  0000000000000008 R_X86_64_RELATIVE                         3f5a0
0000000000066f98  0000000000000008 R_X86_64_RELATIVE                         3f26a
0000000000066fb8  0000000000000008 R_X86_64_RELATIVE                         3f5d0
0000000000066fc0  0000000000000008 R_X86_64_RELATIVE                         3f26a
0000000000066fe0  0000000000000008 R_X86_64_RELATIVE                         3f600
0000000000066fe8  0000000000000008 R_X86_64_RELATIVE                         3f275
0000000000067040  0000000000000008 R_X86_64_RELATIVE                         3fa66
0000000000067050  0000000000000008 R_X86_64_RELATIVE                         3faa5
0000000000067060  0000000000000008 R_X86_64_RELATIVE                         3faab
0000000000067070  0000000000000008 R_X86_64_RELATIVE                         3fab1
0000000000067080  0000000000000008 R_X86_64_RELATIVE                         3fab6
0000000000067090  0000000000000008 R_X86_64_RELATIVE                         3fabe
00000000000670a0  0000000000000008 R_X86_64_RELATIVE                         3fac4
00000000000670b0  0000000000000008 R_X86_64_RELATIVE                         3facb
00000000000670c0  0000000000000008 R_X86_64_RELATIVE                         3fad2
00000000000670e0  0000000000000008 R_X86_64_RELATIVE                         3fa5f
00000000000670f0  0000000000000008 R_X86_64_RELATIVE                         3fad9
0000000000067100  0000000000000008 R_X86_64_RELATIVE                         3fade
0000000000067110  0000000000000008 R_X86_64_RELATIVE                         3fae3
0000000000067120  0000000000000008 R_X86_64_RELATIVE                         3faec
0000000000067130  0000000000000008 R_X86_64_RELATIVE                         3faf3
0000000000067140  0000000000000008 R_X86_64_RELATIVE                         3fafa
0000000000067150  0000000000000008 R_X86_64_RELATIVE                         3fb01
0000000000067160  0000000000000008 R_X86_64_RELATIVE                         3fb08
0000000000067170  0000000000000008 R_X86_64_RELATIVE                         3fb0f
0000000000067180  0000000000000008 R_X86_64_RELATIVE                         3fb16
0000000000067190  0000000000000008 R_X86_64_RELATIVE                         3fb1d
00000000000671c0  0000000000000008 R_X86_64_RELATIVE                         3f986
00000000000671d0  0000000000000008 R_X86_64_RELATIVE                         405d8
00000000000671e0  0000000000000008 R_X86_64_RELATIVE                         405dd
00000000000671f0  0000000000000008 R_X86_64_RELATIVE                         405e2
0000000000067200  0000000000000008 R_X86_64_RELATIVE                         405e7
0000000000067210  0000000000000008 R_X86_64_RELATIVE                         405ec
0000000000067220  0000000000000008 R_X86_64_RELATIVE                         405f1
0000000000067230  0000000000000008 R_X86_64_RELATIVE                         405f6
0000000000067240  0000000000000008 R_X86_64_RELATIVE                         405fb
0000000000067250  0000000000000008 R_X86_64_RELATIVE                         40600
0000000000067260  0000000000000008 R_X86_64_RELATIVE                         40605
0000000000067270  0000000000000008 R_X86_64_RELATIVE                         4060a
0000000000067280  0000000000000008 R_X86_64_RELATIVE                         4060f
0000000000067290  0000000000000008 R_X86_64_RELATIVE                         40614
00000000000672a0  0000000000000008 R_X86_64_RELATIVE                         40618
00000000000672b0  0000000000000008 R_X86_64_RELATIVE                         4061c
00000000000672c0  0000000000000008 R_X86_64_RELATIVE                         40620
00000000000672d0  0000000000000008 R_X86_64_RELATIVE                         40624
00000000000672e0  0000000000000008 R_X86_64_RELATIVE                         40628
00000000000672f0  0000000000000008 R_X86_64_RELATIVE                         4062c
0000000000067300  0000000000000008 R_X86_64_RELATIVE                         40630
0000000000067310  0000000000000008 R_X86_64_RELATIVE                         40634
0000000000067320  0000000000000008 R_X86_64_RELATIVE                         402f2
0000000000067330  0000000000000008 R_X86_64_RELATIVE                         40637
0000000000067340  0000000000000008 R_X86_64_RELATIVE                         40640
0000000000067350  0000000000000008 R_X86_64_RELATIVE                         4064b
0000000000067380  0000000000000008 R_X86_64_RELATIVE                         3f9a6
00000000000673a8  0000000000000008 R_X86_64_RELATIVE                         3f9af
00000000000673d0  0000000000000008 R_X86_64_RELATIVE                         3f9ba
00000000000673f8  0000000000000008 R_X86_64_RELATIVE                         3f9c5
0000000000067420  0000000000000008 R_X86_64_RELATIVE                         3f9d0
0000000000067448  0000000000000008 R_X86_64_RELATIVE                         3f9db
0000000000067470  0000000000000008 R_X86_64_RELATIVE                         3f15e
0000000000067498  0000000000000008 R_X86_64_RELATIVE                         3f9e6
00000000000674c0  0000000000000008 R_X86_64_RELATIVE                         3f9fd
00000000000674e8  0000000000000008 R_X86_64_RELATIVE                         3fa14
0000000000067510  0000000000000008 R_X86_64_RELATIVE                         3f986
0000000000067568  0000000000000008 R_X86_64_RELATIVE                         40e63
0000000000067588  0000000000000008 R_X86_64_RELATIVE                         40e67
00000000000675a8  0000000000000008 R_X86_64_RELATIVE                         40e6c
00000000000675c8  0000000000000008 R_X86_64_RELATIVE                         40e73
00000000000675e8  0000000000000008 R_X86_64_RELATIVE                         40e7a
0000000000068008  0000000000000008 R_X86_64_RELATIVE                         68008
0000000000068038  0000000000000008 R_X86_64_RELATIVE                         3f156
00000000000673a0  0000001900000001 R_X86_64_64            0000000000000000 EVP_des_ede3_cbc@OPENSSL_3.0.0 + 0
00000000000673c8  0000004100000001 R_X86_64_64            0000000000000000 EVP_aes_128_cbc@OPENSSL_3.0.0 + 0
00000000000673f0  0000001f00000001 R_X86_64_64            0000000000000000 EVP_aes_192_cbc@OPENSSL_3.0.0 + 0
0000000000067418  000000c000000001 R_X86_64_64            0000000000000000 EVP_aes_256_cbc@OPENSSL_3.0.0 + 0
0000000000067440  000000f000000001 R_X86_64_64            0000000000000000 EVP_aes_128_ctr@OPENSSL_3.0.0 + 0
0000000000067468  0000004d00000001 R_X86_64_64            0000000000000000 EVP_aes_192_ctr@OPENSSL_3.0.0 + 0
0000000000067490  0000007d00000001 R_X86_64_64            0000000000000000 EVP_aes_256_ctr@OPENSSL_3.0.0 + 0
00000000000674b8  000000e800000001 R_X86_64_64            0000000000000000 EVP_aes_128_gcm@OPENSSL_3.0.0 + 0
00000000000674e0  0000009800000001 R_X86_64_64            0000000000000000 EVP_aes_256_gcm@OPENSSL_3.0.0 + 0
0000000000067578  0000009600000001 R_X86_64_64            0000000000000000 EVP_md5@OPENSSL_3.0.0 + 0
0000000000067598  0000007200000001 R_X86_64_64            0000000000000000 EVP_sha1@OPENSSL_3.0.0 + 0
00000000000675b8  0000004f00000001 R_X86_64_64            0000000000000000 EVP_sha256@OPENSSL_3.0.0 + 0
00000000000675d8  000000e100000001 R_X86_64_64            0000000000000000 EVP_sha384@OPENSSL_3.0.0 + 0
00000000000675f8  0000002c00000001 R_X86_64_64            0000000000000000 EVP_sha512@OPENSSL_3.0.0 + 0
0000000000067fa8  0000001d00000006 R_X86_64_GLOB_DAT      0000000000000000 __gmon_start__ + 0
0000000000067fb0  0000010000000006 R_X86_64_GLOB_DAT      0000000000000000 read@GLIBC_2.2.5 + 0
0000000000067fb8  0000005300000006 R_X86_64_GLOB_DAT      0000000000000000 _ITM_deregisterTMCloneTable + 0
0000000000067fc0  0000006300000006 R_X86_64_GLOB_DAT      0000000000000000 _ITM_registerTMCloneTable + 0
0000000000067fc8  0000010100000006 R_X86_64_GLOB_DAT      0000000000000000 __cxa_finalize@GLIBC_2.2.5 + 0
0000000000067fd0  000000e500000006 R_X86_64_GLOB_DAT      0000000000000000 __libc_start_main@GLIBC_2.34 + 0
0000000000067fd8  0000010600000006 R_X86_64_GLOB_DAT      0000000000000000 write@GLIBC_2.2.5 + 0
0000000000067fe0  000000eb00000006 R_X86_64_GLOB_DAT      0000000000000000 readv@GLIBC_2.2.5 + 0
0000000000068040  0000010300000005 R_X86_64_COPY          0000000000068040 __progname@GLIBC_2.2.5 + 0
0000000000068060  0000010400000005 R_X86_64_COPY          0000000000068060 stderr@GLIBC_2.2.5 + 0

Relocation section '.rela.plt' at offset 0x3988 contains 238 entries:
    Offset             Info             Type               Symbol's Value  Symbol's Name + Addend
0000000000067838  0000000100000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_do_verify@OPENSSL_3.0.0 + 0
0000000000067840  0000000200000007 R_X86_64_JUMP_SLOT     0000000000000000 initgroups@GLIBC_2.2.5 + 0
0000000000067848  0000000300000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_iv_noconst@OPENSSL_3.0.0 + 0
0000000000067850  0000000400000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_get0_group@OPENSSL_3.0.0 + 0
0000000000067858  0000000500000007 R_X86_64_JUMP_SLOT     0000000000000000 dirname@GLIBC_2.2.5 + 0
0000000000067860  0000000600000007 R_X86_64_JUMP_SLOT     0000000000000000 dup2@GLIBC_2.2.5 + 0
0000000000067868  0000000700000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_set_key_length@OPENSSL_3.0.0 + 0
0000000000067870  0000000800000007 R_X86_64_JUMP_SLOT     0000000000000000 BIO_write@OPENSSL_3.0.0 + 0
0000000000067878  0000000900000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_div@OPENSSL_3.0.0 + 0
0000000000067880  0000000a00000007 R_X86_64_JUMP_SLOT     0000000000000000 execv@GLIBC_2.2.5 + 0
0000000000067888  0000000b00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_get1_EC_KEY@OPENSSL_3.0.0 + 0
0000000000067890  0000000c00000007 R_X86_64_JUMP_SLOT     0000000000000000 dlerror@GLIBC_2.34 + 0
0000000000067898  0000000d00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_generate_parameters_ex@OPENSSL_3.0.0 + 0
00000000000678a0  0000000e00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_do_sign@OPENSSL_3.0.0 + 0
00000000000678a8  0000000f00000007 R_X86_64_JUMP_SLOT     0000000000000000 mktime@GLIBC_2.2.5 + 0
00000000000678b0  0000001000000007 R_X86_64_JUMP_SLOT     0000000000000000 memset@GLIBC_2.2.5 + 0
00000000000678b8  0000001100000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_set_asn1_flag@OPENSSL_3.0.0 + 0
00000000000678c0  0000001200000007 R_X86_64_JUMP_SLOT     0000000000000000 snprintf@GLIBC_2.2.5 + 0
00000000000678c8  0000001300000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_get1_DSA@OPENSSL_3.0.0 + 0
00000000000678d0  0000001400000007 R_X86_64_JUMP_SLOT     0000000000000000 close@GLIBC_2.2.5 + 0
00000000000678d8  0000001500000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_free@OPENSSL_3.0.0 + 0
00000000000678e0  0000001600000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_set_private_key@OPENSSL_3.0.0 + 0
00000000000678e8  0000001700000007 R_X86_64_JUMP_SLOT     0000000000000000 ioctl@GLIBC_2.2.5 + 0
00000000000678f0  0000001800000007 R_X86_64_JUMP_SLOT     0000000000000000 abort@GLIBC_2.2.5 + 0
00000000000678f8  0000001a00000007 R_X86_64_JUMP_SLOT     0000000000000000 memchr@GLIBC_2.2.5 + 0
0000000000067900  0000001b00000007 R_X86_64_JUMP_SLOT     0000000000000000 clock_gettime@GLIBC_2.17 + 0
0000000000067908  0000001c00000007 R_X86_64_JUMP_SLOT     0000000000000000 __fprintf_chk@GLIBC_2.3.4 + 0
0000000000067910  0000001e00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_set_asn1_flag@OPENSSL_3.0.0 + 0
0000000000067918  0000002000000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_free@OPENSSL_3.0.0 + 0
0000000000067920  0000002100000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_bin2bn@OPENSSL_3.0.0 + 0
0000000000067928  0000002200000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_SIG_set0@OPENSSL_3.0.0 + 0
0000000000067930  0000002300000007 R_X86_64_JUMP_SLOT     0000000000000000 openlog@GLIBC_2.2.5 + 0
0000000000067938  0000002400000007 R_X86_64_JUMP_SLOT     0000000000000000 exit@GLIBC_2.2.5 + 0
0000000000067940  0000002500000007 R_X86_64_JUMP_SLOT     0000000000000000 fstat@GLIBC_2.33 + 0
0000000000067948  0000002600000007 R_X86_64_JUMP_SLOT     0000000000000000 BIO_new@OPENSSL_3.0.0 + 0
0000000000067950  0000002700000007 R_X86_64_JUMP_SLOT     0000000000000000 getaddrinfo@GLIBC_2.2.5 + 0
0000000000067958  0000002800000007 R_X86_64_JUMP_SLOT     0000000000000000 strcasecmp@GLIBC_2.2.5 + 0
0000000000067960  0000002900000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_blinding_on@OPENSSL_3.0.0 + 0
0000000000067968  0000002a00000007 R_X86_64_JUMP_SLOT     0000000000000000 gettimeofday@GLIBC_2.2.5 + 0
0000000000067970  0000002b00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_public_decrypt@OPENSSL_3.0.0 + 0
0000000000067978  0000002c00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_sha512@OPENSSL_3.0.0 + 0
0000000000067980  0000002d00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_get_affine_coordinates_GFp@OPENSSL_3.0.0 + 0
0000000000067988  0000002e00000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_SIG_free@OPENSSL_3.0.0 + 0
0000000000067990  0000002f00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_chacha20@OPENSSL_3.0.0 + 0
0000000000067998  0000003000000007 R_X86_64_JUMP_SLOT     0000000000000000 strpbrk@GLIBC_2.2.5 + 0
00000000000679a0  0000003100000007 R_X86_64_JUMP_SLOT     0000000000000000 strsignal@GLIBC_2.2.5 + 0
00000000000679a8  0000003200000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_bn2bin@OPENSSL_3.0.0 + 0
00000000000679b0  0000003300000007 R_X86_64_JUMP_SLOT     0000000000000000 reallocarray@GLIBC_2.26 + 0
00000000000679b8  0000003400000007 R_X86_64_JUMP_SLOT     0000000000000000 strncmp@GLIBC_2.2.5 + 0
00000000000679c0  0000003500000007 R_X86_64_JUMP_SLOT     0000000000000000 malloc@GLIBC_2.2.5 + 0
00000000000679c8  0000003600000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_SIG_free@OPENSSL_3.0.0 + 0
00000000000679d0  0000003700000007 R_X86_64_JUMP_SLOT     0000000000000000 sigfillset@GLIBC_2.2.5 + 0
00000000000679d8  0000003800000007 R_X86_64_JUMP_SLOT     0000000000000000 dup@GLIBC_2.2.5 + 0
00000000000679e0  0000003900000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_SIG_new@OPENSSL_3.0.0 + 0
00000000000679e8  0000003a00000007 R_X86_64_JUMP_SLOT     0000000000000000 unlink@GLIBC_2.2.5 + 0
00000000000679f0  0000003b00000007 R_X86_64_JUMP_SLOT     0000000000000000 setresuid@GLIBC_2.2.5 + 0
00000000000679f8  0000003c00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_set_group@OPENSSL_3.0.0 + 0
0000000000067a00  0000003d00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_new@OPENSSL_3.0.0 + 0
0000000000067a08  0000003e00000007 R_X86_64_JUMP_SLOT     0000000000000000 _exit@GLIBC_2.2.5 + 0
0000000000067a10  0000003f00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_set1_RSA@OPENSSL_3.0.0 + 0
0000000000067a18  0000004000000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_set_flags@OPENSSL_3.0.0 + 0
0000000000067a20  0000004100000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_aes_128_cbc@OPENSSL_3.0.0 + 0
0000000000067a28  0000004200000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_print_fp@OPENSSL_3.0.0 + 0
0000000000067a30  0000004300000007 R_X86_64_JUMP_SLOT     0000000000000000 __memcpy_chk@GLIBC_2.3.4 + 0
0000000000067a38  0000004400000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_get0_pqg@OPENSSL_3.0.0 + 0
0000000000067a40  0000004500000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_mul@OPENSSL_3.0.0 + 0
0000000000067a48  0000004600000007 R_X86_64_JUMP_SLOT     0000000000000000 setsockopt@GLIBC_2.2.5 + 0
0000000000067a50  0000004700000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_new@OPENSSL_3.0.0 + 0
0000000000067a58  0000004800000007 R_X86_64_JUMP_SLOT     0000000000000000 getsid@GLIBC_2.2.5 + 0
0000000000067a60  0000004900000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_value_one@OPENSSL_3.0.0 + 0
0000000000067a68  0000004a00000007 R_X86_64_JUMP_SLOT     0000000000000000 sysconf@GLIBC_2.2.5 + 0
0000000000067a70  0000004b00000007 R_X86_64_JUMP_SLOT     0000000000000000 PEM_write_bio_ECPrivateKey@OPENSSL_3.0.0 + 0
0000000000067a78  0000004c00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_free@OPENSSL_3.0.0 + 0
0000000000067a80  0000004e00000007 R_X86_64_JUMP_SLOT     0000000000000000 getpid@GLIBC_2.2.5 + 0
0000000000067a88  0000005000000007 R_X86_64_JUMP_SLOT     0000000000000000 __vsnprintf_chk@GLIBC_2.3.4 + 0
0000000000067a90  0000005100000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_set0_key@OPENSSL_3.0.0 + 0
0000000000067a98  0000005200000007 R_X86_64_JUMP_SLOT     0000000000000000 getpwuid@GLIBC_2.2.5 + 0
0000000000067aa0  0000005400000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_new@OPENSSL_3.0.0 + 0
0000000000067aa8  0000005500000007 R_X86_64_JUMP_SLOT     0000000000000000 geteuid@GLIBC_2.2.5 + 0
0000000000067ab0  0000005600000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_dup@OPENSSL_3.0.0 + 0
0000000000067ab8  0000005700000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_CTX_new@OPENSSL_3.0.0 + 0
0000000000067ac0  0000005800000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_MD_CTX_new@OPENSSL_3.0.0 + 0
0000000000067ac8  0000005900000007 R_X86_64_JUMP_SLOT     0000000000000000 closelog@GLIBC_2.2.5 + 0
0000000000067ad0  0000005a00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_free@OPENSSL_3.0.0 + 0
0000000000067ad8  0000005b00000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_SIG_new@OPENSSL_3.0.0 + 0
0000000000067ae0  0000005c00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_set0_pqg@OPENSSL_3.0.0 + 0
0000000000067ae8  0000005d00000007 R_X86_64_JUMP_SLOT     0000000000000000 freeaddrinfo@GLIBC_2.2.5 + 0
0000000000067af0  0000005e00000007 R_X86_64_JUMP_SLOT     0000000000000000 free@GLIBC_2.2.5 + 0
0000000000067af8  0000005f00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_sign@OPENSSL_3.0.0 + 0
0000000000067b00  0000006000000007 R_X86_64_JUMP_SLOT     0000000000000000 PEM_write_bio_PrivateKey@OPENSSL_3.0.0 + 0
0000000000067b08  0000006100000007 R_X86_64_JUMP_SLOT     0000000000000000 strlen@GLIBC_2.2.5 + 0
0000000000067b10  0000006200000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_free@OPENSSL_3.0.0 + 0
0000000000067b18  0000006400000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_cmp@OPENSSL_3.0.0 + 0
0000000000067b20  0000006500000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_oct2point@OPENSSL_3.0.0 + 0
0000000000067b28  0000006600000007 R_X86_64_JUMP_SLOT     0000000000000000 __asprintf_chk@GLIBC_2.8 + 0
0000000000067b30  0000006700000007 R_X86_64_JUMP_SLOT     0000000000000000 close_range@GLIBC_2.34 + 0
0000000000067b38  0000006800000007 R_X86_64_JUMP_SLOT     0000000000000000 opendir@GLIBC_2.2.5 + 0
0000000000067b40  0000006900000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_Cipher@OPENSSL_3.0.0 + 0
0000000000067b48  0000006a00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_MD_CTX_get0_md@OPENSSL_3.0.0 + 0
0000000000067b50  0000006b00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_generate_key@OPENSSL_3.0.0 + 0
0000000000067b58  0000006c00000007 R_X86_64_JUMP_SLOT     0000000000000000 getentropy@GLIBC_2.25 + 0
0000000000067b60  0000006d00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_get_iv_length@OPENSSL_3.0.0 + 0
0000000000067b68  0000006e00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_do_verify@OPENSSL_3.0.0 + 0
0000000000067b70  0000006f00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_set0_crt_params@OPENSSL_3.0.0 + 0
0000000000067b78  0000007000000007 R_X86_64_JUMP_SLOT     0000000000000000 listen@GLIBC_2.2.5 + 0
0000000000067b80  0000007100000007 R_X86_64_JUMP_SLOT     0000000000000000 __ctype_b_loc@GLIBC_2.3 + 0
0000000000067b88  0000007300000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_get_curve_name@OPENSSL_3.0.0 + 0
0000000000067b90  0000007400000007 R_X86_64_JUMP_SLOT     0000000000000000 readdir@GLIBC_2.2.5 + 0
0000000000067b98  0000007500000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_get_key_length@OPENSSL_3.0.0 + 0
0000000000067ba0  0000007600000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_iv@OPENSSL_3.0.0 + 0
0000000000067ba8  0000007700000007 R_X86_64_JUMP_SLOT     0000000000000000 fdopen@GLIBC_2.2.5 + 0
0000000000067bb0  0000007800000007 R_X86_64_JUMP_SLOT     0000000000000000 strrchr@GLIBC_2.2.5 + 0
0000000000067bb8  0000007900000007 R_X86_64_JUMP_SLOT     0000000000000000 getpagesize@GLIBC_2.2.5 + 0
0000000000067bc0  0000007a00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_set0_factors@OPENSSL_3.0.0 + 0
0000000000067bc8  0000007b00000007 R_X86_64_JUMP_SLOT     0000000000000000 pipe@GLIBC_2.2.5 + 0
0000000000067bd0  0000007c00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_cmp@OPENSSL_3.0.0 + 0
0000000000067bd8  0000007e00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_generate_key@OPENSSL_3.0.0 + 0
0000000000067be0  0000007f00000007 R_X86_64_JUMP_SLOT     0000000000000000 timegm@GLIBC_2.2.5 + 0
0000000000067be8  0000008000000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_SIG_get0@OPENSSL_3.0.0 + 0
0000000000067bf0  0000008100000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_METHOD_get_field_type@OPENSSL_3.0.0 + 0
0000000000067bf8  0000008200000007 R_X86_64_JUMP_SLOT     0000000000000000 poll@GLIBC_2.2.5 + 0
0000000000067c00  0000008300000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_num_bits@OPENSSL_3.0.0 + 0
0000000000067c08  0000008400000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_set_word@OPENSSL_3.0.0 + 0
0000000000067c10  0000008500000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_clear_free@OPENSSL_3.0.0 + 0
0000000000067c18  0000008600000007 R_X86_64_JUMP_SLOT     0000000000000000 PEM_write_bio_DSAPrivateKey@OPENSSL_3.0.0 + 0
0000000000067c20  0000008700000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_cmp@OPENSSL_3.0.0 + 0
0000000000067c28  0000008800000007 R_X86_64_JUMP_SLOT     0000000000000000 kill@GLIBC_2.2.5 + 0
0000000000067c30  0000008900000007 R_X86_64_JUMP_SLOT     0000000000000000 strerror@GLIBC_2.2.5 + 0
0000000000067c38  0000008a00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_get_order@OPENSSL_3.0.0 + 0
0000000000067c40  0000008b00000007 R_X86_64_JUMP_SLOT     0000000000000000 BIO_s_mem@OPENSSL_3.0.0 + 0
0000000000067c48  0000008c00000007 R_X86_64_JUMP_SLOT     0000000000000000 PEM_write_bio_RSAPrivateKey@OPENSSL_3.0.0 + 0
0000000000067c50  0000008d00000007 R_X86_64_JUMP_SLOT     0000000000000000 sigaction@GLIBC_2.2.5 + 0
0000000000067c58  0000008e00000007 R_X86_64_JUMP_SLOT     0000000000000000 __explicit_bzero_chk@GLIBC_2.25 + 0
0000000000067c60  0000008f00000007 R_X86_64_JUMP_SLOT     0000000000000000 getsockopt@GLIBC_2.2.5 + 0
0000000000067c68  0000009000000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_DigestUpdate@OPENSSL_3.0.0 + 0
0000000000067c70  0000009100000007 R_X86_64_JUMP_SLOT     0000000000000000 dlopen@GLIBC_2.34 + 0
0000000000067c78  0000009200000007 R_X86_64_JUMP_SLOT     0000000000000000 fputs@GLIBC_2.2.5 + 0
0000000000067c80  0000009300000007 R_X86_64_JUMP_SLOT     0000000000000000 strtol@GLIBC_2.2.5 + 0
0000000000067c88  0000009400000007 R_X86_64_JUMP_SLOT     0000000000000000 getsockname@GLIBC_2.2.5 + 0
0000000000067c90  0000009500000007 R_X86_64_JUMP_SLOT     0000000000000000 dirfd@GLIBC_2.2.5 + 0
0000000000067c98  0000009700000007 R_X86_64_JUMP_SLOT     0000000000000000 connect@GLIBC_2.2.5 + 0
0000000000067ca0  0000009900000007 R_X86_64_JUMP_SLOT     0000000000000000 ERR_peek_last_error@OPENSSL_3.0.0 + 0
0000000000067ca8  0000009a00000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_sub@OPENSSL_3.0.0 + 0
0000000000067cb0  0000009b00000007 R_X86_64_JUMP_SLOT     0000000000000000 execve@GLIBC_2.2.5 + 0
0000000000067cb8  0000009c00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_method_of@OPENSSL_3.0.0 + 0
0000000000067cc0  0000009d00000007 R_X86_64_JUMP_SLOT     0000000000000000 setresgid@GLIBC_2.2.5 + 0
0000000000067cc8  0000009e00000007 R_X86_64_JUMP_SLOT     0000000000000000 raise@GLIBC_2.2.5 + 0
0000000000067cd0  0000009f00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_generate_key_ex@OPENSSL_3.0.0 + 0
0000000000067cd8  000000a000000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_MD_CTX_copy_ex@OPENSSL_3.0.0 + 0
0000000000067ce0  000000a100000007 R_X86_64_JUMP_SLOT     0000000000000000 strspn@GLIBC_2.2.5 + 0
0000000000067ce8  000000a200000007 R_X86_64_JUMP_SLOT     0000000000000000 strptime@GLIBC_2.2.5 + 0
0000000000067cf0  000000a300000007 R_X86_64_JUMP_SLOT     0000000000000000 __syslog_chk@GLIBC_2.4 + 0
0000000000067cf8  000000a400000007 R_X86_64_JUMP_SLOT     0000000000000000 ECDSA_do_sign@OPENSSL_3.0.0 + 0
0000000000067d00  000000a500000007 R_X86_64_JUMP_SLOT     0000000000000000 memmove@GLIBC_2.2.5 + 0
0000000000067d08  000000a600000007 R_X86_64_JUMP_SLOT     0000000000000000 strchr@GLIBC_2.2.5 + 0
0000000000067d10  000000a700000007 R_X86_64_JUMP_SLOT     0000000000000000 waitpid@GLIBC_2.2.5 + 0
0000000000067d18  000000a800000007 R_X86_64_JUMP_SLOT     0000000000000000 socket@GLIBC_2.2.5 + 0
0000000000067d20  000000a900000007 R_X86_64_JUMP_SLOT     0000000000000000 getenv@GLIBC_2.2.5 + 0
0000000000067d28  000000aa00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_MD_CTX_free@OPENSSL_3.0.0 + 0
0000000000067d30  000000ab00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_get_updated_iv@OPENSSL_3.0.0 + 0
0000000000067d38  000000ac00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_get0_private_key@OPENSSL_3.0.0 + 0
0000000000067d40  000000ad00000007 R_X86_64_JUMP_SLOT     0000000000000000 __errno_location@GLIBC_2.2.5 + 0
0000000000067d48  000000ae00000007 R_X86_64_JUMP_SLOT     0000000000000000 strdup@GLIBC_2.2.5 + 0
0000000000067d50  000000af00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_SIG_set0@OPENSSL_3.0.0 + 0
0000000000067d58  000000b000000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_ctrl@OPENSSL_3.0.0 + 0
0000000000067d60  000000b100000007 R_X86_64_JUMP_SLOT     0000000000000000 ERR_peek_error@OPENSSL_3.0.0 + 0
0000000000067d68  000000b200000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_free@OPENSSL_3.0.0 + 0
0000000000067d70  000000b300000007 R_X86_64_JUMP_SLOT     0000000000000000 strncasecmp@GLIBC_2.2.5 + 0
0000000000067d78  000000b400000007 R_X86_64_JUMP_SLOT     0000000000000000 BN_CTX_free@OPENSSL_3.0.0 + 0
0000000000067d80  000000b500000007 R_X86_64_JUMP_SLOT     0000000000000000 PEM_read_bio_PrivateKey@OPENSSL_3.0.0 + 0
0000000000067d88  000000b600000007 R_X86_64_JUMP_SLOT     0000000000000000 __stack_chk_fail@GLIBC_2.4 + 0
0000000000067d90  000000b700000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_free@OPENSSL_3.0.0 + 0
0000000000067d98  000000b800000007 R_X86_64_JUMP_SLOT     0000000000000000 getnameinfo@GLIBC_2.2.5 + 0
0000000000067da0  000000b900000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_new@OPENSSL_3.0.0 + 0
0000000000067da8  000000ba00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_MD_get_block_size@OPENSSL_3.0.0 + 0
0000000000067db0  000000bb00000007 R_X86_64_JUMP_SLOT     0000000000000000 strcmp@GLIBC_2.2.5 + 0
0000000000067db8  000000bc00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_SIG_get0@OPENSSL_3.0.0 + 0
0000000000067dc0  000000bd00000007 R_X86_64_JUMP_SLOT     0000000000000000 nanosleep@GLIBC_2.2.5 + 0
0000000000067dc8  000000be00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_set1_EC_KEY@OPENSSL_3.0.0 + 0
0000000000067dd0  000000bf00000007 R_X86_64_JUMP_SLOT     0000000000000000 getuid@GLIBC_2.2.5 + 0
0000000000067dd8  000000c100000007 R_X86_64_JUMP_SLOT     0000000000000000 memmem@GLIBC_2.2.5 + 0
0000000000067de0  000000c200000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_DigestInit_ex@OPENSSL_3.0.0 + 0
0000000000067de8  000000c300000007 R_X86_64_JUMP_SLOT     0000000000000000 __ctype_tolower_loc@GLIBC_2.3 + 0
0000000000067df0  000000c400000007 R_X86_64_JUMP_SLOT     0000000000000000 memcmp@GLIBC_2.2.5 + 0
0000000000067df8  000000c500000007 R_X86_64_JUMP_SLOT     0000000000000000 calloc@GLIBC_2.2.5 + 0
0000000000067e00  000000c600000007 R_X86_64_JUMP_SLOT     0000000000000000 munmap@GLIBC_2.2.5 + 0
0000000000067e08  000000c700000007 R_X86_64_JUMP_SLOT     0000000000000000 feof@GLIBC_2.2.5 + 0
0000000000067e10  000000c800000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_point2oct@OPENSSL_3.0.0 + 0
0000000000067e18  000000c900000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CIPHER_CTX_new@OPENSSL_3.0.0 + 0
0000000000067e20  000000ca00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_set_public_key@OPENSSL_3.0.0 + 0
0000000000067e28  000000cb00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_get0_crt_params@OPENSSL_3.0.0 + 0
0000000000067e30  000000cc00000007 R_X86_64_JUMP_SLOT     0000000000000000 BIO_free@OPENSSL_3.0.0 + 0
0000000000067e38  000000cd00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_set0_key@OPENSSL_3.0.0 + 0
0000000000067e40  000000ce00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_new@OPENSSL_3.0.0 + 0
0000000000067e48  000000cf00000007 R_X86_64_JUMP_SLOT     0000000000000000 localtime_r@GLIBC_2.2.5 + 0
0000000000067e50  000000d000000007 R_X86_64_JUMP_SLOT     0000000000000000 BIO_ctrl@OPENSSL_3.0.0 + 0
0000000000067e58  000000d100000007 R_X86_64_JUMP_SLOT     0000000000000000 closedir@GLIBC_2.2.5 + 0
0000000000067e60  000000d200000007 R_X86_64_JUMP_SLOT     0000000000000000 strcspn@GLIBC_2.2.5 + 0
0000000000067e68  000000d300000007 R_X86_64_JUMP_SLOT     0000000000000000 __realpath_chk@GLIBC_2.4 + 0
0000000000067e70  000000d400000007 R_X86_64_JUMP_SLOT     0000000000000000 __snprintf_chk@GLIBC_2.3.4 + 0
0000000000067e78  000000d500000007 R_X86_64_JUMP_SLOT     0000000000000000 strsep@GLIBC_2.2.5 + 0
0000000000067e80  000000d600000007 R_X86_64_JUMP_SLOT     0000000000000000 fork@GLIBC_2.2.5 + 0
0000000000067e88  000000d700000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_get0_public_key@OPENSSL_3.0.0 + 0
0000000000067e90  000000d800000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_get0_factors@OPENSSL_3.0.0 + 0
0000000000067e98  000000d900000007 R_X86_64_JUMP_SLOT     0000000000000000 getppid@GLIBC_2.2.5 + 0
0000000000067ea0  000000da00000007 R_X86_64_JUMP_SLOT     0000000000000000 strtoll@GLIBC_2.2.5 + 0
0000000000067ea8  000000db00000007 R_X86_64_JUMP_SLOT     0000000000000000 dlsym@GLIBC_2.34 + 0
0000000000067eb0  000000dc00000007 R_X86_64_JUMP_SLOT     0000000000000000 DSA_get0_key@OPENSSL_3.0.0 + 0
0000000000067eb8  000000dd00000007 R_X86_64_JUMP_SLOT     0000000000000000 bind@GLIBC_2.2.5 + 0
0000000000067ec0  000000de00000007 R_X86_64_JUMP_SLOT     0000000000000000 fwrite@GLIBC_2.2.5 + 0
0000000000067ec8  000000df00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_free@OPENSSL_3.0.0 + 0
0000000000067ed0  000000e000000007 R_X86_64_JUMP_SLOT     0000000000000000 realloc@GLIBC_2.2.5 + 0
0000000000067ed8  000000e200000007 R_X86_64_JUMP_SLOT     0000000000000000 gai_strerror@GLIBC_2.2.5 + 0
0000000000067ee0  000000e300000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_size@OPENSSL_3.0.0 + 0
0000000000067ee8  000000e400000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_get1_RSA@OPENSSL_3.0.0 + 0
0000000000067ef0  000000e600000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_Digest@OPENSSL_3.0.0 + 0
0000000000067ef8  000000e700000007 R_X86_64_JUMP_SLOT     0000000000000000 strftime@GLIBC_2.2.5 + 0
0000000000067f00  000000e900000007 R_X86_64_JUMP_SLOT     0000000000000000 stat@GLIBC_2.33 + 0
0000000000067f08  000000ea00000007 R_X86_64_JUMP_SLOT     0000000000000000 strtoul@GLIBC_2.2.5 + 0
0000000000067f10  000000ec00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_CipherInit@OPENSSL_3.0.0 + 0
0000000000067f18  000000ed00000007 R_X86_64_JUMP_SLOT     0000000000000000 memcpy@GLIBC_2.14 + 0
0000000000067f20  000000ee00000007 R_X86_64_JUMP_SLOT     0000000000000000 fcntl@GLIBC_2.2.5 + 0
0000000000067f28  000000ef00000007 R_X86_64_JUMP_SLOT     0000000000000000 RSA_get0_key@OPENSSL_3.0.0 + 0
0000000000067f30  000000f100000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_GROUP_new_by_curve_name@OPENSSL_3.0.0 + 0
0000000000067f38  000000f200000007 R_X86_64_JUMP_SLOT     0000000000000000 open@GLIBC_2.2.5 + 0
0000000000067f40  000000f300000007 R_X86_64_JUMP_SLOT     0000000000000000 __vasprintf_chk@GLIBC_2.8 + 0
0000000000067f48  000000f400000007 R_X86_64_JUMP_SLOT     0000000000000000 mmap@GLIBC_2.2.5 + 0
0000000000067f50  000000f500000007 R_X86_64_JUMP_SLOT     0000000000000000 getpwnam@GLIBC_2.2.5 + 0
0000000000067f58  000000f600000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_DigestFinal_ex@OPENSSL_3.0.0 + 0
0000000000067f60  000000f700000007 R_X86_64_JUMP_SLOT     0000000000000000 ERR_get_error@OPENSSL_3.0.0 + 0
0000000000067f68  000000f800000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_get_base_id@OPENSSL_3.0.0 + 0
0000000000067f70  000000f900000007 R_X86_64_JUMP_SLOT     0000000000000000 strndup@GLIBC_2.2.5 + 0
0000000000067f78  000000fa00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_KEY_new_by_curve_name@OPENSSL_3.0.0 + 0
0000000000067f80  000000fb00000007 R_X86_64_JUMP_SLOT     0000000000000000 time@GLIBC_2.2.5 + 0
0000000000067f88  000000fc00000007 R_X86_64_JUMP_SLOT     0000000000000000 EVP_PKEY_set1_DSA@OPENSSL_3.0.0 + 0
0000000000067f90  000000fd00000007 R_X86_64_JUMP_SLOT     0000000000000000 EC_POINT_is_at_infinity@OPENSSL_3.0.0 + 0
0000000000067f98  000000fe00000007 R_X86_64_JUMP_SLOT     0000000000000000 dlclose@GLIBC_2.34 + 0
0000000000067fa0  000000ff00000007 R_X86_64_JUMP_SLOT     0000000000000000 getservbyname@GLIBC_2.2.5 + 0

exec
/bin/bash -lc 'strings -a -t x ./target.bin | rg -i "libssh|openssh|ssh-|kex|packet|cipher|hostkey|curve|known_hosts|copyright|version" | head -n 240; readelf -p .comment ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
   1d06 EVP_CIPHER_CTX_get_updated_iv
   1e7c EVP_CIPHER_CTX_ctrl
   1f0b EVP_CipherInit
   205c EC_GROUP_get_curve_name
   20d5 EVP_CIPHER_CTX_get_iv_length
   20f2 EVP_Cipher
   2154 EC_GROUP_new_by_curve_name
   222c EVP_CIPHER_CTX_iv_noconst
   225c EVP_CIPHER_CTX_get_key_length
   2293 EVP_CIPHER_CTX_iv
   22e5 EVP_CIPHER_CTX_set_key_length
   2396 EVP_CIPHER_CTX_new
   23f9 EVP_CIPHER_CTX_free
   24aa EC_KEY_new_by_curve_name
  3e004 ssh-sk-helper.c
  3e15a %s: parse version
  3e218 unsupported version: received %d, expected %d
  3e2ba ssh-sk-attest-v01
  3e2cc ssh-sk.c
  3e2fa sk_api_version
  3e568 Provider "%s" dlsym(sk_api_version) failed: %s
  3e598 provider %s implements version 0x%08lx
  3e5c0 Provider "%s" implements unsupported version 0x%08lx (supported: 0x%08lx)
  3e9ce invalid elliptic curve
  3e9fd elliptic curve does not match
  3ea36 invalid elliptic curve value
  3eacd no matching cipher found
  3eafc protocol version mismatch
  3ec38 elliptic curve point is too large
  3edd8 could not read protocol version
  3ee50 key encrypted using unsupported cipher
  3f05c ssh-unknown
  3f06f openssh-key-v1
  3f07e ssh-ed25519
  3f08a ssh-rsa
  3f0ac ssh-rsa-cert-v01@openssh.com
  3f1b7 sk-ssh-ed25519@openssh.com
  3f1f1 ssh-dss
  3f24d ssh-dss-cert-v01@openssh.com
  3f288 -----BEGIN OPENSSH PRIVATE KEY-----
  3f2b0 -----END OPENSSH PRIVATE KEY-----
  3f2d8 rsa-sha2-256-cert-v01@openssh.com
  3f300 rsa-sha2-512-cert-v01@openssh.com
  3f4c8 ssh-ed25519-cert-v01@openssh.com
  3f4f0 sk-ssh-ed25519-cert-v01@openssh.com
  3f518 sk-ecdsa-sha2-nistp256@openssh.com
  3f540 webauthn-sk-ecdsa-sha2-nistp256@openssh.com
  3f570 ecdsa-sha2-nistp256-cert-v01@openssh.com
  3f5a0 ecdsa-sha2-nistp384-cert-v01@openssh.com
  3f5d0 ecdsa-sha2-nistp521-cert-v01@openssh.com
  3f600 sk-ecdsa-sha2-nistp256-cert-v01@openssh.com
  3f960 0123456789abcdefzlib@openssh.com,zlib,none
  3f98b none,zlib@openssh.com,zlib
  3f9e6 aes128-gcm@openssh.com
  3f9fd aes256-gcm@openssh.com
  3fa14 chacha20-poly1305@openssh.com
  401eb /tmp/ssh-XXXXXXXXXXXX
  40201 %s/ssh-XXXXXXXXXXXX
  40cfa ssh-ed25519-sk.c
  40e35 ssh-ed25519.c
  670ce .gnu.version
  670db .gnu.version_r

String dump of section '.comment':
  [     0]  GCC: (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0


exec
/bin/bash -lc "objdump -d -M intel ./target.bin | rg -n \"call\\s+14ea0|jmp\\s+14ea0|14ea0\"; strings -a -t x ./target.bin | sed -n '1,260p'" in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
18210:   149f7:	e8 a4 04 00 00       	call   14ea0 <getservbyname@plt+0xe090>
18532:   14ea0:	41 57                	push   r15
    318 /lib64/ld-linux-x86-64.so.2
    378 tfXY
   1c99 __gmon_start__
   1ca8 _ITM_deregisterTMCloneTable
   1cc4 _ITM_registerTMCloneTable
   1cde BN_num_bits
   1cea ECDSA_SIG_free
   1cf9 EVP_PKEY_new
   1d06 EVP_CIPHER_CTX_get_updated_iv
   1d24 EVP_DigestInit_ex
   1d36 BN_div
   1d3d ERR_peek_last_error
   1d51 EC_POINT_free
   1d5f PEM_write_bio_RSAPrivateKey
   1d7b EVP_MD_CTX_copy_ex
   1d8e BN_print_fp
   1d9a DSA_get0_key
   1da7 BN_sub
   1dae EC_KEY_get0_private_key
   1dc6 EC_GROUP_set_asn1_flag
   1ddd RSA_size
   1de6 BN_dup
   1ded ERR_get_error
   1dfb EC_POINT_oct2point
   1e0e RSA_set0_key
   1e1b PEM_read_bio_PrivateKey
   1e33 RSA_generate_key_ex
   1e47 EVP_PKEY_get1_RSA
   1e59 DSA_new
   1e61 EVP_sha256
   1e6c EVP_aes_192_cbc
   1e7c EVP_CIPHER_CTX_ctrl
   1e90 BIO_write
   1e9a BN_set_word
   1ea6 ERR_peek_error
   1eb5 BN_clear_free
   1ec3 EC_GROUP_get_order
   1ed6 DSA_generate_key
   1ee7 EVP_aes_128_cbc
   1ef7 EC_KEY_generate_key
   1f0b EVP_CipherInit
   1f1a BN_bin2bn
   1f24 EVP_MD_CTX_new
   1f33 EVP_chacha20
   1f40 BIO_s_mem
   1f4a EC_GROUP_cmp
   1f57 EC_GROUP_free
   1f65 EVP_aes_192_ctr
   1f75 EVP_md5
   1f7d EC_KEY_get0_public_key
   1f94 EVP_aes_128_gcm
   1fa4 ECDSA_do_verify
   1fb4 RSA_free
   1fbd RSA_public_decrypt
   1fd0 EVP_des_ede3_cbc
   1fe1 EC_METHOD_get_field_type
   1ffa EVP_PKEY_set1_EC_KEY
   200f PEM_write_bio_ECPrivateKey
   202a RSA_new
   2032 BIO_free
   203b EC_KEY_get0_group
   204d ECDSA_SIG_get0
   205c EC_GROUP_get_curve_name
   2074 EVP_aes_128_ctr
   2084 EVP_sha1
   208d EVP_PKEY_get1_DSA
   209f EC_POINT_mul
   20ac EVP_DigestFinal_ex
   20bf EVP_sha384
   20ca EVP_Digest
   20d5 EVP_CIPHER_CTX_get_iv_length
   20f2 EVP_Cipher
   20fd DSA_get0_pqg
   210a ECDSA_SIG_new
   2118 EVP_MD_CTX_get0_md
   212b EVP_PKEY_get_base_id
   2140 RSA_get0_crt_params
   2154 EC_GROUP_new_by_curve_name
   216f DSA_set0_key
   217c RSA_set0_factors
   218d EC_KEY_set_private_key
   21a4 BN_set_flags
   21b1 RSA_get0_factors
   21c2 EC_KEY_set_asn1_flag
   21d7 EC_POINT_new
   21e4 RSA_set0_crt_params
   21f8 EVP_MD_get_block_size
   220e BN_CTX_free
   221a EVP_PKEY_set1_RSA
   222c EVP_CIPHER_CTX_iv_noconst
   2246 ECDSA_SIG_set0
   2255 BN_new
   225c EVP_CIPHER_CTX_get_key_length
   227a BIO_new
   2282 EC_KEY_set_group
   2293 EVP_CIPHER_CTX_iv
   22a5 EC_GROUP_method_of
   22b8 BN_bn2bin
   22c2 RSA_get0_key
   22cf EC_KEY_set_public_key
   22e5 EVP_CIPHER_CTX_set_key_length
   2303 PEM_write_bio_DSAPrivateKey
   231f EC_POINT_get_affine_coordinates_GFp
   2343 EC_POINT_cmp
   2350 BIO_ctrl
   2359 ECDSA_do_sign
   2367 EVP_PKEY_free
   2375 EVP_DigestUpdate
   2386 EVP_aes_256_cbc
   2396 EVP_CIPHER_CTX_new
   23a9 BN_cmp
   23b0 RSA_blinding_on
   23c0 PEM_write_bio_PrivateKey
   23d9 EVP_aes_256_gcm
   23e9 EVP_MD_CTX_free
   23f9 EVP_CIPHER_CTX_free
   240d EVP_PKEY_set1_DSA
   241f BN_CTX_new
   242a EVP_PKEY_get1_EC_KEY
   243f EVP_aes_256_ctr
   244f EC_POINT_is_at_infinity
   2467 EC_KEY_free
   2473 DSA_generate_parameters_ex
   248e EVP_sha512
   2499 DSA_free
   24a2 BN_free
   24aa EC_KEY_new_by_curve_name
   24c3 DSA_set0_pqg
   24d0 EC_POINT_point2oct
   24e3 RSA_sign
   24ec BN_value_one
   24f9 memmem
   2500 strsep
   2507 __ctype_tolower_loc
   251b dlerror
   2523 __progname
   252e __cxa_finalize
   253d closefrom
   2547 read
   254c strchr
   2553 malloc
   255a freeaddrinfo
   2567 fcntl
   256d readv
   2573 connect
   257b getpid
   2582 memmove
   258a strcspn
   2592 munmap
   2599 dirname
   25a1 localtime_r
   25ad closelog
   25b6 dirfd
   25bc getsockname
   25c8 __libc_start_main
   25da timegm
   25e1 getnameinfo
   25ed __fprintf_chk
   25fb strtoul
   2603 strcmp
   260a getentropy
   2615 dlsym
   261b fputs
   2621 nanosleep
   262b socket
   2632 strptime
   263b getservbyname
   2649 getsid
   2650 reallocarray
   265d unlink
   2664 strspn
   266b strncasecmp
   2677 strtol
   267e strsignal
   2688 memset
   268f strcasecmp
   269a strncmp
   26a2 __snprintf_chk
   26b1 __ctype_b_loc
   26bf execv
   26c5 mktime
   26cc getuid
   26d3 __explicit_bzero_chk
   26e8 memchr
   26ef closedir
   26f8 __realpath_chk
   2707 openlog
   270f pipe
   2714 strlen
   271b strdup
   2722 getpwuid
   272b raise
   2731 fdopen
   2738 getenv
   273f close_range
   274b __memcpy_chk
   2758 memcmp
   275f dlopen
   2766 gai_strerror
   2773 realloc
   277b __asprintf_chk
   278a sysconf
   2792 execve
   2799 dlclose
   27a1 __vsnprintf_chk
   27b1 getaddrinfo
   27bd bind
   27c2 geteuid
   27ca strftime
   27d3 abort
   27d9 snprintf
   27e2 fork
   27e7 stderr
   27ee ioctl
   27f4 dup2
   27f9 memcpy
   2800 sigaction
   280a strndup
   2812 listen
   2819 getpagesize
   2825 setresuid
   282f strpbrk
   2837 strrchr
   283f getppid
   2847 kill
   284c gettimeofday
   2859 poll
   285e opendir
   2866 _exit
   286c __vasprintf_chk
   287c getpwnam
   2885 setresgid
   288f __errno_location
   28a0 sigfillset
   28ab __syslog_chk
   28b8 waitpid
   28c0 getsockopt
   28cb fwrite
   28d2 readdir
   28da __stack_chk_fail
   28eb calloc
   28f2 strtoll
   28fa initgroups
   2905 mmap
   290a fstat
   2910 clock_gettime
   291e setsockopt
   2929 feof
   292e program_invocation_short_name
   294c libcrypto.so.3
   295b libc.so.6
   2965 GLIBC_2.14
   2970 GLIBC_2.4
   297a GLIBC_2.3
   2984 GLIBC_2.25
   298f GLIBC_2.8
   2999 GLIBC_2.26
   29a4 GLIBC_2.33
   29af GLIBC_2.3.4
   29bb GLIBC_2.17

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x14700 --stop-address=0x14ea0 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000014700 <closefrom@@Base-0x230c0>:
   14700:	c7 44 24 04 ea ff ff 	mov    DWORD PTR [rsp+0x4],0xffffffea
   14707:	ff 
   14708:	e9 f5 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1470d:	0f 1f 00             	nop    DWORD PTR [rax]
   14710:	c7 44 24 04 ec ff ff 	mov    DWORD PTR [rsp+0x4],0xffffffec
   14717:	ff 
   14718:	31 db                	xor    ebx,ebx
   1471a:	e9 e3 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1471f:	c7 44 24 04 fe ff ff 	mov    DWORD PTR [rsp+0x4],0xfffffffe
   14726:	ff 
   14727:	45 31 ff             	xor    r15d,r15d
   1472a:	45 31 f6             	xor    r14d,r14d
   1472d:	31 db                	xor    ebx,ebx
   1472f:	45 31 e4             	xor    r12d,r12d
   14732:	e9 cb fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   14737:	c7 44 24 04 fe ff ff 	mov    DWORD PTR [rsp+0x4],0xfffffffe
   1473e:	ff 
   1473f:	45 31 ff             	xor    r15d,r15d
   14742:	45 31 e4             	xor    r12d,r12d
   14745:	31 db                	xor    ebx,ebx
   14747:	e9 b6 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1474c:	c7 44 24 04 fe ff ff 	mov    DWORD PTR [rsp+0x4],0xfffffffe
   14753:	ff 
   14754:	45 31 ff             	xor    r15d,r15d
   14757:	31 db                	xor    ebx,ebx
   14759:	e9 a4 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1475e:	c7 44 24 04 fe ff ff 	mov    DWORD PTR [rsp+0x4],0xfffffffe
   14765:	ff 
   14766:	31 db                	xor    ebx,ebx
   14768:	e9 95 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1476d:	c7 44 24 04 fe ff ff 	mov    DWORD PTR [rsp+0x4],0xfffffffe
   14774:	ff 
   14775:	e9 88 fe ff ff       	jmp    14602 <getservbyname@plt+0xd7f2>
   1477a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   14780:	41 57                	push   r15
   14782:	41 56                	push   r14
   14784:	41 55                	push   r13
   14786:	41 54                	push   r12
   14788:	49 89 fc             	mov    r12,rdi
   1478b:	55                   	push   rbp
   1478c:	53                   	push   rbx
   1478d:	89 d3                	mov    ebx,edx
   1478f:	48 83 ec 78          	sub    rsp,0x78
   14793:	48 89 74 24 08       	mov    QWORD PTR [rsp+0x8],rsi
   14798:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1479f:	00 00 
   147a1:	48 89 44 24 68       	mov    QWORD PTR [rsp+0x68],rax
   147a6:	31 c0                	xor    eax,eax
   147a8:	48 c7 44 24 18 00 00 	mov    QWORD PTR [rsp+0x18],0x0
   147af:	00 00 
   147b1:	48 c7 44 24 20 00 00 	mov    QWORD PTR [rsp+0x20],0x0
   147b8:	00 00 
   147ba:	48 c7 44 24 30 00 00 	mov    QWORD PTR [rsp+0x30],0x0
   147c1:	00 00 
   147c3:	48 c7 44 24 38 00 00 	mov    QWORD PTR [rsp+0x38],0x0
   147ca:	00 00 
   147cc:	48 c7 44 24 40 00 00 	mov    QWORD PTR [rsp+0x40],0x0
   147d3:	00 00 
   147d5:	48 c7 44 24 48 00 00 	mov    QWORD PTR [rsp+0x48],0x0
   147dc:	00 00 
   147de:	48 c7 44 24 50 00 00 	mov    QWORD PTR [rsp+0x50],0x0
   147e5:	00 00 
   147e7:	48 c7 44 24 58 00 00 	mov    QWORD PTR [rsp+0x58],0x0
   147ee:	00 00 
   147f0:	48 c7 44 24 60 00 00 	mov    QWORD PTR [rsp+0x60],0x0
   147f7:	00 00 
   147f9:	48 85 f6             	test   rsi,rsi
   147fc:	74 07                	je     14805 <getservbyname@plt+0xd9f5>
   147fe:	48 c7 06 00 00 00 00 	mov    QWORD PTR [rsi],0x0
   14805:	4c 89 e7             	mov    rdi,r12
   14808:	e8 33 7e ff ff       	call   c640 <getservbyname@plt+0x5830>
   1480d:	49 89 c7             	mov    r15,rax
   14810:	48 85 c0             	test   rax,rax
   14813:	0f 84 77 05 00 00    	je     14d90 <getservbyname@plt+0xdf80>
   14819:	48 8d 74 24 18       	lea    rsi,[rsp+0x18]
   1481e:	31 d2                	xor    edx,edx
   14820:	4c 89 e7             	mov    rdi,r12
   14823:	e8 c8 5e 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   14828:	41 89 c6             	mov    r14d,eax
   1482b:	85 c0                	test   eax,eax
   1482d:	0f 85 2d 05 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   14833:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   14838:	e8 c3 a2 ff ff       	call   eb00 <getservbyname@plt+0x7cf0>
   1483d:	41 89 c5             	mov    r13d,eax
   14840:	85 db                	test   ebx,ebx
   14842:	0f 84 78 04 00 00    	je     14cc0 <getservbyname@plt+0xdeb0>
   14848:	41 83 fd 0d          	cmp    r13d,0xd
   1484c:	0f 87 9e 04 00 00    	ja     14cf0 <getservbyname@plt+0xdee0>
   14852:	48 8d 15 87 af 02 00 	lea    rdx,[rip+0x2af87]        # 3f7e0 <closefrom@@Base+0x8020>
   14859:	44 89 e8             	mov    eax,r13d
   1485c:	48 63 04 82          	movsxd rax,DWORD PTR [rdx+rax*4]
   14860:	48 01 d0             	add    rax,rdx
   14863:	3e ff e0             	notrack jmp rax
   14866:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   1486d:	00 00 00 
   14870:	31 d2                	xor    edx,edx
   14872:	31 f6                	xor    esi,esi
   14874:	4c 89 e7             	mov    rdi,r12
   14877:	e8 e4 5b 00 00       	call   1a460 <getservbyname@plt+0x13650>
   1487c:	85 c0                	test   eax,eax
   1487e:	0f 85 dc 04 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   14884:	48 8d 54 24 28       	lea    rdx,[rsp+0x28]
   14889:	48 8d 74 24 30       	lea    rsi,[rsp+0x30]
   1488e:	4c 89 e7             	mov    rdi,r12
   14891:	e8 fa 5c 00 00       	call   1a590 <getservbyname@plt+0x13780>
   14896:	85 c0                	test   eax,eax
   14898:	0f 85 42 04 00 00    	jne    14ce0 <getservbyname@plt+0xded0>
   1489e:	48 83 7c 24 28 20    	cmp    QWORD PTR [rsp+0x28],0x20
   148a4:	0f 85 b6 04 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   148aa:	44 89 ef             	mov    edi,r13d
   148ad:	e8 1e c6 ff ff       	call   10ed0 <getservbyname@plt+0xa0c0>
   148b2:	48 89 c5             	mov    rbp,rax
   148b5:	48 85 c0             	test   rax,rax
   148b8:	0f 84 ee 04 00 00    	je     14dac <getservbyname@plt+0xdf9c>
   148be:	41 83 ed 0c          	sub    r13d,0xc
   148c2:	41 83 fd 01          	cmp    r13d,0x1
   148c6:	0f 86 44 04 00 00    	jbe    14d10 <getservbyname@plt+0xdf00>
   148cc:	48 8b 44 24 30       	mov    rax,QWORD PTR [rsp+0x30]
   148d1:	31 db                	xor    ebx,ebx
   148d3:	48 c7 44 24 30 00 00 	mov    QWORD PTR [rsp+0x30],0x0
   148da:	00 00 
   148dc:	48 89 45 30          	mov    QWORD PTR [rbp+0x30],rax
   148e0:	e9 fd 00 00 00       	jmp    149e2 <getservbyname@plt+0xdbd2>
   148e5:	0f 1f 00             	nop    DWORD PTR [rax]
   148e8:	31 d2                	xor    edx,edx
   148ea:	31 f6                	xor    esi,esi
   148ec:	4c 89 e7             	mov    rdi,r12
   148ef:	e8 6c 5b 00 00       	call   1a460 <getservbyname@plt+0x13650>
   148f4:	85 c0                	test   eax,eax
   148f6:	0f 85 64 04 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   148fc:	44 89 ef             	mov    edi,r13d
   148ff:	e8 cc c5 ff ff       	call   10ed0 <getservbyname@plt+0xa0c0>
   14904:	48 89 c5             	mov    rbp,rax
   14907:	48 85 c0             	test   rax,rax
   1490a:	0f 84 80 04 00 00    	je     14d90 <getservbyname@plt+0xdf80>
   14910:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   14915:	e8 d6 a2 ff ff       	call   ebf0 <getservbyname@plt+0x7de0>
   1491a:	31 d2                	xor    edx,edx
   1491c:	48 8d 74 24 20       	lea    rsi,[rsp+0x20]
   14921:	4c 89 e7             	mov    rdi,r12
   14924:	89 45 18             	mov    DWORD PTR [rbp+0x18],eax
   14927:	e8 c4 5d 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   1492c:	85 c0                	test   eax,eax
   1492e:	0f 85 fc 03 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14934:	48 8b 7c 24 20       	mov    rdi,QWORD PTR [rsp+0x20]
   14939:	e8 c2 b0 ff ff       	call   fa00 <getservbyname@plt+0x8bf0>
   1493e:	39 45 18             	cmp    DWORD PTR [rbp+0x18],eax
   14941:	0f 85 58 04 00 00    	jne    14d9f <getservbyname@plt+0xdf8f>
   14947:	48 8b 7d 20          	mov    rdi,QWORD PTR [rbp+0x20]
   1494b:	e8 70 1a ff ff       	call   63c0 <EC_KEY_free@plt>
   14950:	8b 7d 18             	mov    edi,DWORD PTR [rbp+0x18]
   14953:	e8 68 24 ff ff       	call   6dc0 <EC_KEY_new_by_curve_name@plt>
   14958:	48 89 45 20          	mov    QWORD PTR [rbp+0x20],rax
   1495c:	48 89 c3             	mov    rbx,rax
   1495f:	48 85 c0             	test   rax,rax
   14962:	0f 84 e5 03 00 00    	je     14d4d <getservbyname@plt+0xdf3d>
   14968:	48 89 c7             	mov    rdi,rax
   1496b:	e8 00 16 ff ff       	call   5f70 <EC_KEY_get0_group@plt>
   14970:	48 89 c7             	mov    rdi,rax
   14973:	e8 d8 21 ff ff       	call   6b50 <EC_POINT_new@plt>
   14978:	48 89 c3             	mov    rbx,rax
   1497b:	48 85 c0             	test   rax,rax
   1497e:	0f 84 2a 04 00 00    	je     14dae <getservbyname@plt+0xdf9e>
   14984:	48 8b 7d 20          	mov    rdi,QWORD PTR [rbp+0x20]
   14988:	e8 e3 15 ff ff       	call   5f70 <EC_KEY_get0_group@plt>
   1498d:	48 89 de             	mov    rsi,rbx
   14990:	4c 89 e7             	mov    rdi,r12
   14993:	48 89 c2             	mov    rdx,rax
   14996:	e8 c5 89 00 00       	call   1d360 <getservbyname@plt+0x16550>
   1499b:	85 c0                	test   eax,eax
   1499d:	0f 85 8f 03 00 00    	jne    14d32 <getservbyname@plt+0xdf22>
   149a3:	48 8b 7d 20          	mov    rdi,QWORD PTR [rbp+0x20]
   149a7:	e8 c4 15 ff ff       	call   5f70 <EC_KEY_get0_group@plt>
   149ac:	48 89 de             	mov    rsi,rbx
   149af:	48 89 c7             	mov    rdi,rax
   149b2:	e8 a9 fa ff ff       	call   14460 <getservbyname@plt+0xd650>
   149b7:	85 c0                	test   eax,eax
   149b9:	0f 85 fa 03 00 00    	jne    14db9 <getservbyname@plt+0xdfa9>
   149bf:	48 8b 7d 20          	mov    rdi,QWORD PTR [rbp+0x20]
   149c3:	48 89 de             	mov    rsi,rbx
   149c6:	e8 45 21 ff ff       	call   6b10 <EC_KEY_set_public_key@plt>
   149cb:	83 f8 01             	cmp    eax,0x1
   149ce:	0f 85 da 03 00 00    	jne    14dae <getservbyname@plt+0xdf9e>
   149d4:	41 83 ed 0a          	sub    r13d,0xa
   149d8:	41 83 fd 01          	cmp    r13d,0x1
   149dc:	0f 86 8e 03 00 00    	jbe    14d70 <getservbyname@plt+0xdf60>
   149e2:	48 89 ef             	mov    rdi,rbp
   149e5:	e8 c6 a9 ff ff       	call   f3b0 <getservbyname@plt+0x85a0>
   149ea:	85 c0                	test   eax,eax
   149ec:	74 16                	je     14a04 <getservbyname@plt+0xdbf4>
   149ee:	4c 89 fa             	mov    rdx,r15
   149f1:	48 89 ee             	mov    rsi,rbp
   149f4:	4c 89 e7             	mov    rdi,r12
   149f7:	e8 a4 04 00 00       	call   14ea0 <getservbyname@plt+0xe090>
   149fc:	85 c0                	test   eax,eax
   149fe:	0f 85 fc 02 00 00    	jne    14d00 <getservbyname@plt+0xdef0>
   14a04:	4c 89 e7             	mov    rdi,r12
   14a07:	e8 c4 79 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   14a0c:	48 85 c0             	test   rax,rax
   14a0f:	0f 85 1d 03 00 00    	jne    14d32 <getservbyname@plt+0xdf22>
   14a15:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   14a1a:	48 85 c0             	test   rax,rax
   14a1d:	74 05                	je     14a24 <getservbyname@plt+0xdc14>
   14a1f:	48 89 28             	mov    QWORD PTR [rax],rbp
   14a22:	31 ed                	xor    ebp,ebp
   14a24:	4c 89 ff             	mov    rdi,r15
   14a27:	e8 b4 72 ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   14a2c:	48 89 ef             	mov    rdi,rbp
   14a2f:	e8 2c c0 ff ff       	call   10a60 <getservbyname@plt+0x9c50>
   14a34:	31 ff                	xor    edi,edi
   14a36:	e8 75 1a ff ff       	call   64b0 <free@plt>
   14a3b:	48 8b 7c 24 18       	mov    rdi,QWORD PTR [rsp+0x18]
   14a40:	e8 6b 1a ff ff       	call   64b0 <free@plt>
   14a45:	48 8b 7c 24 20       	mov    rdi,QWORD PTR [rsp+0x20]
   14a4a:	e8 61 1a ff ff       	call   64b0 <free@plt>
   14a4f:	48 8b 7c 24 30       	mov    rdi,QWORD PTR [rsp+0x30]
   14a54:	e8 57 1a ff ff       	call   64b0 <free@plt>
   14a59:	48 8b 7c 24 38       	mov    rdi,QWORD PTR [rsp+0x38]
   14a5e:	e8 8d 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a63:	48 8b 7c 24 40       	mov    rdi,QWORD PTR [rsp+0x40]
   14a68:	e8 83 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a6d:	48 8b 7c 24 48       	mov    rdi,QWORD PTR [rsp+0x48]
   14a72:	e8 79 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a77:	48 8b 7c 24 50       	mov    rdi,QWORD PTR [rsp+0x50]
   14a7c:	e8 6f 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a81:	48 8b 7c 24 58       	mov    rdi,QWORD PTR [rsp+0x58]
   14a86:	e8 65 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a8b:	48 8b 7c 24 60       	mov    rdi,QWORD PTR [rsp+0x60]
   14a90:	e8 5b 1c ff ff       	call   66f0 <BN_clear_free@plt>
   14a95:	48 89 df             	mov    rdi,rbx
   14a98:	e8 c3 21 ff ff       	call   6c60 <EC_POINT_free@plt>
   14a9d:	48 8b 44 24 68       	mov    rax,QWORD PTR [rsp+0x68]
   14aa2:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   14aa9:	00 00 
   14aab:	0f 85 13 03 00 00    	jne    14dc4 <getservbyname@plt+0xdfb4>
   14ab1:	48 83 c4 78          	add    rsp,0x78
   14ab5:	44 89 f0             	mov    eax,r14d
   14ab8:	5b                   	pop    rbx
   14ab9:	5d                   	pop    rbp
   14aba:	41 5c                	pop    r12
   14abc:	41 5d                	pop    r13
   14abe:	41 5e                	pop    r14
   14ac0:	41 5f                	pop    r15
   14ac2:	d9 ee                	fldz   
   14ac4:	d9 ee                	fldz   
   14ac6:	d9 ee                	fldz   
   14ac8:	d9 ee                	fldz   
   14aca:	d9 ee                	fldz   
   14acc:	d9 ee                	fldz   
   14ace:	d9 ee                	fldz   
   14ad0:	d9 ee                	fldz   
   14ad2:	dd d8                	fstp   st(0)
   14ad4:	dd d8                	fstp   st(0)
   14ad6:	dd d8                	fstp   st(0)
   14ad8:	dd d8                	fstp   st(0)
   14ada:	dd d8                	fstp   st(0)
   14adc:	dd d8                	fstp   st(0)
   14ade:	dd d8                	fstp   st(0)
   14ae0:	dd d8                	fstp   st(0)
   14ae2:	31 d2                	xor    edx,edx
   14ae4:	31 c9                	xor    ecx,ecx
   14ae6:	31 f6                	xor    esi,esi
   14ae8:	31 ff                	xor    edi,edi
   14aea:	66 0f ef c0          	pxor   xmm0,xmm0
   14aee:	66 0f ef c9          	pxor   xmm1,xmm1
   14af2:	66 0f ef d2          	pxor   xmm2,xmm2
   14af6:	66 0f ef db          	pxor   xmm3,xmm3
   14afa:	66 0f ef e4          	pxor   xmm4,xmm4
   14afe:	66 0f ef ed          	pxor   xmm5,xmm5
   14b02:	66 0f ef f6          	pxor   xmm6,xmm6
   14b06:	66 0f ef ff          	pxor   xmm7,xmm7
   14b0a:	45 31 c0             	xor    r8d,r8d
   14b0d:	45 31 c9             	xor    r9d,r9d
   14b10:	45 31 d2             	xor    r10d,r10d
   14b13:	45 31 db             	xor    r11d,r11d
   14b16:	66 45 0f ef c0       	pxor   xmm8,xmm8
   14b1b:	66 45 0f ef c9       	pxor   xmm9,xmm9
   14b20:	66 45 0f ef d2       	pxor   xmm10,xmm10
   14b25:	66 45 0f ef db       	pxor   xmm11,xmm11
   14b2a:	66 45 0f ef e4       	pxor   xmm12,xmm12
   14b2f:	66 45 0f ef ed       	pxor   xmm13,xmm13
   14b34:	66 45 0f ef f6       	pxor   xmm14,xmm14
   14b39:	66 45 0f ef ff       	pxor   xmm15,xmm15
   14b3e:	c3                   	ret    
   14b3f:	90                   	nop
   14b40:	31 d2                	xor    edx,edx
   14b42:	31 f6                	xor    esi,esi
   14b44:	4c 89 e7             	mov    rdi,r12
   14b47:	e8 14 59 00 00       	call   1a460 <getservbyname@plt+0x13650>
   14b4c:	85 c0                	test   eax,eax
   14b4e:	0f 85 0c 02 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   14b54:	44 89 ef             	mov    edi,r13d
   14b57:	e8 74 c3 ff ff       	call   10ed0 <getservbyname@plt+0xa0c0>
   14b5c:	48 89 c5             	mov    rbp,rax
   14b5f:	48 85 c0             	test   rax,rax
   14b62:	0f 84 28 02 00 00    	je     14d90 <getservbyname@plt+0xdf80>
   14b68:	48 8d 74 24 48       	lea    rsi,[rsp+0x48]
   14b6d:	4c 89 e7             	mov    rdi,r12
   14b70:	e8 ab 86 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14b75:	85 c0                	test   eax,eax
   14b77:	0f 85 b3 01 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14b7d:	48 8d 74 24 50       	lea    rsi,[rsp+0x50]
   14b82:	4c 89 e7             	mov    rdi,r12
   14b85:	e8 96 86 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14b8a:	85 c0                	test   eax,eax
   14b8c:	0f 85 9e 01 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14b92:	48 8d 74 24 58       	lea    rsi,[rsp+0x58]
   14b97:	4c 89 e7             	mov    rdi,r12
   14b9a:	e8 81 86 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14b9f:	85 c0                	test   eax,eax
   14ba1:	0f 85 89 01 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14ba7:	48 8d 74 24 60       	lea    rsi,[rsp+0x60]
   14bac:	4c 89 e7             	mov    rdi,r12
   14baf:	e8 6c 86 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14bb4:	85 c0                	test   eax,eax
   14bb6:	0f 85 74 01 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14bbc:	48 8b 7d 10          	mov    rdi,QWORD PTR [rbp+0x10]
   14bc0:	48 8b 4c 24 58       	mov    rcx,QWORD PTR [rsp+0x58]
   14bc5:	48 8b 54 24 50       	mov    rdx,QWORD PTR [rsp+0x50]
   14bca:	48 8b 74 24 48       	mov    rsi,QWORD PTR [rsp+0x48]
   14bcf:	e8 bc 18 ff ff       	call   6490 <DSA_set0_pqg@plt>
   14bd4:	85 c0                	test   eax,eax
   14bd6:	0f 84 64 01 00 00    	je     14d40 <getservbyname@plt+0xdf30>
   14bdc:	48 8b 7d 10          	mov    rdi,QWORD PTR [rbp+0x10]
   14be0:	48 8b 74 24 60       	mov    rsi,QWORD PTR [rsp+0x60]
   14be5:	31 d2                	xor    edx,edx
   14be7:	48 c7 44 24 58 00 00 	mov    QWORD PTR [rsp+0x58],0x0
   14bee:	00 00 
   14bf0:	48 c7 44 24 50 00 00 	mov    QWORD PTR [rsp+0x50],0x0
   14bf7:	00 00 
   14bf9:	48 c7 44 24 48 00 00 	mov    QWORD PTR [rsp+0x48],0x0
   14c00:	00 00 
   14c02:	e8 39 1f ff ff       	call   6b40 <DSA_set0_key@plt>
   14c07:	85 c0                	test   eax,eax
   14c09:	0f 84 31 01 00 00    	je     14d40 <getservbyname@plt+0xdf30>
   14c0f:	48 c7 44 24 60 00 00 	mov    QWORD PTR [rsp+0x60],0x0
   14c16:	00 00 
   14c18:	31 db                	xor    ebx,ebx
   14c1a:	e9 c3 fd ff ff       	jmp    149e2 <getservbyname@plt+0xdbd2>
   14c1f:	90                   	nop
   14c20:	31 d2                	xor    edx,edx
   14c22:	31 f6                	xor    esi,esi
   14c24:	4c 89 e7             	mov    rdi,r12
   14c27:	e8 34 58 00 00       	call   1a460 <getservbyname@plt+0x13650>
   14c2c:	85 c0                	test   eax,eax
   14c2e:	0f 85 2c 01 00 00    	jne    14d60 <getservbyname@plt+0xdf50>
   14c34:	44 89 ef             	mov    edi,r13d
   14c37:	e8 94 c2 ff ff       	call   10ed0 <getservbyname@plt+0xa0c0>
   14c3c:	48 89 c5             	mov    rbp,rax
   14c3f:	48 85 c0             	test   rax,rax
   14c42:	0f 84 48 01 00 00    	je     14d90 <getservbyname@plt+0xdf80>
   14c48:	48 8d 74 24 40       	lea    rsi,[rsp+0x40]
   14c4d:	4c 89 e7             	mov    rdi,r12
   14c50:	e8 cb 85 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14c55:	85 c0                	test   eax,eax
   14c57:	0f 85 d3 00 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14c5d:	48 8d 74 24 38       	lea    rsi,[rsp+0x38]
   14c62:	4c 89 e7             	mov    rdi,r12
   14c65:	e8 b6 85 00 00       	call   1d220 <getservbyname@plt+0x16410>
   14c6a:	85 c0                	test   eax,eax
   14c6c:	0f 85 be 00 00 00    	jne    14d30 <getservbyname@plt+0xdf20>
   14c72:	48 8b 7d 08          	mov    rdi,QWORD PTR [rbp+0x8]
   14c76:	48 8b 54 24 40       	mov    rdx,QWORD PTR [rsp+0x40]
   14c7b:	31 c9                	xor    ecx,ecx
   14c7d:	48 8b 74 24 38       	mov    rsi,QWORD PTR [rsp+0x38]
   14c82:	e8 69 17 ff ff       	call   63f0 <RSA_set0_key@plt>
   14c87:	85 c0                	test   eax,eax
   14c89:	0f 84 b1 00 00 00    	je     14d40 <getservbyname@plt+0xdf30>
   14c8f:	48 c7 44 24 40 00 00 	mov    QWORD PTR [rsp+0x40],0x0
   14c96:	00 00 
   14c98:	31 f6                	xor    esi,esi
   14c9a:	48 89 ef             	mov    rdi,rbp
   14c9d:	48 c7 44 24 38 00 00 	mov    QWORD PTR [rsp+0x38],0x0
   14ca4:	00 00 
   14ca6:	e8 65 de ff ff       	call   12b10 <getservbyname@plt+0xbd00>
   14cab:	85 c0                	test   eax,eax
   14cad:	0f 84 65 ff ff ff    	je     14c18 <getservbyname@plt+0xde08>
   14cb3:	41 89 c6             	mov    r14d,eax
   14cb6:	31 db                	xor    ebx,ebx
   14cb8:	e9 67 fd ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14cbd:	0f 1f 00             	nop    DWORD PTR [rax]
   14cc0:	89 c7                	mov    edi,eax
   14cc2:	e8 f9 9c ff ff       	call   e9c0 <getservbyname@plt+0x7bb0>
   14cc7:	85 c0                	test   eax,eax
   14cc9:	0f 84 79 fb ff ff    	je     14848 <getservbyname@plt+0xda38>
   14ccf:	31 db                	xor    ebx,ebx
   14cd1:	31 ed                	xor    ebp,ebp
   14cd3:	41 be ed ff ff ff    	mov    r14d,0xffffffed
   14cd9:	e9 46 fd ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14cde:	66 90                	xchg   ax,ax
   14ce0:	41 89 c6             	mov    r14d,eax
   14ce3:	31 db                	xor    ebx,ebx
   14ce5:	31 ed                	xor    ebp,ebp
   14ce7:	e9 38 fd ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14cec:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   14cf0:	31 db                	xor    ebx,ebx
   14cf2:	31 ed                	xor    ebp,ebp
   14cf4:	41 be f2 ff ff ff    	mov    r14d,0xfffffff2
   14cfa:	e9 25 fd ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14cff:	90                   	nop
   14d00:	41 89 c6             	mov    r14d,eax
   14d03:	e9 1c fd ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d08:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14d0f:	00 
   14d10:	31 d2                	xor    edx,edx
   14d12:	48 8d 70 60          	lea    rsi,[rax+0x60]
   14d16:	4c 89 e7             	mov    rdi,r12
   14d19:	e8 d2 59 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   14d1e:	85 c0                	test   eax,eax
   14d20:	0f 84 a6 fb ff ff    	je     148cc <getservbyname@plt+0xdabc>
   14d26:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
   14d2d:	00 00 00 
   14d30:	31 db                	xor    ebx,ebx
   14d32:	41 be fc ff ff ff    	mov    r14d,0xfffffffc
   14d38:	e9 e7 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d3d:	0f 1f 00             	nop    DWORD PTR [rax]
   14d40:	31 db                	xor    ebx,ebx
   14d42:	41 be ea ff ff ff    	mov    r14d,0xffffffea
   14d48:	e9 d7 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d4d:	41 be f4 ff ff ff    	mov    r14d,0xfffffff4
   14d53:	e9 cc fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d58:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14d5f:	00 
   14d60:	31 db                	xor    ebx,ebx
   14d62:	31 ed                	xor    ebp,ebp
   14d64:	41 be fc ff ff ff    	mov    r14d,0xfffffffc
   14d6a:	e9 b5 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d6f:	90                   	nop
   14d70:	31 d2                	xor    edx,edx
   14d72:	48 8d 75 60          	lea    rsi,[rbp+0x60]
   14d76:	4c 89 e7             	mov    rdi,r12
   14d79:	e8 72 59 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   14d7e:	85 c0                	test   eax,eax
   14d80:	0f 84 5c fc ff ff    	je     149e2 <getservbyname@plt+0xdbd2>
   14d86:	eb aa                	jmp    14d32 <getservbyname@plt+0xdf22>
   14d88:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   14d8f:	00 
   14d90:	31 db                	xor    ebx,ebx
   14d92:	31 ed                	xor    ebp,ebp
   14d94:	41 be fe ff ff ff    	mov    r14d,0xfffffffe
   14d9a:	e9 85 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14d9f:	31 db                	xor    ebx,ebx
   14da1:	41 be f1 ff ff ff    	mov    r14d,0xfffffff1
   14da7:	e9 78 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14dac:	31 db                	xor    ebx,ebx
   14dae:	41 be fe ff ff ff    	mov    r14d,0xfffffffe
   14db4:	e9 6b fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14db9:	41 be ec ff ff ff    	mov    r14d,0xffffffec
   14dbf:	e9 60 fc ff ff       	jmp    14a24 <getservbyname@plt+0xdc14>
   14dc4:	e8 17 1c ff ff       	call   69e0 <__stack_chk_fail@plt>
   14dc9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   14dd0:	f3 0f 1e fa          	endbr64 
   14dd4:	41 54                	push   r12
   14dd6:	49 89 d4             	mov    r12,rdx
   14dd9:	55                   	push   rbp
   14dda:	48 83 ec 08          	sub    rsp,0x8
   14dde:	e8 9d 6b ff ff       	call   b980 <getservbyname@plt+0x4b70>
   14de3:	48 85 c0             	test   rax,rax
   14de6:	0f 84 a5 00 00 00    	je     14e91 <getservbyname@plt+0xe081>
   14dec:	48 89 c5             	mov    rbp,rax
   14def:	4c 89 e6             	mov    rsi,r12
   14df2:	48 89 c7             	mov    rdi,rax
   14df5:	ba 01 00 00 00       	mov    edx,0x1
   14dfa:	e8 81 f9 ff ff       	call   14780 <getservbyname@plt+0xd970>
   14dff:	48 89 ef             	mov    rdi,rbp
   14e02:	41 89 c4             	mov    r12d,eax
   14e05:	e8 d6 6e ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   14e0a:	48 83 c4 08          	add    rsp,0x8
   14e0e:	44 89 e0             	mov    eax,r12d
   14e11:	5d                   	pop    rbp
   14e12:	41 5c                	pop    r12
   14e14:	d9 ee                	fldz   
   14e16:	d9 ee                	fldz   
   14e18:	d9 ee                	fldz   
   14e1a:	d9 ee                	fldz   
   14e1c:	d9 ee                	fldz   
   14e1e:	d9 ee                	fldz   
   14e20:	d9 ee                	fldz   
   14e22:	d9 ee                	fldz   
   14e24:	dd d8                	fstp   st(0)
   14e26:	dd d8                	fstp   st(0)
   14e28:	dd d8                	fstp   st(0)
   14e2a:	dd d8                	fstp   st(0)
   14e2c:	dd d8                	fstp   st(0)
   14e2e:	dd d8                	fstp   st(0)
   14e30:	dd d8                	fstp   st(0)
   14e32:	dd d8                	fstp   st(0)
   14e34:	31 d2                	xor    edx,edx
   14e36:	31 c9                	xor    ecx,ecx
   14e38:	31 f6                	xor    esi,esi
   14e3a:	31 ff                	xor    edi,edi
   14e3c:	66 0f ef c0          	pxor   xmm0,xmm0
   14e40:	66 0f ef c9          	pxor   xmm1,xmm1
   14e44:	66 0f ef d2          	pxor   xmm2,xmm2
   14e48:	66 0f ef db          	pxor   xmm3,xmm3
   14e4c:	66 0f ef e4          	pxor   xmm4,xmm4
   14e50:	66 0f ef ed          	pxor   xmm5,xmm5
   14e54:	66 0f ef f6          	pxor   xmm6,xmm6
   14e58:	66 0f ef ff          	pxor   xmm7,xmm7
   14e5c:	45 31 c0             	xor    r8d,r8d
   14e5f:	45 31 c9             	xor    r9d,r9d
   14e62:	45 31 d2             	xor    r10d,r10d
   14e65:	45 31 db             	xor    r11d,r11d
   14e68:	66 45 0f ef c0       	pxor   xmm8,xmm8
   14e6d:	66 45 0f ef c9       	pxor   xmm9,xmm9
   14e72:	66 45 0f ef d2       	pxor   xmm10,xmm10
   14e77:	66 45 0f ef db       	pxor   xmm11,xmm11
   14e7c:	66 45 0f ef e4       	pxor   xmm12,xmm12
   14e81:	66 45 0f ef ed       	pxor   xmm13,xmm13
   14e86:	66 45 0f ef f6       	pxor   xmm14,xmm14
   14e8b:	66 45 0f ef ff       	pxor   xmm15,xmm15
   14e90:	c3                   	ret    
   14e91:	41 bc fe ff ff ff    	mov    r12d,0xfffffffe
   14e97:	e9 6e ff ff ff       	jmp    14e0a <getservbyname@plt+0xdffa>
   14e9c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x19ba0 --stop-address=0x19d50 ./target.bin; objdump -d -M intel --start-address=0x1a400 --stop-address=0x1a7a0 ./target.bin; objdump -d -M intel --start-address=0x1a9f0 --stop-address=0x1ab60 ./target.bin; objdump -d -M intel --start-address=0x1b820 --stop-address=0x1b940 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000019ba0 <closefrom@@Base-0x1dc20>:
   19ba0:	d8 dd                	fcomp  st(5)
   19ba2:	d8 dd                	fcomp  st(5)
   19ba4:	d8 dd                	fcomp  st(5)
   19ba6:	d8 dd                	fcomp  st(5)
   19ba8:	d8 dd                	fcomp  st(5)
   19baa:	d8 dd                	fcomp  st(5)
   19bac:	d8 31                	fdiv   DWORD PTR [rcx]
   19bae:	d2 31                	shl    BYTE PTR [rcx],cl
   19bb0:	c9                   	leave  
   19bb1:	31 f6                	xor    esi,esi
   19bb3:	31 ff                	xor    edi,edi
   19bb5:	66 0f ef c0          	pxor   xmm0,xmm0
   19bb9:	66 0f ef c9          	pxor   xmm1,xmm1
   19bbd:	66 0f ef d2          	pxor   xmm2,xmm2
   19bc1:	66 0f ef db          	pxor   xmm3,xmm3
   19bc5:	66 0f ef e4          	pxor   xmm4,xmm4
   19bc9:	66 0f ef ed          	pxor   xmm5,xmm5
   19bcd:	66 0f ef f6          	pxor   xmm6,xmm6
   19bd1:	66 0f ef ff          	pxor   xmm7,xmm7
   19bd5:	45 31 c0             	xor    r8d,r8d
   19bd8:	45 31 c9             	xor    r9d,r9d
   19bdb:	45 31 d2             	xor    r10d,r10d
   19bde:	45 31 db             	xor    r11d,r11d
   19be1:	66 45 0f ef c0       	pxor   xmm8,xmm8
   19be6:	66 45 0f ef c9       	pxor   xmm9,xmm9
   19beb:	66 45 0f ef d2       	pxor   xmm10,xmm10
   19bf0:	66 45 0f ef db       	pxor   xmm11,xmm11
   19bf5:	66 45 0f ef e4       	pxor   xmm12,xmm12
   19bfa:	66 45 0f ef ed       	pxor   xmm13,xmm13
   19bff:	66 45 0f ef f6       	pxor   xmm14,xmm14
   19c04:	66 45 0f ef ff       	pxor   xmm15,xmm15
   19c09:	c3                   	ret    
   19c0a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   19c10:	f3 0f 1e fa          	endbr64 
   19c14:	41 54                	push   r12
   19c16:	55                   	push   rbp
   19c17:	48 89 fd             	mov    rbp,rdi
   19c1a:	53                   	push   rbx
   19c1b:	48 89 f3             	mov    rbx,rsi
   19c1e:	e8 fd 28 ff ff       	call   c520 <getservbyname@plt+0x5710>
   19c23:	be 08 00 00 00       	mov    esi,0x8
   19c28:	48 89 ef             	mov    rdi,rbp
   19c2b:	49 89 c4             	mov    r12,rax
   19c2e:	e8 4d 30 ff ff       	call   cc80 <getservbyname@plt+0x5e70>
   19c33:	85 c0                	test   eax,eax
   19c35:	78 11                	js     19c48 <getservbyname@plt+0x12e38>
   19c37:	31 c0                	xor    eax,eax
   19c39:	48 85 db             	test   rbx,rbx
   19c3c:	74 0a                	je     19c48 <getservbyname@plt+0x12e38>
   19c3e:	49 8b 14 24          	mov    rdx,QWORD PTR [r12]
   19c42:	48 0f ca             	bswap  rdx
   19c45:	48 89 13             	mov    QWORD PTR [rbx],rdx
   19c48:	5b                   	pop    rbx
   19c49:	5d                   	pop    rbp
   19c4a:	41 5c                	pop    r12
   19c4c:	d9 ee                	fldz   
   19c4e:	d9 ee                	fldz   
   19c50:	d9 ee                	fldz   
   19c52:	d9 ee                	fldz   
   19c54:	d9 ee                	fldz   
   19c56:	d9 ee                	fldz   
   19c58:	d9 ee                	fldz   
   19c5a:	d9 ee                	fldz   
   19c5c:	dd d8                	fstp   st(0)
   19c5e:	dd d8                	fstp   st(0)
   19c60:	dd d8                	fstp   st(0)
   19c62:	dd d8                	fstp   st(0)
   19c64:	dd d8                	fstp   st(0)
   19c66:	dd d8                	fstp   st(0)
   19c68:	dd d8                	fstp   st(0)
   19c6a:	dd d8                	fstp   st(0)
   19c6c:	31 d2                	xor    edx,edx
   19c6e:	31 c9                	xor    ecx,ecx
   19c70:	31 f6                	xor    esi,esi
   19c72:	31 ff                	xor    edi,edi
   19c74:	66 0f ef c0          	pxor   xmm0,xmm0
   19c78:	66 0f ef c9          	pxor   xmm1,xmm1
   19c7c:	66 0f ef d2          	pxor   xmm2,xmm2
   19c80:	66 0f ef db          	pxor   xmm3,xmm3
   19c84:	66 0f ef e4          	pxor   xmm4,xmm4
   19c88:	66 0f ef ed          	pxor   xmm5,xmm5
   19c8c:	66 0f ef f6          	pxor   xmm6,xmm6
   19c90:	66 0f ef ff          	pxor   xmm7,xmm7
   19c94:	45 31 c0             	xor    r8d,r8d
   19c97:	45 31 c9             	xor    r9d,r9d
   19c9a:	45 31 d2             	xor    r10d,r10d
   19c9d:	45 31 db             	xor    r11d,r11d
   19ca0:	66 45 0f ef c0       	pxor   xmm8,xmm8
   19ca5:	66 45 0f ef c9       	pxor   xmm9,xmm9
   19caa:	66 45 0f ef d2       	pxor   xmm10,xmm10
   19caf:	66 45 0f ef db       	pxor   xmm11,xmm11
   19cb4:	66 45 0f ef e4       	pxor   xmm12,xmm12
   19cb9:	66 45 0f ef ed       	pxor   xmm13,xmm13
   19cbe:	66 45 0f ef f6       	pxor   xmm14,xmm14
   19cc3:	66 45 0f ef ff       	pxor   xmm15,xmm15
   19cc8:	c3                   	ret    
   19cc9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   19cd0:	f3 0f 1e fa          	endbr64 
   19cd4:	41 54                	push   r12
   19cd6:	55                   	push   rbp
   19cd7:	48 89 fd             	mov    rbp,rdi
   19cda:	53                   	push   rbx
   19cdb:	48 89 f3             	mov    rbx,rsi
   19cde:	e8 3d 28 ff ff       	call   c520 <getservbyname@plt+0x5710>
   19ce3:	be 04 00 00 00       	mov    esi,0x4
   19ce8:	48 89 ef             	mov    rdi,rbp
   19ceb:	49 89 c4             	mov    r12,rax
   19cee:	e8 8d 2f ff ff       	call   cc80 <getservbyname@plt+0x5e70>
   19cf3:	85 c0                	test   eax,eax
   19cf5:	78 0f                	js     19d06 <getservbyname@plt+0x12ef6>
   19cf7:	31 c0                	xor    eax,eax
   19cf9:	48 85 db             	test   rbx,rbx
   19cfc:	74 08                	je     19d06 <getservbyname@plt+0x12ef6>
   19cfe:	41 8b 14 24          	mov    edx,DWORD PTR [r12]
   19d02:	0f ca                	bswap  edx
   19d04:	89 13                	mov    DWORD PTR [rbx],edx
   19d06:	5b                   	pop    rbx
   19d07:	5d                   	pop    rbp
   19d08:	41 5c                	pop    r12
   19d0a:	d9 ee                	fldz   
   19d0c:	d9 ee                	fldz   
   19d0e:	d9 ee                	fldz   
   19d10:	d9 ee                	fldz   
   19d12:	d9 ee                	fldz   
   19d14:	d9 ee                	fldz   
   19d16:	d9 ee                	fldz   
   19d18:	d9 ee                	fldz   
   19d1a:	dd d8                	fstp   st(0)
   19d1c:	dd d8                	fstp   st(0)
   19d1e:	dd d8                	fstp   st(0)
   19d20:	dd d8                	fstp   st(0)
   19d22:	dd d8                	fstp   st(0)
   19d24:	dd d8                	fstp   st(0)
   19d26:	dd d8                	fstp   st(0)
   19d28:	dd d8                	fstp   st(0)
   19d2a:	31 d2                	xor    edx,edx
   19d2c:	31 c9                	xor    ecx,ecx
   19d2e:	31 f6                	xor    esi,esi
   19d30:	31 ff                	xor    edi,edi
   19d32:	66 0f ef c0          	pxor   xmm0,xmm0
   19d36:	66 0f ef c9          	pxor   xmm1,xmm1
   19d3a:	66 0f ef d2          	pxor   xmm2,xmm2
   19d3e:	66 0f ef db          	pxor   xmm3,xmm3
   19d42:	66 0f ef e4          	pxor   xmm4,xmm4
   19d46:	66 0f ef ed          	pxor   xmm5,xmm5
   19d4a:	66 0f ef f6          	pxor   xmm6,xmm6
   19d4e:	66                   	data16
   19d4f:	0f                   	.byte 0xf

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001a400 <closefrom@@Base-0x1d3c0>:
   1a400:	ef                   	out    dx,eax
   1a401:	ed                   	in     eax,dx
   1a402:	66 0f ef f6          	pxor   xmm6,xmm6
   1a406:	66 0f ef ff          	pxor   xmm7,xmm7
   1a40a:	45 31 c0             	xor    r8d,r8d
   1a40d:	45 31 c9             	xor    r9d,r9d
   1a410:	45 31 d2             	xor    r10d,r10d
   1a413:	45 31 db             	xor    r11d,r11d
   1a416:	66 45 0f ef c0       	pxor   xmm8,xmm8
   1a41b:	66 45 0f ef c9       	pxor   xmm9,xmm9
   1a420:	66 45 0f ef d2       	pxor   xmm10,xmm10
   1a425:	66 45 0f ef db       	pxor   xmm11,xmm11
   1a42a:	66 45 0f ef e4       	pxor   xmm12,xmm12
   1a42f:	66 45 0f ef ed       	pxor   xmm13,xmm13
   1a434:	66 45 0f ef f6       	pxor   xmm14,xmm14
   1a439:	66 45 0f ef ff       	pxor   xmm15,xmm15
   1a43e:	c3                   	ret    
   1a43f:	90                   	nop
   1a440:	b8 fa ff ff ff       	mov    eax,0xfffffffa
   1a445:	e9 70 ff ff ff       	jmp    1a3ba <getservbyname@plt+0x135aa>
   1a44a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1a450:	b8 fd ff ff ff       	mov    eax,0xfffffffd
   1a455:	e9 60 ff ff ff       	jmp    1a3ba <getservbyname@plt+0x135aa>
   1a45a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1a460:	f3 0f 1e fa          	endbr64 
   1a464:	41 54                	push   r12
   1a466:	49 89 fc             	mov    r12,rdi
   1a469:	55                   	push   rbp
   1a46a:	48 89 f5             	mov    rbp,rsi
   1a46d:	53                   	push   rbx
   1a46e:	48 89 d3             	mov    rbx,rdx
   1a471:	48 83 ec 20          	sub    rsp,0x20
   1a475:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1a47c:	00 00 
   1a47e:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1a483:	31 c0                	xor    eax,eax
   1a485:	48 85 f6             	test   rsi,rsi
   1a488:	74 07                	je     1a491 <getservbyname@plt+0x13681>
   1a48a:	48 c7 06 00 00 00 00 	mov    QWORD PTR [rsi],0x0
   1a491:	48 85 db             	test   rbx,rbx
   1a494:	74 07                	je     1a49d <getservbyname@plt+0x1368d>
   1a496:	48 c7 03 00 00 00 00 	mov    QWORD PTR [rbx],0x0
   1a49d:	48 8d 54 24 08       	lea    rdx,[rsp+0x8]
   1a4a2:	48 8d 74 24 10       	lea    rsi,[rsp+0x10]
   1a4a7:	4c 89 e7             	mov    rdi,r12
   1a4aa:	e8 81 fe ff ff       	call   1a330 <getservbyname@plt+0x13520>
   1a4af:	85 c0                	test   eax,eax
   1a4b1:	78 34                	js     1a4e7 <getservbyname@plt+0x136d7>
   1a4b3:	48 85 ed             	test   rbp,rbp
   1a4b6:	74 09                	je     1a4c1 <getservbyname@plt+0x136b1>
   1a4b8:	48 8b 44 24 10       	mov    rax,QWORD PTR [rsp+0x10]
   1a4bd:	48 89 45 00          	mov    QWORD PTR [rbp+0x0],rax
   1a4c1:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
   1a4c6:	48 85 db             	test   rbx,rbx
   1a4c9:	74 03                	je     1a4ce <getservbyname@plt+0x136be>
   1a4cb:	48 89 33             	mov    QWORD PTR [rbx],rsi
   1a4ce:	48 83 c6 04          	add    rsi,0x4
   1a4d2:	4c 89 e7             	mov    rdi,r12
   1a4d5:	e8 a6 27 ff ff       	call   cc80 <getservbyname@plt+0x5e70>
   1a4da:	31 ff                	xor    edi,edi
   1a4dc:	85 c0                	test   eax,eax
   1a4de:	40 0f 95 c7          	setne  dil
   1a4e2:	e8 f9 35 02 00       	call   3dae0 <closefrom@@Base+0x6320>
   1a4e7:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
   1a4ec:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   1a4f3:	00 00 
   1a4f5:	0f 85 85 00 00 00    	jne    1a580 <getservbyname@plt+0x13770>
   1a4fb:	48 83 c4 20          	add    rsp,0x20
   1a4ff:	5b                   	pop    rbx
   1a500:	5d                   	pop    rbp
   1a501:	41 5c                	pop    r12
   1a503:	d9 ee                	fldz   
   1a505:	d9 ee                	fldz   
   1a507:	d9 ee                	fldz   
   1a509:	d9 ee                	fldz   
   1a50b:	d9 ee                	fldz   
   1a50d:	d9 ee                	fldz   
   1a50f:	d9 ee                	fldz   
   1a511:	d9 ee                	fldz   
   1a513:	dd d8                	fstp   st(0)
   1a515:	dd d8                	fstp   st(0)
   1a517:	dd d8                	fstp   st(0)
   1a519:	dd d8                	fstp   st(0)
   1a51b:	dd d8                	fstp   st(0)
   1a51d:	dd d8                	fstp   st(0)
   1a51f:	dd d8                	fstp   st(0)
   1a521:	dd d8                	fstp   st(0)
   1a523:	31 d2                	xor    edx,edx
   1a525:	31 c9                	xor    ecx,ecx
   1a527:	31 f6                	xor    esi,esi
   1a529:	31 ff                	xor    edi,edi
   1a52b:	66 0f ef c0          	pxor   xmm0,xmm0
   1a52f:	66 0f ef c9          	pxor   xmm1,xmm1
   1a533:	66 0f ef d2          	pxor   xmm2,xmm2
   1a537:	66 0f ef db          	pxor   xmm3,xmm3
   1a53b:	66 0f ef e4          	pxor   xmm4,xmm4
   1a53f:	66 0f ef ed          	pxor   xmm5,xmm5
   1a543:	66 0f ef f6          	pxor   xmm6,xmm6
   1a547:	66 0f ef ff          	pxor   xmm7,xmm7
   1a54b:	45 31 c0             	xor    r8d,r8d
   1a54e:	45 31 c9             	xor    r9d,r9d
   1a551:	45 31 d2             	xor    r10d,r10d
   1a554:	45 31 db             	xor    r11d,r11d
   1a557:	66 45 0f ef c0       	pxor   xmm8,xmm8
   1a55c:	66 45 0f ef c9       	pxor   xmm9,xmm9
   1a561:	66 45 0f ef d2       	pxor   xmm10,xmm10
   1a566:	66 45 0f ef db       	pxor   xmm11,xmm11
   1a56b:	66 45 0f ef e4       	pxor   xmm12,xmm12
   1a570:	66 45 0f ef ed       	pxor   xmm13,xmm13
   1a575:	66 45 0f ef f6       	pxor   xmm14,xmm14
   1a57a:	66 45 0f ef ff       	pxor   xmm15,xmm15
   1a57f:	c3                   	ret    
   1a580:	e8 5b c4 fe ff       	call   69e0 <__stack_chk_fail@plt>
   1a585:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1a58c:	00 00 00 00 
   1a590:	f3 0f 1e fa          	endbr64 
   1a594:	41 54                	push   r12
   1a596:	55                   	push   rbp
   1a597:	48 89 f5             	mov    rbp,rsi
   1a59a:	53                   	push   rbx
   1a59b:	48 89 d3             	mov    rbx,rdx
   1a59e:	48 83 ec 20          	sub    rsp,0x20
   1a5a2:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1a5a9:	00 00 
   1a5ab:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1a5b0:	31 c0                	xor    eax,eax
   1a5b2:	48 85 f6             	test   rsi,rsi
   1a5b5:	74 07                	je     1a5be <getservbyname@plt+0x137ae>
   1a5b7:	48 c7 06 00 00 00 00 	mov    QWORD PTR [rsi],0x0
   1a5be:	48 85 db             	test   rbx,rbx
   1a5c1:	74 07                	je     1a5ca <getservbyname@plt+0x137ba>
   1a5c3:	48 c7 03 00 00 00 00 	mov    QWORD PTR [rbx],0x0
   1a5ca:	48 8d 54 24 10       	lea    rdx,[rsp+0x10]
   1a5cf:	48 8d 74 24 08       	lea    rsi,[rsp+0x8]
   1a5d4:	e8 87 fe ff ff       	call   1a460 <getservbyname@plt+0x13650>
   1a5d9:	85 c0                	test   eax,eax
   1a5db:	78 41                	js     1a61e <getservbyname@plt+0x1380e>
   1a5dd:	48 85 ed             	test   rbp,rbp
   1a5e0:	74 2d                	je     1a60f <getservbyname@plt+0x137ff>
   1a5e2:	4c 8b 64 24 10       	mov    r12,QWORD PTR [rsp+0x10]
   1a5e7:	49 8d 7c 24 01       	lea    rdi,[r12+0x1]
   1a5ec:	e8 5f bc fe ff       	call   6250 <malloc@plt>
   1a5f1:	48 89 45 00          	mov    QWORD PTR [rbp+0x0],rax
   1a5f5:	48 89 c1             	mov    rcx,rax
   1a5f8:	48 85 c0             	test   rax,rax
   1a5fb:	0f 84 dc 00 00 00    	je     1a6dd <getservbyname@plt+0x138cd>
   1a601:	4d 85 e4             	test   r12,r12
   1a604:	0f 85 b6 00 00 00    	jne    1a6c0 <getservbyname@plt+0x138b0>
   1a60a:	42 c6 04 21 00       	mov    BYTE PTR [rcx+r12*1],0x0
   1a60f:	31 c0                	xor    eax,eax
   1a611:	48 85 db             	test   rbx,rbx
   1a614:	74 08                	je     1a61e <getservbyname@plt+0x1380e>
   1a616:	48 8b 54 24 10       	mov    rdx,QWORD PTR [rsp+0x10]
   1a61b:	48 89 13             	mov    QWORD PTR [rbx],rdx
   1a61e:	48 8b 54 24 18       	mov    rdx,QWORD PTR [rsp+0x18]
   1a623:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   1a62a:	00 00 
   1a62c:	0f 85 a6 00 00 00    	jne    1a6d8 <getservbyname@plt+0x138c8>
   1a632:	48 83 c4 20          	add    rsp,0x20
   1a636:	5b                   	pop    rbx
   1a637:	5d                   	pop    rbp
   1a638:	41 5c                	pop    r12
   1a63a:	d9 ee                	fldz   
   1a63c:	d9 ee                	fldz   
   1a63e:	d9 ee                	fldz   
   1a640:	d9 ee                	fldz   
   1a642:	d9 ee                	fldz   
   1a644:	d9 ee                	fldz   
   1a646:	d9 ee                	fldz   
   1a648:	d9 ee                	fldz   
   1a64a:	dd d8                	fstp   st(0)
   1a64c:	dd d8                	fstp   st(0)
   1a64e:	dd d8                	fstp   st(0)
   1a650:	dd d8                	fstp   st(0)
   1a652:	dd d8                	fstp   st(0)
   1a654:	dd d8                	fstp   st(0)
   1a656:	dd d8                	fstp   st(0)
   1a658:	dd d8                	fstp   st(0)
   1a65a:	31 d2                	xor    edx,edx
   1a65c:	31 c9                	xor    ecx,ecx
   1a65e:	31 f6                	xor    esi,esi
   1a660:	31 ff                	xor    edi,edi
   1a662:	66 0f ef c0          	pxor   xmm0,xmm0
   1a666:	66 0f ef c9          	pxor   xmm1,xmm1
   1a66a:	66 0f ef d2          	pxor   xmm2,xmm2
   1a66e:	66 0f ef db          	pxor   xmm3,xmm3
   1a672:	66 0f ef e4          	pxor   xmm4,xmm4
   1a676:	66 0f ef ed          	pxor   xmm5,xmm5
   1a67a:	66 0f ef f6          	pxor   xmm6,xmm6
   1a67e:	66 0f ef ff          	pxor   xmm7,xmm7
   1a682:	45 31 c0             	xor    r8d,r8d
   1a685:	45 31 c9             	xor    r9d,r9d
   1a688:	45 31 d2             	xor    r10d,r10d
   1a68b:	45 31 db             	xor    r11d,r11d
   1a68e:	66 45 0f ef c0       	pxor   xmm8,xmm8
   1a693:	66 45 0f ef c9       	pxor   xmm9,xmm9
   1a698:	66 45 0f ef d2       	pxor   xmm10,xmm10
   1a69d:	66 45 0f ef db       	pxor   xmm11,xmm11
   1a6a2:	66 45 0f ef e4       	pxor   xmm12,xmm12
   1a6a7:	66 45 0f ef ed       	pxor   xmm13,xmm13
   1a6ac:	66 45 0f ef f6       	pxor   xmm14,xmm14
   1a6b1:	66 45 0f ef ff       	pxor   xmm15,xmm15
   1a6b6:	c3                   	ret    
   1a6b7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1a6be:	00 00 
   1a6c0:	48 8b 74 24 08       	mov    rsi,QWORD PTR [rsp+0x8]
   1a6c5:	4c 89 e2             	mov    rdx,r12
   1a6c8:	48 89 c7             	mov    rdi,rax
   1a6cb:	e8 30 c6 fe ff       	call   6d00 <memcpy@plt>
   1a6d0:	48 89 c1             	mov    rcx,rax
   1a6d3:	e9 32 ff ff ff       	jmp    1a60a <getservbyname@plt+0x137fa>
   1a6d8:	e8 03 c3 fe ff       	call   69e0 <__stack_chk_fail@plt>
   1a6dd:	b8 fe ff ff ff       	mov    eax,0xfffffffe
   1a6e2:	e9 37 ff ff ff       	jmp    1a61e <getservbyname@plt+0x1380e>
   1a6e7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
   1a6ee:	00 00 
   1a6f0:	f3 0f 1e fa          	endbr64 
   1a6f4:	41 56                	push   r14
   1a6f6:	41 55                	push   r13
   1a6f8:	49 89 fd             	mov    r13,rdi
   1a6fb:	41 54                	push   r12
   1a6fd:	55                   	push   rbp
   1a6fe:	48 89 f5             	mov    rbp,rsi
   1a701:	53                   	push   rbx
   1a702:	48 89 d3             	mov    rbx,rdx
   1a705:	48 83 ec 20          	sub    rsp,0x20
   1a709:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1a710:	00 00 
   1a712:	48 89 44 24 18       	mov    QWORD PTR [rsp+0x18],rax
   1a717:	31 c0                	xor    eax,eax
   1a719:	48 85 f6             	test   rsi,rsi
   1a71c:	74 07                	je     1a725 <getservbyname@plt+0x13915>
   1a71e:	48 c7 06 00 00 00 00 	mov    QWORD PTR [rsi],0x0
   1a725:	48 85 db             	test   rbx,rbx
   1a728:	74 07                	je     1a731 <getservbyname@plt+0x13921>
   1a72a:	48 c7 03 00 00 00 00 	mov    QWORD PTR [rbx],0x0
   1a731:	48 8d 54 24 08       	lea    rdx,[rsp+0x8]
   1a736:	48 8d 74 24 10       	lea    rsi,[rsp+0x10]
   1a73b:	4c 89 ef             	mov    rdi,r13
   1a73e:	e8 ed fb ff ff       	call   1a330 <getservbyname@plt+0x13520>
   1a743:	41 89 c4             	mov    r12d,eax
   1a746:	85 c0                	test   eax,eax
   1a748:	75 7a                	jne    1a7c4 <getservbyname@plt+0x139b4>
   1a74a:	4c 8b 74 24 08       	mov    r14,QWORD PTR [rsp+0x8]
   1a74f:	4d 85 f6             	test   r14,r14
   1a752:	74 25                	je     1a779 <getservbyname@plt+0x13969>
   1a754:	4c 8b 64 24 10       	mov    r12,QWORD PTR [rsp+0x10]
   1a759:	31 f6                	xor    esi,esi
   1a75b:	4c 89 f2             	mov    rdx,r14
   1a75e:	4c 89 e7             	mov    rdi,r12
   1a761:	e8 5a b9 fe ff       	call   60c0 <memchr@plt>
   1a766:	48 85 c0             	test   rax,rax
   1a769:	74 0e                	je     1a779 <getservbyname@plt+0x13969>
   1a76b:	4b 8d 54 34 ff       	lea    rdx,[r12+r14*1-0x1]
   1a770:	48 39 d0             	cmp    rax,rdx
   1a773:	0f 82 07 01 00 00    	jb     1a880 <getservbyname@plt+0x13a70>
   1a779:	31 d2                	xor    edx,edx
   1a77b:	31 f6                	xor    esi,esi
   1a77d:	4c 89 ef             	mov    rdi,r13
   1a780:	e8 db fc ff ff       	call   1a460 <getservbyname@plt+0x13650>
   1a785:	41 89 c4             	mov    r12d,eax
   1a788:	85 c0                	test   eax,eax
   1a78a:	0f 85 fb 00 00 00    	jne    1a88b <getservbyname@plt+0x13a7b>
   1a790:	48 85 ed             	test   rbp,rbp
   1a793:	74 27                	je     1a7bc <getservbyname@plt+0x139ac>
   1a795:	49 8d 7e 01          	lea    rdi,[r14+0x1]
   1a799:	e8 b2 ba fe ff       	call   6250 <malloc@plt>
   1a79e:	48                   	rex.W
   1a79f:	89                   	.byte 0x89

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001a9f0 <closefrom@@Base-0x1cdd0>:
   1a9f0:	89 44 24 08          	mov    DWORD PTR [rsp+0x8],eax
   1a9f4:	31 c0                	xor    eax,eax
   1a9f6:	48 89 e2             	mov    rdx,rsp
   1a9f9:	e8 22 21 ff ff       	call   cb20 <getservbyname@plt+0x5d10>
   1a9fe:	41 89 c4             	mov    r12d,eax
   1aa01:	85 c0                	test   eax,eax
   1aa03:	78 0c                	js     1aa11 <getservbyname@plt+0x13c01>
   1aa05:	45 31 e4             	xor    r12d,r12d
   1aa08:	4d 85 ed             	test   r13,r13
   1aa0b:	0f 85 9f 00 00 00    	jne    1aab0 <getservbyname@plt+0x13ca0>
   1aa11:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   1aa16:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   1aa1d:	00 00 
   1aa1f:	0f 85 9f 00 00 00    	jne    1aac4 <getservbyname@plt+0x13cb4>
   1aa25:	48 83 c4 10          	add    rsp,0x10
   1aa29:	44 89 e0             	mov    eax,r12d
   1aa2c:	5d                   	pop    rbp
   1aa2d:	41 5c                	pop    r12
   1aa2f:	41 5d                	pop    r13
   1aa31:	d9 ee                	fldz   
   1aa33:	d9 ee                	fldz   
   1aa35:	d9 ee                	fldz   
   1aa37:	d9 ee                	fldz   
   1aa39:	d9 ee                	fldz   
   1aa3b:	d9 ee                	fldz   
   1aa3d:	d9 ee                	fldz   
   1aa3f:	d9 ee                	fldz   
   1aa41:	dd d8                	fstp   st(0)
   1aa43:	dd d8                	fstp   st(0)
   1aa45:	dd d8                	fstp   st(0)
   1aa47:	dd d8                	fstp   st(0)
   1aa49:	dd d8                	fstp   st(0)
   1aa4b:	dd d8                	fstp   st(0)
   1aa4d:	dd d8                	fstp   st(0)
   1aa4f:	dd d8                	fstp   st(0)
   1aa51:	31 d2                	xor    edx,edx
   1aa53:	31 c9                	xor    ecx,ecx
   1aa55:	31 f6                	xor    esi,esi
   1aa57:	31 ff                	xor    edi,edi
   1aa59:	66 0f ef c0          	pxor   xmm0,xmm0
   1aa5d:	66 0f ef c9          	pxor   xmm1,xmm1
   1aa61:	66 0f ef d2          	pxor   xmm2,xmm2
   1aa65:	66 0f ef db          	pxor   xmm3,xmm3
   1aa69:	66 0f ef e4          	pxor   xmm4,xmm4
   1aa6d:	66 0f ef ed          	pxor   xmm5,xmm5
   1aa71:	66 0f ef f6          	pxor   xmm6,xmm6
   1aa75:	66 0f ef ff          	pxor   xmm7,xmm7
   1aa79:	45 31 c0             	xor    r8d,r8d
   1aa7c:	45 31 c9             	xor    r9d,r9d
   1aa7f:	45 31 d2             	xor    r10d,r10d
   1aa82:	45 31 db             	xor    r11d,r11d
   1aa85:	66 45 0f ef c0       	pxor   xmm8,xmm8
   1aa8a:	66 45 0f ef c9       	pxor   xmm9,xmm9
   1aa8f:	66 45 0f ef d2       	pxor   xmm10,xmm10
   1aa94:	66 45 0f ef db       	pxor   xmm11,xmm11
   1aa99:	66 45 0f ef e4       	pxor   xmm12,xmm12
   1aa9e:	66 45 0f ef ed       	pxor   xmm13,xmm13
   1aaa3:	66 45 0f ef f6       	pxor   xmm14,xmm14
   1aaa8:	66 45 0f ef ff       	pxor   xmm15,xmm15
   1aaad:	c3                   	ret    
   1aaae:	66 90                	xchg   ax,ax
   1aab0:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   1aab4:	4c 89 ea             	mov    rdx,r13
   1aab7:	48 89 ee             	mov    rsi,rbp
   1aaba:	e8 41 c2 fe ff       	call   6d00 <memcpy@plt>
   1aabf:	e9 4d ff ff ff       	jmp    1aa11 <getservbyname@plt+0x13c01>
   1aac4:	e8 17 bf fe ff       	call   69e0 <__stack_chk_fail@plt>
   1aac9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   1aad0:	f3 0f 1e fa          	endbr64 
   1aad4:	48 85 f6             	test   rsi,rsi
   1aad7:	74 37                	je     1ab10 <getservbyname@plt+0x13d00>
   1aad9:	41 55                	push   r13
   1aadb:	41 54                	push   r12
   1aadd:	49 89 fc             	mov    r12,rdi
   1aae0:	48 89 f7             	mov    rdi,rsi
   1aae3:	55                   	push   rbp
   1aae4:	48 89 f5             	mov    rbp,rsi
   1aae7:	e8 e4 18 ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   1aaec:	48 89 ef             	mov    rdi,rbp
   1aaef:	49 89 c5             	mov    r13,rax
   1aaf2:	e8 29 1a ff ff       	call   c520 <getservbyname@plt+0x5710>
   1aaf7:	5d                   	pop    rbp
   1aaf8:	4c 89 ea             	mov    rdx,r13
   1aafb:	4c 89 e7             	mov    rdi,r12
   1aafe:	48 89 c6             	mov    rsi,rax
   1ab01:	41 5c                	pop    r12
   1ab03:	41 5d                	pop    r13
   1ab05:	e9 c6 fe ff ff       	jmp    1a9d0 <getservbyname@plt+0x13bc0>
   1ab0a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1ab10:	31 c0                	xor    eax,eax
   1ab12:	d9 ee                	fldz   
   1ab14:	d9 ee                	fldz   
   1ab16:	d9 ee                	fldz   
   1ab18:	d9 ee                	fldz   
   1ab1a:	d9 ee                	fldz   
   1ab1c:	d9 ee                	fldz   
   1ab1e:	d9 ee                	fldz   
   1ab20:	d9 ee                	fldz   
   1ab22:	dd d8                	fstp   st(0)
   1ab24:	dd d8                	fstp   st(0)
   1ab26:	dd d8                	fstp   st(0)
   1ab28:	dd d8                	fstp   st(0)
   1ab2a:	dd d8                	fstp   st(0)
   1ab2c:	dd d8                	fstp   st(0)
   1ab2e:	dd d8                	fstp   st(0)
   1ab30:	dd d8                	fstp   st(0)
   1ab32:	31 d2                	xor    edx,edx
   1ab34:	31 c9                	xor    ecx,ecx
   1ab36:	31 f6                	xor    esi,esi
   1ab38:	31 ff                	xor    edi,edi
   1ab3a:	66 0f ef c0          	pxor   xmm0,xmm0
   1ab3e:	66 0f ef c9          	pxor   xmm1,xmm1
   1ab42:	66 0f ef d2          	pxor   xmm2,xmm2
   1ab46:	66 0f ef db          	pxor   xmm3,xmm3
   1ab4a:	66 0f ef e4          	pxor   xmm4,xmm4
   1ab4e:	66 0f ef ed          	pxor   xmm5,xmm5
   1ab52:	66 0f ef f6          	pxor   xmm6,xmm6
   1ab56:	66 0f ef ff          	pxor   xmm7,xmm7
   1ab5a:	45 31 c0             	xor    r8d,r8d
   1ab5d:	45 31 c9             	xor    r9d,r9d

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000001b820 <closefrom@@Base-0x1bfa0>:
   1b820:	48 89 c2             	mov    rdx,rax
   1b823:	48 83 c4 08          	add    rsp,0x8
   1b827:	48 89 ee             	mov    rsi,rbp
   1b82a:	4c 89 e7             	mov    rdi,r12
   1b82d:	5d                   	pop    rbp
   1b82e:	41 5c                	pop    r12
   1b830:	e9 8b fe ff ff       	jmp    1b6c0 <getservbyname@plt+0x148b0>
   1b835:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1b83c:	00 00 00 00 
   1b840:	f3 0f 1e fa          	endbr64 
   1b844:	41 55                	push   r13
   1b846:	41 54                	push   r12
   1b848:	49 89 fc             	mov    r12,rdi
   1b84b:	55                   	push   rbp
   1b84c:	48 85 f6             	test   rsi,rsi
   1b84f:	74 2f                	je     1b880 <getservbyname@plt+0x14a70>
   1b851:	48 89 f5             	mov    rbp,rsi
   1b854:	48 89 f7             	mov    rdi,rsi
   1b857:	e8 74 0b ff ff       	call   c3d0 <getservbyname@plt+0x55c0>
   1b85c:	48 89 ef             	mov    rdi,rbp
   1b85f:	49 89 c5             	mov    r13,rax
   1b862:	e8 b9 0c ff ff       	call   c520 <getservbyname@plt+0x5710>
   1b867:	5d                   	pop    rbp
   1b868:	4c 89 ea             	mov    rdx,r13
   1b86b:	4c 89 e7             	mov    rdi,r12
   1b86e:	48 89 c6             	mov    rsi,rax
   1b871:	41 5c                	pop    r12
   1b873:	41 5d                	pop    r13
   1b875:	e9 46 fe ff ff       	jmp    1b6c0 <getservbyname@plt+0x148b0>
   1b87a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
   1b880:	5d                   	pop    rbp
   1b881:	4c 89 e7             	mov    rdi,r12
   1b884:	31 d2                	xor    edx,edx
   1b886:	41 5c                	pop    r12
   1b888:	31 f6                	xor    esi,esi
   1b88a:	41 5d                	pop    r13
   1b88c:	e9 2f fe ff ff       	jmp    1b6c0 <getservbyname@plt+0x148b0>
   1b891:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
   1b898:	00 00 00 00 
   1b89c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   1b8a0:	f3 0f 1e fa          	endbr64 
   1b8a4:	41 55                	push   r13
   1b8a6:	41 54                	push   r12
   1b8a8:	55                   	push   rbp
   1b8a9:	53                   	push   rbx
   1b8aa:	48 83 ec 38          	sub    rsp,0x38
   1b8ae:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   1b8b5:	00 00 
   1b8b7:	48 89 44 24 28       	mov    QWORD PTR [rsp+0x28],rax
   1b8bc:	31 c0                	xor    eax,eax
   1b8be:	48 85 ff             	test   rdi,rdi
   1b8c1:	0f 84 29 01 00 00    	je     1b9f0 <getservbyname@plt+0x14be0>
   1b8c7:	48 89 f3             	mov    rbx,rsi
   1b8ca:	48 85 f6             	test   rsi,rsi
   1b8cd:	0f 84 1d 01 00 00    	je     1b9f0 <getservbyname@plt+0x14be0>
   1b8d3:	48 c7 06 00 00 00 00 	mov    QWORD PTR [rsi],0x0
   1b8da:	48 8d 54 24 20       	lea    rdx,[rsp+0x20]
   1b8df:	48 8d 74 24 18       	lea    rsi,[rsp+0x18]
   1b8e4:	48 89 fd             	mov    rbp,rdi
   1b8e7:	e8 44 ea ff ff       	call   1a330 <getservbyname@plt+0x13520>
   1b8ec:	85 c0                	test   eax,eax
   1b8ee:	0f 84 9c 00 00 00    	je     1b990 <getservbyname@plt+0x14b80>
   1b8f4:	48 8b 54 24 28       	mov    rdx,QWORD PTR [rsp+0x28]
   1b8f9:	64 48 2b 14 25 28 00 	sub    rdx,QWORD PTR fs:0x28
   1b900:	00 00 
   1b902:	0f 85 fc 00 00 00    	jne    1ba04 <getservbyname@plt+0x14bf4>
   1b908:	48 83 c4 38          	add    rsp,0x38
   1b90c:	5b                   	pop    rbx
   1b90d:	5d                   	pop    rbp
   1b90e:	41 5c                	pop    r12
   1b910:	41 5d                	pop    r13
   1b912:	d9 ee                	fldz   
   1b914:	d9 ee                	fldz   
   1b916:	d9 ee                	fldz   
   1b918:	d9 ee                	fldz   
   1b91a:	d9 ee                	fldz   
   1b91c:	d9 ee                	fldz   
   1b91e:	d9 ee                	fldz   
   1b920:	d9 ee                	fldz   
   1b922:	dd d8                	fstp   st(0)
   1b924:	dd d8                	fstp   st(0)
   1b926:	dd d8                	fstp   st(0)
   1b928:	dd d8                	fstp   st(0)
   1b92a:	dd d8                	fstp   st(0)
   1b92c:	dd d8                	fstp   st(0)
   1b92e:	dd d8                	fstp   st(0)
   1b930:	dd d8                	fstp   st(0)
   1b932:	31 d2                	xor    edx,edx
   1b934:	31 c9                	xor    ecx,ecx
   1b936:	31 f6                	xor    esi,esi
   1b938:	31 ff                	xor    edi,edi
   1b93a:	66 0f ef c0          	pxor   xmm0,xmm0
   1b93e:	66                   	data16
   1b93f:	0f                   	.byte 0xf

exec
/bin/bash -lc 'strings -a -t x ./target.bin | rg "OpenSSH|SSH_ERR|ssh-sk-helper|usage:|OpenBSD" | head -n 120; objdump -s --start-address=0x3dfc0 --stop-address=0x3e180 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
  3e004 ssh-sk-helper.c
  3e111 usage: %s [-v]

./target.bin:     file format elf64-x86-64

Contents of section .rodata:
 3e000 01000200 7373682d 736b2d68 656c7065  ....ssh-sk-helpe
 3e010 722e6300 696e7661 6c696420 6572726f  r.c.invalid erro
 3e020 7220636f 64652025 64002573 3a207373  r code %d.%s: ss
 3e030 68627566 5f6e6577 20666169 6c656400  hbuf_new failed.
 3e040 25733a20 62756666 65722065 72726f72  %s: buffer error
 3e050 0025733a 20706172 73650025 733a2074  .%s: parse.%s: t
 3e060 7261696c 696e6720 64617461 20696e20  railing data in 
 3e070 72657175 65737400 25733a20 556e7375  request.%s: Unsu
 3e080 70706f72 74656420 6b657920 74797065  pported key type
 3e090 20257300 5369676e 696e6720 6661696c   %s.Signing fail
 3e0a0 65643a20 25730025 733a2063 6f6d706f  ed: %s.%s: compo
 3e0b0 73650025 733a2062 61642074 79706520  se.%s: bad type 
 3e0c0 25750045 6e726f6c 6c6d656e 74206661  %u.Enrollment fa
 3e0d0 696c6564 3a202573 0025733a 20656e63  iled: %s.%s: enc
 3e0e0 6f646520 6b657900 6b657920 257a7520  ode key.key %zu 
 3e0f0 25732025 73207569 646c656e 20257a75  %s %s uidlen %zu
 3e100 0025733a 20636f6d 706f7365 206b6579  .%s: compose key
 3e110 00757361 67653a20 2573205b 2d765d0a  .usage: %s [-v].
 3e120 0025733a 20647570 3a202573 00737368  .%s: dup: %s.ssh
 3e130 5f6d7367 5f726563 76206661 696c6564  _msg_recv failed
 3e140 00726563 65697665 64206d65 73736167  .received messag
 3e150 65206c65 6e20257a 75002573 3a207061  e len %zu.%s: pa
 3e160 72736520 76657273 696f6e00 7265706c  rse version.repl
 3e170 79206c65 6e20257a 75007373 685f6d73  y len %zu.ssh_ms

exec
/bin/bash -lc 'objdump -d -M intel --start-address=0x12bd0 --stop-address=0x12ce0 ./target.bin; objdump -d -M intel --start-address=0x130e0 --stop-address=0x13220 ./target.bin; objdump -d -M intel --start-address=0xd2c0 --stop-address=0xd360 ./target.bin; objdump -d -M intel --start-address=0xbcc0 --stop-address=0xbea0 ./target.bin; objdump -d -M intel --start-address=0xc3a0 --stop-address=0xc550 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

0000000000012bd0 <closefrom@@Base-0x24bf0>:
   12bd0:	66 45 0f ef f6       	pxor   xmm14,xmm14
   12bd5:	66 45 0f ef ff       	pxor   xmm15,xmm15
   12bda:	c3                   	ret    
   12bdb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]
   12be0:	31 c9                	xor    ecx,ecx
   12be2:	31 d2                	xor    edx,edx
   12be4:	4c 89 c7             	mov    rdi,r8
   12be7:	89 f3                	mov    ebx,esi
   12be9:	48 89 e6             	mov    rsi,rsp
   12bec:	e8 2f 41 ff ff       	call   6d20 <RSA_get0_key@plt>
   12bf1:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   12bf5:	e8 d6 3a ff ff       	call   66d0 <BN_num_bits@plt>
   12bfa:	3d ff 03 00 00       	cmp    eax,0x3ff
   12bff:	7e 08                	jle    12c09 <getservbyname@plt+0xbdf9>
   12c01:	39 d8                	cmp    eax,ebx
   12c03:	0f 8d 3a ff ff ff    	jge    12b43 <getservbyname@plt+0xbd33>
   12c09:	b8 c8 ff ff ff       	mov    eax,0xffffffc8
   12c0e:	e9 32 ff ff ff       	jmp    12b45 <getservbyname@plt+0xbd35>
   12c13:	e8 c8 3d ff ff       	call   69e0 <__stack_chk_fail@plt>
   12c18:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   12c1f:	00 
   12c20:	f3 0f 1e fa          	endbr64 
   12c24:	41 54                	push   r12
   12c26:	55                   	push   rbp
   12c27:	53                   	push   rbx
   12c28:	48 89 d3             	mov    rbx,rdx
   12c2b:	48 83 ec 10          	sub    rsp,0x10
   12c2f:	64 48 8b 04 25 28 00 	mov    rax,QWORD PTR fs:0x28
   12c36:	00 00 
   12c38:	48 89 44 24 08       	mov    QWORD PTR [rsp+0x8],rax
   12c3d:	31 c0                	xor    eax,eax
   12c3f:	48 c7 04 24 00 00 00 	mov    QWORD PTR [rsp],0x0
   12c46:	00 
   12c47:	48 85 d2             	test   rdx,rdx
   12c4a:	74 07                	je     12c53 <getservbyname@plt+0xbe43>
   12c4c:	48 c7 02 00 00 00 00 	mov    QWORD PTR [rdx],0x0
   12c53:	e8 28 8d ff ff       	call   b980 <getservbyname@plt+0x4b70>
   12c58:	48 89 c5             	mov    rbp,rax
   12c5b:	48 85 c0             	test   rax,rax
   12c5e:	0f 84 d3 00 00 00    	je     12d37 <getservbyname@plt+0xbf27>
   12c64:	48 89 c7             	mov    rdi,rax
   12c67:	48 89 e6             	mov    rsi,rsp
   12c6a:	31 d2                	xor    edx,edx
   12c6c:	e8 7f 7a 00 00       	call   1a6f0 <getservbyname@plt+0x138e0>
   12c71:	48 8b 3c 24          	mov    rdi,QWORD PTR [rsp]
   12c75:	41 89 c4             	mov    r12d,eax
   12c78:	85 c0                	test   eax,eax
   12c7a:	75 12                	jne    12c8e <getservbyname@plt+0xbe7e>
   12c7c:	48 85 db             	test   rbx,rbx
   12c7f:	74 0d                	je     12c8e <getservbyname@plt+0xbe7e>
   12c81:	48 c7 04 24 00 00 00 	mov    QWORD PTR [rsp],0x0
   12c88:	00 
   12c89:	48 89 3b             	mov    QWORD PTR [rbx],rdi
   12c8c:	31 ff                	xor    edi,edi
   12c8e:	e8 1d 38 ff ff       	call   64b0 <free@plt>
   12c93:	48 89 ef             	mov    rdi,rbp
   12c96:	e8 45 90 ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
   12c9b:	48 8b 44 24 08       	mov    rax,QWORD PTR [rsp+0x8]
   12ca0:	64 48 2b 04 25 28 00 	sub    rax,QWORD PTR fs:0x28
   12ca7:	00 00 
   12ca9:	0f 85 93 00 00 00    	jne    12d42 <getservbyname@plt+0xbf32>
   12caf:	48 83 c4 10          	add    rsp,0x10
   12cb3:	44 89 e0             	mov    eax,r12d
   12cb6:	5b                   	pop    rbx
   12cb7:	5d                   	pop    rbp
   12cb8:	41 5c                	pop    r12
   12cba:	d9 ee                	fldz   
   12cbc:	d9 ee                	fldz   
   12cbe:	d9 ee                	fldz   
   12cc0:	d9 ee                	fldz   
   12cc2:	d9 ee                	fldz   
   12cc4:	d9 ee                	fldz   
   12cc6:	d9 ee                	fldz   
   12cc8:	d9 ee                	fldz   
   12cca:	dd d8                	fstp   st(0)
   12ccc:	dd d8                	fstp   st(0)
   12cce:	dd d8                	fstp   st(0)
   12cd0:	dd d8                	fstp   st(0)
   12cd2:	dd d8                	fstp   st(0)
   12cd4:	dd d8                	fstp   st(0)
   12cd6:	dd d8                	fstp   st(0)
   12cd8:	dd d8                	fstp   st(0)
   12cda:	31 d2                	xor    edx,edx
   12cdc:	31 c9                	xor    ecx,ecx
   12cde:	31 f6                	xor    esi,esi

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

00000000000130e0 <closefrom@@Base-0x246e0>:
   130e0:	45 0f ef c0          	rex.RB pxor mm0,mm0
   130e4:	66 45 0f ef c9       	pxor   xmm9,xmm9
   130e9:	66 45 0f ef d2       	pxor   xmm10,xmm10
   130ee:	66 45 0f ef db       	pxor   xmm11,xmm11
   130f3:	66 45 0f ef e4       	pxor   xmm12,xmm12
   130f8:	66 45 0f ef ed       	pxor   xmm13,xmm13
   130fd:	66 45 0f ef f6       	pxor   xmm14,xmm14
   13102:	66 45 0f ef ff       	pxor   xmm15,xmm15
   13107:	c3                   	ret    
   13108:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
   1310f:	00 
   13110:	4c 8b 24 24          	mov    r12,QWORD PTR [rsp]
   13114:	4c 89 ef             	mov    rdi,r13
   13117:	4c 89 e6             	mov    rsi,r12
   1311a:	e8 11 39 ff ff       	call   6a30 <strcmp@plt>
   1311f:	4c 89 e7             	mov    rdi,r12
   13122:	89 c5                	mov    ebp,eax
   13124:	e8 87 33 ff ff       	call   64b0 <free@plt>
   13129:	85 ed                	test   ebp,ebp
   1312b:	75 07                	jne    13134 <getservbyname@plt+0xc324>
   1312d:	31 c0                	xor    eax,eax
   1312f:	e9 3a ff ff ff       	jmp    1306e <getservbyname@plt+0xc25e>
   13134:	b8 c6 ff ff ff       	mov    eax,0xffffffc6
   13139:	e9 30 ff ff ff       	jmp    1306e <getservbyname@plt+0xc25e>
   1313e:	b8 f6 ff ff ff       	mov    eax,0xfffffff6
   13143:	e9 26 ff ff ff       	jmp    1306e <getservbyname@plt+0xc25e>
   13148:	e8 93 38 ff ff       	call   69e0 <__stack_chk_fail@plt>
   1314d:	0f 1f 00             	nop    DWORD PTR [rax]
   13150:	f3 0f 1e fa          	endbr64 
   13154:	53                   	push   rbx
   13155:	49 89 cb             	mov    r11,rcx
   13158:	48 8b 4c 24 18       	mov    rcx,QWORD PTR [rsp+0x18]
   1315d:	8b 5c 24 10          	mov    ebx,DWORD PTR [rsp+0x10]
   13161:	48 85 c9             	test   rcx,rcx
   13164:	74 07                	je     1316d <getservbyname@plt+0xc35d>
   13166:	48 c7 01 00 00 00 00 	mov    QWORD PTR [rcx],0x0
   1316d:	48 85 d2             	test   rdx,rdx
   13170:	0f 84 22 01 00 00    	je     13298 <getservbyname@plt+0xc488>
   13176:	49 81 f8 00 00 10 00 	cmp    r8,0x100000
   1317d:	0f 87 15 01 00 00    	ja     13298 <getservbyname@plt+0xc488>
   13183:	83 3f 0d             	cmp    DWORD PTR [rdi],0xd
   13186:	0f 87 84 00 00 00    	ja     13210 <getservbyname@plt+0xc400>
   1318c:	8b 07                	mov    eax,DWORD PTR [rdi]
   1318e:	4c 8d 15 b7 c5 02 00 	lea    r10,[rip+0x2c5b7]        # 3f74c <closefrom@@Base+0x7f8c>
   13195:	49 63 04 82          	movsxd rax,DWORD PTR [r10+rax*4]
   13199:	4c 01 d0             	add    rax,r10
   1319c:	3e ff e0             	notrack jmp rax
   1319f:	90                   	nop
   131a0:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
   131a5:	41 89 d9             	mov    r9d,ebx
   131a8:	4c 89 d9             	mov    rcx,r11
   131ab:	5b                   	pop    rbx
   131ac:	e9 5f a4 01 00       	jmp    2d610 <getservbyname@plt+0x26800>
   131b1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   131b8:	4c 89 d9             	mov    rcx,r11
   131bb:	5b                   	pop    rbx
   131bc:	e9 bf b7 01 00       	jmp    2e980 <getservbyname@plt+0x27b70>
   131c1:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   131c8:	41 89 d9             	mov    r9d,ebx
   131cb:	4c 89 d9             	mov    rcx,r11
   131ce:	5b                   	pop    rbx
   131cf:	e9 0c 8f 01 00       	jmp    2c0e0 <getservbyname@plt+0x252d0>
   131d4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   131d8:	41 89 d9             	mov    r9d,ebx
   131db:	4c 89 d9             	mov    rcx,r11
   131de:	5b                   	pop    rbx
   131df:	e9 2c 96 01 00       	jmp    2c810 <getservbyname@plt+0x25a00>
   131e4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   131e8:	41 89 d9             	mov    r9d,ebx
   131eb:	4c 89 d9             	mov    rcx,r11
   131ee:	5b                   	pop    rbx
   131ef:	e9 9c c8 01 00       	jmp    2fa90 <getservbyname@plt+0x28c80>
   131f4:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]
   131f8:	48 89 4c 24 10       	mov    QWORD PTR [rsp+0x10],rcx
   131fd:	41 89 d9             	mov    r9d,ebx
   13200:	4c 89 d9             	mov    rcx,r11
   13203:	5b                   	pop    rbx
   13204:	e9 07 9c 01 00       	jmp    2ce10 <getservbyname@plt+0x26000>
   13209:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
   13210:	b8 f2 ff ff ff       	mov    eax,0xfffffff2
   13215:	5b                   	pop    rbx
   13216:	d9 ee                	fldz   
   13218:	d9 ee                	fldz   
   1321a:	d9 ee                	fldz   
   1321c:	d9 ee                	fldz   
   1321e:	d9 ee                	fldz   

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000000d2c0 <closefrom@@Base-0x2a500>:
    d2c0:	ef                   	out    dx,eax
    d2c1:	ff 45 31             	inc    DWORD PTR [rbp+0x31]
    d2c4:	c0 45 31 c9          	rol    BYTE PTR [rbp+0x31],0xc9
    d2c8:	45 31 d2             	xor    r10d,r10d
    d2cb:	45 31 db             	xor    r11d,r11d
    d2ce:	66 45 0f ef c0       	pxor   xmm8,xmm8
    d2d3:	66 45 0f ef c9       	pxor   xmm9,xmm9
    d2d8:	66 45 0f ef d2       	pxor   xmm10,xmm10
    d2dd:	66 45 0f ef db       	pxor   xmm11,xmm11
    d2e2:	66 45 0f ef e4       	pxor   xmm12,xmm12
    d2e7:	66 45 0f ef ed       	pxor   xmm13,xmm13
    d2ec:	66 45 0f ef f6       	pxor   xmm14,xmm14
    d2f1:	66 45 0f ef ff       	pxor   xmm15,xmm15
    d2f6:	c3                   	ret    
    d2f7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    d2fe:	00 00 
    d300:	83 ff 0c             	cmp    edi,0xc
    d303:	0f 87 8f 00 00 00    	ja     d398 <getservbyname@plt+0x6588>
    d309:	89 f9                	mov    ecx,edi
    d30b:	b8 0f 15 00 00       	mov    eax,0x150f
    d310:	48 d3 e8             	shr    rax,cl
    d313:	83 e0 01             	and    eax,0x1
    d316:	d9 ee                	fldz   
    d318:	d9 ee                	fldz   
    d31a:	d9 ee                	fldz   
    d31c:	d9 ee                	fldz   
    d31e:	d9 ee                	fldz   
    d320:	d9 ee                	fldz   
    d322:	d9 ee                	fldz   
    d324:	d9 ee                	fldz   
    d326:	dd d8                	fstp   st(0)
    d328:	dd d8                	fstp   st(0)
    d32a:	dd d8                	fstp   st(0)
    d32c:	dd d8                	fstp   st(0)
    d32e:	dd d8                	fstp   st(0)
    d330:	dd d8                	fstp   st(0)
    d332:	dd d8                	fstp   st(0)
    d334:	dd d8                	fstp   st(0)
    d336:	31 d2                	xor    edx,edx
    d338:	31 c9                	xor    ecx,ecx
    d33a:	31 f6                	xor    esi,esi
    d33c:	31 ff                	xor    edi,edi
    d33e:	66 0f ef c0          	pxor   xmm0,xmm0
    d342:	66 0f ef c9          	pxor   xmm1,xmm1
    d346:	66 0f ef d2          	pxor   xmm2,xmm2
    d34a:	66 0f ef db          	pxor   xmm3,xmm3
    d34e:	66 0f ef e4          	pxor   xmm4,xmm4
    d352:	66 0f ef ed          	pxor   xmm5,xmm5
    d356:	66 0f ef f6          	pxor   xmm6,xmm6
    d35a:	66 0f ef ff          	pxor   xmm7,xmm7
    d35e:	45                   	rex.RB
    d35f:	31                   	.byte 0x31

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000000bcc0 <closefrom@@Base-0x2bb00>:
    bcc0:	ef                   	out    dx,eax
    bcc1:	ed                   	in     eax,dx
    bcc2:	66 45 0f ef f6       	pxor   xmm14,xmm14
    bcc7:	66 45 0f ef ff       	pxor   xmm15,xmm15
    bccc:	c3                   	ret    
    bccd:	b8 ff ff ff ff       	mov    eax,0xffffffff
    bcd2:	e9 c6 fe ff ff       	jmp    bb9d <getservbyname@plt+0x4d8d>
    bcd7:	66 0f 1f 84 00 00 00 	nop    WORD PTR [rax+rax*1+0x0]
    bcde:	00 00 
    bce0:	f3 0f 1e fa          	endbr64 
    bce4:	48 85 ff             	test   rdi,rdi
    bce7:	0f 84 c3 00 00 00    	je     bdb0 <getservbyname@plt+0x4fa0>
    bced:	55                   	push   rbp
    bcee:	48 89 fd             	mov    rbp,rdi
    bcf1:	e8 ea f7 ff ff       	call   b4e0 <getservbyname@plt+0x46d0>
    bcf6:	85 c0                	test   eax,eax
    bcf8:	75 36                	jne    bd30 <getservbyname@plt+0x4f20>
    bcfa:	83 6d 38 01          	sub    DWORD PTR [rbp+0x38],0x1
    bcfe:	75 30                	jne    bd30 <getservbyname@plt+0x4f20>
    bd00:	48 8b 7d 40          	mov    rdi,QWORD PTR [rbp+0x40]
    bd04:	e8 d7 ff ff ff       	call   bce0 <getservbyname@plt+0x4ed0>
    bd09:	8b 45 30             	mov    eax,DWORD PTR [rbp+0x30]
    bd0c:	48 c7 45 40 00 00 00 	mov    QWORD PTR [rbp+0x40],0x0
    bd13:	00 
    bd14:	85 c0                	test   eax,eax
    bd16:	0f 84 14 01 00 00    	je     be30 <getservbyname@plt+0x5020>
    bd1c:	48 89 ef             	mov    rdi,rbp
    bd1f:	be 48 00 00 00       	mov    esi,0x48
    bd24:	5d                   	pop    rbp
    bd25:	e9 a6 f3 02 00       	jmp    3b0d0 <closefrom@@Base+0x3910>
    bd2a:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    bd30:	5d                   	pop    rbp
    bd31:	d9 ee                	fldz   
    bd33:	d9 ee                	fldz   
    bd35:	d9 ee                	fldz   
    bd37:	d9 ee                	fldz   
    bd39:	d9 ee                	fldz   
    bd3b:	d9 ee                	fldz   
    bd3d:	d9 ee                	fldz   
    bd3f:	d9 ee                	fldz   
    bd41:	dd d8                	fstp   st(0)
    bd43:	dd d8                	fstp   st(0)
    bd45:	dd d8                	fstp   st(0)
    bd47:	dd d8                	fstp   st(0)
    bd49:	dd d8                	fstp   st(0)
    bd4b:	dd d8                	fstp   st(0)
    bd4d:	dd d8                	fstp   st(0)
    bd4f:	dd d8                	fstp   st(0)
    bd51:	31 c0                	xor    eax,eax
    bd53:	31 d2                	xor    edx,edx
    bd55:	31 c9                	xor    ecx,ecx
    bd57:	31 f6                	xor    esi,esi
    bd59:	31 ff                	xor    edi,edi
    bd5b:	66 0f ef c0          	pxor   xmm0,xmm0
    bd5f:	66 0f ef c9          	pxor   xmm1,xmm1
    bd63:	66 0f ef d2          	pxor   xmm2,xmm2
    bd67:	66 0f ef db          	pxor   xmm3,xmm3
    bd6b:	66 0f ef e4          	pxor   xmm4,xmm4
    bd6f:	66 0f ef ed          	pxor   xmm5,xmm5
    bd73:	66 0f ef f6          	pxor   xmm6,xmm6
    bd77:	66 0f ef ff          	pxor   xmm7,xmm7
    bd7b:	45 31 c0             	xor    r8d,r8d
    bd7e:	45 31 c9             	xor    r9d,r9d
    bd81:	45 31 d2             	xor    r10d,r10d
    bd84:	45 31 db             	xor    r11d,r11d
    bd87:	66 45 0f ef c0       	pxor   xmm8,xmm8
    bd8c:	66 45 0f ef c9       	pxor   xmm9,xmm9
    bd91:	66 45 0f ef d2       	pxor   xmm10,xmm10
    bd96:	66 45 0f ef db       	pxor   xmm11,xmm11
    bd9b:	66 45 0f ef e4       	pxor   xmm12,xmm12
    bda0:	66 45 0f ef ed       	pxor   xmm13,xmm13
    bda5:	66 45 0f ef f6       	pxor   xmm14,xmm14
    bdaa:	66 45 0f ef ff       	pxor   xmm15,xmm15
    bdaf:	c3                   	ret    
    bdb0:	d9 ee                	fldz   
    bdb2:	d9 ee                	fldz   
    bdb4:	d9 ee                	fldz   
    bdb6:	d9 ee                	fldz   
    bdb8:	d9 ee                	fldz   
    bdba:	d9 ee                	fldz   
    bdbc:	d9 ee                	fldz   
    bdbe:	d9 ee                	fldz   
    bdc0:	dd d8                	fstp   st(0)
    bdc2:	dd d8                	fstp   st(0)
    bdc4:	dd d8                	fstp   st(0)
    bdc6:	dd d8                	fstp   st(0)
    bdc8:	dd d8                	fstp   st(0)
    bdca:	dd d8                	fstp   st(0)
    bdcc:	dd d8                	fstp   st(0)
    bdce:	dd d8                	fstp   st(0)
    bdd0:	31 c0                	xor    eax,eax
    bdd2:	31 d2                	xor    edx,edx
    bdd4:	31 c9                	xor    ecx,ecx
    bdd6:	31 f6                	xor    esi,esi
    bdd8:	31 ff                	xor    edi,edi
    bdda:	66 0f ef c0          	pxor   xmm0,xmm0
    bdde:	66 0f ef c9          	pxor   xmm1,xmm1
    bde2:	66 0f ef d2          	pxor   xmm2,xmm2
    bde6:	66 0f ef db          	pxor   xmm3,xmm3
    bdea:	66 0f ef e4          	pxor   xmm4,xmm4
    bdee:	66 0f ef ed          	pxor   xmm5,xmm5
    bdf2:	66 0f ef f6          	pxor   xmm6,xmm6
    bdf6:	66 0f ef ff          	pxor   xmm7,xmm7
    bdfa:	45 31 c0             	xor    r8d,r8d
    bdfd:	45 31 c9             	xor    r9d,r9d
    be00:	45 31 d2             	xor    r10d,r10d
    be03:	45 31 db             	xor    r11d,r11d
    be06:	66 45 0f ef c0       	pxor   xmm8,xmm8
    be0b:	66 45 0f ef c9       	pxor   xmm9,xmm9
    be10:	66 45 0f ef d2       	pxor   xmm10,xmm10
    be15:	66 45 0f ef db       	pxor   xmm11,xmm11
    be1a:	66 45 0f ef e4       	pxor   xmm12,xmm12
    be1f:	66 45 0f ef ed       	pxor   xmm13,xmm13
    be24:	66 45 0f ef f6       	pxor   xmm14,xmm14
    be29:	66 45 0f ef ff       	pxor   xmm15,xmm15
    be2e:	c3                   	ret    
    be2f:	90                   	nop
    be30:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
    be34:	48 8b 75 28          	mov    rsi,QWORD PTR [rbp+0x28]
    be38:	48 c7 c2 ff ff ff ff 	mov    rdx,0xffffffffffffffff
    be3f:	e8 3c a9 ff ff       	call   6780 <__explicit_bzero_chk@plt>
    be44:	48 8b 7d 00          	mov    rdi,QWORD PTR [rbp+0x0]
    be48:	e8 63 a6 ff ff       	call   64b0 <free@plt>
    be4d:	e9 ca fe ff ff       	jmp    bd1c <getservbyname@plt+0x4f0c>
    be52:	66 66 2e 0f 1f 84 00 	data16 cs nop WORD PTR [rax+rax*1+0x0]
    be59:	00 00 00 00 
    be5d:	0f 1f 00             	nop    DWORD PTR [rax]
    be60:	f3 0f 1e fa          	endbr64 
    be64:	53                   	push   rbx
    be65:	8b 47 30             	mov    eax,DWORD PTR [rdi+0x30]
    be68:	48 89 fb             	mov    rbx,rdi
    be6b:	85 c0                	test   eax,eax
    be6d:	75 0a                	jne    be79 <getservbyname@plt+0x5069>
    be6f:	83 7f 38 01          	cmp    DWORD PTR [rdi+0x38],0x1
    be73:	0f 86 8f 00 00 00    	jbe    bf08 <getservbyname@plt+0x50f8>
    be79:	48 8b 43 18          	mov    rax,QWORD PTR [rbx+0x18]
    be7d:	48 89 43 10          	mov    QWORD PTR [rbx+0x10],rax
    be81:	5b                   	pop    rbx
    be82:	d9 ee                	fldz   
    be84:	d9 ee                	fldz   
    be86:	d9 ee                	fldz   
    be88:	d9 ee                	fldz   
    be8a:	d9 ee                	fldz   
    be8c:	d9 ee                	fldz   
    be8e:	d9 ee                	fldz   
    be90:	d9 ee                	fldz   
    be92:	dd d8                	fstp   st(0)
    be94:	dd d8                	fstp   st(0)
    be96:	dd d8                	fstp   st(0)
    be98:	dd d8                	fstp   st(0)
    be9a:	dd d8                	fstp   st(0)
    be9c:	dd d8                	fstp   st(0)
    be9e:	dd d8                	fstp   st(0)

./target.bin:     file format elf64-x86-64


Disassembly of section .text:

000000000000c3a0 <closefrom@@Base-0x2b420>:
    c3a0:	ef                   	out    dx,eax
    c3a1:	f6 66 45             	mul    BYTE PTR [rsi+0x45]
    c3a4:	0f ef ff             	pxor   mm7,mm7
    c3a7:	c3                   	ret    
    c3a8:	0f 1f 84 00 00 00 00 	nop    DWORD PTR [rax+rax*1+0x0]
    c3af:	00 
    c3b0:	41 bc cf ff ff ff    	mov    r12d,0xffffffcf
    c3b6:	e9 d0 fe ff ff       	jmp    c28b <getservbyname@plt+0x547b>
    c3bb:	41 bc fe ff ff ff    	mov    r12d,0xfffffffe
    c3c1:	e9 c5 fe ff ff       	jmp    c28b <getservbyname@plt+0x547b>
    c3c6:	66 2e 0f 1f 84 00 00 	cs nop WORD PTR [rax+rax*1+0x0]
    c3cd:	00 00 00 
    c3d0:	f3 0f 1e fa          	endbr64 
    c3d4:	53                   	push   rbx
    c3d5:	48 89 fb             	mov    rbx,rdi
    c3d8:	e8 03 f1 ff ff       	call   b4e0 <getservbyname@plt+0x46d0>
    c3dd:	41 89 c0             	mov    r8d,eax
    c3e0:	31 c0                	xor    eax,eax
    c3e2:	45 85 c0             	test   r8d,r8d
    c3e5:	75 08                	jne    c3ef <getservbyname@plt+0x55df>
    c3e7:	48 8b 43 18          	mov    rax,QWORD PTR [rbx+0x18]
    c3eb:	48 2b 43 10          	sub    rax,QWORD PTR [rbx+0x10]
    c3ef:	5b                   	pop    rbx
    c3f0:	d9 ee                	fldz   
    c3f2:	d9 ee                	fldz   
    c3f4:	d9 ee                	fldz   
    c3f6:	d9 ee                	fldz   
    c3f8:	d9 ee                	fldz   
    c3fa:	d9 ee                	fldz   
    c3fc:	d9 ee                	fldz   
    c3fe:	d9 ee                	fldz   
    c400:	dd d8                	fstp   st(0)
    c402:	dd d8                	fstp   st(0)
    c404:	dd d8                	fstp   st(0)
    c406:	dd d8                	fstp   st(0)
    c408:	dd d8                	fstp   st(0)
    c40a:	dd d8                	fstp   st(0)
    c40c:	dd d8                	fstp   st(0)
    c40e:	dd d8                	fstp   st(0)
    c410:	31 d2                	xor    edx,edx
    c412:	31 c9                	xor    ecx,ecx
    c414:	31 f6                	xor    esi,esi
    c416:	31 ff                	xor    edi,edi
    c418:	66 0f ef c0          	pxor   xmm0,xmm0
    c41c:	66 0f ef c9          	pxor   xmm1,xmm1
    c420:	66 0f ef d2          	pxor   xmm2,xmm2
    c424:	66 0f ef db          	pxor   xmm3,xmm3
    c428:	66 0f ef e4          	pxor   xmm4,xmm4
    c42c:	66 0f ef ed          	pxor   xmm5,xmm5
    c430:	66 0f ef f6          	pxor   xmm6,xmm6
    c434:	66 0f ef ff          	pxor   xmm7,xmm7
    c438:	45 31 c0             	xor    r8d,r8d
    c43b:	45 31 c9             	xor    r9d,r9d
    c43e:	45 31 d2             	xor    r10d,r10d
    c441:	45 31 db             	xor    r11d,r11d
    c444:	66 45 0f ef c0       	pxor   xmm8,xmm8
    c449:	66 45 0f ef c9       	pxor   xmm9,xmm9
    c44e:	66 45 0f ef d2       	pxor   xmm10,xmm10
    c453:	66 45 0f ef db       	pxor   xmm11,xmm11
    c458:	66 45 0f ef e4       	pxor   xmm12,xmm12
    c45d:	66 45 0f ef ed       	pxor   xmm13,xmm13
    c462:	66 45 0f ef f6       	pxor   xmm14,xmm14
    c467:	66 45 0f ef ff       	pxor   xmm15,xmm15
    c46c:	c3                   	ret    
    c46d:	0f 1f 00             	nop    DWORD PTR [rax]
    c470:	f3 0f 1e fa          	endbr64 
    c474:	53                   	push   rbx
    c475:	48 89 fb             	mov    rbx,rdi
    c478:	e8 63 f0 ff ff       	call   b4e0 <getservbyname@plt+0x46d0>
    c47d:	41 89 c0             	mov    r8d,eax
    c480:	31 c0                	xor    eax,eax
    c482:	45 85 c0             	test   r8d,r8d
    c485:	75 19                	jne    c4a0 <getservbyname@plt+0x5690>
    c487:	8b 53 30             	mov    edx,DWORD PTR [rbx+0x30]
    c48a:	85 d2                	test   edx,edx
    c48c:	75 12                	jne    c4a0 <getservbyname@plt+0x5690>
    c48e:	83 7b 38 01          	cmp    DWORD PTR [rbx+0x38],0x1
    c492:	77 0c                	ja     c4a0 <getservbyname@plt+0x5690>
    c494:	48 8b 43 10          	mov    rax,QWORD PTR [rbx+0x10]
    c498:	48 03 43 20          	add    rax,QWORD PTR [rbx+0x20]
    c49c:	48 2b 43 18          	sub    rax,QWORD PTR [rbx+0x18]
    c4a0:	5b                   	pop    rbx
    c4a1:	d9 ee                	fldz   
    c4a3:	d9 ee                	fldz   
    c4a5:	d9 ee                	fldz   
    c4a7:	d9 ee                	fldz   
    c4a9:	d9 ee                	fldz   
    c4ab:	d9 ee                	fldz   
    c4ad:	d9 ee                	fldz   
    c4af:	d9 ee                	fldz   
    c4b1:	dd d8                	fstp   st(0)
    c4b3:	dd d8                	fstp   st(0)
    c4b5:	dd d8                	fstp   st(0)
    c4b7:	dd d8                	fstp   st(0)
    c4b9:	dd d8                	fstp   st(0)
    c4bb:	dd d8                	fstp   st(0)
    c4bd:	dd d8                	fstp   st(0)
    c4bf:	dd d8                	fstp   st(0)
    c4c1:	31 d2                	xor    edx,edx
    c4c3:	31 c9                	xor    ecx,ecx
    c4c5:	31 f6                	xor    esi,esi
    c4c7:	31 ff                	xor    edi,edi
    c4c9:	66 0f ef c0          	pxor   xmm0,xmm0
    c4cd:	66 0f ef c9          	pxor   xmm1,xmm1
    c4d1:	66 0f ef d2          	pxor   xmm2,xmm2
    c4d5:	66 0f ef db          	pxor   xmm3,xmm3
    c4d9:	66 0f ef e4          	pxor   xmm4,xmm4
    c4dd:	66 0f ef ed          	pxor   xmm5,xmm5
    c4e1:	66 0f ef f6          	pxor   xmm6,xmm6
    c4e5:	66 0f ef ff          	pxor   xmm7,xmm7
    c4e9:	45 31 c0             	xor    r8d,r8d
    c4ec:	45 31 c9             	xor    r9d,r9d
    c4ef:	45 31 d2             	xor    r10d,r10d
    c4f2:	45 31 db             	xor    r11d,r11d
    c4f5:	66 45 0f ef c0       	pxor   xmm8,xmm8
    c4fa:	66 45 0f ef c9       	pxor   xmm9,xmm9
    c4ff:	66 45 0f ef d2       	pxor   xmm10,xmm10
    c504:	66 45 0f ef db       	pxor   xmm11,xmm11
    c509:	66 45 0f ef e4       	pxor   xmm12,xmm12
    c50e:	66 45 0f ef ed       	pxor   xmm13,xmm13
    c513:	66 45 0f ef f6       	pxor   xmm14,xmm14
    c518:	66 45 0f ef ff       	pxor   xmm15,xmm15
    c51d:	c3                   	ret    
    c51e:	66 90                	xchg   ax,ax
    c520:	f3 0f 1e fa          	endbr64 
    c524:	53                   	push   rbx
    c525:	48 89 fb             	mov    rbx,rdi
    c528:	e8 b3 ef ff ff       	call   b4e0 <getservbyname@plt+0x46d0>
    c52d:	85 c0                	test   eax,eax
    c52f:	0f 85 8b 00 00 00    	jne    c5c0 <getservbyname@plt+0x57b0>
    c535:	48 8b 43 10          	mov    rax,QWORD PTR [rbx+0x10]
    c539:	48 03 43 08          	add    rax,QWORD PTR [rbx+0x8]
    c53d:	5b                   	pop    rbx
    c53e:	d9 ee                	fldz   
    c540:	d9 ee                	fldz   
    c542:	d9 ee                	fldz   
    c544:	d9 ee                	fldz   
    c546:	d9 ee                	fldz   
    c548:	d9 ee                	fldz   
    c54a:	d9 ee                	fldz   
    c54c:	d9 ee                	fldz   
    c54e:	dd d8                	fstp   st(0)

codex
The call graph confirms this is OpenSSH certificate parsing logic: it consumes the certificate fields from an `sshbuf`, builds principal/option buffers, parses and validates the CA key, verifies the signed prefix, records the signature type, and funnels allocations through the observed cleanup paths. I’m encoding those recovered types and exact error branches now.
apply patch
patch: completed
/tmp/llmdec_codex_s6m_4ok7/decompiled.c
diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..acca76423bc4cf493c74d0f8d68b061d9bf931a7
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,160 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **new_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		new_principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (new_principals == NULL) {
+			free(principal);
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals = new_principals;
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..acca76423bc4cf493c74d0f8d68b061d9bf931a7
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,160 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **new_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		new_principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (new_principals == NULL) {
+			free(principal);
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals = new_principals;
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

exec
/bin/bash -lc "sed -n '1,260p' decompiled.c; gcc -std=c11 -Wall -Wextra -Werror -fsyntax-only decompiled.c; rg -n \""'^[A-Za-z_].*'"\\(["'^;]*$|''^sub_14ea0" decompiled.c' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct sshbuf;
struct sshkey;

struct sshkey_cert {
	struct sshbuf *certblob;
	uint32_t type;
	uint64_t serial;
	char *key_id;
	unsigned int nprincipals;
	char **principals;
	uint64_t valid_after;
	uint64_t valid_before;
	struct sshbuf *critical;
	struct sshbuf *extensions;
	struct sshkey *signature_key;
	char *signature_type;
};

struct sshkey {
	int type;
	unsigned char opaque[124];
	struct sshkey_cert *cert;
};

enum {
	SSH_ERR_ALLOC_FAIL = -2,
	SSH_ERR_INVALID_FORMAT = -4,
	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
	SSH_ERR_KEY_CERT_INVALID = -19,
	SSH2_CERT_TYPE_USER = 1,
	SSH2_CERT_TYPE_HOST = 2,
	SSHKEY_CERT_MAX_PRINCIPALS = 256
};

extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
extern size_t sshbuf_len(const struct sshbuf *);
extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);
extern void *recallocarray(void *, size_t, size_t, size_t);
extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
extern int sshkey_type_is_valid_ca(int);
extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
    const unsigned char *, size_t, const char *, unsigned int, void **);
extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);

int
sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
{
	struct sshbuf *principals = NULL, *critical = NULL;
	struct sshbuf *extensions = NULL, *ca = NULL;
	unsigned char *sig = NULL;
	char *principal = NULL;
	char **new_principals;
	size_t key_id_len = 0, siglen = 0, signed_len;
	int ret;

	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
		return ret;

	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
	    sshbuf_froms(b, &principals) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
	    sshbuf_froms(b, &critical) != 0 ||
	    sshbuf_froms(b, &extensions) != 0 ||
	    sshbuf_get_string(b, NULL, NULL) != 0 ||
	    sshbuf_froms(b, &ca) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	if (key->cert->type != SSH2_CERT_TYPE_USER &&
	    key->cert->type != SSH2_CERT_TYPE_HOST) {
		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
		goto out;
	}

	while (sshbuf_len(principals) != 0) {
		principal = NULL;
		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
		new_principals = recallocarray(key->cert->principals,
		    key->cert->nprincipals, key->cert->nprincipals + 1,
		    sizeof(*key->cert->principals));
		if (new_principals == NULL) {
			free(principal);
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		key->cert->principals = new_principals;
		key->cert->principals[key->cert->nprincipals++] = principal;
		principal = NULL;
	}

	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
		goto out;
	if (extensions != NULL &&
	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
		goto out;

	while (sshbuf_len(critical) != 0) {
		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
		    sshbuf_get_string(critical, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->critical);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	while (extensions != NULL && sshbuf_len(extensions) != 0) {
		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->extensions);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
		ret = SSH_ERR_KEY_CERT_INVALID;
		goto out;
	}

	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
	if (ret != 0)
		goto out;

	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);

out:
	sshbuf_free(ca);
	sshbuf_free(critical);
	sshbuf_free(extensions);
	sshbuf_free(principals);
	free(sig);
	return ret;
}
52:extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
57:sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)

diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..acca76423bc4cf493c74d0f8d68b061d9bf931a7
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,160 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **new_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		new_principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (new_principals == NULL) {
+			free(principal);
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals = new_principals;
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

exec
/bin/bash -lc 'strings -a -t x ./target.bin | rg -n "certificate|cert|signing key|unknown certificate|invalid.*key" | head -n 100; objdump -s --start-address=0x3e8d0 --stop-address=0x3ec00 ./target.bin' in /tmp/llmdec_codex_s6m_4ok7
 succeeded in 0ms:
1890:  3e698 Authenticator returned invalid ECDSA key
1921:  3ea1b key lacks certificate data
1925:  3ea7a invalid certificate
1949:  3ec80 plain key provided where certificate required
1950:  3ecb0 unknown/unsupported certificate type
1951:  3ecd8 invalid certificate signing key
1963:  3eeb0 certificate does not match key
1975:  3f0ac ssh-rsa-cert-v01@openssh.com
1981:  3f0f5 Key is not a certificate
2005:  3f24d ssh-dss-cert-v01@openssh.com
2010:  3f2d8 rsa-sha2-256-cert-v01@openssh.com
2011:  3f300 rsa-sha2-512-cert-v01@openssh.com
2012:  3f328 Certificate invalid: not a host certificate
2013:  3f358 Certificate invalid: not a user certificate
2021:  3f4c8 ssh-ed25519-cert-v01@openssh.com
2022:  3f4f0 sk-ssh-ed25519-cert-v01@openssh.com
2025:  3f570 ecdsa-sha2-nistp256-cert-v01@openssh.com
2026:  3f5a0 ecdsa-sha2-nistp384-cert-v01@openssh.com
2027:  3f5d0 ecdsa-sha2-nistp521-cert-v01@openssh.com
2028:  3f600 sk-ecdsa-sha2-nistp256-cert-v01@openssh.com

./target.bin:     file format elf64-x86-64

Contents of section .rodata:
 3e8d0 73736873 6b5f6164 645f6f70 74696f6e  sshsk_add_option
 3e8e0 00000000 00000000 73736873 6b5f656e  ........sshsk_en
 3e8f0 726f6c6c 00737563 63657373 00756e65  roll.success.une
 3e900 78706563 74656420 696e7465 726e616c  xpected internal
 3e910 20657272 6f72006d 656d6f72 7920616c   error.memory al
 3e920 6c6f6361 74696f6e 20666169 6c656400  location failed.
 3e930 696e636f 6d706c65 7465206d 65737361  incomplete messa
 3e940 67650069 6e76616c 69642066 6f726d61  ge.invalid forma
 3e950 74006269 676e756d 20697320 6e656761  t.bignum is nega
 3e960 74697665 00737472 696e6720 69732074  tive.string is t
 3e970 6f6f206c 61726765 00626967 6e756d20  oo large.bignum 
 3e980 69732074 6f6f206c 61726765 00696e73  is too large.ins
 3e990 75666669 6369656e 74206275 66666572  ufficient buffer
 3e9a0 20737061 63650069 6e76616c 69642061   space.invalid a
 3e9b0 7267756d 656e7400 6b657920 62697473  rgument.key bits
 3e9c0 20646f20 6e6f7420 6d617463 6800696e   do not match.in
 3e9d0 76616c69 6420656c 6c697074 69632063  valid elliptic c
 3e9e0 75727665 006b6579 20747970 6520646f  urve.key type do
 3e9f0 6573206e 6f74206d 61746368 00656c6c  es not match.ell
 3ea00 69707469 63206375 72766520 646f6573  iptic curve does
 3ea10 206e6f74 206d6174 6368006b 6579206c   not match.key l
 3ea20 61636b73 20636572 74696669 63617465  acks certificate
 3ea30 20646174 6100696e 76616c69 6420656c   data.invalid el
 3ea40 6c697074 69632063 75727665 2076616c  liptic curve val
 3ea50 75650069 6e636f72 72656374 20736967  ue.incorrect sig
 3ea60 6e617475 72650065 72726f72 20696e20  nature.error in 
 3ea70 6c696263 72797074 6f00696e 76616c69  libcrypto.invali
 3ea80 64206365 72746966 69636174 65006167  d certificate.ag
 3ea90 656e7420 72656675 73656420 6f706572  ent refused oper
 3eaa0 6174696f 6e004448 20474558 2067726f  ation.DH GEX gro
 3eab0 7570206f 7574206f 66207261 6e676500  up out of range.
 3eac0 64697363 6f6e6e65 63746564 006e6f20  disconnected.no 
 3ead0 6d617463 68696e67 20636970 68657220  matching cipher 
 3eae0 666f756e 64006e6f 206d6174 6368696e  found.no matchin
 3eaf0 67204d41 4320666f 756e6400 70726f74  g MAC found.prot
 3eb00 6f636f6c 20766572 73696f6e 206d6973  ocol version mis
 3eb10 6d617463 6800636f 756c6420 6e6f7420  match.could not 
 3eb20 6c6f6164 20686f73 74206b65 79006669  load host key.fi
 3eb30 6c652063 68616e67 65642077 68696c65  le changed while
 3eb40 20726561 64696e67 00626164 20706572   reading.bad per
 3eb50 6d697373 696f6e73 006b6579 206e6f74  missions.key not
 3eb60 20666f75 6e640061 67656e74 206e6f74   found.agent not
 3eb70 20707265 73656e74 00616765 6e742063   present.agent c
 3eb80 6f6e7461 696e7320 6e6f2069 64656e74  ontains no ident
 3eb90 69746965 73004b65 79206973 20726576  ities.Key is rev
 3eba0 6f6b6564 00436f6e 6e656374 696f6e20  oked.Connection 
 3ebb0 636c6f73 65640043 6f6e6e65 6374696f  closed.Connectio
 3ebc0 6e207469 6d656420 6f757400 436f6e6e  n timed out.Conn
 3ebd0 65637469 6f6e2063 6f727275 70746564  ection corrupted
 3ebe0 0050726f 746f636f 6c206572 726f7200  .Protocol error.
 3ebf0 496e7661 6c696420 6b657920 6c656e67  Invalid key leng

diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..acca76423bc4cf493c74d0f8d68b061d9bf931a7
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,160 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **new_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		new_principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (new_principals == NULL) {
+			free(principal);
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals = new_principals;
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

apply patch
patch: completed
/tmp/llmdec_codex_s6m_4ok7/decompiled.c
diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..24a97be07bf4ae4cebc861ecd06d891a0fd022ad
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,161 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID_SIGN_KEY = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **old_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		old_principals = key->cert->principals;
+		key->cert->principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (key->cert->principals == NULL) {
+			free(principal);
+			key->cert->principals = old_principals;
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..24a97be07bf4ae4cebc861ecd06d891a0fd022ad
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,161 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID_SIGN_KEY = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **old_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		old_principals = key->cert->principals;
+		key->cert->principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (key->cert->principals == NULL) {
+			free(principal);
+			key->cert->principals = old_principals;
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

codex
Created [decompiled.c](/tmp/llmdec_codex_s6m_4ok7/decompiled.c) with the reconstructed `sub_14ea0` function.
diff --git a/llmdec_codex_s6m_4ok7/decompiled.c b/llmdec_codex_s6m_4ok7/decompiled.c
new file mode 100644
index 0000000000000000000000000000000000000000..24a97be07bf4ae4cebc861ecd06d891a0fd022ad
--- /dev/null
+++ b/llmdec_codex_s6m_4ok7/decompiled.c
@@ -0,0 +1,161 @@
+#include <stddef.h>
+#include <stdint.h>
+#include <stdlib.h>
+
+struct sshbuf;
+struct sshkey;
+
+struct sshkey_cert {
+	struct sshbuf *certblob;
+	uint32_t type;
+	uint64_t serial;
+	char *key_id;
+	unsigned int nprincipals;
+	char **principals;
+	uint64_t valid_after;
+	uint64_t valid_before;
+	struct sshbuf *critical;
+	struct sshbuf *extensions;
+	struct sshkey *signature_key;
+	char *signature_type;
+};
+
+struct sshkey {
+	int type;
+	unsigned char opaque[124];
+	struct sshkey_cert *cert;
+};
+
+enum {
+	SSH_ERR_ALLOC_FAIL = -2,
+	SSH_ERR_INVALID_FORMAT = -4,
+	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
+	SSH_ERR_KEY_CERT_INVALID_SIGN_KEY = -19,
+	SSH2_CERT_TYPE_USER = 1,
+	SSH2_CERT_TYPE_HOST = 2,
+	SSHKEY_CERT_MAX_PRINCIPALS = 256
+};
+
+extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
+extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
+extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
+extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
+extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
+extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
+extern size_t sshbuf_len(const struct sshbuf *);
+extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
+extern void sshbuf_free(struct sshbuf *);
+extern void sshbuf_reset(struct sshbuf *);
+extern void *recallocarray(void *, size_t, size_t, size_t);
+extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
+extern int sshkey_type_is_valid_ca(int);
+extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
+    const unsigned char *, size_t, const char *, unsigned int, void **);
+extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);
+
+int
+sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
+{
+	struct sshbuf *principals = NULL, *critical = NULL;
+	struct sshbuf *extensions = NULL, *ca = NULL;
+	unsigned char *sig = NULL;
+	char *principal = NULL;
+	char **old_principals;
+	size_t key_id_len = 0, siglen = 0, signed_len;
+	int ret;
+
+	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
+		return ret;
+
+	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
+	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
+	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
+	    sshbuf_froms(b, &principals) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
+	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
+	    sshbuf_froms(b, &critical) != 0 ||
+	    sshbuf_froms(b, &extensions) != 0 ||
+	    sshbuf_get_string(b, NULL, NULL) != 0 ||
+	    sshbuf_froms(b, &ca) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
+	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
+		ret = SSH_ERR_INVALID_FORMAT;
+		goto out;
+	}
+
+	if (key->cert->type != SSH2_CERT_TYPE_USER &&
+	    key->cert->type != SSH2_CERT_TYPE_HOST) {
+		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
+		goto out;
+	}
+
+	while (sshbuf_len(principals) != 0) {
+		principal = NULL;
+		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
+		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+		old_principals = key->cert->principals;
+		key->cert->principals = recallocarray(key->cert->principals,
+		    key->cert->nprincipals, key->cert->nprincipals + 1,
+		    sizeof(*key->cert->principals));
+		if (key->cert->principals == NULL) {
+			free(principal);
+			key->cert->principals = old_principals;
+			ret = SSH_ERR_ALLOC_FAIL;
+			goto out;
+		}
+		key->cert->principals[key->cert->nprincipals++] = principal;
+		principal = NULL;
+	}
+
+	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
+		goto out;
+	if (extensions != NULL &&
+	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
+		goto out;
+
+	while (sshbuf_len(critical) != 0) {
+		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
+		    sshbuf_get_string(critical, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->critical);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	while (extensions != NULL && sshbuf_len(extensions) != 0) {
+		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
+		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
+			sshbuf_reset(key->cert->extensions);
+			ret = SSH_ERR_INVALID_FORMAT;
+			goto out;
+		}
+	}
+
+	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
+	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
+		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
+		goto out;
+	}
+
+	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
+	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
+	if (ret != 0)
+		goto out;
+
+	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);
+
+out:
+	sshbuf_free(ca);
+	sshbuf_free(critical);
+	sshbuf_free(extensions);
+	sshbuf_free(principals);
+	free(sig);
+	return ret;
+}

tokens used
113,606
```

## Reconstructed C

```c
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

struct sshbuf;
struct sshkey;

struct sshkey_cert {
	struct sshbuf *certblob;
	uint32_t type;
	uint64_t serial;
	char *key_id;
	unsigned int nprincipals;
	char **principals;
	uint64_t valid_after;
	uint64_t valid_before;
	struct sshbuf *critical;
	struct sshbuf *extensions;
	struct sshkey *signature_key;
	char *signature_type;
};

struct sshkey {
	int type;
	unsigned char opaque[124];
	struct sshkey_cert *cert;
};

enum {
	SSH_ERR_ALLOC_FAIL = -2,
	SSH_ERR_INVALID_FORMAT = -4,
	SSH_ERR_KEY_CERT_UNKNOWN_TYPE = -18,
	SSH_ERR_KEY_CERT_INVALID_SIGN_KEY = -19,
	SSH2_CERT_TYPE_USER = 1,
	SSH2_CERT_TYPE_HOST = 2,
	SSHKEY_CERT_MAX_PRINCIPALS = 256
};

extern int sshbuf_putb(struct sshbuf *, const struct sshbuf *);
extern int sshbuf_get_u64(struct sshbuf *, uint64_t *);
extern int sshbuf_get_u32(struct sshbuf *, uint32_t *);
extern int sshbuf_get_cstring(struct sshbuf *, char **, size_t *);
extern int sshbuf_get_string(struct sshbuf *, unsigned char **, size_t *);
extern int sshbuf_froms(struct sshbuf *, struct sshbuf **);
extern size_t sshbuf_len(const struct sshbuf *);
extern const unsigned char *sshbuf_ptr(const struct sshbuf *);
extern void sshbuf_free(struct sshbuf *);
extern void sshbuf_reset(struct sshbuf *);
extern void *recallocarray(void *, size_t, size_t, size_t);
extern int sshkey_from_blob_internal(struct sshbuf *, struct sshkey **, int);
extern int sshkey_type_is_valid_ca(int);
extern int sshkey_verify(const struct sshkey *, const unsigned char *, size_t,
    const unsigned char *, size_t, const char *, unsigned int, void **);
extern int sshkey_get_sigtype(const unsigned char *, size_t, char **);

int
sub_14ea0(struct sshbuf *b, struct sshkey *key, const struct sshbuf *certbuf)
{
	struct sshbuf *principals = NULL, *critical = NULL;
	struct sshbuf *extensions = NULL, *ca = NULL;
	unsigned char *sig = NULL;
	char *principal = NULL;
	char **old_principals;
	size_t key_id_len = 0, siglen = 0, signed_len;
	int ret;

	if ((ret = sshbuf_putb(key->cert->certblob, certbuf)) != 0)
		return ret;

	if (sshbuf_get_u64(b, &key->cert->serial) != 0 ||
	    sshbuf_get_u32(b, &key->cert->type) != 0 ||
	    sshbuf_get_cstring(b, &key->cert->key_id, &key_id_len) != 0 ||
	    sshbuf_froms(b, &principals) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_after) != 0 ||
	    sshbuf_get_u64(b, &key->cert->valid_before) != 0 ||
	    sshbuf_froms(b, &critical) != 0 ||
	    sshbuf_froms(b, &extensions) != 0 ||
	    sshbuf_get_string(b, NULL, NULL) != 0 ||
	    sshbuf_froms(b, &ca) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	signed_len = sshbuf_len(key->cert->certblob) - sshbuf_len(b);
	if (sshbuf_get_string(b, &sig, &siglen) != 0) {
		ret = SSH_ERR_INVALID_FORMAT;
		goto out;
	}

	if (key->cert->type != SSH2_CERT_TYPE_USER &&
	    key->cert->type != SSH2_CERT_TYPE_HOST) {
		ret = SSH_ERR_KEY_CERT_UNKNOWN_TYPE;
		goto out;
	}

	while (sshbuf_len(principals) != 0) {
		principal = NULL;
		if (key->cert->nprincipals >= SSHKEY_CERT_MAX_PRINCIPALS ||
		    sshbuf_get_cstring(principals, &principal, NULL) != 0) {
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
		old_principals = key->cert->principals;
		key->cert->principals = recallocarray(key->cert->principals,
		    key->cert->nprincipals, key->cert->nprincipals + 1,
		    sizeof(*key->cert->principals));
		if (key->cert->principals == NULL) {
			free(principal);
			key->cert->principals = old_principals;
			ret = SSH_ERR_ALLOC_FAIL;
			goto out;
		}
		key->cert->principals[key->cert->nprincipals++] = principal;
		principal = NULL;
	}

	if ((ret = sshbuf_putb(key->cert->critical, critical)) != 0)
		goto out;
	if (extensions != NULL &&
	    (ret = sshbuf_putb(key->cert->extensions, extensions)) != 0)
		goto out;

	while (sshbuf_len(critical) != 0) {
		if (sshbuf_get_string(critical, NULL, NULL) != 0 ||
		    sshbuf_get_string(critical, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->critical);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	while (extensions != NULL && sshbuf_len(extensions) != 0) {
		if (sshbuf_get_string(extensions, NULL, NULL) != 0 ||
		    sshbuf_get_string(extensions, NULL, NULL) != 0) {
			sshbuf_reset(key->cert->extensions);
			ret = SSH_ERR_INVALID_FORMAT;
			goto out;
		}
	}

	if (sshkey_from_blob_internal(ca, &key->cert->signature_key, 0) != 0 ||
	    !sshkey_type_is_valid_ca(key->cert->signature_key->type)) {
		ret = SSH_ERR_KEY_CERT_INVALID_SIGN_KEY;
		goto out;
	}

	ret = sshkey_verify(key->cert->signature_key, sig, siglen,
	    sshbuf_ptr(key->cert->certblob), signed_len, NULL, 0, NULL);
	if (ret != 0)
		goto out;

	ret = sshkey_get_sigtype(sig, siglen, &key->cert->signature_type);

out:
	sshbuf_free(ca);
	sshbuf_free(critical);
	sshbuf_free(extensions);
	sshbuf_free(principals);
	free(sig);
	return ret;
}

```
