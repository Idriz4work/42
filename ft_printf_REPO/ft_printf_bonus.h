/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:32:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 15:55:48 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int		int_handler(const char *format, int i, int value, int *bytes);
int		str_handler(const char *format, int i, char *value, int *bytes);
int		ptr_handler(const char *format, int i, void *value, int *bytes);
int		uns_handler(const char *format, int i, unsigned int value, int *bytes);
int		hex_handler(const char *format, int i, unsigned int value, int *bytes);
int		handle_flags(const char *format, int i, va_list args, int *bytes);
// int	fieldminwidth(const char *format, int i, int spaces);
// int	alternativeForma(const char *format, int i, long hex_oct);
// int	signplus(const char *format, int i, int sign);
int		zero_padder(const char *format, int i, va_list args, int *bytes);
// int	left_justificator(const char *format, int i, int width);
// int	precisionstk(const char *format, int i, double digits);

// UTILITIES FOR BONUS
void	ft_putnbr_zero_uns(unsigned int i, int *bytes);
void	ft_putnbr_zero(int i, int *bytes);

#endif