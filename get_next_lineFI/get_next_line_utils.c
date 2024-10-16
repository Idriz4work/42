#include "get_next_line.h"

// Custom strlen function
size_t ft_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

// Safely joins two strings
char *ft_strjoin(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return NULL;

    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    char *str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));

    if (str == NULL)
        return NULL;

    int i = 0;
    while (i < len1)
    {
        str[i] = s1[i];
        i++;
    }

    int j = 0;
    while (j < len2)
    {
        str[i + j] = s2[j];
        j++;
    }

    str[i + j] = '\0';
    return str;
}

// Helper function to free memory and set pointers to NULL
int freeler(char **s1, char **s2, char **s3)
{
    if (s1 && *s1)
    {
        free(*s1);
        *s1 = NULL;
    }
    if (s2 && *s2)
    {
        free(*s2);
        *s2 = NULL;
    }
    if (s3 && *s3)
    {
        free(*s3);
        *s3 = NULL;
    }
    return 1;
}

// Updates the valueholder by removing the line that was read
void update_holder(char **valueholder)
{
    int j;
    int newline_pos;
    char *newline;
    
    if (!valueholder || !*valueholder)
        return;
    newline = strchr(*valueholder, '\n');
    if (newline == NULL)
    {
        (*valueholder)[0] = '\0';
        return;
    }

    newline_pos = (newline - *valueholder) + 1; 
    j = 0;
    while ((*valueholder)[newline_pos + j] != '\0')
    {
        (*valueholder)[j] = (*valueholder)[newline_pos + j];
        j++;
    }
    (*valueholder)[j] = '\0'; 
}

// Inserts a line into the line buffer
char *insert_line(char **valueholder)
{
    int i;
    int j;
    char *line;
    char *indicator;

    i = 0;
    j = 0;
    line = (char *)malloc(ft_strlen(*valueholder) + 1);
    if (line == NULL)
        return NULL;
    indicator = strchr(*valueholder, '\n');
    if (indicator)
    {
        while ((*valueholder)[i] != '\n' && (*valueholder)[i] != '\0')
            line[j++] = (*valueholder)[i++];
        line[j++] = (*valueholder)[i++];
        line[j] = '\0';
    }
    else
    {
        while ((*valueholder)[i] != '\0')
            line[j++] = (*valueholder)[i++];
        line[j] = '\0';
        freeler(valueholder, NULL, NULL);
        return line;
    }
    update_holder(valueholder);
    return line;
}

// Reads from the file and updates valueholder
int read_file(char **valueholder, int bytes, int fd)
{
    char *temp, *newline;

    temp = (char *)malloc(BUFF_SIZE + 1);
    if (temp == NULL)
        return -1;

    bytes = read(fd, temp, BUFF_SIZE);
    if (bytes > 0)
    {
        temp[bytes] = '\0';
        newline = ft_strjoin(*valueholder, temp);
        free(temp);
        free(*valueholder);
        *valueholder = newline;
        if (*valueholder == NULL)
            return -1;
        if (strchr(*valueholder, '\n'))
            return 1;
    }
    if (bytes <= 0)
    {
        free(temp);
        return bytes;
    }
    return 2;
}