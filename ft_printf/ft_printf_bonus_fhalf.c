/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_fhalf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:39 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/19 11:52:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

datatypes datatype;

int	zero_padder(const char *format, int i, int number)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = 0;
	spaces = 0;
	placeholder = number;
	i++;
	if (!(format[i] >= '0' && format[i] <= '9'))
		return (i - 1);
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces = ft_atoi(buffer);
	in = 0;
	while (placeholder > 0)
	{
		placeholder /= 10;
		in++;
	}
	while (spaces-- > in)
		write(1, "0", 1);
	return (i);
}

int	left_justificator(const char *format, int i)
{
	return (i);
}

int	precisionstk(const char *format, int i)
{
	return (i);
}
