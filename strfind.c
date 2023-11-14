#include "shell.h"

/**
 * start_ - compares strings character by character
 * @str: the string
 * @beg: the other string
 * Return: pointer to character
 */

char *start_(char *str, char *beg)
{
	for (; *beg && *beg == *str; *beg++, str++)
		;
	return ((char *)str);
}
