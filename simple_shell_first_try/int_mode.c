#include "ssh_header.h"

#define MAX_COMMAND_LENGTH 100

/**
 * interactive mode - interactive mode
 */
void interactive_mode(void)
{
char *command = NULL;
char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
size_t len = 0;
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
