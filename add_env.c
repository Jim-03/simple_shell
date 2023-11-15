#include "shell.h"

/**
 * add_env - sets a new environment or updates an existing one.
 * @info: the info_t structure
 * Return: 0 on success, 1 on failure
 */

int add_env(info_t *info)
{
	if (info->argc != 3)
	{
		print_error(info, "Incorrect number of arguments\n");
		return (1);
	}
	if (_add_environment(info, info->argv[1], info->argv[2]) == 0)
		return (0);
	return (1);
}

