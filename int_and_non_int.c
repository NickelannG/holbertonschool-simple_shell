/**
 * interactive_mode - 
 * Return: -
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
        char *command_path = find_path(args[0]);
        if (command_path != NULL)
        {
            execute_command(command_path, args);
            free(command_path);
        }
        else
        {
            printf("Command not found: %s\n", args[0]);
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
    while ((read = getline(&command, &len, stdin)) != -1)
    {
        if (command[read - 1] == '\n')
            command[read - 1] = '\0';
        parse_command(command, args);
        char *command_path = find_path(args[0]);
        if (command_path != NULL)
        {
            execute_command(command_path, args);
            free(command_path);
        }
        else
        {
            printf("Command not found: %s\n", args[0]);
        }
        free(command);
        command = NULL;
    }
    free(command);
}

