#include "shell.h"

/**
 * count_words - counts the words
 * @str: the string
 * @d: a delimiter
 * Return: the number of words
 */

int count_words(const char *str, char d)
{
	int i, words = 0;

	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
			(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			words++;
	return (i);
}
