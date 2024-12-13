/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:36:20 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/18 16:04:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipexe.h"

int pipe_connecter(char **av, int argc, char **envp, int cmd_counter)
{
    int fd[2];
    int fd2[2];
    pid_t pid1;
    char *cmd_argv[999];

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return (-1);
    }
    if (pid1 == 0) // Child process for argv[2]
    {
        close(fd[1]); // Close write end of pipe
        dup2(fd[0], STDOUT_FILENO); // Redirect stdin to pipe read end
        cmd_argv[0] = "/bin/sh";
        cmd_argv[1] = "-c";
        cmd_argv[2] = av[cmd_counter];
        cmd_argv[3] = NULL;
        execve("/bin/sh", cmd_argv, envp);    
        // close(fd[0]); // Close pipe read end after duplicating
    }
    if (pipe(fd) == -1) // Create the pipe
    {
        perror("pipe");
        return (-1);
    }
    else
    {
        close(fd[0]); // Close read end of pipe
        close(fd[1]); // Close write end of pipe        
    }
    waitpid(pid1,NULL,0);
    return (1);
}

int handle_piper(char **av, int argc, char **envp, int cmd_counter)
{
    int fd[2];
    pid_t pid1;
    int output_fd;
    char *cmd_argv[5];

    pid1 = fork();
    if (pid1 == -1)
    {
        perror("fork");
        return (-1);
    }
    if (pid1 == 0)
    {
        close(fd[0]); // Close read end of pipe
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(fd[1]); // Close pipe write end after duplicating
        cmd_argv[0] = "/bin/sh";
        cmd_argv[1] = "-c";
        cmd_argv[2] = av[cmd_counter];
        cmd_argv[3] = NULL;
        execve("/bin/sh", cmd_argv, envp); // Execute command
        perror("execve handle_piper()\n");
        exit(1);            
    }
    else
    {
        pipe_connecter(av,argc,envp,cmd_counter);
        close(fd[0]); // Close read end of pipe
        close(fd[1]); // Close write end of pipe
        waitpid(pid1, NULL, 0); 
    }
    return 1;
}

int handle_commands(int argc, char **av, char **envp)
{
    int cmd_counter;
    char *cmd_argv[5];
    int output_fd;
    pid_t pid;

    cmd_counter = 1;
    while (ft_strncmp(av[cmd_counter++], av[argc - 1], ft_strlen(av[argc - 1])) != 1)
        handle_piper(av, argc, envp, cmd_counter);
    output_fd = open(av[argc - 1], O_WRONLY | O_CREAT, 0644); 
    pid = fork();
    if (output_fd == -1 || pid == -1)
    {
        perror("open/forking error [handle_commands()]");
        exit(1);
        return -1;
    }
    if (pid == 0)
    {
        dup2(output_fd, STDOUT_FILENO); // Redirect stdout to output file
        close(output_fd); // Close output file after duplicating
        cmd_argv[0] = "/bin/sh";
        cmd_argv[1] = "-c";
        cmd_argv[2] = av[cmd_counter];
        cmd_argv[3] = NULL;
        execve("/bin/sh", cmd_argv, envp);
        perror("execve [handle_commands()]");
        exit(1);
    }
    waitpid(pid,NULL,0);
    return (1);
}

// fd[0] - read
// fd[1] - write
// envp - access to binaries environmental variables example:
// envp[0] = "PATH=/usr/bin:/bin";
// envp[1] = "HOME=/home/user";
// useful to call commands in execve()

// ./a.out "../tests/file1" "grep a1" "wc -w" "../tests/file2"
int main(int argc, char **av, char **envp)
{
    int i;

    i = 0;
    if (argc != 5)
    {
        ft_printf("Usage: %s <in file> <cmd1> <cmd2> <output_file>\n", av[0]);
        return (1);
    }
    // if (access(av[1], F_OK) == -1 || (access(av[argc - 1], F_OK) == -1))
    // {
    //     ft_printf("Cant access files\n");
    //     return -2;
    // }
    i = handle_commands(argc, av, envp);
    if (i < 0)
        return -1;
    return (0);
}
