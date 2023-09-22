#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
typedef struct beltins
{
	char *name;
	int (*ptr)(char **);
} buit_t;

extern char **environ;
extern int status;
int accessable(char *cmd, char *arg[]);
void _exec(char *path, char *arg[]);
void _peror(char *mesg, char *shell, char *cmd, int code);
int _hsexit(char **arg);
int _getenv(char *var, char **env);
int builtins(char *cmd, char **arg);
int path_finder(char *cmd, char **arg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *destination, char *source);
int _varcmp(char *var, char *env);
int _strlen(const char *source);
int _strcmp(const char *dest, const char *source);
char *_strcat(char *dest, char *src);

#endif
