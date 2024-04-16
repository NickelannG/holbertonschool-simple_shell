#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 10

int main(void) {
    char *buffer = malloc(MAX_COMMAND_LENGTH);
    size_t len = MAX_COMMAND_LENGTH;
    char *token;
    char *args[MAX_ARGS];
    char *envp[] = { "PATH=/usr/local/bin:/usr/bin:/bin", NULL };

    while (1) {
        printf("$ ");
        if (getline(&buffer, &len, stdin) == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        // Remove newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        int j = 0;
        token = strtok(buffer, " ");
        while (token != NULL && j < MAX_ARGS - 1) {
            args[j++] = token;
            token = strtok(NULL, " ");
        }
        args[j] = NULL;

        // Fork and execute each command
        pid_t pid;
        int i = 0;
        while (i < 1 && args[0] != NULL) {
            pid = fork();
            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            } else if (pid == 0) {
                // Child process
                execve(args[0], args, envp);
                // If execve returns, it must have failed
                perror("execve");
                exit(EXIT_FAILURE);
            } else {
                // Parent process
                wait(NULL);
            }
            i++;
        }
    }

    free(buffer); // Free allocated memory
    return 0;
}

