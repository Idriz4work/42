/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:22:23 by iatilla-            #+#    #+#           */
/*   Updated: 2024/11/07 18:22:23 by iatilla-           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define IFDEF BUFFER_SIZE

#define ENDIF

char	*get_next_line(const int fd);
int		allocateonce(int first_iteration, char **valueholder);
int		read_file(char **valueholder, int bytes, int fd);
char	*insert_line(char **valueholder);
void	update_holder(char **valueholder);

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s1, char c);
