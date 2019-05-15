#include <stdio.h>

int main() {
    const char name[] = "Hello, shsyhy903!\n";
#if defined(__x86_x64__) || defined(__amd64__)
    __asm__ ("movq $1, %%rax;\n"
            "movq $1, %%rdi;\n"
            "movq %0, %%rsi;\n"
            "movq $20, %%rdx;\n"
            "syscall"::"r"(name):"%rax","%rdi","%rsi","%rdx");
#endif
    return 0;
}
