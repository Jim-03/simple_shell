#include "shell.h"

/**
 * shell_main - main loop for shell
 * @info: the info_t structure
 * @av: cli arguments
 * Return: status of the last action
 */

int shell_main(info_t *info, char **av)
{
	ssize_t in = 0;
	int built = 0;

	while (in != -1 && built != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		fault_putchar(-1);
		in = get_input(info);
		if (in != -1)
		{
			set_info(info, av);
			built = find_builtin(info);
			if (built == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}

	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (built == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}

	return (built);
}
