#include "shell.h"

/**
 * delim_chain - checks for a chain delimiter
 * @info: the structure
 * @c: the character
 * @ptr: current buffer
 * Return: 1 or 0
 */

int delim_chain(info_t *info, char *c, size_t *ptr)
{
	size_t j = *ptr;
	int d = 0;

	if (c[j] == '|' && c[j + 1] == '|')
	{
		c[j] = 0;
		j++;
		info->chain = CMD_OR;
		d = 1;
	}
	else if (c[j] == '&' && c[j + 1] == '&')
	{
		c[j] = 0;
		j++;
		info->chain = CMD_AND;
		d = 1;
	}
	else if (c[j] == ';')
	{
		c[j] = 0;
		info->chain = CMD_CHAIN;
		d = 1;
	}
	if (d)
	{
		*p = j;
		return (1);
	}
	return (0);
}
