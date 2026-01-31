CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: value_vs_reference

value_vs_reference: value_vs_reference.c
	$(CC) $(CFLAGS) -o value_vs_reference value_vs_reference.c

clean:
	rm -f value_vs_reference

.PHONY: all clean
