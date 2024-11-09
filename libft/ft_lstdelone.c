#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !f) 
	    return;
	
	while (lst)
	{
	    del(lst->content);
					free(lst->content);
	    lst = lst->next; 
	}
}
