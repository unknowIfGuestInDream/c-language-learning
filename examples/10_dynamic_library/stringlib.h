#ifndef STRINGLIB_H
#define STRINGLIB_H

/**
 * 字符串库头文件 / String Library Header
 * 
 * 这是动态库的头文件，声明了库提供的函数
 * This is the header file for the dynamic library, declaring the functions provided by the library
 */

// 反转字符串 / Reverse string
void reverse_string(char *str);

// 转换为大写 / Convert to uppercase
void to_uppercase(char *str);

// 转换为小写 / Convert to lowercase
void to_lowercase(char *str);

// 统计单词数 / Count words
int count_words(const char *str);

// 删除空白字符 / Remove whitespace
void trim(char *str);

// 检查是否为回文 / Check if palindrome
int is_palindrome(const char *str);

#endif // STRINGLIB_H
