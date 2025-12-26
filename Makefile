CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Find all C files in examples directory
EXAMPLE_DIRS = $(wildcard examples/*)
C_FILES = $(wildcard examples/*/*.c)

all: build_examples

build_examples:
	@echo "Building all C examples..."
	@for dir in $(EXAMPLE_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "Building $$dir..."; \
			$(MAKE) -C $$dir || exit 1; \
		fi; \
	done
	@echo "All examples built successfully!"

clean:
	@echo "Cleaning all examples..."
	@for dir in $(EXAMPLE_DIRS); do \
		if [ -f $$dir/Makefile ]; then \
			echo "Cleaning $$dir..."; \
			$(MAKE) -C $$dir clean; \
		fi; \
	done
	@echo "All examples cleaned!"

test: all
	@echo "Running all examples..."
	@for dir in $(EXAMPLE_DIRS); do \
		if [ -d $$dir ]; then \
			echo "Testing $$dir..."; \
			for exe in $$dir/*; do \
				if [ -x $$exe ] && [ -f $$exe ] && [ ! -d $$exe ]; then \
					echo "Running $$exe:"; \
					$$exe || exit 1; \
				fi; \
			done; \
		fi; \
	done
	@echo "All examples tested successfully!"

.PHONY: all build_examples clean test
