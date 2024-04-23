#include "ssh_header.h"

/**
 * main - entry point
 * Return: 0 (success)
 */
int main(void)
{
    if (isatty(STDIN_FILENO) == 1)
    {
        interactive_mode();
    }
    else
    {
        non_interactive_mode();
    }
    return 0;
}
