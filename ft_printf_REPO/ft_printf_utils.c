/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/23 23:21:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_strings(char *format, int *bytes)
{
	int	j;
	int	written;

	j = 0;
	if (format == NULL)
	{
		written = write(1, "(null)", 6);
		*bytes += written;
		return ;
	}
	while (format[j] != '\0')
	{
		written = write(1, &format[j], 1);
		*bytes += written;
		j++;
	}
}

void	ft_putnbr_ext(int i, int *bytes)
{
	char	curent;
	int		written;

	if (i == -2147483648)
	{
		written = write(1, "-2147483648", 11);
		*bytes += written;
		return ;
	}
	if (i == 0)
	{
		written = write(1, "0", 1);
		*bytes += written;
		return ;
	}
	if (i < 0)
	{
		written = write(1, "-", 1);
		*bytes += written;
		i = -i;
	}
	if (i >= 10)
		ft_putnbr_ext(i / 10, bytes);
	curent = (i % 10) + '0';
	written = write(1, &curent, 1);
	*bytes += written;
	return ;
}

void	ft_putnbr_uns(unsigned int i, int *bytes)
{
	char	curent;
	int		written;

	if (i >= 10)
		ft_putnbr_uns(i / 10, bytes);
	curent = (i % 10) + '0';
	written = write(1, &curent, 1);
	*bytes += written;
}

void	pointer_helper(char buffer[18], int j, int *bytes)
{
	int	written;

	while (j >= 0)
	{
		written = write(1, &buffer[j], 1);
		*bytes += written;
		j--;
	}
}

void	put_pointer(void *ptr, int *bytes)
{
	unsigned long	memory_address;
	char			buffer[18];
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	memory_address = 0;
	memory_address = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*bytes += 5;
		return ;
	}
	write(1, "0x", 2);
	*bytes += 2;
	if (ptr == 0 || memory_address == 0)
	{
		write(1, "0", 1);
		*bytes += 1;
		return ;
	}
	i = 0;
	while (i < 19)
		buffer[i++] = 0;
	i = 0;
	while (memory_address > 0)
	{
		buffer[i++] = hex[memory_address % 16];
		memory_address /= 16;
	}
	buffer[i] = '\0';
	pointer_helper(buffer, i - 1, bytes);
}

// function to print hexadecimal digits
void	print_hex(unsigned int hex, int signal, int *bytes)
{
	char	hex_digits[8];
	int		written;
	int		i;

	i = 0;
	if (hex == 0)
	{
		written = write(1, "0", 1);
		*bytes += written;
	}
	if (signal == 1)
	{
		while (hex != 0)
		{
			hex_digits[i++] = "0123456789abcdef"[hex % 16];
			hex /= 16;
		}
	}
	else
	{
		while (hex != 0)
		{
			hex_digits[i++] = "0123456789ABCDEF"[hex % 16];
			hex /= 16;
		}
	}
	while (--i >= 0)
	{
		written = write(1, &hex_digits[i], 1);
		*bytes += written;
	}
}
