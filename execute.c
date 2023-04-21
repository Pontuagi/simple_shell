#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 * @env: pointer to enviroment variables
 *
 * Return: void.
 */

void execute_cmd(char **argv, char **env)
{
	char *command = NULL, *path = NULL, *flag_1 = NULL;

	if (argv)
	{
		command = argv[0];
		flag_1 = argv[1];
		if (strcmp(command, "exit") == 0)
		{
			if (flag_1)
				exit_func(argv[1]);
			else
				exit_func(0);
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
