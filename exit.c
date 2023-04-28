#include "main.h"

/**
 * exit_func - to exit the shell
 * @argc: argument count
 * @argv: argument vector containing flags and arguments
 */

void exit_func(int argc, char **argv)
{
	int exit_status = 0;
	int no;

	/* if there is more than two argument to exit */
	if (argc > 2)
	{
		exit_status = 1;
	}
	/* check if there is ony 2 arguments in exit call */
	else if (argc == 2)
	{
		/* convert num to interger using atoi function */
		no = _atoi(argv[1]);
		if (no == 0 && _strcmp(argv[1], "0") != 0)
		{
			perror("Invalid exit status");
			exit_status = 1;
		}
		else if (no > 255 || no < 0)
		{
			exit_status = 1;
		}
		else
		{
			exit_status = no;
		}
	}
	exit(exit_status);
}
