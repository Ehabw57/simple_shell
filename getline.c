#include <stdio.h>
#include <unistd.h>
#include "main.h"
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
    ssize_t bytesRead = 0;
    ssize_t totalBytesRead = 0;
    char *buffer = NULL;
    char *temp = NULL;

    if (lineptr == NULL || n == NULL)
        return -1; 

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128; 
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            return -1;
        }
    }

    buffer = *lineptr;

    while (1)
    {
        bytesRead = read(fd, buffer + totalBytesRead, 1);

        if (bytesRead == -1)
            return -1; 
        else if (bytesRead == 0)
            break; 

        else
        {
            totalBytesRead += bytesRead;

            if (totalBytesRead >= *n)
            {
                *n *= 2;
                temp = (char *)realloc(*lineptr, *n);
                if (temp == NULL)
                {
                    free(*lineptr);
                    return -1; 
                }
                buffer = temp;
                *lineptr = buffer;
            }

            if (buffer[totalBytesRead - 1] == '\n')
            {
                break;
            }
        }
    }

    return totalBytesRead;
}
int main(void)
{
    char *buf;
    size_t size = 5;
    int rod;

    rod = _getline(&buf, &size, STDIN_FILENO);
    printf("%s\n", buf);
    free(buf);
    return (0);
}
