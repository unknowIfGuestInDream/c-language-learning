# C语言变量和常量 / Variables and Constants in C

## 概述 / Overview

本示例演示C语言中变量和常量的声明、初始化和使用。

This example demonstrates variable and constant declaration, initialization, and usage in C.

## 关键概念 / Key Concepts

### 变量 / Variables

变量是存储数据的命名内存位置。

**声明 / Declaration:**
```c
int age;              // 声明 / Declare
int count = 10;       // 声明并初始化 / Declare and initialize
int a, b, c;          // 多个变量 / Multiple variables
```

### 常量 / Constants

常量是不能修改的值。

**定义方式 / Definition Methods:**
```c
#define MAX 100       // 宏常量 / Macro constant
const int SIZE = 50;  // const常量 / const constant
```

## 变量命名规则 / Naming Rules

- ✓ 以字母或下划线开头 / Start with letter or underscore
- ✓ 包含字母、数字、下划线 / Letters, digits, underscore
- ✓ 区分大小写 / Case sensitive
- ✗ 不能使用关键字 / No keywords

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 未初始化变量 / Uninitialized | 垃圾值 / Garbage | 默认值 / Default value |
| 常量 / Constants | `#define`, `const` | `final` |
| 全局变量 / Globals | 支持 / Yes | 不支持（类静态）/ No (class static) |

## 编译和运行 / Build and Run

```bash
make
./variables_constants
```
