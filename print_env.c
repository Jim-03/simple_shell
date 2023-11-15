#include "shell.h"

/**
 * print_list_env - prints the environment
 * @info: the structure
 * Return: 0
 */

int print_list_env(info_t *info)
{
	print_listint(info->env);
	return (0);
}
