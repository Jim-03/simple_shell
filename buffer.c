#include "shell.h"

/**
 * input_buf - buffers chains
 * @info: the structure
 * @buf: the buffer
 * @len: the length
 * Return: the bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			process_input(info, buf, len, r);
		}
		return (r);
	}

	return (0);
}

/**
 * process_input - Process the input buffer after reading a line
 * @info: the struct
 * @buf: the input buffer
 * @len: the length variable
 * @r: Bytes read
 */

void process_input(info_t *info, char **buf, size_t *len, ssize_t r)
{
	if (_strchr(*buf, ';'))
	{
		*len = r;
		info->cmd_buf = buf;
	}

	info->error_flag = 1;
	remove_comments(*buf);
	build_history_list(info, *buf, info->histcount++);
}

