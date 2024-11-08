#include "libft.h"

int word_count(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j++;
		i++;
	}
	return j;
}

char **mem_allocate(char const *s, char c)
{
 int counterofC;
 char **array;

 counterofC = word_count(s,c);
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

int copyarray(char **array,char c, char const *s)
{
	int i;
	int j;
	int counterA;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		counterA = 0;
		if (s[i] != c)
		{
			array[j] = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
			if (!array[j])
				return -1;
			while (s[i] && s[i] != c)
				array[j][counterA++] = s[i++];
			array[j++][counterA] = '\0';
		}
		else
			i++;
	}
	array[j] = NULL;
	return 0;
}

char **ft_split(char const *s, char c)
{
	char **array;
	int result;

	array = mem_allocate(s,c);
	if (!array)
		return NULL;
	result = copyarray(array,c,s);
	if (result == -1)
		return NULL;
	return array;
}

// int main()
// {
//  char s[] = "Hello , my name is Ati, Nice to see you !";
//  char c = ',';
//  char **result;
//  int j = 0;
 
// 	result = ft_split(s, c); 
//  if (result == NULL) {
//      printf("Memory allocation failed\n");
//      return 1;
//  }
//  while (result[j] != NULL)
//  {
//      printf("%s\n$", result[j]);
//      j++;
//  }
//  j = 0;
//  while (result[j] != NULL)
//  {
//      free(result[j]);
//      j++;
//  }
//  free(result);
//  return 0;
// }
