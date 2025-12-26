# C语言位域 / Bit Fields in C

## 概述 / Overview

本示例演示C语言结构体中位域的定义和使用。

This example demonstrates bit field definition and usage in C structures.

## 关键概念 / Key Concepts

### 位域定义 / Bit Field Definition

```c
struct Flags {
    unsigned int flag_a : 1;  // 1位 / 1 bit
    unsigned int flag_b : 1;  // 1位 / 1 bit
    unsigned int value  : 4;  // 4位 / 4 bits
    unsigned int code   : 5;  // 5位 / 5 bits
};
```

### 位域特性 / Bit Field Properties

- 宽度指定存储的位数 / Width specifies number of bits
- 可以是 `unsigned int`, `signed int`, 或 `_Bool`
- 无法获取位域的地址 / Cannot take address of bit field
- 访问可能比普通成员慢 / Access may be slower than regular members

## 使用示例 / Usage Examples

### 基本用法 / Basic Usage

```c
struct Flags flags = {0};
flags.flag_a = 1;
flags.value = 9;  // 4位最大值是15 / 4-bit max is 15
```

### RGB颜色存储 / RGB Color Storage

```c
struct RGB565 {
    uint16_t blue  : 5;
    uint16_t green : 6;
    uint16_t red   : 5;
};  // 仅占2字节 / Only 2 bytes
```

### TCP标志位 / TCP Flags

```c
struct TCPFlags {
    uint8_t fin : 1;
    uint8_t syn : 1;
    uint8_t rst : 1;
    uint8_t psh : 1;
    uint8_t ack : 1;
    uint8_t urg : 1;
};
```

## 特殊位域 / Special Bit Fields

### 无名位域（填充）/ Unnamed Bit Fields (Padding)

```c
struct {
    unsigned int flag  : 1;
    unsigned int       : 3;  // 3位填充 / 3-bit padding
    unsigned int value : 4;
};
```

### 零宽度位域 / Zero-width Bit Field

```c
struct {
    unsigned int a : 4;
    unsigned int   : 0;  // 强制对齐 / Force alignment
    unsigned int b : 4;
};
```

## 可移植性问题 / Portability Issues

| 问题 / Issue | 描述 / Description |
|--------------|-------------------|
| 位顺序 | 不同编译器可能不同 / May vary by compiler |
| 存储单元 | 跨边界处理不同 / Cross-boundary handling differs |
| 符号扩展 | signed位域行为不同 / signed bit field behavior varies |

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 位域语法 / Bit Field Syntax | 有 / Yes | 无 / No |
| 紧凑存储 / Compact Storage | 位域 / Bit fields | 位运算 / Bitwise ops |
| 标志集合 / Flag Sets | 位域 / Bit fields | EnumSet |

### Java位运算等价 / Java Bitwise Equivalent

```java
// Java
int flags = 0;
flags |= (1 << 0);  // 设置位0 / Set bit 0
flags |= (9 << 1);  // 设置位1-4 / Set bits 1-4
boolean flag = (flags & 1) != 0;
int value = (flags >> 1) & 0xF;
```

## 编译和运行 / Build and Run

```bash
make
./bit_fields
```

## 最佳实践 / Best Practices

- 对网络/文件格式使用位运算 / Use bitwise ops for network/file formats
- 文档记录位序假设 / Document bit ordering assumptions
- 使用固定宽度类型 / Use fixed-width types
- 仅在单一平台使用位域 / Use bit fields within single platform only
