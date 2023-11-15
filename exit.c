#include "shell.h"

/**
 * _exiter - handles the exit functionality in the shell program
 * @info: the info_t structure
 * Return: -2 if the program should exit, 1 if there's an error.
 */

int _exiter(info_t *info)
{
	int val;

	if (info->argv[1])
	{
		val = fault_atoi(info->argv[1]);
		if (val == -1)
		{
			exit_error(info);
			return (1);
		}
		info->err_num = val;
	}
	else
	{
		info->err_num = -1;
	}
	return (-2);
}

/**
 * exit_error - handles the printing of an exit error message
 * @info: the info_t structure.
 */

void exit_error(info_t *info)
{
	info->status = 2;
	print_error(info, "Illegal number: ");
	fault_puts(info->argv[1]);
	fault_putchar('\n');
}
