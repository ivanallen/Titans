//demo.c
#include <stdio.h>

int main(){
	char x[] = "Hello Wqlcnbb\n";
#if defined(__amd64__)
	__asm__("movq $1, %%rax;\n"
		   "movq $1, %%rdi;\n"
		   "movq %0, %%rsi;\n"
		   "movq $15, %%rdx;\n"
		   "syscall"::"r"(x):"%rax","%rdi","%rsi","%rdx");
#else
	printf("Unsupported Platform\n");
#endif
	return 0;
}
