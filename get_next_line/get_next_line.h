#include "libft/libft.h"

#define BUFF_SIZE 102 // 1024 = 1 chunk

int	get_next_line(const int fd, char **line);
int read_file(char **valueholder, char **line, int bytes, int fd);
char *insert_line(char **line, char **valueholder);
int freeler(char *s1, char *s2, char *s3);
void    update_holder(char **valueholder, int i);