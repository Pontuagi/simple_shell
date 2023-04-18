#include "main.h"

/**
  * main - print ppid of a program.
  *
  * Return: 0 on success and -1 on fail
  */

int main(void)
{
	pid_t bn = getppid();

	printf("%u\n", bn);

	return (0);
}
