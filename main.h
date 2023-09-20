#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
/**
 * struct beltins - a struct to store the name and code for all bultin funxton
 * @name: Name of the function
 * @ptr: Pointer to that functoin
 * @env: environment variable
 * @s: status of the shell
*/
typedef struct beltins
{
	char *name;
	int (*ptr)(char **);
	int s;
	char **env;
} buit_t;
int _exec(char *cmd, char *arg[]);
int builtins(char *cmd, char **arg);
char *_ispath(char **dir, char *cmd);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *source, char *deil);
int _strcmp(const char *dest, const char *source);
int _strlen(const char *source);
char *_strcpy(char *destination, char *source);
char *_strcat(char *dest, char *src);
int _varcmp(char *var, char *env);
int _getenv(char *var, char **env);
int print_env(buit_t *pointer);


#endif
