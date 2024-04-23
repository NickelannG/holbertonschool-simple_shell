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

char *find_path(char *command) {
    char *pathvar = getenv("PATH");
    char *token, *path_with_cmd;
    struct stat st;

    if (pathvar == NULL) {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        return NULL;
    }

    token = strtok(pathvar, ":");
    while (token != NULL) {
        path_with_cmd = malloc(strlen(token) + strlen(command) + 2); /* +2 for '/' and '\0' */
        if (path_with_cmd == NULL) {
            fprintf(stderr, "Error: Memory allocation failed\n");
            return NULL;
        }
        sprintf(path_with_cmd, "%s/%s", token, command);

        if (stat(path_with_cmd, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR)) {
            return path_with_cmd;
        }

        free(path_with_cmd);
        token = strtok(NULL, ":");
    }

    return NULL; /* Command not found in any directory in PATH */
}


/**
 * execute_command - to execute new process
 * by replacing the previous
 * @command: the path of the command
 * @args: command arguments or flags
 */
void execute_command(char *command, char *args[]) 
{
	char *full_path;
	extern char **environ;
	pid_t pid;
	int status;

	if (command == NULL) {
        return;
    }

    full_path = find_path(command);
    if (full_path == NULL) {
        fprintf(stderr, "Error: Command '%s' not found\n", command);
        return;
    }
    
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (execve(full_path, args, environ) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else {
        if (wait(&status) == -1) {
            perror("wait");
            exit(EXIT_FAILURE);
        }
    }

    free(full_path);
}
