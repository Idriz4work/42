
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>

void test_emptyp()
{
	printf("TEST EMPTY\n");
	ft_printf("");
	printf("\n");
	printf("");
	printf("\n");
}

void test_invalid_valuep()
{
	printf("TEST invalid value\n");
	ft_printf("FT:  %\n");
	printf("ORI: %\n");
}

void test_maximal_valuep()
{
	printf("TEST MAX VALUE\n");
	ft_printf("FT:  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("ORI: %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}

// int main()
// {
// 	test_emptyp();
// 	test_invalid_valuep();
// 	test_maximal_valuep();
// }
