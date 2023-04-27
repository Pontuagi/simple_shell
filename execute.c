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
			_puts("./hsh: ");
			perror(command);
		}
		else
		{
			/* execute the path returned */
			fork_exec(argv, path, env);
		}
	}
}
