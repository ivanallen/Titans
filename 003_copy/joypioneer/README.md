
### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，你如何找出出错的原因？

答：通过打印errno定位原因，errno是记录系统的最后一次错误代码。

### 2. 你觉得学习本篇有什么困难？

答：文件描述符到底是干嘛的？可以访问什么类型的文件？linux内核到底怎么管理文件系统的。
### 3. 你觉得掌握文件 IO 还能做些什么事情？

答：使用`read`、`write`可实现其他常用的`linux`命令，网络中读写数据等等。

### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？

答: bash进程打开的文件列表(包括文件名，文件大小，文件类型，文件描述符fd等)。第一个文件的fd是cwd（current work directory）即：应用程序的当前工作目录 。同时bash进程还打开了3个文件，描述符分别是0，1，2分别表示标准输入、标准输出和标准错误。一般情况下，这三个文件其实是同一个，指向显示器。

```
COMMAND  PID    USER   FD   TYPE DEVICE SIZE/OFF      NODE NAME
bash      4655 root  cwd    DIR    8,1     4096  79955133 /mnt/hgfs
...
bash      4655 root  255u   CHR 136,11      0t0        14 /dev/pts/11
```

```
-a：列出打开文件存在的进程；
-c<进程名>：列出指定进程所打开的文件；
-g：列出GID号进程详情；
-d<文件号>：列出占用该文件号的进程；
+d<目录>：列出目录下被打开的文件；
+D<目录>：递归列出目录下被打开的文件；
-n<目录>：列出使用NFS的文件；
-i<条件>：列出符合条件的进程。（4、6、协议、:端口、 @ip ）
-p<进程号>：列出指定进程号所打开的文件；
-u：列出UID号进程详情；
-h：显示帮助信息；
-v：显示版本信息。

lsof输出各列信息的意义如下：
COMMAND：进程的名称
PID：进程标识符
PPID：父进程标识符（需要指定-R参数）
USER：进程所有者
PGID：进程所属组
FD：文件描述符，应用程序通过文件描述符识别该文件。
文件描述符列表：

cwd：表示current work dirctory，即：应用程序的当前工作目录，这是该应用程序启动的目录，除非它本身对这个目录进行更改
txt：该类型的文件是程序代码，如应用程序二进制文件本身或共享库，如上列表中显示的 /sbin/init 程序
lnn：library references (AIX);
er：FD information error (see NAME column);
jld：jail directory (FreeBSD);
ltx：shared library text (code and data);
mxx ：hex memory-mapped type number xx.
m86：DOS Merge mapped file;
mem：memory-mapped file;
mmap：memory-mapped device;
pd：parent directory;
rtd：root directory;
tr：kernel trace file (OpenBSD);
v86 VP/ix mapped file;
0：表示标准输出
1：表示标准输入
2：表示标准错误

一般在标准输出、标准错误、标准输入后还跟着文件状态模式：
u：表示该文件被打开并处于读取/写入模式。
r：表示该文件被打开并处于只读模式。
w：表示该文件被打开并处于。
空格：表示该文件的状态模式为unknow，且没有锁定。
-：表示该文件的状态模式为unknow，且被锁定。

同时在文件状态模式后面，还跟着相关的锁：
N：for a Solaris NFS lock of unknown type;
r：for read lock on part of the file;
R：for a read lock on the entire file;
w：for a write lock on part of the file;（文件的部分写锁）
W：for a write lock on the entire file;（整个文件的写锁）
u：for a read and write lock of any length;
U：for a lock of unknown type;
x：for an SCO OpenServer Xenix lock on part of the file;
X：for an SCO OpenServer Xenix lock on the entire file;
space：if there is no lock.

文件类型：
DIR：表示目录。
CHR：表示字符类型。
BLK：块设备类型。
UNIX： UNIX 域套接字。
FIFO：先进先出 (FIFO) 队列。
IPv4：网际协议 (IP) 套接字。
DEVICE：指定磁盘的名称
SIZE：文件的大小
NODE：索引节点（文件在磁盘上的标识）
NAME：打开文件的确切名称

```

