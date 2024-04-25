#include "ssh_header.h"

/**
 * _getenv - gets an environment variable without using getenv
 * @name: a NULL terminated string containing the name of the environment
 * variable
 * Return: a pointer to the value string, or -1 if it failed
 */

char *_getenv(const char *name)
{
  int i = 0, j;
	int status;

	while (environ[i])
	{
		status = 1;

		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
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
