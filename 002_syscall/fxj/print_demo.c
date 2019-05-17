#include <unistd.h>
int main() {
    char buf[] = "Hello, fuxiangjie!\n";
    write(STDOUT_FILENO, buf, sizeof(buf));
    // arg1: 表示屏幕的代码
    // arg2: 代表将要打印出来的字符串数组
    // arg3: 数组所占内存大小  
    // return value: on success, the number of bytes written is returned. On error, return -1.
    return 0;
}
