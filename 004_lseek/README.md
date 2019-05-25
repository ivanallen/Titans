## 004_lseek

写完上一节的 `mycp` 命令，相信你已经想迫不及待的想了解更多关于文件相关的知识。比如你在使用 `open` 函数的时候，你可能对第三个参数 `0666` 感到费解，也许你在执行程序的过程中遇到各种奇奇怪怪的错误，比如 "Permisson denied" 之类的问题。

总之，不要过于心急，慢慢的一切神秘的面纱都会为你揭开。

在这一篇，你会再次深入的了解到关于 fd 更多的奥秘。上一个 task 里，你是否有对 `read` 和 `write` 的执行原理感到半知半解？

- `read` 是如何记住它读到文件的哪个位置的？换句话说，每次你调用 `read` 函数，为什么不是从文件头部开始重新读取，而是接着上一次读取的位置读取若干字节？
- `write` 函数是如何记住它写入的位置？换句话说，每次你调用 write 的时候，为什么不是从文件头部开始写入，而是从上次写入的位置往后追加写入？

也许你并没有认真思考过上面的问题，只是觉得这是一件很自然的事情。但是这确实是一个值得深思的问题。请你花 2 分钟，认真思考一下，为什么 `read`，`write` 能这样？

好了，为了能讲清楚这件事，我们得再弄出一个新名词——文件偏移量。

### 1. 文件描述符

你可能会问，上一篇不是写过么？是的，不过这次我们再深挖一下 fd 在内核中是怎么表示的。

上一节我们说过，当你使用 `open` 函数的时候，会返回一个 `fd` 值，而这个 `fd` 实际上是内核中某个数组的索引。这个数组到底是什么呢？也许它长成这样：

```c
struct PCB {
    int pid; // 进程号
    struct file* filp[256]; // 进程打开的文件
    // 其它字段
}
```

其中 PCB 表示进程控制块结构体。在这个结构中，有一个类型为 `struct file*` 的数组，名为 `filp`，它的默认大小是 256。

这绝对不是我杜撰的。在早期的内核中，确实是这样表示。那 `open` 函数是怎么工作的呢？

```c
int open(const char* filename, int flags, int mode) {
    struce file* f = (struct file*)malloc(sizeof(struct file));
    // 为 f 填充字段
    // ...
    // 取到当前进程 PCB
    PCB* current = get_current();
    for (int i = 0; i < 256; ++i) {
        if (current->filp[i] == NULL) {
            current->filp[i] = f;
            return i;
        }
    }
    return -1;
}
```

上面的 `open` 函数，首先分配一个 `struct file` 类型的结构体，然后从当前进程的 `filp` 数组中找一个空闲位置，把分配的指针复制进去，同时返回了这个空闲位置的索引号。

当然，实际内核的 `open` 实现比这个复杂多了，它还要干太多太多的事情。不过对我们来说，了解到 `open` 返回值是什么就足够。

也许你更加期待的是 `struct file` 的定义，不是吗？马上就来了：

```c
struct file {
    unsigned short f_mode; // 文件权限位
    unsigned short f_flags; // 文件状态位
    unsigned short f_count; // 引用计数
    struct m_inode * f_inode; // 文件存在磁盘上的哪个位置等等其它信息由这个字段来解释
    off_t f_pos; // 当前偏移量， off_t 可以理解成 int
};
```

看起来似乎很容易，因为 `f_mode` 和 `f_flags` 看起来你都认识，因为 `open` 函数的参数就有，大致上它们的含义是一样的。

`f_inode` 字段会保存关于文件存储在磁盘上的位置信息，而 `f_pos` 就是本篇我们要讲的**文件偏移量**，稍后在第 2 节我们会详述。

唯一你可能比较费解的是 `f_count`，它表示当前这个 `struct file` 同时有几个 fd 指向它。比如 `filp[5]` 和 `filp[10]` 这两个元素的值是一样的，也就是它们指向同一个 `struct file` 对象。有人会问，这怎么可能，`open` 函数不是每次都会分配一个新的 `fd` 吗？是的，但是 Linux 中存在一些函数，可以复制 fd，比如 `dup`，`dup2` 函数。一个 `dup2` 函数可能实现如下：

```c
int dup2(int oldfd, int newfd) {
    // ...
    close(newfd);
    flip[newfd] = flip[oldfd];
    flip[newfd]->count++;
    //...
    return 0;
}
```

看明白了吧？这就是 dup2 函数所做的事情，同样还有 `dup` 函数，它的实现是怎样的呢？这里把它留做习题。

### 2. 文件偏移量

既然 `fd` 是 `flip` 数组的索引号，那一切就好办了，比如 `read` 函数，它可以写成这样：

```c
int read(fd, char* buf, int size) {
    PCB* current = get_current();
    struct file* f = current->filp[fd];
    off_t pos = f->f_pos;

    // 接下来，可以根据 f->f_inode 找到磁盘上的数据，向后数 pos 个字节，开始读取数据
    char* data = get_data(f->f_inode);
    int length = get_length(f->f_inode);
    int left = length - pos; // 还剩余多少字节
    int read_size = min(size, left);
    memcpy(buf, data + pos, read_size);
    f->f_pos += read_size; // 更新 f_pos
    return min(size, left);
}
```

上面是我写的一个非常非常粗糙的版本，但足以描述 `read` 读取文件的原理，我希望你看到的是 `read` 如何使用 `f_pos` 的。

有没有一种办法，直接更改这个 f_pos 呢？Linux 提供了另一个系统调用 lseek 就能做到。

### 3. lseek

```c
off_t lseek(int fd, off_t offset, int whence);
```

上面是 `lseek` 的函数原型，它的目的就是修改 `f_pos` 的值。

当用 `open` 函数打开一个文件的时候，该偏移量 `f_pos` 被默认指定为 0。

- 如果 `whence` 等于 `SEEK_SET`，则 `f_pos = offset`（`offset` 只能是正数）
- 如果 `whence` 等于 `SEEK_CUR`, 则 `f_pos = f_pos + offset`（`offset` 可正可负）
- 如果 `whence` 等于 `SEEK_END`，则 `f_pos = 文件长度 + offset` （`offset` 可正可负）

返回值的含义，请你自己查阅文档，了解其含义。

### 4. 任务

最终你的文件夹内容如下：

```
{{YOUR_NAME}}
├── README.md
├── Makefile
└── mycp2.c
```

#### 4.1 编程

**在这个任务里，你不必再写自己的 Makefile，把 `allen/Makefile` 复制到你的文件夹下面就行了。** 但是请你不要复制我写的 mycp2.c 文件。

- 编写程序 `mycp2`，这个程序只 copy 文件的后一半内容。

例如：原始文件 srcfile 内容为

```
Hello world!
```

执行 `./mycp2 srcfile file` 后，file 的内容为：

```
world!
```

**注意：你 copy 出来的 file 文件大小，一定刚好为 srcfile 大小的一半，或者比 srcfile 的一半多出一个字节（如果 srcfile 是奇数个字节。）**

### 4.2 问答

请你创建一个 README.md 文件放到你的目录，复制以下内容进去，并回答。（当然你的回答不能与我的示例回答相同。）

```
### 1. 写出 `dup` 函数的伪代码。

{{在这里写你的代码}}

### 2. 学习本文知识点对你来说有什么困难？

答：xxx

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：xxx
```

### 5. 扩展阅读

[这里](https://blog.csdn.net/q1007729991/article/details/52564810)提供更多关于文件描述符和 lseek 的资料，可以参考阅读。
