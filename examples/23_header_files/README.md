# C语言标准头文件详解 / C Standard Header Files Guide

## 概述 / Overview

本示例提供C语言标准头文件的全面介绍，包括每个头文件的功能、主要内容、使用示例和与Java的对比。

This example provides a comprehensive guide to C standard header files, including functionality, main contents, usage examples, and comparison with Java.

## 什么是头文件？/ What are Header Files?

头文件（Header Files）是C语言中用于声明函数原型、宏定义、类型定义和全局变量的文件。头文件通常以 `.h` 为扩展名。

Header files in C are files used to declare function prototypes, macro definitions, type definitions, and global variables. Header files typically have a `.h` extension.

### 头文件的作用 / Purpose of Header Files

1. **函数声明** / Function Declarations - 告诉编译器函数的存在和签名 / Tell compiler about function existence and signature
2. **宏定义** / Macro Definitions - 定义常量和宏函数 / Define constants and macro functions
3. **类型定义** / Type Definitions - 定义结构体、联合体、枚举等 / Define structs, unions, enums, etc.
4. **代码复用** / Code Reuse - 允许多个源文件共享声明 / Allow multiple source files to share declarations

### 如何包含头文件 / How to Include Header Files

```c
// 系统头文件：使用尖括号 / System headers: use angle brackets
#include <stdio.h>
#include <stdlib.h>

// 自定义头文件：使用双引号 / Custom headers: use double quotes
#include "myheader.h"
```

## 标准头文件一览 / Standard Header Files Overview

### 基础输入输出 / Basic I/O

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<stdio.h>` | 标准输入输出 / Standard I/O | printf, scanf, fopen, fclose, fread, fwrite |

### 通用工具 / General Utilities

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<stdlib.h>` | 标准库函数 / Standard Library | malloc, free, atoi, rand, exit, qsort |
| `<string.h>` | 字符串操作 / String Operations | strlen, strcpy, strcat, strcmp, memcpy, memset |
| `<math.h>` | 数学函数 / Math Functions | sqrt, pow, sin, cos, log, ceil, floor |
| `<time.h>` | 时间日期 / Time and Date | time, localtime, strftime, clock |

### 字符处理 / Character Handling

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<ctype.h>` | 字符分类 / Character Classification | isalpha, isdigit, toupper, tolower |

### 类型支持 / Type Support

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<stdint.h>` | 固定宽度整数 / Fixed-width Integers | int8_t, int16_t, int32_t, int64_t |
| `<stdbool.h>` | 布尔类型 / Boolean Type | bool, true, false |
| `<limits.h>` | 整数限制 / Integer Limits | INT_MAX, INT_MIN, CHAR_MAX |
| `<float.h>` | 浮点数限制 / Float Limits | FLT_MAX, DBL_MAX, FLT_EPSILON |
| `<stddef.h>` | 标准定义 / Standard Definitions | NULL, size_t, ptrdiff_t, offsetof |

### 错误处理 / Error Handling

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<errno.h>` | 错误号 / Error Numbers | errno, EDOM, ERANGE |
| `<assert.h>` | 断言 / Assertions | assert() |

### 高级功能 / Advanced Features

| 头文件 / Header | 功能 / Function | 主要内容 / Main Contents |
|----------------|-----------------|-------------------------|
| `<signal.h>` | 信号处理 / Signal Handling | signal, raise, SIGINT, SIGTERM |
| `<setjmp.h>` | 非本地跳转 / Non-local Jumps | setjmp, longjmp, jmp_buf |
| `<stdarg.h>` | 可变参数 / Variable Arguments | va_list, va_start, va_arg, va_end |
| `<locale.h>` | 本地化 / Localization | setlocale, localeconv |

## 详细说明 / Detailed Description

### 1. `<stdio.h>` - 标准输入输出 / Standard I/O

这是最常用的头文件，提供所有标准输入输出功能。

This is the most commonly used header, providing all standard I/O functionality.

**主要函数 / Main Functions:**

```c
// 控制台I/O / Console I/O
printf(format, ...);     // 格式化输出 / Formatted output
scanf(format, ...);      // 格式化输入 / Formatted input
puts(str);               // 输出字符串 / Output string
gets(str);               // 输入字符串(不安全) / Input string (unsafe)

// 文件I/O / File I/O
FILE *fopen(filename, mode);   // 打开文件 / Open file
int fclose(FILE *fp);          // 关闭文件 / Close file
size_t fread(ptr, size, count, fp);   // 读取数据 / Read data
size_t fwrite(ptr, size, count, fp);  // 写入数据 / Write data
char *fgets(str, n, fp);       // 读取一行 / Read line
int fputs(str, fp);            // 写入字符串 / Write string

// 格式化到字符串 / Format to string
sprintf(str, format, ...);     // 格式化到字符串 / Format to string
snprintf(str, size, format, ...);  // 安全版本 / Safe version
```

**文件打开模式 / File Open Modes:**
- `"r"` - 读取 / Read
- `"w"` - 写入(覆盖) / Write (overwrite)
- `"a"` - 追加 / Append
- `"r+"` - 读写 / Read and write
- `"rb"` - 二进制读取 / Binary read
- `"wb"` - 二进制写入 / Binary write

### 2. `<stdlib.h>` - 标准库函数 / Standard Library

提供内存管理、类型转换、随机数等功能。

Provides memory management, type conversion, random numbers, etc.

**内存管理 / Memory Management:**
```c
void *malloc(size_t size);           // 分配内存 / Allocate memory
void *calloc(size_t n, size_t size); // 分配并清零 / Allocate and zero
void *realloc(void *ptr, size_t size); // 重新分配 / Reallocate
void free(void *ptr);                // 释放内存 / Free memory
```

**类型转换 / Type Conversion:**
```c
int atoi(const char *str);    // 字符串转整数 / String to int
long atol(const char *str);   // 字符串转长整数 / String to long
double atof(const char *str); // 字符串转浮点数 / String to double
long strtol(str, &endptr, base); // 更安全的转换 / Safer conversion
```

**随机数 / Random Numbers:**
```c
void srand(unsigned int seed);  // 设置随机种子 / Set random seed
int rand(void);                 // 生成随机数 / Generate random number
```

**程序控制 / Program Control:**
```c
void exit(int status);    // 正常退出 / Normal exit
void abort(void);         // 异常终止 / Abort
int atexit(void (*func)(void)); // 注册退出函数 / Register exit handler
```

### 3. `<string.h>` - 字符串操作 / String Operations

提供字符串和内存操作函数。

Provides string and memory operation functions.

**字符串函数 / String Functions:**
```c
size_t strlen(const char *str);           // 字符串长度 / String length
char *strcpy(char *dest, const char *src); // 复制 / Copy
char *strncpy(dest, src, n);              // 安全复制 / Safe copy
char *strcat(char *dest, const char *src); // 连接 / Concatenate
int strcmp(const char *s1, const char *s2); // 比较 / Compare
char *strstr(haystack, needle);           // 查找子串 / Find substring
char *strchr(const char *s, int c);       // 查找字符 / Find character
char *strtok(char *str, const char *delim); // 分割 / Tokenize
```

**内存函数 / Memory Functions:**
```c
void *memcpy(void *dest, const void *src, size_t n);  // 复制 / Copy
void *memmove(void *dest, const void *src, size_t n); // 安全复制 / Safe copy
void *memset(void *s, int c, size_t n);    // 设置 / Set
int memcmp(const void *s1, const void *s2, size_t n); // 比较 / Compare
```

### 4. `<math.h>` - 数学函数 / Math Functions

提供数学运算函数。**编译时需要链接 `-lm`**

Provides mathematical functions. **Compile with `-lm` flag**

**基本运算 / Basic Operations:**
```c
double sqrt(double x);      // 平方根 / Square root
double pow(double x, double y); // 幂运算 / Power
double fabs(double x);      // 绝对值 / Absolute value
double fmod(double x, double y); // 取余 / Modulo
```

**三角函数 / Trigonometric:**
```c
double sin(double x);   // 正弦 / Sine
double cos(double x);   // 余弦 / Cosine
double tan(double x);   // 正切 / Tangent
double asin(double x);  // 反正弦 / Arc sine
```

**指数和对数 / Exponential and Logarithmic:**
```c
double exp(double x);   // e^x
double log(double x);   // 自然对数 / Natural log
double log10(double x); // 常用对数 / Common log
```

**取整函数 / Rounding:**
```c
double ceil(double x);  // 向上取整 / Ceiling
double floor(double x); // 向下取整 / Floor
double round(double x); // 四舍五入 / Round
```

### 5. `<time.h>` - 时间日期 / Time and Date

提供时间和日期处理函数。

Provides time and date handling functions.

```c
time_t time(time_t *t);           // 获取当前时间 / Get current time
struct tm *localtime(const time_t *t); // 转为本地时间 / Convert to local
struct tm *gmtime(const time_t *t);    // 转为UTC时间 / Convert to UTC
size_t strftime(str, max, format, tm); // 格式化时间 / Format time
clock_t clock(void);              // CPU时间 / CPU time
double difftime(time_t t1, time_t t2); // 时间差 / Time difference
```

**struct tm 成员 / struct tm Members:**
- `tm_year` - 年份(从1900年算起) / Year since 1900
- `tm_mon` - 月份(0-11) / Month (0-11)
- `tm_mday` - 日期(1-31) / Day of month (1-31)
- `tm_hour` - 小时(0-23) / Hour (0-23)
- `tm_min` - 分钟(0-59) / Minute (0-59)
- `tm_sec` - 秒(0-60) / Second (0-60)

### 6. `<ctype.h>` - 字符分类 / Character Classification

提供字符测试和转换函数。

Provides character testing and conversion functions.

```c
// 测试函数 / Test functions
int isalpha(int c);  // 是否字母 / Is letter
int isdigit(int c);  // 是否数字 / Is digit
int isalnum(int c);  // 是否字母或数字 / Is alphanumeric
int isspace(int c);  // 是否空白 / Is whitespace
int isupper(int c);  // 是否大写 / Is uppercase
int islower(int c);  // 是否小写 / Is lowercase

// 转换函数 / Conversion functions
int toupper(int c);  // 转大写 / To uppercase
int tolower(int c);  // 转小写 / To lowercase
```

### 7. `<stdint.h>` - 固定宽度整数 / Fixed-width Integers

提供固定大小的整数类型，保证跨平台一致性。

Provides fixed-size integer types for cross-platform consistency.

```c
// 精确宽度类型 / Exact-width types
int8_t, int16_t, int32_t, int64_t
uint8_t, uint16_t, uint32_t, uint64_t

// 限制常量 / Limit constants
INT8_MIN, INT8_MAX, UINT8_MAX
INT16_MIN, INT16_MAX, UINT16_MAX
INT32_MIN, INT32_MAX, UINT32_MAX
INT64_MIN, INT64_MAX, UINT64_MAX
```

### 8. `<stdbool.h>` - 布尔类型 / Boolean Type

C99引入的布尔类型支持。

Boolean type support introduced in C99.

```c
bool flag = true;   // 布尔变量 / Boolean variable
bool result = false;
// true = 1, false = 0
```

### 9. `<errno.h>` - 错误处理 / Error Handling

提供错误码机制。

Provides error code mechanism.

```c
// 检查错误 / Check error
if (some_function() == -1) {
    if (errno == ENOENT) {
        // 文件不存在 / File not found
    }
    perror("Error");  // 打印错误信息 / Print error
}

// 常见错误码 / Common error codes
EDOM    // 数学域错误 / Math domain error
ERANGE  // 结果超出范围 / Result out of range
ENOENT  // 文件不存在 / No such file
ENOMEM  // 内存不足 / Out of memory
```

### 10. `<assert.h>` - 断言 / Assertions

用于调试的断言宏。

Assertion macro for debugging.

```c
assert(expression);  // 如果expression为假则终止程序
                     // If expression is false, program terminates

// 禁用断言 / Disable assertions
#define NDEBUG
#include <assert.h>
```

## 与Java的对比 / Comparison with Java

| C Header | Java Equivalent | 说明 / Notes |
|----------|-----------------|--------------|
| `<stdio.h>` | `System.out`, `Scanner`, `java.io.*` | Java有更高级的I/O抽象 |
| `<stdlib.h>` | N/A (自动内存管理) | Java有垃圾回收 |
| `<string.h>` | `String` 类方法 | Java字符串是对象 |
| `<math.h>` | `Math` 类 | 功能类似 |
| `<time.h>` | `java.time.*` | Java 8+有更好的时间API |
| `<ctype.h>` | `Character` 类 | 功能类似 |
| `<stdbool.h>` | `boolean` 原始类型 | Java内置布尔类型 |

**关键区别 / Key Differences:**

1. **包含方式 / Inclusion:**
   - C: `#include <header.h>` (预处理器指令)
   - Java: `import package.Class;` (编译器处理)

2. **自动导入 / Auto Import:**
   - C: 必须显式包含所有头文件
   - Java: `java.lang` 自动导入

3. **内存管理 / Memory Management:**
   - C: 需要 `<stdlib.h>` 手动管理
   - Java: 自动垃圾回收

4. **类型安全 / Type Safety:**
   - C: 头文件提供声明但不强制类型检查
   - Java: 强类型检查

## 编译和运行 / Build and Run

```bash
make
./header_files
```

或者手动编译 / Or compile manually:

```bash
gcc -Wall -Wextra -std=c11 -o header_files header_files.c -lm
./header_files
```

**注意:** 由于使用了 `<math.h>`，编译时必须链接数学库 `-lm`。

**Note:** Because `<math.h>` is used, you must link the math library with `-lm`.

## 创建自定义头文件 / Creating Custom Header Files

### 头文件结构 / Header File Structure

```c
// myheader.h
#ifndef MYHEADER_H  // 头文件保护 / Include guard
#define MYHEADER_H

// 包含其他需要的头文件 / Include needed headers
#include <stdio.h>

// 宏定义 / Macro definitions
#define MAX_SIZE 100

// 类型定义 / Type definitions
typedef struct {
    int x;
    int y;
} Point;

// 函数声明 / Function declarations
void my_function(int param);
int calculate_sum(int *array, int size);

#endif // MYHEADER_H
```

### 最佳实践 / Best Practices

1. **始终使用头文件保护** / Always use include guards
   ```c
   #ifndef HEADER_NAME_H
   #define HEADER_NAME_H
   // ... content ...
   #endif
   ```

2. **只放声明，不放定义** / Only declarations, not definitions
   - 函数实现放在 `.c` 文件中
   - Put implementations in `.c` files

3. **最小化依赖** / Minimize dependencies
   - 只包含必要的头文件
   - Only include necessary headers

4. **使用前向声明** / Use forward declarations
   - 减少编译依赖
   - Reduce compile dependencies

## 学习建议 / Learning Tips

1. 从最常用的头文件开始：`<stdio.h>`, `<stdlib.h>`, `<string.h>`
2. 了解每个函数的返回值和错误处理方式
3. 使用 `man` 命令查看详细文档：`man printf`
4. 编译时使用 `-Wall -Wextra` 捕获潜在问题
5. 理解头文件和源文件的分离原则

## 参考资料 / References

- [C Standard Library - cppreference.com](https://en.cppreference.com/w/c/header)
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- `man` pages for individual functions
