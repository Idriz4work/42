# ft_printf

Because ft_putstr & ft_putnbr aren't enough 😜

## Table of Contents
- [Overview](#overview)
- [Capabilities](#capabilities)
  - [Specifiers](#specifiers)
  - [Flags](#flags)
- [Bonus Features](#bonus-features)
- [Limitations](#limitations)
- [Installation](#installation)
  - [Prerequisites](#prerequisites)
  - [Building](#building)
  - [Testing](#testing)
- [Usage](#usage)
- [Examples](#examples)

## Overview

Printf is likely one of the most popular commands people see when learning a new programming language, and for a good reason. They are easy to understand and very powerful too. This is why learning to implement our own version of printf can help us better understand what happens internally when entering `printf("Hello World")`!

## Capabilities

Our version of the printf function will be called `ft_printf`, and has the following prototype:

```c
int ft_printf(const char *str, ...);
```

### Specifiers

| Specifier | Description |
|-----------|-------------|
| %         | Prints the percent character |
| c         | Prints a character |
| s         | Prints a string (array of characters) |
| d,i       | Prints an integer |
| p         | Prints pointer address (hex starting with 0x) |
| u         | Prints an unsigned integer |
| x         | Prints an unsigned hexadecimal integer (lowercase a-f) |
| X         | Prints an unsigned hexadecimal integer (uppercase A-F) |

### Flags

| Flag       | Description |
|------------|-------------|
| #    | Specifies the minimum width of the printed variable (adds spaces when necessary) |
| -          | Pads text to the left (adds spaces to the right) |
| 0          | Pads text with zeroes instead of spaces |
| .          | Separates Width and Precision |
| (precision)| Selects the minimum number of elements of the variable that are printed (e.g., number of chars from a string) |

The general structure of the format specification is:
```
%[Flags][Width].[Precision][Specifier]
```

## Bonus Features

As of July 2021, the following flags are part of the bonus:

| Bonus Flag | Description |
|------------|-------------|
| #          | Adds "0X" or "0x" to conversions with hexadecimal specifiers (excluding p) for values other than zero |
| ' '        | A blank space is added provided that no sign is specified |
| +          | Adds a plus sign in front of positive numbers |

## Limitations

This implementation has several limitations compared to the original printf:

- No buffer management
- Different handling of overflows and unexpected inputs
- Limited feature set compared to the original printf
- Relies on our personal libft library, resulting in slower performance
- Not as robust in edge cases as the original printf

## Installation

### Prerequisites

Required dependencies:
- gcc
- clang
- python-norminette
- make
- valgrind (recommended for Linux users)

### Building

1. Clone the repository:
```bash
git clone https://gitlab.com/Idriz4work/42/ft_printf.git
cd ft_printf
```

2. Build the library:
```bash
make
```

### Testing

The makefile provides several useful commands:

```bash
make all           # Compiles the libftprintf.a file
make test         # Compiles ft_printf and libft with a custom main. Checks for leaks in Mac and Linux
make bonus        # Compiles all bonus files instead of the mandatory ones
make norminette   # Checks Norm for both printf and libft files
make git          # Stages every modified file to commit and pushes to upstream branch
```

## Usage

The compilation process creates the following structure:
- Object files are saved in `obj/` and `objb/` folders
- The output file `libftprintf.a` is generated in the `bin/` folder
- You can replace the libft folder with your own implementation

Feel free to replace your own libft inside the ft_printf folder.

## Notes

This project was completed as part of the 42 School curriculum at 42 Madrid. The implementation follows the school's coding standards and requirements while providing a practical understanding of variadic functions and string formatting.

---
Last updated: July 9th, 2021
