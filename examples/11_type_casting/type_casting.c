/*
 * C语言类型转换 / C Type Casting
 * 
 * 本示例演示C语言中的类型转换 / This example demonstrates type casting in C
 * 
 * 与Java对比 / Comparison with Java:
 * - C的类型转换更灵活但也更危险 / C's type casting is more flexible but also more dangerous
 * - C可以在任意类型间强制转换 / C allows casting between arbitrary types
 * - Java有更严格的类型检查 / Java has stricter type checking
 */

#include <stdio.h>
#include <stdint.h>

int main() {
    printf("=== C语言类型转换 / C Type Casting ===\n\n");
    
    // 1. 隐式类型转换（自动转换）/ Implicit Type Conversion (Automatic)
    printf("1. 隐式类型转换 / Implicit Conversion:\n");
    int i = 10;
    double d = i;  // int自动转换为double / int automatically converts to double
    printf("  int i = %d -> double d = %.2f\n", i, d);
    
    char c = 'A';
    int ascii = c;  // char自动转换为int / char automatically converts to int
    printf("  char c = '%c' -> int ascii = %d\n", c, ascii);
    
    // 整数提升 / Integer promotion
    char c1 = 100, c2 = 3;
    int result = c1 + c2;  // char提升为int再计算 / char promoted to int before calculation
    printf("  char(100) + char(3) = %d (整数提升 / integer promotion)\n", result);
    printf("\n");
    
    // 2. 显式类型转换（强制转换）/ Explicit Type Conversion (Casting)
    printf("2. 显式类型转换 / Explicit Casting:\n");
    double pi = 3.14159;
    int truncated = (int)pi;  // 截断小数部分 / Truncate decimal part
    printf("  (int)%.5f = %d (截断小数 / truncate decimals)\n", pi, truncated);
    
    int a = 7, b = 3;
    double ratio = (double)a / b;  // 确保浮点除法 / Ensure floating-point division
    printf("  (double)%d / %d = %.2f\n", a, b, ratio);
    
    // 如果不转换 / Without casting
    int int_div = a / b;  // 整数除法 / Integer division
    printf("  %d / %d = %d (整数除法 / integer division)\n", a, b, int_div);
    printf("\n");
    
    // 3. 指针类型转换 / Pointer Type Casting
    printf("3. 指针类型转换 / Pointer Casting:\n");
    int num = 0x12345678;
    int *int_ptr = &num;
    
    // 将int指针转换为char指针（访问单个字节）/ Cast int pointer to char pointer (access individual bytes)
    unsigned char *byte_ptr = (unsigned char *)int_ptr;
    printf("  int value: 0x%08X\n", num);
    printf("  字节表示 / Byte representation: ");
    for (int i = 0; i < (int)sizeof(int); i++) {
        printf("0x%02X ", byte_ptr[i]);
    }
    printf("\n");
    
    // void指针（通用指针）/ void pointer (generic pointer)
    void *generic_ptr = &num;
    int *restored_ptr = (int *)generic_ptr;  // void指针转换回int指针 / Cast void pointer back to int pointer
    printf("  通过void*还原 / Restored through void*: %d\n", *restored_ptr);
    printf("\n");
    
    // 4. 有符号和无符号转换 / Signed and Unsigned Conversion
    printf("4. 有符号/无符号转换 / Signed/Unsigned Conversion:\n");
    int signed_num = -1;
    unsigned int unsigned_num = (unsigned int)signed_num;
    printf("  signed int: %d\n", signed_num);
    printf("  转换为unsigned: %u (二进制相同，解释不同 / same binary, different interpretation)\n", unsigned_num);
    
    unsigned int large = 4294967295U;  // 最大的32位无符号数 / Maximum 32-bit unsigned
    int signed_large = (int)large;
    printf("  unsigned: %u -> signed: %d (溢出 / overflow)\n", large, signed_large);
    printf("\n");
    
    // 5. 指针和整数转换 / Pointer and Integer Conversion
    printf("5. 指针和整数转换 / Pointer-Integer Conversion:\n");
    int value = 42;
    int *ptr = &value;
    
    // 指针转换为整数（地址值）/ Pointer to integer (address value)
    uintptr_t addr = (uintptr_t)ptr;  // 使用uintptr_t确保不丢失精度 / Use uintptr_t to avoid precision loss
    printf("  指针地址 / Pointer address: %p\n", (void*)ptr);
    printf("  转换为整数 / As integer: %lu\n", (unsigned long)addr);
    
    // 整数转换回指针 / Integer back to pointer
    int *restored = (int *)addr;
    printf("  还原指针的值 / Restored pointer value: %d\n", *restored);
    printf("\n");
    
    // 6. 结构体指针转换 / Structure Pointer Casting
    printf("6. 结构体指针转换 / Structure Pointer Casting:\n");
    struct Point {
        int x;
        int y;
    };
    
    struct Point p = {10, 20};
    void *void_ptr = &p;
    struct Point *point_ptr = (struct Point *)void_ptr;
    printf("  Point: (%d, %d)\n", point_ptr->x, point_ptr->y);
    printf("\n");
    
    // 7. 函数指针转换 / Function Pointer Casting
    printf("7. 函数指针转换 / Function Pointer Casting:\n");
    void (*func_ptr)(void) = NULL;
    void *generic_func = (void *)func_ptr;  // 函数指针转void指针 / Function pointer to void pointer
    printf("  函数指针可以转换为void* / Function pointer can be cast to void*\n");
    printf("  (不建议，仅用于特殊场景 / not recommended, only for special cases)\n");
    printf("\n");
    
    printf("学习要点 / Key Points:\n");
    printf("1. 隐式转换是自动的，从小类型到大类型 / Implicit conversion is automatic, from smaller to larger types\n");
    printf("2. 显式转换用括号：(type)value / Explicit conversion uses parentheses: (type)value\n");
    printf("3. 整数除法需要转换至少一个操作数为浮点 / Integer division needs at least one operand cast to float\n");
    printf("4. 指针转换要小心，可能导致未定义行为 / Be careful with pointer casts, may cause undefined behavior\n");
    printf("5. void*是通用指针，可以指向任何类型 / void* is generic pointer, can point to any type\n");
    printf("6. 有符号/无符号转换改变解释但不改变位模式 / Signed/unsigned conversion changes interpretation but not bit pattern\n");
    
    printf("\n与Java对比 / Comparison with Java:\n");
    printf("- C允许任意类型间转换，Java类型转换受限 / C allows arbitrary type casts, Java has restricted casting\n");
    printf("- C可以在指针和整数间转换，Java不允许 / C can cast between pointers and integers, Java doesn't allow\n");
    printf("- Java有instanceof检查，C没有运行时类型检查 / Java has instanceof, C has no runtime type checking\n");
    printf("- C的转换更危险但更灵活 / C's casting is more dangerous but more flexible\n");
    
    return 0;
}
