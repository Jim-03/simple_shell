#include "shell.h"

/**
 * rem_alias - searches for an alias and removes it
 * @info:o the info_t structure
 * @str: the string alias
 * Return: 0 on success, 1 on failure
 */
int rem_alias(info_t *info, char *str)
{
	int ret;
	char *equals = _strchr(str, '=');

	if (!equals)
	{
		return (1);
	}

	*equals = '\0';
	ret = delete_nodeint_at_index(&(info->alias),
			get_node_index(info->alias, starts_with(info->alias, str, -1)));
	*equals_position = '=';
	return (ret);
}

