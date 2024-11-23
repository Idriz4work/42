
#include "../ft_printf.h"
#include <limits.h>
#include "../ft_printf_bonus.h"

void test1(void) {
	printf("\n--------- BASIC NUMBER TEST ----------\n");
	int i = ft_printf("%p\n",-21);
	int j = printf("%p\n",-21);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	printf("\n--------- BASIC NUMBER TEST 2 ----------\n");
	i = ft_printf("%p\n",34435);
	j = printf("%p\n",34435);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
}

void test2(void) {
	printf("\n---------NULL POINTER ---------");
	int i = ft_printf("%p\n",NULL);
	int j = printf("%p\n",NULL);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	
	printf("\n--------- NEGATIVE VALUE ----------\n");
	i = ft_printf("%p\n",-1);
	j = printf("%p\n",-1);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	
	printf("\n--------- MAX VALUE ADDRESS ----------\n");
	i = ft_printf("%p\n",2147483647);
	j = printf("%p\n",2147483647);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
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