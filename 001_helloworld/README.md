## Hello world 测试

你的第一个任务，就是创建一个 Hello world 程序，并提交到这里。我们的目的是测试你的环境。

你不需要理解 Makefile 这些是做什么的，也不要试图去搜索。必要的时候，你们会懂的。本次任务，你只要按照提示，提交你的代码即可。记住，请不要把编译后生成的 hello_world 二进制程序提交上来。

### 1. 要求

请以你的名字为文件夹，并在这个文件夹里创建以下文件：

```c
{Your Name}
├── Makefile
├── hello_world
└── hello_world.c
```

**重要**：

- 源码文件格式使用 4 空格缩进。
- 不要把你的二进制文件提交上来。
- 两个文件缺一不可。

### 2. 提示

#### 2.1 环境

请先安装 Linux 操作系统，Ubuntu 16 及以上 或者 Centos 7

#### 2.2 程序

- 源文件

```c
// hello_world.c
#include <stdio.h>

int main() {
    printf("Hello world\n");
    return 0;
}
```

- Makefile

```
hello_word:hello_world.c
    gcc -o $@ $<
```

- 运行方法

```
$ make
$ ./hello_world
```
