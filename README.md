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

#### 在Ubuntu/Linux上安装 / Install on Ubuntu/Linux:
```bash
sudo apt-get update
sudo apt-get install build-essential gcc make
```

#### 在Windows上安装 / Install on Windows:

推荐使用MSYS2安装MinGW-w64工具链 / Recommended to use MSYS2 to install MinGW-w64 toolchain:

1. 下载并安装MSYS2 / Download and install MSYS2: https://www.msys2.org/
2. 打开MSYS2 UCRT64终端并运行 / Open MSYS2 UCRT64 terminal and run:
```bash
pacman -Syu
pacman -S mingw-w64-ucrt-x86_64-gcc make
```
3. 将MSYS2添加到系统PATH / Add MSYS2 to system PATH:
   - 添加 `C:\msys64\ucrt64\bin` 和 `C:\msys64\usr\bin` 到系统环境变量PATH
   - Add `C:\msys64\ucrt64\bin` and `C:\msys64\usr\bin` to system environment variable PATH
4. 验证安装 / Verify installation:
```bash
gcc --version
make --version
```

#### 在macOS上安装 / Install on macOS:
```bash
xcode-select --install
# 或使用Homebrew / Or use Homebrew:
brew install gcc make
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

## IDE配置 / IDE Configuration

本项目提供了VSCode和CLion的配置文件，支持Linux、Windows和macOS。详细信息请查看 [IDE_SETUP.md](IDE_SETUP.md)。

This project provides configuration files for VSCode and CLion, supporting Linux, Windows, and macOS. See [IDE_SETUP.md](IDE_SETUP.md) for details.

## 自动化构建 / Automated Build

本项目使用GitHub Actions在Ubuntu和Windows环境中自动编译所有C语言示例。每次推送或Pull Request都会触发自动构建。

This project uses GitHub Actions to automatically compile all C language examples in Ubuntu and Windows environments. Automated builds are triggered on every push or pull request.

工作流文件 / Workflow file: `.github/workflows/build.yml`

## 贡献 / Contributing

欢迎提交新的学习示例！请确保您的代码：

Welcome to submit new learning examples! Please ensure your code:

1. 包含详细的中英文注释 / Includes detailed bilingual comments
2. 有配套的README.md文档 / Has accompanying README.md documentation
3. 包含Makefile便于编译 / Includes Makefile for easy compilation
4. 可以通过编译和测试 / Can be compiled and tested successfully
5. 遵循项目的代码风格 / Follows the project's coding style
