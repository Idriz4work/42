#include "libft.h"

int wordCount(char const *s, char c)
{
	int i,j;

	i = j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return j;
}

char **memAlocator(char const *s, char c)
{
 int counterofC;
 char **array;

 counterofC = wordCount(s,c);
 array = (char **)malloc(sizeof(char *) * (counterofC + 1));
 if (!array)
  return NULL;

 array[0] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
 if (!array[0])
 {
  free(array);
  return NULL;
 }

 return array;
}

// char **copy(char **array,int j, char const *s, char c, int i)
// {
// 	int counterA;
// 	counterA = 0;
// 	array[j] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
//  if (!array[j])
// 		return NULL;
// 	while (s[i] && s[i] != c)
// 		array[j][counterA++] = s[i++];
// 	array[j++][counterA] = '\0';
// 	return array;
// }

int spliter(char ***array, int j, char c, int i,char const *s)
{
	int counterA;
	
	counterA = 0;
	*array[j] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
 if (!array[j])
		return -1;
	while (s[i] && s[i] != c)
		*array[j][counterA++] = s[i++];
	*array[j++][counterA] = '\0';
	return i;
}

char **ft_split(char const *s, char c)
{
	int i,j;
	char **array;

	i = j = 0;
	array = memAlocator(s,c);
	if (!array)
		return NULL;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			i = spliter(&array,j,c,i,s);
			if (i == -1)
				return NULL;
		else
			i++;
	}
	array[j] = NULL;
	return array;
}

int main()
{
    char s[] = "Hello , my name is Ati, Nice to see you !";
    char c = ',';
    char **result;
    int j = 0;

    // Call ft_split
    result = ft_split(s, c);
    
    // Check if split was successful
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Print each word
    while (result[j] != NULL)
    {
        printf("%s || ", result[j]);
        j++;
    }

    // Free allocated memory
    j = 0;
    while (result[j] != NULL)
    {
        free(result[j]);
        j++;
    }
    free(result);

    return 0;
}
