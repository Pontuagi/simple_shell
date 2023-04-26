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
	char *previous;
	static char *last = NULL;
	size_t size = sizeof(buffer);

	getcwd(buffer, size);
	previous = _strdup(buffer);
	if (argc == 1)
	{
		chdir(home);
		setenv("PWD", home, 1);
	}
	else if (argc == 2)
	{
		if (_strcmp(directory, "-") == 0)
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
	last = previous;
}
