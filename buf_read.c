#include "shell.h"

/**
 * read_buf - reads data into a buffer
 * @info: the structure
 * @buf: buffer to store the read data.
 * @i: pointer to the size of the buffer.
 * Return: number of bytes read, or -1 on failure.
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, 1024);
	if (r >= 0)
		*i = r;
	return (r);
}

