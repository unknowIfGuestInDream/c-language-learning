# Makefile for scope_storage example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = scope_storage

all: $(TARGET)

$(TARGET): scope_storage.c
	$(CC) $(CFLAGS) -o $(TARGET) scope_storage.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
