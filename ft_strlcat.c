// #include <stddef.h>    // For size_t

int ft_strlcat(char *s1, const char *s2, int n)
{
 int i, j, s1_len, s2_len;

 i = j = s1_len = s2_len = 0;
 while (s1[s1_len] != '\0')
  s1_len++;
 while (s2[s2_len] != '\0')
  s2_len++;
 if (n <= s1_len)
  return n + s2_len;
 
 i = s1_len;
 while (s2[j] != '\0' && i < n - 1)
 {
  s1[i] = s2[j];
  i++;
  j++;
 }
 s1[i] = '\0';
 return s1_len + s2_len;
}
