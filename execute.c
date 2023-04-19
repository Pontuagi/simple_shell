#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 * @env: pointer to enviroment variables
 * @buff: pointer to our entered string.
 *
 * Return: void.
 */

void execute_cmd(char **argv, char *buff, char **env)
{
	char *command = NULL, *path = NULL;

	if (argv)
	{
		command = argv[0];
		if (strcmp(command, "exit") == 0)
		{
			exit_func(argv);
		}
		else if (strcmp(command, "env") == 0)
		{
			print_env(env);
		}
		else
		{
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

}
