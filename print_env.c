#include "main.h"

/**
 * print_env - to print the enviroment variables
 * @env: the pointer to the eviroment variables
 *
 * Return: always return 0 on success
 */

void print_env(char **env)
{
	unsigned int i = 0;
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("print_env: fork");
		return;
	}
	if (child_pid == 0)
	{
		while (env[i])
		{
			_puts(env[i++]);
		}
		_putchar('\n');
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

}
