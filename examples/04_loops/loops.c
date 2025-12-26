#include <stdio.h>

/**
 * C语言循环
 * Loops in C
 * 
 * 本示例演示for、while、do-while循环以及break、continue的使用
 * This example demonstrates for, while, do-while loops and use of break, continue
 */

int main() {
    printf("=== C语言循环 / Loops in C ===\n\n");
    
    // 1. for循环 / for loop
    printf("1. for循环 / for Loop:\n");
    printf("  1到10的数字 / Numbers from 1 to 10:\n  ");
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 2. for循环变体 / for loop variations
    printf("2. for循环变体 / for Loop Variations:\n");
    
    // 递减循环 / Decrementing loop
    printf("  倒数 / Countdown: ");
    for (int i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 步长为2 / Step by 2
    printf("  偶数 / Even numbers: ");
    for (int i = 0; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    // 多个初始化和更新 / Multiple initialization and update
    printf("  多变量 / Multiple variables: ");
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n\n");
    
    // 3. while循环 / while loop
    printf("3. while循环 / while Loop:\n");
    int count = 1;
    printf("  1到5 / 1 to 5: ");
    while (count <= 5) {
        printf("%d ", count);
        count++;
    }
    printf("\n\n");
    
    // 4. do-while循环 / do-while loop
    printf("4. do-while循环 / do-while Loop:\n");
    int num = 1;
    printf("  至少执行一次 / Executes at least once: ");
    do {
        printf("%d ", num);
        num++;
    } while (num <= 5);
    printf("\n");
    
    // do-while vs while的区别 / Difference between do-while and while
    printf("  区别演示 / Difference demonstration:\n");
    int x = 10;
    printf("    while (x < 5): ");
    while (x < 5) {
        printf("%d ", x);  // 不会执行 / Won't execute
        x++;
    }
    printf("(不执行 / not executed)\n");
    
    x = 10;
    printf("    do-while (x < 5): ");
    do {
        printf("%d ", x);  // 执行一次 / Executes once
        x++;
    } while (x < 5);
    printf("(执行一次 / executed once)\n\n");
    
    // 5. 嵌套循环 / Nested loops
    printf("5. 嵌套循环 / Nested Loops:\n");
    printf("  乘法表 / Multiplication table (1-5):\n");
    for (int i = 1; i <= 5; i++) {
        printf("  ");
        for (int j = 1; j <= 5; j++) {
            printf("%3d ", i * j);
        }
        printf("\n");
    }
    printf("\n");
    
    // 6. break语句 / break statement
    printf("6. break语句 / break Statement:\n");
    printf("  查找第一个能被7整除的数 / Find first number divisible by 7:\n  ");
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {
            printf("找到：%d\n", i);
            break;  // 跳出循环 / Exit loop
        }
    }
    printf("\n");
    
    // 7. continue语句 / continue statement
    printf("7. continue语句 / continue Statement:\n");
    printf("  跳过偶数，只打印奇数 / Skip even, print only odd:\n  ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // 跳过本次迭代 / Skip this iteration
        }
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 8. break和continue在嵌套循环中 / break and continue in nested loops
    printf("8. 嵌套循环中的break / break in Nested Loops:\n");
    printf("  外层break / Outer break:\n");
    for (int i = 1; i <= 3; i++) {
        printf("  外层 i=%d: ", i);
        for (int j = 1; j <= 5; j++) {
            if (j == 3) {
                break;  // 只跳出内层循环 / Only exits inner loop
            }
            printf("%d ", j);
        }
        printf("\n");
    }
    printf("\n");
    
    // 9. 无限循环 / Infinite loop
    printf("9. 无限循环 / Infinite Loop:\n");
    printf("  while(1) 示例（带退出条件）/ while(1) example (with exit condition):\n  ");
    int counter = 0;
    while (1) {
        printf("%d ", counter);
        counter++;
        if (counter >= 5) {
            break;  // 退出无限循环 / Exit infinite loop
        }
    }
    printf("\n\n");
    
    // 10. 求和示例 / Sum example
    printf("10. 实用示例：计算1到100的和 / Practical Example: Sum 1 to 100:\n");
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i;
    }
    printf("  1 + 2 + ... + 100 = %d\n", sum);
    printf("\n");
    
    // 11. 阶乘示例 / Factorial example
    printf("11. 阶乘计算 / Factorial Calculation:\n");
    int n = 5;
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("  %d! = %lld\n", n, factorial);
    printf("\n");
    
    // 12. 斐波那契数列 / Fibonacci sequence
    printf("12. 斐波那契数列 / Fibonacci Sequence:\n");
    printf("  前10项 / First 10 terms: ");
    int a = 0, b = 1, next;
    printf("%d %d ", a, b);
    for (int i = 2; i < 10; i++) {
        next = a + b;
        printf("%d ", next);
        a = b;
        b = next;
    }
    printf("\n\n");
    
    // 13. 寻找最大值 / Finding maximum
    printf("13. 寻找数组最大值 / Finding Maximum in Array:\n");
    int numbers[] = {23, 45, 12, 67, 34, 89, 56};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int max = numbers[0];
    
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("  数组 / Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n  最大值 / Maximum: %d\n\n", max);
    
    // 14. 模式打印 / Pattern printing
    printf("14. 模式打印 / Pattern Printing:\n");
    printf("  三角形 / Triangle:\n");
    for (int i = 1; i <= 5; i++) {
        printf("  ");
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("循环类型 / Loop Types:\n");
    printf("  for        - 已知迭代次数 / Known iteration count\n");
    printf("  while      - 条件为真时执行 / Execute while condition is true\n");
    printf("  do-while   - 至少执行一次 / Execute at least once\n\n");
    
    printf("控制语句 / Control Statements:\n");
    printf("  break      - 跳出循环 / Exit loop\n");
    printf("  continue   - 跳过当前迭代 / Skip current iteration\n\n");
    
    printf("选择循环的建议 / Loop Selection Guide:\n");
    printf("  - 已知次数用for / Known count: use for\n");
    printf("  - 未知次数用while / Unknown count: use while\n");
    printf("  - 至少执行一次用do-while / At least once: use do-while\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - 语法完全相同 / Syntax is identical\n");
    printf("  - Java还有for-each循环 / Java also has for-each loop\n");
    printf("  - C99允许for中声明变量，早期C不行 / C99: declare in for, earlier C: no\n");
    
    return 0;
}
