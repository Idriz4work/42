/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:26:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/23 08:08:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	check_conditionpt2(const char *format, int i, va_list args,
		datatypes datatype)
{
	if (format[i] == 'i' || format[i] == 'd')
	{
		datatype.inte = va_arg(args, int);
		ft_putnbr_ext(datatype.inte);
		i++;
	}
	else if (format[i] == 'c')
	{
		datatype.ch = va_arg(args, int);
		write(1, &datatype.ch, 1);
		i++;
	}
	else if (format[i] == 'u' || format[i - 1] == 'u')
	{
		datatype.uns = va_arg(args, unsigned int);
		ft_putnbr_uns(datatype.uns);
		i++;
	}
	return (i);
}

int	check_conditions(const char *format, int i, va_list args,
		datatypes datatype)
{
	void	*current;

	i++;
	if (format[i] == 's')
	{
		datatype.string = va_arg(args, char *);
		handle_strings(datatype.string);
		i++;
	}
	else if (format[i] == 'p')
	{
		current = va_arg(args, void *);
		put_pointer(current);
		i++;
	}
	else if (format[i] == 'x' || format[i] == 'X')
	{
		datatype.hex = va_arg(args, unsigned int);
		if (format[i] == 'x')
			print_hex(datatype.hex, 1);
		else
			print_hex(datatype.hex, 2);
		i++;
	}
	else
		i = check_conditionpt2(format, i, args, datatype);
	return (i);
}

int calculate_bytes(int i, const char *format)
{
	int bytes;

	bytes = 0;
	return bytes;
}

int	ft_printf(const char *format, ...)
{
	int			i;
	int			bytes;
	va_list		args;
	va_list		copy;
	datatypes	datatype;

	va_copy(copy, args);
	va_start(args, format);
	i = 0;
	bytes = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (!(format[i + 1] >= 'a' && format[i + 1] <= 'z')
				&& !(format[i + 1] >= 'A' && format[i + 1] <= 'Z')
				&& format[i + 1] != '%' && !(format[i + 1] >= '0'
					&& format[i + 1] <= '9'))
			{
				write(1, "%", 1);
				bytes++;
				i++;
				continue ;
			}
			if (format[i + 1] == '%')
			{
				i += 2;
				bytes++;
				write(1, "%", 1);
				continue ;
			}
			i = check_conditions(format, i, args, datatype);
			bytes++;
			continue ;
		}
		bytes += calculate_bytes(i,format);
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (bytes);
}

// i = handle_flags(format, i, copy);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void)
// {
// 	ft_printf("%d\n",032);
// 	printf("%d\n",032);

// ft_printf("%s\n","yo whaqt up dbe");
// printf("%s\n","yo whaqt up");

// ft_printf("%s\n\\r","yo whaqt up");
// printf("%s\n\\r","yo whaqt up");

// ft_printf("%s\n\\r","yo whaqt up");
// printf("%s\n\\r","yo whaqt up");
// }
