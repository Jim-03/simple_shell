#include "shell.h"

/**
 * _alias - alias-related functionality in the shell program
 * @info: the info_t structure
 * Return: 0
 */

int _alias(info_t *info)
{
	list_t *node = info->alias;
	int i;

	if (info->argc == 1)
	{
		while (node)
		{
			print_alias(node);
			node = node->next
		}
	}
	else
	{
		for (i = 1; info->argv[i]; i++)
		{
			equals = _strchr(info->argv[i], '=');
			if (equals)
				add_alias(info, info->argv[i]);
			else
				print_alias(starts_with(info->alias, info->argv[i], '=');
		}
	}

	return (0);
}
