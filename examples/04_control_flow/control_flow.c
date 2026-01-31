#include <stdio.h>

/**
 * C语言控制流：条件语句
 * Control Flow in C: Conditional Statements
 * 
 * 本示例演示if、else、else if和switch语句的使用
 * This example demonstrates the use of if, else, else if, and switch statements
 */

int main() {
    printf("=== C语言控制流 / Control Flow in C ===\n\n");
    
    // 1. if语句 / if statement
    printf("1. if语句 / if Statement:\n");
    int age = 18;
    
    if (age >= 18) {
        printf("  年龄 %d：成年人 / Age %d: Adult\n", age, age);
    }
    printf("\n");
    
    // 2. if-else语句 / if-else statement
    printf("2. if-else语句 / if-else Statement:\n");
    int score = 75;
    
    if (score >= 60) {
        printf("  分数 %d：及格 / Score %d: Pass\n", score, score);
    } else {
        printf("  分数 %d：不及格 / Score %d: Fail\n", score, score);
    }
    printf("\n");
    
    // 3. if-else if-else链 / if-else if-else chain
    printf("3. if-else if-else链 / if-else if-else Chain:\n");
    score = 85;
    
    if (score >= 90) {
        printf("  分数 %d：优秀 / Score %d: Excellent\n", score, score);
    } else if (score >= 80) {
        printf("  分数 %d：良好 / Score %d: Good\n", score, score);
    } else if (score >= 70) {
        printf("  分数 %d：中等 / Score %d: Average\n", score, score);
    } else if (score >= 60) {
        printf("  分数 %d：及格 / Score %d: Pass\n", score, score);
    } else {
        printf("  分数 %d：不及格 / Score %d: Fail\n", score, score);
    }
    printf("\n");
    
    // 4. 嵌套if语句 / Nested if statements
    printf("4. 嵌套if语句 / Nested if Statements:\n");
    int has_ticket = 1;
    age = 25;
    
    if (has_ticket) {
        printf("  有票 / Has ticket\n");
        if (age >= 18) {
            printf("  年龄 %d：可以观看成人电影 / Age %d: Can watch adult movie\n", age, age);
        } else {
            printf("  年龄 %d：只能观看儿童电影 / Age %d: Can only watch kids movie\n", age, age);
        }
    } else {
        printf("  没有票：请先购票 / No ticket: Please buy ticket first\n");
    }
    printf("\n");
    
    // 5. 三元运算符 / Ternary operator
    printf("5. 三元运算符 / Ternary Operator:\n");
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    printf("  a = %d, b = %d\n", a, b);
    printf("  max = (a > b) ? a : b = %d\n", max);
    printf("\n");
    
    // 6. switch语句 / switch statement
    printf("6. switch语句 / switch Statement:\n");
    int day = 3;
    
    switch (day) {
        case 1:
            printf("  Day %d: 星期一 / Monday\n", day);
            break;
        case 2:
            printf("  Day %d: 星期二 / Tuesday\n", day);
            break;
        case 3:
            printf("  Day %d: 星期三 / Wednesday\n", day);
            break;
        case 4:
            printf("  Day %d: 星期四 / Thursday\n", day);
            break;
        case 5:
            printf("  Day %d: 星期五 / Friday\n", day);
            break;
        case 6:
            printf("  Day %d: 星期六 / Saturday\n", day);
            break;
        case 7:
            printf("  Day %d: 星期日 / Sunday\n", day);
            break;
        default:
            printf("  Day %d: 无效的日期 / Invalid day\n", day);
            break;
    }
    printf("\n");
    
    // 7. switch without break (fall-through) / switch无break（穿透）
    printf("7. switch穿透 / switch Fall-through:\n");
    char grade = 'B';
    
    printf("  成绩等级 / Grade: %c\n", grade);
    switch (grade) {
        case 'A':
            printf("  优秀 / Excellent\n");
            break;
        case 'B':
        case 'C':
            printf("  良好 / Good\n");
            break;
        case 'D':
            printf("  及格 / Pass\n");
            break;
        case 'F':
            printf("  不及格 / Fail\n");
            break;
        default:
            printf("  无效等级 / Invalid grade\n");
            break;
    }
    printf("\n");
    
    // 8. 使用switch处理字符 / Using switch with characters
    printf("8. switch处理字符 / switch with Characters:\n");
    char operation = '+';
    int x = 10, y = 5;
    int result;
    
    printf("  %d %c %d = ", x, operation, y);
    switch (operation) {
        case '+':
            result = x + y;
            printf("%d\n", result);
            break;
        case '-':
            result = x - y;
            printf("%d\n", result);
            break;
        case '*':
            result = x * y;
            printf("%d\n", result);
            break;
        case '/':
            if (y != 0) {
                result = x / y;
                printf("%d\n", result);
            } else {
                printf("错误：除以零 / Error: Division by zero\n");
            }
            break;
        default:
            printf("错误：未知运算符 / Error: Unknown operator\n");
            break;
    }
    printf("\n");
    
    // 9. 逻辑运算符组合 / Combining logical operators
    printf("9. 逻辑运算符组合 / Combining Logical Operators:\n");
    int temperature = 25;
    int humidity = 60;
    
    if (temperature >= 20 && temperature <= 30 && humidity < 70) {
        printf("  温度 %d°C, 湿度 %d%%: 天气舒适 / Temp %d°C, Humidity %d%%: Comfortable\n", 
               temperature, humidity, temperature, humidity);
    } else {
        printf("  温度 %d°C, 湿度 %d%%: 天气不适 / Temp %d°C, Humidity %d%%: Uncomfortable\n", 
               temperature, humidity, temperature, humidity);
    }
    printf("\n");
    
    // 10. 条件表达式的简化 / Simplifying conditional expressions
    printf("10. 条件表达式的简化 / Simplifying Conditional Expressions:\n");
    
    // 方式1：标准if / Method 1: Standard if
    int is_even;
    int number = 10;
    if (number % 2 == 0) {
        is_even = 1;
    } else {
        is_even = 0;
    }
    printf("  方式1 / Method 1: %d is %s\n", number, is_even ? "even" : "odd");
    
    // 方式2：三元运算符 / Method 2: Ternary operator
    is_even = (number % 2 == 0) ? 1 : 0;
    printf("  方式2 / Method 2: %d is %s\n", number, is_even ? "even" : "odd");
    
    // 方式3：直接赋值布尔表达式 / Method 3: Direct boolean assignment
    is_even = (number % 2 == 0);
    printf("  方式3 / Method 3: %d is %s\n", number, is_even ? "even" : "odd");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("条件语句 / Conditional Statements:\n");
    printf("  if      - 单一条件 / Single condition\n");
    printf("  if-else - 二选一 / Two choices\n");
    printf("  if-else if-else - 多选一 / Multiple choices\n");
    printf("  switch  - 离散值匹配 / Discrete value matching\n");
    printf("  ? :     - 三元运算符，简洁的二选一 / Ternary operator, concise two choices\n\n");
    
    printf("最佳实践 / Best Practices:\n");
    printf("  - if处理范围判断，switch处理离散值 / if for ranges, switch for discrete values\n");
    printf("  - switch的每个case要有break / Each switch case should have break\n");
    printf("  - 复杂条件使用括号提高可读性 / Use parentheses for complex conditions\n");
    printf("  - 避免过深的嵌套 / Avoid deep nesting\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - 语法基本相同 / Syntax is basically the same\n");
    printf("  - C的switch只支持整数和字符，Java 7+支持字符串 / C: int/char, Java 7+: String\n");
    printf("  - C没有布尔类型（C99前），使用整数0和非0 / C: no bool (pre-C99), use 0 and non-zero\n");
    
    return 0;
}
