
### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？

答：
    方法1：通过打印语句，输出对应的错误信息。
    方法2：通过GDB调试。

### 2. 你觉得学习本篇有什么困难？

答：
    代码格式，因为虽然知道有这种风格的代码格式，但是一直没有这样写过，所以，写代码的时候感觉有点不适应。

### 3. 你觉得掌握文件 IO 还能做些什么事情？

答：使用`read`、`write`可以实现很多常用的`linux`命令，如`cat`、`echo`、`pwd`等。

### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？

答: 可以看到bash进程打开的文件列表(包括文件名，文件大小，文件类型，fd等)。
    第一个文件的fd是cwd，表示当前工作目录current working directory。同时bash进程还打开了3个文件，描述符分别是0，1，2分别表示标准输入、标准输出和标准错误。一般情况下，这三个文件其实是同一个，指向显示器。

```
COMMAND  PID USER   FD   TYPE DEVICE SIZE/OFF   NODE NAME
bash    7841 tdrh  cwd    DIR   0,42        0      8 /mnt/hgfs/Linux_Shared/LocationRepository/Titans/003_copy/tiandirenhe
bash    7841 tdrh  rtd    DIR    8,6     4096      2 /
bash    7841 tdrh  txt    REG    8,6  1037528 402136 /bin/bash
bash    7841 tdrh  mem    REG    8,6    47600 791722 /lib/x86_64-linux-gnu/libnss_files-2.23.so
bash    7841 tdrh  mem    REG    8,6    47648 791702 /lib/x86_64-linux-gnu/libnss_nis-2.23.so
bash    7841 tdrh  mem    REG    8,6    93128 791720 /lib/x86_64-linux-gnu/libnsl-2.23.so
bash    7841 tdrh  mem    REG    8,6    35688 791726 /lib/x86_64-linux-gnu/libnss_compat-2.23.so
bash    7841 tdrh  mem    REG    8,6  4763056   1660 /usr/lib/locale/locale-archive
bash    7841 tdrh  mem    REG    8,6  1868984 791725 /lib/x86_64-linux-gnu/libc-2.23.so
bash    7841 tdrh  mem    REG    8,6    14608 791697 /lib/x86_64-linux-gnu/libdl-2.23.so
bash    7841 tdrh  mem    REG    8,6   167240 792135 /lib/x86_64-linux-gnu/libtinfo.so.5.9
bash    7841 tdrh  mem    REG    8,6   162632 791698 /lib/x86_64-linux-gnu/ld-2.23.so
bash    7841 tdrh  mem    REG    8,6   102200 529717 /usr/share/locale-langpack/zh_CN/LC_MESSAGES/bash.mo
bash    7841 tdrh  mem    REG    8,6    26258 147456 /usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache
bash    7841 tdrh    0u   CHR  136,4      0t0      7 /dev/pts/4
bash    7841 tdrh    1u   CHR  136,4      0t0      7 /dev/pts/4
bash    7841 tdrh    2u   CHR  136,4      0t0      7 /dev/pts/4
bash    7841 tdrh  255u   CHR  136,4      0t0      7 /dev/pts/4

```
