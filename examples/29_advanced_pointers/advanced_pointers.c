/**
 * C语言高级指针用法
 * Advanced Pointer Usage in C
 * 
 * 本示例演示多级指针、指针数组与数组指针的区别和用法
 * This example demonstrates multi-level pointers, pointer arrays vs array pointers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 函数声明 / Function declarations
void demonstrate_multi_level_pointers();
void demonstrate_pointer_array();
void demonstrate_array_pointer();
void demonstrate_pointer_vs_array_comparison();
void demonstrate_function_pointer_array();
void demonstrate_complex_declarations();

// 示例函数用于函数指针数组 / Example functions for function pointer array
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide_safe(int a, int b) { return b != 0 ? a / b : 0; }

int main() {
    printf("=== C语言高级指针用法 / Advanced Pointer Usage in C ===\n\n");
    
    // 1. 多级指针 / Multi-level pointers
    printf("1. 多级指针 / Multi-level Pointers:\n");
    demonstrate_multi_level_pointers();
    
    // 2. 指针数组 / Pointer array
    printf("2. 指针数组 / Pointer Array:\n");
    demonstrate_pointer_array();
    
    // 3. 数组指针 / Array pointer
    printf("3. 数组指针 / Array Pointer:\n");
    demonstrate_array_pointer();
    
    // 4. 对比 / Comparison
    printf("4. 指针数组 vs 数组指针 / Pointer Array vs Array Pointer:\n");
    demonstrate_pointer_vs_array_comparison();
    
    // 5. 函数指针数组 / Function pointer array
    printf("5. 函数指针数组 / Function Pointer Array:\n");
    demonstrate_function_pointer_array();
    
    // 6. 复杂声明解读 / Complex declarations
    printf("6. 复杂声明解读 / Complex Declaration Interpretation:\n");
    demonstrate_complex_declarations();
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("关键区别 / Key Differences:\n");
    printf("  int *arr[5]   - 指针数组：5个指向int的指针\n");
    printf("                  Pointer array: 5 pointers to int\n");
    printf("  int (*ptr)[5] - 数组指针：指向含5个int的数组的指针\n");
    printf("                  Array pointer: pointer to array of 5 ints\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java没有指针，使用引用 / Java has no pointers, uses references\n");
    printf("  - Java的Object[]类似指针数组 / Java Object[] like pointer array\n");
    printf("  - C的多级指针在Java中无直接对应 / C multi-level pointers have no Java equivalent\n");
    printf("  - Java数组是对象，有长度属性 / Java arrays are objects with length\n");
    
    return 0;
}

void demonstrate_multi_level_pointers() {
    printf("  一级指针 / Single pointer:\n");
    int num = 42;
    int *p1 = &num;
    printf("    int num = %d;\n", num);
    printf("    int *p1 = &num;\n");
    printf("    *p1 = %d\n\n", *p1);
    
    printf("  二级指针 / Double pointer:\n");
    int **p2 = &p1;
    printf("    int **p2 = &p1;\n");
    printf("    *p2 = %p (p1的值 / value of p1)\n", (void*)*p2);
    printf("    **p2 = %d (num的值 / value of num)\n\n", **p2);
    
    printf("  三级指针 / Triple pointer:\n");
    int ***p3 = &p2;
    printf("    int ***p3 = &p2;\n");
    printf("    ***p3 = %d (num的值 / value of num)\n\n", ***p3);
    
    printf("  地址关系图 / Address relationship:\n");
    printf("    ┌─────────┐     ┌─────────┐     ┌─────────┐     ┌─────────┐\n");
    printf("    │   p3    │ --> │   p2    │ --> │   p1    │ --> │   num   │\n");
    printf("    │ %p │     │ %p │     │ %p │     │   42    │\n", 
           (void*)p3, (void*)p2, (void*)p1);
    printf("    └─────────┘     └─────────┘     └─────────┘     └─────────┘\n\n");
    
    // 二级指针的实际应用 / Practical use of double pointer
    printf("  二级指针的实际应用 / Practical use of double pointer:\n");
    printf("    - 动态分配二维数组 / Dynamically allocate 2D array\n");
    printf("    - 函数中修改指针本身 / Modify pointer itself in function\n");
    printf("    - main函数的argv参数 / argv parameter in main\n\n");
}

void demonstrate_pointer_array() {
    printf("  指针数组定义 / Pointer array definition:\n");
    printf("    int *arr[5];  // 5个指向int的指针 / 5 pointers to int\n\n");
    
    // 整数指针数组 / Integer pointer array
    int a = 10, b = 20, c = 30;
    int *int_arr[3] = {&a, &b, &c};
    
    printf("  整数指针数组示例 / Integer pointer array example:\n");
    printf("    int a = 10, b = 20, c = 30;\n");
    printf("    int *int_arr[3] = {&a, &b, &c};\n\n");
    
    for (int i = 0; i < 3; i++) {
        printf("    int_arr[%d] = %p, *int_arr[%d] = %d\n", 
               i, (void*)int_arr[i], i, *int_arr[i]);
    }
    printf("\n");
    
    // 字符串数组（指针数组的常见用法）/ String array (common use of pointer array)
    printf("  字符串数组（最常见用法）/ String array (most common use):\n");
    const char *names[] = {"Alice", "Bob", "Charlie"};
    
    printf("    const char *names[] = {\"Alice\", \"Bob\", \"Charlie\"};\n\n");
    
    for (int i = 0; i < 3; i++) {
        printf("    names[%d] = \"%s\"\n", i, names[i]);
    }
    printf("\n");
    
    printf("  内存布局 / Memory layout:\n");
    printf("    ┌───────────┐     ┌───────────────┐\n");
    printf("    │ names[0]  │ --> │ \"Alice\"       │\n");
    printf("    ├───────────┤     ├───────────────┤\n");
    printf("    │ names[1]  │ --> │ \"Bob\"         │\n");
    printf("    ├───────────┤     ├───────────────┤\n");
    printf("    │ names[2]  │ --> │ \"Charlie\"     │\n");
    printf("    └───────────┘     └───────────────┘\n");
    printf("    指针数组           字符串常量\n");
    printf("    Pointer array     String literals\n\n");
}

void demonstrate_array_pointer() {
    printf("  数组指针定义 / Array pointer definition:\n");
    printf("    int (*ptr)[5];  // 指向含5个int的数组 / pointer to array of 5 ints\n\n");
    
    // 一维数组示例 / 1D array example
    int arr[5] = {1, 2, 3, 4, 5};
    int (*ptr)[5] = &arr;  // 注意：取整个数组的地址 / Note: address of entire array
    
    printf("  数组指针示例 / Array pointer example:\n");
    printf("    int arr[5] = {1, 2, 3, 4, 5};\n");
    printf("    int (*ptr)[5] = &arr;\n\n");
    
    printf("    ptr指向整个数组 / ptr points to entire array:\n");
    printf("    ptr = %p\n", (void*)ptr);
    printf("    arr = %p (首元素地址 / first element address)\n", (void*)arr);
    printf("    &arr = %p (数组地址 / array address)\n\n", (void*)&arr);
    
    printf("    访问元素 / Accessing elements:\n");
    for (int i = 0; i < 5; i++) {
        printf("    (*ptr)[%d] = %d\n", i, (*ptr)[i]);
    }
    printf("\n");
    
    // 二维数组示例 / 2D array example
    printf("  数组指针与二维数组 / Array pointer with 2D array:\n");
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int (*row_ptr)[4] = matrix;  // 指向第一行 / Points to first row
    
    printf("    int matrix[3][4] = {...};\n");
    printf("    int (*row_ptr)[4] = matrix;\n\n");
    
    printf("    遍历二维数组 / Traversing 2D array:\n");
    for (int i = 0; i < 3; i++) {
        printf("    行 %d / Row %d: ", i, i);
        for (int j = 0; j < 4; j++) {
            printf("%2d ", row_ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    printf("  指针运算 / Pointer arithmetic:\n");
    printf("    row_ptr     指向第0行 / points to row 0\n");
    printf("    row_ptr + 1 指向第1行 / points to row 1\n");
    printf("    row_ptr + 2 指向第2行 / points to row 2\n\n");
}

void demonstrate_pointer_vs_array_comparison() {
    printf("  声明对比 / Declaration comparison:\n\n");
    
    printf("  ┌────────────────────┬────────────────────────────────────────┐\n");
    printf("  │ 声明 / Declaration │ 含义 / Meaning                         │\n");
    printf("  ├────────────────────┼────────────────────────────────────────┤\n");
    printf("  │ int *arr[5]        │ 5个指向int的指针的数组                 │\n");
    printf("  │                    │ Array of 5 pointers to int             │\n");
    printf("  ├────────────────────┼────────────────────────────────────────┤\n");
    printf("  │ int (*ptr)[5]      │ 指向5个int数组的指针                   │\n");
    printf("  │                    │ Pointer to array of 5 ints             │\n");
    printf("  └────────────────────┴────────────────────────────────────────┘\n\n");
    
    // 大小对比 / Size comparison
    int *arr_of_ptr[5];  // 指针数组 / Pointer array
    int (*ptr_to_arr)[5];  // 数组指针 / Array pointer
    
    printf("  大小对比 / Size comparison:\n");
    printf("    sizeof(int *arr[5]) = %zu 字节 / bytes\n", sizeof(arr_of_ptr));
    printf("      = 5 × sizeof(int*) = 5 × %zu = %zu\n", sizeof(int*), 5 * sizeof(int*));
    printf("    sizeof(int (*ptr)[5]) = %zu 字节 / bytes\n", sizeof(ptr_to_arr));
    printf("      = sizeof(pointer) = %zu\n\n", sizeof(int*));
    
    // 使用场景 / Use cases
    printf("  使用场景 / Use cases:\n");
    printf("    指针数组 int *arr[N] / Pointer array:\n");
    printf("      - 字符串数组 / String arrays (char *strings[])\n");
    printf("      - 命令行参数 / Command-line arguments (argv)\n");
    printf("      - 不规则数组（行长度不同）/ Jagged arrays\n\n");
    
    printf("    数组指针 int (*ptr)[N] / Array pointer:\n");
    printf("      - 遍历二维数组 / Traversing 2D arrays\n");
    printf("      - 函数参数传递二维数组 / Passing 2D arrays to functions\n");
    printf("      - 动态分配连续的二维数组 / Dynamic allocation of contiguous 2D arrays\n\n");
}

void demonstrate_function_pointer_array() {
    printf("  函数指针数组 / Function pointer array:\n");
    printf("    可以存储多个函数地址 / Can store addresses of multiple functions\n\n");
    
    // 定义函数指针数组 / Define function pointer array
    int (*operations[4])(int, int) = {add, subtract, multiply, divide_safe};
    const char *op_names[] = {"+", "-", "*", "/"};
    
    printf("  定义 / Definition:\n");
    printf("    int (*operations[4])(int, int) = {add, subtract, multiply, divide};\n\n");
    
    int a = 20, b = 5;
    printf("  使用 a=%d, b=%d 测试 / Testing with a=%d, b=%d:\n", a, b, a, b);
    
    for (int i = 0; i < 4; i++) {
        int result = operations[i](a, b);
        printf("    %d %s %d = %d\n", a, op_names[i], b, result);
    }
    printf("\n");
    
    // 通过索引调用 / Call by index
    printf("  通过索引调用 / Calling by index:\n");
    printf("    operations[0](10, 5) = %d (add)\n", operations[0](10, 5));
    printf("    operations[2](10, 5) = %d (multiply)\n\n", operations[2](10, 5));
}

void demonstrate_complex_declarations() {
    printf("  复杂声明解读规则 / Complex declaration interpretation rules:\n");
    printf("    1. 从变量名开始 / Start from variable name\n");
    printf("    2. 先右后左 / Go right, then left\n");
    printf("    3. 遇到括号先处理括号内 / Handle parentheses first\n\n");
    
    printf("  示例解读 / Example interpretations:\n\n");
    
    printf("  int *p;\n");
    printf("    解读 / Interpretation: p是指向int的指针\n");
    printf("                          p is a pointer to int\n\n");
    
    printf("  int *p[10];\n");
    printf("    解读 / Interpretation: p是一个数组[10]，元素是指向int的指针\n");
    printf("                          p is an array[10] of pointers to int\n\n");
    
    printf("  int (*p)[10];\n");
    printf("    解读 / Interpretation: p是一个指针，指向含10个int的数组\n");
    printf("                          p is a pointer to an array[10] of int\n\n");
    
    printf("  int **p;\n");
    printf("    解读 / Interpretation: p是指向（指向int的指针）的指针\n");
    printf("                          p is a pointer to a pointer to int\n\n");
    
    printf("  int (*p)(int);\n");
    printf("    解读 / Interpretation: p是一个函数指针，参数int，返回int\n");
    printf("                          p is a pointer to function(int) returning int\n\n");
    
    printf("  int (*p[10])(int);\n");
    printf("    解读 / Interpretation: p是一个数组[10]，元素是函数指针\n");
    printf("                          p is an array[10] of pointers to function(int) returning int\n\n");
    
    printf("  使用typedef简化 / Simplify with typedef:\n");
    printf("    typedef int (*FuncPtr)(int);  // 函数指针类型\n");
    printf("    FuncPtr arr[10];              // 更清晰的声明\n\n");
}
