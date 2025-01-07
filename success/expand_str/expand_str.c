#include <unistd.h>

int is_blank(char c)
{
    if (c == ' ' || c == '\t' || c == '\n')
        return 1;
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    int first_word = 1;
    
    if (argc == 2)
    {
        // Skip leading spaces
        while (argv[1][i] && is_blank(argv[1][i]))
            i++;
            
        // Process each character
        while (argv[1][i])
        {
            // Print non-space characters
            if (!is_blank(argv[1][i]))
            {
                write(1, &argv[1][i], 1);
                first_word = 0;
            }
            // Handle spaces between words
            else if (!first_word)
            {
                // Skip multiple spaces
                while (argv[1][i] && is_blank(argv[1][i]))
                    i++;
                    
                // If there's another word, print three spaces
                if (argv[1][i])
                    write(1, "   ", 3);
                    
                continue;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}