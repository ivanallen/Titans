## 说说你对系统调用的理解？
答：

系统调用是 OS 提供给用户程序调用的一组接口。在保护模式下，用户态的进程是不能访问内核的，如果需要使用内核态的功能，就需要通过系统调用来陷入内核，由 OS 代为完成。通常可以用来控制硬件、设置系统状态或者读取内核数据

跟函数调用的区别：函数调用运行在用户态，主要通过压栈进行，开销比较小。系统调用需要在用户态和内核态之间进行上下文切换，开销比较大。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？
答：
- Linux 平台上，x86 架构系统调用指令是 int 0x80 和 sysenter。
- x64 架构系统调用指令是 syscall
- Arm 架构系统调用指令是 swi

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
答：

1）man 2 能找到的一般都是系统调用
- 文件方面：open、write、read、lseek、fcntl
- 进程方面：fork、wait、waitpid
- 进程通信：pipe、socket
- 线程方面：pthread_create
- 信号方面：signal

2）百度、APUE、UNP

## open 函数的系统调用号是多少？read 呢？你是从哪里找到它们的？
答：

- x64 架构：open 的系统调用号是 2，read 的系统调用号是 0
- x86 架构：open 的系统调用号是 5，read 的系统调用号是 3

百度说是这样找到：

查看 32位 的系统调用号
- cat /usr/include/asm/unistd_32.h

查看64位的系统调用号

- cat /usr/include/asm/unistd_64.h 

我的机器上：
$ cat /usr/include/asm-generic/unistd.h | grep -nw __NR_open
>716:#define __NR_open 1024
>717:__SYSCALL(__NR_open, sys_open)

## malloc 是系统调用吗？为什么？
答：不是。它只是封装了系统调用的一个库函数
- 申请内存小于 128k 时使用 brk 系统调用在堆区分配空间
- 申请内存大于 128k 时使用 mmap 系统调用在映射区分配空间


## 你使用什么命令来查看系统调用的文档？
答：man 2 查看系统调用相关函数，非常详细

## 你觉得学习系统编程会对你有何帮助？
答：

- promote myself and get offer
- learn OS how 2 run