### 1. 如果 open 或者另外几个相关的系统调用执行出错，你如何找出出错的原因？

借助perror(s) 函数，perror(s) 用来将上一个函数发生错误的原因输出到标准设备(stderr)。参数 s 所指的字符串会先打印出，后面再加上错误原因字符串。错误的编号是放在 errno 中, perror 会去自动调用 errno 的错误提示。

比如：
```c
perror("/root/noexitfile");
```
可能输出:
```c
/root/noexitfile: No such file or directory
```

### 2. 你觉得学习本篇有什么困难？

以前就接触文件IO，知道这个概念，并不知道像 read, write 函数是如何实现的，如何统一接口；很多概念不能连起来，比如文件描述符和进程控制块。知道perror函数与error，现在查资料得知 perror 会去自动调用 errno 的错误提示。

### 3、你觉得掌握文件 IO 还能做些什么事情？

用到文件 IO 的地方非常多，可以用来操作设备，在共享内存中，对共享内存的读写需要文件 IO，网络编程中对套接字的读写需要文件 IO，有了文件 IO 的基础，便于学习 IO 多路复用和异步 IO。Linux中有些命令是使用文件 IO，如cat。

### 4、在你的终端执行命令 ps，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 lsof -p ${PID}，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 lsof 执行的输出结果。描述你看到的现象，你发现了什么？

```
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME
bash    4964  skx  cwd    DIR    8,1     4096  786434 /home/skx
bash    4964  skx  rtd    DIR    8,1     4096       2 /
bash    4964  skx  txt    REG    8,1  1113504 1835015 /bin/bash
……
bash    4964  skx  mem    REG    8,1    26376 1180617 /usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache
bash    4964  skx    0u   CHR  136,0      0t0       3 /dev/pts/0
bash    4964  skx    1u   CHR  136,0      0t0       3 /dev/pts/0
bash    4964  skx    2u   CHR  136,0      0t0       3 /dev/pts/0
bash    4964  skx  255u   CHR  136,0      0t0       3 /dev/pts/0
```

lsof 是 一个系统级的监控、诊断工具。意思为 List Open Files，lsof -p -p<进程号>：表示列出指定进程号所打开的文件。

#### 输出结果每个分量意义如下：

- COMMAND：进程的名称 PID：进程标识符
- PID：进程标识符
- PPID：父进程标识符（需要指定-R参数）
- USER：进程所有者
- PGID：进程所属组
- FD：文件描述符，应用程序通过文件描述符识别该文件。
- TYPE：文件类型，如DIR（目录）、REG，CHR（字符类型）等
- DEVICE：指定磁盘的名称
- SIZE：文件的大小
- NODE：索引节点（文件在磁盘上的标识）
- NAME：打开文件的确切名称

#### 文件描述符列表：

- cwd：当前工作目录（current work dirctory）
- rtd：root directory;
- txt：程序代码
- mem：内存映射文件（memory-mapped file）
- 0：标准输出（）
- 1：标准输入
- 2：标准错误