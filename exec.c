#include "main.h"
int _exec(char *cmd, char *arg[])
{

    int id, i = 0;

    printf("%s", cmd);
    while (arg[i] != NULL)
    {
        printf("%s", arg[i]);
        i++;
    }
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
