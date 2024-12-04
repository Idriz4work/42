
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>

// Test 1: Normal String
void	test1s(void)
{
	printf("TEST 1: print(\"%%s\", \"Hello, World!\")\n");
	int j = ft_printf("%s", "Hello, World!");
		// Using ft_printf to print the string
	int i = printf("%s", "Hello, World!");   
		// Using standard printf to print the string
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 2: Empty String
void	test2s(void)
{
	printf("TEST 2: print(\"%%s\", \"\")\n");
	int j = ft_printf("%s", ""); // Using ft_printf to print an empty string
	int i = printf("%s", "");   
		// Using standard printf to print an empty string
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 3: String with Special Characters (newlines)
void	test3s(void)
{
	printf("TEST 3: print(\"%%s\", \"Hello\\nWorld!\\n\")\n");
	int j = ft_printf("%s", "Hello\nWorld!\n");
		// Using ft_printf to print a string with newlines
	int i = printf("%s", "Hello\nWorld!\n");   
		// Using standard printf to print a string with newlines
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 4: String with Only Spaces
void	test4s(void)
{
	printf("TEST 4: print(\"%%s\", \"     \")\n");
	int j = ft_printf("%s", "     "); 
	int i = printf("%s", "     ");   
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 5: Long String
void	test5s(void)
{
	char	long_string[1000];

	printf("TEST 5: print(\"%%s\", \"");
	for (int k = 0; k < 999; k++)
		long_string[k] = 'A';            
	long_string[999] = '\0';             
	int j = ft_printf("%s", long_string);
	int i = printf("%s", long_string);   
	printf("\")\n");
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// Test 6: NULL Pointer for String
void	test6s(void)
{
	printf("TEST 6: print(\"%%s\", NULL)\n");
	int j = ft_printf("%s", NULL); 
	// int i = printf("%s", NULL);   
	printf("\n---------RETURN VALUE---------\n%i\n", j);
}

// Main Function to Call All Tests
// int	main(void)
// {
// 	test1s();
// 	test2s();
// 	test3s();
// 	test4s();
// 	test5s();
// 	test6s();
// 	return (0);
// }
