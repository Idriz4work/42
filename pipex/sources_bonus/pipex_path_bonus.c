/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:35:52 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/04 00:05:50 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*get_command_path(char **binaries, const char *cmd)
{
	char	*bin_path;
	int		j;

	j = 0;
	if (!cmd)
		return (NULL);
	while (binaries[j] != NULL)
	{
		bin_path = malloc(ft_strlen(binaries[j]) + ft_strlen(cmd) + 2);
		if (bin_path == NULL)
		{
			perror("Memory allocation failed\n");
			return (NULL);
		}
		ft_strlcpy(bin_path, binaries[j], ft_strlen(binaries[j]) + 1);
		ft_strlcat(bin_path, "/", ft_strlen(bin_path) + 2);
		ft_strlcat(bin_path, cmd, ft_strlen(bin_path) + ft_strlen(cmd) + 1);
		if (access(bin_path, X_OK) == 0)
			return (bin_path);
		free(bin_path);
		j++;
	}
	return (NULL);
}

char	**path_extractor(char **envp)
{
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			return (ft_split(*envp + 5, ':'));
		envp++;
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp, t_pipex *piper)
{
	char	**binaries;
	char	*cmd_path;

	piper->executable_cmd = ft_split(cmd, ' ');
	binaries = path_extractor(envp);
	if (!binaries)
	{
		perror("Failed to extract binaries from PATH");
		exit(1);
	}
	cmd_path = get_command_path(binaries, piper->executable_cmd[0]);
	piper->executable_cmd[0] = cmd_path;
	if (execve(cmd_path, piper->executable_cmd, envp) == -1)
	{
		perror("execve failed");
		free(cmd_path);
		free_array(piper->executable_cmd);
		exit(1);
	}
}

void	initialize_piper(t_pipex *piper, int argc, char **av)
{
	piper->cmd = NULL;
	piper->executable_cmd = NULL;
	piper->pipe[0] = 0;
	piper->pipe[1] = 0;
	piper->input_fd = open(av[1], O_RDONLY);
	if (piper->input_fd == -1)
		perror("Input file open failed");
	piper->previous = piper->input_fd;
	piper->output_fd = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (piper->output_fd == -1)
		perror("Output file open failed");
}
