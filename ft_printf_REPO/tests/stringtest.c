
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

void test3(void) {
	
}

void test4(void) {

}

void test5(void) {

}

void test6(void) {

}


int main(void) {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}
