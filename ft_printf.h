/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/21 11:52:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
#include <limits.h>
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
int					check_conditions(const char *format, int i, va_list args,
						datatypes datatype);
int					check_conditionpt2(const char *format, int i, va_list args,
						datatypes datatype);

void				put_pointer(void *ptr);
int					ft_atoi(const char *s);
void				handle_strings(char *format, int i);
void				print_hex(unsigned int hex, int signal);
void				ft_putnbr_ext(int i);
void				ft_putnbr_uns(unsigned int i);

#endif
