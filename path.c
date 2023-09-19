#include "main.h"
/**
 * *_ispath - checks path is valid
 * @dir: tokenized path
 * @cmd: entered command
 *
 * Return: path with command on success , NULL on fail
 */
char *_ispath(char **dir, char *cmd)
{
	int x = 0;
	char *full;

	while (dir[x])
	{
		full = _strcat(dir[x], cmd);
		printf("%s\n", full);
		if (access(full, F_OK | X_OK) == 0)
			return (full);
		free(full);
		x++;
	}
	return (NULL);
}
