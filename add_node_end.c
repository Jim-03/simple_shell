#include "shell.h"

/**
 * add_node_end - adds a node to the end of list
 * @head: pointer to beginning of list
 * @str: the string to add at the end
 * Return: address of new elment or null
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end, *temp = *head;
	unsigned int i;

	while (str[i])
	{
		i++;
	}

	end = malloc(sizeof(list_t));

	if (!end)
	{
		return (NULL);
	}

	end->str = strdup(str);
	end->len = i;
	end->next = NULL;

	if (*head == NULL)
	{
		*head = end;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = end;
	}

	return (end);
}
