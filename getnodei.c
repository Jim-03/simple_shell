#include "shell.h"

/**
 * get_node_index - gets the index of a node
 * @h: pointer to list head
 * @n: pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *h, list_t *n)
{
	size_t i = 0;

	while (h)
	{
		if (h == n)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}
