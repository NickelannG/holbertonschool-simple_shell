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

void changeEnvVar(const char *name, const char *value) 
{
	unsigned int i;
	char *temp, *token, *final;
	int j;

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
			final = malloc(strlen(token) + strlen("=") +  strlen(myvalue) + 1);
			if (final == NULL)
			{
				free(temp);
				return;
			}

			strcpy(final, token);
			strcat(final, "=");
			strcat(final, myvalue);
			env[i] = malloc(strlen(final) + 1);
			env[i] =  final;
			j = i;
		}
		free(temp);
		i++;
	}


/**
 * addEnVar - a function that adds a new environment variable
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

     int num_vars = 0;
    while (environ[num_vars] != NULL)
        num_vars++;

    char **new_environ = malloc(sizeof(char *) * (num_vars + 2));
    if (new_environ == NULL)
        return;

    int i = 0;
    while (i < num_vars) {
        new_environ[i] = strdup(environ[i]);
        if (new_environ[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(new_environ[j]);
            free(new_environ);
            return;
        }
        i++;
    }

    new_environ[num_vars] = malloc(strlen(name) + strlen(value) + 2);
    if (new_environ[num_vars] == NULL) {
        for (int j = 0; j < num_vars; j++)
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
	if (name == NULL || value == NULL)
        	return -1; // Invalid input 
	int i = 0;
	while (environ[i] != NULL) 
	{
		char *var = strtok(environ[i], "=");
		if (strcmp(var, name) == 0)
		{
			// Variable exists
			if (overwrite)
			changeEnvVar(name, value);
			return 0;
		}
		i++;
	}
}

/**
 * Description: to test out the function
 * main - entry point 
 *
 * Return: always 0
 */

int main() 
{
	// Test the _setenv function
    _setenv("TEST_VAR", "initial_value", 0); // Add a new variable

    // Print the environment to verify changes
    int i = 0;
    while (environ[i] != NULL) {
        char *env_pair = environ[i];
        printf("%s\n", env_pair);
        i++;
    }

    return 0;
}
