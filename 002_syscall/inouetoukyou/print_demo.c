#include <unistd.h>

int main() {
    const char nickname[] = "inouetoukyou\n";
    /*write函数3个参数，
     * 1）文件描述符，这里STDOUT_FILENO表示标准输出，即屏幕
     * 2）数据的地址，const void*，这里nickname是字符数组
     * 3）输出数据的最大长度*/
    write(STDOUT_FILENO, nickname, sizeof(nickname));
    return 0;
}
