# C语言字符串操作 / String Operations in C

## 概述 / Overview

本示例演示C语言的字符串操作。C语言的字符串是以`\0`结尾的字符数组。

This example demonstrates string operations in C. C strings are character arrays terminated with `\0`.

## 关键概念 / Key Concepts

### C字符串的本质 / Nature of C Strings

C语言的字符串是字符数组，必须以空字符`\0`结尾：
```c
char str[] = "Hello";  // 实际存储: {'H','e','l','l','o','\0'}
```

### 常用字符串函数 / Common String Functions

| 函数 / Function | 用途 / Purpose | 头文件 / Header |
|----------------|---------------|----------------|
| `strlen()` | 获取字符串长度 / Get string length | `<string.h>` |
| `strcpy()` | 复制字符串 / Copy string | `<string.h>` |
| `strcat()` | 连接字符串 / Concatenate strings | `<string.h>` |
| `strcmp()` | 比较字符串 / Compare strings | `<string.h>` |
| `strchr()` | 查找字符 / Find character | `<string.h>` |
| `strstr()` | 查找子串 / Find substring | `<string.h>` |
| `strtok()` | 分割字符串 / Tokenize string | `<string.h>` |
| `sprintf()` | 格式化字符串 / Format string | `<stdio.h>` |
| `atoi()` | 字符串转整数 / String to int | `<stdlib.h>` |
| `atof()` | 字符串转浮点 / String to float | `<stdlib.h>` |

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 字符串类型 / String Type | `char[]` (数组 / array) | `String` (对象 / object) |
| 可变性 / Mutability | 可变 / Mutable | 不可变 / Immutable |
| 长度获取 / Get Length | `strlen(str)` | `str.length()` |
| 连接 / Concatenation | `strcat()` | `+` 或 `concat()` |
| 比较 / Comparison | `strcmp()` | `equals()` |
| 内存管理 / Memory | 手动 / Manual | 自动 / Automatic |

**关键区别 / Key Differences:**
- C字符串是可变的，Java String是不可变的
- C需要手动管理内存，Java有垃圾回收
- C字符串必须以`\0`结尾
- Java有StringBuilder用于可变字符串

## 编译和运行 / Build and Run

```bash
make
./strings
```

## 安全注意事项 / Safety Notes

1. 始终确保字符串以`\0`结尾
2. 使用`strncpy`、`strncat`等带长度限制的函数避免缓冲区溢出
3. 使用动态字符串时记得`free()`
4. `strtok()`会修改原字符串
