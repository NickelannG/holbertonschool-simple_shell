#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 100

void parse_command(char *command, char *args[]);
char *_getenv(const char *name);
void execute_command(char *command, char *args[]);
void interactive_mode(void);
void non_interactive_mode(void);
char *find_path(char *command);
void trim_spaces(char *str);
void changeEnvVar(const char *name, const char *value);
void addEnvVar(const char *name, const char *value);
int _setenv(const char *name, const char *value, int overwrite);

#endif
