#include "ssh_header.h"
#define MAX_COMMAND_LENGTH 100
/**
 * parse_command - to tokenise the user's input
 * @command: the string by the user's input
 * @args: the array of strings representing the parsed
 * arguments
 */
void parse_command(char *command, char *args[])
{
char *delimeter = " \n";
char *token;
int argc = 0;

token = strtok(command, delimeter);
while (token != NULL && argc < MAX_COMMAND_LENGTH)
{
args[argc++] = token;
token = strtok(NULL, delimeter);
}
args[argc] = NULL;
}

void find_path(char *final)
{
char *pathvar = getenv("PATH");
 char *token, *cmd = "/ls";
    struct stat st;

    if (pathvar == NULL) 
    {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        return;
    }

    token = strtok(pathvar, ":");
    while (token != NULL) 
    {
        final = malloc(strlen(token) + strlen(cmd) + 1);
        if (final == NULL) 
	{
            fprintf(stderr, "Error: Memory allocation failed\n");
            return;
        }
        strcpy(final, token);
        strcat(final, cmd);

        printf("Status of %s: ", final);
        if (stat(final, &st) == -1) 
	{
	  fprintf(stderr, "Error: PATH environment variable not found\n");
	  free(final);
        }
	else 
	{
	  return;
        }
        token = strtok(NULL, ":");
    }
}

/**
 * execute_command - to execute new process
 * by replacing the previous
 * @command: the path of the command
 * @args: command arguments or flags
 */
void execute_command(char *command, char *args[])
{
extern char **environ;
pid_t pid;
int status;
if (command == NULL)
{
return;
}
find_path(command);
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(command, args, environ) == -1)
{
perror("execve");
exit(EXIT_FAILURE);
}
}
else
{
if (wait(&status) == -1)
{
perror("wait");
exit(EXIT_FAILURE);
}
}
}
