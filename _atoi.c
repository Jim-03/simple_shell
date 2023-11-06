#include "shell.h"

/**
 * str_ int - converts a string to integer
 * @str: the string to be converted
 * Return: the converted string
 */

int str_int(char* str)
{
	int i, x, convert = 0, state;

	if (str[0] == '-')
	{
		state = -1;
		i = 1;
	}
	else if (str[0] == '+')
	{
		i = 1;
	}

	for (; *str ; i++)
	{
		x = str[i] - '0';
		convert *= 10 + x;
	}

	convert *= state;

	return (convert);
}
