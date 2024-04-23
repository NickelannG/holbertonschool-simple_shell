#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

void parse_command(char *command, char *args[]);
char *_getenv(const char *name);
void execute_command(char *command, char *args[]);
void interactive_mode(void);
void non_interactive_mode(void);
char *find_path(char *command);

int main(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        interactive_mode();
    }
    else
    {
        non_interactive_mode();
    }
    return 0;
}

void parse_command(char *command, char *args[])
{
    if (command == NULL || *command == '\0' || *command == '\n') {
        fprintf(stderr, "Empty command\n");
        return;
    }

    char *delimeter = " \n";
    char *token;
    int argc = 0;

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

    args[argc] = NULL; // Ensure the args array is properly null-terminated
}

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

void execute_command(char *command, char *args[])
{
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

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve(command, args, environ);
        // execve only returns if there is an error
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

void interactive_mode(void)
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
        char *command_path = find_path(args[0]);
        if (command_path != NULL)
        {
            execute_command(command_path, args);
            free(command_path);
        }
        else
        {
            printf("Command not found: %s\n", args[0]);
        }
    }
    free(command);
}

void non_interactive_mode(void)
{
    char *command = NULL;
    char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&command, &len, stdin)) != -1)
    {
        if (command[read - 1] == '\n')
            command[read - 1] = '\0';
        parse_command(command, args);
        char *command_path = find_path(args[0]);
        if (command_path != NULL)
        {
            execute_command(command_path, args);
            free(command_path);
        }
        else
        {
            printf("Command not found: %s\n", args[0]);
        }
        free(command);
        command = NULL;
    }
    free(command);
}

char *find_path(char *command)
{
    // If the command contains a '/' character, assume it's already a full path
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)
        {
            return strdup(command); // Return a duplicate to avoid modifying the original string
        }
        else
        {
            fprintf(stderr, "Command not found or not executable: %s\n", command);
            return NULL;
        }
    }

    char *path = _getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found\n");
        return NULL;
    }

    char *delim = ":";
    char *token = strtok(path, delim);
    while (token != NULL)
    {
        char *full_path = malloc(strlen(token) + strlen(command) + 2); // +2 for '/' and '\0'
        if (full_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(full_path, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
            return full_path;
        }
        free(full_path);
        token = strtok(NULL, delim);
    }
    return NULL;
}

