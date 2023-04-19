#include "main.h"

/**
  * fork_exec - create a child procees to execute our command
  * @argv: the command to execute
  */

void fork_exec(char **argv)
{
	pid_t child;
	int status;

	if (argv != NULL)
	{
	child = fork();
	if (child == 0)
		execute_cmd(argv);
	else
		wait(&status);
	}
}
