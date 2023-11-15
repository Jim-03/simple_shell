#include "shell.h"

/**
 * _chain - Checks the command chain type and modifies the buffer accordingly
 * @info: the structure
 * @c: the character
 * @ptr: current position
 * @i: first position
 * @length: the length of the buffer
 */

void _chain(info_t *info, char *c, size_t *ptr, size_t i, size_t length)
{
	size_t j = *ptr;

	if (info->chain == CMD_AND)
	{
		if (info->status)
		{
			c[i] = 0;
			j = length;
		}
	}
	if (info->chain == CMD_OR)
	{
		if (!info->status)
		{
			c[i] = 0;
			j = lenth;
		}
	}
	*p = j;
}
