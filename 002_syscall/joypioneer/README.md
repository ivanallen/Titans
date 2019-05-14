
## 说说你对系统调用的理解？

答：系统调用是操作系统与应用程序之间的接口。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上：
	x86 架构系统调用指令是 "int 0x80" & "sysenter"。
	x64 架构系统调用指令是 "syscall"。
	Arm 架构系统调用指令是 "swi"。

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 "read"，"write"，"open", "fork"。《unix环境高级编程》。

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：
- 在x64架构中`open`系统调用号是"2"，"read"的系统调用号是"0"。

- 在x86架构中`open`系统调用号是"5"，"read"的系统调用号是"3"。

https://blog.csdn.net/qq_29343201/article/details/52209588

## `malloc` 是系统调用吗？为什么？

答：不是系统调用，malloc调用brk或mmap系统调用去获取内存。
https://blog.csdn.net/shenwanjiang111/article/details/84585400

## 你使用什么命令来查看系统调用的文档？

答："man 2 xxx"; eg: man 2 write。

## 你觉得学习系统编程会对你有何帮助？

答：更加深入了解操作系统，理解程序程序如何运行，解决系统调用出现的问题。比如：write 完文件之后，最好需要同步磁盘处理。
