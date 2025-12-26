# 自定义头文件示例 / Custom Header Files Example

## 概述 / Overview

本示例演示如何创建和使用自定义头文件，包括头文件的结构、最佳实践和多文件项目组织。

This example demonstrates how to create and use custom header files, including header structure, best practices, and multi-file project organization.

## 文件结构 / File Structure

```
24_custom_headers/
├── utils.h           # 通用工具头文件 / General utility header
├── utils.c           # 通用工具实现 / General utility implementation
├── string_utils.h    # 字符串工具头文件 / String utility header
├── string_utils.c    # 字符串工具实现 / String utility implementation
├── main.c            # 主程序 / Main program
├── Makefile          # 构建脚本 / Build script
└── README.md         # 说明文档 / Documentation
```

## 头文件结构 / Header File Structure

### 标准头文件模板 / Standard Header Template

```c
/**
 * 文件描述 / File description
 */

#ifndef HEADER_NAME_H     // 头文件保护开始 / Include guard start
#define HEADER_NAME_H

// 1. 包含其他头文件 / Include other headers
#include <stddef.h>

// 2. 宏定义 / Macro definitions
#define CONSTANT_VALUE 100

// 3. 类型定义 / Type definitions
typedef struct {
    int value;
} MyType;

// 4. 函数声明 / Function declarations
void my_function(int param);

#endif // HEADER_NAME_H   // 头文件保护结束 / Include guard end
```

## 头文件保护 / Include Guards

头文件保护防止头文件被多次包含，避免重复定义错误。

Include guards prevent headers from being included multiple times, avoiding redefinition errors.

```c
#ifndef MYHEADER_H    // 如果未定义 MYHEADER_H / If MYHEADER_H not defined
#define MYHEADER_H    // 定义 MYHEADER_H / Define MYHEADER_H

// 头文件内容 / Header contents

#endif // MYHEADER_H  // 结束条件 / End condition
```

### 替代方案: #pragma once

```c
#pragma once  // 非标准但广泛支持 / Non-standard but widely supported

// 头文件内容 / Header contents
```

## utils.h 功能 / utils.h Features

### 宏定义 / Macro Definitions

| 宏 / Macro | 描述 / Description |
|-----------|-------------------|
| `UTILS_PI` | π常量 / Pi constant |
| `UTILS_E` | e常量 / Euler's constant |
| `UTILS_MAX(a, b)` | 返回较大值 / Returns larger value |
| `UTILS_MIN(a, b)` | 返回较小值 / Returns smaller value |
| `UTILS_ABS(x)` | 返回绝对值 / Returns absolute value |
| `UTILS_ARRAY_LEN(arr)` | 返回数组长度 / Returns array length |

### 类型定义 / Type Definitions

| 类型 / Type | 描述 / Description |
|------------|-------------------|
| `byte_t` | 字节类型 (unsigned char) |
| `uint_t` | 无符号整数 (unsigned int) |
| `utils_status_t` | 状态码枚举 / Status code enum |
| `utils_result_t` | 结果结构体 / Result structure |

### 函数 / Functions

| 函数 / Function | 描述 / Description |
|----------------|-------------------|
| `utils_get_version()` | 获取版本字符串 / Get version string |
| `utils_array_sum()` | 计算数组和 / Calculate array sum |
| `utils_array_average()` | 计算数组平均值 / Calculate array average |
| `utils_array_max()` | 查找最大值 / Find maximum |
| `utils_array_min()` | 查找最小值 / Find minimum |
| `utils_array_reverse()` | 反转数组 / Reverse array |
| `utils_string_is_empty()` | 检查字符串是否为空 / Check if string empty |
| `utils_status_message()` | 获取状态描述 / Get status description |

## string_utils.h 功能 / string_utils.h Features

| 函数 / Function | 描述 / Description |
|----------------|-------------------|
| `str_trim()` | 去除首尾空白 / Trim whitespace |
| `str_to_upper()` | 转为大写 / Convert to uppercase |
| `str_to_lower()` | 转为小写 / Convert to lowercase |
| `str_starts_with()` | 检查前缀 / Check prefix |
| `str_ends_with()` | 检查后缀 / Check suffix |
| `str_count_char()` | 统计字符出现次数 / Count character occurrences |
| `str_reverse()` | 反转字符串 / Reverse string |
| `str_is_numeric()` | 检查是否为数字 / Check if numeric |
| `str_is_alpha()` | 检查是否为字母 / Check if alphabetic |

## 编译和运行 / Build and Run

### 使用Makefile / Using Makefile

```bash
make        # 编译 / Build
./custom_headers  # 运行 / Run
make clean  # 清理 / Clean
```

### 手动编译 / Manual Compilation

```bash
# 方法1: 一次性编译 / Method 1: Compile at once
gcc -Wall -Wextra -std=c11 -o custom_headers main.c utils.c string_utils.c

# 方法2: 分步编译 / Method 2: Step by step
gcc -c utils.c -o utils.o
gcc -c string_utils.c -o string_utils.o
gcc -c main.c -o main.o
gcc main.o utils.o string_utils.o -o custom_headers
```

## 最佳实践 / Best Practices

### 1. 命名约定 / Naming Conventions

```c
// 头文件保护：大写文件名 / Include guard: uppercase filename
#ifndef MY_MODULE_H
#define MY_MODULE_H

// 宏常量：大写带前缀 / Macro constants: uppercase with prefix
#define MY_MODULE_MAX_SIZE 100

// 函数：小写带前缀 / Functions: lowercase with prefix
void my_module_init(void);

// 类型：使用_t后缀 / Types: use _t suffix
typedef struct { ... } my_type_t;
```

### 2. 头文件内容 / Header Contents

**应该包含 / Should include:**
- 头文件保护 / Include guards
- 必要的头文件 / Necessary includes
- 宏定义 / Macro definitions
- 类型定义 / Type definitions
- 函数声明 / Function declarations
- 文档注释 / Documentation comments

**不应该包含 / Should NOT include:**
- 函数实现 / Function implementations
- 全局变量定义 / Global variable definitions
- 不必要的头文件 / Unnecessary includes

### 3. 前向声明 / Forward Declarations

```c
// 当只需要指针时，使用前向声明避免包含整个头文件
// Use forward declaration when only pointer is needed
struct MyStruct;  // 前向声明 / Forward declaration
void process(struct MyStruct *ptr);
```

### 4. 错误处理 / Error Handling

```c
// 使用状态码返回错误 / Use status codes for errors
typedef enum {
    STATUS_SUCCESS = 0,
    STATUS_ERROR_NULL,
    STATUS_ERROR_RANGE
} status_t;

status_t my_function(int *result);
```

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 声明/实现分离 | .h + .c文件 | 单个.java文件 |
| 防止重复包含 | Include guards | 不需要 |
| 导入方式 | #include | import |
| 命名空间 | 前缀约定 | package |
| 依赖管理 | 手动链接 | 自动类加载 |
| 访问控制 | static关键字 | public/private |

### Java开发者注意事项 / Notes for Java Developers

1. **分离声明和实现 / Separate Declaration and Implementation**
   - Java: 单文件包含全部
   - C: 头文件(.h)声明，源文件(.c)实现

2. **头文件保护 / Include Guards**
   - Java: 不需要
   - C: 必须使用防止重复定义

3. **编译过程 / Compilation Process**
   - Java: 自动处理依赖
   - C: 需要手动管理编译顺序

4. **包命名 / Package Naming**
   - Java: package和import
   - C: 使用前缀模拟命名空间

## 常见问题 / Common Issues

### 1. 重复定义错误 / Redefinition Error

**问题 / Problem:**
```
error: redefinition of 'struct MyStruct'
```

**解决 / Solution:**
添加头文件保护 / Add include guards

### 2. 未定义引用 / Undefined Reference

**问题 / Problem:**
```
undefined reference to 'my_function'
```

**解决 / Solution:**
确保链接了实现文件 / Ensure implementation file is linked

### 3. 循环包含 / Circular Include

**问题 / Problem:**
头文件A包含B，B包含A / Header A includes B, B includes A

**解决 / Solution:**
使用前向声明 / Use forward declarations

## 项目组织建议 / Project Organization Tips

```
project/
├── include/          # 公共头文件 / Public headers
│   ├── module_a.h
│   └── module_b.h
├── src/              # 源文件 / Source files
│   ├── module_a.c
│   ├── module_b.c
│   └── main.c
├── internal/         # 内部头文件 / Internal headers
│   └── private.h
├── Makefile
└── README.md
```

## 参考资料 / References

- [C Preprocessor - cppreference.com](https://en.cppreference.com/w/c/preprocessor)
- [Header Files - GNU C Manual](https://www.gnu.org/software/gnu-c-manual/gnu-c-manual.html)
- [Organizing Code Files in C - Learn C](https://www.learn-c.org/en/Header_files)
