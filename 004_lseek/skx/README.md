### 1. 写出 `dup` 函数的伪代码。
dup 函数用来复制一个文件的描述符。
成功：dup 函数返回当前系统可用的最小整数值。 
失败：均返回 -1，并设置 errno

一个文件文件只有一个 v 结点和 i 结点，不同进程打开不同或者相同的文件，都会产生一个文件表，dup 函数会使得在同一个进程中有两个 fd 指向同一个文件表。
```c++
int dup(int oldfd) {
    //...
    PCB* current = get_current();             //找当前进程的进程控制块结构体
    for (int i = 0; i < 256; ++i) {
        if (current -> filp[i] == NULL) {     //从当前进程的 filp 数组中找一个描述符最小的空闲位置
            current -> filp[i] = filp[oldfd]；//令 filp[i] 指向 filp[oldfd]
            current -> flip[i] -> count++;    //引用计数加 1
            return i;                         //返回当前描述符
        }  
    }
    return -1;                                //全都满了，找不到位置
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：以前就知道 dup 和 dup2 的原理，但是没有看伪代码，看了伪代码之后更加清晰明了了

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？
答：O_APPEND 的含义是在每次写之前，都将标志位移动到文件的末端。可以理解为先打开文件，在将当前位置移动到文件的末尾。移动到末端，写数据这两步是一个原子操作，不可拆分。也就是说，当在O_APPEND 打开后，然后用 lseek 移动到其他的位置，然后再用 write 写，还是写在末端 ，中间的 lseek 是无效的。
例如：

```c++
int fd = open("test.txt", RDWR | O_APPEND);
    lseek(fd, 10, SEEK_SET);
    if (write(fd, buffer, strlen(buffer)) != strlen(buffer)) {
          perror("write error");
          exit(1);
    }
     read(fd, buffer, 20);
```
这里 lseek 是没有用的，write 的写入是到文件末端的。在 write 写完后，标志位是在文件末端的， 这里的 read 不会读出任何数据，因为在文件末尾，以前的 lseek 没有起作用，除非在读之前再 lseek 一次。
