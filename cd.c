#include "main.h"

/**
  * _cd - change directory function.
  * @argc: argument count
  * @argv: variable with arguments.
  */

void _cd(int argc, char **argv)
{
	char *home = getenv("HOME");
	char *directory = argv[1];
	char buffer[1024];
	char *previous = getenv("PWD");
	size_t size = sizeof(buffer);

	if (argc == 1)
	{
		chdir(home);
		setenv("PWD", home, 1);
	}
	else if (argc == 2)
	{
		if (_strcmp(directory, "-") == 0)
		{
			if (previous != NULL)
			{
				chdir(previous);
				setenv("PWD", previous, 1);
			}
		}

		else
		{
			if (chdir(directory) == -1)
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
}
