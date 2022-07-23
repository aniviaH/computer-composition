# 查看变量赋值的编译后汇编代码和机器码

```bash
gcc -g -c test.c
objdump -d -M intel -S test.o
```

```bash
test.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <main>:
int main () {
   0:   55                      push   rbp                        # 压栈，基址地址
   1:   48 89 e5                mov    rbp,rsp                    # 将寄存器内容移动到基址寄存器
  int a = 1;
   4:   c7 45 fc 01 00 00 00    mov    DWORD PTR [rbp-0x4],0x1    # 将0x1(1)赋值到寄存器rbp-0x4地址指向的内容，即a=1
  int b = 2;
   b:   c7 45 f8 02 00 00 00    mov    DWORD PTR [rbp-0x8],0x2    # 将0x2(2)赋值到寄存器rbp-0x8地址指向的内容，即b=2
  a = a + b;
  12:   8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]    # 取出32位整数rbp-0x8的内容，赋值到eax
  15:   01 45 fc                add    DWORD PTR [rbp-0x4],eax    # 将eax指向的值，与rbp-0x4指向的值做add，并将结果写到rbp-0x4指向的地址里
  18:   b8 00 00 00 00          mov    eax,0x0                    # 重置eax寄存器
}
  1d:   5d                      pop    rbp                        # 弹出栈数据
  1e:   c3                      ret                               # main函数返回并退出
```

```bash

test.o:     file format elf64-x86-64

Disassembly of section .text:

0000000000000000 <main>:
int main () {
   0:   55                      push   rbp
   1:   48 89 e5                mov    rbp,rsp
  int a = 1;
   4:   c7 45 fc 01 00 00 00    mov    DWORD PTR [rbp-0x4],0x1
  int b = 2;
   b:   c7 45 f8 02 00 00 00    mov    DWORD PTR [rbp-0x8],0x2
  // a = a + b;
  int c = a + b;
  12:   8b 55 fc                mov    edx,DWORD PTR [rbp-0x4]    # 取出rbp-0x4指向的值赋值到edx，即访问a
  15:   8b 45 f8                mov    eax,DWORD PTR [rbp-0x8]    # 取出rbp-0x8指向的值赋值到eax，即访问b
  18:   01 d0                   add    eax,edx                    # edx的值与eax的值做add，并将结果赋值到eax，即 a + b
  1a:   89 45 f4                mov    DWORD PTR [rbp-0xc],eax    # 将eax的值赋值到rbp-0xc，即 int c = [eax]
  1d:   b8 00 00 00 00          mov    eax,0x0
}
  22:   5d                      pop    rbp
  23:   c3                      ret

```
