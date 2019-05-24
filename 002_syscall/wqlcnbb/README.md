##说说你对系统调用的理解？

答：系统调用是操作系统提供给上层应用的接口。

##Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：x86 架构系统调用指令是 int 0x80 或者sysenter。x64架构系统是syscall，Arm架构系统是swi。

##你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 fork， read，write，exit，wait 。我是从 《unix环境高级编程》上找到它们的。

##open 函数的系统调用号是多少？read 呢？你是从哪里找到它们的？

答：在x64架构中open系统调用号是2，read的系统调用号是0。在x86架构中open系统调用号是5，read的系统调用号是3。系统调用号可以在https://blog.csdn.net/u012763794/article/details/78777938中找到。

##malloc 是系统调用吗？为什么？

答：malloc不是系统调用，malloc是使用了系统调用来获取内存，（malloc调用brk或mmap系统调用去获取内存）；
https://blog.csdn.net/shenwanjiang111/article/details/84585400

##你使用什么命令来查看系统调用的文档？

答：man 2 read 。

##你觉得学习系统编程会对你有何帮助？

答：深入理解操作系统，了解底层是如何运行的，有助于提高编程能力。
