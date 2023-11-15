#include "shell.h"

/**
 * add_info - sets fields in structure based on arguments
 * @info: the info_t structure
 * @av: ci arguments
 */
void add_info(info_t *info, char **av)
{
	int i;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
		_replace(info);
		var_rep(info);
	}
}

