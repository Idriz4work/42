/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:13:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/26 18:31:37 by iatilla-         ###   ########.fr       */
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

typedef struct datatypes
{
	int				inte;
	char			*string;
	int				ch;
	unsigned int	uns;
	void			*pointer;
	unsigned int hex;
	size_t			number;
}					t_datatype;

int					ft_printf(const char *format, ...);
int					handle_percent(const char *format, int *i, int *bytes);
int					check_conditions(const char *format, int i, va_list args,
						int *bytes);
int					check_conditionpt2(const char *format, int i, va_list args,
						int *bytes);

void				handle_strings(char *format, int *bytes);
void				pointer_helper(char buffer[2048], int i, int *bytes);
int					pointer_helper_two(void *ptr, unsigned long memory_address,
						int *bytes);
void				put_pointer(void *ptr, int *bytes);
void				print_hex_two(unsigned int hex, int *bytes);
void				print_hex(unsigned int hex, int signal, int *bytes);
int					handle_cases_nbr(int i, int *bytes);
void				ft_putnbr_ext(int i, int *bytes);
void				ft_putnbr_uns(unsigned int i, int *bytes);

#endif
