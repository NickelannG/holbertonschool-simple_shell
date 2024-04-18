#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **environ;

// Function to change the value of an existing environment variable
void changeEnvVar(char *var, char *value) {
    unsigned int i;
    char *temp, *token, *final = "";

    i = 0;
    while (environ[i] != NULL) {
        temp = malloc(strlen(environ[i]) + 1);
        strcpy(temp, environ[i]);

        token = strtok(temp, "=");
        if (strcmp(token, var) == 0) {
            final = malloc(strlen(token) + strlen("=") + strlen(value) + 1);
            strcpy(final, token);
            strcat(final, "=");
            strcat(final, value);
            environ[i] = malloc(strlen(final) + 1);
            strcpy(environ[i], final);
            free(temp);
            free(final);
            return; // Variable found and updated, no need to continue
        }
        i++;
        free(temp);
    }
}

// Function to add a new environment variable
void addEnvVar(char *var, char *value) {
    unsigned int i;

    i = 0;
    while (environ[i] != NULL) {
        i++;
    }

    char **new_environ = malloc(sizeof(char *) * (i + 2)); // +2 for new variable and NULL terminator
    for (int j = 0; j < i; j++) {
        new_environ[j] = malloc(strlen(environ[j]) + 1);
        strcpy(new_environ[j], environ[j]);
    }
    new_environ[i] = malloc(strlen(var) + strlen("=") + strlen(value) + 1);
    sprintf(new_environ[i], "%s=%s", var, value);
    new_environ[i + 1] = NULL; // NULL terminator
    environ = new_environ;
}

int main(int argc, char **argv, char **env) {
    unsigned int i;

    // Copying the environment variables
    i = 0;
    while (env[i] != NULL)
        i++;

    environ = malloc(sizeof(char *) * (i + 1)); // +1 for NULL terminator
    for (int j = 0; j < i; j++) {
        environ[j] = malloc(strlen(env[j]) + 1);
        strcpy(environ[j], env[j]);
    }
    environ[i] = NULL; // NULL terminator

    // Change the value of the environment variable MY_VAR or add it if it doesn't exist
    changeEnvVar("LS_COLORS", "MYVALUE");

    // If MY_VAR doesn't exist, add it
    if (environ[i - 1] != NULL && strncmp(environ[i - 1], "LS_COLORS=", strlen("LS_COLORS=")) != 0) {
        addEnvVar("LS_COLORS", "MYVALUE");
    }

    // Printing the environment
    i = 0;
    while (environ[i] != NULL) {
        printf("%s\n", environ[i]);
        i++;
    }

    // Freeing memory
    for (int j = 0; environ[j] != NULL; j++)
        free(environ[j]);
    free(environ);

    return 0;
}

