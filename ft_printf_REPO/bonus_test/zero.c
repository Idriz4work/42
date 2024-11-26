#include <stdio.h> 
#include <limits.h>
#include "../ft_printf_bonus.h"
#include "../ft_printf.h"

void int_test1(void)
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 1 00 -------------\n");
	i = ft_printf("%01i",0);
	printf("\n");
	j = printf("%01i",0);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 1.2 02[10]-------------\n");
	i = ft_printf("%02i",10);
	printf("\n");
	j = printf("%02i",10);
	printf("\nft: %i\nori: %i\n",i,j);
}

void int_test2(void)
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 01(43)-------------\n");
	i = ft_printf("%01i",43);
	printf("\n");
	j = printf("%01i",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.2 05[43]-------------\n");
	i = ft_printf("%05i",43);
	printf("\n");
	j = printf("%05i",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.3 02[2]-------------\n");
	i = ft_printf("%02i",2);
	printf("\n");
	j = printf("%02i",2); 
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.4 01[2]-------------\n");
	i = ft_printf("%01i",2);
	printf("\n");
	j = printf("%01i",2);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.5 010[1000]-------------\n");
	i = ft_printf("%010i",1000);
	printf("\n");
	j = printf("%010i",1000);
	printf("\nft: %i\nori: %i\n",i,j);
}

void uns_test1()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 1 00 -------------\n");
	i = ft_printf("%01u",0);
	printf("\n");
	j = printf("%01u",0);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 1.2 02[-1]-------------\n");
	i = ft_printf("%02u",-1);
	printf("\n");
	j = printf("%02u",-1);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 1.3 02[-4]-------------\n");
	i = ft_printf("%02u",-4);
	printf("\n");
	j = printf("%02u",-4);
	printf("\nft: %i\nori: %i\n",i,j);
}

void uns_test2()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 014(MAX VALUE [4294967295])-------------\n");
	i = ft_printf("%014u",4294967295);
	printf("\n");
	j = printf("%014u",4294967295);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.2 05[43]-------------\n");
	i = ft_printf("%05u",43);
	printf("\n");
	j = printf("%05u",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.3 02[2]-------------\n");
	i = ft_printf("%02i",2);
	printf("\n");
	j = printf("%02i",2); 
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.4 01[2]-------------\n");
	i = ft_printf("%01i",2);
	printf("\n");
	j = printf("%01i",2);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.5 010[1000]-------------\n");
	i = ft_printf("%010i",1000);
	printf("\n");
	j = printf("%010i",1000);
	printf("\nft: %i\nori: %i\n",i,j);
}

int main(void) {
    // int_test1();     
    // int_test2();  
    uns_test1();  
    uns_test2();  
    // test5();  
    // test6();  
}

