/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/02 20:55:03 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	pointer_helper_two(void *ptr, unsigned long memory_address, int *bytes)
{
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		*bytes += 5;
		return (-1);
	}
	write(1, "0x", 2);
	*bytes += 2;
	if (ptr == 0 || memory_address == 0)
	{
		write(1, "0", 1);
		*bytes += 1;
		return (-1);
	}
	return (0);
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
	i = pointer_helper_two(ptr, memory_address, bytes);
	if (i == -1)
		return ;
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

// functions to print hexadecimal digits
void	print_hex_two(unsigned int hex, int *bytes)
{
	char	hex_digits[8];
	int		i;

	i = 0;
	while (hex > 0)
	{
		hex_digits[i++] = "0123456789abcdef"[hex % 16];
		hex /= 16;
	}
	while (--i >= 0)
	{
		write(1, &hex_digits[i], 1);
		*bytes += 1;
	}
}

void	print_hex(unsigned int hex, int signal, int *bytes)
{
	char	hex_digits[8];
	int		i;

	i = 0;
	if (hex == 0)
	{
		write(1, "0", 1);
		*bytes += 1;
	}
	if (signal == 1)
	{
		print_hex_two(hex, bytes);
		return ;
	}
	while (hex > 0)
	{
		hex_digits[i++] = "0123456789ABCDEF"[hex % 16];
		hex /= 16;
	}
	while (--i >= 0)
	{
		write(1, &hex_digits[i], 1);
		*bytes += 1;
	}
}
