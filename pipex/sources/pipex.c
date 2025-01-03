/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/04 00:05:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex *piper, char **envp)
{
	dup2(piper->input_fd, STDIN_FILENO);
	dup2(piper->pipe[1], STDOUT_FILENO);
	close(piper->pipe[0]);
	close(piper->pipe[1]);
	execute_cmd(piper->cmd, envp, piper);
}

void	parrent_process(t_pipex *piper, char **envp)
{
	dup2(piper->pipe[0], STDIN_FILENO);
	dup2(piper->output_fd, STDOUT_FILENO);
	close(piper->pipe[0]);
	close(piper->pipe[1]);
	execute_cmd(piper->cmd, envp, piper);
}

int	piper_process(char **av, char **envp, t_pipex *piper)
{
	int	pid;

	piper->cmd = av[2];
	if (pipe(piper->pipe) == -1)
	{
		perror("Pipe creation failed");
		return (-1);
	}
	pid = fork();
	if (pid == 0)
		child_process(piper, envp);
	if (pid > 0)
	{
		waitpid(pid, NULL, 0);
		piper->cmd = av[3];
		parrent_process(piper, envp);
	}
	close(piper->pipe[1]);
	while (wait(NULL) > 0)
		;
	return (0);
}

int	parse_checker(int argc, char **av)
{
	if (argc < 5)
	{
		printf("Usage: %s <file1> <cmd1> <cmd2> <file2>\n", av[0]);
		return (-1);
	}
	if (access(av[1], F_OK) == -1)
	{
		perror("Cant access files\n");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **av, char **envp)
{
	t_pipex	piper;

	if (parse_checker(argc, av) == -1)
		return (-1);
	initialize_piper(&piper, argc, av);
	if (piper_process(av, envp, &piper) == -1)
	{
		perror("Failed to handle commands\n");
		return (-1);
	}
	close(piper.output_fd);
	ft_printf("Successfully written to %s\n", av[argc - 1]);
	return (0);
}
