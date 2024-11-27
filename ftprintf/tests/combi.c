

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>

void	test_sui(void)
{
	printf("--------TESTING %%s, %%u, %%i--------\n");
	printf("TEST 1: print(\"%%s\", \"Hello World\")\n");
	int j = ft_printf("%s", "Hello World"); // Using ft_printf to print string
	int i = printf("%s", "Hello World");   
		// Using standard printf to print string
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 2: print(\"%%u\", 1234)\n");
	j = ft_printf("%u", 1234); // Using ft_printf to print unsigned int
	i = printf("%u", 1234);    // Using standard printf to print unsigned int
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 3: print(\"%%i\", -42)\n");
	j = ft_printf("%i", -42); // Using ft_printf to print signed int
	i = printf("%i", -42);    // Using standard printf to print signed int
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

void	test_xXp(void)
{
	printf("--------TESTING %%x, %%X, %%p--------\n");
	printf("TEST 1: print(\"%%x\", 255)\n");
	int j = ft_printf("%x", 255);
		// Using ft_printf to print hexadecimal (lowercase)
	int i = printf("%x", 255);   
		// Using standard printf to print hexadecimal (lowercase)
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 2: print(\"%%X\", 255)\n");
	j = ft_printf("%X", 255);
		// Using ft_printf to print hexadecimal (uppercase)
	i = printf("%X", 255);   
		// Using standard printf to print hexadecimal (uppercase)
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 3: print(\"%%p\", 0x12345)\n");
	j = ft_printf("%p", (void *)0x12345); // Using ft_printf to print pointer
	i = printf("%p", (void *)0x12345);   
		// Using standard printf to print pointer
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

void	test_signcd(void)
{
	printf("--------TESTING %%d, %%c--------\n");
	printf("TEST 1: print(\"%%d\", 0)\n");
	int j = ft_printf("%d", 0); // Using ft_printf to print integer 0
	int i = printf("%d", 0);    // Using standard printf to print integer 0
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 2: print(\"%%d\", -256)\n");
	j = ft_printf("%d", -256); // Using ft_printf to print signed integer
	i = printf("%d", -256);    // Using standard printf to print signed integer
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
	printf("TEST 3: print(\"%%c\", 'A')\n");
	j = ft_printf("%c", 'A'); // Using ft_printf to print character
	i = printf("%c", 'A');    // Using standard printf to print character
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

void	test_cspdiuxXdoublesign(void)
{
	int	j;
	int	i;

	printf("--------TESTING ALL AT ONCE-------\n\n");
	printf("TEST 1: print(\"%%s, %%u, %%s, %%p, %%x %%X %%c %%d\")\n");
	j = ft_printf("%s, I am %u %s. My address is %p, this is my age in hex:%x (%X) %c %d\n", "Hello", 19, "years old", (void *)345, 19, 19,'\n', 42);
	i = printf("%s, I am %u %s. My address is %p, this is my age in hex: %x (%X) %c %d\n", "Hello", 19, "years old", (void *)345, 19, 19, '\n', 42);
	printf("\n---------RETURN VALUE---------\n%i\n%i\n", j, i);
}

// int	main(void)
// {
// 	test_sui();                // Test %s, %u, %i
// 	test_xXp();                // Test %x, %X, %p
// 	test_signcd();             // Test %d, %c
// 	test_cspdiuxXdoublesign(); // Test with all specifiers
// 	return (0);
// }
