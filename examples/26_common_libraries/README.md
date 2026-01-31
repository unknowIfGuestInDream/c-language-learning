# C语言常用库 / Common C Libraries

## 概述 / Overview

本示例演示C标准库中最常用的函数和库。

This example demonstrates the most commonly used functions and libraries from the C standard library.

## 主要标准库 / Main Standard Libraries

### 1. stdio.h - 标准输入输出 / Standard I/O
- `printf()`, `scanf()` - 控制台I/O
- `fprintf()`, `fscanf()` - 文件I/O
- `fopen()`, `fclose()` - 文件操作
- `fgets()`, `fputs()` - 行读写

### 2. stdlib.h - 标准库函数 / Standard Library
- `malloc()`, `free()` - 动态内存分配
- `atoi()`, `atof()` - 字符串转数字
- `rand()`, `srand()` - 随机数
- `exit()`, `abort()` - 程序终止

### 3. string.h - 字符串操作 / String Operations
- `strlen()`, `strcpy()`, `strcat()` - 基本字符串操作
- `strcmp()`, `strstr()` - 字符串比较和查找
- `memcpy()`, `memset()` - 内存操作

### 4. math.h - 数学函数 / Math Functions
- `sqrt()`, `pow()`, `exp()`, `log()` - 基本数学运算
- `sin()`, `cos()`, `tan()` - 三角函数
- `ceil()`, `floor()`, `round()` - 取整函数
- **注意**: 编译时需要链接math库 `-lm`

### 5. time.h - 时间日期 / Time and Date
- `time()` - 获取当前时间
- `localtime()`, `gmtime()` - 时间转换
- `strftime()` - 格式化时间
- `clock()` - 测量CPU时间

### 6. ctype.h - 字符分类 / Character Classification
- `isalpha()`, `isdigit()`, `isalnum()` - 字符测试
- `isupper()`, `islower()` - 大小写测试
- `toupper()`, `tolower()` - 大小写转换

### 7. 其他常用库 / Other Common Libraries
- `limits.h` - 类型限制常量
- `stdint.h` - 固定宽度整数类型
- `stdbool.h` - 布尔类型
- `assert.h` - 断言宏

## 编译和运行 / Build and Run

```bash
make
./common_libraries
```

**注意**: 使用math.h的函数时，编译需要链接数学库：
```bash
gcc -o program program.c -lm
```

## 与Java的对比 / Comparison with Java

| C库 / C Library | Java等价 / Java Equivalent |
|----------------|---------------------------|
| stdio.h | System.out, Scanner |
| stdlib.h | - (内存管理自动) |
| string.h | String类方法 / String class methods |
| math.h | Math类 / Math class |
| time.h | java.time包 / java.time package |

**关键区别 / Key Differences:**
- C库是函数集合，Java有面向对象的类
- C需要手动内存管理，Java有垃圾回收
- C需要显式包含头文件，Java部分自动导入
