#include "shell.h"

/**
 * add_alias - adds a new alias to the end of the alias list
 * @info: the info_t structure
 * @str: the string alias
 * Return: 0 on success, 1 on failure
 */

int add_alias(info_t *info, char *str)
{
	char *equals = _strchr(str, '=');

	if (!equals)
		return (1);
	if (!*++equals)
		return (unset_alias(info, str));
	unset_alias(info, str);
	if (add_node_end(&(info->alias), str, 0) == NULL)
		return (0);
	else
		return (1);
}

