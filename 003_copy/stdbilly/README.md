### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？

答：通过`void perror(const char *s)`函数输出错误信息,`perror()`用来将上一个函数发生错误的原因输出到标准设备(stderr) 。参数 s 所指的字符串会先打印出,后面再加上错误原因字符串,此错误原因依照全局变量`errno` 的值来决定要输出的字符串。 

### 2. 你觉得学习本篇有什么困难？

答：`open`函数的用法,如何选择参数

### 3. 你觉得掌握文件 IO 还能做些什么事情？

答：使用`read`, `write`函数对各种文件类型进行操作,不必关心设备类型

### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？

答: 列出了当前bash进程打开的文件列表

```
COMMAND   PID       USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME
bash    24380 wanghongbo  cwd    DIR   8,25     4096 1572865 /home/wanghongbo
bash    24380 wanghongbo  rtd    DIR   8,24     4096       2 /
bash    24380 wanghongbo  txt    REG   8,24  1113504  654225 /bin/bash
...
bash    24380 wanghongbo    0u   CHR  136,1      0t0       4 /dev/pts/1
```

##### lsof输出各列信息的意义如下：

- COMMAND：进程的名称 
- PID：进程标识符
- USER：进程所有者
- FD：文件描述符，应用程序通过文件描述符识别该文件。如cwd、txt等 TYPE：文件类型，如DIR、REG等
- DEVICE：指定磁盘的名称
- SIZE：文件的大小
- NODE：索引节点（文件在磁盘上的标识）
- NAME：打开文件的确切名称

##### 文件描述符列表：

- cwd：表示current work dirctory，即：应用程序的当前工作目录，这是该应用程序启动的目录，除非它本身对这个目录进行更改
- txt：该类型的文件是程序代码
- mem：memory-mapped file;
- 0：表示标准输出
- 1：表示标准输入
- 2：表示标准错误

##### 一般在标准输出、标准错误、标准输入后还跟着文件状态模式：

- u：表示该文件被打开并处于读取/写入模式
- r：表示该文件被打开并处于只读模式
- w：表示该文件被打开并处于
- 空格：表示该文件的状态模式为unknow，且没有锁定

##### 文件类型：

- DIR：表示目录
- CHR：表示字符类型
- BLK：块设备类型
- UNIX： UNIX 域套接字
- FIFO：先进先出 (FIFO) 队列
- IPv4：网际协议 (IP) 套接字