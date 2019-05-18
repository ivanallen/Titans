#include <unistd.h>

int main() {
    const char myname[] = "yu0206\n";
    write(STDOUT_FILENO, myname, sizeof(myname));
    /*write函数：
     * write(unsigned int fd, const void* buf, size_t count);
     * 参数1---unsigned int fd
     *     文件描述符号 ：STDIN_FILENO 0 标准输入 
     *                    STDOUT_FILENO 1 标准输出
     *                    STDERR_FILENO 2 标准错误输出
     *
     * 参数2---const void* buf
     *     指向一块内存的指针 通常是字符串
     *
     * 参数3---size_t count
     *     每次允许写入的最大字节数
     */
    return 0;
}
