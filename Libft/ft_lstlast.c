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
	t_list *current_node;

	current_node = lst;
	if (!lst)
		return (NULL);
	while (current_node->next != NULL)
		current_node = current_node->next;
	return (current_node);
}

// int	main(void)
// {
// 	int		i;
// 	t_list	*lst;
// 	t_list *tmp;

// 	i = 0;
// 	lst->next = ft_lstnew("next node of first");
// 	lst->next->next = ft_lstnew("merhaba");

// 	tmp = ft_lstlast(lst);
// 	printf("%p",	tmp->next);

// }
