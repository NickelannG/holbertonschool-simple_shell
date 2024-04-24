#include "ssh_header.h"

/**
 * find_path - blabla
 * Return: char
 */

char *find_path(char *command)
{
	char *path;
	char *delim;
    	char *token;
	char *full_path;

    /* If the command contains a '/' character, assume it's already a full path */
    if (strchr(command, '/') != NULL)
    {
        if (access(command, X_OK) == 0)
        {
            return strdup(command); /* Return a duplicate to avoid modifying the original string */
        }
        else
        {
            fprintf(stderr, "Command not found or not executable: %s\n", command);
            exit(0);
        }
    }

    path = _getenv("PATH");
    if (path == NULL)
    {
        fprintf(stderr, "PATH environment variable not found\n");
        return NULL;
    }

    delim = ":";
    token = strtok(path, delim);
    while (token != NULL)
    {
        full_path = malloc(strlen(token) + strlen(command) + 2); /* +2 for '/' and '\0' */
        if (full_path == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        sprintf(full_path, "%s/%s", token, command);
        if (access(full_path, X_OK) == 0)
        {
		return full_path;
        }
        free(full_path);
        token = strtok(NULL, delim);
    }
    return NULL;
}
