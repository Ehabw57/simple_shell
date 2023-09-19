#include "main.h"
/**
 * builtins - check weather the given line is builtin function or not
 * @cmd: the command name
 * @arg: the command args
 * Return: 0 on success , 1 if fails, -1 on error
 */
int builtins(char *cmd, char **arg)
{
	int i = 0, id;
	buit_t arr[2] = {{NULL, NULL}, {NULL, NULL}};

	if (cmd == NULL || arg == NULL)
		return (-1);

	while (arr[i].name != NULL)
	{
		if (_strcmp(arr[i].name, cmd) == 1)
		{
			id = fork();
			if (id > 0)
				return (-1);

			if (id == 0)
			{
				arr[i].ptr(arg);
			}
			else
			{
				wait(NULL);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
