#include "shell_exercise.h"

extern char **environ;

/**
 * changeEnvVar - a function that changes the value of an existing environment variable
 *
 * @var: a pointer to the variable name string that we want to change
 * @value: a pointer to the value string of the environment variable name that we want to change to
 * 
 * Return: no return
 */

void changeEnvVar(char *var, char *value)
{
	unsigned int i;
	int j = -1;
	extern char** environ;
	char **argv;
	char *myvar = "LS_COLORS", *myvalue = "MYVALUE", *token, *temp, *final = "";

	i = 0;
	while (environ[i] != NULL)
	{
		/* Aloocate memory for a copy of the current environment variable */
		temp = malloc(strlen(environ[i]) + 1);
		/* Copy the current environment variable */
		strcpy(temp, environ[i]);

		token = strtok(temp, "="); /* tokenize the variable to get its name */
		if (strcmp(token, myvar) == 0)
		{
			final = malloc(strlen(token) + strlen("=") +  strlen(myvalue) + 1);
			strcpy(final, token);
			strcat(final, "=");
			strcat(final, myvalue);
			environ[i] = malloc(strlen(final) + 1);
			environ[i] =  final;
			j = i;
		}
		i++;
		free(temp);
	}
}

/**
 * addEnVar - a function that adds a new environment variable
 *
 * @var: a pointer to the variable name string that we want to change
 * @value: a pointer to the value string of the environment variable name that we want to change to
 *
 * Return: no return
 */
void addEnvVar(char *var, char *value)
{
	unsigned int i = 0;
    extern char **environ;
    char **argv;
    char *myvar = "MY_VAR", *myvalue = "MYVALUE";

    // Count the number of environment variables
    while (environ[i] != NULL)
    {
        i++;
    }

    // Allocate memory for the new argv array
    argv = malloc(sizeof(char *) * (i + 1));

    // Copy existing environment variables to argv
    for (unsigned int j = 0; j < i; j++)
    {
        argv[j] = malloc(strlen(environ[j]) + 1);
        strcpy(argv[j], environ[j]);
    }

    // Add the new environment variable
    argv[i] = malloc(strlen(myvar) + strlen("=") + strlen(myvalue) + 1);
    strcpy(argv[i], myvar);
    strcat(argv[i], "=");
    strcat(argv[i], myvalue);

    // Print environment variables
    for (unsigned int j = 0; j <= i; j++)
    {
        printf("%s\n", argv[j]);
    }

    // Free allocated memory
    for (unsigned int j = 0; j <= i; j++)
    {
        free(argv[j]);
    }
    free(argv);

    return 0;
}
