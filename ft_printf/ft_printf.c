#include "ft_printf.h"
#include "helpery.c"

datatypes datatype;

int check_conditionpt2(const char *format, int i,va_list args)
{
    if (format[i] == 'i' || format[i] == 'd') {
        datatype.inte = va_arg(args, int);
        ft_putnbrEXT(datatype.inte);
        i++;
    }
    else if (format[i] == 'c') {
        datatype.ch = (char)va_arg(args, int);
        write(1, &datatype.ch, 1);
        i++;
    }
    else if (format[i] == 'o') {
        datatype.octal = va_arg(args, unsigned int);
        print_octal(datatype.octal); 
        i++;
    }
    else if (format[i] == 'u') {
        datatype.uns = va_arg(args, unsigned int);
        ft_putUNSnbrEXT(datatype.uns);
        i++;
    }
    return i;
}

// Helper function for string conversion
int ft_atoi(const char *str)
{
    int result = 0;
    int i = 0;
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}


int checkforSpace(const char *format, int i)
{
    char buffer[20] = {0}; // Initialize buffer with zeros
    int in = 0;
    int spaces;
    
    i++;
    
    if (!(format[i] >= '0' && format[i] <= '9'))
        return i - 1;
    
    while (format[i] >= '0' && format[i] <= '9')
        buffer[in++] = format[i++];
    buffer[in] = '\0';
    
    spaces = ft_atoi(buffer);
    while (spaces-- > 1)
        write(1, " ", 1);
    
    return i - 1;
}

int check_conditions(const char *format, int i, va_list args) {
    if ((format[i] == '%' && (!(format[i+1]) >= 'a' && format[i+1] >= 'Z') ||
    (format[i+1] >= 'A' && format[i+1] <= 'Z')))
    {
        write(1,"%",1);
        return i + 1;
    }
    
    i++;
    if (format[i] == 's' || format[i] == 'S') {
        datatype.string = va_arg(args, char *);
        handle_strings(datatype.string,i);
        i++;
    }
    else if (format[i] == 'p')
    {
        void *current = va_arg(args, void*);
        putPointer(current);
        i++;
    }
    else if (format[i] == 'x' || format[i] == 'X') {
        datatype.hex = va_arg(args, unsigned int);
        print_hex(datatype.hex); 
        i++;
    }
    else
        i = check_conditionpt2(format,i,args);
    return i;
}

// Main ft_printf function stays the same
int ft_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int i;

    i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%')
        {
            i = checkforSpace(format, i);
            i = check_conditions(format, i, args);
        }
        else
        {
            write(1, &format[i], 1);
            i++;
        }
    }
    va_end(args);
    return 0;
}

int main()
{
    ft_printf("Aviye is back %4i\n%\n%\n%s\n",274655,"slnoide");
}
