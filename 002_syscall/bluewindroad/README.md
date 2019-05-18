## 说说你对系统调用的理解？

答：操作系统是程序员和硬件对话的媒介，程序员通过操作系统管理硬件资源，系统调用是 Linux 提供给我们的接口，我们通过系统调用来控制硬件。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有`sysenter`。 x64 架构系统调用指令是 `syscall`。 Arm 架构系统调用指令是 `swi`。

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`, `create`,`link`。我是从 http://asm.sourceforge.net/syscall.html 找到它们的。

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：在i386下，`open`为5，`read`为3，我是从 http://asm.sourceforge.net/syscall.html 找到它们的。

在32位下，`open`为5，`read`为3，我是从 https://blog.csdn.net/qq_29343201/article/details/52209588 找到它们的。

在64位下，`open`为0，`read`为2，我是从 https://blog.csdn.net/qq_29343201/article/details/52209588 找到它们的。

## `malloc` 是系统调用吗？为什么？

答：不是，`malloc`调用`brk`或`mmap`系统调用去获取内存，本身不是系统调用。

## 你使用什么命令来查看系统调用的文档？

答：man 2 ...

## 你觉得学习系统编程会对你有何帮助？

答：知其然也知其所以然，对于编程理解更加深刻
