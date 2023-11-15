#include "shell.h"

/**
 * _history - prints history list
 * @info: the structure
 * Return: 0
 */

int _history(info_t *info)
{
	print_listint(info->hisotry);
	return (0);
}
