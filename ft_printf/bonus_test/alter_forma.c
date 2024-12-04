

void	test_lowerhexALT(void)
{
	int i = printf("================TEST 1 [#0:0]=======================\n\n");
	i = ft_printf("%#0x",0);
	printf("\n");
	int j = printf("%#0x",0);
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

void	test_lowerhexALT3(void)
{
}

void	test_lowerhexALT4(void)
{
}