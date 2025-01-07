#include <unistd.h>

void handle(char c)
{
	int j = 0;
	if (c >= 'a' && c <= 'z')
		j = c - 'a';
	if (c >= 'A' && c <= 'Z')
		j = c - 'A';
	if (j != 0)
	{
		while (j >= 0)
		{
			write(1,&c,1);
			j--;
		}
		return;
	}
	else
		write(1,&c,1);
}

int main(int argc, char **argv)
{
	int i,j;
	i = j = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			handle(argv[1][i]);
			i++;
		}
	}
	write(1,"\n",1);
}