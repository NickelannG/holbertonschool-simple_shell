#include "ss_lib.h"

/**
 * main - prototype
 * Return: 0 
 */
int main(void)
{
char *buffer = malloc(1024);
size_t len = 1024;
char *token;
while (1)
{
printf("$ ");
getline(&buffer, &len, stdin);
printf("%s", buffer);
token = strtok(buffer, " ");
while (token)
{
printf("%s\n", token);
token = strtok(NULL, " ");
}
}
return (0);
}
