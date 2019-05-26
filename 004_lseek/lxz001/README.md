### 1. 写出 `dup` 函数的伪代码。

{{在这里写你的代码}}
int dup(int oldfd){
    //...
    for (int n = 0; n < 256; ++n){
        if (filp[n] == NULL){
            filp[n] = filp[oldfd];
            flip[n]->count++;
            return n;
        }
    }
    return -1;
}

### 2. 学习本文知识点对你来说有什么困难？

答：还好，相关概念也挺熟悉的。

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：打开文件后，每次执行写入write的时候，将pos先移动到文件末尾,写完后也会保持在末尾。
