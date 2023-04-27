#include "main.h"

/**
  * keyword - find if the command is a built-in command
  * @argc: argument count.
  * @argv: argument vector with flags and arguments.
  * @env: variable containing environment variables
  */

void keyword(int argc, char **argv, char **env)

{
	char *command = argv[0];

	if (_strcmp(command, "exit") == 0)
	{
		exit_func(argc, argv);
	}
	else if (_strcmp(command, "env") == 0)
	{
		print_env(env);
	}
	else if (_strcmp(command, "cd") == 0)
	{
		_cd(argc, argv);
	}
	else
	{
		execute_cmd(argv, env);
	}
}
