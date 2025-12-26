# C语言运算符和表达式 / C Operators and Expressions

## 概述 / Overview

本示例演示C语言中的各种运算符，包括算术、关系、逻辑、位运算、赋值、自增/自减、条件运算符等。

This example demonstrates various operators in C, including arithmetic, relational, logical, bitwise, assignment, increment/decrement, and conditional operators.

## 关键概念 / Key Concepts

### 1. 算术运算符 / Arithmetic Operators
- `+, -, *, /, %` - 基本算术运算 / Basic arithmetic operations
- 注意整数除法会截断小数 / Integer division truncates decimals

### 2. 关系运算符 / Relational Operators
- `==, !=, >, <, >=, <=` - 比较运算符 / Comparison operators
- 返回0（false）或1（true）/ Returns 0 (false) or 1 (true)

### 3. 逻辑运算符 / Logical Operators
- `&&` (AND), `||` (OR), `!` (NOT)
- 支持短路求值 / Supports short-circuit evaluation

### 4. 位运算符 / Bitwise Operators
- `&, |, ^, ~, <<, >>` - 位级操作 / Bit-level operations
- 在C中比Java中更常用 / More commonly used in C than Java

### 5. 赋值运算符 / Assignment Operators
- `=, +=, -=, *=, /=, %=, &=, |=, ^=, <<=, >>=`
- 复合赋值运算符 / Compound assignment operators

### 6. 自增/自减 / Increment/Decrement
- `++, --` - 前缀和后缀形式 / Prefix and postfix forms
- 前缀：先改变再使用 / Prefix: change then use
- 后缀：先使用再改变 / Postfix: use then change

### 7. 其他运算符 / Other Operators
- `? :` - 三元条件运算符 / Ternary conditional operator
- `,` - 逗号运算符 / Comma operator
- `sizeof` - 获取类型或变量大小 / Get size of type or variable
- `&` - 取地址 / Address-of
- `*` - 解引用 / Dereference

## 与Java的对比 / Comparison with Java

| 特性 / Feature | C | Java |
|---------------|---|------|
| 基本运算符 / Basic operators | ✅ | ✅ |
| 位运算符 / Bitwise operators | ✅ 常用 / Common | ✅ 较少用 / Less common |
| 指针运算符 / Pointer operators | ✅ `&`, `*` | ❌ 无 / None |
| 无符号右移 / Unsigned right shift | ❌ 只有`>>` / Only `>>` | ✅ `>>>` |
| sizeof运算符 / sizeof operator | ✅ | ❌ 无 / None |
| 运算符优先级 / Precedence | 基本相同 / Mostly same | 基本相同 / Mostly same |

## 编译和运行 / Compilation and Execution

```bash
# 编译 / Compile
make

# 运行 / Run
./operators_expressions

# 清理 / Clean
make clean
```

## 学习要点 / Learning Points

1. **整数除法**：C和Java都会截断小数部分
   **Integer Division**: Both C and Java truncate decimal part

2. **位运算**：在C中更常用于底层操作和性能优化
   **Bitwise Operations**: More commonly used in C for low-level operations

3. **指针运算符**：C特有，Java没有直接的指针操作
   **Pointer Operators**: C-specific, Java has no direct pointer manipulation

4. **sizeof**：编译时求值，返回字节数
   **sizeof**: Evaluated at compile-time, returns bytes

5. **运算符优先级**：理解优先级避免错误，使用括号增加可读性
   **Operator Precedence**: Understand precedence to avoid bugs, use parentheses for clarity

## 常见陷阱 / Common Pitfalls

1. 混淆`=`和`==` / Confusing `=` with `==`
2. 整数除法得不到小数结果 / Integer division doesn't give decimal results
3. 位运算优先级低于比较运算符 / Bitwise operators have lower precedence than comparison
4. 前缀/后缀自增的区别 / Difference between prefix/postfix increment
