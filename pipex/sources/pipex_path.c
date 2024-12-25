/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 04:35:52 by iatilla-          #+#    #+#             */
/*   Updated: 2024/12/25 04:12:35 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_specific_bin(char **binaries)
{
	char	*bin_path;
	int		j;

	j = 0;
	bin_path = NULL;
	while (binaries[j++] != NULL)
	{
		bin_path = malloc(ft_strlen(binaries[j]) + ft_strlen("/sh") + 1);
		if (bin_path == NULL)
		{
			perror("Memory allocation failed\n");
			free(binaries); // Don't forget to free binaries array
			return (NULL);
		}
		ft_strlcpy(bin_path, binaries[j], ft_strlen(binaries[j]) + 1);
		ft_strlcat(bin_path, "/sh", ft_strlen(bin_path) + ft_strlen("/sh") + 1);
		if (access(bin_path, X_OK) == 0)
		{
			free(binaries);    // Free the split array as we're done with it
			return (bin_path); // Return the full path to "sh"
		}
		free(bin_path); // Free memory if the binary isn't found
	}
	return (bin_path);
}

char	*get_right_path(char **envp)
{
	char	*path;
	char	**binaries;
	int		i;

	path = NULL;
	binaries = NULL;
	i = 0;
	while (envp[i++] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")) == 0)
		{
			path = envp[i] + ft_strlen("PATH="); // Skip the "PATH=" part
			binaries = ft_split(path, ':');      // Split the path by ':'
			break ;
		}
	}
	path = get_specific_bin(binaries);
	if (path == NULL)
	{
		perror("PATH not found\n");
		return (NULL);
	}
	return (path); // Return NULL if "sh" was not found in any directory
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
