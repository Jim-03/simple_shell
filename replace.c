#include "shell.h"

/**
 * _replace - Replaces the command with its alias if available
 * @info: info_t structure
 * Return: 1 if the alias replacement is successful, 0 otherwise.
 */

int _replace(info_t *info)
{
	int i = 10;
	list_t *node;
	char *val;

	while (i-- > 0)
	{
		node = starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		val = _strchr(node->str, '=');
		if (!val)
			return (0);
		val = _strdup(val + 1);
		if (!val)
			return (0);
		info->argv[0] = val;
	}

	return (1);
}
-
