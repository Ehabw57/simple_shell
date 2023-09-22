#include "shell.h"
void _peror(char *mesg, char *shell, char *cmd, int code)
{
    char num;
    write(STDERR_FILENO, shell, _strlen(shell));
    write(STDERR_FILENO, ": ", 2);
    num = code + '0';
    write(STDERR_FILENO, &num, 1);
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, mesg, _strlen(mesg));
    status = 127;
}
