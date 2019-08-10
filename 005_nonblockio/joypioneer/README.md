### 1.block_io为什么会阻塞？
    答：block_io.c文件中读取文件采用的是read，read的调用是阻塞的，此时操作系统会把当前进程状态置为阻塞态。

### 2.block_io_ex 为什么无法并发处理两个不同设备来的数据?
    答：block_io_ex程序是以阻塞的方式打开所有文件，该过程只能按照先后顺序处理不同文件，如果有其中一个文件无法读取到数据，则会阻塞，故不能继续处理其他文件中的数据。

### 3.查阅手册，fcntl 各个参数以及返回值的含义是什么？
    答：
    #include <fcntl.h>
    定义函数：
    int fcntl(int fd, int cmd);
    int fcntl(int fd, int cmd, long arg);
    int fcntl(int fd, int cmd, struct flock * lock);
    
    fcntl()用来操作文件描述符的一些特性。
    
    F_DUPFD 用来查找大于或等于参数arg 的最小且仍未使用的文件描述词, 并且复制参数fd 的文件描述词. 执行成功则返回新复制的文件描述词. 请参考dup2(). F_GETFD 取得close-on-exec 旗标. 若此旗标的FD_CLOEXEC 位为0, 代表在调用exec()相关函数时文件将不会关闭.
    F_SETFD 设置close-on-exec 旗标. 该旗标以参数arg 的FD_CLOEXEC 位决定.
    F_GETFL 取得文件描述词状态旗标, 此旗标为open()的参数flags.
    F_SETFL 设置文件描述词状态旗标, 参数arg 为新旗标, 但只允许O_APPEND、O_NONBLOCK 和O_ASYNC 位的改变, 其他位的改变将不受影响.
    F_GETLK 取得文件锁定的状态.
    F_SETLK 设置文件锁定的状态. 此时flcok 结构的l_type 值必须是F_RDLCK、F_WRLCK 或
    F_UNLCK. 如果无法建立锁定, 则返回-1, 错误代码为EACCES 或EAGAIN.
    F_SETLKW 同F_SETLK 作用相同, 但是无法建立锁定时, 此调用会一直等到锁定动作成功为止. 若在等待锁定的过程中被信号中断时, 会立即返回-1, 错误代码为EINTR.
    struct flcok
    {
        short int l_type; //锁定的状态
        short int l_whence; //决定l_start 位置
        off_t l_start; //锁定区域的开头位置
        off_t l_len; //锁定区域的大小
        pid_t l_pid; //锁定动作的进程
    };
    
    l_type 有三种状态:
        F_RDLCK 建立一个供读取用的锁定
        F_WRLCK 建立一个供写入用的锁定
        F_UNLCK 删除之前建立的锁定
    
    l_whence 也有三种方式:
        SEEK_SET 以文件开头为锁定的起始位置.
        SEEK_CUR 以目前文件读写位置为锁定的起始位置
        SEEK_END 以文件结尾为锁定的起始位置.
    返回值：成功则返回0, 若有错误则返回-1, 错误原因存于errno.

### 4.你觉得非阻塞IO解决了什么问题？
    答：避免进程被某一个文件，该文件一直都不会写入数据，使之阻塞住，从而使得多个设备读取数据可以相互独立。

### 5.nonblock_io会有什么问题？
    答：若程序中的所有文件都是没有数据，此时执行，则会占用大量CPU时间。
