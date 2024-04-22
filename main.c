#include "ssh_header.h"
#define MAX_COMMAND_LENGTH 100
/**
 * main - simple shell interative entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
if (isatty((STDIN_FILENO) == 1))
{
interactive_mode();
}
else
{
non_interactive_mode();
}
return (0);
}
