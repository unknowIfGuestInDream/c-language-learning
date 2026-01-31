# C语言结构体和共用体 / Structures and Unions in C

## 概述 / Overview

本示例演示C语言中结构体和共用体的区别与使用。结构体用于组合不同类型的数据，共用体则让多个成员共享同一内存空间。

This example demonstrates the differences and uses of structures and unions in C. Structures combine different data types, while unions let multiple members share the same memory space.

## 关键概念 / Key Concepts

### 1. 结构体 / Structure
- 语法：`struct 名称 { 成员列表 }` / Syntax: `struct name { member_list }`
- 每个成员有独立的内存空间 / Each member has independent memory
- 大小 = 所有成员之和 + 对齐填充 / Size = sum of all members + alignment padding
- 可以同时访问所有成员 / Can access all members simultaneously

### 2. 共用体 / Union
- 语法：`union 名称 { 成员列表 }` / Syntax: `union name { member_list }`
- 所有成员共享同一内存空间 / All members share the same memory
- 大小 = 最大成员的大小 / Size = size of largest member
- 同一时间只有一个成员有效 / Only one member valid at a time

### 3. 带类型标记的变体 / Tagged Union (Variant)
- 结构体中包含枚举类型和共用体 / Structure containing enum type and union
- 枚举标记当前使用的是哪个成员 / Enum tags which member is currently used
- 实现类型安全的变体类型 / Implements type-safe variant type

### 4. 位字段 / Bit Fields
- 在结构体中指定成员的位数 / Specify bit count for members in struct
- 语法：`类型 成员名 : 位数` / Syntax: `type member_name : bits`
- 用于紧凑存储标志位 / Used for compact storage of flags

### 5. 内存对齐 / Memory Alignment
- 编译器可能在成员之间插入填充字节 / Compiler may insert padding between members
- 实际大小可能大于成员大小之和 / Actual size may exceed sum of member sizes
- 对齐提高内存访问效率 / Alignment improves memory access efficiency

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 结构体 / Structure | ✅ struct | ❌ 用class代替 / Use class |
| 共用体 / Union | ✅ union | ❌ 无 / None |
| 位字段 / Bit fields | ✅ 支持 / Supported | ❌ 无 / None |
| 方法 / Methods | ❌ 无 / None | ✅ 有 / Yes |
| 继承 / Inheritance | ❌ 无 / None | ✅ 有 / Yes |
| 内存布局控制 / Memory layout control | ✅ 直接 / Direct | ❌ JVM管理 / JVM managed |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./structs_unions

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **结构体vs共用体**：结构体同时存储，共用体择一存储
   **Struct vs Union**: Struct stores all, union stores one at a time

2. **内存效率**：共用体节省内存，适合变体类型
   **Memory Efficiency**: Union saves memory, good for variant types

3. **类型转换技巧**：共用体可用于查看数据的二进制表示
   **Type Conversion Trick**: Union can view binary representation of data

4. **内存对齐**：理解对齐有助于优化内存使用
   **Memory Alignment**: Understanding alignment helps optimize memory use

## 使用场景 / Use Cases

### 结构体 / Structure
- 组织相关数据（如坐标、日期）/ Organize related data (e.g., coordinates, dates)
- 创建自定义数据类型 / Create custom data types
- 函数参数和返回值的打包 / Package function parameters and return values

### 共用体 / Union
- 节省内存的变体类型 / Memory-saving variant types
- 协议数据包解析 / Protocol packet parsing
- 类型转换和位操作 / Type conversion and bit manipulation
- 实现多态数据结构 / Implementing polymorphic data structures

## 示例代码 / Example Code

### 带类型标记的变体 / Tagged Union
```c
struct Variant {
    enum { INT_TYPE, FLOAT_TYPE, STRING_TYPE } type;
    union {
        int i_val;
        float f_val;
        char s_val[20];
    } value;
};
```

### 位字段 / Bit Fields
```c
struct Flags {
    unsigned int is_active : 1;   // 1位
    unsigned int is_visible : 1;  // 1位
    unsigned int priority : 4;    // 4位
};
```

## 常见陷阱 / Common Pitfalls

1. 访问共用体中未赋值的成员（未定义行为）/ Accessing unassigned union member (undefined behavior)
2. 忽略结构体的内存对齐导致大小计算错误 / Ignoring struct alignment causing size miscalculation
3. 在共用体中存储指针时的内存管理问题 / Memory management issues with pointers in unions
4. 假设位字段的布局是跨平台一致的 / Assuming bit field layout is consistent across platforms
