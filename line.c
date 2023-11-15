#include "shell.h"

/**
 * _getline - reads the next line of input
 * @info: the structure
 * @ptr: the buffer
 * @length: size of the buffer
 * Return:  the number of bytes read or -1 on failure
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[1024];
	static size_t i, len;
	ssize_t r = 0;
	char *c, *p, *new_p;
	size_t s, k;

	if (i == len)
	{
		i = len = 0;
		r = read_buf(info, buf, &len);
		if (r == -1 || (r == 0 && len == 0))
			return (-1);
	}

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	p = *ptr;
	s = p && length ? *length : 0;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? (free(p), -1) : -1);
	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);
	s += k - i;
	i = k;
	if (length)
		*length = s;
	*ptr = new_p;
	return (s);
}

