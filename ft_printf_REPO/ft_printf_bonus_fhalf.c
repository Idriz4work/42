/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_fhalf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:39 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 10:39:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	zero_padder(const char *format, int i, int number, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (number == 0)
		spaces--;
	while (format[in++] >= '0' && format[in] <= '9')
		if (!(format[in + 1] >= 'i') && (!(format[in + 1] >= '0'
					&& format[in + 1] <= '9')))
			return (i - 1);
	in = 0;
	if (number < 0)
	{
		number *= -1;
		if (!number > INT_MAX)
		{
			if (number == -2147483648)
				spaces -= 10;
			write(1, "-", 1);
			*bytes += 1;
			spaces--;
		}
	}
	placeholder = number;
	if (!(format[i] >= '0' && format[i] <= '9'))
		return (i - 1);
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	if (format[i] >= '\t' && format[i] <= 'Z')
		return (i);
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (placeholder > 0)
	{
		placeholder /= 10;
		in++;
	}
	while (spaces-- > in)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	if (number > INT_MAX)
		ft_putnbr_zero_uns(number,bytes);
	else
		ft_putnbr_zero(number, bytes);
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
