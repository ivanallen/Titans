
## 说说你对系统调用的理解？

答：系统调用是 Linux 提供给我们的接口。通过这些接口，我们可以间接调用系统服务（这些服务往往需要更加高级严格的权限）。系统调用保证了OS和用户的隔离，保证了系统的安全性。系统调用和普通库函数调用非常相似，只是系统调用由操作系统内核提供，运行于内核核心态，而普通的库函数调用由函数库或用户自己提供，运行于用户态。
  我参考了维基百科和linux/Unix系统编程手册。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有x86_32<2>使用的 `sysenter` 方式,x86_64使用的 `syscall` 方式。arm的指令是：`swi`

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`,`write`,`socket`。我是从 TCPIP网络编程 找到它们的。

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：`open` :x86架构下是 `5` ， x64架构下是 `2`。 `read` ：x86架构下是 `3` ， x64架构下是 `0`。
x64：https：//blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

x86：https：//syscalls.kernelgrok.com/

## `malloc` 是系统调用吗？为什么？

答：`malloc`不是系统调用， 他是C语言库函数里的一个函数。`malloc`在其内部调用brk()/ sbrk()系统调用来获得内存。
参考文献：https://stackoverflow.com/questions/5716100/what-happens-in-the-kernel-during-malloc/5716525#5716525

## 你使用什么命令来查看系统调用的文档？

答：man 2 系统调用名称  或者  谷歌检索

## 你觉得学习系统编程会对你有何帮助？

答：帮助我更好的理解计算机系统的服务机制
