#include "ss_lib.h"

/**
 * description: prints the address of env and environ
 *
 * main - entry point 
 *
 * Return: always 0
 */

extern char **environ;

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}

	while (*environ != NULL)
	{
		printf("%s\n", *environ);
		environ++;
	}

	printf("\n\n");

	printf("Adress of ENV: %p\n", (void *)&*env);
	printf("Address of ENVIRON: %p\n", (void *)&*environ);

	return (0);
}
