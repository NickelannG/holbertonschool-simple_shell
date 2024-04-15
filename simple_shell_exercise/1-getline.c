#include "shell_exercise.h"

/**
 * description - prints a '$' signs as a prompt for the user to enter a command
 * then prints this command on the next line 
 *
 * main - entry point
 *
 * Return: the number of characters read by getline or -1 on failure
 */
int main()
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &n, stdin);
	if (read != -1) /* getline didn't fail */
	{
		/* Check if "end-of-file" as stated in man 3 getline */
		if (feof(stdin))
			/* Create separation after last input for readability */
			printf("\n");
		else
			printf("%s", line);
	}
	else /* If getline failed */
	{
		free(line); /* Free dynamically allocated buffer before exit */
		return (-1);
	}
	/* Free dynamically allocated buffer */
	free(line);
	return (0);
}
