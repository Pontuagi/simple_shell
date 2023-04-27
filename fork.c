#include "main.h"

/**
  * fork_exec - create a child procees to execute our command
  * @argv: the command to execute
  * @path: the path of the command
  */

void fork_exec(char **argv, char **env)
{
	pid_t child;
	int status;

	if (argv != NULL)
	{
		child = fork();
		if (child == 0)
		{
		/* the child process executes the path and returns to parent */
			if (execve(argv[0], argv, env) == -1)
				perror("error executing comand");
			exit(EXIT_FAILURE);
		}
		else if (child == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else
		{
		/* the parent waits for the child to finish executing */
			waitpid(child, &status, 0);
		}
	}
}
