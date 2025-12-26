# Hello World 示例

## 简介

这是一个最基础的C语言程序，用于演示C语言的基本结构和输出功能。

## 程序说明

这个程序演示了：
- `#include <stdio.h>` - 引入标准输入输出库
- `int main()` - 主函数定义
- `printf()` - 输出函数的使用
- `return 0` - 返回成功状态

## 编译

```bash
make
```

或者直接使用gcc编译：
```bash
gcc -Wall -Wextra -std=c11 -o hello hello.c
```

## 运行

```bash
./hello
```

## 预期输出

```
Hello, World!
欢迎来到C语言学习！
```

## 清理

```bash
make clean
```
