#include "libft.h"

int ft_strlenLST(t_list *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	unsigned int i;
	t_list *copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * ft_strlenLST(lst) + 1);
	if (!lst || !copy)
		return NULL;	
	while (lst[i] != NULL)
	{
		copy[i] = (*f)(i,lst[i]);
		i++;
	}
	return copy;
}
