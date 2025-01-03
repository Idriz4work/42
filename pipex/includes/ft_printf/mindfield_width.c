/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mindfield_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 00:48:54 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/06 00:48:59 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	int_handlermin_width(int i, int value, int *bytes)
{
	long	placeholder;
	int		spaces;

	spaces = 1;
	if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		value *= -1;
		spaces -= 1;
	}
	placeholder = value;
	write_spaces(spaces, 0, bytes);
	if (value == -2147483648)
	{
		write(1, "2147483648", 10);
		*bytes += 10;
		return (i);
	}
	ft_putnbr_ext(placeholder, bytes);
	return (i + 1);
}

int	str_handlermin_width(const char *format, int i, char *value, int *bytes)
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

int	fieldminwidth(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'i' || format[i] == 'd')
		i = int_handlermin_width(i, va_arg(args, int), bytes);
	if (format[i] == 's')
		i = str_handlermin_width(format, i, va_arg(args, char *), bytes);
	return (i);
}
