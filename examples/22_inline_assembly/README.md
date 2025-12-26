# C语言内联汇编 / Inline Assembly in C

## 概述 / Overview

本示例演示GCC内联汇编的基本用法。仅适用于x86/x86_64架构。

This example demonstrates basic GCC inline assembly usage. Only works on x86/x86_64.

## 关键概念 / Key Concepts

### 基本语法 / Basic Syntax

```c
asm("nop");              // 基本形式 / Basic form
__asm__("nop");          // 等价形式 / Equivalent form
asm volatile("nop");     // 防止优化 / Prevent optimization
```

### 扩展语法 / Extended Syntax

```c
asm [volatile] (
    "assembly template"
    : output operands     // 输出操作数
    : input operands      // 输入操作数
    : clobbered registers // 被修改的寄存器
);
```

## 操作数约束 / Operand Constraints

### 通用约束 / General Constraints

| 约束 / Constraint | 含义 / Meaning |
|------------------|----------------|
| `r` | 通用寄存器 / General register |
| `m` | 内存位置 / Memory location |
| `i` | 立即数 / Immediate |
| `g` | 通用 / General |

### x86特定约束 / x86-specific Constraints

| 约束 / Constraint | 寄存器 / Register |
|------------------|-------------------|
| `a` | eax/rax |
| `b` | ebx/rbx |
| `c` | ecx/rcx |
| `d` | edx/rdx |

### 修饰符 / Modifiers

| 修饰符 / Modifier | 含义 / Meaning |
|-----------------|----------------|
| `=` | 只写 / Write-only |
| `+` | 读写 / Read-write |
| `&` | 早期破坏 / Early clobber |

## 代码示例 / Code Examples

### 简单加法 / Simple Addition

```c
int value = 10;
asm("addl $1, %0" : "+r" (value));
// value现在是11 / value is now 11
```

### 两数相加 / Add Two Numbers

```c
int a = 10, b = 20, result;
asm("movl %1, %0\n\t"
    "addl %2, %0"
    : "=r" (result)
    : "r" (a), "r" (b)
);
```

### 获取CPU时间戳 / Get CPU Timestamp

```c
uint32_t lo, hi;
asm volatile("rdtsc" : "=a" (lo), "=d" (hi));
uint64_t timestamp = ((uint64_t)hi << 32) | lo;
```

### 交换两个变量 / Swap Variables

```c
int a = 100, b = 200;
asm("xchgl %0, %1" : "+r" (a), "+r" (b));
```

## Clobber列表 / Clobber List

```c
asm volatile("..."
    : output
    : input
    : "eax", "memory", "cc"  // Clobber list
);
```

| 值 / Value | 含义 / Meaning |
|-----------|----------------|
| `"memory"` | 修改内存 / Modifies memory |
| `"cc"` | 修改条件码 / Modifies condition codes |
| `"eax"` | 修改eax寄存器 / Modifies eax register |

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 内联汇编 / Inline Assembly | 支持 / Supported | 不支持 / Not supported |
| 低级优化 / Low-level Optimization | 直接 / Direct | JNI |
| CPU特殊指令 / Special Instructions | asm() | 无 / None |
| 可移植性 / Portability | 低 / Low | 高 / High |

## 注意事项 / Notes

- 内联汇编依赖于编译器和架构 / Inline assembly depends on compiler and architecture
- 使用volatile防止优化 / Use volatile to prevent optimization
- 注意寄存器保存和恢复 / Mind register saving and restoration
- 优先使用编译器内置函数 / Prefer compiler builtins when available

## 编译和运行 / Build and Run

```bash
make
./inline_assembly
```

## 最佳实践 / Best Practices

- 仅在必要时使用内联汇编 / Use inline assembly only when necessary
- 充分注释汇编代码 / Comment assembly code thoroughly
- 测试在目标平台上的行为 / Test behavior on target platform
- 考虑使用编译器内置函数 / Consider using compiler builtins
