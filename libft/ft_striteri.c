#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	if (!s || !f)
		return;

	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void to_upper_if_space(unsigned int i, char *c)
// {
// 	if (i % 2 == 0 && *c >= 'a' && *c <= 'z') 
// 			*c -= 32; 
// }

// int main()
// {
// 	char s[] = "Hello World!";
// 		printf("Original string: %s\n", s);
// 		ft_striteri(s, to_upper_if_space);
// 		printf("Transformed string: %s\n", s);
// 	return 0;
// }
