# Libft

A comprehensive C library containing 40+ utility functions, including both standard library clones and additional custom functions.

## Table of Contents
- [Overview](#overview)
- [Part 1: C Standard Library Functions](#part-1-c-standard-library-functions)
  - [Character Functions](#character-functions)
  - [String Functions](#string-functions)
  - [Memory Functions](#memory-functions)
  - [Conversion Functions](#conversion-functions)
  - [Memory Allocation](#memory-allocation)
- [Part 2: Additional Functions](#part-2-additional-functions)
  - [String Manipulation](#string-manipulation)
  - [File Descriptor Operations](#file-descriptor-operations)
- [Part 3: Bonus Functions](#part-3-bonus-functions)
  - [Linked List Operations](#linked-list-operations)
- [Project Status](#project-status)
- [Contact](#contact)

## Overview

This project involves creating a library of essential C functions from scratch. It serves as a foundation for understanding basic C programming concepts while introducing more complex topics like linked lists, memory management, and function pointers.

## Part 1: C Standard Library Functions

### Character Functions
- `ft_isalpha()` - Check for alphabetic character
- `ft_isdigit()` - Check for digit character
- `ft_isalnum()` - Check for alphanumeric character
- `ft_isascii()` - Check for ASCII character
- `ft_isprint()` - Check for printable character
- `ft_toupper()` - Convert character to uppercase
- `ft_tolower()` - Convert character to lowercase

### String Functions
- `ft_strlen()` - Calculate string length using `size_t`
- `ft_strchr()` - Locate first occurrence of character in string
- `ft_strrchr()` - Locate last occurrence of character in string
- `ft_strncmp()` - Compare two strings up to n characters
- `ft_strlcpy()` - Copy string with size limitation
- `ft_strlcat()` - Concatenate string with size limitation
- `ft_strnstr()` - Locate substring in string with length limitation

### Memory Functions
- `ft_memset()` - Fill memory with constant byte
- `ft_bzero()` - Zero out memory area
- `ft_memcpy()` - Copy memory area
- `ft_memmove()` - Copy memory area with overlap handling
- `ft_memchr()` - Scan memory for byte
- `ft_memcmp()` - Compare memory areas

### Conversion Functions
- `ft_atoi()` - Convert string to integer

### Memory Allocation
- `ft_calloc()` - Allocate and zero out memory
- `ft_strdup()` - Duplicate string

## Part 2: Additional Functions

### String Manipulation
- `ft_substr()` - Extract substring from string
- `ft_strjoin()` - Concatenate two strings
- `ft_strtrim()` - Trim characters from string
- `ft_split()` - Split string using delimiter
- `ft_itoa()` - Convert integer to string
- `ft_strmapi()` - Apply function to each character with new string
- `ft_striteri()` - Apply function to each character in place

### File Descriptor Operations
- `ft_putchar_fd()` - Output character to file descriptor
- `ft_putstr_fd()` - Output string to file descriptor
- `ft_putendl_fd()` - Output string with newline to file descriptor
- `ft_putnbr_fd()` - Output number to file descriptor

## Part 3: Bonus Functions

### Linked List Operations
Using the following structure:
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

Functions include:
- `ft_lstnew()` - Create new list node
- `ft_lstadd_front()` - Add node at beginning
- `ft_lstsize()` - Count list nodes
- `ft_lstlast()` - Get last node
- `ft_lstadd_back()` - Add node at end
- `ft_lstdelone()` - Delete single node
- `ft_lstclear()` - Delete entire list
- `ft_lstiter()` - Apply function to each node
- `ft_lstmap()` - Create new list with applied function

## Project Status
- Completed: November 11, 2023
- Score: 125/100 (with bonus)

## Contact
For any questions or suggestions regarding this documentation, please contact:
- 42 Intra: iatilla-
