#include <stdio.h>

int main() {
    char x[] = "zhm\n";

#if defined(__i386__)
    __asm("movl $4, %%eax\n"
            "movl $1, %%ebx\n"
            "movl %0, %%ecx\n"
            "movl $4, %%edx\n"
            "int $0x80"::"r"(x):"%eax", "%ebx", "%ecx", "%edx");

#elif defined(__x86_x64__) || defined(__amd64__)
    __asm__ ("movq $1, %%rax;\n"
            "movq $1, %%rdi;\n"
            "movq %0, %%rsi;\n"
            "movq $4, %%rdx;\n"
            "syscall"::"r"(x):"%rax","%rdi","rsi","rdx");
#else
    printf("Unsupported Platform\n");
#endif
    return 0;
}
