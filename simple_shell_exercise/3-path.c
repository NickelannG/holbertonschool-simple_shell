#include "ss_lib.h"

/**
 * description - prints each directory in the environment variable PATH,
 * one directory per line
 *
 * main - entry point
 * @name: a NULL terminated string containing the name of the environment
 * variable
 *
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

		if (strcmp(token, name) == 0) /* match */
		{
			token = strtok(NULL, "61");
			return (token);
		}
		token = strtok(NULL, "=");
		i++;
	}
	return (NULL); /* Variable not found */
}

/**
 * description - prints the environment 
 * main - entry point 
 *
 * Return: always 0
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	char *s;
	char *token;

	s = _getenv("PATH");

	printf("contents of PATH: %s\n", s);

	token = strtok(s, ":");

	while (token != NULL)
	{
		printf("- %s\n", token);
		token = strtok(NULL, ":");
	}
	token = strtok(NULL, ":");
	return (0);
}
