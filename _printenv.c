#include "ssh_header.h"
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
	return;
}
