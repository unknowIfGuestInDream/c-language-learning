#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * C语言文件操作示例
 * File Operations in C
 * 
 * 本示例演示C语言的文件读写操作
 * This example demonstrates file I/O operations in C
 */

// 定义测试文件名 / Define test filenames
#define TEXT_FILE "test_text.txt"
#define BINARY_FILE "test_binary.dat"

// 用于二进制文件的结构体 / Struct for binary file
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

int main() {
    printf("=== C语言文件操作 / File Operations in C ===\n\n");
    
    // 1. 写入文本文件 / Write to text file
    printf("1. 写入文本文件 / Write to Text File:\n");
    FILE *file = fopen(TEXT_FILE, "w");  // "w" = 写模式 / write mode
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    fprintf(file, "第一行文本 / First line of text\n");
    fprintf(file, "第二行文本 / Second line of text\n");
    fprintf(file, "数字 / Numbers: %d, %.2f\n", 42, 3.14);
    
    fclose(file);
    printf("  文本已写入 %s\n", TEXT_FILE);
    printf("\n");
    
    // 2. 读取文本文件 / Read from text file
    printf("2. 读取文本文件 / Read from Text File:\n");
    file = fopen(TEXT_FILE, "r");  // "r" = 读模式 / read mode
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    char line[256];
    printf("  文件内容 / File content:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("    %s", line);
    }
    
    fclose(file);
    printf("\n");
    
    // 3. 追加到文件 / Append to file
    printf("3. 追加到文件 / Append to File:\n");
    file = fopen(TEXT_FILE, "a");  // "a" = 追加模式 / append mode
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    fprintf(file, "追加的行 / Appended line\n");
    fclose(file);
    printf("  已追加到 %s\n", TEXT_FILE);
    
    // 再次读取显示 / Read again to show
    file = fopen(TEXT_FILE, "r");
    printf("  更新后的内容 / Updated content:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("    %s", line);
    }
    fclose(file);
    printf("\n");
    
    // 4. 逐字符读取 / Read character by character
    printf("4. 逐字符读取 / Read Character by Character:\n");
    file = fopen(TEXT_FILE, "r");
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    printf("  前50个字符 / First 50 characters: ");
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF && count < 50) {
        if (ch == '\n') {
            printf("\\n");
        } else {
            printf("%c", ch);
        }
        count++;
    }
    printf("...\n");
    fclose(file);
    printf("\n");
    
    // 5. 格式化读取 / Formatted reading
    printf("5. 格式化读取 / Formatted Reading:\n");
    file = fopen(TEXT_FILE, "w");
    fprintf(file, "张三 25 89.5\n");
    fprintf(file, "李四 23 92.0\n");
    fprintf(file, "王五 24 87.3\n");
    fclose(file);
    
    file = fopen(TEXT_FILE, "r");
    printf("  学生信息 / Student Info:\n");
    char name[50];
    int age;
    float score;
    
    while (fscanf(file, "%s %d %f", name, &age, &score) == 3) {
        printf("    姓名 / Name: %s, 年龄 / Age: %d, 分数 / Score: %.1f\n", 
               name, age, score);
    }
    fclose(file);
    printf("\n");
    
    // 6. 二进制文件写入 / Binary file writing
    printf("6. 二进制文件写入 / Binary File Writing:\n");
    Student students[3] = {
        {1, "张三 / Zhang San", 89.5},
        {2, "李四 / Li Si", 92.0},
        {3, "王五 / Wang Wu", 87.3}
    };
    
    file = fopen(BINARY_FILE, "wb");  // "wb" = 二进制写模式 / binary write mode
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    size_t written = fwrite(students, sizeof(Student), 3, file);
    printf("  写入了 %zu 个学生记录到 %s\n", written, BINARY_FILE);
    printf("  Wrote %zu student records to %s\n", written, BINARY_FILE);
    fclose(file);
    printf("\n");
    
    // 7. 二进制文件读取 / Binary file reading
    printf("7. 二进制文件读取 / Binary File Reading:\n");
    file = fopen(BINARY_FILE, "rb");  // "rb" = 二进制读模式 / binary read mode
    if (file == NULL) {
        printf("  错误：无法打开文件 / Error: Cannot open file\n");
        return 1;
    }
    
    Student read_students[3];
    size_t read_count = fread(read_students, sizeof(Student), 3, file);
    printf("  读取了 %zu 个学生记录 / Read %zu student records:\n", read_count);
    
    for (size_t i = 0; i < read_count; i++) {
        printf("    ID: %d, 姓名 / Name: %s, 分数 / Score: %.1f\n",
               read_students[i].id, read_students[i].name, read_students[i].score);
    }
    fclose(file);
    printf("\n");
    
    // 8. 文件定位 / File positioning
    printf("8. 文件定位 / File Positioning:\n");
    file = fopen(BINARY_FILE, "rb");
    
    // 读取第二个学生 / Read second student
    fseek(file, sizeof(Student), SEEK_SET);  // 从文件开始偏移 / Offset from start
    Student second_student;
    fread(&second_student, sizeof(Student), 1, file);
    printf("  第二个学生 / Second student: %s\n", second_student.name);
    
    // 获取当前位置 / Get current position
    long pos = ftell(file);
    printf("  当前文件位置 / Current file position: %ld 字节 / bytes\n", pos);
    
    // 移到文件末尾 / Move to end of file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    printf("  文件大小 / File size: %ld 字节 / bytes\n", file_size);
    
    // 回到开始 / Back to beginning
    rewind(file);
    printf("  已回到文件开始 / Rewound to beginning\n");
    
    fclose(file);
    printf("\n");
    
    // 9. 检查文件是否存在 / Check if file exists
    printf("9. 检查文件是否存在 / Check if File Exists:\n");
    FILE *test_file = fopen("nonexistent.txt", "r");
    if (test_file == NULL) {
        printf("  文件不存在 / File does not exist\n");
    } else {
        printf("  文件存在 / File exists\n");
        fclose(test_file);
    }
    printf("\n");
    
    // 10. 文件错误处理 / File error handling
    printf("10. 文件错误处理 / File Error Handling:\n");
    file = fopen(TEXT_FILE, "r");
    if (file == NULL) {
        perror("  fopen");
        return 1;
    }
    
    // 检查文件结束 / Check end of file
    fgetc(file);
    if (feof(file)) {
        printf("  已到达文件末尾 / Reached end of file\n");
    }
    
    // 检查错误 / Check for errors
    if (ferror(file)) {
        printf("  发生文件错误 / File error occurred\n");
    }
    
    fclose(file);
    printf("\n");
    
    // 清理：删除测试文件 / Cleanup: delete test files
    printf("清理测试文件 / Cleaning up test files...\n");
    remove(TEXT_FILE);
    remove(BINARY_FILE);
    printf("测试文件已删除 / Test files deleted\n\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("文件打开模式 / File Open Modes:\n");
    printf("  \"r\"  - 读取（文本）/ Read (text)\n");
    printf("  \"w\"  - 写入（文本，覆盖）/ Write (text, overwrite)\n");
    printf("  \"a\"  - 追加（文本）/ Append (text)\n");
    printf("  \"r+\" - 读写（文本）/ Read/Write (text)\n");
    printf("  \"rb\" - 读取（二进制）/ Read (binary)\n");
    printf("  \"wb\" - 写入（二进制）/ Write (binary)\n");
    printf("\n");
    printf("常用函数 / Common Functions:\n");
    printf("  fopen()   - 打开文件 / Open file\n");
    printf("  fclose()  - 关闭文件 / Close file\n");
    printf("  fprintf() - 格式化写入 / Formatted write\n");
    printf("  fscanf()  - 格式化读取 / Formatted read\n");
    printf("  fgets()   - 读取一行 / Read a line\n");
    printf("  fputs()   - 写入一行 / Write a line\n");
    printf("  fread()   - 二进制读取 / Binary read\n");
    printf("  fwrite()  - 二进制写入 / Binary write\n");
    printf("  fseek()   - 定位 / Seek\n");
    printf("  ftell()   - 获取位置 / Get position\n");
    printf("\n");
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C使用FILE指针，Java使用Stream对象\n");
    printf("  - C uses FILE pointer, Java uses Stream objects\n");
    printf("  - C需要手动关闭文件，Java有try-with-resources\n");
    printf("  - C needs manual file closing, Java has try-with-resources\n");
    printf("  - C的文本/二进制模式更明确\n");
    printf("  - C has more explicit text/binary modes\n");
    
    return 0;
}
