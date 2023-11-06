#include "shell.h"

/**
 * add_node - adds node to beginning of list
 * @head: pointer to the list
 * @str: pointer to new string
 * Return: pointer to beginnig of list
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int i = 0;

	while (str[i])
		i++;

	new = malloc(sizeof(list_t));

	if (!new)
		return (NULL);

	new->str = strdup(str);
	new->len = i;
	new->next = (*head);
	 (*head) = new;

	return (*head);
}

