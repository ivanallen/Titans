### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？
答：通过perror来判断错误位置。
### 2. 你觉得学习本篇有什么困难？
答：open、read函数需要对照allen的那篇博客来写，并且对于argc为什么与3作比较感到很疑惑，不过通过查资料明白了点。因为对于这个不是很熟悉，所以都算看着allen的博客一步步来的，感觉大致明白，但是要去细究绝对漏洞百出。
### 3. 你觉得掌握文件 IO 还能做些什么事情？
答：本地存档，读档；最近学校实习做管理系统也有一部分关于IO方面的，感觉以后后端开发，磁盘信息储存应该是息息相关，暂且只知道这些。
### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？
答：前三个文件描述符不一样，后面都是一样的；其他的实在不知道有什么特殊的地方，对这个实在不算很懂。

COMMAND  PID  USER   FD   TYPE DEVICE SIZE/OFF    NODE NAME

bash    4864 sswhg  cwd    DIR    8,1     4096  801821 /home/sswhg/桌面/sswhg/Titans/003_copy/sswhg

bash    4864 sswhg  rtd    DIR    8,1     4096       2 /

bash    4864 sswhg  txt    REG    8,1  1235608  262153 /bin/bas

bash    4864 sswhg  mem    REG    8,1   147601  279533 /usr/share/locale-langpack/zh_CN/LC_MESSAGES/bash.mo

bash    4864 sswhg  mem    REG    8,1    50784  919477 /lib/i386-linux-gnu/libnss_files-2.27.so

bash    4864 sswhg  mem    REG    8,1    96064  919471 /lib/i386-linux-gnu/libnsl-2.27.so

bash    4864 sswhg  mem    REG    8,1    50796  919487 /lib/i386-linux-gnu/libnss_nis-2.27.so

bash    4864 sswhg  mem    REG    8,1    34608  919473 /lib/i386-linux-gnu/libnss_compat-2.27.so

bash    4864 sswhg  mem    REG    8,1 10756928 1190195 /usr/lib/locale/locale-archive

bash    4864 sswhg  mem    REG    8,1  1942840  919389 /lib/i386-linux-gnu/libc-2.27.so

bash    4864 sswhg  mem    REG    8,1    13796  919412 /lib/i386-linux-gnu/libdl-2.27.so

......
