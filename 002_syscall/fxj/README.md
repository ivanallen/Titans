## 说说你对系统调用的理解？

答：系统调用是应用程序主动进入操作系统内核的入口。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有x64 架构中，系统调用指令是 syscall 。

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`, `write`，`access`,我是从适用于x86 64的Linux系统调用表找到它们的。

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：X64位下:"open":2，"read":0； 在适用于x64的Linux系统调用表中找到的 https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
X86位下:"open":5 , "read":3； 在适用于X86的Linux系统调用表中找到的  https://syscalls.kernelgrok.com/

## `malloc` 是系统调用吗？为什么？

答：不是， malloc是C语言中一个封装之后的函数，调用brk或者mmap执行系统命令获取内存

## 你使用什么命令来查看系统调用的文档？

答：man 
Linux系统提供了相对比较丰富的帮助手册（man），man是manual的缩写，在日常linux系统管理中经常用到，今天就简单聊聊man。man 本身也提供自己的帮助手册，通过man就可以查看
https://blog.csdn.net/shuizhizhiyin/article/details/51668962

## 你觉得学习系统编程会对你有何帮助？

答：帮助我了解系统工作原理，提高代码运行效率。
