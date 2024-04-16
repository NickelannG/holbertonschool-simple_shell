#include "ss_lib.h"

/**
 * Description - executes the command ls -l /tmp in 5 different child processes
 * where each child is created by the same parent process and waits for a
 * child process to exit before creating a new child
 *
 * main - entry point 
 *
 * Return: always 0 
 */

int main(void)
{
	pid_t pid;
	int i = 0;

	while (i < 5)
	{
		pid = fork();

		if (pid == -1)
		{
			return (-1);
		}
		if (pid == 0)
		{
			char *array[] = {"/bin/ls", "-l", "/tmp", NULL};
			printf("Child process %d started\n", i);
			execve(array[0], array, NULL);
			exit (1);
		 }
		else
		{
			wait(NULL);
		}
		i++;

	}
	return (0);
}
