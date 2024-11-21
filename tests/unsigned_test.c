
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

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

void test_basic()
{
	printf("TEST BASIC\n");
	ft_printf("FT: Q: hello what was the number again ?\nA: %u\n",7834);
	printf("ORI: Q: hello what was the number again ?\nA: %u\n",7834);

printf("\n");

	ft_printf("\nFT: Q: hello the number is %u ?\nA: Nop: %u\n",7834, 984365);
	printf("ORI: Q: hello the number is %u ?\nA: Nop: %u\n",7834, 984365);

printf("\n");

	ft_printf("\nFT: %u\n",7834);
	printf("ORI: %u\n",7834);


	ft_printf("\nFT: %u -%u0%u0%u\n",7834, 984365,324435,5435);
	printf("ORI: %u -%u0%u0%u\n",7834, 984365,324435,5435);
}

int main()
{
	test_empty();
	printf("\n");
	test_invalid_value();
	printf("\n");
	test_basic();
	printf("\n");
	test_maximal_value();
	printf("\n");
}
