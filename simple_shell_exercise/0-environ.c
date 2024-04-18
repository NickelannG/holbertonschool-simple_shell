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
	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
