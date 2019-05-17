## 说说你对系统调用的理解？
答：
1、操作系统提供给用户程序调用的一组特殊的接口。用户程序可以通过这组特殊接口来获得操作系统内核提供的服务；用户态进程主动切换到内核态;
2、系统调用可以用来控制硬件；设置系统状态或读取内核数据；进程管理，系统调用接口用来保证系统中进程能以多任务在虚拟环境下运行;
3、系统调用机制的核心是使用操作系统为用户特别开放的一个中断，例如Linux的int 80h中断。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？
答：
x86 架构系统调用指令是 int 0x80 和 sysenter。
x64 架构系统调用指令是 syscall
Arm 架构系统调用指令是 swi

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
答：
write、read、open、close、ioctl，clone，fork()，从这里找到https://filippo.io/linux-syscall-table/，非常详细的介绍了每一种系统调用

## open 函数的系统调用号是多少？read 呢？你是从哪里找到它们的？
答：
64位系统：open：2，read：0，从这里找到https://filippo.io/linux-syscall-table/
32位系统：open：5，read：3，从这里找到https://syscalls.kernelgrok.com/

## malloc 是系统调用吗？为什么？
答：
不是系统调用，malloc/free底层是由brk、mmap、munmap系统调用实现的，
brk是将数据段(.data)的最高地址指针_edata往高地址推，申请内存小于 128k 的空间用
mmap是在文件映射区域找一块空闲的虚拟内存，申请内存大于 128k 的空间用

## 你使用什么命令来查看系统调用的文档？
答：
man 2 查看系统调用，如 man 2 read 查看 read 系统调用

## 你觉得学习系统编程会对你有何帮助？
答：
真正理解了操作系统是如何工作
