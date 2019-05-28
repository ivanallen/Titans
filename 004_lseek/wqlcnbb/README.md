### 1.写出 dup 函数的伪代码。

dup函数用来复制参数oldfd所指的文件描述符。当复制成功是，返回最小的尚未被使用过的文件描述符，若有错误则返回-1.错误代码存入errno中。返回的新文件描述符和参数oldfd指向同一个文件，这两个描述符共享同一个数据结构，共享所有的锁定，读写指针和各项权限或标志位。（参考：https://blog.csdn.net/tiandc/article/details/81489447）

```c
int dup(int oldfd) {
    //...
    PCB* current = get_current();
    for (int i = 0; i < 256; ++i) {
        if (current -> filp[i] == NULL) {
            current -> filp[i] = filp[oldfd]；
            current -> flip[i] -> count++;
            return i;
        }  
    }
    return -1;
}
```
### 2.学习本文知识点对你来说有什么困难？

答：基本上没困难。

### 3.你能理解 open 函数 flags 标志位 O_APPEND 是如何实现的吗？

答：用O_APPEND打开后，write操作是一个原子操作，所以每次都会自动把偏移量移到文件末尾，即当你每次调用write时，OS就会把文件的读写位置设置成文件尾部，包括你调用lseek函数来修改文件读写位置。（参考博客：https://blog.csdn.net/zyq522376829/article/details/47730037 和 https://blog.csdn.net/chance_yin/article/details/12281003）。



