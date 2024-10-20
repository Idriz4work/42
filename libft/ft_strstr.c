
char *ft_strstr(char *s1,char *s2)
{
    int i,j;

    i = j = 0;
    if (*s2 == '\0')
     return 0;
	while (*s1 != '\0')
	{ 
        while (*s1 == s2[i]) {
            if (s1[i] != s2[i])
                break;
            if (*s1 == s2[i] && s2[i+1] == '\0')
                return s2;
	    i++;
        }
	    s1++;
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[] = "ausbui aviye";
    char s2[] = "avi";
    printf("%s\n%s",ft_strstr(s,s2),strstr(s,s2));
}
