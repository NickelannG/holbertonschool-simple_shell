#include "shell_exercise.h"


/**
 * description: prints the environment using the global variable environ
 *
 * main - entry point 
 *
 * Return: always 0
 */
int main ()
{
	extern char **environ;

	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
