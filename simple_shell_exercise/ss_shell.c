#include "shell_exercise.h"

/**
 *
 *
 *
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;
	char *args[10];
	int j;

	if (buffer == NULL)
	{
		perror("Error: failed to allocate memory");
		return (1);
	}

	while (1)
	{
		printf("$ ");
		if (getline(&buffer, &len, stdin) == -1)
		{
			perror("Error: failed to read input");
			free(buffer);
			return (1);
		}
		token = strtok(buffer, " ");
		j = 0;
		
		while (token)
		{
			args[j++] = token;
			token = strtok(NULL, " ");
		}
		args[j] = NULL;
		
		pid_t pid;
		pid = fork();
		
		if (pid == -1)
		{
			perror("Error: fork failed");
			free(buffer);
			return (1);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error: execute failed");
				exit (EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}

		int i = 0;
		while ( i < 10)
		{
			args[i++] = NULL;
		}
	}
	free (buffer);
	return (0);
}
