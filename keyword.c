#include "main.h"

/**
  *
  */

void keyword(char **argv, char **env)
{
	char *command = argv[0];

	if (strcmp(command, "exit") == 0)
	{
		exit_func(argv);
	}
	else if (strcmp(command, "setenv") == 0)
	{
		_setenv(argv, env);
	}
	else if (strcmp(command, "env") == 0)
	{
		print_env(env);
	}
	else
	{
		execute_cmd(argv);
	}

}
