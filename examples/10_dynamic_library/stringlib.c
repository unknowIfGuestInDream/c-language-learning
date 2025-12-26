#include "stringlib.h"
#include <string.h>
#include <ctype.h>

/**
 * 字符串库实现 / String Library Implementation
 * 
 * 这是动态库的实现文件
 * This is the implementation file for the dynamic library
 */

// 反转字符串 / Reverse string
void reverse_string(char *str) {
    if (str == NULL) return;
    
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// 转换为大写 / Convert to uppercase
void to_uppercase(char *str) {
    if (str == NULL) return;
    
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// 转换为小写 / Convert to lowercase
void to_lowercase(char *str) {
    if (str == NULL) return;
    
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// 统计单词数 / Count words
int count_words(const char *str) {
    if (str == NULL) return 0;
    
    int count = 0;
    int in_word = 0;
    
    for (int i = 0; str[i]; i++) {
        if (isspace(str[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }
    
    return count;
}

// 删除前后空白字符 / Trim leading and trailing whitespace
void trim(char *str) {
    if (str == NULL) return;
    
    // 删除前导空白 / Remove leading whitespace
    int start = 0;
    while (str[start] && isspace(str[start])) {
        start++;
    }
    
    // 如果全是空白 / If all whitespace
    if (str[start] == '\0') {
        str[0] = '\0';
        return;
    }
    
    // 找到最后一个非空白字符 / Find last non-whitespace character
    int end = strlen(str) - 1;
    while (end >= start && isspace(str[end])) {
        end--;
    }
    
    // 移动字符串 / Shift string
    int len = end - start + 1;
    for (int i = 0; i < len; i++) {
        str[i] = str[start + i];
    }
    str[len] = '\0';
}

// 检查是否为回文 / Check if palindrome
int is_palindrome(const char *str) {
    if (str == NULL) return 0;
    
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - 1 - i])) {
            return 0;
        }
    }
    
    return 1;
}
