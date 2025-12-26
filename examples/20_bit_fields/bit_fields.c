/**
 * C语言位域
 * Bit Fields in C
 * 
 * 本示例演示C语言结构体中的位域使用
 * This example demonstrates bit fields usage in C structures
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 函数声明 / Function declarations
void demonstrate_basic_bit_fields();
void demonstrate_bit_field_sizes();
void demonstrate_unnamed_bit_fields();
void demonstrate_practical_examples();
void demonstrate_portability_issues();

// 打印字节的二进制表示 / Print binary representation of a byte
void print_binary(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
}

// 打印内存的十六进制 / Print memory in hexadecimal
void print_hex_memory(const void *ptr, size_t size) {
    const uint8_t *bytes = (const uint8_t *)ptr;
    for (size_t i = 0; i < size; i++) {
        printf("%02X ", bytes[i]);
    }
}

int main() {
    printf("=== C语言位域 / Bit Fields in C ===\n\n");
    
    // 1. 位域基础 / Bit field basics
    printf("1. 位域基础 / Bit Field Basics:\n");
    demonstrate_basic_bit_fields();
    
    // 2. 位域大小 / Bit field sizes
    printf("2. 位域大小和对齐 / Bit Field Sizes and Alignment:\n");
    demonstrate_bit_field_sizes();
    
    // 3. 无名位域 / Unnamed bit fields
    printf("3. 无名位域和零宽度位域 / Unnamed and Zero-width Bit Fields:\n");
    demonstrate_unnamed_bit_fields();
    
    // 4. 实际应用 / Practical examples
    printf("4. 实际应用示例 / Practical Examples:\n");
    demonstrate_practical_examples();
    
    // 5. 可移植性 / Portability
    printf("5. 位域的可移植性问题 / Bit Field Portability Issues:\n");
    demonstrate_portability_issues();
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("位域要点 / Bit Field Key Points:\n");
    printf("  - 用于紧凑存储多个小值 / Compact storage for multiple small values\n");
    printf("  - 可以是unsigned int, signed int, 或_Bool / Can be unsigned, signed, or _Bool\n");
    printf("  - 无法获取位域的地址 / Cannot take address of bit field\n");
    printf("  - 实现依赖于编译器和平台 / Implementation-dependent\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java没有位域语法 / Java has no bit field syntax\n");
    printf("  - Java使用位运算实现类似功能 / Java uses bitwise operations\n");
    printf("  - Java有EnumSet用于标志位 / Java has EnumSet for flags\n");
    printf("  - C位域更底层更高效 / C bit fields are lower-level and more efficient\n");
    
    return 0;
}

void demonstrate_basic_bit_fields() {
    printf("  位域定义语法 / Bit field definition syntax:\n");
    printf("    struct {\n");
    printf("        unsigned int field_name : width;\n");
    printf("    };\n\n");
    
    // 基本位域结构 / Basic bit field structure
    struct Flags {
        unsigned int flag_a : 1;  // 1位，值0-1 / 1 bit, values 0-1
        unsigned int flag_b : 1;  // 1位，值0-1 / 1 bit, values 0-1
        unsigned int flag_c : 1;  // 1位，值0-1 / 1 bit, values 0-1
        unsigned int value  : 4;  // 4位，值0-15 / 4 bits, values 0-15
        unsigned int code   : 5;  // 5位，值0-31 / 5 bits, values 0-31
    };
    
    struct Flags flags = {0};
    
    printf("  示例结构体 / Example structure:\n");
    printf("    struct Flags {\n");
    printf("        unsigned int flag_a : 1;  // 1位 / 1 bit\n");
    printf("        unsigned int flag_b : 1;  // 1位 / 1 bit\n");
    printf("        unsigned int flag_c : 1;  // 1位 / 1 bit\n");
    printf("        unsigned int value  : 4;  // 4位 / 4 bits\n");
    printf("        unsigned int code   : 5;  // 5位 / 5 bits\n");
    printf("    };\n\n");
    
    printf("    sizeof(struct Flags) = %zu 字节 / bytes\n\n", sizeof(struct Flags));
    
    // 设置值 / Set values
    flags.flag_a = 1;
    flags.flag_b = 0;
    flags.flag_c = 1;
    flags.value = 9;   // 1001 in binary
    flags.code = 21;   // 10101 in binary
    
    printf("  设置值 / Setting values:\n");
    printf("    flags.flag_a = 1;\n");
    printf("    flags.flag_b = 0;\n");
    printf("    flags.flag_c = 1;\n");
    printf("    flags.value = 9;\n");
    printf("    flags.code = 21;\n\n");
    
    printf("  读取值 / Reading values:\n");
    printf("    flag_a = %u\n", flags.flag_a);
    printf("    flag_b = %u\n", flags.flag_b);
    printf("    flag_c = %u\n", flags.flag_c);
    printf("    value  = %u\n", flags.value);
    printf("    code   = %u\n", flags.code);
    printf("\n");
    
    // 值范围 / Value range
    printf("  值范围测试 / Value range test:\n");
    flags.value = 20;  // 超过4位最大值15 / Exceeds 4-bit max 15
    // 4位掩码 = (1 << 4) - 1 = 0xF = 15 / 4-bit mask = (1 << 4) - 1 = 0xF = 15
    const int four_bit_mask = (1 << 4) - 1;
    printf("    flags.value = 20 后实际值 / After setting to 20: %u\n", flags.value);
    printf("    (20 & 0xF = %d，因为只有4位 / because only 4 bits)\n\n", 20 & four_bit_mask);
}

void demonstrate_bit_field_sizes() {
    // 不同大小的位域 / Different sized bit fields
    struct SizeDemo {
        unsigned int a : 3;   // 0-7
        unsigned int b : 5;   // 0-31
        unsigned int c : 8;   // 0-255
        unsigned int d : 16;  // 0-65535
    };
    
    printf("  不同宽度位域 / Different width bit fields:\n");
    printf("    struct SizeDemo {\n");
    printf("        unsigned int a : 3;   // 可存0-7 / Can store 0-7\n");
    printf("        unsigned int b : 5;   // 可存0-31 / Can store 0-31\n");
    printf("        unsigned int c : 8;   // 可存0-255 / Can store 0-255\n");
    printf("        unsigned int d : 16;  // 可存0-65535 / Can store 0-65535\n");
    printf("    };\n\n");
    printf("    sizeof(struct SizeDemo) = %zu 字节 / bytes\n\n", sizeof(struct SizeDemo));
    
    // 位域对齐 / Bit field alignment
    struct AlignDemo1 {
        unsigned int a : 4;
        unsigned int b : 4;
    };
    
    struct AlignDemo2 {
        unsigned int a : 4;
        unsigned int : 0;  // 强制对齐到下一个存储单元 / Force alignment to next unit
        unsigned int b : 4;
    };
    
    printf("  位域对齐对比 / Bit field alignment comparison:\n");
    printf("    struct AlignDemo1 { a:4; b:4; } = %zu 字节 / bytes\n", sizeof(struct AlignDemo1));
    printf("    struct AlignDemo2 { a:4; :0; b:4; } = %zu 字节 / bytes\n", sizeof(struct AlignDemo2));
    printf("    :0 强制下一个位域从新的存储单元开始\n");
    printf("    :0 forces next bit field to start at new storage unit\n\n");
}

void demonstrate_unnamed_bit_fields() {
    // 无名位域 / Unnamed bit fields
    struct WithPadding {
        unsigned int flag : 1;
        unsigned int      : 3;  // 3位填充 / 3-bit padding
        unsigned int value : 4;
    };
    
    printf("  无名位域（用于填充）/ Unnamed bit fields (for padding):\n");
    printf("    struct WithPadding {\n");
    printf("        unsigned int flag  : 1;\n");
    printf("        unsigned int       : 3;  // 3位填充 / 3-bit padding\n");
    printf("        unsigned int value : 4;\n");
    printf("    };\n\n");
    
    struct WithPadding wp = {0};
    wp.flag = 1;
    wp.value = 15;
    
    printf("    flag = %u, value = %u\n", wp.flag, wp.value);
    printf("    内存布局可能: [flag][pad pad pad][value value value value]\n\n");
    
    // 零宽度位域 / Zero-width bit field
    printf("  零宽度位域 / Zero-width bit field:\n");
    printf("    unsigned int : 0;  // 强制对齐到下一个单元边界\n");
    printf("                       // Forces alignment to next unit boundary\n\n");
}

void demonstrate_practical_examples() {
    // 实例1：RGB颜色 / Example 1: RGB Color
    printf("  实例1：RGB颜色存储 / Example 1: RGB Color Storage:\n");
    
    struct RGB565 {
        uint16_t blue  : 5;
        uint16_t green : 6;
        uint16_t red   : 5;
    };
    
    printf("    struct RGB565 {  // 16位颜色 / 16-bit color\n");
    printf("        uint16_t blue  : 5;  // 32级蓝 / 32 levels of blue\n");
    printf("        uint16_t green : 6;  // 64级绿 / 64 levels of green\n");
    printf("        uint16_t red   : 5;  // 32级红 / 32 levels of red\n");
    printf("    };\n\n");
    
    struct RGB565 color = {0};
    color.red = 31;    // 最大红 / Max red
    color.green = 63;  // 最大绿 / Max green
    color.blue = 31;   // 最大蓝 / Max blue
    
    printf("    白色 / White: R=%u, G=%u, B=%u\n", color.red, color.green, color.blue);
    printf("    sizeof = %zu 字节 / bytes\n\n", sizeof(struct RGB565));
    
    // 实例2：TCP标志位 / Example 2: TCP Flags
    printf("  实例2：TCP标志位 / Example 2: TCP Flags:\n");
    
    struct TCPFlags {
        uint8_t fin : 1;  // 结束连接 / Finish connection
        uint8_t syn : 1;  // 同步序号 / Synchronize sequence numbers
        uint8_t rst : 1;  // 重置连接 / Reset connection
        uint8_t psh : 1;  // 推送数据 / Push data
        uint8_t ack : 1;  // 确认 / Acknowledgment
        uint8_t urg : 1;  // 紧急指针 / Urgent pointer
        uint8_t reserved : 2;  // 保留 / Reserved
    };
    
    printf("    struct TCPFlags {  // TCP头部标志\n");
    printf("        uint8_t fin : 1;  // FIN\n");
    printf("        uint8_t syn : 1;  // SYN\n");
    printf("        uint8_t rst : 1;  // RST\n");
    printf("        uint8_t psh : 1;  // PSH\n");
    printf("        uint8_t ack : 1;  // ACK\n");
    printf("        uint8_t urg : 1;  // URG\n");
    printf("        uint8_t reserved : 2;\n");
    printf("    };\n\n");
    
    struct TCPFlags tcp = {0};
    tcp.syn = 1;
    tcp.ack = 1;
    
    printf("    SYN-ACK包: fin=%u syn=%u rst=%u psh=%u ack=%u urg=%u\n",
           tcp.fin, tcp.syn, tcp.rst, tcp.psh, tcp.ack, tcp.urg);
    printf("    sizeof = %zu 字节 / bytes\n\n", sizeof(struct TCPFlags));
    
    // 实例3：文件权限 / Example 3: File Permissions
    printf("  实例3：文件权限 / Example 3: File Permissions:\n");
    
    struct FilePermissions {
        unsigned int owner_read  : 1;
        unsigned int owner_write : 1;
        unsigned int owner_exec  : 1;
        unsigned int group_read  : 1;
        unsigned int group_write : 1;
        unsigned int group_exec  : 1;
        unsigned int other_read  : 1;
        unsigned int other_write : 1;
        unsigned int other_exec  : 1;
    };
    
    struct FilePermissions perm = {0};
    // 设置 755 权限 / Set 755 permissions
    perm.owner_read = perm.owner_write = perm.owner_exec = 1;  // 7
    perm.group_read = perm.group_exec = 1;  // 5
    perm.other_read = perm.other_exec = 1;  // 5
    
    printf("    755权限: owner=%d%d%d group=%d%d%d other=%d%d%d\n",
           perm.owner_read, perm.owner_write, perm.owner_exec,
           perm.group_read, perm.group_write, perm.group_exec,
           perm.other_read, perm.other_write, perm.other_exec);
    printf("\n");
}

void demonstrate_portability_issues() {
    printf("  位域的可移植性问题 / Portability issues with bit fields:\n\n");
    
    printf("  1. 位顺序 / Bit ordering:\n");
    printf("     不同编译器可能从高位或低位开始分配\n");
    printf("     Different compilers may allocate from MSB or LSB\n\n");
    
    printf("  2. 存储单元大小 / Storage unit size:\n");
    printf("     位域跨越边界的处理方式不同\n");
    printf("     Different handling when bit fields cross boundaries\n\n");
    
    printf("  3. 符号扩展 / Sign extension:\n");
    printf("     signed位域的符号扩展行为可能不同\n");
    printf("     Sign extension behavior may differ for signed bit fields\n\n");
    
    printf("  4. 对齐要求 / Alignment requirements:\n");
    printf("     不同平台有不同的对齐规则\n");
    printf("     Different platforms have different alignment rules\n\n");
    
    printf("  可移植性建议 / Portability recommendations:\n");
    printf("    ✓ 对网络协议或文件格式使用位运算而非位域\n");
    printf("      Use bitwise ops for network/file formats\n");
    printf("    ✓ 只在单一平台内部使用位域\n");
    printf("      Only use bit fields within single platform\n");
    printf("    ✓ 使用固定宽度类型（uint8_t等）\n");
    printf("      Use fixed-width types (uint8_t, etc.)\n");
    printf("    ✓ 文档记录假设的位序\n");
    printf("      Document assumed bit ordering\n\n");
    
    // 演示位域与位运算的等价 / Show bit field vs bitwise equivalent
    printf("  位域与位运算等价示例 / Bit field vs bitwise equivalent:\n\n");
    
    printf("    // 位域方式 / Bit field approach:\n");
    printf("    struct { unsigned int flag:1; unsigned int value:4; } bf;\n");
    printf("    bf.flag = 1; bf.value = 9;\n\n");
    
    printf("    // 位运算方式 / Bitwise approach:\n");
    printf("    uint8_t data = 0;\n");
    printf("    data |= (1 << 0);      // 设置flag / Set flag\n");
    printf("    data |= (9 << 1);      // 设置value / Set value\n");
    printf("    int flag = data & 1;   // 读取flag / Read flag\n");
    printf("    int value = (data >> 1) & 0xF;  // 读取value / Read value\n\n");
}
