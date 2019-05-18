## 说说你对系统调用的理解？
答：系统调用和普通的函数调用非常类似。Linux内核中设置一组用于实现各种系统功能的子程序，称为系统调用。用户可以通过系统调用命令在自己的应用
程序中调用它们。系统调用提供了用户程序与操作系统之间的接口。
## Linux平台x86架构的系统调用指令是什么？x64呢？Arm架构Linux平台的系统调用指令是什么？
答：x86架构中系统调用指令是 `int 0x80` 或 `sysenter`。在x64中用 `syscall` 。arm是swi
## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
答：`read` , `open` , `close` 。从https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
## `open`函数的调用号是多少？`read`呢？你是从哪里找到它们的？
答：
64位：`open`函数调用号是2，`read`是0。从https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/
32位：`open`函数调用号是5，`read`是3。从https://syscalls.kernelgrok.com/
## `malloc`是系统调用吗？为什么？
答：不是。`malloc`通过调用系统调用`brk`或`mmap`去获取内存。
## 你使用什么命令来查看系统调用的文档？
答：`man`
## 你觉得学习系统编程对你有何帮助？
答：更好的了解操作系统。
