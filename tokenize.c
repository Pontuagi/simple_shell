#include "main.h"

/**
  * tokenize - function to tokenize a string in a array vector
  * @bytes: number of bytes read from stdin
  * @buffer: string to tokenize
  *
  * Return: return Array of arguments or NULL
  */

char **tokenize(char *buffer, ssize_t bytes)
{
	char **argv, *token;
	int i;
	char *delim = " \n";

	argv = malloc(sizeof(char *) * bytes);
	if (argv == NULL)
		return (NULL);
	token = strtok(buffer, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	return (argv);
}
