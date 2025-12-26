# c-language-learning

C语言学习 / C Language Learning

[![C Language Build](https://github.com/unknowIfGuestInDream/c-language-learning/workflows/C%20Language%20Build/badge.svg)](https://github.com/unknowIfGuestInDream/c-language-learning/actions)

## 项目介绍 / Project Introduction

这是一个全面的C语言学习项目，包含各种C语言学习示例，特别为Java开发者设计。每个示例都包含详细的中英文注释和文档，并通过GitHub Actions自动编译和测试。

This is a comprehensive C language learning project containing various C language learning examples, specially designed for Java developers. Each example includes detailed bilingual (Chinese/English) comments and documentation, and is automatically compiled and tested through GitHub Actions.

## 快速开始 / Quick Start

### 前置要求 / Prerequisites

- GCC编译器 / GCC Compiler
- Make工具 / Make utility

在Ubuntu上安装 / Install on Ubuntu:
```bash
sudo apt-get update
sudo apt-get install build-essential gcc make
```

## 编译和运行 / Compilation and Execution

### 编译所有示例 / Build All Examples

在项目根目录运行：
Run from project root:

```bash
make all
```

### 运行所有示例 / Run All Examples

```bash
make test
```

### 清理构建文件 / Clean Build Files

```bash
make clean
```

## 学习示例 / Learning Examples

所有C语言学习示例都在 `examples/` 目录下，详细信息请查看 [examples/README.md](examples/README.md)。

All C language learning examples are in the `examples/` directory. See [examples/README.md](examples/README.md) for details.

## 自动化构建 / Automated Build

本项目使用GitHub Actions在Ubuntu环境中自动编译所有C语言示例。每次推送或Pull Request都会触发自动构建。

This project uses GitHub Actions to automatically compile all C language examples in an Ubuntu environment. Automated builds are triggered on every push or pull request.

工作流文件 / Workflow file: `.github/workflows/build.yml`

## 贡献 / Contributing

欢迎提交新的学习示例！请确保您的代码：

Welcome to submit new learning examples! Please ensure your code:

1. 包含详细的中英文注释 / Includes detailed bilingual comments
2. 有配套的README.md文档 / Has accompanying README.md documentation
3. 包含Makefile便于编译 / Includes Makefile for easy compilation
4. 可以通过编译和测试 / Can be compiled and tested successfully
5. 遵循项目的代码风格 / Follows the project's coding style
