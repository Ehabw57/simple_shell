#include "shell.h"
void _exec(char *path, char *arg[])
{
    int id;

    id = fork();

    if (id == 0)
    {
        execve(path, arg, environ);
        exit(0);
    }
    else
    {
        wait(&status);
        status = status >> 8;
        return;
    }
}
