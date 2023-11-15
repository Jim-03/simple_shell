#include "shell.h"

/**
 * path_finder - finds the full path of  given command in a string
 * @str: the string
 * @cmd: the command to find
 * Return: the path of the command if found, or NULL if not found
 */

char *path_finder(char *str, char *cmd)
{
	char current_char;
	int i = 0;
	int curr_pos = 0;
	char *path = NULL;

	if (!str || !cmd)
		return (NULL);
	if (_strlen(cmd) > 2 && starts_with(cmd, "./"))
		if (is_cmd(info, cmd))
			return (_strdup(cmd));
	while (1)
	{
		current_char = pathstr[i];
		if (!current_char || current_char == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			_strcat(path, *path ? "/" : "");
			_strcat(path, cmd);
			if (is_exec(info, path))
				return (path);
			free(path);
			if (!current_char)
				break;
		}
		curr_pos = i + 1;
		i++;
	}
	return (NULL);
}
