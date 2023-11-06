#include "shell.h"

/**
 * starts_with - finds node whose string starts with prefix
 * @head: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

list_t *starts_with(list_t *head, char *prefix, char c)
{
	char *ptr = NULL;

	while (head)
	{
		ptr = start_(head->str, prefix);
		if (ptr && ((c == -1) || (*ptr == c)))
			return (head);
		head = head->next;
	}
	return (NULL);
}
