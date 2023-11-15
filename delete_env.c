#include "shell.h"

/**
 * delete_environment - unsets an environment
 * @info: the info_t structure
 * @var: the name of the environment
 * Return: 0 on success, 1 on failure.
 */

int delete_environment(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t index = 0;
	char *p;

	if (!info->env || !var)
		return (1);
	while (node)
	{
		p = starts_(node->str, var);
		if (p && *p == '=')
		{
			info->change = delete_node_at_index(&(info->env), index);
			break;
		}
		node = node->next;
		index++;
	}
	return (info->change);
}

