# Makefile for type_casting example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = type_casting

all: $(TARGET)

$(TARGET): type_casting.c
	$(CC) $(CFLAGS) -o $(TARGET) type_casting.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
