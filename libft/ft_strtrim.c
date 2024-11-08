
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

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int ft_strlen(const char *s1) {
    int i;
    i = 0;
    while (s1[i] != '\0')
        i++;
    return i;
}

int check_letter(char c, char const *set, int indexes) {
    int i;
    i = 0;
    while (i < indexes) {
        if (c == set[i])
            return 1;
        i++;
    }
    return 0;
}

char *ft_strtrim(char const *s1, char const *set) {
    int i;
    char *trimmed;
    int start;
    int total_len;
				int end;
				
				start = 0;
				end = ft_strlen(s1) - 1;
    while (s1[start] != '\0' && check_letter(s1[start], set, ft_strlen(set)))
     start++;
    while (end >= 0 && check_letter(s1[end], set, ft_strlen(set)))
     end--;
    total_len = (end >= start) ? end - start + 1 : 0;
    trimmed = (char *)malloc(sizeof(char) * (total_len + 1));
    if (!trimmed)
     return NULL;
    i = 0;
				while(i < total_len)
				{
     trimmed[i] = s1[start + i];
					i++;
				}
    trimmed[total_len] = '\0';
    return trimmed;
}

int main(void) 
{
    char s[] = "something is written here you can fork my repo and test it out :D";
    char set[] = "siwrte";
    printf("%s\n", ft_strtrim(s, set));
    return 0;
}
