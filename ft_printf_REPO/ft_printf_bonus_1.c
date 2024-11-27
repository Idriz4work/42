/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:39 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/27 12:34:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

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

// int	left_justificator(const char *format, int i,int width)
// {
// 	return (i);
// }

// int	precisionstk(const char *format, int i, double digits)
// {
// 	return (i);
// }
