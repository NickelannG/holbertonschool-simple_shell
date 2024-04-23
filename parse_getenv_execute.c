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

    if (command == NULL || *command == '\0' || *command == '\n') {
        fprintf(stderr, "Empty command\n");
        return;
    }

    token = strtok(command, delimeter);
    if (token == NULL) {
        fprintf(stderr, "No arguments found in command\n");
        return;
    }

    while (token != NULL && argc < MAX_COMMAND_LENGTH)
    {
        args[argc++] = token;
        token = strtok(NULL, delimeter);
    }

    if (argc >= MAX_COMMAND_LENGTH)
    {
        fprintf(stderr, "Too many arguments\n");
        return;
    }

    args[argc] = NULL; /* Ensure the args array is properly null-terminated */
}

/**
 * _getenv - gets an environment variable without using getenv
 * @name: a NULL terminated string containing the name of the environment
 * variable
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
            token = strtok(NULL, "=");
            return token;
        }
        i++;
    }
    return NULL; /* Variable not found */
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
	extern char **environ;

    if (command == NULL)
    {
        return;
    }

    if (access(command, X_OK) == -1)
    {
        fprintf(stderr, "Command not found or not executable: %s\n", command);
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
        execve(command, args, environ);
        /* execve only returns if there is an error */
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }
}
