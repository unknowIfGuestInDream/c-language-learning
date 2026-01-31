#ifndef MATHLIB_H
#define MATHLIB_H

/**
 * 数学库头文件 / Math Library Header
 * 
 * 这是静态库的头文件，声明了库提供的函数
 * This is the header file for the static library, declaring the functions provided by the library
 */

// 加法 / Addition
int add(int a, int b);

// 减法 / Subtraction
int subtract(int a, int b);

// 乘法 / Multiplication
int multiply(int a, int b);

// 除法 / Division (返回商，余数通过指针返回 / Returns quotient, remainder via pointer)
int divide(int a, int b, int *remainder);

// 计算阶乘 / Calculate factorial
long long factorial(int n);

// 判断是否为质数 / Check if prime number
int is_prime(int n);

#endif // MATHLIB_H
