/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:05 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 10:33:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putnbr_zero_uns(unsigned int i, int *bytes)
{
	char	curent;
	unsigned int reducer;

	reducer = 0;
	if (i == 4294967295 || i == -1)
	{
		write(1,"4294967295",12);
		*bytes += 12;
		return ;
	}
	if (i < 0)
		reducer = -i;
	i -= reducer;
	if (i >= 10)
		ft_putnbr_zero_uns(i / 10, bytes);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
	*bytes += 1;
	return ;
}

void	ft_putnbr_zero(int i, int *bytes)
{
	char	curent;

	if (i == -2147483648)
	{
		write(1, "2147483648", 11);
		*bytes += 11;
		return ;
	}
	if (i < 0)
		i = -i;
	if (i >= 10)
		ft_putnbr_zero(i / 10, bytes);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
	*bytes += 1;
	return ;
}
