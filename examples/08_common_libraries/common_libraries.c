#include <stdio.h>      // 标准输入输出 / Standard I/O
#include <stdlib.h>     // 标准库函数 / Standard library functions
#include <string.h>     // 字符串操作 / String operations
#include <math.h>       // 数学函数 / Math functions
#include <time.h>       // 时间日期 / Time and date
#include <ctype.h>      // 字符分类 / Character classification
#include <stdint.h>     // 固定宽度整数 / Fixed-width integers
#include <stdbool.h>    // 布尔类型 / Boolean type
#include <limits.h>     // 类型限制 / Type limits
#include <assert.h>     // 断言 / Assertions

/**
 * C语言常用库函数示例
 * Common C Library Functions
 * 
 * 本示例演示C标准库中最常用的函数
 * This example demonstrates the most commonly used functions from C standard library
 */

int main() {
    printf("=== C语言常用库函数 / Common C Library Functions ===\n\n");
    
    // 1. stdio.h - 标准输入输出 / Standard I/O
    printf("1. stdio.h - 标准输入输出 / Standard I/O:\n");
    printf("  printf() - 格式化输出 / Formatted output\n");
    fprintf(stdout, "  fprintf() - 输出到文件流 / Output to file stream\n");
    
    char buffer[100];
    sprintf(buffer, "  sprintf() - 格式化到字符串 / Format to string: %d", 42);
    printf("%s\n", buffer);
    
    snprintf(buffer, sizeof(buffer), "  snprintf() - 安全的格式化 / Safe formatting");
    printf("%s\n", buffer);
    printf("\n");
    
    // 2. stdlib.h - 标准库函数 / Standard Library Functions
    printf("2. stdlib.h - 标准库函数 / Standard Library Functions:\n");
    
    // 内存分配 / Memory allocation
    int *ptr = (int*)malloc(sizeof(int) * 5);
    printf("  malloc() - 分配内存 / Allocate memory\n");
    ptr = (int*)realloc(ptr, sizeof(int) * 10);
    printf("  realloc() - 重新分配内存 / Reallocate memory\n");
    free(ptr);
    printf("  free() - 释放内存 / Free memory\n");
    
    // 字符串转换 / String conversion
    int num = atoi("12345");
    printf("  atoi(\"12345\") = %d\n", num);
    
    double fnum = atof("3.14159");
    printf("  atof(\"3.14159\") = %.5f\n", fnum);
    
    // 随机数 / Random numbers
    srand(time(NULL));  // 设置随机种子 / Set random seed
    printf("  rand() - 随机数 / Random numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100);
    }
    printf("\n");
    
    // 绝对值 / Absolute value
    printf("  abs(-42) = %d\n", abs(-42));
    printf("\n");
    
    // 3. string.h - 字符串操作 / String Operations
    printf("3. string.h - 字符串操作 / String Operations:\n");
    
    char str1[50] = "Hello";
    char str2[50] = "World";
    
    printf("  strlen(\"%s\") = %zu\n", str1, strlen(str1));
    
    strcpy(str1, "New String");
    printf("  strcpy() - 复制字符串 / Copy string: %s\n", str1);
    
    strcat(str1, " Extended");
    printf("  strcat() - 连接字符串 / Concatenate: %s\n", str1);
    
    printf("  strcmp(\"apple\", \"banana\") = %d\n", strcmp("apple", "banana"));
    
    char *pos = strstr("Hello World", "World");
    if (pos) {
        printf("  strstr() - 查找子串 / Find substring: 找到 / Found\n");
    }
    
    memset(str2, 'A', 5);
    str2[5] = '\0';
    printf("  memset() - 设置内存 / Set memory: %s\n", str2);
    printf("\n");
    
    // 4. math.h - 数学函数 / Math Functions
    printf("4. math.h - 数学函数 / Math Functions:\n");
    printf("  sqrt(16.0) = %.2f\n", sqrt(16.0));
    printf("  pow(2.0, 3.0) = %.2f\n", pow(2.0, 3.0));
    printf("  sin(3.14159/2) = %.4f\n", sin(3.14159/2));
    printf("  cos(0.0) = %.4f\n", cos(0.0));
    printf("  log(2.71828) = %.4f\n", log(2.71828));
    printf("  log10(100.0) = %.2f\n", log10(100.0));
    printf("  ceil(3.14) = %.2f\n", ceil(3.14));
    printf("  floor(3.14) = %.2f\n", floor(3.14));
    printf("  round(3.14) = %.2f\n", round(3.14));
    printf("  fabs(-3.14) = %.2f\n", fabs(-3.14));
    printf("\n");
    
    // 5. time.h - 时间日期 / Time and Date
    printf("5. time.h - 时间日期 / Time and Date:\n");
    
    time_t now = time(NULL);
    printf("  time(NULL) - Unix时间戳 / Unix timestamp: %ld\n", (long)now);
    
    struct tm *local = localtime(&now);
    printf("  localtime() - 本地时间 / Local time:\n");
    printf("    年 / Year: %d\n", local->tm_year + 1900);
    printf("    月 / Month: %d\n", local->tm_mon + 1);
    printf("    日 / Day: %d\n", local->tm_mday);
    printf("    时 / Hour: %d\n", local->tm_hour);
    printf("    分 / Minute: %d\n", local->tm_min);
    printf("    秒 / Second: %d\n", local->tm_sec);
    
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local);
    printf("  strftime() - 格式化时间 / Formatted time: %s\n", time_str);
    
    // 测量时间差 / Measure time difference
    clock_t start = clock();
    // 做一些计算 / Do some computation
    int sum = 0;
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
    clock_t end = clock();
    double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("  clock() - CPU时间 / CPU time: %.6f 秒 / seconds\n", cpu_time);
    printf("\n");
    
    // 6. ctype.h - 字符分类 / Character Classification
    printf("6. ctype.h - 字符分类 / Character Classification:\n");
    char ch = 'A';
    printf("  isalpha('%c') = %d (是字母 / is letter)\n", ch, isalpha(ch));
    printf("  isdigit('5') = %d\n", isdigit('5'));
    printf("  isalnum('A') = %d (是字母或数字 / is alphanumeric)\n", isalnum('A'));
    printf("  isspace(' ') = %d (是空白字符 / is whitespace)\n", isspace(' '));
    printf("  isupper('A') = %d (是大写 / is uppercase)\n", isupper('A'));
    printf("  islower('a') = %d (是小写 / is lowercase)\n", islower('a'));
    printf("  toupper('a') = '%c'\n", toupper('a'));
    printf("  tolower('A') = '%c'\n", tolower('A'));
    printf("\n");
    
    // 7. limits.h - 类型限制 / Type Limits
    printf("7. limits.h - 类型限制 / Type Limits:\n");
    printf("  CHAR_MAX = %d\n", CHAR_MAX);
    printf("  INT_MAX = %d\n", INT_MAX);
    printf("  INT_MIN = %d\n", INT_MIN);
    printf("  LONG_MAX = %ld\n", LONG_MAX);
    printf("  UCHAR_MAX = %d\n", UCHAR_MAX);
    printf("  UINT_MAX = %u\n", UINT_MAX);
    printf("\n");
    
    // 8. assert.h - 断言 / Assertions
    printf("8. assert.h - 断言 / Assertions:\n");
    printf("  assert() - 用于调试的断言 / Assertion for debugging\n");
    int x = 10;
    assert(x == 10);  // 如果条件为假则终止程序 / Terminates if condition is false
    printf("  assert(x == 10) - 通过 / Passed\n");
    // assert(x == 20);  // 这会导致程序终止 / This would terminate the program
    printf("\n");
    
    // 9. stdint.h - 固定宽度整数 / Fixed-width Integers
    printf("9. stdint.h - 固定宽度整数 / Fixed-width Integers:\n");
    int8_t i8 = 127;
    int16_t i16 = 32767;
    int32_t i32 = 2147483647;
    int64_t i64 = 9223372036854775807LL;
    printf("  int8_t max: %d\n", i8);
    printf("  int16_t max: %d\n", i16);
    printf("  int32_t max: %d\n", i32);
    printf("  int64_t max: %lld\n", (long long)i64);
    printf("\n");
    
    // 10. stdbool.h - 布尔类型 / Boolean Type
    printf("10. stdbool.h - 布尔类型 / Boolean Type:\n");
    bool flag1 = true;
    bool flag2 = false;
    printf("  true = %d\n", flag1);
    printf("  false = %d\n", flag2);
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("最常用的C标准库 / Most Commonly Used C Standard Libraries:\n\n");
    
    printf("1. stdio.h\n");
    printf("   - printf, scanf, fprintf, fscanf\n");
    printf("   - fopen, fclose, fread, fwrite\n");
    printf("   - fgets, fputs, fgetc, fputc\n\n");
    
    printf("2. stdlib.h\n");
    printf("   - malloc, calloc, realloc, free\n");
    printf("   - atoi, atof, atol\n");
    printf("   - rand, srand\n");
    printf("   - abs, labs, exit\n\n");
    
    printf("3. string.h\n");
    printf("   - strlen, strcpy, strcat, strcmp\n");
    printf("   - strstr, strchr, strtok\n");
    printf("   - memcpy, memset, memmove\n\n");
    
    printf("4. math.h\n");
    printf("   - sqrt, pow, exp, log\n");
    printf("   - sin, cos, tan\n");
    printf("   - ceil, floor, round\n");
    printf("   编译时需要链接 -lm / Compile with -lm flag\n\n");
    
    printf("5. time.h\n");
    printf("   - time, clock\n");
    printf("   - localtime, gmtime\n");
    printf("   - strftime, difftime\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C库是函数集合，Java有类和对象 / C libraries are function collections, Java has classes\n");
    printf("  - C需要手动包含头文件，Java自动导入java.lang / C needs manual header inclusion\n");
    printf("  - C的math.h类似Java的Math类 / C's math.h is similar to Java's Math class\n");
    printf("  - C的string.h函数类似Java String类的方法 / C's string.h functions similar to Java String methods\n");
    
    return 0;
}
