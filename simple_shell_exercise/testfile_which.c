#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(void) {
    char *pathvar = getenv("PATH");
    char *cmd = "/ls";
    struct stat st;

    if (pathvar == NULL) 
    {
        fprintf(stderr, "Error: PATH environment variable not found\n");
        return 1;
    }

    char *token = strtok(pathvar, ":");
    while (token != NULL) 
    {
        char *final = malloc(strlen(token) + strlen(cmd) + 1);
        if (final == NULL) 
	{
            fprintf(stderr, "Error: Memory allocation failed\n");
            return 1;
        }
        strcpy(final, token);
        strcat(final, cmd);

        printf("Status of %s: ", final);
        if (stat(final, &st) == 0) 
	{
            printf("FOUND\n");
        } else 
	{
            printf("NOT FOUND\n");
        }

        free(final);
        token = strtok(NULL, ":");
    }

    return 0;
}

