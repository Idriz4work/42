/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:11:11 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/15 14:05:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXE_H
#define PIPEXE_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

# include "../ft_printf/Libft/libft.h"
# include "../ft_printf/ft_printf_bonus.h"

int pipex(char **format,int output);
int handle_multiple_cmd(char **format);

#endif
