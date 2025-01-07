/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iatilla- <iatilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:16:38 by iatilla-          #+#    #+#             */
/*   Updated: 2024/11/18 15:37:52 by iatilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*copy;
	void	*placeholder;

	copy = NULL;
	while (lst != NULL)
	{
		placeholder = f(lst->content);
		current = ft_lstnew(placeholder);
		if (current == NULL)
		{
			del(placeholder);
			ft_lstclear(&copy, del);
			return (copy);
		}
		current->content = placeholder;
		current->next = NULL;
		ft_lstadd_back(&copy, current);
		lst = lst->next;
	}
	return (copy);
}

// void	del(void *content)
// {
// 	int i;

// 	i = 0;
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
// 	int fd = open("ft_te",O_RDWR);
// 	int	len;

// 	len = 0;
// 	while (((char *)elem->content)[len])
// 		len++;
// 	write(1,((char *)elem->content),len);
// 	write(1,"\n",1);
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
// 	elem3->next->next = ft_lstnew("THIS IS A CERTIFIED HOOD CLASSIC");
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

// lst = ft_lstnew(strdup(" 1 2 3 "));
// lst->next = ft_lstnew(strdup("ss"));
// lst->next->next = ft_lstnew(strdup("-_-"));
// res = ft_lstmap(lst, printi, del);
// printf("%s\n", (char *)res);f (pouet[i] == 'o')
