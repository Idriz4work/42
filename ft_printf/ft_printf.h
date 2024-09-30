#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct
{
    int inte;             // For 'd', 'i' (signed integer)
    long lon;             // For 'l' (long integer)
    char *string;         // For 's', 'S' (string)
    char ch;              // For 'c', 'C' (character)
    unsigned int uns;     // For 'u', 'U' (unsigned integer)
    unsigned int octal;   // For 'o', 'O' (octal)
    unsigned int hex;     // For 'x', 'X' (hexadecimal)
    void *pointer;        // For 'p' (pointer address)
} datatypes;
