## Makefile

### 介绍

在我们整个项目中，将会大量使用 Makefile 这个工具对你的源码进行构建。很多同学可能不知道 Makefile 的工作原理，这里只作简单介绍。

本质上，Makefile 是一个自动执行任务的工具，无论是构建任务（编译），还是其它什么任务（比如执行某个命令），都没有问题。Makefile 强大的地方在于它能自动处理依赖关系。比如你要学习概率论，那你得先学习完高等数学才行，在 Makefile 里怎么表示呢？下面是一个简单的例子:

```makefile
概率论：高等数学
    Learn 概率论

高等数学：基础数学
    Learn 高等数学

基础数学：
    Learn 基础数学
```

再来一个，下面是一个可以运行的 Makefile 例子:

```makefile
target:work

work:breakfast watch
	@echo "work"

getup:
	@echo "get up"

dress:getup
	@echo "dress"

brush:dress
	@echo "brush teeth"

wash:brush
	@echo "wash my face"

breakfast:wash
	@echo "have a breakfast"

watch:wash
	@echo "watch TV"
```

上面描述了一个简单地过程，你的最终目标是 work，但是要完成 work，你得先看完电视，吃完早饭，而 watch 的前提是洗完脸……你执行完上面的 Makefile 后，会输出：

```
get up
dress
brush teeth
wash my face
have a breakfast
watch TV
work
```

### 应用

那怎么把 Makefile 应用到我们的编译中呢？还是 HelloWorld 的例子。假设我们有一个源文件 hello_world.c，你想编译出一个二进制文件  hello_world，那就这样写：

```
target: hello_world

hello_world: hello_world.c
    gcc -o hello_world.exe hello_world.c
```

上面的 Makefile 含义是，target 目标是要先完成 hello_world 这个任务，而 hello_world 这个任务的目标是得先完成 hello_world.c 这个任务。有同学很好奇，你没有写 hello_world.c 这个任务怎么完成啊！没关系，Makefile 会优先把依赖的目标看成是一个文件，如果这个文件已经存在了，就说明这个任务完成了。

也就是说，你的本地存在 hello_world.c 这个文件，那就能执行 hello_world 这个任务，执行完这个任务后，会在本地生成一个 hello_world.exe 文件。于是 hello_world 任务就被完成了。一旦 hello_world 任务被完成，target 也就被完成了。

在 Makefile 中，我们把这种模式

```
target:dependencies
```

称为 “目标：依赖”关系。其中 target 是要完成的任务名称，而 dependencies 是要完成的任务名称，**你可以同时依赖多个任务**。如果 target 只是单独的表示一个任务名称，而不表示文件，你可以通知 Makefile，它是一个“伪目标”。

比如下面，其中 target 和 hello_world 只是表示任务名称，不代表文件名。

```makefile
target: hello_world

hello_world: hello_world.c
    gcc -o hello_world.exe hello_world.c

.PHONY:target
.PHONY:hello_world
```

如果写成下面这样，就不一样了，hello_world.exe 不仅表示任务名，也表示一个文件。

```makefile
target: hello_world.exe

hello_world.exe: hello_world.c
    gcc -o hello_world.exe hello_world.c

.PHONY:target
```

为什么要把仅表示任务名，而不表示文件的目标声明为 .PHONY 呢？实际上，这有助于 Makefile 自动分析文件过期时间。如果你的文件没有产生变化，Makefile 就什么也不干。就像上面这个例子，如果你不写 .PHONY 声明，每次执行 Makefile 都要执行一次 gcc 命令，而不管你有没有生成 hello_world.exe。

## 其它

关于 Makefile，我们只需要了解这么多就够了。Makefile 其实也提供了很多强大的语法，但这些也只是为了方便你写出更加精简的依赖关系而已。
