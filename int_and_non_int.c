#include "ssh_header.h"

/**
 * interactive_mode - 
 * Return: -
 */

void interactive_mode(void)
{
	char *command = NULL;
	char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
	size_t len = 0;
	char *command_path;
	
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		
		if (getline(&command, &len, stdin) == -1)
		{
			printf("\n");
			break;
		}

		trim_spaces(command);

		if (command == NULL || *command == '\0')
			continue;

		if (strcmp(command, "exit") == 0)
		{
		  free(command);
		  exit(EXIT_SUCCESS);
		  /* break; */
		}

		parse_command(command, args);
		command_path = find_path(args[0]);
		
		if (command_path != NULL)
		{
			execute_command(command_path, args);
			free(command_path);
		}
		else
		{
			printf("Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
			/* break; */
		}
	}
	free(command);
}

/**
 * non_interactive_mode -
 * Return: -
 */

void non_interactive_mode(void)
{
	char *command = NULL;
	char *args[MAX_COMMAND_LENGTH + 1] = {NULL};
	size_t len = 0;
	ssize_t read;
	char *command_path;
	
	while ((read = getline(&command, &len, stdin)) != -1)
	{
		if (command[read - 1] == '\n')
			command[read - 1] = '\0';

		if (command == NULL || *command == '\0')
			continue;

		if (strcmp(command, "exit") == 0)
		{
		  free(command);
		  exit(EXIT_SUCCESS);
		  /* break; */
		}

		parse_command(command, args);
		command_path = find_path(args[0]);

		if (command_path != NULL)
		{
			execute_command(command_path, args);
			free(command_path);
		}
		else
		{
			printf("Command not found: %s\n", args[0]);
			exit(EXIT_FAILURE);
			/* break; */
		}
	}
	free(command);
}
