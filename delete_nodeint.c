#include "shell.h"

/**
 * delete_nodeint_at_index - deletes element t a given index
 * @head: pointer to list
 * @index: position at the list
 * Return: 1 or -1
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *now = *head;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index - 1 && now != NULL; i++)
	{
		now = now->next;
	}

	if (now == NULL)
		return (-1);

	if (now->next == NULL)
		return (-1);

	temp = *head;
	temp = now->next;
	now->next = temp->next;
	free(temp);

	return (1);
}

