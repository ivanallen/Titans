#include <unistd.h>

int main()
{
    char buf[] = "HeXueming\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    //参数1： 文件描述符，STDOUT_FILENO表示的是标准输出流，默认输出到屏幕上。
    //参数2： 字符串数组buf。用于存放待写的数据。
    //参数3： 参数2缓存区的大小
    return 0;
}
