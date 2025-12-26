#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * C语言字符串操作示例
 * String Operations in C
 * 
 * C语言的字符串是以'\0'结尾的字符数组
 * C strings are character arrays terminated with '\0'
 */

int main() {
    printf("=== C语言字符串操作 / String Operations in C ===\n\n");
    
    // 1. 字符串声明和初始化 / String Declaration and Initialization
    printf("1. 字符串声明和初始化 / String Declaration and Initialization:\n");
    
    // 方法1：字符数组 / Method 1: Character array
    char str1[] = "Hello";
    printf("  char str1[] = \"Hello\": %s\n", str1);
    
    // 方法2：字符指针 / Method 2: Character pointer
    char *str2 = "World";
    printf("  char *str2 = \"World\": %s\n", str2);
    
    // 方法3：显式字符数组 / Method 3: Explicit character array
    char str3[] = {'C', ' ', 'L', 'a', 'n', 'g', '\0'};
    printf("  char str3[] = {'C', ' ', 'L', 'a', 'n', 'g', '\\0'}: %s\n", str3);
    
    // 字符串末尾的'\0'非常重要 / The '\0' at the end is very important
    printf("  注意 / Note: 字符串必须以'\\0'结尾 / Strings must end with '\\0'\n");
    printf("\n");
    
    // 2. 字符串长度 / String Length
    printf("2. 字符串长度 / String Length:\n");
    char text[] = "Hello, World!";
    printf("  text = \"%s\"\n", text);
    printf("  strlen(text) = %zu (不包括'\\0' / excluding '\\0')\n", strlen(text));
    printf("  sizeof(text) = %zu (包括'\\0' / including '\\0')\n", sizeof(text));
    printf("\n");
    
    // 3. 字符串复制 / String Copy
    printf("3. 字符串复制 / String Copy:\n");
    char src[] = "Source String";
    char dest[50];
    
    // strcpy: 复制整个字符串 / strcpy: Copy entire string
    strcpy(dest, src);
    printf("  strcpy(dest, \"%s\"): %s\n", src, dest);
    
    // strncpy: 复制指定长度 / strncpy: Copy specified length
    char dest2[50] = {0};
    strncpy(dest2, src, 6);
    printf("  strncpy(dest2, \"%s\", 6): %s\n", src, dest2);
    printf("\n");
    
    // 4. 字符串连接 / String Concatenation
    printf("4. 字符串连接 / String Concatenation:\n");
    char greeting[50] = "Hello";
    char name[] = " World";
    
    // strcat: 连接字符串 / strcat: Concatenate strings
    strcat(greeting, name);
    printf("  strcat(\"Hello\", \" World\"): %s\n", greeting);
    
    // strncat: 连接指定长度 / strncat: Concatenate specified length
    char greeting2[50] = "Hello";
    strncat(greeting2, " C Programming", 2);
    printf("  strncat(\"Hello\", \" C Programming\", 2): %s\n", greeting2);
    printf("\n");
    
    // 5. 字符串比较 / String Comparison
    printf("5. 字符串比较 / String Comparison:\n");
    char str_a[] = "Apple";
    char str_b[] = "Banana";
    char str_c[] = "Apple";
    
    printf("  strcmp(\"%s\", \"%s\") = %d (< 0 表示 str_a < str_b)\n", 
           str_a, str_b, strcmp(str_a, str_b));
    printf("  strcmp(\"%s\", \"%s\") = %d (> 0 表示 str_b > str_a)\n", 
           str_b, str_a, strcmp(str_b, str_a));
    printf("  strcmp(\"%s\", \"%s\") = %d (== 0 表示相等)\n", 
           str_a, str_c, strcmp(str_a, str_c));
    
    // strncmp: 比较前n个字符 / strncmp: Compare first n characters
    printf("  strncmp(\"%s\", \"%s\", 3) = %d\n", 
           str_a, str_b, strncmp(str_a, str_b, 3));
    printf("\n");
    
    // 6. 字符串查找 / String Search
    printf("6. 字符串查找 / String Search:\n");
    char sentence[] = "The quick brown fox jumps over the lazy dog";
    
    // strchr: 查找字符 / strchr: Find character
    char *ptr = strchr(sentence, 'q');
    if (ptr) {
        printf("  strchr(\"%s\", 'q'): 找到在位置 / Found at position %ld\n", 
               sentence, ptr - sentence);
    }
    
    // strstr: 查找子字符串 / strstr: Find substring
    char *ptr2 = strstr(sentence, "fox");
    if (ptr2) {
        printf("  strstr(\"%s\", \"fox\"): 找到在位置 / Found at position %ld\n", 
               sentence, ptr2 - sentence);
    }
    printf("\n");
    
    // 7. 字符串分割 / String Tokenization
    printf("7. 字符串分割 / String Tokenization:\n");
    char csv[] = "apple,banana,orange,grape";
    printf("  原始字符串 / Original: %s\n", csv);
    printf("  分割结果 / Split result:\n");
    
    // 注意：strtok会修改原字符串 / Note: strtok modifies the original string
    char csv_copy[50];
    strcpy(csv_copy, csv);
    
    char *token = strtok(csv_copy, ",");
    int index = 0;
    while (token != NULL) {
        printf("    [%d]: %s\n", index++, token);
        token = strtok(NULL, ",");
    }
    printf("\n");
    
    // 8. 字符串转数字 / String to Number
    printf("8. 字符串转数字 / String to Number:\n");
    char num_str1[] = "12345";
    char num_str2[] = "3.14159";
    
    int num1 = atoi(num_str1);
    double num2 = atof(num_str2);
    
    printf("  atoi(\"%s\") = %d\n", num_str1, num1);
    printf("  atof(\"%s\") = %.5f\n", num_str2, num2);
    printf("\n");
    
    // 9. 数字转字符串 / Number to String
    printf("9. 数字转字符串 / Number to String:\n");
    char buffer[50];
    int value = 42;
    double pi = 3.14159;
    
    sprintf(buffer, "整数 / Integer: %d", value);
    printf("  sprintf: %s\n", buffer);
    
    sprintf(buffer, "浮点数 / Float: %.2f", pi);
    printf("  sprintf: %s\n", buffer);
    printf("\n");
    
    // 10. 字符串大小写转换 / String Case Conversion
    printf("10. 字符串大小写转换 / String Case Conversion:\n");
    char mixed[] = "Hello World";
    printf("  原始 / Original: %s\n", mixed);
    
    // 转大写 / To uppercase
    char upper[50];
    strcpy(upper, mixed);
    for (int i = 0; upper[i]; i++) {
        upper[i] = toupper(upper[i]);
    }
    printf("  大写 / Uppercase: %s\n", upper);
    
    // 转小写 / To lowercase
    char lower[50];
    strcpy(lower, mixed);
    for (int i = 0; lower[i]; i++) {
        lower[i] = tolower(lower[i]);
    }
    printf("  小写 / Lowercase: %s\n", lower);
    printf("\n");
    
    // 11. 动态字符串 / Dynamic String
    printf("11. 动态字符串 / Dynamic String:\n");
    char *dynamic_str = (char*)malloc(20 * sizeof(char));
    strcpy(dynamic_str, "Dynamic String");
    printf("  动态字符串 / Dynamic string: %s\n", dynamic_str);
    
    // 重新分配 / Reallocate
    dynamic_str = (char*)realloc(dynamic_str, 50 * sizeof(char));
    strcat(dynamic_str, " - Extended");
    printf("  扩展后 / After extension: %s\n", dynamic_str);
    
    free(dynamic_str);  // 释放内存 / Free memory
    printf("\n");
    
    // 12. 字符串格式化 / String Formatting
    printf("12. 字符串格式化 / String Formatting:\n");
    char formatted[100];
    int age = 25;
    char person_name[] = "Alice";
    sprintf(formatted, "%s is %d years old", person_name, age);
    printf("  sprintf: %s\n", formatted);
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("C字符串常用函数 / Common C String Functions:\n");
    printf("  strlen()  - 获取长度 / Get length\n");
    printf("  strcpy()  - 复制字符串 / Copy string\n");
    printf("  strcat()  - 连接字符串 / Concatenate string\n");
    printf("  strcmp()  - 比较字符串 / Compare strings\n");
    printf("  strchr()  - 查找字符 / Find character\n");
    printf("  strstr()  - 查找子串 / Find substring\n");
    printf("  strtok()  - 分割字符串 / Tokenize string\n");
    printf("  sprintf() - 格式化字符串 / Format string\n");
    printf("  atoi()    - 字符串转整数 / String to integer\n");
    printf("  atof()    - 字符串转浮点 / String to float\n");
    printf("\n");
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C字符串是字符数组，Java String是对象\n");
    printf("  - C strings are character arrays, Java String is an object\n");
    printf("  - C字符串可变，Java String不可变（用StringBuilder）\n");
    printf("  - C strings are mutable, Java String is immutable (use StringBuilder)\n");
    printf("  - C需要手动管理内存，Java自动管理\n");
    printf("  - C requires manual memory management, Java manages automatically\n");
    
    return 0;
}
