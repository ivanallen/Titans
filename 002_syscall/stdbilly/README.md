## 说说你对系统调用的理解？

答：系统调用是系统调用是 Linux 提供给我们的接口, 程序利用系统调用进入内核来执行一系列操作,如创建进程、处理网络、读写文件等.

https://blog.packagecloud.io/eng/2016/04/05/the-definitive-guide-to-linux-system-calls/

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 和`sysenter`, x64架构中系统调用指令是`syscall`, Arm架构Linux的系统调用指令是`svc`, `swi`已弃用,并在汇编期间转换为`svc`(https://jumpnowtek.com/shellcode/linux-arm-shellcode-part1.html).

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`, `write`,`close`, 在这里找到:https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：

|         | `open` | `read` |
| ------- | ------ | ------ |
| x64架构 | 2      | 0      |
| x86架构 | 5      | 3      |

x64: https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

x86: https://syscalls.kernelgrok.com/

## `malloc` 是系统调用吗？为什么？

答：`malloc`不是系统调用,`malloc`通过`brk()/sbrk()`系统调用获取内存或`mmap()`获取匿名内存.

https://stackoverflow.com/a/5716525

## 你使用什么命令来查看系统调用的文档？

答：`man 2 系统调用名称`

## 你觉得学习系统编程会对你有何帮助？

答：进一步理解程序的执行原理, 理解操作系统