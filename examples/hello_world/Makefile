CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: hello

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c

clean:
	rm -f hello

.PHONY: all clean
