# IDE 配置说明 / IDE Configuration Guide

本项目包含了 VSCode 和 CLion 的配置文件，方便您在这些 IDE 中编译和调试 C 代码。

This project includes configuration files for VSCode and CLion to help you compile and debug C code in these IDEs.

## VSCode 配置 / VSCode Configuration

### 前置要求 / Prerequisites

1. 安装 VSCode / Install VSCode
2. 安装 C/C++ 扩展 / Install C/C++ Extension:
   - 扩展名 / Extension: `ms-vscode.cpptools`
   - 在扩展市场搜索 "C/C++" / Search "C/C++" in Extension Marketplace

3. 可选扩展 / Optional Extensions:
   - **Code Runner** (`formulahendry.code-runner`) - 快速运行代码 / Quick code execution
   - **Makefile Tools** (`ms-vscode.makefile-tools`) - Makefile 支持 / Makefile support

### 配置文件说明 / Configuration Files

项目包含以下 VSCode 配置文件 / Project includes the following VSCode configuration files:

#### `.vscode/tasks.json`
定义了构建任务 / Defines build tasks:

- **Build Current Example** (Ctrl+Shift+B) - 编译当前示例 / Build current example
- **Build All Examples** - 编译所有示例 / Build all examples
- **Clean Current Example** - 清理当前示例 / Clean current example
- **Clean All Examples** - 清理所有示例 / Clean all examples
- **Run Current Example** - 运行当前示例 / Run current example
- **Build and Run Current Example** - 编译并运行 / Build and run
- **Test All Examples** - 测试所有示例 / Test all examples

#### `.vscode/launch.json`
定义了调试配置 / Defines debug configurations:

- **Debug Current C File** (F5) - 调试当前 C 文件 / Debug current C file
- **Debug with Custom Args** - 带参数调试 / Debug with arguments

#### `.vscode/c_cpp_properties.json`
配置 IntelliSense:

- 编译器路径 / Compiler path: `/usr/bin/gcc`
- C 标准 / C Standard: `c11`
- 编译参数 / Compiler flags: `-Wall -Wextra -std=c11`

#### `.vscode/settings.json`
工作区设置 / Workspace settings:

- 编辑器配置 / Editor configuration
- C/C++ 特定设置 / C/C++ specific settings
- Code Runner 配置 / Code Runner configuration

### 使用方法 / Usage

#### 编译和运行 / Build and Run

1. **编译当前文件 / Build Current File:**
   - 快捷键 / Shortcut: `Ctrl+Shift+B`
   - 或 / Or: Terminal → Run Build Task

2. **运行当前示例 / Run Current Example:**
   - 快捷键 / Shortcut: `Ctrl+Shift+T`
   - 或 / Or: Terminal → Run Task → "Run Current Example"

3. **使用 Code Runner (如已安装) / Using Code Runner (if installed):**
   - 快捷键 / Shortcut: `Ctrl+Alt+N`
   - 右键菜单 / Right-click: "Run Code"

#### 调试 / Debugging

1. **开始调试 / Start Debugging:**
   - 快捷键 / Shortcut: `F5`
   - 或 / Or: Run → Start Debugging

2. **断点 / Breakpoints:**
   - 点击行号左侧设置断点 / Click left of line number to set breakpoint
   - `F9` 切换断点 / Toggle breakpoint

3. **调试控制 / Debug Controls:**
   - `F5` - 继续 / Continue
   - `F10` - 单步跳过 / Step Over
   - `F11` - 单步进入 / Step Into
   - `Shift+F11` - 单步退出 / Step Out

### 终端命令 / Terminal Commands

在 VSCode 终端中，您可以使用 / In VSCode terminal, you can use:

```bash
# 编译当前目录的示例 / Build example in current directory
make

# 运行程序 / Run program
./<executable_name>

# 清理 / Clean
make clean

# 编译所有示例 (在根目录) / Build all (in root)
make all

# 测试所有示例 / Test all examples
make test
```

---

## CLion 配置 / CLion Configuration

### 前置要求 / Prerequisites

1. 安装 CLion / Install CLion
2. 确保已安装 GCC 工具链 / Ensure GCC toolchain is installed
3. 首次打开时，CLion 会自动检测 Makefile 项目 / CLion will auto-detect Makefile project on first open

### 配置文件说明 / Configuration Files

项目包含以下 CLion 配置文件 / Project includes the following CLion configuration files:

#### `.idea/misc.xml`
- Makefile 项目设置 / Makefile project settings
- 包含所有示例目录 / Includes all example directories
- 构建目标：`all` / Build target: `all`
- 清理目标：`clean` / Clean target: `clean`

#### `.idea/compiler.xml`
- 编译器设置 / Compiler settings
- 使用 GCC / Uses GCC
- 编译标志 / Compiler flags: `-Wall -Wextra -std=c11`

#### `.idea/vcs.xml`
- Git 版本控制配置 / Git VCS configuration

#### `.idea/encodings.xml`
- 文件编码设置为 UTF-8 / File encoding set to UTF-8

#### `.idea/inspectionProfiles/Project_Default.xml`
- 代码检查配置 / Code inspection configuration
- 启用 ClangTidy 检查 / Enable ClangTidy checks

### 使用方法 / Usage

#### 打开项目 / Open Project

1. 打开 CLion / Open CLion
2. File → Open
3. 选择项目根目录 / Select project root directory
4. CLion 会自动检测 Makefile 项目 / CLion will auto-detect Makefile project

#### 编译和运行 / Build and Run

1. **编译所有示例 / Build All Examples:**
   - 点击工具栏的 "Build" 按钮 / Click "Build" button in toolbar
   - 或 / Or: Build → Build Project (`Ctrl+F9`)

2. **清理 / Clean:**
   - Build → Clean

3. **运行示例 / Run Example:**
   - 右键点击 C 文件 / Right-click on C file
   - Run → Run 'filename'
   - 或创建运行配置 / Or create Run Configuration

#### 创建运行配置 / Create Run Configuration

1. Run → Edit Configurations
2. 点击 '+' → Makefile Target / Click '+' → Makefile Target
3. 配置 / Configuration:
   - Name: 示例名称 / Example name
   - Makefile: 选择示例目录的 Makefile / Select example's Makefile
   - Target: `all`
   - Working Directory: 示例目录 / Example directory

#### 调试 / Debugging

1. **设置断点 / Set Breakpoints:**
   - 点击行号左侧 / Click left of line number
   - `Ctrl+F8` 切换断点 / Toggle breakpoint

2. **开始调试 / Start Debugging:**
   - 创建调试配置 / Create debug configuration
   - Debug → Debug 'configuration' (`Shift+F9`)

3. **调试控制 / Debug Controls:**
   - `F8` - 单步跳过 / Step Over
   - `F7` - 单步进入 / Step Into
   - `Shift+F8` - 单步退出 / Step Out
   - `F9` - 继续 / Resume

### CLion 特色功能 / CLion Special Features

#### 代码导航 / Code Navigation

- **跳转到定义 / Go to Definition:** `Ctrl+B` 或 `Ctrl+Click`
- **查找用法 / Find Usages:** `Alt+F7`
- **查找文件 / Find File:** `Ctrl+Shift+N`
- **查找符号 / Find Symbol:** `Ctrl+Alt+Shift+N`

#### 代码重构 / Code Refactoring

- **重命名 / Rename:** `Shift+F6`
- **提取函数 / Extract Function:** `Ctrl+Alt+M`
- **提取变量 / Extract Variable:** `Ctrl+Alt+V`

#### 代码分析 / Code Analysis

- **分析代码 / Analyze Code:** Analyze → Inspect Code
- **Clang-Tidy:** Tools → Clang-Tidy
- **查看问题 / View Issues:** View → Tool Windows → Problems

---

## 常见问题 / FAQ

### VSCode

**Q: 编译时提示找不到 gcc？/ Q: "gcc not found" when building?**

A: 确保已安装 GCC 并添加到 PATH / Ensure GCC is installed and in PATH:
```bash
# Linux/Mac
which gcc

# Windows (MinGW)
where gcc
```

**Q: IntelliSense 不工作？/ Q: IntelliSense not working?**

A: 
1. 检查 `.vscode/c_cpp_properties.json` 中的编译器路径 / Check compiler path in `.vscode/c_cpp_properties.json`
2. 重启 VSCode / Restart VSCode
3. C/C++ 扩展：Command Palette → "C/C++: Reset IntelliSense Database"

**Q: 调试时无法停在断点？/ Q: Breakpoints not working during debug?**

A: 
1. 确保使用 Debug 模式编译 / Ensure compiling in Debug mode
2. 在 Makefile 中添加 `-g` 标志 / Add `-g` flag in Makefile
3. 检查 GDB 是否已安装 / Check if GDB is installed

### CLion

**Q: CLion 无法识别项目？/ Q: CLion doesn't recognize project?**

A:
1. File → Reload CMake/Makefile Project
2. 检查 `.idea/misc.xml` 配置 / Check `.idea/misc.xml` configuration
3. Invalidate Caches: File → Invalidate Caches / Restart

**Q: 编译错误？/ Q: Build errors?**

A:
1. 确认 GCC 已正确安装 / Confirm GCC is properly installed
2. Build → Clean 后重新编译 / Clean then rebuild
3. 检查 Makefile 语法 / Check Makefile syntax

**Q: 中文注释显示乱码？/ Q: Chinese comments show garbled text?**

A:
1. 检查文件编码为 UTF-8 / Check file encoding is UTF-8
2. File → File Encoding → UTF-8
3. Settings → Editor → File Encodings → Default encoding: UTF-8

---

## 推荐设置 / Recommended Settings

### VSCode 推荐扩展 / VSCode Recommended Extensions

创建 `.vscode/extensions.json`:
```json
{
    "recommendations": [
        "ms-vscode.cpptools",
        "ms-vscode.makefile-tools",
        "formulahendry.code-runner",
        "ms-vscode.cpptools-extension-pack"
    ]
}
```

### 编译标志说明 / Compiler Flags Explained

项目使用的编译标志 / Compiler flags used in project:

- `-Wall` - 启用所有警告 / Enable all warnings
- `-Wextra` - 启用额外警告 / Enable extra warnings
- `-std=c11` - 使用 C11 标准 / Use C11 standard
- `-g` - 生成调试信息 / Generate debug info (for debugging)
- `-O2` - 优化级别 2 / Optimization level 2 (for release)

### 快捷键总结 / Keyboard Shortcuts Summary

#### VSCode
| 功能 / Function | 快捷键 / Shortcut |
|----------------|------------------|
| 构建 / Build | `Ctrl+Shift+B` |
| 运行 / Run | `Ctrl+Shift+T` |
| 调试 / Debug | `F5` |
| 设置断点 / Breakpoint | `F9` |
| 单步跳过 / Step Over | `F10` |
| 单步进入 / Step Into | `F11` |

#### CLion
| 功能 / Function | 快捷键 / Shortcut |
|----------------|------------------|
| 构建 / Build | `Ctrl+F9` |
| 运行 / Run | `Shift+F10` |
| 调试 / Debug | `Shift+F9` |
| 设置断点 / Breakpoint | `Ctrl+F8` |
| 单步跳过 / Step Over | `F8` |
| 单步进入 / Step Into | `F7` |

---

## 故障排除 / Troubleshooting

### 权限问题 / Permission Issues

如果遇到权限问题 / If you encounter permission issues:

```bash
# 给可执行文件添加执行权限 / Add execute permission
chmod +x <executable_name>

# 给 Makefile 添加执行权限 / Add execute permission to Makefile
chmod +x Makefile
```

### 清理并重新构建 / Clean and Rebuild

```bash
# 清理所有构建文件 / Clean all build files
make clean

# 重新构建 / Rebuild
make all
```

### 查看编译详情 / View Build Details

```bash
# 显示详细编译信息 / Show verbose build information
make VERBOSE=1
```

---

## 支持和帮助 / Support and Help

如果遇到问题 / If you encounter issues:

1. 查看项目 README.md / Check project README.md
2. 查看 examples/MAKEFILE_GUIDE.md / Check examples/MAKEFILE_GUIDE.md
3. 提交 Issue 到 GitHub / Submit an Issue on GitHub

---

## 更新日志 / Changelog

- 2025-12-26: 初始版本，支持 VSCode 和 CLion / Initial version with VSCode and CLion support
