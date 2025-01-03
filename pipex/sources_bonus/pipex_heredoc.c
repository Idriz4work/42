/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:43:53 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/03 23:54:31 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	child_process(char **envp, int cmd_index, int argc)
// {
// 	pipex	piper;

// 	dup2(piper.previous, STDIN_FILENO);
// 	if (cmd_index == argc - 1)
// 		dup2(piper.output_fd, STDOUT_FILENO);
// 	else
// 		dup2(piper.pipe[1], STDOUT_FILENO);
// 	close(piper.previous);
// 	close(piper.pipe[1]);
// 	execute_cmd(piper.cmd, envp);
// }

// void	parrent_process(void)
// {
// 	pipex	piper;

// 	dup2(piper.previous, piper.input_fd);
// 	close(piper.previous);
// }

// int	piper_process(int argc, char **av, char **envp)
// {
// 	int		shell_value;
// 	int		pid;
// 	pipex	piper;

// 	shell_value = 2;
// 	while (shell_value != argc - 1)
// 	{
// 		piper.cmd = ft_strdup(av[shell_value]);
// 		if (pipe(piper.pipe) == -1)
// 		{
// 			perror("Pipe creation failed");
// 			return (-1);
// 		}
// 		pid = fork();
// 		if (pid == 0)
// 			child_process(envp, shell_value, argc);
// 		if (pid > 0)
// 		{
// 			waitpid(pid, NULL, 0);
// 			parrent_process();
// 		}
// 		shell_value++;
// 	}
// 	return (0);
// }

// void handle_bonus()
// {
	
// }

// int	parse_checker(int argc, char **av, char **envp)
// {
// 	int	i;

// 	i = 0;
// 	if (argc < 5)
// 	{
// 		printf("Usage: %s <input_file> <cmd1> ... <output_file>\n", av[0]);
// 		return (-1);
// 	}
// 	if (av[2] == "here_doc")
// 		handle_bonus();
// 	while (av[i++] != NULL)
// 	{
// 		if (i != argc - 1)
// 		{
// 			if (access(av[1], F_OK) == -1 || access(av[argc - 1], F_OK) == -1)
// 			{
// 				perror("Cant access files\n");
// 				return (-1);
// 			}
// 			if (check_for_cmd(argc,av[i],envp) == -1)
// 				return (-1);
// 		}
// 	}
// 	return (0);
// }

// int	main(int argc, char **av, char **envp)
// {
// 	pipex	piper;

// 	if (parse_checker(argc, av, envp) == -1)
// 	{
// 		perror("Failed at check values\n");
// 		return (-1);
// 	}
// 	piper.previous = open(av[1], O_RDONLY);
// 	piper.output_fd = open(av[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (piper_process(argc, av, envp) == -1)
// 	{
// 		perror("Failed to handle commands\n");
// 		return (-1);
// 	}
// 	printf("Successfully written to %s\n", av[argc - 1]);
// 	while (wait(NULL) > 0)
// 		;
// 	close(piper.output_fd);
// 	return (0);
// }
