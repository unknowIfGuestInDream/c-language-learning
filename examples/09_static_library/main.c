#include <stdio.h>
#include "mathlib.h"

/**
 * 静态库使用示例 / Static Library Usage Example
 * 
 * 本程序演示如何使用静态库
 * This program demonstrates how to use a static library
 */

int main() {
    printf("=== C语言静态库示例 / C Static Library Example ===\n\n");
    
    // 1. 基本算术运算 / Basic arithmetic operations
    printf("1. 基本算术运算 / Basic Arithmetic Operations:\n");
    int a = 15, b = 7;
    
    printf("  %d + %d = %d\n", a, b, add(a, b));
    printf("  %d - %d = %d\n", a, b, subtract(a, b));
    printf("  %d * %d = %d\n", a, b, multiply(a, b));
    
    int remainder;
    int quotient = divide(a, b, &remainder);
    printf("  %d / %d = %d 余 / remainder %d\n", a, b, quotient, remainder);
    printf("\n");
    
    // 2. 阶乘计算 / Factorial calculation
    printf("2. 阶乘计算 / Factorial Calculation:\n");
    for (int i = 0; i <= 10; i++) {
        printf("  %d! = %lld\n", i, factorial(i));
    }
    printf("\n");
    
    // 3. 质数判断 / Prime number check
    printf("3. 质数判断 / Prime Number Check:\n");
    printf("  质数列表 / Prime numbers from 1 to 30:\n  ");
    int count = 0;
    for (int i = 1; i <= 30; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
            if (count % 10 == 0) printf("\n  ");
        }
    }
    printf("\n\n");
    
    // 4. 使用说明 / Usage instructions
    printf("=== 静态库说明 / Static Library Instructions ===\n");
    printf("静态库的创建和使用步骤 / Steps to create and use static library:\n\n");
    
    printf("1. 编译源文件为目标文件 / Compile source to object file:\n");
    printf("   gcc -c mathlib.c -o mathlib.o\n\n");
    
    printf("2. 创建静态库 / Create static library:\n");
    printf("   ar rcs libmathlib.a mathlib.o\n");
    printf("   (ar = archiver, rcs = replace, create, sort)\n\n");
    
    printf("3. 编译主程序并链接静态库 / Compile main program with static library:\n");
    printf("   gcc main.c -L. -lmathlib -o main\n");
    printf("   (-L. = 在当前目录查找库 / look for libraries in current directory)\n");
    printf("   (-lmathlib = 链接libmathlib.a / link with libmathlib.a)\n\n");
    
    printf("或者直接链接 / Or link directly:\n");
    printf("   gcc main.c libmathlib.a -o main\n\n");
    
    printf("静态库特点 / Static Library Characteristics:\n");
    printf("  ✓ 编译时链接到可执行文件 / Linked at compile time\n");
    printf("  ✓ 可执行文件包含库代码 / Executable contains library code\n");
    printf("  ✓ 不需要运行时依赖 / No runtime dependencies\n");
    printf("  ✓ 可执行文件较大 / Larger executable size\n");
    printf("  ✓ 更新库需要重新编译 / Library updates require recompilation\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C静态库类似Java的jar包 / C static libraries similar to Java JAR files\n");
    printf("  - C在编译时链接，Java在运行时加载 / C links at compile time, Java loads at runtime\n");
    printf("  - C的.a文件（Linux）或.lib（Windows）/ C uses .a (Linux) or .lib (Windows)\n");
    printf("  - Java使用.jar文件 / Java uses .jar files\n");
    
    return 0;
}
