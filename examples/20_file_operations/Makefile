CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: file_operations

file_operations: file_operations.c
	$(CC) $(CFLAGS) -o file_operations file_operations.c

clean:
	rm -f file_operations test_text.txt test_binary.dat

.PHONY: all clean
