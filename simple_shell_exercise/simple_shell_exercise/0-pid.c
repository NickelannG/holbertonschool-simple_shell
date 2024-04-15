#include <stdio.h>
#include <unistd.h>

/**
 * Description - to test with parent process ID program 
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}
