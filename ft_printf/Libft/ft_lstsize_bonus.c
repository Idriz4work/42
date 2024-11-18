/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:49 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/14 11:11:01 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		i;

	i = 0;
	if (!lst)
		return (0);
	current_node = lst;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

// Example of main to test ft_lstsize
// int main()
// {
//     // Creating a simple linked list with 3 nodes
//     // t_list *head = NULL; // ft_lstnew("First node");
//     // head->next = ft_lstnew("Second node");
//     // head->next->next = ft_lstnew("Third node");
// 	// 			head->next->next->next = ft_lstnew("last node meen");
// 	// 			head->next->next->next->next = ft_lstnew("Hello I's me");
//     // Test ft_lstsize
//     printf("Size of linked list: %i\n", ft_lstsize(head)); // Should output 3

//     // Free allocated memory for the linked list
//     t_list *temp;
//     while (head) {
//         temp = head;
//         head = head->next;
//         free(temp);
//     }

//     return (0);
// }