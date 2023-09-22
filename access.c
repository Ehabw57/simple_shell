#include "shell.h"
int accessable(char *cmd, char *arg[])
{
    int stat;
    stat = access(cmd, X_OK);
    if (stat == 0)
    {
        _exec(cmd, arg);
        return (0);
    }
    return (-1);
}
