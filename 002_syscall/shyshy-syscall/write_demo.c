#include<stdio.h>

int main() {
    char x[] = "shyshy903!\n";

#if defined(__amd64__) || defined(_x86_x64_)
    __asm__ ("movq $1, %%rax;\n"
           "movq $1, %%rdi;\n"
           "movq %0, %%rsi;\n"
           "movq $12, %%rdx;\n"
           "syscall"::"r"(x):"%rax", "%rdi", "%rsi", "%rdx");
#else
    printf("Unsupported Platform\n");
#endif
    return 0;
}
