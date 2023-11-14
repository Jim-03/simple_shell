#include "shell.h"

/**
 * fault_puts - prints string
 * @str: string to be printed
 */

void fault_puts(char *str)
{
	int i = 0;

	while (*str != '\0')
	{
		fault_putchar(str[i]);
		i++;
	}
}

/**
 * fault_putchar - writes the character c to stderr
 * @c: The character to print
 * Return: On success 1.
 */

int fault_putchar(char c)
{
	static int i;
	static char buffer[1024];

	if (c == -1 || i >= 1024)
	{
		write(2, buffer, i);
		i = 0;
	}
	if (c != FLUSH)
		buffer[i++] = c;
	return (1);
}

/**
 * _put_file - writes the character c to given fd
 * @c: The character to print
 * @f: The filedescriptor to write to
 * Return: On success 1.
 */
int _put_file(char c, int f)
{
	static int i;
	static char b[1024];

	if (c == -1 || i >= 1024)
	{
		write(f, b, i);
		i = 0;
	}
	if (c != -1)
		b[i++] = c;
	return (1);
}

/**
 *_put_in - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _put_in(char *str, int fd)
{
	int count = 0;

	if (!str)
		return (0);
	while (*str)
	{
		if (write(fd, str, 1) == -1)
			return (-1);
		str++;
		count++;
	}
	return (count);
}

/**
 * fault_atoi - converts string to integer
 * @s: the string
 * Return: the converted string
 */

int fault_atoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '-')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

