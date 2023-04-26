#include "main.h"

/**
  * _setenv - function that sets environment variable
  * @argv: argument vector
  * @env: enviroment variables
  *
  * Return: return 0 on succes or -1 on error
  */

int _setenv(char **argv, char **env)
{
	char *name, *value;
	int ret;

	name = argv[1];
	if (name == NULL)
	{
		print_env(env);
		return (0);
	}
	value = argv[2];
	if (value == NULL)
	{
		ret = setenv(name, value, 0);
	}
	else
	{
		ret = setenv(name, value, 0);
	}

	return (ret);
}
