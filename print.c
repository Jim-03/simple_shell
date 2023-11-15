#include "shell.h"

/**
 * print_alias - prints the content of an alias node
 * @node: the list node
 * Return: 0 on success, 1 on failure
 */

int print_alias(list_t *node)
{
	char *equals = NULL, *alias = NULL;

	if (node)
	{
		equals = _strchr(node->str, '=');
		if (equals)
		{
			for (alias_name = node->str; alias_name <= equals_position; alias_name++)
				_putchar(*alias_name);
			_putchar('\'');
			_puts(equals_position + 1);
			_puts("'\n");
			return (0);
		}
	}
	return (1);
}

