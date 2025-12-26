# C语言基本类型 / Basic Types in C

## 概述 / Overview

本示例展示C语言的所有基本数据类型，包括整数类型、浮点类型、字符类型和布尔类型。

This example demonstrates all basic data types in C, including integer types, floating-point types, character types, and boolean types.

## 关键概念 / Key Concepts

### 1. 整数类型 / Integer Types
- `char`: 1字节，用于字符和小整数
- `short`: 短整型，至少16位
- `int`: 标准整型，通常32位
- `long`: 长整型，至少32位
- `long long`: 长长整型，至少64位

### 2. 无符号类型 / Unsigned Types
- 使用 `unsigned` 关键字
- 范围从0开始，只能存储非负数
- 范围约为有符号类型的两倍

### 3. 浮点类型 / Floating Point Types
- `float`: 单精度，32位
- `double`: 双精度，64位
- `long double`: 扩展精度

### 4. 固定宽度类型 / Fixed Width Types (C99)
- `int8_t`, `int16_t`, `int32_t`, `int64_t`
- `uint8_t`, `uint16_t`, `uint32_t`, `uint64_t`
- 保证在所有平台上都是相同的大小

## 编译和运行 / Build and Run

```bash
make
./basic_types
```

## 与Java的对比 / Comparison with Java

| C Type | Java Type | Size |
|--------|-----------|------|
| char | byte | 1 byte |
| short | short | 2 bytes |
| int | int | 4 bytes |
| long | long | 8 bytes |
| float | float | 4 bytes |
| double | double | 8 bytes |
| bool (C99) | boolean | 1 byte |

**主要区别 / Key Differences:**
- C的 `char` 可以是有符号或无符号的，Java的 `byte` 总是有符号的
- C的 `char` 是1字节，Java的 `char` 是2字节（Unicode）
- C需要 `#include <stdbool.h>` 才能使用 `bool`
- C的类型大小可能因平台而异（除了固定宽度类型）
