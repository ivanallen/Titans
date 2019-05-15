说说你对系统调用的理解？
答：系统调用是 Linux 提供给我们的接口，应用程序通过调用接口完成相应的功能，比如printf函数，它最终使用了 sys_write 这个系统调用。

Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？
答：Linux 平台上，x86 架构系统调用指令是 int 0x80 和 sysenter ，x64是 syscall，arm是 svc 
你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
答：比如 open, read。
https://filippo.io/linux-syscall-table/

open 函数的系统调用号是多少？read 呢？你是从哪里找到它们的？
答：64位平台：open : 2，read : 0   https://filippo.io/linux-syscall-table/
32位平台：open : 5，read : 3   https://syscalls.kernelgrok.com/
malloc 是系统调用吗？为什么？
答：不是，它是系统调用的封装，和print类似，不是操作系统给的接口。
你使用什么命令来查看系统调用的文档？
答：man

你觉得学习系统编程会对你有何帮助？
答：了解函数的底层实现，有助于找到更隐藏的bug。
