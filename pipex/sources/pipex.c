/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 02:05:39 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h> // For access function

char	*get_right_path(char **envp)
{
	char	*path;
	char	**binaries;
	int		i;
	char	*cmd;

	path = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			binaries = ft_split(path, ':');
			break ;
		}
		i++;
	}
	if (!path)
	{
		fprintf(stderr, "PATH variable not found.\n");
		return (NULL);
	}
	for (i = 0; binaries[i] != NULL; i++)
	{
		cmd = ft_strjoin(binaries[i], "/sh");
		if (access(cmd, X_OK) == 0)
		{
			for (int j = 0; binaries[j] != NULL; j++)
				free(binaries[j]);
			free(binaries);
			return (cmd);
		}
		free(cmd);
	}
	fprintf(stderr, "/bin/sh not found.\n");
	for (int j = 0; binaries[j] != NULL; j++)
		free(binaries[j]);
	free(binaries);
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*path;
	char	*cmd_argv[4];

	path = get_right_path(envp);
	if (!path)
		exit(1);
	cmd_argv[0] = path;
	cmd_argv[1] = "-c";
	cmd_argv[2] = cmd;
	cmd_argv[3] = NULL;
	execve(path, cmd_argv, envp);
	perror("execve failed");
	free(path);
	exit(1);
}

int	main(int argc, char **av, char **envp)
{
	int	pid;
	int	shell_value;
	char *cmd_argv[4]; // Might not be necessary in this code snippet,
	int inout_fd[2];   // File descriptors for input and output (file)
	int pipe_fd[2];    // Pipe file descriptors
	shell_value = 2; // Start after the input file and first command
	if (argc < 5)
	{
		printf("Usage: %s <input_file> <cmd1> <cmd2> ... <output_file>\n",
			av[0]);
		return (1);
	}
	if (access(av[1], F_OK) == -1)
	{
		printf("Cannot access input file: %s\n", av[1]);
		return (1);
	}
	inout_fd[0] = open(av[1], O_RDONLY);
	if (inout_fd[0] == -1)
	{
		perror("Failed to open input file");
		return (1);
	}
	inout_fd[1] = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (inout_fd[1] == -1)
	{
		perror("Failed to open output file");
		return (1);
	}
	while (shell_value != argc - 1)
	{
		shell_value++;
		if (shell_value == argc - 1)
			break ;
		// Create a pipe
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
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execute_cmd(av[shell_value], envp);
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0); // Wait for child to finish
			close(inout_fd[0]);
			close(pipe_fd[1]);
			inout_fd[0] = pipe_fd[0];
		}
		else
		{
			perror("Fork failed");
			return (-1);
		}
	}
	printf("Successfully written to %s\n", av[argc - 1]);

	while (wait(NULL) > 0)
		;

	close(inout_fd[1]);
	return (0);
}
