#include "ssh_header.h"
/**
 * main - simple shell interative entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
char *command = NULL;
char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
size_t len = 0;
if (isatty((STDIN_FILENO) == 1))
{
while (1)
{
printf("$ ");
fflush(stdout);
if (getline(&command, &len, stdin) == -1)
{
printf("\n");
free(command);
break;
}
parse_command(command, args);
execute_command(args[0], args);
}
free(command);
}
else
{
non_interactive();
}
return (0);
}
