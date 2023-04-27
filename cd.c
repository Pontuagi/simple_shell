#include "main.h"

/**
  * _cd - change directory function.
  * @argc: argument count
  * @argv: variable with arguments.
  */

void _cd(int argc, char **argv)
{
	char buffer[1024];
	static char *last;
	size_t size = sizeof(buffer);

	if (argc == 1)
	{
		chdir(getenv("HOME"));
		setenv("PWD", getenv("HOME"), 1);
	}
	else if (argc == 2)
	{
		if (_strcmp(argv[1], "-") == 0)
		{
			if (last != NULL)
			{
				chdir(last);
				setenv("PWD", last, 1);
				free(last);
			}
		}
		else
		{
			if (chdir(argv[1]) == -1)
			{
				perror("invalid directory");
			}
			else
			{
				getcwd(buffer, size);
				setenv("PWD", buffer, 1);
			}
		}
	}
	else
	{
		printf("Too many arguments\n");
	}
	last = _strdup(getcwd(buffer, size));
}
