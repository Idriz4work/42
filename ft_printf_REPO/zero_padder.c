/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:28:17 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/27 13:28:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	int_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	while (format[in++] >= '0' && format[in] <= '9')
		if (!(format[in + 1] >= 'i') && (!(format[in] >= '0'
					&& format[in] <= '9')))
			return (i - 1);
	in = 0;
	if (value < 0)
	{
		if (value == -2147483648)
			spaces -= 10;
		write(1, "-", 1);
		value *= -1;
		spaces--;
	}
	placeholder = value;
	if (!(format[i] >= '0' && format[i] <= '9'))
		return (i - 1);
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	if (format[i] >= '\t' && format[i] <= 'Z')
		return (i);
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (placeholder > 0)
	{
		placeholder /= 10;
		in++;
	}
	while (spaces-- > in)
		write(1, "0", 1);
	ft_putnbr_ext(value,bytes);
	return (i);
}

int	uns_handler(const char *format, int i, unsigned int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	in = value;
	if (value < 0)
	{
		in *= -1;
		value = 4294967295 - in;
	}
	placeholder = value;
	return (i);
}

int	hex_handler(const char *format, int i, unsigned int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	in = value;
	if (value < 0)
	{
		in *= -1;
		value = 4294967295 - in;
	}
	placeholder = value;
	return (i);
}

int	zero_padder(const char *format, int i, va_list args, int *bytes)
{
	char	buffer[20];
	int		spaces;

	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handler(format, i, va_arg(args, int), bytes);
	if (format[i] == 'u' || format[i] == 'U')
		i = uns_handler(format, i, va_arg(args, unsigned int), bytes);
	if (format[i] == 'x' || format[i] == 'X')
		i = hex_handler(format, i, va_arg(args, int), bytes);
	return (i);
}

