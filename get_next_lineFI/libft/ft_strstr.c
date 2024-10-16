
char *ft_strstr(char *s1,char *s2)
{
// simplistic algorithm with O(n2) worst case
    int i;
    char c = *s2;
    if (c == '\0')
     return 0;
	while (*s1 != '\0')
	{ 
        if (*s1 == c) {
            while (i == 1) {
                if (s1[i] != s2[i])
                    break;
	    	i++;
            }
        }
	    s1++;
    }
    return 0;
}