#include "ssh_header.h"

/**
 * find_path - search file between the path
 * @command: cmd
 * Return: cmd path
*/

char *find_path(char *command)
{
    char *path = _getenv("PATH");
    char *path_copy = _strdup(path);
    char *path_concat = NULL;
    char **path_split = parse(path_copy, ":");
    int i = 0;
    struct stat info;

    if (stat(command, &info) == 0)
    {
        free(path_copy);
        return strdup(command);
    }

    while (path_split[i])
    {
        /* Allocate memory for path_concat */
        path_concat = malloc(strlen(path_split[i]) + strlen(command) + 2);
        if (path_concat == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        /* Construct the full path */
        strcpy(path_concat, path_split[i]);
        strcat(path_concat, "/");
        strcat(path_concat, command);

        /* Check if the constructed path exists */
        if (stat(path_concat, &info) == 0)
        {
            free(path_copy);
            free(path_split);
            return path_concat;
        }

        free(path_concat); /* Free path_concat if the path does not exist */
        i++;
    }
    free(path_copy);
    free(path_split);

    return NULL; /* Return NULL if the command is not found */
}

/* char *find_path(char *command)
{
	char *path, *path_cpy;
	char **path_split;
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;

	path = _getenv("PATH");

	if (stat(command, &info) == 0)
		return (command);

	path_cpy = malloc(_strlen(path) + 1);
	path_cpy = _strcpy(path_cpy, path);
	path_split = parse(path_cpy, ":");

	while (path_split[i])
	{
		path_len = _strlen(path_split[i]);

		if (path_split[i][path_len - 1] != '/')
			path_concat = _strcat(path_split[i], "/");

		path_concat = _strcat(path_split[i], command);

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



