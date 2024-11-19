/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:09:05 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/19 16:00:38 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_bonus.h"

void	ft_putnbr_zero(int i)
{
	char	curent;

	if (i == -2147483648)
	{
		write(1, "2147483648", 11);
		return ;
	}
	if (i < 0)
		i = -i;
	if (i >= 10)
		ft_putnbr_zero(i / 10);
	curent = (i % 10) + '0';
	write(1, &curent, 1);
	return ;
}
