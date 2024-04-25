#include "ssh_header.h"
/**
 * execute_command - to execute new process
 * by replacing the previous
 * @command: the path of the command
 * @args: command arguments or flags
 */
int execute(char **args)
{
	int id = fork(), status;
	
	if (id == 0)
	{
	  if (execve(args[0], args, environ) == -1)
	      perror("Error");
	}

	else
	    {
	      wait(&status);
	      if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	    }
      
	return (status);
}
