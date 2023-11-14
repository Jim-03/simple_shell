#include "shell.h"

/**
 * str_to_word - seperates a string into words
 * @str: the string
 * @d: the delimiter
 * Return: pointer to string
 */

char **str_to_word(char *str, char d)
{
	int i, j, k, m, numwords = 0, word;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	numwords = count_words(str, d);
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != '\0')
			i++;
		word = word_length(str, d, &i);
		s[j] = allocate_copy_word(str, i - word, word);
		if (!s[j])
		{
			for (int k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
	}
	s[j] = NULL;
	return (s);
}
