#include "shell.h"

/**
 * str_to_wrd - splits strings into words
 * @str: the string
 * @s: delimiter
 * Return: pointer to array of strings
 */

char **str_to_wrd(char *str, char *s)
{
	char **c;
	int x, m, i, words = 0, current, j = 0;
	int previous = 1, k = 0, current1, current2;

	if (!str || str[0] == 0)
		return (NULL);
	if (s == NULL)
		s = " ";
	words = count_words_2(str, s);
	if (words == 0)
		return (NULL);
	c = malloc((words + 1) * sizeof(char *));
	if (c == NULL)
		return (NULL);
	for (i = 0; j < words ; j++)
	{
		current1 = delim_checker(str[i], s);
		while (current1)
			i++;
		current2 = delim_checker(str[i + k], s);
		while (!current2 && str[i + k])
			k++;
		c[j] = malloc((k + 1) * sizeof(char));
		if (c[j] == NULL)
		{
			for (m = 0; m < j; m++)
				free(c[m]);
			free(c);
			return (NULL);
		}
		for (x = 0; x < k; x++)
			c[j][x] = str[i++];
		c[j][x] = 0;
	}
	c[j] = NULL;
	return (c);
}
