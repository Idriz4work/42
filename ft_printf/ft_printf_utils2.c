/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:07:46 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/05 19:12:55 by iatilla-         ###   ########.fr       */
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

int	handle_cases_nbr(int i, int *bytes)
{
	int	written;

	if (i == -2147483648)
	{
		written = write(1, "-2147483648", 11);
		*bytes += written;
		return (-1);
	}
	if (i == 0)
	{
		written = write(1, "0", 1);
		*bytes += written;
		i--;
		return (-1);
	}
	return (0);
}

void	ft_putnbr_ext(long i, int *bytes)
{
	char	curent;
	int		written;

	written = handle_cases_nbr(i, bytes);
	if (written == -1)
		return ;
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
