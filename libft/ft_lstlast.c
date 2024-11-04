#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	return lst[-1].content;
}
