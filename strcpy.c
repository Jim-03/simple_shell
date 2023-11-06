#include "shell.h"

/**
 * *_strcpy - function to copy string
 * @dest: copied string
 * @src: string tobe copied
 * Return: returns the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, n;

	n = 0;
	while (*(src + n) != '\0')
	{
		n++;
	}
	for (i = 0 ; i < n ; i++)
	{
		dest[i] = src[i];
	}
	dest[n] = '\0';
	return (dest);
}
