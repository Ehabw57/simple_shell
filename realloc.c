#include "shell.h"

/**
 *  **_store - function that store in memory
 *  *@po: the pointer to the memory
 *  *@y: byte that store in memory
 *  *@n: num of bytes
 *  *Return: pointer
 */
char *_store(char po, char y, unsigned int n)
{
			unsigned int x;

		for (x = 0; x < n; x++)
			po[x] = y;
			return (po);
}

/**
 *  * delete - function frees a dynamically allocated array of strings.
 *  * @p:  Pointer to the array of strings.
 */
void deletee(char **p)
{
		char **s = p;

		if (!p)
			return;

		while (*p)
			free(*p++);
			free(s);
}

/**
 *  * _Realloc - function reallocates a block of memory to a new size
 *  * @pointer: pointer to previous memory
 *  * @prev_mem_size: size of previous mem
 *  * @new_mem_size: size of new mem
 *  *
 *  * Return: pointer .
 */
void *_Realloc(void *pointer, unsigned int prev_mem_size,
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
