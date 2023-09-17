#include "main.h"

/**
 * _strlen - counts the lenth of passed string
 * source: the string to count it's lenth
 * Return: (-1) if 
*/
int _strlen(const char *source)
{
	unsigned int len = 0;

	if (source == NULL)
		return (-1);

	while (source[len] != '\0')
		len++;
	return (len);
}

int _strncmp(const char *dest, const char *source, unsigned int index)
{
	int i = 0;

	if (dest == NULL || source == NULL)
		return (-1);

	if (index > _strlen(dest) || index > _strlen(source))
		return (-2);

	while (dest[i] == source[i])
	{
		if (i == index)
			return (1);
		i++;
	}
	return (0);
}

int _varcmp(const char *var, const char *env)
{
	int i;

	if (var == NULL || env == NULL)
		return (-1);

	for (i = 0; var[i] == env[i]; i++)
	{
		if (var[i] == '\0' && env[i + 1] == '=')
			return (1);
	}
	return (0);
}

/**
 * _stringcpy - Copies the string pointed to src
 * @destination: Pointer to the destination
 * @source: Pointer to the src
 *
 * Return: Pointer
 */
char *_stringcpy(char *destination, char *source)
{
	int x = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[x])
	{
		destination[x] = source[x];
		x++;
	}
	destination[x] = 0;
	return (destination);
}
