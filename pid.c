#include "main.h"

/**
  * get_pid - get pid of the current process
  *
  * Return: 0 on success and -1 on failure
  */

int get_pid(void)
{
	pid_t n = getpid();

	printf("%u\n", n);

	return (0);
}
