# C语言数组操作 / Array Operations in C

## 概述 / Overview

本示例演示C语言的数组操作，包括静态数组、动态数组，以及如何实现类似Java ArrayList的功能。

This example demonstrates array operations in C, including static arrays, dynamic arrays, and how to implement Java ArrayList-like functionality.

## 关键概念 / Key Concepts

### 1. 静态数组 / Static Array
```c
int arr[5] = {1, 2, 3, 4, 5};  // 大小固定 / Fixed size
```

### 2. 动态数组 / Dynamic Array
```c
int *arr = (int*)malloc(5 * sizeof(int));  // 动态分配 / Dynamic allocation
arr = (int*)realloc(arr, 10 * sizeof(int));  // 重新分配 / Reallocation
free(arr);  // 释放内存 / Free memory
```

### 3. 自定义ArrayList
模拟Java的ArrayList，支持：
- `add(value)` - 添加元素
- `get(index)` - 获取元素
- `set(index, value)` - 设置元素
- `removeAt(index)` - 删除元素
- `size()` - 获取大小
- `clear()` - 清空

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 静态数组 / Static Array | `int arr[5]` | `int[] arr = new int[5]` |
| 动态数组 / Dynamic Array | `malloc/realloc/free` | `ArrayList<Integer>` |
| 边界检查 / Bounds Checking | 无 / No | 有 / Yes |
| 内存管理 / Memory Management | 手动 / Manual | 自动 / Automatic (GC) |
| 扩容 / Expansion | 手动realloc / Manual realloc | 自动 / Automatic |

**关键区别 / Key Differences:**
- C需要手动管理内存（malloc/free）
- C数组不做边界检查，越界会导致未定义行为
- C需要自己实现动态扩容逻辑
- Java的ArrayList自动管理这些细节

## 编译和运行 / Build and Run

```bash
make
./arrays
```

## 内存管理注意事项 / Memory Management Notes

1. 使用`malloc`分配的内存必须用`free`释放
2. 使用`realloc`重新分配大小
3. 避免内存泄漏和重复释放
4. 数组越界是常见的bug来源
