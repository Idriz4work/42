/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:34:12 by iatilla-          #+#    #+#             */
/*   Updated: 2025/01/15 22:05:32 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	process_points(char *content, map	*points)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(content, ' ');
	while (numbers[i] != NULL && numbers[i+1] != NULL)
	{
		mlx_pixel_put(points->ptr_server_mlx, points->ptr_window_mlx,
			255, ft_atoi(numbers[i]), 255);
		mlx_pixel_put(points->ptr_server_mlx, points->ptr_window_mlx,
			ft_atoi(numbers[i+1]), 255, 155);
		i++;
	}
	return (0);
}

int	read_input(char *filename,map *points)
{
	int		fd;
	char	*content;

	ft_printf("hello read\n");
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (-1);
	content = get_next_line(fd);
	while (content != NULL)
	{
		if (process_points(content,points) == -1)
        {
            close(fd);
            return (-1);
        }
        free(content);
        content = get_next_line(fd);
	}
	return (0);
}

int	initiliaze_window(map *points, char *argv)
{
	ft_printf("server startet...\n");
	points->ptr_server_mlx = mlx_init();
	if (!points->ptr_server_mlx)
		return (-1);
	points->ptr_window_mlx = mlx_new_window(points->ptr_server_mlx, 800, 800,
			"yeni pencere");
	if (!points->ptr_window_mlx)
	{
		mlx_destroy_window(points->ptr_server_mlx, points->ptr_window_mlx);
		free(points->ptr_server_mlx);
		points->ptr_server_mlx = NULL;
		return (-1);
	}
	if (read_input(argv,points) == -1)
		return (-1);
	mlx_loop(points->ptr_server_mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	map	points;
	if (argc == 2)
	{
		if (initiliaze_window(&points, argv[1]) == -1)
			return (-1);
	}
	return (1);
}