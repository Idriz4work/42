#include "ft_printf.h"
#include "helpery.c"

// datatypes datatype;

// Function to check and handle format specifiers
int check_conditions(const char *format, int i, va_list args) {
    int j = 0;
    int current;

    // Handle string and uppercase string
    if (format[i] == 's' || format[i] == 'S') {
        char *str = va_arg(args, char *);
        if (format[i] == 'S') { // Uppercase string
            while (str[j] != '\0') {
                if (str[j] >= 'a' && str[j] <= 'z')
                    str[j] -= 32;
                write(1, &str[j], 1);
                j++;
            }
        } else { // Normal string
            while (str[j] != '\0') {
                write(1, &str[j], 1);
                j++;
            }
        }
        i++;
    }

    // Handle integer and decimal
    else if (format[i] == 'i' || format[i] == 'd') {
        current = va_arg(args, int);
        ft_putnbrEXT(current);
        i++;
    }

    // Handle pointer (implement it if needed, currently stubbed)
    else if (format[i] == 'p') {
        // Handle pointer logic here
        i++;
    }

    // Handle hexadecimal
    else if (format[i] == 'x' || format[i] == 'X') {
        unsigned int hex = va_arg(args, unsigned int);
        print_hex(hex); // You need to implement this function as mentioned earlier
        i++;
    }

    // Handle character
    else if (format[i] == 'c') {
        char ch = (char)va_arg(args, int);
        write(1, &ch, 1);
        i++;
    }

    // Handle octal
    else if (format[i] == 'o') {
        unsigned int octal = va_arg(args, unsigned int);
        print_octal(octal); // You need to implement this function
        i++;
    }

    // Handle unsigned integer
    else if (format[i] == 'u') {
        unsigned int uns = va_arg(args, unsigned int);
        ft_putUNSnbrEXT(uns);
        i++;
    }
    if (format[i] == '%')
    {
        write(1,"%",1);
        i++;
    }
    return i;
}

// Main ft_printf function
int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++; // Skip the '%' character
            i = check_conditions(format, i, args); // Process the next character after '%'
        } else {
            write(1, &format[i], 1); // Print regular characters
            i++;
        }
    }

    va_end(args); // Clean up the va_list
    return 0;
}

int main()
{
    ft_printf("hello %% %x %s \n",20021,"yo what up");
}
