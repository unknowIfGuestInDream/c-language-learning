# C语言错误处理 / Error Handling in C

## 概述 / Overview

本示例演示C语言的错误处理机制，包括errno、perror和strerror的使用。

This example demonstrates C error handling mechanisms including errno, perror, and strerror.

## 关键概念 / Key Concepts

### errno全局变量 / errno Global Variable

errno是一个定义在`<errno.h>`中的全局变量，用于存储最近一次系统调用或库函数的错误码。

```c
#include <errno.h>

FILE *fp = fopen("nonexistent.txt", "r");
if (fp == NULL) {
    int saved_errno = errno;  // 立即保存errno / Save errno immediately
    printf("Error code: %d\n", saved_errno);
}
```

### perror()函数 / perror() Function

perror()打印一个描述性错误消息到标准错误输出。

```c
FILE *fp = fopen("nonexistent.txt", "r");
if (fp == NULL) {
    perror("Failed to open file");
    // 输出: Failed to open file: No such file or directory
}
```

### strerror()函数 / strerror() Function

strerror()返回指向错误描述字符串的指针。

```c
#include <string.h>

printf("Error: %s\n", strerror(ENOENT));
// 输出: Error: No such file or directory
```

## 常见errno值 / Common errno Values

| 常量 / Constant | 含义 / Meaning |
|----------------|----------------|
| ENOENT | 文件或目录不存在 / No such file or directory |
| EACCES | 权限被拒绝 / Permission denied |
| ENOMEM | 内存不足 / Out of memory |
| EINVAL | 无效参数 / Invalid argument |
| EEXIST | 文件已存在 / File exists |
| EBADF | 错误的文件描述符 / Bad file descriptor |

## 错误处理模式 / Error Handling Patterns

### 返回值检查 / Return Value Checking

```c
void *ptr = malloc(size);
if (ptr == NULL) {
    // 处理内存分配失败 / Handle allocation failure
    return -1;
}
```

### goto清理模式 / goto Cleanup Pattern

```c
int process_file(const char *filename) {
    char *buffer = malloc(1024);
    if (buffer == NULL) goto error;
    
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) goto cleanup_buffer;
    
    // 处理文件... / Process file...
    
    fclose(fp);
    free(buffer);
    return 0;

cleanup_buffer:
    free(buffer);
error:
    return -1;
}
```

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 错误报告 / Error Reporting | errno, 返回值 / return values | 异常 / Exceptions |
| 错误信息 / Error Messages | perror(), strerror() | e.getMessage() |
| 清理资源 / Resource Cleanup | goto或手动 / goto or manual | try-finally, try-with-resources |
| 错误传播 / Error Propagation | 手动返回 / Manual return | 自动抛出 / Automatic throw |

### Java异常示例 / Java Exception Example

```java
// Java
try {
    FileReader fr = new FileReader("file.txt");
} catch (FileNotFoundException e) {
    System.err.println("Error: " + e.getMessage());
}
```

### C错误处理示例 / C Error Handling Example

```c
// C
FILE *fp = fopen("file.txt", "r");
if (fp == NULL) {
    fprintf(stderr, "Error: %s\n", strerror(errno));
}
```

## 编译和运行 / Build and Run

```bash
make
./error_handling
```
