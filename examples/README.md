# C语言学习示例 / C Language Learning Examples

本目录包含C语言学习的所有示例代码，按照主题分类组织。

This directory contains all C language learning examples, organized by topic.

## 示例列表 / Examples List

### 入门基础 / Getting Started

#### 0. Hello World

最基础的C语言程序示例。

Basic C language program example.

**位置 / Location:** `hello_world/`

**运行 / Run:**
```bash
cd hello_world && make && ./hello
```

---

### 基础知识 / Fundamentals

#### 1. 变量和常量 / Variables and Constants

C语言中变量的声明、初始化和常量的使用。

Variable declaration, initialization, and constant usage in C.

**位置 / Location:** `01_variables_constants/`

**涵盖内容 / Covers:**
- 变量声明和初始化
- #define宏常量
- const常量
- 变量命名规则

**运行 / Run:**
```bash
cd 01_variables_constants && make && ./variables_constants
```

---

#### 2. 基本类型 / Basic Types

C语言的所有基本数据类型，包括整数、浮点数、字符和布尔类型。

All basic data types in C, including integers, floats, characters, and booleans.

**位置 / Location:** `01_basic_types/`

**涵盖内容 / Covers:**
- 整数类型（char, short, int, long, long long）
- 无符号类型
- 浮点类型（float, double）
- 布尔类型（C99+）
- 固定宽度整数类型
- 类型大小和范围

**运行 / Run:**
```bash
cd 01_basic_types && make && ./basic_types
```

---

#### 3. 运算符和表达式 / Operators and Expressions

C语言中的各种运算符，包括算术、关系、逻辑、位运算等。

Various operators in C, including arithmetic, relational, logical, bitwise, etc.

**位置 / Location:** `02_operators_expressions/`

**涵盖内容 / Covers:**
- 算术运算符
- 关系运算符
- 逻辑运算符
- 位运算符
- 赋值运算符
- 自增/自减运算符

**运行 / Run:**
```bash
cd 02_operators_expressions && make && ./operators_expressions
```

---

### 控制结构 / Control Structures

#### 4. 控制流 / Control Flow

C语言的条件语句，包括if-else、switch等。

Conditional statements in C, including if-else, switch, etc.

**位置 / Location:** `03_control_flow/`

**运行 / Run:**
```bash
cd 03_control_flow && make && ./control_flow
```

---

#### 5. 循环 / Loops

C语言的循环结构，包括for、while、do-while。

Loop structures in C, including for, while, do-while.

**位置 / Location:** `04_loops/`

**运行 / Run:**
```bash
cd 04_loops && make && ./loops
```

---

### 函数 / Functions

#### 6. 函数基础 / Function Basics

C语言的函数定义、参数传递、返回值、递归等。

Function definitions, parameter passing, return values, recursion in C.

**位置 / Location:** `05_functions/`

**涵盖内容 / Covers:**
- 函数声明和定义
- 参数传递（按值传递）
- 返回值
- 递归函数
- static和inline函数

**运行 / Run:**
```bash
cd 05_functions && make && ./functions
```

---

#### 7. 值传递 vs 指针传递 / Pass by Value vs Pass by Pointer

理解C语言的参数传递机制：**C语言只有值传递！**

Understanding C's parameter passing mechanism: **C only has pass by value!**

**位置 / Location:** `02_value_vs_reference/`

**涵盖内容 / Covers:**
- 值传递的工作原理
- 如何使用指针实现"引用传递"效果
- 数组传递
- 结构体传递
- 与Java的对比

**运行 / Run:**
```bash
cd 02_value_vs_reference && make && ./value_vs_reference
```

---

#### 8. 可变参数函数 / Variadic Functions

使用stdarg.h实现接受可变数量参数的函数。

Implement functions that accept variable number of arguments using stdarg.h.

**位置 / Location:** `14_variadic_functions/`

**涵盖内容 / Covers:**
- va_list、va_start、va_arg、va_end
- 实现自定义printf
- 可变参数函数的应用

**运行 / Run:**
```bash
cd 14_variadic_functions && make && ./variadic_functions
```

---

#### 9. 函数指针 / Function Pointers

函数指针的声明、使用和回调函数。

Function pointer declaration, usage, and callbacks.

**位置 / Location:** `13_function_pointers/`

**涵盖内容 / Covers:**
- 函数指针语法
- 回调函数
- 函数指针数组
- 使用typedef简化

**运行 / Run:**
```bash
cd 13_function_pointers && make && ./function_pointers
```

---

### 数组和字符串 / Arrays and Strings

#### 10. 数组操作 / Array Operations

C语言的数组操作，包括静态数组、动态数组和自定义ArrayList。

Array operations in C, including static arrays, dynamic arrays, and custom ArrayList.

**位置 / Location:** `03_arrays/`

**涵盖内容 / Covers:**
- 静态数组
- 动态数组（malloc/realloc/free）
- 自定义ArrayList（类似Java的ArrayList）
- 多维数组
- 数组排序

**运行 / Run:**
```bash
cd 03_arrays && make && ./arrays
```

---

#### 11. 字符串操作 / String Operations

C语言的字符串操作和常用字符串函数。

String operations and common string functions in C.

**位置 / Location:** `04_strings/`

**涵盖内容 / Covers:**
- 字符串声明和初始化
- strlen, strcpy, strcat, strcmp
- 字符串查找和分割
- 字符串转数字
- 大小写转换
- 动态字符串

**运行 / Run:**
```bash
cd 04_strings && make && ./strings
```

---

### 指针和内存 / Pointers and Memory

#### 12. 指针基础 / Pointer Basics

C语言指针的基本概念和使用。

Basic concepts and usage of pointers in C.

**位置 / Location:** `06_pointers/`

**涵盖内容 / Covers:**
- 指针声明和初始化
- 取地址运算符&
- 解引用运算符*
- 指针运算

**运行 / Run:**
```bash
cd 06_pointers && make && ./pointers
```

---

#### 13. 高级指针 / Advanced Pointers

多级指针、指针数组与数组指针的区别和用法。

Multi-level pointers, pointer arrays vs array pointers.

**位置 / Location:** `19_advanced_pointers/`

**涵盖内容 / Covers:**
- 多级指针（二级、三级指针）
- 指针数组
- 数组指针
- 函数指针数组
- 复杂声明解读

**运行 / Run:**
```bash
cd 19_advanced_pointers && make && ./advanced_pointers
```

---

#### 14. 内存管理 / Memory Management

动态内存分配和管理。

Dynamic memory allocation and management.

**位置 / Location:** `15_memory_management/`

**涵盖内容 / Covers:**
- malloc/calloc/realloc/free
- 内存泄漏检测
- 常见内存错误

**运行 / Run:**
```bash
cd 15_memory_management && make && ./memory_management
```

---

### 数据结构 / Data Structures

#### 15. 结构体 / Structures

C语言的结构体，类似Java的类但没有方法。

Structures in C, similar to Java classes but without methods.

**位置 / Location:** `05_structs/`

**涵盖内容 / Covers:**
- 结构体定义和初始化
- 访问结构体成员（. 和 ->）
- 嵌套结构体
- 结构体指针
- 结构体数组
- 链表（自引用结构体）

**运行 / Run:**
```bash
cd 05_structs && make && ./structs
```

---

#### 16. 结构体和联合体 / Structures and Unions

结构体和联合体的详细使用。

Detailed usage of structures and unions.

**位置 / Location:** `10_structs_unions/`

**涵盖内容 / Covers:**
- 结构体对齐
- 联合体
- 位域

**运行 / Run:**
```bash
cd 10_structs_unions && make && ./structs_unions
```

---

#### 17. 枚举 / Enumerations

C语言的枚举类型。

Enumeration types in C.

**位置 / Location:** `09_enums/`

**涵盖内容 / Covers:**
- 枚举定义
- 枚举值
- 枚举的使用

**运行 / Run:**
```bash
cd 09_enums && make && ./enums
```

---

#### 18. 位域 / Bit Fields

C语言结构体中的位域使用。

Bit fields usage in C structures.

**位置 / Location:** `20_bit_fields/`

**涵盖内容 / Covers:**
- 位域定义
- 位域大小和对齐
- 无名位域
- 实际应用（RGB、TCP标志）
- 可移植性问题

**运行 / Run:**
```bash
cd 20_bit_fields && make && ./bit_fields
```

---

### 类型系统 / Type System

#### 19. 类型转换 / Type Casting

C语言的隐式和显式类型转换。

Implicit and explicit type conversions in C.

**位置 / Location:** `11_type_casting/`

**涵盖内容 / Covers:**
- 隐式类型转换
- 显式类型转换
- 类型提升规则

**运行 / Run:**
```bash
cd 11_type_casting && make && ./type_casting
```

---

#### 20. 作用域和存储类别 / Scope and Storage Classes

变量的作用域和存储持续时间。

Variable scope and storage duration.

**位置 / Location:** `12_scope_storage/`

**涵盖内容 / Covers:**
- auto/static/extern/register
- 全局变量和局部变量
- 块作用域

**运行 / Run:**
```bash
cd 12_scope_storage && make && ./scope_storage
```

---

### 位操作 / Bit Operations

#### 21. 位操作 / Bit Operations

C语言的位运算操作，包括左移、右移和位掩码。

Bitwise operations in C, including shift operations and bit masking.

**位置 / Location:** `07_bit_operations/`

**涵盖内容 / Covers:**
- 位运算符（&, |, ^, ~, <<, >>）
- 设置、清除、切换特定位
- 位掩码和权限系统
- 位域（Bit Fields）
- 实用技巧

**运行 / Run:**
```bash
cd 07_bit_operations && make && ./bit_operations
```

---

### 输入输出 / Input/Output

#### 22. 文件操作 / File Operations

C语言的文件读写操作，包括文本文件和二进制文件。

File I/O operations in C, including text and binary files.

**位置 / Location:** `06_file_operations/`

**涵盖内容 / Covers:**
- 文件打开和关闭
- 文本文件读写
- 二进制文件读写
- 文件定位（fseek, ftell）
- 错误处理

**运行 / Run:**
```bash
cd 06_file_operations && make && ./file_operations
```

---

#### 23. 命令行参数 / Command Line Arguments

argc和argv的详细用法。

Detailed usage of argc and argv.

**位置 / Location:** `21_command_line_args/`

**涵盖内容 / Covers:**
- argc和argv基础
- argv内存布局
- 参数解析
- 选项处理模式
- getopt库

**运行 / Run:**
```bash
cd 21_command_line_args && make && ./command_line_args -v --help file.txt
```

---

### 标准库和常用功能 / Standard Library and Common Features

#### 24. 常用库函数 / Common Library Functions

C标准库中最常用的函数和库。

Most commonly used functions and libraries from C standard library.

**位置 / Location:** `08_common_libraries/`

**涵盖内容 / Covers:**
- stdio.h - 输入输出
- stdlib.h - 标准库函数
- string.h - 字符串操作
- math.h - 数学函数
- time.h - 时间日期
- ctype.h - 字符分类

**运行 / Run:**
```bash
cd 08_common_libraries && make && ./common_libraries
```

---

#### 25. 标准头文件详解 / Standard Header Files Guide

C语言标准头文件的全面介绍，包括功能、使用示例和与Java的对比。

Comprehensive guide to C standard header files, including functionality, examples, and Java comparison.

**位置 / Location:** `23_header_files/`

**涵盖内容 / Covers:**
- stdio.h - 标准输入输出详解
- stdlib.h - 标准库函数详解
- string.h - 字符串操作详解
- math.h - 数学函数详解
- time.h - 时间日期详解
- ctype.h - 字符分类详解
- stdint.h - 固定宽度整数
- stdbool.h - 布尔类型
- limits.h - 整数限制
- float.h - 浮点数限制
- errno.h - 错误处理
- assert.h - 断言
- signal.h - 信号处理
- stdarg.h - 可变参数
- stddef.h - 标准定义
- setjmp.h - 非本地跳转
- locale.h - 本地化

**运行 / Run:**
```bash
cd 23_header_files && make && ./header_files
```

---

#### 26. 自定义头文件 / Custom Header Files

如何创建和使用自定义头文件，包括多文件项目组织和最佳实践。

How to create and use custom header files, including multi-file project organization and best practices.

**位置 / Location:** `24_custom_headers/`

**涵盖内容 / Covers:**
- 头文件保护 (include guards)
- 宏定义和常量
- 类型定义 (typedef, enum, struct)
- 函数声明与实现分离
- 多文件项目组织
- 命名约定和最佳实践

**运行 / Run:**
```bash
cd 24_custom_headers && make && ./custom_headers
```

---

#### 27. 预处理器 / Preprocessor

C语言预处理器指令。

C preprocessor directives.

**位置 / Location:** `18_preprocessor/`

**涵盖内容 / Covers:**
- #include/#define/#undef
- 条件编译
- 宏函数
- #pragma指令

**运行 / Run:**
```bash
cd 18_preprocessor && make && ./preprocessor
```

---

#### 28. 错误处理 / Error Handling

C语言的错误处理机制，包括errno、perror和strerror。

Error handling mechanisms in C, including errno, perror, and strerror.

**位置 / Location:** `16_error_handling/`

**涵盖内容 / Covers:**
- errno全局变量
- perror()函数
- strerror()函数
- 返回值错误处理
- 自定义错误处理

**运行 / Run:**
```bash
cd 16_error_handling && make && ./error_handling
```

---

#### 29. 信号处理 / Signal Handling

C语言的信号处理机制，使用signal.h处理系统信号。

Signal handling mechanisms in C using signal.h.

**位置 / Location:** `17_signal_handling/`

**涵盖内容 / Covers:**
- signal()函数
- 常见信号（SIGINT, SIGTERM等）
- 信号处理函数
- alarm()定时器
- 信号忽略

**运行 / Run:**
```bash
cd 17_signal_handling && make && ./signal_handling
```

---

### 库开发 / Library Development

#### 30. 静态库 / Static Library

如何创建和使用C语言静态库（.a文件）。

How to create and use C static libraries (.a files).

**位置 / Location:** `09_static_library/`

**涵盖内容 / Covers:**
- 创建静态库
- 链接静态库
- ar命令的使用
- 静态库的特点
- 与动态库的对比

**运行 / Run:**
```bash
cd 09_static_library && make && ./main
```

---

#### 31. 动态链接库 / Dynamic Library

如何创建和使用C语言动态链接库（.so文件）。

How to create and use C dynamic libraries (.so files).

**位置 / Location:** `10_dynamic_library/`

**涵盖内容 / Covers:**
- 创建动态库
- 链接动态库
- 运行时库路径设置
- 动态库的特点
- 与静态库的对比

**运行 / Run:**
```bash
cd 10_dynamic_library && make run
```

---

### 高级主题 / Advanced Topics

#### 32. 内联汇编 / Inline Assembly

GCC内联汇编的基本用法（仅x86/x86_64）。

Basic GCC inline assembly usage (x86/x86_64 only).

**位置 / Location:** `22_inline_assembly/`

**涵盖内容 / Covers:**
- 基本内联汇编语法
- 扩展内联汇编
- 输入输出操作数
- 约束和修饰符
- 实用示例

**运行 / Run:**
```bash
cd 22_inline_assembly && make && ./inline_assembly
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

---

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

---

## 学习建议 / Learning Recommendations

建议按以下顺序学习示例：

Recommended order for studying examples:

### 阶段1：入门基础 / Phase 1: Getting Started
1. **hello_world** - 了解基本结构 / Understand basic structure
2. **01_variables_constants** - 变量和常量 / Variables and constants
3. **01_basic_types** - 掌握数据类型 / Master data types
4. **02_operators_expressions** - 运算符 / Operators

### 阶段2：控制和函数 / Phase 2: Control and Functions
5. **03_control_flow** - 条件语句 / Conditional statements
6. **04_loops** - 循环结构 / Loop structures
7. **05_functions** - 函数基础 / Function basics
8. **02_value_vs_reference** - 理解参数传递 / Understand parameter passing

### 阶段3：数组和字符串 / Phase 3: Arrays and Strings
9. **03_arrays** - 掌握数组操作 / Master array operations
10. **04_strings** - 学习字符串操作 / Learn string operations

### 阶段4：指针和内存 / Phase 4: Pointers and Memory
11. **06_pointers** - 指针基础 / Pointer basics
12. **15_memory_management** - 内存管理 / Memory management
13. **19_advanced_pointers** - 高级指针 / Advanced pointers

### 阶段5：数据结构 / Phase 5: Data Structures
14. **05_structs** - 理解结构体 / Understand structures
15. **09_enums** - 枚举类型 / Enumeration types
16. **10_structs_unions** - 结构体和联合体 / Structures and unions
17. **20_bit_fields** - 位域 / Bit fields

### 阶段6：类型和作用域 / Phase 6: Types and Scope
18. **11_type_casting** - 类型转换 / Type casting
19. **12_scope_storage** - 作用域和存储 / Scope and storage

### 阶段7：高级函数 / Phase 7: Advanced Functions
20. **13_function_pointers** - 函数指针 / Function pointers
21. **14_variadic_functions** - 可变参数 / Variadic functions

### 阶段8：系统编程 / Phase 8: System Programming
22. **06_file_operations** - 学习文件I/O / Learn file I/O
23. **07_bit_operations** - 掌握位操作 / Master bit operations
24. **16_error_handling** - 错误处理 / Error handling
25. **17_signal_handling** - 信号处理 / Signal handling
26. **21_command_line_args** - 命令行参数 / Command line arguments

### 阶段9：预处理和库 / Phase 9: Preprocessing and Libraries
27. **18_preprocessor** - 预处理器 / Preprocessor
28. **08_common_libraries** - 熟悉标准库 / Familiarize with standard library
29. **23_header_files** - 标准头文件详解 / Standard header files guide
30. **24_custom_headers** - 自定义头文件 / Custom header files
31. **09_static_library** - 创建静态库 / Create static libraries
32. **10_dynamic_library** - 创建动态库 / Create dynamic libraries

### 阶段10：进阶主题 / Phase 10: Advanced Topics
33. **22_inline_assembly** - 内联汇编 / Inline assembly

---
