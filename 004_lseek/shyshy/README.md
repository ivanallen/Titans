
### 1. 写出 `dup` 函数的伪代码。
```cpp
    /**dup用来复制参数oldfd所指的文件描述符，  
    当复制成功是，返回最小的尚未被使用过的文件描述符，若有错误则返回-1。  
    错误代码存入errno中返回的新文件描述符和参数oldfd指向同一个文件，  
    这两个描述符共享同一个数据结构，共享所有的锁定，读写指针和各项全现或标志位。
    **/

int dup(int oldfd){
    //...
    PCB* current = get_current();
    for ( int i=1; i<256; i++){
        if(current->filp[i] == NULL){
           current->filp[i] = current->filp[oldfd];
           f = count++;
           current->filp[i] = f; 
           return i;
        }
    }
    return -1;
}
    /**dup2与dup区别是dup2可以用参数newfd指定新文件描述符的数值。  
    若参数newfd已经被程序使用，则系统就会将newfd所指的文件关闭，若newfd等于oldfd，则返回newfd。  
    而不关闭newfd所指的文件。dup2所复制的文件描述符与原来的文件描述符共享各种文件状态。  
    共享所有的锁定，读写位置和各项权限或flags等.
    **/
```
### 2. 学习本文知识对你有什么困难？
答：本章清楚地认识到了文件指针在几个文件I/O函数中的重要作用，挺好理解的。但结构体需要加深理解，基础不好。
### 3. 你能理解`open`函数`flags`标志位`O_APPEND`是如何实现的吗？
答：`O_APPEND`表示追加。如果文件已有内容，这次打开文件所写的数据附加到文件末尾而不覆盖原来的内容。  
    因为`write`函数调用执行后文件指针总是在文件尾部。
