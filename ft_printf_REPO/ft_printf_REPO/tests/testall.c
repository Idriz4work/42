

#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void test_sui()
{

}

void test_xXp()
{

}

void test_signcd()
{
	
}

void test_cspdiuxXdoublesign()
{
	printf("--------TESTING ALL AT ONCE-------\n\n");

	ft_printf("%s, I am %u %s.My address is %p %%, this is my age in hexa: %x (%X) %c %d\n","Hello",19,"years old",345,19,19,'\n',42);
	printf("%s, I am %u %s.My address is %p %%, this is my age in hexa: %x (%X) %c %d\n","Hello",19,"years old",345,19,19,'\n',42);
}

int main()
{
	// test_sui();
	// test_xXp();
	// test_signcd();
	test_cspdiuxXdoublesign();
}
