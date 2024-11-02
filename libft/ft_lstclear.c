#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    int i;
				t_list *next;
				t_list *holder;
    
				if (!next || !holder)
					return;
    i = 0;
    while (holder != NULL)
    {
        next = lst[i]->next;
        del(lst[i]->content);
        free(lst[i]);
								holder = lst[i]->next;
        i++;
    }
    lst = NULL;
}

void del(void *content)
{free(content);}

int main()
{
    int i = 0;
    t_list *lst[4] = {0};
    lst[0] = ft_lstnew("first node");
    lst[0]->next = ft_lstnew("next node of first");
    lst[1] = ft_lstnew("second node");
    lst[1]->next = ft_lstnew("next node of second");
    lst[1]->next->next = NULL;
    while (lst[i] != NULL)
    {
        printf("%s\n", (char *)lst[i]->content); 
								if (lst[i]->next)
         printf("Next node: %s\n", (char *)lst[i]->next->content);
        i++;
    }
    ft_lstclear(lst,&del);
}