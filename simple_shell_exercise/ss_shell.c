#include "ss_lib.h"

/**
 *
 *
 *
 */

int main(void)
{
	char *buffer = malloc(1024);
	size_t len = 1024;
	char *token;
	char *args[10];
	int j = 0;
	char *envp[] = {"/bin/ls", NULL};

	while (1)
	{
	printf("$ ");
	getline(&buffer, &len, stdin);
	token = strtok(buffer, " ");
	exit (1);
	}
	while (token)
	{
	args[j++] = token;
	token = strtok(NULL, " ");
	}
	args[j] = NULL;
	
	int i = 0;
        pid_t pid;

	while (i < 1)
	{

                pid = fork();

                if (pid == -1)
                {
                        return (-1);
                }
                if (pid == 0)
                {
                        execve(args[0], args, envp);
                        exit (1);
                 }
                else
                {
                        wait(NULL);
                }
		i++;
        }     
	free (buffer);
	return (0);
}

