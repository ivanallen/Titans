// x64 系统调用表
// https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
// https://filippo.io/linux-syscall-table/

// x86 系统调用表
// https://syscalls.kernelgrok.com/
// https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux

// How to invoke system call in inline assembly?
// https://stackoverflow.com/questions/9506353/how-to-invoke-a-system-call-via-sysenter-in-inline-assembly

// how to use sysenter under linux
// https://reverseengineering.stackexchange.com/questions/2869/how-to-use-sysenter-under-linux

// Pre-defined Compiler Macros
// https://sourceforge.net/p/predef/wiki/Architectures/
#include <stdio.h>

int main() {
    char x[] = "Hello world\n";

#if defined(__i386__)
    __asm("movl $4, %%eax\n"
            "movl $1, %%ebx\n"
            "movl %0, %%ecx\n"
            "movl $12, %%edx\n"
            "int $0x80"::"r"(x):"%eax", "%ebx", "%ecx", "%edx");
#elif defined(__x86_x64__) || defined(__amd64__)
    __asm__ ("movq $1, %%rax;\n"
            "movq $1, %%rdi;\n"
            "movq %0, %%rsi;\n"
            "movq $12, %%rdx;\n"
            "syscall"::"r"(x):"%rax","%rdi","%rsi","%rdx");
#else
    printf("Unsupported Platform\n");
#endif
    return 0;
}
