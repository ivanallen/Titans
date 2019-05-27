### 1. 写出 `dup` 函数的伪代码。

```c
int dup(int oldfd) {
    // ...
    PCB* current = get_current();
    for (int i = 0; i < 256; ++i) {
        if (current->filp[i] == NULL) {
            current->filp[i] = current->filp[oldfd];
            current->filp[i]->f_count++;
            return i;
        }
    }
    //...
    return -1;
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：目前看来还好。

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：`O_APPEND` 表示每次写时都追加到文件的尾端，主要确保写入`fd`时是原子操作，确保内核每次对文件进行写入之前，都是将进程的当前偏移量设置到该文件的尾端处。所以在每次写之前不需要再调用`lseek`，否则应该在`write`先调用`lseek`。
