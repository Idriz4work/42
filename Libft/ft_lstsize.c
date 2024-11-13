/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:15:49 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/13 19:55:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst[i].next || lst[i].content)
		i++;
	// i--;
	return (i / 2);
}

// Example of main to test ft_lstsize
int main()
{
    // Creating a simple linked list with 3 nodes
    t_list *head = ft_lstnew("First node");
    // head->next = ft_lstnew("Second node");
    // head->next->next = ft_lstnew("Third node");
				// head->content = ft_lstnew("Hello I's me");
				// head->next->next->next = ft_lstnew("last node meen");
    // Test ft_lstsize
    printf("Size of linked list: %i\n", ft_lstsize(head)); // Should output 3

    // Free allocated memory for the linked list
    t_list *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return (0);
}