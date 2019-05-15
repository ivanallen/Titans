#include <unistd.h>

int main() 
{
    char buf[] ="sswhg\n";
    write(STDOUT_FILENO, buf, sizeof(buf));//参数1：为文件描述符，STDOUT_FILENO输出到屏幕 参数2：输出内容 参数3：输出内容字节长度
    return 0;
}
