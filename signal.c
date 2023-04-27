#include "main.h"
/**
 * sigint_handler - handles the ctrl+c
 * @sig_num: the signal number
 */

void sigint_handler(__attribute__((unused))int sig_num)
{
	_puts("\n($) ");
}
