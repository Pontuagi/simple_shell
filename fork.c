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

	if (argv == NULL)
		return;
	child = fork();
	if (child == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		/* the child process executes the path and returns to parent */
		if (execve(path, argv, env) == -1)
		{
			perror("error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child, &status, 0) == -1)
		{
			perror("waitpid failed");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			_puts("child exited with error");
	}
}
