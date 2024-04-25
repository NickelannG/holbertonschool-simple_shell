#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

extern char **environ;


char *_getenv(const char *name);
int execute(char **args);
char *find_path(char *command);
int trim_spaces(char *str);
void _printenv(void);
char **parse(char *str, char *sep);

#endif
