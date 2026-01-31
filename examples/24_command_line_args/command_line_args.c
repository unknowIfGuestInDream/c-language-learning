/**
 * C语言命令行参数处理
 * Command Line Arguments in C
 * 
 * 本示例详细演示argc和argv的使用方法
 * This example demonstrates detailed usage of argc and argv
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 函数声明 / Function declarations
void demonstrate_argc_argv(int argc, char *argv[]);
void demonstrate_argv_memory_layout(int argc, char *argv[]);
void demonstrate_argument_parsing();
void demonstrate_option_patterns();

// 简单的选项解析函数 / Simple option parsing function
int parse_int_option(const char *str) {
    return atoi(str);
}

int main(int argc, char *argv[]) {
    printf("=== C语言命令行参数处理 / Command Line Arguments in C ===\n\n");
    
    // 1. argc和argv基础 / argc and argv basics
    printf("1. argc和argv基础 / argc and argv Basics:\n");
    demonstrate_argc_argv(argc, argv);
    
    // 2. argv的内存布局 / Memory layout of argv
    printf("2. argv的内存布局 / Memory Layout of argv:\n");
    demonstrate_argv_memory_layout(argc, argv);
    
    // 3. 参数解析 / Argument parsing
    printf("3. 参数解析技巧 / Argument Parsing Techniques:\n");
    demonstrate_argument_parsing();
    
    // 4. 选项模式 / Option patterns
    printf("4. 常见选项处理模式 / Common Option Handling Patterns:\n");
    demonstrate_option_patterns();
    
    // 5. 解析当前命令行参数 / Parse current command line arguments
    printf("5. 解析当前命令行参数 / Parse Current Arguments:\n");
    if (argc > 1) {
        printf("  接收到的参数 / Received arguments:\n");
        for (int i = 1; i < argc; i++) {
            printf("    参数 %d / Arg %d: \"%s\"\n", i, i, argv[i]);
            
            // 检查是否是选项 / Check if it's an option
            if (argv[i][0] == '-') {
                if (argv[i][1] == '-') {
                    printf("      -> 长选项 / Long option\n");
                } else {
                    printf("      -> 短选项 / Short option\n");
                }
            } else {
                printf("      -> 位置参数 / Positional argument\n");
            }
        }
    } else {
        printf("  没有提供参数 / No arguments provided\n");
        printf("  尝试: ./command_line_args -v --help file.txt 123\n");
        printf("  Try: ./command_line_args -v --help file.txt 123\n");
    }
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("命令行参数要点 / Command Line Argument Key Points:\n");
    printf("  - argc: 参数数量（包含程序名）/ Argument count (includes program name)\n");
    printf("  - argv[0]: 程序名 / Program name\n");
    printf("  - argv[1..n-1]: 实际参数 / Actual arguments\n");
    printf("  - argv[argc]: NULL（保证）/ NULL (guaranteed)\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java的args不包含程序名 / Java args doesn't include program name\n");
    printf("  - Java: public static void main(String[] args)\n");
    printf("  - C: int main(int argc, char *argv[])\n");
    printf("  - Java的args从实际参数开始 / Java args starts from actual arguments\n");
    printf("  - C的argv[0]是程序名 / C argv[0] is program name\n");
    
    return 0;
}

void demonstrate_argc_argv(int argc, char *argv[]) {
    printf("  main函数签名 / main Function Signatures:\n");
    printf("    int main(void)                    // 无参数 / No arguments\n");
    printf("    int main(int argc, char *argv[])  // 标准形式 / Standard form\n");
    printf("    int main(int argc, char **argv)   // 等价形式 / Equivalent form\n\n");
    
    printf("  argc和argv的含义 / Meaning of argc and argv:\n");
    printf("    argc - 参数数量 / Argument Count\n");
    printf("    argv - 参数向量（字符串数组）/ Argument Vector (string array)\n\n");
    
    printf("  当前执行信息 / Current Execution Info:\n");
    printf("    argc = %d\n", argc);
    printf("    argv[0] (程序名 / Program name) = \"%s\"\n", argv[0]);
    
    for (int i = 1; i < argc; i++) {
        printf("    argv[%d] = \"%s\"\n", i, argv[i]);
    }
    printf("    argv[%d] = %s (始终为NULL / Always NULL)\n", argc, argv[argc] == NULL ? "NULL" : "ERROR");
    printf("\n");
}

void demonstrate_argv_memory_layout(int argc, char *argv[]) {
    printf("  argv的结构 / Structure of argv:\n");
    printf("    argv是指向字符指针的指针 / argv is pointer to pointer to char\n\n");
    
    printf("    ┌─────────┐     ┌────────────────────┐\n");
    printf("    │ argv    │ --> │ argv[0]            │ --> \"%s\"\n", argv[0]);
    if (argc > 1) {
        printf("    └─────────┘     ├────────────────────┤\n");
        printf("                    │ argv[1]            │ --> \"%s\"\n", argv[1]);
    } else {
        printf("    └─────────┘     ├────────────────────┤\n");
        printf("                    │ argv[1]            │ --> (无参数 / No arg)\n");
    }
    printf("                    ├────────────────────┤\n");
    printf("                    │ ...                │\n");
    printf("                    ├────────────────────┤\n");
    printf("                    │ argv[argc] = NULL  │\n");
    printf("                    └────────────────────┘\n\n");
    
    printf("  内存地址示例 / Memory Address Example:\n");
    printf("    argv的地址 / Address of argv: %p\n", (void*)argv);
    for (int i = 0; i <= argc && i < 4; i++) {  // 最多显示4个 / Show at most 4
        printf("    &argv[%d] = %p, argv[%d] = %p", 
               i, (void*)&argv[i], i, (void*)argv[i]);
        if (argv[i]) {
            printf(" -> \"%s\"", argv[i]);
        } else {
            printf(" -> NULL");
        }
        printf("\n");
    }
    printf("\n");
}

void demonstrate_argument_parsing() {
    printf("  字符串转数字 / String to Number Conversion:\n\n");
    
    // atoi / atol / atof
    printf("    简单转换（不推荐）/ Simple conversion (not recommended):\n");
    printf("      int n = atoi(\"123\");    // n = %d\n", atoi("123"));
    printf("      long l = atol(\"12345\"); // l = %ld\n", atol("12345"));
    printf("      double d = atof(\"3.14\"); // d = %f\n", atof("3.14"));
    printf("      问题：无法检测错误 / Problem: Cannot detect errors\n\n");
    
    // strtol / strtod - 更安全的方式 / Safer way
    printf("    安全转换（推荐）/ Safe conversion (recommended):\n");
    char *endptr;
    const char *num_str = "123abc";
    long val = strtol(num_str, &endptr, 10);
    printf("      char *str = \"123abc\";\n");
    printf("      long val = strtol(str, &endptr, 10);\n");
    printf("      val = %ld\n", val);
    printf("      *endptr = '%c' (指向第一个无效字符 / points to first invalid char)\n", *endptr);
    printf("\n");
    
    // 完整的错误检查示例 / Complete error checking example
    printf("    完整错误检查示例 / Complete error checking example:\n");
    printf("      long parse_long(const char *str) {\n");
    printf("          char *endptr;\n");
    printf("          errno = 0;\n");
    printf("          long val = strtol(str, &endptr, 10);\n");
    printf("          if (errno != 0) {\n");
    printf("              perror(\"strtol\");\n");
    printf("              return 0;\n");
    printf("          }\n");
    printf("          if (endptr == str) {\n");
    printf("              fprintf(stderr, \"No digits found\\n\");\n");
    printf("              return 0;\n");
    printf("          }\n");
    printf("          return val;\n");
    printf("      }\n\n");
}

void demonstrate_option_patterns() {
    printf("  常见命令行选项格式 / Common Command Line Option Formats:\n\n");
    
    printf("    1. 短选项 / Short options:\n");
    printf("       -h, -v, -f filename\n");
    printf("       -hvf filename (组合形式 / Combined form)\n\n");
    
    printf("    2. 长选项 / Long options:\n");
    printf("       --help, --version\n");
    printf("       --file=filename\n");
    printf("       --file filename\n\n");
    
    printf("    3. 位置参数 / Positional arguments:\n");
    printf("       program input.txt output.txt\n\n");
    
    // 手动解析示例 / Manual parsing example
    printf("  手动解析示例 / Manual Parsing Example:\n");
    printf("    for (int i = 1; i < argc; i++) {\n");
    printf("        if (strcmp(argv[i], \"-h\") == 0 ||\n");
    printf("            strcmp(argv[i], \"--help\") == 0) {\n");
    printf("            show_help();\n");
    printf("        } else if (strcmp(argv[i], \"-v\") == 0) {\n");
    printf("            verbose = 1;\n");
    printf("        } else if (strcmp(argv[i], \"-f\") == 0) {\n");
    printf("            if (i + 1 < argc) {\n");
    printf("                filename = argv[++i];\n");
    printf("            }\n");
    printf("        } else if (argv[i][0] != '-') {\n");
    printf("            // 位置参数 / Positional argument\n");
    printf("            input_file = argv[i];\n");
    printf("        }\n");
    printf("    }\n\n");
    
    // getopt简介 / getopt introduction
    printf("  使用getopt库 / Using getopt Library:\n");
    printf("    #include <getopt.h>\n\n");
    printf("    int opt;\n");
    printf("    while ((opt = getopt(argc, argv, \"hvf:\")) != -1) {\n");
    printf("        switch (opt) {\n");
    printf("            case 'h': show_help(); break;\n");
    printf("            case 'v': verbose = 1; break;\n");
    printf("            case 'f': filename = optarg; break;\n");
    printf("            case '?': show_usage(); break;\n");
    printf("        }\n");
    printf("    }\n");
    printf("    // optind是第一个非选项参数的索引\n");
    printf("    // optind is index of first non-option argument\n\n");
    
    // 长选项 / Long options
    printf("  getopt_long用于长选项 / getopt_long for long options:\n");
    printf("    static struct option long_options[] = {\n");
    printf("        {\"help\",    no_argument,       0, 'h'},\n");
    printf("        {\"verbose\", no_argument,       0, 'v'},\n");
    printf("        {\"file\",    required_argument, 0, 'f'},\n");
    printf("        {0, 0, 0, 0}\n");
    printf("    };\n\n");
}
