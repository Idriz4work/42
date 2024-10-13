// #include "libtft/."
#include "libft/libft.h"
// #include "libt_ft/ft_strdup.c"
#include <stdio.h>

#define BUFF_SIZE 10 // 1024 = 1 chunk

int	get_next_line(const int fd, char **line);
int read_file(char **valueholder, char **line, int bytes, int fd);
char *reset_valueholder(char **valueholder);
void freeall(char *temp, char *valueholder, int indicator);
char *insert_line(char **line, char **valueholder);
