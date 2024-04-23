#include "ssh_header.h"

extern char **environ;

/**
 * changeEnvVar - a function that changes the value of an existing environment variable
 *
 * @var: a pointer to the variable name string that we want to change
 * @value: a pointer to the value string of the environment variable name that we want to change to
 * 
 * Return: no return
 */

void changeEnvVar(const char *name, const char *value) 
{
	unsigned int i;
	char *temp, *token, *final;

	if (name == NULL || value == NULL)
		return;
	
	i = 0;
	while (environ[i] != NULL) 
	{
		temp = strdup(environ[i]);
		if (temp == NULL) /* if memory allocation failed */
			return;
		
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0) 
		{
			final = malloc(strlen(token) + strlen("=") +  strlen(value) + 1);
			if (final == NULL)
			{
				free(temp);
				return;
			}
			strcpy(final, token);
			strcat(final, "=");
			strcat(final, value);
			environ[i] = final;
		}
		free(temp);
		i++;
	}
}

/**
 * addEnvVar - a function that adds a new environment variable
 *
 * @var: a pointer to the variable name string that we want to change
 * @value: a pointer to the value string of the environment variable name that we want to change to
 *
 * Return: no return
 */

void addEnvVar(const char *name, const char *value) 
{
    int num_vars;
    char **new_environ;
    int i, j;

    if (name == NULL || value == NULL)
        return;

    num_vars = 0;
    while (environ[num_vars] != NULL)
        num_vars++;

    new_environ = malloc(sizeof(char *) * (num_vars + 2));
    if (new_environ == NULL)
        return;

    i = 0;
    while (i < num_vars) {
        new_environ[i] = strdup(environ[i]);
        if (new_environ[i] == NULL) {
            for (j = 0; j < i; j++)
                free(new_environ[j]);
            free(new_environ);
            return;
        }
        i++;
    }

    new_environ[num_vars] = malloc(strlen(name) + strlen(value) + 2);
    if (new_environ[num_vars] == NULL) {
        for (j = 0; j < num_vars; j++)
            free(new_environ[j]);
        free(new_environ);
        return;
    }
    sprintf(new_environ[num_vars], "%s=%s", name, value);
    new_environ[num_vars + 1] = NULL;

    environ = new_environ;
}

/**
 * _setenv - changes or adds an environment variable (without using setenv)
 *
 * @name: a pointer to a null terminated string containing the name of the
 * environment variable to be set or updated
 *
 * @value: A pointer to a null-terminated string containing the new value 
 * to be assigned to the environment variable
 *
 * @overwrite: an int flag to override the change
 *
 * Return: 0 on success, or -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite) 
{
	int i;

	if (name == NULL || value == NULL)
	{
		fprintf(stderr, "Error: Invalid input\n");
		return -1;
	}
	i = 0;
	while (environ[i] != NULL)
	{
		char *var = strtok(environ[i], "=");
		if (strcmp(var, name) == 0)
		{
			if (overwrite)
			{
				changeEnvVar(name, value);
				return (0);
			}
			else
			{
				printf("Environment variable %s already exists. Use overwrite flag to update.\n", name);
				return (0);
			}
		}
		i++;
	}
	addEnvVar(name, value);
	return (0);
}
