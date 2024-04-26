#include "ssh_header.h"

/**
 * find_path - search file between the path
 * @command: cmd
 * Return: cmd path
*/

/**
char *find_path(char *command)
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

char *find_path(char *command)
{
    char *path, *path_cpy, **path_split, *path_concat = NULL;
    int i = 0, path_len = 0;
    struct stat info;

    path = _getenv("PATH");
    if (stat(command, &info) == 0)
        return command;

    path_cpy = malloc(strlen(path) + 1);
    strcpy(path_cpy, path);

    path_split = parse(path_cpy, ":");
    if (!path_split)
    {
        free(path_cpy);
        return NULL;
    }

    path_concat = malloc(path_len + 1);
    if (!path_concat)
    {
        free(path_cpy);
        free(path_split);
        return NULL;
    }

    for (i = 0; path_split[i] != NULL; i++)
    {
        strcpy(path_concat, path_split[i]);
        if (path_concat[strlen(path_concat) - 1] != '/')
            strcat(path_concat, "/");
        strcat(path_concat, command);

        if (stat(path_concat, &info) == 0)
        {
            free(path_cpy);
            free(path_split);
            return path_concat;
        }
    }

    free(path_cpy);
    free(path_split);
    free(path_concat);
    return NULL;
}

