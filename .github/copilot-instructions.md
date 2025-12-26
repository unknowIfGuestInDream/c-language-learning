# GitHub Copilot Instructions for c-language-learning

## Repository Purpose
This is a C language learning repository designed specifically for Java developers. It contains comprehensive examples covering C fundamentals to advanced topics, with bilingual (Chinese/English) documentation and detailed comparisons with Java.

## Code Style and Conventions

### C Code Standards
- **Standard**: Use C11 standard (`-std=c11`)
- **Compiler Flags**: Always compile with `-Wall -Wextra` to catch warnings
- **Comments**: Provide bilingual comments (Chinese first, then English after `/`)
  ```c
  // 这是一个示例 / This is an example
  ```
- **Naming Conventions**:
  - Variables and functions: `snake_case`
  - Constants and macros: `UPPER_SNAKE_CASE`
  - Struct names: `PascalCase` or `snake_case`

### Documentation
- Each example must have a `README.md` with:
  - Title and description in both Chinese and English
  - Key concepts explained
  - Comparison with Java where applicable
  - Compilation and execution instructions
- Code comments should explain "why" not just "what"
- Include examples of common pitfalls and how to avoid them

### Build System
- Each example directory must have its own `Makefile`
- Makefile targets should include: `all`, `clean`, and the executable
- Use proper tab indentation in Makefiles (not spaces)
- Root Makefile should automatically discover and build all examples

## Project Structure
```
c-language-learning/
├── examples/
│   ├── hello_world/          # Basic introduction
│   ├── 01_variables_constants/  # Fundamentals
│   ├── 03_control_flow/      # Control structures
│   ├── 06_pointers/          # Pointers and memory
│   └── ...
├── .github/
│   ├── workflows/            # CI/CD workflows
│   ├── ISSUE_TEMPLATE/       # Issue templates
│   └── CODEOWNERS           # Code ownership
├── .vscode/                  # VSCode configuration
├── .idea/                    # CLion configuration
└── README.md                 # Main documentation
```

## When Adding New Examples

1. **Create a new directory** under `examples/` with a descriptive name
2. **Implement the C program** with comprehensive comments
3. **Create a Makefile** with proper targets
4. **Write a README.md** with bilingual documentation
5. **Add Java comparisons** where relevant
6. **Test compilation** with `make all` from the root
7. **Verify in IDE** configurations work (VSCode and CLion)

## Learning Progression

Examples should follow this progression:
1. **Basics**: Variables, types, operators, control flow, loops
2. **Functions**: Function definitions, parameters, return values
3. **Pointers & Memory**: Pointer basics, arrays, memory management
4. **Data Structures**: Structs, unions, enums
5. **Advanced**: Function pointers, variadic functions, preprocessor
6. **I/O & Files**: File operations, formatted I/O
7. **Libraries**: Static and dynamic libraries

## For Java Developers

When explaining C concepts:
- Always compare with equivalent Java concepts
- Highlight key differences (manual memory management, pointers, etc.)
- Explain C's "close to the metal" philosophy
- Show common pitfalls for Java developers learning C
- Provide examples of memory management patterns

## Best Practices

- **Memory Safety**: Always free allocated memory
- **Null Checks**: Check pointer validity before dereferencing
- **Buffer Overflow**: Use `strncpy` instead of `strcpy`, check array bounds
- **Compiler Warnings**: Treat warnings as errors during development
- **Testing**: Include test cases or verification output in examples
- **Portability**: Write portable code when possible, document platform-specific code

## CI/CD

- All code must pass the GitHub Actions build workflow
- Examples must compile without errors on Ubuntu with GCC
- Warnings should be minimized (with exceptions documented)

## Contributions

When reviewing or suggesting code:
- Ensure bilingual documentation is complete
- Verify Makefile syntax (tabs, not spaces)
- Check for memory leaks in examples using dynamic allocation
- Ensure examples are educational and well-commented
- Validate that Java comparisons are accurate and helpful
