/**
 * C语言内联汇编
 * Inline Assembly in C
 * 
 * 本示例演示GCC内联汇编的基本用法
 * This example demonstrates basic GCC inline assembly usage
 * 
 * 注意：本示例仅适用于x86/x86_64架构和GCC编译器
 * Note: This example only works on x86/x86_64 with GCC compiler
 */

#include <stdio.h>
#include <stdint.h>

// 使用__asm__以确保C11兼容性 / Use __asm__ for C11 compatibility
#define asm __asm__

// 函数声明 / Function declarations
void demonstrate_basic_asm();
void demonstrate_extended_asm();
void demonstrate_input_output();
void demonstrate_constraints();
void demonstrate_practical_examples();

int main() {
    printf("=== C语言内联汇编 / Inline Assembly in C ===\n\n");
    
    // 1. 基本内联汇编 / Basic inline assembly
    printf("1. 基本内联汇编 / Basic Inline Assembly:\n");
    demonstrate_basic_asm();
    
    // 2. 扩展内联汇编 / Extended inline assembly
    printf("2. 扩展内联汇编 / Extended Inline Assembly:\n");
    demonstrate_extended_asm();
    
    // 3. 输入输出操作数 / Input/output operands
    printf("3. 输入输出操作数 / Input/Output Operands:\n");
    demonstrate_input_output();
    
    // 4. 约束说明 / Constraints explanation
    printf("4. 常用约束 / Common Constraints:\n");
    demonstrate_constraints();
    
    // 5. 实用示例 / Practical examples
    printf("5. 实用示例 / Practical Examples:\n");
    demonstrate_practical_examples();
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("内联汇编要点 / Inline Assembly Key Points:\n");
    printf("  - 用于性能关键代码 / Used for performance-critical code\n");
    printf("  - 访问特殊CPU指令 / Access special CPU instructions\n");
    printf("  - 与C变量交互 / Interact with C variables\n");
    printf("  - 注意可移植性问题 / Mind portability issues\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java没有内联汇编 / Java has no inline assembly\n");
    printf("  - Java通过JNI调用本地代码 / Java uses JNI for native code\n");
    printf("  - C的内联汇编更直接高效 / C inline assembly is more direct\n");
    printf("  - Java的JIT会优化字节码 / Java JIT optimizes bytecode\n");
    
    return 0;
}

void demonstrate_basic_asm() {
    printf("  基本语法 / Basic Syntax:\n");
    printf("    asm(\"assembly code\");\n");
    printf("    __asm__(\"assembly code\");  // 等价 / Equivalent\n\n");
    
    // 简单的nop指令 / Simple nop instruction
    printf("  示例：空操作 / Example: No operation\n");
    printf("    asm(\"nop\");\n");
    asm("nop");  // 什么都不做 / Does nothing
    printf("    已执行 / Executed\n\n");
    
    // 多条指令 / Multiple instructions
    printf("  多条指令 / Multiple instructions:\n");
    printf("    asm(\"nop\\n\\t\"\n");
    printf("        \"nop\\n\\t\"\n");
    printf("        \"nop\");\n");
    asm("nop\n\t"
        "nop\n\t"
        "nop");
    printf("    已执行 / Executed\n\n");
}

void demonstrate_extended_asm() {
    printf("  扩展语法 / Extended Syntax:\n");
    printf("    asm [volatile] (\n");
    printf("        \"assembly template\"\n");
    printf("        : output operands     // 输出操作数 / Output operands\n");
    printf("        : input operands      // 输入操作数 / Input operands\n");
    printf("        : clobbered registers // 被修改的寄存器 / Clobbered regs\n");
    printf("    );\n\n");
    
    // 简单示例：将值加1 / Simple example: add 1 to value
    int value = 10;
    printf("  示例：将值加1 / Example: Add 1 to value\n");
    printf("    int value = %d;\n", value);
    
    asm("addl $1, %0"      // 汇编指令 / Assembly instruction
        : "+r" (value)     // 输出：value是读写操作数 / Output: value is read-write
    );
    
    printf("    asm(\"addl $1, %%0\" : \"+r\" (value));\n");
    printf("    结果 / Result: value = %d\n\n", value);
}

void demonstrate_input_output() {
    // 输出操作数 / Output operands
    printf("  输出操作数 / Output Operands:\n");
    printf("    \"=r\" (var) - 只写，寄存器 / Write-only, register\n");
    printf("    \"+r\" (var) - 读写，寄存器 / Read-write, register\n");
    printf("    \"=m\" (var) - 只写，内存 / Write-only, memory\n\n");
    
    // 示例：两数相加 / Example: Add two numbers
    int a = 10, b = 20, result;
    
    printf("  示例：两数相加 / Example: Add two numbers\n");
    printf("    int a = %d, b = %d;\n", a, b);
    
    asm("movl %1, %0\n\t"    // 将a移到result / Move a to result
        "addl %2, %0"        // 将b加到result / Add b to result
        : "=r" (result)      // 输出 / Output
        : "r" (a), "r" (b)   // 输入 / Inputs
    );
    
    printf("    result = %d\n\n", result);
    
    // 输入操作数 / Input operands
    printf("  输入操作数 / Input Operands:\n");
    printf("    \"r\" (var) - 寄存器 / Register\n");
    printf("    \"m\" (var) - 内存 / Memory\n");
    printf("    \"i\" (val) - 立即数 / Immediate\n\n");
    
    // 示例：乘法 / Example: Multiplication
    int x = 5, y = 3, product;
    
    printf("  示例：乘法 / Example: Multiplication\n");
    printf("    int x = %d, y = %d;\n", x, y);
    
    asm("imull %2, %1\n\t"   // 乘法 / Multiply
        "movl %1, %0"        // 移动结果 / Move result
        : "=r" (product)
        : "r" (x), "r" (y)
    );
    
    printf("    product = %d\n\n", product);
}

void demonstrate_constraints() {
    printf("  通用约束 / General Constraints:\n");
    printf("    r - 通用寄存器 / General register\n");
    printf("    m - 内存位置 / Memory location\n");
    printf("    i - 立即整数 / Immediate integer\n");
    printf("    g - 通用（寄存器、内存或立即数）/ General\n\n");
    
    printf("  x86特定约束 / x86-specific Constraints:\n");
    printf("    a - eax/rax寄存器 / eax/rax register\n");
    printf("    b - ebx/rbx寄存器 / ebx/rbx register\n");
    printf("    c - ecx/rcx寄存器 / ecx/rcx register\n");
    printf("    d - edx/rdx寄存器 / edx/rdx register\n");
    printf("    S - esi/rsi寄存器 / esi/rsi register\n");
    printf("    D - edi/rdi寄存器 / edi/rdi register\n\n");
    
    printf("  约束修饰符 / Constraint Modifiers:\n");
    printf("    = - 只写 / Write-only\n");
    printf("    + - 读写 / Read-write\n");
    printf("    & - 早期破坏（输出在输入使用前被修改）\n");
    printf("        Early clobber (output modified before inputs used)\n\n");
    
    printf("  Clobber列表 / Clobber List:\n");
    printf("    \"memory\" - 汇编代码修改内存 / Assembly modifies memory\n");
    printf("    \"cc\"     - 汇编代码修改条件码 / Assembly modifies condition codes\n");
    printf("    \"eax\"    - eax寄存器被修改 / eax register modified\n\n");
}

void demonstrate_practical_examples() {
    // 示例1：获取CPU时间戳 / Example 1: Get CPU timestamp
    printf("  示例1：CPU时间戳 / Example 1: CPU Timestamp\n");
    
    uint32_t lo, hi;
    asm volatile("rdtsc"
        : "=a" (lo), "=d" (hi)
    );
    uint64_t timestamp = ((uint64_t)hi << 32) | lo;
    printf("    CPU时间戳 / CPU timestamp: %lu\n\n", timestamp);
    
    // 示例2：交换两个变量 / Example 2: Swap two variables
    printf("  示例2：交换两个变量 / Example 2: Swap Two Variables\n");
    int p = 100, q = 200;
    printf("    交换前 / Before: p = %d, q = %d\n", p, q);
    
    asm("xchgl %0, %1"
        : "+r" (p), "+r" (q)
    );
    
    printf("    交换后 / After: p = %d, q = %d\n\n", p, q);
    
    // 示例3：计算位数 / Example 3: Count bits
    printf("  示例3：计算前导零 / Example 3: Count Leading Zeros\n");
    uint32_t num = 16;  // 二进制：10000 / Binary: 10000
    uint32_t lz;
    
    asm("bsrl %1, %0\n\t"      // 找最高位1的位置 / Find position of highest 1
        "xorl $31, %0"          // 转换为前导零数量 / Convert to leading zeros
        : "=r" (lz)
        : "r" (num)
    );
    
    printf("    数字 / Number: %u\n", num);
    printf("    前导零 / Leading zeros: %u\n\n", lz);
    
    // 示例4：内存屏障 / Example 4: Memory barrier
    printf("  示例4：内存屏障 / Example 4: Memory Barrier\n");
    printf("    asm volatile(\"\" ::: \"memory\");\n");
    printf("    防止编译器重排内存操作 / Prevents compiler from reordering memory ops\n\n");
    asm volatile("" ::: "memory");
    
    // volatile的作用 / Purpose of volatile
    printf("  volatile关键字 / volatile Keyword:\n");
    printf("    - 防止编译器优化掉汇编代码 / Prevents compiler from optimizing out\n");
    printf("    - 用于有副作用的汇编 / Used for assembly with side effects\n");
    printf("    - 例如：I/O操作、时间戳读取 / E.g., I/O ops, timestamp reads\n\n");
}
