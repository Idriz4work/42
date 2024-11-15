/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/15 10:28:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*copy;
	t_list *tmp;

	copy = malloc(sizeof(t_list) * ft_lstsize(lst) + 1);
	if (!lst || !copy)
		return (NULL);
	tmp = lst;
	while (lst != NULL)
	{
		copy = f(lst->content);
		del(lst);
		tmp = tmp->next;
		lst = tmp->next;		
	}
	// free(tmp);
	return (copy);
}

// void del(void *content)
// {
// 	printf("del was called\n");
// }

// void *printi(void *content)
// {
// 	printf("printi was called\n");
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("Hello");
// 	lst->content = ft_lstnew("Yo");
// 	lst->next = ft_lstnew("World");
// 	lst->next->next = ft_lstnew("!");
// 	ft_lstmap(lst, printi, del);
// }
