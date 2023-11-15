#include "shell.h"

/**
 * del_env - unsets environment
 * @info: the info_t structure
 * Return: 0 on success, 1 on failure
 */

int del_env(info_t *info)
{
	if (info->argc == 1)
	{
		print_error(info, "Too few arguments.\n");
		return (1);
	}

	for (int i = 1; i < info->argc; i++)
		delete_environment(info, info->argv[i]);
	return (0);
}
