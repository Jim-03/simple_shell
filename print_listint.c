#include "shell.h"

/**
 * print_listint - prints all elements of list
 * @h: the head of the list
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t i;

	for (i = 0 ; h != NULL ; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

	return (i);
}
