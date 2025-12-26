# C语言高级指针用法 / Advanced Pointer Usage in C

## 概述 / Overview

本示例演示C语言的高级指针概念，包括多级指针、指针数组与数组指针的区别。

This example demonstrates advanced C pointer concepts including multi-level pointers, pointer arrays vs array pointers.

## 关键概念 / Key Concepts

### 多级指针 / Multi-level Pointers

```c
int num = 42;
int *p1 = &num;      // 一级指针 / Single pointer
int **p2 = &p1;      // 二级指针 / Double pointer
int ***p3 = &p2;     // 三级指针 / Triple pointer

printf("%d\n", ***p3);  // 输出: 42
```

### 指针数组 vs 数组指针 / Pointer Array vs Array Pointer

```c
int *arr[5];    // 指针数组：5个指向int的指针
                // Pointer array: 5 pointers to int

int (*ptr)[5];  // 数组指针：指向含5个int数组的指针
                // Array pointer: pointer to array of 5 ints
```

## 详细对比 / Detailed Comparison

| 特性 / Feature | 指针数组 `int *arr[5]` | 数组指针 `int (*ptr)[5]` |
|---------------|------------------------|-------------------------|
| 大小 / Size | 5 × sizeof(int*) | sizeof(int*) |
| 元素类型 / Element Type | int* | int[5] |
| 常见用途 / Common Use | 字符串数组 | 二维数组遍历 |

## 代码示例 / Code Examples

### 指针数组处理字符串 / Pointer Array for Strings

```c
const char *names[] = {"Alice", "Bob", "Charlie"};

for (int i = 0; i < 3; i++) {
    printf("%s\n", names[i]);
}
```

### 数组指针遍历二维数组 / Array Pointer for 2D Array

```c
int matrix[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
int (*row_ptr)[4] = matrix;

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
        printf("%d ", row_ptr[i][j]);
    }
    printf("\n");
}
```

### 函数指针数组 / Function Pointer Array

```c
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*ops[2])(int, int) = {add, sub};

printf("%d\n", ops[0](10, 5));  // 输出: 15
printf("%d\n", ops[1](10, 5));  // 输出: 5
```

## 复杂声明解读 / Complex Declaration Reading

**规则 / Rules:**
1. 从变量名开始 / Start from variable name
2. 先右后左 / Go right, then left
3. 遇到括号先处理 / Handle parentheses first

**示例 / Examples:**

| 声明 / Declaration | 解读 / Interpretation |
|-------------------|----------------------|
| `int *p` | p是指向int的指针 / p is pointer to int |
| `int *p[10]` | p是10个int指针的数组 / p is array of 10 pointers to int |
| `int (*p)[10]` | p是指向10个int数组的指针 / p is pointer to array of 10 ints |
| `int (*p)(int)` | p是函数指针 / p is pointer to function |

## 与Java的对比 / Comparison with Java

| 概念 / Concept | C | Java |
|---------------|---|------|
| 多级指针 / Multi-level Pointers | `int **pp` | 无直接对应 / No equivalent |
| 指针数组 / Pointer Array | `int *arr[]` | `Object[] arr` |
| 数组指针 / Array Pointer | `int (*p)[]` | 无直接对应 / No equivalent |
| 函数指针 / Function Pointers | `int (*f)(int)` | Lambda, 接口 / Interface |

## 编译和运行 / Build and Run

```bash
make
./advanced_pointers
```
