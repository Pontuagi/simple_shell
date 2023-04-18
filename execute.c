#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 *
 * Return: void.
 */

void execute_cmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error executing");
		}

	}

}
