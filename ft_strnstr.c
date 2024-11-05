#include <stddef.h>    // For size_t

int ft_strlen(char *s)
{
    int i;
    i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *ft_strnstr(char *s1,char *s2,size_t n)
{
    size_t i, len;
    char c;

    c = *s2;
    if (c == '\0')
     return 0;

    len = ft_strlen(s2);
	while (len <= n)
	{ 
        if (*s1 == c) {
            while (i == 1) {
                if (i == len)
                    return (char *)s1;
                if (s1[i] != s2[i])
                    break;
			i++;
            }
        }
	n--;
    s1++;
    }
    return 0;
}
