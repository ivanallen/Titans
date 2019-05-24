#include <unistd.h>   //导入linux系统调用

int main() {
    char buf[] = "jiang yuntao!\n";   //一个字符串指针
    write(STDOUT_FILENO, buf, sizeof(buf));//系统调用，是低级io，STUDOUT_FILENO
    //是文件描述符,参数二是需要输出的，参数三为输出字符数
    return 0;
}
