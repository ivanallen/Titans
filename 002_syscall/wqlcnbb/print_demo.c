#include <unistd.h>

int main(){
	char buf[]="Hello Wqlcnbb\n";
	/*
	 * ssize_t write(int fd, const void *buf, size_t count);
	 * writes up to count bytes from the buffer starting at buf to
	 * the file referred to by the file descriptor fd.
	 * On success, the number of butes written is returned.
	 * On error, -1 is returned, and error is set to indicate the cause of the error.
	 * arg1: fd the file descriptor for example :1(or STDOUT_FILENO) Tohat's the screen
	 * arg2: a pointer to memory buffer;
	 * arg3: write bytes
	 *
	 *
	 * */
	write(1, buf, sizeof(buf));
	return 0;
}
