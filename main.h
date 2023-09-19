#ifndef MAIN_H
#define MAIN_H
#define _BUFFER 1
#include <stdlib.h>
int _strncmp(const char *dest, const char *source, unsigned int index);
int _strcmp(const char *dest, const char *source);
int _strlen(const char *source);
char *_stringcpy(char *destination, char *source);
int _varcmp(const char *var, const char *env);
char *_store(char po, char y, unsigned int n);
void deletee(char **p);
void *_Realloc(void *pointer, unsigned int prev_mem_size, unsigned int new_mem_size);


#endif
