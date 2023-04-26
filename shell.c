#include "main.h"

/**
  * main - create a simple shell
  * @argc: argument count
  * @argv: argument vector to store the arguments
  * @env: parameter to store our local enviromental variables
  *
  * Return: 0 or -1
  */

int main(int argc, char **argv, char **env)
{
	char *token, *buffer, *buffer_copy, *delim = " ";
	size_t n = 0;
	ssize_t bytes;

	while (1)
	{
		printf("($) ");
		/* read input from stdin */
		bytes = getline(&buffer, &n, stdin);
		if (bytes == -1)
		{
			perror("error reading from stdin");
			return (-1);
		}
		if (buffer == NULL)
			return (-1);
		buffer_copy = _strdup(buffer);
		if (buffer_copy == NULL)
		{
			perror("error duplicating string");
			return (-1);
		}
		/* tokenize to find the number of arguments */
		argc = 0;
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			argc++;
			token = strtok(NULL, delim);
		}
		/* tokenize to assign each token to an argv[] */
		argv = tokenize(buffer_copy, bytes);
		/* check for built-in commands and execute */
		keyword(argc, argv, env);
	}
	free(buffer), free(buffer_copy);
	return (0);
}
