#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 * @env: pointer to enviroment variables
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
			perror(command);
		}
		else
		{
			fork_exec(argv, path);
		}
		

	}

}
