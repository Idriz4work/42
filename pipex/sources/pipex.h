/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:11:11 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 01:24:56 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "../Libft/libft.h"
# include "../ft_printf/ft_printf_bonus.h"
#include "../Libft/get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void	execute_cmd(char *cmd, char **envp);
char	*get_right_path(char **envp);

// typedef struct path{
// 	char *path;
	
// } pathy;

#endif
