#include "shell_exercise.h"

/**
 * description - splits a string and returns an array of
 * each word of the string 
 *
 * main - entry point 
 *
 * Return: an array of each word(token) of the string, or -1 if strtok fails
 */
int main ()
{
	char *str = NULL; /* string to be tokenized */
	char *delimeter; /* string containing delimeters */
	char *token; /* parsed string */
	size_t n = 0; /* size of str for getline */
	ssize_t read;

	/* Just in this case our tokens are words, so the delimeter would just be sapces */
	delimeter = " ";

	printf("$ "); /* prompt */
	read = getline(&str, &n, stdin); /* Get the string */

	if (read != -1)
	{
		if (!feof(stdin))
		{
			token = strtok(str, delimeter); /* tokenize first */
			while (token != NULL)
			{
				printf("%s\n", token);
				token = strtok(NULL, delimeter);
			}
		}
		else 
			printf("\n"); /* If at EOF */
	}
	else /* if getline failed */
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0); /* int */
}
