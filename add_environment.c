#include "shell.h"

/**
 * add_environment - sets a new environment or updates an existing one
 * @info: the info_t structure
 * @var: the name
 * @value: the value to set
 * Return: 0 on success, 1 on failure
 */

int add_environment(info_t *info, char *var, char *value)
{
	char *buf, *p;
	list_t *node;

	if (!var || !value)
		return (1);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->change = 1;
			return (0);
		}
		node = node->next;
	}

	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->change = 1;
	return (0);
}

