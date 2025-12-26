#include <stdio.h>

/**
 * C语言参数传递：值传递 vs 指针传递
 * Parameter Passing in C: Pass by Value vs Pass by Pointer
 * 
 * 重要：C语言只有值传递！
 * Important: C only has pass by value!
 * 
 * 但是我们可以传递指针的值，从而实现"引用传递"的效果
 * But we can pass the value of a pointer to achieve "pass by reference" effect
 */

// 值传递示例 / Pass by Value Example
void modifyValue(int x) {
    printf("  函数内修改前 / Before modification in function: x = %d\n", x);
    x = 100;  // 只修改局部副本 / Only modifies local copy
    printf("  函数内修改后 / After modification in function: x = %d\n", x);
}

// 指针传递示例 / Pass by Pointer Example
void modifyByPointer(int *ptr) {
    printf("  函数内修改前 / Before modification in function: *ptr = %d\n", *ptr);
    *ptr = 200;  // 通过指针修改原始值 / Modifies original value through pointer
    printf("  函数内修改后 / After modification in function: *ptr = %d\n", *ptr);
}

// 数组传递示例 / Array Passing Example
// 注意：数组名就是指针，所以数组总是"引用传递"
// Note: Array name is a pointer, so arrays are always "passed by reference"
void modifyArray(int arr[], int size) {
    printf("  函数内修改数组 / Modifying array in function:\n");
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;
        printf("    arr[%d] = %d\n", i, arr[i]);
    }
}

// 结构体值传递 / Pass Struct by Value
struct Point {
    int x;
    int y;
};

void modifyPointValue(struct Point p) {
    printf("  函数内修改前 / Before: p.x=%d, p.y=%d\n", p.x, p.y);
    p.x = 100;
    p.y = 200;
    printf("  函数内修改后 / After: p.x=%d, p.y=%d\n", p.x, p.y);
}

// 结构体指针传递 / Pass Struct by Pointer
void modifyPointPointer(struct Point *p) {
    printf("  函数内修改前 / Before: p->x=%d, p->y=%d\n", p->x, p->y);
    p->x = 300;
    p->y = 400;
    printf("  函数内修改后 / After: p->x=%d, p->y=%d\n", p->x, p->y);
}

// 交换两个数（值传递 - 无效）/ Swap two numbers (by value - doesn't work)
void swapValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("  函数内交换后 / After swap in function: a=%d, b=%d\n", a, b);
}

// 交换两个数（指针传递 - 有效）/ Swap two numbers (by pointer - works)
void swapPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("  函数内交换后 / After swap in function: *a=%d, *b=%d\n", *a, *b);
}

int main() {
    printf("=== C语言参数传递 / Parameter Passing in C ===\n\n");
    
    // 1. 值传递 / Pass by Value
    printf("1. 值传递示例 / Pass by Value Example:\n");
    int num = 50;
    printf("调用前 / Before function call: num = %d\n", num);
    modifyValue(num);
    printf("调用后 / After function call: num = %d\n", num);
    printf("结论 / Conclusion: 原始值未改变 / Original value unchanged\n\n");
    
    // 2. 指针传递 / Pass by Pointer
    printf("2. 指针传递示例 / Pass by Pointer Example:\n");
    num = 50;
    printf("调用前 / Before function call: num = %d\n", num);
    modifyByPointer(&num);  // 传递地址 / Pass address
    printf("调用后 / After function call: num = %d\n", num);
    printf("结论 / Conclusion: 原始值已改变 / Original value changed\n\n");
    
    // 3. 数组传递 / Array Passing
    printf("3. 数组传递示例 / Array Passing Example:\n");
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("调用前 / Before function call: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    modifyArray(arr, size);
    printf("调用后 / After function call: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("结论 / Conclusion: 数组内容已改变 / Array content changed\n\n");
    
    // 4. 结构体值传递 / Pass Struct by Value
    printf("4. 结构体值传递 / Pass Struct by Value:\n");
    struct Point point = {10, 20};
    printf("调用前 / Before: point.x=%d, point.y=%d\n", point.x, point.y);
    modifyPointValue(point);
    printf("调用后 / After: point.x=%d, point.y=%d\n", point.x, point.y);
    printf("结论 / Conclusion: 结构体未改变 / Struct unchanged\n\n");
    
    // 5. 结构体指针传递 / Pass Struct by Pointer
    printf("5. 结构体指针传递 / Pass Struct by Pointer:\n");
    printf("调用前 / Before: point.x=%d, point.y=%d\n", point.x, point.y);
    modifyPointPointer(&point);
    printf("调用后 / After: point.x=%d, point.y=%d\n", point.x, point.y);
    printf("结论 / Conclusion: 结构体已改变 / Struct changed\n\n");
    
    // 6. 交换示例 - 值传递（失败）/ Swap Example - By Value (fails)
    printf("6. 交换示例 - 值传递 / Swap Example - By Value:\n");
    int x = 10, y = 20;
    printf("调用前 / Before: x=%d, y=%d\n", x, y);
    swapValue(x, y);
    printf("调用后 / After: x=%d, y=%d\n", x, y);
    printf("结论 / Conclusion: 交换失败 / Swap failed\n\n");
    
    // 7. 交换示例 - 指针传递（成功）/ Swap Example - By Pointer (works)
    printf("7. 交换示例 - 指针传递 / Swap Example - By Pointer:\n");
    printf("调用前 / Before: x=%d, y=%d\n", x, y);
    swapPointer(&x, &y);
    printf("调用后 / After: x=%d, y=%d\n", x, y);
    printf("结论 / Conclusion: 交换成功 / Swap successful\n\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("1. C语言只有值传递 / C only has pass by value\n");
    printf("2. 要修改原始值，必须传递指针 / To modify original value, pass pointer\n");
    printf("3. 数组名本质是指针，所以总是可以修改 / Array name is pointer, so always modifiable\n");
    printf("4. 与Java对比 / Comparison with Java:\n");
    printf("   - Java基本类型是值传递 / Java primitives are pass by value\n");
    printf("   - Java对象引用是值传递，但可以修改对象 / Java object references are pass by value, but can modify objects\n");
    printf("   - C的指针类似Java的对象引用 / C pointers are similar to Java object references\n");
    
    return 0;
}
