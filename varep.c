#include <stdlib.h>

/**
 * var_rep - changes the command arguments with their corresponding values
 * @info: the structure
 * Return: 0 indicating successful variable replacement.
 */

int var_rep(info_t *info)
{
	int i = 0;
	list_t *node;

	for (; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!_strcmp(info->argv[i], "$?"))
		{
			str_rep(&(info->argv[i]),
			_strdup(convert_number(info->status, 10, 0)));
		}
		else if (!_strcmp(info->argv[i], "$$"))
		{
			str_rep(&(info->argv[i]),
			_strdup(convert_number(getpid(), 10, 0)));
		}
		else
		{
			node = starts_with(info->env, &info->argv[i][1], '=');
			if (node)
			{
				str_rep(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			}
			else
			{
				str_rep(&info->argv[i], _strdup(""));
			}
		}
	}

	return (0);
}

