/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:11:11 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/27 15:44:50 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../Libft/get_next_line/get_next_line.h"
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

char	*get_specific_bin(char **binaries);
char	*get_right_path(char **envp);
void	execute_cmd(char *cmd, char **envp);

typedef struct pipe
{
	int pipe[2];
	int previous;
	int output_fd;
	int input_fd;
	char *cmd[5];
} pipex ;

#endif // PIPEX_H
