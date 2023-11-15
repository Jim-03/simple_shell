#include "shell.h"

/**
 * is_exec - checks if the given path corresponds to a regular file
 * @path: path to check.
 * Return: 1 if the path is a regular file, 0 otherwise.
 */

int is_exec(char *path)
{
	struct stat st;

	if (!path)
		return (0);
	if (stat(path, &st) != 0)
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}

	return (0);
}

