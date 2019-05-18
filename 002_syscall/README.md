## 002_syscall

### 1. 认识系统调用

在此之前，我们整体上了解一下系统编程我们需要学习什么。

大体上，系统编程被切分为以下几大块：

- 文件
- 进程
- 信号
- 线程
- 高级 IO

以上每一块知识都包含若干知识点，而且十分重要。在此之外一些工作中并不太常用的东西，我们会选择性的学习。在进入“文件”这个大类之前，我们先了解一下 Linux 系统（其它 OS 也是一样）中一个十分重要的概念，**系统调用**。

#### 1.1 Hello world

相信你对上一个任务的 Hello world 印象深刻，尽管你没有了解过 `printf` 是如何把 "Hello world\n" 送上屏幕的，但是我相信 git 那些让人摸不着脑袋的命令也能让你回忆起这一切操作是多么的神奇。

好了，关于 git，我们有机会再谈。这一节的任务，我们是学习系统调用。这并不是一个什么抽象的概念，而是活生生的，具体的东西。就像 `printf` 函数，你传入一个字符串，它就能给你送上屏幕。`printf` 函数并没有什么很神奇的地方，它之所以能把字符串送上屏幕，是因为它也要和 Linux 系统打交道，它得通知 Linux：哥们儿，把我这一串字符送上屏幕吧！

其实在 `printf` 内部实现，调用的 Linux 提供的一个叫 `sys_write` 的系统调用。Linux 为了方便我们使用它，提供了一个已经封装好的 C 语言接口 `write` 方便我们使用。具体你可以通过执行 `man 2 write` 来查看 `write` 的使用方法。比如下面这个例子：

```c
#include <unistd.h>

int main() {
    write(1, "Hello world\n", 12);
    return 0;
}
```

`write` 函数的第一个参数术语叫“文件描述符”，它就是一个 int 类型的整数。现在你不需要关心文件描述符是什么意思，把它看成是某个文件的号码牌就行了。在这个例子里，1 表示的是你的屏幕。是的，这是一个固定值，以后你想输出文字到屏幕都可以这么用。但是这个数字看起来显然很常用，因此官方提供了一个宏 `STDOUT_FILENO` 来表示它。

#### 1.2 write

第 1 小节我们说，Linux 平台提供了一个好用的 C 语言接口 `write`. `write` 实际上是系统调用的封装。要想使用系统调用，那得使用特殊的 CPU 指令，这牵涉到硬件了！是的，操作系统要想提供系统调用，必须要 CPU 的支持。而且，很容易想到，在不同 CPU 架构中，系统调用的指令还不一样。

在 x86 架构中，你可以使用 `int 0x80` 中断指令来和 Linux 打交道，也可以使用 `sysenter` 指令来使用系统调用。在 x64 架构中，你可以使用 `syscall` 指令来使用系统调用。

下面是使用 `sys_write` 的方法：

```c
// demo.c
#include <stdio.h>

int main() {
    char x[] = "Hello world\n";

#if defined(__i386__)
    __asm("movl $4, %%eax\n"
            "movl $1, %%ebx\n"
            "movl %0, %%ecx\n"
            "movl $12, %%edx\n"
            "int $0x80"::"r"(x):"%eax", "%ebx", "%ecx", "%edx");
#elif defined(__x86_x64__) || defined(__amd64__)
    __asm__ ("movq $1, %%rax;\n"
            "movq $1, %%rdi;\n"
            "movq %0, %%rsi;\n"
            "movq $12, %%rdx;\n"
            "syscall"::"r"(x):"%rax","%rdi","%rsi","%rdx");
#else
    printf("Unsupported Platform\n");
#endif
    return 0;
}
```

你不必为了理解上面的汇编而去独立学习一堆汇编语法，你只需要知道，要想使用系统调用，库函数 `write` 为我们做了什么。Linux 系统为我们提供了 300 多个系统调用，为了使用 `sys_write` 这个系统调用，你得告诉 Linux 才行。Linux 为每个系统调用分配了一个调用号，在 x86 中，`sys_write` 的调用号是 4，在 x64 架构中，这个调用号是 1. 它们都使用寄存器 eax/rax 进行传参。

_在后面的资料里，你可以找到 Linux 的系统调用表。_

### 2. 任务

你的目录结构将会这样的：

```
allen/
├── README.md
├── Makefile
├── print_demo.c
└── write_demo.c
```
**文件名上请不要自由发挥，比如认为输出结果没有问题，就随意改动文件名。关于 Makefile 文件，请严格按照我的方式编写，确保可执行文件（二进制文件）的名字为 print_demo 和 write_demo**
#### 2.1 使用系统调用 write

请使用 write 向屏幕输出 "你的昵称". 这个程序写到 print_demo.c 中。

**重要**：请在 print_demo.c 加上注释，解释 write 函数各种参数的含义。

#### 2.2 祼用汇编指令

你的任务是，把 1.2 节中的代码 copy 到 write_demo.c 这个文件中，

- 根据你的 CPU 架构，选择合适的代码，并去掉不相关的平台编译代码。（注意，条件编译宏仍需要保留。）
- **更改你 copy 的代码，输出你的昵称**


选做题：当然，你可以甚至把上面的汇编封装成一个真正的 write 函数。这是一个 optional，你可以不做，这可能会花费你大量的时间。

#### 2.3 问答

- 说说你对系统调用的理解？
- Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？
- 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
- `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？
- `malloc` 是系统调用吗？为什么？
- 你使用什么命令来查看系统调用的文档？
- 你觉得学习系统编程会对你有何帮助？

请创建一个文件 README.md，内容如下：

```
## 说说你对系统调用的理解？

答：系统调用是 Linux 提供给我们的接口……

## Linux 平台 x86 架构的系统调用指令是什么？x64 呢？Arm 架构 Linux 平台的系统调用指令是什么？

答：Linux 平台上，x86 架构系统调用指令是 `int 0x80` 还有……

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？

答：比如 `open`, `read`, ……。我是从 xxx 找到它们的。

## `open` 函数的系统调用号是多少？`read` 呢？你是从哪里找到它们的？

答：xxx

## `malloc` 是系统调用吗？为什么？

答：xxx

## 你使用什么命令来查看系统调用的文档？

答：xxx

## 你觉得学习系统编程会对你有何帮助？

答：xxx
```




### 3. 相关资料

- x64 系统调用表

https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

https://filippo.io/linux-syscall-table/

- x86 系统调用表

https://syscalls.kernelgrok.com/

https://en.wikibooks.org/wiki/X86_Assembly/Interfacing_with_Linux

- How to invoke system call in inline assembly?

https://stackoverflow.com/questions/9506353/how-to-invoke-a-system-call-via-sysenter-in-inline-assembly

- how to use sysenter under linux

https://reverseengineering.stackexchange.com/questions/2869/how-to-use-sysenter-under-linux

- Pre-defined Compiler Macros

https://sourceforge.net/p/predef/wiki/Architectures/

