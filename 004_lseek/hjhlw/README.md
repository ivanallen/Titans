### 1. 写出 `dup` 函数的伪代码。

    int dup(int oldfd) {
        PCB *current = get_current();
        for (int i = 0; i < 256; ++i) {
            if (current->filp[i] == NULL) {
                current->filp[i] = current->filp[oldfd];
                return i;
            }
        }
        return -1;
    }

### 2. 学习本文知识点对你来说有什么困难？

答：file结构体中的m_inode不太理解怎么回事,看了关于inode节点的相关资料，还是有点模糊.

### 3. 你能理解 `open` 函数 flags 标志位 `O_APPEND` 是如何实现的吗？

答：应该就是通过改变f_pos(当前偏移量)实现的.
