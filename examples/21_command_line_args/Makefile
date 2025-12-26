CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = command_line_args

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)

.PHONY: all clean
