### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？
答：通过在实现copy过程中可能出错位置进行相应的出错条件打印来获得原因。
### 2. 你觉得学习本篇有什么困难？
答：allen先生的实现源码包含的头文件以前没见过，还有对于`O_CREAT`的第三个权限位也是很迷糊，查到的博客有的是直接大写旗标，但是allen先生的直接是数字权限位。
### 3. 你觉得掌握文件 IO 还能做些什么事情？
答：很多吧，既然电脑设备文件、存储内容、网络等都可以用一个fd描述，那么就可以通过文件函数对其进行各种操作来对其进行修改控制，比如实现常见的文件操作，网络通信等。
### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？
答：
一个进程一个PID一个用户，但是文件描述符有一样也有不一样。
```
进程名称      用户         类型  磁盘名称 大小      索引节点  文件名字
COMMAND  PID USER   FD   TYPE DEVICE  SIZE/OFF     NODE NAME
bash    8927  ypp  cwd    DIR  253,0       195  2301078 /home/ypp/Titans
bash    8927  ypp  rtd    DIR  253,0       224       64 /
bash    8927  ypp  txt    REG  253,0    964608 50346809 /usr/bin/bash
bash    8927  ypp  mem    REG  253,0     61624   363681 /usr/lib64/libnss_files-2.17.so
bash    8927  ypp  mem    REG  253,0 106075056   363642 /usr/lib/locale/locale-archive
bash    8927  ypp  mem    REG  253,0   2151672   363663 /usr/lib64/libc-2.17.so
bash    8927  ypp  mem    REG  253,0     19288   363669 /usr/lib64/libdl-2.17.so
bash    8927  ypp  mem    REG  253,0    174576   156312 /usr/lib64/libtinfo.so.5.9
bash    8927  ypp  mem    REG  253,0    163400    75703 /usr/lib64/ld-2.17.so
bash    8927  ypp  mem    REG  253,0     26254 16878900 /usr/lib64/gconv/gconv-modules.cache
bash    8927  ypp    0u   CHR  136,0       0t0        3 /dev/pts/0
bash    8927  ypp    1u   CHR  136,0       0t0        3 /dev/pts/0
bash    8927  ypp    2u   CHR  136,0       0t0        3 /dev/pts/0
bash    8927  ypp  255u   CHR  136,0       0t0        3 /dev/pts/0
```
