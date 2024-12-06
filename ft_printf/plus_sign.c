/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 04:05:35 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/06 01:14:09 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	handle_sign_and_update(int value, int *bytes, int *spaces)
{
	if (value >= 0)
	{
		write(1, "+", 1);
		(*bytes)++;
	}
	else
		*spaces -= 1;
}

int	extract_spaces_plus(const char *format, int *i)
{
	char	buffer[20];
	int		index;

	index = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
		buffer[index++] = format[(*i)++];
	buffer[index] = '\0';
	return (ft_atoi(buffer));
}

int	int_handlerplus(const char *format, int i, int value, int *bytes)
{
	long	placeholder;
	int		spaces;
	int		digits;

	placeholder = value;
	spaces = 0;
	handle_sign_and_update(value, bytes, &spaces);
	spaces += extract_spaces_plus(format, &i);
	if (placeholder < 0)
		placeholder *= -1;
	digits = count_value_length(placeholder, 10);
	placeholder = value;
	write_spaces(spaces, digits, bytes);
	if (value == -2147483648)
	{
		write(1, "-2147483648", 11);
		*bytes += 11;
		return (i);
	}
	ft_putnbr_ext(placeholder, bytes);
	return (i);
}

// --------------- FUNCTIONAL CODE ---------------------

// int	int_handlerplus(const char *format, int i, int value, int *bytes)
// {
// 	int		in;
// 	char	buffer[20];
// 	long	placeholder;
// 	int		spaces;

// 	spaces = 0;
// 	placeholder = value;
// 	if (value == 0)
// 		spaces--;
// 	if (value >= 0)
// 	{
// 		write(1,"+",1);
// 		*bytes+=1;
// 	}
// 	if (value < 0)
// 	{
// 		placeholder *= -1;
// 		spaces -= 1;
// 	}
// 	in = 0;
// 	while (format[i] >= '0' && format[i] <= '9')
// 		buffer[in++] = format[i++];
// 	buffer[in] = '\0';
// 	spaces += ft_atoi(buffer);
// 	in = 0;
// 	while (placeholder > 0)
// 	{
// 		placeholder /= 10;
// 		in++;
// 	}
// 	placeholder = value;
// 	while (spaces-- > in)
// 	{
// 		write(1, " ", 1);
// 		*bytes += 1;
// 	}
// 	if (value == -2147483648)
// 	{
// 		write(1,"-2147483648",11);
// 		*bytes += 11;
// 		return (i);
// 	}
// 	ft_putnbr_ext(placeholder, bytes);
// 	return (i);
// }
