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
pid_t pid;
int status;
pid = fork();
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execvp(command, args) == -1)
{
perror("execvp");
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

/**
 * main - simple shell interative entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
char *command = NULL;
char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
size_t len = 0;
while (1)
{
printf("$ ");
fflush(stdout);
if (getline(&command, &len, stdin) == -1)
{
printf("\n");
free(command);
break;
}
parse_command(command, args);
execute_command(args[0], args);
}
free(command);
return (0);
}
