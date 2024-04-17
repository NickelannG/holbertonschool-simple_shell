#include "ss_lib.h"

extern char **environ;
/**
 * description: prints the environment using the global variable environ
 *
 * main - entry point 
 *
 * Return: always 0
 */
int main ()
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
