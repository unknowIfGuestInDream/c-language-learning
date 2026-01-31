CC = gcc
CFLAGS = -Wall -Wextra -std=c11
AR = ar
ARFLAGS = rcs

# 目标 / Targets
all: main

# 创建静态库 / Create static library
libmathlib.a: mathlib.o
	$(AR) $(ARFLAGS) libmathlib.a mathlib.o
	@echo "静态库已创建 / Static library created: libmathlib.a"

# 编译库源文件 / Compile library source
mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib.c -o mathlib.o

# 编译并链接主程序 / Compile and link main program
main: main.c libmathlib.a
	$(CC) $(CFLAGS) main.c -L. -lmathlib -o main
	@echo "主程序已编译 / Main program compiled: main"

# 清理 / Clean
clean:
	rm -f *.o *.a main
	@echo "已清理 / Cleaned"

.PHONY: all clean
