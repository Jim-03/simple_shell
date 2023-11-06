#include "shell.h"

/**
 * free_list - frees a linked list
 * @head: pointer to list to  be freed
 */

void free_list(list_t *head)
{
	list_t *del;

	while (head)
	{
		del = head->next;
		free(head->str);
		free(head);
		head = del;
	}
}

