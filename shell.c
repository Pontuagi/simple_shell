#include "main.h"

/**
  * main - create a simple shell
  * @argc: argument count
  * @argv: argument vector to store the arguments
  * Return: 0 or -1
  */

int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t bytes_read;
	int status, i = 0;
	char *token, *buffer, *buffer_copy, *delim = " \n";

	argc = 0;
	while (1)
	{
		printf("($) ");
		bytes_read = getline(&buffer, &n, stdin);
		if (bytes_read == -1)
			return (-1);
		buffer_copy = strdup(buffer);
		if (buffer_copy == NULL)
		{
			perror("error duplicating string");
			return (-1);
		}
		token = strtok(buffer, delim);
		while (token != NULL)
		{
			argc++;
			token = strtok(NULL, " ");
		}
		argc++;
		argv = tokenize(buffer_copy, argc);
		execute_cmd(argv);
	}
	free(buffer), free(buffer_copy);
	return (0);
}
