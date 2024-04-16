#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 10

extern char **environ;

int main(void) {
    char *buffer = malloc(1024);
    size_t len = 1024;
    char *token;
    char **args;

    if (buffer == NULL) {
        perror("Error: failed to allocate memory");
        return 1;
    }

    while (1) {
        printf("%s$ ", getenv("USER")); // Display username in the prompt
        if (getline(&buffer, &len, stdin) == -1) {
            printf("Error: failed to read input\n");
            free(buffer);
            return 1;
        }

        if (strcmp(buffer, "\n") == 0) {
            continue; // Skip empty input
        }

        token = strtok(buffer, " ");
        int j = 0;
        args = malloc((MAX_ARGS + 1) * sizeof(char *)); // Dynamic allocation of args array
        while (token && j < MAX_ARGS) {
            args[j++] = token;
            token = strtok(NULL, " ");
        }
        args[j] = NULL;

        if (strcmp(args[0], "exit") == 0) {
            free(buffer);
            free(args);
            return 0; // Exit the shell
        }

        pid_t pid;
        pid = fork();

        if (pid == -1) {
            perror("Error: fork failed");
            free(buffer);
            free(args);
            return 1;
        } else if (pid == 0) {
            if (execve(args[0], args, environ) == -1) {
                perror("Error: execute failed");
                free(buffer);
                free(args);
                return 1;
            }
        } else {
            if (strcmp(args[j-1], "&") != 0) {
                wait(NULL);
            }
        }

        free(args); // Free memory allocated for args array
    }

    free(buffer);
    return 0;
}

