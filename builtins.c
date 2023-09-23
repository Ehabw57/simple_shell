#include "shell.h"
int _unsetenv(char **env)
{
    int index;

    index = _getenv(env[1], environ);
    if (index < 0)
        return (1);
    index--;
    while (environ[index] != NULL)
    {
        index++;
        environ[index] = environ[index + 1];
    }
    return (0);
}

int _hsexit(char **arg)
{
    int code;
    if (arg[1] == NULL)
    {
        free(arg);
        return (69);
    }
    else
    {
code = _atoi(arg[1]);
        exit(code);
    }
    return (0);
}
int env(char **env)
{
    int i = 0;

    while (environ[i] != NULL && env)
    {
        write(1, environ[i], _strlen(environ[i]));
        write(1, "\n", 1);
        i++;
    }
    status = 0;
    return (0);
}
int builtins(char *cmd, char **arg)
{
    int i = 0;
    buit_t arr[4] = {{"exit", _hsexit}, {"env", env}, {"unsetenv", _unsetenv}, {NULL, NULL}};

    if (cmd == NULL || arg == NULL)
        return (-1);

    while (arr[i].name != NULL)
    {
        if (_strcmp(arr[i].name, cmd) == 1)
        {
            return (arr[i].ptr(arg));
        }
        i++;
    }
    return (1);
}
