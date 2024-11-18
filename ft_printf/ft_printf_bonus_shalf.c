/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_shalf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:14:04 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/18 20:18:05 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	fieldminwidth(const char *format, int i)
{
	return (i);
}

int	alternativeForma(const char *format, int i)
{
	return (i);
}

int	signplus(const char *format, int i)
{
	return (i);
}

int	handle_flags(const char *format, int *i, va_list args)
{
	int	number;

	number = 0;
	if (format[i] == '-')
		*i = left_justificator(format, i);
	if (format[i] == '+')
		*i = signplus(format, i);
	if (format[i] == ' ')
		*i = fieldminwidth(format, i);
	if (format[i] == '#')
		*i = alternativeForma(format, i);
	if (format[i] == '0')
	{
		number = va_arg(args,int);
		*i = zero_padder(format, i, number);
	}
	if (format[i] == '.')
		*i = precisionstk(format, i);
	return (number);
}
