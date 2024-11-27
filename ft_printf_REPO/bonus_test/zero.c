#include <stdio.h> 
#include <limits.h>
#include "../ft_printf_bonus.h"
#include "../ft_printf.h"
// cc main.c alter_forma.c  left_justificator.c  minfield_width.c  precission.c  signplus.c  zero.c ../ft_printf.c ../ft_printf_utils.c ../ft_printf_bonus_1.c ../ft_printf_bonus_2.c ../ft_printf_utils2.c ../ft_printf_bonus_utils.c ../Libft/ft_atoi.c ../handlers.c -g
void int_test1ZERO(void)
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

void int_test2ZERO(void)
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

void uns_test1ZERO()
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

void uns_test2ZERO()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 014(MAX VALUE [4294967295])-------------\n");
	i = ft_printf("%014u",4294967295);
	printf("\n");
	j = printf("%014ld",4294967295);
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

// void str_test1ZERO()
// {
// 	int i,j;
// 	printf("\n----------- TEST 1 010[\\ 0] -------------\n");
// 	i = ft_printf("%010s","\0");
// 	printf("\n");
// 	j = printf("%010s","\0");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 2 010[Ko ni chi wa is a new greeting form]-------------\n");
// 	i = ft_printf("%010s","Ko ni chi wa is a new greeting form");
// 	printf("\n");
// 	j = printf("%010s","Ko ni chi wa is a new greeting form");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 	printf("\n----------- TEST 3 010[\\r\\t\\ e big money /0] -------------\n");
// 	i = ft_printf("%010s","\r\t\ebig money\0");
// 	printf("\n");
// 	j = printf("%010s","\r\t\ebig money\0");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 4 010[]-------------\n");
// 	i = ft_printf("%010s","");
// 	printf("\n");
// 	j = printf("%010s","");
// 	printf("\nft: %i\nori: %i\n",i,j);
// }

// void ptr_test1ZERO()
// {
// 	int i,j;
// 	void *ptrft = 3892;
// 	void *ptrori = 3892;
// 	printf("\n----------- TEST 1 010[3892] -------------\n");
// 	i = ft_printf("%010p",ptrft);
// 	printf("\n");
// 	j = printf("%010p",ptrori);
// 	printf("\nft: %i\nori: %i\n",i,j);
// 	printf("\n----------- TEST 2 010[-1]-------------\n");
// 	i = ft_printf("%010p",-1);
// 	printf("\n");
// 	j = printf("%010p",-1);
// 	printf("\nft: %i\nori: %i\n",i,j);
// 	printf("\n----------- TEST 3 010[\\r\\t\\ e big money /0] -------------\n");
// 	i = ft_printf("%010p","\r\t\ebig money\0");
// 	printf("\n");
// 	j = printf("%010p","\r\t\ebig money\0");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 4 010[]-------------\n");
// 	i = ft_printf("%010p","");
// 	printf("\n");
// 	j = printf("%010","");
// 	printf("\nft: %i\nori: %i\n",i,j);
// }

// void ptr_test2ZERO()
// {
// 	int i;
// 	int j;

// 	printf("\n----------- TEST 5 010[43] -------------\n");
// 	i = ft_printf("%010p",43);
// 	printf("\n");
// 	j = printf("%010p",43);
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 6 010[Ko ni chi wa is a new greeting form]-------------\n");
// 	i = ft_printf("%010p","Ko ni chi wa is a new greeting form");
// 	printf("\n");
// 	j = printf("%010p","Ko ni chi wa is a new greeting form");
// 	printf("\nft: %i\nori: %i\n","Ko ni chi wa is a new greeting form");
// 	printf("\n----------- TEST 7 010[\\r\\t\\ e big money /0] -------------\n");
// 	i = ft_printf("%010p","\r\t\ebig money\0");
// 	printf("\n");
// 	j = printf("%010p","\r\t\ebig money\0");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 8 010[]-------------\n");
// 	i = ft_printf("%010p","");
// 	printf("\n");
// 	j = printf("%010p","");
// 	printf("\nft: %i\nori: %i\n",i,j);
// }

void hex_test1ZERO()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 1 00 -------------\n");
	i = ft_printf("%01X",0);
	printf("\n");
	j = printf("%01X",0);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 1.2 02[10]-------------\n");
	i = ft_printf("%02X",10);
	printf("\n");
	j = printf("%02X",10);
	printf("\nft: %i\nori: %i\n",i,j);
}

void hex_test2ZERO()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 01(43)-------------\n");
	i = ft_printf("%01x",43);
	printf("\n");
	j = printf("%01x",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.2 05[43]-------------\n");
	i = ft_printf("%05x",43);
	printf("\n");
	j = printf("%05x",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.3 02[2]-------------\n");
	i = ft_printf("%02x",2);
	printf("\n");
	j = printf("%02x",2); 
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.4 01[2]-------------\n");
	i = ft_printf("%01x",2);
	printf("\n");
	j = printf("%01x",2);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.5 010[1000]-------------\n");
	i = ft_printf("%010x",1000);
	printf("\n");
	j = printf("%010x",1000);
	printf("\nft: %i\nori: %i\n",i,j);
}

// void per_test1ZERO()
// {
// 	int i,j;
// 	printf("\n----------- TEST 1 010[%%%] -------------\n");
// 	i = ft_printf("%010%%%");
// 	printf("\n");
// 	j = printf("%010%%%");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 2 010[%% %% %%%%%%%% % %%% %]-------------\n");
// 	i = ft_printf("%010%% %% %%%%%%%% % %%% %");
// 	printf("\n");
// 	j = printf("%010%% %% %%%%%%%% % %%% %");
// 	printf("\nft: %i\nori: %i\n","Ko ni chi wa is a new greeting form");
// 	printf("\n----------- TEST 3 010[%] -------------\n");
// 	i = ft_printf("%010%");
// 	printf("\n");
// 	j = printf("%010%");
// 	printf("\nft: %i\nori: %i\n",i,j);
// 		printf("\n----------- TEST 4 010[%^%^%^^%%]-------------\n");
// 	i = ft_printf("%010%^%^%^^%%");
// 	printf("\n");
// 	j = printf("%010%^%^%^^%%");
// 	printf("\nft: %i\nori: %i\n",i,j);
// }

// int main(void) {
//     // int_test1ZERO();     
//     // int_test2ZERO();  
//     uns_test1ZERO();  
//     uns_test2ZERO();  
//     // test5ZERO();  
//     // test6ZERO();  
// }
