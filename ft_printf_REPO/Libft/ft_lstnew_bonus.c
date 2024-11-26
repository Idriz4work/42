/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:29 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/11 17:16:31 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}

// #include <stdio.h>
// int main()
// {
// 	char *data = "Hello, world!";
// 	t_list *node = ft_lstnew(data);

// 	if (node)
// 	{
// 		printf("Content: %s\n", (char *)node->content); // Print content of node
// 		printf("Next: %p\n", (void *)node->next);       // Should be NULL
// 		free(node); // Free allocated memory for node (but not content)
// 	}
// 	else
// 	{
// 		printf("Node creation failed.\n");
// 	}

// 	return (0);
// }
