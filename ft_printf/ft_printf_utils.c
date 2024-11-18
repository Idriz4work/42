/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/18 13:13:43 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	endresult;
	int	is_op;

	i = 0;
	endresult = 0;
	is_op = 1;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-' || s[i] == ' ')
	{
		if (s[i] == '-')
			is_op *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		endresult = endresult * 10 + s[i] - '0';
		i++;
	}
	return (is_op * endresult);
}

void	handle_strings(char *format, int i)
{
	int	j;

	j = 0;
	if (format == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	if (format[i] == 'S')
	{
		while (format[j] != '\0')
		{
			if (format[j] >= 'a' && format[j] <= 'z')
				format[j] -= 32;
			write(1, &format[j], 1);
			j++;
		}
	}
	else
		while (format[j] != '\0')
			write(1, &format[j++], 1);
}

void	ft_putnbrEXT(int i)
{
	char	curent;

	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbrEXT(i / 10);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
	return ;
}

void	ft_putnbrUNS(unsigned int i)
{
	char	curent;

	if (i >= 10)
		ft_putnbrEXT(i / 10);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
}

void	putPointer(void *ptr)
{
	unsigned long	address;
	char			buffer[20];
	char			*hex;
	int				i;

	address = (unsigned long)ptr;
	hex = "0123456789abcdef";
	buffer[0] = '0';
	buffer[1] = 'x';
	i = 2;
	while (i < 18)
	{
		buffer[i] = hex[(address >> ((17 - i) * 4)) & 0xf];
		i++;
	}
	buffer[18] = '\0';
	i = 0;
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

// Helper function to print hexadecimal digits recursively
void	print_hex(unsigned int hex, int signal)
{
	char	digit;

	if (signal == 1)
		write(1, "0x", 2);
	if (hex >= 16)
	{
		print_hex(hex / 16, 0);
	}
	digit = "0123456789ABCDEF"[hex % 16];
	write(1, &digit, 18);
}
