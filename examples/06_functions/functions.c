/*
 * C语言函数 / C Functions
 * 
 * 本示例演示C语言中的函数定义、参数传递、返回值等 / This example demonstrates function definitions, parameters, return values in C
 * 
 * 与Java对比 / Comparison with Java:
 * - C的函数不属于任何类（C没有类）/ C functions don't belong to any class (C has no classes)
 * - C支持函数指针，Java不支持 / C supports function pointers, Java doesn't
 * - C不支持函数重载，Java支持 / C doesn't support function overloading, Java does
 * - C按值传递所有参数，Java按值传递基本类型，按引用传递对象 / C passes all by value, Java passes primitives by value, objects by reference
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

// 1. 简单函数定义 / Simple Function Definition
// 函数声明（原型）/ Function declaration (prototype)
void greet(void);  // void表示无参数 / void means no parameters

// 2. 带参数的函数 / Function with Parameters
int add(int a, int b);

// 3. 带返回值的函数 / Function with Return Value
double calculate_area(double radius);

// 4. 多个参数 / Multiple Parameters
void print_info(const char *name, int age, double height);

// 5. 递归函数 / Recursive Function
int factorial(int n);
int fibonacci(int n);

// 6. 静态函数（文件作用域）/ Static Function (File Scope)
static int helper_function(int x);  // 只能在本文件中使用 / Only usable in this file

// 7. 内联函数建议 / Inline Function Suggestion
// Note: inline functions must be defined in header or same file before use
static inline int max(int a, int b) {  // static inline for internal linkage
    return (a > b) ? a : b;
}

// 8. 带数组参数的函数 / Function with Array Parameter
void print_array(int arr[], int size);  // 数组作为参数时退化为指针 / Array degrades to pointer as parameter
double array_average(int arr[], int size);

// 9. 带指针参数的函数（模拟引用传递）/ Function with Pointer Parameters (Simulating Pass-by-Reference)
void swap(int *a, int *b);
void modify_value(int *ptr);

// 10. 返回指针的函数 / Function Returning Pointer
int* create_array(int size);  // 注意：不要返回局部变量的指针 / Warning: don't return pointer to local variable

int main() {
    printf("=== C语言函数 / C Functions ===\n\n");
    
    // 1. 调用简单函数 / Calling Simple Function
    printf("1. 简单函数调用 / Simple Function Call:\n");
    greet();
    printf("\n");
    
    // 2. 带参数的函数 / Function with Parameters
    printf("2. 带参数的函数 / Function with Parameters:\n");
    int sum = add(10, 20);
    printf("  add(10, 20) = %d\n", sum);
    printf("\n");
    
    // 3. 带返回值的函数 / Function with Return Value
    printf("3. 带返回值的函数 / Function with Return Value:\n");
    double area = calculate_area(5.0);
    printf("  圆的面积（半径=5.0）/ Circle area (radius=5.0) = %.2f\n", area);
    printf("\n");
    
    // 4. 多个参数 / Multiple Parameters
    printf("4. 多个参数 / Multiple Parameters:\n");
    print_info("张三 / Zhang San", 25, 1.75);
    printf("\n");
    
    // 5. 递归函数 / Recursive Function
    printf("5. 递归函数 / Recursive Function:\n");
    printf("  factorial(5) = %d\n", factorial(5));
    printf("  fibonacci(10) = %d\n", fibonacci(10));
    printf("\n");
    
    // 6. 内联函数 / Inline Function
    printf("6. 内联函数 / Inline Function:\n");
    printf("  max(15, 20) = %d\n", max(15, 20));
    printf("\n");
    
    // 7. 数组参数 / Array Parameter
    printf("7. 数组参数 / Array Parameter:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    printf("  数组 / Array: ");
    print_array(numbers, size);
    printf("  平均值 / Average: %.2f\n", array_average(numbers, size));
    printf("\n");
    
    // 8. 指针参数（模拟引用传递）/ Pointer Parameters (Simulating Pass-by-Reference)
    printf("8. 指针参数（模拟引用传递）/ Pointer Parameters:\n");
    int x = 10, y = 20;
    printf("  交换前 / Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);  // 传递地址 / Pass addresses
    printf("  交换后 / After swap: x = %d, y = %d\n", x, y);
    
    int value = 100;
    printf("  修改前 / Before modify: value = %d\n", value);
    modify_value(&value);
    printf("  修改后 / After modify: value = %d\n", value);
    printf("\n");
    
    printf("学习要点 / Key Points:\n");
    printf("1. C的所有参数都是按值传递的 / All C parameters are passed by value\n");
    printf("2. 要修改参数，需要传递指针 / To modify parameters, pass pointers\n");
    printf("3. 数组参数自动转换为指针 / Array parameters automatically convert to pointers\n");
    printf("4. 函数必须在使用前声明 / Functions must be declared before use\n");
    printf("5. C不支持函数重载 / C doesn't support function overloading\n");
    printf("6. static函数只在当前文件可见 / static functions are only visible in current file\n");
    printf("7. inline是对编译器的建议，不保证一定内联 / inline is a suggestion, not guaranteed\n");
    
    return 0;
}

// 函数实现 / Function Implementations

void greet(void) {
    printf("  你好，世界！/ Hello, World!\n");
}

int add(int a, int b) {
    return a + b;
}

double calculate_area(double radius) {
    const double PI = 3.14159265359;
    return PI * radius * radius;
}

void print_info(const char *name, int age, double height) {
    printf("  姓名 / Name: %s\n", name);
    printf("  年龄 / Age: %d\n", age);
    printf("  身高 / Height: %.2f m\n", height);
}

int factorial(int n) {
    // 基本情况 / Base case
    if (n <= 1) {
        return 1;
    }
    // 递归情况 / Recursive case
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    // 基本情况 / Base cases
    if (n <= 1) {
        return n;
    }
    // 递归情况 / Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

static int helper_function(int x) {
    // 这个函数只能在本文件中使用 / This function is only usable in this file
    return x * 2;
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

double array_average(int arr[], int size) {
    if (size == 0) {
        return 0.0;
    }
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

void swap(int *a, int *b) {
    int temp = *a;  // 解引用获取值 / Dereference to get value
    *a = *b;
    *b = temp;
}

void modify_value(int *ptr) {
    *ptr = *ptr * 2;  // 修改指针指向的值 / Modify the value pointed to
}

int* create_array(int size) {
    // 警告：不要这样做！/ Warning: Don't do this!
    // int arr[size];  // 局部数组 / Local array
    // return arr;     // 返回局部变量地址是危险的！/ Returning address of local variable is dangerous!
    
    // 正确做法：使用malloc / Correct way: use malloc
    // int *arr = (int*)malloc(size * sizeof(int));
    // return arr;  // 调用者负责释放 / Caller responsible for freeing
    
    return NULL;  // 仅作示例 / For demonstration only
}
