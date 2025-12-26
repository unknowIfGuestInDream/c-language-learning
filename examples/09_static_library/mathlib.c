#include "mathlib.h"
#include <stddef.h>

/**
 * 数学库实现 / Math Library Implementation
 * 
 * 这是静态库的实现文件
 * This is the implementation file for the static library
 */

// 加法 / Addition
int add(int a, int b) {
    return a + b;
}

// 减法 / Subtraction
int subtract(int a, int b) {
    return a - b;
}

// 乘法 / Multiplication
int multiply(int a, int b) {
    return a * b;
}

// 除法 / Division
int divide(int a, int b, int *remainder) {
    if (b == 0) {
        return 0;  // 避免除以零 / Avoid division by zero
    }
    if (remainder != NULL) {
        *remainder = a % b;
    }
    return a / b;
}

// 计算阶乘 / Calculate factorial
long long factorial(int n) {
    if (n < 0) {
        return -1;  // 负数没有阶乘 / Negative numbers don't have factorial
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 判断是否为质数 / Check if prime number
int is_prime(int n) {
    if (n <= 1) {
        return 0;  // 不是质数 / Not prime
    }
    if (n == 2) {
        return 1;  // 2是质数 / 2 is prime
    }
    if (n % 2 == 0) {
        return 0;  // 偶数不是质数 / Even numbers are not prime
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;  // 找到因子，不是质数 / Found factor, not prime
        }
    }
    return 1;  // 是质数 / Is prime
}
