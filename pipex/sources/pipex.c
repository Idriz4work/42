/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 04:47:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../bonus_src/pipexery.h"

int	main(int argc, char **av, char **envp)
{
	int	pid;
	int	shell_value;

	int inout_fd[2]; // File descriptors for input and output (file)
	int pipe_fd[2];  // Pipe file descriptors
	shell_value = 2; // Start after the input file and first command
	if (argc < 5)
	{
		printf("Usage: %s <input_file> <cmd1> <cmd2> ... <output_file>\n",
			av[0]);
		return (1);
	}
	if (ft_strncmp(av[1],"here_doc",8) == 0)
	{
		handle_bonus(argc,av,envp);
		return 0;
	}
	if (access(av[1], F_OK) == -1)
	{
		printf("Cannot access input file: %s\n", av[1]);
		return (1);
	}
	inout_fd[0] = open(av[1], O_RDONLY);
	inout_fd[1] = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (shell_value != argc - 1)
	{
		shell_value++;
		if (shell_value == argc - 1)
			break ;
		if (pipe(pipe_fd) == -1)
		{
			perror("Pipe creation failed");
			return (-1);
		}
		pid = fork();
		if (pid == 0)
		{
			dup2(inout_fd[0], STDIN_FILENO);
			if (shell_value == argc - 2)
				dup2(inout_fd[1], STDOUT_FILENO);
			else
				dup2(pipe_fd[1], STDOUT_FILENO);
			close(inout_fd[0]);
			close(inout_fd[1]);
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execute_cmd(av[shell_value], envp);
		}
		if (pid > 0)
		{
			waitpid(pid, NULL, 0);
			close(inout_fd[0]);
			close(pipe_fd[1]);
			inout_fd[0] = pipe_fd[0];
		}
	}
	printf("Successfully written to %s\n", av[argc - 1]);
	while (wait(NULL) > 0)
		;
	close(inout_fd[1]);
	return (0);
}
