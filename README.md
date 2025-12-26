# c-language-learning

C语言学习 / C Language Learning

[![C Language Build](https://github.com/unknowIfGuestInDream/c-language-learning/workflows/C%20Language%20Build/badge.svg)](https://github.com/unknowIfGuestInDream/c-language-learning/actions)

## 项目介绍 / Project Introduction

这是一个全面的C语言学习项目，包含各种C语言学习示例，特别为Java开发者设计。每个示例都包含详细的中英文注释和文档，并通过GitHub Actions自动编译和测试。

This is a comprehensive C language learning project containing various C language learning examples, specially designed for Java developers. Each example includes detailed bilingual (Chinese/English) comments and documentation, and is automatically compiled and tested through GitHub Actions.

## 快速开始 / Quick Start

### 前置要求 / Prerequisites

- GCC编译器 / GCC Compiler
- Make工具 / Make utility

在Ubuntu上安装 / Install on Ubuntu:
```bash
sudo apt-get update
sudo apt-get install build-essential gcc make
```

### 编译所有示例 / Build All Examples

```bash
make all
```

### 运行所有示例 / Run All Examples

```bash
make test
```

### 清理构建文件 / Clean Build Files

```bash
make clean
```

## 示例列表 / Examples List

### 0. Hello World

最基础的C语言程序示例。

Basic C language program example.

**位置 / Location:** `examples/hello_world/`

**运行 / Run:**
```bash
cd examples/hello_world && make && ./hello
```

---

### 1. 基本类型 / Basic Types

C语言的所有基本数据类型，包括整数、浮点数、字符和布尔类型。

All basic data types in C, including integers, floats, characters, and booleans.

**位置 / Location:** `examples/01_basic_types/`

**涵盖内容 / Covers:**
- 整数类型（char, short, int, long, long long）
- 无符号类型
- 浮点类型（float, double）
- 布尔类型（C99+）
- 固定宽度整数类型
- 类型大小和范围

**运行 / Run:**
```bash
cd examples/01_basic_types && make && ./basic_types
```

---

### 2. 值传递 vs 指针传递 / Pass by Value vs Pass by Pointer

理解C语言的参数传递机制：**C语言只有值传递！**

Understanding C's parameter passing mechanism: **C only has pass by value!**

**位置 / Location:** `examples/02_value_vs_reference/`

**涵盖内容 / Covers:**
- 值传递的工作原理
- 如何使用指针实现"引用传递"效果
- 数组传递
- 结构体传递
- 与Java的对比

**运行 / Run:**
```bash
cd examples/02_value_vs_reference && make && ./value_vs_reference
```

---

### 3. 数组操作 / Array Operations

C语言的数组操作，包括静态数组、动态数组和自定义ArrayList。

Array operations in C, including static arrays, dynamic arrays, and custom ArrayList.

**位置 / Location:** `examples/03_arrays/`

**涵盖内容 / Covers:**
- 静态数组
- 动态数组（malloc/realloc/free）
- 自定义ArrayList（类似Java的ArrayList）
- 多维数组
- 数组排序

**运行 / Run:**
```bash
cd examples/03_arrays && make && ./arrays
```

---

### 4. 字符串操作 / String Operations

C语言的字符串操作和常用字符串函数。

String operations and common string functions in C.

**位置 / Location:** `examples/04_strings/`

**涵盖内容 / Covers:**
- 字符串声明和初始化
- strlen, strcpy, strcat, strcmp
- 字符串查找和分割
- 字符串转数字
- 大小写转换
- 动态字符串

**运行 / Run:**
```bash
cd examples/04_strings && make && ./strings
```

---

### 5. 结构体 / Structures

C语言的结构体，类似Java的类但没有方法。

Structures in C, similar to Java classes but without methods.

**位置 / Location:** `examples/05_structs/`

**涵盖内容 / Covers:**
- 结构体定义和初始化
- 访问结构体成员（. 和 ->）
- 嵌套结构体
- 结构体指针
- 结构体数组
- 链表（自引用结构体）

**运行 / Run:**
```bash
cd examples/05_structs && make && ./structs
```

---

### 6. 文件操作 / File Operations

C语言的文件读写操作，包括文本文件和二进制文件。

File I/O operations in C, including text and binary files.

**位置 / Location:** `examples/06_file_operations/`

**涵盖内容 / Covers:**
- 文件打开和关闭
- 文本文件读写
- 二进制文件读写
- 文件定位（fseek, ftell）
- 错误处理

**运行 / Run:**
```bash
cd examples/06_file_operations && make && ./file_operations
```

---

### 7. 位操作 / Bit Operations

C语言的位运算操作，包括左移、右移和位掩码。

Bitwise operations in C, including shift operations and bit masking.

**位置 / Location:** `examples/07_bit_operations/`

**涵盖内容 / Covers:**
- 位运算符（&, |, ^, ~, <<, >>）
- 设置、清除、切换特定位
- 位掩码和权限系统
- 位域（Bit Fields）
- 实用技巧

**运行 / Run:**
```bash
cd examples/07_bit_operations && make && ./bit_operations
```

---

### 8. 常用库函数 / Common Library Functions

C标准库中最常用的函数和库。

Most commonly used functions and libraries from C standard library.

**位置 / Location:** `examples/08_common_libraries/`

**涵盖内容 / Covers:**
- stdio.h - 输入输出
- stdlib.h - 标准库函数
- string.h - 字符串操作
- math.h - 数学函数
- time.h - 时间日期
- ctype.h - 字符分类

**运行 / Run:**
```bash
cd examples/08_common_libraries && make && ./common_libraries
```

---

### 9. 静态库 / Static Library

如何创建和使用C语言静态库（.a文件）。

How to create and use C static libraries (.a files).

**位置 / Location:** `examples/09_static_library/`

**涵盖内容 / Covers:**
- 创建静态库
- 链接静态库
- ar命令的使用
- 静态库的特点
- 与动态库的对比

**运行 / Run:**
```bash
cd examples/09_static_library && make && ./main
```

---

### 10. 动态链接库 / Dynamic Library

如何创建和使用C语言动态链接库（.so文件）。

How to create and use C dynamic libraries (.so files).

**位置 / Location:** `examples/10_dynamic_library/`

**涵盖内容 / Covers:**
- 创建动态库
- 链接动态库
- 运行时库路径设置
- 动态库的特点
- 与静态库的对比

**运行 / Run:**
```bash
cd examples/10_dynamic_library && make run
```

---

## Makefile 使用指南 / Makefile Guide

本项目提供了详细的Makefile使用指南，请查看 [MAKEFILE_GUIDE.md](MAKEFILE_GUIDE.md)

This project provides a detailed Makefile usage guide. See [MAKEFILE_GUIDE.md](MAKEFILE_GUIDE.md)

**主要内容 / Contents:**
- Makefile基本语法
- 变量和规则
- 实用模式和示例
- 编译选项说明
- 最佳实践

## 自动化构建 / Automated Build

本项目使用GitHub Actions在Ubuntu环境中自动编译所有C语言示例。每次推送或Pull Request都会触发自动构建。

This project uses GitHub Actions to automatically compile all C language examples in an Ubuntu environment. Automated builds are triggered on every push or pull request.

工作流文件 / Workflow file: `.github/workflows/build.yml`

## 项目结构 / Project Structure

```
c-language-learning/
├── .github/
│   └── workflows/
│       └── build.yml          # GitHub Actions工作流
├── examples/
│   ├── hello_world/           # Hello World示例
│   ├── 01_basic_types/        # 基本类型
│   ├── 02_value_vs_reference/ # 值传递vs指针传递
│   ├── 03_arrays/             # 数组操作
│   ├── 04_strings/            # 字符串操作
│   ├── 05_structs/            # 结构体
│   ├── 06_file_operations/    # 文件操作
│   ├── 07_bit_operations/     # 位操作
│   ├── 08_common_libraries/   # 常用库函数
│   ├── 09_static_library/     # 静态库
│   └── 10_dynamic_library/    # 动态链接库
├── Makefile                   # 根Makefile
├── MAKEFILE_GUIDE.md          # Makefile使用指南
├── README.md                  # 本文件
└── .gitignore                 # Git忽略文件

```

## 给Java开发者的建议 / Tips for Java Developers

如果你是Java开发者，以下是学习C语言时需要注意的关键区别：

If you're a Java developer, here are the key differences to note when learning C:

### 内存管理 / Memory Management
- **Java**: 自动垃圾回收 / Automatic garbage collection
- **C**: 手动管理（malloc/free） / Manual management (malloc/free)

### 字符串 / Strings
- **Java**: String对象，不可变 / String objects, immutable
- **C**: 字符数组，以'\0'结尾 / Character arrays, null-terminated

### 数组 / Arrays
- **Java**: 有length属性，边界检查 / Has length property, bounds checking
- **C**: 无内置大小，无边界检查 / No built-in size, no bounds checking

### 参数传递 / Parameter Passing
- **Java**: 基本类型值传递，对象引用传递 / Primitives by value, objects by reference
- **C**: 只有值传递，使用指针模拟引用传递 / Only by value, use pointers to simulate references

### 面向对象 / Object-Oriented
- **Java**: 完整的OOP支持 / Full OOP support
- **C**: 无OOP，使用结构体和函数指针 / No OOP, use structs and function pointers

### 编译 / Compilation
- **Java**: 编译为字节码，JVM运行 / Compile to bytecode, run on JVM
- **C**: 编译为本地机器码 / Compile to native machine code

## 学习建议 / Learning Recommendations

建议按以下顺序学习示例：

Recommended order for studying examples:

1. **hello_world** - 了解基本结构 / Understand basic structure
2. **01_basic_types** - 掌握数据类型 / Master data types
3. **02_value_vs_reference** - 理解参数传递 / Understand parameter passing
4. **04_strings** - 学习字符串操作 / Learn string operations
5. **03_arrays** - 掌握数组操作 / Master array operations
6. **05_structs** - 理解结构体 / Understand structures
7. **06_file_operations** - 学习文件I/O / Learn file I/O
8. **07_bit_operations** - 掌握位操作 / Master bit operations
9. **08_common_libraries** - 熟悉标准库 / Familiarize with standard library
10. **09_static_library** - 创建静态库 / Create static libraries
11. **10_dynamic_library** - 创建动态库 / Create dynamic libraries

## 贡献 / Contributing

欢迎提交新的学习示例！请确保您的代码：

Welcome to submit new learning examples! Please ensure your code:

1. 包含详细的中英文注释 / Includes detailed bilingual comments
2. 有配套的README.md文档 / Has accompanying README.md documentation
3. 包含Makefile便于编译 / Includes Makefile for easy compilation
4. 可以通过编译和测试 / Can be compiled and tested successfully
5. 遵循项目的代码风格 / Follows the project's coding style

## 许可证 / License

请查看 LICENSE 文件。

Please see the LICENSE file.
