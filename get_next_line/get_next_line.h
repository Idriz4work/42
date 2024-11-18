/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+ +:+         */
/*   By: iatilla- <iatilla-@student.42.fr>        +#+  +:+ +#+            */
/*                                                +#+#+#+#+#+   +#+         */
/*   Created: 2024/11/18 12:59:23 by iatilla-         #+# #+#              */
/*   Updated: 2024/11/18 13:16:06 by iatilla-        ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		allocate_once(char **valueholder);
int		read_file(char **valueholder, int bytes, int fd);
char	*insert_line(char **valueholder);
void	update_holder(char **valueholder);
int		freeler(char **s1, char **s2, char **s3);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s1, char c);

#endif