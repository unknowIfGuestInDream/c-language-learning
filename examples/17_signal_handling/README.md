# C语言信号处理 / Signal Handling in C

## 概述 / Overview

本示例演示C语言的信号处理机制，包括signal.h的使用。

This example demonstrates C signal handling mechanisms using signal.h.

## 关键概念 / Key Concepts

### 什么是信号 / What are Signals

信号是操作系统发送给进程的异步通知，用于通知进程发生了某个事件。

Signals are asynchronous notifications sent by the OS to processes to notify them of events.

### signal()函数 / signal() Function

```c
#include <signal.h>

void handler(int sig) {
    // 处理信号 / Handle signal
}

// 注册处理函数 / Register handler
signal(SIGINT, handler);

// 忽略信号 / Ignore signal
signal(SIGPIPE, SIG_IGN);

// 恢复默认处理 / Restore default handling
signal(SIGINT, SIG_DFL);
```

## 常见信号 / Common Signals

| 信号 / Signal | 值 / Value | 描述 / Description |
|--------------|------------|-------------------|
| SIGINT | 2 | 中断（Ctrl+C）/ Interrupt |
| SIGTERM | 15 | 终止请求 / Termination request |
| SIGKILL | 9 | 强制终止（不可捕获）/ Kill (uncatchable) |
| SIGALRM | 14 | 闹钟超时 / Alarm timeout |
| SIGSEGV | 11 | 段错误 / Segmentation fault |
| SIGUSR1 | 10 | 用户自定义信号1 / User-defined signal 1 |

## 信号处理函数注意事项 / Signal Handler Considerations

1. **保持简短** / Keep it short - 信号处理函数应尽可能简单
2. **异步安全** / Async-safety - 只使用异步信号安全的函数
3. **使用正确类型** / Use correct types - 使用`volatile sig_atomic_t`
4. **避免死锁** / Avoid deadlocks - 不要在处理函数中使用锁

### 异步信号安全函数示例 / Async-signal-safe Functions

- `write()` ✓
- `_exit()` ✓
- `signal()` ✓
- `printf()` ✗ (不安全 / Not safe)
- `malloc()` ✗ (不安全 / Not safe)

## 代码示例 / Code Examples

### 处理Ctrl+C / Handling Ctrl+C

```c
#include <signal.h>
#include <stdio.h>

volatile sig_atomic_t running = 1;

void handle_sigint(int sig) {
    (void)sig;
    running = 0;
}

int main() {
    signal(SIGINT, handle_sigint);
    
    printf("按Ctrl+C退出 / Press Ctrl+C to exit\n");
    while (running) {
        // 工作循环 / Work loop
    }
    printf("\n退出 / Exiting\n");
    return 0;
}
```

### 使用alarm() / Using alarm()

```c
#include <signal.h>
#include <unistd.h>

void alarm_handler(int sig) {
    (void)sig;
    write(1, "Timeout!\n", 9);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);  // 5秒后触发 / Trigger after 5 seconds
    pause();   // 等待信号 / Wait for signal
    return 0;
}
```

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 信号处理 / Signal Handling | signal() | Runtime.addShutdownHook() |
| 中断处理 / Interrupt Handling | SIGINT handler | Thread.interrupt() |
| 超时 / Timeout | alarm() + SIGALRM | Thread.sleep(), Timer |
| 进程终止 / Process Termination | SIGTERM, SIGKILL | System.exit() |

### Java关闭钩子示例 / Java Shutdown Hook Example

```java
// Java
Runtime.getRuntime().addShutdownHook(new Thread(() -> {
    System.out.println("Shutting down...");
}));
```

## 编译和运行 / Build and Run

```bash
make
./signal_handling
```

## 注意事项 / Notes

- SIGKILL和SIGSTOP不能被捕获或忽略
- 信号处理函数可能在任意时刻被调用
- 考虑使用sigaction()获得更精细的控制
