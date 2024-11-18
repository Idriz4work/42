/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/18 20:17:27 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "Libft/libft.h"
#include "ft_printf_bonus.h"

typedef struct
{
	int				inte;
	char			*string;
	int				ch;
	unsigned int	uns;
	unsigned int	hex;
	void			*pointer;
}					datatypes;

int					ft_printf(const char *format, ...);
int					check_conditions(const char *format, int i, va_list args);
int					check_conditionpt2(const char *format, int i, va_list args);

void				putPointer(void *ptr);
int					ft_atoi(const char *s);
void				handle_strings(char *format, int i);
void				print_hex(unsigned int hex, int signal);
void				ft_putnbrEXT(int i, int number);
void				ft_putnbrUNS(unsigned int i);
void				handle_strings(char *format, int i);

#endif
