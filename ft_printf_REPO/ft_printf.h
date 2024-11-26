/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 10:31:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct
{
	int				inte;
	char			*string;
	int				ch;
	unsigned int	uns;
	unsigned int	hex;
	void			*pointer;
	size_t			number;
}					datatypes;

int					ft_printf(const char *format, ...);
int					handle_percent(const char *format, int *i, int *bytes);
int					check_conditions(const char *format, int i, va_list args,
						int *bytes);
int					check_conditionpt2(const char *format, int i, va_list args,
						int *bytes);

void				pointer_helper(char buffer[2048], int i, int *bytes);
void				put_pointer(void *ptr, int *bytes);
void				handle_strings(char *format, int *bytes);
void				print_hex(unsigned int hex, int signal, int *bytes);
void				ft_putnbr_ext(int i, int *bytes);
void				ft_putnbr_uns(unsigned int i, int *bytes);

#endif
