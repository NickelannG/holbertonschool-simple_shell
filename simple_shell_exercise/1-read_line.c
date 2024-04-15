#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
/**
 * main - print "$", wait for user's input
 * on command line and print on next line
 * @ac: void
 * @argv: void
 * Return: 0 on always on success
 */
int main(int ac, char **argv)
{
  char *prompt = "$ ";
  char *lineptr;
  size_t n = 0;
(void)ac; (void)argv;
  printf("%s", prompt);
  getline(&lineptr, &n, stdin);
  printf("%s", lineptr);
  free(lineptr);
  return (0);
}
