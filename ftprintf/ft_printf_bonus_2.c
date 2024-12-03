/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:14:04 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/03 04:18:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

// int	fieldminwidth(const char *format, int i,int spaces)
// {
// 	return (i);
// }

// int	alternativeForma(const char *format, int i,long hex_oct)
// {
// 	return (i);
// }

int	handle_flags(const char *format, int i, va_list copy, int *bytes)
{
	i++;
	// if (format[i+1] == '-')
	// 	i = left_justificator(format, i,va_arg(copy,int));
	if (format[i] == '+')
	{
		while (!(format[i] >= 'A' && format[i] <= 'z'))
			i++;
		i = int_handlerplus(format, i, va_arg(copy, int), bytes);
	}
	// if (format[i] == ' ')
	// 	i = fieldminwidth(format, i,va_arg(copy,int));
	// if (format[i] == '#')
	// 	i = alternativeForma(format, i,va_arg(copy,long));
	if (format[i] == '0')
		i = zero_padder(format, i, copy, bytes);
	// if (format[i] == '.')
	// 	i = precisionstk(format, i,va_arg(copy,double));
	return (i);
}
