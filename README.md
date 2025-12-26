# c-language-learning

C语言学习 / C Language Learning

[![C Language Build](https://github.com/unknowIfGuestInDream/c-language-learning/workflows/C%20Language%20Build/badge.svg)](https://github.com/unknowIfGuestInDream/c-language-learning/actions)

## 项目介绍 / Project Introduction

这是一个C语言学习项目，包含各种C语言学习示例。每个示例都可以通过GitHub Actions自动编译和测试。

This is a C language learning project containing various C language learning examples. Each example can be automatically compiled and tested through GitHub Actions.

## 构建和运行 / Build and Run

### 前置要求 / Prerequisites

- GCC编译器 / GCC Compiler
- Make工具 / Make utility

在Ubuntu上安装 / Install on Ubuntu:
```bash
sudo apt-get update
sudo apt-get install build-essential gcc make
```

### 编译所有示例 / Build All Examples

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

## 示例列表 / Examples List

### 1. Hello World

最基础的C语言程序示例。

Basic C language program example.

**位置 / Location:** `examples/hello_world/`

**编译 / Build:**
```bash
cd examples/hello_world
make
```

**运行 / Run:**
```bash
./hello
```

**输出 / Output:**
```
Hello, World!
欢迎来到C语言学习！
```

## 自动化构建 / Automated Build

本项目使用GitHub Actions在Ubuntu环境中自动编译所有C语言示例。每次推送或Pull Request都会触发自动构建。

This project uses GitHub Actions to automatically compile all C language examples in an Ubuntu environment. Automated builds are triggered on every push or pull request.

工作流文件 / Workflow file: `.github/workflows/build.yml`

## 贡献 / Contributing

欢迎提交新的学习示例！请确保您的代码可以通过编译和测试。

Welcome to submit new learning examples! Please ensure your code can be compiled and tested.

## 许可证 / License

请查看 LICENSE 文件。

Please see the LICENSE file.
