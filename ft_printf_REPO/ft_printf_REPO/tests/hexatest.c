
#include "../ft_printf.h"
#include "../ft_printf_bonus.h"

void test1(void) {
	printf("\n--------- BASIC NUMBER TEST ----------\n");
	int i = ft_printf("%x\n",23);
	int j = printf("%x\n",23);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	printf("\n--------- BASIC NUMBER TEST 2 ----------\n");
	i = ft_printf("%X\n",34435);
	j = printf("%X\n",34435);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
}

void test2(void) {
	printf("\n------------MAXIMAL VALUE-------------\n");
	int i = ft_printf("%x\n",INT_MAX);
	int j = printf("%x\n",INT_MAX);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	
	printf("\n------------MINIMAL VALUE-------------\n");
	i = ft_printf("%x\n",INT_MIN);
	j = printf("%x\n",INT_MIN);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	
	printf("\n------------0 VALUE-------------\n");
	i = ft_printf("%x\n",0);
	j = printf("%x\n",0);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
	
	printf("\n------------ some -------------\n");
	i = ft_printf("%x\n",INT_MAX);
	j = printf("%x\n",INT_MAX);
	printf("\n---------RESULTS------------\nft:%i\noriginal:%i\n",i,j);
}

int main(void) {
	test1();
	test2();
}
