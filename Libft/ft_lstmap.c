/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/15 18:01:06 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;
	t_list	*copy;
	char	*placeholder;

	copy = NULL;
	tmp = lst;
	if (!lst)
		return (copy);
	while (tmp != NULL)
	{
		current = malloc(sizeof(t_list));
		if (!current)
		{
			del(copy);
			return (NULL);
		}
		placeholder = ft_strdup(f((char *)tmp->content));
		if (placeholder == NULL)
		{
			free(current);
			del(copy);
			return (NULL);
		}
		current->content = placeholder;
		current->next = NULL;
		if (!copy)
		{
			copy = current;
			continue;
		}
		ft_lstadd_back(&copy, current);
		del(current);
		tmp = tmp->next;
	}
	free(tmp);
	return (copy);
}

// void	del(void *content)
// {
// 	printf("");
// }

// void	*ft_map(void *ct)
// {
// 	int i;
// 	void	*c;
// 	char	*pouet;

// 	c = ct;
// 	i = -1;
// 	pouet = (char *)c;
// 	while (pouet[++i])
// 		if (pouet[i] == 'o')
// 			pouet[i] = 'a';
// 	return (c);
// }

// void	ft_print_result(t_list *elem)
// {
// 	int	len;

// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1, ((char *)elem->content), len);
// 	write(1, "\n", 1);
// }

// int	main(void)
// {
// 	t_list	*elem;
// 	t_list	*elem2;
// 	t_list	*elem3;
// 	t_list	*elem4;
// 	t_list	*list;
// 	char	*str;
// 	char	*str2;
// 	char	*str3;
// 	char	*str4;
// 	t_list	*lst;
// 	t_list	*res;
// 	int		i;

// 	str = strdup("lorem");
// 	str2 = strdup("ipsum");
// 	str3 = strdup("dolor");
// 	str4 = strdup("sit");
// 	elem = ft_lstnew(str);
// 	elem2 = ft_lstnew(str2);
// 	elem3 = ft_lstnew(str3);
// 	elem4 = ft_lstnew(str4);
// 	elem->next = elem2;
// 	elem2->next = elem3;
// 	elem3->next = elem4;
// 	i = 0;
// 	list = ft_lstmap(elem, &ft_map, del);
// 	ft_print_result(list);
// 	while (list->next)
// 	{
// 		list = list->next;
// 		ft_print_result(list);
// 		i++;
// 	}
// }

// // // // // lst = ft_lstnew(strdup(" 1 2 3 "));
// // // // // lst->next = ft_lstnew(strdup("ss"));
// // // // // lst->next->next = ft_lstnew(strdup("-_-"));
// // // // // res = ft_lstmap(lst, printi, del);
// // // // // printf("%s\n", (char *)res);f (pouet[i] == 'o')

