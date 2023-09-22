#include "shell.h"
int path_finder(char *cmd, char **arg)
{
	char *dir;
	char *path, *move;
	int i = 0, indx, status;

	indx = _getenv("PATH", environ);
	if (indx < 0)
		return (-1);
	path = malloc(sizeof(char) * _strlen(environ[indx] + 4));
	if (path == NULL)
		return (-1);

	_strcpy(path, environ[indx] + 5);

	move = path;
	indx = 0;
	for (i = 0; move[i] != '\0'; i++)
	{

		if (move[i] == ':' || move[i] == '\0')
		{
			move[i] = '\0';
			dir = malloc(sizeof(char) * (i + _strlen(cmd) + 2));
			_strcpy(dir, move);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			status = access(dir, X_OK);
			if (status == 0)
			{
				free(path);
				_exec(dir, arg);
				free(dir);
				return (0);
			}
			else
			{
				free(dir);
				move += (i + 1);
				i = 0;
			}
		}
	}
	free(path);
	return (1);
}

