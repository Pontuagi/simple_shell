#include "main.h"

/**
 * print_env - to print the enviroment variables
 * @env: the pointer to the eviroment variables
 *
 * Return: always return 0 on success
 */
void print_env(char **env)
{
	unsigned int i = 0, j;
	int status;
	pid_t child;

	child = fork();
	if (child == 0)
	{
		while (env[i] != NULL)
		{
			for (j = 0; env[i][j] != '\0'; j++)
				_putchar(env[i][j]);
			_putchar('\n');
			i++;
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}

}
