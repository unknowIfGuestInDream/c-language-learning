/*
 * C语言作用域和存储类 / C Scope and Storage Classes
 */

#include <stdio.h>

// 全局变量 / Global variable
int global_var = 100;

// extern声明（在其他文件定义）/ extern declaration
// extern int external_var;

// static全局变量（文件作用域）/ static global (file scope)
static int file_static = 200;

// 函数声明 / Function declarations
void demonstrate_auto(void);
void demonstrate_static(void);
void demonstrate_register(void);
void demonstrate_extern(void);

int main() {
    printf("=== C语言作用域和存储类 / C Scope and Storage Classes ===\n\n");
    
    // 1. 局部作用域 / Local Scope
    printf("1. 局部作用域 / Local Scope:\n");
    {
        int local_var = 10;  // 块作用域 / Block scope
        printf("  块内变量 / Inside block: %d\n", local_var);
    }
    // local_var在这里不可见 / local_var not visible here
    
    // 2. 全局作用域 / Global Scope
    printf("\n2. 全局作用域 / Global Scope:\n");
    printf("  全局变量 / Global variable: %d\n", global_var);
    global_var = 150;
    printf("  修改后 / After modification: %d\n", global_var);
    
    // 3. auto存储类（默认）/ auto storage class (default)
    printf("\n3. auto存储类 / auto Storage Class:\n");
    demonstrate_auto();
    demonstrate_auto();  // 值不保留 / Value not retained
    
    // 4. static存储类 / static storage class
    printf("\n4. static存储类 / static Storage Class:\n");
    demonstrate_static();
    demonstrate_static();  // 值保留 / Value retained
    demonstrate_static();
    
    // 5. register存储类 / register storage class
    printf("\n5. register存储类 / register Storage Class:\n");
    demonstrate_register();
    
    printf("\n学习要点 / Key Points:\n");
    printf("1. auto: 默认存储类，栈上分配，函数结束时销毁\n");
    printf("2. static: 保持值在整个程序运行期间\n");
    printf("3. extern: 声明外部变量，实际定义在其他文件\n");
    printf("4. register: 建议存储在寄存器，不能取地址\n");
    
    return 0;
}

void demonstrate_auto(void) {
    auto int count = 0;  // auto可以省略 / auto can be omitted
    count++;
    printf("  auto变量 / auto variable: %d\n", count);
}

void demonstrate_static(void) {
    static int count = 0;  // 初始化只执行一次 / Initialized only once
    count++;
    printf("  static变量 / static variable: %d\n", count);
}

void demonstrate_register(void) {
    register int i;  // 建议存储在寄存器 / Suggest register storage
    int sum = 0;
    for (i = 0; i < 10; i++) {
        sum += i;
    }
    printf("  计算结果 / Result: %d\n", sum);
    // printf("  地址: %p\n", &i);  // 错误：不能取register变量的地址 / Error: can't take address
}

void demonstrate_extern(void) {
    // extern声明使用其他文件的变量 / extern to use variable from other file
    printf("  extern用于跨文件共享变量\n");
}
