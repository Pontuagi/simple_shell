#include "main.h"
/**
  */

int main(int ac, char **av)
{
	char buffer[1024];
	ssize_t nread;
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));
	if (ac ==2)
	{
	_puts("($) ");
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		if (errno == EACCES)
			exit(126);
		if (errno == ENOENT)
		{
		_puts("av[0]");
		_puts(": 0: Can't open ");
		_puts(av[1]);
		_putchar('\n');
		exit(127);
		}
		return (EXIT_FAILURE);
	}

