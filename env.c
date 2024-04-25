#include "ssh_header.h"

/**
 * _getenv - gets an environment variable without using getenv
 * @name: a NULL terminated string containing the name of the environment
 * variable
 * Return: a pointer to the value string, or -1 if it failed
 */

char *_getenv(const char *name)
{
    extern char **environ;
    char *token;
    int i = 0;

    while (environ[i] != NULL)
    {
        token = strtok(environ[i], "=");

	if (token == NULL)
	{
		fprintf(stderr, "Invalid environment variable format: %s\n", environ[i]);
		continue;
	}

        if (strcmp(token, name) == 0) /* match */
        {
            token = strtok(NULL, "=");
            return token;
        }
        i++;
    }
    return NULL; /* Variable not found */
}


/**
* description: prints the environment using the global variable environ
* main - entry point
* Return: always 0
*/

void _printenv(void)
{
	char *env = environ[0];
	int i = 0;

	while (env != NULL)
	{
		printf("%s\n", env);
		i++;
		env = environ[i];
	}
}
