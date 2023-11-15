#include "shell.h"

/**
 * str_rep - Replaces a string with a new one in place.
 * @old: Pointer to the old string.
 * @new: Pointer to the new string.
 * Return: 1 if replacement is successful, 0 otherwise.
 */

int str_rep(char **old, char *new)
{
	if (!old || !new)
		return (0);
	free(*old);
	*old = new;

	return (1);
}
