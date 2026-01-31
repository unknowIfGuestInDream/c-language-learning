/*
 * C语言运算符和表达式 / C Operators and Expressions
 * 
 * 本示例演示C语言中的各种运算符 / This example demonstrates various operators in C
 * 
 * 与Java对比 / Comparison with Java:
 * - C和Java的基本运算符非常相似 / C and Java have very similar basic operators
 * - C有位运算符，Java也有但使用较少 / C has bitwise operators, Java has them but less commonly used
 * - C没有>>>运算符（无符号右移）/ C doesn't have >>> operator (unsigned right shift)
 * - C的++/--运算符可用于指针 / C's ++/-- operators can be used on pointers
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("=== C语言运算符和表达式 / C Operators and Expressions ===\n\n");
    
    // 1. 算术运算符 / Arithmetic Operators
    printf("1. 算术运算符 / Arithmetic Operators:\n");
    int a = 10, b = 3;
    printf("  a = %d, b = %d\n", a, b);
    printf("  a + b = %d\n", a + b);     // 加法 / Addition
    printf("  a - b = %d\n", a - b);     // 减法 / Subtraction
    printf("  a * b = %d\n", a * b);     // 乘法 / Multiplication
    printf("  a / b = %d\n", a / b);     // 整数除法 / Integer division (结果3，不是3.33)
    printf("  a %% b = %d\n", a % b);    // 取模 / Modulo (余数 / remainder)
    printf("  (double)a / b = %.2f\n", (double)a / b);  // 浮点除法 / Floating-point division
    
    // Java对比 / Java comparison:
    // Java也有相同的运算符，行为一致 / Java has the same operators with identical behavior
    printf("\n");
    
    // 2. 关系运算符 / Relational Operators
    printf("2. 关系运算符 / Relational Operators:\n");
    printf("  a == b: %d (false)\n", a == b);  // 等于 / Equal to
    printf("  a != b: %d (true)\n", a != b);   // 不等于 / Not equal to
    printf("  a > b: %d (true)\n", a > b);     // 大于 / Greater than
    printf("  a < b: %d (false)\n", a < b);    // 小于 / Less than
    printf("  a >= b: %d (true)\n", a >= b);   // 大于等于 / Greater than or equal to
    printf("  a <= b: %d (false)\n", a <= b);  // 小于等于 / Less than or equal to
    
    // 注意：C中true是1，false是0 / Note: In C, true is 1, false is 0
    printf("\n");
    
    // 3. 逻辑运算符 / Logical Operators
    printf("3. 逻辑运算符 / Logical Operators:\n");
    bool x = true, y = false;
    printf("  x = %d (true), y = %d (false)\n", x, y);
    printf("  x && y: %d (false)\n", x && y);  // 逻辑与 / Logical AND
    printf("  x || y: %d (true)\n", x || y);   // 逻辑或 / Logical OR
    printf("  !x: %d (false)\n", !x);          // 逻辑非 / Logical NOT
    
    // 短路求值 / Short-circuit evaluation
    int i = 0;
    printf("  短路求值演示 / Short-circuit demonstration:\n");
    if (y && (++i > 0)) {  // ++i不会执行，因为y是false / ++i won't execute because y is false
        printf("    This won't print\n");
    }
    printf("  i = %d (没有自增 / not incremented)\n", i);
    printf("\n");
    
    // 4. 位运算符 / Bitwise Operators
    printf("4. 位运算符 / Bitwise Operators:\n");
    unsigned int m = 12;  // 二进制: 1100 / Binary: 1100
    unsigned int n = 10;  // 二进制: 1010 / Binary: 1010
    printf("  m = %u (binary: 1100), n = %u (binary: 1010)\n", m, n);
    printf("  m & n = %u (1000 = 8)\n", m & n);   // 按位与 / Bitwise AND
    printf("  m | n = %u (1110 = 14)\n", m | n);  // 按位或 / Bitwise OR
    printf("  m ^ n = %u (0110 = 6)\n", m ^ n);   // 按位异或 / Bitwise XOR
    printf("  ~m = %u\n", ~m);                    // 按位取反 / Bitwise NOT
    printf("  m << 1 = %u (11000 = 24)\n", m << 1);  // 左移 / Left shift
    printf("  m >> 1 = %u (0110 = 6)\n", m >> 1);    // 右移 / Right shift
    
    // Java对比 / Java comparison:
    // Java还有>>>无符号右移运算符 / Java also has >>> unsigned right shift operator
    printf("\n");
    
    // 5. 赋值运算符 / Assignment Operators
    printf("5. 赋值运算符 / Assignment Operators:\n");
    int c = 5;
    printf("  初始值 / Initial value: c = %d\n", c);
    c += 3;   // 等同于 c = c + 3 / Equivalent to c = c + 3
    printf("  c += 3: c = %d\n", c);
    c -= 2;   // c = c - 2
    printf("  c -= 2: c = %d\n", c);
    c *= 2;   // c = c * 2
    printf("  c *= 2: c = %d\n", c);
    c /= 3;   // c = c / 3
    printf("  c /= 3: c = %d\n", c);
    c %= 3;   // c = c % 3
    printf("  c %%= 3: c = %d\n", c);
    
    // 位赋值运算符 / Bitwise assignment operators
    c = 12;
    c &= 10;  // c = c & 10
    printf("  c &= 10: c = %d\n", c);
    printf("\n");
    
    // 6. 自增/自减运算符 / Increment/Decrement Operators
    printf("6. 自增/自减运算符 / Increment/Decrement Operators:\n");
    int d = 5;
    printf("  d = %d\n", d);
    printf("  ++d = %d (先自增再使用 / pre-increment)\n", ++d);  // d变成6，返回6 / d becomes 6, returns 6
    printf("  d++ = %d (先使用再自增 / post-increment)\n", d++); // 返回6，d变成7 / returns 6, d becomes 7
    printf("  现在 / Now: d = %d\n", d);
    printf("  --d = %d (先自减再使用 / pre-decrement)\n", --d);  // d变成6，返回6 / d becomes 6, returns 6
    printf("  d-- = %d (先使用再自减 / post-decrement)\n", d--); // 返回6，d变成5 / returns 6, d becomes 5
    printf("  现在 / Now: d = %d\n", d);
    printf("\n");
    
    // 7. 条件运算符（三元运算符）/ Conditional Operator (Ternary Operator)
    printf("7. 条件运算符（三元运算符）/ Conditional Operator:\n");
    int e = 10, f = 20;
    int max = (e > f) ? e : f;  // 如果e>f，返回e，否则返回f / If e>f, return e, else return f
    printf("  max(%d, %d) = %d\n", e, f, max);
    
    // 可以嵌套使用 / Can be nested
    int g = 15;
    int result = (e > f) ? e : ((f > g) ? f : g);
    printf("  max(%d, %d, %d) = %d (使用嵌套三元运算符 / using nested ternary)\n", e, f, g, result);
    printf("\n");
    
    // 8. 逗号运算符 / Comma Operator
    printf("8. 逗号运算符 / Comma Operator:\n");
    int h = (5, 10, 15);  // 从左到右求值，返回最后一个值 / Evaluate left to right, return last value
    printf("  h = (5, 10, 15): h = %d\n", h);
    
    // 常用于for循环 / Commonly used in for loops
    printf("  在for循环中使用 / Used in for loop:\n  ");
    for (int i2 = 0, j = 10; i2 < 5; i2++, j--) {  // 同时更新i和j / Update both i and j
        printf("(%d,%d) ", i2, j);
    }
    printf("\n\n");
    
    // 9. sizeof运算符 / sizeof Operator
    printf("9. sizeof运算符 / sizeof Operator:\n");
    printf("  sizeof(int) = %zu bytes\n", sizeof(int));
    printf("  sizeof(char) = %zu bytes\n", sizeof(char));
    printf("  sizeof(double) = %zu bytes\n", sizeof(double));
    printf("  sizeof(a) = %zu bytes\n", sizeof(a));
    int arr[10];
    printf("  sizeof(arr) = %zu bytes (数组总大小 / total array size)\n", sizeof(arr));
    printf("  数组元素个数 / Array element count = %zu\n", sizeof(arr) / sizeof(arr[0]));
    
    // Java对比 / Java comparison:
    // Java没有sizeof运算符 / Java doesn't have sizeof operator
    // Java使用array.length获取数组长度 / Java uses array.length to get array length
    printf("\n");
    
    // 10. 指针运算符 / Pointer Operators
    printf("10. 指针运算符 / Pointer Operators:\n");
    int val = 100;
    int *ptr = &val;  // &: 取地址运算符 / Address-of operator
    printf("  val = %d\n", val);
    printf("  &val = %p (val的地址 / address of val)\n", (void*)&val);
    printf("  ptr = %p (指向val / pointing to val)\n", (void*)ptr);
    printf("  *ptr = %d (解引用，获取ptr指向的值 / dereference, get value pointed by ptr)\n", *ptr);
    
    // Java对比 / Java comparison:
    // Java没有指针运算符和取地址运算符 / Java doesn't have pointer and address-of operators
    // Java的对象引用类似指针，但不能直接操作 / Java's object references are similar to pointers but can't be directly manipulated
    printf("\n");
    
    // 11. 运算符优先级示例 / Operator Precedence Example
    printf("11. 运算符优先级 / Operator Precedence:\n");
    int result1 = 2 + 3 * 4;        // 先乘后加 / Multiplication before addition
    int result2 = (2 + 3) * 4;      // 括号优先 / Parentheses first
    printf("  2 + 3 * 4 = %d (先乘后加 / * before +)\n", result1);
    printf("  (2 + 3) * 4 = %d (括号优先 / parentheses first)\n", result2);
    
    bool result3 = 5 > 3 && 2 < 4;  // 关系运算符优先于逻辑运算符 / Relational before logical
    printf("  5 > 3 && 2 < 4 = %d (关系运算符先执行 / relational operators first)\n", result3);
    printf("\n");
    
    printf("学习要点 / Key Points:\n");
    printf("1. C的运算符与Java大部分相同 / Most C operators are the same as Java\n");
    printf("2. 注意整数除法会截断小数部分 / Integer division truncates decimal part\n");
    printf("3. 位运算符在C中更常用 / Bitwise operators are more commonly used in C\n");
    printf("4. C有指针运算符（& 和 *），Java没有 / C has pointer operators (& and *), Java doesn't\n");
    printf("5. sizeof是编译时运算符，返回类型或变量的字节数 / sizeof is compile-time operator, returns bytes\n");
    printf("6. 理解运算符优先级很重要，使用括号可以明确优先级 / Understanding precedence is important, use parentheses for clarity\n");
    
    return 0;
}
