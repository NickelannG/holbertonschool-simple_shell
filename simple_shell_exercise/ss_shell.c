#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char *command = NULL; /* Dynamically allocated buffer for user input */
    size_t len = 0; /* Length of the input buffer */
    char *args[] = { NULL }; /* No arguments for now */
    char *delimeter = " \n";
    char *token;
    pid_t pid;
    int status;

    while (1) {
        printf("$ ");
        fflush(stdout);

        /* Read a line of input from the user */
        if (getline(&command, &len, stdin) == -1)
	{
            /* Handle EOF (Ctrl+D) */
            printf("\n");
            free(command); /* Free dynamically allocated memory */
            break;
        }
	
	/* Tokenize the command string */
        int argc = 0;
        token = strtok(command, delimeter); /* Tokenize first */
        while (token != NULL && argc < MAX_COMMAND_LENGTH) 
	{
            args[argc++] = token; /* Store token in arguments array */
            token = strtok(NULL, delimeter); /* Get next token */
        }
        args[argc] = NULL; /* Set the last argument to NULL (required by execv) */


        /* Fork a child process */
        pid = fork();

        if (pid == -1) 
	{
            /* Fork failed */
            perror("fork");
            exit(EXIT_FAILURE);
        } 
	else if (pid == 0) 
	{
            /* Child process */
            if (execv(command, args) == -1) 
	    {
                perror("execv");
                exit(EXIT_FAILURE);
            }
        } 
	else 
	{
            /* Parent process */
            /* Wait for the child to terminate */
            if (wait(&status) == -1) 
	    {
                perror("wait");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}
