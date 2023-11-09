#include "shell.h"

/**
 * re_alloc - reallocates memory
 * @ptr: the pointer to the memory
 * @old: the old memory size
 * @new: the new memory size
 */

void *re_alloc(void *ptr, size_t old, size_t newer)
{
	char *p = malloc(newer);
	size_t c;

	if (ptr == NULL)
	{
		return (malloc(newer));
	}

	if (!newer)
	{
		free(ptr);
		return (NULL);
	}

	if (newer == old)
		return (ptr);

	if (!p)
		return (NULL);

	c = (old < newer) ? old : newer;

	while (c--)
	{
		p[c] = ((char *)ptr)[c];
	}

	free(ptr);
	return (p);
}
