CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 源文件 / Source files
SRCS = main.c utils.c string_utils.c

# 目标文件 / Object files
OBJS = $(SRCS:.c=.o)

# 可执行文件 / Executable
TARGET = custom_headers

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译规则 / Compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 依赖关系 / Dependencies
main.o: main.c utils.h string_utils.h
utils.o: utils.c utils.h
string_utils.o: string_utils.c string_utils.h

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
