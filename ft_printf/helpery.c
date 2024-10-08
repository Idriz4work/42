#include "ft_printf.h"

void ft_putnbrEXT(int i)
{
    char curent;

    if (i < 0) {
        write(1, "-", 1);
        i = -i;
    }
    if (i >= 10) {
        ft_putnbrEXT(i / 10);  // Recursively print higher-order digits
    }

    curent = (i % 10) + '0';   // Get the last digit
    write(1, &curent, 1);      // Print the last digit
}

void ft_putUNSnbrEXT(unsigned int i)
{
    char curent;

    if (i >= 10) {
        ft_putnbrEXT(i / 10);  // Recursively print higher-order digits
    }

    curent = (i % 10) + '0';   // Get the last digit
    write(1, &curent, 1);      // Print the last digit
}

void putPointer(void *ptr)
{
    unsigned long address = (unsigned long)ptr;
    char buffer[20];  // Buffer to hold the string representation of the address
    char *hex = "0123456789abcdef";
    int i;

    buffer[0] = '0';
    buffer[1] = 'x';

    i = 2; 
    while(i < 18)
    {
        buffer[i] = hex[(address >> ((17 - i) * 4)) & 0xf];
        i++
    }
    buffer[18] = '\0';

    // Print the formatted address
    i = 0; 
    while (buffer[i] != '\0')
    {
        write(1, &buffer[i], 1);
        i++
    }
}

// Function to print a character using write()
void print_char(char c) {
    write(1, &c, 1);
}

// Helper function to print hexadecimal digits recursively
void print_hex_helper(unsigned int hex) {
    if (hex >= 16) {
        print_hex_helper(hex / 16);
    }

    char digit = "0123456789ABCDEF"[hex % 16];  // Get the hex digit
    print_char(digit);
}

// Function to print hexadecimal number
void print_hex(unsigned int hex) {
    write(1, "0x", 2);  // Print "0x" prefix
    print_hex_helper(hex);
}

// Helper function to print octal digits recursively
void print_octal_helper(unsigned int octal) {
    if (octal >= 8) {
        print_octal_helper(octal / 8);
    }
    // Get the octal digit
    char digit = '0' + (octal % 8);  
    print_char(digit);
}

// Function to print octal number
void print_octal(unsigned int octal) {
    write(1, "0", 1);  // Print "0" prefix
    print_octal_helper(octal);
}
