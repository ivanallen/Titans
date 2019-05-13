#include <unistd.h>
#include <stdlib.h>
#define BUFSIZE 1024
#define PERR(msg) do { perror(msg); exit(1); } while(0);

/*
 * ssize_t write(int fd, const void *buf, size_t count);
 * @ 作用  ： 把 buf 中 count 字节的数据写到文件描述符
 * @ para1： fd 文件描述符，可以是标准输出、文件、socket等
 * @ para2： 缓冲区
 * @ para3： 从缓冲区中拿出的字节数
 * @ 返回值： 实际写入的字节数，返回-1表示写出错。要是写到文件里，返回值一定要和 count 相等
*/

int main () {

    const char buf[BUFSIZE] = "gitdzh\n";
    if (write(STDOUT_FILENO, buf, sizeof(buf)) < 0)
        PERR("write");
    
    return 0;
}
