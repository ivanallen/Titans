## 说说你对系统调用的理解？
答：我们在使用电脑的时候，所有运行的软件都需要使用系统资源，这里涉及到对某些硬件资源的使用，例如读写内存，是不能随意进行的。必须通过系统调用来完成。系统调用可以认为是这些硬件资源的入口，就像c语言中要实现某个功能就需要调用某个函数一样。这种软件进程与硬件资源的隔离性，保证了系统的稳定和安全。      

## Linux平台x86架构的系统调用指令是什么？x64呢？Arm架构Linux平台的系统调用指令是什么？       
答：x86是 `int $0x80` 和 `sysenter` x64是 `syscall` 和 `sysret`   https://arthurchiao.github.io/blog/system-call-definitive-guide-zh/  
    Arm 是 `swi`  www.wowotech.net/process_management/syscall-arm.html       

## 你还能列举几个系统调用的例子出来吗？你是从哪里找到它们的？
答：比如 `read` `open` `close`  在这找到的：  https://filippo.io/linux-syscall-table/      

## `open` 函数的系统调用号是多少？ `read` 呢？你是从哪里找到它们的？      
答： 64bit： `open` 2  `read` 0            32bit： `open` 5  `read` 3    在这找到的： https://blog.csdn.net/qq_29343201/article/details/52209588     

## `malloc` 是系统调用吗？为什么？
答： 不是。 malloc这个函数只是调用了几个系统调用来实现分配内存的功能。      

## 你使用什么命令来查看系统调用的文档？
答： man       

## 你觉得学习系统编程会对你有何帮助？
答：我觉得系统编程会让我更加了解操作系统与各硬件之间的工作关系以及运转规则，有力于提升自己的编程能力与理解能力，对于提升软件性能很有帮助。
