
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void test_empty()
{
	printf("TEST EMPTY\n");
	ft_printf("");
	printf("\n");
	printf("");
	printf("\n");
}

void test_invalid_value()
{
	printf("TEST invalid value\n");
	ft_printf("FT:  %\n");
	printf("ORI: %\n");
}

void test_maximal_value()
{
	printf("TEST MAX VALUE\n");
	ft_printf("FT:  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("ORI: %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}

int main()
{
	test_empty();
	test_invalid_value();
	test_maximal_value();
}
