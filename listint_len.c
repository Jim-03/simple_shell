#include "shell.h"

/**
 * listint_len - finds length of a list
 * @h: the head of the list
 * Return: the length
 */

size_t listint_len(const listint_t *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}

	return (i);
}
