/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_fhalf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:39 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/23 10:05:58 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
#include "ft_printf_bonus.h"

int	zero_padder(const char *format, int i, int number, int *bytes)
{
	int		in;
	int written;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (number == 0)
		spaces--;
	while (format[in++] >= '0' && format[in] <= '9')
		if (!(format[in + 1] >= 'i') && (!(format[in] >= '0'
					&& format[in] <= '9')))
			return (i - 1);
	in = 0;
	if (number < 0)
	{
		if (number == -2147483648)
			spaces -= 10;
		written = write(1, "-", 1);
		
		number *= -1;
		spaces--;
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
		written = write(1, "0", 1);
	if (written > 0)
		*bytes += written;
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
