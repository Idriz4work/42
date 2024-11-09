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

char *ft_strstr(char *s1, char *s2)
{
    int i;

    if (*s2 == '\0')  
        return (s1);  
    while (*s1)
    {
        i = 0;
        while (s1[i] == s2[i])
        {
            if (s2[i + 1] == '\0')  
                return (s1);        
            i++;
        }
        s1++;
    }
    return (0);  
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int	main(void)
// {
// 	char s[] = "ausbui aviye";
// 	char s2[] = "avi";
// 	printf("%s\n%s", ft_strstr(s, s2), strstr(s, s2));
// }
