# 值传递 vs 指针传递 / Pass by Value vs Pass by Pointer

## 概述 / Overview

本示例演示C语言的参数传递机制。**重要：C语言只有值传递！**

This example demonstrates parameter passing mechanisms in C. **Important: C only has pass by value!**

## 关键概念 / Key Concepts

### C语言的参数传递 / Parameter Passing in C

C语言**只有值传递**，但可以通过传递指针来实现"引用传递"的效果。

C only has **pass by value**, but can achieve "pass by reference" effect by passing pointers.

### 1. 值传递 / Pass by Value
```c
void modifyValue(int x) {
    x = 100;  // 只修改副本 / Only modifies copy
}

int num = 50;
modifyValue(num);  // num仍然是50 / num is still 50
```

### 2. 指针传递 / Pass by Pointer
```c
void modifyByPointer(int *ptr) {
    *ptr = 200;  // 修改原始值 / Modifies original
}

int num = 50;
modifyByPointer(&num);  // num现在是200 / num is now 200
```

### 3. 数组传递 / Array Passing
数组名就是指针，所以数组总是可以被修改。

Array name is a pointer, so arrays can always be modified.

```c
void modifyArray(int arr[], int size) {
    arr[0] = 999;  // 修改原始数组 / Modifies original array
}
```

## 与Java的对比 / Comparison with Java

| 类型 / Type | C | Java |
|-------------|---|------|
| 基本类型 / Primitives | 值传递 / Pass by value | 值传递 / Pass by value |
| 数组 / Arrays | 指针（可修改）/ Pointer (modifiable) | 引用（可修改）/ Reference (modifiable) |
| 结构体/对象 / Struct/Object | 值传递（需要指针才能修改）/ By value (need pointer to modify) | 引用传递（可修改）/ By reference (modifiable) |

**关键区别 / Key Difference:**
- Java的对象引用本身是值传递，但指向的对象可以修改
- C需要显式使用指针（`*`和`&`）来实现类似效果

## 编译和运行 / Build and Run

```bash
make
./value_vs_reference
```
