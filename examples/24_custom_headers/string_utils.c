/**
 * 字符串工具实现文件 / String Utility Implementation
 * 
 * 字符串操作函数的实现
 * Implementation of string operation functions
 */

#include "string_utils.h"
#include <string.h>   // 用于 strlen, strcpy / For strlen, strcpy
#include <ctype.h>    // 用于 isspace, toupper, tolower / For isspace, toupper, tolower

// 去除字符串首尾空白字符 / Trim leading and trailing whitespace
char* str_trim(const char *str, char *result, size_t result_size) {
    if (str == NULL || result == NULL || result_size == 0) {
        return NULL;
    }
    
    // 跳过开头的空白 / Skip leading whitespace
    while (*str && isspace((unsigned char)*str)) {
        str++;
    }
    
    // 如果字符串全是空白 / If string is all whitespace
    if (*str == '\0') {
        result[0] = '\0';
        return result;
    }
    
    // 找到结尾非空白字符 / Find trailing non-whitespace
    const char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    
    // 计算长度并复制 / Calculate length and copy
    size_t len = (size_t)(end - str + 1);
    if (len >= result_size) {
        len = result_size - 1;
    }
    
    strncpy(result, str, len);
    result[len] = '\0';
    return result;
}

// 将字符串转为大写 / Convert string to uppercase
char* str_to_upper(const char *str, char *result, size_t result_size) {
    if (str == NULL || result == NULL || result_size == 0) {
        return NULL;
    }
    
    size_t i;
    for (i = 0; str[i] != '\0' && i < result_size - 1; i++) {
        result[i] = (char)toupper((unsigned char)str[i]);
    }
    result[i] = '\0';
    return result;
}

// 将字符串转为小写 / Convert string to lowercase
char* str_to_lower(const char *str, char *result, size_t result_size) {
    if (str == NULL || result == NULL || result_size == 0) {
        return NULL;
    }
    
    size_t i;
    for (i = 0; str[i] != '\0' && i < result_size - 1; i++) {
        result[i] = (char)tolower((unsigned char)str[i]);
    }
    result[i] = '\0';
    return result;
}

// 检查字符串是否以指定前缀开头 / Check if string starts with prefix
bool str_starts_with(const char *str, const char *prefix) {
    if (str == NULL || prefix == NULL) {
        return false;
    }
    
    size_t prefix_len = strlen(prefix);
    size_t str_len = strlen(str);
    
    if (prefix_len > str_len) {
        return false;
    }
    
    return strncmp(str, prefix, prefix_len) == 0;
}

// 检查字符串是否以指定后缀结尾 / Check if string ends with suffix
bool str_ends_with(const char *str, const char *suffix) {
    if (str == NULL || suffix == NULL) {
        return false;
    }
    
    size_t suffix_len = strlen(suffix);
    size_t str_len = strlen(str);
    
    if (suffix_len > str_len) {
        return false;
    }
    
    return strcmp(str + str_len - suffix_len, suffix) == 0;
}

// 统计字符在字符串中出现的次数 / Count character occurrences in string
size_t str_count_char(const char *str, char ch) {
    if (str == NULL) {
        return 0;
    }
    
    size_t count = 0;
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    return count;
}

// 反转字符串 / Reverse string
char* str_reverse(const char *str, char *result, size_t result_size) {
    if (str == NULL || result == NULL || result_size == 0) {
        return NULL;
    }
    
    size_t len = strlen(str);
    if (len >= result_size) {
        len = result_size - 1;
    }
    
    for (size_t i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

// 检查字符串是否只包含数字 / Check if string contains only digits
bool str_is_numeric(const char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }
    
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return false;
        }
        str++;
    }
    return true;
}

// 检查字符串是否只包含字母 / Check if string contains only letters
bool str_is_alpha(const char *str) {
    if (str == NULL || *str == '\0') {
        return false;
    }
    
    while (*str) {
        if (!isalpha((unsigned char)*str)) {
            return false;
        }
        str++;
    }
    return true;
}
