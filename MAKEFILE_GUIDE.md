# Makefile 使用指南 / Makefile Usage Guide

## 什么是Makefile? / What is Makefile?

Makefile是一个构建自动化工具的配置文件，用于管理C/C++项目的编译过程。类似于Java的Maven或Gradle，但更底层和灵活。

Makefile is a configuration file for build automation tools, used to manage the compilation process of C/C++ projects. Similar to Java's Maven or Gradle, but more low-level and flexible.

## 基本语法 / Basic Syntax

```makefile
target: dependencies
	command
```

- `target`: 要生成的目标文件 / File to generate
- `dependencies`: 依赖的文件 / Files it depends on
- `command`: 执行的命令（必须用Tab缩进！）/ Command to execute (must use Tab!)

## 简单示例 / Simple Example

```makefile
# 注释 / Comment
hello: hello.c
	gcc -o hello hello.c

clean:
	rm -f hello
```

使用 / Usage:
```bash
make hello    # 编译hello程序 / Compile hello program
make clean    # 清理生成的文件 / Clean generated files
```

## 变量 / Variables

```makefile
CC = gcc                    # 编译器 / Compiler
CFLAGS = -Wall -Wextra      # 编译选项 / Compiler flags
TARGET = myprogram          # 目标名称 / Target name

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c
```

## 常用变量 / Common Variables

| 变量 / Variable | 说明 / Description |
|----------------|-------------------|
| `CC` | C编译器 / C compiler (gcc, clang) |
| `CFLAGS` | 编译选项 / Compiler flags |
| `LDFLAGS` | 链接选项 / Linker flags |
| `$@` | 当前目标 / Current target |
| `$<` | 第一个依赖 / First dependency |
| `$^` | 所有依赖 / All dependencies |

## 实用模式 / Practical Patterns

### 1. 基本C程序 / Basic C Program

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: program

program: main.c utils.c
	$(CC) $(CFLAGS) -o program main.c utils.c

clean:
	rm -f program

.PHONY: all clean
```

### 2. 多文件项目 / Multi-file Project

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SOURCES = main.c utils.c helpers.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = myapp

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all clean
```

### 3. 带测试的项目 / Project with Tests

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.c
	$(CC) $(CFLAGS) -o main main.c

test: main
	./main
	@echo "Tests passed!"

clean:
	rm -f main

.PHONY: all test clean
```

### 4. 静态库 / Static Library

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
AR = ar
ARFLAGS = rcs

LIB = libmylib.a
OBJS = lib1.o lib2.o

all: $(LIB)

$(LIB): $(OBJS)
	$(AR) $(ARFLAGS) $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all clean
```

### 5. 动态库 / Dynamic Library

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -fPIC

LIB = libmylib.so
OBJS = lib1.o lib2.o

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) -shared -o $(LIB) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB)

.PHONY: all clean
```

## 常用make命令 / Common make Commands

```bash
make              # 执行默认目标（通常是第一个或all）/ Execute default target
make target       # 执行指定目标 / Execute specific target
make clean        # 清理生成的文件 / Clean generated files
make -n           # 显示将要执行的命令但不执行 / Show commands without executing
make -j4          # 并行编译（4个任务）/ Parallel compilation (4 jobs)
```

## 编译选项说明 / Compiler Flags Explanation

### 警告选项 / Warning Flags
```makefile
-Wall            # 启用大多数警告 / Enable most warnings
-Wextra          # 启用额外警告 / Enable extra warnings
-Werror          # 将警告视为错误 / Treat warnings as errors
-pedantic        # 严格遵循标准 / Strict standard conformance
```

### 优化选项 / Optimization Flags
```makefile
-O0              # 无优化（默认）/ No optimization (default)
-O1              # 基本优化 / Basic optimization
-O2              # 推荐的优化级别 / Recommended optimization
-O3              # 最高优化级别 / Maximum optimization
-Os              # 优化大小 / Optimize for size
```

### 调试选项 / Debug Flags
```makefile
-g               # 生成调试信息 / Generate debug info
-ggdb            # 生成GDB专用调试信息 / Generate GDB-specific debug info
```

### 标准选项 / Standard Flags
```makefile
-std=c89         # C89/C90标准 / C89/C90 standard
-std=c99         # C99标准 / C99 standard
-std=c11         # C11标准 / C11 standard
-std=c17         # C17标准 / C17 standard
```

## .PHONY 目标 / .PHONY Targets

`.PHONY` 声明某个目标不是文件，而是命令：

```makefile
.PHONY: all clean test install

all: program

clean:
	rm -f *.o program

test: program
	./program

install: program
	cp program /usr/local/bin/
```

## 条件编译 / Conditional Compilation

```makefile
DEBUG ?= 0

ifeq ($(DEBUG), 1)
    CFLAGS += -g -DDEBUG
else
    CFLAGS += -O2
endif
```

使用 / Usage:
```bash
make              # Release模式 / Release mode
make DEBUG=1      # Debug模式 / Debug mode
```

## 自动依赖生成 / Automatic Dependency Generation

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
DEPFLAGS = -MMD -MP

SOURCES = main.c utils.c
OBJECTS = $(SOURCES:.c=.o)
DEPS = $(OBJECTS:.o=.d)

-include $(DEPS)

program: $(OBJECTS)
	$(CC) $(CFLAGS) -o program $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(DEPS) program

.PHONY: clean
```

## 与Java构建工具的对比 / Comparison with Java Build Tools

| 特性 / Feature | Makefile | Maven | Gradle |
|---------------|----------|-------|--------|
| 语法 / Syntax | Make语法 / Make syntax | XML | Groovy/Kotlin |
| 依赖管理 / Dependencies | 手动 / Manual | 自动 / Automatic | 自动 / Automatic |
| 项目结构 / Structure | 灵活 / Flexible | 约定 / Convention | 灵活 / Flexible |
| 跨平台 / Cross-platform | 需要注意 / Need attention | 是 / Yes | 是 / Yes |
| 学习曲线 / Learning Curve | 中等 / Medium | 高 / High | 高 / High |

## 最佳实践 / Best Practices

1. **使用变量** / Use variables: 便于维护和修改 / Easier to maintain
2. **使用.PHONY** / Use .PHONY: 避免与文件名冲突 / Avoid conflicts
3. **添加clean目标** / Add clean target: 方便清理 / Easy cleanup
4. **合理的编译选项** / Reasonable flags: `-Wall -Wextra -std=c11`
5. **目录组织** / Directory structure: `src/`, `include/`, `build/`
6. **注释** / Comments: 说明复杂的规则 / Explain complex rules

## 完整项目示例 / Complete Project Example

```makefile
# 项目配置 / Project Configuration
PROJECT = myapp
VERSION = 1.0.0

# 编译器设置 / Compiler Settings
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = -lm

# 目录 / Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

# 源文件和目标 / Sources and targets
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BIN_DIR)/$(PROJECT)

# 默认目标 / Default target
all: $(TARGET)

# 创建目录 / Create directories
$(BUILD_DIR) $(BIN_DIR):
	mkdir -p $@

# 链接 / Link
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built $(PROJECT) v$(VERSION)"

# 编译 / Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 清理 / Clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# 运行 / Run
run: $(TARGET)
	$(TARGET)

# 安装 / Install
install: $(TARGET)
	install -m 755 $(TARGET) /usr/local/bin/

# 显示帮助 / Show help
help:
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  clean   - Remove build artifacts"
	@echo "  run     - Build and run the project"
	@echo "  install - Install to /usr/local/bin"
	@echo "  help    - Show this help message"

.PHONY: all clean run install help
```

## 调试Makefile / Debugging Makefile

```bash
make -n          # 显示命令但不执行 / Show commands without executing
make -d          # 显示调试信息 / Show debug information
make --debug     # 详细调试信息 / Detailed debug info
```

## 资源链接 / Resources

- GNU Make手册 / GNU Make Manual: https://www.gnu.org/software/make/manual/
- Make教程 / Make Tutorial: https://makefiletutorial.com/
