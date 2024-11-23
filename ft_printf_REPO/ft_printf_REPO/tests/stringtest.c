
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void test1(void) {
	printf("EMPTY STRING TEST \n");
	ft_printf("ft: %s\n","\0");
	printf("or: %s\n$\n","\0");

	ft_printf("ft: %s\n","");
	printf("ori: %s\n$","");
}

void test2(void) {
	printf("SINGLE CHAR TEST\n");
	ft_printf("%s\n","c");
	printf("%s\n","c");
}

int main(void) {
	test1();
	test2();
}
