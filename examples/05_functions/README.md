# C语言函数 / C Functions

## 概述 / Overview

本示例演示C语言中的函数定义、参数传递、返回值、递归等重要概念。

This example demonstrates function definitions, parameter passing, return values, recursion, and other important concepts in C.

## 关键概念 / Key Concepts

### 1. 函数声明和定义 / Function Declaration and Definition
- 函数原型（声明）/ Function prototype (declaration)
- 函数实现（定义）/ Function implementation (definition)
- 必须在使用前声明 / Must be declared before use

### 2. 参数传递 / Parameter Passing
- **按值传递**：C的所有参数都按值传递 / **Pass by value**: All C parameters are passed by value
- 要修改参数，传递指针 / To modify parameters, pass pointers
- 数组参数退化为指针 / Array parameters degrade to pointers

### 3. 返回值 / Return Values
- 可以返回任何类型（包括指针）/ Can return any type (including pointers)
- `void`表示无返回值 / `void` means no return value
- 不要返回局部变量的地址 / Don't return addresses of local variables

### 4. 递归 / Recursion
- 函数调用自身 / Function calls itself
- 必须有基本情况（终止条件）/ Must have base case (termination condition)
- 示例：阶乘、斐波那契数列 / Examples: factorial, Fibonacci sequence

### 5. 特殊函数类型 / Special Function Types
- **static函数**：文件作用域，只在当前文件可见 / **static functions**: File scope, only visible in current file
- **inline函数**：建议编译器内联 / **inline functions**: Suggest compiler to inline
- **函数指针**：可以指向函数的指针 / **Function pointers**: Pointers that point to functions

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 函数属于类 / Functions belong to class | ❌ 独立函数 / Independent | ✅ 必须在类中 / Must be in class |
| 函数重载 / Function overloading | ❌ 不支持 / Not supported | ✅ 支持 / Supported |
| 参数传递 / Parameter passing | 按值 / By value | 基本类型按值，对象按引用 / Primitives by value, objects by reference |
| 函数指针 / Function pointers | ✅ 支持 / Supported | ❌ 使用接口 / Use interfaces |
| 递归 / Recursion | ✅ | ✅ |
| inline关键字 / inline keyword | ✅ | ❌ JVM自动优化 / JVM auto-optimizes |

## 编译和运行 / Compilation and Execution

```bash
# 编译（需要链接数学库）/ Compile (requires math library)
make

# 运行 / Run
./functions

# 清理 / Clean
make clean
```

## 示例代码说明 / Code Examples

### 1. 简单函数
```c
void greet(void) {
    printf("Hello, World!\n");
}
```

### 2. 带参数和返回值
```c
int add(int a, int b) {
    return a + b;
}
```

### 3. 指针参数（模拟引用传递）
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

### 4. 递归函数
```c
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

## 学习要点 / Learning Points

1. **C的所有参数都是按值传递**
   **All C parameters are passed by value**
   - Java: 基本类型按值，对象按引用 / Primitives by value, objects by reference

2. **要修改参数值，必须传递指针**
   **To modify parameter values, must pass pointers**
   ```c
   void modify(int *ptr) {
       *ptr = 100;  // 修改指针指向的值 / Modify value pointed to
   }
   ```

3. **C不支持函数重载**
   **C doesn't support function overloading**
   - 不能有同名但参数不同的函数 / Can't have same-named functions with different parameters
   - Java支持函数重载 / Java supports function overloading

4. **数组参数实际上是指针**
   **Array parameters are actually pointers**
   ```c
   void func(int arr[]) {  // 等价于 int *arr / Equivalent to int *arr
       // sizeof(arr)不会返回数组大小 / sizeof(arr) won't return array size
   }
   ```

5. **static函数限制作用域**
   **static functions limit scope**
   - 只在当前文件可见，类似Java的private / Only visible in current file, similar to Java's private

## 常见陷阱 / Common Pitfalls

1. **返回局部变量的地址**
   **Returning address of local variable**
   ```c
   int* bad_function() {
       int x = 10;
       return &x;  // 危险！x在函数结束后被销毁 / Dangerous! x is destroyed after function ends
   }
   ```

2. **忘记函数声明**
   **Forgetting function declaration**
   - 在C中，函数必须在使用前声明 / In C, functions must be declared before use

3. **混淆按值传递和按引用传递**
   **Confusing pass-by-value and pass-by-reference**
   - C只有按值传递，要修改参数需要传指针 / C only has pass-by-value, need pointers to modify

4. **递归没有终止条件**
   **Recursion without termination condition**
   - 导致栈溢出 / Causes stack overflow
