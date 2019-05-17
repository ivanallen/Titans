## 说说你对系统调用的理解？

答：系统调用是 Linux 提供给我们的接口,用户可以通过系统调用命令在自己的应用程序中调用它们。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有`sysenter`,x64 架构系统调用指令是`syscall`，arm 是`svc`。

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`,`close`,`fork`...http://blog.sina.cn/dpool/blog/s/blog_a2acdfc701013mtq.html?vt=4

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答: `open`函数在x64位系统的系统调用号是`2`，在x32位系统是`5`
    `read`函数在x64位系统的系统调用号是`0`，在x32位系统是`3`
    https://blog.csdn.net/qq_29343201/article/details/52209588

## `malloc` 是系统调用吗？为什么？

答：不是系统调用，因为malloc使用brk或mmap系统调用去获取内存。

## 你使用什么命令来查看系统调用的文档？

答： `man 2 函数名`。

## 你觉得学习系统编程会对你有何帮助？

答：更了解一些底层的东西。
