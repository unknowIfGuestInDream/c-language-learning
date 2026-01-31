# C语言函数指针和回调 / Function Pointers and Callbacks in C

## 概述 / Overview

本示例演示C语言中函数指针的声明、使用和回调机制。函数指针是实现回调、策略模式和事件驱动编程的基础。

This example demonstrates function pointer declaration, usage, and callback mechanisms in C. Function pointers are fundamental for implementing callbacks, strategy patterns, and event-driven programming.

## 关键概念 / Key Concepts

### 1. 函数指针基础 / Function Pointer Basics
- 函数指针存储函数的地址 / Function pointers store function addresses
- 声明语法：`返回类型 (*指针名)(参数类型列表)` / Syntax: `return_type (*pointer_name)(param_types)`
- 赋值：`func_ptr = function_name` / Assignment: `func_ptr = function_name`
- 调用：`func_ptr(args)` 或 `(*func_ptr)(args)` / Call: `func_ptr(args)` or `(*func_ptr)(args)`

### 2. typedef简化 / typedef Simplification
- `typedef 返回类型 (*类型名)(参数类型列表)` / `typedef return_type (*TypeName)(param_types)`
- 使函数指针声明更清晰 / Makes function pointer declarations clearer
- 示例：`typedef int (*Operation)(int, int)` / Example: `typedef int (*Operation)(int, int)`

### 3. 回调函数 / Callback Functions
- 将函数作为参数传递给另一个函数 / Pass function as argument to another function
- 被调用的函数在适当时机调用回调 / Called function invokes callback at appropriate time
- 实现灵活、可扩展的代码 / Implements flexible, extensible code

### 4. 函数指针数组 / Array of Function Pointers
- 存储多个函数指针的数组 / Array storing multiple function pointers
- 常用于菜单系统、状态机 / Common for menu systems, state machines
- 通过索引选择并调用函数 / Select and call function by index

### 5. 函数指针与结构体 / Function Pointers with Structures
- 在结构体中包含函数指针成员 / Include function pointer members in structs
- 模拟面向对象的方法 / Simulates object-oriented methods
- 实现接口和多态 / Implements interfaces and polymorphism

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 函数指针 / Function pointers | ✅ 原生支持 / Native | ❌ 无 / None |
| 回调机制 / Callback mechanism | 函数指针 / Function pointers | 接口/Lambda / Interface/Lambda |
| 策略模式 / Strategy pattern | 函数指针 / Function pointers | 接口实现 / Interface implementation |
| 闭包 / Closures | ❌ 无 / None | ✅ Lambda表达式 / Lambda expressions |
| 匿名函数 / Anonymous functions | ❌ 无 / None | ✅ Lambda表达式 / Lambda expressions |
| 类型安全 / Type safety | ⚠️ 较弱 / Weaker | ✅ 强 / Strong |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./function_pointers

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **理解语法**：函数指针声明语法复杂，使用typedef简化
   **Understand Syntax**: Function pointer syntax is complex, use typedef to simplify

2. **回调模式**：核心是"控制反转"，调用者不知道具体实现
   **Callback Pattern**: Core is "inversion of control", caller doesn't know implementation

3. **类型匹配**：函数指针必须与目标函数的签名匹配
   **Type Matching**: Function pointer must match target function's signature

4. **qsort示例**：标准库中函数指针的经典应用
   **qsort Example**: Classic use of function pointers in standard library

## 常见应用场景 / Common Use Cases

### 1. 排序函数 / Sorting Functions
```c
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
qsort(arr, size, sizeof(int), compare);
```

### 2. 回调函数 / Callback Functions
```c
typedef void (*Callback)(int);
void process(int arr[], int size, Callback cb) {
    for (int i = 0; i < size; i++) cb(arr[i]);
}
```

### 3. 策略模式 / Strategy Pattern
```c
typedef int (*Strategy)(int, int);
int execute(int a, int b, Strategy strategy) {
    return strategy(a, b);
}
```

### 4. 菜单系统 / Menu System
```c
void (*menu[])(void) = {option1, option2, option3};
menu[choice]();  // 根据选择调用函数 / Call function based on choice
```

## 常见陷阱 / Common Pitfalls

1. 函数指针类型不匹配导致未定义行为 / Function pointer type mismatch causing undefined behavior
2. 忘记检查函数指针是否为NULL / Forgetting to check if function pointer is NULL
3. 混淆函数调用和函数指针赋值 / Confusing function call with function pointer assignment
4. 复杂的函数指针声明难以理解 / Complex function pointer declarations hard to understand

## 高级技巧 / Advanced Techniques

### 返回函数指针的函数 / Function Returning Function Pointer
```c
typedef int (*Operation)(int, int);
Operation getOperation(char op) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        default: return NULL;
    }
}
```

### 模拟面向对象 / Simulating OOP
```c
typedef struct {
    int (*add)(int, int);
    int (*subtract)(int, int);
} Calculator;

Calculator calc = {add_func, subtract_func};
calc.add(10, 5);  // 像方法调用 / Like method call
```
