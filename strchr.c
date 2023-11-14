#include "shell.h"

/**
 * _strchr - searches for a character
 * @s: string to be searched
 * @c: the character to be searched
 * Return: the pointer to the character or NULL
 */

char *_strchr(char *s, char c)
{
	char *temp = s;
	int i = 0;

	while (*temp != '\0')
	{
		if (temp[i] == c)
			return (&s[i]);
		temp++;
	s++;
	}

	return (NULL);
}
