#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	int i;
	t_list tmp;

	i = 0;
	tmp = lst[i];
	lst[0] = new;
	lst[1] = tmp;
	i += 2;
	while (lst[i] != NULL)
	{
		*lst[i] = *lst[i+1];
		i++;
	}
}

int main()
{

}
