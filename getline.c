#include "main.h"
void *_realloc(void *pointer, unsigned int prev_mem_size,
		unsigned int new_mem_size)
{
		char *c;

			if (!pointer)
				return (malloc(new_mem_size));
			if (!new_mem_size)
				return (free(pointer), NULL);
			if (new_mem_size == prev_mem_size)
				return (pointer);

			c = malloc(new_mem_size);
			if (!c)
				return (NULL);

			prev_mem_size = prev_mem_size < new_mem_size ?
				prev_mem_size : new_mem_size;

			while (prev_mem_size--)
				c[prev_mem_size] = ((char *)pointer)[prev_mem_size];
			free(pointer);
			return (c);
}

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t bytesRead = 0;
	ssize_t totalBytesRead = 0;
	char *buffer = NULL;
	char *temp = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	buffer = *lineptr;
	while (1)
	{
		bytesRead = read(fd, buffer + totalBytesRead, 1);
		if (bytesRead == -1)
			return (-1);
		else if (bytesRead == 0)
			break;
		else
		{
			totalBytesRead += bytesRead;
			if (totalBytesRead >= *n)
			{
				*n *= 2;
				temp = (char *)_realloc(*lineptr, *n,(*n)/2);
				if (temp == NULL)
				{
					free(*lineptr);
					return -1;
				}
				buffer = temp;
				*lineptr = buffer;
			}
			if (buffer[totalBytesRead - 1] == '\n')
				break;
		}
	}
	return totalBytesRead;
}
int main(void)
{
	char *line;
	size_t n =1;

	_getline(&line,&n,STDIN_FILENO);
	printf("%s\n",line);
	free(line);


}
