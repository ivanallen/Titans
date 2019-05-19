#include <unistd.h>
#include <string.h>
int main(){
    char x[]="lxz001\n";
    /*
    * ssize_t write(int fd,const void*buf,size_t count);
    * ssize_t:失败返回 -1 成功返回写入字节数
    * fd:文件描述符，一般 标准输入 0，标准输出 1，标准错误 2
    * buf：地址，要写入字符串的地址
    * count:写入字符长度
    */
    write(1,x,strlen(x));
    return 0;
}
