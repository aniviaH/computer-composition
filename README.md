# 编译c文件，查看汇编代码和机器码

在一个 Linux 操作系统上，我们可以简单地使用 gcc 和 objdump 这样两条命令，把对应的汇编代码和机器码都打印出来

```bash
gcc -g -c test.c
objdump -d -M intel -S test.o # 可以认为这个算作反汇编，把二进制的指令代码dump成人类可读的汇编代码。
```
