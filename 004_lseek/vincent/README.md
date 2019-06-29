
### 1. 写出 `dup` 函数的伪代码。

```c
int dup(int fd)
{
    PCB* current = get_current();
    for (int i = 0; i < 256; ++i) {
        if (current->filp[i] == NULL) {
            current->flip[fd]->count++;
            current->filp[i] = current->flip[fd];
            return i;
        }
    }
    return -1;
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：调用write覆盖某文件是怎么实现的？

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：在`open`函数中也许会检查`O_APPEND`标志位，如果置位，就调用`lseek`函数将`f_pos`调整到文件末尾。
```c
int open(const char *pathname, int flags, mode_t mode);
{
    if (flags & O_APPEND) {
        lseek(fd, 0L, SEEK_END);
    }
}
```
