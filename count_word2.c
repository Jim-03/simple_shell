#include "shell.h"

/**
 * count_words_2 - counts words skipping delimiters
 * @str: the string
 * @s: the delimiters
 * Return: the number of words
 */

int count_words_2(char *str, char *s)
{
	int words = 0, i;

	for (i = 0; str[i] != '\0'; i++)
		if (!delim_checker(str[i], s) &&
			(delim_checker(str[i + 1], s) || !str[i + 1]))
			words++;
	return (words);
}
