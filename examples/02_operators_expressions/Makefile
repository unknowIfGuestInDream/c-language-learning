# Makefile for operators_expressions example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = operators_expressions

all: $(TARGET)

$(TARGET): operators_expressions.c
	$(CC) $(CFLAGS) -o $(TARGET) operators_expressions.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
