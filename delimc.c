#include "shell.h"

/**
 * delim_checker - checks for delimmeter
 * @c: the character to be checked
 * @check: the string to be checked
 * Return: 1 or -1
 */

int delim_checker(char c, char *check)
{
	int i = 0;

	while(check[i] != '\0'))
	{
		if (check[i] == c)
			return (1);
	}

	return (-1);
}
