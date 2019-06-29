### 1. 写出 `dup` 函数的伪代码。
int dup(int oldfd){
    //...
    PCB* current = get_current();
    for (int i=1; i<256; i++){
        if(current->filp[i] == NULL){
           current->filp[i] = current->filp[oldfd];
           current->filp[i] = count++; 
           return i;
        }
    }
    return -1;
} 
### 2. 学习本文知识点对你来说有什么困难？
答：因为是对这方面知识只是涉及一点点，所以问题还是挺多。
### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？
答：通过设置lseek偏移量，将它设置到末尾去，然后使用write函数。
