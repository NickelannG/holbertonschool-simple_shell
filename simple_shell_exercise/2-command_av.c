#include "ss_lib.h"
/**
 *
 */
int main (int argc, char *argv[])
{
(void)argc;
char *str = argv[1];
char *delim = " ";
char *token;
int i = 0;
while (str[i] != '\0')
{
token = strtok(str, delim);
printf("%s\n", token);
i++;
}
return (0);
}
