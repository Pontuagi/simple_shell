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
	/* char *bytes_read;*/
	char *token, *buffer, *buffer_copy, *delim = " \n";

	argc = 0;
	while (1)
	{
		printf("($) ");
		buffer = _read_line();
		if (buffer == NULL)
			return (-1);
		buffer_copy = strdup(buffer);
		if (buffer_copy == NULL)
		{
			perror("error duplicating string");
			return (-1);
		}
		token = str_tok(buffer, delim);
		while (token != NULL)
		{
			argc++;
			token = str_tok(NULL, " ");
		}
		argc++;
		argv = tokenize(buffer_copy, argc);
		keyword(argv, env);
	}
	free(buffer), free(buffer_copy);
	return (0);
}
