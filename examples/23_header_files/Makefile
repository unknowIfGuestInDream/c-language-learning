CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lm

all: header_files

header_files: header_files.c
	$(CC) $(CFLAGS) -o header_files header_files.c $(LDFLAGS)

clean:
	rm -f header_files

.PHONY: all clean
