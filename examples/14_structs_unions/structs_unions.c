#include <stdio.h>
#include <string.h>

/**
 * C语言结构体和共用体
 * Structures and Unions in C
 * 
 * 本示例演示结构体和共用体的区别与使用
 * This example demonstrates the differences and uses of structures and unions
 */

// 1. 基本结构体 / Basic structure
struct Point {
    int x;
    int y;
};

// 2. 共用体 / Union
union Data {
    int i;
    float f;
    char str[20];
};

// 3. 结构体中包含共用体 / Structure containing union
struct Variant {
    enum { INT_TYPE, FLOAT_TYPE, STRING_TYPE } type;
    union {
        int i_val;
        float f_val;
        char s_val[20];
    } value;
};

// 4. 位字段结构体 / Bit field structure
struct Flags {
    unsigned int is_active : 1;    // 1位 / 1 bit
    unsigned int is_visible : 1;   // 1位 / 1 bit
    unsigned int priority : 4;     // 4位 / 4 bits
    unsigned int reserved : 26;    // 26位 / 26 bits
};

int main() {
    printf("=== C语言结构体和共用体 / Structures and Unions in C ===\n\n");
    
    // 1. 结构体基本使用 / Basic structure usage
    printf("1. 结构体 / Structure:\n");
    struct Point p1 = {10, 20};
    printf("  Point: (%d, %d)\n", p1.x, p1.y);
    printf("  sizeof(struct Point) = %zu 字节 / bytes\n", sizeof(struct Point));
    printf("  内存布局 / Memory layout: 每个成员独立存储 / Each member stored separately\n");
    printf("\n");
    
    // 2. 共用体基本使用 / Basic union usage
    printf("2. 共用体 / Union:\n");
    union Data data;
    
    printf("  sizeof(union Data) = %zu 字节 / bytes\n", sizeof(union Data));
    printf("  内存布局 / Memory layout: 所有成员共享同一内存 / All members share same memory\n\n");
    
    // 设置整数值 / Set integer value
    data.i = 10;
    printf("  设置 data.i = 10:\n");
    printf("    data.i = %d\n", data.i);
    printf("    data.f = %f (垃圾值 / garbage)\n", data.f);
    printf("    data.str = \"%s\" (垃圾值 / garbage)\n\n", data.str);
    
    // 设置浮点值（覆盖整数）/ Set float value (overwrites integer)
    data.f = 3.14f;
    printf("  设置 data.f = 3.14:\n");
    printf("    data.i = %d (垃圾值 / garbage)\n", data.i);
    printf("    data.f = %f\n", data.f);
    printf("    data.str = \"%s\" (垃圾值 / garbage)\n\n", data.str);
    
    // 设置字符串（覆盖浮点）/ Set string (overwrites float)
    strcpy(data.str, "Hello");
    printf("  设置 data.str = \"Hello\":\n");
    printf("    data.i = %d (垃圾值 / garbage)\n", data.i);
    printf("    data.f = %f (垃圾值 / garbage)\n", data.f);
    printf("    data.str = \"%s\"\n", data.str);
    printf("\n");
    
    // 3. 结构体vs共用体对比 / Structure vs Union comparison
    printf("3. 结构体 vs 共用体对比 / Structure vs Union Comparison:\n");
    
    struct {
        int i;
        float f;
        char str[20];
    } s_data;
    
    union {
        int i;
        float f;
        char str[20];
    } u_data;
    
    printf("  结构体大小 / Structure size: %zu 字节 / bytes (所有成员之和 / sum of all)\n", sizeof(s_data));
    printf("  共用体大小 / Union size: %zu 字节 / bytes (最大成员 / largest member)\n", sizeof(u_data));
    printf("\n");
    
    // 4. 带类型标记的共用体 / Tagged union (variant)
    printf("4. 带类型标记的变体 / Tagged Union (Variant):\n");
    
    struct Variant var1;
    var1.type = INT_TYPE;
    var1.value.i_val = 42;
    
    printf("  变体1 / Variant 1:\n");
    printf("    类型 / Type: INT\n");
    printf("    值 / Value: %d\n\n", var1.value.i_val);
    
    struct Variant var2;
    var2.type = FLOAT_TYPE;
    var2.value.f_val = 3.14f;
    
    printf("  变体2 / Variant 2:\n");
    printf("    类型 / Type: FLOAT\n");
    printf("    值 / Value: %.2f\n\n", var2.value.f_val);
    
    struct Variant var3;
    var3.type = STRING_TYPE;
    strcpy(var3.value.s_val, "Hello");
    
    printf("  变体3 / Variant 3:\n");
    printf("    类型 / Type: STRING\n");
    printf("    值 / Value: %s\n\n", var3.value.s_val);
    
    // 5. 位字段 / Bit fields
    printf("5. 位字段 / Bit Fields:\n");
    struct Flags flags = {0};
    
    printf("  sizeof(struct Flags) = %zu 字节 / bytes\n", sizeof(struct Flags));
    
    flags.is_active = 1;
    flags.is_visible = 1;
    flags.priority = 7;
    
    printf("  is_active = %u\n", flags.is_active);
    printf("  is_visible = %u\n", flags.is_visible);
    printf("  priority = %u\n", flags.priority);
    printf("\n");
    
    // 6. 共用体的实际应用 / Practical use of unions
    printf("6. 共用体的实际应用：类型转换 / Practical Use: Type Conversion:\n");
    
    union {
        float f;
        unsigned int bits;
    } float_bits;
    
    float_bits.f = 3.14f;
    printf("  float 3.14 的二进制表示 / Binary representation of float 3.14:\n");
    printf("    float 值 / float value: %f\n", float_bits.f);
    printf("    bit 模式 / bit pattern: 0x%08X\n", float_bits.bits);
    printf("\n");
    
    // 7. 匿名联合体（C11） / Anonymous union (C11)
    printf("7. 匿名联合体 / Anonymous Union (C11):\n");
    
    struct Message {
        int type;
        union {  // 匿名联合体 / Anonymous union
            int error_code;
            char *message;
            double value;
        };  // 注意分号 / Note semicolon
    };
    
    struct Message msg;
    msg.type = 1;
    msg.error_code = 404;  // 直接访问，不需要.value / Direct access
    
    printf("  消息类型 / Message type: %d\n", msg.type);
    printf("  错误代码 / Error code: %d\n", msg.error_code);
    printf("\n");
    
    // 8. 内存对齐 / Memory alignment
    printf("8. 内存对齐 / Memory Alignment:\n");
    
    struct Aligned {
        char c;      // 1字节 / 1 byte
        int i;       // 4字节 / 4 bytes
        short s;     // 2字节 / 2 bytes
    };
    
    printf("  struct Aligned {\n");
    printf("    char c;   // 1 byte\n");
    printf("    int i;    // 4 bytes\n");
    printf("    short s;  // 2 bytes\n");
    printf("  }\n");
    printf("  理论大小 / Theoretical size: 1 + 4 + 2 = 7 bytes\n");
    printf("  实际大小 / Actual size: %zu bytes (due to alignment)\n", sizeof(struct Aligned));
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n\n");
    
    printf("结构体 / Structure:\n");
    printf("  - 成员独立存储 / Members stored separately\n");
    printf("  - 大小 = 所有成员之和 + 对齐 / Size = sum of all + alignment\n");
    printf("  - 同时访问所有成员 / Access all members simultaneously\n");
    printf("  - 类似Java的类（但无方法）/ Similar to Java class (no methods)\n\n");
    
    printf("共用体 / Union:\n");
    printf("  - 成员共享内存 / Members share memory\n");
    printf("  - 大小 = 最大成员 + 对齐 / Size = largest member + alignment\n");
    printf("  - 同时只能使用一个成员 / Only one member valid at a time\n");
    printf("  - 节省内存，用于变体类型 / Save memory, for variant types\n\n");
    
    printf("使用场景 / Use Cases:\n");
    printf("  结构体 / Structure:\n");
    printf("    - 组织相关数据 / Organize related data\n");
    printf("    - 所有字段都需要 / All fields needed\n");
    printf("  共用体 / Union:\n");
    printf("    - 节省内存 / Save memory\n");
    printf("    - 变体数据类型 / Variant data types\n");
    printf("    - 类型转换技巧 / Type conversion tricks\n");
    printf("    - 协议解析 / Protocol parsing\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C有结构体和共用体，Java只有类 / C: struct & union, Java: only class\n");
    printf("  - Java没有共用体的概念 / Java: no union concept\n");
    printf("  - C的位字段类似但更底层 / C bit fields: similar but lower level\n");
    
    return 0;
}
