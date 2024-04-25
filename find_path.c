#include "ssh_header.h"

/**
 * find_path - search file between the path
 * @command: cmd
 * Return: cmd path


char *find_path(char *command)
{
	char *path = _getenv("PATH"), *path_cpy;
	char **path_split;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	path_cpy = malloc(strlen(path) + 1);

	path_cpy = strcpy(path_cpy, path);
	path_split = parse(path_cpy, ":");

	while (path_split[i])
	{
		path_len = strlen(path_split[i]);

		if (path_split[i][path_len - 1] != '/')
			path_concat = strcat(path_split[i], "/");

		path_concat = strcat(path_split[i], command);

		if (stat(path_concat, &info) == 0)
			break;

		i++;
	}

	free(path_cpy);

	if (!path_split[i])
	{
		free(path_split);
		return (NULL);
	}

	free(path_split);
	return (path_concat);
} 
*/


/**
 * find_path - Searches for the executable path of a command in the PATH environment variable
 * @command: The command to search for
 * Return: The full path to the command if found, otherwise NULL
 */
char *find_path(char *command)
{
    char *path = _getenv("PATH");
    char *path_cpy, *path_concat = NULL;
    char **path_split;
    int i = 0;
    struct stat info;

    if (stat(command, &info) == 0)
        return command;

    path_cpy = strdup(path);
    if (path_cpy == NULL)
    {
        perror("Memory allocation error");
        return NULL;
    }

    path_split = parse(path_cpy, ":");
    free(path_cpy);

    while (path_split[i])
    {

        path_concat = malloc(strlen(path_split[i]) + strlen(command) + 2);

        if (path_concat == NULL)
        {
            perror("Memory allocation error");
            free(path_split);
            return NULL;
        }

        strcpy(path_concat, path_split[i]);
        strcat(path_concat, "/");
        strcat(path_concat, command);

        if (stat(path_concat, &info) == 0)
        {
            free(path_split);
            return path_concat;
        }

        free(path_concat);
        i++;
    }

    free(path_split);
    return NULL;
}
