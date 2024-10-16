
char *ft_strrchr(char *s1,char *s2)
{
	int i,j;
	i = j = 0;
	while (s1[i] != '\0')
	{
		while (s1[i+j] == s2[j] && s2[j] != '\0')
		{
			// locate last occurence of char in s1
			if (s1[i+j] == s2[j] && s2[j+1] == '\0')
				return s1;
			j++;
		}
		i++;
	}
	s1[i+j] = '\0';
	return s1;
}