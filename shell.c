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
	char *token, *buffer = NULL, *buffer_copy = NULL, *delim = " \n";
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
		if (buffer[0] == '\n')
			continue;
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
		argv = tokenize(buffer_copy, bytes);
		keyword(argc, argv, env);
	}
	free(buffer), free(buffer_copy);
	return (0);
}
