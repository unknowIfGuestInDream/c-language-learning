CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 检测操作系统 / Detect operating system
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    # macOS
    LIB_EXT = dylib
    LIB_FLAGS = -dynamiclib
    RUN_CMD = DYLD_LIBRARY_PATH=. ./main
else
    # Linux
    LIB_EXT = so
    LIB_FLAGS = -shared
    RUN_CMD = LD_LIBRARY_PATH=. ./main
endif

LIB_NAME = libstringlib.$(LIB_EXT)

# 目标 / Targets
all: main
	@echo ""
	@echo "动态库已创建 / Dynamic library created: $(LIB_NAME)"
	@echo "主程序已编译 / Main program compiled: main"
	@echo ""
	@echo "运行程序 / To run the program:"
	@echo "  $(RUN_CMD)"
	@echo "或 / or:"
	@echo "  make run"

# 创建动态库 / Create dynamic library
$(LIB_NAME): stringlib.o
	$(CC) $(LIB_FLAGS) -o $(LIB_NAME) stringlib.o

# 编译库源文件（位置无关代码）/ Compile library source (position-independent code)
stringlib.o: stringlib.c stringlib.h
	$(CC) $(CFLAGS) -fPIC -c stringlib.c -o stringlib.o

# 编译并链接主程序 / Compile and link main program
main: main.c $(LIB_NAME)
	$(CC) $(CFLAGS) main.c -L. -lstringlib -o main

# 运行程序 / Run program
run: main
	$(RUN_CMD)

# 清理 / Clean
clean:
	rm -f *.o *.so *.dylib main
	@echo "已清理 / Cleaned"

.PHONY: all run clean
