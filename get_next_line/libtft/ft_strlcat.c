// #include <stddef.h>    // For size_t

int ft_strlcat(char *s1, const char *s2, int n)
{
 int i = 0;
 int j = 0;
 int s1_len = 0;
 int s2_len = 0;
 
	// Calculate the length of s1 (destination string)
 while (s1[s1_len] != '\0')
  s1_len++;
 while (s2[s2_len] != '\0')
  s2_len++;
 if (n <= s1_len)
  return n + s2_len;
 
	// Start appending s2 to s1, but respect the buffer size
 i = s1_len;
 while (s2[j] != '\0' && i < n - 1)
 {
  s1[i] = s2[j];
  i++;
  j++;
 }
 // Null-terminate the string after concatenation
 s1[i] = '\0';
 return s1_len + s2_len;
}
