#include "main.h"

/**
 * _strcat - concanates two strings
 * @dest: string to be concanate
 * @src: concanator
 * Return: returns the concanated string
 */

char *_strcat(char *dest, char *src)
{
	char *new = dest;

	while (*new)
	{
		new++;
	}
	while (*src)
	{
		*new = *src;
		new++;
		src++;
	}
	*new = '\0';
	return (dest);
}
