#include "libft/libft.h"

#define BUFF_SIZE 42

char *get_next_line(const int fd);
char *insert_line(char **valueholder);
void update_holder(char **valueholder);
int freeler(char **s1, char **s2, char **s3);
int read_file(char **valueholder, int bytes, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);