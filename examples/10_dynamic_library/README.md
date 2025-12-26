# C语言动态链接库 / C Dynamic Library

## 概述 / Overview

本示例演示如何创建和使用C语言动态链接库（.so文件）。

This example demonstrates how to create and use C dynamic libraries (.so files).

## 文件说明 / File Description

- `stringlib.h` - 库头文件（函数声明）/ Library header (function declarations)
- `stringlib.c` - 库实现文件 / Library implementation
- `main.c` - 使用库的主程序 / Main program using the library
- `Makefile` - 构建脚本 / Build script

## 创建动态库步骤 / Steps to Create Dynamic Library

### 1. 编译源文件为位置无关代码 / Compile source as position-independent code
```bash
gcc -c -fPIC stringlib.c -o stringlib.o
```
- `-fPIC` = Position Independent Code（位置无关代码，动态库必需）

### 2. 创建动态库 / Create dynamic library

**Linux:**
```bash
gcc -shared -o libstringlib.so stringlib.o
```

**macOS:**
```bash
gcc -dynamiclib -o libstringlib.dylib stringlib.o
```

### 3. 编译主程序并链接 / Compile main program and link
```bash
gcc main.c -L. -lstringlib -o main
```
- `-L.` = 在当前目录查找库 / Look for libraries in current directory
- `-lstringlib` = 链接 libstringlib.so / Link with libstringlib.so

### 4. 运行程序 / Run program

**Linux:**
```bash
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./main
```
或 / or:
```bash
LD_LIBRARY_PATH=. ./main
```

**macOS:**
```bash
export DYLD_LIBRARY_PATH=.:$DYLD_LIBRARY_PATH
./main
```
或 / or:
```bash
DYLD_LIBRARY_PATH=. ./main
```

## 使用Makefile / Using Makefile

```bash
make        # 构建所有内容 / Build everything
make run    # 运行程序 / Run program
make clean  # 清理生成文件 / Clean generated files
```

Makefile会自动检测操作系统并使用正确的命令。
The Makefile automatically detects the operating system and uses the correct commands.

## 动态库特点 / Dynamic Library Characteristics

| 特点 / Feature | 说明 / Description |
|---------------|-------------------|
| 链接时机 / Link Time | 运行时加载 / Loaded at runtime |
| 文件大小 / File Size | 可执行文件小，需要.so文件 / Smaller executable, needs .so file |
| 共享 / Sharing | 多个程序共享同一库 / Multiple programs share same library |
| 更新 / Updates | 只需替换.so文件 / Just replace .so file |
| 文件扩展名 / Extension | .so (Linux), .dylib (macOS), .dll (Windows) |

## 与静态库的对比 / Comparison with Static Library

| 特性 / Feature | 动态库 / Dynamic | 静态库 / Static |
|---------------|-----------------|----------------|
| 链接 / Linking | 运行时 / Runtime | 编译时 / Compile time |
| 大小 / Size | 小（不包含库代码）/ Smaller | 大（包含库代码）/ Larger |
| 更新 / Updates | 替换.so / Replace .so | 重新编译 / Recompile |
| 依赖 / Dependencies | 需.so文件 / Need .so | 无 / None |
| 内存 / Memory | 共享 / Shared | 每个程序独立 / Each program separate |

## 查看动态库信息 / View Dynamic Library Information

**Linux:**
```bash
ldd main                    # 查看程序依赖的动态库 / View library dependencies
nm -D libstringlib.so       # 查看导出的符号 / View exported symbols
readelf -d libstringlib.so  # 查看动态库信息 / View library info
```

**macOS:**
```bash
otool -L main               # 查看程序依赖的动态库 / View library dependencies
nm -gU libstringlib.dylib   # 查看导出的符号 / View exported symbols
```

## 安装动态库 / Installing Dynamic Library

将库安装到系统目录（需要root权限）:
To install library to system directory (needs root):

**Linux:**
```bash
sudo cp libstringlib.so /usr/local/lib/
sudo ldconfig
```

**macOS:**
```bash
sudo cp libstringlib.dylib /usr/local/lib/
```

## 与Java的对比 / Comparison with Java

- **C动态库**: 平台相关，需要为每个平台编译
- **Java JAR**: 跨平台，一次编译到处运行
- **C .so/.dylib/.dll**: 不同平台不同扩展名
- **Java .jar**: 所有平台统一格式
- **JNI**: Java可以通过JNI调用C动态库

## 常见问题 / Common Issues

### 找不到动态库 / Library not found
```
error while loading shared libraries: libstringlib.so: cannot open shared object file
```

**解决方法 / Solution:**
1. 设置 LD_LIBRARY_PATH (Linux) 或 DYLD_LIBRARY_PATH (macOS)
2. 将库复制到系统库目录
3. 使用 rpath 在编译时指定库路径

### 使用rpath / Using rpath
```bash
gcc main.c -L. -lstringlib -Wl,-rpath,. -o main
```
这样程序会在自己所在目录查找库。
This makes the program look for libraries in its own directory.
