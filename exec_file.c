#include "main.h"

/**
  * _exec_file - fuction to execute an executable in th current directory
  * @argv: argument vector containing the command
  * @buffer: stores the path to the command
  * @env: enviromental viriables
  */

void _exec_file(char *buffer, char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("exec_file fork error");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(buffer, argv, env) == -1)
		{
			perror("error executing file");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("waitpid failed");
			exit(EXIT_FAILURE);
		}
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			_puts("child_pid exited with error");
	}
}
