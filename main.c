#include "ssh_header.h"

/**
 * main - entry point
 * Return: 0 (success)
 */
int main(void)
{
	_setenv("PATH", "/bin:/usr/bin", 1);

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	else if (isatty(STDIN_FILENO) == 0)
	{
		non_interactive_mode();
	}
	else
	{
		fprintf(stderr, "Error: Unable to determine terminal status.\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
