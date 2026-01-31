/**
 * 通用工具头文件 / General Utility Header
 * 
 * 演示自定义头文件的基本结构和最佳实践
 * Demonstrates basic structure and best practices for custom header files
 */

#ifndef UTILS_H     // 头文件保护开始 / Include guard start
#define UTILS_H     // 防止重复包含 / Prevent multiple inclusion

// =====================================================================
// 头文件保护说明 / Include Guard Explanation
// =====================================================================
// #ifndef UTILS_H / #define UTILS_H / #endif 是头文件保护
// 确保头文件内容只被编译一次，即使被多次包含
// 
// #ifndef UTILS_H / #define UTILS_H / #endif are include guards
// Ensures header contents are only compiled once, even if included multiple times

// =====================================================================
// 包含其他头文件 / Include Other Headers
// =====================================================================
// 只包含此头文件必需的其他头文件
// Only include headers that are necessary for this header file

#include <stddef.h>   // 用于 size_t / For size_t
#include <stdbool.h>  // 用于 bool / For bool

// =====================================================================
// 宏定义 / Macro Definitions
// =====================================================================

// 数学常量 / Mathematical constants
#define UTILS_PI        3.14159265358979323846
#define UTILS_E         2.71828182845904523536

// 实用宏 / Utility macros
#define UTILS_MAX(a, b) ((a) > (b) ? (a) : (b))
#define UTILS_MIN(a, b) ((a) < (b) ? (a) : (b))
#define UTILS_ABS(x)    ((x) < 0 ? -(x) : (x))

// 数组长度宏 / Array length macro
#define UTILS_ARRAY_LEN(arr) (sizeof(arr) / sizeof((arr)[0]))

// 版本信息 / Version information
#define UTILS_VERSION_MAJOR 1
#define UTILS_VERSION_MINOR 0
#define UTILS_VERSION_PATCH 0

// =====================================================================
// 类型定义 / Type Definitions
// =====================================================================

// 使用typedef创建新类型名 / Create new type names using typedef
typedef unsigned char  byte_t;      // 字节类型 / Byte type
typedef unsigned int   uint_t;      // 无符号整数 / Unsigned integer
typedef unsigned long  ulong_t;     // 无符号长整数 / Unsigned long

// 状态码枚举 / Status code enumeration
typedef enum {
    UTILS_SUCCESS = 0,      // 成功 / Success
    UTILS_ERROR_NULL,       // 空指针错误 / Null pointer error
    UTILS_ERROR_RANGE,      // 范围错误 / Range error
    UTILS_ERROR_MEMORY,     // 内存错误 / Memory error
    UTILS_ERROR_INVALID     // 无效参数 / Invalid parameter
} utils_status_t;

// 结果结构体 / Result structure
typedef struct {
    int value;              // 结果值 / Result value
    utils_status_t status;  // 状态码 / Status code
    char message[64];       // 消息 / Message
} utils_result_t;

// =====================================================================
// 函数声明 / Function Declarations
// =====================================================================
// 头文件中只放声明，不放实现
// Only declarations in header, not implementations

/**
 * 获取版本字符串 / Get version string
 * @return 版本字符串 / Version string
 */
const char* utils_get_version(void);

/**
 * 计算整数数组的和 / Calculate sum of integer array
 * @param arr 数组指针 / Array pointer
 * @param size 数组大小 / Array size
 * @return 数组元素之和 / Sum of array elements
 */
long utils_array_sum(const int *arr, size_t size);

/**
 * 计算整数数组的平均值 / Calculate average of integer array
 * @param arr 数组指针 / Array pointer
 * @param size 数组大小 / Array size
 * @return 平均值 / Average value
 */
double utils_array_average(const int *arr, size_t size);

/**
 * 查找数组中的最大值 / Find maximum value in array
 * @param arr 数组指针 / Array pointer
 * @param size 数组大小 / Array size
 * @param result 结果指针 / Result pointer
 * @return 状态码 / Status code
 */
utils_status_t utils_array_max(const int *arr, size_t size, int *result);

/**
 * 查找数组中的最小值 / Find minimum value in array
 * @param arr 数组指针 / Array pointer
 * @param size 数组大小 / Array size
 * @param result 结果指针 / Result pointer
 * @return 状态码 / Status code
 */
utils_status_t utils_array_min(const int *arr, size_t size, int *result);

/**
 * 反转数组 / Reverse array
 * @param arr 数组指针 / Array pointer
 * @param size 数组大小 / Array size
 */
void utils_array_reverse(int *arr, size_t size);

/**
 * 检查字符串是否为空或NULL / Check if string is empty or NULL
 * @param str 字符串指针 / String pointer
 * @return true如果为空或NULL / true if empty or NULL
 */
bool utils_string_is_empty(const char *str);

/**
 * 获取状态码的描述信息 / Get status code description
 * @param status 状态码 / Status code
 * @return 描述字符串 / Description string
 */
const char* utils_status_message(utils_status_t status);

#endif // UTILS_H   // 头文件保护结束 / Include guard end
