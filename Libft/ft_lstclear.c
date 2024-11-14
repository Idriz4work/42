/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:17:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 10:25:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;

	i = 0;
	while (lst != NULL)
	{
		while (lst[i].next != NULL)
		{
			del(lst[i]->content);
			free(lst[i].next);
			i++;
		}
		free(lst[i]);
	}
	lst = NULL;
}

// void del(void *content)
// {free(content);}

// int main()
// {
//     int i;

//     i = 0;
//     t_list *lst[4] = {0};
//     lst[0] = ft_lstnew("first node");
//     lst[0]->next = ft_lstnew("next node of first");
//     lst[1] = ft_lstnew("second node");
//     lst[1]->next = ft_lstnew("next node of second");
//     lst[1]->next->next = NULL;
//     // while (lst[i] != NULL)
//     // {
//     //     printf("%s\n", (char *)lst[i]->content);
// 	// 	if (lst[i]->next)
//     //         printf("Next node: %s\n", (char *)lst[i]->next->content);
//     //     i++;
//     // }
//     ft_lstclear(lst,&del);
//     if (lst[i])
//     {
//         while (lst[i] != NULL)
//         {
//             printf("%s\n", (char *)lst[i]->content);
//                                     if (lst[i]->next)
//             printf("Next node: %s\n", (char *)lst[i]->next->content);
//             i++;
//         }
//     }
//     else
//         printf("CLear was right\n");
// }