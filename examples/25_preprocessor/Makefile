# Makefile for preprocessor example

CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = preprocessor

all: $(TARGET)

$(TARGET): preprocessor.c
	$(CC) $(CFLAGS) -o $(TARGET) preprocessor.c

clean:
	rm -f $(TARGET)

.PHONY: all clean
