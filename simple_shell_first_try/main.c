#include "ssh_header.h"
#define MAX_COMMAND_LENGTH 100
/**
 * main - simple shell interative entry point
 * Return: Always 0 (Success)
*/
int main(void)
{
if (isatty((STDIN_FILENO) == 1))
{
interactive_mode();
}
else
{
non_interactive_mode();
}
return (0);
}

/**
#include <unistd.h> 
#include <string.h>
#include <stdio.h>  

int main(void) {
    if (isatty(STDIN_FILENO) == 1) {
        char input[100]; Assuming a maximum input length of 100 characters 

        while (1) {
            printf("$ ");
            fgets(input, sizeof(input), stdin);

            Check if the input is "exit" 
            if (strcmp(input, "exit\n") == 0) {
                printf("Exiting shell...\n");
                break; 	Exit the loop and the program
            }
        }
    } else {
        non_interactive_mode();
    }

    return 0;
}
*/


