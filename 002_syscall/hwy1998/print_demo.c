#include <unistd.h>
#include <string.h>
int main()
{
	char x[]="hwy1998\n";
	//ssize_t write(int fd, const void *buf, size_t count);
	//第一个参数是文件描述符，第二个参数是要输出的字符串缓冲区，第三个参数是输出的字节数
	write(1,x,strlen(x));
	return 0;
}

