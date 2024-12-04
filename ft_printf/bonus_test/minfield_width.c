
void int_MIN_test1(void)
{
	int i = printf("================TEST 1 [ 0:0]=======================\n\n");
	i = ft_printf("% 0i",0);
	printf("\n");
	int j = printf("% 0i",0);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}
void int_MIN_test2(void)
{
	int i = printf("================TEST 1 [ 0:12324]=======================\n\n");
	i = ft_printf("% 0i",12324);
	printf("\n");
	int j = printf("% 0i",12324);
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
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
	i = ft_printf("% 0s","");
	printf("\n");
	int j = printf("% 0s","");
	printf("\n");
	printf("RESULT: ft: %i \t or: %i\n",i,j);
}
