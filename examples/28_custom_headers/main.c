/**
 * 自定义头文件示例主程序 / Custom Header Files Example Main Program
 * 
 * 本示例演示如何创建和使用自定义头文件
 * This example demonstrates how to create and use custom header files
 * 
 * 编译方法 / Compilation:
 *   gcc -Wall -Wextra -std=c11 -o custom_headers main.c utils.c string_utils.c
 *   或使用Makefile: make
 */

#include <stdio.h>
#include "utils.h"         // 包含自定义头文件 / Include custom header
#include "string_utils.h"  // 包含另一个自定义头文件 / Include another custom header

// =====================================================================
// 辅助函数 / Helper Functions
// =====================================================================

// 打印分隔线 / Print separator
static void print_section(const char *title) {
    printf("\n");
    printf("========================================\n");
    printf("  %s\n", title);
    printf("========================================\n");
}

// 打印数组 / Print array
static void print_array(const char *label, const int *arr, size_t size) {
    printf("  %s: [", label);
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// =====================================================================
// 主程序 / Main Program
// =====================================================================

int main(void) {
    printf("╔══════════════════════════════════════════════════════════════╗\n");
    printf("║     自定义头文件示例 / Custom Header Files Example           ║\n");
    printf("╚══════════════════════════════════════════════════════════════╝\n");
    
    // =====================================================================
    // 1. utils.h 示例 / utils.h Examples
    // =====================================================================
    print_section("1. utils.h - 通用工具 / General Utilities");
    
    // 版本信息 / Version information
    printf("\n[版本信息 / Version Info]\n");
    printf("  库版本 / Library version: %s\n", utils_get_version());
    printf("  版本宏 / Version macros: %d.%d.%d\n", 
           UTILS_VERSION_MAJOR, UTILS_VERSION_MINOR, UTILS_VERSION_PATCH);
    
    // 常量宏 / Constant macros
    printf("\n[数学常量 / Math Constants]\n");
    printf("  UTILS_PI = %.15f\n", UTILS_PI);
    printf("  UTILS_E  = %.15f\n", UTILS_E);
    
    // 工具宏 / Utility macros
    printf("\n[工具宏 / Utility Macros]\n");
    int a = 10, b = 25;
    printf("  a = %d, b = %d\n", a, b);
    printf("  UTILS_MAX(a, b) = %d\n", UTILS_MAX(a, b));
    printf("  UTILS_MIN(a, b) = %d\n", UTILS_MIN(a, b));
    printf("  UTILS_ABS(-42) = %d\n", UTILS_ABS(-42));
    
    // 数组操作 / Array operations
    printf("\n[数组操作 / Array Operations]\n");
    int numbers[] = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    size_t size = UTILS_ARRAY_LEN(numbers);
    
    printf("  UTILS_ARRAY_LEN宏 / UTILS_ARRAY_LEN macro: 数组长度 / Array length = %zu\n", size);
    print_array("原始数组 / Original", numbers, size);
    
    // 数组统计 / Array statistics
    long sum = utils_array_sum(numbers, size);
    double avg = utils_array_average(numbers, size);
    printf("  utils_array_sum() = %ld\n", sum);
    printf("  utils_array_average() = %.2f\n", avg);
    
    // 最大最小值 / Max and min
    int max_val, min_val;
    utils_status_t status;
    
    status = utils_array_max(numbers, size, &max_val);
    if (status == UTILS_SUCCESS) {
        printf("  utils_array_max() = %d\n", max_val);
    }
    
    status = utils_array_min(numbers, size, &min_val);
    if (status == UTILS_SUCCESS) {
        printf("  utils_array_min() = %d\n", min_val);
    }
    
    // 反转数组 / Reverse array
    int arr_copy[] = {1, 2, 3, 4, 5};
    size_t copy_size = UTILS_ARRAY_LEN(arr_copy);
    print_array("反转前 / Before reverse", arr_copy, copy_size);
    utils_array_reverse(arr_copy, copy_size);
    print_array("反转后 / After reverse", arr_copy, copy_size);
    
    // 类型定义 / Type definitions
    printf("\n[自定义类型 / Custom Types]\n");
    byte_t byte_val = 255;
    uint_t uint_val = 12345;
    printf("  byte_t byte_val = %u\n", byte_val);
    printf("  uint_t uint_val = %u\n", uint_val);
    
    // 状态码 / Status codes
    printf("\n[状态码 / Status Codes]\n");
    printf("  UTILS_SUCCESS: %s\n", utils_status_message(UTILS_SUCCESS));
    printf("  UTILS_ERROR_NULL: %s\n", utils_status_message(UTILS_ERROR_NULL));
    printf("  UTILS_ERROR_RANGE: %s\n", utils_status_message(UTILS_ERROR_RANGE));
    
    // 错误处理示例 / Error handling example
    printf("\n[错误处理示例 / Error Handling Example]\n");
    int result;
    status = utils_array_max(NULL, 5, &result);  // 传入空指针 / Pass null pointer
    printf("  utils_array_max(NULL, ...) 返回 / returned: %s\n", 
           utils_status_message(status));
    
    // 字符串检查 / String check
    printf("\n[字符串检查 / String Check]\n");
    printf("  utils_string_is_empty(NULL) = %s\n", 
           utils_string_is_empty(NULL) ? "true" : "false");
    printf("  utils_string_is_empty(\"\") = %s\n", 
           utils_string_is_empty("") ? "true" : "false");
    printf("  utils_string_is_empty(\"hello\") = %s\n", 
           utils_string_is_empty("hello") ? "true" : "false");
    
    // =====================================================================
    // 2. string_utils.h 示例 / string_utils.h Examples
    // =====================================================================
    print_section("2. string_utils.h - 字符串工具 / String Utilities");
    
    char buffer[STR_BUFFER_SIZE];
    
    // 去除空白 / Trim whitespace
    printf("\n[去除空白 / Trim Whitespace]\n");
    const char *padded = "   Hello World   ";
    printf("  原字符串 / Original: \"%s\"\n", padded);
    str_trim(padded, buffer, sizeof(buffer));
    printf("  str_trim(): \"%s\"\n", buffer);
    
    // 大小写转换 / Case conversion
    printf("\n[大小写转换 / Case Conversion]\n");
    const char *mixed = "Hello World 123";
    printf("  原字符串 / Original: \"%s\"\n", mixed);
    str_to_upper(mixed, buffer, sizeof(buffer));
    printf("  str_to_upper(): \"%s\"\n", buffer);
    str_to_lower(mixed, buffer, sizeof(buffer));
    printf("  str_to_lower(): \"%s\"\n", buffer);
    
    // 前缀后缀检查 / Prefix and suffix check
    printf("\n[前缀后缀检查 / Prefix & Suffix Check]\n");
    const char *filename = "document.txt";
    printf("  字符串 / String: \"%s\"\n", filename);
    printf("  str_starts_with(\"doc\") = %s\n", 
           str_starts_with(filename, "doc") ? "true" : "false");
    printf("  str_starts_with(\"file\") = %s\n", 
           str_starts_with(filename, "file") ? "true" : "false");
    printf("  str_ends_with(\".txt\") = %s\n", 
           str_ends_with(filename, ".txt") ? "true" : "false");
    printf("  str_ends_with(\".pdf\") = %s\n", 
           str_ends_with(filename, ".pdf") ? "true" : "false");
    
    // 字符计数 / Character count
    printf("\n[字符计数 / Character Count]\n");
    const char *text = "Hello, how are you?";
    printf("  字符串 / String: \"%s\"\n", text);
    printf("  str_count_char('o') = %zu\n", str_count_char(text, 'o'));
    printf("  str_count_char('l') = %zu\n", str_count_char(text, 'l'));
    printf("  str_count_char('z') = %zu\n", str_count_char(text, 'z'));
    
    // 字符串反转 / String reverse
    printf("\n[字符串反转 / String Reverse]\n");
    const char *forward = "Hello";
    printf("  原字符串 / Original: \"%s\"\n", forward);
    str_reverse(forward, buffer, sizeof(buffer));
    printf("  str_reverse(): \"%s\"\n", buffer);
    
    // 类型检查 / Type check
    printf("\n[类型检查 / Type Check]\n");
    printf("  str_is_numeric(\"12345\") = %s\n", 
           str_is_numeric("12345") ? "true" : "false");
    printf("  str_is_numeric(\"123abc\") = %s\n", 
           str_is_numeric("123abc") ? "true" : "false");
    printf("  str_is_alpha(\"Hello\") = %s\n", 
           str_is_alpha("Hello") ? "true" : "false");
    printf("  str_is_alpha(\"Hello123\") = %s\n", 
           str_is_alpha("Hello123") ? "true" : "false");
    
    // =====================================================================
    // 3. 总结 / Summary
    // =====================================================================
    print_section("3. 自定义头文件最佳实践 / Custom Header Best Practices");
    
    printf("\n[头文件结构 / Header Structure]\n");
    printf("  1. 头文件保护 (#ifndef/#define/#endif)\n");
    printf("     Include guards to prevent multiple inclusion\n");
    printf("\n");
    printf("  2. 必要的头文件包含\n");
    printf("     Include only necessary headers\n");
    printf("\n");
    printf("  3. 宏定义 (常量、工具宏)\n");
    printf("     Macro definitions (constants, utility macros)\n");
    printf("\n");
    printf("  4. 类型定义 (typedef, enum, struct)\n");
    printf("     Type definitions (typedef, enum, struct)\n");
    printf("\n");
    printf("  5. 函数声明 (只有声明，不包含实现)\n");
    printf("     Function declarations (only declarations, no implementations)\n");
    
    printf("\n[命名约定 / Naming Conventions]\n");
    printf("  - 头文件保护使用大写: FILENAME_H\n");
    printf("  - 宏常量使用大写: PREFIX_NAME\n");
    printf("  - 函数使用前缀: prefix_function_name\n");
    printf("  - 类型使用_t后缀: type_name_t\n");
    
    printf("\n[与Java的对比 / Comparison with Java]\n");
    printf("  ┌───────────────────────┬──────────────────────────┐\n");
    printf("  │ C Header File         │ Java Equivalent          │\n");
    printf("  ├───────────────────────┼──────────────────────────┤\n");
    printf("  │ #include \"utils.h\"    │ import package.Utils;    │\n");
    printf("  │ Include guard         │ Not needed (package)     │\n");
    printf("  │ Function declaration  │ Method signature         │\n");
    printf("  │ .h + .c files         │ Single .java file        │\n");
    printf("  │ Manual linking        │ Auto class loading       │\n");
    printf("  └───────────────────────┴──────────────────────────┘\n");
    
    printf("\n学习要点 / Key Points:\n");
    printf("1. 使用头文件保护防止重复包含\n");
    printf("   Use include guards to prevent multiple inclusion\n");
    printf("2. 头文件只放声明，实现放在.c文件\n");
    printf("   Header: declarations only; .c file: implementations\n");
    printf("3. 使用有意义的前缀避免命名冲突\n");
    printf("   Use meaningful prefixes to avoid naming conflicts\n");
    printf("4. 提供清晰的文档注释\n");
    printf("   Provide clear documentation comments\n");
    printf("5. 设计合理的错误处理机制\n");
    printf("   Design proper error handling mechanisms\n");
    
    return 0;
}
