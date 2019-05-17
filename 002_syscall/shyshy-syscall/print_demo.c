#include <unistd.h>

int main(){
    char name[]="shyshy903\n";
    /*函数会把参数2所指的内存写入name个字节到参数1所指定的文件内。
     * 参数1，是open函数返回的文件描述符，0\1\2分别对应标准输入、输出、出错；
     * 也对应了键盘、显示器、显示器；
     * 参数2，变量缓冲、存储区
     * 从缓冲区需要写入的字节输；
     */
    write(STDOUT_FILENO,name,sizeof(name));
    return 0;
}
