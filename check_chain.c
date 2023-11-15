#include "shell.h"

/**
 * check_chain - Checks and modifies the command buffer based on command type
 * @info: structure
 * @buf: cmd buffer
 * @p: the iterator position
 * @i: current position
 * @len: length of the command buffer
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	switch (info->chain)
	{
		case CMD_AND:
			if (info->status)
			{
				buf[i] = 0;
				j = len;
			}
			break;
		case CMD_OR:
			if (!info->status)
			{
				buf[i] = 0;
				j = len;
			}
			break;
		default:
			break;
	}
	*p = j;
}

