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
	pid_t child;

	child = fork();
	if (child == 0)
	{
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
		exit(0);
	}
	else
	{
		wait(&status);
	}

}
