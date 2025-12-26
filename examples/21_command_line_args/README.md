# C语言命令行参数处理 / Command Line Arguments in C

## 概述 / Overview

本示例详细演示C语言中argc和argv的使用方法。

This example demonstrates detailed usage of argc and argv in C.

## 关键概念 / Key Concepts

### main函数签名 / main Function Signatures

```c
int main(void)                    // 无参数 / No arguments
int main(int argc, char *argv[])  // 标准形式 / Standard form
int main(int argc, char **argv)   // 等价形式 / Equivalent form
```

### argc和argv / argc and argv

- `argc` - 参数数量 / Argument Count
- `argv` - 参数向量（字符串数组）/ Argument Vector (string array)
- `argv[0]` - 程序名 / Program name
- `argv[argc]` - 始终为NULL / Always NULL

## 代码示例 / Code Examples

### 基本遍历 / Basic Iteration

```c
int main(int argc, char *argv[]) {
    printf("参数数量: %d\n", argc);
    
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    
    return 0;
}
```

### 字符串转数字 / String to Number

```c
// 简单方式（不推荐）/ Simple (not recommended)
int n = atoi(argv[1]);

// 安全方式（推荐）/ Safe (recommended)
char *endptr;
long n = strtol(argv[1], &endptr, 10);
if (endptr == argv[1]) {
    fprintf(stderr, "无效数字 / Invalid number\n");
}
```

### 选项解析 / Option Parsing

```c
for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
        show_help();
    } else if (strcmp(argv[i], "-v") == 0) {
        verbose = 1;
    } else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
        filename = argv[++i];
    }
}
```

### 使用getopt / Using getopt

```c
#include <getopt.h>

int opt;
while ((opt = getopt(argc, argv, "hvf:")) != -1) {
    switch (opt) {
        case 'h': show_help(); break;
        case 'v': verbose = 1; break;
        case 'f': filename = optarg; break;
    }
}
// optind是第一个非选项参数的索引
```

## 选项格式 / Option Formats

| 格式 / Format | 示例 / Example |
|--------------|----------------|
| 短选项 / Short | `-h`, `-v`, `-f file` |
| 长选项 / Long | `--help`, `--file=name` |
| 位置参数 / Positional | `program input output` |

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 函数签名 | `main(int argc, char *argv[])` | `main(String[] args)` |
| 程序名 | `argv[0]` | 不包含 / Not included |
| 参数起始 | `argv[1]` | `args[0]` |
| 参数数量 | `argc` | `args.length` |

### 索引对比 / Index Comparison

```
命令: program arg1 arg2

C语言:
  argc = 3
  argv[0] = "program"
  argv[1] = "arg1"
  argv[2] = "arg2"

Java:
  args.length = 2
  args[0] = "arg1"
  args[1] = "arg2"
```

## 编译和运行 / Build and Run

```bash
make
./command_line_args -v --help file.txt 123
```

## 最佳实践 / Best Practices

- 始终检查argc避免越界访问 / Always check argc to avoid out-of-bounds
- 使用strtol/strtod而非atoi/atof / Use strtol/strtod instead of atoi/atof
- 对复杂选项使用getopt / Use getopt for complex options
- 提供帮助信息 / Provide help information
