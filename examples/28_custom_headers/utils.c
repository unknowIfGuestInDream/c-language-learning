/**
 * 通用工具实现文件 / General Utility Implementation
 * 
 * 头文件中声明的函数的实现
 * Implementation of functions declared in header file
 */

#include "utils.h"      // 包含对应的头文件 / Include corresponding header
#include <string.h>     // 用于 strlen / For strlen
#include <stdio.h>      // 用于 snprintf / For snprintf

// =====================================================================
// 静态变量 / Static Variables
// =====================================================================
// 使用static限制变量作用域到本文件
// Use static to limit variable scope to this file

static char version_string[32] = {0};

// =====================================================================
// 函数实现 / Function Implementations
// =====================================================================

// 获取版本字符串 / Get version string
const char* utils_get_version(void) {
    if (version_string[0] == '\0') {
        snprintf(version_string, sizeof(version_string), "%d.%d.%d",
                 UTILS_VERSION_MAJOR, UTILS_VERSION_MINOR, UTILS_VERSION_PATCH);
    }
    return version_string;
}

// 计算整数数组的和 / Calculate sum of integer array
long utils_array_sum(const int *arr, size_t size) {
    if (arr == NULL || size == 0) {
        return 0;
    }
    
    long sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// 计算整数数组的平均值 / Calculate average of integer array
double utils_array_average(const int *arr, size_t size) {
    if (arr == NULL || size == 0) {
        return 0.0;
    }
    
    return (double)utils_array_sum(arr, size) / (double)size;
}

// 查找数组中的最大值 / Find maximum value in array
utils_status_t utils_array_max(const int *arr, size_t size, int *result) {
    if (arr == NULL || result == NULL) {
        return UTILS_ERROR_NULL;
    }
    if (size == 0) {
        return UTILS_ERROR_RANGE;
    }
    
    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    *result = max;
    return UTILS_SUCCESS;
}

// 查找数组中的最小值 / Find minimum value in array
utils_status_t utils_array_min(const int *arr, size_t size, int *result) {
    if (arr == NULL || result == NULL) {
        return UTILS_ERROR_NULL;
    }
    if (size == 0) {
        return UTILS_ERROR_RANGE;
    }
    
    int min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    *result = min;
    return UTILS_SUCCESS;
}

// 反转数组 / Reverse array
void utils_array_reverse(int *arr, size_t size) {
    if (arr == NULL || size <= 1) {
        return;
    }
    
    for (size_t i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// 检查字符串是否为空或NULL / Check if string is empty or NULL
bool utils_string_is_empty(const char *str) {
    return (str == NULL || str[0] == '\0');
}

// 获取状态码的描述信息 / Get status code description
const char* utils_status_message(utils_status_t status) {
    switch (status) {
        case UTILS_SUCCESS:
            return "成功 / Success";
        case UTILS_ERROR_NULL:
            return "空指针错误 / Null pointer error";
        case UTILS_ERROR_RANGE:
            return "范围错误 / Range error";
        case UTILS_ERROR_MEMORY:
            return "内存错误 / Memory error";
        case UTILS_ERROR_INVALID:
            return "无效参数 / Invalid parameter";
        default:
            return "未知错误 / Unknown error";
    }
}
