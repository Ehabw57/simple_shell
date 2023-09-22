#include "shell.h"

/**
 * _string_copy - copy string
 * @d: destination
 * @s: source
 *
 * Return: pointer to destination
 */
char *_string_copy(char *d, char *s)
{
	int x = 0;

	if (d == s || s == 0)
		return  (d);
	while (s[x])
	{
		d[x] = s[x];
		x++;
	}
	d[x] = 0;
	return (d);
}

/**
 * _string_duplications - dup string
 * @string: the string
 *
 * Return: pointer
 */
char *_string_duplications(const char *string)
{
	int y = 0;
	char *z;

	if (string == NULL)
		return (NULL);
	while (*string++)
		y++;
	z = malloc(sizeof(char) * (y + 1));
	if (!z)
		return (NULL);
	for (y++; y--;)
		z[y] = *--string;
	return (z);
}

/**
 * _print_string - print string
 * @string: string
 *
 * Return: void
 */
void _print_string(char *string)
{
	int x = 0;

	if (!string)
		return;
	while (string[x] != '\0')
	{
		_putchar(string[x]);
		x++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1 ,  On error, -1
 */
int _putchar(char c)

{
	return (write(1, &c, 1));
}

