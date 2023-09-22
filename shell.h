#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR	        1
#define CMD_AND	        2
#define CMD_CHAIN       3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE	0
#define USE_STRTOK	0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;

char *find_path(info_t *, char *, char *);
char *duplicates_characters(char *, int, int);
int cmd(info_t *, char *);
void deletee(char **);
void *_Realloc(void *, unsigned int, unsigned int);
char *_store(char *, char, unsigned int);
int _putchar(char);
void _print_string(char *);
char *_string_duplications(const char *);
char *_string_copy(char *, char *);
int  _string_comparison(char *, char *);
char *is_string_starts_with(const char *, const char *);
char *_string_concatenates(char *, char *);
int _string_length(char *);



