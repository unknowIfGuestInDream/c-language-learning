#include <stdio.h>
#include <limits.h>

/**
 * C语言变量和常量
 * Variables and Constants in C
 * 
 * 本示例演示C语言中的变量声明、初始化和常量的使用
 * This example demonstrates variable declaration, initialization, and constant usage in C
 */

// 全局变量 / Global variable
int global_var = 100;

// 常量定义 / Constant definitions
#define MAX_SIZE 100        // 宏常量 / Macro constant
#define PI 3.14159          // 宏常量 / Macro constant

// const常量 / const constant
const int BUFFER_SIZE = 256;

int main() {
    printf("=== C语言变量和常量 / Variables and Constants in C ===\n\n");
    
    // 1. 变量声明和初始化 / Variable declaration and initialization
    printf("1. 变量声明和初始化 / Variable Declaration and Initialization:\n");
    
    // 声明但未初始化（包含垃圾值）/ Declared but uninitialized (contains garbage)
    // 注意：使用未初始化变量会导致未定义行为，这里仅作演示 / Note: Using uninitialized variables causes undefined behavior, for demo only
    int uninitialized = 0;  // 初始化为0以避免警告 / Initialize to 0 to avoid warning
    printf("  未初始化变量示例 / Uninitialized variable example: %d (已初始化为0 / initialized to 0 for safety)\n", uninitialized);
    printf("  实际使用中，未初始化变量包含垃圾值 / In practice, uninitialized variables contain garbage values\n");
    
    // 声明并初始化 / Declare and initialize
    int initialized = 42;
    printf("  初始化变量 / Initialized variable: %d\n", initialized);
    
    // 多个变量声明 / Multiple variable declaration
    int a = 1, b = 2, c = 3;
    printf("  多个变量 / Multiple variables: a=%d, b=%d, c=%d\n", a, b, c);
    printf("\n");
    
    // 2. 不同数据类型的变量 / Variables of different data types
    printf("2. 不同数据类型的变量 / Variables of Different Data Types:\n");
    
    char ch = 'A';
    short s = 32000;
    int i = 2147483647;
    long l = 9223372036854775807L;
    float f = 3.14f;
    double d = 3.14159265359;
    
    printf("  char: %c\n", ch);
    printf("  short: %d\n", s);
    printf("  int: %d\n", i);
    printf("  long: %ld\n", l);
    printf("  float: %.2f\n", f);
    printf("  double: %.10f\n", d);
    printf("\n");
    
    // 3. 变量修饰符 / Variable modifiers
    printf("3. 变量修饰符 / Variable Modifiers:\n");
    
    // signed和unsigned / signed and unsigned
    signed int si = -100;
    unsigned int ui = 100;
    printf("  signed int: %d\n", si);
    printf("  unsigned int: %u\n", ui);
    
    // short和long / short and long
    short int short_int = 32767;
    long int long_int = 2147483647L;
    long long int llong_int = 9223372036854775807LL;
    printf("  short int: %d\n", short_int);
    printf("  long int: %ld\n", long_int);
    printf("  long long int: %lld\n", llong_int);
    printf("\n");
    
    // 4. 常量 / Constants
    printf("4. 常量 / Constants:\n");
    
    // 使用#define宏 / Using #define macro
    printf("  #define MAX_SIZE = %d\n", MAX_SIZE);
    printf("  #define PI = %.5f\n", PI);
    
    // 使用const关键字 / Using const keyword
    printf("  const BUFFER_SIZE = %d\n", BUFFER_SIZE);
    
    // const变量 / const variable
    const int days_in_week = 7;
    printf("  const days_in_week = %d\n", days_in_week);
    
    // 尝试修改const会导致编译错误 / Attempting to modify const causes compile error
    // days_in_week = 8;  // 错误：不能修改const变量 / Error: cannot modify const
    printf("\n");
    
    // 5. 字面常量 / Literal constants
    printf("5. 字面常量 / Literal Constants:\n");
    
    // 整数字面量 / Integer literals
    int decimal = 100;        // 十进制 / Decimal
    int octal = 0144;         // 八进制（0开头）/ Octal (starts with 0)
    int hex = 0x64;           // 十六进制（0x开头）/ Hexadecimal (starts with 0x)
    printf("  decimal: %d\n", decimal);
    printf("  octal: %d (八进制0144 / octal 0144)\n", octal);
    printf("  hex: %d (十六进制0x64 / hex 0x64)\n", hex);
    
    // 浮点字面量 / Floating-point literals
    float f1 = 3.14f;         // float类型 / float type
    double d1 = 3.14;         // double类型 / double type
    double d2 = 3.14e2;       // 科学计数法 / Scientific notation (314.0)
    printf("  float: %.2f\n", f1);
    printf("  double: %.2f\n", d1);
    printf("  scientific: %.2f\n", d2);
    
    // 字符字面量 / Character literals
    char c1 = 'A';            // 普通字符 / Normal character
    char c3 = 65;             // ASCII码 / ASCII code
    printf("  char 'A': %c\n", c1);
    printf("  char by ASCII 65: %c\n", c3);
    printf("  escape char example: newline='\\n', tab='\\t'\n");
    
    // 字符串字面量 / String literals
    char *str = "Hello, World!";
    printf("  string: %s\n", str);
    printf("\n");
    
    // 6. 类型限定符 / Type qualifiers
    printf("6. 类型限定符 / Type Qualifiers:\n");
    
    // const - 不可修改 / const - cannot be modified
    const int constant = 100;
    printf("  const int: %d (不可修改 / immutable)\n", constant);
    
    // volatile - 可能被外部改变 / volatile - may be changed externally
    volatile int sensor_value = 0;
    printf("  volatile int: %d (可能被硬件改变 / may be changed by hardware)\n", sensor_value);
    
    // restrict - 指针独占访问 / restrict - pointer has exclusive access (C99)
    // int *restrict ptr;
    printf("\n");
    
    // 7. 变量命名规则 / Variable naming rules
    printf("7. 变量命名规则 / Variable Naming Rules:\n");
    printf("  ✓ 必须以字母或下划线开头 / Must start with letter or underscore\n");
    printf("  ✓ 可以包含字母、数字和下划线 / Can contain letters, digits, underscore\n");
    printf("  ✓ 区分大小写 / Case sensitive\n");
    printf("  ✓ 不能使用C关键字 / Cannot use C keywords\n");
    printf("  ✓ 推荐使用有意义的名称 / Use meaningful names\n");
    printf("\n");
    
    // 示例 / Examples
    int age = 25;                    // 好 / Good
    int student_count = 100;         // 好 / Good
    int MAX_VALUE = 1000;            // 常量通常用大写 / Constants usually uppercase
    // int 2fast = 0;                // 错误：以数字开头 / Error: starts with digit
    // int for = 0;                  // 错误：使用关键字 / Error: uses keyword
    printf("  示例 / Examples:\n");
    printf("    int age = %d;\n", age);
    printf("    int student_count = %d;\n", student_count);
    printf("    int MAX_VALUE = %d;\n", MAX_VALUE);
    printf("\n");
    
    // 8. 全局变量vs局部变量 / Global vs Local variables
    printf("8. 全局变量 vs 局部变量 / Global vs Local Variables:\n");
    printf("  全局变量 / Global variable: %d\n", global_var);
    
    int local_var = 200;
    printf("  局部变量 / Local variable: %d\n", local_var);
    
    printf("  全局变量：在函数外声明，整个程序可见 / Global: declared outside functions, visible throughout program\n");
    printf("  局部变量：在函数内声明，仅在函数内可见 / Local: declared inside functions, visible only in function\n");
    printf("\n");
    
    // 9. 常量表达式 / Constant expressions
    printf("9. 常量表达式 / Constant Expressions:\n");
    int array[10];  // 使用字面量而非变量 / Use literal instead of variable for C11 compatibility
    array[0] = 1;   // 使用数组避免警告 / Use array to avoid warning
    printf("  使用常量定义数组大小 / Using constant for array size: int array[10]\n");
    printf("  数组第一个元素 / First element: %d\n", array[0]);
    printf("  注意：C11标准推荐使用宏或枚举定义编译时常量 / Note: C11 recommends macros or enums for compile-time constants\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("变量 / Variables:\n");
    printf("  - 必须先声明后使用 / Must be declared before use\n");
    printf("  - 建议初始化 / Should be initialized\n");
    printf("  - 有类型和作用域 / Have type and scope\n\n");
    
    printf("常量 / Constants:\n");
    printf("  - #define宏：预处理器替换 / #define: preprocessor replacement\n");
    printf("  - const关键字：类型安全 / const keyword: type-safe\n");
    printf("  - 字面量：直接写在代码中 / Literals: written directly in code\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C变量未初始化时包含垃圾值，Java有默认值 / C: garbage values, Java: default values\n");
    printf("  - C有#define和const，Java只有final / C: #define & const, Java: final\n");
    printf("  - C变量可在栈或堆，Java对象只在堆 / C: stack or heap, Java objects: heap only\n");
    
    return 0;
}
