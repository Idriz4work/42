/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:57 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/16 15:09:14 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
// new->next = NULL;
// int	main(void)
// {
// 	int i = 0;
// 	t_list *newy;
// 	newy = ft_lstnew("0 new node: THIS IS THE NEW ONE");
// 	newy->next = NULL;
// 	t_list *lst[8] = {0};
// 	lst[0] = ft_lstnew("1 node");
// 	lst[0]->next = NULL;
// 	ft_lstadd_back(lst, newy);
// 	while (lst[i] != NULL)
// 	{
// 		printf("%s\n", (char *)lst[i]->content);
// 		if (lst[i]->next)
// 			printf("Next node: %s\n", (char *)lst[i]->next->content);
// 		i++;
// 	}
// }
