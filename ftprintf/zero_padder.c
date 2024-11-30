/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:17:17 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/30 20:45:38 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

// int check_value(int value, int *bytes, long *placeholder, int spaces)
// {
// 	if (value < 0)
// 	{
// 		if (placeholder == -2147483648)
// 		{
// 			spaces -= 10;
// 			write(1, "-2", 2);
// 			*bytes+=2;
// 			placeholder = 147483648;
// 		}
// 		else
// 		{
// 			write(1,"-",1);
// 			*bytes+=1;
// 			placeholder *= -1;
// 			spaces -= 2;
// 		}
// 	}
// 	return (spaces);
// }

int	int_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long	placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	if (placeholder == -2147483648)
	{
		spaces -= 10;
		write(1, "-2", 2);
		*bytes += 2;
		placeholder = 147483648;
	}
	else if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		placeholder *= -1;
		value *= -1;
		spaces -= 1;
	}
	while (format[i-- + 1] <= '%')
		;
	in = 0;
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
	ft_putnbr_ext(placeholder, bytes);
	return (i);
}

int	uns_handler(const char *format, int i, unsigned int value, int *bytes)
{
	int				in;
	char			buffer[20];
	unsigned int	placeholder;
	int				spaces;

	in = i;
	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	while (format[i-- + 1] <= '%')
		;
	in = 0;
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
	if (placeholder == 0)
		return (i - 1);
	return (i);
}

int	lowerhex_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long	placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	// if (placeholder == -2147483648)
	// {
	// 	spaces -= 10;
	// 	write(1, "-2", 2);
	// 	*bytes += 2;
	// 	placeholder = 147483648;
	// }
	if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		placeholder *= -1;
		value *= -1;
		spaces -= 1;
	}
	while (format[i-- + 1] <= '%')
		;
	in = 0;
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
	print_hex(value, 0, bytes);
	return (i);
}

int	upperhex_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long	placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	// if (placeholder == -2147483648)
	// {
	// 	spaces -= 10;
	// 	write(1, "-2", 2);
	// 	*bytes += 2;
	// 	placeholder = 147483648;
	// }
	if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		placeholder *= -1;
		value *= -1;
		spaces -= 1;
	}
	while (format[i-- + 1] <= '%')
		;
	in = 0;
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
	print_hex(value, 1, bytes);
	return (i);
}

int	zero_padder(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handler(format, i, va_arg(args, int), bytes);
	if (format[i] == 'u')
		i = uns_handler(format, i, va_arg(args, unsigned int), bytes);
	if (format[i] == 'x')
		i = lowerhex_handler(format, i, va_arg(args, int), bytes);
	if (format[i] == 'X')
		i = upperhex_handler(format, i, va_arg(args, int), bytes);
	return (i);
}
