#include "shell.h"

ssize_t get_input(info_t *info)
{
	static char *buf = NULL;
	static size_t i = 0, len = 0;
	ssize_t r = 0;
	size_t j;
	char **buf_p = &(info->arg), *p;

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

