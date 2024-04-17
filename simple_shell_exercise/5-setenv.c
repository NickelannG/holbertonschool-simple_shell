#include "ss_lib.h"

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
	extern char **environ;
	size_t new_size;
	overwrite = 1;
	char *temp;
	int i = 0;

	value = malloc(sizeof(char)*strlen(name)); /* allocated memory for new environment variable */
	while (environ[i] != NULL)
	{
		token = strtok(environ[i], "=");

		if (strcmp(token, name) == 0 && overwrite == 1)
		{
			strcpy(token, value);
		}
		else
		{
			new_value = realloc(value, new_size * sizeof(char)*strlen(name));
			i++;
			free(new_value);
		}
		if (environ[i - 1])
		{
			strcat(environ, new_value);
		}
	}
	free(value);
	return (NULL);
}
