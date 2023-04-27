#include "main.h"

/**
  * main - create a simple shell
  * @argc: argument count
  * @argv: argument vector to store the arguments
  * @env: parameter to store our local enviromental variables
  *
  * Return: 0 or -1
  */

int main(int argc, char **argv, char **envp)
{
	char *token, *buffer = NULL, *buffer_copy = NULL, *delim = " \n";
	size_t n = 0;
	int i;
	char **args;
	while (1)
	{
		printf("($) ");
		/* read input from stdin */
		if (getline(&buffer, &n, stdin) == -1)
			return (-1);
		if (buffer[0] == '\n')
			continue;
		buffer_copy = strdup(buffer);
		/* tokenize to find the number of arguments */
		i = 0;
		args = malloc(sizeof(char *) * 256);
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			argv[i++] = token;
			argc++;
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		fork_exec(args, envp);
	}
	free(buffer), free(buffer_copy), free(args);
	return (0);
}
