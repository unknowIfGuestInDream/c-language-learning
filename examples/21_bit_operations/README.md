# C语言位操作 / Bit Operations in C

## 概述 / Overview

本示例演示C语言的位运算操作，包括左移、右移和各种位操作技巧。

This example demonstrates bitwise operations in C, including left shift, right shift, and various bit manipulation techniques.

## 位运算符 / Bitwise Operators

| 运算符 / Operator | 名称 / Name | 说明 / Description |
|------------------|------------|-------------------|
| `&` | AND / 与 | 两位都为1结果为1 / Both bits must be 1 |
| `\|` | OR / 或 | 任一位为1结果为1 / Either bit is 1 |
| `^` | XOR / 异或 | 两位不同结果为1 / Bits are different |
| `~` | NOT / 非 | 位取反 / Invert bits |
| `<<` | Left Shift / 左移 | 向左移动位 / Shift bits left |
| `>>` | Right Shift / 右移 | 向右移动位 / Shift bits right |

## 常见操作 / Common Operations

### 1. 设置位 / Set Bit
```c
value |= (1 << n);  // 设置第n位为1 / Set bit n to 1
```

### 2. 清除位 / Clear Bit
```c
value &= ~(1 << n);  // 清除第n位 / Clear bit n
```

### 3. 切换位 / Toggle Bit
```c
value ^= (1 << n);  // 切换第n位 / Toggle bit n
```

### 4. 检查位 / Check Bit
```c
int bit = (value >> n) & 1;  // 检查第n位 / Check bit n
```

### 5. 移位乘除 / Shift Multiplication/Division
```c
value << n;  // 乘以 2^n / Multiply by 2^n
value >> n;  // 除以 2^n / Divide by 2^n
```

## 实际应用 / Practical Applications

1. **权限系统 / Permission System**: 使用位掩码表示多个权限
2. **标志位 / Flags**: 在单个整数中存储多个布尔值
3. **高效运算 / Efficient Operations**: 快速乘除2的幂
4. **硬件控制 / Hardware Control**: 设置寄存器位
5. **数据压缩 / Data Compression**: 紧凑存储数据

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 基本运算符 / Basic Ops | `&, |, ^, ~, <<, >>` | `&, |, ^, ~, <<, >>` |
| 无符号右移 / Unsigned Right | `>>` (无符号类型) | `>>>` |
| 位域 / Bit Fields | 支持 / Yes (struct) | 不支持 / No |

**关键区别 / Key Differences:**
- Java有无符号右移运算符`>>>`
- C有位域（bit fields）特性
- C的右移对有符号数是算术右移，对无符号数是逻辑右移

## 编译和运行 / Build and Run

```bash
make
./bit_operations
```

## 性能提示 / Performance Tips

- 移位比乘除法快（编译器通常会自动优化）
- 位运算比逻辑运算快
- 用于底层优化和系统编程
