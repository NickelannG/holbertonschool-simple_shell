#include "ss_lib.h"

int main(int ac, char **av, char **env)
{
    unsigned int i = 0;
    extern char **environ;
    char **argv;
    char *myvar = "MY_VAR", *myvalue = "MYVALUE";

    // Count the number of environment variables
    while (environ[i] != NULL)
    {
        i++;
    }

    // Allocate memory for the new argv array
    argv = malloc(sizeof(char *) * (i + 1));

    // Copy existing environment variables to argv
    for (unsigned int j = 0; j < i; j++)
    {
        argv[j] = malloc(strlen(environ[j]) + 1);
        strcpy(argv[j], environ[j]);
    }

    // Add the new environment variable
    argv[i] = malloc(strlen(myvar) + strlen("=") + strlen(myvalue) + 1);
    strcpy(argv[i], myvar);
    strcat(argv[i], "=");
    strcat(argv[i], myvalue);

    // Print environment variables
    for (unsigned int j = 0; j <= i; j++)
    {
        printf("%s\n", argv[j]);
    }

    // Free allocated memory
    for (unsigned int j = 0; j <= i; j++)
    {
        free(argv[j]);
    }
    free(argv);

    return 0;
}
