#include "ssh_header.h"

/**
 * execute - to execute new process
 * by replacing the previous
 * @args: command arguments or flags
 * Return: status
 */
int execute(char **args)
{
	int id = fork(), status;

	if (id == 0)
	{
		if (execve(args[0], args, environ) == -1)
			perror("Error");
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			status = WEXITSTATUS(status);
	}

	return (status);
}
