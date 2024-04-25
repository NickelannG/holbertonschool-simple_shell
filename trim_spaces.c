#include "ssh_header.h"
/**
 * trim_spaces - trims spaces
 * @str: the string to be trimmed
 * Return: 1
 */

int trim_spaces(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}
