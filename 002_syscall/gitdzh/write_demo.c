#include <unistd.h>
#include <stdio.h>
#define BUFSIZE 1024

int main () {

    const char buf[BUFSIZE] = "gitdzh\n";

    // 寄存器 eax/rax 进行传参
#if defined(__x86_x64__) || defined(__amd64__)
    __asm__ ("movq $1, %%rax;\n"
            "movq $1, %%rdi;\n"
            "movq %0, %%rsi;\n"
            "movq $7, %%rdx;\n"
            "syscall"::"r"(buf):"%rax","%rdi","%rsi","%rdx");
#endif
    
    return 0;
}
