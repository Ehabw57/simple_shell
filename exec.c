#include "main.h"
int _exec(char *cmd, char *arg[])
{

    int id,;
    id = fork();
    if (id == 0)
    {
        execve(cmd, arg, NULL);
        perror("cant exec the command\n");
        exit(22);
    }
    if (id > 0)
    {
        wait(NULL);
        return (0);
    }
    perror("cant fork\n");
    return (-1);
}
