#include "shell.h"

/**
 * _strlen - counts the lenth of passed string
 * @source: the string to count it's lenth
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

/**
 * _varcmp - compares one string with a singel env var
 * @var: name of the env var
 * @env: pointer to env var
 * Return: 1 if the var found, 0 if not
 */
int _varcmp(char *var, char *env)
{
	int i = 0;

	if (var == NULL || env == NULL)
		return (0);

	while (var[i] == env[i] || (var[i] == '\0'))
	{
		if (var[i] == '\0' && env[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

/**
 * *_strcpy - Copies the string pointed to src
 * @destination: the string to paste to
 * @source: the string to copy from
 * Return: the result on success, NULL on failer
 */
char *_strcpy(char *destination, char *source)
{
	int x = 0;

	if (source == NULL)
		return (NULL);

	if (destination == source || source == 0)
		return (destination);
	while (source[x] != '\0')
	{
		destination[x] = source[x];
		x++;
	}
	destination[x] = '\0';
	return (destination);
}
/**
 * _strcmp - compaers 2 strings
 * @dest: The first string
 * @source: The sec string
 * Return: -1 on error, 1 on success, 0 on fails
 */
int _strcmp(const char *dest, const char *source)
{
	int i = 0;

	if (dest == NULL || source == NULL)
		return (-1);
	while (dest[i] == source[i])
	{
		if (dest[i + 1] == '\0' && source[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

/**
 * _strcat - a function that copyes tow strings
 * @dest: the one to copy text for
 * @src: the one to copy text from
 * Return: always dest
 **/
char *_strcat(char *dest, char *src)
{
	int i=0;
	int c;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);

	while(dest[i] != '\0')
	i++;

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[i] = src[c];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
