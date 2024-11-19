/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_shalf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:14:04 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/19 18:37:57 by iatilla-         ###   ########.fr       */
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

// int	signplus(const char *format, int i,int sign)
// {
// 	return (i);
// }

int	handle_flags(const char *format, int i, va_list args)
{
	va_list	copy;

	va_copy(copy, args);
	// if (format[i+1] == '-')
	// 	i = left_justificator(format, i,va_arg(copy,int));
	// if (format[i+1] == '+')
	// 	i = signplus(format, i,va_arg(copy,int));
	// if (format[i+1] == ' ')
	// 	i = fieldminwidth(format, i,va_arg(copy,int));
	// if (format[i+1] == '#')
	// 	i = alternativeForma(format, i,va_arg(copy,long));
	if (format[i+1] == '0')
	{
		i++;
		i = zero_padder(format, i, va_arg(copy, int));
	}
	// if (format[i+1] == '.')
	// 	i = precisionstk(format, i,va_arg(copy,double));
	return (i);
}
