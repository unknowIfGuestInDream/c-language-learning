#include <stdio.h>
#include <string.h>
#include "stringlib.h"

/**
 * 动态库使用示例 / Dynamic Library Usage Example
 * 
 * 本程序演示如何使用动态库
 * This program demonstrates how to use a dynamic library
 */

int main() {
    printf("=== C语言动态库示例 / C Dynamic Library Example ===\n\n");
    
    // 1. 字符串反转 / String reversal
    printf("1. 字符串反转 / String Reversal:\n");
    char str1[100] = "Hello World";
    printf("  原始 / Original: %s\n", str1);
    reverse_string(str1);
    printf("  反转 / Reversed: %s\n", str1);
    printf("\n");
    
    // 2. 大小写转换 / Case conversion
    printf("2. 大小写转换 / Case Conversion:\n");
    char str2[100] = "Hello World";
    printf("  原始 / Original: %s\n", str2);
    
    to_uppercase(str2);
    printf("  大写 / Uppercase: %s\n", str2);
    
    to_lowercase(str2);
    printf("  小写 / Lowercase: %s\n", str2);
    printf("\n");
    
    // 3. 单词计数 / Word count
    printf("3. 单词计数 / Word Count:\n");
    char *sentences[] = {
        "Hello World",
        "The quick brown fox jumps over the lazy dog",
        "C programming is fun",
        "One",
        ""
    };
    
    for (int i = 0; i < 5; i++) {
        printf("  \"%s\" -> %d 个单词 / words\n", 
               sentences[i], count_words(sentences[i]));
    }
    printf("\n");
    
    // 4. 删除空白 / Trim whitespace
    printf("4. 删除空白字符 / Trim Whitespace:\n");
    char str3[100] = "   Hello World   ";
    printf("  原始 / Original: \"%s\"\n", str3);
    trim(str3);
    printf("  处理后 / After trim: \"%s\"\n", str3);
    printf("\n");
    
    // 5. 回文检查 / Palindrome check
    printf("5. 回文检查 / Palindrome Check:\n");
    char *test_strings[] = {
        "racecar",
        "A man a plan a canal Panama",
        "hello",
        "Madam",
        "12321"
    };
    
    for (int i = 0; i < 5; i++) {
        // 创建副本用于测试（因为检查时会忽略大小写）
        // Create copy for testing (since check ignores case)
        char test[100];
        strcpy(test, test_strings[i]);
        
        // 移除空格进行回文测试
        // Remove spaces for palindrome test
        char no_space[100];
        int j = 0;
        for (int k = 0; test[k]; k++) {
            if (test[k] != ' ') {
                no_space[j++] = test[k];
            }
        }
        no_space[j] = '\0';
        
        int result = is_palindrome(no_space);
        printf("  \"%s\" -> %s\n", test_strings[i], 
               result ? "是回文 / Is palindrome" : "不是回文 / Not palindrome");
    }
    printf("\n");
    
    // 使用说明 / Usage instructions
    printf("=== 动态库说明 / Dynamic Library Instructions ===\n");
    printf("动态库的创建和使用步骤 / Steps to create and use dynamic library:\n\n");
    
    printf("1. 编译源文件为位置无关代码 / Compile source as position-independent code:\n");
    printf("   gcc -c -fPIC stringlib.c -o stringlib.o\n");
    printf("   (-fPIC = Position Independent Code，动态库必需)\n\n");
    
    printf("2. 创建动态库 / Create dynamic library:\n");
    printf("   gcc -shared -o libstringlib.so stringlib.o\n");
    printf("   (-shared = 创建共享库 / create shared library)\n\n");
    
    printf("3. 编译主程序并链接动态库 / Compile main program with dynamic library:\n");
    printf("   gcc main.c -L. -lstringlib -o main\n");
    printf("   (-L. = 在当前目录查找库 / look for libraries in current directory)\n");
    printf("   (-lstringlib = 链接libstringlib.so / link with libstringlib.so)\n\n");
    
    printf("4. 运行时设置库路径 / Set library path at runtime:\n");
    printf("   Linux: export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH\n");
    printf("   macOS: export DYLD_LIBRARY_PATH=.:$DYLD_LIBRARY_PATH\n");
    printf("   或使用 / Or use: ./main (如果在当前目录 / if in current directory)\n\n");
    
    printf("动态库特点 / Dynamic Library Characteristics:\n");
    printf("  ✓ 运行时加载 / Loaded at runtime\n");
    printf("  ✓ 可执行文件较小 / Smaller executable size\n");
    printf("  ✓ 多个程序可共享同一库 / Multiple programs can share the same library\n");
    printf("  ✓ 更新库不需重新编译程序 / Library updates don't require program recompilation\n");
    printf("  ✓ 运行时需要库文件 / Requires library file at runtime\n\n");
    
    printf("文件扩展名 / File Extensions:\n");
    printf("  Linux: .so (Shared Object)\n");
    printf("  macOS: .dylib (Dynamic Library)\n");
    printf("  Windows: .dll (Dynamic Link Library)\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C动态库类似Java的本地库（JNI）/ C dynamic libraries similar to Java native libraries (JNI)\n");
    printf("  - C在运行时加载，Java也在运行时加载 / Both load at runtime\n");
    printf("  - C需要设置库路径，Java使用java.library.path / C needs library path, Java uses java.library.path\n");
    printf("  - C的.so文件平台相关，Java的.jar文件跨平台 / C .so is platform-specific, Java .jar is cross-platform\n");
    
    return 0;
}
