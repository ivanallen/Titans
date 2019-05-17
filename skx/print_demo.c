#include <unistd.h>

int main() {
    char buf[] = "skx\n";
    write(STDOUT_FILENO, buf, sizeof(buf));//STDOUT_FILENO:标准输出,指屏幕,buf:输出的内容,sizeof(buf):输出内容的长度,返回值：写入字节数，错误则返回-1
    return 0;
}
