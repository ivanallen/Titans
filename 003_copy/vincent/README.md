
### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？

答：通过打印errno对应的字符串找到出错原因。比如对于`open`调用, 我们可以用下面这段代码来打印出错原因

```C
if ((fd = open(filename, O_RDONLY)) < 0) {
    perror("open");
    return -1;
}
```

### 2. 你觉得学习本篇有什么困难？

答：
- 内核是怎么管理文件的？fd在内核里面真的是数组索引吗？
- lsof -p 打印出来的内容不是很理解，各个列分别是什么意思？

### 3. 你觉得掌握文件 IO 还能做些什么事情？

答：使用`read`、`write`可以实现很多常用的`linux`命令，如`cat`、`echo`、`pwd`等。

### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？

答: 可以看到bash进程打开的文件列表(包括文件名，文件大小，文件类型，fd等)。第一个文件的fd是cwd，表示当前工作目录current working directory。同时bash进程还打开了3个文件，描述符分别是0，1，2分别表示标准输入、标准输出和标准错误。一般情况下，这三个文件其实是同一个，指向显示器。

```
bash    2231 root  cwd    DIR  253,0        99 34337600 /mnt/hgfs
...
bash    2231 root    0u   CHR  136,0       0t0        3 /dev/pts/0
bash    2231 root    1u   CHR  136,0       0t0        3 /dev/pts/0
bash    2231 root    2u   CHR  136,0       0t0        3 /dev/pts/0
```