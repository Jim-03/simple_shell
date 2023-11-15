#include <stdlib.h>

/**
 * @duplicate_characters - creates a substring from the characters in the string
 * @str: input string.
 * @start: the starting index
 * @stop: the stopping index
 * Return: the substring
 */
char *dup_chars(char *str, int start, int stop)
{
	char *buf;
	int k = 0, i;

	if (!str || start < 0 || stop < start)
		return (NULL);
	buf = (char *)malloc(stop - start + 1);
	if (!buf)
		return (NULL);

    	for (i = start; i < stop; i++)
	{
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	}
	buf[k] = '\0';
	return (buf);
}

