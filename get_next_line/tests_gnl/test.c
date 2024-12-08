

#include "../get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 

void testerror()
{
    int i = 0;
    const int fd = open("tests/readerror.txt", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Don't forget to close the file descriptor
}

void test1()
{
    int i = 0;
    const int fd = open("tests/1char.txt", O_RDONLY); 
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  
}

void testemp()
{
    int i = 0;
    const int fd = open("tests/testemp.txt", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void test1test()
{
    int i = 0;
    const int fd = open("tests/test1.txt", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void testlong()
{
    int i = 0;
    const int fd = open("tests/long.txt", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void testpy()
{
    int i = 0;
    const int fd = open("tests/random.py", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void testjs()
{
    int i = 0;
    const int fd = open("tests/testJS.js", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void testhtml()
{
    int i = 0;
    const int fd = open("tests/testhtml.html", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

void testnl()
{
    int i = 0;
    const int fd = open("tests/1nl", O_RDONLY);  // Adjusted path
    char *line[3] = {NULL, NULL, NULL};
    while (line[i] != NULL)
    {
        line[i] = get_next_line(fd);
        printf("result of line[%i]: %s\n", i, line[i]);
        i++;
    }
    if (line[i] != NULL)
        printf("MISTAKE AT line[%i]: %s", i, line[i]);
    close(fd);  // Close the file descriptor
}

int main(void)
{
    testerror();
    test1test();
    testlong();
    test1();
    testemp();  
    testpy();  
    testjs();  
    testhtml();  
    testnl();  
    return 0;
}
