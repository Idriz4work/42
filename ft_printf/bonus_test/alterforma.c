

#include <stdio.h>
# include "../ft_printf.h"
# include "../ft_printf_bonus.h"
#include <limits.h>

void	test_lowerhexALT(void)
{
	int i = printf("================TEST 1 [#0:0]=======================\n\n");
	i = ft_printf("%#x",0);
	printf("\n");
	int j = printf("%#x",0);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void	test_lowerhexALT2(void)
{
	int i = printf("\n================TEST 1 [#30:432]=======================\n\n");
	i = ft_printf("%#30x",432);
	printf("\n");
	int j = printf("%#30x",432);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void test_lowerhexALT3(void)
{
    int i = printf("\n================TEST 2 [#x with signed and various limits]=======================\n\n");
//     i = printf(" %#x ", -14); 
// 	printf("\n");      // Signed negative
    // int j = ft_printf(" %#x ", -14); // ft_printf Signed negative
	int j;
	//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", -15);       // Signed negative
// printf("\n");
//     j = ft_printf(" %#x ", -15);    // ft_printf Signed negative
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", -16);       // Signed negative
// printf("\n");
//     j = ft_printf(" %#x ", -16);    // ft_printf Signed negative
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", -99);       // Large signed negative
// printf("\n");
//     j = ft_printf(" %#x ", -99);    // ft_printf Large signed negative
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", -100);      // Large signed negative
// printf("\n");
//     j = ft_printf(" %#x ", -100);   // ft_printf Large signed negative
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", -101);      // Large signed negative
// printf("\n");
//     j = ft_printf(" %#x ", -101);   // ft_printf Large signed negative
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", INT_MAX);   // Maximum integer
// printf("\n");
//     j = ft_printf(" %#x ", INT_MAX); // ft_printf Maximum integer
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

    j = ft_printf(" %#X%#X ", INT_MIN,INT_MAX); // ft_printf Minimum integer
    printf("\n");
    i = printf(" %#X%#X ", INT_MIN,INT_MAX);   // Minimum integer
printf("\n");
    printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", LONG_MAX);  // Maximum long
// printf("\n");
//     j = ft_printf(" %#x ", LONG_MAX); // ft_printf Maximum long
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", UINT_MAX);  // Maximum unsigned int
// printf("\n");
//     j = ft_printf(" %#x ", UINT_MAX); // ft_printf Maximum unsigned int
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", ULONG_MAX); // Maximum unsigned long
// printf("\n");
//     j = ft_printf(" %#x ", ULONG_MAX); // ft_printf Maximum unsigned long
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

//     i = printf(" %#x ", 9223372036854775807LL); // Large long long
// printf("\n");
//     j = ft_printf(" %#x ", 9223372036854775807LL); // ft_printf Large long long
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);

    // Multiple values test
//     i = printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf("\n");
//     j = ft_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//     printf("\n");
//     printf("RESULT: ft: %i \t or: %i\n", j, i);
// 	i = printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf("\n");
// j = ft_printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// printf("\n");
// printf("RESULT: ft: %i \t or: %i\n", j, i);

}


void	test_lowerhexALT4(void)
{
}