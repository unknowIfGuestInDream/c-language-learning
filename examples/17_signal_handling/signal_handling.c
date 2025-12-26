/**
 * C语言信号处理
 * Signal Handling in C
 * 
 * 本示例演示C语言的信号处理机制，包括signal.h的使用
 * This example demonstrates C signal handling mechanisms using signal.h
 * 
 * 注意：信号处理在不同操作系统上可能有差异
 * Note: Signal handling may vary across different operating systems
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

// 全局变量用于演示 / Global variable for demonstration
volatile sig_atomic_t signal_received = 0;

// 函数声明 / Function declarations
void demonstrate_signal_basics();
void demonstrate_common_signals();
void demonstrate_signal_handler();
void demonstrate_signal_ignore();
void demonstrate_alarm_signal();

// 信号处理函数 / Signal handler functions
void sigint_handler(int sig) {
    // 只能在信号处理函数中使用异步信号安全的函数
    // Only async-signal-safe functions can be used in signal handlers
    signal_received = sig;
    // 注意：printf不是异步信号安全的，这里仅作演示
    // Note: printf is not async-signal-safe, used here for demo only
    const char msg[] = "\n  收到SIGINT信号 / Received SIGINT signal\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

void sigterm_handler(int sig) {
    signal_received = sig;
    const char msg[] = "\n  收到SIGTERM信号 / Received SIGTERM signal\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

void sigalrm_handler(int sig) {
    (void)sig;  // 避免未使用参数警告 / Avoid unused parameter warning
    const char msg[] = "  闹钟信号触发! / Alarm signal triggered!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

void sigusr1_handler(int sig) {
    (void)sig;
    const char msg[] = "  收到用户自定义信号1 / Received user signal 1\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

int main() {
    printf("=== C语言信号处理 / Signal Handling in C ===\n\n");
    
    // 1. 信号基础 / Signal basics
    printf("1. 信号基础 / Signal Basics:\n");
    demonstrate_signal_basics();
    
    // 2. 常见信号 / Common signals
    printf("2. 常见信号 / Common Signals:\n");
    demonstrate_common_signals();
    
    // 3. 信号处理函数 / Signal handlers
    printf("3. 信号处理函数 / Signal Handlers:\n");
    demonstrate_signal_handler();
    
    // 4. 忽略信号 / Ignoring signals
    printf("4. 忽略信号 / Ignoring Signals:\n");
    demonstrate_signal_ignore();
    
    // 5. 闹钟信号 / Alarm signal
    printf("5. 闹钟信号 / Alarm Signal:\n");
    demonstrate_alarm_signal();
    
    // 6. 信号处理最佳实践 / Signal handling best practices
    printf("6. 信号处理最佳实践 / Signal Handling Best Practices:\n");
    printf("  ✓ 信号处理函数应尽量简短 / Keep signal handlers short\n");
    printf("  ✓ 只使用异步信号安全的函数 / Use only async-signal-safe functions\n");
    printf("  ✓ 使用volatile sig_atomic_t类型 / Use volatile sig_atomic_t type\n");
    printf("  ✓ 避免在处理函数中分配内存 / Avoid memory allocation in handlers\n");
    printf("  ✓ 考虑使用sigaction代替signal / Consider sigaction over signal\n");
    printf("  ✓ 小心处理可重入性问题 / Be careful with reentrancy issues\n");
    printf("\n");
    
    // 总结 / Summary
    printf("=== 总结 / Summary ===\n");
    printf("信号处理要点 / Signal Handling Key Points:\n");
    printf("  - 信号是软件中断 / Signals are software interrupts\n");
    printf("  - 可以捕获、忽略或使用默认处理 / Can catch, ignore, or use default\n");
    printf("  - SIGKILL和SIGSTOP不能被捕获 / SIGKILL and SIGSTOP cannot be caught\n");
    printf("  - 处理函数应是异步信号安全的 / Handlers should be async-signal-safe\n\n");
    
    printf("与Java的对比 / Comparison with Java:\n");
    printf("  - Java使用关闭钩子(shutdown hooks) / Java uses shutdown hooks\n");
    printf("  - C可以直接处理底层信号 / C handles low-level signals directly\n");
    printf("  - Java的信号处理受JVM限制 / Java signal handling limited by JVM\n");
    printf("  - C的信号更接近操作系统 / C signals closer to OS level\n");
    
    return 0;
}

void demonstrate_signal_basics() {
    printf("  信号是什么 / What are signals:\n");
    printf("    - 信号是异步通知机制 / Signals are asynchronous notifications\n");
    printf("    - 由操作系统发送给进程 / Sent by OS to processes\n");
    printf("    - 用于进程间通信 / Used for inter-process communication\n");
    printf("    - 可以被程序捕获和处理 / Can be caught and handled by programs\n\n");
    
    printf("  信号的来源 / Signal sources:\n");
    printf("    - 硬件异常（如除零）/ Hardware exceptions (e.g., divide by zero)\n");
    printf("    - 用户输入（如Ctrl+C）/ User input (e.g., Ctrl+C)\n");
    printf("    - 进程间通信 / Inter-process communication\n");
    printf("    - 系统调用（如alarm）/ System calls (e.g., alarm)\n\n");
    
    printf("  signal()函数原型 / signal() function prototype:\n");
    printf("    void (*signal(int sig, void (*handler)(int)))(int);\n");
    printf("    或者使用typedef更清晰 / Or clearer with typedef:\n");
    printf("    typedef void (*sighandler_t)(int);\n");
    printf("    sighandler_t signal(int sig, sighandler_t handler);\n\n");
}

void demonstrate_common_signals() {
    printf("  POSIX标准信号 / POSIX Standard Signals:\n\n");
    
    printf("  ┌─────────┬────────┬─────────────────────────────────────────┐\n");
    printf("  │ 信号    │ 值     │ 描述 / Description                      │\n");
    printf("  │ Signal  │ Value  │                                         │\n");
    printf("  ├─────────┼────────┼─────────────────────────────────────────┤\n");
    printf("  │ SIGINT  │ %d     │ 中断（Ctrl+C）/ Interrupt              │\n", SIGINT);
    printf("  │ SIGTERM │ %d    │ 终止请求 / Termination request          │\n", SIGTERM);
    printf("  │ SIGKILL │ %d     │ 强制终止（不可捕获）/ Kill (uncatchable)│\n", SIGKILL);
    printf("  │ SIGSTOP │ %d    │ 停止进程（不可捕获）/ Stop (uncatchable)│\n", SIGSTOP);
    printf("  │ SIGALRM │ %d    │ 闹钟超时 / Alarm timeout                │\n", SIGALRM);
    printf("  │ SIGUSR1 │ %d    │ 用户自定义1 / User-defined 1           │\n", SIGUSR1);
    printf("  │ SIGUSR2 │ %d    │ 用户自定义2 / User-defined 2           │\n", SIGUSR2);
    printf("  │ SIGCHLD │ %d    │ 子进程状态改变 / Child status changed   │\n", SIGCHLD);
    printf("  │ SIGPIPE │ %d    │ 管道破裂 / Broken pipe                  │\n", SIGPIPE);
    printf("  │ SIGSEGV │ %d    │ 段错误 / Segmentation fault             │\n", SIGSEGV);
    printf("  └─────────┴────────┴─────────────────────────────────────────┘\n\n");
    
    printf("  信号的默认行为 / Default signal behavior:\n");
    printf("    - 终止进程 / Terminate process\n");
    printf("    - 终止并产生core dump / Terminate and core dump\n");
    printf("    - 忽略 / Ignore\n");
    printf("    - 停止进程 / Stop process\n\n");
}

void demonstrate_signal_handler() {
    printf("  设置信号处理函数 / Setting signal handlers:\n\n");
    
    // 保存原来的处理函数 / Save original handler
    void (*old_handler)(int);
    
    printf("  注册SIGINT处理函数 / Register SIGINT handler:\n");
    printf("    signal(SIGINT, sigint_handler);\n\n");
    
    old_handler = signal(SIGINT, sigint_handler);
    if (old_handler == SIG_ERR) {
        perror("    signal失败 / signal failed");
    } else {
        printf("    处理函数已注册 / Handler registered\n");
    }
    
    // 发送信号给自己测试 / Send signal to self for testing
    printf("\n  向自己发送信号测试 / Sending signal to self for testing:\n");
    printf("    raise(SIGINT);\n");
    raise(SIGINT);
    
    printf("\n  信号处理完成，继续执行 / Signal handled, execution continues\n");
    
    // 恢复默认处理函数 / Restore default handler
    signal(SIGINT, SIG_DFL);
    printf("  已恢复默认处理函数 / Default handler restored\n\n");
    
    // 特殊处理函数值 / Special handler values
    printf("  特殊处理函数值 / Special handler values:\n");
    printf("    SIG_DFL - 默认处理 / Default handling\n");
    printf("    SIG_IGN - 忽略信号 / Ignore signal\n");
    printf("    SIG_ERR - 错误返回值 / Error return value\n\n");
}

void demonstrate_signal_ignore() {
    printf("  忽略信号 / Ignoring signals:\n");
    printf("    signal(SIGPIPE, SIG_IGN);  // 忽略管道破裂信号\n\n");
    
    // 忽略SIGUSR1 / Ignore SIGUSR1
    signal(SIGUSR1, SIG_IGN);
    printf("  SIGUSR1已被忽略 / SIGUSR1 is now ignored\n");
    
    // 发送被忽略的信号 / Send ignored signal
    printf("  发送SIGUSR1（被忽略）/ Sending SIGUSR1 (ignored):\n");
    raise(SIGUSR1);
    printf("  信号被忽略，无事发生 / Signal ignored, nothing happened\n\n");
    
    // 恢复处理函数 / Restore handler
    signal(SIGUSR1, sigusr1_handler);
    printf("  恢复SIGUSR1处理函数后发送 / Sending after restoring handler:\n");
    raise(SIGUSR1);
    printf("\n");
    
    // 不可忽略的信号 / Signals that cannot be ignored
    printf("  不可忽略/捕获的信号 / Signals that cannot be ignored/caught:\n");
    printf("    SIGKILL (9)  - 强制终止 / Force kill\n");
    printf("    SIGSTOP (19) - 强制停止 / Force stop\n\n");
}

void demonstrate_alarm_signal() {
    printf("  alarm()函数 / alarm() function:\n");
    printf("    unsigned int alarm(unsigned int seconds);\n");
    printf("    在指定秒数后发送SIGALRM信号 / Sends SIGALRM after specified seconds\n\n");
    
    // 设置SIGALRM处理函数 / Set SIGALRM handler
    signal(SIGALRM, sigalrm_handler);
    
    printf("  设置1秒后的闹钟 / Setting 1 second alarm:\n");
    printf("    alarm(1);\n");
    
    unsigned int remaining = alarm(1);
    printf("  之前的闹钟剩余时间: %u秒 / Previous alarm remaining: %u seconds\n\n", remaining, remaining);
    
    printf("  等待闹钟信号... / Waiting for alarm signal...\n");
    sleep(2);  // 等待闹钟触发 / Wait for alarm
    
    printf("\n  取消闹钟 / Cancel alarm:\n");
    printf("    alarm(0);  // 参数为0表示取消 / 0 means cancel\n\n");
    alarm(0);
    
    // 恢复默认处理 / Restore default handling
    signal(SIGALRM, SIG_DFL);
}
