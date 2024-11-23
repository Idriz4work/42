/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:32:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/23 09:52:22 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"


int		handle_flags(const char *format, int i, va_list args, int *bytes);
// int	fieldminwidth(const char *format, int i, int spaces);
// int	alternativeForma(const char *format, int i, long hex_oct);
// int	signplus(const char *format, int i, int sign);
int		zero_padder(const char *format, int i, int number, int *bytes);
// int	left_justificator(const char *format, int i, int width);
// int	precisionstk(const char *format, int i, double digits);

void	ft_putnbr_zero(int i,int *bytes);

#endif