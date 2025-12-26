# C语言结构体 / Structures in C

## 概述 / Overview

本示例演示C语言的结构体（struct），这是C语言中组织复杂数据的主要方式。

This example demonstrates structures (struct) in C, the primary way to organize complex data.

## 关键概念 / Key Concepts

### 结构体定义 / Struct Definition

```c
// 方法1：基本定义 / Method 1: Basic definition
struct Point {
    int x;
    int y;
};

// 方法2：使用typedef / Method 2: Using typedef
typedef struct {
    char name[50];
    int age;
} Person;
```

### 访问成员 / Accessing Members

```c
// 使用 . 访问（对象）/ Use . for objects
Person p;
p.age = 25;

// 使用 -> 访问（指针）/ Use -> for pointers
Person *ptr = &p;
ptr->age = 25;
// 等价于 / Equivalent to
(*ptr).age = 25;
```

## 关键特性 / Key Features

1. **值语义 / Value Semantics**: 结构体可以直接赋值，会复制所有成员
2. **灵活性 / Flexibility**: 可以包含任何类型，包括指针和其他结构体
3. **自引用 / Self-reference**: 可以包含指向自身类型的指针（用于链表、树等）
4. **内存对齐 / Memory Alignment**: 编译器可能添加填充字节以优化访问

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C Struct | Java Class |
|---------------|----------|-----------|
| 方法 / Methods | 无 / No | 有 / Yes |
| 继承 / Inheritance | 无 / No | 有 / Yes |
| 封装 / Encapsulation | 无 / No | 有 / Yes (private/public) |
| 构造函数 / Constructor | 无 / No | 有 / Yes |
| 内存分配 / Allocation | 栈或堆 / Stack or heap | 堆 / Heap only |
| 访问方式 / Access | `.` 或 `->` | `.` only |

**关键区别 / Key Differences:**
- C struct是纯数据容器，Java class是对象（数据+行为）
- C需要手动管理内存，Java有垃圾回收
- C struct可以在栈上，Java对象只能在堆上

## 常见用途 / Common Uses

1. **数据组织 / Data Organization**: 将相关数据组合在一起
2. **链表和树 / Lists and Trees**: 使用自引用结构体
3. **API接口 / API Interfaces**: 定义数据结构
4. **系统编程 / System Programming**: 表示硬件结构

## 编译和运行 / Build and Run

```bash
make
./structs
```
