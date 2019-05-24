### 1. 如果 `open` 或者另外几个相关的系统调用执行出错，，你如何找出出错的原因？
答：先用man 2查询相关文档，看自己的写的调用函数是否出错。如果排查不出来错误，将显示的错误原因用搜索引擎查找。
### 2. 你觉得学习本篇有什么困难？
答：学习本篇需要去查看大量的英文文档，阅读起来比较困难。
### 3. 你觉得掌握文件 IO 还能做些什么事情？
答：可以向音箱输出数据，从麦克风中读取数据，向网络中读数据和写数据，从键盘读数据，向屏幕写数据。
### 4. 在你的终端执行命令 `ps`，你会看到你当前 bash 的 PID 号（第一行），记下这个 PID，然后再执行 `lsof -p ${PID}`，注意了，请把 ${PID} 替换成你看到的 PID。接下来你会看到 `lsof` 执行的输出结果。描述你看到的现象，你发现了什么？
答：屏幕输出了许多信息，第一行由command,pid,user,fd,type,device,size/off,node,name。所有的PID都是bash的pid,fd是有cwd,rtd,txt,mem,0u,1u等。显示的都是执行bash这个进程所需要依赖的文件。