/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_forma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 03:41:51 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/04 18:37:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	lowerhex_handleralt(const char *format, int i, int value, int *bytes)
{
	int			in;
	char		buffer[20];
	long long	placeholder;
	int			spaces;

	spaces = 0;
	if (value == 0)
		spaces--;
	else if (value == -2147483648 || value < 0)
		spaces -= 8;
	placeholder = value;
	while (format[i - 1] != '%')
		i--;
	in = 0;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (placeholder > 0)
	{
		placeholder /= 16;
		in++;
	}
	placeholder = value;
	while (spaces-- > in)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	print_hex(placeholder, 1, bytes);
	return (i + 1);
}

int	upperhex_handleralt(const char *format, int i, int value, int *bytes)
{
	int			in;
	char		buffer[20];
	long long	placeholder;
	int			spaces;

	spaces = 0;
	if (value == 0)
		spaces--;
	else if (value == -2147483648 || value < 0)
		spaces -= 8;
	placeholder = value;
	while (format[i - 1] != '%')
		i--;
	in = 0;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (placeholder > 0)
	{
		placeholder /= 16;
		in++;
	}
	placeholder = value;
	while (spaces-- > in)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	print_hex(placeholder, 0, bytes);
	return (i + 1);
}

int	alterforma(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'x')
		i = lowerhex_handleralt(format, i, va_arg(args, int), bytes);
	if (format[i] == 'X')
		i = upperhex_handleralt(format, i, va_arg(args, int), bytes);
	return (i);
}

