# x86


# x86-64

**Name:** System V
**Arguments:** rdi, rsi, rdx, rcx, r8, r9 and stack RTL for additional arguments
**Scratch Registers:** rax, rcx, rdx, rsi, rdi, r8 - r11
**Preserved Registers:** rbx, rsp, rbp, r12 - r15
**Return Value:** rax, rdx
**Stack Alignment:** 16 bytes
**Stack Cleanup:** caller
**Used By:** GCC - Linux
**Remarks:** the Linux kernel uses registers rdi, rsi, rdx, r10, r8, r9 for arguments

---

**Name:** Microsoft x64 ([doc](https://docs.microsoft.com/en-us/cpp/build/calling-convention))
**Arguments:** rcx/xmm0 ,rdx/xmm1 ,r8/xmm2 ,r9/xmm3 and stack RTL for additional arguments
**Scratch Registers:** rax, rcx, rdx, r8, - r11
**Preserved Registers:** rbx, rsp, rbp, rdi, rsi, r12 - r15
**Return Value:** rax/xmm0
**Stack Alignment:** 16 bytes, 32 bytes shadow space on stack
**Stack Cleanup:** caller
**Used By:** Windows, UEFI
