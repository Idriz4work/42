#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "helpery.c"

typedef struct {
    int inte;             // For 'd', 'i' (signed integer)
    long lon;             // For 'l' (long integer)
    char *string;         // For 's', 'S' (string)
    char ch;              // For 'c', 'C' (character)
    unsigned int uns;     // For 'u', 'U' (unsigned integer)
    unsigned int octal;   // For 'o', 'O' (octal)
    unsigned int hex;     // For 'x', 'X' (hexadecimal)
    void *pointer;        // For 'p' (pointer address)
} datatypes;

int is_digit(char ce);
void putPointer(void *ptr);
int ft_atoi(const char *str);
void print_octal(unsigned int octal);
void print_hex(unsigned int hex);
void print_hex_helper(unsigned int hex);
void print_char(char c);
void ft_putUNSnbrEXT(unsigned int i);
void ft_putnbrEXT(int i);
void handle_strings(char *format,int i);
int is_alpha(char ce);

#endif
