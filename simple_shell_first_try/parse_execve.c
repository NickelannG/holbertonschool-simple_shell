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
 * description - gets an environment variable without using getenv
 * main - entry point
 * @name: a NULL terminated string containing the name of the environment
 * variable
 *
 * Return: a pointer to the value string, or -1 if it failed
 */
char *_getenv(const char *name)
{
	extern char **environ;
	char *token;
	int i = 0;

	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");

		if (strcmp(token, name) == 0) /* match */
		{
			token = strtok(NULL, "61");
			return (token);
		}
		token = strtok(NULL, "=");
		i++;
	}
	return (NULL); /* Variable not found */
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
char *command_path = _getenv("PATH");
pid_t pid;
int status;
char *ls_path;

if (strcmp(command, "exit") == 0) 
{
	exit(EXIT_SUCCESS);
}
if (command == NULL || command_path == NULL)
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
	/* args[0] = command_path; */
if(strcmp(command, "ls") == 0)
{
	ls_path = "/bin/ls";

if (execve(ls_path, args, environ) == -1)
{
	fprintf(stderr, "Failed to execute command: %s\n", command);
	perror("execve");
	exit(EXIT_FAILURE);
}
}
else
{
	fprintf(stderr, "Unknown command: %s\n", command);
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
