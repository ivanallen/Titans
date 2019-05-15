
## 说说你对系统调用的理解？

答：系统调用是操作系统提供给上层应用的接口。

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有`sysenter`。x64架构系统调用指令是`syscall`，`Arm`架构系统调用指令是`swi`。

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `fork`， `read`，`write`，`exit" 。https://www.kancloud.cn/wizardforcel/linux-c-book/134954

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：
- 在x64架构中`open`系统调用号是`2`，`read`的系统调用号是`0`。

- 在x86架构中`open`系统调用号是`5`，`read`的系统调用号是`3`。

cat /usr/include/asm/unistd_32.h  32位
cat /usr/include/asm/unistd_64.h　64位

## `malloc` 是系统调用吗？为什么？

答：不是， 是对于系统调用的封装，其内部调用了`brk`或者`sbrk`系统调用。

## 你使用什么命令来查看系统调用的文档？

答：man

## 你觉得学习系统编程会对你有何帮助？

答：深入理解操作系统，提升debug能力。
