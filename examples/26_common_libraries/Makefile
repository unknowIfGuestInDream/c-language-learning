CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

all: common_libraries

common_libraries: common_libraries.c
	$(CC) $(CFLAGS) -o common_libraries common_libraries.c $(LDFLAGS)

clean:
	rm -f common_libraries

.PHONY: all clean
