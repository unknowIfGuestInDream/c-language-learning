#include <stdio.h>

/**
 * C语言枚举类型
 * Enumeration Types in C
 * 
 * 本示例演示枚举类型的定义和使用
 * This example demonstrates the definition and use of enumeration types
 */

// 1. 基本枚举定义 / Basic enum definition
enum Weekday {
    MONDAY,      // 0
    TUESDAY,     // 1
    WEDNESDAY,   // 2
    THURSDAY,    // 3
    FRIDAY,      // 4
    SATURDAY,    // 5
    SUNDAY       // 6
};

// 2. 指定枚举值 / Enum with specified values
enum Status {
    SUCCESS = 0,
    ERROR = -1,
    WARNING = 1,
    INFO = 2
};

// 3. 使用typedef简化 / Using typedef for simplification
typedef enum {
    RED,
    GREEN,
    BLUE,
    YELLOW
} Color;

// 4. 枚举作为标志位 / Enum as flags
enum FilePermission {
    READ = 1,      // 0001
    WRITE = 2,     // 0010
    EXECUTE = 4,   // 0100
    DELETE = 8     // 1000
};

// 5. 月份枚举 / Month enumeration
typedef enum {
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
} Month;

int main() {
    printf("=== C语言枚举类型 / Enumeration Types in C ===\n\n");
    
    // 1. 基本使用 / Basic usage
    printf("1. 基本枚举 / Basic Enumeration:\n");
    enum Weekday today = WEDNESDAY;
    printf("  今天是 / Today is: %d (WEDNESDAY)\n", today);
    
    printf("  枚举值 / Enum values:\n");
    printf("    MONDAY = %d\n", MONDAY);
    printf("    TUESDAY = %d\n", TUESDAY);
    printf("    WEDNESDAY = %d\n", WEDNESDAY);
    printf("\n");
    
    // 2. 使用枚举作为switch / Using enum in switch
    printf("2. 在switch中使用枚举 / Using Enum in switch:\n");
    today = FRIDAY;
    
    switch (today) {
        case MONDAY:
            printf("  星期一：新的一周开始 / Monday: New week begins\n");
            break;
        case TUESDAY:
        case WEDNESDAY:
        case THURSDAY:
            printf("  工作日 / Weekday\n");
            break;
        case FRIDAY:
            printf("  星期五：周末快到了！/ Friday: Weekend is coming!\n");
            break;
        case SATURDAY:
        case SUNDAY:
            printf("  周末：休息时间 / Weekend: Rest time\n");
            break;
        default:
            printf("  无效的日期 / Invalid day\n");
            break;
    }
    printf("\n");
    
    // 3. 状态码枚举 / Status code enumeration
    printf("3. 状态码枚举 / Status Code Enumeration:\n");
    enum Status result = SUCCESS;
    
    printf("  状态码 / Status codes:\n");
    printf("    SUCCESS = %d\n", SUCCESS);
    printf("    ERROR = %d\n", ERROR);
    printf("    WARNING = %d\n", WARNING);
    printf("    INFO = %d\n", INFO);
    
    if (result == SUCCESS) {
        printf("  操作成功 / Operation successful\n");
    }
    printf("\n");
    
    // 4. 颜色枚举 / Color enumeration
    printf("4. 颜色枚举（使用typedef）/ Color Enum (with typedef):\n");
    Color favorite = BLUE;
    
    printf("  我最喜欢的颜色 / My favorite color: ");
    switch (favorite) {
        case RED:
            printf("红色 / Red\n");
            break;
        case GREEN:
            printf("绿色 / Green\n");
            break;
        case BLUE:
            printf("蓝色 / Blue\n");
            break;
        case YELLOW:
            printf("黄色 / Yellow\n");
            break;
    }
    printf("\n");
    
    // 5. 枚举作为标志位 / Enum as flags
    printf("5. 枚举作为标志位 / Enum as Flags:\n");
    int permissions = READ | WRITE;  // 组合权限 / Combined permissions
    
    printf("  权限 / Permissions: %d\n", permissions);
    printf("  检查权限 / Checking permissions:\n");
    
    if (permissions & READ) {
        printf("    有读权限 / Has READ permission\n");
    }
    if (permissions & WRITE) {
        printf("    有写权限 / Has WRITE permission\n");
    }
    if (permissions & EXECUTE) {
        printf("    有执行权限 / Has EXECUTE permission\n");
    } else {
        printf("    无执行权限 / No EXECUTE permission\n");
    }
    printf("\n");
    
    // 6. 月份枚举 / Month enumeration
    printf("6. 月份枚举 / Month Enumeration:\n");
    Month current_month = JUL;
    
    printf("  当前月份 / Current month: ");
    switch (current_month) {
        case JAN: printf("一月 / January\n"); break;
        case FEB: printf("二月 / February\n"); break;
        case MAR: printf("三月 / March\n"); break;
        case APR: printf("四月 / April\n"); break;
        case MAY: printf("五月 / May\n"); break;
        case JUN: printf("六月 / June\n"); break;
        case JUL: printf("七月 / July\n"); break;
        case AUG: printf("八月 / August\n"); break;
        case SEP: printf("九月 / September\n"); break;
        case OCT: printf("十月 / October\n"); break;
        case NOV: printf("十一月 / November\n"); break;
        case DEC: printf("十二月 / December\n"); break;
    }
    printf("  月份值 / Month value: %d\n", current_month);
    printf("\n");
    
    // 7. 枚举的大小 / Size of enum
    printf("7. 枚举的大小 / Size of Enum:\n");
    printf("  sizeof(enum Weekday) = %zu 字节 / bytes\n", sizeof(enum Weekday));
    printf("  sizeof(Color) = %zu 字节 / bytes\n", sizeof(Color));
    printf("  枚举本质上是整数类型 / Enums are essentially integer types\n");
    printf("\n");
    
    // 8. 枚举vs #define / Enum vs #define
    printf("8. 枚举 vs #define / Enum vs #define:\n");
    printf("  枚举的优点 / Advantages of Enum:\n");
    printf("    ✓ 类型安全 / Type safe\n");
    printf("    ✓ 自动编号 / Automatic numbering\n");
    printf("    ✓ 调试器可显示名称 / Debugger shows names\n");
    printf("    ✓ 作用域限定 / Scoped\n");
    printf("  #define的优点 / Advantages of #define:\n");
    printf("    ✓ 预处理器替换 / Preprocessor replacement\n");
    printf("    ✓ 可用于非整数 / Can be used for non-integers\n");
    printf("\n");
    
    // 9. 遍历枚举 / Iterating through enum
    printf("9. 遍历枚举 / Iterating Through Enum:\n");
    printf("  一周的所有天 / All days of the week:\n");
    for (enum Weekday day = MONDAY; day <= SUNDAY; day++) {
        printf("    Day %d\n", day);
    }
    printf("\n");
    
    // 10. 实际应用示例 / Practical application example
    printf("10. 实际应用：状态机 / Practical Application: State Machine:\n");
    
    typedef enum {
        STATE_IDLE,
        STATE_RUNNING,
        STATE_PAUSED,
        STATE_STOPPED
    } MachineState;
    
    MachineState state = STATE_IDLE;
    printf("  初始状态 / Initial state: IDLE\n");
    
    // 状态转换 / State transition
    state = STATE_RUNNING;
    printf("  状态变为 / State changed to: RUNNING\n");
    
    state = STATE_PAUSED;
    printf("  状态变为 / State changed to: PAUSED\n");
    
    state = STATE_STOPPED;
    printf("  状态变为 / State changed to: STOPPED\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("枚举的特点 / Enum Characteristics:\n");
    printf("  - 用于定义一组命名的整数常量 / Define a set of named integer constants\n");
    printf("  - 提高代码可读性 / Improve code readability\n");
    printf("  - 默认从0开始递增 / Default starts from 0 and increments\n");
    printf("  - 可以指定具体值 / Can specify specific values\n\n");
    
    printf("最佳实践 / Best Practices:\n");
    printf("  - 使用枚举代替魔数 / Use enum instead of magic numbers\n");
    printf("  - 枚举名使用大写 / Use uppercase for enum names\n");
    printf("  - 在switch中使用枚举 / Use enum in switch statements\n");
    printf("  - 位标志使用2的幂 / Use powers of 2 for bit flags\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - C枚举是整数，Java枚举是类 / C: integers, Java: classes\n");
    printf("  - C枚举可隐式转换为int / C: implicit int conversion\n");
    printf("  - Java枚举有方法和字段 / Java: has methods and fields\n");
    printf("  - C枚举更轻量但功能较少 / C: lighter but less features\n");
    
    return 0;
}
