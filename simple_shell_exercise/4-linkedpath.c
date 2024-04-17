#include "ss_lib.h"

/**
 * description - builds a linked list of the PATH directories
 *
 * main - entry point 
 *
 * Return: always 0
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
int main()
{
	char *s;
	char *token;
	dlistint_t *head = NULL;

	s = _getenv("PATH");

	printf("contents of PATH: %s\n", s);

	token = strtok(s, ":");

	while (token != NULL)
	{
		printf("- %s\n", token);
		add_dnodeint_end(&head, token);
		token = strtok(NULL, ":");
	}
	printf("printing list... \n");
	print_dlistint(head);
	return (0);
}
