#ifndef HEADER_H
#define HEADER_H

/* libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/* global var */
extern char **environ;

/* prototypes */
char *_getenv(const char *name);
int execute(char **args);
char *find_path(char *command);
int trim_spaces(char *str);
void _printenv(void);
char **parse(char *str, char *sep);
void *_calloc(unsigned int nmemb, unsigned int size);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char **_split(char *str, char *sep);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(const char *s);

#endif
