#include "shell.h"
void _peror(char *mesg, char *shell, char *cmd, int code)
{
    char num;
    write(2, shell, _strlen(shell));
    write(2, ": ", 2);
    num = code + '0';
    write(2, &num, 1);
    write(2, ": ", 2);
    write(2, cmd, _strlen(cmd));
    write(2, mesg, _strlen(mesg));
    status = 127;
}
