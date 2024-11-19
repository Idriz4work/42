/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 23:26:58 by marvin            #+#    #+#             */
/*   Updated: 2024/11/19 20:20:12 by iatilla-         ###   ########.fr       */
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
	else if (format[i++] == 'c')
		write(1, &format[i], 1);
	else if (format[i] == 'u')
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
	if ((format[i] == '%') && (!((format[i] >= 'a' && format[i] <= 'z')
				|| (format[i] >= 'A' && format[i] <= 'Z')))
		&& (!(format[i] >= '0' && format[i] <= '9')))
	{
		write(1, "%", 1);
		return (i + 1);
	}
	if (format[i] == 's' || format[i] == 'S')
	{
		datatype.string = va_arg(args, char *);
		handle_strings(datatype.string, i);
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

int	ft_printf(const char *format, ...)
{
	int			i;
	va_list		args;
	datatypes	datatype;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = handle_flags(format, i, args);
			i = check_conditions(format, i, args, datatype);
		}
		write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main(void)
// {
// 	ft_printf("%s\n\\r","yo whaqt up");
// 	printf("%s\n\\r","yo whaqt up");
	
// 	ft_printf("%s\n","yo whaqt up dbe");
// 	printf("%s\n","yo whaqt up");
	
// 	ft_printf("%s\n\\r","yo whaqt up");
// 	printf("%s\n\\r","yo whaqt up");
	
// 	ft_printf("%s\n\\r","yo whaqt up");
// 	printf("%s\n\\r","yo whaqt up");
// }
