#include <stdlib.h>
#include <stdio.h>

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char *sub;
	int i;

	sub = (char *)malloc(sizeof(char) * len);
	if (!sub)
		return NULL;
	i = 0;
	while (len-- > 0)
		sub[i++] = s[start++];
	sub[i+1] = '\0';
	return sub;
}

// int main()
// {
// 	int i = 0;
// 	int len = 1;
// 	const char s[] = "my name is atikopati how are you doing ?";
// 	printf("my: %s\n",ft_substr(s,i,len));
// }
