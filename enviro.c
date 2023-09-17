#include "main.h"
char *_getenv(const char *var, const char **env)
{
	int i;

	if (env == NULL || var == NULL)
		return (NULL);

	for (i = 0; env[i] != NULL; i++)
	{
		if (_varcmp(var, env[i]) == 1)
			return (env[i]);
	}
	return (NULL);
}
