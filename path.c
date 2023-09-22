#include "shell.h"

/**
 * cmd - determines if a file is an exe
 * @i: struct
 * @p: path
 *
 * Return: 1 if true, 0 no
 */
int cmd(info_t *i, char *p)
{
	struct stat st;

	(void)i;
	if (!p || stat(p, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * duplicates_characters - duplicates characters
 * @p: the PATH
 * @s: index
 * @t: index
 *
 * Return: pointer to new buffer
 */
char *duplicates_characters(char *p, int s, int t)
{
	static xhar buffer[1024];
	int x = 0, b = 0;

	for (b = 0, x = s; x < t; x++)
		if (p[x] != ':')
			buffer[b++] = p[x];
	buffer[b] = 0;
	return (buffer);
}

/**
 * find_path - finds this cmd in the PATH
 * @i: struct
 * @p: the PATH
 * @c: the cmd
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *i, char *p, char *c)
{
	int x = 0, curr = 0;
	char *path;

	if (!p)
		return (NULL);
	if ((_string_length(c) > 2) && is_string_starts_with(c, "./"))
	{
		if (cmd(i, c))
			return (c);
	}
	while (1)
	{
		if (!p[x] || p[x] == ':')
		{
			path = duplicates_characters(p, curr,x );
			if (!*path)
				_string_concatenates(path, c);
			else
			{
				_string_concatenates(path, "/");
				_string_concatenates(path, c);
			}
			if (cmd(i, path))
				return (path);
			if (!p[x])
				break;
			curr = x;
		}
		x++;
	}
	return (NULL);
}
