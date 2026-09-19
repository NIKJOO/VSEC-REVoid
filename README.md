# VSEC-REVoid

**Advanced Code Obfuscation Engine powered by Clang AST Analysis**

> **⚠️ DEMO / LIMITED EDITION — Beta 1.0**  
> This is a **restricted demonstration build**. Many features are intentionally limited or incomplete.  
> Please report any bugs, crashes, incorrect behavior, or missing capabilities so the project can be finalized.  
> Once the tool reaches a stable and complete state, the full source code will be released publicly.

---

## Overview

**VSEC-REVoid** transforms selected C/C++ functions into a highly polymorphic, unique-per-function virtual machine.  
Each virtualized function receives its own independent:

- Seed & opcode mapping  
- Handler encryption keys  
- Dispatcher topology  
- Junk code & nested arithmetic bodies  
- State IDs and control-flow layout  

The result is a strongly obfuscated binary that is extremely difficult to reverse-engineer using conventional static or dynamic analysis.

---

## Key Obfuscation Features

### Core Virtualization
- **Unique Per-Function Polymorphic VM**  
  Every function marked for virtualization gets a completely different VM instance (seed, opcode table, handler layout, encryption).

- **Virtualized Control Flow**  
  Original control flow is completely replaced by a custom bytecode interpreter with multi-layer state machines.

### Control-Flow Obfuscation
- Multi-thread decoy state machines  
- Thread-based control-flow noise  
- Bogus Control Flow (BCF)  
- Control-flow splitting & merging  
- Indirect state selection  
- Opaque predicates (including context-sensitive / history-dependent predicates)  
- Fake jump injection with randomized topology  
- Nested mini-VMs  

### Code & Data Protection
- Multi-layer code encryption  
- Handler encryption + chaining  
- Opcode remapping  
- Instruction substitution (MBA / nested arithmetic)  
- Segmented live bytecode window (dual-segment unlock / far segments locked)  
- Pointer encode / decode  
- Stack-frame obfuscation  
- VM state splitting  

### Anti-Analysis & Runtime Defenses
- Runtime attestation  
- Self-integrity checks  
- Checksum-based control flow  
- Anti-emulation timing checks  
- Time-based soft gates  
- Trigger mutation  
- Runtime key material generation  
- Data-dependent handler salt (path + runtime key mixed, semantics-preserving)  

### Hybrid Native + VM Execution
- Intelligent instruction-level native fallback  
- Seamless marshalling of complex C++ constructs (classes, STL, virtual methods, strings, registry, file I/O)  
- Pure arithmetic and control flow stay inside the unique VM  
- Complex operations are cleanly handed off to native thunks without breaking the virtualized context  

### Metamorphic Engine
- MBA junk insertion  
- Opaque control-flow generation  
- Dead code injection inside the dispatcher and fake jumps  
- Polymorphic / metamorphic handler bodies  

---

## Current Status (Demo Limitations)

This release is a **limited demo**. The following points apply:

- Only a restricted set of features is fully enabled  
- Some advanced options and full multi-function virtualization modes are disabled or simplified  
- The tool currently focuses primarily on virtualizing `main` (legacy `-f` flags are accepted but ignored)  
- Generated code is randomized on every run  
- Not all edge cases of modern C++ are guaranteed to be handled perfectly  

**Please report every issue you encounter.**  
Your feedback is essential to complete the project.

---

## Reporting Bugs & Feedback

If you find:
- Crashes  
- Incorrect program behavior after obfuscation  
- Unsupported language constructs that should work  
- Performance problems  
- Any other unexpected behavior  

…please open an issue with:
1. Minimal reproducible sample  
2. Exact command line used  
3. Compiler version and environment  
4. Observed vs expected behavior  

All reports will be used to harden and complete the final public version.

---

## Future Plans

- Full multi-function selective virtualization  
- Expanded language support and hybrid coverage  
- Additional anti-analysis layers  
- Configuration system for strength vs performance trade-offs  
- **Public release of the complete source code** once the project reaches production quality  

---

## Disclaimer

This is experimental software provided for research and evaluation purposes only.  
Use at your own risk. The authors are not responsible for any damage or misuse.

---

**VSEC-REVoid** — Making reverse engineering painful, one polymorphic VM at a time.
