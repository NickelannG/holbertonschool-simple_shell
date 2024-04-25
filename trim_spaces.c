#include "ssh_header.h"
/**
 * trim_spaces - trims spaces
 * Return: -
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
