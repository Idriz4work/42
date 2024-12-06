
void int_MIN_test1(void)
{
	int i = printf("================TEST 1 [ 0:0]=======================\n\n");
	i = ft_printf("% 0i",0);
	printf("\n");
	int j = printf("% 0i",0);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}
#include <stdio.h>
#include <limits.h>

void int_MIN_test2(void)
{
    int i, j;
    printf("----------- TEST 1.3 0 100 [INT MAX VALUE && MINUS VALUE] -------------\n");
    i = ft_printf("% i", INT_MAX);
    printf("\n");
    j = printf("% i", INT_MAX);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("% i", INT_MIN);
    printf("\n");
    j = printf("% i", INT_MIN);
    printf("\n");

    printf("----------- TEST 1.5 FAILED TESTS FRANCI -------------\n");
    i = ft_printf("% i", LONG_MAX);
    printf("\n");
    j = printf("% i", LONG_MAX);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("% d", -42);
    printf("\n");
    j = printf("% d", -42);
    printf("\nft: %i\nori: %i\n", i, j);

    i = ft_printf("% d", INT_MIN);
    printf("\n");
    j = printf("% d", INT_MIN);
    printf("\nft: %i\nori: %i\n", i, j);
	// printf("\n----------- TEST 1.4 024[102332]-------------\n");
	// i = ft_printf(" % i % i % i % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\n");
	// j = printf(" % i % d % d % d % d % d % d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nft: %i\nori: %i\n",i,j);
}

// String minimum width tests
void str_MIN_test1(void)
{
	int i = printf("================TEST 1 [ 0:Hello world]=======================\n\n");
	i = ft_printf("% 0s","Hello world");
	printf("\n");
	int j = printf("% 0s","Hello world");
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}
void str_MIN_test2(void)
{
	int i = printf("================TEST 1 [ 0:empty]=======================\n\n");
	i = ft_printf("% 1s","");
	printf("\n");
	int j = printf("% 1s","");
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void str_MIN_test3(void)
{
int i = printf("================TEST 1 [ STRING TESTS ]=======================\n\n");
i = ft_printf("% s", "");
printf("\n");
int j = printf("% s", "");
printf("\n");
printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void str_MIN_test4(void)
{
int i = printf("================TEST 2 [ STRING TESTS ]=======================\n\n");
i = ft_printf(" % s ", "");
printf("\n");
int j = printf(" % s ", "");
printf("\n");
printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void str_MIN_test5(void)
{
int i = printf("================TEST 3 [ STRING TESTS ]=======================\n\n");
i = ft_printf(" % s ", "-");
printf("\n");
int j = printf(" % s ", "-");
printf("\n");
printf("RESULT: ft: %i \t or: %i\n",i,j);
}
