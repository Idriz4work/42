/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:55 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 10:13: by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *lst;
// 	t_list *tmp;

// 	// Initialize the list and add some nodes
// 	lst = ft_lstnew("first node");
// 	lst->next = ft_lstnew("next node of first");
// 	lst->next->next = ft_lstnew("merhaba");

// 	// Test ft_lstlast
// 	tmp = ft_lstlast(lst);

// 	// Print content of the last node to verify it's correct
// 	if (tmp != NULL)
// 	{
// 		printf("Last node content: %s\n", (char *)tmp->content);
// 		printf("Next pointer of the last node: %p\n", tmp->next);
// 		// Should be NULL
// 	}
// 	if (tmp == NULL)
// 	{
// 		printf("Last node content: %s\n", (char *)tmp);
// 		// printf("Next pointer of the last node: %p\n", tmp->next);
// 	}
// }