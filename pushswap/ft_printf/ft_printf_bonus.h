/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:30:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/07 17:09:54 by iatilla-         ###   ########.fr       */
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

// bonus 2 complete all flags [+ #]
int		int_handlerplus(const char *format, int i, int value, int *bytes);

int		fieldminwidth(const char *format, int i, va_list args, int *bytes);
int		int_handlermin_width(int i, int value, int *bytes);
int		str_handlermin_width(const char *format, int i, char *value,
			int *bytes);

int		alterforma(const char *format, int i, va_list args, int *bytes);
int		lowerhex_handleralt(int i, int value, int *bytes);
int		upperhex_handleralt(int i, int value, int *bytes);

// UTILITIES FOR BONUS
int		extract_spaces(const char *format, int *i);
int		count_value_length(long value, int divide_value);
void	write_zeros(int spaces, int digits, int *bytes);
void	handle_negative(long *value, int *spaces, int *bytes);
void	handle_sign_and_update(int value, int *bytes, int *spaces);
void	write_spaces(int spaces, int digits, int *bytes);
int		extract_spaces_plus(const char *format, int *i);
// int		left_justificator(const char *format, int i, va_list args,
			// int *bytes);
// int		int_handlerlft(const char *format, int i, int value, int *bytes);
// int		uns_handlerlft(const char *format, int i, unsigned int value,
// 			int *bytes);
// int		lowerhex_handlerlft(const char *format, int i, int value,
			// int *bytes);
// int		upperhex_handlerlft(const char *format, int i, int value,
			// int *bytes);
// int		str_handlerlft(const char *format, int i, char *value, int *bytes);

// int		precission_stk(const char *format, int i, va_list args, int *bytes);
#endif