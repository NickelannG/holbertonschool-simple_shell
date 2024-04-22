#include "ssh_header.h"
#define MAX_COMMAND_LENGTH 100
/**
 * non_interactive_mode - non-interactive mode
 * @input_file: file name entered
 */
void non_interactive_mode(void)
{
char *command = NULL;
char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
size_t len = 0;
ssize_t read;
while ((read = getline(&command, &len, stdin)) != -1)
{
if (command[read - 1] == '\n')
command[read - 1] = '\0';
parse_command(command, args);
execute_command(args[0], args);
free(command);
command = NULL;
}
free(command);
}
