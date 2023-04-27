#include "main.h"

/**
  * fork_exec - create a child procees to execute our command
  * @argv: the command to execute
  * @path: the path of the command
  * @env: the enviroment variables
  */

<<<<<<< HEAD
void fork_exec(char **argv, char **env)
=======
void fork_exec(char **argv, char *path, char **env)
>>>>>>> de6ed2d3d784f440464e4c9bc31016a803475346
{
	pid_t child;
	int status;

	if (argv != NULL)
	{
		child = fork();
		if (child == 0)
		{
		/* the child process executes the path and returns to parent */
<<<<<<< HEAD
			if (execve(argv[0], argv, env) == -1)
=======
			if (execve(path, argv, env) == -1)
>>>>>>> de6ed2d3d784f440464e4c9bc31016a803475346
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
