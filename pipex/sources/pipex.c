/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/15 15:01:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexe.h"

// char *find_rightbinary(char **format)
// {
// 	char *binary;
// 	char *path;
// 	int fd;
// 	int i;

// 	path = "~/bin/";
// 	while ()	
// 	{

// 		i++;
// 	}
// 	return binary;
// }

// int	pipex(char **format, int output_file)
// {
// 	int		index;
// 	char *pathfor_cmd;

// 	pathfor_cmd = find_rightbinary(format);
// 	index = 0;
// 	while (index != 4)
// 	{
// 		if (access(output_file) == 0)
// 		{
// 			ft_putstr_fd(format[index],output_file);
// 			ft_putchar_fd('\n',output_file);
// 			execve(pathfor_cmd,format[index],"hello");
// 		}
// 		else
// 		{
// 			perror("No access to write file: [%s]\n",format[3]);
// 			return -1;
// 		}
// 		// ft_printf("%s\n", format[index]);
// 		index++;
// 	}
	
// 	return index;
// }
// 	// handle_functions(|]);

// int	handle_multiple_cmd(char **format)
// {
// 	int i;

// 	i = 0;
// 	return (i);
// }

// fd[0] -  read
// fd[1] - write
// envp - access to binaries enviromental variables example:
// envp[0] = "PATH=/usr/bin:/bin";
// envp[1] = "HOME=/home/user"; 
// usefull to call commands in execve()

int	main(int argc, char **av, char **envp)
{
 int fd[2];
 pid_t pid1, pid2;
			
   if (argc != 5) 
   {
       ft_printf("Usage: %s <in file> <cmd1> <cmd2> <output_file>\n", av[0]);
       return (1);
   }
   if (pipe(fd) == -1) // Create the pipe
   {
       perror("pipe");
       return (1);
   }
   // First child process
   pid1 = fork();
   if (pid1 == -1)
   {
       perror("fork");
       return (1);
   }
   if (pid1 == 0) // Child process for argv[1]
   {
       int output_fd;
       close(fd[0]); // Close read end of pipe
       dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
       close(fd[1]); // Close pipe write end after duplicating
       char *cmd1_argv[] = {"/bin/sh", "-c", av[2], NULL}; // Command arguments
       execve("/bin/sh", cmd1_argv, envp); // Execute command
       perror("execve"); // Execve failed
       exit(1);
   }
   // Second child process
   pid2 = fork();
   if (pid2 == -1)
   {
       perror("fork");
       return (1);
   }
   if (pid2 == 0) // Child process for argv[2]
   {
       int output_fd;
       close(fd[1]); // Close write end of pipe
       dup2(fd[0], STDIN_FILENO); // Redirect stdin to pipe read end
       close(fd[0]); // Close pipe read end after duplicating
       output_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // Open output file
       if (output_fd == -1)
       {
           perror("open");
           exit(1);
       }
       dup2(output_fd, STDOUT_FILENO); // Redirect stdout to output file
       close(output_fd); // Close output file after duplicating
       char *cmd2_argv[] = {"/bin/sh", "-c", av[3], NULL}; // Command arguments
       execve("/bin/sh", cmd2_argv, envp); // Execute command
       perror("execve"); // Execve failed
       exit(1);
   }
   // Parent process
   close(fd[0]); // Close read end of pipe
   close(fd[1]); // Close write end of pipe
   waitpid(pid1, NULL, 0); // Wait for first child to finish
   waitpid(pid2, NULL, 0); // Wait for second child to finish
   return (0);
}

