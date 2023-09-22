#include "shell.h"

int _hsexit(char **arg)
{
    if (arg[1] == NULL || arg[0] != NULL)
    {
        free(arg);
     return (69);
    }
return(0);
}
int env(char **env)
{
    int i = 0;

    while (environ[i] != NULL && env)
    {
        write(1, environ[i], _strlen(environ[i]));
        write(1, "\n", 1);
    }
    status = 0;
    return (0);
}
int builtins(char *cmd, char **arg)
{
    int i = 0;
    buit_t arr[3] = {{"exit", _hsexit}, {"env", env}, {NULL, NULL}};

    if (cmd == NULL || arg == NULL)
        return (-1);

    while (arr[i].name != NULL)
    {
        if (_strcmp(arr[i].name, cmd) == 1)
        {
            return(arr[i].ptr(arg));
        }
        i++;
    }
    return (1);
}
