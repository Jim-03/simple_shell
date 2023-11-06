#include "main.h"

/**
 * _strcmp - compares the strings
 * @s1: one of the strings
 * @s2: another string
 * Return: returns value based on results
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s2++;
		s1++;
	}
	return (*s1 - *s2);
}
