### 1. 写出 `dup` 函数的伪代码。
```
int dup2(int oldfd) {
    PCB* current = get_current();
    for (int i = 0;i < 256; ++i) {
    if (flip[i] == null) {
    flip[i] = flip[oldfd];
    flip[i]->count++;
    break;
    }
    return i;
}
```
### 2. 学习本文知识点对你来说有什么困难？

答：刚开始时没有意识到进程与本章任务的关系，走了一些弯路。

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：使用O_APPEND属性后，这个效果只有在你每一次使用write函数时，才会生效，即当你每次调用write时，OS就会把文件的读写位置设置成文件尾部；而你之前做的所有工作，包括你调用lseek函数来修改文件读写位置，到了你每一次调用write函数时，操作系统还是会把读写位置设置成文件尾部！即所有的写操作都只能在文件尾部进行！（这是我在博客上找到的标准答案）


我个人通俗把它理解为每次write的时候都会调用lseek使写入从末尾开始。
