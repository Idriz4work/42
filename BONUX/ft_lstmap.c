/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:30:41 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_lst(t_list *s)
{
	int	i;

	i = 0;
	while (s != NULL)
		i++;
	return (i);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	unsigned int	i;
	t_list			*copy;

	i = 0;
	copy = (t_list)malloc(sizeof(t_list) * ft_strlen_lst(lst) + 1);
	if (!lst || !copy)
		return (NULL);
	while (!lst)
	{
		printf("%p\n", lst[i].content);
		(*f)(i, lst[i]);
		copy[i] = (*f)(i, lst[i]);
		(del)(lst[i].content);
		free(lst[i].content);
		i++;
	}
	return (copy);
}

// int	main(void)
// {
// 	int		i;
// 	t_list	*lst;

// 	i = 0;
// 	lst->content = ft_lstnew("Hello");
// 	lst->next = ft_lstnew("World");
// 	lst->next->next = ft_lstnew("!");
// 	ft_lstmap(lst, &ft_bzero, &ft_lstclear);
// }
