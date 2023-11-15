#include "shell.h"

/**
 * find_env - finds the value of an environment
 * @info: info_t structure
 * @name: the name of the environment
 * Return: the value of the environment variable, or NULL if not found
 */

char *find_env(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_(node->str, name);
		if (ptr && *ptr)
			return (p);
		node = node->next;
	}
	return (NULL);
}

