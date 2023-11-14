#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: string to copy to
 * @src: string to be copied
 * @n: maximum number of characters to copy
 * Return: returns a pointer to the copied string
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *temp = dest;

	while (*src && n > 0)
	{
		*temp = *src;
		temp++;
		src++;
		n--;
	}

	while (n > 0)
	{
		*temp = '\0';
		temp++;
		n--;
	}

	return (dest);
}

