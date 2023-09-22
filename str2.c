#include "shell.h"

/**
 * _string_length - the length
 * @c: the string
 *
 * Return: length of c
 */
int _string_length(char *c)
{
	int x = 0;

	if (!c)
		return (0);

	while (*c++)
		x++;
	return (x);
}

/**
 * _string_comparison - funcation that make comparison between strings
 * @string1: string1
 * @string2: string2
 *
 * Return: - when string1 < string2, + when string1 >
 * string2, 0 when if string1 == string2
 */
int  _string_comparison(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);

	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * is_string_starts_with - checks if strings starts at the same time
 * @a: string to search
 * @b: thr substring to find
 *
 * Return: address
 */
char *is_string_starts_with(const char *a, const char *b)
{
	while (*b)
		if (*b++ != *a++)
			return (NULL);
	return ((char *)a);
}

/**
 * _string_concatenates - concatenates strings
 * @d: the destination
 * @s: the source
 *
 * Return: pointer
 */
char *_string_concatenates(char *d, char *s)
{
	char *z = d;

	while (*d)
		d++;
	while (*s)
		*d++ = *s++;
	*d = *s;
	return (z);
}
