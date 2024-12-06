


// Integer sign tests
void int_SIGN_test1(void)
{
	int i = printf("================TEST 1 [+0:0]=======================\n\n");
	i = ft_printf("%+0i",0);
	printf("\n");
	int j = printf("%+0i",0);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}
void int_SIGN_test2(void)
{
	int i = printf("\n================TEST 2 [+30:-432]=======================\n\n");
	i = ft_printf("%+30d",-432);
	printf("\n");
	int j = printf("%#30d",-432);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
	printf("\n================TEST 3 [+10:-1]=======================\n\n");
	i = ft_printf("%+10i",-1);
	printf("\n");
	j = printf("%+10i",-1);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}

#include <stdio.h>
#include <limits.h>

void int_SIGN_test3(void)
{
    int i = printf("================TEST 1 [ PLUS SIGN TESTS ]=======================\n\n");
    i = ft_printf(" %+d ", INT_MIN);
    printf("\n");
    int j = printf(" %+d ", INT_MIN);
    printf("\n");
    printf("RESULT: ft: %i \t or: %i\n",i,j);
}

void int_SIGN_test4(void)
{
    int i = printf("================TEST 2 [ PLUS SIGN MULTIPLE TESTS ]=======================\n\n");
    i = ft_printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    int j = printf(" %+d %+d %+d %+d %+d %+d %+d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    printf("RESULT: ft: %i \t or: %i\n",i,j);
}