/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alter_forma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 03:41:51 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/06 01:18:21 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	lowerhex_handleralt(int i, int value, int *bytes)
{
	int			in;
	long long	placeholder;

	if (value == 0)
	{
		write(1, "0", 1);
		*bytes += 1;
		return (i + 1);
	}
	placeholder = value;
	in = 0;
	write(1, "0x", 2);
	*bytes += 2;
	in = 0;
	print_hex(placeholder, 1, bytes);
	return (i);
}

int	upperhex_handleralt(int i, int value, int *bytes)
{
	int			in;
	long long	placeholder;

	if (value == 0)
	{
		write(1, "0", 1);
		*bytes += 1;
		return (i + 1);
	}
	placeholder = value;
	in = 0;
	write(1, "0X", 2);
	*bytes += 2;
	in = 0;
	print_hex(placeholder, 0, bytes);
	return (i);
}

int	alterforma(const char *format, int i, va_list args, int *bytes)
{
	while (!(format[i] >= 'A' && format[i] <= 'z'))
		i++;
	if (format[i] == 'x')
		i = lowerhex_handleralt(i, va_arg(args, int), bytes);
	else if (format[i] == 'X')
		i = upperhex_handleralt(i, va_arg(args, int), bytes);
	return (i);
}
