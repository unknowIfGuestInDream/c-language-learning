# 贡献指南 / Contributing Guide

[English](#english) | [中文](#中文)

---

## English

Thank you for considering contributing to the C Language Learning repository! This guide will help you understand our contribution process and standards.

### Table of Contents
- [Code of Conduct](#code-of-conduct)
- [How to Contribute](#how-to-contribute)
- [Commit Message Format](#commit-message-format)
- [Code Style Guidelines](#code-style-guidelines)
- [Pull Request Process](#pull-request-process)
- [Issue Reporting](#issue-reporting)

### Code of Conduct

This project follows a code of conduct to ensure a welcoming and inclusive environment for all contributors. Please be respectful and constructive in all interactions.

### How to Contribute

1. **Fork the repository** to your GitHub account
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/c-language-learning.git
   cd c-language-learning
   ```
3. **Create a feature branch**:
   ```bash
   git checkout -b feat/your-feature-name
   ```
4. **Make your changes** following our guidelines
5. **Test your changes**:
   ```bash
   make clean && make all
   make test
   ```
6. **Commit your changes** using conventional commits
7. **Push to your fork** and create a Pull Request

### Commit Message Format

We follow the [Conventional Commits](https://www.conventionalcommits.org/) specification:

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

#### Types
- **feat**: A new feature or example
- **fix**: A bug fix
- **docs**: Documentation only changes
- **style**: Code style changes (formatting, missing semicolons, etc.)
- **refactor**: Code refactoring without changing functionality
- **test**: Adding or modifying tests
- **chore**: Changes to build process or auxiliary tools
- **perf**: Performance improvements

#### Examples
```
feat: add signal handling example with sigaction
fix: correct memory leak in dynamic array example
docs: update README with new learning path
style: format code according to project standards
refactor: reorganize pointer examples for clarity
test: add unit tests for string operations
chore: update Makefile to support parallel builds
```

### Code Style Guidelines

#### C Code Standards
- **Standard**: Use C11 (`-std=c11`)
- **Compiler Flags**: Always use `-Wall -Wextra` to catch warnings
- **Comments**: Provide bilingual comments (Chinese first, then English)
  ```c
  // 这是一个示例 / This is an example
  int main(void) {
      // 变量声明 / Variable declaration
      int x = 10;
      return 0;
  }
  ```
- **Naming Conventions**:
  - Variables and functions: `snake_case`
  - Constants and macros: `UPPER_SNAKE_CASE`
  - Struct names: `PascalCase` or `snake_case`

#### File Organization
- Each example must have its own directory under `examples/`
- Required files per example:
  - `*.c` - Source code with bilingual comments
  - `Makefile` - Build configuration (use tabs, not spaces!)
  - `README.md` - Bilingual documentation with:
    - Title and description
    - Key concepts
    - Java comparison (if applicable)
    - Compilation and execution instructions

#### Makefile Standards
- Use **tabs** for indentation in recipes (not spaces)
- Include these targets: `all`, `clean`
- Use proper compiler flags: `-Wall -Wextra -std=c11`
- Example template:
  ```makefile
  CC = gcc
  CFLAGS = -Wall -Wextra -std=c11
  TARGET = example_name
  
  all: $(TARGET)
  
  $(TARGET): $(TARGET).c
  	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
  
  clean:
  	rm -f $(TARGET)
  ```

#### Documentation Requirements
- **Bilingual**: All documentation must be in both Chinese and English
- **README Structure**:
  1. Title (Chinese / English)
  2. Description
  3. Key Concepts
  4. Java Comparison (if applicable)
  5. Compilation Instructions
  6. Execution Instructions
  7. Expected Output
  8. Learning Notes

### Pull Request Process

1. **Update your branch** with the latest master:
   ```bash
   git checkout master
   git pull upstream master
   git checkout your-feature-branch
   git rebase master
   ```

2. **Ensure all checks pass**:
   - Code compiles without errors
   - No new warnings introduced
   - Tests pass (`make test`)
   - Documentation is complete and bilingual

3. **Use the PR template** - Fill out all sections:
   - Type of change
   - Description of changes
   - Testing performed
   - Checklist completion

4. **Request review** - The maintainer will review your PR

5. **Address feedback** - Make requested changes promptly

6. **Merge** - Once approved, your PR will be merged

### Issue Reporting

When reporting issues, please use the appropriate template:

- **Bug Report**: For bugs in code or documentation
- **Feature Request**: For new examples or features
- **General Question**: For questions about C programming
- **Know-How**: For sharing C programming knowledge

Include:
- Clear description of the issue
- Steps to reproduce (for bugs)
- Expected vs actual behavior
- Environment details (OS, compiler version)
- Code snippets (if applicable)

### Adding New Examples

When adding a new C programming example:

1. **Choose appropriate numbering** - Follow the existing pattern
2. **Create directory structure**:
   ```
   examples/XX_topic_name/
   ├── topic_name.c
   ├── Makefile
   └── README.md
   ```
3. **Write comprehensive code**:
   - Include detailed bilingual comments
   - Demonstrate key concepts thoroughly
   - Compare with Java where applicable
   - Handle errors properly
   - Use best practices

4. **Document thoroughly**:
   - Explain "why" not just "what"
   - Include practical use cases
   - Note common pitfalls
   - Provide learning tips

5. **Test rigorously**:
   - Compile with `-Wall -Wextra`
   - Test on multiple platforms if possible
   - Verify output is correct
   - Check for memory leaks (with valgrind if available)

6. **Update root files**:
   - Add executable to `.gitignore`
   - Update main `README.md` with new example
   - Ensure root `Makefile` discovers new example

### Questions?

If you have questions about contributing:
- Check existing issues and documentation
- Ask in a new issue with the "general-question" template
- Review other examples for reference

---

## 中文

感谢您考虑为C语言学习仓库做出贡献！本指南将帮助您了解我们的贡献流程和标准。

### 目录
- [行为准则](#行为准则)
- [如何贡献](#如何贡献)
- [提交信息格式](#提交信息格式)
- [代码风格指南](#代码风格指南)
- [Pull Request流程](#pull-request流程)
- [Issue报告](#issue报告)

### 行为准则

本项目遵循行为准则，以确保为所有贡献者提供友好和包容的环境。请在所有互动中保持尊重和建设性。

### 如何贡献

1. **Fork此仓库**到您的GitHub账户
2. **克隆您的fork**到本地：
   ```bash
   git clone https://github.com/YOUR_USERNAME/c-language-learning.git
   cd c-language-learning
   ```
3. **创建功能分支**：
   ```bash
   git checkout -b feat/your-feature-name
   ```
4. **按照我们的指南进行更改**
5. **测试您的更改**：
   ```bash
   make clean && make all
   make test
   ```
6. **使用约定式提交提交更改**
7. **推送到您的fork**并创建Pull Request

### 提交信息格式

我们遵循[约定式提交](https://www.conventionalcommits.org/)规范：

```
<类型>[可选范围]: <描述>

[可选正文]

[可选脚注]
```

#### 类型
- **feat**: 新功能或示例
- **fix**: Bug修复
- **docs**: 仅文档更改
- **style**: 代码风格更改（格式化、缺少分号等）
- **refactor**: 不改变功能的代码重构
- **test**: 添加或修改测试
- **chore**: 构建过程或辅助工具的更改
- **perf**: 性能改进

#### 示例
```
feat: 添加signal处理示例使用sigaction
fix: 修复动态数组示例中的内存泄漏
docs: 使用新学习路径更新README
style: 按照项目标准格式化代码
refactor: 重新组织指针示例以提高清晰度
test: 为字符串操作添加单元测试
chore: 更新Makefile以支持并行构建
```

### 代码风格指南

#### C代码标准
- **标准**：使用C11（`-std=c11`）
- **编译器标志**：始终使用`-Wall -Wextra`来捕获警告
- **注释**：提供双语注释（中文在前，然后是英文）
  ```c
  // 这是一个示例 / This is an example
  int main(void) {
      // 变量声明 / Variable declaration
      int x = 10;
      return 0;
  }
  ```
- **命名约定**：
  - 变量和函数：`snake_case`
  - 常量和宏：`UPPER_SNAKE_CASE`
  - 结构体名称：`PascalCase`或`snake_case`

#### 文件组织
- 每个示例必须在`examples/`下有自己的目录
- 每个示例必需的文件：
  - `*.c` - 带双语注释的源代码
  - `Makefile` - 构建配置（使用制表符tab，不是空格！）
  - `README.md` - 双语文档，包含：
    - 标题和描述
    - 关键概念
    - 与Java的比较（如适用）
    - 编译和执行说明

#### Makefile标准
- 在配方中使用**制表符tab**进行缩进（不是空格）
- 包含这些目标：`all`、`clean`
- 使用适当的编译器标志：`-Wall -Wextra -std=c11`
- 示例模板：
  ```makefile
  CC = gcc
  CFLAGS = -Wall -Wextra -std=c11
  TARGET = example_name
  
  all: $(TARGET)
  
  $(TARGET): $(TARGET).c
  	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
  
  clean:
  	rm -f $(TARGET)
  ```

#### 文档要求
- **双语**：所有文档必须同时使用中文和英文
- **README结构**：
  1. 标题（中文/英文）
  2. 描述
  3. 关键概念
  4. 与Java的比较（如适用）
  5. 编译说明
  6. 执行说明
  7. 预期输出
  8. 学习笔记

### Pull Request流程

1. **使用最新的master更新您的分支**：
   ```bash
   git checkout master
   git pull upstream master
   git checkout your-feature-branch
   git rebase master
   ```

2. **确保所有检查通过**：
   - 代码编译无错误
   - 未引入新警告
   - 测试通过（`make test`）
   - 文档完整且双语

3. **使用PR模板** - 填写所有部分：
   - 变更类型
   - 变更描述
   - 执行的测试
   - 检查清单完成情况

4. **请求审查** - 维护者将审查您的PR

5. **处理反馈** - 及时进行请求的更改

6. **合并** - 批准后，您的PR将被合并

### Issue报告

报告问题时，请使用适当的模板：

- **Bug报告**：用于代码或文档中的bug
- **功能请求**：用于新示例或功能
- **一般问题**：用于C编程问题
- **知识分享**：用于分享C编程知识

包括：
- 问题的清晰描述
- 重现步骤（对于bug）
- 预期行为与实际行为
- 环境详细信息（操作系统、编译器版本）
- 代码片段（如适用）

### 添加新示例

添加新的C编程示例时：

1. **选择适当的编号** - 遵循现有模式
2. **创建目录结构**：
   ```
   examples/XX_topic_name/
   ├── topic_name.c
   ├── Makefile
   └── README.md
   ```
3. **编写全面的代码**：
   - 包含详细的双语注释
   - 全面演示关键概念
   - 在适用的地方与Java进行比较
   - 正确处理错误
   - 使用最佳实践

4. **全面文档化**：
   - 解释"为什么"而不仅仅是"是什么"
   - 包含实际用例
   - 注意常见陷阱
   - 提供学习技巧

5. **严格测试**：
   - 使用`-Wall -Wextra`编译
   - 如果可能在多个平台上测试
   - 验证输出正确
   - 检查内存泄漏（如果可用valgrind）

6. **更新根文件**：
   - 将可执行文件添加到`.gitignore`
   - 使用新示例更新主`README.md`
   - 确保根`Makefile`发现新示例

### 有问题？

如果您对贡献有疑问：
- 检查现有的issues和文档
- 使用"general-question"模板在新issue中提问
- 查看其他示例作为参考

---

## License / 许可证

By contributing to this repository, you agree that your contributions will be licensed under the same license as the project.

通过为此仓库做出贡献，您同意您的贡献将按照与项目相同的许可证进行许可。
