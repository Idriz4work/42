#include "libft.h"

int ft_lstlen(t_list **lst)
{
	int i;

	i = 0;
	while (lst[i] != NULL)
		i++;
	return i;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	int i,half_size;
	t_list *tmp, *last;

	half_size = ft_lstlen(lst);
	i = 0;
	tmp = lst[i];
	lst[0] = new;
	lst[1] = tmp;
	last = lst[-1];
	i += 2;
	while (i < half_size / 2)
	{
		if (lst[i+1] != NULL)
		{
			tmp = lst[i+1];
			lst[i] = tmp;
		}	
		last = lst[i];
		i++;
	}
	lst[i] = last;
}

int main()
{
 int i = 0;
	t_list *newy;
	newy = ft_lstnew("0 new node: THIS IS THE NEW ONE");
	newy->next = NULL;
 t_list *lst[4] = {0};
 lst[0] = ft_lstnew("1 node");
 lst[0]->next = ft_lstnew("next node of first");
 lst[1] = ft_lstnew("2 node");
 lst[1]->next = ft_lstnew("next node of second");
	lst[2] = ft_lstnew("3 node");
 lst[2]->next = ft_lstnew("next node of first");
 lst[3] = ft_lstnew("4 node");
 lst[3]->next = ft_lstnew("next node of second");
	lst[4] = ft_lstnew("5 node");
 lst[4]->next = ft_lstnew("next node of first");
 lst[5] = ft_lstnew("6 node");
 lst[5]->next = ft_lstnew("next node of second");
 lst[5]->next->next = NULL;
	ft_lstadd_front(lst,newy);
 while (lst[i] != NULL)
 {
     printf("%s\n", (char *)lst[i]->content); 
					if (lst[i]->next)
      printf("Next node: %s\n", (char *)lst[i]->next->content);
     i++;
 }
}
