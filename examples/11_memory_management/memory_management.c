#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * C语言内存管理
 * Memory Management in C
 * 
 * 本示例演示动态内存分配、释放和常见内存问题
 * This example demonstrates dynamic memory allocation, deallocation, and common memory issues
 */

// 演示函数 / Demonstration functions
void demonstrate_malloc();
void demonstrate_calloc();
void demonstrate_realloc();
void demonstrate_memory_leak();
void demonstrate_array_allocation();

int main() {
    printf("=== C语言内存管理 / Memory Management in C ===\n\n");
    
    // 1. 内存布局 / Memory layout
    printf("1. C程序内存布局 / C Program Memory Layout:\n");
    printf("  ┌────────────────┐\n");
    printf("  │ Stack (栈)     │ ← 局部变量、函数参数 / Local variables, parameters\n");
    printf("  │      ↓         │\n");
    printf("  │                │\n");
    printf("  │      ↑         │\n");
    printf("  │ Heap (堆)      │ ← 动态分配 / Dynamic allocation\n");
    printf("  ├────────────────┤\n");
    printf("  │ BSS            │ ← 未初始化全局变量 / Uninitialized globals\n");
    printf("  ├────────────────┤\n");
    printf("  │ Data           │ ← 已初始化全局变量 / Initialized globals\n");
    printf("  ├────────────────┤\n");
    printf("  │ Text (代码)    │ ← 程序代码 / Program code\n");
    printf("  └────────────────┘\n\n");
    
    // 2. malloc - 分配内存 / malloc - allocate memory
    printf("2. malloc() - 分配内存 / Allocate Memory:\n");
    demonstrate_malloc();
    
    // 3. calloc - 分配并清零 / calloc - allocate and zero
    printf("3. calloc() - 分配并清零 / Allocate and Zero:\n");
    demonstrate_calloc();
    
    // 4. realloc - 重新分配 / realloc - reallocate
    printf("4. realloc() - 重新分配 / Reallocate:\n");
    demonstrate_realloc();
    
    // 5. 动态数组 / Dynamic arrays
    printf("5. 动态数组 / Dynamic Arrays:\n");
    demonstrate_array_allocation();
    
    // 6. 内存泄漏 / Memory leak
    printf("6. 内存泄漏示例 / Memory Leak Example:\n");
    printf("  注意：这是演示，实际代码中要避免！/ Note: This is demo, avoid in real code!\n");
    // demonstrate_memory_leak();  // 取消注释会导致内存泄漏 / Uncommenting causes leak
    printf("  内存泄漏：分配内存后未释放 / Memory leak: allocated but not freed\n\n");
    
    // 7. 常见内存错误 / Common memory errors
    printf("7. 常见内存错误 / Common Memory Errors:\n");
    printf("  a) 内存泄漏 / Memory Leak:\n");
    printf("     int *p = malloc(sizeof(int));\n");
    printf("     // 忘记 free(p); / Forgot free(p);\n\n");
    
    printf("  b) 悬空指针 / Dangling Pointer:\n");
    printf("     int *p = malloc(sizeof(int));\n");
    printf("     free(p);\n");
    printf("     *p = 10; // 错误：使用已释放的内存 / Error: using freed memory\n\n");
    
    printf("  c) 重复释放 / Double Free:\n");
    printf("     int *p = malloc(sizeof(int));\n");
    printf("     free(p);\n");
    printf("     free(p); // 错误：重复释放 / Error: double free\n\n");
    
    printf("  d) 越界访问 / Buffer Overflow:\n");
    printf("     int *arr = malloc(5 * sizeof(int));\n");
    printf("     arr[10] = 100; // 错误：越界 / Error: out of bounds\n\n");
    
    // 8. 最佳实践 / Best practices
    printf("8. 内存管理最佳实践 / Memory Management Best Practices:\n");
    printf("  ✓ 每个malloc/calloc必须有对应的free / Every malloc/calloc must have a free\n");
    printf("  ✓ 释放后将指针设为NULL / Set pointer to NULL after free\n");
    printf("  ✓ 检查malloc返回值 / Check malloc return value\n");
    printf("  ✓ 使用valgrind等工具检测泄漏 / Use valgrind to detect leaks\n");
    printf("  ✓ 避免在循环中不必要的分配 / Avoid unnecessary allocation in loops\n\n");
    
    // 9. sizeof运算符 / sizeof operator
    printf("9. sizeof运算符 / sizeof Operator:\n");
    int *int_ptr = malloc(sizeof(int));
    printf("  sizeof(int) = %zu\n", sizeof(int));
    printf("  sizeof(int*) = %zu\n", sizeof(int_ptr));
    printf("  sizeof运算符返回字节数 / sizeof returns number of bytes\n");
    free(int_ptr);
    printf("\n");
    
    // 10. 内存管理函数对比 / Memory function comparison
    printf("10. 内存管理函数对比 / Memory Functions Comparison:\n");
    printf("  ┌──────────┬────────────┬──────────────┬──────────────┐\n");
    printf("  │ 函数     │ 分配       │ 初始化       │ 返回值       │\n");
    printf("  │ Function │ Allocate   │ Initialize   │ Return       │\n");
    printf("  ├──────────┼────────────┼──────────────┼──────────────┤\n");
    printf("  │ malloc   │ 指定字节   │ 不初始化     │ void*        │\n");
    printf("  │          │ bytes      │ no init      │              │\n");
    printf("  ├──────────┼────────────┼──────────────┼──────────────┤\n");
    printf("  │ calloc   │ 元素×大小  │ 清零         │ void*        │\n");
    printf("  │          │ count×size │ zero         │              │\n");
    printf("  ├──────────┼────────────┼──────────────┼──────────────┤\n");
    printf("  │ realloc  │ 重新分配   │ 保留旧数据   │ void*        │\n");
    printf("  │          │ resize     │ keep old     │              │\n");
    printf("  ├──────────┼────────────┼──────────────┼──────────────┤\n");
    printf("  │ free     │ 释放       │ N/A          │ void         │\n");
    printf("  │          │ release    │              │              │\n");
    printf("  └──────────┴────────────┴──────────────┴──────────────┘\n\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("关键点 / Key Points:\n");
    printf("  - C需要手动管理内存 / C requires manual memory management\n");
    printf("  - malloc分配，free释放 / malloc allocates, free releases\n");
    printf("  - 始终检查malloc返回值 / Always check malloc return value\n");
    printf("  - 避免内存泄漏和悬空指针 / Avoid leaks and dangling pointers\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java有垃圾回收器，自动管理内存 / Java: garbage collector, automatic\n");
    printf("  - C需要手动free，Java自动回收 / C: manual free, Java: automatic GC\n");
    printf("  - C更快但易出错，Java更安全但有GC开销 / C: faster but error-prone, Java: safer with GC overhead\n");
    
    return 0;
}

void demonstrate_malloc() {
    // 分配单个整数 / Allocate single integer
    int *num = (int*)malloc(sizeof(int));
    
    if (num == NULL) {
        printf("  内存分配失败！/ Memory allocation failed!\n");
        return;
    }
    
    *num = 42;
    printf("  分配的整数值 / Allocated integer: %d\n", *num);
    printf("  地址 / Address: %p\n", (void*)num);
    
    free(num);  // 释放内存 / Free memory
    num = NULL;  // 避免悬空指针 / Avoid dangling pointer
    printf("  内存已释放 / Memory freed\n\n");
}

void demonstrate_calloc() {
    // 分配5个整数的数组，并清零 / Allocate array of 5 integers, zero-initialized
    int *arr = (int*)calloc(5, sizeof(int));
    
    if (arr == NULL) {
        printf("  内存分配失败！/ Memory allocation failed!\n");
        return;
    }
    
    printf("  calloc分配的数组（已清零）/ calloc array (zero-initialized):\n  ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);  // 应该全是0 / Should all be 0
    }
    printf("\n");
    
    free(arr);
    printf("  内存已释放 / Memory freed\n\n");
}

void demonstrate_realloc() {
    // 初始分配5个整数 / Initially allocate 5 integers
    int *arr = (int*)malloc(5 * sizeof(int));
    
    if (arr == NULL) {
        printf("  内存分配失败！/ Memory allocation failed!\n");
        return;
    }
    
    // 填充数据 / Fill with data
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
    }
    
    printf("  原始数组 / Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // 重新分配为10个整数 / Reallocate to 10 integers
    int *new_arr = (int*)realloc(arr, 10 * sizeof(int));
    
    if (new_arr == NULL) {
        printf("  重新分配失败！/ Reallocation failed!\n");
        free(arr);  // 原内存仍有效 / Original memory still valid
        return;
    }
    
    arr = new_arr;  // 更新指针 / Update pointer
    
    // 填充新元素 / Fill new elements
    for (int i = 5; i < 10; i++) {
        arr[i] = i + 1;
    }
    
    printf("  扩展后数组 / Expanded array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    free(arr);
    printf("  内存已释放 / Memory freed\n\n");
}

void demonstrate_array_allocation() {
    // 2D数组分配 / 2D array allocation
    int rows = 3, cols = 4;
    
    // 分配行指针 / Allocate row pointers
    int **matrix = (int**)malloc(rows * sizeof(int*));
    
    // 分配每一行 / Allocate each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // 填充数据 / Fill with data
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }
    
    // 打印矩阵 / Print matrix
    printf("  动态2D数组 / Dynamic 2D array:\n");
    for (int i = 0; i < rows; i++) {
        printf("  ");
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // 释放内存 / Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("  内存已释放 / Memory freed\n\n");
}

void demonstrate_memory_leak() {
    // 这会导致内存泄漏！/ This causes memory leak!
    for (int i = 0; i < 3; i++) {
        int *leak = (int*)malloc(sizeof(int));
        *leak = i;
        // 忘记free(leak); / Forgot free(leak);
    }
    printf("  内存泄漏：分配了但未释放 / Memory leaked: allocated but not freed\n");
}
