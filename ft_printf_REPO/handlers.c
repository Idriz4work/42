/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:28:17 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 18:45:24 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

int	int_handler(const char *format, int i, int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		spaces;

	in = i;
	while (format[in] != '%')
		in--;
	in++;
	while (format[i] >= '0' && format[i] <= '9')
		buffer[in++] = format[i++];
	buffer[in] = '\0';
	spaces += ft_atoi(buffer);
	in = value;
	while (in > 9)
	{
		spaces--;
		in /= 10;
	}
	while (spaces-- > 0)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	return (i);
}

int	str_handler(const char *format, int i, char *value, int *bytes)
{
	int		in;
	char	buffer[20];
	char	*placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	placeholder = value;
	if (!(format[i] >= '0' && format[i] <= '9'))
		return (i - 1);
	return (i);
}

int	ptr_handler(const char *format, int i, void *value, int *bytes)
{
	int		in;
	char	buffer[20];
	char	*placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	placeholder = value;
	return (i);
}

int	uns_handler(const char *format, int i, unsigned int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	in = value;
	if (value < 0)
	{
		in *= -1;
		value = 4294967295 - in;
	}
	placeholder = value;
	return (i);
}

int	hex_handler(const char *format, int i, unsigned int value, int *bytes)
{
	int		in;
	char	buffer[20];
	int		placeholder;
	int		spaces;

	in = i;
	spaces = 0;
	if (value == 0)
		spaces--;
	in = value;
	if (value < 0)
	{
		in *= -1;
		value = 4294967295 - in;
	}
	placeholder = value;
	return (i);
}
