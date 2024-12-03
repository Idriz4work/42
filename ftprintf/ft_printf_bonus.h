/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:30:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/03 04:18:08 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int		handle_flags(const char *format, int i, va_list args, int *bytes);

int		zero_padder(const char *format, int i, va_list args, int *bytes);
int		int_handlerzero(const char *format, int i, int value, int *bytes);
int		uns_handlerzero(const char *format, int i, unsigned int value,
			int *bytes);
int		upperhex_handlerzero(const char *format, int i, int value, int *bytes);
int		lowerhex_handlerzero(const char *format, int i, int value, int *bytes);

int		int_handlerplus(const char *format, int i, int value, int *bytes);
// int	fieldminwidth(const char *format, int i, int spaces);

// int	alternativeForma(const char *format, int i, long hex_oct);

// int	left_justificator(const char *format, int i, int width);

// int	precisionstk(const char *format, int i, double digits);

// UTILITIES FOR BONUS
void	ft_putnbr_zero_uns(unsigned int i, int *bytes);
void	ft_putnbr_zero(int i, int *bytes);
#endif