# x86 Disassembler (in C)
 
A minimal x86-64 disassembler built from scratch in C — no external libraries, no disassembly frameworks. The goal is to understand how compiled code is actually structured at the byte level, one step at a time.
 
## What it does
 
- Reads raw bytes directly from a file (including real compiled `.exe` files)
- Matches recognized byte values against a table of common x86-64 opcodes
- Decodes multi-byte instructions (e.g. `mov eax, imm32`), correctly reconstructing little-endian operand values
- Prints a human-readable disassembly of what it finds
## Progress so far
 
- **Step 1** — Raw file I/O: reading a file byte-by-byte and printing hex values
- **Step 2** — Single-byte opcode matching (`push rbp`, `pop rbp`, `ret`, `nop`, `call`, `jmp`, `int3`)
- **Step 3** — Multi-byte instruction decoding (`mov eax, imm32`), including little-endian byte reconstruction
- **Step 4** — Tested against a real compiled binary (`notepad.exe`) instead of hand-built test files
## A real limitation discovered along the way
 
Running this against real compiled code (Step 4) surfaced a genuine, well-known problem in naive disassembly: **this project uses a linear sweep approach** — it reads every byte in a straight line and checks it against the opcode table, with no awareness of whether that byte is actually part of an instruction or just incidental data.
 
This produces false positives. For example, a byte matching `0xB8` (`mov eax, imm32`) might actually just be a random byte sitting inside unrelated data or padding, not a real instruction at all — but linear sweep has no way to tell the difference, so it decodes it anyway.
 
Real disassemblers solve this with **recursive descent** — instead of blindly reading every byte in sequence, they start at known code entry points and only follow actual control flow (jumps, calls, branches), so they never mistake data for instructions. Implementing that properly requires understanding executable file formats (like PE headers on Windows) and control flow analysis — a natural next milestone for this project, not yet built.
 
This isn't a bug so much as a documented, inherent limitation of the linear sweep technique — and hitting it firsthand was a genuinely useful part of learning how real disassemblers are designed.
 
## Why this project exists
 
I'm a game developer working primarily in Unreal Engine Blueprints, currently learning C/C++ and low-level systems from first principles. This project is part of that — understanding x86 assembly, memory layout, and reverse engineering fundamentals by building the tools myself rather than just using existing ones.
 
## Built with
 
Plain C, compiled with MSVC (`cl`). No external dependencies.
