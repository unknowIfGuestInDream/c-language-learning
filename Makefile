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
					case "$$exe" in \
						*.so|*.dylib|*.a|*.o) \
							;; \
						*) \
							echo "Running $$exe:"; \
							if [ "$$dir" = "examples/10_dynamic_library" ] || [ "$$dir" = "examples/09_static_library" ]; then \
								cd $$dir && LD_LIBRARY_PATH=.:$$LD_LIBRARY_PATH DYLD_LIBRARY_PATH=.:$$DYLD_LIBRARY_PATH ./`basename $$exe` || exit 1; cd - > /dev/null; \
							else \
								$$exe || exit 1; \
							fi \
							;; \
					esac; \
				fi; \
			done; \
		fi; \
	done
	@echo "All examples tested successfully!"

.PHONY: all build_examples clean test
