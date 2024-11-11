/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: iatilla- <iatilla-@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/11/06 12:59:09 by iatilla-         #+#    #+#             */
/*   Updated: 2024/11/06 12:59:09 by iatilla-        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(char *s1,const char *s2, size_t n)
{
 size_t i;
	size_t j;

 i = 0;
	j = 0;
 if (*s2 == '\0')  
  return (s1);  
 while (*s1 && j < n)
 {
  i = 0;
  while (s1[i] == s2[i])
  {
   if (s2[i + 1] == '\0' || i + 1 == n)
    return (s1);
   i++;
  }
		j++;
  s1++;
	}
 return (0); 
}
#include <string.h>
int	main(void)
{
	char s[] = "hello I'm back";
	char s1[] = "hello I'm gone";
	printf("ft: %s\n%s\n", ft_strnstr(s, s1, 10),strnstr(s, s1, 10));
}
