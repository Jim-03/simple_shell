#include "shell.h"

/**
 * is_alpha - checks if character is alphabetic
 * @c: character to be checked
 * Return: 1 pass, 0 none
 */

int is_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);

	else
		return (0);
}
