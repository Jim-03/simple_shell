#include "shell.h"

/**
 * shell_inter - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 or 0
 */

int shell_inter(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
