#include "main.h"

/**
 * exit_func - to exit the shell
 * @num: exit argument.
 */

void exit_func(char **argv)
{
	char *num = argv[1];
	int no;

	if (num == NULL)
	{
		exit(0);
	}
	else
	{
		no = atoi(num);
		if (no > 255)
			exit(0);
		else
			exit(no);
	}
}
