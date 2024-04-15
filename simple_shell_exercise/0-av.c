#include "shell_exercise.h"

/**
 * description - prints all the arguments without using ac
 * main - entry point 
 *
 * @ac: number of command line arguments (unused variable)
 * @av: a NULL terminated array of strings containing the
 * command line arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	(void)ac; /* Cast ac to void to indicate intentially unused */
	int i = 0; /* iterate through array */

	while (av[i] != NULL)
	{
		printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
