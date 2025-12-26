CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: $(notdir $(CURDIR))

$(notdir $(CURDIR)): $(notdir $(CURDIR)).c
$(CC) $(CFLAGS) -o $(notdir $(CURDIR)) $(notdir $(CURDIR)).c

clean:
rm -f $(notdir $(CURDIR))

.PHONY: all clean
