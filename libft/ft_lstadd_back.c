#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	lst[-1] = new;
	int i,j;
	t_list tmp;

	i = 1;
	j = 0;
	tmp = lst[-1];
	lst[1] = tmp;
	j -= 2;
	while (lst[i++] != NULL)
		;
	while (i > 1)
	{
		*lst[j] = *lst[i-1];
		i--;
	}
}
