# Makefile for functions example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = functions

all: $(TARGET)

$(TARGET): functions.c
	$(CC) $(CFLAGS) -o $(TARGET) functions.c -lm

clean:
	rm -f $(TARGET)

.PHONY: all clean
