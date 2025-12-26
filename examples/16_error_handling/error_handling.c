/**
 * C语言错误处理
 * Error Handling in C
 * 
 * 本示例演示C语言的错误处理机制，包括errno、perror和strerror
 * This example demonstrates C error handling mechanisms including errno, perror, and strerror
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <math.h>

// 函数声明 / Function declarations
void demonstrate_errno();
void demonstrate_perror();
void demonstrate_strerror();
void demonstrate_return_codes();
void custom_error_handling();

// 自定义错误码 / Custom error codes
typedef enum {
    SUCCESS = 0,
    ERR_NULL_POINTER = -1,
    ERR_INVALID_INPUT = -2,
    ERR_OUT_OF_MEMORY = -3,
    ERR_FILE_NOT_FOUND = -4
} ErrorCode;

// 获取错误信息 / Get error message
const char* get_error_message(ErrorCode code) {
    switch (code) {
        case SUCCESS: return "成功 / Success";
        case ERR_NULL_POINTER: return "空指针错误 / Null pointer error";
        case ERR_INVALID_INPUT: return "无效输入 / Invalid input";
        case ERR_OUT_OF_MEMORY: return "内存不足 / Out of memory";
        case ERR_FILE_NOT_FOUND: return "文件未找到 / File not found";
        default: return "未知错误 / Unknown error";
    }
}

// 示例函数：带错误码返回 / Example function with error code return
ErrorCode divide(int a, int b, int *result) {
    if (result == NULL) {
        return ERR_NULL_POINTER;
    }
    if (b == 0) {
        return ERR_INVALID_INPUT;
    }
    *result = a / b;
    return SUCCESS;
}

int main() {
    printf("=== C语言错误处理 / Error Handling in C ===\n\n");
    
    // 1. errno全局变量 / errno global variable
    printf("1. errno全局变量 / errno Global Variable:\n");
    demonstrate_errno();
    
    // 2. perror函数 / perror function
    printf("2. perror()函数 / perror() Function:\n");
    demonstrate_perror();
    
    // 3. strerror函数 / strerror function
    printf("3. strerror()函数 / strerror() Function:\n");
    demonstrate_strerror();
    
    // 4. 返回值错误处理 / Return value error handling
    printf("4. 返回值错误处理 / Return Value Error Handling:\n");
    demonstrate_return_codes();
    
    // 5. 自定义错误处理 / Custom error handling
    printf("5. 自定义错误处理 / Custom Error Handling:\n");
    custom_error_handling();
    
    // 6. 错误处理最佳实践 / Error handling best practices
    printf("6. 错误处理最佳实践 / Error Handling Best Practices:\n");
    printf("  ✓ 始终检查函数返回值 / Always check function return values\n");
    printf("  ✓ 使用errno时先保存，避免被覆盖 / Save errno immediately to avoid overwriting\n");
    printf("  ✓ 调用库函数前将errno设为0 / Set errno to 0 before calling library functions\n");
    printf("  ✓ 提供有意义的错误信息 / Provide meaningful error messages\n");
    printf("  ✓ 清理资源后再返回错误 / Clean up resources before returning on error\n");
    printf("  ✓ 使用goto进行统一的错误清理 / Use goto for unified error cleanup\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("错误处理机制 / Error Handling Mechanisms:\n");
    printf("  - errno: 全局错误码变量 / Global error code variable\n");
    printf("  - perror(): 打印错误描述 / Print error description\n");
    printf("  - strerror(): 获取错误字符串 / Get error string\n");
    printf("  - 返回值: 函数返回错误码 / Return values: function error codes\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java使用异常机制 / Java uses exception mechanism\n");
    printf("  - C使用返回值和errno / C uses return values and errno\n");
    printf("  - Java异常有栈追踪 / Java exceptions have stack traces\n");
    printf("  - C需要手动传递错误信息 / C requires manual error propagation\n");
    printf("  - Java: try-catch-finally / Java: try-catch-finally\n");
    printf("  - C: if检查 + goto清理 / C: if checks + goto cleanup\n");
    
    return 0;
}

void demonstrate_errno() {
    // errno是一个全局变量，用于存储最近一次错误的错误码
    // errno is a global variable storing the error code of the last error
    
    printf("  errno介绍 / Introduction to errno:\n");
    printf("    errno定义在<errno.h>中 / errno is defined in <errno.h>\n");
    printf("    每个线程有自己的errno / Each thread has its own errno\n\n");
    
    // 示例：文件打开失败 / Example: file open failure
    errno = 0;  // 重置errno / Reset errno
    FILE *fp = fopen("/nonexistent/file.txt", "r");
    
    if (fp == NULL) {
        int saved_errno = errno;  // 保存errno / Save errno
        printf("  文件打开失败示例 / File open failure example:\n");
        printf("    errno = %d\n", saved_errno);
        printf("    含义 / Meaning: %s\n", strerror(saved_errno));
    } else {
        fclose(fp);
    }
    printf("\n");
    
    // 常见errno值 / Common errno values
    printf("  常见errno值 / Common errno values:\n");
    printf("    ENOENT  (%d): 文件或目录不存在 / No such file or directory\n", ENOENT);
    printf("    EACCES  (%d): 权限被拒绝 / Permission denied\n", EACCES);
    printf("    ENOMEM  (%d): 内存不足 / Out of memory\n", ENOMEM);
    printf("    EINVAL  (%d): 无效参数 / Invalid argument\n", EINVAL);
    printf("    EEXIST  (%d): 文件已存在 / File exists\n", EEXIST);
    printf("\n");
}

void demonstrate_perror() {
    // perror打印自定义前缀 + 错误描述
    // perror prints custom prefix + error description
    
    printf("  perror()用法 / perror() usage:\n");
    printf("    格式: perror(\"前缀\") / Format: perror(\"prefix\")\n");
    printf("    输出: 前缀: 错误描述 / Output: prefix: error description\n\n");
    
    // 示例 / Example
    errno = 0;
    FILE *fp = fopen("/nonexistent/path/file.txt", "r");
    
    if (fp == NULL) {
        printf("  示例输出 / Example output:\n    ");
        perror("fopen失败 / fopen failed");
    } else {
        fclose(fp);
    }
    printf("\n");
}

void demonstrate_strerror() {
    // strerror返回错误描述字符串
    // strerror returns error description string
    
    printf("  strerror()用法 / strerror() usage:\n");
    printf("    格式: char *strerror(int errnum)\n");
    printf("    返回: 错误描述字符串 / Returns: error description string\n\n");
    
    // 打印一些常见错误的描述 / Print descriptions of common errors
    printf("  常见错误描述 / Common error descriptions:\n");
    int common_errors[] = {ENOENT, EACCES, ENOMEM, EINVAL, EEXIST, EBADF};
    int num_errors = sizeof(common_errors) / sizeof(common_errors[0]);
    
    for (int i = 0; i < num_errors; i++) {
        printf("    errno %d: %s\n", common_errors[i], strerror(common_errors[i]));
    }
    printf("\n");
    
    // 结合使用示例 / Combined usage example
    printf("  结合使用示例 / Combined usage example:\n");
    errno = 0;
    FILE *fp = fopen("/tmp/test_nonexistent_12345.txt", "r");
    if (fp == NULL) {
        int saved_errno = errno;
        printf("    错误码 / Error code: %d\n", saved_errno);
        printf("    错误描述 / Error description: %s\n", strerror(saved_errno));
    } else {
        fclose(fp);
    }
    printf("\n");
}

void demonstrate_return_codes() {
    // C语言常用返回值约定 / C return value conventions
    
    printf("  返回值约定 / Return Value Conventions:\n");
    printf("    成功通常返回0或正数 / Success usually returns 0 or positive\n");
    printf("    失败通常返回-1或负数 / Failure usually returns -1 or negative\n");
    printf("    指针函数失败返回NULL / Pointer functions return NULL on failure\n\n");
    
    // malloc示例 / malloc example
    printf("  malloc返回值检查 / malloc return value check:\n");
    void *ptr = malloc(sizeof(int) * 100);
    if (ptr == NULL) {
        printf("    内存分配失败! / Memory allocation failed!\n");
    } else {
        printf("    内存分配成功 / Memory allocation successful\n");
        free(ptr);
    }
    printf("\n");
    
    // fopen示例 / fopen example
    printf("  fopen返回值检查 / fopen return value check:\n");
    FILE *fp = fopen("/tmp/test_error_handling.txt", "w");
    if (fp == NULL) {
        printf("    文件打开失败: %s\n", strerror(errno));
    } else {
        printf("    文件打开成功 / File opened successfully\n");
        fclose(fp);
        // 清理测试文件 / Cleanup test file
        remove("/tmp/test_error_handling.txt");
    }
    printf("\n");
}

void custom_error_handling() {
    // 使用自定义错误码和错误处理函数
    // Using custom error codes and error handling functions
    
    printf("  使用自定义错误处理 / Using custom error handling:\n\n");
    
    // 测试正常情况 / Test normal case
    int result;
    ErrorCode err = divide(10, 2, &result);
    if (err == SUCCESS) {
        printf("    10 / 2 = %d\n", result);
    } else {
        printf("    错误 / Error: %s\n", get_error_message(err));
    }
    
    // 测试除以零 / Test division by zero
    err = divide(10, 0, &result);
    if (err == SUCCESS) {
        printf("    10 / 0 = %d\n", result);
    } else {
        printf("    10 / 0 错误 / Error: %s\n", get_error_message(err));
    }
    
    // 测试空指针 / Test null pointer
    err = divide(10, 2, NULL);
    if (err == SUCCESS) {
        printf("    结果已存储 / Result stored\n");
    } else {
        printf("    NULL指针错误 / Error: %s\n", get_error_message(err));
    }
    printf("\n");
    
    // goto错误处理模式 / goto error handling pattern
    printf("  goto错误处理模式 / goto Error Handling Pattern:\n");
    printf("    int process() {\n");
    printf("        char *buf = malloc(100);\n");
    printf("        if (buf == NULL) goto error;\n");
    printf("        \n");
    printf("        FILE *fp = fopen(\"file.txt\", \"r\");\n");
    printf("        if (fp == NULL) goto cleanup_buf;\n");
    printf("        \n");
    printf("        // 处理... / Processing...\n");
    printf("        \n");
    printf("        fclose(fp);\n");
    printf("        free(buf);\n");
    printf("        return 0;\n");
    printf("        \n");
    printf("    cleanup_buf:\n");
    printf("        free(buf);\n");
    printf("    error:\n");
    printf("        return -1;\n");
    printf("    }\n");
    printf("\n");
}
