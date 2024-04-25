#include "ssh_header.h"

/**
 * find_path - blabla
 * Return: char
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



/* char *find_path(char *command)
{
    char *path = _getenv("PATH");
    char *path_cpy;
    char *full_path = NULL;
    char *dir;
    struct stat info;

    if (strchr(command, '/') != NULL)
      {
    
        if (stat(command, &info) == 0)
	  {
	  return strdup(command);
        }
	else
	  {
	  return NULL;
        }
    }
    
    if (!path)
        return NULL;

    path_cpy = strdup(path);
    if (!path_cpy)
    {
        perror("Memory allocation error");
        return NULL;
    }

    dir = strtok(path_cpy, ":");
    
    while (dir != NULL)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (!full_path)
        {
            perror("Memory allocation error");
            free(path_cpy);
            return NULL;
        }

        sprintf(full_path, "%s/%s", dir, command);


        if (stat(full_path, &info) == 0)
        {
            free(path_cpy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_cpy);
    return NULL;
    } */


/* char *find_path(char *command)
{
	char *path = _getenv("PATH"), *path_cpy;
	char **path_split;
	char *path_ls = "ls";
	char *path_concat = NULL;
	int i = 0, path_len = 0;
	struct stat info;
	
	if (stat(command, &info) == 0)
		return (command);

	if(strcmp(path_ls, command) == 0)
	  _getenv("PATH");
	    	
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
	} */
