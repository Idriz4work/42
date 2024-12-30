/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:05 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/06 00:47:31 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	extract_spaces(const char *format, int *i)
{
	char	buffer[20];
	int		index;

	index = 0;
	while (format[*i - 1] != '%')
		(*i)--;
	while (format[*i] >= '0' && format[*i] <= '9')
		buffer[index++] = format[(*i)++];
	buffer[index] = '\0';
	return (ft_atoi(buffer));
}

int	count_value_length(long value, int divide_value)
{
	int	digit_length;

	digit_length = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= divide_value;
		digit_length++;
	}
	return (digit_length);
}

void	write_spaces(int spaces, int digits, int *bytes)
{
	while (spaces-- > digits)
	{
		write(1, " ", 1);
		(*bytes)++;
	}
}

void	write_zeros(int spaces, int digits, int *bytes)
{
	while (spaces-- > digits)
	{
		write(1, "0", 1);
		(*bytes)++;
	}
}

void	handle_negative(long *value, int *spaces, int *bytes)
{
	if (*value < 0)
	{
		write(1, "-", 1);
		(*bytes)++;
		*value *= -1;
		(*spaces)--;
	}
}
