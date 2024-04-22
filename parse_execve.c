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
