#include "shell.h"

/**
 * _strdup - copies a string returning the pointer
 * @str: the string to be copied
 * Return: the result
 */

char *_strdup(char *str)
{
	char *temp;
	int i, size = 0;

	if (str == NULL)
		return (NULL);

	while (str[size])
		size++;

	temp = malloc((sizeof(char) * size) + 1);

	if (temp == NULL)
		return (NULL);

	for (i = 0 ; i < size ; i++)
		temp[i] = str[i];

	return (temp);
}
