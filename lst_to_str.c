#include "shell.h"

/**
 * list_to_strings - creates an array of strings
 * @head: pointer to first element
 * Return: array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **arr;
	char *str;

	if (!head || !i)
		return (NULL);
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(arr[j]);
			free(arr);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		arr[i] = str;
	}
	arr[i] = NULL;
	return (arr);
}
