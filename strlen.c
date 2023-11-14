#include "shell.h"

/**
 * _strlen - returns the length of the string
 * @str: the string to check length
 * Return: the length
 */

int _strlen(char *str)
{
	int length = 0;

	if (!str)
		return (0);

	while (*str++)
		length++;

	return (length);
}
