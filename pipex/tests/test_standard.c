
#include "../sources/pipex.h"

int main()
{
	pipex("file1 grep a1 | wc -w file2");
	stdout("< file1 grep a1 | wc -w > file2");
	printf("RESULT MUST BE 0\n");

	pipex("file1 ls -l | wc -l file2");
	stdout("< file1 ls -l | wc -l > file2");
	printf("RESULT MUST BE 0\n");

}