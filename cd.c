#include "shell.h"

/**
 * dir_changer - changes the directory
 * @info: the info_t structure.
 * Return: 0 on success, 1 on failure.
 */

int dir_changer(info_t *info)
{
	char buffer[1024];
	char *current = getcwd(buffer, 1024);
	char *new = NULL;
	int ch_dir;

	if (!current)
	{
		_puts("TODO: >>getcwd failure emsg here<<\n");
		return (1);
	}
	if (!info->argv[1])
		new = _getenv(info, "HOME=");
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		new = _getenv(info, "OLDPWD=");
		if (!new)
		{
			_puts(current_dir);
			_putchar('\n');
			return (1);
		}
	}
	else
		new_dir = info->argv[1];
	ch_dir = chdir(new_dir);
	if (ch_dir == -1)
	{
		print_error(info, "can't cd to ");
		fault_puts(info->argv[1]);
		fault_putchar('\n');
		return (1);
	}

	_setenv(info, "OLDPWD", current_dir);
	_setenv(info, "PWD", getcwd(buffer, 1024));
	return (0);
}

