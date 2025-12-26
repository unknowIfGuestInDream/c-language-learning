#include <stdio.h>
#include <stdlib.h>

/**
 * C语言函数指针和回调函数
 * Function Pointers and Callbacks in C
 * 
 * 本示例演示函数指针的声明、使用和回调机制
 * This example demonstrates function pointer declaration, usage, and callback mechanisms
 */

// 简单函数 / Simple functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) return 0;
    return a / b;
}

// 使用函数指针作为参数 / Using function pointer as parameter
int calculate(int a, int b, int (*operation)(int, int)) {
    return operation(a, b);
}

// 回调函数示例 / Callback function example
typedef void (*CallbackFunction)(int);

void processArray(int arr[], int size, CallbackFunction callback) {
    for (int i = 0; i < size; i++) {
        callback(arr[i]);
    }
}

void printNumber(int num) {
    printf("%d ", num);
}

void printSquare(int num) {
    printf("%d ", num * num);
}

// 比较函数类型（用于排序）/ Comparison function type (for sorting)
typedef int (*CompareFunction)(const void*, const void*);

int compareInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compareIntDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// 函数指针数组 / Array of function pointers
void menu_option_1() { printf("  执行选项1 / Executing option 1\n"); }
void menu_option_2() { printf("  执行选项2 / Executing option 2\n"); }
void menu_option_3() { printf("  执行选项3 / Executing option 3\n"); }

int main() {
    printf("=== C语言函数指针和回调 / Function Pointers and Callbacks ===\n\n");
    
    // 1. 基本函数指针 / Basic function pointer
    printf("1. 基本函数指针 / Basic Function Pointer:\n");
    
    // 声明函数指针 / Declare function pointer
    int (*func_ptr)(int, int);
    
    // 指向add函数 / Point to add function
    func_ptr = add;
    printf("  add(10, 5) = %d\n", func_ptr(10, 5));
    
    // 指向subtract函数 / Point to subtract function
    func_ptr = subtract;
    printf("  subtract(10, 5) = %d\n", func_ptr(10, 5));
    
    // 也可以使用&运算符 / Can also use & operator
    func_ptr = &multiply;
    printf("  multiply(10, 5) = %d\n", (*func_ptr)(10, 5));
    printf("\n");
    
    // 2. 函数指针作为参数 / Function pointer as parameter
    printf("2. 函数指针作为参数 / Function Pointer as Parameter:\n");
    
    printf("  calculate(10, 5, add) = %d\n", calculate(10, 5, add));
    printf("  calculate(10, 5, subtract) = %d\n", calculate(10, 5, subtract));
    printf("  calculate(10, 5, multiply) = %d\n", calculate(10, 5, multiply));
    printf("  calculate(10, 5, divide) = %d\n", calculate(10, 5, divide));
    printf("\n");
    
    // 3. 回调函数 / Callback functions
    printf("3. 回调函数 / Callback Functions:\n");
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("  原始数组 / Original array: ");
    processArray(numbers, size, printNumber);
    printf("\n");
    
    printf("  平方后 / Squared: ");
    processArray(numbers, size, printSquare);
    printf("\n\n");
    
    // 4. 使用qsort和函数指针 / Using qsort with function pointers
    printf("4. 排序与函数指针 / Sorting with Function Pointers:\n");
    
    int arr1[] = {64, 34, 25, 12, 22, 11, 90};
    int arr_size = sizeof(arr1) / sizeof(arr1[0]);
    
    printf("  原始数组 / Original: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    // 升序排序 / Ascending sort
    qsort(arr1, arr_size, sizeof(int), compareInt);
    printf("  升序 / Ascending: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    // 降序排序 / Descending sort
    qsort(arr1, arr_size, sizeof(int), compareIntDesc);
    printf("  降序 / Descending: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");
    
    // 5. 函数指针数组 / Array of function pointers
    printf("5. 函数指针数组 / Array of Function Pointers:\n");
    
    // 声明并初始化函数指针数组 / Declare and initialize array
    void (*menu[])(void) = {menu_option_1, menu_option_2, menu_option_3};
    
    printf("  菜单系统 / Menu system:\n");
    for (int i = 0; i < 3; i++) {
        printf("  选择 %d / Choice %d:\n", i+1, i+1);
        menu[i]();  // 调用函数 / Call function
    }
    printf("\n");
    
    // 6. typedef简化函数指针 / typedef to simplify function pointers
    printf("6. typedef简化函数指针 / typedef for Function Pointers:\n");
    
    // 定义函数指针类型 / Define function pointer type
    typedef int (*Operation)(int, int);
    
    Operation op;
    op = add;
    printf("  使用typedef后更清晰 / Clearer with typedef:\n");
    printf("  Operation op = add;\n");
    printf("  op(15, 3) = %d\n", op(15, 3));
    printf("\n");
    
    // 7. 返回函数指针 / Returning function pointer
    printf("7. 返回函数指针 / Returning Function Pointer:\n");
    
    // 简化的示例 / Simplified example
    Operation getOperation(char op_char) {
        switch (op_char) {
            case '+': return add;
            case '-': return subtract;
            case '*': return multiply;
            case '/': return divide;
            default: return NULL;
        }
    }
    
    char operators[] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++) {
        Operation current_op = getOperation(operators[i]);
        if (current_op) {
            printf("  20 %c 4 = %d\n", operators[i], current_op(20, 4));
        }
    }
    printf("\n");
    
    // 8. 函数指针与结构体 / Function pointers with structures
    printf("8. 函数指针与结构体 / Function Pointers with Structures:\n");
    
    typedef struct {
        int (*add)(int, int);
        int (*subtract)(int, int);
        int (*multiply)(int, int);
    } Calculator;
    
    Calculator calc = {add, subtract, multiply};
    
    printf("  计算器结构体 / Calculator structure:\n");
    printf("  calc.add(8, 2) = %d\n", calc.add(8, 2));
    printf("  calc.subtract(8, 2) = %d\n", calc.subtract(8, 2));
    printf("  calc.multiply(8, 2) = %d\n", calc.multiply(8, 2));
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("函数指针特点 / Function Pointer Characteristics:\n");
    printf("  - 存储函数地址 / Store function address\n");
    printf("  - 可以作为参数传递 / Can be passed as parameters\n");
    printf("  - 实现回调机制 / Implement callback mechanism\n");
    printf("  - 支持动态函数调用 / Support dynamic function calls\n\n");
    
    printf("语法 / Syntax:\n");
    printf("  声明 / Declaration: int (*func_ptr)(int, int);\n");
    printf("  赋值 / Assignment: func_ptr = function_name;\n");
    printf("  调用 / Calling: result = func_ptr(a, b);\n");
    printf("  typedef: typedef int (*Operation)(int, int);\n\n");
    
    printf("应用场景 / Use Cases:\n");
    printf("  - 回调函数 / Callback functions\n");
    printf("  - 插件系统 / Plugin systems\n");
    printf("  - 事件处理 / Event handling\n");
    printf("  - 策略模式 / Strategy pattern\n");
    printf("  - 排序/搜索算法 / Sort/search algorithms\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C使用函数指针，Java使用接口/Lambda / C: function pointers, Java: interfaces/lambdas\n");
    printf("  - C的函数指针更底层 / C: lower level\n");
    printf("  - Java的接口更面向对象 / Java: more object-oriented\n");
    printf("  - C没有闭包，Java有Lambda / C: no closures, Java: has lambdas\n");
    
    return 0;
}
