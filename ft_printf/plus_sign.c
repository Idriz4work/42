/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:05:35 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/04 19:09:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

// int check_value(int value, int *bytes, long *placeholder, int spaces)
// {
// 	if (value < 0)
// 	{
// 		if (placeholder == -2147483648)
// 		{
// 			spaces -= 10;
// 			write(1, "-2", 2);
// 			*bytes+=2;
// 			placeholder = 147483648;
// 		}
// 		else
// 		{
// 			write(1,"-",1);
// 			*bytes+=1;
// 			placeholder *= -1;
// 			spaces -= 2;
// 		}
// 	}
// 	return (spaces);
// }

int	int_handlerplus(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	long	placeholder;
	int		spaces;

	spaces = 0;
	placeholder = value;
	if (value == 0)
		spaces--;
	if (placeholder == -2147483648)
	{
		spaces -= 10;
		write(1, "-2", 2);
		*bytes += 2;
		placeholder = 147483648;
	}
	else if (value < 0)
	{
		write(1, "-", 1);
		*bytes += 1;
		placeholder *= -1;
		value *= -1;
		spaces -= 1;
	}
	else if(value > 0)
	{
		write (1,"+",1);
		*bytes+=1;
	}
	while (format[i-- + 1] <= '%')
		;
	in = 0;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = 0;
	while (value > 0)
	{
		value /= 10;
		in++;
	}
	while (spaces-- > in)
	{
		write(1, " ", 1);
		*bytes += 1;
	}
	ft_putnbr_ext(placeholder, bytes);
	return (i + 1);
}
