#include "shell.h"

/**
 * string_strings - frees a string of strings
 * @str: the md array
 */

void string_strings(char *str)
{
	char **ptr = str;

	if (str == NULL)
		return;

	while (*str)
	{
		free(*str);
		str++;
	}

	free(ptr);
}
