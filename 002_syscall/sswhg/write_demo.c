#include <stdio.h>

int main() {
    char x[] = "Hello sswhg\n";

#if defined(__i386__)
    __asm("movl $4, %%eax\n"
            "movl $1, %%ebx\n"
            "movl %0, %%ecx\n"
            "movl $12, %%edx\n"
            "int $0x80"::"r"(x):"%eax", "%ebx", "%ecx", "%edx");
#endif
    return 0;
}
