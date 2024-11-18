/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:32:14 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/18 20:16:58 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

int	signplus(const char *format, int i);
int	alternativeForma(const char *format, int i);
int	fieldminwidth(const char *format, int i);
int	zero_padder(const char *format, int i, int number);
int	left_justificator(const char *format, int i);
int	precisionstk(const char *format, int i);
int	handle_flags(const char *format, int *i, va_list args);
#endif