
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
	int i = ft_printf("%\n");
	int j = printf("%\n");
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
}

void test_long_value()
{
	printf("TEST LONG VALUE\n");
	ft_printf("FT:  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
	printf("ORI: %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
}

int main()
{
	test_empty();
	test_invalid_value();
	test_long_value();
}
