#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f) 
	    return;
	
	while (lst)
	{
	    f(lst->content); 
	    lst = lst->next; 
	}
}

// #include <stdio.h>
// void convert(t_list *data)
// {
// 	printf("function was called");
// }

// int main()
// {
// 	char *data = "Hello, world!";
// 	t_list *node = ft_lstnew(data);

// 	if (node)
// 	{
// 		printf("Content: %s\n", (char *)node->content); // Print content of node
// 		printf("Next: %p\n", (void *)node->next);       // Should be NULL
// 		free(node); // Free allocated memory for node (but not content)
// 	}
// 	else
// 		printf("Node creation failed.\n");
// 	ft_lstiter(node,convert);

// 	return 0;
// }
