
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"
#include <stdio.h>

void test_empty()
{
	printf("TEST EMPTY\n");
	ft_printf("FT: %u\n",0);
	printf("ORI: %u\n\n",0);
}

void test_invalid_value()
{
	printf("TEST invalid value\n");
	ft_printf("FT: %u\n",-1);
	printf("ORI: %u\n",-1);
}

void test_maximal_value()
{
	printf("TEST MAX VALUE\n");
	ft_printf("FT: %u\n",INT_MAX);
	printf("ORI: %u\n",INT_MAX);
}

void test_minimal_value()
{
	printf("TEST MINIMAL VALUE\n");
	ft_printf("FT: %u\n",INT_MIN);
	printf("ORI: %u\n\n",INT_MIN);
}

void test_basic()
{
	printf("TEST BASIC\n");
	ft_printf("FT: Q: hello what was the number again ?\nA: %u\n",7834);
	printf("ORI: Q: hello what was the number again ?\nA: %u\n",7834);


	ft_printf("\nFT: Q: hello the number is %u ?\nA: Nop: %u\n",7834, 984365);
	printf("ORI: Q: hello the number is %u ?\nA: Nop: %u\n",7834, 984365);


	ft_printf("\nFT: %u\n",7834);
	printf("ORI: %u\n",7834);


	ft_printf("\nFT: %u -%u0%u0%u\n",7834, 984365,324435,5435);
	printf("ORI: %u -%u0%u0%u\n",7834, 984365,324435,5435);
}

void test_verylong()
{
	ft_printf("TEST LONG\n\n");
	ft_printf("%u\n",-+-783425237);
	printf("%u\n\n",-+-783425237);
	ft_printf("%u\n",78342);
	printf("%u\n\n",78342);
	ft_printf("\0%u\n",-+-78);
	printf("\0%u\n\n",-+-78);
}

void test_withothers()
{
	printf("TEST WITH OTHERS\n\n");
	ft_printf("Hello my name is %s%s I am %u years old and live in %s.\n Do you want %s with %s it costs %u(%u$) ?\n","Ati","(ZORILLA)",19,"Germany","kebab","onions",7,12);
	printf("Hello my name is %s%s I am %u years old and live in %s.\n Do you want %s with %s it costs %u(%u$) ?\n","Ati","(ZORILLA)",19,"Germany","kebab","onions",7,12);
	ft_printf("%s%s%u %s.\n%s%s%u(%u$) ?\n","Ati","the real",53,"(ZORILLA)","Germany","kebab",7,12);
	printf("%s%s%u %s.\n%s%s%u(%u$) ?\n","Ati","the real",53,"(ZORILLA)","Germany","kebab",7,12);
}

// int main()
// {
// 	test_empty();
// 	test_invalid_value();
// 	test_basic();
// 	test_maximal_value();
// 	test_minimal_value();
// 	test_verylong();
// 	test_withothers();
// }
