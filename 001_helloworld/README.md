### Hello world 测试

你的第一个任务，就是创建一个 Hello world 程序，并提交到这里。我们的目的是测试你的环境。

#### 1. 要求

请以你的名字为文件夹，并在这个文件夹里创建以下文件：

```c
|-- {Your name}
  |-- hello_world.c
  |-- Makefile
```

#### 2. 提示

##### 2.1 环境

请先安装 Linux 操作系统，Ubuntu 16 及以上 或者 Centos 7

##### 2.2 程序

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
