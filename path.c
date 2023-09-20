#include "main.h"
/**
 * *_ispath - checks path is valid
 * @dir: tokenized path
 * @cmd: entered command
 *
 * Return: path with command on success , NULL on fail
 */
char *_ispath(char **env, char *cmd)
{
	int x = 0, index;
	char *full;
	char *dir[100];

	index = _getenv("PATH", env);
	dir[0] = _strtok(env[index], ":");
	while (dir[x] != NULL)
	{
		x++;
		dir[x] = _strtok(NULL, ":");
	}
	x = 0;
	while (dir[x])
	{
		full = _strcat(dir[x], cmd);
		printf("%s iam strcat\n",full);
		if (access(full, F_OK | X_OK) == 0)
			return (full);
		free(full);
		x++;
	}
	return (NULL);
}
