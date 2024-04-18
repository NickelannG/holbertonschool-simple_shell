#include "ss_lib.h"
/**
 *
 */
int _unsetenv(const char *name)
{
  extern char **environ;
  char **new_array;
  char *token, *temp;
  int og_index, new_index, unset_index;
  og_index = 0;
  
  while(environ[og_index] != NULL)
    {
      printf("%s\n", environ[og_index]);
      temp = malloc(strlen(environ[og_index] + 1));
      strcpy(temp, environ[og_index]);
      token = strtok(temp, "=");
      if (strcmp(token, name) == 0)
     {
       unset_index = og_index; 
     }
     og_index++;
     free(temp);
    }

      if(unset_index != -1)
      {
      new_array = malloc(sizeof(char *) * og_index);
      og_index = 0;
      new_index = 0;
      while(environ[og_index] != NULL)
	{
	  if (og_index != unset_index)
	    {
	      new_array[new_index] = malloc(strlen(environ[og_index]) + 1);
	      strcpy(new_array[new_index], environ[og_index]);
	      new_index++;
	    }
	  og_index++;
	}
      environ = new_array;
       }
      printf("Printing environ\n\n");
      og_index = 0;
      while(environ[og_index] != NULL)
	{
	  printf("%s\n", environ[og_index]);
	  free(new_array[new_index]);
	  og_index++;
	}
      free(new_array);
      printf("\n\ndone!\n");      
      return(0);
}

int main() {
  extern char **environ;
  // Example usage of _unsetenv function
    printf("Initial environment:\n");
    char **environ_copy = environ; // Make a copy of the original environment
    int i = 0;
    while (environ_copy[i] != NULL) {
        printf("%s\n", environ_copy[i]);
        i++;
    }

    // Unset environment variable "MY_VAR"
    const char *name_to_unset = "MY_VAR";
    _unsetenv(name_to_unset);

    // Print modified environment after unsetting the variable
    printf("\nEnvironment after unsetting %s:\n", name_to_unset);
    i = 0;
    while (environ_copy[i] != NULL) {
        printf("%s\n", environ_copy[i]);
        i++;
    }

    return 0;
}
