# C语言静态库 / C Static Library

## 概述 / Overview

本示例演示如何创建和使用C语言静态库（.a文件）。

This example demonstrates how to create and use C static libraries (.a files).

## 文件说明 / File Description

- `mathlib.h` - 库头文件（函数声明）/ Library header (function declarations)
- `mathlib.c` - 库实现文件 / Library implementation
- `main.c` - 使用库的主程序 / Main program using the library
- `Makefile` - 构建脚本 / Build script

## 创建静态库步骤 / Steps to Create Static Library

### 1. 编译源文件为目标文件 / Compile source to object file
```bash
gcc -c mathlib.c -o mathlib.o
```

### 2. 创建静态库 / Create static library
```bash
ar rcs libmathlib.a mathlib.o
```
- `ar` = archiver (归档工具)
- `r` = replace (替换)
- `c` = create (创建)
- `s` = sort (排序索引)

### 3. 编译主程序并链接 / Compile main program and link
```bash
gcc main.c -L. -lmathlib -o main
```
- `-L.` = 在当前目录查找库 / Look for libraries in current directory
- `-lmathlib` = 链接 libmathlib.a / Link with libmathlib.a

或者直接链接 / Or link directly:
```bash
gcc main.c libmathlib.a -o main
```

## 使用Makefile / Using Makefile

```bash
make        # 构建所有内容 / Build everything
make clean  # 清理生成文件 / Clean generated files
./main      # 运行程序 / Run program
```

## 静态库特点 / Static Library Characteristics

| 特点 / Feature | 说明 / Description |
|---------------|-------------------|
| 链接时机 / Link Time | 编译时链接 / Linked at compile time |
| 文件大小 / File Size | 可执行文件包含库代码，较大 / Executable contains library code, larger |
| 运行依赖 / Runtime Dependency | 无需外部文件 / No external files needed |
| 更新 / Updates | 需要重新编译程序 / Need to recompile program |
| 文件扩展名 / File Extension | .a (Linux/Unix), .lib (Windows) |

## 与动态库的对比 / Comparison with Dynamic Library

| 特性 / Feature | 静态库 / Static | 动态库 / Dynamic |
|---------------|----------------|-----------------|
| 链接 / Linking | 编译时 / Compile time | 运行时 / Runtime |
| 大小 / Size | 大 / Larger | 小 / Smaller |
| 更新 / Updates | 需重编译 / Need recompile | 只需替换.so文件 / Just replace .so |
| 依赖 / Dependencies | 无 / None | 需.so文件 / Need .so file |

## 与Java的对比 / Comparison with Java

- **C静态库**: 编译时链接，类似将JAR内容复制到程序中
- **Java JAR**: 运行时加载，更灵活
- **C .a/.lib**: 平台相关
- **Java .jar**: 跨平台

## 查看静态库内容 / View Static Library Contents

```bash
ar -t libmathlib.a  # 列出库中的目标文件 / List object files in library
nm libmathlib.a     # 显示符号表 / Show symbol table
```
