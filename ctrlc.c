#include "shell.h"

/**
 * sigintHandler - Handles(Ctrl+C)
 * @sig_num: Signal number (unused).
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
	_puts("\n$ ");
	_putchar(BUF_FLUSH);
}

