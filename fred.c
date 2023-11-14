#include "shell.h"

/**
 * free_NULL - used to free a pointer
 * @ptr: the pointer
 * Return: 1 or 0
 */

int free_NULL(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}

	return (0);
}
