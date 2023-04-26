#include "main.h"

/**
 * exit_func - to exit the shell
 * @argc: argument count
 * @argv: argument vector containing flags and arguments
 */

void exit_func(int argc, char **argv)
{
	char *num = argv[1];
	int no;

	/* if there is only one argument to exit */
	if (argc == 1)
	{
		exit(0);
	}
	/* check if there is ony 2 arguments in exit call */
	else if (argc == 2)
	{
		/* convert num to interger using atoi function */
		no = _atoi(num);
		if (no > 255)
			exit(0);
		else
			exit(no);
	}
	else
	{
		errno = EINVAL;
		perror("Too many arguments to exit");
	}
}
