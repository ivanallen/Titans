### 1. 写出 `dup` 函数的伪代码。
```
int dup(int oldfd) {
    PCB* cur = get_current(); //获取当前进程
    for (int i = 0; i < 256; ++i) {
    if (cur->flip[i] == null) {//找到空的flip
        cur->flip[i] = cur->flip[oldfd];
        cur->flip[i]->count++;
        return i;
    }
    return -1;
}
```
### 2. 学习本文知识点对你来说有什么困难？

答：就是`lseek`函数其实可以拿来算文件的长度的，但是一开始我一直在纠结该怎么得到文件长度，回头看才发现`lseek`第三参数的妙用。

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：`0_APPEND`表示以追加的方式打开文件。实现应该就是识别传来的`0_APPEND`参数设置，用`lseek`将偏移量设置到末尾。
