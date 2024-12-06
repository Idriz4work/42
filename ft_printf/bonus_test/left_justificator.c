
#include <stdio.h>
# include "../ft_printf.h"
# include "../ft_printf_bonus.h"
#include <limits.h>


// Integer left-justified tests
void int_LFT_test1(void)
{
	int i;
	int j;
	printf("=================== TEST LEFT JUSTIFICATOR  (C) ====================\n\n");
	i = ft_printf("%-21c",'d');
	printf("\n");
	j = printf("%-21c",'d');
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
	i = ft_printf("%-21c%-10c",'d','a');
	printf("\n");
	j = printf("%-21c%-10c",'d','a');
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
	printf("=================== TEST LEFT JUSTIFICATOR (INT) ====================\n\n");
	i = ft_printf("%-1c",INT_MIN);
	printf("\n");
	j = printf("%-1c",INT_MIN);
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
	i = ft_printf("%-21i",INT_MAX);
	printf("\n");
	j = printf("%-21i",INT_MAX);
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
}
void int_LFT_test2(void)
{
	int i,j;
	printf("=================== TEST LEFT JUSTIFICATOR (INT) ====================\n\n");
	i = ft_printf("%-1c",0);
	printf("\n");
	j = printf("%-1c",0);
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
	i = ft_printf("%-21i",342);
	printf("\n");
	j = printf("%-21i",342);
	printf("\n");
	printf("RESULT\n ft: %i\nori:%i\n",i,j);
}

// Unsigned Integer left-justified tests
void uns_LFT_test1(void)
{
    int i, j;
    printf("----------- TEST 1.3 0 100 [INT MAX VALUE && MINUS VALUE] -------------\n");
    i = ft_printf("%-i", INT_MAX);
    printf("\n");
    j = printf("%-i", INT_MAX);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("%-i", INT_MIN);
    printf("\n");
    j = printf("%-i", INT_MIN);
    printf("\n");

    printf("----------- TEST 1.5 FAILED TESTS FRANCI -------------\n");
    i = ft_printf("%-i", LONG_MAX);
    printf("\n");
    j = printf("%-i", LONG_MAX);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("%-d", -42);
    printf("\n");
    j = printf("%-d", -42);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("%-d", INT_MIN);
    printf("\n");
    j = printf("%-d", INT_MIN);
    printf("\nft: %i\nori: %i\n", i, j);
	printf("\n----------- TEST 1.4 024[102332]-------------\n");
	i = ft_printf(" %-i %-i %-i %-d %-d %-d %-d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n");
	j = printf(" %-i %-d %-d %-d %-d %-d %-d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i\nori: %i\n",i,j);
}
void uns_LFT_test2(void)
{

}

// String left-justified tests
void str_LFT_test1(void)
{

}
void str_LFT_test2(void)
{

}

// Pointer left-justified tests
void ptr_LFT_test1(void)
{

}
void ptr_LFT_test2(void)
{

}

// Hexadecimal left-justified tests
void hex_LFT_test1(void)
{

}
void hex_LFT_test2(void)
{

}

// Percentage left-justified tests
void per_LFT_test1(void)
{

}
