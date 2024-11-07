#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "helpery.c"

typedef struct {
    int inte;            
    long lon;            
    char *string;        
    char ch;             
    unsigned int uns;    
    unsigned int octal;  
    unsigned int hex;    
    void *pointer;       
} datatypes;

int is_digit(char ce);
int is_alpha(char ce);
void putPointer(void *ptr);
int ft_atoi(const char *str);
void print_octal(unsigned int octal);
void print_hex(unsigned int hex);
void print_hex_helper(unsigned int hex);
void print_char(char c);
void ft_putUNSnbrEXT(unsigned int i);
void ft_putnbrEXT(int i);
void handle_strings(char *format,int i);

#endif
