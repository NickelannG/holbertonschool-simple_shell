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
int main(int ac, char **av, char **env)
{
	unsigned int i;
	int j = -1;
	extern char** environ;
	char **argv;
	char *myvar = "LS_COLORS", *myvalue = "MYVALUE", *token, *temp, *final = "";

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", environ[i]);

		temp = malloc(strlen(env[i]) + 1);
		strcpy(temp, env[i]);

		token = strtok(temp, "=");
		if (strcmp(token, myvar) == 0)
		{
			final = malloc(strlen(token) + strlen("=") +  strlen(myvalue) + 1);
			strcpy(final, token);
			strcat(final, "=");
			strcat(final, myvalue);
			env[i] = malloc(strlen(final) + 1);
			env[i] =  final;
			j = i;
		}
		i++;
		free(temp);
	}
	printf("Printing Environ\n\n");
	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	printf("\n\nall done!\n");
	return (0);
}
