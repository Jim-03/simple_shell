#include "shell.h"

/**
 * _memset - fills bytes to a memory
 * @p: pointer to memory
 * @n: number of bytes
 * @b: the bytes
 * Return: nothing
 */

void *_memset(void *p, size_t n, char b)
{
	unsigned char *ptr = (unsigned char *)p;
	size_t i;

	for (i = 0; i < n; i++)
	{
		ptr[i] = b;
	}
}
