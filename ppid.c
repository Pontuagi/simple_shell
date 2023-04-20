#include "main.h"

/**
  * get_ppid - print ppid of a program.
  *
  * Return: 0 on success and -1 on fail
  */

int get_ppid(void)
{
	pid_t bn = getppid();

	printf("%u\n", bn);

	return (0);
}
