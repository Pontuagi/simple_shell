#include "main.h"

/**
  * fork_exec - create a child procees to execute our command
  * @argv: the command to execute
  * @path: the path of the command
  * @env: the enviroment variables
  */

void fork_exec(char **argv, char *path, char **env)
{
	pid_t child;
	int status;

	if (argv != NULL)
	{
		child = fork();
		if (child == 0)
		{
		/* the child process executes the path and returns to parent */
			if (execve(path, argv, env) == -1)
				perror("error executing comand");
			exit(0);
		}
		else
		{
		/* the parent waits for the child to finish executing */
			wait(&status);
		}
	}
}
