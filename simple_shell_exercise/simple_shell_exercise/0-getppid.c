#include "shell_exercise.h"

/**
 * Description - prints the PID of the parent process
 *
 * main - entry point to the program
 *
 * Return: Always 0
 */
int main (void)
{
	pid_t ppid; /* Parent process ID */

	ppid = getppid();
	printf ("%u\n", ppid);
	return (0);
}
