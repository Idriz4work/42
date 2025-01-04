/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 22:06:25 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/07 17:10:12 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	handle_flags(const char *format, int i, va_list copy, int *bytes)
{
	i++;
	if (format[i] == '0')
		i = zero_padder(format, i, copy, bytes);
	if (format[i] == '+')
		i = int_handlerplus(format, i + 1, va_arg(copy, int), bytes);
	if (format[i] == ' ')
		i = fieldminwidth(format, i, copy, bytes);
	if (format[i] == '#')
		i = alterforma(format, i, copy, bytes);
	while ((format[i] >= 'a' && format[i] <= 'z') || (format[i] >= 'A'
			&& format[i] <= 'Z'))
		i++;
	return (i);
}
	// if (format[i + 1] == '-')
	// 	i = left_justificator(format, i, copy,bytes);
	// if (format[i] == '.')
	// 	i = precisionstk(format, i, va_arg(copy, double),bytes);
