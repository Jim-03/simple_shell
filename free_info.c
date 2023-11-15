#include "shell.h"

/**
 * free_info - frees info memory
 * @info: the info_t structure
 * @all: free all memory (1) or not (0)
 */

void free_info(info_t *info, int all)
{
	string_strings(info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->cmd_buf)
			string_strings(info->arg);
		free_list(&(info->env));
		free_list(&(info->history));
		free_list(&(info->alias));
		free_NULL((void **)info->cmd_buf);
		string_strings(info->environ);
		info->environ = NULL;
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(-1);
	}
}

