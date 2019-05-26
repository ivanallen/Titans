
### 1. 写出 `dup` 函数的伪代码。
```cpp
//dup函数返回当前系统可用的最小整数值。dup2函数返回第一个不小于newfd的整数值。

int dup(int oldfd){
    //...
    PCB* current = get_current();
    for ( int i=1; i<256; i++){
        if(current->filp[i] == NULL){
           current->filp[i] = current->filp[oldfd] + 1;
           return i;
        }
    }
    return -1;
}
```
### 2. 学习本文知识对你有什么困难？
答：本章清楚地认识到了文件指针在几个文件I/O函数中的重要作用，挺好理解的。但结构体需要加深理解，基础不好。
### 3. 你能理解 `open` 函数 `flags` 标志位 `O_APPEND' 是如何实现的吗？
答：`O_APPEND` 表示追加。如果文件 已有内容，这次打开文件所写的数据附件到文件末尾而不覆盖原来的内容。因为 `write` 函数调用执行后文件指针总是在文件尾部。