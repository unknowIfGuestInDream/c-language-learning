/*
 * C语言预处理器 / C Preprocessor
 */

#include <stdio.h>

// 1. 宏定义 / Macro definitions
#define PI 3.14159
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(x) ((x) * (x))
#define DEBUG 1

// 2. 条件编译 / Conditional compilation
#ifdef DEBUG
    #define LOG(msg) printf("[DEBUG] %s\n", msg)
#else
    #define LOG(msg)
#endif

// 3. 字符串化 / Stringification
#define TO_STRING(x) #x
#define PRINT_VAR(var) printf(#var " = %d\n", var)

// 4. 连接 / Concatenation
#define CONCAT(a, b) a##b

// 5. 多行宏 / Multi-line macro
#define SWAP(a, b, type) do { \
    type temp = a; \
    a = b; \
    b = temp; \
} while(0)

int main() {
    printf("=== C语言预处理器 / C Preprocessor ===\n\n");
    
    // 1. 使用宏常量 / Using macro constants
    printf("1. 宏常量 / Macro Constants:\n");
    printf("  PI = %.5f\n", PI);
    double radius = 5.0;
    double area = PI * radius * radius;
    printf("  圆面积 / Circle area (r=%.1f) = %.2f\n", radius, area);
    
    // 2. 使用宏函数 / Using macro functions
    printf("\n2. 宏函数 / Macro Functions:\n");
    printf("  MAX(10, 20) = %d\n", MAX(10, 20));
    printf("  SQUARE(5) = %d\n", SQUARE(5));
    
    // 注意：宏的副作用 / Warning: macro side effects
    int x = 5;
    // int bad = SQUARE(x++);  // 危险！x++会被执行两次 / Dangerous! x++ executed twice
    printf("  注意：SQUARE(x++)会导致x++执行两次！\n");
    
    // 3. 条件编译 / Conditional compilation
    printf("\n3. 条件编译 / Conditional Compilation:\n");
    LOG("这是调试信息 / This is debug info");
    #ifdef DEBUG
        printf("  DEBUG模式已启用 / DEBUG mode enabled\n");
    #endif
    
    // 4. 字符串化 / Stringification
    printf("\n4. 字符串化 / Stringification:\n");
    int value = 100;
    PRINT_VAR(value);
    printf("  TO_STRING(Hello) = \"%s\"\n", TO_STRING(Hello));
    
    // 5. 标记连接 / Token concatenation
    printf("\n5. 标记连接 / Token Concatenation:\n");
    int var1 = 10, var2 = 20;
    printf("  var1 = %d\n", var1);
    printf("  var2 = %d\n", var2);
    int result = CONCAT(var, 1) + CONCAT(var, 2);
    printf("  var1 + var2 = %d\n", result);
    
    // 6. 多行宏 / Multi-line macro
    printf("\n6. 多行宏 / Multi-line Macro:\n");
    int a = 10, b = 20;
    printf("  交换前 / Before SWAP: a=%d, b=%d\n", a, b);
    SWAP(a, b, int);
    printf("  交换后 / After SWAP: a=%d, b=%d\n", a, b);
    
    // 7. 预定义宏 / Predefined macros
    printf("\n7. 预定义宏 / Predefined Macros:\n");
    printf("  文件名 / File: %s\n", __FILE__);
    printf("  行号 / Line: %d\n", __LINE__);
    printf("  日期 / Date: %s\n", __DATE__);
    printf("  时间 / Time: %s\n", __TIME__);
    
    printf("\n学习要点 / Key Points:\n");
    printf("1. #define定义宏常量和宏函数\n");
    printf("2. 宏是文本替换，不进行类型检查\n");
    printf("3. 宏参数要用括号括起来避免优先级问题\n");
    printf("4. #ifdef/#ifndef用于条件编译\n");
    printf("5. #用于字符串化，##用于标记连接\n");
    printf("6. 预定义宏提供编译时信息\n");
    
    return 0;
}
