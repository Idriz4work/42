/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justificator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:54:30 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/06 03:52:40 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	int_handlerlft(const char *format, int i, int value, int *bytes)
{
	long	placeholder;
	int		spaces;
	int		digits;

	placeholder = value;
	spaces = 0;
	handle_sign_and_update(value, bytes, &spaces);
	spaces += extract_spaces_plus(format, &i);
	if (placeholder < 0)
		placeholder *= -1;
	digits = count_value_length(placeholder, 10);
	placeholder = value;
	write_spaces(spaces, digits, bytes);
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		*bytes += 11;
		return (i);
	}
	ft_putnbr_ext(placeholder, bytes);
	return (i);
}

int	uns_handlerlft(const char *format, int i, unsigned int value, int *bytes)
{
	long	placeholder;
	int		spaces;
	int		digits;

	placeholder = value;
	spaces = 0;
	handle_sign_and_update(value, bytes, &spaces);
	spaces += extract_spaces_plus(format, &i);
	if (placeholder < 0)
		placeholder *= -1;
	digits = count_value_length(placeholder, 10);
	placeholder = value;
	write_spaces(spaces, digits, bytes);
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		*bytes += 11;
		return (i);
	}
	ft_putnbr_uns(placeholder, bytes);
	return (i);
}

int	lowerhex_handlerlft(const char *format, int i, int value, int *bytes)
{
	long	placeholder;
	int		spaces;
	int		digits;

	placeholder = value;
	spaces = 0;
	handle_sign_and_update(value, bytes, &spaces);
	spaces += extract_spaces_plus(format, &i);
	if (placeholder < 0)
		placeholder *= -1;
	digits = count_value_length(placeholder, 10);
	placeholder = value;
	write_spaces(spaces, digits, bytes);
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		*bytes += 11;
		return (i);
	}
	print_hex(placeholder, 1, bytes);
	return (i);
}

int	upperhex_handlerlft(const char *format, int i, int value, int *bytes)
{
	long	placeholder;
	int		spaces;
	int		digits;

	placeholder = value;
	spaces = 0;
	handle_sign_and_update(value, bytes, &spaces);
	spaces += extract_spaces_plus(format, &i);
	if (placeholder < 0)
		placeholder *= -1;
	digits = count_value_length(placeholder, 10);
	placeholder = value;
	write_spaces(spaces, digits, bytes);
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		*bytes += 11;
		return (i);
	}
	print_hex(placeholder, 0, bytes);
	return (i);
}

int	str_handlerlft(const char *format, int i, char *value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		spaces;

	spaces = 0;
	in = 0;
	while (format[i - 1] != '%')
		i--;
	if (format[i] == ' ')
		i++;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = ft_strlen(value);
	while (spaces-- > in)
	{
		write(1, " ", 1);
		*bytes += 1;
	}
	handle_strings(value, bytes);
	return (i + 1);
}

int	char_hanlderlft(const char *format, int i, char *value, int *bytes)
{
	
	return (i);
}

int	left_justificator(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'c')
		i = uns_handlerlft(format, i, va_arg(args, unsigned int), bytes);
	// if (format[i] == 's')
	// 	i = uns_handlerlft(format, i, va_arg(args, unsigned int), bytes);
	// if (format[i] == 'i' || format[i] == 'd')
	// 	i = int_handlerlft(format, i, va_arg(args, int), bytes);
	// if (format[i] == 'p')
	// 	i = uns_handlerlft(format, i, va_arg(args, unsigned int), bytes);
	// if (format[i] == 'u')
	// 	i = uns_handlerlft(format, i, va_arg(args, unsigned int), bytes);
	// if (format[i] == 'x')
	// 	i = lowerhex_handlerlft(format, i, va_arg(args, int), bytes);
	// if (format[i] == 'X')
	// 	i = upperhex_handlerlft(format, i, va_arg(args, int), bytes);
	return (i);
}