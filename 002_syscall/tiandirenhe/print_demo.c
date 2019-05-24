#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char* nickname = "tiandirenhe\n";//参数二：指定的缓冲区，要输出的字符串保存该处。
    size_t bytes = strlen(nickname);//参数三：字符串中有效字符的个数。（strlen()用来计算指定的字符串s的长度，不包括结束字符"\0"）
    ssize_t  ret = write(STDOUT_FILENO, nickname, bytes);//参数一:代表文件描述符，STDOUT_FILENO是代表文件描述符编号的宏。

    //write函数返回值：写入文档的字节数（成功）；-1（出错）
    if(-1 == ret)
    {
        perror("write error!\n"); //perror ( )用 来 将 上 一 个 函 数 发 生 错 误 的 原 因 输 出 到 标 准 设备 (stderr)
    }

    return 0;
}
