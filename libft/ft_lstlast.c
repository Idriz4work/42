#include "libft.h"

t_list *ft_lstlast(t_list *lst) {
 if (!lst)
  return NULL;
 while (lst->next != NULL)
  lst = lst->next;
 return lst;
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

}

