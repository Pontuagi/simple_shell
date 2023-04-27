#include "main.h"

/**
 * execute_cmd - execute the argv[0] as a command
 * @argv: argument vector containing commands and flags
 * @env: the enviroment variables
 *
 * Return: void.
 */

void execute_cmd(char **argv, char **env)
{
	char *command = NULL, *path = NULL;
	if (argv)
	{
		command = argv[0];
		/* get the command path */
		path = get_path(command);
		if (path == NULL)
		{
			/* errno is set to ENOENT(no such file or directory) */
			errno = ENOENT;
			perror("./hsh");
		}
		else
		{
			/* execute the path returned */
<<<<<<< HEAD
			fork_exec(argv, env);
=======
			fork_exec(argv, path, env);
>>>>>>> de6ed2d3d784f440464e4c9bc31016a803475346
		}
	}
}
