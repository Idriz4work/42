/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:17:17 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/27 21:25:23 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	int_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	while (format[i-- + 1] <= '%')
		;
	in = 0;
	if (value < 0)
	{
		if (placeholder == -2147483648)
			spaces -= 10;
		write(1, "-", 1);
		*bytes+=1;
		placeholder *= -1;
		value *= -1;
		spaces--;
	}
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (value > 0)
	{
		value /= 10;
		in++;
	}
	while (spaces-- > in)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	ft_putnbr_ext(placeholder,bytes);
	return (i);
}

// int	uns_handler(const char *format, int i, unsigned int value, int *bytes)
// {
// 	int		in;
// 	char	buffer[20];
// 	int		placeholder;
// 	int		spaces;

// 	in = i;
// 	spaces = 0;
// 	if (value == 0)
// 		spaces--;
// 	in = value;
// 	if (value < 0)
// 	{
// 		in *= -1;
// 		value = 4294967295 - in;
// 	}
// 	placeholder = value;
// 	return (i);
// }

// int	hex_handler(const char *format, int i, unsigned int value, int *bytes)
// {
// 	int		in;
// 	char	buffer[20];
// 	int		placeholder;
// 	int		spaces;

// 	in = i;
// 	spaces = 0;
// 	if (value == 0)
// 		spaces--;
// 	in = value;
// 	if (value < 0)
// 	{
// 		in *= -1;
// 		value = 4294967295 - in;
// 	}
// 	placeholder = value;
// 	return (i);
// }

int	zero_padder(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handler(format, i, va_arg(args, int), bytes);
	// if (format[i] == 'u' || format[i] == 'U')
	// 	i = uns_handler(format, i, va_arg(args, unsigned int), bytes);
	// if (format[i] == 'x' || format[i] == 'X')
	// 	i = hex_handler(format, i, va_arg(args, int), bytes);
	return (i);
}
