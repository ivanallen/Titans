1. block_io 为什么会阻塞？
答：因为在 block_io 中，read函数和write函数在默认情况下是阻塞的。read函数在没有数据到达前时，会阻塞，一直等到数据到达。

2. block_io_ex 为什么无法并发处理两个不同设备来的数据?
答：在block_io_ex中，我们采用把两个不同的设备的文件描述符放入数组中，然后轮询之。问题在于，当前的设备数据一直没有到达，那么read函数会一直阻塞下去，直到当前设备数据到达。就算排在后面的设备的数据已经达到，也无法及时处理，导致了如今的现象。

3. 查阅手册，fcntl 各个参数以及返回值的含义是什么？
答： 头文件：

#include <unistd.h>    
#include <fcntl.h>
定义函数：

int fcntl(int fd, int cmd);
int fcntl(int fd, int cmd, long arg);
int fcntl(int fd, int cmd, struct flock * lock);
函数说明：

1、fcntl()用来操作文件描述词的一些特性。

2、参数fd 代表欲设置的文件描述词。

3、参数cmd 代表欲操作的指令。有以下几种情况:

F_DUPFD 用来查找大于或等于参数arg 的最小且仍未使用的文件描述词, 并且复制参数fd 的文件描述词. 执行成功则返回新复制的文件描述词. 请参考dup2(). F_GETFD 取得close-on-exec 旗标. 若此旗标的FD_CLOEXEC 位为0, 代表在调用exec()相关函数时文件将不会关闭.

F_SETFD 设置close-on-exec 旗标. 该旗标以参数arg 的FD_CLOEXEC 位决定.

F_GETFL 取得文件描述词状态旗标, 此旗标为open()的参数flags.

F_SETFL 设置文件描述词状态旗标, 参数arg 为新旗标, 但只允许O_APPEND、O_NONBLOCK 和O_ASYNC 位的改变, 其他位的改变将不受影响.

F_GETLK 取得文件锁定的状态.

F_SETLK 设置文件锁定的状态. 此时flcok 结构的l_type 值必须是F_RDLCK、F_WRLCK.

F_UNLCK 如果无法建立锁定, 则返回-1, 错误代码为EACCES 或EAGAIN.

F_SETLKW 同F_SETLK 作用相同, 但是无法建立锁定时, 此调用会一直等到锁定动作成功为止. 若在等待锁定的过程中被信号中断时, 会立即返回-1, 错误代码为EINTR. 参数lock 指针为flock 结构指针, 定义如下

struct flcok
{
    short int l_type; //锁定的状态
    short int l_whence; //决定l_start 位置
    off_t l_start; //锁定区域的开头位置
    off_t l_len; //锁定区域的大小
    pid_t l_pid; //锁定动作的进程
};
/*
l_type 有三种状态:
    F_RDLCK 建立一个供读取用的锁定
    F_WRLCK 建立一个供写入用的锁定
    F_UNLCK 删除之前建立的锁定

l_whence 也有三种方式:
    SEEK_SET 以文件开头为锁定的起始位置.
    SEEK_CUR 以目前文件读写位置为锁定的起始位置
    SEEK_END 以文件结尾为锁定的起始位置.
    */
返回值：成功则返回0, 若有错误则返回-1, 错误原因存于errno.

4. 你觉得非阻塞 IO 解决了什么问题？
答：我认为非阻塞 IO 解决了阻塞 IO 不能即使处理任一设备的数据到达这个问题。只要某设备数据到达，在下次轮询时就能得到处理，不受其他设备数据到达影响。

5. nonblock_io 会有什么问题？
答：我写的nonblock_io，cpu一直会轮询数组中的那些文件描述符。即使都没有数据到达，CPU也会一直空转下去，所以这个nonblock_io效率不高。
