#include "libft/libft.h"

#define BUFF_SIZE 10

char *get_next_line(const int fd);
int read_file(char **valueholder,int bytes, int fd);
char *insert_line(char **line, char **valueholder);
int freeler(char **s1, char **s2, char **s3);
void    update_holder(char **valueholder);
int condition_check(char **line,char **valueholder,int *first_iteration,int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);