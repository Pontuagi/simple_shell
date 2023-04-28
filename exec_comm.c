#include "main.h"

/**
  * _exec_comm - function to execute command that is not an executable file
  * @buffer: pointer to where command and arguments are stored
  * @ac: variable to store argument count
  * @av: variable to store arguments in a vector
  * @env: enviromental variables.
  */

void _exec_comm(char *buffer, int ac, char **av, char **env)
{
	ac = _argc(buffer);
	av = tokenize(buffer, ac);
	if (av == NULL)
	{
		_puts("failed to allocate tokens to av\n");
	}
	keyword(ac, av, env);
}
