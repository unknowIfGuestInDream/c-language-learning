#include <stdio.h>
#include <stdlib.h>

/**
 * C语言指针详解
 * Pointers in C
 * 
 * 本示例详细演示指针的概念、用法和高级特性
 * This example demonstrates pointer concepts, usage, and advanced features in detail
 */

// 函数声明 / Function declarations
void basic_pointers();
void pointer_arithmetic();
void pointer_and_arrays();
void pointer_to_pointer();
void const_pointers();
void function_with_pointers();
void swap(int *a, int *b);

int main() {
    printf("=== C语言指针详解 / Pointers in C ===\n\n");
    
    basic_pointers();
    pointer_arithmetic();
    pointer_and_arrays();
    pointer_to_pointer();
    const_pointers();
    function_with_pointers();
    
    return 0;
}

void basic_pointers() {
    printf("1. 指针基础 / Pointer Basics:\n");
    
    int num = 42;
    int *ptr = &num;  // ptr指向num / ptr points to num
    
    printf("  变量 num / Variable num:\n");
    printf("    值 / Value: %d\n", num);
    printf("    地址 / Address: %p\n", (void*)&num);
    printf("  指针 ptr / Pointer ptr:\n");
    printf("    指针的值（num的地址）/ Pointer value (address of num): %p\n", (void*)ptr);
    printf("    指针指向的值 / Value pointed to: %d\n", *ptr);
    printf("    指针自身的地址 / Address of pointer itself: %p\n", (void*)&ptr);
    
    // 通过指针修改值 / Modify value through pointer
    *ptr = 100;
    printf("  通过指针修改后 / After modification through pointer:\n");
    printf("    num = %d\n", num);
    printf("    *ptr = %d\n", *ptr);
    printf("\n");
}

void pointer_arithmetic() {
    printf("2. 指针运算 / Pointer Arithmetic:\n");
    
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;  // 指向数组首元素 / Points to first element
    
    printf("  数组 / Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("  指针运算 / Pointer arithmetic:\n");
    printf("    p指向 / p points to: %d (地址 / address: %p)\n", *p, (void*)p);
    
    p++;  // 移动到下一个元素 / Move to next element
    printf("    p++后 / After p++: %d (地址 / address: %p)\n", *p, (void*)p);
    
    p += 2;  // 前进2个元素 / Advance 2 elements
    printf("    p+=2后 / After p+=2: %d (地址 / address: %p)\n", *p, (void*)p);
    
    p--;  // 后退1个元素 / Move back 1 element
    printf("    p--后 / After p--: %d (地址 / address: %p)\n", *p, (void*)p);
    
    printf("  注意 / Note: 指针加1实际移动sizeof(type)字节 / Adding 1 moves sizeof(type) bytes\n");
    printf("  sizeof(int) = %zu bytes\n", sizeof(int));
    printf("\n");
}

void pointer_and_arrays() {
    printf("3. 指针与数组 / Pointers and Arrays:\n");
    
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;
    
    printf("  数组名就是指向首元素的指针 / Array name is pointer to first element\n");
    printf("  arr[i] 等价于 / arr[i] is equivalent to:\n");
    printf("    *(arr + i)\n");
    printf("    *(p + i)\n");
    printf("    p[i]\n\n");
    
    printf("  使用不同方式访问数组 / Accessing array different ways:\n");
    for (int i = 0; i < 5; i++) {
        printf("    arr[%d] = %d, *(arr+%d) = %d, p[%d] = %d, *(p+%d) = %d\n",
               i, arr[i], i, *(arr+i), i, p[i], i, *(p+i));
    }
    printf("\n");
}

void pointer_to_pointer() {
    printf("4. 指向指针的指针 / Pointer to Pointer:\n");
    
    int num = 42;
    int *ptr = &num;
    int **pptr = &ptr;  // 指向指针的指针 / Pointer to pointer
    
    printf("  num = %d\n", num);
    printf("  *ptr = %d\n", *ptr);
    printf("  **pptr = %d\n", **pptr);
    printf("\n");
    
    printf("  地址关系 / Address relationships:\n");
    printf("    &num = %p\n", (void*)&num);
    printf("    ptr = %p (指向num / points to num)\n", (void*)ptr);
    printf("    &ptr = %p\n", (void*)&ptr);
    printf("    pptr = %p (指向ptr / points to ptr)\n", (void*)pptr);
    printf("\n");
    
    // 通过二级指针修改值 / Modify value through double pointer
    **pptr = 100;
    printf("  通过 **pptr 修改后 / After modifying through **pptr:\n");
    printf("    num = %d\n", num);
    printf("\n");
}

void const_pointers() {
    printf("5. const指针 / const Pointers:\n");
    
    int x = 10, y = 20;
    
    // 指向常量的指针 / Pointer to constant
    const int *ptr1 = &x;
    printf("  const int *ptr1: 不能通过ptr1修改值 / Cannot modify value through ptr1\n");
    printf("    *ptr1 = %d\n", *ptr1);
    // *ptr1 = 20;  // 错误 / Error
    ptr1 = &y;      // 可以改变指向 / Can change what it points to
    printf("    可以改变指向 / Can change pointer: *ptr1 = %d\n", *ptr1);
    printf("\n");
    
    // 常量指针 / Constant pointer
    int * const ptr2 = &x;
    printf("  int * const ptr2: 不能改变指向，但可以修改值 / Cannot change pointer, can modify value\n");
    printf("    *ptr2 = %d\n", *ptr2);
    *ptr2 = 30;     // 可以修改值 / Can modify value
    printf("    修改值后 / After modifying: *ptr2 = %d\n", *ptr2);
    // ptr2 = &y;   // 错误 / Error
    printf("\n");
    
    // 指向常量的常量指针 / Constant pointer to constant
    const int * const ptr3 = &x;
    printf("  const int * const ptr3: 都不能改变 / Cannot change either\n");
    printf("    *ptr3 = %d\n", *ptr3);
    // *ptr3 = 40;  // 错误 / Error
    // ptr3 = &y;   // 错误 / Error
    printf("\n");
}

void function_with_pointers() {
    printf("6. 函数与指针 / Functions with Pointers:\n");
    
    int a = 10, b = 20;
    printf("  交换前 / Before swap: a=%d, b=%d\n", a, b);
    
    swap(&a, &b);
    
    printf("  交换后 / After swap: a=%d, b=%d\n", a, b);
    printf("\n");
    
    // 函数返回指针 / Function returning pointer
    printf("7. 动态内存和指针 / Dynamic Memory and Pointers:\n");
    int *dynamic = (int*)malloc(sizeof(int));
    *dynamic = 99;
    printf("  动态分配的值 / Dynamically allocated value: %d\n", *dynamic);
    printf("  地址 / Address: %p\n", (void*)dynamic);
    free(dynamic);
    dynamic = NULL;  // 避免悬空指针 / Avoid dangling pointer
    printf("  内存已释放，指针设为NULL / Memory freed, pointer set to NULL\n");
    printf("\n");
    
    // NULL指针 / NULL pointer
    printf("8. NULL指针 / NULL Pointer:\n");
    int *null_ptr = NULL;
    printf("  NULL指针的值 / NULL pointer value: %p\n", (void*)null_ptr);
    
    if (null_ptr == NULL) {
        printf("  指针是NULL，使用前应检查 / Pointer is NULL, should check before use\n");
    }
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("指针要点 / Pointer Key Points:\n");
    printf("  - 指针存储内存地址 / Pointers store memory addresses\n");
    printf("  - & 取地址操作符 / & is address-of operator\n");
    printf("  - * 解引用操作符 / * is dereference operator\n");
    printf("  - 指针运算基于类型大小 / Pointer arithmetic based on type size\n");
    printf("  - 数组名是指向首元素的指针 / Array name is pointer to first element\n");
    printf("  - 使用NULL避免悬空指针 / Use NULL to avoid dangling pointers\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java没有指针，只有引用 / Java: no pointers, only references\n");
    printf("  - C指针可以运算，Java引用不行 / C: pointer arithmetic, Java: no\n");
    printf("  - C需要手动内存管理 / C: manual memory management\n");
    printf("  - Java引用自动管理 / Java: automatic reference management\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
