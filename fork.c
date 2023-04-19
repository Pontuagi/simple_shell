#include "main.h"

/**
  * fork_exec - create a child procees to execute our command
  * @argv: the command to execute
  * @path: the path of the command
  */

void fork_exec(char **argv, char *path)
{
	pid_t child;
	int status;

	if (argv != NULL)
	{
	child = fork();
	if (child == 0)
	{
		if (execve(path, argv, NULL) == -1)
			perror("error executing comand");
		exit(0);
	}
	else
		wait(&status);
	}
}
