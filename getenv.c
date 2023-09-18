#include "main.h"
/**
 * _getenv - Finds an enviroment variable in the env array
 * @var: The name of the var to be found
 * @env: An array of enviroment variables
 * Return: The index of the var (success) or -1 on (failur)
 */
int _getenv(char *var, char **env)
{
	int i;

	if (env == NULL || var == NULL)
		return (-1);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_varcmp(var, env[i]) == 1)
			return (i);
	}
	return (-1);
}
