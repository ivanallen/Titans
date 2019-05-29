### 1. 写出 `dup` 函数的伪代码。

```c
int dup(int oldfd) {
    int i;
    for (i = 0; i < 256; ++i) {
        if (flip[i] == NULL) {
            flip[i] = flip[oldfd];
            ++flip[i] -> count;
            return i;
        }
    }
    return -1;
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：如何运用lseek获取文件长度

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：根据 `man 2 open`   
#### O_APPEND ####
The  file  is opened in append mode.  Before each `write(2)`,  
the file offset is positioned at the end of the file, as if  
with `lseek(2)`.  
...  
先通过 `lseek` 将偏移量设置在文件末尾，然后通过 `write` 函数实现 append 功能
