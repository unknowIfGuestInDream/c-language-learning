/*
 * C语言可变参数函数 / C Variadic Functions
 */

#include <stdio.h>
#include <stdarg.h>

// 可变参数函数声明 / Variadic function declarations
int sum_integers(int count, ...);
double average(int count, ...);
void print_strings(const char *first, ...);
int max_of_numbers(int count, ...);

int main() {
    printf("=== C语言可变参数函数 / C Variadic Functions ===\n\n");
    
    // 1. 整数求和 / Sum integers
    printf("1. 整数求和 / Sum Integers:\n");
    printf("  sum(3, 10, 20, 30) = %d\n", sum_integers(3, 10, 20, 30));
    printf("  sum(5, 1, 2, 3, 4, 5) = %d\n", sum_integers(5, 1, 2, 3, 4, 5));
    
    // 2. 计算平均值 / Calculate average
    printf("\n2. 计算平均值 / Calculate Average:\n");
    printf("  average(4, 10.0, 20.0, 30.0, 40.0) = %.2f\n", 
           average(4, 10.0, 20.0, 30.0, 40.0));
    
    // 3. 打印字符串 / Print strings
    printf("\n3. 打印字符串 / Print Strings:\n");
    printf("  ");
    print_strings("Hello", "World", "from", "C", NULL);
    
    // 4. 找最大值 / Find maximum
    printf("\n4. 找最大值 / Find Maximum:\n");
    printf("  max(5, 23, 45, 12, 67, 34) = %d\n", 
           max_of_numbers(5, 23, 45, 12, 67, 34));
    
    printf("\n学习要点 / Key Points:\n");
    printf("1. 使用stdarg.h提供的宏：va_list, va_start, va_arg, va_end\n");
    printf("2. 至少需要一个固定参数（通常表示可变参数的数量）\n");
    printf("3. va_start初始化，va_arg获取参数，va_end清理\n");
    printf("4. 类似printf的函数都使用可变参数\n");
    
    return 0;
}

int sum_integers(int count, ...) {
    va_list args;
    va_start(args, count);  // 初始化 / Initialize
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);  // 获取下一个int参数 / Get next int argument
    }
    
    va_end(args);  // 清理 / Cleanup
    return sum;
}

double average(int count, ...) {
    if (count == 0) return 0.0;
    
    va_list args;
    va_start(args, count);
    
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, double);
    }
    
    va_end(args);
    return sum / count;
}

void print_strings(const char *first, ...) {
    printf("%s ", first);
    
    va_list args;
    va_start(args, first);
    
    const char *str;
    while ((str = va_arg(args, const char *)) != NULL) {
        printf("%s ", str);
    }
    
    va_end(args);
    printf("\n");
}

int max_of_numbers(int count, ...) {
    if (count == 0) return 0;
    
    va_list args;
    va_start(args, count);
    
    int max = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int num = va_arg(args, int);
        if (num > max) {
            max = num;
        }
    }
    
    va_end(args);
    return max;
}
