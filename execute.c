#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 *
 * Return: void.
 */

void execute_cmd(char **argv)
{
	char *command = NULL, *path = NULL;

	if (argv)
	{
		command = argv[0];
		path = get_path(command);
		if (path == NULL)
		{
			perror("command not found here");
		}
		else
		{
			if (execve(path, argv, NULL) == -1)
			{
				perror("Error executing");
			}
		}


	}

}
