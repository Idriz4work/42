/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:26:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/18 10:28:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

datatypes datatype;

int check_conditionpt2(const char *format, int i,va_list args)
{
    if (format[i] == 'i' || format[i] == 'd')
    {
        datatype.inte = va_arg(args, int);
        ft_putnbrEXT(datatype.inte);
        i++;
    }
    else if (format[i] == 'c')
    {
        datatype.ch = va_arg(args, int);
        write(1, &datatype.ch, 1);
        i++;
    }
    else if (format[i] == 'o')
    {
        datatype.octal = va_arg(args, unsigned int);
        print_octal(datatype.octal,1); 
        i++;
    }
    else if (format[i] == 'u')
    {
        datatype.uns = va_arg(args, unsigned int);
        ft_putnbrUNS(datatype.uns);
        i++;
    }
    return i;
}

int check_conditions(const char *format, int i, va_list args)
{
    void *current;
 
    i++;
    if ((format[i] == '%') && (!((format[i] >= 'a' && format[i] <= 'z') ||
    (format[i] >= 'A' && format[i] <= 'Z'))) && (!(format[i] >= '0' && format[i] <= '9')))
    {
        write(1,"%",1);
        return i + 1;
    }   
    if (format[i] == 's' || format[i] == 'S')
    {
        datatype.string = va_arg(args, char *);
        handle_strings(datatype.string,i);
        i++;
    }
    else if (format[i] == 'p')
    {
        current = va_arg(args, void*);
        putPointer(current);
        i++;
    }
    else if (format[i] == 'x' || format[i] == 'X')
    {
        datatype.hex = va_arg(args, unsigned int);
        print_hex(datatype.hex,1); 
        i++;
    }
    else
        i = check_conditionpt2(format,i,args);
    return i;
}

int ft_printf(const char *format, ...)
{
    int i;
    va_list args;
    va_start(args, format);

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            i = check_conditions(format, i, args);
        else
        {
            write(1, &format[i], 1);
            i++;
        }
    }
    va_end(args);
    return 0;
}

// int main()
// {
    // ft_printf("%x\n%s\n---\n",274655,"slnoide");
    // printf("%x\n%s\n",274655,"slnoide");
    // ft_printf("\n--------------\n%%\n%%\n");
    // printf("%%\n%%\n");
//     ft_printf(" %c",'0');
//     printf(" %c",'0');
//     ft_printf(" %c\n", '0' - 256);
//     ft_printf("%c \n", '0' + 256);
//     ft_printf("test1 %c %c %c \n", '0', 65, '1');
//     ft_printf("test2 %c %c %c \n", ' ', ' ', ' ');
//     ft_printf("test3 %c %c %c \n", '1', '2', '3');
//     ft_printf("test4 %c %c %c \n", '2', '1', 65);
//     ft_printf("test5 %c %c %c \n", 0, '1', '2');
// }