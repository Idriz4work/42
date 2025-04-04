/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 05:11:11 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/04 00:08:46 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../includes/Libft/get_next_line/get_next_line.h"
# include "../includes/Libft/libft.h"
# include "../includes/ft_printf/ft_printf_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct pipe
{
	int		pipe[2];
	int		previous;
	int		input_fd;
	int		output_fd;
	char	*cmd;
	char	**executable_cmd;
}			t_pipex;

void		child_process(t_pipex *piper, char **envp);
void		parrent_process(t_pipex *piper, char **envp);
int			piper_process(char **av, char **envp, t_pipex *piper);
void		initialize_piper(t_pipex *piper, int argc, char **av);
int			parse_checker(int argc, char **av);

void		free_array(char **array);
char		*get_command_path(char **binaries, const char *cmd);
char		**path_extractor(char **envp);
void		execute_cmd(char *cmd, char **envp, t_pipex *piper);

#endif
