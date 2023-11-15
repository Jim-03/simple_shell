#include "shell.h"

/**
 * @brief Sets certain fields in the info_t structure based on command-line arguments.
 *
 * This function initializes or updates fields in the info_t structure
 * using command-line arguments. It converts the argument to an array of strings,
 * allocates memory if necessary, counts the number of arguments, and replaces
 * aliases and variables in the argument list.
 *
 * @param info Pointer to the info_t structure.
 * @param av   Command-line arguments array.
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

