/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/23 07:47:27 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	pipe_connecter(int fd[2], char **envp, char *shell_value)
// {
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

int	shell_executer(int before_fd[2], char **envp, char *shell_value)
{
	char	*cmd_argv[4];

	cmd_argv[0] = "/bin/sh";
	cmd_argv[1] = "-c";
	cmd_argv[2] = shell_value; // The shell command
	cmd_argv[3] = NULL;
	execve("/bin/sh", cmd_argv, envp); // Execute the command
	perror("execve failed");           // If execve returns, there was an error
	exit(1);                           // Exit with failure
}

 
int	main(int argc, char **av, char **envp)
{
	int		pid;
	int		shell_value;
	char	*cmd_argv[4];
	int		before_fd[2];
	int		current_fd[2];

	shell_value = 0;
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
	before_fd[0] = open(av[1], O_RDONLY);
	before_fd[1] = 1;//open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (shell_value != argc - 1)
	{
		shell_value++;
		if (shell_value == argc - 1)
			break;
		// make new pipe
		if (pipe(current_fd) == -1)
		{
			perror("ERROR PIPE 1\n");
			return (-1);
		}
		pid = fork();
		
		// CHILD
		if (pid == 0)
		{
			dup2(before_fd[0],STDIN_FILENO);
			if (shell_value == argc - 2)
				dup2(open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777),STDOUT_FILENO);
			else
				dup2(current_fd[1],STDOUT_FILENO);
			close(before_fd[1]);
			close(before_fd[0]);
			close(current_fd[0]);
			close(current_fd[1]);
			cmd_argv[0] = "/bin/sh";
			cmd_argv[1] = "-c";
			cmd_argv[2] = av[shell_value]; // The shell command
			cmd_argv[3] = NULL;
			execve("/bin/sh", cmd_argv, envp); // Execute the command
			perror("execve failed");           // If execve returns,
			exit(1);
		}
		// PARRENT
		if (pid > 0)
		{
			close(before_fd[0]);
			close(before_fd[0]);
			before_fd[0] = current_fd[0];
			before_fd[1] = current_fd[1];
		}
	}
	ft_printf("Successfully written to %s\n", av[argc - 1]);
	close(current_fd[0]);
	close(current_fd[1]);
	close(before_fd[0]);
	close(before_fd[1]);
	return (0);
}
