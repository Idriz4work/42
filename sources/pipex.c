/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/21 10:29:57 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	pipe_connecter(int fd[2], char **envp, char *shell_value)
// {
// }

// int	shell_executer(int fd[2], char **envp, char *shell_value)
// {
// 	char	*cmd_argv[5];
// 	char *inside_of_file;

// 	while (inside_of_file != NULL)
// 	{
// 		inside_of_file += get_next_line(fd[0]);
// 		ft_putstr_fd(inside_of_file,fd[1]);
// 	}
// 	cmd_argv[0] = "/bin/sh";
// 	cmd_argv[1] = "-c";
// 	cmd_argv[2] = shell_value;
// 	cmd_argv[3] = NULL;
// 	execve("/bin/sh", cmd_argv, envp); // Execute shell command
// 	perror("execve [pipe_connecter()]");
// 	exit(-1); // Exit if execve fails
// 	return (0);
// }

// int	handle_piper(char **av, int fd[2], char **envp, int cmd_counter)
// {
// 	pid_t	pid1;
// 	int identificator;
// 	char	*cmd_argv[5];

// 	identificator = -1;
// 	if (pipe(fd) == -1)
// 	{
// 		perror("error piping handler_piper()\n");
// 		return (-1);
// 	}
// 	pid1 = fork();
// 	if (pid1 == -1)
// 	{
// 		perror("fork error [handle_piper()]");
// 		return (-1);
// 	}
// 	if (pid1 == 0)
// 	{
// 		if (dup2(fd[0], STDIN_FILENO) < 0)
// 		{
// 			perror("dup2 fd[0]");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (dup2(fd[1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup2 fd[1]");
// 			exit(EXIT_FAILURE);
// 		}
// 		// Close the original file descriptors
// 		close(fd[0]);
// 		identificator = shell_executer(fd,envp,av[cmd_counter]);
// 		close(fd[1]);
// 		if (identificator == -1)
// 			return (identificator);
// 	}
// 	else
// 		waitpid(pid1, NULL, 0); // Wait for child process
// 	return (1);
// }

// int	handle_commands(int argc, char **av, char **envp, int fd[2])
// {
// 	int		cmd_counter;
// 	pid_t	pid;
// 	char	*cmd_argv[5];

// 	cmd_counter = 0;
// 	while (cmd_counter++ < argc - 2)
// 		if (handle_piper(av, fd, envp, cmd_counter) < 0)
// 			return (-1);
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork error [handle_commands()]");
// 		return (-1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (dup2(fd[0], STDIN_FILENO) < 0)
// 		{
// 			perror("dup2 input_fd[0]");
// 			exit(EXIT_FAILURE);
// 		}
// 		if (dup2(fd[1], STDOUT_FILENO) < 0)
// 		{
// 			perror("dup2 output_fd[1]");
// 			exit(EXIT_FAILURE);
// 		}
// 		// Close the original file descriptors
// 		close(fd[0]);
// 		close(fd[1]);
// 		shell_executer(fd,envp,av[cmd_counter]);
// 		exit(1);
// 	}
// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid, NULL, 0); // Wait for child process
// 	return (1);
// }

// fd[0] - read
// fd[1] - write
// envp - access to binaries environmental variables example:
// envp[0] = "PATH=/usr/bin:/bin";
// envp[1] = "HOME=/home/user";
// useful to call commands in execve()

// ./a.out "../tests/file1" "grep a1" "wc -w" "../tests/file2"
// int	main(int argc, char **av, char **envp)
// {
// 	int	fd[2];

// 	if (argc < 5)
// 	{
// 		printf("Usage: %s <input_file> <cmd1> <cmd2> ... <output_file>\n",
// 			av[0]);
// 		return (1);
// 	}
// 	if (access(av[1], F_OK) == -1)
// 	{
// 		printf("Cannot access input file: %s\n", av[1]);
// 		return (1);
// 	}
// 	fd[0] = open(av[1], O_RDONLY);
// 	fd[1] = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (fd[0] == -1 || fd[1] == -1)
// 	{
// 		perror("Error opening files");
// 		return (1);
// 	}
// 	if (handle_commands(argc, av, envp, fd) < 0)
// 		return (1);
// 	ft_printf("Successfully written to %s\n",av[argc - 1]);
// 	close(fd[0]);
// 	close(fd[1]);
// 	return (0);
// }

int	main(int argc, char **av, char **envp)
{
	int fd[2];
	int pipes[2];
	int pid;
	int shell_value = 1;
	char *cmd_argv[5];
	char *reading_buf;

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
	fd[0] = open(av[1], O_RDONLY);
	fd[1] = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[0] == -1 || fd[1] == -1)
	{
		perror("Error opening files");
		return (1);
	}
	while (shell_value != argc - 2)
	{
		pipes[0] = dup(fd[0]);
		pipes[1] = dup(fd[1]);
		// make new pipe
		if (pipe(pipes) == -1)
		{
			perror("ERROR PIPE 1\n");
			return (-1);
		}
		pid = fork();
		if (pid == 0)
		{
			dup2(pipes[0], STDIN_FILENO);
			dup2(pipes[1], STDOUT_FILENO);
			cmd_argv[0] = "/bin/sh";
			cmd_argv[1] = "-c";
			cmd_argv[2] = av[shell_value];
			cmd_argv[3] = NULL;
			execve("/bin/sh", cmd_argv, envp); // Execute shell command
			perror("execve [pipe_connecter()]");
			exit(-1); // Exit if execve fails
			close(pipes[1]);
			close(pipes[0]);
		}
		else
		{
			// Parent process reads output using get_next_line
			close(pipes[1]); // Close the write end of the pipe
			while ((reading_buf = get_next_line(fd[0])) != NULL)
			{
				ft_printf("%s", reading_buf); // Print each line
				free(reading_buf);           
					// Free the dynamically allocated line
			}
			close(pipes[0]); // Close the read end of the pipe
		}
		shell_value++;
	}
	ft_printf("Successfully written to %s\n", av[argc - 1]);
	close(fd[0]);
	close(fd[1]);
	return (0);
}