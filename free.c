#include "shell.h"

/**
 * clear - sets info_t to default
 * @info: the info_t structure
 */

void clear(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}
