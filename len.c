#include "shell.h"

/**
 * word_length - calculates the length of a word
 * @str: the string
 * @d: a delimeter
 * @index: the index to start from
 * Return: the length
 */

int word_length(const char *str, char d, int *index)
{
	int len = 0;

	while (str[*inex + len] != d && str[*index + len] != '\0')
		len++;
	return (len);
}
