### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？

答：在系统调用执行错误时，首先系统调用函数返回-1。然后系统会更新设置全局变量errno。每种错误都有它自己的常量值，通过查阅手册资料等方式来判断errno的值代表哪种错误，然后定位错误。

### 2. 你觉得学习本篇有什么困难？

答：对于文件描述符，我的理解是，它是对于每一个模块（想象出来的）的编号。像普通文件，套接字，还有其他我还不熟悉的东西，他们都拥有特定的功能，例如普通文件就是用来存放数据，套接字就是用来通信的（可能不正确）。
在本篇的学习中，我的困难是 不是很理解文件描述符它在系统调用和系统中的具体工作流程

### 3. 你觉得掌握文件 IO 还能做些什么事情？

答：我认为可以使用 `read`，`write` 去写网络程序，开发服务器。掌握文件 IO 就能对系统的所有文件进行读写，还有通过套接字对远端的服务器/客户端发送信息。掌握文件 IO 是每个后端开发程序员必备技能。

### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？

答：我发现结果中分为这几项数据：COMMAND  PID  USER  FD   TYPE  DEVICE  SIZE/OFF  NODE  NAME。
其中 COMMAND这一项都是bash。PID都是50931，也就是我刚刚ps得到的第一个PID。USER都是he，也就是我的用户名。DEVICE都是8,1。其他项各有不同。
查阅资料发现，`lsof -p ${PID}`的作用是列出指定进程号所打开的文件，所以上面的输出结果就是列出当前bash进程打开的所有文件。
如下是网上找到的关于lsof命令的相关信息：

COMMAND：进程的名称

PID：进程标识符

PPID：父进程标识符（需要指定-R参数）

USER：进程所有者

PGID：进程所属组

FD：文件描述符，应用程序通过文件描述符识别该文件。如cwd、txt等

（1）cwd：表示current work dirctory，即：应用程序的当前工作目录，这是该应用程序启动的目录，除非它本身对这个目录进行更改

（2）txt ：该类型的文件是程序代码，如应用程序二进制文件本身或共享库，如上列表中显示的 /sbin/init 程序

（3）lnn：library references (AIX);

（4）er：FD information error (see NAME column);

（5）jld：jail directory (FreeBSD);

（6）ltx：shared library text (code and data);

（7）mxx ：hex memory-mapped type number xx.

（8）m86：DOS Merge mapped file;

（9）mem：memory-mapped file;

（10）mmap：memory-mapped device;

（11）pd：parent directory;

（12）rtd：root directory;

（13）tr：kernel trace file (OpenBSD);

（14）v86  VP/ix mapped file;

（15）0：表示标准输出

（16）1：表示标准输入

（17）2：表示标准错误

一般在标准输出、标准错误、标准输入后还跟着文件状态模式：r、w、u等

（1）u：表示该文件被打开并处于读取/写入模式

（2）r：表示该文件被打开并处于只读模式

（3）w：表示该文件被打开并处于

（4）空格：表示该文件的状态模式为unknow，且没有锁定

（5）-：表示该文件的状态模式为unknow，且被锁定

同时在文件状态模式后面，还跟着相关的锁

（1）N：for a Solaris NFS lock of unknown type;

（2）r：for read lock on part of the file;

（3）R：for a read lock on the entire file;

（4）w：for a write lock on part of the file;（文件的部分写锁）

（5）W：for a write lock on the entire file;（整个文件的写锁）

（6）u：for a read and write lock of any length;

（7）U：for a lock of unknown type;

（8）x：for an SCO OpenServer Xenix lock on part      of the file;

（9）X：for an SCO OpenServer Xenix lock on the      entire file;

（10）space：if there is no lock.

TYPE：文件类型，如DIR、REG等，常见的文件类型

（1）DIR：表示目录

（2）CHR：表示字符类型

（3）BLK：块设备类型

（4）UNIX： UNIX 域套接字

（5）FIFO：先进先出 (FIFO) 队列

（6）IPv4：网际协议 (IP) 套接字

DEVICE：指定磁盘的名称

SIZE：文件的大小

NODE：索引节点（文件在磁盘上的标识）

NAME：打开文件的确切名称

参考链接：https://www.cnblogs.com/peida/archive/2013/02/26/2932972.html
