### 1. 写出 `dup` 函数的伪代码。

```c
int dup(int oldfd) {
	PCB* current = get_current(); 
    for (int i = 0; i < 256; ++i) {
        if(current->flip[i] == null) {
            current->flip[i] = current->flip[oldfd];
            current->flip[i]->count++;
            return i;
        }
    }
    return -1;
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：如何使用`lseek`函数

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：通过查阅文档

The file is opened in append mode.  Before each `write(2)`, the file offset is positioned at the end of the file, as if with `lseek(2)`.  The modification of the file offset and the write operation are performed as a single atomic step.

通过`lseek`函数重定位`offset`至文件末尾, 通过`write`函数在文件末尾写入