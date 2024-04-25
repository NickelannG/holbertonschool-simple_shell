#include "ssh_header.h"

/**
 * main - entry point
 * Return: 0 (success)
 */
int main(void)
{
	char *command = NULL;
	char **args;
	size_t len = 0;
	ssize_t read = 0;
	int exit_status = 0;
	
	while (1)
	{
	        if(isatty(STDIN_FILENO) == 1)
		   printf("$ ");
		read = getline(&command, &len, stdin); 
		if(read == -1 || strcmp("exit\n", command) == 0)
		{
			free(command);
			break;
		}
		command[read - 1] = '\0';

		if(strcmp("env", command) == 0)
		  {
		    _printenv();
		    continue;
		  }

		if(trim_spaces(command) == 1)
		  {
		    exit_status = 0;
		    continue;
		  }

		args = parse(command, " ");
		args[0] = find_path(args[0]);

		if(args[0] != NULL)
		  exit_status = execute(args);		
		else
		  perror("Error");
		free(args);
	}
	return(exit_status);
}
