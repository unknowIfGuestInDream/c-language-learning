# C语言内存管理 / Memory Management in C

## 概述 / Overview

本示例演示C语言中的动态内存分配、释放和常见内存问题。内存管理是C语言编程中最重要的技能之一。

This example demonstrates dynamic memory allocation, deallocation, and common memory issues in C. Memory management is one of the most important skills in C programming.

## 关键概念 / Key Concepts

### 1. 内存布局 / Memory Layout
- **Stack（栈）**：局部变量、函数参数 / Local variables, parameters
- **Heap（堆）**：动态分配的内存 / Dynamically allocated memory
- **BSS**：未初始化的全局变量 / Uninitialized global variables
- **Data**：已初始化的全局变量 / Initialized global variables
- **Text**：程序代码 / Program code

### 2. malloc() - 分配内存 / Allocate Memory
- 语法：`void *malloc(size_t size)` / Syntax: `void *malloc(size_t size)`
- 分配指定字节数的内存 / Allocates specified bytes
- 不初始化内存（内容是垃圾值）/ Does not initialize (content is garbage)
- 返回void*，需要类型转换 / Returns void*, needs type cast

### 3. calloc() - 分配并清零 / Allocate and Zero
- 语法：`void *calloc(size_t count, size_t size)` / Syntax: `void *calloc(size_t count, size_t size)`
- 分配count个大小为size的元素 / Allocates count elements of size
- 初始化所有位为零 / Initializes all bits to zero

### 4. realloc() - 重新分配 / Reallocate
- 语法：`void *realloc(void *ptr, size_t size)` / Syntax: `void *realloc(void *ptr, size_t size)`
- 调整已分配内存的大小 / Resizes allocated memory
- 保留原有数据（在新大小范围内）/ Preserves original data (within new size)

### 5. free() - 释放内存 / Free Memory
- 语法：`void free(void *ptr)` / Syntax: `void free(void *ptr)`
- 释放malloc/calloc/realloc分配的内存 / Frees memory from malloc/calloc/realloc
- 释放后应将指针置NULL / Should set pointer to NULL after freeing

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 内存分配 / Memory allocation | malloc/calloc | new |
| 内存释放 / Memory deallocation | free (手动 / manual) | 自动GC / Automatic GC |
| 内存泄漏风险 / Memory leak risk | ✅ 高 / High | ✅ 较低 / Lower |
| 悬空引用 / Dangling references | ✅ 可能 / Possible | ❌ 不可能 / Impossible |
| 缓冲区溢出 / Buffer overflow | ✅ 可能 / Possible | ❌ 异常保护 / Exception protected |
| 性能控制 / Performance control | ✅ 完全 / Full | ❌ 受GC影响 / GC dependent |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./memory_management

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **配对原则**：每个malloc/calloc必须有对应的free
   **Pairing Principle**: Every malloc/calloc must have a corresponding free

2. **检查返回值**：malloc可能失败返回NULL
   **Check Return Value**: malloc can fail and return NULL

3. **避免悬空指针**：free后立即将指针设为NULL
   **Avoid Dangling Pointers**: Set pointer to NULL immediately after free

4. **使用sizeof**：用sizeof计算大小，不要硬编码
   **Use sizeof**: Calculate size with sizeof, don't hardcode

## 常见内存错误 / Common Memory Errors

### 1. 内存泄漏 / Memory Leak
```c
int *p = malloc(sizeof(int));
// 忘记 free(p); / Forgot free(p);
```

### 2. 悬空指针 / Dangling Pointer
```c
int *p = malloc(sizeof(int));
free(p);
*p = 10; // 错误：使用已释放的内存 / Error: using freed memory
```

### 3. 重复释放 / Double Free
```c
int *p = malloc(sizeof(int));
free(p);
free(p); // 错误：重复释放 / Error: double free
```

### 4. 越界访问 / Buffer Overflow
```c
int *arr = malloc(5 * sizeof(int));
arr[10] = 100; // 错误：越界 / Error: out of bounds
```

## 最佳实践 / Best Practices

1. ✅ 每个malloc/calloc必须有对应的free / Every malloc/calloc must have a free
2. ✅ 释放后将指针设为NULL / Set pointer to NULL after free
3. ✅ 检查malloc返回值是否为NULL / Check if malloc returns NULL
4. ✅ 使用valgrind等工具检测泄漏 / Use valgrind to detect leaks
5. ✅ 避免在循环中不必要的分配 / Avoid unnecessary allocation in loops
6. ✅ 使用sizeof而不是硬编码大小 / Use sizeof instead of hardcoded sizes

## 调试工具 / Debugging Tools

- **Valgrind**：检测内存泄漏和非法访问 / Detect memory leaks and illegal access
- **AddressSanitizer**：编译时检测内存错误 / Compile-time memory error detection
- **GDB**：调试器，可以检查内存状态 / Debugger for examining memory state
