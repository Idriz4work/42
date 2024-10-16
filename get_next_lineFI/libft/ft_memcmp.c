#include <stddef.h>    // For size_t

void       *ft_memcmp(void *s1, const void *s2, size_t n)
{
	int i;
	i = 0;
	const char *ptrs2;
	char *ptrs1;
	ptrs1 = s1;
	ptrs2 = s2;
	while (n > 0)
	{
		if (ptrs1[i] < ptrs2[i] || ptrs1[i] > ptrs2[i] || ptrs1[i] == ptrs2[i])
			return 0;
		i++;
		n--;
	}
	return 0;
}