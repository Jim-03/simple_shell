#include "shell.h"

/**
 * allocate_copy_word - allocates memory for a word and copies it
 * @str: the string
 * @start: the start of the word
 * @length: the length of the word
 * Return: the allocated pointer
 */

char *allocate_copy_word(const char *str, int start, int length)
{
	char *wrd = malloc((length + 1) * sizeof(char));

	if (!word)
		return (NULL);
	for (int i = 0; i < length; i++)
		wrd[i] = str[start + i];
	wrd[length] = '\0';
	return (wrd);
}

