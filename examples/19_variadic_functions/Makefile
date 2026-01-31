# Makefile for variadic_functions example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = variadic_functions

all: $(TARGET)

$(TARGET): variadic_functions.c
	$(CC) $(CFLAGS) -o $(TARGET) variadic_functions.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
