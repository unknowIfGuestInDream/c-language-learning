CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: variables_constants

variables_constants: variables_constants.c
	$(CC) $(CFLAGS) -o variables_constants variables_constants.c

clean:
	rm -f variables_constants

.PHONY: all clean
