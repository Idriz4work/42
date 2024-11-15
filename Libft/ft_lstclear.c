/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/15 11:02:25 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (*lst == NULL)
	{
		del(lst);
		return ;
	}
	while (*lst != NULL && lst != NULL)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
}

// void	del(void *content)
// {
// 	printf("del called\n");
// }

// int	main(void)
// {
// 	int i;

// 	i = 0;
// 	t_list *lst[4] = {0};
// 	lst[0] = ft_lstnew(strdup("nyancat"));

// 	lst[0]->next = ft_lstnew(strdup("#TEST#"));
// 	while (lst[i] != NULL)
// 	{
// 		printf("%s\n", (char *)lst[i]->content);
// 		if (lst[i]->next)
// 			printf("Next node: %s\n", (char *)lst[i]->next->content);
// 		i++;
// 	}

// 	ft_lstclear(lst, &del);

// 	if (lst[i])
// 	{
// 		while (lst[i] != NULL)
// 		{
// 			printf("%s\n", (char *)lst[i]->content);
// 			i++;
// 		}
// 	}
// 	else
// 		printf("CLear was right\n");
// 	if (*lst == NULL)
// 		printf("NULL\n");
// }	