#include "shell.h"

/**
 * add_env_list - populates the environment list
 * @info: the info_t structure
 * Return: 0 on success, 1 on failure
 */
int add_env_list(info_t *info)
{
	list_t *list = NULL;
	size_t i;

	if (!environ)
	{
		fault_puts(info, "'environ' is NULL\n");
		return (1);
	}
	for (i = 0; environ[i]; i++)
		add_node_end(&list, environ[i], 0);
	info->env = list;

	return (0);
}

