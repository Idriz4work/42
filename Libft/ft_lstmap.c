/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 12:13:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	unsigned int	i;
	t_list			*copy;

	i = 0;
	copy = NULL;
	if (!lst || !copy)
		return (NULL);
	while (!lst)
	{
		(f)(copy[i].content);
		(del)(lst[i].content);
		free(lst[i].content);
		i++;
	}
	return (copy);
}

// int	main(void)
// {
// 	int		i;
		// printf("%p\n", lst[i].content);
// 	t_list	*lst;

// 	i = 0;
// 	lst->content = ft_lstnew("Hello");
// 	lst->next = ft_lstnew("World");
// 	lst->next->next = ft_lstnew("!");
// 	ft_lstmap(lst, &ft_bzero, &ft_lstclear);
// }
