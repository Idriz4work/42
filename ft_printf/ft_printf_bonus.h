/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:30:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/04 17:32:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int		handle_flags(const char *format, int i, va_list args, int *bytes);

// bonus 1 complete 1 one those flags [-0.]
int		zero_padder(const char *format, int i, va_list args, int *bytes);
int		int_handlerzero(const char *format, int i, int value, int *bytes);
int		uns_handlerzero(const char *format, int i, unsigned int value,
			int *bytes);
int		upperhex_handlerzero(const char *format, int i, int value, int *bytes);
int		lowerhex_handlerzero(const char *format, int i, int value, int *bytes);


int	left_justificator(const char *format, int i, va_list args, int *bytes);


int	precission_stk(const char *format, int i, va_list args, int *bytes);

// bonus 2 complete all flags [+ #]
int		int_handlerplus(const char *format, int i, int value, int *bytes);

int	fieldminwidth(const char *format, int i, va_list args, int *bytes);
int int_handlermin_width(const char *format, int i, int value, int *bytes);
int str_handlermin_width(const char *format, int i, char *value, int *bytes);

int	alterforma(const char *format, int i, va_list args, int *bytes);
int	lowerhex_handleralt(const char *format, int i, int value, int *bytes);
int	upperhex_handleralt(const char *format, int i, int value, int *bytes);


// UTILITIES FOR BONUS
void	ft_putnbr_zero_uns(unsigned int i, int *bytes);
void	ft_putnbr_zero(int i, int *bytes);
#endif