# C语言控制流 / Control Flow in C

## 概述 / Overview

本示例演示C语言中的条件语句，包括if、else、else if、switch和三元运算符的使用。

This example demonstrates conditional statements in C, including if, else, else if, switch, and ternary operators.

## 关键概念 / Key Concepts

### 1. if语句 / if Statement
- 最基本的条件判断 / Basic conditional check
- 条件为真（非零）时执行代码块 / Executes code block when condition is true (non-zero)

### 2. if-else语句 / if-else Statement
- 二选一的条件判断 / Two-way conditional branch
- 条件为真执行if块，否则执行else块 / Executes if block when true, else block otherwise

### 3. if-else if-else链 / if-else if-else Chain
- 多选一的条件判断 / Multi-way conditional branch
- 从上到下依次判断条件 / Conditions evaluated from top to bottom

### 4. 嵌套if语句 / Nested if Statements
- if语句内部包含另一个if语句 / if statement inside another if statement
- 应避免过深的嵌套 / Avoid deep nesting

### 5. switch语句 / switch Statement
- 基于整数或字符值的多分支选择 / Multi-way selection based on integer or character value
- 每个case需要break防止穿透 / Each case needs break to prevent fall-through
- default处理未匹配的情况 / default handles unmatched cases

### 6. 三元运算符 / Ternary Operator
- `条件 ? 值1 : 值2` 格式 / `condition ? value1 : value2` format
- 简洁的条件表达式 / Concise conditional expression

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| if-else语法 / if-else syntax | ✅ 相同 / Same | ✅ 相同 / Same |
| switch支持类型 / switch types | 整数/字符 / int/char | 整数/字符/字符串/枚举 / int/char/String/enum |
| 布尔类型 / Boolean type | C99前无 / None pre-C99 | ✅ boolean |
| 条件判断 / Condition check | 0为假，非0为真 / 0=false, non-0=true | 必须是boolean / Must be boolean |
| 三元运算符 / Ternary operator | ✅ 相同 / Same | ✅ 相同 / Same |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./control_flow

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **条件表达式**：C语言中0为假，任何非0值为真
   **Conditional Expressions**: In C, 0 is false, any non-zero value is true

2. **switch vs if-else**：离散值匹配用switch，范围判断用if-else
   **switch vs if-else**: Use switch for discrete values, if-else for ranges

3. **break的重要性**：switch中忘记break会导致case穿透
   **Importance of break**: Missing break in switch causes fall-through

4. **代码可读性**：复杂条件使用括号，避免深层嵌套
   **Code Readability**: Use parentheses for complex conditions, avoid deep nesting

## 常见陷阱 / Common Pitfalls

1. 在条件中使用`=`而不是`==` / Using `=` instead of `==` in conditions
2. 忘记switch中的break语句 / Forgetting break in switch statements
3. 嵌套过深导致代码难以维护 / Deep nesting making code hard to maintain
4. 忽略else分支的边界情况 / Ignoring edge cases in else branches
