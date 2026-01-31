#include <stdio.h>
#include <stdint.h>

/**
 * C语言位操作示例
 * Bit Operations in C
 * 
 * 本示例演示C语言的位运算操作
 * This example demonstrates bitwise operations in C
 */

// 打印二进制表示 / Print binary representation
void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0 && i != 0) printf(" ");  // 每4位加空格 / Space every 4 bits
    }
}

// 打印字节的二进制 / Print byte in binary
void printByte(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

int main() {
    printf("=== C语言位操作 / Bit Operations in C ===\n\n");
    
    // 1. 位运算符 / Bitwise Operators
    printf("1. 位运算符 / Bitwise Operators:\n");
    uint8_t a = 60;  // 0011 1100
    uint8_t b = 13;  // 0000 1101
    
    printf("  a = %3d = ", a);
    printByte(a);
    printf("\n");
    printf("  b = %3d = ", b);
    printByte(b);
    printf("\n\n");
    
    // 按位与 / Bitwise AND
    uint8_t and_result = a & b;  // 0000 1100 = 12
    printf("  a & b  = %3d = ", and_result);
    printByte(and_result);
    printf(" (AND: 两位都为1才为1 / both bits must be 1)\n");
    
    // 按位或 / Bitwise OR
    uint8_t or_result = a | b;  // 0011 1101 = 61
    printf("  a | b  = %3d = ", or_result);
    printByte(or_result);
    printf(" (OR: 任一位为1即为1 / either bit is 1)\n");
    
    // 按位异或 / Bitwise XOR
    uint8_t xor_result = a ^ b;  // 0011 0001 = 49
    printf("  a ^ b  = %3d = ", xor_result);
    printByte(xor_result);
    printf(" (XOR: 两位不同为1 / bits are different)\n");
    
    // 按位取反 / Bitwise NOT
    uint8_t not_result = ~a;  // 1100 0011 = 195
    printf("  ~a     = %3d = ", not_result);
    printByte(not_result);
    printf(" (NOT: 位取反 / invert bits)\n");
    printf("\n");
    
    // 2. 左移操作 / Left Shift
    printf("2. 左移操作 / Left Shift (<<):\n");
    uint8_t num = 5;  // 0000 0101
    printf("  原始值 / Original: %d = ", num);
    printByte(num);
    printf("\n");
    
    for (int i = 1; i <= 3; i++) {
        uint8_t shifted = num << i;
        printf("  %d << %d = %3d = ", num, i, shifted);
        printByte(shifted);
        printf(" (相当于乘以 2^%d = %d / equivalent to multiply by 2^%d = %d)\n", 
               i, 1 << i, i, 1 << i);
    }
    printf("\n");
    
    // 3. 右移操作 / Right Shift
    printf("3. 右移操作 / Right Shift (>>):\n");
    num = 40;  // 0010 1000
    printf("  原始值 / Original: %d = ", num);
    printByte(num);
    printf("\n");
    
    for (int i = 1; i <= 3; i++) {
        uint8_t shifted = num >> i;
        printf("  %d >> %d = %3d = ", num, i, shifted);
        printByte(shifted);
        printf(" (相当于除以 2^%d = %d / equivalent to divide by 2^%d = %d)\n", 
               i, 1 << i, i, 1 << i);
    }
    printf("\n");
    
    // 4. 设置特定位 / Set Specific Bit
    printf("4. 设置特定位 / Set Specific Bit:\n");
    uint8_t value = 0;  // 0000 0000
    printf("  原始值 / Original: ");
    printByte(value);
    printf("\n");
    
    // 设置第3位为1 / Set bit 3 to 1
    int bit_pos = 3;
    value = value | (1 << bit_pos);
    printf("  设置第%d位 / Set bit %d: ", bit_pos, bit_pos);
    printByte(value);
    printf(" (使用 | (1 << %d) / using | (1 << %d))\n", bit_pos, bit_pos);
    
    // 设置第5位为1 / Set bit 5 to 1
    bit_pos = 5;
    value = value | (1 << bit_pos);
    printf("  设置第%d位 / Set bit %d: ", bit_pos, bit_pos);
    printByte(value);
    printf("\n\n");
    
    // 5. 清除特定位 / Clear Specific Bit
    printf("5. 清除特定位 / Clear Specific Bit:\n");
    value = 0b10101010;  // 170
    printf("  原始值 / Original: ");
    printByte(value);
    printf(" = %d\n", value);
    
    // 清除第1位 / Clear bit 1
    bit_pos = 1;
    value = value & ~(1 << bit_pos);
    printf("  清除第%d位 / Clear bit %d: ", bit_pos, bit_pos);
    printByte(value);
    printf(" (使用 & ~(1 << %d) / using & ~(1 << %d))\n", bit_pos, bit_pos);
    
    // 清除第3位 / Clear bit 3
    bit_pos = 3;
    value = value & ~(1 << bit_pos);
    printf("  清除第%d位 / Clear bit %d: ", bit_pos, bit_pos);
    printByte(value);
    printf("\n\n");
    
    // 6. 切换特定位 / Toggle Specific Bit
    printf("6. 切换特定位 / Toggle Specific Bit:\n");
    value = 0b10101010;
    printf("  原始值 / Original: ");
    printByte(value);
    printf("\n");
    
    // 切换第1位 / Toggle bit 1
    bit_pos = 1;
    value = value ^ (1 << bit_pos);
    printf("  切换第%d位 / Toggle bit %d: ", bit_pos, bit_pos);
    printByte(value);
    printf(" (使用 ^ (1 << %d) / using ^ (1 << %d))\n", bit_pos, bit_pos);
    
    // 再次切换第1位 / Toggle bit 1 again
    value = value ^ (1 << bit_pos);
    printf("  再次切换第%d位 / Toggle bit %d again: ", bit_pos, bit_pos);
    printByte(value);
    printf("\n\n");
    
    // 7. 检查特定位 / Check Specific Bit
    printf("7. 检查特定位 / Check Specific Bit:\n");
    value = 0b10101010;
    printf("  值 / Value: ");
    printByte(value);
    printf("\n");
    
    for (int i = 0; i < 8; i++) {
        int bit = (value >> i) & 1;
        printf("  第%d位 / Bit %d: %d\n", i, i, bit);
    }
    printf("\n");
    
    // 8. 位掩码 / Bit Masks
    printf("8. 位掩码 / Bit Masks:\n");
    // 权限系统示例 / Permission system example
    #define READ    0b001  // 1
    #define WRITE   0b010  // 2
    #define EXECUTE 0b100  // 4
    
    uint8_t permissions = 0;
    printf("  初始权限 / Initial permissions: ");
    printBinary(permissions, 3);
    printf("\n");
    
    // 添加读权限 / Add read permission
    permissions |= READ;
    printf("  添加读权限 / Add READ: ");
    printBinary(permissions, 3);
    printf(" = %d\n", permissions);
    
    // 添加写权限 / Add write permission
    permissions |= WRITE;
    printf("  添加写权限 / Add WRITE: ");
    printBinary(permissions, 3);
    printf(" = %d\n", permissions);
    
    // 检查是否有写权限 / Check if has write permission
    if (permissions & WRITE) {
        printf("  有写权限 / Has WRITE permission\n");
    }
    
    // 移除写权限 / Remove write permission
    permissions &= ~WRITE;
    printf("  移除写权限 / Remove WRITE: ");
    printBinary(permissions, 3);
    printf(" = %d\n", permissions);
    
    // 检查是否有写权限 / Check if has write permission
    if (!(permissions & WRITE)) {
        printf("  没有写权限 / No WRITE permission\n");
    }
    printf("\n");
    
    // 9. 位域（Bit Fields）/ Bit Fields
    printf("9. 位域 / Bit Fields:\n");
    struct Flags {
        unsigned int flag1 : 1;  // 1位 / 1 bit
        unsigned int flag2 : 1;  // 1位 / 1 bit
        unsigned int flag3 : 1;  // 1位 / 1 bit
        unsigned int value : 5;  // 5位 / 5 bits
    };
    
    struct Flags flags = {0};
    printf("  sizeof(struct Flags) = %zu 字节 / bytes\n", sizeof(struct Flags));
    
    flags.flag1 = 1;
    flags.flag2 = 0;
    flags.flag3 = 1;
    flags.value = 15;
    
    printf("  flag1 = %u\n", flags.flag1);
    printf("  flag2 = %u\n", flags.flag2);
    printf("  flag3 = %u\n", flags.flag3);
    printf("  value = %u\n", flags.value);
    printf("\n");
    
    // 10. 实用示例：交换两个数（不用临时变量）/ Practical: Swap without temp variable
    printf("10. 实用示例：交换两个数 / Practical Example: Swap Numbers:\n");
    int x = 10, y = 20;
    printf("  交换前 / Before: x = %d, y = %d\n", x, y);
    
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    
    printf("  交换后 / After: x = %d, y = %d\n", x, y);
    printf("  方法 / Method: x = x ^ y; y = x ^ y; x = x ^ y;\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("位运算符 / Bitwise Operators:\n");
    printf("  &   - 按位与 / AND\n");
    printf("  |   - 按位或 / OR\n");
    printf("  ^   - 按位异或 / XOR\n");
    printf("  ~   - 按位取反 / NOT\n");
    printf("  <<  - 左移 / Left shift\n");
    printf("  >>  - 右移 / Right shift\n");
    printf("\n");
    printf("常见用途 / Common Uses:\n");
    printf("  1. 权限和标志管理 / Permission and flag management\n");
    printf("  2. 高效的乘除法（2的幂）/ Efficient multiplication/division (powers of 2)\n");
    printf("  3. 位掩码操作 / Bit masking operations\n");
    printf("  4. 底层硬件控制 / Low-level hardware control\n");
    printf("  5. 数据压缩和加密 / Data compression and encryption\n");
    printf("\n");
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - 操作符相同 / Same operators\n");
    printf("  - Java有无符号右移 >>> / Java has unsigned right shift >>>\n");
    printf("  - C的位运算更常用于系统编程 / C bitwise ops more common in systems programming\n");
    
    return 0;
}
