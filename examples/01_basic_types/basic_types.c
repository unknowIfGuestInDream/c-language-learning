#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

/**
 * C语言基本类型示例
 * Basic Types in C
 * 
 * 本示例展示C语言的所有基本数据类型及其特性
 * This example demonstrates all basic data types in C and their properties
 */

int main() {
    printf("=== C语言基本类型 / C Basic Types ===\n\n");
    
    // 1. 整数类型 / Integer Types
    printf("1. 整数类型 / Integer Types:\n");
    
    // char: 1字节，通常用于字符，但也是最小的整数类型
    // char: 1 byte, typically used for characters, but also the smallest integer type
    char c = 'A';
    printf("  char c = 'A': %c (ASCII: %d)\n", c, c);
    printf("  char 范围 / Range: %d to %d\n", CHAR_MIN, CHAR_MAX);
    
    // short: 短整型，至少16位
    // short: short integer, at least 16 bits
    short s = 32000;
    printf("  short s = %d\n", s);
    printf("  short 范围 / Range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    
    // int: 整型，通常32位
    // int: integer, typically 32 bits
    int i = 2147483647;
    printf("  int i = %d\n", i);
    printf("  int 范围 / Range: %d to %d\n", INT_MIN, INT_MAX);
    
    // long: 长整型，至少32位
    // long: long integer, at least 32 bits
    long l = 2147483647L;
    printf("  long l = %ld\n", l);
    printf("  long 范围 / Range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    
    // long long: 长长整型，至少64位
    // long long: long long integer, at least 64 bits
    long long ll = 9223372036854775807LL;
    printf("  long long ll = %lld\n", ll);
    printf("  long long 范围 / Range: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    
    printf("\n");
    
    // 2. 无符号整数类型 / Unsigned Integer Types
    printf("2. 无符号整数类型 / Unsigned Integer Types:\n");
    
    unsigned char uc = 255;
    printf("  unsigned char uc = %u\n", uc);
    printf("  unsigned char 范围 / Range: 0 to %u\n", UCHAR_MAX);
    
    unsigned int ui = 4294967295U;
    printf("  unsigned int ui = %u\n", ui);
    printf("  unsigned int 范围 / Range: 0 to %u\n", UINT_MAX);
    
    unsigned long ul = 4294967295UL;
    printf("  unsigned long ul = %lu\n", ul);
    printf("  unsigned long 范围 / Range: 0 to %lu\n", ULONG_MAX);
    
    printf("\n");
    
    // 3. 浮点类型 / Floating Point Types
    printf("3. 浮点类型 / Floating Point Types:\n");
    
    // float: 单精度浮点数，通常32位
    // float: single precision floating point, typically 32 bits
    float f = 3.14159f;
    printf("  float f = %.5f\n", f);
    printf("  float 精度 / Precision: %d 位小数 / decimal digits\n", FLT_DIG);
    
    // double: 双精度浮点数，通常64位
    // double: double precision floating point, typically 64 bits
    double d = 3.141592653589793;
    printf("  double d = %.15f\n", d);
    printf("  double 精度 / Precision: %d 位小数 / decimal digits\n", DBL_DIG);
    
    printf("\n");
    
    // 4. 布尔类型 / Boolean Type (C99)
    printf("4. 布尔类型 / Boolean Type (C99 及以后 / and later):\n");
    
    bool b1 = true;
    bool b2 = false;
    printf("  bool b1 = true: %d\n", b1);
    printf("  bool b2 = false: %d\n", b2);
    printf("  注意 / Note: true=1, false=0\n");
    
    printf("\n");
    
    // 5. 固定宽度整数类型 / Fixed Width Integer Types (C99)
    printf("5. 固定宽度整数类型 / Fixed Width Integer Types (C99):\n");
    
    int8_t i8 = 127;
    int16_t i16 = 32767;
    int32_t i32 = 2147483647;
    int64_t i64 = 9223372036854775807LL;
    
    printf("  int8_t  (8位有符号 / 8-bit signed): %d\n", i8);
    printf("  int16_t (16位有符号 / 16-bit signed): %d\n", i16);
    printf("  int32_t (32位有符号 / 32-bit signed): %d\n", i32);
    printf("  int64_t (64位有符号 / 64-bit signed): %lld\n", i64);
    
    uint8_t ui8 = 255;
    uint16_t ui16 = 65535;
    uint32_t ui32 = 4294967295U;
    uint64_t ui64 = 18446744073709551615ULL;
    
    printf("  uint8_t  (8位无符号 / 8-bit unsigned): %u\n", ui8);
    printf("  uint16_t (16位无符号 / 16-bit unsigned): %u\n", ui16);
    printf("  uint32_t (32位无符号 / 32-bit unsigned): %u\n", ui32);
    printf("  uint64_t (64位无符号 / 64-bit unsigned): %llu\n", ui64);
    
    printf("\n");
    
    // 6. 类型大小 / Type Sizes
    printf("6. 类型大小 / Type Sizes (本系统 / on this system):\n");
    printf("  sizeof(char) = %zu 字节 / bytes\n", sizeof(char));
    printf("  sizeof(short) = %zu 字节 / bytes\n", sizeof(short));
    printf("  sizeof(int) = %zu 字节 / bytes\n", sizeof(int));
    printf("  sizeof(long) = %zu 字节 / bytes\n", sizeof(long));
    printf("  sizeof(long long) = %zu 字节 / bytes\n", sizeof(long long));
    printf("  sizeof(float) = %zu 字节 / bytes\n", sizeof(float));
    printf("  sizeof(double) = %zu 字节 / bytes\n", sizeof(double));
    printf("  sizeof(bool) = %zu 字节 / bytes\n", sizeof(bool));
    
    return 0;
}
