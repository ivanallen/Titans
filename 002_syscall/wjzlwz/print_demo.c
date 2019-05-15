#include <unistd.h>

int main() {
    const char buf[] = "wjzlwz\n";
    /*
    参数１为文件描述符，STDOUT_FILENO输出到屏幕
    参数２为输出内容
    参数３代表输出内容字节长度
    */
    
    write(STDOUT_FILENO, buf, sizeof(buf));
    
    return 0;
}
