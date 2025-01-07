#include <unistd.h>

int is_blank(char c)
{
    if (c == ' ' || c == '\n' || c == '\t')
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    int start;
    int end;

    if (argc == 2)
    {
        // Find string length
        while (argv[1][i] != '\0')
            i++;
        
        // Start from the end (point to last character)
        i--;
        
        // Process each word from end to start
        while (i >= 0)
        {
            // Skip spaces from right
            while (i >= 0 && is_blank(argv[1][i]))
                i--;
            end = i + 1;
            
            // Find start of word
            while (i >= 0 && !is_blank(argv[1][i]))
                i--;
            start = i + 1;
            
            // Print the word
            int j = start;
            while (j < end)
            {
                write(1, &argv[1][j], 1);
                j++;
            }
            
            // Print space if not at beginning
            if (i >= 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}