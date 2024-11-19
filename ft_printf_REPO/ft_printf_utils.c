/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/19 19:53:20 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_strings(char *format, int i)
{
	int	j;

	j = 0;
	if (format == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (format[j] != '\0')
		write(1, &format[j++], 1);
}

void	ft_putnbr_ext(int i)
{
	char	curent;

	if (i == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (i == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_ext(i / 10);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
	return ;
}

void	ft_putnbr_uns(unsigned int i)
{
	char	curent;

	if (i >= 10)
		ft_putnbr_ext(i / 10);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
}

void	put_pointer(void *ptr)
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
	{
		if (hex >= 16)
			print_hex(hex / 16, 1);
		digit = "0123456789abcdef"[hex % 16];
		write(1, &digit, 1);
	}
	if (signal == 2)
	{
		if (hex >= 16)
			print_hex(hex / 16, 2);
		digit = "0123456789ABCDEF"[hex % 16];
		write(1, &digit, 1);
	}
}
