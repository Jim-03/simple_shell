#include "shell.h"

/**
 * get_input - gets line input
 * @info: the struct
 * Return: bytes read
 */

ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, len;
	ssize_t r = 0;
	size_t j;
	char **buf_p = &(info->arg), *p;

	i = 0;
	len = 0;
	_putchar(-1);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;
		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (_chain(info, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->chain = 0;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

