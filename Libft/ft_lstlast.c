/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:55 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:30:10 by iatilla-         ###   ########.fr       */
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
// 	int		i;
// 	t_list	*newy;
// 	t_list	*lst[4] = {0};

// 	i = 0;
// 	newy = ft_lstnew("0 new node: THIS IS THE NEW ONE");
// 	newy->next = NULL;
// 	lst[0] = ft_lstnew("1 node");
// 	lst[0]->next = ft_lstnew("next node of first");
// 	lst[1] = ft_lstnew("2 node");
// 	lst[1]->next = ft_lstnew("next node of second");
// 	lst[2] = ft_lstnew("3 node");
// 	lst[2]->next = ft_lstnew("next node of first");
// }
