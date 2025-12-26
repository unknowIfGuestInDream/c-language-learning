/**
 * 字符串工具头文件 / String Utility Header
 * 
 * 提供常用的字符串操作函数
 * Provides common string operation functions
 */

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <stddef.h>   // 用于 size_t / For size_t
#include <stdbool.h>  // 用于 bool / For bool

// =====================================================================
// 宏定义 / Macro Definitions
// =====================================================================

// 默认缓冲区大小 / Default buffer size
#define STR_BUFFER_SIZE 256

// =====================================================================
// 函数声明 / Function Declarations
// =====================================================================

/**
 * 去除字符串首尾空白字符 / Trim leading and trailing whitespace
 * @param str 原字符串 / Original string
 * @param result 结果缓冲区 / Result buffer
 * @param result_size 缓冲区大小 / Buffer size
 * @return 成功返回结果指针，失败返回NULL / Returns result pointer on success, NULL on failure
 */
char* str_trim(const char *str, char *result, size_t result_size);

/**
 * 将字符串转为大写 / Convert string to uppercase
 * @param str 原字符串 / Original string
 * @param result 结果缓冲区 / Result buffer
 * @param result_size 缓冲区大小 / Buffer size
 * @return 成功返回结果指针，失败返回NULL / Returns result pointer on success, NULL on failure
 */
char* str_to_upper(const char *str, char *result, size_t result_size);

/**
 * 将字符串转为小写 / Convert string to lowercase
 * @param str 原字符串 / Original string
 * @param result 结果缓冲区 / Result buffer
 * @param result_size 缓冲区大小 / Buffer size
 * @return 成功返回结果指针，失败返回NULL / Returns result pointer on success, NULL on failure
 */
char* str_to_lower(const char *str, char *result, size_t result_size);

/**
 * 检查字符串是否以指定前缀开头 / Check if string starts with prefix
 * @param str 原字符串 / Original string
 * @param prefix 前缀 / Prefix
 * @return true如果以prefix开头 / true if starts with prefix
 */
bool str_starts_with(const char *str, const char *prefix);

/**
 * 检查字符串是否以指定后缀结尾 / Check if string ends with suffix
 * @param str 原字符串 / Original string
 * @param suffix 后缀 / Suffix
 * @return true如果以suffix结尾 / true if ends with suffix
 */
bool str_ends_with(const char *str, const char *suffix);

/**
 * 统计字符在字符串中出现的次数 / Count character occurrences in string
 * @param str 字符串 / String
 * @param ch 要统计的字符 / Character to count
 * @return 出现次数 / Number of occurrences
 */
size_t str_count_char(const char *str, char ch);

/**
 * 反转字符串 / Reverse string
 * @param str 原字符串 / Original string
 * @param result 结果缓冲区 / Result buffer
 * @param result_size 缓冲区大小 / Buffer size
 * @return 成功返回结果指针，失败返回NULL / Returns result pointer on success, NULL on failure
 */
char* str_reverse(const char *str, char *result, size_t result_size);

/**
 * 检查字符串是否只包含数字 / Check if string contains only digits
 * @param str 字符串 / String
 * @return true如果只包含数字 / true if contains only digits
 */
bool str_is_numeric(const char *str);

/**
 * 检查字符串是否只包含字母 / Check if string contains only letters
 * @param str 字符串 / String
 * @return true如果只包含字母 / true if contains only letters
 */
bool str_is_alpha(const char *str);

#endif // STRING_UTILS_H
