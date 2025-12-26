# C语言文件操作 / File Operations in C

## 概述 / Overview

本示例演示C语言的文件I/O操作，包括文本文件和二进制文件的读写。

This example demonstrates file I/O operations in C, including reading and writing text and binary files.

## 关键概念 / Key Concepts

### 文件打开模式 / File Open Modes

| 模式 / Mode | 说明 / Description |
|------------|-------------------|
| `"r"` | 只读（文本）/ Read only (text) |
| `"w"` | 写入，覆盖（文本）/ Write, overwrite (text) |
| `"a"` | 追加（文本）/ Append (text) |
| `"r+"` | 读写（文本）/ Read/write (text) |
| `"w+"` | 读写，覆盖（文本）/ Read/write, overwrite (text) |
| `"rb"` | 只读（二进制）/ Read only (binary) |
| `"wb"` | 写入（二进制）/ Write (binary) |
| `"ab"` | 追加（二进制）/ Append (binary) |

### 常用函数 / Common Functions

**文本文件 / Text Files:**
```c
fprintf(file, "format", ...);  // 格式化写入 / Formatted write
fscanf(file, "format", ...);   // 格式化读取 / Formatted read
fgets(buffer, size, file);     // 读取一行 / Read a line
fputs(string, file);           // 写入字符串 / Write a string
```

**二进制文件 / Binary Files:**
```c
fread(buffer, size, count, file);   // 读取 / Read
fwrite(buffer, size, count, file);  // 写入 / Write
```

**文件定位 / File Positioning:**
```c
fseek(file, offset, origin);  // 移动文件指针 / Move file pointer
ftell(file);                  // 获取当前位置 / Get current position
rewind(file);                 // 回到开始 / Rewind to beginning
```

## 与Java的对比 / Comparison with Java

| 操作 / Operation | C | Java |
|-----------------|---|------|
| 打开文件 / Open | `fopen()` | `new FileReader()` |
| 关闭文件 / Close | `fclose()` | `close()` 或 try-with-resources |
| 读取行 / Read line | `fgets()` | `BufferedReader.readLine()` |
| 写入 / Write | `fprintf()` | `PrintWriter.println()` |
| 二进制读写 / Binary I/O | `fread/fwrite` | `DataInputStream/DataOutputStream` |

**关键区别 / Key Differences:**
- C需要手动检查`NULL`并关闭文件
- Java有异常处理和自动资源管理
- C的文本/二进制模式在Windows上有区别（换行符转换）

## 编译和运行 / Build and Run

```bash
make
./file_operations
```

## 最佳实践 / Best Practices

1. 始终检查`fopen()`返回值
2. 使用后关闭文件（`fclose()`）
3. 使用`perror()`进行错误报告
4. 二进制数据使用`"rb"`/`"wb"`模式
5. 注意缓冲区大小，避免溢出
