/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:48 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:17:53 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to add a new node to the front of the list
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int main()
// {
//  int i = 0;
// 	t_list *newy;
// 	newy = ft_lstnew("0 new node: THIS IS THE NEW ONE");
// 	newy->next = NULL;
//  t_list *lst[4] = {0};
//  lst[0] = ft_lstnew("1 node");
//  lst[0]->next = ft_lstnew("next node of first");
//  lst[1] = ft_lstnew("2 node");
//  lst[1]->next = ft_lstnew("next node of second");
// 	lst[2] = ft_lstnew("3 node");
//  lst[2]->next = ft_lstnew("next node of first");
//  lst[3] = ft_lstnew("4 node");
//  lst[3]->next = ft<stddef.h> _lstnew("next node of second");
// 	lst[4] = ft_lstnew("5 node");
//  lst[4]->next = ft_lstnew("next node of first");
//  lst[5] = ft_lstnew("6 node");
//  lst[5]->next = ft_lstnew("next node of second");
//  lst[5]->next->next = NULL;
// 	ft_lstadd_front(lst,newy);
//  while (lst[i] != NULL)
//  {
//      printf("%s\n", (char *)lst[i]->content);
// 					if (lst[i]->next)
//       printf("Next node: %s\n", (char *)lst[i]->next->content);
//      i++;
//  }
// }