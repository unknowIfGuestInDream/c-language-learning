/**
 * C语言标准头文件详解 / C Standard Header Files Guide
 * 
 * 本示例详细介绍C语言标准头文件的功能和使用方法
 * This example provides detailed explanation of C standard header files
 * 
 * 头文件是什么？/ What are Header Files?
 * - 头文件包含函数声明、宏定义、类型定义等
 * - Header files contain function declarations, macro definitions, type definitions, etc.
 * - 使用#include预处理指令包含头文件
 * - Use #include preprocessor directive to include header files
 */

// =====================================================================
// 标准头文件包含 / Standard Header File Includes
// =====================================================================

// 标准输入输出 / Standard I/O
#include <stdio.h>

// 标准库函数 / Standard Library Functions
#include <stdlib.h>

// 字符串操作 / String Operations
#include <string.h>

// 数学函数 / Math Functions
#include <math.h>

// 时间日期 / Time and Date
#include <time.h>

// 字符分类和转换 / Character Classification and Conversion
#include <ctype.h>

// 固定宽度整数类型 / Fixed-width Integer Types
#include <stdint.h>

// 布尔类型 / Boolean Type
#include <stdbool.h>

// 类型限制常量 / Type Limit Constants
#include <limits.h>

// 浮点数限制 / Floating Point Limits
#include <float.h>

// 断言 / Assertions
#include <assert.h>

// 错误号 / Error Numbers
#include <errno.h>

// 信号处理 / Signal Handling
#include <signal.h>

// 非本地跳转 / Non-local Jumps
#include <setjmp.h>

// 可变参数 / Variable Arguments
#include <stdarg.h>

// 标准定义 / Standard Definitions
#include <stddef.h>

// 本地化 / Localization
#include <locale.h>

// =====================================================================
// 辅助函数 / Helper Functions
// =====================================================================

// 演示可变参数函数 / Demonstrate variadic function
static void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// =====================================================================
// 主程序 / Main Program
// =====================================================================

int main(void) {
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║     C语言标准头文件详解 / C Standard Header Files Guide      ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    
    // =====================================================================
    // 1. <stdio.h> - 标准输入输出 / Standard I/O
    // =====================================================================
    printf("\n========================================\n");
    printf("  1. <stdio.h> - 标准输入输出 / Standard I/O\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 提供输入输出函数 / Provides I/O functions\n");
    printf("  - 文件操作函数 / File operations\n");
    printf("  - 格式化输出 / Formatted output\n");
    
    printf("\n主要函数 / Main Functions:\n");
    
    // printf/scanf系列 / printf/scanf family
    printf("\n  [格式化I/O / Formatted I/O]\n");
    int num = 42;
    double pi = 3.14159;
    printf("  printf(): printf(\"num=%%d, pi=%%.2f\", 42, 3.14159)\n");
    printf("  输出/Output: num=%d, pi=%.2f\n", num, pi);
    
    char buffer[100];
    sprintf(buffer, "sprintf示例 / sprintf example: %d", num);
    printf("  sprintf(): %s\n", buffer);
    
    snprintf(buffer, sizeof(buffer), "snprintf: %s", "安全格式化/Safe formatting");
    printf("  snprintf(): %s (带缓冲区大小限制/With buffer size limit)\n", buffer);
    
    // fprintf演示 / fprintf demonstration
    printf("  fprintf(): 输出到指定流/Output to specified stream\n");
    fprintf(stdout, "    示例/Example: fprintf(stdout, ...) 输出到标准输出\n");
    
    // 文件操作 / File operations
    printf("\n  [文件操作 / File Operations]\n");
    printf("  fopen(): 打开文件 / Open file\n");
    printf("    模式/Modes: \"r\"读, \"w\"写, \"a\"追加, \"rb\"二进制读...\n");
    printf("  fclose(): 关闭文件 / Close file\n");
    printf("  fread()/fwrite(): 二进制读写 / Binary read/write\n");
    printf("  fgets()/fputs(): 行读写 / Line read/write\n");
    printf("  fgetc()/fputc(): 字符读写 / Character read/write\n");
    printf("  fseek()/ftell()/rewind(): 文件定位 / File positioning\n");
    printf("  feof()/ferror(): 检查文件状态 / Check file status\n");
    
    // 常量 / Constants
    printf("\n  [常量 / Constants]\n");
    printf("  EOF: 文件结束标志 / End of file marker = %d\n", EOF);
    printf("  NULL: 空指针 / Null pointer\n");
    printf("  BUFSIZ: 缓冲区大小 / Buffer size = %d\n", BUFSIZ);
    printf("  FILENAME_MAX: 最大文件名长度 / Max filename length = %d\n", FILENAME_MAX);
    
    // =====================================================================
    // 2. <stdlib.h> - 标准库函数 / Standard Library Functions
    // =====================================================================
    printf("\n========================================\n");
    printf("  2. <stdlib.h> - 标准库函数 / Standard Library\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 内存管理函数 / Memory management functions\n");
    printf("  - 字符串转换 / String conversion\n");
    printf("  - 随机数生成 / Random number generation\n");
    printf("  - 程序控制 / Program control\n");
    printf("  - 排序和搜索 / Sorting and searching\n");
    
    printf("\n主要函数 / Main Functions:\n");
    
    // 内存管理 / Memory management
    printf("\n  [内存管理 / Memory Management]\n");
    int *arr = (int *)malloc(5 * sizeof(int));
    printf("  malloc(size): 分配内存 / Allocate memory\n");
    printf("    示例/Example: int *p = malloc(5 * sizeof(int))\n");
    
    int *arr2 = (int *)calloc(5, sizeof(int));
    printf("  calloc(n, size): 分配并清零 / Allocate and zero\n");
    printf("    与malloc区别：calloc初始化为0 / Unlike malloc: calloc initializes to 0\n");
    
    arr = (int *)realloc(arr, 10 * sizeof(int));
    printf("  realloc(ptr, size): 重新分配 / Reallocate\n");
    
    free(arr);
    free(arr2);
    printf("  free(ptr): 释放内存 / Free memory\n");
    
    // 字符串转换 / String conversion
    printf("\n  [字符串转换 / String Conversion]\n");
    printf("  atoi(\"123\") = %d\n", atoi("123"));
    printf("  atol(\"123456\") = %ld\n", atol("123456"));
    printf("  atof(\"3.14\") = %.2f\n", atof("3.14"));
    
    char *endptr;
    long val = strtol("100abc", &endptr, 10);
    printf("  strtol(\"100abc\", &endptr, 10) = %ld, 剩余/remaining: \"%s\"\n", val, endptr);
    
    // 随机数 / Random numbers
    printf("\n  [随机数 / Random Numbers]\n");
    srand((unsigned int)time(NULL));
    printf("  srand(seed): 设置随机种子 / Set random seed\n");
    printf("  rand(): 生成随机数 / Generate random: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", rand() % 100);
    }
    printf("\n");
    printf("  RAND_MAX = %d\n", RAND_MAX);
    
    // 数学运算 / Math operations
    printf("\n  [数学运算 / Math Operations]\n");
    printf("  abs(-10) = %d\n", abs(-10));
    printf("  labs(-1000000L) = %ld\n", labs(-1000000L));
    
    div_t result = div(17, 5);
    printf("  div(17, 5) = 商/quot: %d, 余/rem: %d\n", result.quot, result.rem);
    
    // 程序控制 / Program control
    printf("\n  [程序控制 / Program Control]\n");
    printf("  exit(status): 正常退出 / Normal exit\n");
    printf("  abort(): 异常终止 / Abnormal termination\n");
    printf("  atexit(func): 注册退出函数 / Register exit handler\n");
    printf("  system(cmd): 执行系统命令 / Execute system command\n");
    
    // 环境变量 / Environment variables
    printf("\n  [环境变量 / Environment Variables]\n");
    const char *path = getenv("PATH");
    if (path) {
        printf("  getenv(\"PATH\"): 获取环境变量 / Get environment variable\n");
        printf("    PATH长度/length: %zu 字符/chars\n", strlen(path));
    }
    
    // =====================================================================
    // 3. <string.h> - 字符串操作 / String Operations
    // =====================================================================
    printf("\n========================================\n");
    printf("  3. <string.h> - 字符串操作 / String Operations\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 字符串操作函数 / String manipulation functions\n");
    printf("  - 内存操作函数 / Memory operation functions\n");
    printf("  - 字符串比较和搜索 / String comparison and searching\n");
    
    printf("\n主要函数 / Main Functions:\n");
    
    // 字符串操作 / String operations
    printf("\n  [字符串操作 / String Operations]\n");
    char str1[50] = "Hello";
    
    printf("  strlen(\"%s\") = %zu\n", str1, strlen(str1));
    
    char dest[50];
    strcpy(dest, str1);
    printf("  strcpy(dest, \"%s\") -> dest = \"%s\"\n", str1, dest);
    
    strncpy(dest, "Source", 3);
    dest[3] = '\0';
    printf("  strncpy(dest, \"Source\", 3) -> dest = \"%s\" (安全版本/Safer version)\n", dest);
    
    strcpy(dest, "Hello");
    strcat(dest, " World");
    printf("  strcat(\"%s\", \" World\") -> \"%s\"\n", "Hello", dest);
    
    // 字符串比较 / String comparison
    printf("\n  [字符串比较 / String Comparison]\n");
    printf("  strcmp(\"abc\", \"abd\") = %d (< 0 表示前者小/means first is smaller)\n", 
           strcmp("abc", "abd"));
    printf("  strcmp(\"abc\", \"abc\") = %d (= 0 表示相等/means equal)\n", 
           strcmp("abc", "abc"));
    printf("  strncmp(): 比较前n个字符 / Compare first n characters\n");
    
    // 字符串搜索 / String searching
    printf("\n  [字符串搜索 / String Searching]\n");
    char *found = strstr("Hello World", "World");
    if (found) {
        printf("  strstr(\"Hello World\", \"World\") = \"%s\"\n", found);
    }
    
    char *chr = strchr("Hello", 'l');
    if (chr) {
        printf("  strchr(\"Hello\", 'l') = \"%s\" (首次出现/First occurrence)\n", chr);
    }
    
    char *rchr = strrchr("Hello", 'l');
    if (rchr) {
        printf("  strrchr(\"Hello\", 'l') = \"%s\" (最后出现/Last occurrence)\n", rchr);
    }
    
    // 字符串分割 / String tokenizing
    printf("\n  [字符串分割 / String Tokenizing]\n");
    char sentence[] = "Hello,World,C,Language";
    printf("  strtok(\"%s\", \",\"): ", sentence);
    char *token = strtok(sentence, ",");
    while (token != NULL) {
        printf("[%s] ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");
    
    // 内存操作 / Memory operations
    printf("\n  [内存操作 / Memory Operations]\n");
    char mem[20];
    memset(mem, 'A', 10);
    mem[10] = '\0';
    printf("  memset(mem, 'A', 10) -> \"%s\"\n", mem);
    
    char src[] = "Hello";
    char dst[10];
    memcpy(dst, src, 6);
    printf("  memcpy(dst, \"%s\", 6) -> \"%s\"\n", src, dst);
    
    printf("  memmove(): 安全复制重叠区域 / Safe copy for overlapping regions\n");
    printf("  memcmp(): 比较内存区域 / Compare memory regions\n");
    
    // =====================================================================
    // 4. <math.h> - 数学函数 / Math Functions
    // =====================================================================
    printf("\n========================================\n");
    printf("  4. <math.h> - 数学函数 / Math Functions\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 基本数学运算 / Basic math operations\n");
    printf("  - 三角函数 / Trigonometric functions\n");
    printf("  - 指数和对数 / Exponential and logarithmic functions\n");
    printf("  - 取整函数 / Rounding functions\n");
    printf("  ⚠ 编译时需要链接 -lm / Compile with -lm flag\n");
    
    printf("\n主要函数 / Main Functions:\n");
    
    // 基本运算 / Basic operations
    printf("\n  [基本运算 / Basic Operations]\n");
    printf("  sqrt(16.0) = %.2f (平方根/Square root)\n", sqrt(16.0));
    printf("  pow(2.0, 10.0) = %.0f (幂运算/Power)\n", pow(2.0, 10.0));
    printf("  fabs(-3.14) = %.2f (绝对值/Absolute value)\n", fabs(-3.14));
    printf("  fmod(10.5, 3.0) = %.2f (取余/Modulo)\n", fmod(10.5, 3.0));
    
    // 指数和对数 / Exponential and logarithmic
    printf("\n  [指数和对数 / Exponential & Logarithmic]\n");
    printf("  exp(1.0) = %.4f (e^1, 自然指数/Natural exponential)\n", exp(1.0));
    printf("  log(2.718) = %.4f (自然对数/Natural logarithm)\n", log(2.718));
    printf("  log10(100.0) = %.2f (常用对数/Common logarithm)\n", log10(100.0));
    printf("  log2(8.0) = %.2f (以2为底/Base-2 logarithm)\n", log2(8.0));
    
    // 三角函数 / Trigonometric functions
    printf("\n  [三角函数 / Trigonometric Functions]\n");
    // 定义π常量，M_PI需要_GNU_SOURCE或_USE_MATH_DEFINES / Define π constant, M_PI needs _GNU_SOURCE or _USE_MATH_DEFINES
    #ifndef M_PI
    #define M_PI 3.14159265358979323846
    #endif
    double angle = M_PI / 4;  // 45度 / 45 degrees (π/4)
    printf("  sin(π/4) = %.4f\n", sin(angle));
    printf("  cos(π/4) = %.4f\n", cos(angle));
    printf("  tan(π/4) = %.4f\n", tan(angle));
    printf("  asin(0.5) = %.4f 弧度/radians\n", asin(0.5));
    printf("  M_PI = %.10f (π的值/Value of π)\n", M_PI);
    
    // 取整函数 / Rounding functions
    printf("\n  [取整函数 / Rounding Functions]\n");
    printf("  ceil(3.2) = %.1f (向上取整/Ceiling)\n", ceil(3.2));
    printf("  floor(3.8) = %.1f (向下取整/Floor)\n", floor(3.8));
    printf("  round(3.5) = %.1f (四舍五入/Round)\n", round(3.5));
    printf("  trunc(3.9) = %.1f (截断/Truncate)\n", trunc(3.9));
    
    // 双曲函数 / Hyperbolic functions
    printf("\n  [双曲函数 / Hyperbolic Functions]\n");
    printf("  sinh(1.0) = %.4f\n", sinh(1.0));
    printf("  cosh(1.0) = %.4f\n", cosh(1.0));
    printf("  tanh(1.0) = %.4f\n", tanh(1.0));
    
    // =====================================================================
    // 5. <time.h> - 时间日期 / Time and Date
    // =====================================================================
    printf("\n========================================\n");
    printf("  5. <time.h> - 时间日期 / Time and Date\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 获取和操作时间 / Get and manipulate time\n");
    printf("  - 时间格式化 / Time formatting\n");
    printf("  - 计算时间差 / Calculate time differences\n");
    
    printf("\n主要函数和类型 / Main Functions and Types:\n");
    
    // 获取时间 / Getting time
    printf("\n  [获取时间 / Getting Time]\n");
    time_t now = time(NULL);
    printf("  time(NULL) = %ld (Unix时间戳/Unix timestamp)\n", (long)now);
    
    // 时间转换 / Time conversion
    printf("\n  [时间转换 / Time Conversion]\n");
    struct tm *local = localtime(&now);
    printf("  localtime(): 转为本地时间结构 / Convert to local time struct\n");
    printf("    tm_year = %d (年份-1900/Year since 1900)\n", local->tm_year);
    printf("    tm_mon = %d (月份0-11/Month 0-11)\n", local->tm_mon);
    printf("    tm_mday = %d (日期1-31/Day 1-31)\n", local->tm_mday);
    printf("    tm_hour = %d (小时0-23/Hour 0-23)\n", local->tm_hour);
    printf("    tm_min = %d (分钟0-59/Minute 0-59)\n", local->tm_min);
    printf("    tm_sec = %d (秒0-60/Second 0-60)\n", local->tm_sec);
    printf("    tm_wday = %d (星期0-6,0=周日/Weekday, 0=Sunday)\n", local->tm_wday);
    printf("    tm_yday = %d (年中第几天/Day of year)\n", local->tm_yday);
    
    printf("  gmtime(): 转为UTC时间 / Convert to UTC time\n");
    
    // 时间格式化 / Time formatting
    printf("\n  [时间格式化 / Time Formatting]\n");
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", local);
    printf("  strftime(): \"%s\"\n", time_str);
    strftime(time_str, sizeof(time_str), "%A, %B %d, %Y", local);
    printf("  strftime(): \"%s\"\n", time_str);
    printf("  格式说明符 / Format specifiers:\n");
    printf("    %%Y-年份, %%m-月份, %%d-日期, %%H-小时, %%M-分钟, %%S-秒\n");
    printf("    %%A-星期全名, %%B-月份全名, %%p-AM/PM\n");
    
    // 时间计算 / Time calculation
    printf("\n  [时间计算 / Time Calculation]\n");
    clock_t start = clock();
    // 做一些计算 / Do some computation
    volatile long sum = 0;
    for (long i = 0; i < 1000000; i++) {
        sum += i;
    }
    clock_t end = clock();
    double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("  clock(): 测量CPU时间 / Measure CPU time\n");
    printf("    计算耗时/Computation time: %.6f 秒/seconds\n", cpu_time);
    printf("  CLOCKS_PER_SEC = %ld\n", (long)CLOCKS_PER_SEC);
    printf("  difftime(t2, t1): 计算时间差(秒) / Calculate time difference\n");
    
    // =====================================================================
    // 6. <ctype.h> - 字符分类和转换 / Character Classification
    // =====================================================================
    printf("\n========================================\n");
    printf("  6. <ctype.h> - 字符分类和转换 / Character Classification\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 字符类型测试 / Character type testing\n");
    printf("  - 大小写转换 / Case conversion\n");
    
    printf("\n主要函数 / Main Functions:\n");
    
    // 字符测试 / Character testing
    printf("\n  [字符测试 / Character Testing]\n");
    printf("  isalpha('A') = %d (是否字母/Is letter)\n", isalpha('A') ? 1 : 0);
    printf("  isdigit('5') = %d (是否数字/Is digit)\n", isdigit('5') ? 1 : 0);
    printf("  isalnum('A') = %d (是否字母或数字/Is alphanumeric)\n", isalnum('A') ? 1 : 0);
    printf("  isspace(' ') = %d (是否空白/Is whitespace)\n", isspace(' ') ? 1 : 0);
    printf("  isupper('A') = %d (是否大写/Is uppercase)\n", isupper('A') ? 1 : 0);
    printf("  islower('a') = %d (是否小写/Is lowercase)\n", islower('a') ? 1 : 0);
    printf("  ispunct('.') = %d (是否标点/Is punctuation)\n", ispunct('.') ? 1 : 0);
    printf("  isprint('A') = %d (是否可打印/Is printable)\n", isprint('A') ? 1 : 0);
    printf("  iscntrl('\\n') = %d (是否控制字符/Is control char)\n", iscntrl('\n') ? 1 : 0);
    printf("  isxdigit('F') = %d (是否十六进制数字/Is hex digit)\n", isxdigit('F') ? 1 : 0);
    
    // 大小写转换 / Case conversion
    printf("\n  [大小写转换 / Case Conversion]\n");
    printf("  toupper('a') = '%c'\n", toupper('a'));
    printf("  tolower('A') = '%c'\n", tolower('A'));
    
    // =====================================================================
    // 7. <stdint.h> - 固定宽度整数 / Fixed-width Integers
    // =====================================================================
    printf("\n========================================\n");
    printf("  7. <stdint.h> - 固定宽度整数 / Fixed-width Integers\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 提供固定位数的整数类型 / Provides fixed-size integer types\n");
    printf("  - 保证跨平台一致性 / Ensures cross-platform consistency\n");
    
    printf("\n主要类型 / Main Types:\n");
    
    // 精确宽度类型 / Exact-width types
    printf("\n  [精确宽度类型 / Exact-width Types]\n");
    int8_t i8 = INT8_MAX;
    int16_t i16 = INT16_MAX;
    int32_t i32 = INT32_MAX;
    int64_t i64 = INT64_MAX;
    printf("  int8_t:  %d bits, 范围/range: %d to %d\n", 8, INT8_MIN, INT8_MAX);
    printf("  int16_t: %d bits, 范围/range: %d to %d\n", 16, INT16_MIN, INT16_MAX);
    printf("  int32_t: %d bits, 范围/range: %d to %d\n", 32, INT32_MIN, INT32_MAX);
    printf("  int64_t: %d bits\n", 64);
    
    // 无符号类型 / Unsigned types
    printf("\n  [无符号类型 / Unsigned Types]\n");
    printf("  uint8_t:  最大/max: %u\n", UINT8_MAX);
    printf("  uint16_t: 最大/max: %u\n", UINT16_MAX);
    printf("  uint32_t: 最大/max: %u\n", UINT32_MAX);
    printf("  uint64_t: 最大/max: %llu\n", (unsigned long long)UINT64_MAX);
    
    // 最小宽度类型 / Minimum-width types
    printf("\n  [最小宽度类型 / Minimum-width Types]\n");
    printf("  int_least8_t, int_least16_t, int_least32_t, int_least64_t\n");
    printf("  保证至少有指定位数 / Guarantees at least specified bits\n");
    
    // 最快类型 / Fastest types
    printf("\n  [最快类型 / Fastest Types]\n");
    printf("  int_fast8_t, int_fast16_t, int_fast32_t, int_fast64_t\n");
    printf("  在当前平台上最快的类型 / Fastest type on current platform\n");
    
    // 指针大小类型 / Pointer-size types
    printf("\n  [指针大小类型 / Pointer-size Types]\n");
    printf("  intptr_t:  可以存储指针的整数 / Integer that can hold a pointer\n");
    printf("  uintptr_t: 无符号版本 / Unsigned version\n");
    printf("  sizeof(intptr_t) = %zu\n", sizeof(intptr_t));
    
    // 避免警告 / Avoid warnings
    (void)i8; (void)i16; (void)i32; (void)i64;
    
    // =====================================================================
    // 8. <stdbool.h> - 布尔类型 / Boolean Type
    // =====================================================================
    printf("\n========================================\n");
    printf("  8. <stdbool.h> - 布尔类型 / Boolean Type\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - C99引入的布尔类型支持 / Boolean type support from C99\n");
    
    printf("\n主要定义 / Main Definitions:\n");
    printf("  bool:  布尔类型 / Boolean type\n");
    printf("  true:  真值 / True value = %d\n", true);
    printf("  false: 假值 / False value = %d\n", false);
    
    bool flag = true;
    printf("\n  示例/Example: bool flag = true; -> flag = %d\n", flag);
    printf("  sizeof(bool) = %zu\n", sizeof(bool));
    
    // =====================================================================
    // 9. <limits.h> - 整数类型限制 / Integer Type Limits
    // =====================================================================
    printf("\n========================================\n");
    printf("  9. <limits.h> - 整数类型限制 / Integer Limits\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 定义整数类型的限制常量 / Defines limits of integer types\n");
    
    printf("\n主要常量 / Main Constants:\n");
    printf("  CHAR_BIT = %d (char的位数/Bits in char)\n", CHAR_BIT);
    printf("  CHAR_MIN = %d, CHAR_MAX = %d\n", CHAR_MIN, CHAR_MAX);
    printf("  SCHAR_MIN = %d, SCHAR_MAX = %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("  UCHAR_MAX = %d\n", UCHAR_MAX);
    printf("  SHRT_MIN = %d, SHRT_MAX = %d\n", SHRT_MIN, SHRT_MAX);
    printf("  USHRT_MAX = %u\n", USHRT_MAX);
    printf("  INT_MIN = %d, INT_MAX = %d\n", INT_MIN, INT_MAX);
    printf("  UINT_MAX = %u\n", UINT_MAX);
    printf("  LONG_MIN = %ld, LONG_MAX = %ld\n", LONG_MIN, LONG_MAX);
    printf("  ULONG_MAX = %lu\n", ULONG_MAX);
    printf("  LLONG_MIN = %lld\n", LLONG_MIN);
    printf("  LLONG_MAX = %lld\n", LLONG_MAX);
    printf("  ULLONG_MAX = %llu\n", ULLONG_MAX);
    
    // =====================================================================
    // 10. <float.h> - 浮点数限制 / Floating Point Limits
    // =====================================================================
    printf("\n========================================\n");
    printf("  10. <float.h> - 浮点数限制 / Float Limits\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 定义浮点类型的限制常量 / Defines limits of floating types\n");
    
    printf("\n主要常量 / Main Constants:\n");
    printf("  FLT_MIN = %e (float最小正值/Min positive float)\n", FLT_MIN);
    printf("  FLT_MAX = %e (float最大值/Max float)\n", FLT_MAX);
    printf("  FLT_EPSILON = %e (float精度/Float precision)\n", FLT_EPSILON);
    printf("  FLT_DIG = %d (float有效数字/Float decimal digits)\n", FLT_DIG);
    printf("  DBL_MIN = %e (double最小正值/Min positive double)\n", DBL_MIN);
    printf("  DBL_MAX = %e (double最大值/Max double)\n", DBL_MAX);
    printf("  DBL_EPSILON = %e (double精度/Double precision)\n", DBL_EPSILON);
    printf("  DBL_DIG = %d (double有效数字/Double decimal digits)\n", DBL_DIG);
    
    // =====================================================================
    // 11. <assert.h> - 断言 / Assertions
    // =====================================================================
    printf("\n========================================\n");
    printf("  11. <assert.h> - 断言 / Assertions\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 提供调试断言宏 / Provides debugging assertion macro\n");
    printf("  - 用于在开发时检查假设 / Used to verify assumptions during development\n");
    
    printf("\n使用方法 / Usage:\n");
    printf("  assert(expression)\n");
    printf("  - 如果表达式为假，打印错误并终止程序\n");
    printf("  - If expression is false, prints error and terminates\n");
    
    int x = 10;
    assert(x == 10);  // 通过 / Pass
    printf("  assert(x == 10) - 通过/Passed\n");
    // assert(x == 20);  // 会失败 / Would fail
    
    printf("\n  禁用断言 / Disable assertions:\n");
    printf("  在包含assert.h前定义 #define NDEBUG\n");
    printf("  Define #define NDEBUG before including assert.h\n");
    
    // =====================================================================
    // 12. <errno.h> - 错误号 / Error Numbers
    // =====================================================================
    printf("\n========================================\n");
    printf("  12. <errno.h> - 错误号 / Error Numbers\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 提供错误码机制 / Provides error code mechanism\n");
    printf("  - 用于报告库函数错误 / Used to report library function errors\n");
    
    printf("\n主要内容 / Main Contents:\n");
    printf("  errno: 全局错误变量 / Global error variable\n");
    printf("  常见错误码 / Common error codes:\n");
    printf("    EDOM = %d (数学函数域错误/Math domain error)\n", EDOM);
    printf("    ERANGE = %d (结果超出范围/Result out of range)\n", ERANGE);
    printf("    EILSEQ = %d (非法字节序列/Illegal byte sequence)\n", EILSEQ);
    
    // 演示errno使用 / Demonstrate errno usage
    errno = 0;
    double bad_result = log(-1.0);  // 会设置errno为EDOM / Will set errno to EDOM
    if (errno == EDOM) {
        printf("\n  示例/Example: log(-1.0) 设置 errno = EDOM\n");
    } else {
        printf("\n  示例/Example: 数学函数可以设置errno / Math functions can set errno\n");
    }
    printf("  perror(\"msg\"): 打印错误信息 / Print error message\n");
    printf("  strerror(errno): 获取错误描述 / Get error description\n");
    
    // 避免警告 / Avoid warning
    (void)bad_result;
    
    // =====================================================================
    // 13. <stdarg.h> - 可变参数 / Variable Arguments
    // =====================================================================
    printf("\n========================================\n");
    printf("  13. <stdarg.h> - 可变参数 / Variable Arguments\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 支持可变参数函数 / Supports variadic functions\n");
    printf("  - 如printf, scanf等 / Like printf, scanf, etc.\n");
    
    printf("\n主要宏 / Main Macros:\n");
    printf("  va_list:   参数列表类型 / Argument list type\n");
    printf("  va_start(ap, last): 初始化参数列表 / Initialize argument list\n");
    printf("  va_arg(ap, type):   获取下一个参数 / Get next argument\n");
    printf("  va_end(ap):         结束参数访问 / End argument access\n");
    printf("  va_copy(dest, src): 复制参数列表 / Copy argument list\n");
    
    printf("\n  示例/Example:\n");
    my_printf("  my_printf: %s, %d, %.2f\n", "Hello", 42, 3.14);
    
    // =====================================================================
    // 14. <stddef.h> - 标准定义 / Standard Definitions
    // =====================================================================
    printf("\n========================================\n");
    printf("  14. <stddef.h> - 标准定义 / Standard Definitions\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 提供常用类型和宏定义 / Provides common types and macros\n");
    
    printf("\n主要定义 / Main Definitions:\n");
    printf("  NULL: 空指针常量 / Null pointer constant\n");
    printf("  size_t: 无符号大小类型 / Unsigned size type, sizeof(size_t) = %zu\n", sizeof(size_t));
    printf("  ptrdiff_t: 指针差类型 / Pointer difference type\n");
    printf("  offsetof(type, member): 结构体成员偏移量 / Struct member offset\n");
    
    struct Example {
        int a;
        double b;
        char c;
    };
    printf("  示例/Example: offsetof(struct {int a; double b; char c;}, b) = %zu\n", 
           offsetof(struct Example, b));
    
    // =====================================================================
    // 15. <signal.h> - 信号处理 / Signal Handling
    // =====================================================================
    printf("\n========================================\n");
    printf("  15. <signal.h> - 信号处理 / Signal Handling\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 处理异步事件和中断 / Handle async events and interrupts\n");
    
    printf("\n主要内容 / Main Contents:\n");
    printf("  signal(sig, handler): 设置信号处理函数 / Set signal handler\n");
    printf("  raise(sig): 发送信号给自己 / Send signal to self\n");
    
    printf("\n  常见信号 / Common Signals:\n");
    printf("    SIGINT = %d (Ctrl+C中断/Interrupt)\n", SIGINT);
    printf("    SIGTERM = %d (终止请求/Termination request)\n", SIGTERM);
    printf("    SIGSEGV = %d (段错误/Segmentation fault)\n", SIGSEGV);
    printf("    SIGFPE = %d (浮点异常/Floating point exception)\n", SIGFPE);
    printf("    SIGABRT = %d (abort调用/Abort called)\n", SIGABRT);
    
    printf("\n  处理选项 / Handler Options:\n");
    printf("    SIG_DFL: 默认处理 / Default handling\n");
    printf("    SIG_IGN: 忽略信号 / Ignore signal\n");
    
    // =====================================================================
    // 16. <setjmp.h> - 非本地跳转 / Non-local Jumps
    // =====================================================================
    printf("\n========================================\n");
    printf("  16. <setjmp.h> - 非本地跳转 / Non-local Jumps\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 实现跨函数的跳转 / Implements jumps across functions\n");
    printf("  - 类似异常处理机制 / Similar to exception handling\n");
    
    printf("\n主要内容 / Main Contents:\n");
    printf("  jmp_buf: 保存跳转状态的类型 / Type to save jump state\n");
    printf("  setjmp(env): 设置跳转点，返回0 / Set jump point, returns 0\n");
    printf("  longjmp(env, val): 跳转到setjmp点 / Jump to setjmp point\n");
    
    printf("\n  使用场景 / Use Cases:\n");
    printf("  - 错误恢复 / Error recovery\n");
    printf("  - 深层函数调用的快速返回 / Quick return from deep calls\n");
    printf("  ⚠ 慎用：可能导致资源泄漏 / Use carefully: may cause resource leaks\n");
    
    // =====================================================================
    // 17. <locale.h> - 本地化 / Localization
    // =====================================================================
    printf("\n========================================\n");
    printf("  17. <locale.h> - 本地化 / Localization\n");
    printf("========================================\n");
    
    printf("\n功能概述 / Overview:\n");
    printf("  - 支持国际化和本地化 / Supports internationalization\n");
    printf("  - 影响数字、货币、日期格式等 / Affects number, currency, date formats\n");
    
    printf("\n主要内容 / Main Contents:\n");
    printf("  setlocale(category, locale): 设置区域设置 / Set locale\n");
    printf("  localeconv(): 获取数字格式信息 / Get numeric format info\n");
    
    printf("\n  区域类别 / Locale Categories:\n");
    printf("    LC_ALL:      所有类别 / All categories\n");
    printf("    LC_COLLATE:  字符串排序 / String collation\n");
    printf("    LC_CTYPE:    字符分类 / Character classification\n");
    printf("    LC_MONETARY: 货币格式 / Monetary format\n");
    printf("    LC_NUMERIC:  数字格式 / Numeric format\n");
    printf("    LC_TIME:     时间日期格式 / Time/date format\n");
    
    char *current_locale = setlocale(LC_ALL, NULL);
    printf("\n  当前区域设置 / Current locale: %s\n", current_locale ? current_locale : "NULL");
    
    // =====================================================================
    // 总结 / Summary
    // =====================================================================
    printf("\n╔══════════════════════════════════════════════════════════════╗\n");
    printf("║                    总结 / Summary                             ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    
    printf("\n最常用的头文件 / Most Commonly Used Headers:\n");
    printf("┌─────────────────┬────────────────────────────────────────────┐\n");
    printf("│ 头文件/Header   │ 主要用途/Main Purpose                      │\n");
    printf("├─────────────────┼────────────────────────────────────────────┤\n");
    printf("│ <stdio.h>       │ 输入输出/I/O operations                    │\n");
    printf("│ <stdlib.h>      │ 内存管理、类型转换/Memory, conversions     │\n");
    printf("│ <string.h>      │ 字符串操作/String operations               │\n");
    printf("│ <math.h>        │ 数学函数/Math functions (-lm)              │\n");
    printf("│ <time.h>        │ 时间日期/Time and date                     │\n");
    printf("│ <ctype.h>       │ 字符分类/Character classification          │\n");
    printf("│ <stdint.h>      │ 固定宽度整数/Fixed-width integers          │\n");
    printf("│ <stdbool.h>     │ 布尔类型/Boolean type                      │\n");
    printf("│ <limits.h>      │ 整数限制/Integer limits                    │\n");
    printf("│ <errno.h>       │ 错误处理/Error handling                    │\n");
    printf("└─────────────────┴────────────────────────────────────────────┘\n");
    
    printf("\n与Java的对比 / Comparison with Java:\n");
    printf("┌─────────────────────────────────────────────────────────────────┐\n");
    printf("│ C                              │ Java                           │\n");
    printf("├─────────────────────────────────────────────────────────────────┤\n");
    printf("│ #include <stdio.h>             │ System.out (自动导入)           │\n");
    printf("│ #include <string.h>            │ String类方法                   │\n");
    printf("│ #include <math.h>              │ Math类                         │\n");
    printf("│ #include <time.h>              │ java.time包                    │\n");
    printf("│ #include <stdlib.h>            │ 不需要(自动内存管理)            │\n");
    printf("│ #include <stdbool.h>           │ boolean是原始类型               │\n");
    printf("│ 显式包含头文件                  │ 自动导入java.lang              │\n");
    printf("│ 预处理器处理                    │ 编译器处理import               │\n");
    printf("└─────────────────────────────────────────────────────────────────┘\n");
    
    printf("\n学习要点 / Key Points:\n");
    printf("1. 头文件需要用#include包含 / Headers need #include\n");
    printf("2. 系统头文件用<>, 自定义用\"\" / System headers use <>, custom use \"\"\n");
    printf("3. 头文件只包含声明，不包含定义(通常) / Headers contain declarations only\n");
    printf("4. 使用头文件保护防止重复包含 / Use include guards\n");
    printf("5. 了解每个头文件的功能可以提高开发效率 / Know each header's purpose\n");
    
    return 0;
}
