/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:16 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 14:08:10 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

// void	delt(void *t)
// {
// 	printf("DELETED");
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew("Oh k");
// 	lst->next = ft_lstnew("hi");
// 	lst->next->next = ft_lstnew("Bye");
// 	ft_lstdelone(lst, delt);
// 	printf("%s\n%s\n", (char *)lst->content, (char *)lst->next);
// }
