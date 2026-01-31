# C语言循环 / Loops in C

## 概述 / Overview

本示例演示C语言中的循环结构，包括for、while、do-while循环，以及break和continue控制语句的使用。

This example demonstrates loop structures in C, including for, while, do-while loops, and the use of break and continue control statements.

## 关键概念 / Key Concepts

### 1. for循环 / for Loop
- 语法：`for (初始化; 条件; 更新)` / Syntax: `for (init; condition; update)`
- 适用于已知迭代次数的情况 / Best for known iteration count
- 支持多变量初始化和更新 / Supports multiple variable init and update

### 2. while循环 / while Loop
- 语法：`while (条件)` / Syntax: `while (condition)`
- 先检查条件再执行 / Checks condition before executing
- 适用于未知迭代次数的情况 / Best for unknown iteration count

### 3. do-while循环 / do-while Loop
- 语法：`do { } while (条件);` / Syntax: `do { } while (condition);`
- 至少执行一次 / Executes at least once
- 先执行再检查条件 / Executes first, then checks condition

### 4. break语句 / break Statement
- 立即退出当前循环 / Immediately exits current loop
- 只影响最内层循环 / Only affects innermost loop

### 5. continue语句 / continue Statement
- 跳过当前迭代，继续下一次 / Skips current iteration, continues to next
- 只影响最内层循环 / Only affects innermost loop

### 6. 嵌套循环 / Nested Loops
- 循环内部包含另一个循环 / Loop inside another loop
- 常用于多维数据处理 / Common for multi-dimensional data

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| for循环语法 / for loop syntax | ✅ 相同 / Same | ✅ 相同 / Same |
| while循环 / while loop | ✅ 相同 / Same | ✅ 相同 / Same |
| do-while循环 / do-while loop | ✅ 相同 / Same | ✅ 相同 / Same |
| for-each循环 / for-each loop | ❌ 无 / None | ✅ 有 / Yes |
| break/continue | ✅ 相同 / Same | ✅ 相同 / Same |
| 标签break / labeled break | ❌ 无 / None | ✅ 有 / Yes |
| for中声明变量 / var in for | C99+ | ✅ 始终支持 / Always |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./loops

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **循环选择**：已知次数用for，未知次数用while，至少一次用do-while
   **Loop Selection**: Known count: for, unknown: while, at least once: do-while

2. **无限循环**：`while(1)`或`for(;;)`创建无限循环，需要break退出
   **Infinite Loops**: Use `while(1)` or `for(;;)`, need break to exit

3. **循环效率**：避免在循环条件中进行复杂计算
   **Loop Efficiency**: Avoid complex calculations in loop conditions

4. **嵌套深度**：一般不超过3层嵌套，过深考虑重构
   **Nesting Depth**: Generally no more than 3 levels, consider refactoring if deeper

## 常见陷阱 / Common Pitfalls

1. 忘记更新循环变量导致无限循环 / Forgetting to update loop variable causing infinite loop
2. off-by-one错误（多一次或少一次迭代）/ Off-by-one errors (one too many or few iterations)
3. 在循环体内修改循环变量导致意外行为 / Modifying loop variable inside body causing unexpected behavior
4. break只退出最内层循环 / break only exits innermost loop

## 实用示例 / Practical Examples

本示例包含以下实用算法：
This example includes the following practical algorithms:

- 计算1到100的和 / Sum from 1 to 100
- 阶乘计算 / Factorial calculation
- 斐波那契数列 / Fibonacci sequence
- 数组最大值查找 / Finding maximum in array
- 图案打印 / Pattern printing
