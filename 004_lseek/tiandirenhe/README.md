### 4.2 问答

### 1. 写出 `dup` 函数的伪代码。

{{在这里写你的代码}}
```
int dup(int oldfd) {
    //...
    PCB* current = get_current();// 取到当前进程 PCB
    for (int i = 0; i < 256; ++i) {//遍历filp数组，找到第一个（值最小的）空闲位置，并将filp[oldfd]所指向的文件表赋值给空闲的filp[i]，就是说，filp[i]和filp[oldfd]指向同一个文件。
        if (current->filp[i] == NULL) {
            current->filp[i] = current->filp[oldfd]；
            current->flip[i]->count++;
            return i;//成功找到则返回索引值，即新的文件描述符的索引值
        }  
    }
    return -1;//失败则返回-1              
}
```

### 2. 学习本文知识点对你来说有什么困难？

答：没有困难

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：使用了O_APPEND标志打开一个文件，则相应标志也被设置到文件表项的文件状态标志中。每次对这种具有添写标志的文件执行写操作时，
    在文件表项中的当前文件偏移量首先被置为i节点表项中的文件长度。这就使得每次写的数据都添加到文件的当前尾端处。
    使用O_APPEND属性后，这个效果只有在你每一次使用write函数时，才会生效，即当你每次调用write时，OS就会把文件的读写位置设置成文件尾部；而你之前做的所有工作，包括你调用lseek函数来修改文件读写位置，到了你每一次调用write函数时，
    操作系统还是会把读写位置设置成文件尾部！即所有的写操作都只能在文件尾部进行！
```    
int open(const char* filename, int flags, int mode) {
    struce file* f = (struct file*)malloc(sizeof(struct file));
    if (NULL == f) {
        return -1;    
    }
    // 为 f 填充字段
    f->f_flags  = flags;//假如此时flags为O_APPEND
    // ...
    // 取到当前进程 PCB
    PCB* current = get_current();
    for (int i = 0; i < 256; ++i) {
        if (current->filp[i] == NULL) {
            current->filp[i] = f;//其实就是将文件的标志位信息写入文件表中，OPen函数返回其文件描述符索引值，将来在write操作的时候，根据flags标志，设置off_t f_pos; （当前偏移量），到文件的尾部，这样就保证了每次写入数据都是从文件尾部开始。
            return i;
        }
    }
    return -1;
}
``` 
