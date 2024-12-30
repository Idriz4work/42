/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/30 04:59:16 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(pipex *piper, char **envp, int cmd_index, int argc)
{

	execute_cmd(piper->cmd, envp, piper);
}

void	parrent_process(pipex *piper)
{

}

int	piper_process(int argc, char **av, char **envp, pipex *piper)
{
	int	shell_value;
	int	pid;

	shell_value = 2;
	while (shell_value != argc - 1)
	{
		piper->cmd = av[shell_value];
		if (pipe(piper->pipe) == -1)
		{
			perror("Pipe creation failed");
			return (-1);
		}
		pid = fork();
		if (pid == 0)
			child_process(piper, envp, shell_value, argc);
		if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			parrent_process(piper);
		}
		shell_value++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

void	initialize_piper(pipex *piper, int argc, char **av)
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

int	parse_checker(int argc, char **av, char **envp)
{
	if (argc < 5)
	{
		printf("Usage: %s <input_file> <cmd1> ... <output_file>\n", av[0]);
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
	pipex	piper;

	if (parse_checker(argc, av, envp) == -1)
		return (-1);
	initialize_piper(&piper, argc, av);
	if (piper_process(argc, av, envp, &piper) == -1)
	{
		perror("Failed to handle commands\n");
		return (-1);
	}
	close(piper.output_fd);
	printf("Successfully written to %s\n", av[argc - 1]);
	return (0);
}
