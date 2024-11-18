#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct {
    int inte;            
    long lon;            
    char *string;        
    int ch;             
    unsigned int uns;    
    unsigned int octal;  
    unsigned int hex;    
    void *pointer;       
} datatypes;

int ft_printf(const char *format, ...);
int check_conditions(const char *format, int i, va_list args);
int check_conditionpt2(const char *format, int i,va_list args);

void putPointer(void *ptr);
int	ft_atoi(const char *s);
void handle_strings(char *format,int i);
void print_octal(unsigned int octal,int signal);
void print_hex(unsigned int hex,int signal);
void ft_putnbrEXT(int i);
void ft_putnbrUNS(unsigned int i);
void handle_strings(char *format,int i);

#endif
