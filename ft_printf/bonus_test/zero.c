#include <stdio.h> 
#include <limits.h>
#include "../ft_printf_bonus.h"
#include "../ft_printf.h"
// cc main.c alter_forma.c  left_justificator.c  minfield_width.c  precission.c  signplus.c  zero.c ../ft_printf.c ../ft_printf_utils.c ../ft_printf_bonus_1.c ../ft_printf_bonus_2.c ../ft_printf_utils2.c ../ft_printf_bonus_utils.c ../Libft/ft_atoi.c ../handlers.c -g
void int_test1ZERO(void)
{
	int i = 0;
	int j = 0;
	// printf("----------- TEST 1 INT 00 -------------\n");
	// i = ft_printf("%01i",0);
	// printf("\n");
	// j = printf("%01i",0);
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("\n----------- TEST 1.2 02[10]-------------\n");
	// i = ft_printf("%02i",10);
	// printf("\n");
	// j = printf("%02i",10);
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("----------- TEST 1.3 0 100 [INT MAX VALUE && MINUS VALUE] -------------\n");
	// i = ft_printf("%0100i",INT_MAX);
	// printf("\n");
	// j = printf("%0100i",INT_MAX);
	// printf("\nft: %i\nori: %i\n",i,j);
	// i = ft_printf("%0100i",INT_MIN);
	// printf("\n");
	// j = printf("%0100i",INT_MIN);
	printf("----------- TEST 1.5 FAILED TESTS FRANCI -------------\n");
	i = ft_printf("%012i", LONG_MIN);
	printf("\n");
	j = printf("%012i", LONG_MIN);
	printf("\nft: %i\nori: %i\n",i,j);
	// i = ft_printf("%015d", -42);
	// printf("\n");
	// j = printf("%015d", -42);
	// printf("\nft: %i\nori: %i\n",i,j);
	// i = ft_printf("%010d",INT_MIN);
	// printf("\n");
	// j = printf("%010d",INT_MIN);
	// printf("\nft: %i\nori: %i\n",i,j);


	// printf("\n----------- TEST 1.4 024[102332]-------------\n");
	// i = ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\n");
	// j = printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nft: %i\nori: %i\n",i,j);
}

void int_test2ZERO(void)
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 INT 01(43)-------------\n");
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
	printf("\n----------- TEST 2.5 010[-1]-------------\n");
	i = ft_printf("%010i",-1);
	printf("\n");
	j = printf("%010i",-1);
	printf("\nft: %i\nori: %i\n",i,j);
}

void uns_test58()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 58 UNSIGNED 02[-1]-------------\n");
    i = ft_printf("%02u", -1);
    printf("\n");
    j = printf("%02u", -1);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test59()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 59 UNSIGNED 03[1]-------------\n");
    i = ft_printf("%03u", 1);
    printf("\n");
    j = printf("%03u", 1);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test60()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 60 UNSIGNED 04[9]-------------\n");
    i = ft_printf("%04u", 9);
    printf("\n");
    j = printf("%04u", 9);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test61()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 61 UNSIGNED 01[10]-------------\n");
    i = ft_printf("%01u", 10);
    printf("\n");
    j = printf("%01u", 10);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test62()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 62 UNSIGNED 02[11]-------------\n");
    i = ft_printf("%02u", 11);
    printf("\n");
    j = printf("%02u", 11);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test63()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 63 UNSIGNED 03[15]-------------\n");
    i = ft_printf("%03u", 15);
    printf("\n");
    j = printf("%03u", 15);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test64()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 64 UNSIGNED 04[16]-------------\n");
    i = ft_printf("%04u", 16);
    printf("\n");
    j = printf("%04u", 16);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test65()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 65 UNSIGNED 05[17]-------------\n");
    i = ft_printf("%05u", 17);
    printf("\n");
    j = printf("%05u", 17);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test66()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 66 UNSIGNED 01[99]-------------\n");
    i = ft_printf("%01u", 99);
    printf("\n");
    j = printf("%01u", 99);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test67()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 67 UNSIGNED 02[100]-------------\n");
    i = ft_printf("%02u", 100);
    printf("\n");
    j = printf("%02u", 100);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test68()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 68 UNSIGNED 03[101]-------------\n");
    i = ft_printf("%03u", 101);
    printf("\n");
    j = printf("%03u", 101);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test69()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 69 UNSIGNED 01[-9]-------------\n");
    i = ft_printf("%01u", -9);
    printf("\n");
    j = printf("%01u", -9);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test70()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 70 UNSIGNED 02[-10]-------------\n");
    i = ft_printf("%02u", -10);
    printf("\n");
    j = printf("%02u", -10);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test71()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 71 UNSIGNED 03[-11]-------------\n");
    i = ft_printf("%03u", -11);
    printf("\n");
    j = printf("%03u", -11);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test72()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 72 UNSIGNED 04[-14]-------------\n");
    i = ft_printf("%04u", -14);
    printf("\n");
    j = printf("%04u", -14);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test73()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 73 UNSIGNED 05[-15]-------------\n");
    i = ft_printf("%05u", -15);
    printf("\n");
    j = printf("%05u", -15);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test74()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 74 UNSIGNED 06[-16]-------------\n");
    i = ft_printf("%06u", -16);
    printf("\n");
    j = printf("%06u", -16);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test75()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 75 UNSIGNED 01[-99]-------------\n");
    i = ft_printf("%01u", -99);
    printf("\n");
    j = printf("%01u", -99);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test76()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 76 UNSIGNED 02[-100]-------------\n");
    i = ft_printf("%02u", -100);
    printf("\n");
    j = printf("%02u", -100);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test77()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 77 UNSIGNED 03[-101]-------------\n");
    i = ft_printf("%03u", -101);
    printf("\n");
    j = printf("%03u", -101);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test78()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 78 UNSIGNED 09[INT_MAX]-------------\n");
    i = ft_printf("%09u", INT_MAX);
    printf("\n");
    j = printf("%09u", INT_MAX);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test79()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 79 UNSIGNED 10[INT_MIN]-------------\n");
    i = ft_printf("%010u", INT_MIN);
    printf("\n");
    j = printf("%010u", INT_MIN);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test80()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 80 UNSIGNED 11[LONG_MAX]-------------\n");
    i = ft_printf("%011u", LONG_MAX);
    printf("\n");
    j = printf("%011u", LONG_MAX);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test81()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 81 UNSIGNED 12[LONG_MIN]-------------\n");
    i = ft_printf("%012u", LONG_MIN);
    printf("\n");
    j = printf("%012u", LONG_MIN);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test82()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 82 UNSIGNED 13[UINT_MAX]-------------\n");
    i = ft_printf("%013u", UINT_MAX);
    printf("\n");
    j = printf("%013u", UINT_MAX);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test83()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 83 UNSIGNED 14[ULONG_MAX]-------------\n");
    i = ft_printf("%014u", ULONG_MAX);
    printf("\n");
    j = printf("%014u", ULONG_MAX);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test84()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 84 UNSIGNED 15[9223372036854775807LL]-------------\n");
    i = ft_printf("%015u", 9223372036854775807LL);
    printf("\n");
    j = printf("%015u", 9223372036854775807LL);
    printf("\nft: %i\nori: %i\n", i, j);
}

void uns_test85()
{
    int i = 0;
    int j = 0;
    printf("----------- TEST 85 UNSIGNED Multiple values-------------\n");
    i = ft_printf("%011u %012u %013u %014u %015u", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    j = printf("%011u %012u %013u %014u %015u", LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\nft: %i\nori: %i\n", i, j);
}


void uns_test1ZERO()
{

    // uns_test58();
    // uns_test59();
    // uns_test60();
    // uns_test61();
    // uns_test62();
    // uns_test63();
    // uns_test64();
    // uns_test65();
    // uns_test66();
    // uns_test67();
    // uns_test68();
    // uns_test69();
    // uns_test70();
    // uns_test71();
    // uns_test72();
    // uns_test73();
    // uns_test74();
    // uns_test75();
    // uns_test76();
    // uns_test77();
    // uns_test78();
    // uns_test79();
    // uns_test80();
    // uns_test81();
    // uns_test82();
    // uns_test83();
    // uns_test84();
    uns_test85();

}

void uns_test2ZERO()
{
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 UNSIGNED 014(MAX VALUE [4294967295])-------------\n");
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
	
	printf("----------- TEST 1.3 0 100 [INT MAX VALUE && MINUS VALUE] -------------\n");
	i = ft_printf("%0100u",INT_MAX);
	printf("\n");
	j = printf("%0100u",INT_MAX);
	printf("\nft: %i\nori: %i\n",i,j);
	i = ft_printf("%0100u",INT_MIN);
	printf("\n");
	j = printf("%0100u",INT_MIN);
	printf("----------- TEST 1.5 FAILED TESTS FRANCI -------------\n");
	i = ft_printf("%011u", LONG_MAX);
	printf("\n");
	j = printf("%011u", LONG_MAX);
	printf("\nft: %i\nori: %i\n",i,j);
	i = ft_printf("%015u", -42);
	printf("\n");
	j = printf("%015u", -42);
	printf("\nft: %i\nori: %i\n",i,j);
	i = ft_printf("%010u",INT_MIN);
	printf("\n");
	j = printf("%010u",INT_MIN);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 1.4 024[102332]-------------\n");
	i = ft_printf(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	j = printf(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
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
	printf("----------- TEST 1 HEX 00 -------------\n");
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
	int i;
	int j;

	i = 0;
	j = 0;
	// printf("----------- TEST 2 HEX 01(43)-------------\n");
	// i = ft_printf("%01x",43);
	// printf("\n");
	// j = printf("%01x",43);
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("\n----------- TEST 2.2 05[43]-------------\n");
	// i = ft_printf("%05x",43);
	// printf("\n");
	// j = printf("%05x",43);
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("\n----------- TEST 2.3 02[2]-------------\n");
	// i = ft_printf("%02x",2);
	// printf("\n");
	// j = printf("%02x",2); 
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("\n----------- TEST 2.4 01[2]-------------\n");
	// i = ft_printf("%01x",2);
	// printf("\n");
	// j = printf("%01x",2);
	// printf("\nft: %i\nori: %i\n",i,j);
	// printf("\n----------- TEST 2.5 010[1000]-------------\n");
	// i = ft_printf("%010x",1000);
	// printf("\n");
	// j = printf("%010x",1000);
	// printf("\nft: %i\nori: %i\n",i,j);

	// printf("----------- TEST 2 UNSIGNED 014(MAX VALUE [4294967295])-------------\n");
	// i = ft_printf("%014x", 4294967295);  // Change %u to %x for hexadecimal output
	// printf("\n");
	// j = printf("%014x", 4294967295);  // Change %u to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);

	// printf("\n----------- TEST 2.2 05[43]-------------\n");
	// i = ft_printf("%05x", 43);  // Change %u to %x for hexadecimal output
	// printf("\n");
	// j = printf("%05x", 43);  // Change %u to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);

	// printf("\n----------- TEST 2.3 02[2]-------------\n");
	// i = ft_printf("%02x", 2);  // Change %i to %x for hexadecimal output
	// printf("\n");
	// j = printf("%02x", 2);  // Change %i to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);

	// printf("\n----------- TEST 2.4 01[2]-------------\n");
	// i = ft_printf("%01x", 2);  // Change %i to %x for hexadecimal output
	// printf("\n");
	// j = printf("%01x", 2);  // Change %i to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);

	// printf("\n----------- TEST 2.5 010[1000]-------------\n");
	// i = ft_printf("%010x", 1000);  // Change %i to %x for hexadecimal output
	// printf("\n");
	// j = printf("%010x", 1000);  // Change %i to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);

	printf("\n----------- TEST 1.3 0 100 [INT MAX VALUE && MINUS VALUE] -------------\n");
	// i = ft_printf("%010x", INT_MAX);  // Change %u to %x for hexadecimal output
	// printf("\n");
	// j = printf("%010x", INT_MAX);  // Change %u to %x for hexadecimal output
	// printf("\nft: %i\nori: %i\n", i, j);
	// i = ft_printf("%0100x", INT_MIN);  // Change %u to %x for hexadecimal output
	// printf("\n");
	// j = printf("%0100x", INT_MIN);  // Change %u to %x for hexadecimal output
	// printf("\n");
	// printf("\nft: %i\nori: %i\n", i, j);

	printf("\n----------- TEST 1.5 FAILED TESTS FRANCI -------------\n");
	i = ft_printf("%011x", LONG_MAX);  // Change %u to %x for hexadecimal output
	printf("\n");
	j = printf("%011x", LONG_MAX);  // Change %u to %x for hexadecimal output
	printf("\nft: %i\nori: %i\n", i, j);
	i = ft_printf("%015x", -42);  // Change %u to %x for hexadecimal output
	printf("\n");
	j = printf("%015x", -42);  // Change %u to %x for hexadecimal output
	printf("\nft: %i\nori: %i\n", i, j);
	i = ft_printf("%010x", INT_MIN);  // Change %u to %x for hexadecimal output
	printf("\n");
	j = printf("%010x", INT_MIN);  // Change %u to %x for hexadecimal output
	printf("\nft: %i\nori: %i\n", i, j);

	printf("\n----------- TEST 1.4 024[102332]-------------\n");
	i = ft_printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);  // Change %u to %x for hexadecimal output
	printf("\n");
	j = printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);  // Change %u to %x for hexadecimal output
	printf("\nft: %i\nori: %i\n", i, j);

}

void	hex_test3ZERO()
{
	printf("\n======================== [UPPER CASE TESTS] =============================\n");
	int i = 0;
	int j = 0;
	printf("----------- TEST 2 HEX 01(43)-------------\n");
	i = ft_printf("%01X",43);
	printf("\n");
	j = printf("%01X",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.2 05[43]-------------\n");
	i = ft_printf("%05X",43);
	printf("\n");
	j = printf("%05X",43);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.3 02[2]-------------\n");
	i = ft_printf("%02X",2);
	printf("\n");
	j = printf("%02X",2); 
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.4 01[2]-------------\n");
	i = ft_printf("%01X",2);
	printf("\n");
	j = printf("%01X",2);
	printf("\nft: %i\nori: %i\n",i,j);
	printf("\n----------- TEST 2.5 010[1000]-------------\n");
	i = ft_printf("%010X",1000);
	printf("\n");
	j = printf("%010X",1000);
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
