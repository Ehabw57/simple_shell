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
*/
typedef struct beltins
{
	char *name;
	int (*ptr)(char **);
} buit_t;
int builtins(char *cmd, char **arg);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char *_strtok(char *source, char *deil);
int _strncmp(const char *dest, const char *source, unsigned int index);
int _strcmp(const char *dest, const char *source);
int _strlen(const char *source);
char *_strcpy(char *destination, char *source);
int _varcmp(char *var, char *env);
void *_realloc(void *pointer, unsigned int prev_mem_size,
unsigned int new_mem_size);
int _getenv(char *var, char **env);

#endif
