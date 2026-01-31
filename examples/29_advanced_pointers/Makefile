CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = advanced_pointers

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)

.PHONY: all clean
